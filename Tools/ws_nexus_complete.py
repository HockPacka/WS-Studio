"""Complete missing NexusForever NPC placements through the AzerothCore adapter.
Read-only planning by default. --apply requires the reviewed plan and backs up touched tables.
Native IDs are retained in a separate registry; existing placements are matched, never recreated.
"""
from pathlib import Path
import sys,csv,json,math,collections,hashlib,argparse,subprocess,os
from datetime import datetime,timezone
ROOT=Path(__file__).resolve().parents[1];sys.path.insert(0,str(ROOT/'tools'))
from ws_azerothcore_install import Server
import ws_spawns,ws_text
from ws_npc_patch import model_list
from ws_map_setup import Dbc

def table(name):
 return {int(r['ID']):r for r in csv.DictReader(open(ROOT/'WoWClient/tables_csv'/(name+'.csv'),encoding='utf-8-sig'))}
def integer(r,k):return int(r.get(k) or 0)
def sqltext(s):return "'"+str(s).replace('\\','\\\\').replace("'","''")+"'"
def main():
 ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--server',required=True);ap.add_argument('--output',type=Path,default=ROOT/'build_wildstar/deployments/nexus-completion-20261028');ap.add_argument('--apply',action='store_true');a=ap.parse_args();out=a.output;out.mkdir(parents=True,exist_ok=True);s=Server(a.server)
 if (out/'installed.json').is_file():
  count=s.query('SELECT COUNT(*) FROM wildstar_nexus_spawn n JOIN creature c ON c.guid=n.spawn_guid AND c.id=4100000+n.native_creature')
  if count!='16940':raise ValueError('Installed Nexus spawn registry differs from live creatures; inspect before changing anything')
  print('Already installed: 16940 verified NPC placements; no changes.');return
 ct,di,mi,races,outfits,types,items,worlds,factions=[table(n) for n in ['Creature2','Creature2DisplayInfo','Creature2ModelInfo','Race','Creature2OutfitInfo','Item2Type','ItemDisplay','World','Faction2']]
 slots={i:integer(types.get(integer(r,'item2TypeId'),{}),'itemSlotId') for i,r in items.items()}
 paths=model_list(str(ROOT/'WoWClient'));baseids={p.lower():200000+i for i,p in enumerate(paths)}
 # Verify actual installed server AND client DBC rows, not a newly sorted hypothetical ID range.
 valid=[]
 for root in [s.data/'dbc',ROOT/'WoWClient/WoWOverride/DBFilesClient']:
  dd=Dbc(root/'CreatureDisplayInfo.dbc');md=Dbc(root/'CreatureModelData.dbc');mrs={r[0]:r for r in md.recs};lookup={}
  for r in dd.recs:
   m=mrs.get(r[1]);
   if m:
    off=m[2];end=md.strings.find(0,off);name=md.strings[off:end].decode('utf-8','replace').lower();lookup[r[0]]=name
  valid.append(lookup)
 rows=s.query('SELECT guid,id,map,CAST(position_x AS DECIMAL(20,5)),CAST(position_y AS DECIMAL(20,5)),CAST(position_z AS DECIMAL(20,5)) FROM creature WHERE id>=4100000 AND id<4500000')
 existing=collections.defaultdict(list)
 for line in rows.splitlines():
  g,e,m,x,y,z=line.split('\t');existing[int(e),int(m)].append((int(g),float(x),float(y),float(z)))
 used=set();maxguid=int(s.query('SELECT COALESCE(MAX(guid),4100000) FROM creature WHERE guid BETWEEN 4100000 AND 4199999'))
 templates={int(r.split('\t')[0]):r.split('\t')[1] for r in s.query('SELECT entry,subname FROM creature_template WHERE entry BETWEEN 4100000 AND 4499999').splitlines()}
 windows={(w['map'],w['bb']//64,w['aa']//64):w['id'] for w in json.loads((ROOT/'build_wildstar/generated/map_links.json').read_text())['windows']}
 texts=ws_text.load(str(ROOT/'WoWClient/ClientDataEN/en-US.bin'))
 plan=[];skipped=[];newtemplates={};counters=collections.Counter()
 for file,world,entities in ws_spawns.parse_db(str(ROOT/'NexusForever.WorldDatabase')):
  for ordinal,r in enumerate(entities):
   kind,cid,area,x,y,z,rx,ry,rz,display,outfit,f1,f2,stats=r
   if kind!=0:continue
   entry=4100000+cid;name=Path(worlds.get(world,{}).get('assetPath','').replace('\\','/')).name
   wx=int(math.floor(x/32768+1));wy=int(math.floor(z/32768+1));mid=windows.get((name,wx,wy))
   if mid is None:skipped.append(dict(creature=cid,reason='unregistered map window',world=world));continue
   px=17066.666+ws_spawns.K_SCALE*(z-32768*wy);py=17066.666+ws_spawns.K_SCALE*(x-32768*wx);pz=1600+ws_spawns.K_SCALE*y
   key=str(Path(file).relative_to(ROOT/'NexusForever.WorldDatabase')).replace('\\','/')+':'+str(ordinal)
   matches=[v for v in existing[entry,mid] if v[0] not in used and max(abs(v[1]-px),abs(v[2]-py),abs(v[3]-pz))<.025]
   if matches:
    guid=min(matches,key=lambda v:sum((v[k+1]-q)**2 for k,q in enumerate([px,py,pz])))[0];used.add(guid);new=False;profile=None;base=None
   else:
    row=di.get(display);source_kind='d'
    if not row:row=mi.get(integer(ct.get(cid,{}),'creature2ModelInfoId'));source_kind='i'
    if not row:skipped.append(dict(creature=cid,reason='missing native display/model row'));continue
    native=integer(row,'raceId' if source_kind=='d' else 'race');sex=integer(row,'sex')
    path=row.get('assetPath') or races.get(native,{}).get('femaleAssetPath' if sex else 'maleAssetPath','')
    base=baseids.get(path.lower())
    if base is None:skipped.append(dict(creature=cid,reason='missing native base asset',display=display,race=native,path=path));continue
    for lookup in valid:
     if lookup.get(base)!='ws\\'+path.lower():raise ValueError('Installed display/model ID mismatch: '+str(base))
    picked={}
    for k in range(20):
     it=integer(row,'itemDisplayId%02d'%k)
     if it and slots.get(it):picked[slots[it]]=it
    for k in range(6):
     it=integer(outfits.get(outfit,{}),'itemDisplayId%02d'%k)
     if it and slots.get(it):picked[slots[it]]=it
    omitted=[]
    suffix=Path(path.replace('\\','/')).stem
    for slot,it in list(picked.items()):
     model=items[it].get('skinnedModel')
     if not model:continue
     original=ROOT/'WoWClient/ClientData'/model
     candidate=original.with_name(original.stem+'_'+suffix+original.suffix)
     if original.is_file() or candidate.is_file():continue
     if len(list(original.parent.glob(original.stem+'_*')))==1:continue
     if slot>=24:raise ValueError('Missing mandatory body component '+str(it)+' '+suffix)
     omitted.append(it);del picked[slot]
    equipment=[picked[k] for k in sorted(picked)]
    if not equipment:raise ValueError('Unresolved nonhumanoid missing spawn '+key)
    if len(equipment)>20:raise ValueError('Too many components '+key)
    fields=[1,base,0,sex]+[0]*10
    profile=','.join(map(str,fields))+';;'+','.join(map(str,equipment))
    maxguid+=1;guid=maxguid;new=True
    if guid>=4200000:raise ValueError('Spawn namespace exhausted')
    if entry not in templates:
     c=ct[cid];nm=texts.get(integer(c,'localizedTextIdName'),'').strip() or c.get('description') or 'WS '+str(cid)
     newtemplates.setdefault(entry,dict(name=nm[:100],base=base,level=max(1,min(80,int(stats.get(10,1)))),faction=ws_spawns.faction_of(texts.get(integer(factions.get(f1,{}),'localizedTextIdName'),'')),scale=float(c.get('modelScale') or 1)*float(row.get('scale') or 1)))
    elif templates[entry]!='WildStar':raise ValueError('Template namespace collision '+str(entry))
   record=dict(source_key=key,guid=guid,entry=entry,world=world,area=area,creature=cid,display=display,outfit=outfit,map=mid,x=round(px,3),y=round(py,3),z=round(pz,3),orientation=round(rx%(2*math.pi),4),new=new,base=base,descriptor=profile,omitted_items=omitted if new else [])
   plan.append(record);counters['new' if new else 'existing']+=1
 if counters['existing']!=sum(map(len,existing.values())):raise ValueError('Some existing WildStar spawns do not match the source: '+str(counters))
 report=dict(counts=dict(counters),templates=len(newtemplates),skipped=skipped,uniqueProfiles=len({r['descriptor'] for r in plan if r['new']}),omittedComponentOccurrences=sum(len(r['omitted_items']) for r in plan),affectedSpawns=sum(bool(r['omitted_items']) for r in plan),maps=dict(collections.Counter(r['map'] for r in plan if r['new'])))
 (out/'plan.json').write_text(json.dumps(dict(report=report,templates=newtemplates,spawns=plan),indent=2),encoding='utf-8');print(json.dumps(report,indent=2))
 if skipped:raise ValueError('Unresolved NPCs remain; refusing partial deployment')
 new=[r for r in plan if r['new']];assert len(new)==4601, 'Re-review changed completion count'
 newbases=sorted({r['base'] for r in new});knownmodels={int(x) for x in s.query('SELECT DisplayID FROM creature_model_info WHERE DisplayID IN ('+','.join(map(str,newbases))+')').splitlines()};missingmodels=sorted(set(newbases)-knownmodels)
 statements=['START TRANSACTION;']
 for entry,t in sorted(newtemplates.items()):
  statements.append("INSERT INTO creature_template (entry,name,subname,minlevel,maxlevel,faction,unit_class,type,speed_walk,speed_run) VALUES (%d,%s,'WildStar',%d,%d,%d,1,7,1,1.14286);"%(entry,sqltext(t['name']),t['level'],t['level'],t['faction']))
  statements.append('INSERT INTO creature_template_model (CreatureID,Idx,CreatureDisplayID,DisplayScale,Probability) VALUES (%d,0,%d,%.5f,1);'%(entry,t['base'],t['scale']))
 for did in missingmodels:statements.append('INSERT INTO creature_model_info (DisplayID,BoundingRadius,CombatReach,Gender,DisplayID_Other_Gender,VerifiedBuild) VALUES (%d,.5,1.5,2,0,0);'%did)
 for r in new:
  statements.append("INSERT INTO creature (guid,id,map,spawnMask,phaseMask,position_x,position_y,position_z,orientation,spawntimesecs,MovementType,Comment) VALUES (%d,%d,%d,1,1,%.3f,%.3f,%.3f,%.4f,300,0,%s);"%(r['guid'],r['entry'],r['map'],r['x'],r['y'],r['z'],r['orientation'],sqltext('WildStar NexusDB '+r['source_key'])))
  statements.append('INSERT INTO wildstar_appearance_profile (owner_type,owner_id,base_display,original_display,descriptor) VALUES (\'C\',%d,%d,%d,%s);'%(r['guid'],r['base'],r['base'],sqltext(r['descriptor'])))
 for r in plan:
  statements.append('INSERT INTO wildstar_nexus_spawn (source_key,spawn_guid,native_creature,native_world,native_area,native_display,native_outfit) VALUES (%s,%d,%d,%d,%d,%d,%d);'%(sqltext(r['source_key']),r['guid'],r['creature'],r['world'],r['area'],r['display'],r['outfit']))
 # Batch rows by INSERT prefix instead of issuing tens of thousands of round trips.
 grouped={}
 for statement in statements[1:]:
  prefix,values=statement.split(' VALUES ',1);grouped.setdefault(prefix,[]).append(values[:-1])
 batches=['START TRANSACTION;']
 for prefix,values in grouped.items():
  for start in range(0,len(values),500):batches.append(prefix+' VALUES '+',\n'.join(values[start:start+500])+';')
 batches.append('COMMIT;');sql='\n'.join(batches)+'\n';(out/'install.world.sql').write_text(sql,encoding='utf-8')
 rollback=['START TRANSACTION;','DELETE FROM wildstar_nexus_spawn WHERE source_key IN ('+','.join(sqltext(r['source_key']) for r in plan)+');','DELETE FROM wildstar_appearance_profile WHERE owner_type=\'C\' AND owner_id IN ('+','.join(str(r['guid']) for r in new)+');','DELETE FROM creature WHERE guid IN ('+','.join(str(r['guid']) for r in new)+');']
 if newtemplates:
  ids=','.join(map(str,newtemplates));rollback+=['DELETE FROM creature_template_model WHERE CreatureID IN ('+ids+');','DELETE FROM creature_template WHERE entry IN ('+ids+");"]
 if missingmodels:rollback+=['DELETE FROM creature_model_info WHERE DisplayID IN ('+','.join(map(str,missingmodels))+');']
 rollback+=['COMMIT;'];(out/'rollback.world.sql').write_text('\n'.join(rollback),encoding='utf-8')
 if not a.apply:return
 expected={r['descriptor'] for r in new}
 prepared={line.split('\t',1)[1] for line in (out/'profiles.tsv').read_text().splitlines()}
 if expected!=prepared:raise ValueError('Profile preflight inputs do not match the current plan')
 checked=0
 for n in range(4):
  log=(out/f'profile_preflight_{n}.log').read_text().splitlines()
  results=[line.split('\t') for line in log if line.startswith('RESULT\t')]
  if len(results)!=1 or int(results[0][2])!=0:raise ValueError('Native component validation has not passed')
  checked+=int(results[0][1])
 if checked!=len(expected):raise ValueError('Native component validation count differs')
 registry_exists=s.query("SELECT COUNT(*) FROM information_schema.TABLES WHERE TABLE_SCHEMA=DATABASE() AND TABLE_NAME='wildstar_nexus_spawn'")!='0'
 if registry_exists:
  if not (out/'before.sql').is_file() or s.query('SELECT COUNT(*) FROM wildstar_nexus_spawn')!='0':raise ValueError('Already deployed/unowned registry; refusing second installation')
  columns=s.query("SELECT COLUMN_NAME FROM information_schema.COLUMNS WHERE TABLE_SCHEMA=DATABASE() AND TABLE_NAME='wildstar_nexus_spawn'")
  if set(columns.splitlines())!={'source_key','spawn_guid','native_creature','native_world','native_area','native_display','native_outfit'}:raise ValueError('Registry schema mismatch')
 backup=out/'before.sql'
 if backup.exists():backup=out/('before-retry-'+datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'.sql')
 with backup.open('xb') as f:
  r=subprocess.run([str(s.bin/'mysqldump.exe'),*s.args,'--single-transaction','--skip-lock-tables','--set-gtid-purged=OFF','--column-statistics=0',s.database,'creature','creature_template','creature_template_model','creature_model_info','wildstar_appearance_profile'],stdout=f,stderr=subprocess.PIPE,env=s.env,timeout=180)
 if r.returncode:raise RuntimeError(r.stderr.decode(errors='replace'))
 s.query('CREATE TABLE IF NOT EXISTS wildstar_nexus_spawn (source_key varchar(255) NOT NULL PRIMARY KEY,spawn_guid int unsigned NOT NULL UNIQUE,native_creature int unsigned NOT NULL,native_world int unsigned NOT NULL,native_area int unsigned NOT NULL,native_display int unsigned NOT NULL,native_outfit int unsigned NOT NULL) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4')
 result=subprocess.run([str(s.bin/'mysql.exe'),*s.args,'--batch','--raw','--skip-column-names',s.database],input=sql,text=True,capture_output=True,env=s.env,timeout=900)
 if result.returncode:raise RuntimeError(result.stderr.strip())
 result=s.query('SELECT COUNT(*),COUNT(DISTINCT spawn_guid) FROM wildstar_nexus_spawn');assert result=='16940\t16940',result
 profiles=s.query("SELECT COUNT(*) FROM wildstar_appearance_profile p JOIN wildstar_nexus_spawn n ON n.spawn_guid=p.owner_id WHERE p.owner_type='C'");assert int(profiles)>=4601
 (out/'installed.json').write_text(json.dumps(dict(core=str(s.core),report=report,registry=result,profiles=profiles,sql_sha256=hashlib.sha256(sql.encode()).hexdigest(),serverRestarted=False),indent=2));print('INSTALLED; graceful worldserver restart required')
if __name__=='__main__':main()
