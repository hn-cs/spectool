#!/usr/bin/env python3
"""
统计指定目录下，各子文件夹中使用 //@ admit 但不是
//@ admit \\valid 或 //@ admit \\separated 的 .acsl.c 文件数量。

用法:
    python scripts/count_admit.py <目标目录>
"""

import sys
import os
import re


# 定义需要排除的 admit 后继关键词
_EXCLUDED_ADMIT_SUFFIX = {r"\valid", r"\separated"}


def _has_bare_admit(content: str) -> bool:
    """
    判断内容中是否存在「裸 //@ admit」，即 //@ admit 后面紧跟的内容
    不是 \\valid 或 \\separated（包括 admit 后面直接跟 ; 或其他内容）。

    如果有多个 //@ admit，只要有一个不是 \\valid 或 \\separated 就返回 True。
    """
    # 匹配 //@ admit 后面可选的 \标识符（不含分号等标点）
    for m in re.finditer(r'//@\s+admit\b\s*(\\[a-zA-Z]+)?', content):
        suffix = m.group(1)  # 如 \valid / \separated，或 None（裸 admit）
        if suffix is None:
            return True   # 完全裸，后面没跟反斜杠关键词
        if suffix not in _EXCLUDED_ADMIT_SUFFIX:
            return True   # 跟了别的关键词（如 \unknown），也算裸
        # \valid 或 \separated → 符合排除条件，继续检查下一个匹配
    return False


def count_admit_files(root_dir: str) -> tuple[dict[str, int], list[str]]:
    """
    遍历 root_dir 下的所有子文件夹，对每个子文件夹：
      1. 查找后缀为 .acsl.c 的文件
      2. 如果没有则跳过
      3. 对每个 .acsl.c 文件，检测是否存在裸 //@ admit
         （即 //@ admit 后面不是 \\valid 或 \\separated）
      4. 统计该文件夹下有多少个 .acsl.c 文件包含裸 admit

    返回: ({ 文件夹名: 计数 }, [完整文件路径列表])
    """
    result: dict[str, int] = {}
    all_admit_files: list[str] = []

    for entry in sorted(os.scandir(root_dir), key=lambda e: e.name):
        if not entry.is_dir():
            continue

        folder = entry.name
        folder_path = entry.path

        # 收集该目录下所有 .acsl.c 文件
        acsl_files = [
            f.name for f in os.scandir(folder_path)
            if f.is_file() and f.name.endswith(".acsl.c")
        ]

        if not acsl_files:
            continue

        # 检测每个文件是否包含裸 //@ admit
        count = 0
        admit_files: list[str] = []
        for fname in acsl_files:
            fpath = os.path.join(folder_path, fname)
            try:
                with open(fpath, "r", encoding="utf-8", errors="replace") as f:
                    content = f.read()
                if _has_bare_admit(content):
                    count += 1
                    admit_files.append(fname)
                    all_admit_files.append(fpath)
            except Exception as e:
                print(f"  [警告] 无法读取 {fpath}: {e}", file=sys.stderr)

        if count > 0:
            result[folder] = count
            print(f"\n📁 {folder}/")
            print(f"   共 {len(acsl_files)} 个 .acsl.c 文件")
            print(f"   其中 {count} 个含有裸 //@ admit（非 \\valid 或 \\separated）:")
            for fname in admit_files:
                print(f"     - {fname}")

    return result, all_admit_files


def main():
    if len(sys.argv) < 2:
        print("用法: python scripts/count_admit.py <目标目录>", file=sys.stderr)
        sys.exit(1)

    root_dir = sys.argv[1]

    if not os.path.isdir(root_dir):
        print(f"错误: '{root_dir}' 不是有效的目录", file=sys.stderr)
        sys.exit(1)

    # 生成输出文件名：scripts/<目标目录名>_admit.txt
    dir_name = os.path.basename(os.path.normpath(root_dir))
    script_dir = os.path.dirname(os.path.abspath(__file__))
    out_path = os.path.join(script_dir, f"{dir_name}_admit.txt")

    print(f"🔍 扫描目录: {root_dir}")
    print("=" * 50)

    counts, admit_files = count_admit_files(root_dir)

    print("\n" + "=" * 50)
    total_files = len(admit_files)
    total_folders = len(counts)
    print(f"\n📊 总计:")
    print(f"   有 .acsl.c 子文件夹数: {total_folders}")
    print(f"   使用裸 //@ admit 的 .acsl.c 文件总数: {total_files}")

    # 写入结果到 txt 文件
    with open(out_path, "w", encoding="utf-8") as f:
        for filepath in admit_files:
            f.write(filepath + "\n")

    print(f"\n📄 结果已保存到: {out_path}")


if __name__ == "__main__":
    main()
