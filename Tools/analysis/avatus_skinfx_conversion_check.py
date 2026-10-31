"""Validate native Avatus SkinFX records in the actual C++ M3->M2 output."""
import importlib.util
import json
from pathlib import Path
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[2]
CLI = ROOT / 'wowdecomp/build/x64/bin/Release/m3_to_m2_cli.exe'
OUT = ROOT / 'build_m3test/scratch/avatus_skinfx_sho/conversion'
spec = importlib.util.spec_from_file_location('wildstar_m3', ROOT / 'tools/blender_addon/wildstar_m3/m3.py')
m3 = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m3)


def array(data, offset):
    return struct.unpack_from('<II', data, offset)


def sample_scalar(track, time):
    keys, values = track['keys'], track['values']
    if not keys:
        return 1.0
    hi = next((index for index, key in enumerate(keys) if key > time), len(keys))
    lo = max(0, hi - 1)
    hi = min(hi, len(keys) - 1)
    fraction = 0.0 if hi == lo else (time - keys[lo]) / max(1, keys[hi] - keys[lo])
    return max(0.0, min(1.0, values[lo] + (values[hi] - values[lo]) * fraction))


def raw_mesh_skinfx(data, model):
    geometry_count, geometry_offset = struct.unpack_from('<QQ', data, 0x250)
    geometry_offset += m3.HEADER_END
    geometry_base = m3._a16(geometry_offset + geometry_count * 0xC8)
    result = []
    for gi, geometry in enumerate(model.geometries):
        mesh_count, mesh_offset = struct.unpack_from('<QQ', data, geometry_offset + gi * 0xC8 + 0x80)
        mesh_base = geometry_base + mesh_offset
        for mi in range(mesh_count):
            raw = mesh_base + mi * 0x70
            flags = struct.unpack_from('<I', data, raw + 0x38)[0]
            skinfx = struct.unpack_from('<H', data, raw + 0x1C)[0]
            if flags & 0x0A != 0x0A:
                result.append(skinfx)
    return result


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    native_reports = json.loads((OUT.parent / 'avatus_native_audit.json').read_text(encoding='utf-8'))
    fx_reports = json.loads((OUT.parent / 'avatus_skinfx_records.json').read_text(encoding='utf-8'))
    reports = []
    for native, fx_report in zip(native_reports, fx_reports):
        source = ROOT / native['model']
        data = source.read_bytes()
        model = m3.read_model(data)
        expected = raw_mesh_skinfx(data, model)
        target = OUT / (source.stem + '.m2')
        skin_path = target.with_suffix('.skin')
        subprocess.run([str(CLI), str(source), str(target), str(skin_path)], check=True, capture_output=True)
        m2, skin = target.read_bytes(), skin_path.read_bytes()
        batch_count, batches = array(skin, 0x24)
        assert batch_count == len(expected), (source.name, batch_count, len(expected))
        combo_count, combos = array(m2, 0x80)
        weight_count, weights = array(m2, 0x58)
        weight_combo_count, weight_combos = array(m2, 0x90)
        sequence_count, _ = array(m2, 0x1C)
        texture_count, textures = array(m2, 0x50)
        bone_count, _ = array(m2, 0x2C)
        vertex_count, vertices = array(m2, 0x3C)
        particle_count, _ = array(m2, 0x128)
        ribbon_count, _ = array(m2, 0x120)
        assert bone_count == len(model.bones)
        assert sequence_count == len(model.clips)
        # M3Anim exports mapped WoW animations first, retaining source order
        # inside both groups. Keep this list in sync with kAnimMap.
        mapped_ids = {150, 165, 1213, 153, 152, 154, 606, 607, 157, 1472,
                      1283, 429, 164, 155, 1196, 890, 151, 86, 575, 156,
                      166, 167, 159, 163, 161, 162, 710, 472, 884, 885,
                      816, 282, 645, 626, 625, 627, 698, 1214, 1215, 887,
                      475, 692, 693, 1334}
        ordered_clips = ([clip for clip in model.clips if clip.anim_id in mapped_ids] +
                         [clip for clip in model.clips if clip.anim_id not in mapped_ids])
        assert vertex_count == sum(geometry.vertex_count for geometry in model.geometries)
        for vertex in range(vertex_count):
            at = vertices + vertex * 0x30
            assert sum(m2[at + 0x0C:at + 0x10]) == 255
            assert all(index < bone_count for index in m2[at + 0x10:at + 0x14])
        assert combo_count == batch_count * 10
        assert weight_count == len(fx_report['skinFxRecords']) + 1
        assert weight_combo_count == batch_count
        texture_names = []
        for index in range(texture_count):
            length, offset = array(m2, textures + index * 0x10 + 8)
            texture_names.append(m2[offset:offset + length - 1].decode('ascii') if length else '')
        affected = []
        activation = {}
        for batch in range(batch_count):
            at = batches + batch * 0x18
            shader, texture_count_batch, combo = struct.unpack_from('<H10xHH', skin, at + 2)
            weight_combo = struct.unpack_from('<H', skin, at + 0x14)[0]
            fx = expected[batch]
            valid_fx = fx < len(fx_report['skinFxRecords'])
            assert bool(shader & 0x4000) == valid_fx, (source.name, batch, fx, hex(shader))
            assert combo == batch * 10
            assert struct.unpack_from('<H', m2, weight_combos + batch * 2)[0] == (fx + 1 if valid_fx else 0)
            assert weight_combo == batch
            if valid_fx:
                affected.append(batch)
                assert texture_count_batch >= 2
                record = fx_report['skinFxRecords'][fx]
                effect_bone = model.bones[record['words'][0]]
                assert effect_bone.scale is None and effect_bone.parent_scale is None
                slots = struct.unpack_from('<10H', m2, combos + combo * 2)
                for slot, key in ((8, 'textureA'), (9, 'textureB')):
                    expected_texture = record[key]['index']
                    assert slots[slot] == expected_texture, (source.name, batch, slot, slots[slot], expected_texture)
                    expected_name = 'WS\\' + record[key]['name'].rsplit('.', 1)[0] + '.blp'
                    assert texture_names[slots[slot]] == expected_name
                weight = weights + (fx + 1) * 0x14
                count, arrays = array(m2, weight + 12)
                time_count, time_arrays = array(m2, weight + 4)
                assert count == sequence_count and time_count == count
                native_track = record['tracks']['alphaHalf_at_0x28']
                active_sequences = []
                for sequence in range(count):
                    clip = ordered_clips[sequence]
                    key_count, keys = array(m2, arrays + sequence * 8)
                    exported_time_count, times = array(m2, time_arrays + sequence * 8)
                    assert key_count >= 2 and exported_time_count == key_count
                    actual_times = list(struct.unpack_from('<%dI' % key_count, m2, times))
                    values = list(struct.unpack_from('<%dH' % key_count, m2, keys))
                    expected_times = sorted({clip.start, clip.end}.union(
                        time for time in native_track['keys'] if clip.start < time < clip.end))
                    assert actual_times == [time - clip.start for time in expected_times], (
                        source.name, fx, sequence, 'activation keys changed')
                    expected_values = [int(sample_scalar(native_track, time) * 32767.0 + 0.5)
                                       for time in expected_times]
                    assert values == expected_values, (
                        source.name, fx, sequence, 'native intensity activation mismatch', values, expected_values)
                    if any(values):
                        active_sequences.append({'sequence': sequence, 'animId': clip.anim_id,
                                                 'start': clip.start, 'end': clip.end})
                assert active_sequences, (source.name, fx, 'intensity lost')
                assert len(active_sequences) < count, (source.name, fx, 'effect never deactivates')
                activation[str(fx)] = {'bone': record['words'][0], 'gate': 'intensity-only',
                                       'activeSequences': active_sequences}
        reports.append({'model': native['model'], 'batches': batch_count,
                        'skinFxBatches': affected, 'records': len(fx_report['skinFxRecords']),
                        'textureCombos': combo_count, 'textureWeights': weight_count,
                        'bones': bone_count, 'clips': sequence_count, 'vertices': vertex_count,
                        'particleEmitters': particle_count, 'ribbonEmitters': ribbon_count,
                        'activation': activation,
                        'missingNativePermutations': native['summary']['missingPermutations']})
        print(source.name, 'PASS', len(affected), 'SkinFX batches,', weight_count, 'weights,',
              bone_count, 'bones,', sequence_count, 'clips,', particle_count, 'emitters,', ribbon_count, 'ribbons')
    (OUT / 'validation.json').write_text(json.dumps(reports, indent=2), encoding='utf-8')
    print('PASS: geometry, skinning, clips, emitters, direct SkinFX records, texture pairs and exact per-sequence intensity activation')


if __name__ == '__main__':
    main()
