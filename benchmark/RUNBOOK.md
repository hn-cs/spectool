# spec-bottomup 批量评测 Runbook

> 将此文件内容作为 prompt 交给主 Claude Code（装载 deepseek-v4-flash），由它编排子 agent 并行完成目录下全部 .c 文件的 ACSL 规约生成与验证。

## 你的角色

你是**主 agent**，只负责：
1. 扫描输入文件夹，列出所有 `.c` 文件并写入 JSON
2. 运行 Step 3.1 Python 脚本：验证文件 + 生成内嵌数据的 Workflow 脚本
3. 通过 Workflow pipeline 派发（20 并发流水线）
4. 从 Workflow 结果中收集数据
5. 执行 Pass/Fail 校验后汇总统计报告

**你不直接处理任何 .c 文件。** 所有 ACSL 生成、注入、验证、修复工作都由子 agent 完成。

## 输入

- **输入文件夹**：`/Users/hjj/coding/spec_cc_version/autospec+/LLM4Veri/dataset_test/live24`（文件数以 Step 1 实际扫描结果为准，目录中每个 `.c` 文件都会被处理）
- **输出目录**：`/Users/hjj/coding/spec_cc_version/output/live24`

## 输出目录结构规范

每个子 agent 必须为其处理的 .c 文件创建独立子文件夹，所有中间产物放在对应文件夹内。汇总文件放在输出目录最外层。

```
output/xxx/
├── results.jsonl          # 汇总结果（每行一条 JSON，含 token 消耗）
├── results.csv            # 汇总 CSV
├── report.md              # 最终报告
├── 1/                     # 文件 1.c 的独立文件夹
│   ├── 1.acsl.c           # 注入后的 ACSL C 文件
│   ├── 1.wp.txt           # Frama-C WP 原始输出
│   └── ...                # 其他中间产物
├── 10/                    # 文件 10.c 的独立文件夹
│   ├── 10.acsl.c
│   └── 10.wp.txt
└── ...
```

## 执行步骤

### Step 0：环境检查

```sh
PYTHONPATH=spectool python3 -m spectool.cli doctor
```

确认 `"ready": true`。如果不是，停止并报告。

#### Z3 检查与配置

Frama-C WP 需要 Z3 prover 配置在 why3.conf 中。检查方法：

```sh
why3 config list-provers | grep Z3
```

如果 Z3 未列出，执行：

```sh
# 1. 安装 Z3（如未安装）
brew install z3

# 2. 手动添加 Z3 到 why3.conf
cat >> ~/.why3.conf << 'EOF'

[prover]
name = "Z3"
path = "/opt/homebrew/bin/z3"
version = "4.12.0"
driver = "/Users/hjj/.opam/4.14.1/share/why3/drivers/z3_487.drv"

[prover]
name = "Z3 (noBV)"
path = "/opt/homebrew/bin/z3"
version = "4.12.0"
driver = "/Users/hjj/.opam/4.14.1/share/why3/drivers/z3_471_nobv.drv"
EOF
```

配置后重新验证：
```sh
why3 config list-provers
PYTHONPATH=spectool python3 -m spectool.cli doctor
```

### Step 1：扫描文件列表（写入 JSON，唯一数据源）

**必须**用 Python 扫描目录并写入 JSON 文件（禁止用 `ls` + shell 数组）。`os.listdir()` 会自动正确处理文件名中的空格，JSON 序列化保证后续读取完整无损。

```python
import os, json

INPUT_DIR = "..."   # 从环境变量或参数传入
files = []
for f in sorted(os.listdir(INPUT_DIR)):
    if f.endswith('.c'):
        name = f.replace('.c', '')
        path = os.path.join(INPUT_DIR, f)
        files.append({"name": name, "path": path})

with open('/tmp/benchmark_files.json', 'w') as fp:
    json.dump(files, fp, indent=2)

print(f"Total: {len(files)}")
```

