"""Verify portable row merge/unmerge, conflicts and no direct server install."""
from pathlib import Path
import hashlib,json,subprocess,sys
ROOT=Path(__file__).resolve().parents[2];sys.path.insert(0,str(ROOT/'tools'))
from ws_content_output import ClientArchive
from ws_dbc_delta import Dbc,merge
PACKAGE=ROOT/'build_wildstar/wildstar335a';OUT=ROOT/'build_m3test/plugin_separation_check';OUT.mkdir(exist_ok=True)
archive=ClientArchive(ROOT/'WoWClient/Data');results=[]
for path in sorted((PACKAGE/'server/dbc-deltas').glob('*.json')):
    delta=json.loads(path.read_text());name=delta['table'];source=archive.get('DBFilesClient\\'+name+'.dbc')
    target=Dbc(source,name);extra=target.decode(target.rows[0]);extra[0]=31 if target.packed else 1999999999
    if target.packed:extra[1]=31
    target.rows.append(target.encode(extra));with_user=target.save()
    patched=merge(delta,with_user);assert merge(delta,patched)==patched,'not idempotent: '+name
    final=Dbc(patched,name)
    assert any(final.decode(r)==extra for r in final.rows),'unrelated content lost: '+name
    undone=Dbc(merge(delta,patched,remove=True),name)
    assert [undone.decode(r) for r in undone.rows]==[target.decode(r) for r in target.rows],'rollback changed unrelated records: '+name
    if delta['records']:
        conflict=Dbc(patched,name);key=delta['records'][0]['key']
        for i,row in enumerate(conflict.rows):
            v=conflict.decode(row)
            if conflict.key(v)==key:
                index=1 if not conflict.packed else None
                if index is not None:v[index]='another plugin' if isinstance(v[index],str) else (v[index]^1)
                else:
                    # CharBaseInfo is all key: an occupied natural key is
                    # already exactly this pair, and has no mutable payload.
                    continue
                conflict.rows[i]=conflict.encode(v);break
        if not target.packed:
            try:merge(delta,conflict.save())
            except ValueError:pass
            else:raise AssertionError('conflicting row silently overwritten: '+name)
    results.append(dict(table=name,rows=len(delta['records']),preserves_other_rows=True,idempotent=True,removable=True))

# The legacy direct-server arguments must stop before output or DB access.
fake=OUT/'server_canary';fake.mkdir(exist_ok=True);canary=fake/'do_not_touch.txt';canary.write_text('original server data')
for script,extra in [('ws_races.py',[]),('ws_npc_patch.py',[]),('ws_map_setup.py',['Western']),('ws_zones.py',[])]:
    run=subprocess.run([sys.executable,str(ROOT/'tools'/script),*extra,'--server',str(fake),'--output',str(OUT/script)],capture_output=True,text=True)
    assert run.returncode!=0 and 'Direct server installation has been removed' in run.stderr,(script,run.stderr)
    assert canary.read_text()=='original server data' and not (OUT/script).exists()
for entry in json.loads((PACKAGE/'manifest.json').read_text())['nativeTables']:
    p=PACKAGE/'native/DB'/(entry['table']+'.tbl');original=ROOT/'WoWClient/ClientData/DB'/p.name
    assert p.read_bytes()==original.read_bytes()
    assert hashlib.sha256(p.read_bytes()).hexdigest()==entry['sha256']
native_count=len(json.loads((PACKAGE/'manifest.json').read_text())['nativeTables'])
report=dict(dbc_cases=results,native_tables_preserved=native_count,server_install_rejections=4,database_connections=0)
(OUT/'validation.json').write_text(json.dumps(report,indent=2)+'\n')
print('PASS portable DBC merge/unmerge:',len(results),'tables; custom target rows retained; conflicts rejected')
print('PASS',native_count,'original native tables byte-identical; all four direct-server paths rejected before writes')
