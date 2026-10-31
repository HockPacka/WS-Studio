"""Explicit AzerothCore deployment adapter; offline generators remain independent.

--prepare performs read-only server checks and stages merged DBCs.
--apply backs up world starter tables and DBCs, then installs on a stopped core.
Credentials are read from the server config and never printed or saved here.
"""
import argparse,hashlib,json,os,re,shutil,struct,subprocess
from datetime import datetime,timezone
from pathlib import Path
from ws_content_output import ROOT
from ws_dbc_delta import Dbc,merge

TABLES=['playercreateinfo','player_race_stats','playercreateinfo_action','playercreateinfo_item',
        'playercreateinfo_skills','playercreateinfo_spell_custom','playercreateinfo_cast_spell']


class Server:
    def __init__(self,core):
        self.core=Path(core).resolve()
        conf=(self.core/'configs/worldserver.conf').read_text(encoding='utf-8-sig')
        def setting(key):
            m=re.search(r'^\s*'+re.escape(key)+r'\s*=\s*"([^"\r\n]*)"',conf,re.M)
            if not m:raise ValueError('Missing configuration: '+key)
            return m.group(1)
        host,port,user,password,self.database=setting('WorldDatabaseInfo').split(';')
        self.env=os.environ.copy();self.env['MYSQL_PWD']=password
        self.bin=self.core.parent/'mysql/bin'
        self.args=['--host='+host,'--port='+port,'--user='+user,'--default-character-set=utf8mb4']
        data=Path(setting('DataDir'));self.data=data if data.is_absolute() else (self.core/data).resolve()

    def query(self,sql):
        r=subprocess.run([str(self.bin/'mysql.exe'),*self.args,'--batch','--raw','--skip-column-names',self.database],
            input=sql,text=True,capture_output=True,env=self.env,timeout=90)
        if r.returncode:raise RuntimeError(r.stderr.strip())
        return r.stdout.strip()

    def stopped(self):
        r=subprocess.run(['powershell','-NoProfile','-Command',
            "Get-CimInstance Win32_Process -Filter \"Name='worldserver.exe'\" | Select-Object -ExpandProperty ExecutablePath"],capture_output=True,text=True,check=True)
        return str(self.core/'worldserver.exe').lower() not in r.stdout.lower()

    def backup(self,folder):
        path=folder/'world-starter-tables.sql'
        with path.open('xb') as f:
            r=subprocess.run([str(self.bin/'mysqldump.exe'),*self.args,'--single-transaction','--skip-lock-tables',
                '--set-gtid-purged=OFF','--column-statistics=0',self.database,*TABLES],stdout=f,stderr=subprocess.PIPE,env=self.env,timeout=90)
        if r.returncode:raise RuntimeError(r.stderr.decode(errors='replace'))
        return hashlib.sha256(path.read_bytes()).hexdigest()


def legacy_client_copy(name,raw,package):
    """Only migrate old owned rows if the entire input matches a known backup.

    Existing repack DBCs were previously copied by our legacy race generator.
    Never infer ownership from a race/ID range in an unknown target file.
    """
    if name not in ('CharBaseInfo','CharStartOutfit','NameGen'):return raw,None
    candidates=[]
    for root in [ROOT/'build_wildstar/backups',package/'backups']:
        candidates.extend(root.rglob(name+'.dbc.*'))
    known=next((p for p in candidates if p.read_bytes()==raw),None)
    if known is None:return raw,None
    normalized=bytearray(raw)
    if name=='CharBaseInfo' and struct.unpack_from('<2I',raw,8)==(1,2):struct.pack_into('<I',normalized,8,2)
    dbc=Dbc(bytes(normalized),name)
    def ours(row):
        v=dbc.decode(row)
        race=v[0] if name=='CharBaseInfo' else v[1]&255 if name=='CharStartOutfit' else v[2]
        return 22<=race<=30
    dbc.rows=[r for r in dbc.rows if not ours(r)]
    return dbc.save(),str(known)


