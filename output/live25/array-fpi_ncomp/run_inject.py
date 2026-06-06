#!/usr/bin/env python3
import json
import subprocess
import sys

with open('/Users/hjj/coding/spec_cc_version/output/live25/array-fpi_ncomp/loops.json') as f:
    loops = f.read()

result = subprocess.run(
    [sys.executable, '-m', 'spectool.cli', 'inject',
     '--src', '/Users/hjj/coding/spec_cc_version/autospec+/LLM4Veri/dataset_test/live25/array-fpi_ncomp.c',
     '--out', '/Users/hjj/coding/spec_cc_version/output/live25/array-fpi_ncomp/array-fpi_ncomp.acsl.c',
     '--loops', loops],
    capture_output=True, text=True, timeout=30,
    env={'PYTHONPATH': '/Users/hjj/coding/spec_cc_version/spectool'}
)
print(json.dumps({"stdout": result.stdout, "stderr": result.stderr, "rc": result.returncode}))
