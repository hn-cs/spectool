# 规约生成 Skill 化设计方案

> 目标：把 **AutoSpec+**（静态分析、自底向上、ACSL）与 **FM-Agent**（Hoare Prompt、自顶向下、自然语言规约）两套方法蒸馏为一组 **轻量、可插拔的 Claude Code Skill**，并在 AutoSpec+ 的「生成—验证—修复」骨架之上，吸收 FM-Agent 的「先生成自然语言规约、再正向推理生成 ACSL」的思路。

本文档会持续迭代，先把整体方案、数据源、可复用代码的 CLI 封装、Skill 设计讲清楚，便于你逐条确认。

### 范围边界（已确认）

- **只做 C + Frama-C**。FM-Agent 本身支持 16 种语言（Rust/C++/Python/Java/Go/… 等），靠的是「用 LLM 推理代替符号验证」——推理不依赖语言专属工具链，所以能换语言。但本方案**以 Frama-C/WP 为唯一裁判**，而 Frama-C 只吃 C、ACSL 也只是 C 的形式化注解语言，因此被钉死在 C 上。多语言能力与「符号验证为准」的主线天然冲突，故**明确不纳入**，避免误解为要接 16 种语言。
- **静态分析默认关闭、按需启用**。`spec-analyze` 默认让 Claude 直接读代码定位函数与循环（短程任务足够好）；只有到**仓库级**代码、上下文装不下、依赖关系复杂时，才启用 veri-clang 静态分析辅助定位与排序。详见 §6.1。
- **Skill 粒度**：保持 6 个原子 Skill + 1 个 pipeline 总编排。

---

## 1. 背景：两套方法的现状与矛盾点

### 1.1 AutoSpec+（自底向上 / 符号验证）

| 维度 | 内容 |
|---|---|
| 思路 | 神经-符号闭环：LLM 生成 ACSL 候选，Frama-C/WP 作为**确定性裁判** |
| 分解 | `veri-clang` 静态分析构建扩展调用图，按依赖**自底向上**排序，逐函数/逐循环生成 |
| 产物 | 机器可检验的 **ACSL** 注解（contract、loop invariant、loop variant） |
| 验证 | `frama-c -wp`，解析 `Proved goals: n/m` 判定 Pass/Fail/Invalid |
| 修复 | 用 WP 失败 goal 定位失败行，打 `INFILL` 标记，重查 LLM，最多 5 轮 |
| 关键文件 | `LLM4Veri/mark.py`（静态分析）、`src/framac.py`（验证）、`src/simplify_acsl.py`（失败定位）、`src/llmveri.py`（主循环）、`termination/`（停机分析） |

**强项**：产物是可被 Frama-C 严格证明的 ACSL；验证是确定性的、可信的。
**弱项**：直接让 LLM 一步到位写 ACSL，难度大；缺少「先想清楚函数语义」这一中间层。

### 1.2 FM-Agent（自顶向下 / LLM 推理）

| 维度 | 内容 |
|---|---|
| 思路 | Hoare 风格：先理解系统设计意图，生成**自然语言行为规约**，再正向推理检查实现是否符合 |
| 分解 | OpenCode 理解代码库 → 划分 phase → 静态调用图分 layer（叶子在 layer 0） |
| 产物 | 注释形式的**自然语言规约** `[SPEC] Pre/Post [SPEC]` + 被调函数摘要 `[INFO]` |
| 验证 | **LLM 正向推理**：函数切块（~40 行）→ 逐块生成后置条件 → 检查是否蕴含规约后条件 |
| 修复 | 推理发现 MISMATCH → 生成测试用例触发 bug → 输出 bug 报告 |
| 关键文件 | `src/reasoner.py`（正向推理核心）、`src/prompts.py`、`src/verification.py`、`src/extract.py`、`md/*.md`（Hoare 工作流模板） |

**强项**：自然语言规约更贴近开发者意图，先「想清楚」再落地；Hoare 正向推理可解释。
**弱项**：验证靠 LLM 推理，**非确定性**，受模型能力影响大，可能幻觉；产物不是机器可证明的形式化规约。

### 1.3 天然矛盾点

| 矛盾 | AutoSpec+ | FM-Agent | 本方案取舍 |
|---|---|---|---|
| 分解方向 | 自底向上（调用图依赖序） | 自顶向下（phase）+ 自底向上（layer） | **双向混合**：自顶向下定「该写多强」，自底向上做「验证供给」（见 §2.4） |
| 规约形态 | 直接 ACSL | 自然语言 | **两段式**：先 NL，再 NL→ACSL |
| 验证手段 | Frama-C/WP（确定性） | LLM 推理（非确定性） | **以 Frama-C 为准**，LLM 推理作为生成期的「自检/草稿」 |
| 编排者 | Python `main.py` | Python + OpenCode | **Claude Code 自身**作为编排者，Skill 调薄 CLI |

**核心设计判断**：以 AutoSpec+ 的符号验证闭环为骨架（确定性、可信），把 FM-Agent 的 Hoare Prompt 作为**生成阶段的中间层**——先产自然语言规约，再正向推理翻译为 ACSL，最后交给 Frama-C 裁决。**方向上采用双向混合**：用自顶向下解决「规约强度」难题，用自底向上满足「Frama-C 模块化验证」要求（详见 §2.4）。

---

## 2. 整体方案：融合后的流水线

### 2.1 一句话概括

> **定位排序 → 自顶向下需求分析（定每个函数该写多强的 NL 规约）→ 自底向上把 NL 翻成 ACSL 并验证 → Frama-C 裁决 → 供需不匹配则带方向修复**。整个流程由 Claude Code 作为编排者驱动，每一步是一个可插拔 Skill，背后是一个薄 CLI。核心是 §2.4 的**双向混合**：自顶向下治强度，自底向上做验证。

### 2.2 流水线图