记录总文件数 `TOTAL`。创建输出目录及子文件夹：

```sh
mkdir -p "$OUTPUT_DIR"
```

### Step 2：初始化结果文件

创建 `$OUTPUT_DIR/results.jsonl`，每行一条结果（由子 agent 追加）。
创建一个空的汇总变量或文件来跟踪进度。

### Step 3：流水线派发（Workflow pipeline）

**不再使用"等满一批 → 发下一批"模式。** 改为调用 Workflow 工具的 `pipeline()`，自动维持 20 个并发槽位：一个子 agent 完成任务后立即启动下一个，零等待空闲。

> ⚠️ **历史教训（连续 3 次事故）**：此前所有事故的根因都是**验证数据和执行数据不同**——Step 3.1 验证了 `/tmp/benchmark_files.json`（正确），但 Step 3.2 手写了一个不同的文件数组（错误）。以下 Step 3.1 和 3.2 已合并为单一流程，消除所有手工构造数据的可能。

#### 3.1 验证 + 生成可执行 Workflow 脚本（🔴 唯一一次构造数据）

**此步骤一次性完成所有数据准备工作。** 运行以下 Python 脚本，它会：
1. 读取 Step 1 的 JSON 文件
2. 对每条路径执行 A-F 验证
3. **将所有文件列表嵌入到 Workflow 脚本中并写入磁盘**
4. 输出最终调用指令

```python
import json, os, pwd, datetime
from pathlib import Path

INPUT_DIR = "..."   # 替换为实际输入目录
OUTPUT_DIR = "..."  # 替换为实际输出目录

# ====== 步骤 A-D：读取并验证 ======

with open('/tmp/benchmark_files.json') as f:
    files = json.load(f)
total = len(files)
print(f"[A] 从 JSON 读取到 {total} 个文件")

bad = [f for f in files if not os.path.isfile(f['path'])]
assert len(bad) == 0, f"发现 {len(bad)} 个文件在磁盘上不存在！第一个：{bad[0]}"
print(f"[B] ✅ 全部 {total} 个路径存在于磁盘")

wrong_dir = [f for f in files if not f['path'].startswith(INPUT_DIR)]
assert len(wrong_dir) == 0, f"发现 {len(wrong_dir)} 个路径不在输入目录内！"
print(f"[C] ✅ 全部路径指向正确的输入目录")

current_user = pwd.getpwuid(os.getuid()).pw_name
home_mismatch = [f for f in files if f'/Users/{current_user}/' not in f['path']]
assert len(home_mismatch) == 0, f"发现 {len(home_mismatch)} 个路径用户目录不符！"
print(f"[D] ✅ 全部路径用户目录一致 ({current_user})")

# ====== 步骤 E：打印前 5 条和后 5 条 ======

print("\n[E] 文件列表首尾确认:")
for f in files[:5]:
    print(f'  [前] {f["name"]} -> {f["path"]}')
for f in files[-5:]:
    print(f'  [后] {f["name"]} -> {f["path"]}')

# ====== 步骤 F：交叉验证文件名不重复且 name+'.c'==basename ======

from collections import Counter
name_counts = Counter(f['name'] for f in files)
dups = {k:v for k,v in name_counts.items() if v > 1}
assert len(dups) == 0, f"发现重复 name: {dups}"
print(f"[F] ✅ 所有 name 唯一")

name_mismatch = [f for f in files if f['name'] + '.c' != os.path.basename(f['path'])]
assert len(name_mismatch) == 0, f"name 与 basename 不匹配！第一个：{name_mismatch[0]}"
print(f"[F] ✅ 所有 name + '.c' == basename")

# ====== 最终安全检查 ======
# 再次全面验证——这次遍历的既是验证数据也是执行数据
all_ok = True
for f in files:
    if not os.path.isfile(f['path']):
        print(f'❌ 致命：文件不存在: {f["path"]}')
        all_ok = False
assert all_ok, "存在不存在的文件路径，立即中止！"

# ====== 生成 Workflow 脚本（文件列表嵌入在脚本中）======
# 
# 🔴🔴🔴 关键设计：文件列表由 Python 嵌入 JS 脚本文件，
# Workflow 调用时不再通过 args.files 传递。
# 主 agent 只能传入 inputDir 和 outputDir 两个短字符串。
# 这彻底消除了手写文件数组的可能。
# 🔴🔴🔴

WORKFLOW_SCRIPT = f'''export const meta = {{
  name: 'spec-bottomup-benchmark',
  description: '流水线式批量 ACSL 规约生成与验证',
  phases: [
    {{ title: '流水线处理' }},
    {{ title: '汇总报告' }},
  ],
}}

// ⚠️ 警告：此文件由 Step 3.1 Python 脚本在 {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')} 自动生成。
// 文件列表来源：Step 1 扫描 -> {Path('/tmp/benchmark_files.json').name} -> 验证通过后嵌入。
// 🔴 禁止手动修改 files 数组。如需修改，请重新运行 Step 3.1。

const EMBEDDED_FILES = {json.dumps(files, indent=2)};

const INPUT_DIR = args.inputDir;
const OUTPUT_DIR = args.outputDir;
const files = EMBEDDED_FILES;
const CONCURRENCY = 20;

phase('流水线处理');
log(`维持 ${{CONCURRENCY}} 并发流水线，处理 ${{files.length}} 个文件...`);

const results = await pipeline(
  files,
  (file) => {{
    const prompt = `请先调用 /spec-bottomup skill 加载 ACSL 规约生成的完整指令，然后在此任务参数下执行：

