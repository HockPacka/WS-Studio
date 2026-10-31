"""Read data at virtual addresses of WildStar64.exe.  usage: pe_str.py addr[,addr...] [len]   (prints ascii/utf-16 strings and hex)"""
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
exe = open(os.path.join(ROOT, 'WildStar', 'Client64', 'WildStar64.exe'), 'rb').read()
pe = struct.unpack_from('<I', exe, 0x3C)[0]
nsec = struct.unpack_from('<H', exe, pe + 6)[0]
opt = struct.unpack_from('<H', exe, pe + 20)[0]
base = struct.unpack_from('<Q', exe, pe + 24 + 24)[0]
secs = []
for i in range(nsec):
    s = pe + 24 + opt + i * 40
    vsz, va, rsz, raw = struct.unpack_from('<IIII', exe, s + 8)
    secs.append((va, vsz, raw, rsz))


def read(addr, n):
    rva = addr - base
    for va, vsz, raw, rsz in secs:
        if va <= rva < va + max(vsz, rsz):
            return exe[raw + rva - va: raw + rva - va + n]
    return b''


n = int(sys.argv[2]) if len(sys.argv) > 2 else 96
for a in sys.argv[1].split(','):
    d = read(int(a, 16), n)
    u = d.decode('utf-16le', 'replace').split('\0')[0]
    s = d.decode('latin-1').split('\0')[0]
    print(a, repr(s[:80]), '| utf16:', repr(u[:80]), '|', d[:24].hex(' ', 4))
