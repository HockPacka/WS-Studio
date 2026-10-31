# WildstarLoader.dll – plan (WildStar .m3/.tex in the decompiled WoW 3.3.5a client)

> **Revision (user decision):** the on-disk formats stay original (`.m3`, `.tex`, `.archive`). There is **no M2/BLP file conversion and no extracted data**; the DLL is a *reader*.
> Layer [3] below therefore changes from "write M2/BLP files" to "**fill the client's in-memory model/texture objects directly from the M3/tex data**"
> (`CM2Shared` + skin profile + animation tables, and a GX texture created from tex mip data). The engine still renders through its own M2 runtime structures, because a second
> renderer would be a rewrite; but no M2 byte stream is ever produced or stored. Phase 3/4 estimates stay the same (the mapping work is identical), plus ~1 week to learn which
> `CM2Shared` fields the render path really needs (from `Engine/Source/Model2/M2Shared.cpp`, `M2Model.cpp`). The memory-backed `SFileImpl` of phase 0 is then needed only for
> archive reads, not for fake M2 files.

Constraint (user): the WildStar folder stays untouched; the DLL reads `WildStar/Patch/ClientData*.index/.archive` exactly like the WildStar client. No extraction.
Host: `wowdecomp` (x64 `WowClient64.exe`, full source). Hook points are in our own source, so no byte patching/Detours is needed; only a few lines call into the DLL.

## Architecture
```
WowClient64.exe ──LoadLibrary──> WildstarLoader.dll
   SFile::OpenEx(name)  ──(1 line)──> WS_TryOpen(name) ─┐ not a WildStar path -> normal MPQ
                                                         v
 [1 archive reader] ClientData.index/.archive (sha1 -> block, raw/deflate/LZMA)   ← port of tools/Halon
 [2 virtual FS]     "WS\Art\Creature\X\X.m2|.skin|.blp" -> ClientData "Art/Creature/X/X.m3|.tex", memory-backed SFileImpl
 [3 converters]     m3 -> M2 (v264) + .skin   |  tex -> BLP2   (cached in memory, optional disk cache)
 [4 content hooks]  Lua/ModelFrame path first, DBC rows (CreatureDisplayInfo/ModelData) later
```
Why this seam: `CM2Cache::CreateShared` -> `SFile::OpenEx` -> `CM2Shared::Load` (async read) and `LoadSkinProfile` read plain M2/.skin bytes; BLP goes through the same SFile path.
If we deliver byte-exact M2/.skin/BLP buffers, the whole renderer, animation system, particles, lights and picking work unchanged.

## Phases
| # | Deliverable | Content | Estimate |
|---|---|---|---|
| 0 | DLL skeleton + hook | CMake target `WildstarLoader`, `WS_Init(path)`, 1-line hook in `SFile::OpenEx`/`FindFile`, memory-backed SFileImpl (new type or Blizzard stream), `WildstarLoader.ini` (WildStar path, prefix) | 1–2 days |
| 1 | Archive reader | .index/.archive parse (layout known from Halon), case-insensitive path tree, zlib (in ThirdParty) + LZMA (in ThirdParty) | 2–3 days |
| 2 | tex -> BLP2 | DXT1/3/5 pass-through with mip chain, ARGB/RGB565/gray decode -> uncompressed or DXT re-encode, WildStar JPG variants (decode + DXT encode), size limits | 3–4 days |
| 3 | Static M3 -> M2 | header, vertices (pos/normal/UV, color), 1 skin profile (<=65535 verts, split meshes), submeshes, texture units, materials -> render flags/blend modes/shader id, bounding boxes | 4–6 days |
| 4 | Skeleton + skinning + animation | bones (parent, pivot), vertex bone indices (4 influences), M2 tracks from clip table (ms, quaternion, translation, scale), WoW AnimationData ids from `docs/wow_animation_map_proposal.csv`, mirrored-limb handling (negative scale baked into rest + sign matrices, see `m3_animation_format.md`) | 1.5–2.5 weeks |
| 5 | Show it in game | first via `ModelFrame:SetModel("WS\\...m2")` / model viewer; then DBC rows (CreatureModelData, CreatureDisplayInfo, ItemDisplayInfo) injected at DBC load, matching AzerothCore (`azerothcore-wotlk/`) | 4–6 days |
| 6 | Extras | attachments (0x280), cameras (0x328), events/sound ids (0x2C8 -> SoundEntries), collision (0x490 -> M2 collision), bounds | 3–5 days |
| 7 | Effects (optional) | emitters (0x2F8) -> M2 particles/ribbons, lights have no M2 equivalent | 2–3 weeks, partial only |
| 8 | Terrain (optional, separate project) | `.area` -> ADT/WDT; `.area` is only ~20 % decoded | large, not part of this plan |

