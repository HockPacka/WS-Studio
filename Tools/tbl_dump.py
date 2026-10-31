#!/usr/bin/env python3
"""Dump WildStar .tbl game tables (DB/*.tbl in ClientData) to CSV. Usage: tbl_dump.py [outdir] [name-substring...]"""
import csv, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.join(HERE, 'Halon'))
import halon
from validate_formats import inflate, a16, PATCH, ROOT

TYPES = {3: 'int', 4: 'float', 11: 'bool', 20: 'long', 130: 'string'}

def parse(b):
    (name_cnt, _u, rec_size, fcnt, foff, rcnt, total, roff, lcnt, loff, _p) = struct.unpack_from('<11Q', b, 8)
    H = 96
    name = b[H:H + (name_cnt - 1) * 2].decode('utf-16le')
    fp = H + foff
    fields = [struct.unpack_from('<IIQHHI', b, fp + i * 24) for i in range(fcnt)]
    nb = a16(fp + fcnt * 24)
    cols = [(b[nb + f[2]:nb + f[2] + (f[0] - 1) * 2].decode('utf-16le'), f[3]) for f in fields]
    rows = []
    for r in range(rcnt):
        p = H + roff + r * rec_size; row = []
        for _, t in cols:
            if t in (3, 11): row.append(struct.unpack_from('<i', b, p)[0] if t == 3 else bool(struct.unpack_from('<i', b, p)[0])); p += 4
            elif t == 4: row.append(round(struct.unpack_from('<f', b, p)[0], 6)); p += 4
            elif t == 20: row.append(struct.unpack_from('<q', b, p)[0]); p += 8
            elif t == 130:
                if p % 8 != 0 and (p - (H + roff + r * rec_size)) % 8: p += 4
                sp = struct.unpack_from('<Q', b, p)[0]; p += 8
                s = H + roff + sp; e = s
                while b[e] or b[e + 1]: e += 2
                row.append(b[s:e].decode('utf-16le'))
            else: row.append(None)
        rows.append(row)
    return name, cols, rows

def load(fs, path):
    f = fs[path]; i, _ = fs.data.blocks[f.sha1]; o, bs = fs.data.fs[i]
    with open(fs.data.name, 'rb') as a: a.seek(o); return inflate(f, a.read(bs))

if __name__ == '__main__':
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, 'extracted', 'tables_csv')
    flt = [s.lower() for s in sys.argv[2:]]
    os.makedirs(out, exist_ok=True)
    fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
    n = 0
    for k in sorted(fs['DB'].files):
        if flt and not any(s in k.lower() for s in flt): continue
        name, cols, rows = parse(load(fs, 'DB/' + k))
        with open(os.path.join(out, k[:-4] + '.csv'), 'w', newline='', encoding='utf-8') as fh:
            w = csv.writer(fh); w.writerow([c for c, _ in cols]); w.writerows(rows)
        n += 1
    print(n, 'tables ->', out)
