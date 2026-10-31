"""Stage native spell FX and combat-authoritative compatibility telegraph metadata.

Native visual phases/attachments are explicit compatibility mappings. No damage
logic or original TBL files are changed; unconvertible/conditional FX are omitted.
"""
import argparse,json,struct
from pathlib import Path
from ws_combat_starters import ROOT,digest
from ws_dbc_delta import Dbc,STRINGS,merge
from ws_content_output import ClientArchive
from ws_azerothcore_install import Server
from wildstar_spells.schema import read_tbl,f32

def lua(v):
    if v is None:return 'nil'
    if isinstance(v,bool):return str(v).lower()
    if isinstance(v,(float,int)):return repr(v)
    if isinstance(v,str):return json.dumps(v)
    if isinstance(v,list):return '{'+','.join(lua(x) for x in v)+'}'
    return '{'+','.join('['+lua(k)+']='+lua(x) for k,x in v.items())+'}'

# SpellVisualKit slots; muzzle/weapon mappings approximate native attachments.
ATTACH={8:4,9:5,12:5,15:3,16:7,44:7,46:4,51:7,84:6,85:7,187:7}
def phase_slot(v,e):
    if v['prerequisiteId'] or e['prerequisiteId'] or v['stageType'] not in (1,2):return None
    if e['visualType'] not in (5,6):return None
    if any(v[k] for k in ('modelOffsetX','modelOffsetY','modelOffsetZ')):return None
    if v['targetTypeFlags']==4:phase=3
    elif v['targetTypeFlags']==1:phase=1 if v['stageType']==1 else 2
    else:return None
    attachment=v['modelAttachmentIdCaster'] or e['modelAttachmentId']
    slot=ATTACH.get(attachment)
    return (phase,slot) if slot is not None else None

