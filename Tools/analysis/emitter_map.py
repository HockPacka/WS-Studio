"""Consensus map of the emitter blob struct: positions of embedded DPs and scalar field statistics.
usage: emitter_map.py [every-nth-file] [struct size hex]"""
import collections
import math
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS)
sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
import halon  # noqa: E402
from validate_formats import inflate, PATCH, a16  # noqa: E402

step = int(sys.argv[1]) if len(sys.argv) > 1 else 10
S = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0xFF0
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]
files = []
while stack:
    d = stack.pop()
    files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3'))
    stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
blobs = []
types = collections.Counter()
with open(fs.data.name, 'rb') as a:
    for f in files[::step]:
        i, _ = fs.data.blocks[f.sha1]
        o, bs = fs.data.fs[i]
        a.seek(o)
        b = inflate(f, a.read(bs))
        c, off = struct.unpack_from('<QQ', b, 0x2F8)
        if not c:
            continue
        addr = off + 0x630
        base = a16(addr + c * 0xA0)
        els = []
        for k in range(c):
            e = addr + k * 0xA0
            t = struct.unpack_from('<I', b, e + 4)[0]
            bo = struct.unpack_from('<Q', b, e + 0x90)[0]
            if bo < 1 << 40:
                els.append((t, base + bo))
        for k, (t, bp) in enumerate(els):
            types[t] += 1
            if t == 0 and bp + S + 0x20 <= len(b):
                blobs.append(b[bp: bp + S + 0x400])
print('emitters by type', dict(types), '; type-0 blobs sampled', len(blobs))
N = len(blobs)
# DP consensus: position p (8-aligned) is DP if count in 1..64, key/val offsets multiples of 16, valOff-keyOff == a16(4*count)
dp_ok = collections.Counter()
dp_tot = collections.Counter()
for bl in blobs:
    for p in range(0x20, S - 23, 8):
        cnt, ko, vo = struct.unpack_from('<QQQ', bl, p)
        if cnt == 0 and ko == 0 and vo == 0:
            continue
        dp_tot[p] += 1
        if 1 <= cnt <= 4096 and ko % 16 == 0 and vo % 16 == 0 and vo - ko == a16(4 * cnt) and ko >= 0x10:
            dp_ok[p] += 1
dps = [p for p in sorted(dp_ok) if dp_ok[p] >= 0.8 * N]
# remove overlapping (keep first of overlapping runs of 24 B)
final = []
for p in dps:
    if not final or p >= final[-1] + 24:
        final.append(p)
print('embedded DPs found: %d' % len(final))
print('positions:', ' '.join('%X' % p for p in final))
covered = set()
for p in final:
    covered.update(range(p, p + 24))
# scalar classification of the rest
def isfloat(v):
    if v == 0:
        return False
    x = struct.unpack('<f', struct.pack('<I', v))[0]
    return math.isfinite(x) and 1e-6 < abs(x) < 1e7 and (v >> 23) & 0xFF != 0


out = []
for p in range(0, S, 4):
    if p in covered:
        continue
    cnt = collections.Counter(struct.unpack_from('<I', bl, p)[0] for bl in blobs)
    zero = cnt.get(0, 0) / N
    if zero > 0.995:
        continue
    fl = sum(c for v, c in cnt.items() if isfloat(v)) / N
    small = sum(c for v, c in cnt.items() if v < 0x10000) / N
    kind = 'F32' if fl > 0.7 else ('INT' if small > 0.9 else 'MIX')
    top = ', '.join('%s:%d%%' % ((('%.4g' % struct.unpack('<f', struct.pack('<I', v))[0]) if kind == 'F32' else ('%d' % v if v < 0x10000 else '0x%X' % v)), 100 * c // N) for v, c in cnt.most_common(4))
    out.append('+0x%03X %-3s zero %3d%% distinct %-5d %s' % (p, kind, zero * 100, len(cnt), top))
print('non-zero scalar dwords outside DPs:', len(out))
print('\n'.join(out))
