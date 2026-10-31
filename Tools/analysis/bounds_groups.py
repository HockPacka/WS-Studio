"""Which header bounding group matches the geometry bounds?  usage: bounds_groups.py [every-nth-file]"""
import collections
import glob
import math
import os
import statistics
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

H = 0x630
step = int(sys.argv[1]) if len(sys.argv) > 1 else 20
GROUPS = (0x390, 0x3D0, 0x410, 0x450, 0x4B0, 0x4F0)
contain = collections.Counter()
ratio = collections.defaultdict(list)
zero = collections.Counter()
tot = 0
cr = collections.defaultdict(list)
for f in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]:
    b = open(f, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    gc, go = struct.unpack_from('<QQ', b, 0x250)
    if not gc:
        continue
    ga = go + H
    gb = (ga + gc * 0xC8 + 15) & ~15
    mn = [1e9] * 3
    mx = [-1e9] * 3
    ok = True
    for g in range(gc):
        e = ga + g * 0xC8
        vc = struct.unpack_from('<I', b, e + 0x18)[0]
        vs = struct.unpack_from('<H', b, e + 0x1C)[0]
        t0 = b[e + 0x20]
        p0 = b[e + 0x2B]
        n, o = struct.unpack_from('<QQ', b, e + 0x38)
        base = gb + o
        if t0 not in (1, 2) or base + vc * vs > len(b):
            ok = False
            break
        for i in range(vc):
            p = base + i * vs + p0
            v = struct.unpack_from('<3f', b, p) if t0 == 1 else [x / 1024.0 for x in struct.unpack_from('<3h', b, p)]
            for k in range(3):
                mn[k] = min(mn[k], v[k])
                mx[k] = max(mx[k], v[k])
    if not ok or mn[0] > mx[0]:
        continue
    tot += 1
    vol = [max(mx[k] - mn[k], 1e-6) for k in range(3)]
    for a in GROUPS:
        gmin = struct.unpack_from('<3f', b, a)
        gmax = struct.unpack_from('<3f', b, a + 0x10)
        if all(x == 0 for x in gmin + gmax):
            zero[a] += 1
            continue
        if all(gmin[k] <= mn[k] + 0.01 and gmax[k] >= mx[k] - 0.01 for k in range(3)):
            contain[a] += 1
        ratio[a].append(math.prod(max(gmax[k] - gmin[k], 1e-6) / vol[k] for k in range(3)) ** (1 / 3))
        if a != 0x4F0:
            cen = struct.unpack_from('<3f', b, a + 0x20)
            rad = struct.unpack_from('<f', b, a + 0x30)[0]
            mid = [(gmin[k] + gmax[k]) / 2 for k in range(3)]
            cr[a].append(all(abs(cen[k] - mid[k]) < 0.01 + 1e-3 * abs(mid[k]) for k in range(3)))
            cr[a + 1].append(abs(rad - math.sqrt(sum(((gmax[k] - gmin[k]) / 2) ** 2 for k in range(3)))) < 0.02 * max(rad, 1))
print('models', tot)
for a in GROUPS:
    r = ratio[a]
    print('%03X zero %d  contains-vertex-bbox %d  volume ratio median %.3f  center=mid %.0f%%  radius=halfdiag %.0f%%' % (
        a, zero[a], contain[a], statistics.median(r) if r else -1, 100.0 * sum(cr[a]) / max(len(cr[a]), 1), 100.0 * sum(cr[a + 1]) / max(len(cr[a + 1]), 1)))
