"""Native desktop entrypoint for WildStar Model Studio.

Displays the locally served WebGL interface INSIDE a native OS window using
WebView2 (Windows) / WebKit (Linux, macOS). No external browser or Internet.
The native C M3 DLL is loaded by ctypes. Python handles I3 and AREA.
The DLL is bundled by PyInstaller and no external web browser is required.
"""
from __future__ import annotations

import argparse
import os
from pathlib import Path
import sys
from threading import Thread
from http.server import ThreadingHTTPServer


def main() -> int:
    parser = argparse.ArgumentParser(description='WildStar Model Studio Desktop')
    parser.add_argument('asset', nargs='?', default='', help='Optional M3/I3/AREA file to open')
    parser.add_argument('--port', type=int, default=0)
    args = parser.parse_args()

    try:
        import webview
    except ImportError:
        print('pywebview fehlt: python -m pip install -r requirements.txt', file=sys.stderr)
        return 2

    # Imported after parsing arguments so --help works without pywebview.
    from server import ViewerHandler, ViewerServer

    host = ViewerServer(('127.0.0.1', args.port), ViewerHandler)
    server_thread = Thread(target=host.serve_forever, name='wildstar-local-server', daemon=True)
    server_thread.start()
    try:
        uri = f'http://127.0.0.1:{host.server_port}/'
        if args.asset:
            initial_path = Path(args.asset).expanduser().resolve()
            if not initial_path.is_file():
                print(f'Datei nicht gefunden: {initial_path}', file=sys.stderr)
                return 2
            # Never expose a filesystem path in the URL or to an external server.
            # The start-up file is read by the local backend only.
            host.pending_file = initial_path
            uri += '?startup=1'
        window = webview.create_window(
            'WildStar Model Studio', uri,
            width=1500, height=930, min_size=(1024, 650),
            background_color='#0b1521', text_select=True,
        )
        def choose_asset():
            files = window.create_file_dialog(
                file_types=('WildStar Assets (*.m3;*.i3;*.area)', 'Alle Dateien (*.*)')
            )
            return files[0] if files else None

        host.file_picker = choose_asset
        def choose_texture_root():
            try:
                selected = window.create_file_dialog(webview.FOLDER_DIALOG)
                return selected[0] if selected else None
            except (AttributeError, TypeError):
                from tkinter import Tk, filedialog
                ui=Tk();ui.withdraw()
                try:return filedialog.askdirectory(title='WildStar ClientData auswählen')
                finally:ui.destroy()
        host.folder_picker = choose_texture_root
        # Embedded native WebView window. There is deliberately no external
        # webbrowser.open() call. The port is an OS-chosen loopback port.
        webview.start(gui='edgechromium' if os.name == 'nt' else None, debug=False)
    finally:
        host.shutdown()
        host.server_close()
        server_thread.join(timeout=3)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
