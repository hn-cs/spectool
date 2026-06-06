# spec-bottomup 批量评测总览

## 流程简介

本评测使用 **spec-bottomup** pipeline 对 C 程序进行**自底向上 ACSL 规约生成与验证**：

1. **spec-bottomup skill** —— 为 C 源文件中的每个循环自动生成 `loop invariant` / `loop assigns` / `loop variant` 等 ACSL 注解，并通过 `spectool` CLI（inject → verify → locate-fail → 修复）进行迭代验证
2. **Frama-C WP (27.1 Cobalt)** + **Alt-Ergo 2.6.2** + **Z3 4.15.4** 作为后端验证器
3. **Workflow pipeline** — 主 agent 通过 20 并发流水线派发子 agent，每个子 agent 独立处理一个 `.c` 文件
4. **作弊检测** — 自动扫描 `.acsl.c` 中的 `//@ admit` 违规使用（仅允许 `\valid` / `\separated` 内存声明），违规文件计为失败

## spec-bottomup 实验结果（deepseek-v4-flash）

| Benchmark | 总文件数 | 作弊 | pass@1 | pass@5 | 失败（含作弊） |
|-----------|---------|------|--------|--------|--------------|
| autobench_v2 | 257 | 6 | 172/257 (66.9%) | 244/257 (94.9%) | 13/257 (5.1%) |
| live24 | 284 | 2 | 196/284 (69.0%) | 268/284 (94.4%) | 16/284 (5.6%) |
| live25 | 360 | 43 | 227/360 (63.1%) | 297/360 (82.5%) | 63/360 (17.5%) |

> ℹ️ pass@n 的分母为各 benchmark 的总文件数。作弊文件直接计为失败，不排除出分母。
> live24 用的是较早版本，实际应有约 270 案例。

---

## 横向对比：autospec+ 不同模型在 autobench_v2 上的表现（pass@5）

| 模型 | pass@5 |
|------|--------|
| qwen3-235b | 150/257 (58.4%) |
| deepseek-v3.1 | 151/257 (58.8%) |
| kimi-k2 | 168/257 (65.4%) |
| gpt-4o | 157/257 (61.1%) |
| gpt5.5 | 229/257 (89.1%) |
| gemini2.5pro | 224/257 (87.2%) |
| **deepseek-v4-flash (autospec+)** | 176/257 (68.5%) |
| **deepseek-v4-flash (spec-bottomup)** | **244/257 (94.9%)** |

- spec-bottomup pass@5 = 94.9%，显著优于 autospec+ 最佳（gpt5.5 89.1%）
- autospec+ 中 gemini2.5pro / gpt5.5 表现最好（>87%）
- 相同模型 deepseek-v4-flash 下，spec-bottomup (94.9%) 远高于 autospec+ (68.5%)

---

## 横向对比：autospec+ 不同模型在 live24 上的表现

| 模型 | pass@1 | pass@5 |
|------|--------|--------|
| llama3.3 | 51.5% | 57.4% |
| qwen3-32B | 49.6% | 58.2% |
| Qwen3-32b-thinking | 51.6% | 64.4% |
| Deepseek-R1 | 55.1% | 65.6% |
| Deepseek-V3.2 | 60.7% | 67.0% |
| gpt5.5 | 60.3% | 76.2% |
| deepseek-v4-flash (autospec+) | 52.2% | 65.9% |
| **deepseek-v4-flash (spec-bottomup)** | **69.0%** | **94.4%** |

- spec-bottomup 在 live24 上 pass@5 达 94.4%，远高于 autospec+ 最佳（gpt5.5 76.2%）
- pass@1 也显著领先（69.0% vs autospec+ 最佳 Deepseek-V3.2 60.7%）

---

## 横向对比：autospec+ 不同模型在 live25 上的表现

| 模型 | pass@1 | pass@5 |
|------|--------|--------|
| llama3.3 | 17.8% | 21.7% |
| qwen3-32b | 15.6% | 22.2% |
| qwen3-32b-thinking | 16.5% | 23.9% |
| deepseek-r1 | 14.4% | 21.1% |
| deepseek-v3.2 | 22.6% | 25.8% |
| gpt5.5 | 40.8% | 51.6% |
| deepseek-v4-flash (autospec+) | 21.1% | 28.3% |
| **deepseek-v4-flash (spec-bottomup)** | **63.1%** | **82.5%** |

- live25 是所有模型最具挑战的数据集
- spec-bottomup 显著优于 autospec+：pass@1 63.1% vs 最佳 gpt5.5 40.8%，pass@5 82.5% vs 最佳 gpt5.5 51.6%
