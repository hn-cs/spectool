# spectool

为 C 程序自动生成可被 Frama-C 严格证明的 ACSL 规约（函数契约 / 循环不变式 / 循环变体），由 Claude Code 驱动。

## 整体策略：双路径 + 融合

```
任务进入
  │
  ▼
┌──────────────────────┐
│  Part 1：自底向上      │  ← 提炼 autospec+ 精髓，先跑一遍
│  (spec-bottomup)      │
└──────────┬───────────┘
           │
      全部通过？──Yes──▶ 结束 ✓
           │
           No（部分/全部失败）
           │
           ▼
┌──────────────────────┐
│  Part 2：自顶向下      │  ← 另一套策略，独立产出结果
│  (spec-topdown)       │     （暂未实现）
└──────────┬───────────┘
           │
           ▼
┌──────────────────────┐
│  Part 3：融合          │  ← 合并两份结果文件
│  (spec-fusion)        │     删除错的，保留对的，拼出最终版
└──────────┬───────────┘
           │
      最终验证 ──Pass──▶ 结束 ✓
```

### Part 1 — 自底向上（当前重点）

提炼 AutoSpec+ 的核心闭环，不依赖 clang 静态分析，由 Claude 直接承担代码理解：

1. **分析**：读源码，识别函数、循环、调用依赖，排出自底向上处理序
2. **生成 ACSL**：对每个函数/循环，直接生成 loop invariant / assigns / variant / 函数契约
3. **注入 + 验证**：`spectool inject` → `spectool verify`（Frama-C WP）
4. **修复**：失败时 `spectool locate-fail` 定位原因，调整 ACSL，最多 N 轮
5. **产出**：带 ACSL 注解的 `.acsl.c` 文件 + 验证结果

一个任务进来后先用 Part 1 跑一遍。如果全部 Pass，直接结束。

### Part 2 — 自顶向下（暂未设计）

当 Part 1 失败时进入。采用不同的推理路径（如 Hoare Prompt 先生成 NL 规约、自顶向下从调用者需求推强度等）。独立产出自己的 `.acsl.c` 结果文件。

### Part 3 — 融合

两份结果文件（Part 1 的和 Part 2 的）都可能部分正确、部分错误。融合阶段：

1. 对比两份注解文件中每个函数/循环的 ACSL
2. 分别验证，**删除错的，保留对的**
3. 尝试从两份中拼出一个能通过完整验证的最终版

## 架构

```
Layer A — Claude Code Skills
  └── spec-bottomup    Part 1：自底向上闭环（已实现）

Layer B — spectool CLI（确定性工具箱）
  └── doctor / extract / inject / verify / locate-fail

外部工具 — frama-c 27.1 + Alt-Ergo + Z3
```

Claude 做推理决策，spectool 做确定性工作（注入、验证、解析），互不越界。

## 目录结构

```
spectool/
├── spectool/                   # Layer B：确定性 CLI 工具箱
│   ├── SKILL.md                # 工具能力清单 + 调用约定
│   ├── pyproject.toml
│   └── spectool/
│       ├── cli.py              # 入口
│       ├── registry.py         # @command 装饰器
│       ├── io.py               # JSON 输出 / 退出码
│       ├── commands/           # 一命令一文件（doctor/extract/inject/verify/locate_fail）
│       └── vendored/           # 核心模块（cextract/framac/inject/locate）
├── .claude/skills/             # Layer A：Claude Code Skills
│   └── spec-bottomup/          # Part 1 自底向上 skill
├── tests/cases/                # 测试用例（来自 live25 benchmark）
├── autospec+/                  # 代码采石场（参考用）
└── FM-Agent/                   # 代码采石场（参考用）
```

## 环境安装

### 依赖

- macOS / Linux
- Frama-C 27.1 + Alt-Ergo + Z3（通过 opam）
- Python >= 3.8

### 安装步骤

```sh
# 1. 安装 opam（macOS）
brew install opam
opam init --auto-setup --yes --bare

# 2. 创建 OCaml switch 并安装 Frama-C + Alt-Ergo
opam switch create frama-c-27 ocaml-base-compiler.4.14.2 --yes
eval $(opam env --switch=frama-c-27)
brew install autoconf gmp graphviz zlib
opam install frama-c.27.1 alt-ergo --yes

# 3. 安装 Z3 + 配置 why3
brew install z3
why3 config detect

# 4. 安装 spectool CLI
cd spectool && pip install -e .
# 或：PYTHONPATH=spectool python3 -m spectool.cli --help
```

## spectool CLI 用法

stdout 输出 JSON，stderr 输出日志，退出码：0 成功 / 2 工具缺失 / 3 输入错误。

```sh
spectool doctor                           # 环境自检
spectool extract --src f.c                # 列出所有函数
spectool extract --src f.c --func main    # 抽取单个函数
spectool inject --src f.c --out f.acsl.c \
  --func main --acsl @spec.acsl \
  --loops '[{"line":10,"acsl":"..."}]'    # ACSL 注入
spectool verify -f f.acsl.c --timeout 10  # Frama-C 验证
spectool locate-fail --wp wp.txt --src f.acsl.c  # 失败定位
```

## 已验证的发现（14 个测试 case）

| 问题 | 影响 | 应对 |
|------|------|------|
| 无括号 `for` 循环的注解位置 | 注解放在 `for(...)` 和 body 之间导致语法错误 | 必须放在 `for` 关键字之前（inject 自动处理） |
| malloc 指针有效性 | WP 无法自动推导 `\valid` / `\separated` | 需要 `//@ admit` 声明 |
| 跨循环数组知识传递 | 后续循环无法自动继承前序循环的数组不变式 | 显式将数组知识作为后续循环的不变式 |
| VLA 数组分离性 | 多个栈上 VLA 数组的分离性无法自动推导 | 需要 `//@ admit \separated(...)` 声明 |
| 双倍索引的不变式表达 | `a[2*j]` 和 `a[2*j+1]` 形式可能导致推导困难 | 合并为 `a[j]` 线性索引形式 |

## 测试用例

`tests/cases/` 下的已验证案例：

| 编号 | 名称 | 特点 |
|------|------|------|
| 06 | dual_var | while 循环、双变量、代数关系 |
| 07 | algebraic_identity | 无括号 for 循环、VLA 数组 |
| 08 | recurrence | malloc 指针、递推关系 |
| 09 | three_loops | VLA 分离性、跨循环知识传递 |
| 10 | cubic_recurrence | malloc、三次递推、多循环依赖 |
| 11 | array_index_value | 条件断言、模运算不变式 |
| 12 | pair_sum_const | 三 VLA 数组、\separated |
| 13 | doub_access | 双倍索引、线性化不变式 |
| 14 | zero_sum_malloc | malloc、累加归零 |