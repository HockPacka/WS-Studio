"""Native M3 DLL integration and output equivalence tests."""
import base64
import ctypes
import json
import struct
import sys
from pathlib import Path
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT))
from readers import read_m3, read_model_bytes, FormatError
from native_m3 import find_library, parser_status, read_m3_native

class NativeTests(unittest.TestCase):
    def test_native_library_present(self):
        self.assertTrue(find_library(), 'Native parser library missing')
        self.assertTrue(parser_status()['nativeM3'])

    def test_native_python_geometry_equivalent(self):
        p = ROOT / 'demo' / 'Crystal.m3'
        data = p.read_bytes()
        a = read_m3(data,p.name)
        b = read_model_bytes(data,p.name,p)
        self.assertEqual(b['parser'], 'Native C DLL (ABI 2)')
        self.assertEqual(a['stats'], b['stats'])
        self.assertEqual(len(a['sections']),len(b['sections']))
        for ma,mb in zip(a['sections'],b['sections']):
            self.assertEqual(ma['triangles'],mb['triangles'])
            self.assertEqual(ma['vertices'],mb['vertices'])
            self.assertEqual(base64.b64decode(ma['indices']),base64.b64decode(mb['indices']))
            px = struct.unpack('<%df' % (len(base64.b64decode(ma['positions']))//4),base64.b64decode(ma['positions']))
            py = struct.unpack('<%df' % (len(base64.b64decode(mb['positions']))//4),base64.b64decode(mb['positions']))
            for x,y in zip(px,py):self.assertAlmostEqual(x,y,places=5)

    def test_reject_bad_pointer(self):
        p=ROOT/'demo'/'Crystal.m3';s=bytearray(p.read_bytes())
        struct.pack_into('<Q',s,0x258,2**63)
        with self.assertRaises(FormatError): read_m3_native(bytes(s),'badpointer.m3')

    def test_truncated(self):
        with self.assertRaises(FormatError):read_m3_native(b'LDOM','truncated.m3')

    def test_windows_x64_dll_header(self):
        dll=ROOT/'native'/'ws_m3_parser.dll';data=dll.read_bytes()
        self.assertEqual(data[:2],b'MZ')
        pe=struct.unpack_from('<I',data,0x3c)[0]
        self.assertEqual(data[pe:pe+4],b'PE\0\0')
        self.assertEqual(struct.unpack_from('<H',data,pe+4)[0],0x8664)
        for symbol in (b'ws_m3_parse_json',b'ws_m3_abi_version',b'ws_m3_free',b'kernel32.dll'):
            self.assertIn(symbol,data)

if __name__ == '__main__':unittest.main()