Realistic timeline: first textured static WildStar prop in WoW ≈ 1.5 weeks (phases 0–3). Animated character/creature ≈ 4–6 weeks. Polished (materials, attachments, DBC, server) ≈ 8–10 weeks.

## Difficulty: 6.5 / 10
Easy: archive reader, texture conversion, hook (the client source is ours). Medium: mesh/skin conversion, DBC injection. Hard: animation fidelity (mirrored bones, track layout, 3.3.5 compression), materials (WoW 3.3.5a has fixed-function-like combiners: no normal maps/PBR/gloss/parallax, no 4-layer blending), particles.

## Known hard limits of 3.3.5a (data that gets lost – to be logged by the converter)
* 4 bone influences/vertex (WildStar also 4), skin profile 65535 vertices, WoW M2 bone count practical <= 255 (WildStar max ~213: fine).
* No tangent/bitangent streams, no vertex color 2, no ninth-texture UV (f4b.zw), only 2 UV sets.
* Material layers (class/type 0..22, gloss, glow, height/parallax, color_mod) collapse to one of the fixed WoW shader combos; normal maps are dropped.
* Sound events: WildStar SoundEvent ids have no SoundEntries rows -> need a mapping table or dropped.
* Lights, face-customization ranges (0x598), hull mesh (0x510), random ranges, animated-prop states (0x4A0) have no M2 field.
* Textures > 2048 px or non-power-of-two must be resampled; BLP has max 16 mips.

## Risks / open questions
1. Hook details (SFileImpl memory type, async read path, `FindFile`/exists checks) – small spike in phase 0 settles this.
2. Exact M2 v264 field semantics for tracks (use the decompiled `M2Model.cpp`/`M2Data` structs as the reference, plus warcraft-rs in `tools/`).
3. The still-open M3 blocks (0x308/0x540/0x560/0x570/0x588) are not needed for phases 0–6.
4. Legal/safety: DLL is client-side only; keep `WOWDECOMP_DISABLE_SIGNATURE_CHECKS` off unless required (our virtual files bypass MPQ signature checks anyway).

## Recommended start
Spike (1–2 days): phase 0 + 1 + a hand-built M2 of a WildStar cube loaded via `ModelFrame:SetModel`. If that renders, the rest is "just" converters, which we can prototype in Python (existing `m3.py`) before porting to C++, or write once in C++ and reuse the same code in the Bevy tool.

## Alignment with `wow_335a_wildstar_plugin_guide.md`
The guide matches this plan: strategy 1 "In-Memory Translation" + way 1 "clean plugin interface in wowdecomp x64" (no 4 GB limit, signature checks switchable). Decisions taken from it:
* Host = `WowClient64.exe` built from `wowdecomp`; the plugin interface is a small loader for `WildstarLoader.dll` (no MinHook needed, the hook points are source lines).
* Switch point: the M2 load path checks the buffer magic (`MD20`); an `LDOM` (M3) buffer goes to the DLL. In 12340 the data arrives through `CM2Shared::Load` / `Initialize` (async buffer), so the check belongs there.
* Allocate with `SMemAlloc` so WoW can free the objects.
* **Normal maps (extra phase after 4):** "shadow data" – DLL-side `unordered_map<CM2Model*, Ext>` holding a tangent vertex buffer (from M3 f3a/f3c, already decoded) and the normal-map texture, bound in a render hook with our own HLSL; cleaned up from the model destructor. Needs tangents, which M2 has no stream for.
* **Terrain (separate project):** `.area` -> `MCNK` resampling (145 vertices, max 4 layers, MDDF placement). Blocked by `.area` being only ~20 % decoded.
* **Server side:** the same parsers for AzerothCore's `mapextractor`/`vmap4extractor` (collision from M3 `0x490` and `.area`).

