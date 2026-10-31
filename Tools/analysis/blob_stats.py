"""Blob sizes and dword class map of the effect blobs pointed to by AP 0x2F8 elements (+0x90).
usage: blob_stats.py [every-nth-file]"""
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
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]
files = []
while stack:
    d = stack.pop()
    files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3'))
    stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
sizes = collections.defaultdict(collections.Counter)
blobs = collections.defaultdict(list)
with open(fs.data.name, 'rb') as a:
    for f in files[::step]:
        i, _ = fs.data.blocks[f.sha1]
        o, bs = fs.data.fs[i]
        a.seek(o)
        b = inflate(f, a.read(bs))
        c, off = struct.unpack_from('<QQ', b, 0x2F8)
        if not c:
            continue
        es = 0xA0
        addr = off + 0x630
        base = a16(addr + c * es)
        els = []
        for k in range(c):
            e = addr + k * es
            t = struct.unpack_from('<I', b, e + 4)[0]
            starts = []
            for p in (0x20, 0x38, 0x50):
                cc, ko, vo = struct.unpack_from('<QQQ', b, e + p)
                if cc:
                    starts += [ko, vo]
            blob = struct.unpack_from('<Q', b, e + 0x90)[0]
            els.append((t, starts, blob))
        for k, (t, starts, blob) in enumerate(els):
            if blob >= 1 << 40:
                continue
            # next nested start of the following element
            if k + 1 < len(els) and els[k + 1][1]:
                nxt = min(els[k + 1][1])
                if nxt > blob:
                    sizes[t][nxt - blob] += 1
                    if len(blobs[(t, nxt - blob)]) < 400 and base + blob + (nxt - blob) <= len(b):
                        blobs[(t, nxt - blob)].append(b[base + blob: base + nxt])
for t, cnt in sorted(sizes.items()):
    print('emitter type', t, 'blob sizes', cnt.most_common(8))


def isfloat(v):
    if v == 0:
        return False
    x = struct.unpack('<f', struct.pack('<I', v))[0]
    return math.isfinite(x) and 1e-6 < abs(x) < 1e7 and (v >> 23) & 0xFF != 0


for key, lst in sorted(blobs.items(), key=lambda kv: -len(kv[1]))[:3]:
    t, size = key
    print('=== type %d blob size %d (0x%X)  samples %d' % (t, size, size, len(lst)))
    n = size // 4
    cls = []
    for p in range(n):
        vs = [struct.unpack_from('<I', x, p * 4)[0] for x in lst]
        cnt = collections.Counter(vs)
        zero = cnt.get(0, 0) / len(vs)
        fl = sum(c for v, c in cnt.items() if isfloat(v)) / len(vs)
        small = sum(c for v, c in cnt.items() if v < 0x10000) / len(vs)
        k = 'Z' if zero > 0.98 else ('F' if fl > 0.7 else ('I' if small > 0.9 else 'M'))
        cls.append((k, len(cnt), cnt.most_common(2)))
    # run-length print
    i = 0
    while i < n:
        j = i
        while j + 1 < n and cls[j + 1][0] == cls[i][0] and (cls[i][0] in 'ZF'):
            j += 1
        ex = cls[i][2]
        exs = ', '.join(('%.4g' % struct.unpack('<f', struct.pack('<I', v))[0]) if cls[i][0] == 'F' else ('%d' % v if v < 0x10000 else '0x%X' % v) for v, _ in ex)
        print('+0x%04X..0x%04X %-1s %-5d distinct=%d  e.g. %s' % (i * 4, j * 4 + 3, cls[i][0], j - i + 1, cls[i][1], exs))
        i = j + 1
