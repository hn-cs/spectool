# 自然语言行为规约编写规则（Hoare Prompt）

> 抽取并精简自 FM-Agent `md/system_prompt.md`。`spec-nl` 在写自然语言 Pre/Post 时遵循这 7 条；目标是「描述意图与契约，不描述实现」，这样下一步 `spec-acsl` 翻译时只需处理形式化表达，不被实现细节带偏。

## Rule 1：写 WHAT，不写 HOW
描述函数对调用者的**保证**，而非如何实现。围绕这些维度：
- 数据结构不变式：大小、元素类型、有效范围、顺序
- 状态不变式：调用前/后必须成立的条件
- 结果契约：返回值性质、输入与输出的关系
- 输出格式契约：产出数据的形状/编码/模式
- 错误契约：在**什么确切条件**下抛出哪种错误
- 资源契约：所有权转移、分配/释放义务

## Rule 2：不要描述实现
不要：点名内部 helper 调用；描述分支选择（"如果 long 为真则……"）；枚举具体常量/配置键/查表项；命名性能微优化；按名字枚举 dispatch case——而应描述**支配规则**。

## Rule 3：不用模糊词
禁止："appropriate / correctly handles / as expected / processes / manages / properly / validates the input / handles the case"。每条断言都必须**可验证、可证伪**。
- BAD: "correctly parses the input string"
- GOOD: "returns the number of milliseconds corresponding to the numeric and unit parts of str"

## Rule 4：规约是 CALLER-DRIVEN（与本方案「自顶向下定强度」一致）
- 前置条件来自**调用者在调用前保证了什么**
- 后置条件来自**调用者从本函数需要什么**
- prompt 里若提供了调用者上下文，**务必使用**——这正是 `serves:` 字段的来源（§2.4）

## Rule 5：规约描述「意图中的正确行为」
- 实现可能有 bug；规约**不记录** bug。
- 若实现满足不了调用者所需，规约仍描述**调用者所需**——差距本身就是 bug。
- 把规约写成「一个理想正确实现必须满足的契约」。

## Rule 6：规约用于验证，而非重构
正确的规约应能让你**验证**实现、或写出另一个满足同契约的实现；但**不应**能据此重构出原实现。
- **石蕊测试**：若删掉某个分支/某次 helper 调用会让规约变错，则规约与实现耦合过紧，应改写为横切不变式。

## Rule 7：精确 = 支配规则，而非枚举
不要点名集合的具体成员（即便作为"例子"）。描述支配规则。
- BAD: "Dispatches to fmtShort or fmtLong based on options.long"
- GOOD: "Returns a short-form string when options.long is absent or false; a long-form string when true"

---

## 输出格式（C，注释前缀 `//`）

```
// [SPEC]
// Unit: <相对仓库根的文件路径>
//
// <FunctionName>(<params>) -> <ReturnType>
//
// Pre-condition:
//   - ...
//
// Post-condition:
//   - ...
//
// serves: <服务于哪条调用者义务——记录强度来由；叶子/顶层 API 可写 "top-level: <目标>">
// [SPEC]
```

> 速记：**问「无论哪个调用者、走哪条路径，返回后什么恒为真？」——那就是后置条件。**