```
┌──────────────────────────────────────────────────────────────────────┐
│                     Claude Code （编排者 / Orchestrator）                │
│   读取 plan，按依赖序逐个函数驱动下面的 Skill，维护状态与重试预算           │
└──────────────────────────────────────────────────────────────────────┘
        │
        ▼
  ┌─────────────┐   C 源码
  │ ① 静态分析   │   ── veri-clang ──►  规约位置(SpecLoC) + 扩展调用图
  │ spec-analyze │                       └─► 自底向上任务序 (plan.json)
  └─────────────┘
        │  按依赖序，对每个函数：
        ▼
  ┌─────────────┐   函数代码 + 被调者已验证契约([INFO])
  │ ② NL 规约    │   ── Hoare Prompt（Claude 推理）──►  自然语言 Pre/Post
  │ spec-nl      │       （前置/后置/不变式，意图而非实现）
  └─────────────┘
        │
        ▼
  ┌─────────────┐   NL 规约 + 代码
  │ ③ NL→ACSL    │   ── 正向推理 + 翻译（Claude 推理）──►  候选 ACSL 注解
  │ spec-acsl    │       （contract / loop invariant）
  └─────────────┘
        │
        ▼
  ┌─────────────┐   注解后的 .c
  │ ④ 验证       │   ── frama-c -wp ──►  Pass_n_n / Fail_x_m / Invalid
  │ spec-verify  │
  └─────────────┘
        │
   ┌────┴─────┐
   │ Pass?    │── 是 ──► 固化该函数契约（写回 .h / [INFO] 池），进入下一个函数
   └────┬─────┘
        │ 否（Fail/Invalid，预算未耗尽）
        ▼
  ┌─────────────┐   WP 失败 goal + 失败行
  │ ⑤ 修复       │   ── simplify_acsl 定位 + 反馈给 ②/③ 重生成 ──►  回到 ④
  │ spec-repair  │       （超出预算 → 标记未证明，记录原因）
  └─────────────┘
        │ （可选）全部 Pass 后
        ▼
  ┌─────────────┐
  │ ⑥ 停机分析   │   ── 生成 loop variant + frama-c 验证 ──► 偏正确性升级为完全正确性
  │ spec-term    │
  └─────────────┘
```

### 2.3 与原两套方法的对应关系

| 步骤 | 复用来源 | 本方案角色 |
|---|---|---|
| ① 静态分析 | AutoSpec+ `mark.py` / veri-clang | 不变，提供定位与排序 |
| ② NL 规约 | FM-Agent `reasoner`/`prompts`/`system_prompt.md` 的 Hoare Prompt | **新增中间层**：在 AutoSpec 流程里插入 |
| ③ NL→ACSL | 新增桥接（借鉴 FM-Agent 正向推理 + AutoSpec 的 ACSL few-shot） | **本方案最关键的新组件** |
| ④ 验证 | AutoSpec+ `framac.py` | 不变，确定性裁判 |
| ⑤ 修复 | AutoSpec+ `simplify_acsl.py` + 重生成 | 反馈回 ②/③ 而非仅 ③ |
| ⑥ 停机 | AutoSpec+ `termination/` | 可选增强 |

> **关键变化**：FM-Agent 原本用 LLM 推理「代替」验证；本方案把这套 Hoare 推理**前移到生成侧**，作为「先想清楚 NL 语义 + 草拟 ACSL」的脚手架，真正的验证仍交给 Frama-C。这样既拿到「先自然语言后形式化」的可解释性，又保住了符号验证的可信度。

### 2.4 双向混合机制：自顶向下定强度，自底向上做验证

> **首版口径（已确认）**：本节描述的是**完整机制（目标形态）**。**首版只实现其简化版——单遍自底向上 + spec-nl 只看「直接调用者一层」反推强度**（详见 §6.7）。完整两遍扫描与跨层需求上溯作为后续演进。下文先讲清完整机制，便于理解设计意图。

**为什么不能纯自底向上**：给叶子函数写契约时，看不到调用者会怎么用它，只能**猜强度**——猜弱了调用者证不动，猜强了叶子自己实现不出来。错配要等爬到调用者才暴露，再回头重写叶子，代价高。这正是纯自底向上「规约过强/过弱」失败的根因。

**为什么不能纯自顶向下**：Frama-C 做的是**模块化验证**——要验调用者 `main`，必须先有被调者 `helper` 的契约**存在且已证**。验证这一步天然要求自底向上。

**结论：两个方向服务于两件不同的事，不是二选一。**

| 方向 | 解决的问题 | 落在哪个 Skill |
|---|---|---|
| **自顶向下（需求传播）** | 定下每个函数*该保证多强*——强度由「调用者需要什么」反推，天生校准 | `spec-nl`（NL 规约阶段） |
| **自底向上（验证供给）** | 真正证明每个函数满足契约——叶子先证，作为调用者的已验证前提 | `spec-acsl` / `spec-verify` |

**混合流程 = 两遍扫描 + 一个调和环：**

```
第一遍（自顶向下 / 需求分析）：调用者 → 被调者
  从顶层目标（main 的断言 / 公开 API 的意图）出发，逐层往下：
  「为了让调用者成立，这个被调者至少要保证什么？」
  → 产出每个函数的【目标契约(demand)】，并记录它服务于哪条调用者义务
  → 强度被「恰好够调用者用」钉死，避免过强/过弱

          │ 目标契约（NL，带强度来由）
          ▼
第二遍（自底向上 / 实现验证）：被调者 → 调用者
  叶子先行，把目标契约翻成 ACSL，用【已验证的被调者契约】喂给 Frama-C：
  「这个函数的实现，真能满足它的目标契约吗？(supply)」
  → Pass：契约入池，供调用者使用
  → Fail：进入调和环

          │ 供给 < 需求（实现满足不了被需求的契约）
          ▼
调和环（供需不匹配 → 带方向语义的修复，§6.5）：
  ① ACSL 翻译偏了            → 重译（停在自底向上层）
  ② 目标契约本身不现实       → 回传调用者：放松期望 / 调用者自己加防御
                              （沿自顶向下链上溯一层，改需求再重来）
```

**这套机制的理论对应**：就是模块化验证里的 **assume-guarantee / 契约推断**——自顶向下计算「被需求的契约(demand)」，自底向上检查「可实现性(supply)」，不匹配时在供需之间协商。我们的「两级回退修复」因此带上了明确方向：**ACSL 层重译 = 修供给，NL 层回传 = 调需求**。

