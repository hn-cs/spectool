#!/usr/bin/env python3
import json
import sys
import os

sys.path.insert(0, os.path.join(os.path.dirname(__file__), '../../../../spectool'))

from spectool.cli import main

# Prepare args
sys.argv = [
    'spectool.cli', 'inject',
    '--src', '/Users/hjj/coding/spec_cc_version/autospec+/LLM4Veri/dataset_test/live25/array-crafted_zero_sum_const3.c',
    '--out', '/Users/hjj/coding/spec_cc_version/output/live25/array-crafted_zero_sum_const3/array-crafted_zero_sum_const3.acsl.c',
    '--loops', open('/Users/hjj/coding/spec_cc_version/output/live25/array-crafted_zero_sum_const3/loops.json').read(),
]

main()
