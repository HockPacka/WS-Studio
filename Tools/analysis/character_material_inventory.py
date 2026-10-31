"""Inventory raw M3 material layers and texture references without the renderer."""
from pathlib import Path
from collections import Counter
import json,struct
ROOT=Path(__file__).resolve().parents[2]
def align(n):return (n+15)&~15
def material_info(p):
    b=p.read_bytes()
    def ap(offset):
        n,o=struct.unpack_from('<QQ',b,offset);return n,0x630+o
    # Header size is build-specific. Use the existing format reader's base.
    tc,ta=ap(0x1c0);nb=align(ta+tc*32);textures=[]
    for i in range(tc):
        t=ta+i*32;n,o=struct.unpack_from('<QQ',b,t+16)
        textures.append(dict(type=b[t+2],replaceable=struct.unpack_from('<H',b,t)[0],path=b[nb+o:nb+o+n*2].decode('utf-16le').rstrip('\0')))
    mc,ma=ap(0x1f0);db=align(ma+mc*48);materials=[]
    for i in range(mc):
        n,o=struct.unpack_from('<QQ',b,ma+i*48+32);layers=[]
        for j in range(n):
            t=db+o+j*0x128;color,normal=struct.unpack_from('<HH',b,t)
            layers.append(dict(color=color,normal=normal,modes=struct.unpack_from('<5I',b,t+4),layerClass=struct.unpack_from('<I',b,t+0x120)[0],materialType=struct.unpack_from('<I',b,t+0x124)[0]))
        materials.append(layers)
    return dict(path=str(p.relative_to(ROOT/'WoWClient/ClientData')),textures=textures,materials=materials)
def main():
    records=[]
    for p in (ROOT/'WoWClient/ClientData/Art/Character').rglob('*.m3'):
        try:records.append(material_info(p))
        except Exception as e:raise RuntimeError(str(p)) from e
    counts=Counter(len(m) for r in records for m in r['materials'])
    kinds=Counter(t['type'] for r in records for t in r['textures'])
    absent=[dict(model=r['path'],**t) for r in records for t in r['textures'] if t['path'] and not (ROOT/'WoWClient/ClientData'/t['path']).is_file()]
    replacement_absent=[t for t in absent if t['replaceable'] in (1,2)]
    fixed_absent=[t for t in absent if t['replaceable'] not in (1,2)]
    out=ROOT/'build_m3test/character_material_inventory.json'
    out.write_text(json.dumps(dict(layerCounts=dict(counts),textureTypes=dict(kinds),missingFixedReferences=fixed_absent,
        virtualReplacementReferences=replacement_absent,models=records),indent=2),encoding='utf-8')
    print('M3 models:',len(records),'material layer counts:',dict(counts),'texture types:',dict(kinds))
    print('Absent fixed files:',len(fixed_absent),'native replacement-slot references:',len(replacement_absent))
if __name__=='__main__':main()
