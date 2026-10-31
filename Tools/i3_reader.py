"""WildStar .i3 reader.

.i3 files come in two flavours (docs/i3_format.md):
  'FEDS' (SDEF, version 30)  sector file  <Model>.<Sector>.i3  - the renderable geometry (header 0x1B0 bytes)
  'FEDI' (IDEF, version 41)  model file   <Model>.i3           - materials / shader parameters / sector list (header 0x170 bytes)
Both are relocatable structs: every array is stored as (u32 count, u32 pad, u64 offset), offsets are relative to the end of the header.
Layout derived from the client loaders FUN_1402d2e30 (FEDS) and FUN_1402c9270 (FEDI) in WildStar64.exe.

usage: i3_reader.py <file.i3>                  dump the header slots (and names / sectors of a FEDI file)
       i3_reader.py --obj <sector.i3> <out.obj>   export the geometry of a sector file
       i3_reader.py --check <ClientData/Art>   validate every .i3 (all arrays inside the file)
"""
import os
import struct
import sys

HEADER = 0x1B0      # FEDS
IHEADER = 0x170     # FEDI

# FEDS plain arrays: (name, offset of the u32 count in the header, element stride); the u64 file offset is 8 bytes after the count
SIMPLE = [
    ('name', 0x20, 2),        # UTF-16 sector name ("Sector_Exterior")
    ('pos', 0x38, 12),        # float3 vertex positions
    ('vtx20', 0x48, 20),      # per vertex: [0..3] packed (tangent), [4..7] oct-normal in bytes 5/6, [8..15] 4 half floats (2 uv sets), [16..19] rgba
    ('index', 0x58, 4),       # u32 triangle indices, three per triangle
    ('tri_u16', 0x68, 2),     # one u16 per triangle (surface / material flag)
    ('submesh', 0x78, 28),    # {u32 kind, u32 firstIndex, u32 lastIndex, u32 firstVertex, u32 lastVertex, u32 id, u32 0}
    ('kd_nodes', 0x88, 8),    # kd tree over the triangles: {float split, u32 info}
    ('kd_leaves', 0x98, 8),   # {u32 start, u32 count} ranges into kd_tris
    ('kd_tris', 0xA8, 4),     # u32 triangle numbers
    ('u32_b', 0xB8, 4), ('u32_c', 0xC8, 4), ('u32_d', 0xE8, 4), ('u32_e', 0xF8, 4), ('u32_f', 0x108, 4),
    ('d_s16', 0x150, 16), ('d_s2_0', 0x160, 2), ('d_s2_1', 0x170, 2),
    ('tail_u16', 0x190, 2),   # submesh numbers
]
# arrays of {u32 count, u64 offset -> u16[count]}: (name, header offset of the slot, entry stride, offset of the inner count in the entry)
NESTED = [('b_list', 0xD8, 16, 0), ('c_list', 0x140, 24, 8), ('e_list', 0x180, 32, 8)]

# FEDI plain arrays (name, count offset, stride)
ISLOTS = [('sectors', 0x20, 0x40), ('s30', 0x30, 0x90), ('s40', 0x40, 0x58), ('s50', 0x50, 2), ('s60', 0x60, 0x40), ('s70', 0x70, 0x28),
          ('s80', 0x80, 0xB0), ('s90', 0x90, 0x20), ('sa0', 0xA0, 0x40), ('sb0', 0xB0, 2), ('sc0', 0xC0, 0x38), ('sd0', 0xD0, 8),
          ('se0', 0xE0, 2), ('sf0', 0xF0, 2), ('s100', 0x100, 4), ('s110', 0x110, 4), ('pool', 0x120, 2), ('names', 0x130, 4)]


def read_slot(b, cnt_off):
    cnt = struct.unpack_from('<I', b, cnt_off)[0]
    off = struct.unpack_from('<Q', b, cnt_off + 8)[0]
    return cnt, off


def parse(b):
    """FEDS sector file"""
    if b[:4] != b'FEDS':
        raise ValueError('not FEDS')
    ver = struct.unpack_from('<I', b, 4)[0]
    if ver != 30:
        raise ValueError('version %d' % ver)
    out = {'version': ver, 'arrays': {}, 'nested': {}}
    for name, co, stride in SIMPLE:
        cnt, off = read_slot(b, co)
        out['arrays'][name] = (cnt, off, stride)
    for name, co, stride, inner in NESTED:
        cnt, off = read_slot(b, co)
        out['nested'][name] = (cnt, off, stride, inner)
    out['bbox'] = struct.unpack_from('<3f', b, 0x120) + struct.unpack_from('<3f', b, 0x130)
    return out


def check(b):
    """list of problems (empty = every array lies inside the file)"""
    p = parse(b)
    bad = []
    for name, (cnt, off, stride) in p['arrays'].items():
        end = HEADER + off + cnt * stride
        if cnt and end > len(b):
            bad.append('%s: end %#x > size %#x' % (name, end, len(b)))
    for name, (cnt, off, stride, inner) in p['nested'].items():
        if not cnt:
            continue
        if HEADER + off + cnt * stride > len(b):
            bad.append('%s: end beyond file' % name)
            continue
        for i in range(cnt):
            e = HEADER + off + i * stride
            c2, o2 = struct.unpack_from('<I', b, e + inner)[0], struct.unpack_from('<Q', b, e + inner + 8)[0]
            if c2 and HEADER + o2 + c2 * 2 > len(b):
                bad.append('%s[%d] inner array beyond file' % (name, i))
    return bad


