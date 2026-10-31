"""Stage/install the separate Eluna appearance bridge, with backups. No core restart or DBC replacement."""
from pathlib import Path
import argparse,shutil,json,hashlib
from datetime import datetime,timezone
from ws_appearance_catalog import generate,ROOT
from ws_azerothcore_install import Server
def main():
    ap=argparse.ArgumentParser();ap.add_argument('--server',required=True,help='Core directory');ap.add_argument('--apply',action='store_true');args=ap.parse_args()
    out=ROOT/'build_wildstar/wildstar335a/server/adapters/azerothcore/appearance';catalog=generate(out)
    protocol=ROOT/'WoWClient/Interface/WildStarDebug/ProfileProtocol.lua'
    source=ROOT/'plugins/wildstar335a/adapters/azerothcore/WildStarAppearanceServer.lua'
    script='-- Generated appearance bridge: shared codec, numeric catalog, server handlers.\n'+protocol.read_text(encoding='utf-8')+'\n'+(out/'AppearanceCatalog.lua').read_text(encoding='utf-8')+'\n'+source.read_text(encoding='utf-8')
    (out/'WildStarAppearance.lua').write_text(script,encoding='utf-8')
    migration=ROOT/'plugins/wildstar335a/adapters/azerothcore/ws_appearance_profile.world.sql'
    shutil.copy2(migration,out/migration.name)
    if not args.apply:print('Staged',out);return
    server=Server(args.server);folder=server.core/'lua_scripts';assert folder.is_dir()
    expected={'owner_type','owner_id','base_display','original_display','descriptor','updated_at'}
    columns=server.query("SELECT COLUMN_NAME FROM information_schema.COLUMNS WHERE TABLE_SCHEMA=DATABASE() AND TABLE_NAME='wildstar_appearance_profile'")
    if columns and set(columns.splitlines())!=expected:raise RuntimeError('Existing profile table has an incompatible schema')
    stamp=datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    backup=ROOT/'build_wildstar/deployments'/('appearance-'+stamp);backup.mkdir(parents=True,exist_ok=False)
    for name in ['WildStarRaceDisplay.lua','WildStarAppearance.lua']:
        if (folder/name).is_file():shutil.copy2(folder/name,backup/name)
    if columns:
        rows=server.query('SELECT owner_type,owner_id,base_display,original_display,descriptor FROM wildstar_appearance_profile')
        (backup/'existing_profiles.tsv').write_text(rows,encoding='utf-8')
    race=folder/'WildStarRaceDisplay.lua'
    if race.is_file():
        text=race.read_text(encoding='utf-8-sig')
        if 'WildStarAppearance.HasProfile' not in text:
            anchor='if not player then return end'
            if anchor not in text:raise RuntimeError('Unknown race script layout; refusing to overwrite it')
            text=text.replace(anchor,anchor+'\n\tif WildStarAppearance and WildStarAppearance.HasProfile(player) then WildStarAppearance.Apply(player); return end',1)
            race.write_text(text,encoding='utf-8')
    server.query(migration.read_text(encoding='utf-8'))
    target=folder/'WildStarAppearance.lua';temporary=target.with_suffix('.lua.tmp');temporary.write_text(script,encoding='utf-8');temporary.replace(target)
    check=server.query("SELECT COUNT(*) FROM information_schema.COLUMNS WHERE TABLE_SCHEMA=DATABASE() AND TABLE_NAME='wildstar_appearance_profile'")
    if check!='6':raise RuntimeError('Profile table verification failed')
    (backup/'deployment.json').write_text(json.dumps(dict(core=str(server.core),script=str(target),sha256=hashlib.sha256(target.read_bytes()).hexdigest(),catalog=catalog['hash'],table='wildstar_appearance_profile',serverReloaded=False),indent=2),encoding='utf-8')
    print('Installed server script and separate profile table. Backup:',backup)
    print('Lua activation requires .reload eluna or the next normal worldserver start; no restart performed.')
if __name__=='__main__':main()