**与现有数据结构的衔接**：
- 第一遍产出的「目标契约」就是 `<func>.nl.md`，额外记一个 `serves:` 字段（服务于哪个调用者义务）。
- 第二遍的「已验证被调者契约」就是 `contracts.json` 里的条目（对应 FM-Agent 的 `[INFO]`）。
- `plan.json` 同时存**两个序**：自顶向下的 `demand_order`（调用者在前）和自底向上的 `verify_order`（叶子在前）。

> 一句话：**先自顶向下问「该证多强」，再自底向上证「能不能做到」，差了就在两者间协商。** 这样既治了自底向上的强度病，又满足了 Frama-C 的模块化验证前提。

---

## 3. 数据源

分三类：**运行期输入**、**少样本/知识库**、**过程产物**。

### 3.1 运行期输入（被验证对象）
- 用户的 C/C++ 源码（单文件或互依赖的多文件组）；`.h` 由 Frama-C 多文件能力自动发现。
- 可选的项目级领域知识（借鉴 FM-Agent 的 `engine_overview.txt` / `phase_NN_types.txt`），帮助 NL 规约理解设计意图。

### 3.2 少样本 / 知识库（驱动生成质量）
- **ACSL few-shot 示例**：复用 AutoSpec+ `LLM4Veri/src/prompt/`（contract、loop invariant、infill 示例）。
- **Hoare Prompt 规则**：复用 FM-Agent `md/system_prompt.md`（行为规约「写什么/不写什么」7 条规则）。
- **NL→ACSL 翻译对照样例**：「自然语言 Pre/Post ↔ ACSL `requires/ensures/loop invariant`」的成对样例库。**⏸ 暂不做**——首版先靠 Claude 自身的 ACSL 能力 + AutoSpec+ 现成 few-shot 完成翻译；若实测翻译质量不足，再在「正式开始前」决定是否构建该样例库（见 §6.3 与 §10 待决项）。
- 现成评测集：AutoSpec+ `experiment_results/`、`LLM4Veri/dataset/`（含 inter-modular 的 x509 例子）作为回归测试与样例来源。

### 3.3 过程产物（中间状态，落盘便于断点续跑与审计）
- `plan.json`：任务清单 + 序。**首版只需自底向上 `verify_order`（叶子在前）**；自顶向下 `demand_order`（调用者在前）留待完整两遍演进。每项含函数 FQN、文件:行、循环位置、依赖。
- `<func>.nl.md`：该函数的自然语言目标契约，含 `serves:` 字段（服务于哪条调用者义务，记录强度来由）。
- `<func>.acsl.c`：注入 ACSL 后的代码。
- `<func>.wp.txt` + 判定：Frama-C 输出与 Pass/Fail。
- `contracts.json`：已验证契约池（叶子先入池，作为调用者验证时的 `[INFO]` 前提，实现自底向上供给）。

---

## 4. 架构总览：两层 + 外部工具

> Skill（语义层，Claude 执行）在上，`spectool`（确定性工具层，自包含）在下，最底是 frama-c/veri-clang 外部二进制。原两个项目不在运行架构里，只是编码期的代码来源。

```
┌─────────────────────────────────────────────────────────────┐
│  Layer A — Skills（Claude Code 可插拔技能，含提示词与流程）       │
│  spec-analyze · spec-nl · spec-acsl · spec-verify ·          │
│  spec-repair · spec-term · spec-pipeline(总编排)              │
└─────────────────────────────────────────────────────────────┘
                          │ 调用
                          ▼
┌─────────────────────────────────────────────────────────────┐
│  Layer B — spectool CLI（自包含；可复用片段已抽取/vendor 进来）   │
│  纯确定性/工具性工作：静态分析、Frama-C、解析、注入、状态读写       │
│  内部 vendored 实现（清理后的抽取代码，不 import 原项目）           │
└─────────────────────────────────────────────────────────────┘
                          │ subprocess 调用外部二进制
                          ▼
┌─────────────────────────────────────────────────────────────┐
│  外部运行时依赖（真正需要的二进制）                              │
│  frama-c / WP / Alt-Ergo / Z3 · veri-clang                  │
└─────────────────────────────────────────────────────────────┘

   （注）autospec+ / FM-Agent 两个目录 = 「代码采石场」，仅在编码期
        供我们抽取可复用片段，抽完后 spectool 不再依赖它们，可删除。
```

**职责划分原则（关键）**：
- **凡是确定性、工具性的工作 → 沉到 Layer B CLI**（静态分析、跑 Frama-C、正则解析、ACSL 注入、状态读写）。这些不该让 LLM 做，既慢又不稳。
- **凡是需要语义理解、推理、生成的工作 → 留在 Layer A Skill 由 Claude 完成**（写 NL 规约、NL→ACSL 翻译、读 WP 报错决定怎么改）。
- 这样 Claude Code 天然替代了 AutoSpec+ 的 `main.py` 主循环和 FM-Agent 的 OpenCode 编排——**编排逻辑由 Skill 指令描述，Claude 执行**。

**关于两个原项目的定位（重要修订）**：
- `autospec+` / `FM-Agent` **不作为整体被运行、也不在运行时被 import**。它们只是**代码采石场（code quarry）**——编码期我们从中抽取可复用的确定性片段（如 frama-c 调用、WP 输出解析、函数切块），**清理后 vendor 进 `spectool/spectool/vendored/`**，使 `spectool` 自包含。
- 抽取完成后，`spectool` 的运行**只依赖外部二进制**（frama-c / veri-clang），与那两个目录再无关系；它们甚至可以从仓库移除而不影响运行。
- 真正的运行时依赖只有 **frama-c / veri-clang 这类外部工具**——这本来就是该调的，保留。

---

## 5. Layer B：`spectool` CLI 详细设计

