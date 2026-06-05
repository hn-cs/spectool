---
name: spec-analyze
description: 定位 C 代码里的函数、循环、调用依赖，并排出自底向上（叶子在前）的处理顺序，产出 plan.json。双模式：默认 Claude 直接读源码定位（短程任务）；仓库级大代码切到 veri-clang 静态分析。
---

# spec-analyze：定位与排序（双模式）

产出统一格式的 `plan.json`（叶子在前的 `verify_order`），供 spec-pipeline 驱动。

## 模式选择
先估量规模，二选一：

### 默认模式 — 直接读取（短程任务，省 token、更快）
适用：单文件 / 少数几个文件、依赖关系能看清。**不依赖 veri-clang。**

1. 读源码，可用 CLI 帮你枚举函数与行号：
   ```sh
   spectool extract --src <file.c> --json     # -> functions[].{name,start_line,end_line}
   ```
2. 自己识别每个函数内的**循环行号**（for/while 语句所在行）和**调用依赖**（谁调用谁）。
3. 按依赖排**自底向上序**：被调者（叶子）在前，调用者在后。
4. 组装 plan.json：
   ```json
   {
     "tasks": [
       {"fqn":"helper","file":"foo.c","line":12,"loops":[],"deps":[],"status":"pending"},
       {"fqn":"main","file":"foo.c","line":30,"loops":[34],"deps":["helper"],"status":"pending"}
     ],
     "verify_order": ["helper","main"]
   }
   ```
5. 写入：`spectool state init --proj <proj> --plan @plan.json`

### 可选模式 — veri-clang 静态分析（仓库级任务）
触发判据（任一）：文件数多、总行数大到上下文装不下、跨文件依赖复杂、人工读取易漏，或用户显式要求。
```sh
spectool analyze -f <file.c> --proj <proj> --json
```
- 它用 veri-clang 产出 SpecLoC（函数位置 + 循环行号）并写 plan.json。
- 注意：当前 `analyze` 的 `deps` 为空、`verify_order` 为 veri-clang 报告序——你需要据调用关系**校正依赖与顺序**后再写回（`state init`）。

## 产物
两模式都产出同格式 plan.json；下游 skill 无感知差异。首版只需 `verify_order` 一个序（`demand_order` 留待完整两遍演进，现在不写）。
