"""Guarded installation of visual-only DBC changes, addon and separate client EXE."""
import argparse,json,os,shutil
from pathlib import Path
from ws_combat_starters import ROOT,digest
from ws_azerothcore_install import Server

def install(package,client,core,deployment,apply=False):
    package=Path(package).resolve();client=Path(client).resolve();server=Server(core);deployment=Path(deployment).resolve()
    if deployment.exists() or any(p==deployment or p in deployment.parents for p in [client,server.core,server.data]):raise ValueError('new external deployment folder required')
    m=json.loads((package/'manifest.json').read_text());files=[dict(f) for f in m['files']]
    for f in files:
        d=Path(f['destination'])
        if d.parent not in [client/'WoWOverride/DBFilesClient',server.data/'dbc']:raise ValueError('unexpected destination')
    old=json.loads((ROOT/'build_wildstar/deployments/combat-starters-live-20261029/installation.json').read_text())
    previous={f['destination']:f['after'] for f in old['files']}
    def add(src,dest,owned=False):
        src=Path(src);dest=Path(dest);before=digest(dest.read_bytes()) if dest.exists() else None
        if owned and str(dest) in previous and before!=previous[str(dest)]:raise ValueError('starter addon changed concurrently')
        if not owned and dest.exists() and before!=digest(src.read_bytes()):raise ValueError('unowned new destination already exists: '+str(dest))
        files.append(dict(source=str(src),destination=str(dest),before=before,after=digest(src.read_bytes())))
    addon=ROOT/'plugins/wildstar335a/client/WildStarAbilities';dest=client/'Interface/AddOns/WildStarAbilities'
    add(addon/'WildStarAbilities.toc',dest/'WildStarAbilities.toc',True)
    add(addon/'CombatTelegraphs.lua',dest/'CombatTelegraphs.lua')
    add(package/'CombatVisualData.lua',dest/'CombatVisualData.lua')
    exe=ROOT/'wowdecomp/bin/Win/WowClient64_WildStarTelegraph_v2_test.exe'
    add(exe,client/exe.name)
    for f in files:
        src=Path(f['source']);d=Path(f['destination'])
        if digest(src.read_bytes())!=f['after'] or (digest(d.read_bytes()) if d.exists() else None)!=f['before']:raise ValueError('staged/live file changed: '+str(d))
    for model in m['models']:
        p=client/'ClientData'/Path(model['path'].replace('\\','/'))
        if digest(p.read_bytes())!=model['sha256']:raise ValueError('native FX asset changed')
    if apply and not server.stopped():raise ValueError('stop worldserver gracefully before installing its Spell.dbc')
    deployment.mkdir(parents=True)
    for i,f in enumerate(files):
        dest=Path(f['destination'])
        if dest.exists():
            backup=deployment/'backups'/str(i);backup.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(dest,backup);f['backup']=str(backup)
    receipt=dict(applied=False,visualsOnly=True,sqlWritten=False,files=files,package=str(package),
        classes=6,abilities=30,nativeFxAbilities=m['nativeFxAbilities'],nativeFxBindings=m['nativeFxBindings'])
    rp=deployment/'installation.json';rp.write_text(json.dumps(receipt,indent=2))
    if apply:
        written=[]
        try:
            for f in files:
                d=Path(f['destination'])
                if (digest(d.read_bytes()) if d.exists() else None)!=f['before']:raise ValueError('concurrent write')
                raw=Path(f['source']).read_bytes()
                if digest(raw)!=f['after']:raise ValueError('concurrent source write')
                d.parent.mkdir(parents=True,exist_ok=True);temp=d.with_name(d.name+'.wsvisual-new');temp.write_bytes(raw);os.replace(temp,d);written.append(f)
            for f in files:
                if digest(Path(f['destination']).read_bytes())!=f['after']:raise ValueError('readback failed')
        except Exception:
            for f in reversed(written):
                d=Path(f['destination'])
                if digest(d.read_bytes())!=f['after']:continue
                if f.get('backup'):shutil.copyfile(f['backup'],d)
                else:d.unlink()
            raise
        receipt['applied']=True;rp.write_text(json.dumps(receipt,indent=2))
    print(json.dumps(dict(applied=receipt['applied'],files=len(files),nativeFxAbilities=m['nativeFxAbilities'],receipt=str(rp))))

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--package',type=Path,required=True);p.add_argument('--client',type=Path,default=ROOT/'WoWClient')
    p.add_argument('--core',type=Path,required=True);p.add_argument('--deployment',type=Path,required=True);p.add_argument('--apply',action='store_true')
    a=p.parse_args();install(a.package,a.client,a.core,a.deployment,a.apply)
