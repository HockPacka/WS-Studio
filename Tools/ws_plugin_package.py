"""Build a portable WildStar content package without a server or database.
The package is data + client patches, not a universal server-core binary plugin.
"""
import argparse,hashlib,json,shutil,subprocess,sys
from pathlib import Path
from ws_content_output import ROOT,DEFAULT_CLIENT,ClientArchive
from ws_dbc_delta import export_delta,STRINGS
import ws_npc_patch
import tbl_dump

TABLES=['Race','Class','CharacterCreation','CharacterCreationPreset','CharacterCreationArmorSet',
        'CharacterCustomization','CharacterCustomizationLabel','CharacterCustomizationSelection',
        'ItemSlot','ItemDisplay','CustomizationParameter','CustomizationParameterMap',
        'ModelMesh','ModelBone','ModelPose','ComponentRegion','ComponentRegionRect','ItemColorSet','DyeColorRamp',
        'Item2Type','Creature2DisplayInfo','Creature2ModelInfo']

def write_json(path,data):
    path.parent.mkdir(parents=True,exist_ok=True);path.write_text(json.dumps(data,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--client',default=DEFAULT_CLIENT);ap.add_argument('--output',default=str(ROOT/'build_wildstar'/'wildstar335a'));ap.add_argument('--skip-generate',action='store_true');a=ap.parse_args()
    client=Path(a.client).resolve();out=Path(a.output).resolve()
    if out==client or client in out.parents:ap.error('output must be outside the original client tree')
    out.mkdir(parents=True,exist_ok=True)
    (out/'tools').mkdir(exist_ok=True)
    shutil.copy2(ROOT/'tools'/'ws_dbc_delta.py',out/'tools'/'ws_dbc_delta.py')
    shutil.copy2(ROOT/'plugins'/'wildstar335a'/'README.md',out/'README.md')
    # Runtime debug scripts belong to the client extension, alongside its hooks.
    debug_source=client/'Interface'/'WildStarDebug'
    if debug_source.is_dir():
        debug_dest=out/'client'/'Interface'/'WildStarDebug'
        debug_dest.mkdir(parents=True,exist_ok=True)
        for script in debug_source.glob('*.lua'):shutil.copy2(script,debug_dest/script.name)
    adapter_readme=out/'server/adapters/azerothcore/README.md'
    adapter_readme.parent.mkdir(parents=True,exist_ok=True)
    shutil.copy2(ROOT/'plugins/wildstar335a/adapters/azerothcore/README.md',adapter_readme)
    for filename in ('WildStarAppearanceServer.lua','ws_appearance_profile.world.sql'):
        shutil.copy2(ROOT/'plugins/wildstar335a/adapters/azerothcore'/filename,adapter_readme.parent/filename)
    from ws_appearance_catalog import generate as generate_appearance
    generate_appearance(adapter_readme.parent/'appearance')
    if not a.skip_generate:
        for name,extra in [('ws_races.py',[]),('ws_playable_races.py',[]),('ws_map_setup.py',['Western']),('ws_zones.py',[])]:
            subprocess.run([sys.executable,str(ROOT/'tools'/name),*extra,'--client',str(client),'--output',str(out)],check=True)
    archive=ClientArchive(client/'Data');count=ws_npc_patch.display_count(str(client));deltas={}
    generated=out/'client'/'WoWOverride'/'DBFilesClient'
    for file in sorted(generated.glob('*.dbc')):
        if file.stem not in STRINGS:continue
        delta=export_delta(file.stem,archive.get('DBFilesClient\\'+file.name),file.read_bytes(),count)
        write_json(out/'server'/'dbc-deltas'/(file.stem+'.json'),delta);deltas[file.stem]=len(delta['records'])
    provenance=[]
    for name in TABLES:
        source=client/'ClientData'/'DB'/(name+'.tbl');raw=source.read_bytes();dest=out/'native'/'DB'/source.name;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes(raw)
        table,cols,rows=tbl_dump.parse(raw)
        # Preserve long values exactly across JS/JSON consumers (cost bitfields).
        values=[[str(v) if kind==20 else v for v,(_,kind) in zip(row,cols)] for row in rows]
        write_json(out/'native'/'decoded'/(name+'.json'),dict(table=table,columns=[dict(name=n,type=t) for n,t in cols],rows=values))
        provenance.append(dict(table=name,rows=len(rows),sha256=hashlib.sha256(raw).hexdigest()))
    repo=ROOT/'wowdecomp';commit=subprocess.check_output(['git','-C',str(repo),'rev-parse','HEAD'],text=True).strip()
    patch=subprocess.check_output(['git','-C',str(repo),'diff','--binary','HEAD','--','.'])
    (out/'client'/'source').mkdir(parents=True,exist_ok=True);(out/'client'/'source'/'working-tree-hooks.patch').write_bytes(patch)
    # New modules are absent from a normal git diff until tracked; export them
    # explicitly without staging, committing or changing the working tree.
    additions=subprocess.check_output(['git','-C',str(repo),'ls-files','--others','--exclude-standard','-z'])
    for raw in additions.split(b'\0'):
        if not raw:continue
        rel=Path(raw.decode('utf-8'))
        if rel.suffix.lower() not in ('.h','.cpp','.hlsl','.txt'):continue
        dest=out/'client'/'source'/'new-files'/rel;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(repo/rel,dest)
    write_json(out/'manifest.json',dict(schemaVersion=1,id='wildstar335a-content',status='offline-data-and-source-package',
        wowBuild=12340,wildstarBuild=16042,clientBaselineCommit=commit,serverInstallation=False,characterDatabaseWrites=False,
        nativeTables=provenance,dbcDeltaRows=deltas,
        adapters={'azerothcore':'starter SQL + optional creation-rule source hook, targeting repack revision 191715d85cad; not installed','trinitycore':'not implemented','cmangos':'not implemented'},
        capabilities={'additionalPlayableRaces':'AzerothCore RaceMgr registration + 36 starter pairs prepared offline; deployment and in-game tests pending','characterPersistence':'seven character choices via WoW fields; separate Eluna World DB profile adapter for cosmetic player/NPC variants, native presets and ItemDisplay overrides; live multi-client verification pending'},
        assetPolicy=f'{len(TABLES)} native tables included; original M3/TEX/AREA assets remain external and are not bundled',
        idPolicy='current development IDs preserved; target conflicts rejected by ws_dbc_delta.py; no automatic renumbering',
        sourceProvenance='complete local tracked diff + new modules; includes prior workspace edits, not an authorship attribution'))
    print('Portable package:',out);print('DBC delta rows:',deltas);print('Native character tables:',len(provenance));print('No server files or SQL databases were accessed.')

if __name__=='__main__':main()
