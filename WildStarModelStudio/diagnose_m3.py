"""Standalone M3 diagnostic, independent of the WebGL viewer."""
from __future__ import annotations
import argparse
import json
from pathlib import Path
import sys
from native_m3 import read_m3_native, parser_status


def main():
    parser = argparse.ArgumentParser(description='WildStar M3 parser diagnostic')
    parser.add_argument('model', type=Path, help='Path to a WildStar .m3 file')
    parser.add_argument('--export-json', type=Path, metavar='FILE', help='Vollständige vom Parser gelesene M3-Daten als JSON speichern')
    args = parser.parse_args()
    model = args.model.expanduser()
    print('Parser:', parser_status())
    try:
        data = model.read_bytes()
        print(f'File: {model} ({len(data):,} bytes)')
        result = read_m3_native(data, model.name)
    except (OSError, ValueError) as exc:
        print(f'FAIL: {exc}', file=sys.stderr)
        return 1
    print('SUCCESS:', result['stats'])
    print('Warnings:', result.get('warnings', []))
    if args.export_json:
        args.export_json.write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding='utf-8')
        print('JSON exportiert:', args.export_json)
    for mesh in result['sections'][:25]:
        print(f"  {mesh['name']}: {mesh['vertices']} vertices, {mesh['triangles']} triangles")
    return 0

if __name__ == '__main__':
    raise SystemExit(main())
