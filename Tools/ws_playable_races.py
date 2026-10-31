"""Prepare native race rules and AzerothCore starter data; never connect to SQL.

Gameplay is a WoW compatibility profile: original WildStar class/start data is
preserved in the registry, not treated as WoW spells, equipment or map IDs.
"""
import argparse
import difflib
import hashlib
import json
from pathlib import Path
import struct

import tbl_dump
from ws_content_output import DEFAULT_CLIENT, DEFAULT_OUTPUT, Output, add_output_arguments
from ws_races import RACES, FIRST_ID, CLASS_MAP, EXILE

SKILL_ID_BASE = 9000000
TEMPLATES = {
    EXILE: {1: 1, 3: 3, 4: 1, 5: 1, 8: 1, 9: 1},
    166: {1: 2, 3: 2, 4: 2, 5: 5, 8: 5, 9: 2},
}


def table(client, name):
    raw = (Path(client)/'ClientData'/'DB'/(name+'.tbl')).read_bytes()
    _, cols, rows = tbl_dump.parse(raw)
    return [dict(zip((c[0] for c in cols), r)) for r in rows], hashlib.sha256(raw).hexdigest()


def registry(client):
    creation, creation_hash = table(client, 'CharacterCreation')
    races, race_hash = table(client, 'Race')
    race_by_id = {r['ID']: r for r in races}
    entries = []
    for i, (key, native, faction, base, _, _, name, _) in enumerate(RACES):
        rows = [r for r in creation if r['raceId'] == native and r['factionId'] == faction
                and r['enabled'] and not r['costumeOnly'] and r['classId'] in CLASS_MAP]
        classes = []
        for cls in sorted({r['classId'] for r in rows}):
            wow_class = CLASS_MAP[cls]
            sources = [r for r in rows if r['classId'] == cls]
            classes.append(dict(nativeClass=cls, wowClass=wow_class,
                sexes=sorted({r['sex'] for r in sources}),
                templateRace=TEMPLATES[faction][wow_class], creationRows=sources))
        entries.append(dict(key=key, name=name, wowRace=FIRST_ID+i, nativeRace=native,
            nativeFaction=faction, team='alliance' if faction == EXILE else 'horde' if faction else None,
            playable=bool(classes), templateRace=base, classes=classes,
            sexes=sorted({s for c in classes for s in c['sexes']}),
            maleModel=race_by_id[native]['maleAssetPath'], femaleModel=race_by_id[native]['femaleAssetPath']))
    return dict(schemaVersion=1, sourceHashes={'Race.tbl':race_hash, 'CharacterCreation.tbl':creation_hash},
        gameplay='WoW classes, starter locations and stats are compatibility templates, not native WildStar gameplay',
        races=entries)


def rules_header(data):
    lines = ['// Generated from original WildStar Race.tbl + CharacterCreation.tbl.',
        '// Shared client/server rules. No SQL connection or core headers.', '#pragma once',
        '#include <cstdint>', 'namespace WildStarRaceRules {',
        'inline bool IsManagedRace(uint32_t race) { return race >= 22 && race <= 30; }',
        'inline bool IsSexAllowed(uint32_t race, uint32_t sex) {',
        '    if (sex >= 2) return false;', '    switch (race) {']
    for r in data['races']:
        bits=sum(1<<s for s in r['sexes'])
        lines.append('    case %d: return (%du & (1u << sex)) != 0;' % (r['wowRace'],bits))
    lines += ['    default: return true;', '    }', '}',
        'inline bool IsCreationAllowed(uint32_t race, uint32_t cls, uint32_t sex) {',
        '    if (!IsSexAllowed(race, sex) || cls >= 32) return false;', '    switch (race) {']
    for r in data['races']:
        # The native data currently has the same class set for both sexes;
        # emit per-sex masks nonetheless so a later data build remains exact.
        masks=[sum(1<<c['wowClass'] for c in r['classes'] if s in c['sexes']) for s in (0,1)]
        lines.append('    case %d: return ((sex == 0 ? %du : %du) & (1u << cls)) != 0;' % (r['wowRace'],*masks))
    lines += ['    default: return true;', '    }', '}', '} // namespace WildStarRaceRules', '']
    return '\n'.join(lines)


