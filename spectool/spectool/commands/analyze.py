"""spectool analyze — veri-clang static analysis: spec locations + bottom-up order.

REPO-SCALE ONLY. For short-range tasks the spec-analyze skill has Claude read
the source directly; this command is the optional fallback for large codebases
(docs/design.md §6.1). Writes plan.json under <proj>/.spec/.

veri-clang gives spec locations and loops but not a full dependency order; the
emitted verify_order here is the source order of leaves-first as reported, which
Claude may refine. (A precise call-graph order is a future enhancement.)
"""

import os

from ..registry import command
from ..io import emit_json, fail, EXIT_TOOL_MISSING
from ..vendored import clang_analyze
from .. import state


@command(name="analyze",
         help="[repo-scale] Run veri-clang to locate specs and emit plan.json.")
def configure(parser):
    parser.add_argument("-f", "--file", required=True, help="C file to analyze.")
    parser.add_argument("--proj", default=".", help="Project root (for .spec/plan.json).")
    parser.add_argument("--no-write", action="store_true",
                        help="Print plan to stdout but do not write .spec/plan.json.")


def run(args):
    if not os.path.exists(args.file):
        fail("input C file not found: %s" % args.file)

    try:
        spec_path = clang_analyze.run_veri_clang(args.file)
    except FileNotFoundError as e:
        # veri-clang missing, or it produced no SpecLoC.
        msg = str(e)
        code = EXIT_TOOL_MISSING if "not found" in msg and "binary" in msg else EXIT_TOOL_MISSING
        fail(msg, code=code)

    raw_tasks = clang_analyze.parse_specloc(spec_path)
    tasks = []
    for t in raw_tasks:
        tasks.append({
            "fqn": t["fqn"],
            "file": t["file"],
            "line": t["line"],
            "loops": t["loops"],
            "deps": [],            # veri-clang SpecLoC does not carry call deps here.
            "status": "pending",
        })
    verify_order = [t["fqn"] for t in tasks]  # leaves-first per veri-clang ordering

    plan = {"version": 1, "tasks": tasks, "verify_order": verify_order}
    if not args.no_write:
        state.save_plan(args.proj, plan)

    emit_json({
        "tasks": tasks,
        "verify_order": verify_order,
        "plan_file": None if args.no_write else state.plan_path(args.proj),
        "source": "veri-clang",
    })
