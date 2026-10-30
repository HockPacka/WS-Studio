"""ctypes bridge to the native WildStar M3 parser (DLL on Windows).

All input bytes are owned by Python for the duration of the call. The native
library returns an independent JSON UTF-8 buffer allocated on its own heap;
only ws_m3_free may release that buffer. No Python objects cross the C ABI.
"""
from __future__ import annotations
import ctypes
import json
import os
from pathlib import Path
import sys
from readers import FormatError

class NativeM3Error(FormatError):
    pass

_DLL = None

def find_library() -> Path | None:
    filename = 'ws_m3_parser.dll' if os.name == 'nt' else 'libws_m3_parser.dylib' if sys.platform == 'darwin' else 'libws_m3_parser.so'
    roots = [Path(getattr(sys, '_MEIPASS', Path(__file__).resolve().parent)), Path(__file__).resolve().parent]
    for root in roots:
        for path in (root / filename, root / 'native' / filename):
            if path.is_file():
                return path
    return None

def parser_status() -> dict:
    path = find_library()
    if path is None:
        return {'nativeM3': False, 'library': None, 'abi': 2,
                'error': 'M3-DLL nicht gefunden'}
    try:
        _library()  # A DLL on disk is not necessarily loadable or ABI-compatible.
    except NativeM3Error as exc:
        return {'nativeM3': False, 'library': path.name, 'abi': 2, 'error': str(exc)}
    return {'nativeM3': True, 'library': path.name, 'abi': 2}

def _library():
    global _DLL
    if _DLL is not None:
        return _DLL
    path = find_library()
    if path is None:
        raise NativeM3Error('Native M3-Parser-DLL fehlt. Starte build_windows.bat erneut oder kopiere native/ws_m3_parser.dll in den Programmordner.')
    try:
        lib = ctypes.CDLL(str(path))
        lib.ws_m3_abi_version.argtypes = ()
        lib.ws_m3_abi_version.restype = ctypes.c_uint32
        if lib.ws_m3_abi_version() != 2:
            raise NativeM3Error(f'Falsche M3-DLL-Version: {path.name} (benötigt ABI 2).')
        lib.ws_m3_parse_json.argtypes = (ctypes.c_void_p, ctypes.c_size_t, ctypes.c_char_p,
                                          ctypes.POINTER(ctypes.c_void_p), ctypes.POINTER(ctypes.c_void_p))
        lib.ws_m3_parse_json.restype = ctypes.c_int
        lib.ws_m3_free.argtypes = (ctypes.c_void_p,)
        lib.ws_m3_free.restype = None
        _DLL = lib
        return lib
    except (OSError, AttributeError) as exc:
        raise NativeM3Error(f'M3-Parser-Bibliothek konnte nicht geladen werden ({path}): {exc}') from exc

def read_m3_native(data: bytes, name: str) -> dict:
    lib = _library()
    if len(data) > 512 * 1024 * 1024:
        raise NativeM3Error('M3-Datei überschreitet 512 MiB.')
    buffer = ctypes.create_string_buffer(data)
    out_json = ctypes.c_void_p()
    out_error = ctypes.c_void_p()
    try:
        success = lib.ws_m3_parse_json(buffer, len(data), name.encode('utf-8'),
                                       ctypes.byref(out_json), ctypes.byref(out_error))
        if not success:
            message = ctypes.string_at(out_error).decode('utf-8', 'replace') if out_error.value else 'Unbekannter Parserfehler'
            raise NativeM3Error(f'M3-Parser: {message}')
        if not out_json.value:
            raise NativeM3Error('M3-Parser lieferte keinen Ergebnis-Puffer.')
        payload = ctypes.string_at(out_json)
        obj = json.loads(payload)
        if obj.get('format') != 'M3':
            raise NativeM3Error('Unerwartetes M3-DLL-Ergebnis.')
        return obj
    finally:
        if out_json.value:
            lib.ws_m3_free(out_json)
        if out_error.value:
            lib.ws_m3_free(out_error)
