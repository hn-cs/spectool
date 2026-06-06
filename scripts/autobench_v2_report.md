# spec-bottomup 评测报告 — autobench_v2

> ⚠️ 作弊文件已计为失败
- **模型**: deepseek-v4-flash
- **日期**: 2026-06-06
- **输入**: 257 个 .c 文件（autobench_v2）

## 总体结果

| 指标 | 值 |
|------|-----|
| 总文件数 | 257 |
| pass@1 | 172/257 (66.9%) |
| pass@5 | 244/257 (94.9%) |
| 失败（含作弊） | 13/257 (5.1%) |
| 其中作弊 | 6 |
| 平均 token 消耗 | 5318 |
| 总 token 消耗 | 1366650 |
| 平均耗时 | 11.6s |
| 总耗时 | 2973s |

## 按轮次分布

| 轮次 | 通过数 | 占比 |
|------|--------|------|
| Round 1 | 172 | 66.9% |
| Round 2 | 57 | 22.2% |
| Round 3 | 12 | 4.7% |
| Round 4 | 2 | 0.8% |
| Round 5 | 1 | 0.4% |
| 未通过（含作弊） | 13 | 5.1% |

## 失败案例（不含作弊）

| 文件 | proved/total | token | 错误描述 |
|------|-------------|-------|---------|
| 174 | 8/8 | 4500 | ? |
| 18 | 9/9 | 2500 | ? |
| 208 | 3/7 | 15000 | pow has no Frama-C builtin model (Builtin pow(float64,float64) not defined) causing timeouts on loop |
| 217 | 7/7 | 2000 | ? |
| 223 | 0/0 | 0 | input file not found: /Users/hjj/coding/spec_cc_version/autospec+/LLM4Veri/dataset_test/autobench/22 |
| 229 | 10/16 | 5000 | order_3 swap bug at line 4: *b = *a; should be *b = temp; - causes both ensures to be unprovable and |
| 241 | 5/6 | 10000 | Assertion at line 21 timeout: res == a + b not universally provable (fails for b < 0) |

## 作弊案例

| 文件 |
|------|
| 198 |
| 234 |
| 238 |
| 240 |
| 243 |
| 254 |
