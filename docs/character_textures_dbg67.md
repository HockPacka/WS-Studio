# Charaktertexturen, Sprachen und Vorschau: dbg67

Client: `WoWClient/WowClient64_dbg67.exe`, SHA-256 `cc3a876f2562c18528e3e52ab91ab7e0f6af933fa2b7e04e27678569761e19a4`.

## Native Texturregionen

`ItemDisplay.skinColorMap` ist bei Charakteren häufig ein logischer Texturname, keine vorhandene Gesamtdatei. Beispiel Human-Male: `CHR_Human_M_Skin_Tan_01_Color.tex` fehlt, vorhanden sind dessen `.Skin_Body.tex`, `.Skin_Arm.tex`, `.Skin_Head.tex` und `.Skin_Eye.tex`. Die Dateigrößen passen zu `ComponentRegionRect`: Körper 320×1024, Arm 512×256, Kopf 704×384 und Auge 192×128 im 1024×1024-Layout 2.

Der neue Pfad liest das Layout über `Race.componentLayoutIdMale/Female`, setzt die vorhandenen Teilbilder nach ihren Region-Rechtecken und `ItemDisplay.componentPriority` zusammen und erzeugt einen BLP-Atlas mit Mip-Kette im Speicher. Körper und die angehängten Kopf-/Haar-/Ohrenmodelle verwenden denselben Atlas. Die Original-TBL-, M3- und TEX-Dateien werden nicht verändert.

Mordesh verwenden teilweise einen logischen Namen ohne Rassen-/Geschlechtssuffix. Der Leser prüft zusätzlich den eindeutigen Namen mit dem Basismodell-Suffix vor `_Color`, etwa `CHR_Skin_Green_01_Mordesh_F_Color.Skin_Body.tex`. Die Haut-Atlas-Alpha wird auf volle Deckung gesetzt; native Material-/Dye-Werte werden damit nicht als Hauttransparenz interpretiert. Vollständige WildStar-Dye-Shader und alle zusätzlichen Anpassungskategorien sind dadurch noch nicht nachgebildet.

## Auswahlregeln

Die fünf WoW-Aussehensfelder speichern Indizes in native Wertelisten. Fraktionsgebundene Human-Gesichts- und Haarlabels behalten Vorrang vor generischen Race-0-Einträgen. Stilfelder benutzen primäre Stil-Labels; Farb-Labels werden nicht versehentlich als Frisur oder Bart ausgewählt. Farblisten berücksichtigen die aktuell gewählte Frisur beziehungsweise das Gesicht. Eine Glatze besitzt keine unabhängige Haarfarbe; ihre Pfeile werden deaktiviert, statt `0/0` als Auswahl anzuzeigen. Fehlt eine unabhängige Farboption, erscheint `Linked to Skin`.

## Hintergrund und Positionierung

Erstellung und Charakterauswahl verwenden denselben Native→WoW-Hintergrund-Fallback. Auch `GetSelectBackgroundModel` ist jetzt abgedeckt. Alle neuen Rassen verwenden vorläufig die Human-Vorschau mit identischem Anheftungspunkt und Kamera, statt unterschiedlicher Dwarf-/Troll-Kameratransformationen.

Die Glue-Vorschau normalisiert Größe und Fußhöhe anhand der tatsächlichen M2-Vertexpositionen. Die M3-Headergrenzen enthalten Animationsauslenkungen bis mehrere Meter unterhalb des Bodens und eignen sich nicht als stehende Modellhöhe. Chua erhalten eine kleinere Zielhöhe. Die Skalierung wird nur von Erstellung und Auswahl angewendet; Ingame-Skalierung und Server-DBC-Werte werden nicht geändert.

## Chat-Sprachfehler

Der aktive ursprüngliche Human-Warrior besitzt auf dem Server Common (Skill 98, 300/300). Die neuen Dominion-Charaktere besitzen Orcish (109, 300/300). Es wurden keine Sprachfertigkeiten pauschal in der Charakterdatenbank geändert.

Der Fehler entsteht im Client: `SpellTableInitialize` und `SpellTableLookupInfo` nahmen zusammenhängende Zeilen pro Skill an. Angefügte Erweiterungszeilen legten einen neuen Hash-Eintrag für dieselbe Skill-ID an; die spätere Gruppe verdeckte die ursprünglichen WoW-Zeilen. Der neue Lookup indexiert alle Zeilen je Skill und erhält die Reihenfolge innerhalb dieser Gruppe. Damit bleiben ursprüngliche und native Rassen-/Klassenmasken verfügbar, unabhängig von der physischen DBC-Zeilenreihenfolge.

## Prüfung

`tools/analysis/character_runtime_check.py` führt den tatsächlichen C++-Leser/Konverter aus: 15 zulässige Rassen-/Geschlechtsvarianten, jeweils Standardprofil und fünf Optionswechsel. Alle angeforderten Texturen werden als BLP geladen und decodiert; Atlasgröße, nicht konstante RGB-Werte und deckende Haut-Alpha werden geprüft. Die erzeugten Atlanten liegen unter `build_m3test/character_composition/`.

Die Sprachprüfung reproduziert den alten Human/Common-Fehler anhand der installierten DBC-Zeilen und prüft, dass der vollständige Gruppenindex die ursprünglichen WoW- sowie die erlaubten neuen Rassen-/Klassenkombinationen erhält. Das Release-x64-Ziel `Wow` baut erfolgreich.

Die ursprüngliche AzerothCore-Installation bleibt unter `build_wildstar/deployments/azerothcore-races-v1/installed.json` dokumentiert. Die Korrekturen in dbg67 erfordern keine weitere SQL-Migration oder Datenbankänderung.