def skill_dbc(output, data, name):
    raw=output.original_dbc(name)
    magic,count,fields,size,ss=struct.unpack_from('<4s4I',raw)
    assert magic==b'WDBC' and size==fields*4
    assert fields=={'SkillRaceClassInfo':8,'SkillLineAbility':14}[name]
    rows=[list(struct.unpack_from('<%dI'%fields,raw,20+i*size)) for i in range(count)]
    assert not any(SKILL_ID_BASE <= r[0] < SKILL_ID_BASE+100000 for r in rows),'reserved skill IDs occupied'
    race_col,class_col=(2,3) if name=='SkillRaceClassInfo' else (3,4)
    added=[]
    for race in data['races']:
        for cls in race['classes']:
            source_bit=1<<(cls['templateRace']-1); class_bit=1<<(cls['wowClass']-1)
            for row in rows:
                # Generic raceMask=0 already applies to the new race.
                if not row[race_col] or not row[race_col]&source_bit:continue
                if row[class_col] and not row[class_col]&class_bit:continue
                if name=='SkillLineAbility' and (row[5]&source_bit or row[6]&class_bit):continue
                n=row.copy();n[0]=SKILL_ID_BASE+len(added)
                n[race_col]=1<<(race['wowRace']-1);n[class_col]=class_bit
                if name=='SkillLineAbility':n[5]=n[6]=0
                added.append(n)
    if len(added)>=100000:raise ValueError('skill ID reservation exceeded')
    strings=raw[20+count*size:]
    result=struct.pack('<4s4I',magic,count+len(added),fields,size,ss)
    result+=b''.join(struct.pack('<%dI'%fields,*r) for r in rows+added)+strings
    Path(output.client_path('WoWOverride/DBFilesClient/'+name+'.dbc')).write_bytes(result)
    output.install_client_file('WoWOverride/DBFilesClient/'+name+'.dbc')
    return len(added)


def starter_sql(data):
    """DML inside a procedure: any error rolls back the entire migration.

    No automatic execution. Plain INSERT rejects collisions. Existing generic
    raceMask=0 rows apply naturally and are not duplicated or modified.
    """
    playable=[r for r in data['races'] if r['playable']]
    ids=','.join(str(r['wowRace']) for r in playable)
    mask=sum(1<<(r['wowRace']-1) for r in playable)
    lines=['-- WildStar AzerothCore starter compatibility profile v1.',
        '-- Target world DB only. No characters/auth schema writes. Manual execution.',
        '-- Requires matching staged client/server DBCs incl. the two skill tables.',
        '-- Start locations remain stock Human/Orc locations until server map collision data exists.',
        '-- SQL stores starter rules, not full native WildStar appearance.',
        'DELIMITER $$', 'CREATE PROCEDURE ws335a_install_playable_races_v1()', 'BEGIN',
        '  DECLARE EXIT HANDLER FOR SQLEXCEPTION BEGIN ROLLBACK; RESIGNAL; END;',
        '  START TRANSACTION;',
        "  IF (SELECT COUNT(*) FROM information_schema.TABLES WHERE TABLE_SCHEMA=DATABASE() AND TABLE_NAME IN ('playercreateinfo','player_race_stats','playercreateinfo_action','playercreateinfo_item','playercreateinfo_skills','playercreateinfo_spell_custom','playercreateinfo_cast_spell') AND ENGINE='InnoDB') <> 7 THEN",
        "    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'WildStar requires all seven world tables with InnoDB';",
        '  END IF;']
    for tab,col in [('playercreateinfo','race'),('player_race_stats','Race'),
                    ('playercreateinfo_action','race'),('playercreateinfo_item','race')]:
        lines += [f'  IF EXISTS (SELECT 1 FROM `{tab}` WHERE `{col}` IN ({ids})) THEN',
                  f"    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'WildStar ID conflict: {tab}';",'  END IF;']
    for tab,col in [('playercreateinfo_skills','raceMask'),('playercreateinfo_spell_custom','racemask'),('playercreateinfo_cast_spell','raceMask')]:
        lines += [f'  IF EXISTS (SELECT 1 FROM `{tab}` WHERE (`{col}` & {mask}) <> 0) THEN',
                  f"    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'WildStar mask conflict: {tab}';",'  END IF;']
    # Validate every required source before the first persistent INSERT.
    for base in sorted({r['templateRace'] for r in playable}):
        lines += [f'  IF NOT EXISTS (SELECT 1 FROM player_race_stats WHERE Race={base}) OR NOT EXISTS (SELECT 1 FROM playercreateinfo WHERE race={base} AND class=1) THEN',
                  "    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Missing starter race template';",'  END IF;']
    templates=sorted({(c['templateRace'],c['wowClass']) for r in playable for c in r['classes']})
    for base,cls in templates:
        lines += [f'  IF NOT EXISTS (SELECT 1 FROM playercreateinfo WHERE race={base} AND class={cls}) THEN',
                  "    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Missing starter class template';",'  END IF;']
    for r in playable:
        rid,base=r['wowRace'],r['templateRace']; race_bit=1<<(rid-1)
        lines += [f"  -- {r['key']}: native race {r['nativeRace']}, faction {r['nativeFaction']}.",
            f'  INSERT INTO player_race_stats (Race,Strength,Agility,Stamina,Intellect,Spirit) SELECT {rid},Strength,Agility,Stamina,Intellect,Spirit FROM player_race_stats WHERE Race={base};']
        for c in r['classes']:
            cls,source=c['wowClass'],c['templateRace'];class_bit=1<<(cls-1);source_bit=1<<(source-1)
            lines += [f'  INSERT INTO playercreateinfo (race,class,map,zone,position_x,position_y,position_z,orientation) SELECT {rid},{cls},map,zone,position_x,position_y,position_z,orientation FROM playercreateinfo WHERE race={base} AND class=1;',
                f'  INSERT INTO playercreateinfo_action (race,class,button,action,type) SELECT {rid},{cls},button,action,type FROM playercreateinfo_action WHERE race={source} AND class={cls};',
                f'  INSERT INTO playercreateinfo_item (race,class,itemid,amount,Note) SELECT {rid},{cls},itemid,amount,Note FROM playercreateinfo_item WHERE race={source} AND class IN (0,{cls});',
                f"  INSERT INTO playercreateinfo_skills (raceMask,classMask,skill,`rank`,comment) SELECT {race_bit},{class_bit},skill,MAX(`rank`),'WildStar compatibility template' FROM playercreateinfo_skills WHERE raceMask<>0 AND (raceMask & {source_bit})<>0 AND (classMask=0 OR (classMask & {class_bit})<>0) GROUP BY skill;",
                f"  INSERT INTO playercreateinfo_spell_custom (racemask,classmask,Spell,Note) SELECT DISTINCT {race_bit},{class_bit},Spell,'WildStar compatibility template' FROM playercreateinfo_spell_custom WHERE racemask<>0 AND (racemask & {source_bit})<>0 AND (classmask=0 OR (classmask & {class_bit})<>0);",
                f'  INSERT INTO playercreateinfo_cast_spell (raceMask,classMask,spell) SELECT DISTINCT {race_bit},{class_bit},spell FROM playercreateinfo_cast_spell WHERE raceMask<>0 AND (raceMask & {source_bit})<>0 AND (classMask=0 OR (classMask & {class_bit})<>0);']
    lines += ['  COMMIT;', 'END$$', 'DELIMITER ;', 'CALL ws335a_install_playable_races_v1();',
        'DROP PROCEDURE ws335a_install_playable_races_v1;', '']
    return '\n'.join(lines)


