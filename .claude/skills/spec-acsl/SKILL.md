---
name: spec-acsl
description: 把自然语言规约（<fqn>.nl.md）正向推理地翻译为 ACSL（requires/ensures/assigns + loop invariant/assigns），并用 spectool inject 注入到正确位置，产出 <fqn>.acsl.c。自底向上验证供给的起点。
---

# spec-acsl：NL → ACSL 翻译（自底向上验证供给）

本方案最关键的新组件。自然语言规约已把「该证什么」固定下来，这一步只处理**形式化表达**，降低一步到位写 ACSL 的失败率。

## 必读
加载 `.claude/skills/shared/acsl_fewshot.md`（contract / loop invariant 成对样例 + NL→ACSL 对照表）。
> NL→ACSL 专用对照样例库**首版不建**——先用你自身的 ACSL 能力 + 这份 few-shot；若实测翻译质量不足再补（design §10）。

## 方向：自底向上
按 plan.json 的 `verify_order`（叶子在前）处理。被调者已先验证、契约在池中，作为本函数的 Frama-C `[INFO]` 前提。

## 步骤
1. 读目标契约 `<proj>/.spec/<fqn>.nl.md` 与函数代码。
2. 取被调者已验证 ACSL 契约：
   ```sh
   spectool contracts get-callees --proj <proj> --callees <dep...> --json
   ```
   翻译时假定这些契约成立（不要重证被调者）。
3. **正向推理地翻译**：
   - 每条 NL Pre → `requires`；每条 NL Post → `ensures`（用 `\result`、量词、蕴含表达「找到/没找到」等分情况）。
   - 函数副作用 → `assigns`（无副作用写 `assigns \nothing;`）。
   - 每个循环 → `loop invariant`（覆盖计数器范围 + 已建立的部分结果 + break 后的状态），**务必配齐 `loop assigns`**（循环体写过的所有左值——最常见的失败原因就是漏它）。
4. **注入**到正确位置：
   ```sh
   spectool inject --src <file.c> --out <proj>/.spec/<fqn>.acsl.c --func <fqn> \
     --acsl @<fqn>.contract.txt \
     --loops '[{"line":<循环语句行>,"acsl":"loop invariant ...; loop assigns ...;"}]'
   ```
   - `--acsl` 是函数契约（requires/ensures/assigns），放到函数签名上方。
   - `--loops` 每项 `line` 是循环语句在**原文件**中的 1-based 行号（来自 plan.json 的 loops）。
   - ACSL 文本可内联，或写到文件用 `@path` 传入（含特殊字符时更稳）。

## 产物
候选 `<proj>/.spec/<fqn>.acsl.c`，交给 spec-verify。

## 纪律
- 翻译要忠于 NL 规约的强度；不要顺手加 NL 里没有的约束（除非是为通过验证补的 `loop assigns`/`\valid` 这类形式化必需项）。
- 翻错/太强会在 spec-verify 暴露，由 spec-repair 带你回来重译——这是预期的供给侧循环。
