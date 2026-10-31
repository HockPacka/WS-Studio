"""Show how decompiled engine code uses an M3 header slot.
usage: slot_uses.py <hexslot> [context-lines] [max-hits]   (reads docs/ghidra_slotfuncs.c + docs/_slot_funcs.json)"""
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
src = open(os.path.join(ROOT, 'docs', 'ghidra_slotfuncs.c'), encoding='utf-8', errors='replace').read()
funcs = {}
for m in re.finditer(r'^==== (\S+) @ (\S+) size \d+ ====\n(.*?)(?=^==== |\Z)', src, re.M | re.S):
    funcs[m.group(2)] = m.group(3)
slot = int(sys.argv[1], 16)
ctx = int(sys.argv[2]) if len(sys.argv) > 2 else 2
mx = int(sys.argv[3]) if len(sys.argv) > 3 else 12


def pats(v):
    return [r'(?<![0-9a-fA-Fx])0x%x(?![0-9a-fA-F])' % v, r'(?<![0-9a-zA-Z_])%d(?![0-9a-zA-Z_])' % v]


# pointer field = slot+8, count field = slot
want = pats(slot + 8)
want_cnt = pats(slot)
shown = 0
for fa, body in funcs.items():
    lines = body.split('\n')
    hit = [i for i, l in enumerate(lines) if any(re.search(p, l) for p in want) and ('+' in l or '*' in l)]
    if not hit:
        continue
    print('#### function', fa, 'hits', len(hit))
    last = -99
    for i in hit[:4]:
        if shown >= mx:
            break
        lo, hi = max(0, i - ctx), min(len(lines), i + ctx + 1)
        if lo <= last:
            lo = last + 1
        print('\n'.join('%5d| %s' % (k, lines[k]) for k in range(lo, hi)))
        print('   ...')
        last = hi
        shown += 1
    if shown >= mx:
        break
