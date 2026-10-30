"""WildStar FEDS/FEDI/AREA reader + legacy M3 reference implementation.

Based on the format research in HockPacka/WS-Tools:
  docs/m3_format_spec.md, tools/blender_addon/wildstar_m3/m3.py
  docs/i3_dgn_format.md, tools/i3_reader.py
The live M3 route uses the native ws_m3_parser.dll instead.
This is a static mesh viewer, NOT a complete asset loader.
"""
from __future__ import annotations

from array import array
import base64
import math
from pathlib import Path
import struct
import sys
import zlib

MAX_FILE = 512 * 1024 * 1024
MAX_OTHER_FILE = 128 * 1024 * 1024
MAX_VERTICES = 750_000
MAX_SECTIONS = 350
MAX_INDEX_COUNT = 3_500_000


class FormatError(ValueError):
    pass


def at(data: bytes, off: int, fmt: str):
    if off < 0 or off + struct.calcsize(fmt) > len(data):
        raise FormatError(f"Datei abgeschnitten (Offset 0x{off:x}, {fmt})")
    return struct.unpack_from(fmt, data, off)


def within(data: bytes, off: int, size: int):
    if off < 0 or size < 0 or off + size > len(data):
        raise FormatError(f"Ungültiger Datenbereich 0x{off:x}+{size}")
    return off


def ap64(data: bytes, header_off: int, base: int, stride: int):
    count, off = at(data, header_off, '<QQ')
    if count > 20_000_000:
        raise FormatError('Unrealistisch große Array-Länge')
    start = base + off
    within(data, start, count * stride)
    return int(count), int(start)


def ap32(data: bytes, header_off: int, base: int, stride: int):
    count, off = at(data, header_off, '<I4xQ')
    if count > 20_000_000:
        raise FormatError('Unrealistisch große Array-Länge')
    start = base + off
    within(data, start, count * stride)
    return int(count), int(start)


def oct_decode(a: int, b: int):
    x = a / 255.0 * 2 - 1
    y = b / 255.0 * 2 - 1
    z = 1 - abs(x) - abs(y)
    if z < 0:
        x, y = (1 - abs(y)) * (1 if x >= 0 else -1), (1 - abs(x)) * (1 if y >= 0 else -1)
    l = math.sqrt(x * x + y * y + z * z) or 1
    return (x / l, y / l, z / l)


def encode(arr):
    if sys.byteorder != 'little':
        arr.byteswap()
    return base64.b64encode(arr.tobytes()).decode('ascii')


