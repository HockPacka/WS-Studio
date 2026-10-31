"""Byte coverage of the m3walk structure model on every .m3: bytes inside known arrays vs. 'gaps' (extent - count*elem size - <16 padding)
usage: coverage.py [every-nth-file]  -> docs/m3_coverage.json"""
import collections
import glob
import json
import multiprocessing as mp
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS)
import m3walk  # noqa: E402

ROOT = os.path.dirname(TOOLS)


def work(path):
    b = open(path, 'rb').read()
    out = collections.Counter()
    if b[:4] != b'LDOM':
        return out
    out['files'] += 1
    out['bytes'] += len(b)
    out['header'] += m3walk.H
    seen = set()
    for start, end, r in m3walk.extents(b):
        if (start, r.label) in seen:
            continue
        seen.add((start, r.label))
        ext = end - start
        if r.kind in ('ap', 'keys') and r.elem:
            exact = r.count * r.elem
            gap = max(0, ext - exact - 15)
            out['array:' + r.label.split('+')[0]] += min(ext, exact)
            if gap:
                out['gap_after:' + r.label] += gap
                out['gap_total'] += gap
            out['known'] += min(ext, exact)
        elif r.kind == 'values':
            out['values'] += ext
            out['known'] += ext
        else:
            out['other:' + r.label] += ext
            out['known'] += ext
    return out


if __name__ == '__main__':
    mp.freeze_support()
    step = int(sys.argv[1]) if len(sys.argv) > 1 else 1
    files = sorted(glob.glob(os.path.join(ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]
    tot = collections.Counter()
    with mp.Pool(max(1, (os.cpu_count() or 4) - 2)) as p:
        for o in p.imap_unordered(work, files, chunksize=64):
            tot.update(o)
    n = tot['bytes']
    print('files', tot['files'], 'bytes %.2f GB' % (n / 2 ** 30))
    print('header %.2f%%  known arrays+values %.2f%%  gap_total %.4f%%' % (100.0 * tot['header'] / n, 100.0 * tot['known'] / n, 100.0 * tot['gap_total'] / n))
    for k, v in sorted(tot.items(), key=lambda kv: -kv[1]):
        if k.startswith('gap_after') and v > n * 1e-5:
            print('   %-34s %12d  %.4f%%' % (k, v, 100.0 * v / n))
    json.dump(dict(tot), open(os.path.join(ROOT, 'docs', 'm3_coverage.json'), 'w'), indent=1)
