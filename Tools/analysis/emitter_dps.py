"""Per-property statistics of the 139 embedded DPs of the particle emitter struct (type 0, struct size 0xFF0).
value stride = (next property's key offset - this value offset) / count  (nested arrays are laid out in table order)."""
import collections
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS)
sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
import halon  # noqa: E402
from validate_formats import inflate, PATCH, a16  # noqa: E402

POS = [int(x, 16) for x in '68 80 98 B0 C8 E0 F8 110 128 140 158 170 188 1A0 1B8 1D0 1E8 200 218 230 248 260 278 298 2B0 2C8 2E0 2F8 310 328 340 358 370 388 3A0 3B8 3D0 3E8 408 420 438 450 468 480 498 4B0 4C8 4E0 500 518 530 548 560 578 590 5A8 5C0 5D8 5F8 610 628 640 658 670 688 6A0 6B8 6D0 6F0 708 720 738 750 768 780 798 7B0 7C8 870 888 8A0 8B8 8D0 8E8 900 918 930 948 960 9A0 9B8 9D0 9E8 A00 A18 A30 A48 A60 A78 A98 AB0 AC8 AE0 AF8 B10 B28 B40 B58 B70 B90 BA8 BC0 BD8 BF0 C08 C20 C38 C50 C68 C88 CA0 CB8 CD0 CE8 D00 D18 D30 D48 D60 D80 D98 DB0 DC8 DE0 DF8 E10 E28 E40 E58'.split()]
S = 0xFF0
step = int(sys.argv[1]) if len(sys.argv) > 1 else 10
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]
files = []
while stack:
    d = stack.pop()
    files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3'))
    stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
stride = collections.defaultdict(collections.Counter)
cons = collections.defaultdict(lambda: {k: True for k in (1, 2, 3, 4, 6, 8, 12, 16)})
seen_multi = collections.Counter()
cnt = collections.defaultdict(collections.Counter)
vals = collections.defaultdict(lambda: collections.Counter())
keys1 = collections.defaultdict(collections.Counter)
n = 0
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
            if t == 0 and bo < 1 << 40:
                els.append(base + bo)
        for bp in els:
            if bp + S + 0x40 > len(b):
                continue
            nb = bp + S
            dps = [struct.unpack_from('<QQQ', b, bp + p) for p in POS]
            n += 1
            for idx, (cc, ko, vo) in enumerate(dps):
                cnt[idx][cc] += 1
                if cc == 0:
                    continue
                nxt = dps[idx + 1][1] if idx + 1 < len(dps) else None
                if nxt and cc > 0:
                    st = (nxt - vo) / cc
                    stride[idx][round(st, 2)] += 1
                    if cc > 1:
                        L = nxt - vo
                        seen_multi[idx] += 1
                        for sv in list(cons[idx]):
                            if not (cc * sv <= L < cc * sv + 16):
                                cons[idx][sv] = False
                if cc == 1:
                    raw = b[nb + vo: nb + vo + 4]
                    vals[idx][raw.hex()] += 1
print('emitters', n)
print('idx  pos  consistent strides (from multi-key samples)')
for idx in range(len(POS)):
    ok = [k for k, v in cons[idx].items() if v] if seen_multi[idx] else []
    top = ', '.join('%s:%d' % (k, v) for k, v in vals[idx].most_common(2))
    print('%3d %4X  multi=%-4d strides=%-14s %s' % (idx, POS[idx], seen_multi[idx], ok, top))
