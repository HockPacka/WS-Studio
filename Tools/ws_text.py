"""Reader for the WildStar language file (ClientDataEN/en-US.bin, magic 'LTEX' stored as 'XETL').

Layout (verified: id 1 = Cancel, 2 = Help, 3 = Ok):
  0x40  u32 entry count
  0xA0  entry table, count x (u32 id, u32 text offset in UTF-16 characters)
  0xA0 + 8 * count + 8  start of the text block (UTF-16LE, zero terminated)
usage: ws_text.py <en-US.bin> <id> [id...]
"""
import struct
import sys


def load(path):
    b = open(path, 'rb').read()

    if b[:4] != b'XETL' and b[:4] != b'LTEX':
        raise ValueError('not a language file')

    n = struct.unpack_from('<I', b, 0x40)[0]
    table = 0xA0
    base = table + n * 8 + 8
    out = {}

    for i in range(n):
        id_, off = struct.unpack_from('<II', b, table + i * 8)
        o = base + off * 2
        e = b.find(b'\0\0', o)

        while e >= 0 and (e - o) % 2:
            e = b.find(b'\0\0', e + 1)

        out[id_] = b[o:e].decode('utf-16le', 'replace')

    return out


if __name__ == '__main__':
    t = load(sys.argv[1])

    for a in sys.argv[2:]:
        print(a, t.get(int(a)))
