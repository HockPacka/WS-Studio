"""Probe the not yet decoded M3 header slots: which slots are populated, and element/nested statistics.
usage: block_probe.py [every-nth-file]"""
import collections
import glob
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
H = 0x630
step = int(sys.argv[1]) if len(sys.argv) > 1 else 50
files = sorted(glob.glob(os.path.join(ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]
pop = collections.Counter()
for f in files:
    b = open(f, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    for off in range(0x10, 0x630 - 15, 8):
        c, o = struct.unpack_from('<QQ', b, off)
        if 0 < c < 1 << 24 and 0 <= o < len(b) - H:
            pop[off] += 1
print(len(files), 'files')
for off in sorted(pop):
    if off >= 0x340:
        print('%03X %d' % (off, pop[off]))
