"""spectool contracts — read/write the verified-contract pool (contracts.json).

The bottom-up "supply" side: leaves' verified contracts are stored here and
handed to callers as [INFO] prerequisites (docs/design.md §2.4, §3.3).
"""

import os

from ..registry import command
from ..io import emit_json, fail
from .. import state


@command(name="contracts",
         help="Read/write the verified-contract pool: get | put | get-callees.")
def configure(parser):
    parser.add_argument("action", choices=["get", "put", "get-callees", "list"],
                        help="Operation to perform.")
    parser.add_argument("--proj", default=".", help="Project root (.spec/contracts.json).")
    parser.add_argument("--fqn", default=None, help="Function name (for get/put).")
    parser.add_argument("--signature", default=None, help="Function signature (for put).")
    parser.add_argument("--acsl", default=None, help="Verified ACSL contract (literal or @file, for put).")
    parser.add_argument("--wp", default=None, help="WP result string e.g. Pass_5_5 (for put).")
    parser.add_argument("--callees", nargs="*", default=None,
                        help="Callee FQNs to fetch contracts for (get-callees).")


def _read_arg(value):
    if value and value.startswith("@"):
        path = value[1:]
        if not os.path.exists(path):
            fail("referenced file not found: %s" % path)
        with open(path, "r", encoding="utf-8") as f:
            return f.read()
    return value


def run(args):
    if args.action == "list":
        data = state.load_contracts(args.proj)
        emit_json({"contracts": data.get("contracts", {})})

    if args.action == "get":
        if not args.fqn:
            fail("--fqn required for get")
        data = state.load_contracts(args.proj)
        entry = data.get("contracts", {}).get(args.fqn)
        if entry is None:
            emit_json({"found": False, "fqn": args.fqn})
        emit_json({"found": True, "fqn": args.fqn, "contract": entry})

    if args.action == "get-callees":
        callees = args.callees or []
        found = state.get_callee_contracts(args.proj, callees)
        emit_json({"callees": found, "count": len(found)})

    if args.action == "put":
        if not args.fqn:
            fail("--fqn required for put")
        acsl = _read_arg(args.acsl) or ""
        entry = state.put_contract(
            args.proj, args.fqn,
            signature=args.signature or "",
            acsl=acsl,
            verified=True,
            wp=args.wp or "",
        )
        emit_json({"ok": True, "fqn": args.fqn, "contract": entry})
