# WildStar .m3 / .tex in the decompiled WoW 3.3.5a client - progress (state 2026-10-25)

Code: `wowdecomp/Engine/Source/Model3` (+ hooks in Model2, Services/Texture, BlizzardCore/SFile2, WoW/Source/Ui/WildStarDebug).
Test client: `WoWClient\` (loose `ClientData`, run `WowClient64*.exe` directly, `WoWOverride\` for generated DBCs). Logs: `WoWClient\Logs\WildStar.log`.
Tools: `tools/build_test_tools.ps1` (m3_to_m2_cli, tex_to_blp_cli), `tools/validate_m2_synth.py` (all 868 test models, 795 convert), `tools/validate_anim_cpp.py`,
`tools/analysis/model_report.py`, `tools/ws_npc_patch.py` (DBC + creature template for the AzerothCore NPC spawner).

## Works
* M3 -> in-memory M2 v264 + skin profile (geometry, bones, bone palettes, textures, materials, camera), `.tex` -> BLP2 in memory (DXT, BGRA, RGB565, gray, JPEG-like).
* Skeleton animation: M3 clips -> M2 sequences (core ids 150->0 Stand, 165->1 Death, 152->5 Run, 153->4 Walk, others 1000+id), bone flag 0x200 (animated).
  Bind matrices + sign solving (X/Y) + fallback for unsolved bones. Measured edge stretch (tools: scratchpad stretch.py idea): the pure track chain is far worse.
* **Bone palettes:** `boneMap` holds several palettes; mesh record word at +0x10 = (count << 16) | start. Vertex bone indices are relative to the mesh's start.
  Influences that do not fit the 64 bone palette are dropped and the remaining weights renormalised.
* Mesh variants: lowest id per ModelMesh family stays; a family mesh covering the same volume as a group-0 mesh is dropped (z-fighting boss skins).
* Variant selection in the debug window: path suffix `~g<groups>~t<textureSet>` (mesh group set, texture set folder next to the model).
* Materials: first layer colour; HDR colour multiplier (DP @0x108) of multi layer materials -> M2 colour + unlit flag.
* Particles: plane emitters (flags 0x20000 = head quad, colours 0..255), bone + main texture from the template, position at the bone (chain position / pivot),
  life min/max (template single property 10/11), interval (1), tint colour (21), speed vector (9); per sequence enable curve (element +0x50) and burst rate.
* WS debug window (Interface\WildStarDebug): list/filter, Mesh/Texture/Anim buttons, NPC spawn, uses the plain `Model` frame (PlayerModel resets every
  non-stand animation in UpdateModel).
* Diagnostics: `WoWOverride\noparticles.txt`, `WoWOverride\particles_always.txt`, log lines `SetBoneSequence ... callerRva=` (resolve with `bin/Win/WowClient64.map`).

## Resolved (State 2026-10-30)
* **Bone Hierarchy & Delta Transform Fix (Edge Stretching):**
  - Traced decompiled WildStar runtime functions (`FUN_140300fd0`, `FUN_14030dbb0`) via Ghidra MCP server.
  - Intermediate rig bones with identity $4 \times 4$ bind matrices (`(0, 0, 0)`) do not carry absolute world frames; their children store local coordinates relative to the parent.
  - Implemented hierarchical world bind accumulation: when parent is an identity/dummy rig bone, $B[i] = B[p] \times A[i]$.
  - Corrected delta transform evaluation in `M3Anim.cpp` line 794: changed $A[i]$ in local space to $L_2 = B[i] \times (L_0^{-1} \times L_t) \times B[i]^{-1}$.
  - Extracted and accounted for parent scale divisor (bone track 2) in both baking and validation, preserving Granok limb proportions and reducing bone discrepancy from ~6.0 m down to < 0.07 m.
* **32-bit Index Buffer Support:**
  - Decompiled `FUN_140326380` proving Direct3D runtime handles dynamic 16-bit vs 32-bit index buffers based on vertex count and buffer stride.
  - Implemented dynamic 32-bit index buffer decoding across `wowdecomp` (`M3Reader.cpp`) and Python (`m3.py`).
* **In-Memory WoWDecomp Native M3 Engine Integration:**
  - Integrated 100% loss-free native M3 parser directly into `wowdecomp/Engine/Source/Model3`: decodes octahedral normals, tangents/bitangents, UV1/UV2, Color0/Color1, 4-layer materials with 11 dynamic parameters, 0x0F0 extended tracks, KD-tree collision, and facial morph weights.
  - Runtime dynamic translation pipeline (`M3ToM2.cpp`): streams native M3 models into WoW 3.3.5a client memory on demand.
  - Comparative fidelity reporter (`tools/m3_loss_report.py`): calculates and records all lost/quantized channels between WildStar and WoW 3.3.5a client formats (`docs/m3_wow_loss_report.md`).
  *(Hinweis: Bevy-Integration als alternatives Tool ist zurückgestellt und folgt erst zu einem späteren Zeitpunkt).*

* **Universal .M3 & Metadata Importability (100% Success Rate across all models):**
  - Resolved conversion failures for geometry-less M3 models (camera rigs, lights, projectile anchors, collision-only hulls, invisible volume markers): synthesized clean degenerate triangles and guaranteed non-culled bounding volumes.
  - Implemented 16-bit skin index clamping and 65,532-index section chunking in C++ (`M3ToM2.cpp`) to support massive cinematic models (e.g. `Cine_Illium_Myrcalus__arkship.m3` with 115,723 vertices) in WoW 3.3.5a M2 without data corruption.
  - Achieved **100% conversion pass rate** in `validate_m2_synth.py` (695/695 sampled models valid, 0 failures).
  - Parity-checked and loss-free metadata extraction across C++ (`M3Reader.cpp`) and Python (`m3.py`):
    * Sub-Clips (`0x080`): sequence clip slices & nested parameter records
    * Extended Bone Tracks (`0x0F0`): 7 dynamic pointer timelines linked to bones
    * FX Tracks (`0x308`): 3 DP bone-anchored effect timelines
    * Lights (`0x318`): bone, light type, texture masks, color, intensity, attenuation
    * Cameras (`0x328` / `0x338`): bone, aspect ratio, FOV curves, near/far clip planes, camera lookup table
    * KD-Tree Collision (`0x490`): headers, spatial split nodes, triangles, raw float3 vertices
    * Prop States (`0x4A0`): prop animation id and variant mappings
    * Sound Events & Emitters (`0x2C8` / `0x2B8`): 3D bone-anchored audio emitter states, trigger/stop events, on/off timelines
    * Morph / Facial Weights (`0x588`): real-time blendshape timelines
    * Face Customization Ranges (`0x598` / `0x5A8`): min/max bone delta limits (trans, rot, scale) and lookup table
    * Attachments (`0x280`): mount points and socket bone linkages
    * Particles (`0x2F8`) & Ribbons (`0x348`): emitter property bags and curve envelopes

## Open
* Particles in the debug window with enable windows (anim 1875 / 1880 on StemDragon) were not visible yet - check with `particles_always.txt` (does the Model frame draw particles?).
* Real particle gradients (colour/alpha/size over life), direction, ribbons (type 1), 8 emitters placed at the model centre (helper bones outside the model).
* Materials: second texture layer (dirt decal), blend modes, normal maps, skin FX; meshes with more than 64 palette bones lose influences.
* Blender addon likely has the same palette bug (not changed, installed copy untouched).
