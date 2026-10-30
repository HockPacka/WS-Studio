"""M3 ABI2 regression using a synthetic LDOM tree with nested material/bone pointers.
No game assets required. Real model validation remains a separate task.
"""
import base64
import struct
import sys
import unittest
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT))
from native_m3 import read_m3_native
from readers import FormatError


def aligned(buf):
    buf.extend(b'\0'*((-len(buf))%16))


def enriched():
    b=bytearray((ROOT/'demo/Crystal.m3').read_bytes())
    geo=0x630
    # Replace the original 14-byte position/normal vertex stream by 18-byte
    # position/normal/UV stream, keeping all original mesh and index pointers.
    geo_base=(0x630+0xc8+15)&~15
    n=struct.unpack_from('<I',b,geo+0x18)[0]
    old=geo_base+struct.unpack_from('<Q',b,geo+0x40)[0]
    original=bytes(b[old:old+n*14]);aligned(b)
    struct.pack_into('<H',b,geo+0x1c,18)
    b[geo+0x20+8]=5
    struct.pack_into('<QQ',b,geo+0x38,n*18,len(b)-geo_base)
    for i in range(n):
        b.extend(original[i*14:(i+1)*14]);b.extend(struct.pack('<2e',i/100,1-i/100))

    # Bone palette (one global bone), bone transform + keyed rotation/translation.
    aligned(b);bone_map=len(b);struct.pack_into('<QQ',b,0x1b0,1,bone_map-0x630);b.extend(struct.pack('<H',0))
    aligned(b);bone_start=len(b);struct.pack_into('<QQ',b,0x180,1,bone_start-0x630)
    bone=bytearray(0x160)
    struct.pack_into('<h',bone,4,-1)
    struct.pack_into('<H',bone,0,27)
    for off in [0xd0,0x110]:struct.pack_into('<16f',bone,off,*(1 if i%5==0 else 0 for i in range(16)))
    b.extend(bone);aligned(b);base=len(b)
    # translation track 6: one key at 1,500 ms, float3
    k_off=len(b)-base;b.extend(struct.pack('<I',1500));aligned(b)
    v_off=len(b)-base;b.extend(struct.pack('<3f',2.5,-3.25,7.75))
    struct.pack_into('<QQQ',b,bone_start+0x10+6*24,1,k_off,v_off)
    # rotation track 4: two quaternions, int16 / 16384
    aligned(b);rot_k=len(b)-base;b.extend(struct.pack('<II',0,1500));aligned(b)
    rot_v=len(b)-base;b.extend(struct.pack('<8h',0,0,0,16384,0,8192,0,14189))
    struct.pack_into('<QQQ',b,bone_start+0x10+4*24,2,rot_k,rot_v)

    # One animation clip.
    aligned(b);at=len(b);struct.pack_into('<QQ',b,0x10,1,at-0x630)
    clip=bytearray(0x70);struct.pack_into('<6H2If',clip,0,152,1,0,0,100,200,0,1500,1.0)
    b.extend(clip)

    # One texture path.
    aligned(b);at=len(b);struct.pack_into('<QQ',b,0x1c0,1,at-0x630)
    tex=bytearray(0x20);struct.pack_into('<H',tex,0,0xffff)
    tex[2]=0
    b.extend(tex);aligned(b);nb=len(b);path='Art\\Creature\\Demo_Color.tex'
    struct.pack_into('<QQ',b,at+16,len(path),len(b)-nb);b.extend(path.encode('utf-16le'))

    # One material, one layer and a gloss track.
    aligned(b);at=len(b);struct.pack_into('<QQ',b,0x1f0,1,at-0x630)
    mat=bytearray(0x30);struct.pack_into('<QQ',mat,0x20,1,0);b.extend(mat)
    aligned(b);db=len(b);desc=bytearray(0x128)
    struct.pack_into('<HH',desc,0,0,0xffff)
    struct.pack_into('<II',desc,0x120,4,7)
    b.extend(desc);aligned(b);nested=len(b)
    struct.pack_into('<QQQ',b,db+0x30,1,0,16)
    b.extend(struct.pack('<I',0));b.extend(b'\0'*12);b.extend(struct.pack('<f',.75))
    # attachment + camera + light + ribbon/particle record metadata
    aligned(b);at=len(b);struct.pack_into('<QQ',b,0x280,1,at-0x630);b.extend(struct.pack('<4H',0,0,91,0))
    aligned(b);at=len(b);struct.pack_into('<QQ',b,0x328,1,at-0x630);cam=bytearray(0x38);struct.pack_into('<2H',cam,0,2,0);b.extend(cam)
    aligned(b);at=len(b);struct.pack_into('<QQ',b,0x318,1,at-0x630);lit=bytearray(0x190);struct.pack_into('<2H',lit,0,1,0);b.extend(lit)
    aligned(b);at=len(b);struct.pack_into('<QQ',b,0x2f8,1,at-0x630);em=bytearray(0xa0);struct.pack_into('<HI',em,0,0,0);b.extend(em)
    return bytes(b)


class ExtendedParserTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):cls.obj=read_m3_native(enriched(),'advanced.m3')
    def test_uvs(self):
        s=self.obj['sections'][0]
        uv=struct.unpack('<%df'%(len(base64.b64decode(s['uv1']))//4),base64.b64decode(s['uv1']))
        self.assertAlmostEqual(uv[0],0,places=3)
        self.assertAlmostEqual(uv[1],0,places=3)
        self.assertAlmostEqual(uv[2],.01,places=3)
    def test_bones_and_tracks(self):
        d=self.obj['m3Details'];self.assertEqual(d['boneMap'],[0]);self.assertEqual(len(d['bones']),1)
        bone=d['bones'][0]
        self.assertEqual(bone['parent'],-1)
        t=bone['tracks']['translation']
        self.assertEqual(t['count'],1)
        self.assertEqual(struct.unpack('<I',base64.b64decode(t['times'])),(1500,))
        self.assertEqual(struct.unpack('<3f',base64.b64decode(t['values'])),(2.5,-3.25,7.75))
        self.assertEqual(bone['tracks']['rotation']['count'],2)
    def test_materials(self):
        mat=self.obj['m3Details']['materialData'][0]['layers'][0]
        self.assertEqual(mat['colorTexture'],0)
        self.assertEqual(mat['normalTexture'],65535)
        self.assertEqual(mat['materialType'],7)
        self.assertAlmostEqual(struct.unpack('<f',base64.b64decode(mat['parameters']['gloss']['values']))[0],.75)
    def test_extras(self):
        d=self.obj['m3Details']
        self.assertEqual(len(d['attachments']),1)
        self.assertEqual(len(d['cameras']),1)
        self.assertEqual(len(d['lights']),1)
        self.assertEqual(len(d['emitters']),1)
        self.assertIn('Demo_Color.tex',d['textures'][0]['path'])
        self.assertEqual(d['clips'][0]['id'],152)
    def test_reject_unknown_version(self):
        b=bytearray(enriched());struct.pack_into('<I',b,4,999)
        with self.assertRaises(FormatError):read_m3_native(bytes(b),'unsupported.m3')

if __name__=='__main__':unittest.main()

class OtherM3AssetsTests(unittest.TestCase):
    def test_m3_without_visible_geometry_still_yields_metadata(self):
        b=bytearray((ROOT/'demo/Crystal.m3').read_bytes())
        # Delete the mesh list (geometry remains valid, but no visible meshes)
        struct.pack_into('<Q',b,0x630+0x80,0)
        model=read_m3_native(bytes(b),'helper_only.m3')
        self.assertEqual(model['sections'],[])
        self.assertEqual(model['stats']['meshes'],0)
        self.assertEqual(model['m3Details']['geometryInventory'][0]['vertexCount'],30)
    def test_emitter_particle_template(self):
        b=bytearray(enriched())
        # Existing emitter table appended last. Add its 0xED0 template after the
        # descriptors, using native relative pointer semantics.
        count,off=struct.unpack_from('<QQ',b,0x2f8)
        self.assertEqual(count,1)
        at=0x630+off
        aligned(b);base=len(b)
        struct.pack_into('<Q',b,at+0x90,0)
        tpl=bytearray(0xed0)
        struct.pack_into('<H',tpl,0x978,0)
        struct.pack_into('<H',tpl,0x994,0xffff)
        struct.pack_into('<H',tpl,8,3)
        struct.pack_into('<I',tpl,0xe78,4)
        struct.pack_into('<f',tpl,0xe7c,8.0)
        struct.pack_into('<I',tpl,0xe8c,12)
        b.extend(tpl)
        # One spawn count, times are stored relative to end of template.
        struct.pack_into('<I4xQQ',b,base+0x68,1,0,16)
        b.extend(struct.pack('<I',0)+b'\0'*12+struct.pack('<H',5))
        em=read_m3_native(bytes(b),'particle.m3')['m3Details']['emitters'][0]
        self.assertEqual(em['template']['texture0'],0)
        self.assertEqual(em['template']['shape'],3)
        self.assertEqual(em['template']['flipbookCols'],4)
        self.assertEqual(em['template']['properties']['spawnMin'],5)
