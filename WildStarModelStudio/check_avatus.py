"""Validate an extracted WildStar Avatus pack with the actual native M3 parser.

Usage: python check_avatus.py "D:\\WS-Tools\\Avatus" [--json report.json]
       python check_avatus.py "D:\\WS-Tools\\Avatus\\Avatus.m3" [--json report.json]
No originals are modified. Never claim successful parsing for untested files.
"""
from __future__ import annotations
import argparse
import json
from pathlib import Path
import sys
import traceback

from native_m3 import read_m3_native, parser_status
from material_service import pack_texture_path, clientdata_root, texture_path
from tex_decoder import header, decode, TexError

KNOWN_PARTS = ['Avatus.m3', 'Avatus_Gun.m3', 'Avatus_HandLf.m3', 'Avatus_HandRt.m3']


def check_pack(target: Path, decode_textures: bool = True) -> dict:
    """Check an Avatus folder *or* a single dragged .m3 file.

    Passing a file checks that file; passing a directory checks the four
    official Avatus parts (and makes missing components visible in the report).
    The input is never modified.
    """
    target = Path(target).expanduser().resolve()
    if target.is_file():
        if target.suffix.casefold() != '.m3':
            raise ValueError(f'Bitte eine .m3-Datei oder den Avatus-Ordner auswählen: {target}')
        folder = target.parent
        names = [target.name]
        mode = 'single_m3'
    elif target.is_dir():
        folder = target
        names = KNOWN_PARTS
        mode = 'avatus_pack'
    else:
        raise FileNotFoundError(f'Pfad existiert nicht: {target}\n'
                                'Bitte den Avatus-Ordner oder eine vorhandene .m3-Datei übergeben.')
    info = {'inputPath': str(target), 'mode': mode, 'folder': str(folder),
            'parser': parser_status(), 'parts': [], 'textures': [], 'summary': {}}
    paths = {}
    for name in names:
        part_path = folder / name
        row = {'name': name, 'found': part_path.is_file(), 'readable': False,
               'meshCount': 0, 'rawMeshCount': 0, 'rawVertexCount': 0, 'rawIndexCount': 0, 'bones': 0, 'clips': 0, 'materials': 0, 'textureRefs': 0,
               'missingTextureRefs': [], 'errors': []}
        if part_path.is_file():
            try:
                parsed = read_m3_native(part_path.read_bytes(), name)
                row.update(readable=True, meshCount=parsed['stats']['meshes'],
                           bones=parsed['stats']['bones'], clips=parsed['stats']['animations'],
                           materials=parsed['stats']['materials'])
                raw_geos = parsed.get('m3Details', {}).get('geometryInventory', [])
                row['rawMeshCount'] = sum(g.get('meshCount', 0) for g in raw_geos)
                row['rawVertexCount'] = sum(g.get('vertexCount', 0) for g in raw_geos)
                row['rawIndexCount'] = sum(g.get('indexCount', 0) for g in raw_geos)
                tex = parsed.get('m3Details', {}).get('textures', [])
                row['textureRefs'] = len(tex)
                for ref in tex:
                    virtual = ref.get('path') or ''
                    path = (texture_path(clientdata_root(part_path), virtual)
                            if clientdata_root(part_path) else None)
                    path = path or pack_texture_path(part_path, virtual)
                    if path:
                        paths[path.name.casefold()] = path
                    elif virtual:
                        row['missingTextureRefs'].append(virtual)
                if not row['meshCount'] and row['rawMeshCount'] > 0:
                    row['errors'].append(
                        f'M3-Geometrie erkannt ({row["rawMeshCount"]} Roh-Meshes, '
                        f'{row["rawIndexCount"]} Indizes), aber der Renderer erhielt 0 Meshes. '
                        'Bitte aktuelle DLL verwenden und Indexbuffer prüfen.')
                elif not row['meshCount']:
                    row['errors'].append('Dieses Modell enthält laut Geometrieinventar keine Meshes.')
            except Exception as exc:
                row['errors'].append(f'M3-Parser: {exc}')
        else:
            row['errors'].append('Datei nicht vorhanden')
        info['parts'].append(row)

    # Independently inspect all TEX files, not only those currently referenced.
    texture_dir = folder / 'Textures'
    for path in sorted(texture_dir.glob('*')) if texture_dir.is_dir() else []:
        if path.suffix.casefold() != '.tex':
            continue
        row = {'name': path.name, 'headerValid': False, 'decoded': False, 'error': None}
        try:
            data = path.read_bytes()
            hdr = header(data)
            row.update(headerValid=True, width=hdr['w'], height=hdr['h'],
                       fmt=hdr['fmt'], jpg=bool(hdr['jpg']), jpgType=hdr['kind'])
            if decode_textures:
                img = decode(data, max_size=256)
                row['decoded'] = True
                row['previewSize'] = list(img.size)
        except (OSError, TexError, ValueError, IndexError, MemoryError) as exc:
            row['error'] = str(exc)
        info['textures'].append(row)
    info['summary'] = {
        'partsReadable': sum(x['readable'] for x in info['parts']),
        'partsWithRenderedMeshes': sum(x['meshCount'] > 0 for x in info['parts']),
        'partsWithLostGeometry': sum(x['readable'] and x['rawMeshCount'] > 0 and x['meshCount'] == 0 for x in info['parts']),
        'partsTotal': len(info['parts']),
        'textureHeadersOK': sum(x['headerValid'] for x in info['textures']),
        'textureDecoded': sum(x['decoded'] for x in info['textures']),
        'textureTotal': len(info['textures']),
        'missingTextureRefs': sum(len(x['missingTextureRefs']) for x in info['parts']),
    }
    return info


