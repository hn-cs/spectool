"""spectool state — read/update plan.json task status.

Lets the pipeline mark each task pending/passed/failed/unproved and resume.
"""

import os

from ..registry import command
from ..io import emit_json, fail
from .. import state as state_mod


_VALID_STATUS = ("pending", "passed", "failed", "unproved", "in_progress")


@command(name="state",
         help="Read/update plan.json task state: show | set-status | next.")
def configure(parser):
    parser.add_argument("action", choices=["show", "set-status", "next", "init"],
                        help="Operation to perform.")
    parser.add_argument("--proj", default=".", help="Project root (.spec/plan.json).")
    parser.add_argument("--fqn", default=None, help="Task FQN (for set-status).")
    parser.add_argument("--status", default=None, choices=_VALID_STATUS,
                        help="New status (for set-status).")
    parser.add_argument("--reason", default=None, help="Optional note (e.g. why unproved).")
    parser.add_argument("--plan", default=None,
                        help="For init: a plan.json (literal or @file) to write.")


def run(args):
    if args.action == "init":
        import json
        raw = args.plan
        if raw and raw.startswith("@"):
            path = raw[1:]
            if not os.path.exists(path):
                fail("plan file not found: %s" % path)
            with open(path, "r", encoding="utf-8") as f:
                raw = f.read()
        if not raw:
            fail("--plan required for init")
        try:
            plan = json.loads(raw)
        except json.JSONDecodeError as e:
            fail("--plan is not valid JSON: %s" % e)
        plan.setdefault("version", 1)
        for t in plan.get("tasks", []):
            t.setdefault("status", "pending")
        state_mod.save_plan(args.proj, plan)
        emit_json({"ok": True, "plan_file": state_mod.plan_path(args.proj),
                   "tasks": len(plan.get("tasks", []))})

    if args.action == "show":
        plan = state_mod.load_plan(args.proj)
        emit_json(plan)

    if args.action == "next":
        plan = state_mod.load_plan(args.proj)
        order = plan.get("verify_order") or [t["fqn"] for t in plan.get("tasks", [])]
        status = {t["fqn"]: t.get("status", "pending") for t in plan.get("tasks", [])}
        nxt = next((f for f in order if status.get(f, "pending") in ("pending", "in_progress")), None)
        emit_json({"next": nxt, "done": nxt is None})

    if args.action == "set-status":
        if not args.fqn or not args.status:
            fail("--fqn and --status required for set-status")
        fields = {}
        if args.reason:
            fields["reason"] = args.reason
        ok = state_mod.set_task_status(args.proj, args.fqn, args.status, **fields)
        if not ok:
            fail("task not found in plan: %s" % args.fqn)
        emit_json({"ok": True, "fqn": args.fqn, "status": args.status})
