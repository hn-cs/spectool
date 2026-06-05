---
name: spec-pipeline
description: 端到端编排「生成—验证—修复」规约流水线。当用户要求为一个/一组 C 文件生成可被 Frama-C 证明的 ACSL 规约（function contract / loop invariant / loop variant）时使用。首版口径：单遍自底向上 + 自然语言规约只看一层调用者反推强度。
---

# spec-pipeline：规约生成总编排

你是这条流水线的**编排者**（替代了原 AutoSpec+ `main.py` 主循环）。按 §6.7「首版：单遍自底向上 + 一层向上看目标」推进。所有确定性工作交给 `spectool` CLI；语义/推理工作你自己做。

## 前置：环境体检
先运行一次，确认 frama-c 与 prover 就绪（在 acslagent 容器内）：
```sh
spectool doctor --proj <proj> --json
```
- `ready=false` 且缺 `frama-c`/prover → 停下，提示用户「需在 acslagent 镜像内运行」（见 design §8.5）。

## 步骤

### 0. 定位与排序（调用 spec-analyze）
得到 `verify_order`（叶子在前）与每个函数的 file:line、loop 行号，写入 `<proj>/.spec/plan.json`。
```sh
spectool state init --proj <proj> --plan @plan.json   # 写入任务清单
```

### 1. 逐函数循环（按 verify_order）
取下一个待处理函数：
```sh
spectool state next --proj <proj> --json     # -> {"next": "<fqn>", "done": false}
```
`done=true` → 跳到步骤 2。否则对该函数 `<fqn>`：

1. **取被调者已验证契约**（作为 Frama-C 的 [INFO] 前提）：
   ```sh
   spectool contracts get-callees --proj <proj> --callees <dep1> <dep2> --json
   ```
2. **写自然语言规约**（调用 **spec-nl**）：读 `<fqn>` 的代码 + **直接调用者**的调用点/已写目标，反推强度，产出 `<proj>/.spec/<fqn>.nl.md`（含 `serves:`）。
3. **翻译为 ACSL**（调用 **spec-acsl**）：NL + 被调者契约 → 注入 → `<proj>/.spec/<fqn>.acsl.c`。
4. **验证**（调用 **spec-verify**）：
   - Pass → `spectool contracts put` 入池；`spectool state set-status --fqn <fqn> --status passed`；回到步骤 1 取下一个。
   - Fail/Invalid → 进入 **spec-repair**（带方向语义的修复循环，预算默认 5 轮）。
5. **修复**（调用 **spec-repair**）：定位失败 → 判定供给侧/需求侧 → 重译或退化处理 → 回到本函数步骤 4。预算耗尽 → `state set-status --status unproved --reason "<最后WP报错>"`，**如实记录**，继续下一个函数（不阻塞整体）。

### 2. （可选）停机分析
对已偏正确、需完全正确性的循环，调用 **spec-term** 生成 loop variant 并验证。

### 3. 汇总报告
读 `spectool state show --proj <proj>`，输出每个函数 passed / unproved（及原因）、契约池位置。**不要谎报通过**：unproved 就如实说 unproved，附最后的 WP 失败 goal。

## 关键纪律
- **Frama-C 是唯一裁判**。你的推理只用于「生成」和「读报错决定怎么改」，绝不用于「替代验证」。
- **首版不做跨多层需求传播**：spec-nl 只看直接调用者一层。完整两遍扫描是后续演进，现在不要实现。
- **预算**：单函数修复最多 5 轮（对齐 MAX_ITERATION_TIMES / MAX_SPC_ITER）。
- 状态全部落盘在 `<proj>/.spec/`，支持断点续跑。