## Revision 2 (user decision): no archive reader
The loader reads **loose files from `ClientData/` in the WoW root** (the layout produced by `extract_raw.cmd`, e.g. `ClientData/Art/Creature/X/X.m3`, `.tex`). Consequences:
* Layer [1] (index/archive reader, zlib/LZMA port) and phase 1 are dropped; `WS\...` paths map to `<WoW root>\ClientData\...` and are read with the normal file API.
* The "WildStar folder stays untouched" constraint is replaced by "ClientData is a copy next to Wow.exe".
* Phase 0 shrinks (no memory-backed archive streams needed); estimate for the first static prop drops by ~2–3 days (≈ 1 week).

## Revision 3 (user decision): variant A – extend the M2 functions with M3 branches
* No separate DLL required: new module `wowdecomp/Engine/Source/Model3/` (M3 + tex readers, mapping to the M2 runtime structures) with narrow entry points in `Model2`.
* `CM2Shared::Load/Initialize` and the skin-profile functions check the buffer magic: `MD20` = original path, `LDOM` = M3 path.
* The M3 path fills the same structures (vertices, skin profile, bones, sequences, textures, batches); animation, scene, culling, lighting, picking, attachments and cameras are reused unchanged.
* Extra data (tangents, normal maps, 4-layer materials) become new fields on `CM2Shared`/`CM2Model` (structs may grow because we build the client ourselves).
* Files are read as loose files from `<WoW root>\ClientData\` (revision 2). Only our built `WowClient64.exe` runs this; the original `Wow.exe` is not supported.
* The DLL / hooking / shadow-data parts of the older sections are obsolete; the converter mapping tables (phases 2–6) stay valid.

## Status (milestone 1 code written, not yet run in the client)
* `wowdecomp/Engine/Source/Model3/`: `M3Reader` (geometry, bones, bone map, textures, materials, bounds) and `M3ToM2` (builds the M2 v264 data stream + one skin profile **in memory**; axis map (x,y,z)->(z,x,y); bind-pose skeleton; one static "stand" sequence; texture names kept as `.tex`).
* Hooks (small): `CM2Cache::CreateShared` accepts `.m3`; `CM2Shared::LoadM3` reads `ClientData\<path>`, converts, finishes loading synchronously; `LoadSkinProfile` uses the in-memory skin stream; `CM2Shared` got `m_m3SkinData/Size`.
* Verification: `tools/validate_m2_synth.py` (independent parser over `build_m3test/m3_to_m2_cli.exe`): 793/868 sampled models valid, 68 have no geometry (cameras/lights), 4 "index outside mesh vertex range", 3 exceed the u16 skin index start (needs multiple skin profiles). `M2Shared.cpp`/`M2Cache.cpp` compile with MSVC x64.
* Not done yet: `.tex` texture loader hook (TextureCreate expects BLP), animation tracks, materials/blend modes, >65535 index splitting, full client build (needs CMake – not installed), in-game test (`ModelFrame:SetModel("Art\...\X.m3")`).

## Milestone 2 reached (2026-10-25): a WildStar .m3 renders in the WoW 3.3.5a world
Aurin_F spawned as an NPC (display id 225055) in AzerothCore shows as a (selection-highlighted) silhouette in the decompiled client. Needed on the way:
* sequence hash table needs empty slots (0xFFFF) – otherwise the animation id lookup loops forever (client freeze without a crash report);
* texture-weight (transparency) track needs one key of 1.0 – an empty track stays at its initial value 0 and every batch is skipped as invisible;
* per-mesh bone palettes (<= 64 bones) instead of the full 173-bone list; two-sided materials (no culling) until the winding is mapped;
* `WoWOverride\DBFilesClient\*.dbc` loose override (SFile::OpenEx) + `tools/ws_npc_patch.py` (DBC rows + generic NPC entry 4000000) + in-game debug window with Spawn/Del NPC buttons.
Open next: JPG-like .tex decoder (almost all character/prop textures), animation tracks (bone tracks -> M2 tracks, clip table -> sequences), real material/blend mapping, winding check, models with > 65535 vertices/indices, many more models in the DBC.
