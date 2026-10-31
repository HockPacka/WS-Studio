"""Decode Avatus 0x560 records and bind them to native SkinFX texture evidence."""
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[2]
HEADER_END = 0x630
RECORD_SIZE = 0xA0


def align16(value):
    return (value + 15) & ~15


def tracked_values(data, record, nested_base, offset, value_format, value_size):
    count, key_offset, value_offset = struct.unpack_from('<QQQ', data, record + offset)
    if not count:
        return {'count': 0, 'keys': [], 'values': []}
    if count > 65536:
        raise ValueError(f'unreasonable DP count {count} at {record + offset:#x}')
    key_start = nested_base + key_offset
    value_start = nested_base + value_offset
    if key_start + count * 4 > len(data) or value_start + count * value_size > len(data):
        raise ValueError(f'DP outside model at {record + offset:#x}')
    keys = list(struct.unpack_from(f'<{count}I', data, key_start))
    values = [struct.unpack_from(value_format, data, value_start + i * value_size)
              for i in range(count)]
    values = [value[0] if len(value) == 1 else list(value) for value in values]
    return {'count': count, 'keys': keys, 'values': values}


def audit(path):
    data = path.read_bytes()
    if data[:4] != b'LDOM':
        raise ValueError(f'{path}: not LDOM')
    texture_count, texture_offset = struct.unpack_from('<QQ', data, 0x1C0)
    texture_base = HEADER_END + texture_offset
    texture_nested = align16(texture_base + texture_count * 0x20)
    textures = []
    for index in range(texture_count):
        record = texture_base + index * 0x20
        model_texture_id = struct.unpack_from('<H', data, record)[0]
        texture_type = data[record + 2]
        count, offset = struct.unpack_from('<QQ', data, record + 0x10)
        start = texture_nested + offset
        name = data[start:start + count * 2].decode('utf-16le', 'replace').rstrip('\0')
        textures.append({'index': index, 'name': name, 'type': texture_type,
                         'modelTextureId': model_texture_id})

    count, offset = struct.unpack_from('<QQ', data, 0x560)
    record_base = HEADER_END + offset
    if record_base + count * RECORD_SIZE > len(data):
        raise ValueError(f'{path}: 0x560 array outside model')
    nested_base = align16(record_base + count * RECORD_SIZE)
    records = []
    for index in range(count):
        record = record_base + index * RECORD_SIZE
        words = list(struct.unpack_from('<12H', data, record))
        texture_a, texture_b = words[2], words[5]
        records.append({
            'index': index,
            'fileOffset': record,
            'words': words,
            'nativeFields': {
                'textureA_at_0x04': texture_a,
                'effectType_at_0x06': words[3],
                'textureB_at_0x0A': texture_b,
                'material_at_0x0E': words[7],
                'flags_at_0x12': words[9],
                'blendMode_at_0x16': words[11],
            },
            'textureA': textures[texture_a] if texture_a < len(textures) else None,
            'textureB': textures[texture_b] if texture_b < len(textures) else None,
            'tracks': {
                'alphaHalf_at_0x28': tracked_values(data, record, nested_base, 0x28, '<e', 2),
                'flagsU16_at_0x40': tracked_values(data, record, nested_base, 0x40, '<H', 2),
                'color0Float4_at_0x58': tracked_values(data, record, nested_base, 0x58, '<4f', 16),
                'color1Float4_at_0x70': tracked_values(data, record, nested_base, 0x70, '<4f', 16),
                'color2Float4_at_0x88': tracked_values(data, record, nested_base, 0x88, '<4f', 16),
            },
        })
    return {'model': str(path.relative_to(ROOT)), 'textures': textures, 'skinFxRecords': records}


def main():
    folder = ROOT / 'WoWClient/ClientData/Art/Creature/Avatus'
    reports = [audit(folder / name) for name in
               ('Avatus.m3', 'Avatus_Gun.m3', 'Avatus_HandLf.m3', 'Avatus_HandRt.m3')]
    output = ROOT / 'build_m3test/scratch/avatus_skinfx_sho/avatus_skinfx_records.json'
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(reports, indent=2), encoding='utf-8')
    for report in reports:
        print(Path(report['model']).name, '0x560 records', len(report['skinFxRecords']))
        for record in report['skinFxRecords']:
            fields = record['nativeFields']
            print(' ', record['index'], fields,
                  'A=', record['textureA'], 'B=', record['textureB'])
            for name, track in record['tracks'].items():
                if track['count']:
                    print('   ', name, 'keys', track['keys'][:8], 'values', track['values'][:8])
    print('report', output)


if __name__ == '__main__':
    main()
