# Mordesh character parts and native race icons — 2026-10-28

## Character composition

Two independent faults were reproduced in `character_cli` with the native data:

1. `Allowed` admitted every Human race-0 customization row for Mordesh. That added Human hair display 238 to the choices (Human model, Human UV layout and region files) despite native Mordesh hair models being available. Generic foreign race folders are now rejected; explicitly race-specific rows retain their selection path. The corrected default uses native Mordesh bald display 5370; cycling hair selects display 4973 and `Hair_02_Mordesh_M.m3`. Its native head/hair color tiles resolve successfully.
2. Separate head/hair parts use LOCAL `meshDisplay` indices, not global ModelMesh IDs. E.g. Mordesh Face_01 list maps groups 0..5 to ModelMesh IDs 52..57 (beard variants); Hair_01 maps groups 0/1 to 124/125 (hat hair). Append previously discarded the part's display table, leaving the combined converter to reinterpret local indices as unrelated IDs. This could show unwanted beard/hat shapes over the selected face/hair.

Selection now resolves each part's local index to its actual ModelMesh ID, applies the customization's family selection or native default flags, and keeps unconditional group 255. Selection runs before appending. Selected meshes are marked unconditional so the combined M2 conversion cannot select variants again using another part's namespace. This also applies to the base model if it has a display table. `WS_CHAR_AUDIT=1` now logs `part_source` (native slot, ItemDisplay, actual resolved model path).

This fixes selection and overlapping geometry; no guessed vertex offsets or skeleton scaling were added. Original M3/TEX/TBL files remain unchanged. The prior WoW body-clothing/alpha fix remains in this build.

## Race portraits

`tools/extract_race_icons.py` extracts the 15 original portraits declared by `UI/Assets/Docs/Sprites/charactercreate.xml`, from `UI_BK3_CharacterCreate_Finalize.tex`. Atlas rectangles come from the original sprite XML. Aspect ratio and alpha are retained in 128x128 TGA assets; PNG copies and a source manifest are also written for inspection. Exiles use Human Exile, Granok, Aurin and Mordesh portraits; Dominion uses Cassian/Dom, Draken, Mechari and Chua. Male/female portraits switch with gender; Chua uses one original portrait.

`tools/client/WSRaceIcons.lua` installs the portrait texture for creation race buttons (normal/pressed) and the selected race panel. Switching back to a stock race restores the appropriate stock atlas and coordinates. It is loaded after `WSRaces.lua` by the live and portable GlueXML TOCs. `tools/ws_races.py` now includes this hook and generates/installs its TGA dependencies when regenerating race data.

Live assets: `WoWClient/WoWOverride/Interface/WildStar/Races`.
Preview: `build_m3test/race_icons_preview.png`.

## Checks

- Full `armor_body_cli` regression passes for all 15 playable race/sex compositions, original skin under transparent armor, unchanged geometry on WoW clothes, unequip, exact alpha 0/128/255, and explicit native chest ItemDisplay 435. Log: `build_m3test/mordesh_armor_regression.log`.
- Mordesh male/female `character_attachment_check.py`: actual serialized M2 Stand/Walk/Run head-scale samples, hand anchors and seven option cycles. Logs: `build_m3test/mordesh_animation_check.log`, `build_m3test/mordesh_female_animation_check.log`.
- `tools/analysis/race_icons_check.lua` under client Lua 5.1 tests 16 race/sex combinations, button normal/pressed textures, gender refresh and restoration of stock icons. Live/portable hooks pass syntax checks.
- Release build: `WoWClient/WowClient64_MordeshIcons_test.exe` (includes the previous streaming/startup and body-armor fixes).

An in-game visual comparison with this build remains to be done. Optional absent region tiles reported by the texture audit are not automatically missing assets; native region flags and partial overlays deliberately leave some regions untouched. No claim that every possible texture combination was visually verified.
