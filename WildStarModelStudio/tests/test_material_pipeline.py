"""Texture decoding, path isolation, material catalogue and native M3 loading."""
import base64
from io import BytesIO
from pathlib import Path
import struct
import sys
import tempfile
import unittest

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT))
from tex_decoder import header, decode, decode_png, TexError
from material_service import attach_materials, clientdata_root, color_state, texture_path
from native_m3 import read_m3_native
from tests.test_native_m3_extended import enriched


def tex(fmt,dimensions=(4,4),pixels=None,kind=0,jpg=0,channels=None):
    w,h=dimensions
    b=bytearray(112);b[1:4]=b'GFX'
    struct.pack_into('<9I',b,4,3,w,h,1,1,1,fmt,jpg,kind)
    if channels:
        for i, values in enumerate(channels):struct.pack_into('<3B',b,40+i*3,*values)
    if pixels:b.extend(pixels)
    return bytes(b)

class TexDecoderTests(unittest.TestCase):
    def test_dxt1(self):
        x=tex(13,pixels=struct.pack('<HHI',0xf800,0x07e0,0))
        self.assertEqual(decode(x).getpixel((0,0)),(255,0,0,255))
        self.assertTrue(decode_png(x).startswith(b'\x89PNG'))
    def test_bgra(self):
        x=tex(0,dimensions=(1,1),pixels=bytes([10,20,30,40]))
        self.assertEqual(decode(x).getpixel((0,0)),(30,20,10,40))
    def test_grayscale(self):
        x=tex(6,dimensions=(1,1),pixels=bytes([110]))
        self.assertEqual(decode(x).getpixel((0,0)),(110,110,110,255))
    def test_rgb565(self):
        x=tex(5,dimensions=(1,1),pixels=struct.pack('<H',0x07e0))
        self.assertEqual(decode(x).getpixel((0,0)),(0,255,0,255))
    def test_jpeg_default_planes(self):
        # No entropy data needed when all channels have constant defaults.
        x=tex(0,dimensions=(8,8),jpg=1,kind=1,channels=[(50,1,255),(50,1,8),(50,1,16),(50,1,64)])
        x=bytearray(x);struct.pack_into('<I',x,52,1)
        im=decode(bytes(x));self.assertEqual(im.size,(8,8));self.assertEqual(im.getpixel((0,0)),(64,8,16,255))
    def test_dxt3_and_dxt5(self):
        dxt3=tex(14,pixels=b'\xff'*8+struct.pack('<HHI',0xf800,0x07e0,0))
        dxt5=tex(15,pixels=b'\xff\x00'+b'\x00'*6+struct.pack('<HHI',0xf800,0x07e0,0))
        for item in (dxt3,dxt5):
            self.assertEqual(decode(item).getpixel((0,0)),(255,0,0,255))
    def test_jpeg_nonconstant_plane(self):
        from PIL import Image
        from io import BytesIO
        # A single standard JPEG 8x8 entropy block fits WildStar TYPE2 plane 0.
        source=BytesIO()
        Image.new('L',(8,8),55).save(source,'JPEG',quality=50)
        raw=source.getvalue();p=raw.index(b'\xff\xda')
        start=p+2+struct.unpack_from('>H',raw,p+2)[0]
        entropy=raw[start:-2].replace(b'\xff\x00',b'\xff')
        x=bytearray(tex(0,dimensions=(8,8),jpg=1,kind=1,
            channels=[(50,0,0),(50,1,22),(50,1,44),(50,1,66)]))
        struct.pack_into('<I',x,52,1);struct.pack_into('<I',x,56,len(entropy));x.extend(entropy)
        im=decode(bytes(x))
        self.assertEqual(im.size,(8,8))
        self.assertLess(abs(im.getpixel((0,0))[3]-55),3)
    def test_bad_tex(self):
        with self.assertRaises(TexError):decode(b'wrong')
        with self.assertRaises(TexError):decode(tex(13,pixels=b'x'))

class MaterialAssetsTests(unittest.TestCase):
    def test_root_and_traversal(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td)/'ClientData';sub=root/'Art'/'Creature';sub.mkdir(parents=True)
            (sub/'Demo_Color.tex').write_bytes(tex(13,pixels=struct.pack('<HHI',0xf800,0x07e0,0)))
            source=sub/'advanced.m3'
            self.assertEqual(clientdata_root(source),root)
            self.assertEqual(texture_path(root,r'art\creature\demo_color.TEX'),sub/'Demo_Color.tex')
            self.assertIsNone(texture_path(root,r'..\secrets.txt'))
            self.assertIsNone(texture_path(root,r'C:\temp\demo.tex'))
            parsed=read_m3_native(enriched(),'advanced.m3')
            class Server:pass
            server=Server()
            returned=attach_materials(server,parsed,source)
            self.assertTrue(returned['textureRootReady'])
            self.assertEqual(returned['textureCountReady'],1)
            self.assertEqual(returned['textureAssets'][0]['status'],'ready')
            self.assertEqual(returned['textureAssets'][0]['id'],0)
            img=decode_png(server.asset_paths[0].read_bytes())
            self.assertTrue(img.startswith(b'\x89PNG'))
    def test_blend_state(self):
        h=bytearray(32);struct.pack_into('<I',h,20,1)
        self.assertEqual(color_state({'headerHex':h.hex()}),1)

if __name__=='__main__':unittest.main()
