"""For every u16/u32 field of a header array: which array of the same model does it index into?
usage: field_ref_test.py slot(hex) elemsize [every-nth-file]
Reports, per 2-byte field, the share of values (excluding 0xFFFF) that are < count(array) for the best fitting arrays and where max(value) == count-1."""
import collections
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

slot = int(sys.argv[1], 16)
es = int(sys.argv[2], 0)
step = int(sys.argv[3]) if len(sys.argv) > 3 else 1
ARR = {0x10: 'clips', 0x80: 'ap080', 0xF0: 'ap0F0', 0x180: 'bones', 0x1B0: 'boneMap', 0x1C0: 'textures', 0x1E0: 'ap1E0', 0x1F0: 'materials',
       0x200: 'ap200', 0x250: 'geometry', 0x260: 'ap260', 0x280: 'attach', 0x2B8: 'ap2B8', 0x2C8: 'sounds', 0x2F8: 'emitters', 0x308: 'ap308',
       0x318: 'lights', 0x328: 'cameras', 0x490: 'ap490', 0x560: 'ap560', 0x570: 'ap570', 0x588: 'ap588', 0x598: 'ap598'}
tot = collections.Counter()
below = collections.defaultdict(collections.Counter)
exact = collections.defaultdict(collections.Counter)
vmax = {}
for f in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]:
    b = open(f, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    c, o = struct.unpack_from('<QQ', b, slot)
    if not c or o + vb.H + c * es > len(b):
        continue
    counts = {n: struct.unpack_from('<Q', b, off)[0] for off, n in ARR.items()}
    gc, go = struct.unpack_from('<QQ', b, 0x250)
    mm = 0
    for g in range(gc):
        mm += struct.unpack_from('<Q', b, go + vb.H + g * 0xC8 + 0x80)[0]
    counts['meshes'] = mm
    for w in range(0, es - 1, 2):
        mx = -1
        for k in range(c):
            v = struct.unpack_from('<H', b, o + vb.H + k * es + w)[0]
            if v == 0xFFFF:
                continue
            tot[w] += 1
            mx = max(mx, v)
            for n, cn in counts.items():
                if v < cn:
                    below[w][n] += 1
        if mx >= 0:
            for n, cn in counts.items():
                if mx == cn - 1:
                    exact[w][n] += 1
for w in sorted(tot):
    best = sorted(below[w].items(), key=lambda kv: -kv[1])[:4]
    print('+%02X n=%d  ' % (w, tot[w]) + ', '.join('%s %.0f%%' % (n, 100.0 * v / tot[w]) for n, v in best) + '   | max==count-1: ' + ', '.join(
        '%s %d' % kv for kv in exact[w].most_common(3)))
