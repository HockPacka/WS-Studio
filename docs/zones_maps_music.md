# Zonen, Weltkarten, Musik (dbg61 bis dbg62)

Alles Generierte liegt im Staging-Ordner `build_wildstar/generated` (`tools/ws_content_output.py`), nichts wird am Server geschrieben. `--install-client` kopiert in `WoWClient`.

## Zonen
- Zell-Bit 28 = vier WorldZone-IDs je Zelle, Bit 16 wählt je Teilfläche (`(v >> 3) & 3`). Der häufigste Slot gewinnt (`CellZone` in `Area3/AdtBuilder.cpp`).
- `SMChunk.areaid = 900000 + WorldZone-ID` (`kAreaIdBase`).
- `tools/ws_zones.py`: AreaTable.dbc mit 3436 Zonen, Namen aus `ClientDataEN/en-US.bin` (`tools/ws_text.py`, Format: Anzahl bei 0x40, Tabelle ab 0xA0 mit (id, Offset in UTF-16-Zeichen), Text ab 0xA0 + 8 * Anzahl + 8).

## Weltkarten
- Original: `ClientData/UI/Maps/<MapZone.folder>/UI_CRB_Revealed[_0].tex` (quadratisch, Sechseck-Raster).
- Der Client baut die 12 Kacheln (4 x 3 x 256 px, sichtbar 1002 x 668, Bild auf 668 Höhe mittig) zur Laufzeit: `M3::LoadWorldMapTile` für `Interface\WorldMap\WS_<Ordner>\WS_<Ordner><n>.blp`, Cache `WildStarContent\Cache`.
- `tools/ws_worldmap.py`: WorldMapArea.dbc (id 900000 + MapZone.ID, Area = 900000 + WorldZone-ID). Die Rechtecke sind Schätzungen (Zellen-Bounding-Box mal `--margin`), Kalibrierung mit `--margin/--shift-x/--shift-y/--flip-x/--flip-y`. Die Hex-Koordinaten der Tabellen (`hexMin/hexLim`) ließen sich nicht verlässlich in Meter umrechnen (ca. 53 bis 56 m pro Hex, Streuung etwa 7 Hex). Ein WoW-Fenster hat nur 64 x 64 Tiles, der Westkontinent ist größer.

## Musik
- Kette: WorldZone.soundZoneKitId (vom Elternzone geerbt, falls 0) -> SoundZoneKit.soundMusicSetId -> SoundMusicSet.soundEventIdStart -> SoundEvent.name -> Wwise-Event (Hash = FNV-1 des kleingeschriebenen Namens, `Events.bnk`) -> Aktionen -> `Structure_Music.bnk` (MusicSwitch/Playlist/Segment/Track) -> `<id>.wem`.
- `tools/wwise_bnk.py` liest HIRC (Bank-Version 88) und sucht in den Objekten nach Verweisen auf andere Objekt- und Datei-IDs; die Parameterblöcke werden nicht ausgewertet (Näherung).
- `.wem` = Wwise Vorbis (Codec 0xFFFF); `tools/vgmstream/vgmstream-cli.exe` dekodiert nach WAV (`WoWOverride/Sound/WildStar/ws_<id>.wav`, 148 Dateien, 3,5 GB).
- `tools/ws_music.py`: SoundEntries.dbc und ZoneMusic.dbc (id 900000 + Zone), `AreaTable.ZoneMusic` für 278 Zonen. Im Spiel bestätigt (dbg62).

## Offen
- WAV ist groß (MP3/OGG-Encoder nötig, OGG-Unterstützung von WoW ungeprüft); Dekodierung zur Laufzeit im Client fehlt.
- Musik: Stinger und Mood-Events (`soundEventIdMusicMood`, Intro) sowie Ambiente (`soundEventIdAmbientDay/Night`) sind nicht abgebildet.
- Karten: Lage der Zonenrechtecke, Kontinentkarte über mehrere WoW-Fenster.
