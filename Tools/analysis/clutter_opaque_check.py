"""Check derived opaque detail textures: RGB/mips unchanged, alpha becomes 255."""
from pathlib import Path
import json
import struct
import subprocess
import sys
import numpy as np
from PIL import Image

ROOT=Path(__file__).resolve().parents[2]
CLI=ROOT/'wowdecomp/build/x64/bin/Release/tex_to_blp_cli.exe'


def levels(b):
    w,h=struct.unpack_from('<II',b,12)
    for mip in range(16):
        off=struct.unpack_from('<I',b,0x14+mip*4)[0]
        size=struct.unpack_from('<I',b,0x54+mip*4)[0]
        if not size: break
        mw,mh=max(1,w>>mip),max(1,h>>mip)
        data=b[off:off+size]
        if b[8]==3:
            pixels=np.frombuffer(data,np.uint8).reshape(mh,mw,4)[...,[2,1,0,3]]
        else:
            kind={0:1,1:2,7:3}[b[10]]
            pixels=np.asarray(Image.frombytes('RGBA',(mw,mh),data,'bcn',kind))
        yield pixels


def main():
    out=ROOT/'build_m3test/clutter_opaque_dbg43';out.mkdir(parents=True,exist_ok=True)
    source=ROOT/'WoWClient/ClientData/Art/Terrain/Gravel/Clutter/Clutter_Gravel_SmoothRoundStonesMossy_GreyGreen_000_Color.tex'
    cases=[source]
    for fmt in (13,14,15):
        b=bytearray(112);b[:4]=source.read_bytes()[:4]
        struct.pack_into('<9I',b,4,3,4,4,1,1,1,fmt,0,0)
        rgb=struct.pack('<HHI',0,65535,0xe4e4e4e4)
        if fmt==14: b.extend(bytes.fromhex('1032547698badcfe'))
        if fmt==15: b.extend(bytes.fromhex('00ff1032547698ba'))
        b.extend(rgb)
        p=out/f'dxt{fmt}.tex';p.write_bytes(b);cases.append(p)
    counts=[]
    for i,p in enumerate(cases):
        normal,opaque=out/f'{i}_normal.blp',out/f'{i}_opaque.blp'
        subprocess.run([str(CLI),str(p),str(normal)],check=True)
        subprocess.run([str(CLI),str(p),str(opaque),'--opaque'],check=True)
        original,converted=normal.read_bytes(),opaque.read_bytes()
        assert converted[9]==0
        a,b=list(levels(original)),list(levels(converted));assert len(a)==len(b)
        for before,after in zip(a,b):
            assert np.all(after[...,3]==255)
            assert np.abs(before[...,:3].astype(int)-after[...,:3].astype(int)).max()<=2
        if i==0:
            assert np.any(a[0][...,3]<128), 'real rock must exercise material alpha'
            recipe=out/'recipe.blp'
            name='WS\\Art\\Terrain\\Gravel\\Clutter\\Clutter_Gravel_SmoothRoundStonesMossy_GreyGreen_000_Color#opaque.blp'
            subprocess.run([str(CLI),name,str(recipe),'--load'],cwd=ROOT/'WoWClient',check=True)
            assert recipe.read_bytes()==converted
        counts.append(dict(source=str(p),mips=len(a),opaque=True,rgb_preserved=True))
    (out/'validation.json').write_text(json.dumps(counts,indent=2))
    print('PASS opaque detail textures: real rock + DXT1/3/5, RGB/mips preserved, TEX path recipe verified')


if __name__=='__main__': main()