## ⚠️ batch 运行额外约束
1. 禁止翻阅无关资料
2. 不得修改原始 assert
3. 所有产物放在独立子文件夹
4. 结果 JSON 必须包含 tokens 字段
5. **禁止执行与验证无关的命令**（--help、版本检查、配置查看、环境安装等）。环境已就绪，只管执行 inject → verify → locate-fail → 修复。

## 任务参数
- 输入文件：${{file.path}}
- 输出目录：${{OUTPUT_DIR}}
- basename：${{file.name}}
- .acsl.c 路径：${{OUTPUT_DIR}}/${{file.name}}/${{file.name}}.acsl.c
- .wp.txt 路径：${{OUTPUT_DIR}}/${{file.name}}/${{file.name}}.wp.txt

## 结果输出
将结果 JSON **追加**写入 ${{OUTPUT_DIR}}/results.jsonl。最后一行输出必须为如下 JSON：
{{"file":"${{file.name}}","status":"pass|fail","round":N,"proved":M,"total":T,"elapsed_sec":S,"tokens":N,"error":null|"..."}}`;

    return agent(prompt, {{label: file.name}});
  }}
);

log('流水线处理完成');
'''

script_path = '/tmp/benchmark_workflow_script.js'
with open(script_path, 'w') as f:
    f.write(WORKFLOW_SCRIPT)

print(f'\n✅ 所有 {total} 个文件已通过一致性检查')
print(f'✅ Workflow 脚本已生成: {script_path}')
print(f'✅ 脚本已内嵌 {total} 个文件的完整数据')
print(f'\n>>> 下一步 Step 3.2 调用指令:')
print(f'    Workflow({{scriptPath: "{script_path}",')
print(f'              args: {{"inputDir": "{INPUT_DIR}", "outputDir": "{OUTPUT_DIR}"}}}})')
print()

# 准备工作
os.makedirs(OUTPUT_DIR, exist_ok=True)
with open(os.path.join(OUTPUT_DIR, 'results.jsonl'), 'w') as f:
    pass
print(f'✅ 输出目录已创建: {OUTPUT_DIR}')
print(f'✅ results.jsonl 已初始化')
```

**执行完毕后**，你会看到类似输出：

