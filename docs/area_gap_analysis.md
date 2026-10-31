# .area – was fehlt noch

Basis: `docs/area_check_all.txt` (15 051 Dateien, 0 Fehler), `tools/area_subchunks.py`, Stichprobe 115 Maps (je ≤12 Tiles).

## 1. Dekodiert und im ADT genutzt
- KNHC (Zellen): Höhe (MCVT), Normalen (MCNR), Layer/Blend (MCLY/MCAL), Löcher, Clutter (MCLT-Erweiterung)
- pORP (Props, 104-B-Records): MDDF/MODF, Quaternion-Erweiterungen (MDQT/MOQT), Strukturen (.i3/.dgn → WMO)
- PORP-Subchunk je Zelle: Prop-ID-Listen (701 731 Zellen)

## 2. Dekodiert/erkannt, aber nicht umgesetzt
| Daten | Umfang | Ziel in WoW | Stand |
|---|---|---|---|
| Wasser: `GtAW` + `Psbw` (je 35 573 Zellen, ~2,4 / ~3,4 KB) | Western/LevianBay 14 pro Datei, NewPlayerExperience 52, Whitevale 27, Hycrest 25 | MH2O + WorldWater*-Tabellen | nicht exportiert, Header `01000000 06000000 8d000000 76000000` gemeinsam |
| Zell-Bit 13 (1 009 846 Zellen) / Bit 3 | Farbkarte 65x65 (BC2 / RGB565), Neutral ca. (131,129,131) | MCCV | **umgesetzt (dbg56, im Spiel ab dbg60 sichtbar; WDT-MPHD-Flag 0x2 nötig, sonst Vertexformat ohne Farbe)** (145 Vertices, neutral auf 127 normiert, Alpha 255; Alpha-Nibbles von Bit 13 bleiben ungenutzt, Bedeutung offen) |
| Zell-Bit 28 (1 326 542) + Bit 16 | 4 WorldZone-IDs je Zelle, Bit 16 wählt je Teilfläche | MCNK.areaid / AreaTable.dbc | **umgesetzt (dbg61)**: Area-ID = 900000 + WorldZone-ID (häufigster Slot), 3436 AreaTable-Zeilen mit Namen aus en-US.bin (`tools/ws_zones.py`, `tools/ws_text.py`); Musik/Fog (soundZoneKitId, Light.dbc) nicht abgebildet |
| `Druc` (23 523 Zellen, 32–80 B) | Punktlisten (Eastern 11/Datei, AstrovoidPrison 7,5) | unklar (Dekal/Pfad/Trigger) | unentschlüsselt |
| TRUC/CURT (968 Dateien) | u32-Count + 6×u32 Records | Streckenpunkte/Kurven? | Struktur bekannt, Semantik offen |
| `_Low`-Tiles | LOD-Höhen | WoW-LOD/Fernsicht | ignoriert |

## 3. Vorhanden, nicht dekodiert (Zell-Bits)
bit 22 (267 k), bit 9 (36 k), bit 10 (35 k), bit 26 (11 k), bit 11 (881), bit 31 (57); bits 14/15/20/29 (~20 k) nur teilweise. Nächster Schritt: Bit-Block-Größen pro Bit messen (`area_subchunks.py` erweitern) und mit Zell-Werten (Höhe/Layer) korrelieren.

## 4. ADT-Chunks, die der Builder nicht schreibt
MH2O (Wasser), MCCV (Vertexfarben), MCSH (Schatten), MCLQ nicht nötig, MTEX-Flags/Specular, MFBO (Flugbegrenzung). Zonen/Area-IDs werden pauschal gesetzt.

## 5. Prop-Records (104 B)
Unbekannte Felder (Tint, Flags, LOD-Distanzen) werden ignoriert; Strukturen am Tile-Rand werden nur vom Ursprungstile referenziert.

## Empfohlene Reihenfolge
1. Wasser (größter sichtbarer Gewinn: GtAW/Psbw → MH2O)
2. Bit 28 → Zonen (Namen/Musik/Sky-Auswahl)
3. Bit 13 → MCCV
4. Druc/CURT-Semantik, unbekannte Bits
