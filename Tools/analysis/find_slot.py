"""Try a record spec at every 8-byte header position and report where it validates. usage: find_slot.py [every-nth-file]"""
import collections
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS)
import validate_blocks as vb  # noqa: E402

SPEC = (0x40, [(0x00, 'ap', 0x10), (0x10, 'ap', 0xC), (0x20, 'ap', 4), (0x30, 'ap', 0x14)])
step = int(sys.argv[1]) if len(sys.argv) > 1 else 40
files = sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]
ok = collections.Counter()
bad = collections.Counter()
for f in files:
    b = open(f, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    for slot in range(0x340, 0x630 - 15, 8):
        c, o = struct.unpack_from('<QQ', b, slot)
        if not 0 < c < 4096:
            continue
        r = vb.check_array(b, o + vb.H, c, SPEC[0], SPEC[1], True, collections.Counter(), 'x')
        (ok if r else bad)[slot] += 1
for slot in sorted(set(ok) | set(bad)):
    print('%03X ok %d bad %d' % (slot, ok[slot], bad[slot]))
