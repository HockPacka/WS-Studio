"""Cross-check native SKY parsing/evaluation against raw Python decoding.

SH formulas independently transcribed from FUN_1401aefa0 / FUN_1401af0b0 /
FUN_1401af310 / FUN_1401af740. Also checks AREA corner weights through the
actual WoW world-coordinate query and synthetic cone/local-source cases.
"""
from pathlib import Path
import json, math, subprocess, sys
import numpy as np
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
from sky_reader import read_sky,sample_track,sample_resources,cell_sky_weights
from area_reader import read_area,read_chnk,split_cell
CLI=ROOT/'wowdecomp/build/x64/bin/Release/sky_cli.exe'

def basis(d):
    x,y,z=d
    return np.array([.2820948,-.48860252*y,.48860252*z,-.48860252*x,1.0925485*x*y,-1.0925485*y*z,.31539157*(3*z*z-1),-1.0925485*x*z,.54627424*(x*x-y*y)])

def direction(v):
    e,a=np.radians(v[:2]);return np.array([np.cos(a)*np.cos(e),np.sin(e),np.sin(a)*np.cos(e)])

def directional(color,d):
    return np.outer(color*2.956793,basis(d))

def angular(color,d,angle,normalize_cone):
    cs,sn=math.cos(angle),math.sin(angle)
    norm=math.sin(min(angle,1.0))**2 if normalize_cone else 1.0
    gains=np.array([1.7724539*(1-cs)]+[sn*sn*3.0699801*.5]*3+[(cs*cs-1)*cs*-3.9633274*.5]*5)
    x,y,z=d
    shape=np.array([1,-y,z,-x,8.6602545*x*y*.2,8.6602545*y*z*-.2,
                    z*z-x*x*.5-y*y*.5,8.6602545*x*z*-.2,8.6602545*(x*x-y*y)*.1])
    return np.outer(color/norm,gains)*shape

def cone(color,d,angle):
    return directional(color,d) if angle<.0001 else angular(color,d,angle,True)

def local_source(color,d,distance):
    length=np.linalg.norm(d)
    if length<=1e-12:return np.zeros((3,9))
    angle=math.acos(np.clip(distance/length,-1,1)) if distance<length else 1.0
    return angular(color,d/length,angle,False)

def sample(t,time):
    if not t['count'] or not t.get('sorted_times',True) or max(t['times'])>86400:return None
    return np.array(sample_track(t,time))

def reference(sky,time):
    out=[]
    for g in sky['groups'].values():
        sh=np.zeros((3,9));bands=np.zeros((16,3))
        for t in g['arrays']['0x8']:
            v=sample(t,time)
            if v is not None:sh[:,0]+=v[:3]*3.5449078
        for t in g['arrays']['0x18']:
            v=sample(t,time)
            if v is not None:sh+=directional(v[4:7],direction(v))
        for t in g['arrays']['0x28']:
            v=sample(t,time)
            if v is not None:
                d=direction(v);mean=(v[4:7]+v[8:11])*.5;delta=(v[4:7]-mean)*3.0699801
                sh[:,0]+=mean*5.317362;sh[:,1:4]+=np.outer(delta,[-d[1],d[2],-d[0]])
        for t in g['arrays']['0x38']:
            v=sample(t,time)
            if v is not None:sh+=cone(v[4:7],direction(v),v[8])
        for t in g['arrays']['0x48']:
            v=sample(t,time)
            if v is not None:sh+=local_source(v[4:7],direction(v)*v[9],v[8])
        for t in g['arrays']['0x58']+[g['sh_track']]:
            v=sample(t,time)
            if v is not None:sh+=v.reshape(3,9)
        v=sample(g['record_110_track'],time)
        if v is not None:bands=v[4:].reshape(16,4)[:,:3]
        out.append(dict(sh=sh.reshape(-1),bands=bands))
    return out

def run(*args,cwd=ROOT):
    return json.loads(subprocess.check_output([str(CLI),*map(str,args)],cwd=cwd,text=True))

files=['Ellevar_Main_005.sky','Ellevar_SZ_CreepyForest_001.sky','TestReference.sky','NorthernWilds_Main.sky','WhiteVale_Main.sky',
       'Adventure_Astrovoid.sky','Algoroc_Main05.sky','Flux_Dark.sky']
