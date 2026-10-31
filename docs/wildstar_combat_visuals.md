# Class telegraphs and native spell effects, compatibility v2

2026-10-29. Installed on top of the 30-ability starter set.

## Use

Fully restart with `WoWClient/WowClient64_WildStarTelegraph_v2_test.exe`.
The normal ability bar `/wsabilities` remains available. Telegraphs respond to
confirmed spell events, not button presses. Native M3 spell effects are attached
through SpellVisual/SpellVisualKit/SpellVisualEffectName records.

- `/wsvisuals on` / `/wsvisuals off`: enable/disable combat telegraph overlays.
  This setting does not suppress the engine's spell particle/model effects.
- `/wsvisuals compat`: show engine area circles or a single-target marker.
- `/wsvisuals native`: show an explicitly cosmetic original-shape preview.
  Original telegraph geometry does **not** change the compatibility spell's hits.

The single-target marker uses the visible unit's current target, or the caster
when an appropriate target is unavailable. It is not proof of the actual heal or
projectile destination (mouseover, self-cast modifiers, and later target changes
can differ). Area spells use their installed SpellRadius value around the caster.

## What was connected

All 30 starter abilities have raw native telegraph records. The exporter retains
all shapes, flags, prerequisites, offsets, timings and original float precision;
it no longer selects one CSV row and rounds its dimensions to two decimals.

57 native M3 FX assets were found in these visual groups. Offline conversion
passed for 54. Three assets have no renderable geometry in the current converter;
those are not installed as supported FX. The reviewed phase/attachment mapping
produced **47 bindings across 23 abilities**. The other seven retain WoW effects:
Power Link, Flak Cannon, Unstable Anomaly, Crush, Stealth, Stagger, Quick Draw.
Their native proxy/child, conditional or unsupported visual dispatch still needs
separate implementation. No complete native sound-event dispatcher is claimed.

Only native visualType 5/6 models with supported phase/attachment, zero offset,
no prerequisites, bounded scale and successful offline conversion are used.
Native stage 1 maps to a WoW precast kit (to the cast kit for instant spells),
stage 2 to cast/impact, with explicit caster/target flags. BASE, CHEST/CHESTCTR,
HEAD and weapon/muzzle attachments map to WoW kit slots. Weapon/muzzle slots,
stage timing and retained stock sounds are **compatibility approximations**,
not recovered original dispatch. Existing missile/state phases remain available.
Original native particle colors, textures, mesh and animation data pass through
the existing M3 reader. Actual visual quality/lifetime still needs live testing.

## Client fixes

- Stock 3.3.5a unit-spell events contained only unit/name/rank/cast-count. The
  client now appends the real spell ID as argument five, preserving the original
  four arguments. This also prevents false matches such as WoW Druid Shred.
- `WSTriggerTelegraph` now returns an individual handle. `WSCancelTelegraph(id)`
  removes that cast without displaying its completion flash; zero clears all.
- `WSGetUnitWorldPosition(unit)` supplies positions for visible unit tokens.
  No guessed map-normalized coordinates or remote-at-player fallback is used.
- Cast bars supply actual preparation time. Successful instant casts display
  only after success; failed casts never create a new area. Interrupts remove
  active overlays, world transitions clear them, and unit-token aliases dedupe.
- Renderer inputs are bounded/finite, active overlays are capped at 128, supplied
  facing is preserved, and per-cast synchronous logging is opt-in through
  `WS_TELEGRAPH_LOG`.

The native preview currently supports unconditional circle/cone/rectangle shapes
with approximate texture geometry. Conditional multi-shapes, original offsets,
arbitrary cone angles and ring inner radii are not reproduced. Data is retained
for subsequent renderer work. The default compatibility mode avoids promising
native cone/rectangle hits for a WoW single-target spell.

The addon renders the player and observable unit tokens (target/focus/party/raid,
etc. as supplied by the client). It does not add an all-nearby-units broadcast
protocol. It never applies damage, heals, changes resources or sends a cast.
The old 750-damage Lua executor is not registered for any new starter spell ID.

## Package and validation

- `tools/ws_combat_visuals.py`: raw TBL -> explicit visual delta + addon metadata.
- `tools/ws_combat_visuals_install.py`: stopped-core installation, exact hash
  guards, backups, readback, rollback on write failure; no SQL writes.
- `build_wildstar/combat_visuals_v2/manifest.json`: native hashes, models, counts.
- `build_wildstar/combat_visuals_v2/native-visuals.json`: full raw visual and
  telegraph records plus selected bindings and unsupported paths.
- `build_wildstar/deployments/combat-visuals-live-20261029/installation.json`:
  installed file hashes and backups.

Spell gameplay fields are preserved: only column 131 (SpellVisual reference)
changes on owned starter rows. Unrelated DBC records remain unchanged. Tests
cover cast confirmation, interruptions, instant casts, duplicate unit tokens,
unknown/colliding IDs, disabled display, zone cleanup, raw multi-shape retention
and visual-only changes. 91 combat/export tests passed. Release client build and
visual-reference checks passed. Offline conversion does not prove that every
native effect looks correct in game; live cast validation remains outstanding.

The separate MSBuild project copy `WowClientTelegraph.vcxproj` builds a uniquely
named executable without changing the shared CMake output-name setting. The
existing client executable is not overwritten.
