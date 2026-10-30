# Avatus Asset Pack – aktueller Analyse- und Teststand

Source: https://github.com/HockPacka/WS-Tools/tree/main/Avatus (GitHub `main`, 2026-10-29)

## Originaldateien

| Datei | Größe | M3 v100 | Geometrie | Bones | Clips | Materialien | TEX-Referenzen |
|---|---:|---|---:|---:|---:|---:|---:|
| `Avatus.m3` | 4.245.984 B | nicht live geprüft | ? | ? | ? | ? | ? |
| `Avatus_Gun.m3` | 191.424 B | strukturell untersucht | 1.437 Vertices / 2.116 Triangles / 2 Meshes | 31 | 24 | 2 | 6 |
| `Avatus_HandLf.m3` | 221.840 B | strukturell untersucht | 1.406 Vertices / 1.956 Triangles / 3 Meshes | 31 | 29 | 5 | 8 |
| `Avatus_HandRt.m3` | 220.560 B | strukturell untersucht | 1.374 Vertices / 1.956 Triangles / 3 Meshes | 28 | 29 | 5 | 8 |

Die drei kleineren M3-Dateien wurden direkt aus GitHub als Base64 gelesen und anhand ihrer Binärstrukturen untersucht. Der Hauptkörper liegt über der Größe des Connector-Rückgabekanals; **sein echter Laufzeittest ist offen**. Die native DLL wurde nur mit synthetischen M3-Daten und Demo-Dateien ausgeführt; der Connector-Check ist **kein** nativer Integrationstest.

Alle zehn `.tex`-Dateien aus `Avatus/Textures` haben einen gültigen `GFX v3`-Header:

| TEX | Pixeltyp / Header |
|---|---|
| `Avatus_Glass_Grad.tex` | BGRA 128×2 |
| `Avatus_Glass_SkinFX.tex` | BC1/DXT1 1024×1024 |
| `avatus_glass_color.tex` | WildStar JPEG-like TYPE1 1024×1024 |
| `avatus_glass_normal.tex` | WildStar JPEG-like TYPE2 1024×1024 |
| `avatus_gp01_color.tex` | WildStar JPEG-like TYPE3 1024×1024 |
| `avatus_gp01_normal.tex` | WildStar JPEG-like TYPE2 1024×1024 |
| `avatus_gp02_color.tex` | WildStar JPEG-like TYPE3 1024×1024 |
| `avatus_gp02_normal.tex` | WildStar JPEG-like TYPE2 1024×1024 |
| `avatus_gp03_color.tex` | WildStar JPEG-like TYPE3 1024×1024 |
| `avatus_gp03_normal.tex` | WildStar JPEG-like TYPE2 1024×1024 |

Die Headerprüfung beweist **noch keine fehlerfreie Bilddekodierung**. Die JPEG-like TEXs müssen in der lokalen Originaldatei-Verifikation laufen.

## Avatus-Sonderfall und Fix

M3-Texturpfade enthalten etwa:

`Art\\Creature\\Avatus\\Textures\\avatus_gp03_color.tex`

Im Repository liegen dieselben Assets jedoch als:

`Avatus/Textures/avatus_gp03_color.tex`

Die neue lokale Asset-Paket-Suche unterstützt beide Layouts mit sicherer, case-insensitiver Auflösung, ohne Pfade außerhalb des gewählten Verzeichnisses freizugeben. Zusammengehörige Modelle können aus dem linken Menü geladen werden. Das Materialpanel zeigt TEX-Referenzen und zusätzliche Texturdateien aus dem Ordner an.

## Funktionale Grenzen

Der Viewer zeigt statische Geometrie und angenäherte Materialien. **Kein vollwertiger animierter Avatus-Renderer:** Skeletal Animation, Skinning, zusammengesetzte Körperteil-Transforms, Echtzeitpartikel, Ribbons und die proprietären WildStar-Shaderpermutationen sind noch nicht originalgetreu implementiert. Die Parser-DLL stellt wichtige Metadaten bereit, aber manche Felder bleiben Rohdaten.

## Auf deinem PC vollständig prüfen

1. `WS-Tools` klonen oder als ZIP entpacken; `Avatus/` muss alle vier M3 und den Unterordner `Textures/` enthalten.
2. `start_desktop_windows.bat` starten, `Avatus/Avatus.m3` öffnen. Die weiteren Modelle stehen links unter **MODEL PACK**.
3. Den Avatus-Ordner auf `check_avatus_windows.bat` ziehen. Die Datei `avatus_report.json` enthält **echte** Lesetests für alle vier M3 und die zehn TEX-Dateien.
4. Fehler aus `avatus_report.json` sind verbleibende Kompatibilitätslücken, nicht automatisch Dateifehler. Diese bitte für weitere Parser-Fixes verwenden.


## Update 2026-10-29 – Null-Mesh-Fix aus echtem `avatus_report.json`

Die Diagnose des Nutzers meldete 4/4 lesbare M3 und 10/10 dekodierte TEX,
aber 0 sichtbare Meshes bei jedem Modell. Der native Parser behandelte die
Index-AP-Byteanzahl bei `geometry + 0x70` irrtümlich als u16-Elementanzahl
und prüfte die doppelte Datenlänge. Der Fix ist in v0.7.1 enthalten; die
Geometrieprüfung zeigt die getrennten Zähler `rawMeshCount` und `meshCount`.
Das Hauptmodell muss mit der neuen DLL auf Windows erneut getestet werden.
