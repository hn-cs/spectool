---
name: spec-verify
description: 用 frama-c -wp 验证注入了 ACSL 的 C 文件，解析 proved/total goals 判定 Pass/Fail/Invalid。Pass 则把契约写入契约池；Fail/Invalid 交给 spec-repair。Frama-C 是唯一确定性裁判。
---

# spec-verify：验证（确定性裁判）

## 步骤
1. 跑 WP，保存 stdout 供 locate-fail 用：
   ```sh
   spectool verify -f <proj>/.spec/<fqn>.acsl.c --timeout 8 \
     --save-stdout <proj>/.spec/<fqn>.wp.txt --json
   ```
2. 读返回 JSON 的 `result`：
   - **Pass**（proved == total）→ 契约入池，标记 passed：
     ```sh
     spectool contracts put --proj <proj> --fqn <fqn> \
       --signature "<函数签名>" --acsl @<fqn>.contract.txt --wp <raw_result_type>
     spectool state set-status --proj <proj> --fqn <fqn> --status passed
     ```
   - **Fail**（proved < total）→ 交给 **spec-repair**（带上 `<fqn>.wp.txt`）。
   - **Invalid** → frama-c 没能生成 goal（语法错/缺头文件/aborted）。先看 `hint` 与 `stderr_tail`：多半是注入位置或 ACSL 语法问题 → 交给 spec-repair 当作「表达问题」修。

## 退出码语义
- `0` 正常（无论 Pass/Fail，只要 frama-c 跑通就是 0；Pass/Fail 看 JSON 的 result 字段）。
- `2` frama-c 二进制缺失/不可用 → 停下，提示在 acslagent 容器内运行。
- `3` 输入文件不存在。

## 纪律
- **只有 `result==Pass` 才算通过**。Invalid 不是通过，Fail 不是通过。
- 不要为了「让它过」而删规约或放宽到平凡——那等于没验证。弱化必须有 `serves:` 依据（交给 spec-repair 判断）。
