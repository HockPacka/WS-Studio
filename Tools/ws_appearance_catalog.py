"""Offline numeric model/preset catalog for the Eluna appearance bridge; never allocates new DBC IDs."""
from pathlib import Path
import json,sys
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
from tbl_dump import parse
from ws_npc_patch import model_list
def table(name):
    _,c,r=parse((ROOT/'WoWClient/ClientData/DB'/(name+'.tbl')).read_bytes());return [dict(zip([x[0] for x in c],v)) for v in r]
def generate(out):
    models=model_list(str(ROOT/'WoWClient'));by_path={p.lower():200000+i for i,p in enumerate(models)}
    h=2166136261
    for p in models:
        for c in p.encode('mbcs').lower()+b'\n':h=((h^c)*16777619)&0xffffffff
    for name in ['CharacterCustomization','CharacterCustomizationLabel','ItemDisplay','Item2Type','Creature2DisplayInfo','Creature2ModelInfo','ComponentRegion','ComponentRegionRect','Race','ModelMesh','ItemColorSet','DyeColorRamp']:
        for c in (ROOT/'WoWClient/ClientData/DB'/(name+'.tbl')).read_bytes():h=((h^c)*16777619)&0xffffffff
    races={r['ID']:r for r in table('Race')};mapping={22:1,23:3,24:4,25:16,26:1,27:5,28:12,29:13}
    metadata={200000+i:dict(sex=0,races={},humanoid=False) for i in range(len(models))}
    for wow,native in mapping.items():
        for sex,column in [(0,'maleAssetPath'),(1,'femaleAssetPath')]:
            if native==13 and sex==1:continue
            display=by_path.get(races[native][column].lower())
            if display is not None:metadata[display]['races'][wow]=True;metadata[display]['sex']=sex;metadata[display]['humanoid']=True
    presets=[]
    for name in ['Creature2DisplayInfo','Creature2ModelInfo']:
        presets.append({r['ID']:by_path[r['assetPath'].lower()] for r in table(name) if r['assetPath'].lower() in by_path})
    slots={r['ID']:r['itemSlotId'] for r in table('Item2Type')}
    items={r['ID']:True for r in table('ItemDisplay') if slots.get(r.get('item2TypeId'),0)}
    result=dict(hash=f'{h:08x}',models=metadata,display=presets[0],model=presets[1],items=items)
    lines=['WSPCatalog = {hash="'+result['hash']+'",models={']
    for id,m in metadata.items():lines.append(f'[{id}]={{sex={m["sex"]},humanoid={str(m["humanoid"]).lower()},races={{'+','.join(f'[{race}]=true' for race in m['races'])+'}},')
    lines.append('},display={'+','.join(f'[{k}]={v}' for k,v in presets[0].items())+'},model={'+','.join(f'[{k}]={v}' for k,v in presets[1].items())+'},items={'+','.join(f'[{k}]=true' for k in items)+'}}')
    out=Path(out);out.mkdir(parents=True,exist_ok=True);(out/'AppearanceCatalog.lua').write_text('\n'.join(lines)+'\n',encoding='utf-8');(out/'appearance_catalog.json').write_text(json.dumps(result,separators=(',',':')),encoding='utf-8')
    print('Catalog',result['hash'],'models',len(models),'presets',len(presets[0])+len(presets[1]),'items',len(items));return result
if __name__=='__main__':generate(sys.argv[1] if len(sys.argv)>1 else ROOT/'build_wildstar/wildstar335a/server/adapters/azerothcore/appearance')
