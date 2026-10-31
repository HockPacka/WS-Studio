"""WildStar .area reader (terrain tile). Structure from tools/NexusForever/Source/NexusForever.IO/Area, extended and verified against all files.

File:   u32 magic ('area' = 0x61726561 big endian text, bytes 'a','e','r','a' read as LE 0x61657261 ... both spellings exist), u32 version,
        then chunks:  u32 id, u32 size, data   (ids are ASCII read big endian: 'CHNK' 'CURT' 'PROp' 'DHMO' ...)
CHNK:   16 x 16 cells, a list of  u32 info (index delta in the top byte, size in the low 24 bits) + cell data
Cell:   u32 flags, then for every set bit i a fixed size block (CELL_BLOCK_SIZE[i]), then trailing sub chunks (u32 id, u32 size, data)

usage: area_reader.py file.area [file.area ...]   (prints the chunk / cell structure)  or  area_reader.py --check <root dir> [limit]
"""
import os
import struct
import sys
import zlib

CELL_BLOCK_SIZE = [722, 16, 8450, 8450, 8450, 4, 64, 16, 4225, 2178, 4, 578, 1, 4624, 2312, 8450, 4096, 2312, 2312, 2312, 2312, 1, 16, 16900, 8, 8450,
                   21316, 4096, 16, 8450, 8450, 2312]

# Physical 17x17 BC blocks cover 65x65 logical texels (68x68 padded).
# They MUST NOT be interpreted as 17x17 vertices or four u16 channels.
CELL_BLOCK_ENCODING = {13: 'BC2/DXT3', **{b: 'BC1/DXT1' for b in (14, 17, 18, 19, 20, 31)}}
CELL_BLOCK_SEMANTICS = {
    6: '2x2 corners, four WorldSky uint32 IDs per corner (64 bytes)',
    7: '2x2 corners, four WorldSky UNORM8 weights per corner (16 bytes)',
    13: 'colour RGB + 4-bit alpha attribute (alpha meaning not established)',
    16: 'packed zone/terrain flags; zone index=(v>>3)&3; 0x20 suppresses clutter',
    17: 'BC1 base layer weights RGB, layer 3 is the remainder',
    18: 'BC1 signed RGB correction to block 17',
    27: 'four 2-bit worldClutterId00..03 selectors, one per WorldLayer slot',
}


# Raster descriptor of every flag bit, read from the game client (WildStar64.exe, table at 0x140c4135c - 0x10, 0x38 bytes per entry, used by FUN_1402e4ec0):
# (first sample index, one past the last sample index, bytes per sample, (linked bits)).  Block size = (hi - lo) * (hi - lo) * bytes for the square rasters.
# lo / hi are cell relative sample coordinates, e.g. the heightmap is -1 .. 18 (19 samples: sample 0 = the cell's own first vertex, -1 = left neighbour, 17,18 = right neighbour).
CELL_BLOCK_DIMS = {
    0: (-1, 18, 2, ()), 1: (0, 1, 16, ()), 2: (0, 65, 2, (17, 18)), 3: (0, 65, 2, (13,)), 4: (0, 65, 2, ()), 5: (0, 1, 4, ()), 6: (0, 2, 16, ()), 7: (0, 2, 4, ()),
    8: (0, 65, 1, ()), 9: (0, 33, 2, ()), 10: (0, 1, 4, ()), 11: (0, 17, 2, ()), 12: (0, 1, 1, ()), 13: (0, 17, 16, ()), 14: (0, 17, 8, ()), 15: (0, 65, 2, (14,)),
    16: (0, 64, 1, ()), 17: (0, 17, 8, ()), 18: (0, 17, 8, ()), 19: (0, 17, 8, ()), 20: (0, 17, 8, ()), 21: (0, 1, 1, ()), 22: (0, 1, 16, ()), 23: (0, 65, 4, ()),
    24: (0, 2, 2, ()), 25: (0, 65, 2, ()), 26: (-4, 69, 4, ()), 27: (0, 64, 1, ()), 28: (0, 1, 16, ()), 29: (0, 65, 2, (19, 20)), 30: (0, 65, 2, (31,)), 31: (0, 17, 8, ()),
}


def fourcc(v):
    return struct.pack('>I', v).decode('latin-1')


def read_area(b):
    """returns dict(version, chunks=[(id, size, parsed)]) ; raises ValueError on a structure violation"""
    if len(b) < 8:
        raise ValueError('short file')
    magic, version = struct.unpack_from('<II', b, 0)
    if struct.pack('>I', magic) not in (b'area', b'AREA') and struct.pack('<I', magic) not in (b'area', b'AREA'):
        raise ValueError('bad magic %08x' % magic)
    pos = 8
    chunks = []
    while pos < len(b):
        if pos + 8 > len(b):
            raise ValueError('truncated chunk header')
        cid, size = struct.unpack_from('>II', b, pos)  # id as big endian text
        cid_le, = struct.unpack_from('<I', b, pos)
        size, = struct.unpack_from('<I', b, pos + 4)
        data = b[pos + 8:pos + 8 + size]
        if len(data) != size:
            raise ValueError('chunk %s overruns the file' % fourcc(cid))
        name = fourcc(cid_le) if False else struct.pack('<I', cid_le).decode('latin-1')
        chunks.append((name, size, data, pos))
        pos += 8 + size
    return {'version': version, 'compressed': b[:4] == b'AERA', 'chunks': chunks}


