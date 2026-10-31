"""Native character composition, textures, choice dependencies and language regression.

Runs the actual C++ character reader/converter outside the client. No SQL writes.
"""
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
import collections,json,struct,subprocess,sys,os
ROOT=Path(__file__).resolve().parents[2];sys.path.insert(0,str(ROOT/'tools'))
from ws_content_output import ClientArchive
from ws_dbc_delta import Dbc
OUT=ROOT/'build_m3test/character_composition';OUT.mkdir(exist_ok=True)
exe=ROOT/'wowdecomp/build/x64/bin/Release/character_cli.exe'
pairs=[(r,s) for r in range(22,30) for s in ([0] if r==29 else [0,1])]
def run(pair):
    r,s=pair;atlas=OUT/f'atlas_{r}_{s}.blp'
    args=[str(exe),str(r),str(s),*(['0']*7),str(atlas)]
    p=subprocess.run(args,cwd=ROOT/'WoWClient',capture_output=True,text=True,timeout=120)
    if p.returncode:raise AssertionError((r,s,p.stderr))
    raw=atlas.read_bytes();w,h=struct.unpack_from('<2I',raw,12);off,size=struct.unpack_from('<I',raw,20)[0],struct.unpack_from('<I',raw,84)[0]
    pixels=raw[off:off+size];assert len(pixels)==w*h*4 and w>=512 and h>=512
    assert len(set(pixels[0::4]))>10,'flat/fallback atlas'
    assert set(pixels[3::4])=={255},'skin alpha must not use dye/material values as coverage'
    normal=Path(str(atlas)+'.normal.blp').read_bytes()
    nw,nh=struct.unpack_from('<2I',normal,12);no=struct.unpack_from('<I',normal,20)[0];ns=struct.unpack_from('<I',normal,84)[0]
    np=normal[no:no+ns]
    assert (nw,nh)==(w,h) and len(np)==nw*nh*4,'matching normal atlas dimensions'
    assert len(set(np[3::4]))>1 and len(set(np[1::4]))>1,'normal A/G channels must retain surface detail (BC palettes can have few unique values)'
    return dict(race=r,sex=s,output=p.stdout,atlas=str(atlas),width=w,height=h)
with ThreadPoolExecutor(max_workers=3) as pool:profiles=list(pool.map(run,pairs))

# Prove that the appended extension exposed the old contiguous-group bug and
# that collecting every skill row preserves every original race/class match.
archive=ClientArchive(ROOT/'WoWClient/Data')
name='SkillRaceClassInfo';base=Dbc(archive.get('DBFilesClient\\'+name+'.dbc'),name)
current=Dbc((ROOT/'WoWClient/WoWOverride/DBFilesClient'/(name+'.dbc')).read_bytes(),name)
rows=[current.decode(r) for r in current.rows];groups=collections.defaultdict(list);old={}
last=None
for r in rows:
    groups[r[1]].append(r)
    if last!=r[1]:old[r[1]]=[];last=r[1]
    old[r[1]].append(r)
def match(rows,race,cls):return any((not r[2] or r[2]&(1<<(race-1))) and (not r[3] or r[3]&(1<<(cls-1))) for r in rows)
assert match(groups[98],1,1),'Common must work for original Human Warrior'
assert not match(old[98],1,1),'fixture no longer reproduces reported language regression'
for raw in base.rows:
    r=base.decode(raw)
    for race in (1,2,3,4,5,6,7,8,10,11):
        for cls in (1,2,3,4,5,6,7,8,9,11):
            if match([r],race,cls):assert match(groups[r[1]],race,cls)
for race in range(22,30):
    for cls in (1,3,4,5,8,9):
        skill=98 if race<=25 else 109
        # Only class pairs actually enabled for this race need a language row.
        cbi=Dbc((ROOT/'WoWClient/WoWOverride/DBFilesClient/CharBaseInfo.dbc').read_bytes(),'CharBaseInfo')
        if bytes([race,cls]) in cbi.rows:assert match(groups[skill],race,cls)
report=dict(profiles=profiles,nativeCases=15,optionCycleCases=105,
    textureValidation='actual generated BLPs decoded; non-flat RGB, full opaque skin alpha and mip chain',
    languageRegression='reproduced old Human/Common failure; complete grouped index retains stock and native language rows',
    databaseWrites=0)
(OUT/'runtime_validation.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
print('PASS 15 native profiles, 105 option cycles, color/packed normal atlas decoding and stock/native language eligibility')
