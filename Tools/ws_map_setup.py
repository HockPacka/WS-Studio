#!/usr/bin/env python3
"""Generate an offline WoW map registration for a WildStar map window.

Writes WDT, a Map.dbc reference based on original client MPQs, and separate
AzerothCore teleport SQL drafts under --output. No server installation or
SQL execution. --install-client explicitly copies only client outputs.
Usage: ws_map_setup.py Western [--window 0 0] [--id 5000] [--output PATH]
"""
import argparse
import os
import re
import shutil
import struct
from ws_content_output import DEFAULT_CLIENT, Output, add_output_arguments, reject_server_install

DEFAULT_SERVER = None  # legacy CLI compatibility; never a generation input


class Dbc:
    def __init__(self, path):
        b = path if isinstance(path,bytes) else open(path, 'rb').read()
        magic, self.rc, self.fc, self.rs, ss = struct.unpack_from('<4s4I', b, 0)
        assert magic == b'WDBC'
        self.recs = [list(struct.unpack_from('<%dI' % self.fc, b, 20 + i * self.rs)) for i in range(self.rc)]
        self.strings = bytearray(b[20 + self.rc * self.rs:20 + self.rc * self.rs + ss])

    def add_string(self, s):
        off = len(self.strings)
        self.strings += s.encode('utf-8') + b'\0'
        return off

    def save(self, path):
        out = bytearray(struct.pack('<4s4I', b'WDBC', len(self.recs), self.fc, self.rs, len(self.strings)))
        for r in self.recs:
            out += struct.pack('<%dI' % self.fc, *r)
        out += self.strings
        os.makedirs(os.path.dirname(path), exist_ok=True)
        open(path, 'wb').write(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('name')
    ap.add_argument('--window', nargs=2, type=int, default=[0, 0])
    ap.add_argument('--id', type=int, default=5000)
    ap.add_argument('--client', default=DEFAULT_CLIENT)
    ap.add_argument('--server', default=DEFAULT_SERVER)
    ap.add_argument('--start', nargs=2, default=['39', '3b'], help='tile (AA BB hex) of the teleport target, default the test tile Western.393b')
    ap.add_argument('--apply', action='store_true', help='run the generated SQL against the server world database')
    add_output_arguments(ap)
    a = ap.parse_args()
    reject_server_install(ap,a)
    output=Output(a)
    wx, wy = a.window
    directory = 'WS_' + a.name + ('' if (wx, wy) == (0, 0) else '_%d_%d' % (wx, wy))

    # ---- WDT: tile table
    src = os.path.join(a.client, 'ClientData', 'Map', a.name)
    main_tbl = bytearray(4096 * 8)
    tiles = 0
    for f in os.listdir(src):
        m = re.match(r'^%s\.([0-9a-f]{2})([0-9a-f]{2})\.area$' % re.escape(a.name), f)
        if not m:
            continue
        aa, bb = int(m.group(1), 16), int(m.group(2), 16)
        tx, ty = 63 - (bb - 64 * wx), 63 - (aa - 64 * wy)
        if 0 <= tx < 64 and 0 <= ty < 64:
            struct.pack_into('<II', main_tbl, (64 * ty + tx) * 8, 1, 0)
            tiles += 1
    wdt = struct.pack('<4sI', b'REVM', 4) + struct.pack('<I', 18)
    wdt += struct.pack('<4sI', b'DHPM', 32) + struct.pack('<8I', 6, 0, 0, 0, 0, 0, 0, 0)
    wdt += struct.pack('<4sI', b'NIAM', len(main_tbl)) + bytes(main_tbl)
    rel='WoWOverride/World/Maps/'+directory+'/'+directory+'.wdt'
    for d in (os.path.dirname(output.client_path(rel)),):
        os.makedirs(d, exist_ok=True)
        open(os.path.join(d, directory + '.wdt'), 'wb').write(wdt)
    output.install_client_file(rel)
    print('WDT', directory, tiles, 'tiles')

    # ---- Map.dbc (template = row of map 0, own id)
    dbc = Dbc(output.original_dbc('Map'))
    dbc.recs = [r for r in dbc.recs if r[0] != a.id]
    tpl = [r for r in dbc.recs if r[0] == 0][0]
    row = list(tpl)
    row[0] = a.id
    row[1] = dbc.add_string(directory)
    # name (16 locales + flags at 5..21): enUS = own string, other locales 0
    name_off = dbc.add_string('WildStar ' + a.name)
    for i in range(5, 22):
        row[i] = 0
    row[5] = name_off
    row[21] = 0xFFFFFFFF
    dbc.recs.append(row)
    rel='WoWOverride/DBFilesClient/Map.dbc'
    for dst in (output.client_path(rel),):
        dbc.save(dst)
    output.install_client_file(rel)
    print('Map.dbc row id', a.id, 'directory', directory)

    # ---- teleport helper SQL (own game_tele id range 900000+)
    sqld = output.adapter_path('sql')
    os.makedirs(sqld, exist_ok=True)
    tele_id = 900000 + a.id
    # start position: centre of the middle existing tile; z is a guess (the test tile heights are around -750 m)
    import importlib.util
    spec = importlib.util.spec_from_file_location('ar', os.path.join(os.path.dirname(os.path.abspath(__file__)), 'area_reader.py'))
    ar = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(ar)
    aa0, bb0 = int(a.start[0], 16), int(a.start[1], 16)
    t = ar.read_area(open(os.path.join(src, '%s.%02x%02x.area' % (a.name, aa0, bb0)), 'rb').read())
    hraw = 8.0 * 2048 + 0.0
    for name, size, data, pos in t['chunks']:
        if name == 'KNHC':
            for idx, fl, cell in ar.read_chnk(data):
                if idx == 8 + 16 * 8:
                    f2, bl, subs = ar.split_cell(cell)
                    if 0 in bl:
                        hraw = struct.unpack_from('<H', bl[0], (9 * 19 + 9) * 2)[0]
    scale = 33.333332 / 32.0
    ws_x = ((bb0 - 64) * 512 + 8 * 32 + 16)
    ws_z = ((aa0 - 64) * 512 + 8 * 32 + 16)
    ws_y = hraw / 8.0 - 2048.0
    px = scale * ws_z + 17066.666
    py = scale * ws_x + 17066.666
    pz = scale * ws_y + 1600.0 + 5.0   # kZOffset of wowdecomp/Engine/Source/Area3/AdtBuilder.h
    print('teleport target tile %02x%02x: x %.2f y %.2f z %.2f' % (aa0, bb0, px, py, pz))
    with open(os.path.join(sqld, 'ws_map_%d.world.sql' % a.id), 'w', encoding='utf-8') as f:
        f.write('-- teleport target for WildStar map %s (map id %d, namespace: game_tele id %d)\n' % (a.name, a.id, tele_id))
        f.write('-- AzerothCore adapter only; occupied IDs cause INSERT to fail instead of replacing existing content.\n')
        f.write("INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES (%d, %.3f, %.3f, %.3f, 0, %d, 'ws%d');\n" % (tele_id, px, py, pz, a.id, a.id))
    with open(os.path.join(sqld, 'ws_map_%d.uninstall.world.sql' % a.id), 'w', encoding='utf-8') as f:
        f.write("DELETE FROM `game_tele` WHERE `id`=%d AND `name`='ws%d' AND `map`=%d;\n" % (tele_id,a.id,a.id))
    output.finish('maps')


if __name__ == '__main__':
    main()
