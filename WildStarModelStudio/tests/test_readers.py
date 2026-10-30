import sys
from pathlib import Path
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from readers import FormatError, read_model_bytes
from create_demo import create_m3, create_i3, create_fedi, create_area

class ReaderTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        create_m3();create_i3();create_fedi();create_area()

    def test_m3(self):
        p=Path(__file__).resolve().parents[1]/'demo/Crystal.m3'
        m=read_model_bytes(p.read_bytes(),p.name,p)
        self.assertEqual(m['format'],'M3')
        self.assertEqual(m['stats']['meshes'],3)
        self.assertEqual(m['stats']['vertices'],30)
        self.assertEqual(m['stats']['triangles'],48)
        self.assertIn('m3Details', m)
        self.assertIn('clips',m['m3Details'])
        self.assertTrue(m['bounds'][0]<m['bounds'][3])

    def test_i3(self):
        p=Path(__file__).resolve().parents[1]/'demo/Crystal.Sector_Exterior.i3'
        m=read_model_bytes(p.read_bytes(),p.name,p)
        self.assertEqual(m['format'],'I3 / FEDS')
        self.assertEqual(m['stats']['meshes'],1)
        self.assertEqual(m['stats']['triangles'],16)

    def test_fedi(self):
        p=Path(__file__).resolve().parents[1]/'demo/Crystal.i3'
        m=read_model_bytes(p.read_bytes(),p.name,p)
        self.assertEqual(m['format'],'I3 / FEDI')
        self.assertEqual(m['stats']['sectors'],1)
        self.assertEqual(m['stats']['triangles'],16)

    def test_area(self):
        p=Path(__file__).resolve().parents[1]/'demo/Hills.area'
        m=read_model_bytes(p.read_bytes(),p.name,p)
        self.assertEqual(m['format'],'AREA / Terrain')
        self.assertEqual(m['stats']['cells'],256)
        self.assertEqual(m['stats']['vertices'],257*257)
        self.assertEqual(m['stats']['triangles'],256*256*2)

    def test_invalid(self):
        with self.assertRaises(FormatError):read_model_bytes(b'NOT MODEL', 'fail.m3')

    def test_truncated_m3(self):
        p=Path(__file__).resolve().parents[1]/'demo/Crystal.m3'
        with self.assertRaises(FormatError):read_model_bytes(p.read_bytes()[:0x650],p.name)

if __name__=='__main__':unittest.main()
