"""Independent Pillow BCn check and terrain block mosaics.

usage: terrain_block_check.py tile.area terrain_blend_cli.bin output_directory
The binary comes from the C++ terrain_blend_cli using the production decoder.
"""
from collections import Counter
import csv
import json
from pathlib import Path
import struct
import sys

import numpy as np
from PIL import Image, ImageDraw

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from area_reader import read_area, read_chnk, split_cell


def bc(data, kind):
    # Pillow's native BCn decoder is independent of our C++ decoder.
    return np.asarray(Image.frombytes('RGBA', (68, 68), data, 'bcn', kind))[:65, :65].astype(float) / 255


def reference(blocks):
    for bit in (29, 2):
        if bit in blocks and any(blocks[bit]):
            v = np.frombuffer(blocks[bit], '<u2').reshape(65, 65)
            w = np.stack([(v >> (4*k)) & 15 for k in range(4)], -1).astype(float)
            total = w.sum(-1, keepdims=True)
            w /= np.maximum(total, 1)
            w[total[..., 0] == 0, 0] = 1
            return bit, w
    for bit in (19, 17):
        if bit in blocks:
            base = bc(blocks[bit], 1)
            rgb = base[..., :3]
            if bit+1 in blocks:
                rgb = rgb + bc(blocks[bit+1], 1)[..., :3] * [31/15, 63/31, 31/15] - 1
            w = np.concatenate((rgb, 1-rgb.sum(-1, keepdims=True)), -1)
            return bit, np.clip(w, 0, 1) * base[..., 3:4]
    return -1, np.zeros((65, 65, 4))


