#!/usr/bin/env python3
"""Generate offline WildStar zone registrations from WorldZone.csv.

WoW area ID = AREA_BASE + native WorldZone ID, matching AdtBuilder. The base
AreaTable.dbc is read from original client MPQs. Outputs stay under --output;
--install-client explicitly copies client outputs. Server paths are rejected.
Usage: ws_zones.py [--client PATH] [--output PATH]
"""
import argparse
import csv
import os
import shutil
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ws_text  # noqa: E402
from ws_map_setup import Dbc, DEFAULT_CLIENT, DEFAULT_SERVER  # noqa: E402
from ws_content_output import Output, add_output_arguments, reject_server_install

AREA_BASE = 50000   # uint16-safe; keep identical to kAreaIdBase in AdtBuilder.h


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--client', default=DEFAULT_CLIENT)
    ap.add_argument('--server', default=DEFAULT_SERVER)
    add_output_arguments(ap)
    a = ap.parse_args()
    reject_server_install(ap,a)
    output=Output(a)
    dbc = Dbc(output.original_dbc('AreaTable'))
    assert dbc.fc == 36, 'AreaTable.dbc: unexpected field count %d' % dbc.fc
    text = ws_text.load(os.path.join(a.client, 'ClientDataEN', 'en-US.bin'))
    zones = list(csv.DictReader(open(os.path.join(a.client, 'tables_csv', 'WorldZone.csv'), encoding='utf-8')))
    ids = {int(z['ID']) for z in zones}
    dbc.recs = [r for r in dbc.recs if not (AREA_BASE <= r[0] < 60000 or 900000 <= r[0] < 1000000)]
    added = 0

    for z in zones:
        zid = int(z['ID'])
        name = text.get(int(z['localizedTextIdName']), '').strip()

        if not name:
            name = 'WildStar zone %d' % zid

        row = [0] * dbc.fc
        row[0] = AREA_BASE + zid
        parent = int(z['parentZoneId'])
        row[2] = AREA_BASE + parent if parent in ids and parent != zid else 0
        row[11] = dbc.add_string(name)   # AreaName_lang enUS (client uses UTF-8)
        row[27] = 0xFFFFFFFF                                                             # name flags
        row[33] = struct.unpack('<I', struct.pack('<f', -5000.0))[0]                    # MinElevation
        dbc.recs.append(row)
        added += 1

    rel='WoWOverride/DBFilesClient/AreaTable.dbc'
    for dst in (output.client_path(rel),):
        dbc.save(dst)
    output.install_client_file(rel)

    print('AreaTable.dbc: %d original rows + %d WildStar zones (ids %d + WorldZone id)' % (len(dbc.recs) - added, added, AREA_BASE))
    output.finish('zones')


if __name__ == '__main__':
    main()
