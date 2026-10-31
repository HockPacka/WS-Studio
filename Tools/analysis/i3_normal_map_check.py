"""Check decoded Datascape I3 normal-map channels against DXT5nm constraints."""
import importlib.util
from pathlib import Path
import sys

import numpy as np

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location('tex', ROOT / 'tools/blender_addon/wildstar_m3/tex.py')
tex = importlib.util.module_from_spec(spec)
spec.loader.exec_module(tex)

NAMES = [
    r'Art\Structure\Texture\Eldan\Occulus_Boss_Room\str_eldan_occulusbossroom_floor_000_NormalUncompressed.tex',
    r'Art\Structure\Texture\Eldan\EldanDungeon_TempleofScionicOrder\STR_EldanTSO_JoinArches_000_Normal.tex',
    r'Art\Structure\Texture\Eldan\EldanDungeon_TempleofScionicOrder\STR_EldanTSO_BaseStone_000_Normal.tex',
    r'Art\Structure\Texture\Eldan\EldanDungeon_TempleofScionicOrder\STR_EldanTSO_RoomBTrim_000_Normal.tex',
    r'Art\Structure\Texture\Eldan\EldanDungeon_TempleofScionicOrder\STR_EldanTSO_ClimbCeilingTile_000_Normal.tex',
    r'Art\Structure\Texture\Eldan\EldanDungeon_TempleofScionicOrder\STR_EldanTSO_RoomBDetails_000_Normal.tex',
    r'Art\Structure\Texture\Eldan\EldanDungeon_TempleofScionicOrder\STR_EldanTSO_StainedGlassSet3_000_Normal.tex',
]


def main(client_data):
    for name in NAMES:
        path = Path(client_data) / name
        data = path.read_bytes()
        header = tex.parse_header(data)
        w, h, rgba = tex.decode_tex(data, max_size=1024)
        xy = rgba[..., [3, 1]].astype(np.float32) / 127.5 - 1.0
        length2 = (xy * xy).sum(axis=-1)
        print(f'{path.name}: {w}x{h} fmt={header["fmt"]} jpg={header["is_jpg"]} '
              f'x=[{xy[..., 0].min():.3f},{xy[..., 0].max():.3f}] '
              f'y=[{xy[..., 1].min():.3f},{xy[..., 1].max():.3f}] '
              f'invalid={(length2 > 1.2).mean() * 100:.2f}% '
              f'flat={(np.max(np.abs(xy), axis=-1) < 0.05).mean() * 100:.2f}%')


if __name__ == '__main__':
    main(sys.argv[1] if len(sys.argv) > 1 else ROOT / 'WoWClient/ClientData')
