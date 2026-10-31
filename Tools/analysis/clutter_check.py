"""Independent validation of generated MCLT instances against AREA and CSV tables.

Usage: clutter_check.py source.area generated.adt output_directory
Also converts every used model to validate the ground-detail model contract.
"""
from collections import Counter
import csv
import json
from pathlib import Path
import struct
import subprocess
import sys
import numpy as np
from PIL import Image, ImageDraw
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from area_reader import read_area, read_chnk, split_cell
from terrain_block_check import reference

ROOT = Path(__file__).resolve().parents[2]
SCALE = 33.333332 / 32


def float_bc1(data):
    """Vectorized normalized BC1 reference (no intermediate RGB byte rounding)."""
    blocks = np.frombuffer(data,np.uint8).reshape(-1,8).astype(np.uint32)
    a, b = blocks[:,0]+256*blocks[:,1], blocks[:,2]+256*blocks[:,3]
    def rgb(v): return np.stack([(v>>11)/31,((v>>5)&63)/63,(v&31)/31],axis=-1)
    pa, pb = rgb(a), rgb(b)
    four = a>b
    palette = np.ones((289,4,4))
    palette[:,0,:3]=pa; palette[:,1,:3]=pb
    palette[:,2,:3]=np.where(four[:,None],(2*pa+pb)/3,(pa+pb)/2)
    palette[:,3,:3]=np.where(four[:,None],(pa+2*pb)/3,0)
    palette[:,3,3]=four
    bits = blocks[:,4]+(blocks[:,5]<<8)+(blocks[:,6]<<16)+(blocks[:,7]<<24)
    indices = (bits[:,None]>>(2*np.arange(16,dtype=np.uint32)))&3
    pixels = palette[np.arange(289)[:,None],indices]
    return pixels.reshape(17,17,4,4,4).transpose(0,2,1,3,4).reshape(68,68,4)[:65,:65]


def source_weights(blocks):
    if any(bit in blocks and any(blocks[bit]) for bit in (29,2)):
        return reference(blocks)[1]
    for bit in (19,17):
        if bit not in blocks: continue
        base = float_bc1(blocks[bit]); rgb = base[...,:3]
        if bit+1 in blocks:
            rgb = rgb + float_bc1(blocks[bit+1])[...,:3]*[31/15,63/31,31/15]-1
        return np.clip(np.concatenate([rgb,1-rgb.sum(-1,keepdims=True)],axis=-1),0,1)*base[...,3:4]
    return np.zeros((65,65,4))


def chunks(data, start=0):
    while start < len(data):
        tag, size = struct.unpack_from('<II', data, start)
        end = start + 8 + size
        assert end <= len(data)
        yield struct.pack('>I',tag).decode('ascii'), data[start+8:end]
        start = end