把两个项目里**确定性的、可复用的**代码片段**抽取出来、清理后 vendor 进** `spectool`，对外暴露为统一 CLI。它**自包含**（不 import 原项目）、**不调用 LLM**（LLM 由 Claude 在 Skill 层完成），只做工具活，输出统一为 **JSON**（便于 Claude 解析）。运行时只 subprocess 调用 frama-c / veri-clang 等外部二进制。

### 5.1 设计约定（以「方便 Claude 调用」为唯一标准）

| 决策 | 选择 | 为什么对 Claude 友好 |
|---|---|---|
| 入口形态 | **单一入口 `spectool <subcommand>`**，不散落多个脚本 | Claude 只需记一个命令名；`spectool --help` 即可自发现全部能力 |
| 实现库 | **`argparse`（标准库），不用 click** | 零额外依赖，docker 里不必再装包；子命令 + `--help` 已够用，越少依赖越「可插拔」 |
| 安装方式 | **打包为 `console_scripts`，`pip install -e`** | Claude 在任意目录直接敲 `spectool ...`，无需记 `python /长路径/cli.py` |
| 输出协议 | **stdout 仅输出 JSON**；人类可读日志走 **stderr** | Claude 解析 stdout 稳定，不被日志污染 |
| 成败判定 | **退出码语义化**：`0` 成功 / `2` 工具缺失 / `3` 输入错误 | Claude 靠退出码判断，不用猜文本 |
| 工作目录 | `<proj>/.spec/` 存 `plan.json`、`contracts.json`、每函数产物 | 状态落盘，支持断点续跑与审计 |

> 一句话：**一个命令、子命令自描述、JSON 进 JSON 出、退出码定成败、零多余依赖**——这套约定让 Claude 把 `spectool` 当成稳定可预测的工具调用，而不是需要解析自然语言输出的黑盒。

### 5.2 子命令清单

| 子命令 | 复用来源 | 作用 | 关键输入 → 输出 |
|---|---|---|---|
| `analyze` | AutoSpec+ `mark.py` + veri-clang | **仅仓库级按需用**：静态分析，产出规约位置 + 自底向上任务序 | `.c` → `plan.json` |
| `inject` | AutoSpec+ `baselib`/infill 逻辑 | 把 ACSL 文本注入到指定函数/循环位置 | 代码 + ACSL → 注解后 `.c` |
| `verify` | AutoSpec+ `framac.py` | 跑 frama-c -wp，解析 goals | 注解 `.c` → `{result, n, m, std, err}` |
| `locate-fail` | AutoSpec+ `simplify_acsl.py` | 解析 WP 输出，定位失败 goal 与行号 | WP 输出 → 失败项列表 |
| `extract` | FM-Agent `extract.py` | 抽取单个函数为独立片段（NL 推理上下文） | `.c` + 函数名 → 片段 |
| `parse-spec` | FM-Agent `parser.py` | 解析 `[SPEC]`/`[INFO]` 注释块 | 文件 → 结构化 spec |
| `split-blocks` | FM-Agent `reasoner._split_into_blocks_braced` | 按花括号深度切块（供 Hoare 推理） | 函数 → 块列表 |
| `contracts` | 新增（薄） | 读写已验证契约池，按调用图取某函数的被调者契约 | `contracts.json` ⇄ 查询 |
| `variant` | AutoSpec+ `termination/` | 注入 loop variant 并验证停机 | 代码 + variant → 验证结果 |
| `state` | 新增（薄） | 读写 `plan.json` 任务状态（pending/passed/failed/给下一个） | — |
| `doctor` | 新增（薄） | 环境自检（frama-c / Alt-Ergo / Z3 / veri-clang 是否就绪） | — → 缺失项列表 |

### 5.3 各子命令接口示例

> 下面是「Claude 怎么调、拿到什么」的直观示例。签名后注明其包装的现有函数。

#### `spectool analyze`
```bash
spectool analyze -f foo.c --proj ./myproj --json
```
包装：`mark.py:RunClangCommand/GetSpecLoc` → 解析 `SpecLoC.txt`。
输出：
```json
{
  "tasks": [
    {"fqn": "helper", "file": "foo.c", "line": 12, "loops": [], "deps": []},
    {"fqn": "main",   "file": "foo.c", "line": 30, "loops": [34], "deps": ["helper"]}
  ],
  "order": ["helper", "main"]
}
```

#### `spectool verify`（最核心、最高频）
```bash
spectool verify -f foo.acsl.c --timeout 8 --json
```
包装：`framac.py:run_framac_with_wp` + `get_result_type`。
输出：
```json
{
  "result": "Fail", "proved": 3, "total": 5,
  "raw_result_type": "Fail_3_5",
  "stdout_file": ".spec/foo.wp.txt",
  "elapsed_sec": 6.2
}
```

#### `spectool locate-fail`
```bash
spectool locate-fail --wp .spec/foo.wp.txt --src foo.acsl.c --json
```
包装：`simplify_acsl.py:simplify_acsl`。
输出：
```json
{
  "failures": [
    {"goal": "Post-condition", "function": "main", "line": 41, "kind": "ensures"},
    {"goal": "loop invariant", "function": "main", "line": 35, "kind": "loop_inv"}
  ]
}
```
> Claude 拿到这个 JSON 后，自己决定「第 41 行的 ensures 太强 / 第 35 行缺一条不变式」并重写——**判断留给 Claude，定位留给 CLI**。

#### `spectool inject`
```bash
spectool inject --src foo.c --func main --acsl @main.acsl.txt --out foo.acsl.c
```
包装：infill 标记 + 注入逻辑。把 ACSL 精确放到函数契约位置 / 循环前。

#### `spectool split-blocks`（服务于 NL 推理）
```bash
spectool split-blocks --func @main.c --granularity 40 --json
```
包装：`reasoner._split_into_blocks_braced`。输出按花括号边界切好的代码块数组，供 Skill ② 做 Hoare 正向推理。

### 5.4 抽取来源速查（从采石场抽哪些片段 → vendor 进哪个命令）

> 下表是**编码期的抽取清单**：从 `autospec+` / `FM-Agent` 里挖出这些确定性片段，清理后放进 `spectool/spectool/vendored/`，供对应命令调用。**运行时不再 import 原项目。**

