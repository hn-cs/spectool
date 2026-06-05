# ...existing code...
import argparse
import json
import re
from pathlib import Path
from collections import defaultdict

RANGES = [
    ("1-133", 1, 133),
    ("134-179", 134, 179),
    ("180-231", 180, 231),
    ("231-251", 231, 251),
    ("252-257", 252, 257),
]


def analyze(jsonl_path: str):
    p = Path(jsonl_path)
    if not p.exists():
        raise FileNotFoundError(jsonl_path)

    counts = {label: defaultdict(int) for (label, _, _) in RANGES}
    details = {label: defaultdict(list) for (label, _, _) in RANGES}  # 新增：保存 0 与 Check 的具体文件名

    num_re = re.compile(r"(\d+)(?:\.c)?$")

    with p.open("r", encoding="utf-8") as f:
        for line_no, line in enumerate(f, start=1):
            line = line.strip()
            if not line:
                continue
            try:
                item = json.loads(line)
            except json.JSONDecodeError:
                continue

            filename = str(item.get("filename", ""))
            m = num_re.search(filename)
            if not m:
                continue
            n = int(m.group(1))

            raw_status = item.get("Status")
            key = None
            if raw_status == 1 or raw_status == "1":
                key = "1"
            elif raw_status == 0 or raw_status == "0":
                key = "0"
            elif str(raw_status).lower().startswith("check"):
                key = "Check"
            else:
                key = str(raw_status)

            for label, start, end in RANGES:
                if start <= n <= end:
                    counts[label][key] += 1
                    # 只在 0 或 Check 时记录具体文件名
                    if key in ("0", "Check"):
                        details[label][key].append(filename)

    # 输出结果（显示 Status 为 1、0、Check 的计数；并列出 0 与 Check 的具体文件名）
    for label, _, _ in RANGES:
        c = counts[label]
        d = details[label]
        zero_list = ", ".join(d.get("0", []))
        check_list = ", ".join(d.get("Check", []))
        print(f"{label}: 1={c.get('1',0)}  0={c.get('0',0)}  Check={c.get('Check',0)}")
        if zero_list:
            print(f"  0 files: {zero_list}")
        if check_list:
            print(f"  Check files: {check_list}")


def main():
    parser = argparse.ArgumentParser(description="分析 jsonl 中各区间 Status 统计")
    parser.add_argument("jsonl_path", help="输入 jsonl 文件路径")
    args = parser.parse_args()
    analyze(args.jsonl_path)


if __name__ == "__main__":
    main()
# ...existing code...