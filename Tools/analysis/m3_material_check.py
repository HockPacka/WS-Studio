"""Validate M3 material/alpha conversion on real props and controlled variants.

Usage: python tools/analysis/m3_material_check.py [output_directory]
Uses the standalone Release m3_to_m2_cli and tex_to_blp_cli tools.
"""
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location('m3', ROOT / 'tools/blender_addon/wildstar_m3/m3.py')
m3 = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m3)


def array(b, off):
    return struct.unpack_from('<II', b, off)


def convert(source, directory, name):
    output = directory / (name + '.m2')
    skin = directory / (name + '.skin')
    subprocess.run([str(ROOT / 'wowdecomp/build/x64/bin/Release/m3_to_m2_cli.exe'),
                    str(source), str(output), str(skin)], check=True, capture_output=True)
    return output.read_bytes(), skin.read_bytes()


def check(b, skin, modes, texture_count):
    count, off = array(b, 0x70)
    actual = [struct.unpack_from('<HH', b, off + i * 4)[1] for i in range(count)]
    assert actual == modes, (actual, modes)
    count, off = array(b, 0x50)
    assert count == texture_count + 1
    for i in range(texture_count):
        _, flags, n, _ = struct.unpack_from('<4I', b, off + i * 16)
        if n: assert flags == 3, (i, flags)
    assert struct.unpack_from('<4I', b, off + texture_count * 16) == (0, 0, 0, 0)
    return actual


def first_alpha(b, skin):
    _, batch = array(skin, 0x24)
    ci = struct.unpack_from('<H', skin, batch + 8)[0]
    assert ci != 0xffff
    _, colors = array(b, 0x48)
    _, keys = array(b, colors + ci * 0x28 + 0x14 + 12)
    _, key = array(b, keys)
    return struct.unpack_from('<H', b, key)[0] / 32767


