"""Structural walker for WildStar .m3: attributes every byte of a file to an array / track / blob and measures value strides.

Everything in an .m3 is a tree of arrays:  AP = (u64 count, u64 offset)  and  DP = (u64 count, u64 keyOffset, u64 valueOffset).
Header-level offsets are relative to 0x630; nested ones are relative to align16(end of the parent array).
`SPEC` lists, per header array, the element size and the positions of nested AP / DP fields inside the element.
"""
import collections
import struct

H = 0x630


def a16(x):
    return (x + 15) & ~15


# top level arrays: slot -> (name, element size)
TOP_AP = {0x010: ('clips', 0x70), 0x080: ('ap080', 0x30), 0x0F0: ('ap0F0', 0xB8), 0x180: ('bones', 0x160), 0x190: ('ap190', 2), 0x1A0: ('ap1A0', 2),
          0x1B0: ('boneMap', 2), 0x1C0: ('textures', 0x20), 0x1D0: ('ap1D0', 2), 0x1E0: ('ap1E0', 0x98), 0x1F0: ('materials', 0x30),
          0x200: ('ap200', 4), 0x210: ('ap210', 2), 0x220: ('ap220', 0x46), 0x230: ('ap230', 4), 0x240: ('ap240', 0x70), 0x250: ('geometry', 0xC8),
          0x260: ('ap260', 4), 0x270: ('ap270', 2), 0x280: ('ap280', 8), 0x2A8: ('ap2A8', 0x10), 0x2B8: ('ap2B8', 0x28), 0x2C8: ('ap2C8', 8),
          0x2D8: ('ap2D8', 2), 0x2E8: ('ap2E8', 8), 0x2F8: ('ap2F8', 0xA0), 0x308: ('ap308', 0x50), 0x318: ('ap318', 0x190), 0x328: ('ap328', 0x38),
          0x338: ('ap338', 2), 0x490: ('ap490', 0x40), 0x4A0: ('ap4A0', 4), 0x510: ('ap510', 0x10), 0x520: ('ap520', 4), 0x530: ('ap530', 4),
          0x540: ('ap540', 0x68), 0x550: ('ap550', 2), 0x560: ('ap560', 0xA0), 0x570: ('ap570', 0x20), 0x588: ('ap588', 0x20), 0x598: ('ap598', 0x4C),
          0x5A8: ('ap5A8', 2)}
TOP_DP = [0x20, 0x38, 0x50, 0x68, 0x90, 0xA8, 0xC0, 0xD8, 0x100, 0x118, 0x130, 0x148, 0x160, 0x290, 0x350, 0x370, 0x5C0]

# nested layouts (positions inside the element): name -> {'ap': [offsets], 'dp': [offsets]}
SPEC = {
    'ap0F0': {'dp': [0x08, 0x20, 0x38, 0x50, 0x68, 0x80, 0x98]},
    'ap1E0': {'dp': [0x08, 0x20, 0x38, 0x50, 0x68, 0x80]},
    # material layer ("description", 0x128 B): 9 scalar DPs, the raw DP at +0x90 and the color multiplier DP at +0x108
    'desc': {'dp': [0x18, 0x30, 0x48, 0x60, 0x78, 0x90, 0xA8, 0xC0, 0xD8, 0xF0, 0x108]},
    'ap2F8': {'dp': [0x20, 0x38, 0x50], 'blob': [0x90]},
    'ap308': {'dp': [0x08, 0x20, 0x38]},
    # engine loader FUN_14030c7d0: 3 x S2, 2 x S4 (colors), 11 x S2
    'ap318': {'dp': [0x10, 0x28, 0x40, 0x58, 0x70, 0x88, 0xA0, 0xB8, 0xD0, 0xE8, 0x100, 0x118, 0x130, 0x148, 0x160, 0x178]},
    'ap328': {'dp': [0x10]},
    # collision block: 4 APs (header records 16 B, float3 vertices, u32 indices, 20 B kd-tree nodes)
    'ap490': {'ap': [(0x00, 0x10), (0x10, 0xC), (0x20, 4), (0x30, 0x14)]},
    # FUN_14030f660: S2, S4, S6 DPs + DP with 8-byte values
    'ap540': {'dp': [0x08, 0x20, 0x38, 0x50]},
    # FUN_14030c930: S2 + DP(count,u32 keys,u16 values) + 3 x S4
    'ap560': {'dp': [0x28, 0x40, 0x58, 0x70, 0x88]},
    'ap570': {'dp': [0x08]},
    'ap588': {'dp': [0x08]},
    # sound emitter: AP of 0x20-byte records at +0x08 and +0x18; each record has a DP at +0x08 (u16 / u8 values)
    'ap2B8': {'ap': [(0x08, 0x20), (0x18, 0x20)], 'sub': {0x08: {'dp': [0x08]}, 0x18: {'dp': [0x08]}}},
}


class Region:
    __slots__ = ('start', 'count', 'label', 'kind', 'elem')

    def __init__(self, start, count, label, kind, elem=0):
        self.start, self.count, self.label, self.kind, self.elem = start, count, label, kind, elem


