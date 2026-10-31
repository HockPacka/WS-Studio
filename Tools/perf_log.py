"""Summarises Logs\\WildStar.log of the client: where the main thread waits (textures, models, tiles) and the frame hitches.
usage: perf_log.py [WildStar.log] [--last N]   (--last: only the last N seconds of the session)
"""
import collections
import re
import sys

path = 'WoWClient/Logs/WildStar.log'
last = None
args = sys.argv[1:]

while args:
    a = args.pop(0)

    if a == '--last':
        last = float(args.pop(0))
    else:
        path = a

rows = []
session_resets = 0

for line in open(path, encoding='latin-1'):
    m = re.match(r'\[(\d+)\] (.*)', line.rstrip('\n'))

    if m:
        stamp=int(m.group(1))
        # The client appends multiple process sessions to the same file, while
        # its millisecond clock restarts. Do not attribute previous runs' work
        # to the current hitch or produce a negative report duration.
        if rows and stamp < rows[-1][0]-10000:
            rows=[];session_resets+=1
        rows.append((stamp, m.group(2)))

if not rows:
    sys.exit('empty log')

end = rows[-1][0]

if last:
    rows = [r for r in rows if r[0] >= end - last * 1000]

span = (rows[-1][0] - rows[0][0]) / 1000.0
print('%d lines, %.0f s' % (len(rows), span))
if session_resets:print('current session only (%d previous timestamp resets)'%session_resets)


def num(pattern, text):
    m = re.search(pattern, text)
    return int(m.group(1)) if m else 0


groups = collections.defaultdict(list)

for ts, body in rows:
    if body.startswith('texture ') and ' create ' in body:
        groups['texture (wait / convert on the main thread)'].append(num(r'(?:wait|convert) (\d+) ms', body))
        groups['texture (create in the client)'].append(num(r'create (\d+) ms', body))
    elif body.startswith('M3 ClientData') and body.endswith(' ms'):
        groups['model (LoadM3 incl. FinishLoading)'].append(num(r'(\d+) ms$', body))
    elif body.startswith('area tile') and ' in ' in body:
        groups['area tile'].append(num(r'in (\d+) ms', body))
    elif body.startswith('frame hitch'):
        groups['frame hitch'].append(num(r'hitch: (\d+)', body))
    elif body.startswith('structure ') and body.endswith(' ms'):
        groups['structure root'].append(num(r'(\d+) ms$', body))

print('%-48s %6s %9s %7s %7s' % ('what', 'count', 'sum s', 'avg ms', 'max ms'))

for k, v in groups.items():
    print('%-48s %6d %9.1f %7.0f %7d' % (k, len(v), sum(v) / 1000.0, sum(v) / len(v), max(v)))

fails = collections.Counter(re.sub(r'^\S+ ', '', b)[:90] for t, b in rows if 'failed' in b or 'failure' in b)

for k, v in fails.most_common(8):
    print('  %4d x %s' % (v, k))