def main():
    area = read_area(Path(sys.argv[1]).read_bytes())
    cells = {}
    for tag, size, data, pos in area['chunks']:
        if tag in ('CHNK', 'KNHC'):
            for index, flags, raw in read_chnk(data, area['compressed']):
                if index >= 0:
                    cells[index] = split_cell(raw)[1]
    out = Path(sys.argv[3]); out.mkdir(parents=True, exist_ok=True)
    production = Path(sys.argv[2]).read_bytes()
    stride = 4 + 65*65*4*4
    assert len(production) == 256*stride
    mosaics = {n: np.zeros((1024, 1024, 3), np.uint8) for n in
               ('weights_before', 'weights_decoded', 'bit13_colour', 'bit13_alpha', 'bit17_bc1', 'bit18_bc1', 'bit16_flags', 'bit16_zone_index', 'bit16_no_clutter', 'bit27_fields',
                'bit27_slot0', 'bit27_slot1', 'bit27_slot2', 'bit27_slot3')}
    palette = np.array([[90, 100, 130], [185, 150, 90], [55, 120, 185], [80, 170, 90]])
    maximum = 0; sources = Counter(); values = {16: Counter(), 27: Counter()}
    table = Path(sys.argv[1]).parents[3] / 'tables_csv' / 'WorldLayer.csv'
    layers = {int(r['ID']): r for r in csv.DictReader(table.open(encoding='utf-8-sig'))} if table.exists() else {}
    clutter_samples = clutter_matches = 0
    errors = []
    for i, blocks in cells.items():
        source, ref = reference(blocks)
        actualSource = struct.unpack_from('<i', production, i*stride)[0]
        actual = np.frombuffer(production, '<f4', count=65*65*4, offset=i*stride+4).reshape(65, 65, 4)
        assert actualSource == source, (i, actualSource, source)
        err = float(np.abs(actual-ref).max()); maximum = max(maximum, err)
        errors.append(err); sources[source] += 1
        # Integer endpoint expansion in Pillow differs slightly from GPU-normalised
        # floats. Allow that quantisation, including residual accumulation.
        assert err < 1/31, (i, source, err)
        y, x = divmod(i, 16); dest = np.s_[y*64:(y+1)*64, x*64:(x+1)*64]
        normal = actual[:64, :64] / np.maximum(actual[:64, :64].sum(-1, keepdims=True), 1e-12)
        mosaics['weights_decoded'][dest] = np.clip(normal @ palette, 0, 255).astype(np.uint8)
        before = ref[:64, :64].copy()
        if source in (17, 19):
            # Reconstruct dbg38's mistaken first-endpoint vertex raster.
            data = np.frombuffer(blocks[source], '<u2').reshape(17, 17, 4)[..., 0]
            rgb = np.stack([((data >> 11)&31)/31, ((data >> 5)&63)/63, (data&31)/31], -1)
            axis = np.arange(64)/4; lo = axis.astype(int); hi = np.minimum(lo+1, 16); t = (axis-lo)[:, None, None]
            horizontal = rgb[:, lo]*(1-t.transpose(1,0,2)) + rgb[:, hi]*t.transpose(1,0,2)
            old = horizontal[lo]*(1-t) + horizontal[hi]*t
            before = np.concatenate((old, np.maximum(0, 1-old.sum(-1, keepdims=True))), -1)
        before /= np.maximum(before.sum(-1, keepdims=True), 1e-12)
        mosaics['weights_before'][dest] = np.clip(before @ palette, 0, 255).astype(np.uint8)
        if 13 in blocks:
            rgba = bc(blocks[13], 2)
            mosaics['bit13_colour'][dest] = (rgba[:64, :64, :3]*255).astype(np.uint8)
            mosaics['bit13_alpha'][dest] = (rgba[:64, :64, 3:4]*255).astype(np.uint8)
        for bit in (17, 18):
            if bit in blocks:
                mosaics[f'bit{bit}_bc1'][dest] = (bc(blocks[bit],1)[:64, :64, :3]*255).astype(np.uint8)
        for bit in (16, 27):
            if bit in blocks:
                v = np.frombuffer(blocks[bit], np.uint8).reshape(64, 64)
                values[bit].update(v.ravel().tolist())
                if bit == 16:
                    mosaics['bit16_flags'][dest] = np.stack([(v&32)*7, (v&8)*28, (v&16)*14], -1)
                    mosaics['bit16_zone_index'][dest] = (((v>>3)&3)*85)[..., None]
                    mosaics['bit16_no_clutter'][dest] = (((v>>5)&1)*255)[..., None]
                else:
                    mosaics['bit27_fields'][dest] = np.stack([(v&3)*85, ((v>>2)&3)*85, ((v>>4)&3)*85], -1)
                    ids = struct.unpack('<4I', blocks[1]) if 1 in blocks else (0,0,0,0)
                    for slot in range(4):
                        field = (v>>(2*slot))&3
                        mosaics[f'bit27_slot{slot}'][dest] = (field*85)[..., None]
                        layer = layers.get(ids[slot])
                        if layer:
                            for preset in range(1,4):
                                count = int((field == preset).sum())
                                clutter_samples += count
                                if int(layer[f'worldClutterId{preset:02d}']): clutter_matches += count
    for name, pixels in mosaics.items(): Image.fromarray(pixels).save(out / (name+'.png'))
    # Side-by-side crops use the same fixed slot colours. These are weight maps,
    # not a simulation of texture sampling or in-game lighting.
    compare = Image.new('RGB', (1400, 745), '#171b22'); draw = ImageDraw.Draw(compare)
    for x, name, title in [(10,'weights_before','dbg38: BC1 endpoints misread as vertices'), (710,'weights_decoded','dbg39: decoded pixels + signed correction')]:
        compare.paste(Image.fromarray(mosaics[name]).resize((680,680)), (x,45)); draw.text((x,15),title,fill='white')
    compare.save(out/'blend_comparison.png')
    report = dict(tile=str(Path(sys.argv[1])), cells=len(cells), sources=dict(sources),
                  max_cpp_pillow_error=maximum, mean_cell_max_error=float(np.mean(errors)),
                  nonzero_clutter_fields=clutter_samples, fields_selecting_existing_clutter=clutter_matches,
                  bit16_values=dict(values[16]), bit27_values=dict(values[27]))
    (out/'validation.json').write_text(json.dumps(report,indent=2))
    print(json.dumps({k:v for k,v in report.items() if k not in ('bit16_values','bit27_values')}))


if __name__ == '__main__': main()
