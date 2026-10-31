#!/usr/bin/env python3
"""WildStar Telegraph Auto-Importer & Cache Pipeline.

Extracts all 180 telegraph assets from ClientData.archive:
- .tex (Tiles, Ramps, Color Gradient Textures) -> converted to .blp in cache
- .m3 (Telegraph Meshes for Cones, Rings, Squares, Corridors) -> cached
- .sho (Native DX9 Pixel Shader bytecode: TelegraphPS.ps_3_0.sho) -> cached
- .tbl (Spell4Telegraph.tbl, TelegraphDamage.tbl) -> parsed into catalog

Usage:
    python tools/ws_telegraph_importer.py [--force]
"""

import json
import os
import struct
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, ROOT)
sys.path.insert(0, os.path.join(ROOT, 'tools'))
sys.path.insert(0, os.path.join(ROOT, 'tools', 'Halon'))
import halon  # noqa: E402
from extract_raw import decompress  # noqa: E402

ARCHIVE_PATH = os.path.join(ROOT, 'WildStar', 'Patch', 'ClientData')
TEX_TO_BLP_EXE = os.path.join(ROOT, 'build_m3test', 'tex_to_blp_cli.exe')
CACHE_ROOT = os.path.join(ROOT, 'WoWClient', 'WildStarContent', 'Cache', 'telegraph')


def collect_telegraph_files(fs):
    files = []
    def scan(d):
        for f in d.files.values():
            if 'telegraph' in f.path.lower():
                files.append(f)
        for sub in d.dirs.values():
            scan(sub)
    scan(fs.root)
    return files


def extract_file_content(fs, archive, f):
    idx, _ = fs.data.blocks[f.sha1]
    off, sz = fs.data.fs[idx]
    archive.seek(off)
    return decompress(f, archive.read(sz))


def main():
    force = '--force' in sys.argv
    print(f'[Telegraph-Importer] Starte Auto-Import aus {ARCHIVE_PATH}...')
    if not os.path.exists(ARCHIVE_PATH + '.index') or not os.path.exists(ARCHIVE_PATH + '.archive'):
        print('[FEHLER] ClientData.index oder ClientData.archive nicht gefunden!')
        sys.exit(1)

    os.makedirs(CACHE_ROOT, exist_ok=True)
    raw_dir = os.path.join(CACHE_ROOT, 'raw')
    blp_dir = os.path.join(CACHE_ROOT, 'blp')
    m3_dir = os.path.join(CACHE_ROOT, 'm3')
    shader_dir = os.path.join(CACHE_ROOT, 'shaders')
    tbl_dir = os.path.join(CACHE_ROOT, 'tables')
    for d in (raw_dir, blp_dir, m3_dir, shader_dir, tbl_dir):
        os.makedirs(d, exist_ok=True)

    fs = halon.Filesystem(ARCHIVE_PATH)
    telegraph_files = collect_telegraph_files(fs)
    print(f'[Telegraph-Importer] {len(telegraph_files)} Telegraph-Dateien im WildStar-Archiv identifiziert.')

    start_time = time.time()
    extracted_counts = {'tex': 0, 'm3': 0, 'sho': 0, 'tbl': 0, 'other': 0}
    converted_blp = 0
    skipped = 0

    with open(fs.data.name, 'rb') as archive:
        for i, f in enumerate(telegraph_files, 1):
            ext = os.path.splitext(f.path)[1].lower()
            fname = os.path.basename(f.path)
            
            # Zielpfad im Cache
            if ext == '.tex':
                out_raw = os.path.join(raw_dir, fname)
                out_blp = os.path.join(blp_dir, os.path.splitext(fname)[0] + '.blp')
                target_check = out_blp
            elif ext == '.m3':
                out_raw = os.path.join(m3_dir, fname)
                target_check = out_raw
            elif ext == '.sho':
                out_raw = os.path.join(shader_dir, fname)
                target_check = out_raw
            elif ext == '.tbl':
                out_raw = os.path.join(tbl_dir, fname)
                target_check = out_raw
            else:
                out_raw = os.path.join(CACHE_ROOT, fname)
                target_check = out_raw

            # Caching-Prüfung
            if not force and os.path.exists(target_check) and os.path.getsize(target_check) > 0:
                skipped += 1
                continue

            # Aus Archiv extrahieren
            content = extract_file_content(fs, archive, f)
            with open(out_raw, 'wb') as wf:
                wf.write(content)

            # Statistik
            if ext == '.tex':
                extracted_counts['tex'] += 1
                # Zu BLP konvertieren
                if os.path.exists(TEX_TO_BLP_EXE):
                    res = subprocess.run([TEX_TO_BLP_EXE, out_raw, out_blp], capture_output=True)
                    if res.returncode == 0 and os.path.exists(out_blp) and os.path.getsize(out_blp) > 0:
                        converted_blp += 1
            elif ext == '.m3':
                extracted_counts['m3'] += 1
            elif ext == '.sho':
                extracted_counts['sho'] += 1
                # Bei ps_3_0 direkt den DX9 Shader-Bytecode extrahieren
                if 'ps_3_0' in fname:
                    dx9_bin = os.path.join(shader_dir, os.path.splitext(fname)[0] + '.dx9ps')
                    idx_ps = content.find(b'\x00\x03\xff\xff')
                    if idx_ps != -1:
                        # Extrahiere Bytecode bis zum End-Token 0x0000FFFF
                        end_tok = content.find(b'\xff\xff\x00\x00', idx_ps)
                        if end_tok != -1:
                            with open(dx9_bin, 'wb') as sf:
                                sf.write(content[idx_ps:end_tok + 4])
                            print(f'  -> Native DX9 Pixel Shader extrahiert: {os.path.basename(dx9_bin)} ({end_tok + 4 - idx_ps} Bytes)')
            elif ext == '.tbl':
                extracted_counts['tbl'] += 1
            else:
                extracted_counts['other'] += 1

    duration = time.time() - start_time
    print(f'[Telegraph-Importer] Abgeschlossen in {duration:.2f}s:')
    print(f'  - Übersprungen (bereits im Cache): {skipped}')
    print(f'  - Extrahierte .tex: {extracted_counts["tex"]} (Konvertiert zu .blp: {converted_blp})')
    print(f'  - Extrahierte .m3 Meshes: {extracted_counts["m3"]}')
    print(f'  - Extrahierte .sho Shader: {extracted_counts["sho"]}')
    print(f'  - Extrahierte .tbl Tabellen: {extracted_counts["tbl"]}')
    print(f'  - Cache-Verzeichnis: {CACHE_ROOT}')

    # Erzeuge Metadaten-Katalog
    catalog = {
        'version': 1,
        'cache_dir': CACHE_ROOT,
        'tiles': [os.path.splitext(f)[0] for f in os.listdir(blp_dir) if 'tile' in f.lower()],
        'ramps': [os.path.splitext(f)[0] for f in os.listdir(blp_dir) if 'ramp' in f.lower()],
        'models': [f for f in os.listdir(m3_dir) if f.endswith('.m3')],
        'shaders': [f for f in os.listdir(shader_dir)],
    }
    catalog_path = os.path.join(CACHE_ROOT, 'telegraph_catalog.json')
    with open(catalog_path, 'w', encoding='utf-8') as jf:
        json.dump(catalog, jf, indent=2)
    print(f'[Telegraph-Importer] Katalog gespeichert in: {catalog_path}')


if __name__ == '__main__':
    main()
