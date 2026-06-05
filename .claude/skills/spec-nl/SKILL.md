---
name: spec-nl
description: 为单个 C 函数生成自然语言行为规约（Pre/Post/关键不变式），遵循 Hoare Prompt 规则。自顶向下定强度：读直接调用者的需求反推「该保证多强」，记入 serves 字段。产物喂给 spec-acsl 翻译，不用于替代验证。
---

# spec-nl：自然语言规约生成（自顶向下需求分析 + Hoare Prompt）

这是从 FM-Agent 借来的「先想清楚 + 看目标」中间层。**只产自然语言**，下一步 spec-acsl 才翻成 ACSL。

## 必读
先加载规则：`.claude/skills/shared/hoare_rules.md`（7 条行为规约规则）。严格遵循「写 WHAT 不写 HOW、无模糊词、caller-driven」。

## 方向：自顶向下（首版只看一层）
给当前函数写 NL 前，**读它的直接调用者**：
- 调用者在调用点传入什么（→ 反推 Pre）、从返回值/副作用需要什么（→ 反推 Post）。
- 强度由「恰好够调用者用」校准——避免过强（自己实现不出）/过弱（调用者证不动）。
- 把「本契约服务于哪条调用者义务」写进 `serves:` 字段（强度来由，供 spec-repair 追溯）。
- 首版**不做**跨多层传播；只看直接调用者一层。叶子/顶层 API 没有调用者上下文时，按函数自身语义 + 公开意图写，`serves:` 记 `top-level: <目标>`。

## 步骤
1. 取函数代码（`spectool extract --src <file> --func <fqn>`）。
2. 取被调者已验证契约作为参考（`spectool contracts get-callees ...`），帮助理解本函数依赖了什么。
3. （函数较长时）切块自检：
   ```sh
   spectool split-blocks --func @<fqn>.c --granularity 40 --json
   ```
   对每块做 **Hoare 正向推理**（在脑内/文字里）：从 Pre 出发逐块推 Post，检查你写的后置条件是否覆盖所有路径（含 break/early return）。这是**自检**，不是验证。
4. 产出 `<proj>/.spec/<fqn>.nl.md`，格式见 hoare_rules.md 的输出格式（含 `serves:`）。

## 输出示例（求和函数）
```
// [SPEC]
// sum(int *a, int n) -> int
//
// Pre-condition:
//   - n >= 0
//   - a points to a readable array of at least n ints
//
// Post-condition:
//   - \result equals the sum of a[0..n-1]
//   - a is not modified
//
// 关键循环不变式（意图）：已累加前 i 项；i 在 [0,n] 内
//
// serves: 调用者 compute_total 需要「对输入数组求和且不改动数组」
// [SPEC]
```

## 纪律
- 描述**意图**，不描述实现细节（不点名内部分支/helper）。
- 不要在这一步写 ACSL——那是 spec-acsl 的事。
