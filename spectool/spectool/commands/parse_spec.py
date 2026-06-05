"""spectool parse-spec — parse [SPEC]/[INFO] comment blocks into structured JSON."""

import os

from ..registry import command
from ..io import emit_json, fail
from ..vendored import specmark


@command(name="parse-spec",
         help="Parse [SPEC]/[INFO] comment blocks out of an annotated source file.")
def configure(parser):
    parser.add_argument("-f", "--file", required=True, help="Annotated source file.")


def run(args):
    if not os.path.exists(args.file):
        fail("file not found: %s" % args.file)
    result = specmark.parse_spec_file(args.file)
    emit_json(result)
