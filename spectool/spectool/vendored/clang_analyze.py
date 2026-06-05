"""veri-clang static-analysis wrapper: emit SpecLoC + build a bottom-up order.

Extracted from autospec+/LLM4Veri/mark.py (RunClangCommand / GetSpecLoc /
TransformDict). Cleaned: removed the pickle-based task-marking machinery and the
dataset-specific preprocessing; kept just "run veri-clang, read SpecLoC.txt,
turn it into structured task dicts". This is the *optional* repo-scale locator
(docs/design.md §6.1) — the default path is Claude reading the source directly.

SpecLoC.txt line format (one per spec location):
    <func_name>===<file>:<func_line>===<loop_spec>
where <loop_spec> is "0" (no loops), a single line number, "@<n>" (outer loop),
or a comma-separated list.

No LLM calls. Invokes the external `veri-clang` binary.
"""

import os
import subprocess

VERI_CLANG_BIN = os.environ.get("SPECTOOL_VERI_CLANG", "veri-clang")
SPEC_FILE = "SpecLoC.txt"


def run_veri_clang(cfile, cwd=None):
    """Run veri-clang on `cfile`; returns the path to the produced SpecLoC.txt.

    Raises FileNotFoundError if the binary is missing or no SpecLoC is produced.
    """
    workdir = cwd or os.path.dirname(os.path.abspath(cfile)) or "."
    spec_path = os.path.join(workdir, SPEC_FILE)
    # Clean stale artifacts.
    for stale in ("tmp.o", SPEC_FILE):
        p = os.path.join(workdir, stale)
        if os.path.exists(p):
            try:
                os.remove(p)
            except OSError:
                pass

    cmd = [VERI_CLANG_BIN, "-O0", "-c", os.path.abspath(cfile), "-o", "tmp.o"]
    try:
        proc = subprocess.Popen(cmd, cwd=workdir, close_fds=True,
                                 stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        proc.communicate()
    except FileNotFoundError:
        raise FileNotFoundError(
            "veri-clang binary '%s' not found (run inside the acslagent image)" % VERI_CLANG_BIN
        )

    if not os.path.exists(spec_path):
        raise FileNotFoundError(
            "veri-clang did not produce %s for %s" % (SPEC_FILE, cfile)
        )
    return spec_path


def parse_specloc(spec_path):
    """Parse SpecLoC.txt into a list of task dicts.

    Each: {"fqn", "file", "line", "loops": [..], "outer_loops": [..]}
    """
    tasks = []
    with open(spec_path, "r", encoding="utf-8") as f:
        for raw in f:
            line = raw.strip()
            if not line or "===" not in line:
                continue
            parts = line.split("===")
            if len(parts) != 3:
                continue
            func_name, func_loc, loop_loc = parts
            if ":" not in func_loc:
                continue
            file_name, fline = func_loc.rsplit(":", 1)
            loops = []
            outer = []
            if loop_loc and loop_loc != "0":
                for tok in loop_loc.split(","):
                    tok = tok.strip()
                    if not tok:
                        continue
                    if tok.startswith("@"):
                        num = tok.replace("@", "")
                        if num.isdigit():
                            outer.append(int(num))
                            loops.append(int(num))
                    elif tok.isdigit():
                        loops.append(int(tok))
            tasks.append({
                "fqn": func_name,
                "file": os.path.basename(file_name),
                "line": int(fline) if fline.isdigit() else None,
                "loops": loops,
                "outer_loops": outer,
            })
    return tasks