real_local_sources=0
cases=0
for name in files:
    p=ROOT/'WoWClient/ClientData/Sky'/name;s=read_sky(p.read_bytes())
    real_local_sources+=sum(t['count'] for g in s['groups'].values() for t in g['arrays']['0x48'])
    for time in (0,21600,43200,64800,86400):
        native=run(p,time)
        for ng,ref in zip(native['groups'],reference(s,time)):
            for field in ('sh','bands'):np.testing.assert_allclose(ng[field],ref[field],atol=3e-5,rtol=3e-5)
        expected_models=[]
        for m in s['models']:
            tr=m['track']
            if not tr['count'] or not tr['sorted_times'] or max(tr['times'])>86400:continue
            interval=sample_resources(dict(times=tr['times'],values=[[i] for i in range(tr['count'])]),time)
            v=sum(np.array(tr['values'][i])*w for i,w in interval)
            expected_models.append((m,v))
        assert len(native['models'])==len(expected_models)
        for got,(m,v) in zip(native['models'],expected_models):
            assert got['path']==m['path'].replace('\\','/') and got['flags']==m['header_words'][0]>>16
            np.testing.assert_allclose(got['angles'],v[:2],atol=3e-5,rtol=3e-5)
            np.testing.assert_allclose(got['color'],v[4:],atol=3e-5,rtol=3e-5)
        cloud=s['tracks']['0x310'];expected=sample_resources(cloud,time)
        assert len(native['clouds'])==len(expected)
        np.testing.assert_allclose(native['clouds'],expected,atol=1e-6)
        expected_alpha=sample(s['tracks']['0x328'],time)
        np.testing.assert_allclose(native['cloudAlpha'],1.0 if expected_alpha is None else expected_alpha[0],atol=1e-6)
        cases+=1
assert real_local_sources>0,'real Local-Source tracks were not covered'
print('PASS native SH, 16 color bands, cyclic model rotation/tint/alpha and CloudSet keys:',cases,'day-time samples;',real_local_sources,'real Local-Source tracks')

# Synthetic edge cases independently compare both angular SH projections.
native=run('--projections')
projection_cases=[(3,0.0,0.0),(3,.65,0.0),(3,1.4,0.0),
                  (4,1.0,2.0),(4,3.0,2.0),(4,1.0,.5)]
assert len(native)==len(projection_cases)
for got,(array,angle,scale) in zip(native,projection_cases):
    color=np.array([1.,.5,.25]);unit=direction([20,30])
    expected=cone(color,unit,angle) if array==3 else local_source(color,unit*scale,angle)
    np.testing.assert_allclose(np.array(got['sh']).reshape(3,9),expected,atol=3e-5,rtol=3e-5)
print('PASS independent Cone/Local-Source projection edge cases:',len(native))

# AREA reader is intentionally independent of the native coordinate query.
tile=read_area((ROOT/'WoWClient/ClientData/Map/Western/Western.393b.area').read_bytes())
cells={}
for name,size,data,pos in tile['chunks']:
    if name in ('CHNK','KNHC'):
        for index,flags,raw in read_chnk(data,tile['compressed']):
            if index>=0:cells[index]=split_cell(raw)[1]
queries=0
for cx,cy,u,v in [(0,0,.5,.5),(3,7,.2,.8),(15,15,.5,.5),(8,4,.9,.1),(7,4,.001,.6),(7,4,.999,.6)]:
    blocks=cells[(15-cx)+16*(15-cy)]
    expected=cell_sky_weights(blocks[6],blocks[7],u,v)
    total=sum(w for _,w in expected);expected={i:w/total for i,w in expected}
    wx=17066.6666666667-(6*16+cy+1-v)*(100/3)
    wy=17066.6666666667-(4*16+cx+1-u)*(100/3)
    got=run('--query','WS_Western',wx,wy,43200,cwd=ROOT/'WoWClient')
    assert got['active'] and set(i for i,w in got['weights'])==set(expected),(got,expected)
    for i,w in got['weights']:assert abs(w-expected[i])<.0001,(got,expected)
    queries+=1
assert run('--query','Azeroth',0,0,43200,cwd=ROOT/'WoWClient')=={'active':False,'weights':[]}
assert not run('--query','WS_Western',1e9,1e9,43200,cwd=ROOT/'WoWClient')['active']
print('PASS native AREA-to-world coordinate queries:',queries,'positions + ordinary-map/out-of-map fallback')
