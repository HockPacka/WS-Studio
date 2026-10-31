# WildStar zone ids: AreaTable base 50000 (16 bit safe)

AzerothCore stores the area id of a terrain cell in 16 bit (MAPS v9 area grid), so the former base 900000 does not fit. WildStar zones now use **AreaTable id = 50000 + native WorldZone id** (ids up to 56030, the stock 3.3.5a table ends below 6100).

* Client: `kAreaIdBase = 50000` in `Area3/AdtBuilder.h` (`SMChunk.m_areaid`), disk cache version bumped (Cache.h).
* Generators (all offline, output `build_wildstar/generated`, server untouched): `ws_zones.py` (AreaTable rows), `ws_music.py --all-maps` (ZoneMusic / SoundEntries, ids stay 900000+), `ws_worldmap.py`, `ws_map_links.py` (WorldMapArea / WorldMapContinent, overview pictures, server area grids `server/adapters/azerothcore/map-links/maps/*.map`), `ws_dbc_delta.py` (knows both ranges). Order: ws_zones, ws_music, ws_map_links (it reads and writes the generated AreaTable).
* Not changed: sound / music row ids (900000+), WorldMapArea row ids (900000+, 920000+ roots), character / skill ids.
* `ws_map_links.py` no longer stops on area cells that name a zone missing from WorldZone (12 ids: 657, 661, 362, 1264, 1009, 2428-2430, 1387, 1409, 1429, 278; 657 alone has 29 526 cells): those cells get no area and are counted in `map_links.json` (`unknownZoneCells`).
* Generated 2026-10-26: 3436 WildStar AreaTable rows, 14 235 server area tiles, 132 windows, 1468 zone assignments, 498 zones without a map.
* Not installed: the client still has the old 900000 AreaTable / WorldMapArea / ZoneMusic in `WoWClient/WoWOverride/DBFilesClient`, the server was not touched. dbg109 uses base 50000, so install the generated client files (`ws_zones.py --install-client` and the other tools) before testing zone names / world map.
