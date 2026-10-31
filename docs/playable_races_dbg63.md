# Spielbare WildStar-Rassen: dbg63, Vorbereitung für AzerothCore

Client: `WoWClient/WowClient64_dbg63.exe`, SHA-256 `f72a9992a3c8ca1eecc9d6cda3ff664ae17551914e1292e411df6654e26336ef`.

## Behobener Ladefehler

Die tatsächlich installierte `WoWOverride/DBFilesClient/CharBaseInfo.dbc` hatte weiterhin `fieldCount=1`, obwohl Client und originales MPQ `fieldCount=2` verlangen. Die 98 Datensätze sind jeweils zwei Bytes groß: Rasse und Klasse. Der Header wurde korrigiert und die vorherige Datei nach `build_wildstar/backups/client/CharBaseInfo.dbc.e65d4bea445707c0` gesichert. Bereits dbg62 kann mit der korrigierten Datei über diesen Ladefehler hinauskommen; ein erfolgreicher Spielstart wurde hier nicht beobachtet.

## Charakterauswahl

Die Regeln stammen aus den originalen `Race.tbl` und aktivierten, nicht als Kostüm markierten `CharacterCreation.tbl`-Zeilen. Es gibt acht spielbare Einträge, 36 Klassenpaare und 67 Kombinationen einschließlich Geschlecht. Chua haben nur eine männliche Variante; Eshara bleibt verborgen. dbg63 berücksichtigt die Geschlechtsregeln bei zufälliger Erstellung, Rassenwechsel und Geschlechtswechsel. Die UI liest nach einer Änderung das tatsächlich akzeptierte Geschlecht zurück.

Alle 67 Kombinationen haben jetzt ein Startoutfit aus einer gültigen WoW-Rassen-/Klassenvorlage; darunter Jäger-Vorlagen, die bei Human/Orc als direkte Kopiervorlage fehlten. Frauen-Namenszeilen und Outfits werden für Chua nicht mehr erzeugt.

## Server-Adapter

Der laufende Server liegt unter dem Downloads-Repack und meldet `191715d85cad+`, nicht im gleichnamigen Ordner dieses Projekts. Es wurden keine Serverdateien, Serverprozesse oder Datenbanken verändert.

Die passende öffentliche AzerothCore/NPCBots-Quellversion enthält bereits dynamische Registrierung über `RaceMgr`. Das Paket enthält vorbereitete Start-SQL für dessen World-Schema und zusätzliche DBC-Einträge für `SkillRaceClassInfo` (2494) und `SkillLineAbility` (419). Ein optionaler Quellpatch prüft Rasse/Klasse/Geschlecht serverseitig. Die ausführliche Adapterbeschreibung liegt unter `plugins/wildstar335a/adapters/azerothcore/README.md` und wird in das Paket kopiert.

Die SQL wird nicht automatisch ausgeführt. Startorte, Klassen, Werte und Rassenboni sind zunächst WoW-Kompatibilitätsvorlagen. Vollständige native WildStar-Erscheinungsanpassung ist weiterhin offen. Der ursprüngliche Charakterdatenbestand wird nicht kopiert oder überschrieben.

## Validierung

- Release-x64-Client mit Ziel `Wow` erfolgreich gebaut.
- Originale WoW-Datensätze in beiden Fertigkeitstabellen bleiben bytegetreu erhalten.
- Alle 67 Rassen-/Klassen-/Geschlechtskombinationen besitzen Startoutfits.
- Die SQL-INSERT/SELECT-Anweisungen wurden mit upstream Startdaten in einer isolierten SQLite-Testdatenbank ausgeführt; vorhandene Zeilen bleiben erhalten.
- Alle zehn DBC-Deltas bestehen Zusammenführen, Wiederholen, Konfliktprüfung und Zurücknehmen mit fremden Zielzeilen.

Die MySQL-Prozedur und der optionale Server-Quellpatch wurden nicht auf dem laufenden Repack ausgeführt oder als Serverbinary gebaut. Serverinstallation, Charaktererstellung und erneutes Einloggen stehen aus.
