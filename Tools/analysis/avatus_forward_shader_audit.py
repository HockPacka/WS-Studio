"""Disassemble the exact transparent ModelPS keys selected by native FUN_1403283c0."""
import json
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from sho_reader import read_sho
from dxbc_dis import disassemble

PASS_OFFSETS = (0x9000, 0xA200, 0xB400, 0xC600)


def main():
    source = ROOT / 'build_m3test/scratch/avatus_skinfx_sho/avatus_native_audit.json'
    reports = json.loads(source.read_text(encoding='utf-8'))
    output = ROOT / 'build_m3test/scratch/avatus_skinfx_sho/exact_forward'
    output.mkdir(parents=True, exist_ok=True)
    shader_path = ROOT / 'WoWClient/ClientData/Shaders/ModelPS.ps_4_0.sho'
    shader_data = shader_path.read_bytes()
    container = read_sho(shader_data)
    mapping = container['permutation_to_code']
    base_keys = sorted({mesh['permutation'] for report in reports for mesh in report['meshes']})
    results = []
    for base in base_keys:
        for pass_offset in PASS_OFFSETS:
            key = base + pass_offset
            code_index = mapping[key] if key < len(mapping) else 0xFFFFFFFF
            item = {'base': base, 'passOffset': pass_offset, 'permutation': key,
                    'code': code_index, 'exists': code_index != 0xFFFFFFFF}
            if code_index != 0xFFFFFFFF:
                blob_info = container['code'][code_index]
                blob = shader_data[blob_info['offset']:blob_info['offset'] + blob_info['bytes']]
                text = disassemble(blob).rstrip('\0').replace('\r', '')
                name = f'p{key}_c{code_index}_base{base}_offset{pass_offset}.txt'
                (output / name).write_text(text, encoding='utf-8')
                item.update(file=name,
                            samplers=sorted({int(value) for value in re.findall(r'dcl_sampler s(\d+)', text)}),
                            resources=sorted({int(value) for value in re.findall(r'dcl_resource_texture2d .*?t(\d+)', text)}),
                            effectInstructions=[line.strip() for line in text.splitlines()
                                                if re.search(r'\b[st]1[01]\b|cb1\[2[89]\]', line)])
            results.append(item)
            print(f'base={base:#x} offset={pass_offset:#x} key={key:#x} code={code_index}',
                  item.get('samplers', []))
    (output / 'report.json').write_text(json.dumps(results, indent=2), encoding='utf-8')
    print('report', output / 'report.json')


if __name__ == '__main__':
    main()
