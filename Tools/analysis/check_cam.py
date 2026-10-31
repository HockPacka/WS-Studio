"""Relation between the 0x338 camera lookup table and the camera records (0x328): is +0 (u16) the ModelCamera id?"""
import collections
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

H = vb.H
rel = collections.Counter()
ex = []
for p in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True)):
    b = open(p, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    c, o = struct.unpack_from('<QQ', b, 0x328)
    n, t = struct.unpack_from('<QQ', b, 0x338)
    if not c or not n:
        continue
    cams = [struct.unpack_from('<HHIfIIIIIIIfff', b, o + H + k * 0x38) for k in range(c)] if False else None
    ids = [struct.unpack_from('<H', b, o + H + k * 0x38)[0] for k in range(c)]
    look = struct.unpack_from('<%dH' % n, b, t + H)
    for i, v in enumerate(look):
        if v == 0xFFFF:
            continue
        for d in (0, 1):
            if ids[v] == i + d:
                rel['id==index+%d' % d] += 1
        rel['total'] += 1
    if len(ex) < 3:
        ex.append((os.path.basename(p), ids, look))
print(rel)
for e in ex:
    print(e)
