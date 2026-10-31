"""Which header slot 'owns' how many bytes of all .m3 files?  (extent = start of an array up to the start of the next array)

Known, decoded structures are attributed to their own label, everything between two array starts belongs to the earlier one.
Output: docs/m3_byte_ownership.json + table. Run: python -I tools/analysis/byte_ownership.py [every-nth-file]"""
import collections
import json
import multiprocessing as mp
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
sys.path.insert(0, TOOLS)
import halon  # noqa: E402
from validate_formats import inflate, PATCH, ROOT, ARCHIVES, a16  # noqa: E402

H = 0x630
AP = {0x010: 'clips', 0x080: 'ap080', 0x0F0: 'ap0F0', 0x180: 'bones', 0x190: 'ap190', 0x1A0: 'ap1A0', 0x1B0: 'boneMap', 0x1C0: 'textures',
      0x1D0: 'ap1D0', 0x1E0: 'ap1E0', 0x1F0: 'materials', 0x200: 'ap200', 0x210: 'ap210', 0x220: 'ap220', 0x230: 'ap230', 0x240: 'ap240',
      0x250: 'geometry', 0x260: 'ap260', 0x270: 'ap270', 0x280: 'ap280', 0x2A8: 'ap2A8', 0x2B8: 'ap2B8', 0x2C8: 'ap2C8', 0x2D8: 'ap2D8',
      0x2E8: 'ap2E8', 0x2F8: 'ap2F8', 0x308: 'ap308', 0x318: 'ap318', 0x328: 'ap328', 0x338: 'ap338', 0x490: 'ap490', 0x4A0: 'ap4A0',
      0x510: 'ap510', 0x520: 'ap520', 0x530: 'ap530', 0x540: 'ap540', 0x550: 'ap550', 0x560: 'ap560', 0x570: 'ap570', 0x588: 'ap588',
      0x598: 'ap598', 0x5A8: 'ap5A8'}
DP = {0x20: 'dp020', 0x38: 'dp038', 0x50: 'dp050', 0x68: 'dp068', 0x90: 'dp090', 0xA8: 'dp0A8', 0xC0: 'dp0C0', 0xD8: 'dp0D8', 0x100: 'dp100',
      0x118: 'dp118', 0x130: 'dp130', 0x148: 'dp148', 0x160: 'dp160', 0x290: 'dp290', 0x350: 'dp350', 0x370: 'dp370', 0x5C0: 'dp5C0'}


def starts(b):
    """list of (address, label) for every array start we can find"""
    out = []
    for off, name in AP.items():
        c, o = struct.unpack_from('<QQ', b, off)
        if c:
            out.append((o + H, name))
    for off, name in DP.items():
        c, k, v = struct.unpack_from('<QQQ', b, off)
        if c:
            out.append((k + H, name + '.keys'))
            out.append((v + H, name + '.values'))
    # bones' tracks
    bc, bo = struct.unpack_from('<QQ', b, 0x180)
    ba = bo + H
    base = a16(ba + bc * 0x160)
    for i in range(bc):
        for j in range(8):
            c, k, v = struct.unpack_from('<QQQ', b, ba + i * 0x160 + 0x10 + j * 24)
            if c:
                out.append((k + base, 'bone.track%d.keys' % j))
                out.append((v + base, 'bone.track%d.values' % j))
    # textures names, materials descriptions, geometry sub arrays
    tc, to = struct.unpack_from('<QQ', b, 0x1C0)
    ta = to + H
    nb = a16(ta + tc * 0x20)
    for i in range(tc):
        c, o = struct.unpack_from('<QQ', b, ta + i * 0x20 + 16)
        if c:
            out.append((o + nb, 'textures.names'))
    mc, mo = struct.unpack_from('<QQ', b, 0x1F0)
    ma = mo + H
    db = a16(ma + mc * 0x30)
    for i in range(mc):
        c, o = struct.unpack_from('<QQ', b, ma + i * 0x30 + 0x20)
        if c:
            out.append((o + db, 'materials.descriptions'))
    gc, go = struct.unpack_from('<QQ', b, 0x250)
    ga = go + H
    gb = a16(ga + gc * 0xC8)
    for i in range(gc):
        g = ga + i * 0xC8
        for off, nm in ((0x08, 'geo.sub08'), (0x38, 'geo.vertices'), (0x48, 'geo.sub48'), (0x58, 'geo.sub58'), (0x70, 'geo.indices'),
                        (0x80, 'geo.meshes'), (0x98, 'geo.meshVertexRange'), (0xA8, 'geo.subA8'), (0xB8, 'geo.subB8')):
            c, o = struct.unpack_from('<QQ', b, g + off)
            if c:
                out.append((o + gb, nm))
    return out


def worker(a):
    wid, n, step = a
    own = collections.Counter()
    tot = 0
    count = 0
    i = 0
    for name in ARCHIVES:
        fs = halon.Filesystem(os.path.join(PATCH, name))
        with open(fs.data.name, 'rb') as arc:
            stack = [fs.root]
            files = []
            while stack:
                d = stack.pop()
                files.extend(d.files.values())
                stack.extend(d.dirs.values())
            files.sort(key=lambda f: f.path)
            for f in files:
                if not f.name.lower().endswith('.m3'):
                    continue
                i += 1
                if i % n != wid or (i // n) % step:
                    continue
                idx, _ = fs.data.blocks[f.sha1]
                off, bs = fs.data.fs[idx]
                arc.seek(off)
                b = inflate(f, arc.read(bs))
                if b[:4] != b'LDOM':
                    continue
                st = sorted(set(starts(b)))
                size = len(b)
                own['header'] += H
                tot += size
                count += 1
                for k, (addr, label) in enumerate(st):
                    end = st[k + 1][0] if k + 1 < len(st) else size
                    if end > addr:
                        own[label] += end - addr
    return own, tot, count


if __name__ == '__main__':
    mp.freeze_support()
    step = int(sys.argv[1]) if len(sys.argv) > 1 else 1
    n = max(1, (os.cpu_count() or 4) - 2)
    with mp.Pool(n) as p:
        parts = p.map(worker, [(w, n, step) for w in range(n)])
    own = collections.Counter()
    tot = 0
    cnt = 0
    for o, t, c in parts:
        own.update(o)
        tot += t
        cnt += c
    json.dump({'files': cnt, 'bytes': tot, 'owned': dict(own)}, open(os.path.join(ROOT, 'docs', 'm3_byte_ownership.json'), 'w'), indent=1)
    print('files', cnt, 'bytes %.2f GB' % (tot / 2 ** 30))
    for k, v in own.most_common(45):
        print('%-26s %14d  %5.2f%%' % (k, v, 100.0 * v / tot))
