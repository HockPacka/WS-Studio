"""Extract original race skin examples and shared clothing overlay regions as RGBA PNG."""
from pathlib import Path
import sys,json,zipfile,importlib.util
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[1]
DATA=ROOT/'WoWClient/ClientData'
OUT=ROOT/'exports/character_clothing_png'
sys.path[:0]=[str(ROOT/'tools'),str(ROOT/'tools/blender_addon/wildstar_m3')]
from tbl_dump import parse
import tex

def table(name):
    _,c,r=parse((DATA/'DB'/(name+'.tbl')).read_bytes())
    return [dict(zip((x[0] for x in c),row)) for row in r]

def extract(source,target):
    w,h,a=tex.decode_tex(source.read_bytes(),16384)
    img=Image.fromarray(np.asarray(a,dtype=np.uint8),'RGBA')
    assert img.size==(w,h)
    img.save(target)
    check=Image.open(target);check.load()
    return dict(source=str(source.relative_to(DATA)),png=str(target.relative_to(OUT)),width=w,height=h,alphaMin=int(a[:,:,3].min()),alphaMax=int(a[:,:,3].max()))

def main():
    OUT.mkdir(parents=True,exist_ok=True)
    displays={r['ID']:r for r in table('ItemDisplay')}
    custom=table('CharacterCustomization');races={r['ID']:r for r in table('Race')}
    manifest=[]
    for name,race in [('Human_Exile',1),('Granok',3),('Aurin',4),('Mordesh',16),('Cassian_Dominion',1),('Draken',5),('Mechari',12),('Chua',13)]:
        found=None
        for row in custom:
            if row['raceId']!=race or row['gender']!=0 or row['itemSlotId']!=24 or row['flags']&3!=2:continue
            d=displays.get(row['itemDisplayId'],{})
            path=d.get('skinColorMap','')
            if not path:continue
            original=DATA/path
            candidates=[original.with_suffix('.Skin_Body.tex'),original]
            suffix=Path(races[race]['maleAssetPath'].replace('\\','/')).stem
            stem=original.stem
            at=stem.lower().rfind('_color')
            if at>=0:
                resolved=original.with_name(stem[:at]+'_'+suffix+stem[at:]+original.suffix)
                candidates.extend([resolved.with_suffix('.Skin_Body.tex'),resolved])
            found=next((p for p in candidates if p.is_file()),None)
            if found:
                result=extract(found,OUT/(name+'_skin.png'));result.update(race=name,nativeRaceId=race,sex=0,itemDisplayId=row['itemDisplayId'],role='skin example; separate from clothing atlas')
                manifest.append(result);break
        if not found:raise RuntimeError('No original skin example: '+name)
    # Eshara has no native component layout; export its model's real first color map.
    import m3
    eshara=DATA/races[2]['maleAssetPath']
    model=m3.read_model(eshara.read_bytes()) if eshara.is_file() else None
    source=next((DATA/t[0] for t in model.textures if t[1]==0 and (DATA/t[0]).is_file()),None) if model else None
    if source:
        result=extract(source,OUT/'Eshara_model_color.png');result.update(race='Eshara',nativeRaceId=2,role='original nonplayable model color; no component layout');manifest.append(result)
    regions={r['ID']:r for r in table('ComponentRegion')}
    rects=[r for r in table('ComponentRegionRect') if r['componentLayoutId']==10 and regions[r['regionId']]['componentMap']==1]
    assert rects
    width=max(r['rectLimX'] for r in rects);height=max(r['rectLimY'] for r in rects)
    atlas=Image.new('RGBA',(width,height),(0,0,0,0))
    stem=DATA/'Art/Item/Armor/Medium/Medium_008/AMR_Medium_008_Color'
    for r in rects:
        region=regions[r['regionId']]['EnumName'];source=Path(str(stem)+'.'+region+'.tex')
        if not source.is_file():continue
        target=OUT/(region+'_color.png');result=extract(source,target)
        rect=(r['rectMinX'],r['rectMinY'],r['rectLimX'],r['rectLimY'])
        image=Image.open(target).convert('RGBA')
        image=image.resize((rect[2]-rect[0],rect[3]-rect[1]),Image.Resampling.BILINEAR)
        atlas.paste(image,rect[:2])
        result.update(role='shared clothing color region',componentLayoutId=10,region=region,rect=rect);manifest.append(result)
    atlas.save(OUT/'Clothing_Atlas_Medium_008.png')
    dye=Path(str(stem).replace('_Color','_Dye')+'.Armor_Chest.tex')
    if dye.is_file():
        result=extract(dye,OUT/'Armor_Chest_dye_mask.png');result['role']='dye mask; data channels, not color';manifest.append(result)
    (OUT/'sources.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2),encoding='utf-8')
    (OUT/'README.txt').write_text('Originale WildStar-Texturen als RGBA-PNG, inklusive unveraendertem Alpha.\n'
        'Pro Rasse ein maennliches Hautbeispiel. Human/Exile und Cassian verwenden dieselbe Human-Grundtextur.\n'
        'Eshara: nicht spielbar; die in Race.tbl genannte Modelldatei fehlt in diesem Datenbestand.\n'
        'Kleidung: ItemDisplay.armorColorMap -> AMR_Medium_008_Color.Armor_*.tex.\n'
        'Clothing_Atlas_Medium_008.png rekonstruiert den gemeinsamen Armor-Atlas mit ComponentLayoutId 10.\n'
        'Dieser Armor-Atlas ist von den rassespezifischen Skin-Atlanten getrennt; kein direktes Ueberlagern der PNGs.\n'
        'Armor_Chest_dye_mask.png enthaelt Dye-Steuerdaten. Alle Quelldateien und Rechtecke stehen in sources.json.\n',encoding='utf-8')
    archive=OUT.with_suffix('.zip')
    with zipfile.ZipFile(archive,'w',zipfile.ZIP_DEFLATED) as z:
        for p in sorted(OUT.iterdir()):
            if p.is_file():z.write(p,p.name)
    print('Export:',OUT);print('ZIP:',archive);print('PNG files:',len(list(OUT.glob('*.png'))))
    print('Skin examples:',[(r.get('race'),r['width'],r['height']) for r in manifest if 'race' in r])

if __name__=='__main__':main()
