# spec-bottomup 评测报告 — live25

> ⚠️ 作弊文件已计为失败
- **模型**: deepseek-v4-flash
- **日期**: 2026-06-06
- **输入**: 360 个 .c 文件（live25）

## 总体结果

| 指标 | 值 |
|------|-----|
| 总文件数 | 360 |
| pass@1 | 227/360 (63.1%) |
| pass@5 | 297/360 (82.5%) |
| 失败（含作弊） | 63/360 (17.5%) |
| 其中作弊 | 43 |
| 平均 token 消耗 | 11762 |
| 总 token 消耗 | 4234247 |
| 平均耗时 | 27.1s |
| 总耗时 | 9756s |

## 按轮次分布

| 轮次 | 通过数 | 占比 |
|------|--------|------|
| Round 1 | 227 | 63.1% |
| Round 2 | 43 | 11.9% |
| Round 3 | 17 | 4.7% |
| Round 4 | 8 | 2.2% |
| Round 5 | 2 | 0.6% |
| 未通过（含作弊） | 63 | 17.5% |

## 失败案例（不含作弊）

| 文件 | proved/total | token | 错误描述 |
|------|-------------|-------|---------|
| array-cav19_array_doub_access_init_const | 0/0 | 0 | agent异常: sub-agent did not write any output |
| array-cav19_array_init_both_ends_multiple_sum | 0/0 | 0 | agent异常: sub-agent did not write any output |
| array-crafted_mapsum2 | 29/30 | 185000 | Assertion line 67: ret==ret2&&ret==ret5 times out (Z3/Alt-Ergo 120s). Requires proving mapsum_val(x, |
| array-examples_sanfoundry_24-1 | 15/17 | 4500 | Two assertions (lines 31,43) cannot be proved: assert((i % 2) == 0) and assert((i % 2) != 0) are not |
| array-examples_standard_init3_ground-2 | 33/33 | 6000 | ? |
| array-fpi_ifeqn3 | 31/33 | 98000 | 2 timeouts: loop_inv_5_preserved (relational b invariant) and assert_3 (b closed form after loop 2) |
| array-fpi_ifeqn4 | 29/29 | 12000 | ? |
| array-industry-pattern_array_of_struct_ptr_cond_init | 18/25 | 12478 | WP typed model cannot track malloc freshness with casts; 7 goals timed out in loop 1 (invariant pres |
| array-industry-pattern_array_of_struct_ptr_monotonic | 32/37 | 50000 | 5 loop assigns checks timeout (30s each) — WP internal Init tracking not matchable to ACSL loop assi |
| array-industry-pattern_array_ptr_single_elem_init-1 | 14/18 | 75000 | 4 loop assigns unproven (heap memory in first loop with malloc) |
| array-lopstr16_base_case | 26/27 | 65000 | Loop assigns timeout (prover performance on quantified existential) |
| array-multidimensional_copy-partial-3-u | 92/93 | 10000 | Assertion at line 136 not provable: the program partially copies B to A only for two cube regions ([ |
| array-programs_partial_mod_count_limited_gen | 27/28 | 80000 | Assertion on line 44 (j <= (N*(R-1))/(R*R)) timed out: counting argument for zero positions bound ca |
| array-tiling_mbpr2 | 35/36 | 75000 | Assertion at line 67: Z3 and Alt-Ergo timeout on quantifier-based parity reasoning (volArray[i] >= M |
| heap-data_min_max | 8/11 | 45000 | First loop invariant preservation timed out (inductive predicate all_in_range too complex for 60s);  |
| loop-invariants_odd | 6/8 | 80000 | lemma timeouts on universal bit_test; variant 0 generates unprovable false goal; assertion and invar |
| loop-lit_ddlm2013 | 14/16 | 18000 | 2 auxiliary post-branch assertions timeout (to_uint32 on j+1 expressions) |
| loop-lit_gcnr2008 | 14/15 | 15000 | ? |
| loop-lit_gsv2008 | 8/8 | 3500 | ? |
| loop-zilu_benchmark44_disjunctive | 5/6 | 42000 | Assertion x <= y + 16 is not universally provable: case A (x<0 && y<0) can increase x-y by 24, produ |

## 作弊案例

| 文件 |
|------|
| array-cav19_array_init_nondet_vars |
| array-crafted_bAnd1 |
| array-crafted_bAnd2 |
| array-crafted_bAnd3 |
| array-crafted_bAnd5 |
| array-crafted_bor1 |
| array-crafted_bor3 |
| array-crafted_bor4 |
| array-crafted_mapavg1 |
| array-crafted_mapavg2 |
| array-crafted_mapavg4 |
| array-crafted_mapsum3 |
| array-crafted_mapsum4 |
| array-crafted_xor1 |
| array-crafted_xor3 |
| array-crafted_xor4 |
| array-industry-pattern_array_of_struct_ptr_flag_init |
| array-industry-pattern_array_ptr_partial_init |
| array-lopstr16_break-1 |
| array-lopstr16_single_elem_safe |
| array-programs_partial_mod_count_limited_5 |
| array-tiling_nr2 |
| array-tiling_nr3 |
| array-tiling_pr3 |
| heap-data_calendar |
| heap-data_hash_fun |
| heap-data_packet_filter |
| heap-data_process_queue |
| heap-data_quick_sort_split |
| heap-data_running_example |
| heap-data_shared_mem1 |
| heap-data_shared_mem2 |
| loop-acceleration_diamond_1-1 |
| loop-invariants_bin-suffix-5 |
| loop-invariants_even |
| loop-invariants_mod4 |
| loop-zilu_benchmark28_linear |
| recursified_loop-crafted_recursified_simple_vardep_2 |
| recursified_loop-invariants_recursified_bin-suffix-5 |
| recursified_loop-invariants_recursified_even |
| recursified_loop-invariants_recursified_mod4 |
| recursified_loop-invariants_recursified_odd |
| reducercommutativity_max05-1 |
