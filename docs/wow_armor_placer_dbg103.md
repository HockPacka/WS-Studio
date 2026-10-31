# WoW armor on WildStar race models: texture placer (dbg103)

Goal: wear a WoW armor piece on a WildStar race character, place each WoW texture section on the WildStar skin atlas in game, send back the numbers.
Rule: **WoW BLP armor uses the placement table, native WildStar armor (ItemDisplay rows, `~e`) keeps the native atlas path.**

## How it works

* `CCharacterComponent::AddItem` ignores WoW items for WildStar race models (they would be composited onto a black CharSections base). The new path works on the unit model:
  `WildStarArmorItems(player)` collects the worn texture items (shirt, chest, belt, legs, boots, wrists, gloves, tabard) from `m_playerVisibleItems`.
* The model path of a WildStar race player now carries them: `...~c<race>.<sex>.<7 choices>~w<revision>.<slot>_<ItemDisplayInfo>...m3` (`WSCharacter::ModelPath(base, appearance, items)`, built in `CGUnit_C::UpdateDisplayInfo` and `GetModelFileName`).
* `WSCharacter::Compose` -> `BuildAtlas` (colour atlas of the body only) calls `WSArmor::Overlay` after the native layers: for every item the WoW layer resolves the section textures (`Item\TextureComponents\<Section>Texture\<name>_U/M/F.blp`, same lookup and layer priorities as `LoadItemComponentTexture` / `s_itemPriority`), the BLP2 file (palette, DXT1/3/5, BGRA) is decoded and alpha-blended into the rectangle of that section.
* Rectangles are normalised (0..1) per race / sex model key (`human_f`) and live in `WoWOverride\ws_armor_regions.txt`. Without an entry they are derived from the atlas regions Skin_Body and Skin_Arm with the WoW proportions (torso upper 25 %, torso lower 12.5 %, leg upper 25 %, leg lower 25 %, foot 12.5 % of the body strip; arm upper 37.5 %, lower 37.5 %, hand 25 % of the arm region).
* Equipment changes: `EquipVisibleItem` / `RefreshVisibleItems` schedule the player; `WildStarArmorUpdate` (called every frame from `DayNight::Update`) rebuilds the model through `UpdateDisplayInfo(1)` 400 ms after the last change, only if the item list differs from the one the model was built with.

## The placer window

`/wsarmor` (file `WoWClient/Interface/WildStarDebug/WildStarArmor.lua`, loaded like the other debug windows).
Pick a section (AU AL HA TU TL LU LL FO), edit X / Y / Width / Height in atlas pixels (Enter, or the - / + buttons with the Step field), mirror X / mirror Y / swap X-Y. "Rebuild after every change" rebuilds the model 0.7 s after the last edit; "Apply now", "Save file" (writes the table), "Reload file".
The file is the result to send back: one line per section `<model key> <section> <x> <y> <w> <h> <flip>` with the pixel values in a trailing comment.

Lua functions: `WSArmorInfo`, `WSArmorGet`, `WSArmorSet`, `WSArmorApply`, `WSArmorSave`, `WSArmorReload`.

## Offline checks

* `wow_armor_cli` (pastes given BLP files with default rectangles of a 1024 atlas): the plate set `ItemDisplayInfo 1184` (extracted with `tools/wow_item_textures.py extract 1184 <dir> M`) decodes and blends correctly.
* `character_cli` with `WS_WOW_BLP_DIR=<dir with sec0..7.blp>` and `WS_ATLAS_BMP=<out.bmp>` composes Human_F with one WoW item through the real `Compose` path: the WoW sections appear in the Skin_Body strip and the Skin_Arm region of the generated atlas.
* The engine and client build; the game window was **not** used.

## Limits

* Texture only: no helm / shoulder / cape models, no sleeve or robe geosets, no WoW weapons on WildStar models yet.
* A rectangle is an approximation of a UV island; some sections will not fit perfectly (front / back halves, flipped islands). The flip bits help with mirrored islands.
* Character creation / selection screens do not show WoW armor (in world only).
* Old atlas revisions of an edited table are dropped from the generated texture map (`EraseGeneratedTextures`); the converted model of every revision is rebuilt by the normal model load (1 to 3 s).
* `kCacheVersion` was not changed (character models are not disk cached).

## dbg104: preview of the atlas and no more lag spike per edit

