"""Read and disassemble WoW Terrain.bls permutations from the local MPQ files.

usage: terrain_shader_dump.py <64-bit StormLib.dll> <WoWClient> <output dir>
"""
import ctypes as c
from pathlib import Path
import struct
import sys

from dxbc_dis import disassemble


def main():
    dll = c.WinDLL(str(Path(sys.argv[1]).resolve()))
    dll.SFileOpenArchive.argtypes = [c.c_char_p, c.c_uint, c.c_uint, c.POINTER(c.c_void_p)]
    dll.SFileOpenFileEx.argtypes = [c.c_void_p, c.c_char_p, c.c_uint, c.POINTER(c.c_void_p)]
    dll.SFileGetFileSize.argtypes = [c.c_void_p, c.POINTER(c.c_uint)]
    dll.SFileGetFileSize.restype = c.c_uint
    dll.SFileReadFile.argtypes = [c.c_void_p, c.c_void_p, c.c_uint, c.POINTER(c.c_uint), c.c_void_p]
    dll.SFileCloseFile.argtypes = [c.c_void_p]
    dll.SFileCloseArchive.argtypes = [c.c_void_p]
    for name in ('SFileOpenArchive', 'SFileOpenFileEx', 'SFileReadFile', 'SFileCloseFile', 'SFileCloseArchive'):
        getattr(dll, name).restype = c.c_bool
    out = Path(sys.argv[3])
    out.mkdir(parents=True, exist_ok=True)
    archives = list((Path(sys.argv[2]) / 'Data').glob('*.MPQ'))
    # Patch archives override base archives; the highest patch number wins.
    def priority(p):
        name = p.stem.lower()
        return (1, int(name.split('-')[1]) if '-' in name else 1) if name.startswith('patch') else (0, name)
    archives.sort(key=priority, reverse=True)
    for profile in ('vs_3_0', 'vs_2_0', 'vs_1_1'):
        entry = f'Shaders\\Vertex\\{profile}\\Terrain.bls'.encode()
        for archive in archives:
            handle, file = c.c_void_p(), c.c_void_p()
            if not dll.SFileOpenArchive(str(archive.resolve()).encode(), 0, 0x100, c.byref(handle)):
                continue
            try:
                if not dll.SFileOpenFileEx(handle, entry, 0, c.byref(file)):
                    continue
                try:
                    high = c.c_uint()
                    size = dll.SFileGetFileSize(file, c.byref(high))
                    if high.value or size == 0xFFFFFFFF:
                        print('unreadable entry:', archive.name, profile)
                        continue
                    buf, read = c.create_string_buffer(size), c.c_uint()
                    if not dll.SFileReadFile(file, buf, size, c.byref(read), None) or read.value != size:
                        raise ValueError('short MPQ read')
                    data = buf.raw
                finally:
                    dll.SFileCloseFile(file)
            finally:
                dll.SFileCloseArchive(handle)
            magic, version, unknown = struct.unpack_from('<3I', data)
            if magic != 0x47585348 or version != 0x10003:
                raise ValueError('unsupported BLS header')
            pos = 12
            count = 0
            while pos < len(data):
                size = struct.unpack_from('<I', data, pos + 12)[0]
                code = data[pos + 16:pos + 16 + size]
                if size:
                    (out / f'terrain_{profile}_{count:03d}.txt').write_text(disassemble(code), encoding='utf-8')
                count += 1
                pos += 16 + ((size + 3) & ~3)
            print(profile, archive.name, count, 'permutations')
            break


if __name__ == '__main__':
    main()
