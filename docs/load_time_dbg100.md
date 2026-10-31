# Load time (dbg100)

Symptom: the loading screen stays at 50 % for minutes (cold cache: 6+ minutes, the client is not frozen, the log keeps growing).

## Findings (Logs\WildStar.log of the slow run, `tools/perf_log.py`)

* The world load (`CMap::PrepareUpdate` with `bPreload`) calls `AsyncFileReadWaitAll()` three times; progress 0.5 is the second wait. Every wait covers all tiles and doodads inside the stream distance. With `farclip` clamped to 1583 yards by `World::ValidateFarClip` the stream distance is 1979 yards = 64 area tiles (8 x 8), thousands of M3 models, structures and textures.
* In the 352 s run: 742 model loads (203 s), 453 texture waits / conversions (154 s), 38 structure roots (72 s, up to 19 s each), 63 tiles built on demand (15 s).
* `WildStarContent\Cache` is stamped with one global `kCacheVersion`. Every bump (13 -> 14 -> 15 -> 16 during one day) invalidated all converted textures (7000+ files), although only the model converter had changed. The cache write times show three full rebuild waves (10-25 23h, 10-26 02h, 03h).

## Changes

1. `Model3/Cache.h/.cpp`: the `tex` kind has its own `kTexCacheVersion`. Bump it only when `TexToBlp` / `TexJpg` change their BLP output; `kCacheVersion` (models, ADT, structures) no longer flushes textures.
2. `WorldClient/World.cpp` (`PrepareAreaOfInterest`): during the preload the stream distance and the object area are limited to 700 yards (about 9 tiles); after the preload the limit grows by 150 yards per second until the normal distance is reached, so far tiles stream in while the player is in the world. `WoWOverride\preload_distance.txt` (yards, 0 = stock behaviour) and `WoWOverride\preload_growth.txt` change this.

## Expected effect / not verified

Not measured in game. The first start after this build still converts whatever the cache lacks (the cache keeps working from now on); the preload should wait for roughly one seventh of the previous work. While the distance grows, tile loads happen on the main thread (as stock WoW does when crossing a tile border), so short hitches are possible in the first seconds.

Still open: structure roots up to 19 s (i3 -> WMO conversion on the main thread), character models of 30 MB (1 to 3.4 s per appearance change at character select), repeated "model without geometry" attempts for light models (4252 x `n_lit_point_med.m3`).
