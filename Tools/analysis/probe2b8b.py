"""Show full 0x2B8 records (with nested bool tracks) for models whose elements have nested records."""
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

shown = 0
for f in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True)):
    b = open(f, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    c, o = struct.unpack_from('<QQ', b, 0x2B8)
    if not c:
        continue
    a = o + vb.H
    base = vb.a16(a + c * 0x28)
    hit = False
    for k in range(c):
        e = a + k * 0x28
        n18, o18 = struct.unpack_from('<QQ', b, e + 0x18)
        if n18 >= 2:
            hit = True
    if not hit:
        continue
    shown += 1
    print('==', os.path.relpath(f, vb.ROOT), 'elements', c)
    for k in range(c):
        e = a + k * 0x28
        n08, o08 = struct.unpack_from('<QQ', b, e + 8)
        n18, o18 = struct.unpack_from('<QQ', b, e + 0x18)
        print('  [%d] id %#x  n08 %d  n18 %d  tail %s' % (k, struct.unpack_from('<I', b, e)[0], n08, n18, b[e + 0x20:e + 0x28].hex()))
        rb = vb.a16(base + o18 + n18 * 0x20) if False else None
        ra = base + o18
        nb = vb.a16(ra + n18 * 0x20)
        for r in range(n18):
            re_ = ra + r * 0x20
            w0, = struct.unpack_from('<Q', b, re_)
            cnt, ko, vo = struct.unpack_from('<QQQ', b, re_ + 8)
            keys = struct.unpack_from('<%dI' % cnt, b, nb + ko) if cnt else ()
            vals = b[nb + vo:nb + vo + cnt].hex() if cnt else ''
            print('      rec %d: w0 %#018x  dp count %d keys %s vals %s' % (r, w0, cnt, keys[:8], vals[:16]))
    if shown >= 4:
        break
