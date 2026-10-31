"""Check native race rules, outfit coverage, skill adapters and starter DML offline."""
from pathlib import Path
import json,re,sqlite3,struct,sys

ROOT=Path(__file__).resolve().parents[2];sys.path.insert(0,str(ROOT/'tools'))
from ws_playable_races import registry,starter_sql
from ws_dbc_delta import Dbc
from ws_content_output import ClientArchive

PACKAGE=ROOT/'build_wildstar/wildstar335a';DBC=PACKAGE/'client/WoWOverride/DBFilesClient'
data=registry(ROOT/'WoWClient')
expected={(r['wowRace'],c['wowClass'],s) for r in data['races'] for c in r['classes'] for s in c['sexes']}
assert len(expected)==67 and len({(r,c) for r,c,s in expected})==36
assert not any(r==30 or r==29 and s==1 for r,c,s in expected)
cbi=Dbc((DBC/'CharBaseInfo.dbc').read_bytes(),'CharBaseInfo')
assert cbi.fields==2 and cbi.size==2
assert {tuple(row) for row in cbi.rows if row[0]>=22}=={(r,c) for r,c,s in expected}
cso=Dbc((DBC/'CharStartOutfit.dbc').read_bytes(),'CharStartOutfit')
outfits={tuple(row[4:7]) for row in cso.rows if row[4]>=22}
assert outfits==expected,('outfit coverage',expected-outfits,outfits-expected)
archive=ClientArchive(ROOT/'WoWClient/Data');counts={}
for name in ['SkillRaceClassInfo','SkillLineAbility']:
    original=Dbc(archive.get('DBFilesClient\\'+name+'.dbc'),name)
    patched=Dbc((DBC/(name+'.dbc')).read_bytes(),name)
    assert patched.rows[:len(original.rows)]==original.rows,'stock rows changed'
    assert original.strings==patched.strings
    rows=[patched.decode(r) for r in patched.rows[len(original.rows):]]
    assert len({r[0] for r in rows})==len(rows)
    rc,cc=(2,3) if name=='SkillRaceClassInfo' else (3,4)
    for race in data['races']:
        for cls in race['classes']:
            rb,cb,sb=1<<(race['wowRace']-1),1<<(cls['wowClass']-1),1<<(cls['templateRace']-1)
            want=[]
            for raw in original.rows:
                r=original.decode(raw)
                if not r[rc] or not r[rc]&sb or r[cc] and not r[cc]&cb:continue
                if name=='SkillLineAbility' and (r[5]&sb or r[6]&cb):continue
                r[0]=0;r[rc]=rb;r[cc]=cb
                if name=='SkillLineAbility':r[5]=r[6]=0
                want.append(r)
            actual=[]
            for row in rows:
                if row[rc]==rb and row[cc]==cb:
                    r=row.copy();r[0]=0;actual.append(r)
            assert actual==want,(name,race['key'],cls['wowClass'])
    counts[name]=len(rows)

# Execute only the generated INSERT/SELECT DML against an isolated in-memory
# schema with upstream reference starter records, never a live MySQL connection.
db=sqlite3.connect(':memory:')
ref=ROOT/'tools/reference/azerothcore-191715d85cad/data/sql/base/db_world'
schemas={
    'playercreateinfo':'race,class,map,zone,position_x,position_y,position_z,orientation,PRIMARY KEY(race,class)',
    'player_race_stats':'Race PRIMARY KEY,Strength,Agility,Stamina,Intellect,Spirit',
    'playercreateinfo_action':'race,class,button,action,type,PRIMARY KEY(race,class,button)',
    'playercreateinfo_item':'race,class,itemid,amount,Note,PRIMARY KEY(race,class,itemid)',
    'playercreateinfo_skills':'raceMask,classMask,skill,rank,comment,PRIMARY KEY(raceMask,classMask,skill)',
    'playercreateinfo_spell_custom':'racemask,classmask,Spell,Note,PRIMARY KEY(racemask,classmask,Spell)',
    'playercreateinfo_cast_spell':'raceMask,classMask,spell,note',
}
for name,cols in schemas.items():
    db.execute('CREATE TABLE '+name+' ('+cols+')')
    p=ref/(name+'.sql')
    if p.exists():
        for statement in re.findall(r'INSERT INTO `'+name+r'` VALUES\s*.*?;',p.read_text(encoding='utf-8'),re.S):
            db.executescript(statement)
# Exercise race-specific and generic skills/spells and custom items.
db.executescript("INSERT INTO playercreateinfo_spell_custom VALUES(1,0,668,'common'),(2,0,669,'orcish'); INSERT INTO playercreateinfo_cast_spell (raceMask,classMask,spell) VALUES(1,0,123),(0,0,456); INSERT INTO playercreateinfo_item VALUES(1,1,999,1,'test');")
stock={name:list(db.execute('SELECT * FROM '+name+' WHERE '+('raceMask' if name in ('playercreateinfo_skills','playercreateinfo_spell_custom','playercreateinfo_cast_spell') else 'race')+' < 22')) for name in schemas}
sql=starter_sql(data)
assert 'ROLLBACK; RESIGNAL;' in sql and 'COMMIT;' in sql and 'ENGINE=' in sql
assert 'INSERT IGNORE' not in sql and 'REPLACE INTO' not in sql and 'DELETE FROM' not in sql
for statement in re.findall(r'^  INSERT INTO .*?;',sql,re.M):db.execute(statement.strip())
assert db.execute('SELECT COUNT(*) FROM playercreateinfo WHERE race BETWEEN 22 AND 29').fetchone()[0]==36
assert db.execute('SELECT COUNT(*) FROM player_race_stats WHERE Race BETWEEN 22 AND 29').fetchone()[0]==8
for name,rows in stock.items():
    current=list(db.execute('SELECT * FROM '+name+' WHERE '+('raceMask' if name in ('playercreateinfo_skills','playercreateinfo_spell_custom','playercreateinfo_cast_spell') else 'race')+' < 22'))
    assert current==rows,('stock SQL rows changed',name)

report=dict(playableRaces=8,raceClassPairs=36,sexClassCombinations=67,outfitCoverage='complete',
    skillAdditions=counts,sqlDml='passed isolated SQLite fixture; MySQL procedure/live server not executed',
    sourceRules='enabled non-costume CharacterCreation.tbl rows',serverWrites=0)
out=ROOT/'build_m3test/playable_races_check';out.mkdir(exist_ok=True)
(out/'validation.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
print(json.dumps(report,indent=2))
