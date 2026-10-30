# -*- mode: python ; coding: utf-8 -*-
# Native desktop app, includes the Python M3 reader AND all local WebGL UI files.
# Build on Windows: py -m PyInstaller --noconfirm WildStarModelStudio.spec
from pathlib import Path
from PyInstaller.utils.hooks import collect_submodules, collect_data_files, collect_dynamic_libs

base = Path(SPECPATH)
assets = ['index.html', 'style.css', 'app.js', 'm3_explorer.js', 'material_renderer.js', 'material_animation.js', 'skeleton_animation.js', 'favicon.svg']
native_dll = base / 'native' / 'ws_m3_parser.dll'
if not native_dll.exists():
    raise RuntimeError('Native M3 DLL fehlt. Bitte build_windows.bat ausführen.')
assets += [str(p.relative_to(base)) for p in (base / 'demo').rglob('*') if p.is_file()]
data = [(str(base / path), str(Path(path).parent)) for path in assets]
data += collect_data_files('webview')
a = Analysis(
    ['desktop.py'], pathex=[str(base)], binaries=collect_dynamic_libs('webview') + [(str(native_dll), '.')], datas=data,
    hiddenimports=['tkinter', 'tkinter.filedialog'] + collect_submodules('webview'),
    hookspath=[], hooksconfig={}, runtime_hooks=[], excludes=[], noarchive=False,
)
pyz = PYZ(a.pure)
exe = EXE(
    pyz, a.scripts, [], exclude_binaries=True,
    name='WildStarModelStudio', debug=False, bootloader_ignore_signals=False,
    strip=False, upx=False, console=False, icon=str(base / 'app_icon.ico'),
)
coll = COLLECT(exe, a.binaries, a.datas, strip=False, upx=False, name='WildStarModelStudio')
