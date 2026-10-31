"""Split a WildStar .sho (STGT container with embedded DXBC blobs) and disassemble blobs with the system D3DCompiler_47.

usage: dxbc_dis.py <file.sho> [index|all-count] [outfile]
"""
import ctypes
import os
import struct
import sys


def find_blobs(data):
    out = []
    pos = 0
    while True:
        i = data.find(b'DXBC', pos)
        if i < 0:
            break
        if i + 32 <= len(data):
            size = struct.unpack_from('<I', data, i + 24)[0]
            if 32 < size <= len(data) - i:
                out.append((i, size))
                pos = i + size
                continue
        pos = i + 4
    return out


def disassemble(blob):
    dll = ctypes.WinDLL(r'C:\Windows\System32\D3DCompiler_47.dll')
    f = dll.D3DDisassemble
    f.argtypes = [ctypes.c_char_p, ctypes.c_size_t, ctypes.c_uint, ctypes.c_char_p, ctypes.POINTER(ctypes.c_void_p)]
    f.restype = ctypes.c_long
    res = ctypes.c_void_p()
    hr = f(blob, len(blob), 0, None, ctypes.byref(res))
    if hr != 0:
        raise RuntimeError('D3DDisassemble hr=0x%08X' % (hr & 0xFFFFFFFF))
    vt = ctypes.cast(ctypes.cast(res, ctypes.POINTER(ctypes.c_void_p))[0], ctypes.POINTER(ctypes.c_void_p))
    get_ptr = ctypes.WINFUNCTYPE(ctypes.c_void_p, ctypes.c_void_p)(vt[3])
    get_size = ctypes.WINFUNCTYPE(ctypes.c_size_t, ctypes.c_void_p)(vt[4])
    return ctypes.string_at(get_ptr(res), get_size(res)).decode('latin-1')


if __name__ == '__main__':
    data = open(sys.argv[1], 'rb').read()
    blobs = find_blobs(data)
    print(len(blobs), 'DXBC blobs; first sizes', [s for _, s in blobs[:8]])
    if len(sys.argv) > 2:
        idx = int(sys.argv[2])
        off, size = blobs[idx]
        txt = disassemble(data[off:off + size])
        if len(sys.argv) > 3:
            open(sys.argv[3], 'w', encoding='utf-8').write(txt)
        else:
            print(txt)
