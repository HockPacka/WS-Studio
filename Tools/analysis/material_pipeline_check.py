"""Regression for Argon's cobweb / Protostar material investigation.
Uses isolated Release tools; extracts stock shader bytecode from local MPQs.
"""
from pathlib import Path
import importlib.util,json,struct,subprocess,sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
from ws_content_output import ClientArchive
OUT=ROOT/'build_m3test/material_fx_probe'
BIN=ROOT/'wowdecomp/build/x64/bin/Release'
DATA=ROOT/'WoWClient/ClientData'

def run(*args):
    return subprocess.run([str(a) for a in args],cwd=ROOT,capture_output=True,text=True,check=True).stdout

def array(b,offset):return struct.unpack_from('<II',b,offset)

def main():
    OUT.mkdir(parents=True,exist_ok=True)
    archive=ClientArchive(ROOT/'WoWClient/Data')
    for stage,profile,name,perms in [('Vertex','vs_3_0','Diffuse_T1_T2',[30,31]),('Pixel','ps_3_0','Combiners_Opaque',[0]),('Pixel','ps_3_0','Combiners_Mod',[0])]:
        data=archive.get(f'Shaders\\{stage}\\{profile}\\{name}.bls');at=12;i=0
        while at<len(data):
            n=struct.unpack_from('<I',data,at+12)[0]
            if i in perms:(OUT/(name+'_'+str(i)+'.bin')).write_bytes(data[at+16:at+16+n])
            at+=16+((n+3)&~3);i+=1
    gpu=run(BIN/'material_pipeline_device_check.exe',OUT)
    print(gpu.strip())
    webs=sorted((DATA/'Art/Prop/Natural/Cobwebs').rglob('*.m3'))
    machines=[DATA/rel for rel in [
        'Art/Prop/Constructed/Generator/Protostar/PRP_Generator_ProtostarSolar_000.m3',
        'Art/Prop/Constructed/MISC/Protostar/PRP_Feeder_ProtostarCubig_000.m3']]
    sky=[DATA/rel for rel in [
        'Art/Sky/SkyBox/Dungeon/DataScape/Sky_Datascape_Air_Clouds_000.m3',
        'Art/Sky/SkyBox/Arcterra/Sky_Arcterra_Main_000.m3',
        'Art/Sky/SkyBox/Galeras/Sky_Galeras_CloudCover_000.m3',
        'Art/Sky/SkyBox/Halon_Ring/Sky_HalonRing_PlasmaField_000.m3',
        'Art/Sky/SkyBox/CrimsonIsle/Sky_CrimsonIsle_HexPattern_001.m3',
        'Art/Sky/SkyBox/CrimsonIsle/Sky_CrimsonIsle_HexPattern_003.m3',
        'Art/Sky/Glare/Sky_Glare_AdvancedSunGlare_White.m3']]
    report=[];fourLayerSky=[]
    for source in webs+sky+machines:
        target=OUT/(source.stem+'.m2');skinpath=target.with_suffix('.skin')
        run(BIN/'m3_to_m2_cli.exe',source,target,skinpath)
        b=target.read_bytes();skin=skinpath.read_bytes()
        nt,texat=array(b,0x50);nc,comboat=array(b,0x80);nm,matat=array(b,0x70);nb,batchat=array(skin,0x24)
        batches=[]
        for i in range(nb):
            batch=batchat+i*24
            shader=struct.unpack_from('<H',skin,batch+2)[0]
            mat=struct.unpack_from('<H',skin,batch+10)[0]
            flags,blend=struct.unpack_from('<HH',b,matat+mat*4)
            count,combo=struct.unpack_from('<HH',skin,batch+14)
            ids=struct.unpack_from('<8H',b,comboat+combo*2)
            if source in webs and blend:
                assert shader!=0,(source.name,i,'opaque combiner discards coverage')
            if shader&0x8880==0x8880:
                # Every populated layered colour must carry a filename; absent
                # layers use the dedicated white slot and may remain empty.
                for index in ids[:4]:
                    if index==nt-1:continue
                    length,offset=struct.unpack_from('<II',b,texat+index*16+8)
                    assert length>1 and offset<len(b),(source.name,i,index)
                if source in sky and ids[3]!=nt-1:
                    fourLayerSky.append(dict(model=source.name,batch=i,shader=hex(shader),textures=ids))
            batches.append(dict(shader=hex(shader),blend=blend,textures=ids))
        report.append(dict(model=str(source.relative_to(DATA)),batches=batches))
    star=next(r for r in report if r['model'].endswith('PRP_Cobweb_StarShape_SquareFit_000.m3'))
    assert star['batches'][0]['shader']=='0x1' and star['batches'][0]['blend']==3,star
    assert all(any(int(b['shader'],16)&0x8880==0x8880 for b in r['batches']) for r in report[-2:])
    assert fourLayerSky,'Datascape sky fixtures no longer exercise a fourth material layer'
    (OUT/'material_pipeline_report.json').write_text(json.dumps(dict(gpu=gpu,models=report,fourLayerSky=fourLayerSky),indent=2),encoding='utf-8')
    print(f'PASS {len(webs)} cobweb models, {len(machines)} Protostar machines and {len(sky)} sky models; four-layer sky batches={len(fourLayerSky)}')

if __name__=='__main__':main()