def rgba_hex(i: int):
    # Distinct but harmonious materials in the viewport.
    palette = ('#7dcbe8', '#e2a67d', '#91d5b4', '#b9a8f0', '#edc27f', '#dca4bc',
               '#90b2e9', '#c2cf91', '#7cc8b8', '#e6af91')
    return palette[(i * 7 + i // 5) % len(palette)]


class Accumulator:
    def __init__(self):
        self.sections = []
        self.warnings = []
        self.vertex_count = 0
        self.triangle_count = 0
        self.bounds = [float('inf')] * 3 + [float('-inf')] * 3

    def add(self, name: str, positions, normals, triangle_indices, material: int = 0, **meta):
        if not positions or len(triangle_indices) < 3:
            return
        if len(self.sections) >= MAX_SECTIONS or self.vertex_count + len(positions) > MAX_VERTICES or len(triangle_indices) > MAX_INDEX_COUNT:
            if 'Vorschau-Limit' not in self.warnings:
                self.warnings.append('Vorschau-Limit: sehr große Modelle werden teilweise angezeigt (max. 350 Meshes / 750.000 Vertices).')
            return
        p = array('f')
        n = array('f')
        for k, v in enumerate(positions):
            if len(v) != 3 or not all(math.isfinite(x) for x in v):
                raise FormatError('Ungültige Vertex-Koordinaten')
            # WildStar Y-up -> viewer Z-up. Same orientation as the Blender add-on.
            x, y, z = v
            p.extend((x, -z, y))
            for axis, value in enumerate((x, -z, y)):
                self.bounds[axis] = min(self.bounds[axis], value)
                self.bounds[axis + 3] = max(self.bounds[axis + 3], value)
            if normals and k < len(normals):
                nx, ny, nz = normals[k]
                n.extend((nx, -nz, ny))
            else:
                n.extend((0.0, 0.0, 1.0))
        valid = array('I')
        for q in range(0, len(triangle_indices) - 2, 3):
            a, b, c = map(int, triangle_indices[q:q + 3])
            if 0 <= a < len(positions) and 0 <= b < len(positions) and 0 <= c < len(positions) and len({a, b, c}) == 3:
                valid.extend((a, b, c))
        if not valid:
            return
        self.sections.append({
            'name': name, 'color': rgba_hex(material), 'material': material,
            'vertices': len(positions), 'triangles': len(valid) // 3,
            'positions': encode(p), 'normals': encode(n), 'indices': encode(valid),
            'meta': meta,
        })
        self.vertex_count += len(positions)
        self.triangle_count += len(valid) // 3

    def result(self, name: str, fmt: str, info: dict):
        if not self.sections:
            raise FormatError('Keine darstellbaren Dreiecke gefunden')
        return {
            'name': name, 'format': fmt, 'sections': self.sections,
            'stats': {'vertices': self.vertex_count, 'triangles': self.triangle_count,
                      'meshes': len(self.sections), **info},
            'bounds': self.bounds, 'warnings': self.warnings,
        }


def m3_layout(types):
    widths = (0, 2, 0, 2, 4, 4, 1)
    # Field types are specific to each slot, as established by the M3 importer.
    entries = []
    off = 0
    for i in range(11):
        t = types[i]
        size = (12 if t == 1 else 6 if t == 2 else 0) if i == 0 else (2 if t == 3 else 0) if i in (1, 2, 3) else (4 if t == 4 else 0) if i in (4, 5, 6, 7) else (4 if t == 5 else 0) if i in (8, 9) else (1 if t == 6 else 0)
        entries.append(off if size else None)
        off += size
    return entries, off


def read_m3(data: bytes, name: str):
    if len(data) < 0x630 or data[:4] != b'LDOM':
        raise FormatError('Keine gültige WildStar-M3-Datei (LDOM)')
    ver, = at(data, 4, '<I')
    acc = Accumulator()
    gc, ga = ap64(data, 0x250, 0x630, 0xc8)
    geo_base = (ga + gc * 0xc8 + 15) & ~15
    bone_count, bone_array = ap64(data, 0x180, 0x630, 0x160)
    clip_count, clip_array = ap64(data, 0x10, 0x630, 0x70)
    material_count, _ = ap64(data, 0x1f0, 0x630, 0x30)
    tex_count, tex_array = ap64(data, 0x1c0, 0x630, 0x20)
    total_bones, total_clips = bone_count, clip_count
    total_materials, total_textures = material_count, tex_count
    if any(c > 500_000 for c in (bone_count, clip_count, material_count, tex_count)):
        raise FormatError('M3-Metadatenarrays unrealistisch groß')
    # Metadata is independent of the static preview; retain useful names and
    # timelines even though this first viewer does not evaluate animation.
    clip_meta = []
    for i in range(min(clip_count, 96)):
        r = clip_array + i * 0x70
        anim_id, variant = at(data, r, '<2H')
        start, end = at(data, r + 0x0c, '<2I')
        clip_meta.append({'id': anim_id, 'variant': variant,
                          'durationMs': max(0, int(end) - int(start))})
    texture_meta = []
    texture_pool_base = (tex_array + tex_count * 0x20 + 15) & ~15
    for i in range(min(tex_count, 96)):
        r = tex_array + i * 0x20
        tex_id, tex_type = at(data, r, '<HB')
        char_count, offset = at(data, r + 0x10, '<QQ')
        if char_count > 8192:
            acc.warnings.append(f'Texturpfad {i} zu lang')
            continue
        start = texture_pool_base + offset
        if char_count:
            within(data, start, char_count * 2)
            tex_path = data[start:start + char_count * 2].decode('utf-16le', 'replace').rstrip('\0')
        else:
            tex_path = ''
        texture_meta.append({'id': tex_id, 'type': tex_type, 'path': tex_path})
    for gi in range(gc):
        g = ga + gi * 0xc8
        vcount, vsize, _ = at(data, g + 0x18, '<IHH')
        types = at(data, g + 0x20, '<11B')
        fields, actual_size = m3_layout(types)
        if vsize != actual_size or vsize == 0:
            raise FormatError(f'M3 Geometry {gi}: unbekanntes Vertexformat ({vsize} != {actual_size})')
        vc, vo = ap64(data, g + 0x38, geo_base, 1)
        within(data, vo, vcount * vsize)
        icount, = at(data, g + 0x68, '<I')
        idx_count, idx_start = ap64(data, g + 0x70, geo_base, 2)
        if idx_count < icount:
            raise FormatError('M3 Indexbuffer ist kürzer als erwartet')
        mc, ma = ap64(data, g + 0x80, geo_base, 0x70)
        if vcount > 4_000_000 or icount > 20_000_000 or mc > 10000:
            raise FormatError('M3-Array zu groß')
        # Decode the full geometry once; M3 mesh indices are relative to start_vertex.
        positions = []
        normals = []
        for i in range(vcount):
            pos = vo + i * vsize
            if types[0] == 1:
                p = at(data, pos + fields[0], '<3f')
            elif types[0] == 2:
                p = tuple(v / 1024.0 for v in at(data, pos + fields[0], '<3h'))
            else:
                raise FormatError('M3 ohne Positionsattribut')
            positions.append(p)
            if fields[2] is not None:
                a, b = at(data, pos + fields[2], '<BB')
                normals.append(oct_decode(a, b))
            else:
                normals.append((0, 1, 0))
        for j in range(mc):
            rec = ma + j * 0x70
            start_idx, first_vertex, num_idx, num_vertices = at(data, rec, '<4I')
            mat = at(data, rec + 0x16, '<H')[0]
            group = data[rec + 0x1e]
            cluster = data[rec + 0x22]
            if num_idx < 3 or num_vertices < 3:
                continue
            if first_vertex + num_vertices > vcount or start_idx + num_idx > icount:
                acc.warnings.append(f'Mesh {gi}:{j}: ungültiger Bereich übersprungen')
                continue
            raw_idx = at(data, idx_start + start_idx * 2, '<' + str(num_idx) + 'H')
            acc.add(f'Geometry {gi} / Mesh {j}', positions[first_vertex:first_vertex + num_vertices],
                    normals[first_vertex:first_vertex + num_vertices], raw_idx,
                    material=mat, group=group, cluster=cluster)
    result = acc.result(name, 'M3', {'bones': int(total_bones), 'animations': int(total_clips),
                                    'materials': int(total_materials), 'textures': int(total_textures), 'version': int(ver)})
    result['m3Details'] = {'clips': clip_meta, 'textures': texture_meta,
                           'moreClips': max(0, clip_count - len(clip_meta)),
                           'moreTextures': max(0, tex_count - len(texture_meta))}
    return result


def read_feds(data: bytes, name: str, acc: Accumulator | None = None):
    if len(data) < 0x1b0 or data[:4] != b'FEDS':
        raise FormatError('Kein gültiger I3-Sektor (FEDS)')
    ver, = at(data, 4, '<I')
    if ver != 30:
        raise FormatError(f'Unbekannte FEDS-Version {ver}')
    acc = acc if acc is not None else Accumulator()
    vc, va = ap32(data, 0x38, 0x1b0, 12)
    ac, aa = ap32(data, 0x48, 0x1b0, 20)
    ic, ia = ap32(data, 0x58, 0x1b0, 4)
    mc, ma = ap32(data, 0x78, 0x1b0, 28)
    if ac < vc or vc > 4_000_000 or ic > 20_000_000:
        raise FormatError('Ungültige FEDS-Vertex-/Indexanzahl')
    verts = [at(data, va + i * 12, '<3f') for i in range(vc)]
    norms = [oct_decode(data[aa + i * 20 + 6], data[aa + i * 20 + 5]) for i in range(vc)]
    for mi in range(mc):
        kind, first_i, last_i, first_v, last_v, code, _ = at(data, ma + mi * 28, '<7I')
        if first_i > last_i or last_i >= ic:
            acc.warnings.append(f'{name} Submesh {mi}: ungültiger Indexbereich')
            continue
        count = last_i - first_i + 1
        count -= count % 3
        if not count:
            continue
        indices = at(data, ia + first_i * 4, '<' + str(count) + 'I')
        lo = min(indices)
        hi = max(indices)
        if hi >= vc:
            acc.warnings.append(f'{name} Submesh {mi}: Vertexindex außerhalb des Puffers')
            continue
        acc.add(f'{name} / Submesh {mi}', verts[lo:hi + 1], norms[lo:hi + 1],
                [idx - lo for idx in indices], material=code >> 8, kind=int(kind), surface=int(code))
    return acc


def _read_fedi(data: bytes):
    if len(data) < 0x170 or data[:4] != b'FEDI' or at(data, 4, '<I')[0] != 41:
        raise FormatError('Keine gültige I3-Hauptdatei (FEDI v41)')
    pc, po = ap32(data, 0x120, 0x170, 2)
    pool = data[po:po + pc * 2].decode('utf-16le', 'replace')
    nc, no = ap32(data, 0x130, 0x170, 4)
    names = []
    for (i,) in struct.iter_unpack('<I', data[no:no + nc * 4]):
        if i >= len(pool):
            raise FormatError('FEDI Name außerhalb Stringpool')
        end = pool.find('\0', i)
        names.append(pool[i:end if end >= 0 else None])
    sc, so = ap32(data, 0x20, 0x170, 0x40)
    result = []
    for i in range(sc):
        n = at(data, so + i * 0x40, '<I')[0]
        if n >= len(names):
            raise FormatError('FEDI Sektorname ungültig')
        result.append(names[n])
    return result


# All 32 block widths from the original WildStar terrain descriptor table.
CELL_BLOCK_SIZES = (722,16,8450,8450,8450,4,64,16,4225,2178,4,578,1,
                    4624,2312,8450,4096,2312,2312,2312,2312,1,16,16900,
                    8,8450,21316,4096,16,8450,8450,2312)


def read_area(data: bytes, name: str):
    """Height geometry of a 512m AREA tile; no texture layers or props yet."""
    if data[:4] not in (b'area',b'AREA') or len(data)<16:
        raise FormatError('Keine gültige AREA-Datei')
    compressed = data[:4]==b'AREA'
    pos=8
    terrain=None
    while pos + 8 <= len(data):
        chunk_id=data[pos:pos+4]
        size=at(data,pos+4,'<I')[0]
        start=pos+8
        within(data,start,size)
        if chunk_id in (b'KNHC',b'CHNK'):
            terrain=data[start:start+size]
            break
        pos=start+size
    if terrain is None:
        raise FormatError('AREA ohne CHNK-Terrain')
    h=[None]*(257*257)
    off=0; last=0; first=True; valid_cells=0
    while off<len(terrain):
        if off+4>len(terrain):raise FormatError('AREA-Cellheader abgeschnitten')
        info=at(terrain,off,'<I')[0];off+=4
        delta=(info>>24)&255; raw_size=info&0xffffff
        if compressed:
            decomp=zlib.decompressobj()
            try:
                cell=decomp.decompress(terrain[off:], 8*1024*1024)
            except zlib.error as ex:
                raise FormatError('AREA-Zlib fehlerhaft') from ex
            if not decomp.eof:raise FormatError('AREA-Zlib-Stream unvollständig')
            off=len(terrain)-len(decomp.unused_data)
            if first:
                first=False
                continue
            if len(cell)!=raw_size:raise FormatError('AREA-Zlib-Größe stimmt nicht')
        else:
            within(terrain,off,raw_size)
            cell=terrain[off:off+raw_size];off+=raw_size
        idx=last+delta
        last=idx+1
        if idx>=256:raise FormatError('AREA-Zellindex außerhalb 16×16 Raster')
        if len(cell)<4:continue
        flags=at(cell,0,'<I')[0]
        expected=4+sum(CELL_BLOCK_SIZES[i] for i in range(32) if flags&(1<<i))
        if expected>len(cell):raise FormatError('AREA-Zellblöcke abgeschnitten')
        if not flags&1:continue
        samples=at(cell,4,'<361H')
        cx,cy=idx%16,idx//16
        for ly in range(17):
            for lx in range(17):
                gx=cx*16+lx; gy=cy*16+ly
                h[gy*257+gx]=samples[(ly+1)*19+(lx+1)]/8.0-2048.0
        valid_cells+=1
    if not valid_cells:
        raise FormatError('Keine Heightmap-Zellen vorhanden')
    # Build a complete grid; reject triangles crossing missing cells.
    positions=[];normals=[];indices=[]
    for gy in range(257):
        for gx in range(257):
            i=gy*257+gx
            height=h[i]
            if height is None:height=0.0
            positions.append((gx*2.0,height,gy*2.0))
            def hval(x,y):
                v=h[max(0,min(256,y))*257+max(0,min(256,x))]
                return v if v is not None else height
            sx=(hval(gx+1,gy)-hval(gx-1,gy))/4.0
            sy=(hval(gx,gy+1)-hval(gx,gy-1))/4.0
            nlen=math.sqrt(sx*sx+sy*sy+1)
            normals.append((-sx/nlen,1/nlen,sy/nlen))
    for gy in range(256):
        for gx in range(256):
            p=gy*257+gx
            if h[p] is None or h[p+1] is None or h[p+257] is None or h[p+258] is None:
                continue
            # Y-up source orientation -> renderer converts to Z-up.
            indices.extend((p,p+1,p+257,p+1,p+258,p+257))
    acc=Accumulator()
    acc.add('Terrain / Heightmap',positions,normals,indices,material=8,cells=valid_cells)
    acc.warnings.append('Nur Höhengeometrie: Texturlayer, Wasser, Props und Clutter werden noch nicht gerendert.')
    return acc.result(name,'AREA / Terrain',{'bones':0,'animations':0,'materials':0,'textures':0,
                                             'version':at(data,4,'<I')[0], 'cells':valid_cells})


def read_model_bytes(data: bytes, name: str, source_path: Path | None = None):
    if len(data) > (MAX_FILE if data[:4] == b'LDOM' else MAX_OTHER_FILE):
        raise FormatError('Datei zu groß für die Vorschau (M3 max. 512 MiB, I3/AREA max. 128 MiB).')
    if data[:4] in (b'area',b'AREA'):
        return read_area(data,name)
    if data[:4] == b'LDOM':
        from native_m3 import read_m3_native
        return read_m3_native(data, name)
    if data[:4] == b'FEDS':
        acc = read_feds(data, name)
        return acc.result(name, 'I3 / FEDS', {'bones': 0, 'animations': 0, 'materials': 'sektorabhängig', 'textures': 0, 'version': 30})
    if data[:4] == b'FEDI':
        if source_path is None:
            raise FormatError('I3-Hauptdateien benötigen die Sektordateien. Bitte „Datei vom PC öffnen“ verwenden.')
        sector_names = _read_fedi(data)
        acc = Accumulator()
        directory = {p.name.casefold(): p for p in source_path.parent.glob('*.i3') if p.is_file()}
        found = 0
        for name_part in sector_names:
            sector = directory.get(f'{source_path.stem}.{name_part}.i3'.casefold())
            if sector is None:
                acc.warnings.append(f'Sektor fehlt: {name_part}')
                continue
            if sector.stat().st_size > MAX_FILE:
                acc.warnings.append(f'Sektor zu groß: {sector.name}')
                continue
            read_feds(sector.read_bytes(), name_part, acc)
            found += 1
        return acc.result(name, 'I3 / FEDI', {'bones': 0, 'animations': 0, 'materials': 'mehrere', 'textures': 0,
                                              'version': 41, 'sectors': found, 'expectedSectors': len(sector_names)})
    raise FormatError('Nicht unterstützte Datei. Bitte .m3, .i3 oder .area wählen.')
