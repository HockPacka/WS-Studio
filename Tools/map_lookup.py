"""Resolves module relative addresses (rva) of a WowClient64 crash / exception log to function names using the linker map.
usage: map_lookup.py <rva hex> [<rva hex> ...]      or      map_lookup.py --log Logs\\WildStar.log   (last EXCEPTION block)
"""
import bisect
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
MAP = os.path.join(os.path.dirname(HERE), 'wowdecomp', 'bin', 'Win', 'WowClient64.map')
PREF = 0x140000000


def load():
    rows = []
    for line in open(MAP, errors='ignore'):
        m = re.match(r'\s*0001:([0-9a-f]{8})\s+(\S+)\s+([0-9a-f]{16})', line)
        if m:
            rows.append((int(m.group(3), 16) - PREF, m.group(2)))
    rows.sort()
    return rows


def name(rows, rva):
    i = bisect.bisect(rows, (rva, '~')) - 1
    return (rows[i][1], rva - rows[i][0]) if i >= 0 else ('?', 0)


def demangle(sym):
    try:
        import subprocess
        out = subprocess.run(['undname', sym], capture_output=True, text=True).stdout
        return out.strip() or sym
    except Exception:  # noqa: BLE001
        return sym


if __name__ == '__main__':
    rows = load()
    if len(sys.argv) > 2 and sys.argv[1] == '--log':
        lines = open(sys.argv[2], errors='ignore').read().splitlines()
        idx = max(i for i, l in enumerate(lines) if l.startswith('EXCEPTION'))
        print(lines[idx])
        rvas = [int(re.search(r'rva ([0-9a-f]+)', l).group(1), 16) for l in lines[idx:idx + 42] if re.search(r'rva [0-9a-f]+', l)]
    else:
        rvas = [int(a, 16) for a in sys.argv[1:]]
    for r in rvas:
        n, off = name(rows, r)
        print('%08x  %s +0x%x' % (r, n, off))
