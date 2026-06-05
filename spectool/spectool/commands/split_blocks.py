"""spectool split-blocks — split a function into brace-aware blocks for Hoare reasoning."""

import os

from ..registry import command
from ..io import emit_json, fail
from ..vendored import blocks


@command(name="split-blocks",
         help="Split a C function into brace-boundary-respecting blocks (for forward reasoning).")
def configure(parser):
    parser.add_argument("--func", required=True,
                        help="Function source: literal text, or @file to read from a file.")
    parser.add_argument("--granularity", type=int, default=blocks.DEFAULT_GRANULARITY,
                        help="Approx lines per block (default %d)." % blocks.DEFAULT_GRANULARITY)


def run(args):
    text = args.func
    if text.startswith("@"):
        path = text[1:]
        if not os.path.exists(path):
            fail("function file not found: %s" % path)
        with open(path, "r", encoding="utf-8", errors="replace") as f:
            text = f.read()

    chunks = blocks.split_into_blocks(text, granularity=args.granularity)
    emit_json({
        "blocks": chunks,
        "count": len(chunks),
    })
