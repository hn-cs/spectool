"""Inject a `loop variant` clause into an existing loop annotation block.

Extracted from autospec+/termination/src/generate_variant.py
(find_matching_brace / inject_variant / loop-pattern scan). The LLM call that
produced the variant string is removed — Claude supplies the variant text in the
skill layer; this module only places it correctly (before the closing `*/` of
the loop's annotation block), per Frama-C's positional rule.

No LLM calls.
"""

import re

_LOOP_PATTERN = re.compile(
    r"(/\*@[\s\S]*?\*/\s*)((?:while|for)\s*\(.*\))",
    re.MULTILINE,
)


def find_loops_missing_variant(source_text):
    """Return [{"loop": <stmt str>, "has_variant": bool, "ann_start": int,
               "ann_end": int}] for every annotated loop in the file."""
    out = []
    for m in _LOOP_PATTERN.finditer(source_text):
        ann = m.group(1)
        loop_stmt = m.group(2).strip()
        s, e = m.span(1)
        out.append({
            "loop": loop_stmt,
            "has_variant": "loop variant" in ann,
            "ann_start": s,
            "ann_end": e,
        })
    return out


def inject_variant_block(annotation_block, variant_string):
    """Insert `variant_string` just before the closing `*/`, preserving indent.

    The capture group may include trailing whitespace after `*/` (the regex ends
    with `\\s*`); we preserve it so the following statement keeps its separation.
    """
    end = annotation_block.rfind("*/")
    if end == -1:
        return annotation_block
    trailing = annotation_block[end + 2:]          # whitespace after the closing */
    before = annotation_block[:end].rstrip()
    last_nl = before.rfind("\n")
    indent_line = before[last_nl + 1:]
    indent = " " * (len(indent_line) - len(indent_line.lstrip()))
    vs = variant_string.strip()
    if not vs.endswith(";"):
        vs += ";"
    if not vs.startswith("loop variant"):
        vs = "loop variant " + vs.lstrip()
    return "%s\n%s%s\n%s*/%s" % (before, indent, vs, indent, trailing)


def inject_variants(source_text, variants):
    """Inject variants into the file.

    variants: list of {"loop": <substring to match the loop stmt>,
                       "variant": <expr or full clause>}
    Loops are matched by the first one whose statement contains the given
    `loop` substring and that lacks a variant. Applied back-to-front.
    """
    matches = list(_LOOP_PATTERN.finditer(source_text))
    # Build a plan: map each requested variant to a concrete match span.
    used = set()
    plan = []  # (ann_start, ann_end, new_block)
    for req in variants:
        needle = req.get("loop", "").strip()
        vtext = req.get("variant", "")
        if not vtext.strip():
            continue
        for k, m in enumerate(matches):
            if k in used:
                continue
            ann = m.group(1)
            loop_stmt = m.group(2)
            if "loop variant" in ann:
                continue
            if needle and needle not in loop_stmt:
                continue
            used.add(k)
            new_block = inject_variant_block(ann, vtext)
            plan.append((m.span(1)[0], m.span(1)[1], new_block))
            break

    content = source_text
    for start, end, new_block in sorted(plan, key=lambda x: x[0], reverse=True):
        content = content[:start] + new_block + content[end:]
    return content