def main():
    source, target, out = Path(sys.argv[1]), Path(sys.argv[2]), Path(sys.argv[3])
    out.mkdir(parents=True, exist_ok=True)
    area = read_area(source.read_bytes())
    cells = {}
    for tag, _, data, _ in area['chunks']:
        if tag in ('CHNK','KNHC'):
            for i, _, raw in read_chnk(data, area['compressed']):
                if i >= 0: cells[i] = split_cell(raw)[1]
    tables = ROOT / 'WoWClient/tables_csv'
    layers = {int(r['ID']): r for r in csv.DictReader((tables/'WorldLayer.csv').open(encoding='utf-8-sig'))}
    clutter = {int(r['ID']): r for r in csv.DictReader((tables/'WorldClutter.csv').open(encoding='utf-8-sig'))}
    models, density = Counter(), Counter()
    # Source-orientation preview with forbidden pixels in red and actual placements in green.
    image = Image.new('RGB',(1024,1024),(24,28,32)); draw=ImageDraw.Draw(image)
    count = 0; populated = 0
    for tag, data in chunks(target.read_bytes()):
        if tag != 'MCNK': continue
        cx, cy = struct.unpack_from('<II',data,4)
        ix, iy = 15-cx, 15-cy
        blocks = cells.get(ix+16*iy,{})
        if 16 in blocks:
            flags = np.frombuffer(blocks[16],np.uint8).reshape(64,64)
            rgb = np.zeros((64,64,3),np.uint8) + [24,28,32]
            rgb[(flags&32)!=0] = [90,25,25]
            image.paste(Image.fromarray(rgb.astype(np.uint8)),(ix*64,iy*64))
        for sub, payload in chunks(data,128):
            if sub != 'MCLT': continue
            populated += 1
            version, nmodels, n = struct.unpack_from('<III',payload)
            assert version == 1 and 0 < nmodels <= 96 and n <= 1000
            pos = 12; names = []
            for _ in range(nmodels):
                flags, size = struct.unpack_from('<II',payload,pos); pos += 8
                name = payload[pos:pos+size-1].decode(); assert payload[pos+size-1] == 0
                pos += size
                assert name.startswith('WS\\') and (ROOT/'WoWClient/ClientData'/name[3:].replace('\\','/')).is_file(), name
                names.append(name)
            assert len(payload)-pos == n*20
            ids = struct.unpack('<4I',blocks[1])
            weights = source_weights(blocks)
            for j in range(n):
                model, x, y, rotation, scale = struct.unpack_from('<I4f',payload,pos+j*20)
                assert 0 <= model < nmodels and 0 <= x < 32 and 0 <= y < 32
                px, py = min(63,int(x*2)), min(63,int(y*2)); pixel = px+py*64
                assert 16 not in blocks or not (blocks[16][pixel]&32), (cx,cy,x,y)
                fx, fy = x*2-px, y*2-py
                w = ((weights[py,px]*(1-fx)+weights[py,px+1]*fx)*(1-fy)
                     +(weights[py+1,px]*(1-fx)+weights[py+1,px+1]*fx)*fy)
                w = w*w; w /= max(w.sum(),1e-20)
                possible = []
                for slot, layerid in enumerate(ids):
                    if w[slot] < 0.25-2e-6: continue
                    selector = (blocks.get(27,b'\0'*4096)[pixel]>>(slot*2))&3
                    row = layers.get(layerid)
                    if not row: continue
                    preset = clutter.get(int(row[f'worldClutterId0{selector}']))
                    if not preset or float(preset['density']) <= 0: continue
                    for k in range(6):
                        suffix = f'0{k}' if k else '0'
                        if float(preset['assetWeight'+suffix]) <= 0: continue
                        if ('WS\\'+preset['assetPath'+suffix]).lower() == names[model].lower():
                            lo, hi = sorted([float(preset['minScale'+suffix])*SCALE,SCALE])
                            rlo, rhi = sorted([float(preset['rotationMin'+suffix]),float(preset['rotationMax'+suffix])])
                            if lo-1e-5<=scale<=hi+1e-5 and rlo-1e-5<=rotation<=rhi+1e-5: possible.append(slot)
                assert possible, (cx,cy,names[model],x,y,scale,rotation,w)
                models[names[model]] += 1
                density[cx+cy*16] += 1; count += 1
                draw.point((ix*64+px,iy*64+py),fill=(90,230,100))
    assert count > 0
    image.save(out/'placements.png')
    converted=[]; texture_names=set()
    cli = ROOT/'wowdecomp/build/x64/bin/Release/m3_to_m2_cli.exe'
    for i, name in enumerate(models):
        path = ROOT/'WoWClient/ClientData'/name[3:].replace('\\','/')
        m2, skin = out/f'{i:03d}.m2', out/f'{i:03d}.skin'
        subprocess.run([str(cli),str(path),str(m2),str(skin)],check=True,capture_output=True)
        b, s = m2.read_bytes(), skin.read_bytes()
        batches, off = struct.unpack_from('<II',s,0x24)
        textures, tc = struct.unpack_from('<II',b,0x80)
        used = set()
        for j in range(batches):
            combo = struct.unpack_from('<H',s,off+j*24+16)[0]
            used.add(struct.unpack_from('<H',b,tc+combo*2)[0])
        assert len(used) == 1, (name,used,'detail renderer needs one atlas')
        _, texoff=struct.unpack_from('<II',b,0x50)
        for t in used:
            length,offset=struct.unpack_from('<II',b,texoff+t*16+8)
            texname=b[offset:offset+length-1].decode()
            assert texname.startswith('WS\\'), (name,texname)
            texture_names.add(texname)
        vertices = struct.unpack_from('<I',s,4)[0]
        indices = struct.unpack_from('<I',s,12)[0]
        assert vertices <= 4096 and indices <= 4096, (name,vertices,indices)
        converted.append(dict(model=name,vertices=vertices,indices=indices,instances=models[name]))
    texcli=ROOT/'wowdecomp/build/x64/bin/Release/tex_to_blp_cli.exe'
    for i,name in enumerate(sorted(texture_names)):
        path=ROOT/'WoWClient/ClientData'/name[3:].replace('\\','/')
        path=path.with_suffix('.tex')
        subprocess.run([str(texcli),str(path),str(out/f'texture_{i:03d}.blp')],check=True,capture_output=True)
    report=dict(placements=count,populated_chunks=populated,max_per_chunk=max(density.values()),
                unique_models=len(models),models=converted,textures=len(texture_names),forbidden_placements=0,invalid_presets=0)
    (out/'validation.json').write_text(json.dumps(report,indent=2))
    print('PASS',count,'placements in',populated,'chunks;',len(models),'models; zero blocked/invalid placements')


if __name__=='__main__': main()
