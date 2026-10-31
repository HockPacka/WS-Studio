"""WildStar .dgn reader (docs/dgn_format.md).

.dgn files describe dungeon kits:
  'NGND' (DNGN, version 6)  <Model>.dgn      dungeon definition: guid, name, model (.i3) path and the list of dressings (name + .N.dgn file)
  <Model>.<N>.dgn  (no magic, first u32 = N)  dressing N: the props (.m3 / light models) placed in the dungeon with colour, scale, position, rotation

Layout of the definition file derived from the client loader FUN_1402d5650 (WildStar64.exe); the dressing files were decoded from the data
(88 .. 2 MB files, all consistent, python tools/dgn_reader.py --check <ClientData/Art>).

usage: dgn_reader.py <file.dgn>           dump
       dgn_reader.py --check <dir>        validate every .dgn below dir (and that referenced models exist when --client <ClientData> is given)
"""
import os
import struct
import sys

DEF_HEADER = 0x50
DRESS_HEADER = 0x30
PLACEMENT = 0x80


def utf16(b, off, count):
    return b[off:off + count * 2].decode('utf-16le', 'replace').rstrip('\0')


def parse_definition(b):
    if b[:4] != b'NGND' or struct.unpack_from('<I', b, 4)[0] != 6:
        raise ValueError('not NGND v6')
    out = {}
    for name, co in (('guid', 0x08), ('name', 0x18), ('model', 0x28)):
        cnt, off = struct.unpack_from('<IxxxxQ', b, co)
        out[name] = utf16(b, DEF_HEADER + off, cnt)
    cnt, off = struct.unpack_from('<IxxxxQ', b, 0x38)
    dress = []
    for i in range(cnt):
        e = DEF_HEADER + off + i * 0x28
        idx = struct.unpack_from('<I', b, e)[0]
        nc, no = struct.unpack_from('<IxxxxQ', b, e + 8)
        pc, po = struct.unpack_from('<IxxxxQ', b, e + 0x18)
        # nested strings are relative to the 16-byte-aligned end of the dressing array
        base = (DEF_HEADER + off + cnt * 0x28 + 15) & ~15
        dress.append({'index': idx, 'name': utf16(b, base + no, nc), 'file': utf16(b, base + po, pc)})
    out['dressings'] = dress
    return out


def parse_dressing(b):
    """list of placements {id, model, color, scale, pos, rot(xyzw), extra}"""
    index = struct.unpack_from('<I', b, 0)[0]
    count, off = struct.unpack_from('<IxxxxQ', b, 0x08)
    c2, o2 = struct.unpack_from('<IxxxxQ', b, 0x18)
    pool = DRESS_HEADER + count * PLACEMENT
    items = []
    for i in range(count):
        r = DRESS_HEADER + i * PLACEMENT
        pid = struct.unpack_from('<I', b, r)[0]
        plen, poff = struct.unpack_from('<IxxxxQ', b, r + 8)
        items.append({
            'id': pid,
            'model': utf16(b, pool + poff, plen),
            'color': struct.unpack_from('<4f', b, r + 0x20),
            'scale': struct.unpack_from('<f', b, r + 0x30)[0],
            'pos': struct.unpack_from('<3f', b, r + 0x40),
            'rot': struct.unpack_from('<4f', b, r + 0x50),
            'extra_count': struct.unpack_from('<I', b, r + 0x60)[0],
        })
    # second array: 0x14 byte records {u32 hash, u32 value, 3 x u32 0}, offset relative to the end of the header
    tail = [struct.unpack_from('<5I', b, DRESS_HEADER + o2 + i * 20) for i in range(c2)]
    return {'index': index, 'placements': items, 'tail': tail}


def check_file(b, path):
    if b[:4] == b'NGND':
        d = parse_definition(b)
        return d, []
    d = parse_dressing(b)
    bad = []
    count = len(d['placements'])
    if DRESS_HEADER + count * PLACEMENT > len(b):
        bad.append('placements beyond file')
    expect = os.path.basename(path).rsplit('.', 2)[-2]
    if expect.isdigit() and int(expect) != d['index']:
        bad.append('index %d != file number %s' % (d['index'], expect))
    return d, bad


def main():
    if len(sys.argv) >= 3 and sys.argv[1] == '--check':
        client = sys.argv[sys.argv.index('--client') + 1] if '--client' in sys.argv else None
        n = ok = defs = placements = missing = 0
        models = {}
        for r, _, fs in os.walk(sys.argv[2]):
            for f in fs:
                if not f.endswith('.dgn'):
                    continue
                path = os.path.join(r, f)
                b = open(path, 'rb').read()
                n += 1
                try:
                    d, bad = check_file(b, path)
                except Exception as e:  # noqa: BLE001
                    print(path, e)
                    continue
                if b[:4] == b'NGND':
                    defs += 1
                else:
                    placements += len(d['placements'])
                    for p in d['placements']:
                        models[p['model']] = models.get(p['model'], 0) + 1
                if bad:
                    print(path, bad)
                else:
                    ok += 1
        if client:
            for m in models:
                if not os.path.exists(os.path.join(client, m)):
                    missing += 1
        print('dgn files %d (definitions %d), consistent %d, placements %d, distinct models %d%s' % (
            n, defs, ok, placements, len(models), ', missing in client: %d' % missing if client else ''))
        return
    b = open(sys.argv[1], 'rb').read()
    d, bad = check_file(b, sys.argv[1])
    if b[:4] == b'NGND':
        for k, v in d.items():
            print(k, v)
    else:
        print('index', d['index'], 'placements', len(d['placements']), 'tail', d['tail'])
        for p in d['placements']:
            print(p)
    if bad:
        print('PROBLEMS', bad)


if __name__ == '__main__':
    main()