```
[A] 从 JSON 读取到 284 个文件
[B] ✅ 全部 284 个路径存在于磁盘
[C] ✅ 全部路径指向正确的输入目录
[D] ✅ 全部路径用户目录一致 (hjj)
[E] 文件列表首尾确认:
  [前] 21176_BL.EN.U4CSE21176_1 -> /Users/hjj/.../21176_BL.EN.U4CSE21176_1.c
  ...
  [后] upper_bound -> /Users/hjj/.../upper_bound.c
[F] ✅ 所有 name 唯一
[F] ✅ 所有 name + '.c' == basename

✅ 所有 284 个文件已通过一致性检查
✅ Workflow 脚本已生成: /tmp/benchmark_workflow_script.js
✅ 脚本已内嵌 284 个文件的完整数据

>>> 下一步 Step 3.2 调用指令:
    Workflow({scriptPath: "/tmp/benchmark_workflow_script.js",
              args: {"inputDir": "/Users/hjj/.../live24", "outputDir": "/Users/hjj/.../output/live24"}})
```

> 🔴 **关键保障**：此输出中的「前 5 条」和「后 5 条」你必须目视确认文件名看起来合理（没有从其他目录混入的无关文件、没有凭感觉瞎猜的文件名）。这是阻止假文件进入流水线的最后防线。

#### 3.2 调用 Workflow

**不要新建任何数据。** 直接使用 Step 3.1 输出的调用指令：

```js
Workflow({
  scriptPath: "/tmp/benchmark_workflow_script.js",
  args: {"inputDir": "...", "outputDir": "..."}
})
```

> 🚫 **禁止做以下任何操作**（每条都曾导致事故）：
> 1. ❌ 在 Workflow 调用的 `args` 中附加 `files` 字段——文件列表已内嵌在脚本中
> 2. ❌ 在 Workflow 脚本中使用 `args.files`——脚本中用的是 `EMBEDDED_FILES`
> 3. ❌ 手写任何文件路径——两个短字符串 `inputDir` 和 `outputDir` 足够

### Step 4：收集结果与 Pass/Fail 校验

Workflow 的 `pipeline()` 已在处理中自动收集所有结果。全部完成后：

1. **读取** `$OUTPUT_DIR/results.jsonl`，解析每行 JSON
2. **Pass/Fail 校验**（修正子 agent 可能返回的错误判定）：
   ```
   if status == "pass" and proved != total → 修正为 status = "fail"
   if status == "fail" and proved == total → 修正为 status = "pass"
   ```
   同时检查 JSON 格式完整性，缺失字段用默认值填充。
3. 如果子 agent 返回异常或没有有效 JSON，记录为：
   ```json
   {"file": "xxx.c", "status": "error", "round": 0, "proved": 0, "total": 0, "elapsed_sec": 0, "tokens": 0, "error": "agent异常描述"}
   ```
4. **作弊检测**（扫描 .acsl.c 中的 `//@ admit`）：
   - 对每个文件，检查其 .acsl.c 中的 `//@ admit`
   - 如果 `admit` 内容不是 `\valid` 或 `\separated`：
     - 属于**逻辑前提条件**（如 `\forall i,j; ... ==> a[i]<=a[j]`）→ 本应是 `requires`
     - 属于**直接断言**（如 `admit ret == 0`）→ 作弊绕过验证
     - 统一标记为 `"cheat"`，排除出 pass/fail 统计
5. 打印进度摘要：
   ```
   [完成] 总计 X/Y，pass@1: Z，pass@5: W，总耗时 T s
   ```

### Step 5：汇总报告

全部文件处理完成后，读取 `$OUTPUT_DIR/results.jsonl`，**先执行 Pass/Fail 校验**：

```python
for each line in results.jsonl:
    if line.status == "pass" and line.proved != line.total:
        line.status = "fail"  # 修正子 agent 的错误判定
    if line.status == "fail" and line.proved == line.total:
        line.status = "pass"  # 修正子 agent 的错误判定
```

