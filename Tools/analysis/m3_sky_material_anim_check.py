"""Regression for real Sky material clips and source COLOR0 preservation."""
import importlib.util
import json
from pathlib import Path
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[2]
CLI = ROOT / 'wowdecomp/build/x64/bin/Release/m3_to_m2_cli.exe'
DATA = ROOT / 'WoWClient/ClientData'
OUT = ROOT / 'build_m3test/scratch/sky_animation_dark_m3/material_tracks'
spec = importlib.util.spec_from_file_location('wildstar_m3', ROOT / 'tools/blender_addon/wildstar_m3/m3.py')
m3 = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m3)


def array(data, offset):
    return struct.unpack_from('<II', data, offset)


def track(data, color, alpha, sequence=0):
    base = color + (0x14 if alpha else 0)
    count, arrays = array(data, base + 12)
    assert sequence < count
    key_count, keys = array(data, arrays + sequence * 8)
    assert keys + key_count * (2 if alpha else 12) <= len(data)
    return key_count, keys


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    fixtures = [
        'Art/Sky/SkyBox/Dungeon/DataScape/Sky_Datascape_Air_Clouds_000.m3',
        'Art/Sky/SkyBox/SpaceTravel/Sky_SpaceTravel_Mist_Slow_002.m3',
        'Art/Sky/SkyBox/Halon_Ring/Sky_HalonRing_Nebula_002.m3',
        'Art/Sky/SkyBox/Dungeon/WorldStory1/SKY_Dungeon_WorldStory1_DataFlow_000.m3',
    ]
    report = []
    for relative in fixtures:
        source = DATA / relative
        if not source.exists():
            matches = list((DATA / 'Art/Sky').rglob(source.name))
            assert len(matches) == 1, (relative, matches)
            source = matches[0]
        target = OUT / (source.stem + '.m2')
        skin_path = target.with_suffix('.skin')
        subprocess.run([str(CLI), str(source), str(target), str(skin_path)], check=True, capture_output=True)
        data, skin = target.read_bytes(), skin_path.read_bytes()
        sequence_count, sequences = array(data, 0x1C)
        color_count, colors = array(data, 0x48)
        batch_count, batches = array(skin, 0x24)
        assert sequence_count and color_count >= 5, source.name
        durations = [struct.unpack_from('<I', data, sequences + i * 0x40 + 4)[0] for i in range(sequence_count)]
        extended = []
        animated_entries = 0
        for batch in range(batch_count):
            at = batches + batch * 0x18
            shader = struct.unpack_from('<H', skin, at + 2)[0]
            color_index = struct.unpack_from('<H', skin, at + 8)[0]
            if not shader & 0x2000:
                continue
            assert color_index + 4 < color_count, (source.name, batch, color_index, color_count)
            extended.append(batch)
            base = colors + color_index * 0x28
            for sequence in range(sequence_count):
                count, keys = track(data, base, False, sequence)
                assert count >= 2
                values = struct.unpack_from('<%df' % (count * 3), data, keys)
                assert all(value == 1.0 for value in values), (source.name, batch, sequence, color_index, values)
                count, keys = track(data, base, True, sequence)
                assert count >= 2 and all(value == 32767 for value in struct.unpack_from('<%dH' % count, data, keys))
            for layer in range(1, 5):
                entry = base + layer * 0x28
                for alpha in (False, True):
                    total = 0
                    for sequence in range(sequence_count):
                        count, keys = track(data, entry, alpha, sequence)
                        assert count >= 2
                        if alpha:
                            values = struct.unpack_from('<%dH' % count, data, keys)
                            assert all(0 <= value <= 32767 for value in values)
                        else:
                            values = struct.unpack_from('<%df' % (count * 3), data, keys)
                            assert all(value >= 0.0 for value in values)
                        total += count
                    animated_entries += total > 2 * sequence_count
        assert extended, (source.name, extended)
        # DataScape contributes static COLOR0/material data, not a material clip.
        assert animated_entries or source.name == 'Sky_Datascape_Air_Clouds_000.m3', (source.name, animated_entries)
        item = dict(model=str(source.relative_to(DATA)), sequences=sequence_count, durations=durations,
                    colors=color_count, extendedBatches=extended, animatedEntries=animated_entries)
        if source.name == 'Sky_Datascape_Air_Clouds_000.m3':
            assert struct.unpack_from('<H', data, sequences)[0] == 0
            raw = m3.read_model(source.read_bytes())
            assert len(raw.clips) == 1
            assert durations[0] == raw.clips[0].end - raw.clips[0].start == 99967, durations
            color0 = [color for geometry in raw.geometries for color in geometry.color0]
            vertex_count = array(data, 0x3C)[0]
            assert len(color0) == vertex_count and color0, (len(color0), vertex_count)
            assert all(len(color) == 4 and all(0 <= channel <= 255 for channel in color) for color in color0)
            assert any(color[:3] != (255, 255, 255) for color in color0)
            item['color0Vertices'] = len(color0)
            item['color0MeanBGRA'] = [sum(color[channel] for color in color0) / len(color0) for channel in range(4)]
        report.append(item)
    (OUT / 'validation.json').write_text(json.dumps(report, indent=2), encoding='utf-8')
    print(f'PASS {len(report)} real animated Sky materials: neutral base + four layer tracks, bounded values, clip timing and DataScape COLOR0')


if __name__ == '__main__':
    main()
