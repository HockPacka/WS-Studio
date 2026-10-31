# NexusForever NPC completion (AzerothCore adapter)

Source: `NexusForever.WorldDatabase`, read only. Entity type 0 (NonPlayer) supplies 16,940 recorded placements on Western, Eastern and NewCentral map windows. Other entity types are not converted to creatures.

The existing phase-1 import already placed 12,339 nonhumanoid entities. This completion adds the remaining 4,601 humanoid placements and 2,144 previously absent templates. Existing rows are matched one-to-one by native Creature2 entry, registered map and float-tolerant position (0.025 WoW units); they are not inserted again or deleted.

## IDs and appearance

- Template entry = 4,100,000 + native Creature2 ID.
- New spawn GUIDs = 4,112,339 .. 4,116,939 (allocated after every occupied GUID in the owned namespace).
- Base displays are checked against BOTH installed client and server CreatureDisplayInfo/CreatureModelData files; existing IDs are reused, not renumbered.
- Native display race/sex selects the actual original character model. ItemDisplay components from the entity's Creature2DisplayInfo are merged by native item slot; Creature2OutfitInfo overrides those slots. Each new spawn receives its descriptor in the existing `wildstar_appearance_profile` table. The existing Lua appearance bridge synchronizes it with compatible clients.
- The separate `wildstar_nexus_spawn` registry records source file/entity ordinal, spawn GUID and original creature/world/area/display/outfit IDs for all 16,940 placements. Native IDs are not repurposed to overwrite stock WoW templates.

Source World assets are resolved through the registered map-window manifest. Coordinates retain the phase-1 axis/scale conversion and original yaw. Nine map windows receive new spawns: 5000, 5001, 5002, 5100, 5101, 5103, 5200, 5201, 5203. Original source world IDs remain available in the registry even when several native worlds reuse the same geometry.

## Asset exceptions and material support

17 component/body-model combinations reference original armor models not present in the extracted assets (79 component occurrences across 78 spawns). These pieces alone are omitted; the NPC is still placed with its correct native creature/display/outfit references. Exact exceptions are in deployment `component_preflight.json`, and per-spawn `omitted_items` in `plan.json`. No substitute race model or guessed armor model is used.

Complete NPC outfits may use fixed M3 material maps instead of ComponentRegion atlas tiles. Character composition now detects that path, retains the separate original fixed color/normal maps for each material, and updates only dynamic skin bindings to the composed body atlas. This prevents atlas composition errors and flattening of distinct skin/armor textures. Existing regional native armor and WoW body overlays retain their separate paths.

## Validation and deployment

`tools/ws_nexus_complete.py --server <Core>` prepares the plan and SQL; `--apply` requires successful native-component preflight for every distinct descriptor. `nexus_profile_cli` resolves profile paths and composes native body/head/hair/armor components. It skips the repeated standing-height animation calculation for bulk validation; runtime composition still computes it by default. The existing 15-character armor/alpha regression covers the normal runtime path.

Deployment artifacts: `build_wildstar/deployments/nexus-completion-20261028/` contains the native-ID plan, component audit, profile inputs/logs, transactional `install.world.sql`, exact `rollback.world.sql`, pre-install SQL backup and installation receipt. Tables use InnoDB. SQL inserts only new creature/template/model/profile rows and the owned registry; no stock creature rows are rewritten.

The adapter needs a graceful worldserver restart to load new templates/spawns and the appearance profile cache. `tools/ws_world_console_control.py` can send Ctrl-C only after checking the console process allowlist; it never force-terminates the core. Start_World.bat explicitly recommends Ctrl-C for saving player state. Authentication and database services are left running.

Client: `WoWClient/WowClient64_NexusNPCs_test.exe` includes the fixed full-outfit material path and the preceding single-level texture-upload fix. Use this executable for the new NPC appearances.

This is a placement/appearance import. WildStar quest, vendor, combat AI and pathing logic is not converted here. NPC levels use the existing WoW 1..80 mapping and factions the prior adapter's friendly/neutral/hostile name heuristic. Native outfit dye-color-set overrides are not fully represented by the current appearance descriptor. Live visual verification of every NPC is outstanding.

## Activation follow-up

The initial row-at-a-time import exceeded the adapter's 90-second query timeout. InnoDB rolled it back completely (registry/profile counts zero, original 12,339 spawns intact). The corrected importer batches 500 rows per INSERT in one transaction. It completed successfully and verifies all 16,940 registry/creature joins and all 4,601 profile rows. Re-running --apply verifies the installed registry and makes no changes.

The first restart exposed pre-existing missing MapDifficulty entries for the custom map windows: every native spawn emitted a warning. The reference core logs this but does not skip the creature. `tools/ws_nexus_mapdifficulty.py` adds normal-difficulty rows for the nine populated Nexus map windows to client/server MapDifficulty.dbc, after preserving both originals. Existing stock rows are unchanged. The resulting DBC and exact additions are saved in the deployment folder; the portable client copy is updated. The first core was stopped gracefully again, and the final restart uses native file handles for logging.

Final activation verified: worldserver PID 11920 is listening on port 8085; its ready log confirms `[WildStarAppearance] loaded 4601 profiles; catalog 0f373c45`. `worldserver-active.log` contains zero missing-difficulty warnings. The 16,940 registry rows match 16,940 creature rows. Full composition preflight: 2,773 passed / 0 failed. Reapplication verifies those registry joins and performs no changes.
