# spec-bottomup 评测报告 — live24

> ⚠️ 作弊文件已计为失败
- **模型**: deepseek-v4-flash
- **日期**: 2026-06-06
- **输入**: 284 个 .c 文件（live24）

## 总体结果

| 指标 | 值 |
|------|-----|
| 总文件数 | 284 |
| pass@1 | 196/284 (69.0%) |
| pass@5 | 268/284 (94.4%) |
| 失败（含作弊） | 16/284 (5.6%) |
| 其中作弊 | 2 |
| 平均 token 消耗 | 6819 |
| 总 token 消耗 | 1936582 |
| 平均耗时 | 12.0s |
| 总耗时 | 3407s |

## 按轮次分布

| 轮次 | 通过数 | 占比 |
|------|--------|------|
| Round 1 | 196 | 69.0% |
| Round 2 | 49 | 17.3% |
| Round 3 | 16 | 5.6% |
| Round 4 | 3 | 1.1% |
| Round 5 | 4 | 1.4% |
| 未通过（含作弊） | 16 | 5.6% |

## 失败案例（不含作弊）

| 文件 | proved/total | token | 错误描述 |
|------|-------------|-------|---------|
| 21176_LogicFunction | 11/12 | 6500 | Pre-condition a <= 0 not satisfiable in main (a=3 > 0), asserting fmin<=fmax requires a<=0 for linea |
| 21176_LogicFunction2 | 11/12 | 4000 | main calls check(3,4,7) with a=3>0, violating requires a<=0; assertion fmin<=fmax only provable when |
| arepina_distance_abs | 14/15 | 4000 | ? |
| arrays_and_loops_1 | 3/3 | 4000 | ? |
| code2_77 | 6/7 | 12000 | loop variant unprovable: while(unknown()) body does not guarantee progress on every iteration |
| corinnt_order_inc_max | 30/30 | 12000 | ? |
| corinnt_remainder | 9/9 | 25000 | ? |
| corinnt_sort-3 | 4/4 | 28000 | ? |
| count | 23/23 | 20000 | ? |
| evdenis_acsl-examples_10_rec | 10/10 | 3500 | ? |
| evdenis_small-examples_mod | 4/4 | 800 | ? |
| frama-c-wp-tutorial-en_10 | 10/11 | 45000 | Post-condition of order_3 (combined sortedness/sum/sumSq/membership) times out on SMT solvers in WP  |
| general_wp_problem_triangle_angles | 8/8 | 1500 | ? |
| pointers_add_pointers_3_vars | 12/12 | 8000 | ? |

## 作弊案例

| 文件 |
|------|
| replace_copy |
| stack_top_wd |
