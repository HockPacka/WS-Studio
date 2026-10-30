"""M3 v0.5 editor integration regression (no original commercial assets)."""
import json
from pathlib import Path
import shutil
import subprocess
import unittest
from native_m3 import read_m3_native

ROOT=Path(__file__).resolve().parents[1]


class EditorIntegration(unittest.TestCase):
    def test_explorer_asset_packaged(self):
        from server import BASE
        self.assertTrue((BASE/'m3_explorer.js').is_file())
        source=(BASE/'index.html').read_text(encoding='utf-8')
        self.assertIn('/m3_explorer.js', source)
        self.assertIn('id="m3DataList"', source)
        spec=(BASE/'WildStarModelStudio.spec').read_text(encoding='utf-8')
        self.assertIn('m3_explorer.js',spec)

    def test_full_parser_schema_from_demo(self):
        model=read_m3_native((ROOT/'demo/Crystal.m3').read_bytes(),'Crystal.m3')
        self.assertEqual(model['format'],'M3')
        self.assertTrue(model['sections'])
        for key in ['bones','materialData','clips','textures','attachments','cameras','lights',
                    'emitters','collision','geometryInventory','auxiliaryTables','rawHeader']:
            self.assertIn(key,model['m3Details'])

    @unittest.skipUnless(shutil.which('node'),'Node.js not installed')
    def test_m3_js_explorer(self):
        result=subprocess.run(['node',str(ROOT/'tests/test_editor_m3.js')],cwd=ROOT,
                              capture_output=True,text=True,timeout=10)
        self.assertEqual(result.returncode,0,result.stderr)
        self.assertIn('assertions OK',result.stdout)