def read_chnk(data, compressed=False):
    """returns list of (index, flags, cell_bytes) for the cells of a CHNK chunk.
    'area' files: entries are  u32 info (index delta << 24 | size)  + size bytes.
    'AERA' files (upper case magic, *_Low.*.area): every entry is  u32 info (index delta << 24 | UNCOMPRESSED size)  + a self delimiting zlib stream;
    the first entry (index 0, 1024 bytes) is not a regular cell (flags 0x16d do not fit the block sizes) and is returned with index -1."""
    pos = 0
    last = 0
    cells = []
    first = True
    while pos < len(data):
        if pos + 4 > len(data):
            raise ValueError('truncated cell header')
        info, = struct.unpack_from('<I', data, pos)
        idx = (info >> 24) & 0xFF
        size = info & 0xFFFFFF
        pos += 4
        if compressed:
            z = zlib.decompressobj()
            try:
                cell = z.decompress(data[pos:])
            except zlib.error as ex:
                raise ValueError('zlib: %s' % ex)
            pos = len(data) - len(z.unused_data)
            if first:
                first = False
                cells.append((-1, 0, cell))
                continue
            if len(cell) != size:
                raise ValueError('cell size %d != %d' % (len(cell), size))
        else:
            cell = data[pos:pos + size]
            if len(cell) != size:
                raise ValueError('cell overruns chunk')
            pos += size
        idx += last
        last = idx + 1
        if idx >= 256:
            raise ValueError('cell index %d' % idx)
        flags, = struct.unpack_from('<I', cell, 0)
        cells.append((idx, flags, cell))
    return cells


def split_cell(cell):
    """returns (flags, {bit: block bytes}, [(subchunk id, data)]) ; raises ValueError if the block sizes do not fit"""
    flags, = struct.unpack_from('<I', cell, 0)
    pos = 4
    blocks = {}
    for i in range(32):
        if flags & (1 << i):
            n = CELL_BLOCK_SIZE[i]
            if pos + n > len(cell):
                raise ValueError('block %d overruns the cell' % i)
            blocks[i] = cell[pos:pos + n]
            pos += n
    subs = []
    while pos < len(cell):
        if pos + 8 > len(cell):
            raise ValueError('trailing bytes %d in cell' % (len(cell) - pos))
        cid = cell[pos:pos + 4].decode('latin-1')
        size, = struct.unpack_from('<I', cell, pos + 4)
        data = cell[pos + 8:pos + 8 + size]
        if len(data) != size:
            raise ValueError('sub chunk %s overruns the cell' % cid)
        subs.append((cid, data))
        pos += 8 + size
    return flags, blocks, subs


def describe(path):
    b = open(path, 'rb').read()
    a = read_area(b)
    print(os.path.basename(path), len(b), 'bytes, version', a['version'])
    for name, size, data, pos in a['chunks']:
        print('  chunk', name, size, 'at', pos)
        if name == 'CHNK' or name.upper() == 'KNHC' or name == 'KNHC'[::-1]:
            pass
        if name in ('CHNK', 'KNHC'):
            cells = read_chnk(data, a['compressed'])
            print('    cells', len(cells))
            for idx, flags, cell in cells[:3]:
                fl, blocks, subs = split_cell(cell)
                print('    cell', idx, 'flags %08x' % fl, 'blocks', sorted(blocks), 'sub chunks', [(c, len(d)) for c, d in subs])


def check(root, limit=0):
    ok = bad = 0
    errs = {}
    stats = {}
    for d, _dirs, files in os.walk(root):
        for f in files:
            if not f.lower().endswith('.area'):
                continue
            if limit and ok + bad >= limit:
                return ok, bad, errs, stats
            p = os.path.join(d, f)
            try:
                b = open(p, 'rb').read()
                a = read_area(b)
                for name, size, data, pos in a['chunks']:
                    stats[name] = stats.get(name, 0) + 1
                    if name in ('CHNK', 'KNHC'):
                        for idx, flags, cell in read_chnk(data, a['compressed']):
                            if idx < 0:
                                continue
                            fl, blocks, subs = split_cell(cell)
                            for bit in blocks:
                                stats['bit%d' % bit] = stats.get('bit%d' % bit, 0) + 1
                            for cid, sd in subs:
                                stats['sub:' + cid] = stats.get('sub:' + cid, 0) + 1
                ok += 1
            except Exception as ex:  # noqa: BLE001
                bad += 1
                errs.setdefault(str(ex)[:60], []).append(p)
    return ok, bad, errs, stats


if __name__ == '__main__':
    if len(sys.argv) > 2 and sys.argv[1] == '--check':
        ok, bad, errs, stats = check(sys.argv[2], int(sys.argv[3]) if len(sys.argv) > 3 else 0)
        print('ok', ok, 'bad', bad)
        for k, v in errs.items():
            print(' ', len(v), k, v[0])
        print(sorted(stats.items()))
    else:
        for p in sys.argv[1:]:
            describe(p)
