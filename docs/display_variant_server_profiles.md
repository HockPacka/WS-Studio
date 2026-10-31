# DisplayVariant / server-owned appearance profiles (2026-10-26)

## What is implemented

The existing M3 browser can now save its selected appearance through a separate
AzerothCore Eluna adapter for both players and persistent creature spawns.
The server retains the descriptor and sends it to compatible nearby clients.
New combinations do not allocate or replace CreatureDisplayInfo rows.

Profile data includes an existing base display, seven character choices, native
Creature2DisplayInfo / Creature2ModelInfo preset, mesh groups, texture set, and
up to 20 native ItemDisplay overrides. The native preset loader now composes
humanoid body/head/hair components and clothing instead of only applying mesh
IDs and texture replacements. Explicit character choices override preset body
components; explicit ItemDisplay overrides take precedence over both.

Clothing uses a separate armor color/normal atlas (ComponentLayoutId 10).
Skin and armor are not painted into the same UV space. Item2Type supplies the
native slot for each ItemDisplay; the highest-priority component in each slot
is used. Generated atlas keys include a hash of selected slot/display pairs to
avoid sharing the wrong clothing or face between otherwise equal profiles.

## Use

1. Start `WoWClient/WowClient64_DisplayProfiles_test.exe` and log in as a GM.
2. Open `/ws`, select a model, then click **Customize** (or `/wsappearance`).
3. On the first run click **Reload server Lua**. The status should become
   **Server connected**. The command is the existing `.reload eluna` GM command.
4. Cycle character options or **Native Display preset**. The Human/Cassian
   button selects the two native Human customization contexts.
5. Optionally enter native ItemDisplay IDs, separated by commas, and press
   Enter. Example clothing: `4160,4161,4159,4162` (Medium_008 chest/pants/gloves/boots).
6. **Apply to target** saves the selected player or persistent creature spawn;
   **Apply to me** saves the player's cosmetic profile. **Read target profile**
   loads saved settings; **Reset target/me** removes the profile and restores
   the original native display.

The existing Spawn NPC button now also submits the editor profile after its
ordinary add/set-model commands. Temporary summons without a persistent spawn
ID are rejected for persistence. Gameplay race, class, faction and existing
character appearance columns are not rewritten by this profile editor.

## Server installation and storage

Source adapter: `plugins/wildstar335a/adapters/azerothcore/WildStarAppearanceServer.lua`.
Migration: `ws_appearance_profile.world.sql`, own World DB table
`wildstar_appearance_profile`, keyed by `P + player GUID low` or
`C + creature DB spawn ID`. Existing server tables are not replaced.

`tools/ws_appearance_install.py --server <Core> --apply` stages a self-contained
Lua file, creates/checks that table, backs up the affected Lua files and any
existing profile rows, and adds a profile-aware guard to the existing race
display script. No server process is restarted. Lua reload still needs a GM
command or a normal server start. The adapter has been installed on the local
AzerothCore repack; a real server reload / live two-client check is outstanding.

The portable offline package contains the adapter, migration, shared codec and
numeric catalog. Its native table set now includes Item2Type,
Creature2DisplayInfo and Creature2ModelInfo (22 original tables total).

## Wire format and validation

The standard addon channel uses prefix `WSVPROF`. Server event 30 receives
requests; replies use Player:SendAddonMessage to the receiving player's own
name. The client rejects other sender names. Every client handshakes its model
and native-table fingerprint, including the original customization and display
tables. The current fingerprint is `0f373c45` for 34712 base models.

Codec v1: `14-number CSV;mesh-group CSV;ItemDisplay CSV`.
Header: version, base display, cosmetic race, sex, seven choice indices,
native preset kind (0 none / 1 DisplayInfo / 2 ModelInfo), native row, texture set.
Only numeric data travels; arbitrary paths or Lua code are not accepted.
200-character chunks have bounded counts, TTL and reassembly storage.

Only GM rank >=3 may save/read/remove profiles. The server resolves the actual
selected unit, checks same-map distance, validates model/preset association and
item IDs against its generated catalog, and rate-limits edits. Server state
is bound to the selected full GUID so changing targets during chunk transfer
cannot redirect an edit or reset. Server state
is sent to compatible nearby clients, including later joins via periodic
snapshots. Raw GUID field halves are formatted to hex without a floating-point
64-bit GUID conversion. The client indexes overrides by full GUID plus expected
display ID, leaving shapeshift/temporary morph display IDs alone.

Client integration is in `Area3/DisplayProfile.*`, `Ui/WildStarDebug.cpp`, the
existing Unit_C model-resolution path, and the Lua `AppearanceEditor.lua`.
Model path suffix `~e<ID>.<ID>...` carries native component/armor overrides;
`~c`, `~d` and `~i` remain the existing native choices/preset mechanisms.

## Checks and limits

* Full isolated Release client build passes.
* `display_profile_cli`: parser rejection cases, full-GUID lookup, idempotence,
  mismatched display/morph handling, reset, and all 15 playable race/sex profiles
  assembled with native chest, pants, gloves and boots pass.
* `tools/analysis/appearance_protocol_test.lua`, executed by the real Lua 5.1
  test host, passes fragment/reassembly bounds, GM enforcement, player/NPC save
  and reset, reload from mocked persisted rows, two-recipient snapshot delivery,
  and the actual client editor callbacks against the mocked server.
* The numeric Python and C++ fingerprints match. Live rendering, two actual game
  sessions and database persistence across a real core restart remain to test.

This is a cosmetic profile adapter, not the entire WildStar equipment system.
Rigid object/weapon attachment placement, arbitrary armor Dye channel editing,
SkinFX, materialData/color-shift fields, and unsupported cinematic body rigs
are not claimed complete. Raw native tables retain those fields. The original
M3 browser's existing per-model geometry/FX limitations still apply. There is
no TrinityCore/CMaNGOS adapter yet; the shared descriptor/codec can be reused.

API references: [server addon event](https://www.azerothcore.org/eluna/Global/RegisterServerEvent.html),
[addon replies](https://www.azerothcore.org/eluna/Player/SendAddonMessage.html).
