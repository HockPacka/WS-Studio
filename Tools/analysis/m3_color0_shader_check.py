"""Validate the M3-only COLOR0 patch against the real WoW vs_3_0 permutations.

The token transformation mirrors WildStarModelShader::VertexWithColor0. Every
patched shader is also parsed by the system D3D disassembler.
"""
import json
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tools/analysis'))
from ws_content_output import ClientArchive
from dxbc_dis import disassemble

OUT = ROOT / 'build_m3test/scratch/sky_animation_dark_m3/color0_shaders'


def reg_type(token):
    return ((token >> 28) & 7) | ((token >> 8) & 0x18)


def reg(kind, number):
    return 0x80000000 | number | ((kind & 7) << 28) | (((kind >> 3) & 3) << 11)


def dst(kind, number, mask):
    return reg(kind, number) | (mask << 16)


def src(kind, number):
    return reg(kind, number) | 0x00E40000


def patch(blob):
    words = list(struct.unpack('<%dI' % (len(blob) // 4), blob))
    assert words[0] == 0xFFFE0300
    used_temp = set()
    input6 = False
    color_out = None
    end = None
    i = 1
    while i < len(words):
        token = words[i]
        if token == 0x0000FFFF:
            end = i
            break
        op = token & 0xFFFF
        if op == 0xFFFE:
            step = 1 + ((token >> 16) & 0x7FFF)
            assert step <= len(words) - i
            i += step
            continue
        length = (token >> 24) & 0xF
        assert length + 1 <= len(words) - i
        if op == 0x1F:
            assert length >= 2
            usage = words[i + 1] & 0x1F
            index = (words[i + 1] >> 16) & 0xF
            target = words[i + 2]
            if reg_type(target) == 6 and usage == 10 and index == 0:
                assert color_out is None
                color_out = target & 0x7FF
        for value in words[i + 1:i + 1 + length]:
            if not value & 0x80000000:
                continue
            kind, number = reg_type(value), value & 0x7FF
            if kind == 0 and number < 32:
                used_temp.add(number)
            if kind == 1 and number == 6:
                input6 = True
        i += 1 + length
    assert end is not None and color_out is not None and not input6
    temp = next(i for i in range(32) if i not in used_temp)
    header_end = 1
    while header_end < end:
        op = words[header_end] & 0xFFFF
        if op == 0xFFFE:
            header_end += 1 + ((words[header_end] >> 16) & 0x7FFF)
        elif op == 0x1F:
            header_end += 1 + ((words[header_end] >> 24) & 0xF)
        else:
            break
    writes = 0
    i = header_end
    while i < end:
        token = words[i]
        op = token & 0xFFFF
        if op == 0xFFFE:
            i += 1 + ((token >> 16) & 0x7FFF)
            continue
        length = (token >> 24) & 0xF
        if op != 0x1F and length and reg_type(words[i + 1]) == 6 and words[i + 1] & 0x7FF == color_out:
            words[i + 1] = (words[i + 1] & ~((7 << 28) | (3 << 11) | 0x7FF)) | temp
            writes += 1
        i += 1 + length
    assert writes
    result = words[:header_end] + [0x0200001F, 10, reg(1, 6) | 0x000F0000] + words[header_end:end]
    result += [0x03000005, dst(0, temp, 7), src(0, temp), src(1, 6)]
    result += [0x03000002, dst(6, color_out, 7), src(0, temp), src(0, temp)]
    result += [0x02000001, dst(6, color_out, 8), src(0, temp), 0x0000FFFF]
    return struct.pack('<%dI' % len(result), *result), temp, color_out, writes


def permutations(data, wanted):
    at = 12
    index = 0
    while at < len(data):
        size = struct.unpack_from('<I', data, at + 12)[0]
        if index in wanted:
            yield index, data[at + 16:at + 16 + size]
        at += 16 + ((size + 3) & ~3)
        index += 1


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    archive = ClientArchive(ROOT / 'WoWClient/Data')
    report = []
    for name in ('Diffuse_T1', 'Diffuse_T1_T2'):
        data = archive.get(f'Shaders\\Vertex\\vs_3_0\\{name}.bls')
        for permutation, original in permutations(data, {30, 40, 50}):
            patched, temp, color_out, writes = patch(original)
            text = disassemble(patched).rstrip('\x00')
            stem = f'{name}_{permutation}'
            (OUT / f'{stem}_original.bin').write_bytes(original)
            (OUT / f'{stem}_color0.bin').write_bytes(patched)
            (OUT / f'{stem}_color0.txt').write_text(text, encoding='utf-8')
            assert 'dcl_color v6' in text, stem
            assert f'mul r{temp}.xyz, r{temp}, v6' in text, stem
            assert f'add o{color_out}.xyz, r{temp}, r{temp}' in text, stem
            assert f'mov o{color_out}.w, r{temp}' in text, stem
            report.append(dict(shader=stem, originalBytes=len(original), patchedBytes=len(patched),
                               temp=temp, colorOutput=color_out, redirectedWrites=writes))
    (OUT / 'validation.json').write_text(json.dumps(report, indent=2), encoding='utf-8')
    print(f'PASS COLOR0 RGB*2 with original alpha on {len(report)} real WoW vertex shaders; D3D disassembly accepted every patch')


if __name__ == '__main__':
    main()