| 抽取来源（采石场路径） | vendor 后服务的子命令 |
|---|---|
| `LLM4Veri/mark.py: RunClangCommand / GetSpecLoc / TransformDict` | `analyze` |
| `LLM4Veri/src/framac.py: run_framac_with_wp / get_result_type` | `verify` |
| `LLM4Veri/src/simplify_acsl.py: simplify_acsl` | `locate-fail` |
| `termination/src/generate_variant.py: inject_variant`；`call_framac.py: run_framac_and_check` | `variant` |
| `FM-Agent/src/extract.py: run_extraction` | `extract` |
| `FM-Agent/src/parser.py: parse_input_function` | `parse-spec` |
| `FM-Agent/src/reasoner.py: _split_into_blocks_braced` | `split-blocks` |

> 注意：FM-Agent 里**调用 LLM 的部分**（`_generate_block_post_condition`、`_check_post_implies_spec`、`llm_client.py`）**不抽取**——这些语义推理改由 Claude 在 Skill 层用提示词完成，只抽取其确定性的切块/解析骨架。这正是「蒸馏」的核心：把 LLM 调用从 Python 里抽走，交还给 Claude Code。

### 5.5 工程化结构：命令注册式（可维护性核心）

`spectool` 不把逻辑堆在单个 `cli.py`，而是采用**命令注册式**布局——外层是 `SKILL.md` + `requirements.txt` + `pyproject.toml`，**每个子命令是 `commands/` 下的一个独立文件**，通过装饰器自注册到 dispatcher。**加一个新命令 = 加一个文件，不动入口**。

```
spectool/
├── SKILL.md            # 工具能力清单 + 调用约定（人 / Claude 都读）
├── requirements.txt    # 依赖极简（镜像已带 frama-c/openai 等）
├── pyproject.toml      # 入口：[project.scripts] spectool = "spectool.cli:main"
└── spectool/
    ├── cli.py          # 扫描 commands/，为每个命令建 subparser，再 dispatch
    ├── registry.py     # @command 装饰器 + COMMANDS 注册表
    ├── io.py           # emit_json() / fail() / log()：统一输出与退出码
    ├── commands/       # ★ 一命令一文件，自注册
    │   ├── verify.py   #   analyze / verify / locate_fail / inject / ...
    │   └── ...
    ├── vendored/       # 从采石场抽取、清理后的自包含实现（不 import 原项目）
    │   ├── framac.py   #   ← 抽自 LLM4Veri/src/framac.py
    │   ├── locate.py   #   ← 抽自 simplify_acsl.py
    │   ├── blocks.py   #   ← 抽自 FM-Agent reasoner._split_into_blocks_braced
    │   └── ...
    └── state.py        # plan.json / contracts.json 读写
```

> `vendored/` 里是**抽取并清理后的代码副本**，已去掉对原项目其余部分的依赖、去掉 LLM 调用。这样 `spectool` 自包含，原两个目录可随时移除。

**注册机制（约定，便于实现时照抄）**：

每个命令文件实现两个约定函数，并用 `@command` 注册：
```python
# spectool/commands/verify.py
from ..registry import command
from ..io import emit_json, fail
from ..vendored import framac

@command(
    name="verify",
    help="Run frama-c -wp on an annotated C file and report proved/total goals.",
)
def configure(parser):                      # 1) 声明本命令的参数
    parser.add_argument("-f", "--file", required=True)
    parser.add_argument("--timeout", type=int, default=8)

def run(args):                              # 2) 执行，统一用 io helper 出 JSON / 退出码
    rtype, std, err, sec = framac.run_framac_with_wp(args.file, args.timeout)
    if rtype == "Invalid":
        return fail(code=2, msg="frama-c could not generate goals", stdout_file=std)
    proved, total = parse_pn(rtype)
    emit_json({"result": "Pass" if proved == total else "Fail",
               "proved": proved, "total": total,
               "raw_result_type": rtype, "stdout_file": std, "elapsed_sec": sec})
```

```python
# spectool/cli.py（骨架）
import argparse, importlib, pkgutil
from . import commands
from .registry import COMMANDS

def main():
    for m in pkgutil.iter_modules(commands.__path__):   # 自动发现所有命令文件
        importlib.import_module(f"{commands.__name__}.{m.name}")
    parser = argparse.ArgumentParser(prog="spectool")
    sub = parser.add_subparsers(dest="cmd", required=True)
    for name, c in COMMANDS.items():
        p = sub.add_parser(name, help=c.help); c.configure(p); p.set_defaults(_run=c.run)
    args = parser.parse_args()
    args._run(args)
```

**这套结构带来的可维护性**：
- **新增命令零侵入**：丢一个 `commands/foo.py` 进去就生效，`cli.py` 不用改。
- **关注点分离**：参数声明（`configure`）/ 业务（`run`）/ 输出协议（`io.py`）/ 抽取实现（`vendored/`）各管一段。
- **vendored 实现自包含**：从采石场抽取清理后即与原项目脱钩，原目录可删；命令层只依赖 `vendored/` 的稳定接口。
- **`SKILL.md` 即活文档**：列出每个子命令的用途与 I/O，Claude 读它就知道工具箱里有什么、怎么调。

---

## 6. Layer A：Skill 详细设计

每个 Skill = 一段 `SKILL.md`（触发条件 + 步骤 + 提示词 + 何时调哪个 `spectool` 子命令）。Claude 读取后自行执行。下面给出每个 Skill 的职责、输入输出、以及它内部「Claude 做什么 / CLI 做什么」的分工。

### 6.1 `spec-analyze`（定位与排序，**双模式**）

定位「有哪些函数、哪些循环、谁调用谁、按什么顺序处理」这件事有两条路径，Skill 默认走第一条，必要时切第二条：

