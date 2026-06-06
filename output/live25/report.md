# spec-bottomup 评测报告 — live25

- **模型**: deepseek-v4-flash
- **日期**: 2026-06-06
- **输入**: 360 个 .c 文件（live25 数据集）
- **处理**: Workflow pipeline, 20 并发

## 总体结果

| 指标 | 值 |
|------|-----|
| pass@1 | 234/360 (65.0%) |
| pass@5 | 334/360 (92.8%) |
| 失败/错误 | 24/360 (6.7%) |
| 平均修复轮数（仅 pass 案例） | 1.57 |
| 平均 token 消耗 | 11,762 |
| 总 token 消耗 | 4,234,247 |
| 平均耗时 | 27.1 s |
| 总耗时 | 9756 s (162.6 min) |
| 总 goals | 8607/8660 (99.4%) |

## 按轮次分布

| 轮次 | 通过数 | 占比 |
|------|--------|------|
| Round 0 | 2 | 0.6% |
| Round 1 | 234 | 65.0% |
| Round 2 | 50 | 13.9% |
| Round 3 | 24 | 6.7% |
| Round 4 | 15 | 4.2% |
| Round 5 | 9 | 2.5% |
| Round 6 | 1 | 0.3% |
| Round 10 | 1 | 0.3% |
| 未通过 | 24 | 6.7% |

## 失败案例列表

### Fail（proved < total）

| 文件 | proved/total | token 消耗 | 耗时(s) | 错误类型 |
|------|-------------|-----------|---------|---------|
| array-crafted_mapsum2 | 29/30 | 185,000 | 306.0 | Assertion line 67: ret==ret2&&ret==ret5 times out (Z3/Alt-Er |
| array-examples_sanfoundry_24-1 | 15/17 | 4,500 | 16.7 | Two assertions (lines 31,43) cannot be proved: assert((i % 2 |
| array-fpi_ifeqn3 | 31/33 | 98,000 | 65.0 | 2 timeouts: loop_inv_5_preserved (relational b invariant) an |
| array-industry-pattern_array_of_struct_ptr_cond_init | 18/25 | 12,478 | 601.0 | WP typed model cannot track malloc freshness with casts; 7 g |
| array-industry-pattern_array_of_struct_ptr_monotonic | 32/37 | 50,000 | 96.9 | 5 loop assigns checks timeout (30s each) — WP internal Init  |
| array-industry-pattern_array_ptr_partial_init | 24/25 | 500,000 | 216.0 |  |
| array-industry-pattern_array_ptr_single_elem_init-1 | 14/18 | 75,000 | 90.0 | 4 loop assigns unproven (heap memory in first loop with mall |
| array-lopstr16_base_case | 26/27 | 65,000 | 32.9 | Loop assigns timeout (prover performance on quantified exist |
| array-lopstr16_break-1 | 17/18 | 12,000 | 94.0 | Loop assigns sub-goal timeout on Call Effect consistency (Qe |
| array-lopstr16_single_elem_safe | 16/20 | 45,000 | 152.0 | Loop assigns timeouts on loop 1 (malloc effects not covered  |
| array-multidimensional_copy-partial-3-u | 92/93 | 10,000 | 190.3 | Assertion at line 136 not provable: the program partially co |
| array-programs_partial_mod_count_limited_gen | 27/28 | 80,000 | 17.4 | Assertion on line 44 (j <= (N*(R-1))/(R*R)) timed out: count |
| array-tiling_mbpr2 | 35/36 | 75,000 | 18.9 | Assertion at line 67: Z3 and Alt-Ergo timeout on quantifier- |
| array-tiling_nr2 | 32/34 | 18,000 | 280.0 | 2 loop assigns timeouts (outer loop): SMT solver cannot hand |
| heap-data_calendar | 10/12 | 150,000 | 64.3 | loop_assigns_timeout: linked list malloc effect not provable |
| heap-data_hash_fun | 15/17 | 20,000 | 19.8 | WP allocation tracking not implemented: loop assigns for mal |
| heap-data_min_max | 8/11 | 45,000 | 588.0 | First loop invariant preservation timed out (inductive predi |
| heap-data_running_example | 10/17 | 15,000 | 97.0 | 7 loop assigns timeouts on dynamic linked list heap writes - |
| loop-invariants_odd | 6/8 | 80,000 | 130.0 | lemma timeouts on universal bit_test; variant 0 generates un |
| loop-lit_ddlm2013 | 14/16 | 18,000 | 19.5 | 2 auxiliary post-branch assertions timeout (to_uint32 on j+1 |
| loop-lit_gcnr2008 | 14/15 | 15,000 | 18.8 |  |
| loop-zilu_benchmark44_disjunctive | 5/6 | 42,000 | 16.5 | Assertion x <= y + 16 is not universally provable: case A (x |

### Error（agent 异常）

| 文件 |
|------|
| array-cav19_array_doub_access_init_const |
| array-cav19_array_init_both_ends_multiple_sum |