然后计算统计指标：

```python
pass_at_1 = 第 1 轮就 pass 的数量 / TOTAL
pass_at_5 = 5 轮内 pass 的数量 / TOTAL
avg_rounds = 所有 pass 案例的平均轮数
avg_time = 所有案例的平均耗时
avg_tokens = 所有案例的平均 token 消耗
total_tokens = 所有案例的总 token 消耗
total_time = 所有案例的总耗时
```

生成汇总报告 `$OUTPUT_DIR/report.md`：

```markdown
# spec-bottomup 评测报告

- 模型：deepseek-v4-flash
- 日期：YYYY-MM-DD
- 输入：TOTAL 个 .c 文件

## 总体结果

| 指标 | 值 |
|------|-----|
| pass@1 | X/TOTAL (XX.X%) |
| pass@5 | Y/TOTAL (YY.Y%) |
| 平均修复轮数（仅 pass 案例） | Z.Z |
| 平均 token 消耗 | TTTT |
| 总 token 消耗 | TTTTTT |
| 平均耗时 | XX.X s |
| 总耗时 | XXXX s |

## 按轮次分布

| 轮次 | 通过数 | 占比 |
|------|--------|------|
| Round 1 | ... | ... |
| Round 2 | ... | ... |
| Round 3 | ... | ... |
| Round 4 | ... | ... |
| Round 5 | ... | ... |
| 未通过 | ... | ... |

## 失败案例列表

| 文件 | proved/total | token 消耗 | 错误类型 |
|------|-------------|-----------|---------|
| ... | ... | ... | ... |
```

同时输出 `$OUTPUT_DIR/results.csv`（方便后续分析）：
```csv
file,status,round,proved,total,elapsed_sec,tokens,error
xxx.c,pass,1,9,9,1.2,12345,
yyy.c,fail,5,3,7,45.6,67890,loop_inv preservation failed
```

## 关键约束

1. **流水线并发 20**：Workflow pipeline() 自动维持 20 个并发槽位，处理完一个立即启动下一个，零等待空闲
2. **子 agent 独立**：每个子 agent 只处理一个 .c 文件，互不依赖
3. **超时兜底**：如果单个文件 verify 超过 120 秒，视为 timeout
4. **主 agent 不做 ACSL 生成**：所有推理工作都在子 agent 中完成
5. **结果持久化**：每完成一条立即写入 results.jsonl，防止中途崩溃丢失进度
6. **子 agent 权限隔离**：子 agent 只允许读取输入目录（INPUT_DIR）中的文件，禁止翻阅外部目录
7. **断言不可变性**：所有原始 `//@ assert` 必须原样保留，允许添加辅助 assert 但不能修改或删除原始断言
8. **禁止无关命令**：子 agent 不得执行 --help、版本检查、环境安装等非验证命令
9. **Pass/Fail 校验**：主 agent 在汇总阶段必须校验 proved == total 才计为 pass，修正子 agent 的错误判定
10. **Admit 作弊检测**：`//@ admit` 仅限于 `\valid` / `\separated` 内存声明。扫描发现 admit 用于逻辑断言（如 `admit ret == 0`）立即判为 `cheat` 并排除统计
11. **文件列表由 Python 嵌入 Workflow 脚本**：不允许通过 `args.files` 传递文件列表。Step 3.1 的 Python 脚本会将验证后的文件数组直接嵌入生成的 `.js` 脚本中。主 agent 调用 Workflow 时只传 `inputDir` 和 `outputDir` 两个短字符串，彻底消除手写文件数组的入口。

## 🕳️ 历史陷阱记录

### 陷阱 #1：手写 file 数组导致假文件派发（首次犯）

**现象**：主 agent 派发了约 280 个文件到 Workflow，其中 238 个（85%）在目标目录中不存在。子 agent 全部报错。

