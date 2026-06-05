"""Parse [SPEC] / [INFO] comment blocks out of an annotated source file.

Extracted from FM-Agent/src/parser.py. Kept the marker grammar and the
INFO-knowledge map; dropped the line-numbering / comment-stripping that fed the
LLM reasoner (the skill layer handles the code itself). Returns plain dicts so
the CLI can emit JSON.

Grammar (comment prefix is `//` for C):
    // [SPEC]
    // ... natural-language pre/post ...
    // [SPEC]
    // [INFO]
    // callee(sig) -> ret
    //   Pre: ...  Post: ...
    // [SPLIT]
    // ...
    // [INFO]
    <source>

No LLM calls.
"""

import re

_SECTION_RE = re.compile(r"^\s*(?:(?://+|#+|--+|%+)\s*)?\[(SPEC|INFO)\]\s*$")
_SPLIT_RE = re.compile(r"^\s*(?://+\s*)?\[SPLIT\]\s*$")


def _strip_comment_prefix(line):
    return re.sub(r"^(\s*)//+ ?", r"\1", line)


def _extract_section(lines, marker):
    start_idx = end_idx = None
    collected = []
    for index, line in enumerate(lines):
        m = _SECTION_RE.match(line)
        if m and m.group(1) == marker:
            if start_idx is None:
                start_idx = index
            else:
                end_idx = index
                break
            continue
        if start_idx is not None and end_idx is None:
            collected.append(_strip_comment_prefix(line))
    text = "\n".join(collected).strip() if end_idx is not None else ""
    return text, start_idx, end_idx


def _func_name(signature_line):
    m = re.search(r"([A-Za-z_][A-Za-z0-9_]*)\s*\(", signature_line)
    return m.group(1) if m else None


def _parse_info(section_text):
    if not section_text.strip() or section_text.strip() == "(no callees)":
        return []
    entries = []
    for raw in re.split(r"\n\s*(?://+\s*)?\[SPLIT\]\s*\n", "\n" + section_text + "\n"):
        raw = raw.strip()
        if not raw:
            continue
        entry_lines = [l.rstrip() for l in raw.splitlines() if l.strip()]
        if not entry_lines:
            continue
        name = _func_name(entry_lines[0])
        if name is None:
            continue
        entries.append({
            "function": name,
            "signature": entry_lines[0],
            "spec": "\n".join(entry_lines[1:]).strip(),
        })
    return entries


def parse_spec_file(path):
    """Return {"nl_spec": str, "callees": [{function,signature,spec}], "has_spec": bool}."""
    with open(path, "r", encoding="utf-8", errors="replace") as f:
        content = f.read()
    lines = content.splitlines()
    nl_spec, _, _ = _extract_section(lines, "SPEC")
    info_text, _, _ = _extract_section(lines, "INFO")
    callees = _parse_info(info_text)
    return {
        "nl_spec": nl_spec,
        "callees": callees,
        "has_spec": bool(nl_spec),
    }
