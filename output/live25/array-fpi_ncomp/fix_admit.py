#!/usr/bin/env python3
with open('/Users/hjj/coding/spec_cc_version/output/live25/array-fpi_ncomp/array-fpi_ncomp.acsl.c') as f:
    content = f.read()

old = '\t\t/*@\n\t  admit \\valid(a+(0 .. N-1));\n\t  admit \\valid(b+(0 .. N-1));\n\t  admit \\valid(c+(0 .. N-1));\n\t  admit \\separated(a+(0 .. N-1), b+(0 .. N-1), c+(0 .. N-1));\n\t*/\n'

new = '\t\t/*@ admit \\valid(a+(0 .. N-1)); */\n\t\t/*@ admit \\valid(b+(0 .. N-1)); */\n\t\t/*@ admit \\valid(c+(0 .. N-1)); */\n\t\t/*@ admit \\separated(a+(0 .. N-1), b+(0 .. N-1), c+(0 .. N-1)); */\n'

if old in content:
    content = content.replace(old, new)
    with open('/Users/hjj/coding/spec_cc_version/output/live25/array-fpi_ncomp/array-fpi_ncomp.acsl.c', 'w') as f:
        f.write(content)
    print('REPLACED')
else:
    print('NOT FOUND')
    # Debug: show what's around that area
    idx = content.find('/**')
    if idx != -1:
        print(repr(content[idx-30:idx+200]))
