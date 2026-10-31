# WildStar-Client-Root und Windows-Dateidialoge

Genesis verwendet **originale Clientdaten** (kein JSON-Zwischenexport). Beim ersten Start öffnet sich in Genesis die Einrichtung für den WildStar-Client-Root. Über **Durchsuchen…** erscheint der native Windows-Ordnerauswahldialog.

Wählbar sind beispielsweise:

```text
D:\GODOT\Projects\WILDSTAR-Decomp\WoWClient
D:\GODOT\Projects\WILDSTAR-Decomp\WoWClient\ClientData
D:\Games\WildStar
```

Der Root-Scanner erkennt `ClientData` und gegebenenfalls `ClientDataEN` automatisch, auch unter bis zu drei Verzeichnisebenen. Die Indexierung läuft auf einem eigenen Hintergrundthread. Die Originaldateien werden niemals geschrieben, konvertiert, verschoben oder kopiert.

Der erfolgreich ausgewählte Root wird lokal in `%LOCALAPPDATA%\GenesisRebuild\client_root.txt` gespeichert, damit keine erneute Auswahl bei jedem Start nötig ist. Über **File → Choose Client Root…** kann der Pfad jederzeit geändert werden.

## AREA-Datei mit dem Windows Explorer öffnen

**File → Open AREA…** (auch der Button **Open AREA…** im Header) verwendet nun den **nativen Microsoft-Windows-Datei-öffnen-Dialog**, mit WildStar-`.area`-Filter und Ordnernavigation. Der voreingestellte Ordner ist `ClientData\Map`; wenn bereits eine AREA-Datei geladen wurde, wird deren Verzeichnis geöffnet.

Optional: **File → Open AREA by path…** öffnet die alte manuelle Pfadeingabe. Vor dem Laden muss ein gültiger Client-Index bereitstehen.

## Abhängigkeiten

Der **Assets-Tab** in der rechten Genesis-Leiste zeigt die Indexgröße und die erkannte Anzahl `.area`, `.tex`, `.m3`, `.i3`, `.sky` und `.tbl`-Dateien an. Für die aktuell geöffnete `.area` werden folgende Informationen geprüft:

- Prop-Modellpfade werden ohne Berücksichtigung der Groß-/Kleinschreibung und unabhängig von `/\`-Trennzeichen gegen den Index aufgelöst.
- Mehrere `ClientData`- und `ClientDataEN`-Vorkommen werden nach Dateityp behandelt. Binäre Assets bevorzugen `ClientData`, tabellen-/textbezogene Dateien bevorzugen `ClientDataEN`.
- Die verwendeten `WorldLayer`-, `WorldSky`- und `WorldZone`-IDs werden gesammelt und die entsprechenden Datenbankdateien (falls vorhanden) im Index angezeigt.

**Wichtig:** Die eigentliche Beziehung `WorldLayer.ID → Texturpfad` und `WorldSky.ID → .sky` benötigt einen zusätzlichen nativen `.tbl`-Tabellendekoder. Ein gefundener Tabellen-Dateipfad bedeutet noch nicht, dass die einzelnen IDs schon aufgelöst werden können. Originale Terrain-Materialien bleiben bis zu diesem weiteren Arbeitsschritt Debug-/Inspektionsdaten. M3/I3-Props werden nativ gelesen (siehe `README_M3_I3.md`).

## Start und Tests

```powershell
cd GenesisRebuild
cargo test -p wildstar_formats
cargo check -p genesis
cargo fast
```

Optional lässt sich die Root-Auswahl per Kommandozeile vorbelegen:

```powershell
cargo fast -- --client-root "D:\WildStar\WoWClient"
```

Oder beide Pfade explizit:

```powershell
cargo fast -- --client-root "D:\WildStar\WoWClient" --area "D:\WildStar\WoWClient\ClientData\Map\Western\Western.393b.area"
```

Die native Dialog-Integration verwendet `rfd` und sollte auf Windows als der vertraute Explorer-Dateidialog erscheinen. GitHub Actions validiert Parser-Tests und den Rust-Compilecheck; die echte Windows-Dialogdarstellung muss lokal geprüft werden.