- **默认模式 — Claude 直接读取定位（短程任务）**：Claude 直接读源码，识别函数、循环位置、调用依赖，自己排出自底向上序，写出 `plan.json`。**不依赖 veri-clang**，环境门槛为零，对单文件 / 几个文件的短程任务定位质量好、够用。
- **可选模式 — veri-clang 静态分析（仓库级任务）**：当代码达到**仓库级**、函数与依赖多到 Claude 上下文装不下或人工读取易漏时，调用 `spectool analyze` 用 veri-clang 构建扩展调用图、精确定位 SpecLoC 并生成依赖序。作为定位的**辅助**，弥补长程任务下直接读取的局限。
- **如何选择**：Skill 指令里给 Claude 一个判据——文件数 / 总行数 / 跨文件依赖超过阈值，或用户显式要求，则切到静态分析模式；否则默认直接读取。
- **产物**：两种模式都产出统一格式的 `plan.json`（含自顶向下 `demand_order` 与自底向上 `verify_order` 两个序，见 §3.3），下游 Skill 无感知差异。

### 6.2 `spec-nl`（自然语言规约生成 —— 自顶向下需求分析 + Hoare Prompt）
- **方向：自顶向下（首版只看一层）**。首版在单遍自底向上推进中，给当前函数写 NL 时**读其直接调用者的调用点 / 已写目标**，反推「为了让调用者成立，本函数至少要保证什么」——强度由真实需求校准，从源头避免过强/过弱（机制全貌见 §2.4，完整多层传播留待演进）。
- **输入**：单个函数代码 + **直接调用者的调用上下文/目标**（提供「被需求的强度」）+（若已存在）被调者契约。
- **Claude 做**：加载 `shared/hoare_rules.md`（抽自 FM-Agent `system_prompt.md` 的 7 条行为规约规则），写出 **Pre-condition / Post-condition / 关键不变式**，强调「描述意图与数据契约，不描述实现细节」；并在 `serves:` 字段记录本契约服务于哪条调用者义务。必要时用 `spectool split-blocks` 切块、对每块做 Hoare 正向推理来**自检** NL 规约是否覆盖全路径。
- **产物**：`<func>.nl.md`（目标契约，带 `serves:` 强度来由）。
- **要点**：这是从 FM-Agent 借来的「先想清楚 + 自顶向下看目标」步骤，产物喂给下一步翻译，而非用于替代验证。

### 6.3 `spec-acsl`（NL → ACSL 翻译 —— 自底向上验证供给的起点）
- **方向：自底向上**。按 `plan.json` 的 `verify_order`（叶子在前）处理：叶子函数先把目标契约翻成 ACSL 并验证通过，入契约池，再轮到它的调用者。
- **输入**：`<func>.nl.md`（目标契约）+ 函数代码 + **被调者已验证的 ACSL 契约**（从 `contracts.json` 取，作为 Frama-C 的 `[INFO]` 前提）。
- **Claude 做**：
  1. 加载 AutoSpec+ 的 ACSL few-shot（`src/prompt/`）作为翻译参考。（**NL→ACSL 专用对照样例库暂不做**，先用 Claude 自身 ACSL 能力 + 该 few-shot；不足再补，见 §10。）
  2. 把每条自然语言 Pre/Post **正向推理**地翻译为 ACSL `requires/ensures`；为循环补 `loop invariant`（必要时 `loop assigns`）。
  3. 调 `spectool inject` 注入到正确位置，生成 `<func>.acsl.c`。
- **产物**：候选 `<func>.acsl.c`。
- **设计理由**：直接 NL→ACSL 比「代码→ACSL」更可控——自然语言规约已经把「该证什么」固定下来，翻译阶段只需处理形式化表达，降低一步到位写 ACSL 的失败率。

### 6.4 `spec-verify`（验证）
- **Claude 做**：调 `spectool verify`，读 `{result, proved/total}`。Pass → 调 `spectool contracts` 把契约写回契约池（供后续调用者使用）；Fail/Invalid → 交给 `spec-repair`。
- **CLI 做**：frama-c -wp + 解析。

### 6.5 `spec-repair`（修复 —— 供需协商，带方向语义）
- **输入**：失败的 `.acsl.c` + WP 输出。
- **Claude 做**：调 `spectool locate-fail` 拿到失败 goal + 行号，判断失败属于哪类（对应 §2.4 调和环）：
  - **供给侧 / ACSL 表达问题**（翻译错/太强/缺 assigns）→ 回 §6.3 **重译**该条，方向不变（停在自底向上层）。**首版主要走这条。**
  - **需求侧 / 目标契约不现实**（实现根本满足不了被需求的强度）→ **首版退化处理**：让本函数自身加防御 / 弱化本函数契约并相应调整其直接调用者；若无法本地解决则标 `unproved` 并记录。完整的「跨多层上溯调用者改需求」留待两遍演进。
  - 反复失败且预算（默认 5 轮，对齐 `MAX_ITERATION_TIMES`/`MAX_SPC_ITER`）耗尽 → 标记 `unproved`，记录最后的 WP 报错，**如实汇报**而不强行通过。
- **设计要点**：这就是 §2.4 的 assume-guarantee 协商落地——**ACSL 层重译 = 修供给，NL 层回传 = 调需求**。两级回退之所以成立，正因为有自顶向下的 NL 中间层与 `serves:` 强度来由可追溯。

### 6.6 `spec-term`（停机分析，可选）
- **Claude 做**：对已偏正确的循环，生成 ranking function，调 `spectool variant` 注入并用 WP 验证，升级为完全正确性。
- 复用 `termination/`。

### 6.7 `spec-pipeline`（总编排）

**首版（已确认）：单遍自底向上 + 一层向上看目标**

按 `verify_order`（叶子→调用者）单遍推进，对每个函数：
1. `spec-nl`：写目标契约。**自顶向下的需求只看「直接调用者一层」**——读该函数在其**直接调用者**里的调用点 / 调用者已写的目标，反推本函数「该保证多强」，记入 `serves:`。不做全局多层需求传播。
2. `spec-acsl → spec-verify →（失败则 spec-repair 循环）`：翻 ACSL 并验证，Pass 后契约入 `contracts.json`，供其调用者使用。
3. 可选最后跑 `spec-term`。维护整体进度、预算、最终报告（通过 / 未通过及原因）。