def main() -> int:
    parser = argparse.ArgumentParser(description='Avatus M3 + TEX Diagnose')
    parser.add_argument('folder', type=Path, help='Pfad zum Avatus-Ordner ODER zu einer einzelnen .m3-Datei')
    parser.add_argument('--json', type=Path, help='Bericht als JSON speichern')
    parser.add_argument('--headers-only', action='store_true', help='TEX nicht vollständig dekodieren')
    args = parser.parse_args()
    try:
        report = check_pack(args.folder, not args.headers_only)
    except (FileNotFoundError, NotADirectoryError, ValueError, OSError) as exc:
        print(f'FEHLER: {exc}', file=sys.stderr)
        return 2
    print('AVATUS PACK – ECHTE DATEIEN PRÜFEN')
    print('Parser:',report['parser'])
    for p in report['parts']:
        mark='OK' if p['readable'] else 'FEHLER'
        print(f' [{mark}] {p["name"]}: {p["meshCount"]} Meshes ({p["rawMeshCount"]} Roh-Meshes) / {p["bones"]} Bones / {p["clips"]} Clips / {p["materials"]} Materialien / {p["textureRefs"]} TEX-Referenzen')
        for e in p['errors']: print('   !',e)
        for e in p['missingTextureRefs']: print('   ! TEX fehlt:',e)
    for tex in report['textures']:
        label='OK' if (tex['decoded'] or args.headers_only and tex['headerValid']) else 'FEHLER'
        print(f' [{label}] {tex["name"]} – {tex.get("width","?")}x{tex.get("height","?")}: {tex.get("error") or ""}')
    print('GESAMT:',report['summary'])
    if args.json:
        try:
            args.json.write_text(json.dumps(report,ensure_ascii=False,indent=2),encoding='utf-8')
        except OSError as exc:
            print(f'FEHLER: Bericht konnte nicht gespeichert werden: {exc}', file=sys.stderr)
            return 2
        print('JSON geschrieben:',args.json)
    return 0 if all(p['readable'] and not p['missingTextureRefs'] and (p['meshCount'] > 0 or p['rawMeshCount'] == 0) for p in report['parts']) and all(
        t['headerValid'] and (t['decoded'] or args.headers_only) for t in report['textures']) else 1


if __name__ == '__main__':
    sys.exit(main())
