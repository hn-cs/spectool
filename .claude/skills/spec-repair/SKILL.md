---
name: spec-repair
description: 验证失败时的修复——用 spectool locate-fail 定位失败 goal 与行号，判断属于供给侧（ACSL 表达问题，原地重译）还是需求侧（目标契约不现实，退化处理），带方向语义地修复后回到 spec-verify。预算默认 5 轮。
---

# spec-repair：修复（供需协商，带方向语义）

对应 design §2.4 的 assume-guarantee 调和环：**ACSL 层重译 = 修供给，NL 层回传 = 调需求**。

## 步骤
1. **定位失败**（只读，不改源码）：
   ```sh
   spectool locate-fail --wp <proj>/.spec/<fqn>.wp.txt --src <proj>/.spec/<fqn>.acsl.c --json
   ```
   得到 `failures[]`，每项含 `goal / line / function / kind`（kind ∈ ensures/requires/assigns/loop_inv/loop_variant/assert/other）。
2. **逐条判定方向**：

   ### 供给侧 / ACSL 表达问题（首版主要走这条）
   症状：`kind=assigns`（漏 loop assigns 最常见）、loop_inv 缺一条、`requires` 太弱导致越界/溢出 goal、量词写错、Invalid（语法/注入位置错）。
   → **回 spec-acsl 原地重译该条**，方向不变（仍在自底向上层）：补 `loop assigns` / 加 `\valid` / 补不变式 / 修语法。重新 inject → 回 spec-verify。
   参考 acsl_fewshot.md 末尾「常见失败 → 修法」。

   ### 需求侧 / 目标契约不现实
   症状：`ensures` 反复证不动，且检查实现确实**给不出**被需求的强度（不是表达问题，是契约本身过强）。
   → **首版退化处理**（不做跨多层上溯）：
     - 让本函数自身加防御（如对入参加 `requires` 前置约束）；或
     - 弱化本函数 `ensures` 到实现真能保证的强度，并据 `serves:` **同步调整其直接调用者**的假设；或
     - 本地无法解决 → 标 `unproved` 并记录。
   > 完整的「沿调用链上溯任意层改需求」是两遍演进，首版不做。

3. **重验**：回到 spec-verify 跑 `verify`。Pass → 入池；仍 Fail → 下一轮（预算 -1）。

## 预算
默认 **5 轮**（对齐 MAX_ITERATION_TIMES / MAX_SPC_ITER）。耗尽仍不过：
```sh
spectool state set-status --proj <proj> --fqn <fqn> --status unproved \
  --reason "<最后一轮失败的 goal 与原因>"
```
**如实汇报，不强行通过**。继续处理下一个函数，不阻塞整体。

## 纪律
- 修复要带方向：先判供给/需求，再动手。盲目堆 ACSL 会越改越乱。
- 每轮只动「定位指出的那几条」，改完立即重验，保持小步可回溯。
