"""Brace-depth-aware function block splitter.

Extracted from FM-Agent/src/reasoner.py (_split_into_blocks_braced /
_compute_brace_depth_per_line / _split_into_blocks). Cleaned: GRANULARITY is a
parameter instead of a `from config import *` global, and the LLM reasoning that
consumed the blocks in the original is gone — only the deterministic splitter
remains (Claude does the Hoare reasoning in the skill layer, docs/design.md §5.4).
"""

DEFAULT_GRANULARITY = 40


def _split_plain(func, granularity):
    lines = func.strip().split("\n")
    total = len(lines)
    if total <= granularity:
        return [func.strip()]
    blocks = []
    i = 0
    while i < total:
        remaining = total - i
        if remaining <= granularity * 2:
            blocks.append("\n".join(lines[i:]))
            break
        end = i + granularity
        blocks.append("\n".join(lines[i:end]))
        i = end
    return blocks


def _brace_depth_per_line(lines):
    depths = []
    depth = 0
    for line in lines:
        i = 0
        n = len(line)
        while i < n:
            ch = line[i]
            if ch == '"':
                i += 1
                while i < n:
                    if line[i] == "\\":
                        i += 2
                        continue
                    if line[i] == '"':
                        i += 1
                        break
                    i += 1
                continue
            if ch == "'":
                i += 1
                while i < n:
                    if line[i] == "\\":
                        i += 2
                        continue
                    if line[i] == "'":
                        i += 1
                        break
                    i += 1
                continue
            if ch == "/" and i + 1 < n and line[i + 1] == "/":
                break
            if ch == "/" and i + 1 < n and line[i + 1] == "*":
                i += 2
                while i < n:
                    if line[i] == "*" and i + 1 < n and line[i + 1] == "/":
                        i += 2
                        break
                    i += 1
                continue
            if ch == "{":
                depth += 1
            elif ch == "}":
                depth -= 1
            i += 1
        depths.append(depth)
    return depths


def split_into_blocks(func, granularity=DEFAULT_GRANULARITY):
    """Split a C function body into blocks that respect `{...}` boundaries.

    Each block is roughly `granularity` lines but only ever cut at a point where
    brace depth has returned to the function's entry depth, so a block never ends
    mid-statement/mid-scope.
    """
    raw_lines = func.strip().split("\n")
    total = len(raw_lines)
    if total <= granularity:
        return [func.strip()]

    # Strip an optional "Line N: " prefix some callers add.
    stripped = []
    for line in raw_lines:
        if line.startswith("Line "):
            colon = line.find(":", 5)
            if colon != -1:
                line = line[colon + 1:].lstrip()
        stripped.append(line)

    depths = _brace_depth_per_line(stripped)
    entry_depth = depths[0] if total else 0
    if entry_depth == 0:
        entry_depth = next((d for d in depths if d > 0), 0)
    if entry_depth == 0:
        return _split_plain(func, granularity)

    blocks = []
    i = 0
    while i < total:
        remaining = total - i
        if remaining <= granularity * 2:
            blocks.append("\n".join(raw_lines[i:]))
            break
        target = i + granularity
        split_point = -1
        for j in range(target, total):
            if depths[j] == entry_depth:
                split_point = j
                break
        if split_point == -1:
            blocks.append("\n".join(raw_lines[i:]))
            break
        blocks.append("\n".join(raw_lines[i:split_point + 1]))
        i = split_point + 1
    return blocks
