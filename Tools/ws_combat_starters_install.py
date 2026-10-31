"""Install the reviewed compatibility set on a stopped AzerothCore. No SQL writes.

Prepares exact file hashes/backups. Stock spell rows and native diagnostic
profiles are not replaced. --prepare is read only against the installation.
"""
import argparse,json,os,re,shutil
from pathlib import Path
from ws_combat_starters import ROOT,POLICY,digest
from ws_azerothcore_install import Server

def sql_conflicts(server,spell_ids):
    cols=server.query("SELECT TABLE_NAME,COLUMN_NAME FROM information_schema.COLUMNS WHERE TABLE_SCHEMA=DATABASE() AND DATA_TYPE IN ('int','bigint','mediumint','smallint','tinyint') AND ((TABLE_NAME LIKE 'spell_%' AND LOWER(COLUMN_NAME) IN ('entry','id','spell','spell_id','spellid','spell_trigger','spell_effect')) OR LOWER(COLUMN_NAME) REGEXP '^(spell|spell_id|spellid|spellid_[1-8]|spell[1-8]|rewardspell|rewardspellcast|sourcespellid|requiredspell|auraspell|auraspellid|triggerspell|triggeredspell)$')")
    statements=[];ids=','.join(map(str,sorted(spell_ids)))
    for line in cols.splitlines():
        t,c=line.split('\t')
        if not re.fullmatch('[A-Za-z0-9_]+',t+c):raise ValueError('invalid schema identifier')
        statements.append(f"SELECT '{t}.{c}' AS occupied FROM `{t}` WHERE ABS(CAST(`{c}` AS SIGNED)) IN ({ids}) LIMIT 1")
    found=server.query(' UNION ALL '.join('('+s+')' for s in statements)) if statements else ''
    if found:raise ValueError('SQL namespace conflict: '+found)

def plan(package,client,core):
    package=Path(package).resolve();client=Path(client).resolve();server=Server(core)
    m=json.loads((package/'manifest.json').read_text())
    if not m.get('complete') or m['mode']!='wow-compatibility' or m['policyHash']!=digest(POLICY.read_bytes()):raise ValueError('unapproved/incomplete or changed starter policy')
    files=[]
    for item in m['files']:
        src=Path(item['staged']);dest=Path(item['destination'])
        if dest.parent not in [client/'WoWOverride/DBFilesClient',server.data/'dbc']:raise ValueError('unexpected DBC destination')
        if digest(src.read_bytes())!=item['after']:raise ValueError('staged DBC changed')
        current=digest(dest.read_bytes()) if dest.exists() else None
        if current!=item['before']:raise ValueError('live DBC changed since preparation: '+str(dest))
        files.append(dict(source=str(src),destination=str(dest),before=current,after=item['after']))
    def add(source,dest,generated=None):
        source=Path(source);dest=Path(dest)
        raw=source.read_bytes() if generated is None else generated
        files.append(dict(source=str(source),destination=str(dest),before=digest(dest.read_bytes()) if dest.exists() else None,
            after=digest(raw),**({'generated':raw.decode('utf-8')} if generated is not None else {})))
    luaRoot=server.core/'lua_scripts';adapter=ROOT/'plugins/wildstar335a/adapters/azerothcore'
    add(adapter/'StarterClasses.lua',luaRoot/'WildStarCombat/StarterClasses.lua')
    add(adapter/'WildStarClassesServer.lua',luaRoot/'WildStarClassesServer.lua')
    add(package/'StarterData.data',luaRoot/'WildStarCombat/StarterData.data')
    addon=ROOT/'plugins/wildstar335a/client/WildStarAbilities';dest=client/'Interface/AddOns/WildStarAbilities'
    for p in addon.iterdir():add(p,dest/p.name)
    raw=(package/'StarterData.data').read_text();assert raw.startswith('return ')
    add(package/'StarterData.data',dest/'StarterData.lua',('WildStarStarterData='+raw[7:]).encode())
    for asset in m['assets']:
        relative=Path(asset['relative']);src=package/'assets'/relative
        if relative.is_absolute() or '..' in relative.parts or digest(src.read_bytes())!=asset['sha256']:raise ValueError('bad native asset')
        add(src,client/'WoWOverride'/relative)
    # There must be no legacy Lua 750-damage dispatch for an approved engine ID.
    ids={e['wowSpell'] for e in m['abilities']}
    for p in luaRoot.rglob('*Telegraph*Data*.lua'):
        keys={int(k) for k in re.findall(r'\[(\d+)\]\s*=',p.read_text(encoding='utf-8-sig'))}
        if keys&ids:raise ValueError('duplicate legacy telegraph executor: '+str(p))
    sql_conflicts(server,ids)
    return files,m

def install(package,client,core,deployment,apply=False):
    deployment=Path(deployment).resolve();server=Server(core)
    if deployment.exists() or any(p in deployment.parents or p==deployment for p in [Path(client).resolve(),server.core,server.data]):
        raise ValueError('choose a new external deployment folder')
    files,m=plan(package,client,core)
    if apply and not server.stopped():raise ValueError('stop this worldserver gracefully first')
    deployment.mkdir(parents=True)
    # Snapshot every original file before the first mutation.
    for i,f in enumerate(files):
        dest=Path(f['destination']);backup=deployment/'backups'/str(i)
        if dest.exists():backup.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(dest,backup);f['backup']=str(backup)
    receipt=dict(mode=m['mode'],abilities=len(m['abilities']),classes=6,sqlWritten=False,
        applied=False,package=str(Path(package).resolve()),files=files)
    rp=deployment/'installation.json';rp.write_text(json.dumps(receipt,indent=2))
    if apply:
        for f in files:
            dest=Path(f['destination'])
            if (digest(dest.read_bytes()) if dest.exists() else None)!=f['before']:raise ValueError('concurrent file edit: '+str(dest))
            if 'generated' not in f and digest(Path(f['source']).read_bytes())!=f['after']:raise ValueError('source changed during install')
        written=[]
        try:
            for f in files:
                dest=Path(f['destination']);dest.parent.mkdir(parents=True,exist_ok=True)
                raw=f['generated'].encode() if 'generated' in f else Path(f['source']).read_bytes()
                temp=dest.with_name(dest.name+'.wsclasses-new');temp.write_bytes(raw);os.replace(temp,dest);written.append(f)
            for f in files:
                if digest(Path(f['destination']).read_bytes())!=f['after']:raise ValueError('installation readback failed')
        except Exception:
            for f in reversed(written):
                dest=Path(f['destination'])
                if digest(dest.read_bytes())!=f['after']:continue
                if f.get('backup'):shutil.copyfile(f['backup'],dest)
                else:dest.unlink()
            raise
        receipt['applied']=True;rp.write_text(json.dumps(receipt,indent=2))
    print(json.dumps(dict(applied=receipt['applied'],classes=6,abilities=30,files=len(files),receipt=str(rp))))

if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--package',type=Path,required=True)
    ap.add_argument('--client',type=Path,default=ROOT/'WoWClient');ap.add_argument('--core',type=Path,required=True)
    ap.add_argument('--deployment',type=Path,required=True);ap.add_argument('--apply',action='store_true')
    a=ap.parse_args();install(a.package,a.client,a.core,a.deployment,a.apply)
