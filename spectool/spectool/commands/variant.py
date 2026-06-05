"""spectool variant — inject loop variant clauses and re-verify termination."""

import os

from ..registry import command
from ..io import emit_json, fail, EXIT_TOOL_MISSING
from ..vendored import term, framac


def _read_arg(value):
    if value and value.startswith("@"):
        path = value[1:]
        if not os.path.exists(path):
            fail("referenced file not found: %s" % path)
        with open(path, "r", encoding="utf-8") as f:
            return f.read()
    return value


@command(name="variant",
         help="Inject loop variant(s) into annotated loops, optionally verify termination.")
def configure(parser):
    parser.add_argument("--src", required=True, help="Annotated C file (already has loop invariants).")
    parser.add_argument("--out", required=True, help="Output file with variants injected.")
    parser.add_argument("--variants", default=None,
                        help='JSON list (literal or @file): [{"loop":"<substr>","variant":"n-i"}]. '
                             "Omit to just list loops missing a variant.")
    parser.add_argument("--verify", action="store_true",
                        help="Run frama-c -wp on the result after injection.")
    parser.add_argument("--timeout", type=int, default=8)


def run(args):
    if not os.path.exists(args.src):
        fail("source file not found: %s" % args.src)
    with open(args.src, "r", encoding="utf-8", errors="replace") as f:
        source = f.read()

    variants_raw = _read_arg(args.variants)
    if not variants_raw:
        loops = term.find_loops_missing_variant(source)
        emit_json({
            "loops": [{"loop": l["loop"], "has_variant": l["has_variant"]} for l in loops],
            "missing_variant": [l["loop"] for l in loops if not l["has_variant"]],
        })

    import json
    try:
        variants = json.loads(variants_raw)
    except json.JSONDecodeError as e:
        fail("--variants is not valid JSON: %s" % e)

    annotated = term.inject_variants(source, variants)
    with open(args.out, "w", encoding="utf-8") as f:
        f.write(annotated)

    result = {"ok": True, "out": args.out, "injected": len(variants)}

    if args.verify:
        try:
            res = framac.run_framac_with_wp(args.out, timeout=args.timeout)
        except FileNotFoundError as e:
            fail(str(e), code=EXIT_TOOL_MISSING)
        proved, total = framac.parse_proved(res["result_type"])
        result["verify"] = {
            "result": framac.verdict_of(res["result_type"]),
            "proved": proved,
            "total": total,
            "raw_result_type": res["result_type"],
            "elapsed_sec": res["elapsed_sec"],
        }

    emit_json(result)
