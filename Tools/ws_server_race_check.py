"""Read-only check of the server's Data/dbc: for every WildStar race (ChrRaces id >= 22) the male / female player display id, its CreatureDisplayInfo row and the
CreatureModelData model path. Shows where a race would fall back to a human model.
usage: ws_server_race_check.py --server "<AzerothCore folder>"
"""
import argparse
import os
import struct


def load(d, name):
    b = open(os.path.join(d, name + '.dbc'), 'rb').read()
    m, rc, fc, rs, ss = struct.unpack_from('<4s4I', b, 0)
    return [struct.unpack_from('<%dI' % fc, b, 20 + i * rs) for i in range(rc)], b[20 + rc * rs:]


def text(t, o):
    return t[o:t.find(b'\0', o)].decode('latin1')


ap = argparse.ArgumentParser()
ap.add_argument('--server', required=True)
a = ap.parse_args()
d = os.path.join(a.server, 'Data', 'dbc')
races, rs = load(d, 'ChrRaces')
cdi, _ = load(d, 'CreatureDisplayInfo')
cmd, ms = load(d, 'CreatureModelData')
display = {r[0]: r for r in cdi}
model = {r[0]: r for r in cmd}

for r in races:
    if r[0] < 22 and r[0] != 1:
        continue

    for sex, idx in (('male', 4), ('female', 5)):
        did = r[idx]
        info = display.get(did)
        md = model.get(info[1]) if info else None
        print('%2d %-14s %-6s display %6d  %s  %s' % (r[0], text(rs, r[14]), sex, did, 'CreatureDisplayInfo ok' if info else 'CreatureDisplayInfo MISSING', text(ms, md[2]) if md else '(no model data)'))
