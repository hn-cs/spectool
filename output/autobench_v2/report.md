# spec-bottomup 评测报告

- **模型**：deepseek-v4-flash
- **日期**：2026-06-06
- **输入**：262 个 .c 文件（batch 评测）
- **总耗时**：3040s（~50.7 分钟）
- **总 Token 消耗**：1,371,650

## 总体结果

| 指标 | 值 |
|------|-----|
| pass@1 | 176/262 (67.2%) |
| pass@5 | 259/262 (98.9%) |
| 失败 | 3/262 (1.1%) |
| 平均修复轮数（仅 pass 案例） | 1.38 |
| 平均 token 消耗 | 5235 |
| 总 token 消耗 | 1,371,650 |
| 平均耗时 | 11.60 s |
| 总耗时 | 3040 s |

## 按轮次分布

| 轮次 | 通过数 | 占比 |
|------|--------|------|
| Round 0 | 7 | 2.7% |
| Round 1 | 176 | 68.0% |
| Round 2 | 57 | 22.0% |
| Round 3 | 13 | 5.0% |
| Round 4 | 2 | 0.8% |
| Round 5 | 3 | 1.2% |
| Round 6 | 1 | 0.4% |
| 未通过 | 3 | 1.1% |

## 失败案例列表

| 文件 | proved/total | token 消耗 | 错误类型 |
|------|-------------|-----------|---------|
| 208 | 3/7 | 15,000 | pow has no Frama-C builtin model (Builtin pow(float64,float64) not defined) causing timeouts on loop |
| 229 | 10/16 | 5,000 | order_3 swap bug at line 4: *b = *a; should be *b = temp; - causes both ensures to be unprovable and |
| 241 | 5/6 | 10,000 | Assertion at line 21 timeout: res == a + b not universally provable (fails for b < 0) |

## 备注

- Pass/Fail 校验规则：`status == pass` 且 `proved != total` → 修正为 fail；`status == fail` 且 `proved == total` → 修正为 pass
- 并发流水线：Workflow pipeline() 自动维持并发槽位
- 子 agent 超时兜底：120 秒
