"""Infer where nested (count, offset) arrays and (count, keyOff, valOff) triples sit inside the elements of unknown header arrays.

For every slot and every 8-byte aligned position p inside the element we count over many models how often the 16 bytes at p look
like a valid array pointer (count>0, offset within file, base+offset aligned data) versus invalid, and likewise for triples.
Positions that are valid in 100 % of the cases in which the count is non-zero are reported.

usage: infer_nested.py [every-nth-file]"""
import collections
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
sys.path.insert(0, os.path.join(os.path.dirname(HERE), 'Halon'))
import halon  # noqa: E402
from validate_formats import inflate, PATCH, ROOT, a16  # noqa: E402

H = 0x630
SLOTS = {0x1E0: 0x98, 0x2A8: 0x10, 0x2B8: 0x28, 0x2F8: 0xA0, 0x308: 0x50, 0x318: 0x190, 0x328: 0x38, 0x4A0: 4, 0x510: 0x10, 0x540: 0x68,
         0x560: 0xA0, 0x570: 0x20, 0x588: 0x20, 0x598: 0x4C, 0x5A8: 2, 0x220: 0x46, 0x240: 0x70, 0x080: 0x30, 0x0F0: 0x1C}
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]
files = []
while stack:
    d = stack.pop()
    files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3'))
    stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
step = int(sys.argv[1]) if len(sys.argv) > 1 else 25
stat = collections.defaultdict(lambda: collections.Counter())
with open(fs.data.name, 'rb') as a:
    for f in files[::step]:
        i, _ = fs.data.blocks[f.sha1]
        o, bs = fs.data.fs[i]
        a.seek(o)
        b = inflate(f, a.read(bs))
        size = len(b)
        for slot, es in SLOTS.items():
            c, off = struct.unpack_from('<QQ', b, slot)
            if not c or c > 100000:
                continue
            addr = off + H
            base = a16(addr + c * es)
            if addr + c * es > size:
                continue
            for k in range(min(c, 60)):
                e = addr + k * es
                for p in range(0, es - 15, 8):
                    cnt, ofs = struct.unpack_from('<QQ', b, e + p)
                    key = (slot, p)
                    if cnt == 0:
                        if ofs == 0:
                            stat[key]['zero_ap'] += 1
                        continue
                    if cnt < 1 << 24 and base + ofs <= size and ofs % 1 == 0 and cnt * 1 + base + ofs <= size + 16:
                        stat[key]['valid_ap'] += 1
                    else:
                        stat[key]['invalid_ap'] += 1
                for p in range(0, es - 23, 8):
                    cnt, ko, vo = struct.unpack_from('<QQQ', b, e + p)
                    key = (slot, p)
                    if cnt == 0:
                        continue
                    if cnt < 1 << 20 and base + ko + 4 * cnt <= size and base + vo <= size and ko <= vo and vo - ko >= 4 * cnt:
                        stat[key]['valid_dp'] += 1
                    else:
                        stat[key]['invalid_dp'] += 1
res = {}
for (slot, p), c in sorted(stat.items()):
    va, ia, vd, idp = c['valid_ap'], c['invalid_ap'], c['valid_dp'], c['invalid_dp']
    if va >= 5 and ia == 0:
        res.setdefault('0x%X' % slot, []).append(('AP', hex(p), va, c['zero_ap']))
    if vd >= 5 and idp == 0:
        res.setdefault('0x%X' % slot, []).append(('DP', hex(p), vd))
for s, v in res.items():
    print(s, 'elem 0x%X' % SLOTS[int(s, 16)], v)
json.dump(res, open(os.path.join(ROOT, 'docs', 'm3_nested_inference.json'), 'w'), indent=1)
