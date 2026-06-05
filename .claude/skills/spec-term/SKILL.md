---
name: spec-term
description: （可选）停机分析——对已偏正确的循环生成 loop variant（非负且严格递减的整型表达式），用 spectool variant 注入并用 frama-c 验证，把偏正确性升级为完全正确性。
---

# spec-term：停机分析（可选增强）

在函数的 contract + loop invariant 已全部 Pass（偏正确性）之后运行，补 `loop variant` 证明循环停机（完全正确性）。

## 步骤
1. 列出缺 variant 的循环：
   ```sh
   spectool variant --src <proj>/.spec/<fqn>.acsl.c --out /tmp/_probe.c --json
   # -> {"loops":[...], "missing_variant":["for (...)","while (...)"]}
   ```
2. 对每个缺 variant 的循环，生成一个 **ranking function**：一个**非负整型**表达式，且每次迭代**严格递减**。
   - 常见形态：`n - i`（计数上行）、`hi - lo`（二分收缩）、剩余元素数等。
3. 注入并验证：
   ```sh
   spectool variant --src <proj>/.spec/<fqn>.acsl.c --out <proj>/.spec/<fqn>.term.c \
     --variants '[{"loop":"for (int i","variant":"n - i"}]' --verify --timeout 8 --json
   ```
   - `loop` 是用于匹配循环语句的子串；`variant` 可写表达式（会自动补成 `loop variant <expr>;`）或完整子句。
   - `--verify` 会在注入后直接跑 frama-c -wp。
4. 读 `verify.result`：
   - Pass → 完全正确性达成，可把 `.term.c` 作为该函数最终产物。
   - Fail → 多半 variant 不满足「非负」或「严格递减」；换一个表达式重试（可借 spec-repair 思路定位）。

## 复用来源
deterministic 注入逻辑来自 AutoSpec+ `termination/`（已 vendor 进 `spectool variant`）；variant 表达式由你生成（原项目里的 LLM 调用已抽走）。

## 纪律
- variant 必须同时满足非负 + 严格递减，二者缺一 WP 都不会过。
- 这是可选步骤；用户只要偏正确性时可跳过。
