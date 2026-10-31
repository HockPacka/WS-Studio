"""Install only the plugin-owned native combat profile schema (--apply required)."""
import argparse,datetime,hashlib,json
from pathlib import Path
from ws_azerothcore_install import Server
ROOT=Path(__file__).resolve().parents[1]
TABLE='wildstar_combat_profile'
MARKER='wildstar335a combat profiles v1'
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--core',type=Path,required=True)
    ap.add_argument('--output',type=Path,required=True);ap.add_argument('--apply',action='store_true')
    args=ap.parse_args();server=Server(args.core)
    found=server.query("SELECT TABLE_COMMENT FROM information_schema.TABLES WHERE TABLE_SCHEMA=DATABASE() AND TABLE_NAME='"+TABLE+"'")
    assert not found or found==MARKER,'Existing table has unknown ownership; no changes made'
    schema=ROOT/'plugins/wildstar335a/adapters/azerothcore/ws_combat_profile.world.sql'
    if not args.apply:print('Preflight passed; table '+('already exists' if found else 'will be created')+'; no writes');return
    assert not args.output.exists(),'Choose a new receipt folder';args.output.mkdir(parents=True)
    if found:
        before=server.query('SHOW CREATE TABLE '+TABLE)
        (args.output/'schema.before.txt').write_text(before,encoding='utf-8')
    else:server.query(schema.read_text())
    assert server.query("SELECT TABLE_COMMENT FROM information_schema.TABLES WHERE TABLE_SCHEMA=DATABASE() AND TABLE_NAME='"+TABLE+"'")==MARKER
    columns=server.query('SHOW COLUMNS FROM '+TABLE)
    assert [line.split('\t')[0] for line in columns.splitlines()]==['realm_id','owner_guid','revision','payload','updated_at'],'Unexpected profile schema'
    assert not server.query("SELECT TRIGGER_NAME FROM information_schema.TRIGGERS WHERE TRIGGER_SCHEMA=DATABASE() AND EVENT_OBJECT_TABLE='"+TABLE+"'"),'Unexpected triggers on profile table'
    # Isolated, uncommitted SQL integration test. Never use a real character ID.
    key='realm_id=4294967295 AND owner_guid=4294967295'
    assert server.query('SELECT COUNT(*) FROM '+TABLE+' WHERE '+key)=='0','SQL test key is occupied'
    payload='1;1;x;x;x'+';0,0'*12
    output=server.query('START TRANSACTION; INSERT INTO '+TABLE+" (realm_id,owner_guid,revision,payload) VALUES (4294967295,4294967295,1,'"+payload+"'); UPDATE "+TABLE+' SET revision=revision+1 WHERE '+key+' AND revision=1; UPDATE '+TABLE+' SET revision=revision+1 WHERE '+key+' AND revision=1; SELECT revision,payload FROM '+TABLE+' WHERE '+key+'; ROLLBACK; SELECT COUNT(*) FROM '+TABLE+' WHERE '+key+';')
    assert output.splitlines()==['2\t'+payload,'0'],'MySQL CAS/rollback verification failed'
    assert server.query('SELECT COUNT(*) FROM '+TABLE+' WHERE '+key)=='0'
    after=server.query('SHOW CREATE TABLE '+TABLE);(args.output/'schema.after.txt').write_text(after,encoding='utf-8')
    receipt={'adapter':'azerothcore','table':TABLE,'created':not bool(found),'sourceSha256':hashlib.sha256(schema.read_bytes()).hexdigest(),
        'mysqlCompareAndSwap':'passed','mysqlTestRows':'rolled back; verified absent','stockTablesChanged':False,
        'time':datetime.datetime.now().isoformat()}
    (args.output/'schema_installation.json').write_text(json.dumps(receipt,indent=2))
    print(json.dumps(receipt))
if __name__=='__main__':main()
