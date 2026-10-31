"""Lists the WMO (.i3 structure) placements of an ADT built by adt_build_cli with their WoW world position (for `.go xyz`).
usage: adt_structures.py <file.adt>
"""
import struct
import sys

b = open(sys.argv[1], 'rb').read()
o = 0
ch = {}
while o < len(b):
    t = b[o:o + 4][::-1].decode('latin-1')
    sz = struct.unpack_from('<I', b, o + 4)[0]
    if t != 'MCNK':
        ch[t] = (o + 8, sz)
    o += 8 + sz
mw = ch['MWMO']
names = b[mw[0]:mw[0] + mw[1]].split(b'\0')[:-1]
mo = ch['MODF']
for i in range(mo[1] // 64):
    r = mo[0] + 64 * i
    nid, uid, x, y, z = struct.unpack_from('<2I3f', b, r)
    print('%-60s world X=%.1f Y=%.1f Z=%.1f' % (names[nid].decode().split('\\')[-1], 17066.666 - z, 17066.666 - x, y))
