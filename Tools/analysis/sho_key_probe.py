"""Probe: does the key table of an STGT .sho (table A at header u64[4] with u64[3] entries) line up with the blobs in order?
Correlates the bits of the nonzero keys (slot order) with the texture registers used by blob number = rank."""
import array
import re
import struct
import sys

sys.path.insert(0, 'tools/analysis')
import dxbc_dis as D  # noqa: E402

path = sys.argv[1]
n = int(sys.argv[2]) if len(sys.argv) > 2 else 1500
data = open(path, 'rb').read()
h = struct.unpack_from('<12Q', data, 0)
count, aoff = h[3], h[4]
A = array.array('I')
A.frombytes(data[aoff:aoff + count * 4])
keys = [(i, a) for i, a in enumerate(A) if a]
blobs = D.find_blobs(data)
print('nonzero keys', len(keys), 'blobs', len(blobs))
feat = []
for r in range(n):
    off, size = blobs[r]
    t = D.disassemble(data[off:off + size])
    regs = set(int(x) for x in re.findall(r'dcl_resource_texture\w+ \([^)]*\) t(\d+)', t))
    feat.append(regs)
import collections
for reg in range(16):
    best = []
    for bit in range(32):
        a = [(keys[r][1] >> bit) & 1 for r in range(n)]
        b = [1 if reg in feat[r] else 0 for r in range(n)]
        sa, sb = sum(a), sum(b)
        if sa in (0, n) or sb in (0, n):
            continue
        both = sum(1 for x, y in zip(a, b) if x and y)
        # phi coefficient
        n11, n10, n01 = both, sa - both, sb - both
        n00 = n - n11 - n10 - n01
        den = ((n11 + n10) * (n01 + n00) * (n11 + n01) * (n10 + n00)) ** 0.5
        phi = (n11 * n00 - n10 * n01) / den if den else 0
        best.append((abs(phi), bit, round(phi, 2)))
    best.sort(reverse=True)
    print('t%d' % reg, best[:3])