def parse_idef(b):
    """FEDI model file: slots, string pool, names and the sector list"""
    if b[:4] != b'FEDI' or struct.unpack_from('<I', b, 4)[0] != 41:
        raise ValueError('not FEDI v41')
    out = {'slots': {}}
    for name, co, stride in ISLOTS:
        out['slots'][name] = read_slot(b, co) + (stride,)
    out['bbox'] = struct.unpack_from('<3f', b, 0x140) + struct.unpack_from('<3f', b, 0x150)
    pc, po, _ = out['slots']['pool']
    pool = b[IHEADER + po:IHEADER + po + pc * 2].decode('utf-16le', 'replace')
    nc, no, _ = out['slots']['names']
    out['pool'] = pool
    names = []
    for i in struct.unpack_from('<%dI' % nc, b, IHEADER + no):
        end = pool.find('\0', i)
        names.append(pool[i:end if end >= 0 else len(pool)])
    out['names'] = names
    sc, so, ss = out['slots']['sectors']
    out['sectors'] = [names[struct.unpack_from('<I', b, IHEADER + so + i * ss)[0]] for i in range(sc)]
    return out


def check_idef(b):
    p = parse_idef(b)
    return ['%s beyond file' % n for n, (c, o, s) in p['slots'].items() if c and IHEADER + o + c * s > len(b)]


def decode_vertices(b, p):
    """positions (n,3), normals (n,3) from the octahedral bytes 5/6, uv0 / uv1 (n,2) half floats, rgba bytes (n,4)"""
    import numpy as np
    c, o, _ = p['arrays']['pos']
    pos = np.frombuffer(b, '<f4', c * 3, HEADER + o).reshape(c, 3)
    vo = HEADER + p['arrays']['vtx20'][1]
    raw = np.frombuffer(b, np.uint8, c * 20, vo).reshape(c, 20)
    x = raw[:, 6] / 255.0 * 2 - 1
    y = raw[:, 5] / 255.0 * 2 - 1
    z = 1 - abs(x) - abs(y)
    t = np.clip(-z, 0, None)
    x = x + np.where(x >= 0, -t, t)
    y = y + np.where(y >= 0, -t, t)
    n = np.stack([x, y, z], 1)
    n /= np.linalg.norm(n, axis=1, keepdims=True) + 1e-12
    halves = np.frombuffer(b, '<f2', c * 10, vo).reshape(c, 10)
    return pos, n, halves[:, 4:6].astype(np.float32), halves[:, 6:8].astype(np.float32), raw[:, 16:20]


def export_obj(path, out):
    """wavefront obj of a FEDS sector file, one object per sub mesh"""
    import numpy as np
    b = open(path, 'rb').read()
    p = parse(b)
    pos, n, uv0, _, _ = decode_vertices(b, p)
    ci, oi, _ = p['arrays']['index']
    idx = np.frombuffer(b, '<u4', ci, HEADER + oi)
    rc, ro, _ = p['arrays']['submesh']
    with open(out, 'w') as f:
        for v in pos:
            f.write('v %f %f %f\n' % tuple(v))
        for v in uv0:
            f.write('vt %f %f\n' % (v[0], 1 - v[1]))
        for v in n:
            f.write('vn %f %f %f\n' % tuple(v))
        for k in range(rc):
            rec = struct.unpack_from('<7I', b, HEADER + ro + k * 28)
            f.write('o sub%d_%d\n' % (k, rec[5]))
            for t in range(rec[1] // 3, (rec[2] + 1) // 3):
                a = idx[t * 3:t * 3 + 3] + 1
                f.write('f %d/%d/%d %d/%d/%d %d/%d/%d\n' % (a[0], a[0], a[0], a[1], a[1], a[1], a[2], a[2], a[2]))


def check_tree(root):
    n = ok = idef_n = idef_ok = 0
    for r, _, fs in os.walk(root):
        for f in fs:
            if not f.endswith('.i3'):
                continue
            path = os.path.join(r, f)
            b = open(path, 'rb').read()
            try:
                if b[:4] == b'FEDI':
                    idef_n += 1
                    idef_ok += not check_idef(b)
                elif b[:4] == b'FEDS':
                    n += 1
                    bad = check(b)
                    ok += not bad
                    if bad and n - ok < 10:
                        print(path, bad[:3])
            except Exception as e:  # noqa: BLE001
                print(path, e)
    print('FEDS files %d, consistent %d; FEDI files %d, consistent %d' % (n, ok, idef_n, idef_ok))


def main():
    if len(sys.argv) >= 3 and sys.argv[1] == '--check':
        check_tree(sys.argv[2])
        return
    if len(sys.argv) >= 4 and sys.argv[1] == '--obj':
        export_obj(sys.argv[2], sys.argv[3])
        return
    b = open(sys.argv[1], 'rb').read()
    if b[:4] == b'FEDI':
        p = parse_idef(b)
        print('bbox', p['bbox'])
        print('sectors', p['sectors'])
        print('names', p['names'])
        for k, v in p['slots'].items():
            print(k, v)
        return
    p = parse(b)
    print('size %#x bbox %s' % (len(b), p['bbox']))
    for name, (cnt, off, stride) in p['arrays'].items():
        print('%-9s count %-8d off %#-8x stride %-2d end %#x' % (name, cnt, off, stride, HEADER + off + cnt * stride))
    for name, v in p['nested'].items():
        print(name, v)


if __name__ == '__main__':
    main()
