# WildStar-Rassen in der Welt und auf dem Server (dbg72 bis dbg80)

Alles hier ist im Spiel bestätigt (Mechari, Draken, Granok, Mordesh, Cassian), Stand 2026-10-25.

## Befunde und Lösungen
| Problem | Ursache | Lösung |
|---|---|---|
| In der Welt Mensch / Tauren-Kuh | Der Core sendet für Rassen 22..29 stock WoW-Displays (3827, 3770, 3470 ...) und teils Geschlecht 2 ("none"), obwohl `ChrRaces.dbc` die WildStar-Displays hat | Eluna-Skript `Core/lua_scripts/WildStarRaceDisplay.lua` (`tools/ws_server_race_lua.py`) setzt Native- und Display-ID aus ChrRaces; `creature_model_info` der Rassen-Displays mit Gender 0/1 (nicht 2); Client: `WildStarPlayerDisplayId`, `WildStarSex` (Fallback PLAYER_BYTES_3) in `Unit_C.cpp` |
| Spieler in der Welt ohne Aussehen (schwarz/grün/grau) | Das Weltmodell wurde ohne `~c`-Variante geladen; die Ersetzung in der CharacterComponent erreichte das Weltmodell nie | `CGUnit_C::GetModelFileName` und `UpdateDisplayInfo` liefern `WSCharacter::ModelPath(...)` mit den Aussehen-Bytes |
| WoW-Startausrüstung färbte den Körper | Items werden auf eine leere CharSections-Basis gelegt | `CCharacterComponent::AddItem` überspringt WildStar-Rassen; `CharStartOutfit.dbc` der Rassen 22+ leer (`tools/ws_empty_outfits.py`, `ws_races.py`) |
| Modelle schweben | Die Stand-Animation hebt die Wurzel (Mechari 0,92 m) | `Model::groundLift`: Wurzelknochen aller Sequenzen werden um die Fußhöhe der Stand-Pose abgesenkt (`Character.cpp` `StandFootHeight`, `M3Anim.cpp`) |
| Kamera zu hoch, Türen zu klein | Kollisionshöhe aus dem M3-Header-Volumen (Mechari 7,9 m); Kamera = Kollisionshöhe - 0,17 | Bounds aus Bind-Pose-Vertices (`character_cli --bounds`), Skalierung der Rassenmodelle auf höchstens 2,4 m (`ws_npc_patch.py`), `CreatureModelData`-Flags `0x804` |
| Customization ging verloren | Geschlecht 2 vom Server (siehe oben) -> falsches Modell, `Compose` scheiterte | wie oben |
| Attachments / Knochen | M3-Attachments wurden nicht konvertiert | Reader liest Array 0x280, `M3ToM2` schreibt WoW-Attachments (Hand R/L 1/2, Helm 11, Kopf 20, Rücken 12/30, Schilde 0/28, Namen 18, Basis 19, Zauberhände 21/22, Scheiden 26..28, Specials 23..25) und Lookup, Kopf als Schlüsselknochen |

## Server-Daten
- `Data/dbc`: ChrRaces, CharStartOutfit (leer für WildStar-Rassen), CreatureDisplayInfo/ModelData (ab ID 200000, `tools/ws_server_dbc_merge.py`, Backups `*.bak_ws_*`).
- DB `acore_world`: Tabelle `ws_race_customization` (Optionslisten je Rasse und Geschlecht, `tools/ws_server_options.py`), `creature_model_info` der Rassen-Displays, NPC-Spawns (`ws_spawns.py`).
- Aussehen: fünf WoW-Bytes; Eye Color (hairColor Bits 4..7) und Body Type (skin Bits 4..7) darin gepackt.

## Offen
- Warum der Core stock-Displays sendet, ist nicht geklärt (Skript ist ein Umweg).
- Body Type wirkt noch nicht auf das Modell (Reglerwerte); Stufe 2 der Optionen (Ohren, Hörner, Schmuck, Zubehör, Farben).
- Ausrüstung auf WildStar-Modellen unsichtbar.
