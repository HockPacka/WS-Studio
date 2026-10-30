"""M3 ABI2 animated material DP descriptors in a real native parser call.
The fixture modifies a synthetic M3, not a game asset.
"""
import base64
import struct
import unittest
from pathlib import Path
import sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from tests.test_native_m3_extended import enriched
from native_m3 import read_m3_native


def align(b):
    b.extend(b'\0' * (-len(b) % 16))


def animated_m3():
    b=bytearray(enriched())
    count, rel=struct.unpack_from('<QQ',b,0x1f0)
    assert count==1
    ma=0x630+rel
    n,off=struct.unpack_from('<QQ',b,ma+0x20)
    assert n==1
    db=(ma+count*0x30+15)&~15
    desc=db+off
    nested=(desc+n*0x128+15)&~15
    def add(off, times, values):
        align(b);keys=len(b)-nested
        b.extend(struct.pack(f'<{len(times)}I',*times))
        align(b);vals=len(b)-nested
        b.extend(struct.pack(f'<{len(values)}f',*values))
        struct.pack_into('<QQQ',b,desc+off,len(times),keys,vals)
    add(0x30,[0,1000,2000],[0.0,0.75,0.0])  # gloss
    add(0x48,[0,1000],[0,2])  # glow
    add(0x60,[0,1000],[0.1,1])  # opacity
    add(0x108,[0,1000],[1,0,0,0,1,0.5])  # RGB tint
    return bytes(b)


class AnimatedMaterialNativeTests(unittest.TestCase):
    def test_multikey_materials_exported_from_native_dll(self):
        model=read_m3_native(animated_m3(),'animated_materials.m3')
        self.assertEqual(model['stats']['meshes'],3)
        p=model['m3Details']['materialData'][0]['layers'][0]['parameters']
        for name, expected in [('gloss',3),('glow',2),('opacity',2),('colorMod',2)]:
            self.assertEqual(p[name]['count'],expected,name)
            times=struct.unpack('<'+('I'*expected),base64.b64decode(p[name]['times']))
            self.assertEqual(times[0],0)
        value=struct.unpack('<3f',base64.b64decode(p['colorMod']['values'])[:12])
        self.assertEqual(value,(1,0,0))
        self.assertEqual(len(base64.b64decode(p['colorMod']['values'])),24)


if __name__=='__main__':unittest.main()
