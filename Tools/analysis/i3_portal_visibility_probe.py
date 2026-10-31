"""Audit native portal shapes and replay the WMO client's batch dispatch rules.
No client/server assets are changed. Existing generated WMO fixtures are inputs.
"""
from pathlib import Path
from collections import Counter
import json,struct,sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
from i3_reader import parse_idef
from wmo_check import chunks
OUT=ROOT/'build_m3test/i3_portal_probe'

def native_shapes():
    models=json.loads((OUT/'inventory.json').read_text())
    counts=Counter();affected=[]
    for model in models:
        if not model['portalsRaw']:continue
        b=(ROOT/'WoWClient/ClientData'/model['path']).read_bytes()
        n,_,off=struct.unpack_from('<IIQ',b,0x30);base=0x170+off
        shapes=[]
        for i in range(n):
            r=base+i*0x90;nv=struct.unpack_from('<I',b,r+0x40)[0];ni=struct.unpack_from('<I',b,r+0x50)[0]
            counts[(nv,ni)]+=1;shapes.append([nv,ni])
        if any(pair!=[4,6] for pair in shapes):affected.append(dict(path=model['path'],shapes=shapes))
    return dict(rawShapeCounts={f'{v} vertices / {i} indices':n for (v,i),n in sorted(counts.items())},modelsWithUnsupportedShapes=affected)

def generated(prefix):
    root=Path(str(prefix)+'.wmo').read_bytes();rc={tag:(offset,size) for tag,offset,size in chunks(root)}
    root_flags=struct.unpack_from('<H',root,rc['MOHD'][0]+0x3c)[0]
    np=rc['MOPT'][1]//20;nr=rc['MOPR'][1]//8
    groups=[]
    for path in sorted(prefix.parent.glob(prefix.name+'_*.wmo')):
        b=path.read_bytes();top=chunks(b);header=top[1][1]
        flags=struct.unpack_from('<I',b,header+8)[0]
        sub={tag:(offset,size) for tag,offset,size in chunks(b,header+0x44)}
        trans,nint,next_=struct.unpack_from('<3H',b,header+0x28)
        batches=sub['MOBA'][1]//24;has_colors='MOCV' in sub
        # CMapObj::RenderGroup chooses InteriorRender only if m_colorVertexList
        # exists. ExteriorRender delegates to UnifiedRender only for MOHD flag 2.
        dispatch='UnifiedRender' if root_flags&2 else ('InteriorRender' if has_colors else 'ExteriorRender')
        drawn=batches if root_flags&2 or has_colors else next_
        groups.append(dict(file=path.name,flags=hex(flags),portalRange=struct.unpack_from('<2H',b,header+0x24),
            batches=batches,interiorBatches=nint,exteriorBatches=next_,vertexColors=has_colors,
            renderer=dispatch,drawLoopCount=drawn,invisibleByDispatch=batches>0 and drawn==0))
    return dict(prefix=prefix.name,rootFlags=hex(root_flags),portals=np,references=nr,groups=groups)

def main():
    fixed='--fixed' in sys.argv
    names=('pell_small_fixed','church_fixed') if fixed else ('pell_small','church')
    report=dict(native=native_shapes(),generated=[generated(OUT/name) for name in names])
    (OUT/('fixed_visibility_report.json' if fixed else 'visibility_report.json')).write_text(json.dumps(report,indent=2),encoding='utf-8')
    print('Native portal shapes:',report['native']['rawShapeCounts'])
    print('Models with shapes discarded by original quad-only reader:',len(report['native']['modelsWithUnsupportedShapes']))
    for r in report['generated']:
        print(r['prefix'],'root flags',r['rootFlags'],'groups',len(r['groups']),
              'invisible groups',sum(g['invisibleByDispatch'] for g in r['groups']))
        for g in r['groups']:
            print(' ',g['file'],g['flags'],'batches',g['batches'],'int',g['interiorBatches'],'ext',g['exteriorBatches'],g['renderer'],'draws',g['drawLoopCount'])
    if fixed:
        for r in report['generated']:
            assert r['rootFlags']=='0x2',r
            assert not any(g['invisibleByDispatch'] for g in r['groups']),r
            assert any(int(g['flags'],16)&0x2000 for g in r['groups']),r
            assert r['portals'] and r['references'],r
        print('PASS: both structures retain indoor groups and draw all populated groups')
if __name__=='__main__':main()
