"""Tests the packaged app entrypoint without requiring a GUI in CI."""
import importlib
import json
from pathlib import Path
import sys
import unittest
from unittest.mock import patch
from urllib.request import urlopen

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))


class FakeWebView:
    def __init__(self):
        self.address = None
        self.options = None
        self.started = False

    def create_file_dialog(self, **kw):
        self.file_dialog_called = True
        return (str(ROOT / 'demo' / 'Crystal.m3'),)

    def create_window(self, title, uri, **kw):
        self.address = uri
        self.options = kw
        self.title = title
        return self

    def start(self, **kw):
        self.started = True
        with urlopen(self.address) as response:
            assert b'WILDSTAR' in response.read()
        with urlopen(self.address.split('?')[0].rstrip('/') + '/api/demo') as response:
            parsed = json.load(response)
        assert parsed['format'] == 'M3', parsed
        # Native dialog requires a POST, same as the real in-window UI.
        from urllib.request import Request
        req = Request(self.address.split('?')[0].rstrip('/') + '/api/browse', data=b'', headers={'X-Viewer-Request':'1'},method='POST')
        with urlopen(req) as response:
            picked = json.load(response)
        assert picked['format'] == 'M3'
        assert self.file_dialog_called
        if '?startup=1' in self.address:
            with urlopen(self.address.split('?')[0].rstrip('/') + '/api/startup') as response:
                model = json.load(response)
            assert model['format'] == 'M3'
            with urlopen(self.address.split('?')[0].rstrip('/') + '/api/startup') as response:
                assert json.load(response)['cancelled'] is True


class DesktopTests(unittest.TestCase):
    def test_native_desktop_lifecycle(self):
        fake = FakeWebView()
        with patch.dict(sys.modules, {'webview': fake}), patch.object(sys, 'argv', ['desktop.py', str(ROOT / 'demo' / 'Crystal.m3')]):
            import desktop
            self.assertEqual(desktop.main(), 0)
        self.assertTrue(fake.started)
        self.assertIn('WildStar Model Studio', fake.title)
        self.assertIn('startup=1', fake.address)


if __name__ == '__main__':
    unittest.main()
