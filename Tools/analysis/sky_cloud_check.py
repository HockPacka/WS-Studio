"""Check native cloud fields against independent CSV/reference placement math.
Also validates actual local assets through the existing native model/TEX tools.
"""
import csv,importlib.util,json,math,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];CLIENT=ROOT/'WoWClient';OUT=ROOT/'build_m3test/sky_stage2';OUT.mkdir(exist_ok=True)
CLI=ROOT/'wowdecomp/build/x64/bin/Release/sky_cli.exe'
BIN=CLI.parent
def table(n):return {int(r['ID']):r for r in csv.DictReader((CLIENT/'tables_csv'/f'{n}.csv').open(encoding='utf-8-sig'))}
sets,tracks=table('SkyCloudSet'),table('SkyTrackCloudSet');assets=set();cases=0
for set_id,cloud in sets.items():
    density=float(cloud['density']);expected=[]
    for i in range(math.ceil(density)):
        seed=(set_id*0x9e3779b9+i*0x85ebca6b)&0xffffffff
        def random():
            global seed
            seed=(seed*1664525+1013904223)&0xffffffff;return seed/2**32
        z=random()*4000-2000
        lane=next((k for k,end in enumerate([-1200,-200,0,200,1200,2000]) if z<=end),5)
        track=tracks.get(int(cloud[f'skyTrackCloudSetId{lane:02d}']))
        if not track or not int(track['count']):continue
        n=int(random()*int(track['count']));path=track[f'model{n:02d}']
        if not path:continue
        scale=float(track[f'minSize{n:02d}'])+random()*(float(track[f'maxSize{n:02d}'])-float(track[f'minSize{n:02d}']))
        phase=random()*4000
        expected.append((path.replace('\\','/'),i,z,scale,phase))
    for seconds in (0,1,300):
        actual=json.loads(subprocess.check_output([str(CLI),'--clouds',str(set_id),str(seconds)],cwd=CLIENT,text=True))
        assert len(actual)==len(expected),(set_id,len(actual),len(expected))
        for got,(path,i,z,scale,phase) in zip(actual,expected):
            x=(phase+seconds*15)%4000-2000
            assert got['path']==path and got['index']==i
            assert abs(got['scale']-scale)<1e-6
            desired=[(x+z)/math.sqrt(2),200,(z-x)/math.sqrt(2)]
            assert max(abs(a-b) for a,b in zip(got['position'],desired))<.0005,(got,desired)
            alpha=min(1,max(0,(2000-abs(x))/400))*min(1,density-i)
            assert abs(got['alpha']-alpha)<1e-6
            assets.add(path)
        cases+=1
spec=importlib.util.spec_from_file_location('m3',ROOT/'tools/blender_addon/wildstar_m3/m3.py');m3=importlib.util.module_from_spec(spec);spec.loader.exec_module(m3)
textures=set();converted=[];missing=[]
for path in sorted(assets):
    p=CLIENT/'ClientData'/path
    if not p.is_file():missing.append(path);continue
    raw=p.read_bytes();model=m3.read_model(raw)
    for tex in model.textures:
        if tex[0] and tex[1]==0:textures.add(tex[0].replace('\\','/'))
    target=OUT/(p.stem+'.m2');skin=target.with_suffix('.skin')
    subprocess.run([str(BIN/'m3_to_m2_cli.exe'),str(p),str(target),str(skin)],check=True,capture_output=True)
    converted.append(path)
for path in sorted(textures):
    p=CLIENT/'ClientData'/path
    subprocess.run([str(BIN/'tex_to_blp_cli.exe'),str(p),str(OUT/(p.stem+'.blp'))],check=True,capture_output=True)
report=dict(cloud_cases=cases,models=converted,textures=sorted(textures),missing_resources=missing)
(OUT/'cloud_validation.json').write_text(json.dumps(report,indent=2),encoding='utf-8')
print('PASS cloud table/placement/reference:',cases,'cases;',len(converted),'real models;',len(textures),'TEX textures converted;',len(missing),'missing local resources')
for path in missing:print('MISSING',path)