* **Lag spike:** every edit rebuilt the whole 30 MB character model (`UpdateDisplayInfo`, 1 to 3 s). Now `WildStarArmor.cpp` `SwapAtlas` composes only the colour atlas (`WSCharacter::ComposeBodyAtlas`, same slots / layers / WoW overlay as `Compose`, appearance and native items read from the live model path) and replaces the texture of the live model instance (`CM2Model::m_textures[i]`, the entry that is the body atlas; the new texture is uploaded immediately). The full model rebuild remains the fallback if the model has no WildStar body atlas. Equipment changes use the same fast path.
* **Preview (left of the window):** the skin atlas that is on the model right now (`WSArmorAtlas()` returns the texture name; including the pasted WoW armor) 512 x 512, with the eight section rectangles drawn over it (own colour each, selected one yellow with a corner handle). Drag a rectangle to move it, drag the bottom right corner to scale it, click another rectangle to select it; the model texture updates while you drag (every 0.4 s) and after release. The fields in the window follow the drag.
* `tools`: `lua_check` (`wow_armor` Lua syntax check with the client's Lua 5.1): `build/x64/bin/Release/lua_check.exe <file.lua>`.
* Not verified in the game window: whether the UI texture loader shows the generated `WS\characteratlas\...blp` texture in the preview (it uses the same `WS\` prefix path as model textures); if the preview stays dark the rectangles are still drawn and editable.


## dbg105: Skin atlas vs. armor atlas, preview fix

* Two different atlases exist per WildStar race: the **skin atlas** (ComponentLayoutId 2: Skin_Body, Skin_Arm, Skin_Eye, Skin_Hair, Skin_Head, Skin_FacialHair) is what the naked body mesh uses, the **armor atlas** (layout 10: Armor_Chest, Armor_Gloves ...) only the WildStar armor mesh parts. The placer pastes WoW textures into the *skin* atlas, so its rectangles are not the layout-10 regions.
* Measured on the UV islands of the Human male body mesh (1024 x 1024, uv1): body strip x 0-320 = torso y 0-270, pelvis -400, thigh -610, shin -810, boot -1024; arm strip x 320-832 = shoulder-elbow 337-500, forearm 500-650, hand 650-800. The default rectangles now follow these cut lines (torso upper 26.4 %, lower 12.7 %, leg upper 20.5 %, leg lower 19.5 %, foot 20.9 % of the strip; arm 35 / 30 / 35 %).
* Preview: the UI texture loader does not resolve generated `WS\...` textures (black panel). `WSArmorAtlas()` now writes the current atlas to `WoWOverride\Interface\WSArmortlas_<n>.blp` (previous file deleted) and returns `Interface\WSArmortlas_<n>`.

## dbg106: WoW textures on the shared armor atlas (layout 10)

* The skin atlas path is gone: one placement table (key `armor`, `WoWOverride\ws_armor_regions.txt`) now serves **all** WildStar models, because ComponentLayout 10 (Armor_Chest / Sleeves / Gloves / Pants / Boots ...) is the same for every race.
* WoW items are shown by native WildStar armor meshes ("carriers"): chest (shirt / chest / tabard / bracers), pants, boots, gloves. Defaults are the Reflex_001 set (ItemDisplay 435 / 437 / 434 / 436, meshes exist for all 13 race/sex models, UVs verified: chest = Chest + Sleeves, pants = Pants, boots = Boots, gloves = Gloves). Replace them in `WoWOverride\ws_armor_carriers.txt` (`<native slot 1|2|5|6> <ItemDisplay id>` per line, needs a restart). A native item in a slot always wins over the WoW item for that slot.
* Default rectangles (px of 1024): upper arm 768,192 256x192; lower arm 768,384 256x192; hand 768,576 256x448; torso upper 320,192 448x384; torso lower 320,576 448x192; leg upper 0,384 320x160; leg lower 0,544 320x160; foot 0,704 320x320. Unpainted parts of the carrier UVs are neutral grey.
* Live update: same carrier set -> only the armor colour texture of the live model is swapped (no model rebuild); another carrier set (item put on / taken off) -> `UpdateDisplayInfo(1)`.
* Fixed in the same step: `IsBodyAtlas` compared against `"characteratlas\v4_"` (a vertical tab, the backslash was not doubled), so `WSArmorAtlas()` found no texture (black preview) and the fast atlas swap never ran. Revision numbers start at 2000 so cached models of the skin atlas mode (revision < 2000 in the path) are not reused.

## dbg107: armor parts stayed in T-pose above the character

Armor part M3s (native `~e` items and the carriers alike) contain copies of body bones with `modelBoneId` 65535. `Append` matched them only by identical bind matrix, which failed for ~20 bones per part, so they were appended as new bones that no animation drives: the part stood in bind pose (T-pose, lifted by the Stand clip offset) above the character. The bone record has a hash at +8 (`M3::Bone::hash`, unique per skeleton, equal for the same bone in body and parts): unnamed bones are now matched by hash first. Bone count after composing equals the body's again (Human M 212, Granok M 190, Draken M 203). Revision base is 3000 so cached models built with the bug are not reused (native `~e` armor models built earlier stay in the cache: delete `WildStarContent\Cache\m3` once).

## dbg108: armor almost invisible (alpha)

Armor materials carry 0.15 in the opacity field (every mesh of Reflex_001, measured with `character_cli` + `WS_CHAR_DUMP`). `M3ToM2` promotes an opaque material with opacity < 0.996 to alpha blending, so the carriers (and native `~e` armor) were drawn at 15 % opacity. `Compose` now sets the opacity of armor part materials to 1 (all sections of the composed Human M model are opaque again, blend 0). Revision base 4000 so cached models of dbg107 are not reused.
