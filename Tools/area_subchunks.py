"""Surveys the trailing sub chunks of the cells (Psbw, Druc, PORP, GtAW) and the top level chunks of .area files: sizes, how many cells, a few samples.
usage: area_subchunks.py <Map folder> [max files]
"""
import collections
import glob
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import area_reader as A  # noqa: E402

folder = sys.argv[1]
limit = int(sys.argv[2]) if len(sys.argv) > 2 else 200
sizes = collections.defaultdict(collections.Counter)
samples = {}
top = collections.Counter()
topsizes = collections.defaultdict(list)
bits = collections.Counter()
files = 0

all_files = sorted(glob.glob(os.path.join(folder, '*.area')))
step = max(1, len(all_files) // limit)

for f in all_files[::step][:limit]:
    b = open(f, 'rb').read()

    try:
        a = A.read_area(b)
    except ValueError:
        continue

    files += 1

    for name, size, data, pos in a['chunks']:
        top[name] += 1
        topsizes[name].append(size)

        if name in ('CHNK', 'KNHC'):
            for idx, flags, cell in A.read_chnk(data, a['compressed']):
                fl, blocks, subs = A.split_cell(cell)

                for bit in blocks:
                    bits[bit] += 1

                for cid, d in subs:
                    sizes[cid][len(d)] += 1
                    samples.setdefault(cid, d[:96])

print('files', files)
print('top level chunks', dict(top))
print({k: (min(v), max(v), len(v)) for k, v in topsizes.items()})
print('cell block bits', sorted(bits.items()))

for cid, c in sizes.items():
    print(cid, 'cells', sum(c.values()), 'sizes', c.most_common(6))
    print('   sample', samples[cid].hex(' ', 4)[:300])
