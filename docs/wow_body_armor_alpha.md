# WoW clothing on WildStar body meshes — 2026-10-28

## Cause and behavior

The previous path inserted Reflex_001 chest/pants/gloves/boots as native armor carriers for WoW texture sections. Its shared layout-10 atlas was filled with opaque gray (112). WSArmor::Overlay already blended BLP alpha correctly, but alpha 0 revealed that gray carrier surface instead of the character skin. Carrier geometry also introduced collars/buckles and other shapes absent from the WoW item.

WoW `~w` clothing now paints the fully composed native body color atlas. Alpha 0 preserves original skin; intermediate alpha blends over skin; the final body remains opaque. No Reflex carrier meshes are inserted. Existing native appearance parts (head, hair, body variants) remain selected normally. Explicit native `~e` ItemDisplays keep their separate armor models and atlas. Native items take precedence in occupied slots. Belts and standalone bracers also resolve without needing a carrier.

The revision base is 5000, distinguishing the new WoW appearance paths from old carrier variants. `/wsarmor` follows the race/sex body atlas (e.g. `mechari_m`); old `armor` layout-10 placements are not applied to the body. Existing per-model placements remain supported. Removing every WoW item swaps back to the skin atlas. Ordinary clothing edits now require an atlas swap, without changing geometry.

Native armor texture lookup additionally tries sex-only suffixes, e.g. `AMR_Reflex_001_M_color.Armor_Chest.tex`, after generic and model-specific names. This was missing independently of the carrier change.

## Submesh inventory

Read directly from extracted base M3 geometry mesh arrays. Each listed file has one geometry block. These counts exclude attached heads, hair and armor:

| Native model | Male | Female |
|---|---:|---:|
| Human (shared by Exile/Cassian) | 36 | 38 |
| Granok | 35 | 36 |
| Aurin | 37 | 39 |
| Mordesh | 43 | 46 |
| Draken | 40 | 40 |
| Mechari | 36 | 29 |
| Chua | 39 | — |

All base entries above have group byte 255 at mesh +0x1E, as read by the current native reader. Array index 0 is not the WoW body geoset 0. Restricting to the first raw entry would discard other parts of the body. The fix keeps native base geometry and adds WoW clothing to its body atlas, rather than replacing native group IDs with WoW geoset IDs.

Detailed raw counts: `build_m3test/character_submeshes.json`. Final composed counts depend on appearance; the regression's default Mechari male contains 59 entries (body + customization), unchanged when WoW clothing is equipped.

## Verification / limits

- `armor_body_cli` checks exact alpha 0/128/255 blending, all 15 playable race/sex compositions, transparent clothing equal to bare skin, unchanged geometry when equipping six WoW slots, and removal of all WoW clothing.
- Explicit native Reflex chest ItemDisplay 435 still appends geometry successfully.
- Lua 5.1 syntax check of live and portable `/wsarmor` files passes.
- Release client: `WoWClient/WowClient64_BodyArmor_test.exe`.
- Test outputs: `build_m3test/armor_body_regression.log`, `build_m3test/armor_native_regression.log`.

No in-game visual comparison has been made with this executable. Body UV layouts differ from WoW; default rectangle mapping is an approximation, and per-race alignment can be adjusted in `/wsarmor`. This is texture clothing, not newly generated WoW robe/glove/boot geometry for the WildStar skeleton. Existing helmet/shoulder/weapon attachment handling is separate from this body-overlay fix. Original assets and server data were not changed.
