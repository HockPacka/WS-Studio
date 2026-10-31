"""Read-only inventory of native class/spell data and deployed Spell.dbc placeholders."""
from pathlib import Path
import csv,struct,json,collections,re,hashlib
ROOT=Path(__file__).resolve().parents[2];OUT=ROOT/'build_wildstar/analysis/class_feasibility';OUT.mkdir(parents=True,exist_ok=True);DATA=ROOT/'WoWClient/tables_csv'
import sys
sys.path.insert(0,str(ROOT/'tools'))
from wildstar_spells.schema import spell_layout
LAYOUT=spell_layout(ROOT/'wowdecomp/WoW/Source/DB/Rec/SpellRec.h')
def field(r,name,index=0):return r[LAYOUT[name][0]+index]
def rows(name):return list(csv.DictReader(open(DATA/(name+'.csv'),encoding='utf-8-sig')))
def n(r,key):return int(r.get(key) or 0)
classes=rows('Class');spells=rows('Spell4');bases={n(r,'ID'):r for r in rows('Spell4Base')};effects=rows('Spell4Effects');byspell={n(r,'ID'):r for r in spells};expected={100000+n(r,'ID') for r in spells}
telegraphs=rows('Spell4Telegraph');teleids={n(r,'spell4Id') for r in telegraphs};effects_by=collections.defaultdict(list)
for r in effects:effects_by[n(r,'spellId')].append(r)
report=dict(native=dict(classes=len(classes),spell4=len(spells),spell4Base=len(bases),effectRows=len(effects),effectTypes=len({n(r,'effectType') for r in effects}),telegraphRows=len(telegraphs),telegraphSpells=len(teleids)),classes=[],deployed=[])
core=ROOT/'Repack AzerothCore NPCBots(2026)(Update 6.2)/Repack AzerothCore NPCBots'
for path in [ROOT/'WoWClient/WoWOverride/DBFilesClient/Spell.dbc',core/'Data/dbc/Spell.dbc']:
 raw=path.read_bytes();magic,count,fc,rs,ss=struct.unpack_from('<4s4I',raw);assert magic==b'WDBC' and(fc,rs)==(234,936)
 ids=collections.Counter();stats=collections.Counter();native_records={}
 for i in range(count):
  r=struct.unpack_from('<234I',raw,20+i*rs);ids[r[0]]+=1
  if r[0] not in expected:continue
  native_records[r[0]]=r
  for key,test in [('rangeZero',field(r,'m_rangeIndex')==0),('schoolZero',field(r,'m_schoolMask')==0),('physicalSchool',field(r,'m_schoolMask')==1),('durationZero',field(r,'m_durationIndex')==0),('visualZero',r[131]==r[132]==0),('iconZero',field(r,'m_spellIconID')==0),('targetsZero',not any(r[86:92])),('noResourceCost',r[42]==r[43]==r[44]==r[45]==0),('dummyOnly',r[71:74]==(0,0,3)),('fixedDamageThirdSlot',r[71:74]==(0,0,2) and r[82]==750)]:
   if test:stats[key]+=1
  stats['effect0_'+str(r[71])]+=1;stats['effect1_'+str(r[72])]+=1;stats['effect2_'+str(r[73])]+=1
 result=dict(path=str(path),sha256=hashlib.sha256(raw).hexdigest(),records=count,duplicates=sum(v-1 for v in ids.values()),nativeExpected=len(expected),nativePresent=len(native_records),missing=len(expected-set(native_records)),stats=dict(stats));report['deployed'].append(result)
for c in classes:
 cid=n(c,'ID');owned={i for i,b in bases.items() if n(b,'classIdPlayer')==cid};members=[s for s in spells if n(s,'spell4BaseIdBaseSpell') in owned];sids={n(s,'ID') for s in members};roots=[n(c,k) for k in c if k.startswith('spell4Id') and n(c,k)];root_ok=[i for i in roots if i in byspell]
 report['classes'].append(dict(id=cid,name=c['enumName'],rawClassTaggedBaseRows=len(owned),spell4Rows=len(members),roots=roots,missingRoots=sorted(set(roots)-set(root_ok)),effectRows=sum(len(effects_by[i]) for i in sids),effectTypes=sorted({n(e,'effectType') for i in sids for e in effects_by[i]}),telegraphSpellRows=len(sids&teleids),nonemptyBaseIcons=sum(bool(bases[i]['icon']) for i in owned),sourceGroupListId=n(c,'spell4GroupId')))
source=(ROOT/'NexusForever/Source/NexusForever.Game/Spell/SpellEffectHandler.cs').read_text();report['nexusReference']=dict(registeredHandlers=re.findall(r'\[SpellEffectHandler\(SpellEffectType\.(\w+)\)\]',source),note='Reference implementation only; not AzerothCore code and not evidence of complete combat behavior')
# Inspect the configured world database without writing to it.
try:
 import sys
 sys.path.insert(0,str(ROOT/'tools'))
 from ws_azerothcore_install import Server
 server=Server(core/'Core')
 script_rows=server.query('SELECT spell_id,ScriptName FROM spell_script_names WHERE spell_id BETWEEN 100000 AND 199999').splitlines()
 refs={}
 for tab,col in [('spell_script_names','spell_id'),('spell_proc','SpellId'),('spell_bonus_data','entry'),('spell_threat','entry'),('spell_dbc','ID')]:
  values=server.query('SELECT DISTINCT `'+col+'` FROM `'+tab+'` WHERE ABS(`'+col+'`) BETWEEN 100000 AND 199999')
  overlap=sorted({abs(int(v)) for v in values.splitlines() if abs(int(v)) in expected})
  refs[tab]=dict(intersections=overlap,count=len(overlap))
 report['server']=dict(nativeStartSpellRows=int(server.query('SELECT COUNT(*) FROM playercreateinfo_spell_custom WHERE racemask & 534773760 <> 0 AND spell BETWEEN 100000 AND 199999')),nativeRangeScriptRows=script_rows,nativeScriptMatches=[v for v in script_rows if abs(int(v.split('\t')[0])) in expected],idReferenceAudit=refs)
except Exception as e:
 report['server']=dict(available=False,error=str(e)[:200])
(OUT/'audit.json').write_text(json.dumps(report,indent=2),encoding='utf-8');print(json.dumps(dict(native=report['native'],deployed=report['deployed'],classes=report['classes']),indent=2))