def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--core',required=True)
    ap.add_argument('--package',default=str(ROOT/'build_wildstar/wildstar335a'))
    ap.add_argument('--deployment',required=True)
    action=ap.add_mutually_exclusive_group(required=True);action.add_argument('--prepare',action='store_true');action.add_argument('--apply',action='store_true')
    a=ap.parse_args();server=Server(a.core);package=Path(a.package).resolve();deploy=Path(a.deployment).resolve()
    if deploy==server.core or server.core in deploy.parents or deploy==server.data or server.data in deploy.parents:
        ap.error('Deployment staging/backup must be outside live server directories')
    if a.apply and not server.stopped():ap.error('Stop this worldserver gracefully before --apply; auth and MySQL can stay running')
    ids=','.join(map(str,range(22,30)));mask=sum(1<<(r-1) for r in range(22,30))
    engine=server.query("SELECT COUNT(*) FROM information_schema.TABLES WHERE TABLE_SCHEMA=DATABASE() AND TABLE_NAME IN ("+','.join("'"+t+"'" for t in TABLES)+") AND ENGINE='InnoDB';")
    if engine!='7':raise ValueError('Target needs seven expected InnoDB tables')
    conflicts=[]
    for tab in TABLES:
        condition=f'race IN ({ids})' if tab not in TABLES[4:] else f'(raceMask & {mask})<>0'
        n=int(server.query(f'SELECT COUNT(*) FROM `{tab}` WHERE {condition};'))
        if n:conflicts.append((tab,n))
    if conflicts:raise ValueError('Starter SQL ID/mask conflicts: '+repr(conflicts))
    staged={};records=[]
    # All merges and conflicts are resolved before any live mutation or backup.
    for delta_path in sorted((package/'server/dbc-deltas').glob('*.json')):
        delta=json.loads(delta_path.read_text(encoding='utf-8'));name=delta['table']
        target=server.data/'dbc'/(name+'.dbc');old=target.read_bytes()
        normalized,legacy=legacy_client_copy(name,old,package)
        new=merge(delta,normalized);staged[name]=(target,old,new)
        records.append(dict(table=name,before=hashlib.sha256(old).hexdigest(),after=hashlib.sha256(new).hexdigest(),legacyProof=legacy))
    deploy.mkdir(parents=True,exist_ok=True)
    report=dict(core=str(server.core),data=str(server.data),database=server.database,dbc=records,
        state='prepared',utc=datetime.now(timezone.utc).isoformat(),characterDatabaseWrites=False)
    for name,(_,old,new) in staged.items():
        p=deploy/'prepared/dbc'/(name+'.dbc');p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(new)
    (deploy/'preflight.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    if not a.apply:print('Prepared',len(staged),'DBCs and SQL preflight; live server untouched:',deploy);return
    backup=deploy/'backup';backup.mkdir(exist_ok=False)
    report['worldBackupSha256']=server.backup(backup)
    for name,(_,old,_) in staged.items():
        p=backup/'dbc'/(name+'.dbc');p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(old)
    sql=(package/'server/adapters/azerothcore/sql/ws_playable_races.world.sql').read_text(encoding='utf-8')
    (backup/'applied.sql').write_text(sql,encoding='utf-8')
    written=[]
    try:
        for name,(target,old,new) in staged.items():
            if target.read_bytes()!=old:raise RuntimeError('Server DBC changed during deployment: '+name)
            target.write_bytes(new);written.append(name)
        server.query(sql)
    except Exception:
        for name in written:staged[name][0].write_bytes(staged[name][1])
        raise
    for name,(target,_,new) in staged.items():assert target.read_bytes()==new
    report.update(state='installed',starterPairs=int(server.query('SELECT COUNT(*) FROM playercreateinfo WHERE race BETWEEN 22 AND 29;')),
        starterRaces=int(server.query('SELECT COUNT(*) FROM player_race_stats WHERE Race BETWEEN 22 AND 29;')))
    (deploy/'installed.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print('Installed',len(staged),'DBCs,',report['starterRaces'],'starter races and',report['starterPairs'],'class pairs.')
    print('World tables and original DBCs backed up:',backup)


if __name__=='__main__':main()
