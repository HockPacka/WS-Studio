"""Stage a separately approved WoW compatibility starter set. Never installs the catalog.

Each native ability is explicitly paired with an engine template. Native raw
records and effect sets are evidence, NOT advertised as implemented mechanics.
No native proxy execution or Lua combat damage is involved.
"""
import argparse, hashlib, json, shutil
from pathlib import Path
from wildstar_spells.schema import read_tbl, spell_layout, u32
from ws_dbc_delta import Dbc, STRINGS, merge
from ws_content_output import ClientArchive
from ws_azerothcore_install import Server
from ws_combat_data import lua

ROOT=Path(__file__).resolve().parents[1]
POLICY=ROOT/'plugins/wildstar335a/data/compatibility_starters.json'
ALLOWED_EFFECTS={0,2,6,10,68,114,121,138}
LOSSES=[
 'WoW template effect amounts, cast times, durations, targeting and visuals replace native effects.',
 'Five starter abilities per class; no complete native ability book, tiers, AMP tree or progression.',
 'Mana replaces native caster resources; Warrior uses Rage and Stalker Energy.',
 'Physical=WoW physical, Tech=Nature, Magic=Arcane, healing=Holy (compatibility mapping).',
 'No native telegraph, charge stages, combo stages, bot AI, interrupts armor or Spell Surge.',
 'Native profile ratings/action set remain separate diagnostic data, not engine combat ratings.',
 'Underlying WoW carrier classes and their existing spells/talents remain available.',
]
def digest(b):return hashlib.sha256(b).hexdigest()
def finish_assets(out):
    out=Path(out);patch=json.loads((out/'deltas/SpellIcon.json').read_text())
    files=[]
    for entry in patch['records']:
        relative=Path(entry['fields'][1].replace('\\','/'))
        if relative.suffix.lower()!='.tga':relative=relative.with_suffix('.tga')
        source=ROOT/'build_wildstar/spells_phase1_v3/catalog/assets'/relative
        dest=out/'assets'/relative;dest.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(source,dest)
        files.append(dict(relative=str(relative),sha256=digest(dest.read_bytes())))
    manifest=json.loads((out/'manifest.json').read_text());manifest['assets']=files;manifest['complete']=True
    (out/'manifest.json').write_text(json.dumps(manifest,indent=2),encoding='utf-8')
def delta(name,db,rows):
    return dict(schemaVersion=1,table=name,fieldCount=db.fields,recordSize=db.size,
        stringColumns=sorted(STRINGS[name]),installable=True,
        adapter='wow-compatibility-starters-v1',records=[dict(key=[v[0]],fields=v,expected=None) for v in rows])

def adapt(row,layout,cost,power,cooldown,school,name,template_name):
    r=row[:]
    def put(key,value):
        start,n=layout[key];r[start:start+n]=value if isinstance(value,list) else [u32(value)]*n
    # Isolate these spells from carrier-family talents, rank chains and stance gates.
    for key in ['m_category','m_categoryRecoveryTime','m_shapeshiftMask','m_shapeshiftExclude',
        'm_spellClassSet','m_spellClassMask','m_effectSpellClassMaskA','m_effectSpellClassMaskB',
        'm_effectSpellClassMaskC','m_manaCostPerLevel','m_manaPerSecond','m_manaPerSecondPerLevel',
        'm_requiredAreasID','m_requiredTotemCategoryID','m_totem','m_reagent','m_reagentCount',
        'm_runeCostID','m_powerDisplayID','m_equippedItemSubclass','m_equippedItemInvTypes']:
        put(key,0)
    put('m_equippedItemClass',-1)
    put('m_powerType',power);put('m_manaCost',cost if power else 0)
    put('m_manaCostPct',cost if power==0 else 0)
    put('m_recoveryTime',cooldown);put('m_startRecoveryCategory',133);put('m_startRecoveryTime',1500)
    put('m_spellLevel',1);put('m_baseLevel',1)
    # DUMMY effects rely on template-specific scripts. Combo points belong to
    # the WoW Rogue system, not the native Stalker/Warrior starter set.
    for i in range(3):
        e=layout['m_effect'][0]+i
        if r[e] in (3,80):
            for key in ['m_effect','m_effectDieSides','m_effectRealPointsPerLevel','m_effectBasePoints',
                'm_effectMechanic','m_implicitTargetA','m_implicitTargetB','m_effectRadiusIndex',
                'm_effectAura','m_effectAuraPeriod','m_effectAmplitude','m_effectChainTargets',
                'm_effectItemType','m_effectMiscValue','m_effectMiscValueB','m_effectTriggerSpell',
                'm_effectPointsPerCombo','m_effectBonusCoefficient']:
                r[layout[key][0]+i]=0
    effects=r[layout['m_effect'][0]:layout['m_effect'][0]+3]
    if not any(effects) or set(effects)-ALLOWED_EFFECTS:raise ValueError('unsupported engine template effects')
    if any(r[layout['m_effectTriggerSpell'][0]:layout['m_effectTriggerSpell'][0]+3]):raise ValueError('unreviewed triggered dependency')
    heals=10 in effects or any(r[layout['m_effectAura'][0]+i]==8 for i in range(3))
    put('m_schoolMask',2 if heals else school)
    put('m_name',[name]*16+[65535]);put('m_nameSubtext',['Compatibility']*16+[65535])
    text=('WoW compatibility mode: '+template_name+' mechanics. Original WildStar effects, resources, '
          'telegraphs and progression are not reproduced. See /wsabilities.')
    put('m_description',[text]*16+[65535]);put('m_auraDescription',['']*16+[65535])
    # Copied descriptions would refer to the template's spell ID or other ranks.
    put('m_descriptionVariablesID',0)
    return r

