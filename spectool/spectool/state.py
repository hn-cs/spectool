"""Process-state I/O: plan.json + contracts.json under <proj>/.spec/.

These are the durable artifacts that let the pipeline resume and that carry the
bottom-up "verified contract pool" (docs/design.md §3.3). Pure file I/O; no
business logic, no LLM.

plan.json schema (v1, single-pass bottom-up — §6.7):
    {
      "version": 1,
      "tasks": [
        {"fqn": "helper", "file": "foo.c", "line": 12, "loops": [],
         "deps": ["..."], "status": "pending|passed|failed|unproved"},
        ...
      ],
      "verify_order": ["helper", "main"]   # leaves first
      # demand_order is reserved for the future full two-pass design.
    }

contracts.json schema:
    {
      "version": 1,
      "contracts": {
        "<fqn>": {"signature": "...", "acsl": "requires ...; ensures ...;",
                   "verified": true, "wp": "Pass_5_5"}
      }
    }
"""

import os
import json


SPEC_DIRNAME = ".spec"


def spec_dir(proj):
    d = os.path.join(proj, SPEC_DIRNAME)
    os.makedirs(d, exist_ok=True)
    return d


def _path(proj, name):
    return os.path.join(spec_dir(proj), name)


def plan_path(proj):
    return _path(proj, "plan.json")


def contracts_path(proj):
    return _path(proj, "contracts.json")


def _read_json(path, default):
    if not os.path.exists(path):
        return default
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)


def _write_json(path, obj):
    with open(path, "w", encoding="utf-8") as f:
        json.dump(obj, f, ensure_ascii=False, indent=2)
        f.write("\n")


# ----- plan.json -----

def load_plan(proj):
    return _read_json(plan_path(proj), {"version": 1, "tasks": [], "verify_order": []})


def save_plan(proj, plan):
    _write_json(plan_path(proj), plan)


def set_task_status(proj, fqn, status, **fields):
    plan = load_plan(proj)
    found = False
    for t in plan.get("tasks", []):
        if t.get("fqn") == fqn:
            t["status"] = status
            t.update(fields)
            found = True
            break
    save_plan(proj, plan)
    return found


# ----- contracts.json -----

def load_contracts(proj):
    return _read_json(contracts_path(proj), {"version": 1, "contracts": {}})


def save_contracts(proj, data):
    _write_json(contracts_path(proj), data)


def put_contract(proj, fqn, signature, acsl, verified=True, wp=""):
    data = load_contracts(proj)
    data.setdefault("contracts", {})[fqn] = {
        "signature": signature,
        "acsl": acsl,
        "verified": bool(verified),
        "wp": wp,
    }
    save_contracts(proj, data)
    return data["contracts"][fqn]


def get_callee_contracts(proj, callees):
    """Return the verified contracts for the given callee FQNs (for [INFO])."""
    data = load_contracts(proj)
    pool = data.get("contracts", {})
    out = {}
    for name in callees:
        if name in pool and pool[name].get("verified"):
            out[name] = pool[name]
    return out
