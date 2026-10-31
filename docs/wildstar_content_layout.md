# WildStar content in the WoW server / client - separation from the original (rules for everything we generate)

Goal: the original WoW 3.3.5a data and the AzerothCore database stay untouched. Everything generated from WildStar data lives in its own files, its own ID ranges and
can be removed again with one script.

## Folder (client side, `WoWClient\WildStarContent\`)
```
sql\<name>.world.sql             idempotent install (DELETE by our id range, then INSERT) for the AzerothCore `world` database
sql\<name>.uninstall.world.sql   removes exactly what the install file added
dbc\                             generated DBC rows (CreatureDisplayInfo / CreatureModelData / Map / AreaTable ...), copied to WoWOverride\DBFilesClient and Data\dbc by a deploy script
world\<MapName>\                 generated ADT / WDT / minimap files for the WildStar maps (loose files, no MPQ patching)
```
Nothing is applied to the live database or the server `Data` folder unless a script is started with `--apply` (default: only write files). The server DBC originals are kept as `*.dbc.orig_ws`.

## ID namespaces (never reuse an original id)
| what | range | notes |
|---|---|---|
| CreatureDisplayInfo / CreatureModelData id | 200000 + global model index | `tools/ws_npc_patch.py`; index = position in the sorted model list of `ClientData` |
| creature_template entry | 4000000 - 4099999 | 4000000 = generic "WS Model" NPC used by the debug window |
| gameobject_template entry | 4100000 - 4199999 | props placed in the terrain (planned) |
| Map.dbc id | 5000 - 5999 | one id per WildStar map (`5000` = first test map) |
| AreaTable id | 50000 - 59999 | |
| guid ranges (creature / gameobject spawns) | 4000000 + | spawns of the generated maps |

## Pipeline for terrain (planned, first test tile `Western.393b`)
1. `tools/area_reader.py` -> height raster (257 x 257 samples per tile), 4 layer ids per cell, RGB565 / nibble weights, water, `PORP` placements.
2. Convert to WoW ADT (MCNK 16 x 16, 9 x 9 + 8 x 8 heights, 4 layers + alpha) and WDT for a new map id (5000...), written to `WildStarContent\world\`.
3. `Map.dbc` / `AreaTable.dbc` rows for the new map (own ids), SQL for spawns and game objects (own ranges).
4. Server: mapextractor output for the new map into a separate folder, deploy / undeploy script copies it next to the original maps; the client reads it as loose files.
5. Terrain textures: `WorldLayer` `.tex` files are read natively by the client (`Model3` texture hook, `WS\` prefix), no BLP files are written.

## Already generated (separated)
* `WildStarContent\sql\ws_npc_spawner.world.sql` (+ uninstall): creature entry 4000000. NOTE: this row was installed into `acore_world` in an earlier step; the uninstall file removes it.
* `WoWOverride\DBFilesClient\CreatureModelData.dbc` / `CreatureDisplayInfo.dbc` (client) and the patched copies in the server `Data\dbc` (originals kept as `*.dbc.orig_ws`).

## Cache of converted content (dbg52)
`WoWClient\WildStarContent\Cache\<kind>\<hash>.bin` (kinds: tex = BLP textures, m3 = converted models, adt = terrain tiles). Pure speed cache: every entry is rebuilt from ClientData when it is missing or when the size / write time of a source file or the converter version (`M3::kCacheVersion` in Engine/Source/Model3/Cache.h) differs; nothing is read from it that ClientData could not provide. Delete the folder at any time; `WoWOverride\no_cache.txt` switches it off. Disk use: about 1 - 1.4 MB per texture, 2 - 5 MB per tile.
