#!/usr/bin/env python3
"""Removes the starter equipment of the WildStar races (ChrRaces id >= 22) from CharStartOutfit.dbc: every item / display / inventory type of their rows becomes 0.
WoW items cannot be shown on the WildStar race models yet (the client ignores them for these races), so new characters start without outfit items.
Rows of the other races stay untouched. Files are backed up next to the original (<name>.dbc.bak_ws_<hash>).
usage: ws_empty_outfits.py [--client <WoWClient>] [--server "<AzerothCore folder>"]   (the server is only changed when --server is given)
"""
import argparse
import hashlib
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ws_map_setup import DEFAULT_CLIENT  # noqa: E402

FIRST_WS_RACE = 22


def process(path):
    """CharStartOutfit rows are 74 dwords (the header counts the packed race/class/gender/unk bytes as four fields: 77): id, race|class<<8|gender<<16, then 24 item ids,
    24 display ids and 24 inventory types."""
    raw = bytearray(open(path, 'rb').read())
    magic, rc, fc, rs, ss = struct.unpack_from('<4s4I', raw, 0)
    assert magic == b'WDBC' and rs % 4 == 0 and rs // 4 == 74, '%s: unexpected layout (record size %d)' % (path, rs)
    changed = 0
    out = bytearray(raw)

    for i in range(rc):
        base = 20 + i * rs
        race = out[base + 4]

        if race >= FIRST_WS_RACE and any(out[base + 8:base + rs]):
            out[base + 8:base + rs] = bytes(rs - 8)
            changed += 1

    if changed:
        backup = path + '.bak_ws_' + hashlib.sha256(bytes(raw)).hexdigest()[:12]

        if not os.path.exists(backup):
            open(backup, 'wb').write(raw)

        open(path, 'wb').write(out)

    print('%s: %d WildStar outfit rows emptied (of %d rows)' % (path, changed, rc))


ap = argparse.ArgumentParser()
ap.add_argument('--client', default=DEFAULT_CLIENT)
ap.add_argument('--server')
a = ap.parse_args()
process(os.path.join(a.client, 'WoWOverride', 'DBFilesClient', 'CharStartOutfit.dbc'))

if a.server:
    process(os.path.join(a.server, 'Data', 'dbc', 'CharStartOutfit.dbc'))
