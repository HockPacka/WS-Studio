"""Field statistics for one rare M3 slot over all models.  usage: block_stats.py slot(hex) [every-nth-file]
For every element: distribution of the 4-byte words that are not covered by nested AP/DP fields, nested counts, and leaf value statistics."""
import collections
import glob
import math
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

H = vb.H
slot = int(sys.argv[1], 16)
step = int(sys.argv[2]) if len(sys.argv) > 2 else 1
es, fields = vb.SPEC[slot]


def covered(fields):
    s = set()
    for off, kind, arg in fields:
        n = 16 if kind == 'ap' else 24
        s.update(range(off, off + n))
    return s


words = collections.defaultdict(collections.Counter)
counts = collections.defaultdict(collections.Counter)
leaf = collections.defaultdict(collections.Counter)
keys_first = collections.Counter()
nmod = nel = 0


def half(v):
    return struct.unpack('<e', struct.pack('<H', v))[0]


def walk(b, addr, count, es, fields, path, depth=0):
    base = vb.a16(addr + count * es)
    cov = covered(fields)
    for k in range(count):
        e = addr + k * es
        for w in range(0, es - 3, 4):
            if not any(x in cov for x in range(w, w + 4)):
                words[path + '+%02X' % w][struct.unpack_from('<I', b, e + w)[0]] += 1
        for off, kind, arg in fields:
            if kind == 'ap':
                c, o = struct.unpack_from('<QQ', b, e + off)
                counts[path + '+%02X' % off][min(c, 20)] += 1
                if c and isinstance(arg, tuple):
                    walk(b, base + o, c, arg[0], arg[1], path + '+%02X' % off, depth + 1)
                elif c:
                    for i in range(min(c, 50)):
                        v = b[base + o + i * arg: base + o + (i + 1) * arg]
                        leaf[path + '+%02X' % off][v.hex()] += 1
            else:
                c, ko, vo = struct.unpack_from('<QQQ', b, e + off)
                counts[path + '+%02X' % off][min(c, 20)] += 1
                if c:
                    keys_first[struct.unpack_from('<I', b, base + ko)[0]] += 1
                    for i in range(min(c, 50)):
                        v = b[base + vo + i * arg: base + vo + (i + 1) * arg]
                        leaf[path + '+%02X' % off][v.hex()] += 1


for f in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]:
    b = open(f, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    c, o = struct.unpack_from('<QQ', b, slot)
    if not c or o + H + c * es > len(b):
        continue
    nmod += 1
    nel += c
    walk(b, o + H, c, es, fields, '')
print('slot %03X: %d models, %d elements' % (slot, nmod, nel))
for p in sorted(words):
    print('word %-14s %s' % (p, ', '.join('%#x:%d' % kv for kv in words[p].most_common(8))))
for p in sorted(counts):
    print('count %-14s %s' % (p, dict(sorted(counts[p].items())[:10])))
for p in sorted(leaf):
    print('leaf %-14s %s' % (p, ', '.join('%s:%d' % kv for kv in leaf[p].most_common(8))))