**根因**：Step 1 用 python 正确扫描了目录，但 Step 3 派发 Workflow 时**没有从该 JSON 文件读取**，而是传入了另一个完全不同来源的文件列表。正确列表和错误列表的**交集为 0**。

### 陷阱 #2 ⚠️ 致命重犯（陷阱 #1 的精确复读）

**现象**：再次派发了大量不存在的文件。

**根因**：主 agent 凭记忆硬编码文件数组：
1. 用 `ls *.c` 的输出「目测」拼凑了文件名 → 猜错了数量和后缀
2. 混入了其他目录的无关文件
3. 路径中混入了错误用户目录

### 陷阱 #3：子 agent 执行无关命令

子 agent 在 verify 前执行 `--help`、版本检查等，浪费 token。已集成到子 agent prompt 约束中。

### 陷阱 #4 🆕 新发现：验证数据 ≠ 执行数据（与 #1/#2 同根同源）

> **此陷阱与 #1/#2 本质完全相同，但暴露出更隐蔽的失败模式：验证通过了正确的数据，但执行时用了另一份错误数据。**

**现象**：Step 3.1 验证 A-F 全部通过（`✅ 全部 284 个路径存在于磁盘`），但 Workflow 启动后子 agent 立即报错 `"input file not found"`。最终发现 12 个被派发的文件在磁盘上不存在。

**根因**：Step 3.1 验证了 `/tmp/benchmark_files.json`（**正确数据**），但 Step 3.2 调用 Workflow 时手写了 `args.files`（**错误数据**——主 agent 凭记忆猜测了 `21176_LogicFunction5`~`8` 和 `Asaithambi_*` 等不存在的文件名）。验证通过了正确的数据，但没有验证实际传给 Workflow 的数据。

```
/tmp/benchmark_files.json  ← 正确 (284 files)   ✅ Step 3.1 验证通过
         ↓
主 agent 手写 args.files    ← 错误 (含12个假文件)  ❌ Step 3.2 派发
         ↓
子 agent 找不到文件          ← 崩溃
```

**为什么之前的预防措施没有生效**：
- 陷阱 #1 的预防措施（从 JSON 读取）→ ❌ 主 agent 没有执行读取操作
- 陷阱 #2 的预防措施（不可硬编码）→ ❌ 主 agent 在验证通过后放松警惕，以为"验证过了就安全了"
- **根本原因：验证和派发之间没有任何数据传递契约。验证的数据和派发的数据是两份完全独立的数据结构，没有任何交叉校验。**

**预防措施（已集成到新版 Step 3）**：

1. **消除 `args.files` 参数**：Workflow 脚本不再通过 `args.files` 接收文件列表。文件数组由 Python 验证后直接嵌入 `.js` 脚本中的 `EMBEDDED_FILES` 常量。
2. **主 agent 只能传两个字符串**：Step 3.2 的 Workflow 调用只有 `inputDir` 和 `outputDir` 两个参数。主 agent 没有任何入口可以传入假文件。
3. **单一数据管道**：从 Step 1 的 `os.listdir()` 到 Step 3.1 的 Python 验证脚本，再到 `.js` 脚本中的内嵌数据，全程是同一份 Python 对象在流动。主 agent 只在最后一步转发脚本路径。

```
os.listdir()                      ← Step 1: 扫描目录
    ↓ json.dump
/tmp/benchmark_files.json         ← Step 1: 写入 JSON
    ↓ json.load
Python 内存中的 files 对象          ← Step 3.1: 读取
    ↓ 验证 A-F                     ← Step 3.1: 验证（验证的就是待执行的数据）
Python 内嵌到 .js 脚本              ← Step 3.1: 写入 EMBEDDED_FILES
    ↓
Workflow 读取 EMBEDDED_FILES       ← Step 3.2: 执行（手写文件数组的入口为零）
```

4. **防御性输出**：Step 3.1 Python 脚本末尾打印首尾 5 条文件名，主 agent 必须目视确认没有混入其他目录的文件。
