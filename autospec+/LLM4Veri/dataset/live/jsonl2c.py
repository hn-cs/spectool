import argparse
import json
from pathlib import Path


def jsonl_to_c(jsonl_path: str, output_dir: str) -> None:
    jsonl_file = Path(jsonl_path)
    out_dir = Path(output_dir)
    out_dir.mkdir(parents=True, exist_ok=True)

    with jsonl_file.open("r", encoding="utf-8") as f:
        for line_no, line in enumerate(f, start=1):
            line = line.strip()
            if not line:
                continue

            try:
                item = json.loads(line)
            except json.JSONDecodeError as e:
                raise ValueError(f"第 {line_no} 行 JSON 解析失败: {e}") from e

            if "input" not in item:
                raise KeyError(f"第 {line_no} 行缺少 input 字段")
            if "filefolder_name" not in item:
                raise KeyError(f"第 {line_no} 行缺少 filefolder_name 字段")

            code = item["input"]
            safe_name = str(item["filefolder_name"]).replace("/", "_")
            filename = f"{safe_name}.c"
            out_path = out_dir / filename

            with out_path.open("w", encoding="utf-8", newline="\n") as c_file:
                c_file.write(code)

    print(f"已完成转换，输出目录: {out_dir}")


def main():
    parser = argparse.ArgumentParser(description="将 jsonl 中的 input 字段转换为 .c 文件")
    parser.add_argument("jsonl_path", help="jsonl 文件路径")
    parser.add_argument("output_dir", help="输出 c 文件的目录")
    args = parser.parse_args()

    jsonl_to_c(args.jsonl_path, args.output_dir)


if __name__ == "__main__":
    main()