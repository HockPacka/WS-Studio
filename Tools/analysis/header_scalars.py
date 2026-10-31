"""Header bytes that are not part of an AP/DP slot ("scalars"): ranges, value statistics.  usage: header_scalars.py [every-nth-file]"""
import collections
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS)
import m3walk  # noqa: E402

ROOT = os.path.dirname(TOOLS)
step = int(sys.argv[1]) if len(sys.argv) > 1 else 50
ap = set(m3walk.TOP_AP) | {0x1B0, 0x1C0, 0x1F0, 0x250, 0x180}
dp = set(m3walk.TOP_DP)
cov = set(range(0, 8))  # 'LDOM' + version
for s in ap:
    cov.update(range(s, s + 16))
for s in dp:
    cov.update(range(s, s + 24))
free = [i for i in range(0x630) if i not in cov]
ranges = []
for i in free:
    if ranges and ranges[-1][1] == i:
        ranges[-1][1] = i + 1
    else:
        ranges.append([i, i + 1])
print('uncovered header ranges:', ', '.join('%03X-%03X' % (a, e) for a, e in ranges))
files = sorted(glob.glob(os.path.join(ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]
stats = collections.defaultdict(collections.Counter)
for f in files:
    b = open(f, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    for a, e in ranges:
        for w in range(a, e - 3, 4):
            stats[w][struct.unpack_from('<I', b, w)[0]] += 1
for w in sorted(stats):
    cc = stats[w]
    print('%03X distinct %-5d %s' % (w, len(cc), ', '.join('%#x:%d' % kv for kv in cc.most_common(5))))
