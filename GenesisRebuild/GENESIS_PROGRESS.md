# Genesis Editor Rebuilder – Fortschritt und Übergabe

**Stand:** 31. Oktober 2026  
**Repository:** [HockPacka/WS-Studio](https://github.com/HockPacka/WS-Studio)  
**Dokumentiert für:** `main` (vor der Dokumentation: `ee873248b2ad602df2444d77b7c7212fa1e38183`)  
**Entwicklungsbranch der AREA-/Texturarbeiten:** `feature/genesis-raw-area-3d`  
**Technik:** Rust (Edition 2024), Bevy 0.20.1, bevy_egui 0.43.1, native Library `wildstar_formats`

> **Projektziel:** Eine eigenständige Rekonstruktion des ursprünglichen WildStar-Genesis-World-Editors mit direktem Zugriff auf die Originaldateien. Diese Datei dokumentiert den belegbaren Entwicklungsstand, nicht die Fertigstellung. „Implementiert“, „getestet“ und „visuell mit echten Clientdaten verifiziert“ sind unterschiedliche Aussagen.

## 1. Unsere bisherige Umsetzung

| Bereich | Implementiert | Einschränkungen |
| --- | --- | --- |
| Klassische Genesis-Oberfläche | Menüleiste, Ribbon, Docks, Floating Properties, anpassbarer 3D-Viewport. Separater egui-Kamera-Kontext, damit die Menüs nicht durch den 3D-Viewport abgeschnitten werden. | Visuelle Originaltreue und DPI-Varianten nicht vollständig geprüft. |
| Direkter AREA-Reader | Originale `.area`/`AERA` lesen, komprimierte Daten entpacken, 16×16 Zellen verwalten, 257×257-Höhenmesh erzeugen; unbekannte Bytes bleiben erhalten. | Viele Spezialblöcke sind weiterhin nicht vollständig entschlüsselt. |
| AREA-Metadaten | Vier WorldLayer-IDs pro Zelle, Layergewichte (Bit 2/29), RGB565-Farbkarte, WorldSky-/WorldZone-IDs, Road-/Clutter-Flags, Props und Rohchunk-Inspector. | Bestimmte Spezialmasken/Flags noch nicht sicher interpretiert. |
| Native Rust-Crate | `crates/wildstar_formats` statt DLL oder JSON-Zwischenkonvertierung; Formatdekoder unabhängig vom Renderer. | Muss bei weiteren Formaten mit echten Referenzdateien validiert werden. |
| Client-Root | Native Windows-Ordnerauswahl; `ClientData` und `ClientDataEN` indexieren, Pfade ohne Beachtung der Groß-/Kleinschreibung auflösen, Root lokal merken. | Vollständiger Asset-Index wird beim Start erneut aufgebaut; noch kein persistierter Index-Cache. |
| „Open AREA“ | Nativer Windows-Datei-öffnen-Dialog mit `.area`-Filter; manuelle Pfadeingabe optional. | Visuelle Prüfung unter Windows empfohlen. |
| WorldLayer / TEX | LBTD-/`WorldLayer.tbl`-Reader, Texturpfade und Tiling; TEX-Decoder für BGRA/RGB565/BC1–BC3 und WildStar-JPEG-TYPE1–3. | Originaldatei-Abdeckung noch nicht vollständig validiert. |
| Textured-Terrain | Anfänglich 4-Layer-CPU-Atlas aus echter `.tex` + AREA-Gewichten; Materialstatus, konkrete Fehlermeldungen und RGB565-Fallback sichtbar. | Ohne echten Client-GPU-Test noch kein Nachweis der korrekten Ausgabe. |

**Letzte konkrete Fehlersuche:** Die Warnung `field notes is never read` war nicht die Ursache für unsichtbare Texturen. Die `notes` werden inzwischen im AREA-Dock angezeigt. Die Diagnose unterscheidet jetzt „TEXTURED“ und „RGB565 fallback“ und meldet fehlende WorldLayer/TEX-Dateien. Der TEX-Decoder wurde um das proprietäre JPEG-artige Format erweitert.

## 2. Zusätzlicher Codeumfang auf main

Auf `main` liegen mittlerweile weitere Entwicklungen, die über den zunächst angelegten Textur-Branch hinausgehen. Diese Punkte sind **im Repository implementiert**, jedoch nicht pauschal auf deinem lokalen Rechner visuell getestet:

- **Runtime-Splatting:** `src/terrain_splat.rs` / `src/terrain_splat.wesl` rendern vier Texture-Layer pro Terrainzelle mit Texture-Array, Weightmap, WorldLayer-Tiling, Normalmap und Macro-Tint; der CPU-Atlas bleibt als Fallback. Eine prozedurale Testszene ist in `src/splat_demo.rs` vorhanden.
- **Verbesserte Materialpipeline:** höhere TEX-/Atlas-Auflösung, Material-/Texturcache und veränderbare Macro-Tint-Stärke mit Gamma-Option (`src/terrain_material.rs`).
- **Modelle und Props:** native M3-/I3-Reader (`wildstar_formats/src/m3.rs` und `i3.rs`), Modell- und Materialanzeige inklusive Texturpfaden über `src/props.rs`. Grenzen für Modellgröße, Animation und Materialvarianten bestehen weiterhin.
- **World Streaming:** Map-/Tile-Erkennung, Nachladen benachbarter 512-m-AREA-Tiles auf Worker-Threads, Entladen entfernter Tiles (`src/streaming.rs`, `wildstar_formats/src/zone.rs`).
- **Wasser:** Geometrie und grundlegendes transparentes Material aus AREA-Wasserdaten (`src/water.rs`).

Damit ist Genesis als **Viewer und Editor-Prototyp** weiterentwickelt, aber noch kein vollständig funktionsfähiger und rückschreibender World Editor.

## 3. Wichtige Dateien

```text
GenesisRebuild/
├── Cargo.toml
├── .cargo/config.toml                   # cargo fast / fast-check
├── src/
│   ├── main.rs                          # App, Kamera, UI, Viewport, Docks
│   ├── client_data.rs                   # Root-/Dateiauswahl, Asset-Anbindung
│   ├── area_ui.rs                       # AREA-Inspector
│   ├── terrain.rs                       # Höhenmesh, Vertexdaten, UVs
│   ├── terrain_material.rs              # WorldLayer, TEX, Albedo/Normal/Tint
│   ├── terrain_splat.rs                 # Bevy-Terrainmaterial
│   ├── terrain_splat.wesl               # Runtime-Layer-Shader
│   ├── streaming.rs                     # Mehrere AREA-Tiles
│   ├── props.rs                         # M3/I3-Props und Materialien
│   └── water.rs                         # Wasser-Mesh/-Material
└── crates/wildstar_formats/src/
    ├── area.rs, area/metadata.rs        # .area und Metadaten
    ├── assets.rs                        # Asset-Pfadindex
    ├── tbl.rs                           # LBTD / WorldLayer.tbl
    ├── tex.rs, tex/jpg.rs               # .tex und proprietäres JPEG
    ├── m3.rs, i3.rs                     # Modellformate
    └── zone.rs                          # Karten/Tiles
```

Die WildStar-Originaldateien werden **gelesen, nicht überschrieben**. Es gibt keine notwendige DLL und keine vorgeschaltete JSON-Konvertierung.

## 4. Tests: Was ist tatsächlich bestätigt?

- [Windows-GitHub-Actions-Lauf 41139400091](https://github.com/HockPacka/WS-Studio/actions/runs/41139400091): **17 `wildstar_formats`-Tests bestanden** und `cargo check -p genesis` erfolgreich (AREA-/JPEG-Branch-Commit `f355c25`).
- [Neuerer Feature-Branch-Lauf 41147889252](https://github.com/HockPacka/WS-Studio/actions/runs/41147889252): Status **success** für Commit `87434cf`.
- **Achtung:** `main` hat danach noch neue Commits erhalten (unter anderem GPU-Splatting, M3/I3, Materialien). Ein separater erfolgreicher Windows-Build **des aktuellen main-HEAD** wurde beim Erstellen dieser Dokumentation nicht festgestellt. Die oben genannten CI-Ergebnisse sind kein Beweis für dessen vollständige Laufzeitfunktion.

### Lokal testen (PowerShell)

Im Repository:

```powershell
git switch main
git pull
cd GenesisRebuild
cargo test -p wildstar_formats
cargo check -p genesis
cargo fast
```

Dann den **WildStar-Root** auswählen, eine `.area` mit **File → Open AREA…** laden und **AREA → Textured** prüfen. Im WORLD-/ZONE-Dock kann das Nachladen angrenzender Tiles getestet werden.

**Wenn Terrain-Texturen fehlen:** prüfen, ob `ClientData`/`ClientDataEN` indexiert sind, ob `WorldLayer.tbl` gefunden wurde, wie viele Layer und TEX-Dateien tatsächlich dekodiert wurden und ob `RGB565 fallback` angezeigt wird. Für die weitere Analyse einen Screenshot und die konkrete Statusmeldung sichern.

## 5. Offene Probleme und Risiken

1. **Reales Rendering:** Die Layer-Texturen waren bei deinem letzten lokalen Test nicht sichtbar. Der Code zur TEX-/Materialdiagnose und die JPEG-Dekodierung wurden erweitert, die Bildausgabe mit denselben lokalen Clientdaten wurde aber **noch nicht erneut bestätigt**.
2. **Originaltreue:** UV-Phase an Cell-/Tile-Grenzen, Gamma/SRGB, Material-Bitmasken, Normal-Y-Achse und Layer-Blendfunktion müssen mit Original-WildStar-Daten verglichen werden.
3. **Startzeit:** Der Asset-Scanner durchsucht bislang alle Dateien bei jedem Start neu; einen persistenten/incrementellen Index beziehungsweise vollständiges Lazy Loading gibt es noch nicht.
4. **Teilweise unbekannte Formate:** Einige AREA-Blöcke, Texturnebenkanäle, Clutter-/Wasser-/Sky-Details und Animationen sind unvollständig interpretiert.
5. **Modelsystem:** M3/I3-Skinning/Animation, Spezialmaterialien, Transformationsmaßstäbe und weitere Assets sind nicht vollständig abgedeckt.
6. **Echte Editierfunktionen:** Viele Genesis-Menüs/Brushes sind UI-Vorlagen; produktives Height-/Layer-/Zone-Painting, Undo/Redo, Speichern und sicherer Binär-Roundtrip sind noch ausstehend.
7. **Streaming:** Speicherverbrauch, Ladezeiten, Kamerasprünge, Tile-Grenzen und Freigabe von Ressourcen müssen auf Windows vermessen werden.

## 6. Roadmap (Priorität)

- **P0 – Textur-Fehler mit echter AREA reproduzieren und beheben.** Auflösung `WorldLayer-ID → TBL-Zeile → ColorMapPath → TEX → Materialbinding → Shader-Ausgabe` lückenlos diagnostizieren.
- **P0 – Windows-GPU-Smoketest und visuelle Regressionen.** Automatischer Demo-Screenshot zusätzlich zu CI-Unit-Tests und `cargo check`; Vergleich an einer bekannten AREA.
- **P1 – WildStar-Materialparität.** UV-Kontinuität, Blendgewichte, Macro-Tint, Normalmaps und Spezialmasken mit WS-Tools/Originaldaten verifizieren.
- **P1 – Asset-Cache/Lazy Loading.** Wiederholtes Indexieren verringern, nur benötigte Ressourcen laden und geladenes Material teilen.
- **P1 – Streaming, Props und Wasser mit echten Zonen testen.** RAM/VRAM, Ladezeit, Darstellung und Skalierung prüfen.
- **P2 – Genesis als Editor fertigstellen.** Tatsächliche Werkzeuge, Undo/Redo, sicheres Speichern/Reload und Byte-/Semantik-Roundtrip-Tests.

## 7. Weiterführende Dokumentation

- [AREA-Format und Inspector](README_AREA_FORMATS.md)
- [ClientData-Root und Windows-Dateidialog](README_CLIENT_ROOT.md)
- [WorldLayer-Texturen und Runtime-Splatting](README_WORLDLAYER_TEXTURES.md)
- [M3/I3-Parser und Modelle](README_M3_I3.md)
- [Responsive UI](README_RESPONSIVE_UI.md)
- [Schnellere Cargo-Builds](README_FAST_BUILDS.md)
- Original-Editor-Screenshots und Vergleichsinformationen: [WILDSTAREDITOR](WILDSTAREDITOR/)

**Hinweis für weitere Entwicklungsarbeit:** Diese Datei ist eine Momentaufnahme vom 31.10.2026. Bei neuen Implementierungen den Abschnitt „Tests“ nur dann auf „bestanden“ setzen, wenn der konkrete Branch/Commit und das Testergebnis nachvollziehbar sind.