def main():
    out = Path(sys.argv[1] if len(sys.argv) > 1 else ROOT / 'build_m3test/material_dbg42')
    out.mkdir(parents=True, exist_ok=True)
    natural = ROOT / 'WoWClient/ClientData/Art/Prop/Natural'
    cases = [
        natural / 'Flowers/StarFlower/PRP_Flower_PurpleStarFlower_000.m3',
        natural / 'Bush/WeepingUmbrella/PRP_Bush_WeepingUmbrella_000.m3',
        natural / 'Tree/Withered_Pointy_Pine/PRP_Tree_Withered_PointyPine_000.m3',
        natural / 'Rock/SlantedPointyWhite/PRP_Rock_SlantedPointyLarge_White_000.m3',
        natural / 'Tree/PointyPine/Algeroc/PRP_Tree_AlgerocPointyPine_000.m3',
        natural / 'Bush/WeepingUmbrella/PRP_Bush_WeepingUmbrella_EldanTech_000.m3',
    ]
    # Expected visible batches established from original draw-list selection,
    # including helper envelopes in WeepingUmbrella and Algeroc PointyPine.
    expected_modes = [[1], [1, 1], [0, 1, 1], [0], [0, 1], [1]]
    results, textures = [], set()
    for source, modes in zip(cases, expected_modes):
        model = m3.read_model(source.read_bytes())
        b, skin = convert(source, out, source.stem)
        check(b, skin, modes, len(model.textures))
        for mat in model.material_info:
            index = mat.layers[0].tex_color
            if index != 0xffff:
                textures.add(ROOT / 'WoWClient/ClientData' / model.textures[index][0].replace('\\', '/'))
        results.append(dict(model=str(source.relative_to(ROOT)), modes=modes,
                            uv_range=[[min(v[i] for g in model.geometries for v in g.uv1),
                                       max(v[i] for g in model.geometries for v in g.uv1)] for i in (0, 1)]))

    # Independently patch the raw file to exercise all blend modes and scalar opacity.
    original = cases[0].read_bytes()
    mc, mo = struct.unpack_from('<QQ', original, 0x1f0)
    material = mo + 0x630
    assert mc == 1
    dc, do = struct.unpack_from('<QQ', original, material + 0x20)
    layer = ((material + mc * 0x30 + 15) & ~15) + do
    nbase = (layer + dc * 0x128 + 15) & ~15
    source = out / 'controlled.m3'
    controlled = []
    for mode in range(7):
        data = bytearray(original)
        struct.pack_into('<I', data, material + 0x14, mode)
        source.write_bytes(data)
        b, skin = convert(source, out, 'controlled')
        check(b, skin, [mode], len(m3.read_model(original).textures))
        controlled.append(dict(mode=mode))
    for opacity in (0.0, 0.25, 0.75, 1.0):
        data = bytearray(original)
        struct.pack_into('<I', data, material + 0x14, 0)
        key = len(data)
        data.extend(struct.pack('<If', 0, opacity))
        struct.pack_into('<QQQ', data, layer + 0x60, 1, key - nbase, key + 4 - nbase)
        source.write_bytes(data)
        b, skin = convert(source, out, 'controlled')
        check(b, skin, [2 if opacity < 0.996 else 0], len(m3.read_model(original).textures))
        if opacity < 1: assert abs(first_alpha(b, skin) - opacity) <= 1 / 32767
        controlled.append(dict(opacity=opacity))
    # No color texture must select the dedicated white slot, not another material's atlas.
    data = bytearray(original)
    struct.pack_into('<H', data, layer, 0xffff)
    source.write_bytes(data)
    b, skin = convert(source, out, 'controlled')
    _, combo = array(b, 0x80)
    assert struct.unpack_from('<H', b, combo)[0] == len(m3.read_model(original).textures)

    data = bytearray(original)
    struct.pack_into('<II', data, material + 0x0c, 3, 0)
    struct.pack_into('<I', data, material + 0x14, 2)
    source.write_bytes(data)
    b, skin = convert(source, out, 'controlled')
    _, mats = array(b, 0x70)
    assert struct.unpack_from('<H', b, mats)[0] & 0x18 == 0x18

    # Single-layer tint DPs must not be dropped (the old reader required >= 2 layers).
    data = bytearray(original)
    key = len(data)
    data.extend(struct.pack('<I3f', 0, 0.5, 0.75, 1.0))
    struct.pack_into('<QQQ', data, layer + 0x108, 1, key - nbase, key + 4 - nbase)
    source.write_bytes(data)
    b, skin = convert(source, out, 'controlled')
    _, colors = array(b, 0x48)
    _, keys = array(b, colors + 12)
    _, values = array(b, keys)
    assert struct.unpack_from('<3f', b, values) == (0.5, 0.75, 1.0)

    gc, go = struct.unpack_from('<QQ', original, 0x250)
    ga = go + 0x630
    gb = (ga + gc * 0xc8 + 15) & ~15
    _, mo = struct.unpack_from('<QQ', original, ga + 0x80)
    mesh = gb + mo
    for flags in (0, 2, 8, 10, 0x20a):
        data = bytearray(original)
        struct.pack_into('<I', data, mesh + 0x38, flags)
        source.write_bytes(data)
        process = subprocess.run([str(ROOT / 'wowdecomp/build/x64/bin/Release/m3_to_m2_cli.exe'),
                                  str(source), str(out / 'flags.m2'), str(out / 'flags.skin')], capture_output=True)
        if flags in (10, 0x20a):
            assert process.returncode == 1 and b'model without geometry' in process.stderr
        else:
            assert process.returncode == 0, process.stderr

    paths = out / 'textures.txt'
    paths.write_text('\n'.join(str(p) for p in sorted(textures)))
    subprocess.run([sys.executable, str(ROOT / 'tools/analysis/texture_mip_check.py'),
                    str(ROOT / 'wowdecomp/build/x64/bin/Release/tex_to_blp_cli.exe'),
                    str(paths), str(out / 'texture_mips')], check=True)
    report = dict(real_models=results, controlled_cases=controlled, white_fallback=True,
                  depth_flags=True, single_layer_tint=True, helper_mesh_flags=True)
    (out / 'validation.json').write_text(json.dumps(report, indent=2))
    print('PASS: 6 real models, 7 blend modes, 4 opacity cases, 5 helper flag cases, white fallback, source alpha/mip preservation')


if __name__ == '__main__':
    main()