> 这样仍拿到自顶向下「校准强度」的主要收益（一层调用者上下文通常足够定强度），又避免完整两遍的编排复杂度。`plan.json` 首版**只需 `verify_order` 一个序**，`demand_order` 留待演进。

**后续演进（暂不做）：完整两遍扫描**

待单遍跑通、确有「跨多层需求传播」的需要时，再升级为 §2.4 的完整双向：先按 `demand_order` 整遍自顶向下产全部目标契约，再按 `verify_order` 整遍自底向上验证，`spec-repair` 需求侧可上溯任意层调用者改需求。

- 这一层替代了 AutoSpec+ `main.py`/`auto_run.py` 的批处理循环与 FM-Agent `main.py` 的 5 阶段编排。

### 6.8 Skill 间数据流（双向）

### 6.8 Skill 间数据流

**首版（单遍自底向上，verify_order：叶子→调用者）**：

```
对每个函数（叶子先行）：
  直接调用者上下文 ─┐
                   ▼
  [spec-nl] ──► foo.nl.md（目标契约 + serves:，强度只看一层调用者）
       ▲              │
       │              ▼
       │      [spec-acsl] ──► foo.acsl.c ──► [spec-verify]
       │                                          │
       │ 供给侧：原地重译                           │ Pass
       └── locate-fail ◄── 失败 ──[spec-repair]   ▼
                                          contracts.json（叶子契约供调用者）
   （需求侧不匹配：首版退化为「本函数加防御 / 标 unproved 并记录」，
     不做跨层上溯——上溯留待完整两遍演进）
```

**后续演进（完整两遍，见 §2.4 / §6.7）**：第一遍 `demand_order` 自顶向下产全部目标契约，第二遍 `verify_order` 自底向上验证，`spec-repair` 需求侧可上溯任意层。

---

## 7. 一个函数的端到端走查（让方案落地可感）

以 `LLM4Veri/dataset` 里一个带循环的求和函数为例：

1. **`spec-analyze`** → `spectool analyze` → `plan.json`：`sum` 无依赖，排第一，含一个 loop@L5。
2. **`spec-nl`**：Claude 按 Hoare Prompt 写出
   *Pre：`n>=0 && \valid(a+(0..n-1))`；Post：`\result == \sum(a,0,n)`；循环不变式（意图）：已累加前 i 项*。存 `sum.nl.md`。
3. **`spec-acsl`**：Claude 把上面翻成
   `requires n>=0; requires \valid(a+(0..n-1)); ensures \result==\sum(...);`
   循环处 `loop invariant 0<=i<=n; loop invariant s==\sum(a,0,i); loop assigns i,s;`
   → `spectool inject` → `sum.acsl.c`。
4. **`spec-verify`** → `spectool verify` → `Fail_4_5`（缺 `loop assigns` 导致一个 goal 没证）。
5. **`spec-repair`** → `spectool locate-fail` → 「L5 loop，assigns 不足」→ 判定为 ACSL 表达问题 → 回 §6.3 补 `loop assigns` → 重验 → `Pass_5_5`。
6. 契约写入 `contracts.json`；若需完全正确性，`spec-term` 生成 `loop variant n-i;` 验证停机。

---

## 8. 目录与交付物布局（建议）

```
spec_cc_version/
├── docs/
│   └── design.md                  # 本文档
├── spectool/                      # Layer B：薄 CLI（新建，命令注册式）
│   ├── SKILL.md                   # 工具说明：能力清单 + 调用约定（给 Claude/人看）
│   ├── requirements.txt           # 依赖（尽量空/极简，复用镜像已有库）
│   ├── pyproject.toml             # console_scripts 入口：spectool = spectool.cli:main
│   └── spectool/                  # 包本体
│       ├── __init__.py
│       ├── cli.py                 # dispatcher：扫描 commands/ 自动注册 subparser
│       ├── registry.py            # @command 装饰器 + 命令注册表
│       ├── io.py                  # 统一 JSON 输出 / 退出码 / stderr 日志 helper
│       ├── commands/              # ★ 每个子命令一个文件，自注册（加命令=加文件）
│       │   ├── __init__.py
│       │   ├── analyze.py
│       │   ├── verify.py
│       │   ├── locate_fail.py
│       │   ├── inject.py
│       │   ├── extract.py
│       │   ├── parse_spec.py
│       │   ├── split_blocks.py
│       │   ├── contracts.py
│       │   ├── variant.py
│       │   ├── state.py
│       │   └── doctor.py
│       ├── vendored/              # 从采石场抽取、清理后的自包含实现（不 import 原项目）
│       │   ├── framac.py          # ← 抽自 LLM4Veri/src/framac.py
│       │   ├── analyze.py         # ← 抽自 LLM4Veri/mark.py
│       │   ├── locate.py          # ← 抽自 simplify_acsl.py
│       │   ├── term.py            # ← 抽自 termination/
│       │   ├── extract.py         # ← 抽自 FM-Agent/src/extract.py
│       │   └── blocks.py          # ← 抽自 reasoner._split_into_blocks_braced
│       └── state.py               # plan.json / contracts.json 读写
├── .claude/
│   └── skills/                    # Layer A：Skill（新建）
│       ├── spec-analyze/SKILL.md
│       ├── spec-nl/SKILL.md
│       ├── spec-acsl/SKILL.md
│       ├── spec-verify/SKILL.md
│       ├── spec-repair/SKILL.md
│       ├── spec-term/SKILL.md
│       ├── spec-pipeline/SKILL.md
│       └── shared/                # 共享提示词资产
│           ├── hoare_rules.md     # ← 抽自 FM-Agent md/system_prompt.md
│           ├── acsl_fewshot/      # ← 抽自 AutoSpec+ src/prompt/
│           └── nl2acsl_examples/  # ⏸ 暂不做，正式开始前确认是否需要
│
├── autospec+/                     # 代码采石场：仅供编码期抽取，抽完可移除
└── FM-Agent/                      # 代码采石场：仅供编码期抽取，抽完可移除
```

---

## 8.5 运行环境：复用现成 Docker 镜像（已确认）

