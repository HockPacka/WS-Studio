import http.client
from pathlib import Path
import struct
import sys
import tempfile
import threading
import unittest

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT))
from server import ViewerHandler,ViewerServer
from tests.test_native_m3_extended import enriched
from tests.test_material_pipeline import tex

class HTTPMaterialTests(unittest.TestCase):
    def test_texture_loaded_from_real_model_location(self):
        with tempfile.TemporaryDirectory() as td:
            folder=Path(td)/'ClientData'/'Art'/'Creature';folder.mkdir(parents=True)
            path=folder/'Advanced.m3';path.write_bytes(enriched())
            (folder/'Demo_Color.tex').write_bytes(tex(13,pixels=struct.pack('<HHI',0xf800,0x07e0,0)))
            server=ViewerServer(('127.0.0.1',0),ViewerHandler)
            server.pending_file=path
            thread=threading.Thread(target=server.serve_forever,daemon=True);thread.start()
            try:
                client=http.client.HTTPConnection('127.0.0.1',server.server_port,timeout=8)
                client.request('GET','/api/startup')
                response=client.getresponse();self.assertEqual(response.status,200)
                import json
                model=json.loads(response.read());asset=model['textureAssets'][0]
                self.assertTrue(asset['url']);self.assertEqual(model['textureCountReady'],1)
                client.request('GET',asset['url'])
                response=client.getresponse();self.assertEqual(response.status,200)
                self.assertEqual(response.getheader('Content-Type'),'image/png')
                self.assertTrue(response.read().startswith(b'\x89PNG'))
                client.request('GET',asset['url'].replace('/0','/4'))
                response=client.getresponse();self.assertEqual(response.status,404);response.read()
                client.close()
            finally:server.shutdown();server.server_close();thread.join(timeout=4)

if __name__=='__main__':unittest.main()
