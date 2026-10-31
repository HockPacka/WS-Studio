# Charaktererstellung, Stufe 1: Eye Color und Body Type (dbg68)

Client: `WoWClient/WowClient64_dbg68.exe`.

## Idee
Die fünf WoW-Aussehensbytes (Haut, Gesicht, Frisur, Haarfarbe, Bart/Ohren) bleiben unverändert. Zwei weitere WildStar-Optionen reisen in den hohen Nibbles zweier Bytes, der Server speichert sie unverändert:

| Option | Label / Slot | Byte |
|---|---|---|
| 6 Body Type (9 Werte) | Label 25, Slot BodyType 70 | Hautbyte, Bits 4..7 (Hautfarbe in Bits 0..3) |
| 5 Eye Color (3 bis 13 Werte) | Label 7, Slot BodyEye 26 | Haarfarbbyte, Bits 4..7 (Haarfarbe in Bits 0..3) |

`WSGetAppearance` / `WSSetAppearance` (`WoW/Common/ComponentCore/WildStarAppearance.h`) packen und entpacken. Hautfarbe und Haarfarbe sind deshalb auf 16 Werte begrenzt (alle Rassen haben höchstens 11). Mit Standardwerten (Index 0) sind die Bytes identisch zu vorher.

## Geändert
- `Area3/Character.{h,cpp}`: `kOptions = 7`; `Labels`, `Choices`, `Selected`, `Normalize`, `Label` kennen Option 5 und 6. Der Rückfall für Option 3 und die Auswahl für Option 4 nehmen Label 7/25 nicht mehr, damit nichts doppelt erscheint (Granok/Mordesh zeigten Eye Color vorher als Haarfarbe).
- Variantenpfad `~c<race>.<sex>.<7 Werte>` (`Model3/ModelList.{h,cpp}`, `Model2/M2Shared.cpp`).
- `Glue/CharacterCreation*.cpp`: Zufallswahl und `WSGetCustomizationInfo` für 7 Optionen.
- GlueXML (`tools/ws_races.py`): zwei zusätzliche Zeilen `CharacterCustomizationButtonFrame6/7` über den fünf bestehenden; `WSRaces.lua` blendet sie aus, wenn die Rasse die Option nicht hat.

## Geprüft
`character_cli` für alle 8 Rassen und beide Geschlechter: 7 Optionen, Komposition ohne Fehler, Eye Color und Body Type wechseln. Eye Color und Body Type wirken über Atlas-Texturen und Mesh-Gruppen der nativen Tabellen.

## Offen / ungeprüft
- Aussehen im Spiel und Zeilenabstand der Oberfläche (7 Zeilen übereinander).
- Ob der Server die höheren Bytewerte beim Erstellen akzeptiert (AzerothCore prüft Haut/Haarfarbe gegen `CharSections`).
- Stufe 2: Ohren, Hörner, Schmuck, Gesichtszubehör, Blatt-/Kristallfarbe.
