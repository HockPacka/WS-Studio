"""Add missing normal-difficulty registrations only for Nexus spawn map windows."""
from pathlib import Path
import sys,json,shutil,hashlib
sys.path.insert(0,str(Path(__file__).resolve().parent))
from ws_azerothcore_install import Server
from ws_map_setup import Dbc
from ws_content_output import ClientArchive,ROOT
s=Server(sys.argv[1]);out=ROOT/'build_wildstar/deployments/nexus-completion-20261028';p=json.loads((out/'plan.json').read_text());maps=sorted({r['map'] for r in p['spawns']})
if not s.stopped():raise SystemExit('Worldserver must finish its graceful shutdown before DBC installation')
client=ROOT/'WoWClient/WoWOverride/DBFilesClient/MapDifficulty.dbc'
server=s.data/'dbc/MapDifficulty.dbc'
report=[]
for label,target in [('server',server),('client',client)]:
 old=target.read_bytes() if target.is_file() else ClientArchive(ROOT/'WoWClient/Data').get('DBFilesClient\\MapDifficulty.dbc')
 backup=out/(label+'-MapDifficulty.before.dbc');
 if not backup.exists():backup.write_bytes(old)
 d=Dbc(old);assert d.fc==23 and d.rs==92
 template=next(r for r in d.recs if r[1]==0 and r[2]==0);before=[r[:] for r in d.recs];pairs={(r[1],r[2]) for r in d.recs};ids={r[0] for r in d.recs};added=[]
 for mid in maps:
  if (mid,0) in pairs:continue
  row=template[:];row[0]=950000+mid;row[1]=mid
  if row[0] in ids:raise ValueError('Difficulty ID collision')
  d.recs.append(row);added.append((row[0],mid))
 assert d.recs[:len(before)]==before
 prepared=out/(label+'-MapDifficulty.dbc');d.save(str(prepared));target.parent.mkdir(parents=True,exist_ok=True);temp=target.with_suffix('.dbc.tmp');shutil.copyfile(prepared,temp);temp.replace(target)
 report.append(dict(target=label,path=str(target),added=added,sha256=hashlib.sha256(target.read_bytes()).hexdigest()))
portable=ROOT/'build_wildstar/wildstar335a/client/WoWOverride/DBFilesClient/MapDifficulty.dbc';portable.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(client,portable)
(out/'mapdifficulty-installed.json').write_text(json.dumps(report,indent=2));print('Normal map difficulty entries installed:',maps)
