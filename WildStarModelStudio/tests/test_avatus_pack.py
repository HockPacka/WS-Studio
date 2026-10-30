"""Regressions for the official Avatus folder layout in WS-Tools.

These are synthetic data tests; the original >4MB Avatus.m3 isn't packaged.
"""
from __future__ import annotations
import http.client
import json
from pathlib import Path
import struct
import sys
import tempfile
import threading
import unittest

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT))
from material_service import attach_materials, pack_texture_path
from server import ViewerHandler, ViewerServer
from native_m3 import read_m3_native
from tests.test_native_m3_extended import enriched
from tests.test_material_pipeline import tex


class PackAssetsTests(unittest.TestCase):
    def test_avatus_reference_casefold_and_local_pack(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td)/'WS-Tools';mod=root/'Avatus';textures=mod/'Textures';textures.mkdir(parents=True)
            (mod/'Avatus.m3').write_bytes(enriched())
            image=textures/'avatus_gp03_color.tex'
            image.write_bytes(tex(13,pixels=struct.pack('<HHI',0xf800,0x07e0,0)))
            ref=r'Art\Creature\Avatus\Textures\AVATUS_GP03_COLOR.TEX'
            self.assertEqual(pack_texture_path(mod/'Avatus.m3',ref),image)
            obj=read_m3_native(enriched(),'Avatus.m3')
            obj['m3Details']['textures'][0]['path']=ref
            class S:pass
            server=S();server.texture_root=None
            attach_materials(server,obj,mod/'Avatus.m3')
            self.assertEqual(obj['textureCountReady'],1)
            self.assertEqual(obj['textureAssets'][0]['source'],'Local Asset Pack')
            self.assertTrue(obj['textureAssets'][0]['url'])
    def test_all_local_textures_exposed_in_pack_gallery(self):
        with tempfile.TemporaryDirectory() as td:
            folder=Path(td)/'Avatus';texdir=folder/'Textures';texdir.mkdir(parents=True)
            (folder/'Avatus.m3').write_bytes(enriched())
            for i in range(10):
                (texdir/f'tex_{i}.tex').write_bytes(tex(13,pixels=struct.pack('<HHI',0xf800,0x07e0,0)))
            obj=read_m3_native(enriched(),'Avatus.m3')
            obj['m3Details']['textures'][0]['path']=r'Art\Creature\Avatus\Textures\tex_0.tex'
            class S:pass
            server=S();server.texture_root=None
            attach_materials(server,obj,folder/'Avatus.m3')
            self.assertEqual(len(obj['packExtraTextures']),9)
            self.assertEqual(len(server.asset_paths),10)
            self.assertEqual(obj['textureCountReady'],10)

    def test_pack_path_does_not_accept_parent_or_other_model(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td)/'Avatus';(root/'Textures').mkdir(parents=True)
            (root/'Textures'/'t.tex').write_bytes(b'whatever')
            for ref in [r'Art\Creature\Other\Textures\t.tex',
                        r'Art\Creature\Avatus\Textures\..\t.tex',
                        r'Art\Creature\Avatus\Textures\t.png',
                        r'C:\Windows\System32\t.tex']:
                self.assertIsNone(pack_texture_path(root/'Avatus.m3',ref))
    def test_cannot_escape_pack_with_symlink(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td)/'Avatus';root.mkdir()
            outside=Path(td)/'outside';outside.mkdir();(outside/'t.tex').write_bytes(b'no')
            try:(root/'Textures').symlink_to(outside,target_is_directory=True)
            except OSError:self.skipTest('Symlink privilege unavailable')
            self.assertIsNone(pack_texture_path(root/'Avatus.m3',r'Art\Creature\Avatus\Textures\t.tex'))
    def test_model_parts_and_local_texture_endpoint(self):
        with tempfile.TemporaryDirectory() as td:
            mod=Path(td)/'Avatus';textures=mod/'Textures';textures.mkdir(parents=True)
            for name in ('Avatus.m3','Avatus_Gun.m3','Avatus_HandLf.m3','Avatus_HandRt.m3'):
                (mod/name).write_bytes(enriched())
            (mod/'Different.m3').write_bytes(enriched())
            server=ViewerServer(('127.0.0.1',0),ViewerHandler)
            server.pending_file=mod/'Avatus.m3'
            thread=threading.Thread(target=server.serve_forever,daemon=True);thread.start()
            try:
                client=http.client.HTTPConnection('127.0.0.1',server.server_port,timeout=8)
                client.request('GET','/api/startup');response=client.getresponse()
                self.assertEqual(response.status,200)
                model=json.loads(response.read());self.assertEqual(len(model['modelParts']),4)
                self.assertEqual(model['modelParts'][0]['name'],'Avatus.m3')
                chosen=next(x for x in model['modelParts'] if x['name']=='Avatus_Gun.m3')
                client.request('GET',chosen['url']);response=client.getresponse()
                self.assertEqual(response.status,200)
                switched=json.loads(response.read());self.assertEqual(switched['name'],'Avatus_Gun.m3')
                self.assertEqual(len(switched['modelParts']),4)
                client.request('GET',chosen['url']);response=client.getresponse()
                self.assertEqual(response.status,404);response.read() # Old token revoked
                client.close()
            finally:
                server.shutdown();server.server_close();thread.join(timeout=4)

if __name__=='__main__':unittest.main()
