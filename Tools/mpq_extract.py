#!/usr/bin/env python3
"""Minimal pure-python MPQ (v1/v2, WoW 3.3.5a) file extractor - no StormLib / 32-bit dll needed.

usage: mpq_extract.py <client Data dir> <out dir> <mpq path> [<mpq path> ...]
  e.g. mpq_extract.py WoWClient\\Data tools\\_mpq_out Interface\\GlueXML\\CharacterCreate.lua DBFilesClient\\ChrRaces.dbc
Archives are searched in 3.3.5a priority order (patches first); first hit wins.
Only whole-file replacements are supported (PTCH patch files are skipped / reported).
"""
import bz2
import os
import struct
import sys
import zlib

ORDER = [
    'patch-5.MPQ', 'patch-4.MPQ', 'patch-3.MPQ', 'patch-2.MPQ', 'patch.MPQ',
    'enUS/patch-enUS-3.MPQ', 'enUS/patch-enUS-2.MPQ', 'enUS/patch-enUS.MPQ',
    'enUS/locale-enUS.MPQ', 'enUS/expansion-locale-enUS.MPQ', 'enUS/lichking-locale-enUS.MPQ',
    'lichking.MPQ', 'expansion.MPQ', 'common-2.MPQ', 'common.MPQ',
    'enUS/base-enUS.MPQ',
]

_tab = {}


def _init_crypt():
    seed = 0x00100001
    for i in range(256):
        idx = i
        for _ in range(5):
            seed = (seed * 125 + 3) % 0x2AAAAB
            t1 = (seed & 0xFFFF) << 16
            seed = (seed * 125 + 3) % 0x2AAAAB
            t2 = seed & 0xFFFF
            _tab[idx] = t1 | t2
            idx += 0x100


_init_crypt()


def mpq_hash(s, kind):
    s1, s2 = 0x7FED7FED, 0xEEEEEEEE
    for c in s.upper().replace('/', '\\'):
        ch = ord(c)
        v = _tab[(kind << 8) + ch]
        s1 = (v ^ (s1 + s2)) & 0xFFFFFFFF
        s2 = (ch + s1 + s2 + (s2 << 5) + 3) & 0xFFFFFFFF
    return s1


def decrypt(data, key):
    n = len(data) // 4
    vals = list(struct.unpack('<%dI' % n, data[:n * 4]))
    s2 = 0xEEEEEEEE
    for i in range(n):
        s2 = (s2 + _tab[0x400 + (key & 0xFF)]) & 0xFFFFFFFF
        v = vals[i] ^ ((key + s2) & 0xFFFFFFFF)
        key = (((~key << 21) + 0x11111111) | (key >> 11)) & 0xFFFFFFFF
        s2 = (v + s2 + (s2 << 5) + 3) & 0xFFFFFFFF
        vals[i] = v
    return struct.pack('<%dI' % n, *vals) + data[n * 4:]


class Mpq:
    def __init__(self, path):
        self.f = open(path, 'rb')
        raw = self.f.read(0x2000)
        # header may be at any 0x200 boundary (user data header 'MPQ\x1b' redirects)
        base = 0
        while True:
            self.f.seek(base)
            sig = self.f.read(4)
            if sig == b'MPQ\x1a':
                break
            if sig == b'MPQ\x1b':
                self.f.seek(base + 8)
                base += struct.unpack('<I', self.f.read(4))[0]
                continue
            base += 0x200
            if base > 0x100000:
                raise ValueError('no MPQ header in ' + path)
        self.base = base
        self.f.seek(base + 4)
        hs, _asz, fmt, shift = struct.unpack('<IIHH', self.f.read(12))
        ht_off, bt_off, ht_n, bt_n = struct.unpack('<4I', self.f.read(16))
        self.sector = 512 << shift
        self.f.seek(base + ht_off)
        ht = decrypt(self.f.read(ht_n * 16), mpq_hash('(hash table)', 3))
        self.hash = [struct.unpack_from('<IIHHI', ht, i * 16) for i in range(ht_n)]
        self.f.seek(base + bt_off)
        bt = decrypt(self.f.read(bt_n * 16), mpq_hash('(block table)', 3))
        self.block = [struct.unpack_from('<4I', bt, i * 16) for i in range(bt_n)]
        self.mask = ht_n - 1

    def find(self, name):
        a, b = mpq_hash(name, 1), mpq_hash(name, 2)
        i = mpq_hash(name, 0) & self.mask
        for _ in range(len(self.hash)):
            ha, hb, _loc, _pl, bi = self.hash[i]
            if bi == 0xFFFFFFFF:
                return None
            if ha == a and hb == b and bi != 0xFFFFFFFE:
                return bi
            i = (i + 1) & self.mask
        return None

    def read(self, name):
        bi = self.find(name)
        if bi is None:
            return None
        off, csz, fsz, flags = self.block[bi]
        if not flags & 0x80000000:
            return None
        if flags & 0x100000:
            return b'PATCH'
        self.f.seek(self.base + off)
        raw = self.f.read(csz)
        key = 0
        if flags & 0x10000:
            key = mpq_hash(os.path.basename(name.replace('/', '\\').split('\\')[-1]), 3)
            if flags & 0x20000:
                key = (key + off) ^ fsz
        if flags & 0x1000000:  # single unit
            data = decrypt(raw, key) if flags & 0x10000 else raw
            return self._unc(data, fsz, flags)
        n = (fsz + self.sector - 1) // self.sector
        if flags & 0x200:  # compressed with sector offset table
            offs = list(struct.unpack('<%dI' % (n + 1), (decrypt(raw[:(n + 1) * 4], key - 1) if flags & 0x10000 else raw[:(n + 1) * 4])))
            out = b''
            for i in range(n):
                sec = raw[offs[i]:offs[i + 1]]
                if flags & 0x10000:
                    sec = decrypt(sec, key + i)
                want = min(self.sector, fsz - i * self.sector)
                out += self._unc(sec, want, flags)
            return out
        out = b''
        for i in range(n):
            sec = raw[i * self.sector:(i + 1) * self.sector]
            out += decrypt(sec, key + i) if flags & 0x10000 else sec
        return out

    @staticmethod
    def _unc(data, want, flags):
        if len(data) >= want or not flags & 0x200 and not flags & 0x1000000:
            return data[:want] if len(data) >= want else data
        m = data[0]
        d = data[1:]
        if m & 0x02:
            d = zlib.decompress(d)
        elif m & 0x10:
            d = bz2.decompress(d)
        elif m:
            raise NotImplementedError('mpq compression 0x%02x' % m)
        return d


def main():
    data_dir, out_dir, files = sys.argv[1], sys.argv[2], sys.argv[3:]
    archives = []
    for rel in ORDER:
        p = os.path.join(data_dir, rel)
        if os.path.exists(p):
            try:
                archives.append((rel, Mpq(p)))
            except Exception as e:
                print('skip', rel, e)
    for name in files:
        done = False
        for rel, a in archives:
            d = a.read(name)
            if d is None:
                continue
            if d == b'PATCH':
                print('%s: patch file in %s (skipped, looking further)' % (name, rel))
                continue
            dst = os.path.join(out_dir, name.replace('/', os.sep))
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            open(dst, 'wb').write(d)
            print('%s <- %s (%d bytes)' % (name, rel, len(d)))
            done = True
            break
        if not done:
            print('%s: NOT FOUND' % name)


if __name__ == '__main__':
    main()