def generate(output):
    data=registry(output.client)
    dest=output.root/'native'/'character';dest.mkdir(parents=True,exist_ok=True)
    (dest/'playable-races.json').write_text(json.dumps(data,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    header=rules_header(data)
    (dest/'WildStarRaceRules.h').write_text(header,encoding='utf-8')
    sql_path=Path(output.adapter_path('sql/ws_playable_races.world.sql'))
    sql_path.write_text(starter_sql(data),encoding='utf-8')
    counts={name:skill_dbc(output,data,name) for name in ['SkillRaceClassInfo','SkillLineAbility']}
    # Optional source hook enforces sex/class restrictions against forged packets.
    # Export a patch; never edit or replace the running server binary.
    ref=Path(__file__).resolve().parent/'reference/azerothcore-191715d85cad/src/server/game/Entities/Player/Player.cpp'
    if ref.exists():
        original=ref.read_text(encoding='utf-8');new=original.replace('#include "Player.h"','#include "Player.h"\n#include "WildStarRaceRules.h"',1)
        needle='bool Player::Create(ObjectGuid::LowType guidlow, CharacterCreateInfo* createInfo)\n{'
        assert needle in new
        new=new.replace(needle,needle+'\n    if (WildStarRaceRules::IsManagedRace(createInfo->Race) &&\n        !WildStarRaceRules::IsCreationAllowed(createInfo->Race, createInfo->Class, createInfo->Gender))\n        return false;\n',1)
        patch=''.join(difflib.unified_diff(original.splitlines(True),new.splitlines(True),fromfile='a/src/server/game/Entities/Player/Player.cpp',tofile='b/src/server/game/Entities/Player/Player.cpp'))
        Path(output.adapter_path('source/creation-rules.patch')).write_text(patch,encoding='utf-8')
        Path(output.adapter_path('source/WildStarRaceRules.h')).write_text(header,encoding='utf-8')
    output.finish('playable-races')
    print('Prepared',sum(r['playable'] for r in data['races']),'playable races,',sum(len(r['classes']) for r in data['races']),'race/class pairs; skill DBC additions:',counts)
    print('SQL is a file only; no server DB or executable was changed.')
    return data,counts


def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--client',default=DEFAULT_CLIENT)
    add_output_arguments(ap);args=ap.parse_args();generate(Output(args))


if __name__=='__main__':main()
