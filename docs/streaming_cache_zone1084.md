# Streaming cache, zone 1084 (Eastern)

2026-10-28. Client: WoWClient/WowClient64_Streaming_test.exe.

Fixed the non-prefetched default M3 path bypassing the persistent model cache.
Character/customization/armor variants retain their existing composition path.
Added persistent WMO root/group/metadata caching with model, sector, dressing
and referenced-model source stamps. WMO textures are prefetched on the worker.
Cache versions remain model/ADT 21, textures 16: output is unchanged.

Precomputed 4064 assets around the three native zone tiles plus their neighbours
(15 tiles); skipped 4 geometryless models, no failures. The manifest expands
structure dressings and model/structure textures.
Repeat preparation: WoWClient/Precache_Zone1084.cmd, with the game closed.

Validation: full WMO root/groups/metadata and M3/skin output match the uncached
converter byte for byte. Osun sample: first 590 ms, persistent-cache reload 27 ms.
Private fixture verifies sector-stamp invalidation and corrupt-cache recovery.
Results: build_m3test/wmo_cache_regression.json, streaming_cache_osun.log and
zone1084_warmup_run.log. An in-game before/after FPS comparison is still pending.

Model logs now separate prepare and FinishLoading time; perf_log.py ignores
previous process sessions when the timestamp resets.

Startup work is documented in startup_hang_dbg109.md: gxVSync=0 resolved the
observed D3D9/DWM startup stall. WS and WS Debug defer their widgets to world
entry, hide on leaving the world and reuse them on re-entry. The automatic
preview startup file is preserved with suffix .disabled_manual_menu.