def build(client,core,out):
    client=Path(client).resolve();out=Path(out).resolve();server=Server(core)
    if out.exists() or client in out.parents or server.core in out.parents or server.data in out.parents:
        raise ValueError('choose a new staging folder outside client/server')
    policy=json.loads(POLICY.read_text());ids=json.loads((ROOT/'plugins/wildstar335a/data/spell_ids.json').read_text())
    archive=ClientArchive(client/'Data');dbpath=client/'ClientData/DB'
    nt={n:read_tbl(dbpath/(n+'.tbl')) for n in ['Spell4','Spell4Base','Spell4Effects']}
    spells=nt['Spell4'].index();bases=nt['Spell4Base'].index()
    layout=spell_layout(ROOT/'wowdecomp/WoW/Source/DB/Rec/SpellRec.h')
    stock={n:Dbc(archive.get('DBFilesClient\\'+n+'.dbc'),n) for n in ['Spell','SpellIcon','SkillLineAbility']}
    sr={v[0]:v for raw in stock['Spell'].rows for v in [stock['Spell'].decode(raw)]}
    skills=[stock['SkillLineAbility'].decode(r) for r in stock['SkillLineAbility'].rows]
    icons=json.loads((ROOT/'build_wildstar/spells_phase1_v3/icons.json').read_text())['resolved']
    iconmap=ids['tables']['SpellIcon'];rows={n:[] for n in stock};manifest=[];usedicons=set();classdata={}
    raceMask=sum(1<<(i-1) for i in range(22,30))
    for c in policy['classes']:
        cid=c['id'];classdata[cid]=dict(name=c['name'],carrier=c['carrier'],abilities={})
        for native,template,cost,cooldown,expectedName in c['abilities']:
            s=spells[native];b=bases[s['spell4BaseIdBaseSpell']]
            if b['classIdPlayer']!=cid or s['tierIndex']!=1 or any(x in s['description'].lower() for x in ['deprecated','[dep]','[test]']):
                raise ValueError('invalid starter selection: '+str(native))
            r=sr[template];r=adapt(r,layout,cost,c['power'],cooldown,c['school'],expectedName,sr[template][136])
            r[0]=ids['tables']['Spell'][str(native)]
            iconkey=b['icon'];icon=icons.get(iconkey)
            if not icon:raise ValueError('native icon missing '+iconkey)
            iconid=iconmap[iconkey];r[133]=iconid
            if iconid not in usedicons:rows['SpellIcon'].append([iconid,icon['texture']]);usedicons.add(iconid)
            rows['Spell'].append(r)
            # Explicit mapping to the already-existing carrier's spellbook tab.
            skill=next(v[:] for v in skills if v[2]==c['skillRoot'])
            skill[0]=10000000+native;skill[2]=r[0];skill[3]=raceMask;skill[4]=1<<(c['carrier']-1)
            skill[5:14]=[0,0,0,0,0,0,0,0,0];rows['SkillLineAbility'].append(skill)
            entry=dict(nativeClass=cid,nativeSpell=native,nativeBase=b['ID'],wowSpell=r[0],name=expectedName,
                nativeDescription=s['description'],template=template,templateName=sr[template][136],
                engineEffects=r[71:74],engineSchool=r[225],cost=cost,costMode='percent base mana' if c['power']==0 else ('rage internal units' if c['power']==1 else 'energy'),
                cooldownMs=cooldown,learnLevel=1,mode=policy['mode'],nativeMechanicsImplemented=False,
                nativeEffectIds=[e['ID'] for e in nt['Spell4Effects'].rows if e['spellId']==native])
            manifest.append(entry);abilities=classdata[cid]['abilities']
            abilities[len(abilities)+1]=dict(id=r[0],name=expectedName,template=entry['templateName'],native=native)
    # Full read-only namespace audit, including SQL references, before staging.
    from wildstar_spells.reservations import snapshot
    reservation=snapshot(client,core)
    if set(e['wowSpell'] for e in manifest)&set(reservation['tables']['Spell']):raise ValueError('spell namespace collision')
    out.mkdir(parents=True);(out/'deltas').mkdir();(out/'staged').mkdir();files=[]
    for name,values in rows.items():
        patch=delta(name,stock[name],values)
        (out/'deltas'/(name+'.json')).write_text(json.dumps(patch,ensure_ascii=False),encoding='utf-8')
        for label,destination in [('client',client/'WoWOverride/DBFilesClient'/(name+'.dbc')),('server',server.data/'dbc'/(name+'.dbc'))]:
            raw=destination.read_bytes() if destination.is_file() else archive.get('DBFilesClient\\'+name+'.dbc')
            staged=out/'staged'/(label+'-'+name+'.dbc');new=merge(patch,raw);staged.write_bytes(new)
            files.append(dict(destination=str(destination),staged=str(staged),before=digest(raw) if destination.exists() else None,after=digest(new)))
    (out/'StarterData.data').write_text('return '+lua(dict(mode=policy['mode'],classes=classdata))+'\n',encoding='utf-8')
    (out/'reservation.json').write_text(json.dumps(reservation),encoding='utf-8')
    receipt=dict(version=1,mode=policy['mode'],abilities=manifest,losses=LOSSES,files=files,
        sourceHashes={n:t.sha256 for n,t in nt.items()},policyHash=digest(POLICY.read_bytes()))
    (out/'manifest.json').write_text(json.dumps(receipt,indent=2),encoding='utf-8')
    finish_assets(out)
    print(json.dumps(dict(classes=len(classdata),abilities=len(manifest),files=len(files),output=str(out))))
    return receipt

if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--client',type=Path,default=ROOT/'WoWClient')
    ap.add_argument('--core',type=Path,required=True);ap.add_argument('--output',type=Path,required=True)
    a=ap.parse_args();build(a.client,a.core,a.output)