def build(client,core,out):
    client=Path(client).resolve();server=Server(core);out=Path(out).resolve()
    if out.exists() or any(p==out or p in out.parents for p in [client,server.core,server.data]):raise ValueError('choose new external output')
    receipt=json.loads((ROOT/'build_wildstar/deployments/combat-starters-live-20261029/installation.json').read_text())
    for f in receipt['files']:
        if Path(f['destination']).suffix=='.dbc' and digest(Path(f['destination']).read_bytes())!=f['after']:raise ValueError('starter DBC changed: '+f['destination'])
    starters=json.loads((ROOT/'build_wildstar/combat_starters_v2/manifest.json').read_text())['abilities']
    db=client/'ClientData/DB';tables={n:read_tbl(db/(n+'.tbl')) for n in ['Spell4','Spell4Telegraph','TelegraphDamage','Spell4VisualGroup','Spell4Visual','VisualEffect','ModelAttachment']};ix={n:t.index() for n,t in tables.items()}
    verdict={r['path']:r for r in json.loads((ROOT/'build_wildstar/analysis/starter_fx_conversion/report.json').read_text())}
    archive=ClientArchive(client/'Data');names=['Spell','SpellVisual','SpellVisualKit','SpellVisualEffectName']
    raw={};dbc={};indexed={}
    for n in names:
        path=client/'WoWOverride/DBFilesClient'/(n+'.dbc')
        raw[n]=path.read_bytes() if path.exists() else archive.get('DBFilesClient\\'+n+'.dbc')
        dbc[n]=Dbc(raw[n],n);indexed[n]={v[0]:v for r in dbc[n].rows for v in [dbc[n].decode(r)]}
    def generic(name):
        p=client/'WoWOverride/DBFilesClient'/(name+'.dbc');b=p.read_bytes() if p.exists() else archive.get('DBFilesClient\\'+name+'.dbc')
        _,count,fields,size,_=struct.unpack_from('<4s4I',b)
        return {struct.unpack_from('<I',b,20+i*size)[0]:b[20+i*size:20+(i+1)*size] for i in range(count)}
    radii=generic('SpellRadius');casttimes=generic('SpellCastTimes')
    patches={n:[] for n in names};meta={};effectRows={};audit=[];modelFiles={}
    for a in starters:
        native=a['nativeSpell'];sid=a['wowSpell'];s=ix['Spell4'][native];group=ix['Spell4VisualGroup'].get(s['spell4VisualGroupId'],{})
        original=indexed['Spell'][sid];spell=original[:];visual=indexed['SpellVisual'].get(spell[131],[0]*32)[:]
        newvisual=200000+native;visual[0]=newvisual;kits={};used=[];skipped=[]
        rawVisuals=[]
        for key,vid in group.items():
            if not key.startswith('spell4VisualId') or not vid:continue
            v=ix['Spell4Visual'][vid];e=ix['VisualEffect'].get(v['visualEffectId'])
            if not e:continue
            rawVisuals.append(dict(visual=v,effect=e))
            path=e['modelAssetPath'];selection=phase_slot(v,e)
            if not path:continue
            if not selection or not verdict.get(path,{}).get('ok'):
                skipped.append(dict(visual=vid,effect=e['ID'],reason='conditional/unsupported attachment or phase/failed model conversion'));continue
            phase,slot=selection
            actualCast=struct.unpack_from('<i',casttimes[spell[28]],4)[0] if spell[28] in casttimes else 0
            if phase==1 and actualCast<=0:phase=2
            scale=e['modelScale']*v['modelScale']
            if not .05<=scale<=5:
                skipped.append(dict(visual=vid,effect=e['ID'],reason='unreviewed scale'));continue
            if phase not in kits:
                old=indexed['SpellVisualKit'].get(visual[phase],[0]*38)
                kit=[0]*38;kit[0]=300000+native*3+phase
                # Keep cast animation and stock sound; omit script/proc fields.
                for col in (1,2,15,16):kit[col]=old[col]
                kits[phase]=kit
            kit=kits[phase]
            if kit[slot]:continue # first explicit raw entry per phase/attachment
            eid=200000+e['ID'];kit[slot]=eid
            row=[eid,'WildStar '+str(e['ID']),path,f32(0),f32(scale),f32(scale),f32(scale)]
            if eid in effectRows and effectRows[eid]!=row:
                # Same asset with a different per-spell scale needs its own ID.
                eid=400000+vid;row[0]=eid;kit[slot]=eid
            effectRows[eid]=row
            source=client/'ClientData'/Path(path.replace('\\','/'))
            modelFiles[path]=dict(path=path,sha256=digest(source.read_bytes()),offlineConvertible=True)
            used.append(dict(visual=vid,effect=e['ID'],phase=phase,slot=slot,attachment=e['modelAttachmentId'],path=path,scale=scale))
        # Never replace the existing visual if no native phase is supported.
        if used:
            for phase,kit in kits.items():
                visual[phase]=kit[0];patches['SpellVisualKit'].append(dict(key=[kit[0]],fields=kit,expected=None))
            spell[131]=newvisual
            patches['SpellVisual'].append(dict(key=[newvisual],fields=visual,expected=None))
            patches['Spell'].append(dict(key=[sid],fields=spell,expected=original))
        nativeTelegraphs=[ix['TelegraphDamage'][r['telegraphDamageId']] for r in tables['Spell4Telegraph'].rows if r['spell4Id']==native]
        radius=0
        for r in spell[92:95]:
            if r:
                vals=struct.unpack('<4I',radii[r]);radius=max(radius,struct.unpack('<f',struct.pack('<I',vals[1]))[0])
        heals=10 in spell[71:74] or 8 in spell[95:98]
        # Instant area -> caster circle; single-target -> target marker, not a
        # fake native cone that would promise hits outside the engine target.
        target='caster' if radius>0 or 1 in spell[86:89] else 'target'
        duration=struct.unpack_from('<i',casttimes[spell[28]],4)[0] if spell[28] in casttimes else 0
        meta[sid]=dict(name=a['name'],native=native,healing=heals,shape=0,length=radius if radius>0 else .8,width=radius if radius>0 else .8,
            anchor=target,castMs=max(0,duration),nativeTelegraphs=nativeTelegraphs,nativeFx=len(used),nativeAreaIsPreviewOnly=True)
        audit.append(dict(name=a['name'],native=native,wowSpell=sid,used=used,skipped=skipped,rawVisuals=rawVisuals,nativeTelegraphs=nativeTelegraphs))
    patches['SpellVisualEffectName']=[dict(key=[k],fields=v,expected=None) for k,v in sorted(effectRows.items())]
    out.mkdir(parents=True);(out/'deltas').mkdir();(out/'staged').mkdir();files=[]
    for name,records in patches.items():
        delta=dict(schemaVersion=1,table=name,fieldCount=dbc[name].fields,recordSize=dbc[name].size,stringColumns=sorted(STRINGS[name]),records=records,installable=True,adapter='wildstar-compatibility-visuals-v1')
        (out/'deltas'/(name+'.json')).write_text(json.dumps(delta),encoding='utf-8')
        destinations=[('client',client/'WoWOverride/DBFilesClient'/(name+'.dbc'))]
        if name=='Spell':destinations.append(('server',server.data/'dbc/Spell.dbc'))
        for label,dest in destinations:
            before=dest.read_bytes() if dest.exists() else archive.get('DBFilesClient\\'+name+'.dbc')
            after=merge(delta,before);staged=out/'staged'/(label+'-'+name+'.dbc');staged.write_bytes(after)
            files.append(dict(source=str(staged),destination=str(dest),before=digest(before) if dest.exists() else None,after=digest(after)))
    (out/'CombatVisualData.lua').write_text('WildStarCombatVisualData='+lua(meta)+'\n',encoding='utf-8')
    (out/'native-visuals.json').write_text(json.dumps(audit,indent=2),encoding='utf-8')
    result=dict(files=files,sourceHashes={n:t.sha256 for n,t in tables.items()},models=list(modelFiles.values()),abilities=30,
        nativeFxAbilities=sum(bool(r['used']) for r in audit),nativeFxBindings=sum(len(r['used']) for r in audit),telegraphAbilities=sum(bool(r['nativeTelegraphs']) for r in audit),
        limitations=['Visual phase/attachment mapping uses WoW compatibility kit slots, not recovered native dispatch.',
            'Conditions, nonzero offsets, unknown attachment slots, SkinFX/sound-only FX remain on stock fallback.',
            'Native cone/ring/rectangle preview is cosmetic; engine hit areas use compatibility circles/target markers.'])
    (out/'manifest.json').write_text(json.dumps(result,indent=2))
    print(json.dumps({k:v for k,v in result.items() if k in ['abilities','nativeFxAbilities','nativeFxBindings','telegraphAbilities']}))

if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--core',type=Path,required=True);ap.add_argument('--output',type=Path,required=True)
    ap.add_argument('--client',type=Path,default=ROOT/'WoWClient');a=ap.parse_args();build(a.client,a.core,a.output)