def nest(b, addr, count, es, spec, name, add, depth=0):
    """registers every nested array of `count` elements at `addr`; spec: 'ap' [(offset, elem size)], 'dp' [offsets], 'blob' [offsets],
    'sub' {ap offset: spec of its records}"""
    size = len(b)
    if depth > 3 or addr + count * es > size:
        return
    base = a16(addr + count * es)
    for k in range(count):
        e = addr + k * es
        for p in spec.get('ap', []):
            p, ees = p if isinstance(p, tuple) else (p, 0)
            cc, oo = struct.unpack_from('<QQ', b, e + p)
            add(base + oo, cc, '%s+%X' % (name, p), 'ap', ees)
            if cc and p in spec.get('sub', {}):
                nest(b, base + oo, cc, ees, spec['sub'][p], '%s+%X' % (name, p), add, depth + 1)
        for p in spec.get('dp', []):
            cc, ko, vo = struct.unpack_from('<QQQ', b, e + p)
            add(base + ko, cc, '%s+%X.keys' % (name, p), 'keys', 4)
            add(base + vo, cc, '%s+%X.values' % (name, p), 'values')
        for p in spec.get('blob', []):
            (bo,) = struct.unpack_from('<Q', b, e + p)
            if bo < (1 << 40):
                add(base + bo, 1, '%s+%X.blob' % (name, p), 'blob')


def collect(b):
    """returns list of Region for every array start found (without end; end is derived from the next start)"""
    size = len(b)
    regs = []

    def add(addr, count, label, kind, elem=0):
        if count and 0 <= addr < size:
            regs.append(Region(addr, count, label, kind, elem))

    for slot, (name, es) in TOP_AP.items():
        c, o = struct.unpack_from('<QQ', b, slot)
        if not c:
            continue
        addr = o + H
        add(addr, c, name, 'ap', es)
        if name in SPEC and addr + c * es <= size:
            nest(b, addr, c, es, SPEC[name], name, add)
    for slot in TOP_DP:
        c, k, v = struct.unpack_from('<QQQ', b, slot)
        add(k + H, c, 'dp%03X.keys' % slot, 'keys', 4)
        add(v + H, c, 'dp%03X.values' % slot, 'values')
    # bones
    bc, bo = struct.unpack_from('<QQ', b, 0x180)
    ba = bo + H
    base = a16(ba + bc * 0x160)
    for i in range(bc):
        for j in range(8):
            c, k, v = struct.unpack_from('<QQQ', b, ba + i * 0x160 + 0x10 + j * 24)
            add(k + base, c, 'bone.t%d.keys' % j, 'keys', 4)
            add(v + base, c, 'bone.t%d.values' % j, 'values', (6, 6, 6, 6, 8, 8, 12, 12)[j])
    # textures / materials / geometry
    tc, to = struct.unpack_from('<QQ', b, 0x1C0)
    ta = to + H
    nb = a16(ta + tc * 0x20)
    for i in range(tc):
        c, o = struct.unpack_from('<QQ', b, ta + i * 0x20 + 16)
        add(o + nb, c, 'texture.name', 'ap', 2)
    mc, mo = struct.unpack_from('<QQ', b, 0x1F0)
    ma = mo + H
    db = a16(ma + mc * 0x30)
    for i in range(mc):
        c, o = struct.unpack_from('<QQ', b, ma + i * 0x30 + 0x20)
        add(o + db, c, 'material.descriptions', 'ap', 0x128)
        if c:
            nest(b, o + db, c, 0x128, SPEC['desc'], 'desc', add)
    gc, go = struct.unpack_from('<QQ', b, 0x250)
    ga = go + H
    gb = a16(ga + gc * 0xC8)
    for i in range(gc):
        g = ga + i * 0xC8
        for off, nm, es in ((0x08, 'geo.sub08', 1), (0x38, 'geo.vertices', 0), (0x48, 'geo.sub48', 1), (0x58, 'geo.sub58', 1), (0x70, 'geo.indices', 2),
                            (0x80, 'geo.meshes', 0x70), (0x98, 'geo.meshVertexRange', 4), (0xA8, 'geo.subA8', 2), (0xB8, 'geo.subB8', 4)):
            c, o = struct.unpack_from('<QQ', b, g + off)
            add(o + gb, c, nm, 'ap', es)
    return regs


def extents(b, regs=None):
    """sorted [(start, end, region)] where end = next distinct start (or EOF)"""
    regs = regs if regs is not None else collect(b)
    regs = sorted(regs, key=lambda r: r.start)
    out = []
    starts = sorted({r.start for r in regs})
    nxt = {s: (starts[i + 1] if i + 1 < len(starts) else len(b)) for i, s in enumerate(starts)}
    for r in regs:
        out.append((r.start, nxt[r.start], r))
    return out


def stride_of(count, span):
    """value stride from the span to the next array (padding < 16)"""
    if count <= 0:
        return None
    s = span // count
    if s * count <= span < s * count + 16:
        return s
    return None
