"""
WildStar Spell-to-Telegraph Database Generator
Generates:
1. AzerothCore/Eluna fast Lua lookup: Core/lua_scripts/WildStarTelegraphData.lua
2. Client AddOn fast Lua lookup: WoWClient/Interface/AddOns/WildStarTelegraph/WildStarTelegraphData.lua
3. Client/Tool cache metadata: WoWClient/WildStarContent/Cache/telegraph/telegraph_db.json
"""

import os
import csv
import json
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CSV_DIR = os.path.join(ROOT, "WoWClient", "tables_csv")

TARGET_LUA_PATHS = [
    os.path.join(ROOT, "Repack AzerothCore NPCBots(2026)(Update 6.2)", "Repack AzerothCore NPCBots", "Core", "lua_scripts", "WildStarTelegraphData.lua"),
    os.path.join(ROOT, "Repack AzerothCore NPCBots", "Core", "lua_scripts", "WildStarTelegraphData.lua"),
    os.path.join(ROOT, "WoWClient", "Interface", "AddOns", "WildStarTelegraph", "WildStarTelegraphData.lua")
]

JSON_CACHE_PATH = os.path.join(
    ROOT,
    "WoWClient",
    "WildStarContent",
    "Cache",
    "telegraph",
    "telegraph_db.json"
)

def main():
    t0 = time.time()
    print("=" * 60)
    print("WildStar Spell-to-Telegraph Generator")
    print("=" * 60)

    # 1. Read TelegraphDamage.csv
    td_path = os.path.join(CSV_DIR, "TelegraphDamage.csv")
    damage_shapes = {}
    with open(td_path, "r", encoding="utf-8", errors="ignore") as f:
        r = csv.DictReader(f)
        for row in r:
            td_id = row["ID"]
            shape_enum = int(row["damageShapeEnum"])
            damage_shapes[td_id] = {
                "shape": shape_enum,
                "p0": round(float(row["param00"]), 2),
                "p1": round(float(row["param01"]), 2),
                "p2": round(float(row["param02"]), 2),
                "rampIn": int(row["telegraphTimeRampInMs"]),
                "rot": round(float(row["rotationDegrees"]), 2),
                "xOff": round(float(row["xPositionOffset"]), 2),
                "yOff": round(float(row["yPositionOffset"]), 2),
                "zOff": round(float(row["zPositionOffset"]), 2),
            }
    print(f"[+] Loaded {len(damage_shapes)} TelegraphDamage shapes.")

    # 2. Read Spell4Telegraph.csv
    st_path = os.path.join(CSV_DIR, "Spell4Telegraph.csv")
    spell_to_telegraph = {}
    with open(st_path, "r", encoding="utf-8", errors="ignore") as f:
        r = csv.DictReader(f)
        for row in r:
            s_id = int(row["spell4Id"])
            td_id = row["telegraphDamageId"]
            if td_id in damage_shapes:
                if s_id not in spell_to_telegraph:
                    spell_to_telegraph[s_id] = damage_shapes[td_id]

    print(f"[+] Mapped {len(spell_to_telegraph)} Spells to active Telegraph shapes.")

    # 3. Export JSON Database
    os.makedirs(os.path.dirname(JSON_CACHE_PATH), exist_ok=True)
    with open(JSON_CACHE_PATH, "w", encoding="utf-8") as f:
        json.dump(spell_to_telegraph, f, separators=(',', ':'))
    print(f"[+] Written JSON Database: {JSON_CACHE_PATH} ({os.path.getsize(JSON_CACHE_PATH)/1024:.1f} KB)")

    # 4. Generate Lua content with dual lookup ([s_id] and [100000 + s_id])
    lua_lines = [
        "-- WildStar Auto-Generated Spell-to-Telegraph Database\n",
        f"-- Total unique combat spells with telegraphs: {len(spell_to_telegraph)}\n",
        "WSTelegraphData = {}\n",
        "_G.WSTelegraphData = WSTelegraphData\n\n"
    ]
    for s_id, data in sorted(spell_to_telegraph.items()):
        val_str = f"{{{data['shape']},{data['p0']},{data['p1']},{data['p2']},{data['rampIn']},{data['rot']}}}"
        lua_lines.append(f"WSTelegraphData[{s_id}]={val_str}\n")
        lua_lines.append(f"WSTelegraphData[{100000 + s_id}]={val_str}\n")

    lua_content = "".join(lua_lines)

    for p in TARGET_LUA_PATHS:
        os.makedirs(os.path.dirname(p), exist_ok=True)
        with open(p, "w", encoding="utf-8") as f:
            f.write(lua_content)
        print(f"[+] Written Lua Database: {p} ({os.path.getsize(p)/1024:.1f} KB)")

    print(f"[+] Finished in {time.time()-t0:.2f} seconds!")

if __name__ == "__main__":
    main()
