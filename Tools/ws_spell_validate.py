"""Validate a phase-1 spell package against original MPQs and its reservation snapshot."""
import argparse,hashlib,json,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];sys.path.insert(0,str(ROOT/'tools'))
from wildstar_spells.schema import Dbc,f32,u32
from ws_content_output import ClientArchive
from ws_azerothcore_install import Server

def validate(package,client,core=None,previous=None):
 package=Path(package);client=Path(client);report=json.loads((package/'report.json').read_text());ids=json.loads((package/'id_map.json').read_text())['tables'];reserve=json.loads((package/'reservations.json').read_text());archive=ClientArchive(client/'Data');dbcs={};rowmaps={}
 assert report['installable'] is False and report['runtimeReady'] is False
 original_count={}
 for name in ['Spell','SpellCastTimes','SpellDuration','SpellRange','SpellIcon']:
  original=Dbc(archive.get('DBFilesClient\\'+name+'.dbc'));new=Dbc((package/'catalog'/(name+'.dbc')).read_bytes());n=len(original.rows)
  assert new.fields==original.fields and new.rows[:n]==original.rows,(name,'original rows modified')
  assert new.strings[:len(original.strings)]==original.strings,(name,'original strings modified')
  additions={r[0] for r in new.rows[n:]};assert not additions&set(reserve['tables'][name]),(name,'ID collision')
  dbcs[name]=new;rowmaps[name]={r[0]:r for r in new.rows};original_count[name]=n
 for source in json.loads((package/'source_tables.json').read_text()):
  assert hashlib.sha256((package/'native'/(source['table']+'.tbl')).read_bytes()).hexdigest()==source['sha256']
 lang=json.loads((package/'localization.json').read_text());assert hashlib.sha256((package/lang['nativeCopy']).read_bytes()).hexdigest()==lang['sha256']
 seen=set();classes={};count=0
 for line in (package/'native/spells.jsonl').open(encoding='utf-8'):
  item=json.loads(line);native=item['rawSpell'];sid=item['nativeSpellId'];did=ids['Spell'][str(sid)];r=rowmaps['Spell'][did];seen.add(did);count+=1
  assert not item['runtimeReady'] and not item['implemented'] and not item['tested']
  assert r[71:74]==[0,0,0],('Invented effect',sid)
  assert r[29]==u32(native['spellCoolDown'])
  cast=rowmaps['SpellCastTimes'][r[28]];assert cast[1:]==[u32(native['castTime']),0,u32(native['castTime'])]
  if native['spellDuration']:assert rowmaps['SpellDuration'][r[40]][1:]==[u32(native['spellDuration']),0,u32(native['spellDuration'])]
  else:assert r[40]==0
  rg=rowmaps['SpellRange'][r[46]];assert rg[1:5]==[f32(native['targetMinRange']),f32(native['targetMinRange']),f32(native['targetMaxRange']),f32(native['targetMaxRange'])]
  assert r[45]==0,('Range written into mana field',sid)
  if r[133]:
   icon=rowmaps['SpellIcon'][r[133]];off=icon[1];end=dbcs['SpellIcon'].strings.find(0,off);path=dbcs['SpellIcon'].strings[off:end].decode();assert (package/'catalog/assets'/path.replace('\\','/')).is_file()
  off=r[136];end=dbcs['Spell'].strings.find(0,off);assert dbcs['Spell'].strings[off:end].decode('utf-8')==item['name']
 assert count==report['nativeSpellCount'] and len(seen)==count
 assert len(dbcs['Spell'].rows)-original_count['Spell']==count
 if previous:
  older=json.loads((Path(previous)/'id_map.json').read_text())['tables']
  for table,values in older.items():assert all(ids[table].get(k)==v for k,v in values.items()),('IDs changed',table)
 live_checked=[]
 if core:
  server=Server(core)
  for source in reserve['sources']:
   name=source['table'];path=(client/'WoWOverride/DBFilesClient' if source['kind']=='client' else server.data/'dbc')/(name+'.dbc')
   data=path.read_bytes() if path.exists() else archive.get('DBFilesClient\\'+name+'.dbc');assert hashlib.sha256(data).hexdigest()==source['sha256'],('Live file changed',str(path));live_checked.append(str(path))
 result=dict(passed=True,spells=count,originalCounts=original_count,noInventedEffects=True,rawSourceHashesVerified=True,priorMappingsStable=bool(previous),liveFileHashesUnchanged=len(live_checked))
 (package/'validation.json').write_text(json.dumps(result,indent=2));return result
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('package',type=Path);p.add_argument('--client',type=Path,default=ROOT/'WoWClient');p.add_argument('--server-core',type=Path);p.add_argument('--previous',type=Path);a=p.parse_args();print(json.dumps(validate(a.package,a.client,a.server_core,a.previous),indent=2))
