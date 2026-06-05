# spectool — 确定性规约工具箱（Layer B）

> 支撑 `spec-*` 系列 Skill 的薄 CLI。**只做确定性/工具活，不调用 LLM**（语义/推理由 Claude 在 Skill 层完成）。stdout 输出 JSON、stderr 输出日志、退出码语义化。运行时只 subprocess 调用 frama-c / veri-clang 等外部二进制（由 acslagent 镜像提供）。

## 安装（在 acslagent 容器内）
```sh
pip install -e /app/spectool && spectool doctor --json
```

## 调用约定
- **stdout 仅 JSON**：解析它即可，不会被日志污染。
- **stderr 为人类日志**：调试用。
- **退出码**：`0` 成功 / `2` 外部工具缺失（frama-c/veri-clang/prover）/ `3` 输入错误。
- **状态落盘**：`<proj>/.spec/` 下 `plan.json`（任务+序）、`contracts.json`（已验证契约池）、每函数 `<fqn>.nl.md/.acsl.c/.wp.txt`。
- ACSL/JSON 类参数支持 `@path` 从文件读入（含特殊字符时更稳）。

## 子命令清单
| 子命令 | 作用 | 关键 I/O |
|---|---|---|
| `doctor` | 环境体检（frama-c/prover/veri-clang 是否就绪、工作区是否可写） | → `{ready, tools, missing}` |
| `analyze` | **仅仓库级**：veri-clang 静态分析，产 plan.json | `-f file.c --proj` → tasks + verify_order |
| `extract` | 抽取单个函数 / 列出全部函数（含行号） | `--src --func` → source + 行号 |
| `split-blocks` | 按花括号深度切块（供 Hoare 自检） | `--func @file --granularity` → blocks[] |
| `inject` | 把 ACSL 注入到函数契约位 / 循环前 | `--src --out --func --acsl --loops` → 注解后 .c |
| `verify` | **核心**：跑 frama-c -wp，解析 proved/total | `-f file.acsl.c --timeout --save-stdout` → `{result,proved,total}` |
| `locate-fail` | 解析 WP 输出定位失败 goal+行号（只读，不改源码） | `--wp --src` → failures[] |
| `parse-spec` | 解析 `[SPEC]`/`[INFO]` 注释块 | `-f file` → `{nl_spec, callees}` |
| `contracts` | 读写已验证契约池（get/put/get-callees/list） | `--proj --fqn --acsl ...` |
| `state` | 读写 plan.json 任务状态（show/set-status/next/init） | `--proj --fqn --status` |
| `variant` | 注入 loop variant 并（可选）验证停机 | `--src --out --variants --verify` |

## 设计出处
各子命令的确定性实现 vendor 自两个「代码采石场」（autospec+ / FM-Agent），清理后放在 `spectool/vendored/`，**不 import 原项目**。详见 docs/design.md §5。
