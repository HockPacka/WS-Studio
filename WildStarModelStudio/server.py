"""WildStar Asset Viewer — local-only HTTP backend (Python standard library)."""
from __future__ import annotations

import argparse
import gzip
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import json
from pathlib import Path
import sys
import traceback
import secrets
import struct
from urllib.parse import unquote
import webbrowser

from readers import MAX_FILE, MAX_OTHER_FILE, FormatError, read_model_bytes
from native_m3 import parser_status
from material_service import attach_materials, TEXTURE_LIMIT
from tex_decoder import decode_png, TexError

BASE = Path(__file__).resolve().parent


class ViewerServer(ThreadingHTTPServer):
    daemon_threads = True
    allow_reuse_address = True
    pending_file: Path | None = None
    file_picker = None
    folder_picker = None
    texture_root: Path | None = None
    asset_paths = {}
    asset_cache = {}
    # Reuse JPEG-like TEX decoding across Avatus body/gun/hand switching.
    decoded_file_cache = {}
    asset_token = ""
    latest_model = None
    latest_source = None
    part_token = ""
    part_paths = {}

TYPES = {'.html': 'text/html; charset=utf-8', '.js': 'text/javascript; charset=utf-8',
         '.css': 'text/css; charset=utf-8', '.ico': 'image/x-icon', '.svg': 'image/svg+xml'}