AutoSpec+ 已提供配置好的 docker 镜像，里面 **veri-clang、frama-c（WP/Alt-Ergo/Z3）、openai 等库均已就绪**——这正是本方案的运行底座，无需我们再搭环境。

| 镜像 | 用途 |
|---|---|
| `junjiehu1905/acslagent:latest` | 主镜像：含 veri-clang、frama-c、Python/openai 等，跑主流程（analyze/verify/locate-fail/…） |
| `junjiehu1905/termination_analysis:latest` | 停机分析镜像：跑 `spec-term` / `spectool variant` |

**对设计的两点影响（相较初稿的修订）**：

1. **veri-clang 现成 → 静态分析模式从「高门槛可选」降级为「随手可用」**。§6.1 的双模式依然成立（短程仍默认直接读取，省 token、更快），但仓库级任务切到 veri-clang 时**没有额外安装成本**，可以放心依赖。
2. **`spectool` 设计为「在该镜像内运行」**。因此：
   - `spectool` 直接调用镜像里的 `frama-c` / `veri-clang` 可执行文件，路径稳定。
   - `spectool doctor` 的定位从「装没装齐」**转为「快速确认挂载与版本」**——检查工作目录是否正确挂载、`frama-c --version` / `veri-clang --version` 是否可执行、prover（Alt-Ergo/Z3）是否在 PATH，给 Claude 一个开工前的一键体检。

**推荐运行方式**（Skill 文档里会写明，让 Claude 知道在容器内操作）：
```sh
# 挂载当前工作区进容器，spectool 与源码、.spec/ 产物都在容器内可见
docker run -it --rm -v $(pwd):/app junjiehu1905/acslagent:latest /bin/bash
# 容器内：安装薄 CLI 后即可全局调用
pip install -e /app/spectool && spectool doctor --json
```

> **运行拓扑（已确认：方案 A）**：`spectool`、各 `SKILL.md` 与源码、`.spec/` 产物**全部随工作区挂载进容器**，由**容器内**的 Claude Code / 终端调用。`spectool` 直接调用容器里的 `frama-c` / `veri-clang`，无需 `docker exec` 转发——封装最简单、路径最稳定，也让 §5.5 的命令注册式 CLI 直接落地。

---

## 9. 关键设计决策小结（供确认）

1. **以符号验证为准**：Frama-C/WP 是唯一裁判，FM-Agent 的 LLM 推理降级为生成期自检，不替代验证。✅ 保住可信度。
2. **两段式生成**：先 NL 规约（Hoare Prompt）→ 再 NL→ACSL 翻译，比直接写 ACSL 更可控。✅ 这是融合的核心价值。
3. **双向混合（核心）**：自顶向下做需求分析定「该写多强」，自底向上做验证供给满足「Frama-C 模块化前提」；供需不匹配则 assume-guarantee 协商。✅ 治本地解决了自底向上的规约过强/过弱病（§2.4）。**首版只实现简化版——单遍自底向上 + spec-nl 看一层调用者**，完整两遍留待演进（§6.7）。
4. **LLM 调用从 Python 抽离，交还 Claude Code**：CLI 只留确定性工具活；编排由 Skill 指令 + Claude 完成，天然「轻量、可插拔」。
5. **修复带方向语义**：供给侧重译 / 需求侧上溯调用者改期望——靠自顶向下的 NL 中间层与 `serves:` 来由才成立。
6. **原项目仅作代码采石场**：可复用片段抽取 vendor 进 `spectool`，运行时不依赖原目录，自包含、可删。
7. **需新建的主要资产**：`spectool` CLI（命令注册式）、各 `SKILL.md`、共享提示词资产；NL↔ACSL 样例库暂缓。

---

## 10. 决策记录与待决问题

### 已确认
- ✅ **范围**：首版只做 **C + Frama-C**，FM-Agent 多语言能力不纳入（见「范围边界」）。
- ✅ **定位方式**：`spec-analyze` 双模式，默认 Claude 直接读取定位，veri-clang 静态分析作为仓库级任务的按需辅助（§6.1）。veri-clang 在现成 docker 镜像里，无安装成本（§8.5）。
- ✅ **Skill 粒度**：6 个原子 Skill + 1 个 pipeline。
- ✅ **CLI 形态**：单一入口 `spectool` + `argparse`（零依赖）+ `console_scripts` 全局可调 + JSON/stderr/退出码协议（§5.1）。**命令注册式工程结构**：外层 `SKILL.md`+`requirements.txt`+`pyproject.toml`，`commands/` 下一命令一文件自注册（§5.5）。
- ✅ **运行拓扑**：方案 A——`spectool` + `SKILL.md` + 源码 + `.spec/` 全部挂载进容器，容器内调用，直调 frama-c/veri-clang（§8.5）。
- ✅ **运行环境**：复用 `junjiehu1905/acslagent:latest` 与 `junjiehu1905/termination_analysis:latest` 镜像（含 veri-clang/frama-c/openai）。`spectool doctor` 改为「挂载与版本体检」（§8.5）。
- ✅ **NL→ACSL 样例库**：**首版暂不做**，先用 Claude 自身 ACSL 能力 + AutoSpec+ few-shot；列为「正式开始前需确认」项（见下）。
- ✅ **编排粒度**：**首版用单遍自底向上 + spec-nl 看一层调用者**；`plan.json` 首版只需 `verify_order`。完整两遍扫描 + 跨层需求上溯作为后续演进（§6.7）。
- ✅ **原项目定位**：仅作代码采石场，可复用片段抽取 vendor 进 `spectool`，运行时不依赖、可移除（§4）。

### 正式开始编码前需最终确认
1. **NL→ACSL 样例库是否要建**：取决于首版翻译质量实测。若 `spec-acsl` 经常翻错/翻得过强，则用 AutoSpec+ `experiment_results/` 里已验证通过的样本反向构造「NL↔ACSL」成对数据补强。**默认不建，需要时再启。**

> 下一步：可据本文档开始落地——先搭 `spectool` 骨架（§5.5 注册式结构）+ 各子命令适配，再写 6 个 `SKILL.md`（§6）。需要我把哪一部分展开到可直接编码的程度，告诉我。
