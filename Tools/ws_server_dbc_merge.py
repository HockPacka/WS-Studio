#!/usr/bin/env python3
"""Explicit, user-approved server step: merges the WildStar rows (id >= 200000) of the staging CreatureModelData / CreatureDisplayInfo into the
server's own Data/dbc copies. The server's other rows stay untouched, the server file is backed up first (<name>.dbc.bak_ws_<digest>).
usage: ws_server_dbc_merge.py --server "<AzerothCore folder>" [--staging build_wildstar/generated]
"""
import argparse
import hashlib
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ws_map_setup import Dbc  # noqa: E402

LOW, HIGH = 200000, 300000
STRING_FIELDS = {'CreatureModelData': (2,), 'CreatureDisplayInfo': ()}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--server', required=True)
    ap.add_argument('--staging', default=os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'build_wildstar', 'generated'))
    a = ap.parse_args()

    for name in ('CreatureModelData', 'CreatureDisplayInfo'):
        dst = os.path.join(a.server, 'Data', 'dbc', name + '.dbc')
        src = os.path.join(a.staging, 'client', 'WoWOverride', 'DBFilesClient', name + '.dbc')
        srv, stage = Dbc(dst), Dbc(src)
        assert srv.fc == stage.fc, '%s: field count differs (%d / %d)' % (name, srv.fc, stage.fc)
        raw = open(dst, 'rb').read()
        backup = dst + '.bak_ws_' + hashlib.sha256(raw).hexdigest()[:12]

        if not os.path.exists(backup):
            open(backup, 'wb').write(raw)

        srv.recs = [r for r in srv.recs if not (LOW <= r[0] < HIGH)]
        added = 0

        for r in stage.recs:
            if LOW <= r[0] < HIGH:
                r = list(r)

                for f in STRING_FIELDS[name]:
                    end = stage.strings.index(b'\0', r[f])
                    r[f] = srv.add_string(stage.strings[r[f]:end].decode('latin-1'))

                srv.recs.append(r)
                added += 1

        srv.save(dst)
        print('%s: %d WildStar rows merged into %s (backup %s)' % (name, added, dst, os.path.basename(backup)))


if __name__ == '__main__':
    main()