class ViewerHandler(BaseHTTPRequestHandler):
    def log_message(self, fmt, *args):
        sys.stderr.write('[Viewer] ' + fmt % args + '\n')

    def _send(self, data: bytes, status: int = 200, mime: str = 'application/json; charset=utf-8', gzip_ok: bool = False):
        if gzip_ok and 'gzip' in self.headers.get('Accept-Encoding', '') and len(data) > 1024:
            data = gzip.compress(data, compresslevel=3)
            compressed = True
        else:
            compressed = False
        self.send_response(status)
        self.send_header('Content-Type', mime)
        self.send_header('Content-Length', str(len(data)))
        self.send_header('X-Content-Type-Options', 'nosniff')
        self.send_header('Cache-Control', 'no-store')
        if compressed:
            self.send_header('Content-Encoding', 'gzip')
        self.end_headers()
        self.wfile.write(data)

    def _json(self, obj, status=200):
        self._send(json.dumps(obj, ensure_ascii=False, separators=(',', ':')).encode('utf-8'), status, gzip_ok=True)

    def do_GET(self):
        path = self.path.split('?', 1)[0]
        if path.startswith('/api/texture/'):
            try:
                _,_,_,token,index = path.split('/')
                idx=int(index)
                if token!=self.server.asset_token or idx not in self.server.asset_paths:
                    self.send_error(404);return
                cached=self.server.asset_cache.get(idx)
                if cached is None:
                    src=self.server.asset_paths[idx]
                    if src.stat().st_size>TEXTURE_LIMIT:raise TexError('Texture zu groß')
                    stamp=(str(src.resolve()),src.stat().st_mtime_ns,src.stat().st_size)
                    cached=self.server.decoded_file_cache.get(stamp)
                    if cached is None:
                        cached=decode_png(src.read_bytes(),1024)
                        if len(self.server.decoded_file_cache)>=24:
                            self.server.decoded_file_cache.pop(next(iter(self.server.decoded_file_cache)))
                        self.server.decoded_file_cache[stamp]=cached
                    if len(self.server.asset_cache)<48:self.server.asset_cache[idx]=cached
                self._send(cached,200,'image/png')
            except (ValueError,OSError,TexError,OverflowError,MemoryError) as exc:
                self._json({'error':f'TEX: {exc}'},422)
            return
        if path.startswith('/api/model-part/'):
            try:
                _, _, _, token, index = path.split('/')
                idx = int(index)
                selected = self.server.part_paths.get(idx)
                if not secrets.compare_digest(token, self.server.part_token) or selected is None:
                    self._json({'error': 'Modellteil ist nicht freigegeben'}, 404)
                elif not selected.is_file() or selected.stat().st_size > MAX_FILE:
                    self._json({'error': 'Modellteil fehlt oder ist zu groß'}, 422)
                else:
                    self._json(self._open_model(selected.read_bytes(), selected.name, selected))
            except (ValueError, OSError, FormatError) as exc:
                self._json({'error': str(exc)}, 422)
            return
        if path == '/api/status':
            self._json(parser_status())
            return
        if path == '/api/startup':
            try:
                selected = self.server.pending_file
                self.server.pending_file = None  # One-shot: do not expose arbitrary paths after startup.
                if selected is None:
                    self._json({'cancelled': True})
                elif selected.stat().st_size > (MAX_FILE if selected.suffix.lower()=='.m3' else MAX_OTHER_FILE):
                    self._json({'error': 'Datei zu groß'}, 422)
                else:
                    self._json(self._open_model(selected.read_bytes(), selected.name, selected))
            except Exception as e:
                self._json({'error': str(e)}, 422)
            return
        if path == '/api/animated-demo':
            try:
                demo = BASE / 'demo' / 'AnimatedCrystal.m3'
                self._json(self._open_model(demo.read_bytes(), demo.name, demo))
            except Exception as e:
                self._json({'error': str(e)}, 422)
            return
        if path == '/api/demo':
            try:
                demo = BASE / 'demo' / 'Crystal.m3'
                self._json(self._open_model(demo.read_bytes(), demo.name, demo))
            except Exception as e:
                self._json({'error': str(e)}, 422)
            return
        public = {'/': 'index.html', '/index.html': 'index.html', '/app.js': 'app.js', '/m3_explorer.js': 'm3_explorer.js', '/material_renderer.js': 'material_renderer.js', '/material_animation.js': 'material_animation.js', '/skeleton_animation.js': 'skeleton_animation.js', '/style.css': 'style.css', '/favicon.svg': 'favicon.svg'}
        if path not in public:
            self.send_error(404)
            return
        filepath = BASE / public[path]
        data = filepath.read_bytes()
        self._send(data, 200, TYPES[filepath.suffix])

    def _open_model(self,data,name,path=None):
        parsed=read_model_bytes(data,name,path)
        self.server.latest_model=parsed
        self.server.latest_source = path
        parsed = attach_materials(self.server, parsed, path)
        self.server.part_token = secrets.token_hex(16)
        self.server.part_paths = {}
        if path is not None and path.suffix.casefold() == '.m3':
            # No arbitrary path from HTTP can be requested. Only sibling models
            # sharing a creature pack's base name are ever exposed.
            base = path.stem.split('_', 1)[0].casefold()
            try:
                siblings = sorted((p for p in path.parent.iterdir()
                                   if p.is_file() and p.suffix.casefold() == '.m3'
                                   and p.stem.split('_', 1)[0].casefold() == base),
                                  key=lambda p: (p.stem.casefold() != base, p.name.casefold()))[:24]
            except OSError:
                siblings = []
            parts = []
            for i, sibling in enumerate(siblings):
                self.server.part_paths[i] = sibling
                parts.append({'id': i, 'name': sibling.name,
                              'active': sibling.resolve() == path.resolve(),
                              'url': f'/api/model-part/{self.server.part_token}/{i}'})
            parsed['modelParts'] = parts
        else:
            parsed['modelParts'] = []
        return parsed

    def do_POST(self):
        origin = self.headers.get('Origin', '')
        if origin and not (origin.startswith('http://127.0.0.1:') or origin.startswith('http://localhost:')):
            self._json({'error': 'Unzulässige Anfragequelle'}, 403)
            return
        if self.headers.get('X-Viewer-Request') != '1':
            self._json({'error': 'Viewer-Header fehlt'}, 403)
            return
        if self.path == '/api/texture-root':
            try:
                if self.server.folder_picker is not None:
                    chosen=self.server.folder_picker()
                else:
                    import tkinter as tk
                    from tkinter import filedialog
                    window=tk.Tk();window.withdraw();window.attributes('-topmost',True)
                    try:chosen=filedialog.askdirectory(parent=window,title='WildStar ClientData-Ordner auswählen')
                    finally:window.destroy()
                if not chosen:
                    self._json({'cancelled':True});return
                root=Path(chosen).resolve()
                if not root.is_dir():raise ValueError('Ordner existiert nicht')
                self.server.texture_root=root
                model=self.server.latest_model
                if model is not None:
                    self._json(attach_materials(self.server,model,self.server.latest_source))
                else:self._json({'textureRootReady':True,'textureCountReady':0,'textureAssets':[]})
            except Exception as exc:self._json({'error':str(exc)},422)
            return
        if self.path == '/api/browse':
            try:
                # Native GUI dialog for the frozen desktop app. Browser-only
                # development mode falls back to tkinter.
                if self.server.file_picker is not None:
                    selected = self.server.file_picker()
                else:
                    import tkinter as tk
                    from tkinter import filedialog
                    root = tk.Tk()
                    root.withdraw()
                    root.attributes('-topmost', True)
                    try:
                        selected = filedialog.askopenfilename(parent=root, title='WildStar-Modell auswählen',
                                          filetypes=[('WildStar Assets', '*.m3 *.i3 *.area'), ('Alle Dateien', '*.*')])
                    finally:
                        root.destroy()
                if not selected:
                    self._json({'cancelled': True})
                    return
                path = Path(selected)
                if path.stat().st_size > (MAX_FILE if path.suffix.lower()=='.m3' else MAX_OTHER_FILE):
                    raise FormatError('Datei zu groß (M3 max. 512 MiB, I3/AREA max. 128 MiB).')
                result = self._open_model(path.read_bytes(), path.name, path)
                self._json(result)
            except Exception as e:
                self._json({'error': str(e)}, 422)
            return
        if self.path != '/api/open':
            self._json({'error': 'Unbekannte API'}, 404)
            return
        try:
            size = int(self.headers.get('Content-Length', '-1'))
            if size < 0 or size > MAX_FILE:
                raise FormatError('Dateigröße nicht unterstützt (max. 512 MiB).')
            filename = Path(unquote(self.headers.get('X-File-Name', 'model.m3'))).name
            if Path(filename).suffix.lower() not in ('.m3', '.i3', '.area'):
                raise FormatError('Nur .m3, .i3 oder .area sind in dieser Version unterstützt.')
            if size > (MAX_FILE if filename.lower().endswith('.m3') else MAX_OTHER_FILE):
                raise FormatError('Datei zu groß (M3 max. 512 MiB, I3/AREA max. 128 MiB).')
            data = self.rfile.read(size)
            if len(data) != size:
                raise FormatError('Unvollständiger Datei-Upload')
            self._json(self._open_model(data, filename))
        except (ValueError, struct.error, MemoryError) as e:
            self._json({'error': str(e)}, 422)
        except Exception as e:
            traceback.print_exc()
            self._json({'error': f'Lesefehler: {e}'}, 422)



def main():
    parser = argparse.ArgumentParser(description='Lokaler WildStar-M3/I3-Viewer')
    parser.add_argument('--port', type=int, default=0, help='Port (Standard: automatisch)')
    parser.add_argument('--no-browser', action='store_true')
    args = parser.parse_args()
    server = ViewerServer(('127.0.0.1', args.port), ViewerHandler)
    url = f'http://127.0.0.1:{server.server_port}/'
    print(f'\nWildStar Model Viewer\n{url}\nZum Beenden Strg+C drücken.\n', flush=True)
    if not args.no_browser:
        import threading
        threading.Timer(0.5, lambda: webbrowser.open(url)).start()
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print('\nViewer beendet.')
    finally:
        server.server_close()


if __name__ == '__main__':
    main()
