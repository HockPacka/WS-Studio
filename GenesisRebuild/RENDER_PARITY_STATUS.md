# Genesis Render Parity – technischer Branch-Stand

**Projekt:** WS-Studio / GenesisRebuild (Rust, Bevy 0.20.1, WildStar Build 16042)  
**Branch:** `feature/genesis-m3-i3-render-parity`  
**Stand der Implementierung:** `e0871a03d58042a80da384f6c8a6ef75784823f6` (2026-11-01)  
**Status:** Rust-Formatbibliothek / Editor-Compilerchecks in Windows-CI erfolgreich, **keine bestätigte originale GPU-Bildparität**.  
**Testplan:** [RENDER_PARITY_QA_CHECKLIST.md](RENDER_PARITY_QA_CHECKLIST.md)

Diese Datei hält den **Code-/Erkenntnisstand** vor einer weiteren Render-Iteration fest, nicht eine Behauptung, dass alle visuellen Effekte im laufenden Spiel geprüft seien. Sie ist ein Snapshot; spätere Änderungen in diesem Branch müssen den Stand und die QA-Ergebnisse aktualisieren. Originaldaten (ClientData, .m3, .i3, .area, .sky) werden vom Preview-Rendering nicht modifiziert.

## Verifikation (Stand 2026-11-01)

- Letzter erfolgreicher CI-Lauf für den genannten Code-Commit: https://github.com/HockPacka/WS-Studio/actions/runs/41355989748
- Bestätigte Jobs: `cargo test -p wildstar_formats`, AREA-Bit19/20-Probe an `WildStarModelStudio/demo/Hills.area`, `cargo check -p genesis`, `cargo check -p genesis --tests`.
- **Nicht bestätigt:** `cargo test -p genesis` als ausgeführter Editor-Testlauf; WESL/WGPU-Kompilierung zur Laufzeit; Screenshots oder Messungen auf Windows-GPU; Performance auf großen Zonen; Gleichheit zu WildStar-Referenzbildern.
- CI-Workflow: [../.github/workflows/genesis-ui.yml](../.github/workflows/genesis-ui.yml); wird auf dem Feature-Branch über den offenen Pull-Request ausgeführt. Dokumentations-Commits benötigen keine neuen Render-Freigaben.

## Bausteine und tatsächlicher Status

| Bereich | Code-Stand | Was noch fehlt / warum prüfen |
|---|---|---|
| M3 `LDOM` v100 | Native Vertices, Submeshes, UV0/UV1, Color0/Color1, Bounds, Textur-Metadaten, Bone-/Clip-Tracks | Modell-Achsen, Skalierung, echte Animation / GPU-Skinning |
| I3 `FEDI` / `FEDS` | Sektor-/Pass-Parsing, Material-Set `Default_Pass`, UV0/UV1, Vertexfarben, Kollisionsmesh-Filter | Originales I3-Vertexfarb-/UV1-Blending, weitere Materialsets |
| Normalmap-Tangenten | UV0-/Dreiecks-basierte Tangenten + `tangent.w`-Handedness mit Unit-Tests | Gespiegelte UV-Seams mit gemeinsam genutzten Vertices brauchen ggf. Vertex-Splits |
| M3-/I3-Normalmap-TEX | RGB vs. Alpha/Green einmal pro Bild erkannt, lineares RGBA zur PBR-Nutzung | Heuristik, Originalformat-/Y-Konvention und visuelle Parität nicht bewiesen |
| M3-Materialien | Materialkopf + bis vier 0x128-Layer mit Texturen, 5 Mode-Worten, Klasse, Typ, Erstwerten von Opacity/Gloss/Glow/ColorMod | Zeitliche DP-Animation, Layer-Modi, Masken, Shader-Permutationen |
| M3-Mehrschicht-Shader | Layer 0: Bevy `StandardMaterial`; Layer 1–3: alpha-over auf UV0 im WESL-Fragmentshader | Nur Preview-Näherung; Color1-Masken, zusätzliche Normalmaps/UV1 und Retail-Blendlogik fehlen |
| M3 Blend/Farbe | Opaque, Cutout, Alpha, Add/Multiply grob Bevy zugeordnet; Gloss -> Roughness, Glow -> Emissive | Spezialmodi, Specular, HDR/Exposure, Alpha-/OIT-Runtimeprüfung |
| Terrain-Mesh | 257×257 Höhenraster / AREA, UV0, Vertex-Farbdiagnostik, Normalen | Shadow-/Normal-Ausrichtung, fehlende Cells, Randnähte auf realen Tiles |
| Terrain WorldLayer | 4 Ebenen je 32-m-Cell, Gewichte, Normal-/Albedo-Texturarrays, per-Pixel-Tiling | Original LandPS-Layergewichte/-Offset, gewählte Normalmap-Packing-Heuristik |
| Terrain-Makrofarbe | AREA Bit 3 RGB565 / Bit 13 BC2, 1024×1024 Sample-Map, neutraler Wert 128, GPU-Splat-Tint | Farbraum-/Gamma-Abgleich, Nahtstellen, BC2-Alpha-Bedeutung offen |
| Terrain Painting | Texture-/Color-Paint mit separaten Quellen und nativen Edit-Plänen, Undo-/Redo-Code | Manuelle Roundtrip-Prüfung auf Kopie, Originaldateien schützen |
| Sky `.sky` | Zeitkurven von Ambient, SunDiffuse, SunSpecular, FogDistance, NightAmbient, HorizonFogMod; WorldSky-Zonen | `SunSpecular` nur ausgewertet, nicht als separate PBR-Specular-Beleuchtung |
| PBR-Umgebungslicht | Ambientfarbe der aktiven Sky an `GlobalAmbientLight`, skalierbar 0–2 | Absolute Helligkeit ist angenäherte Bevy-Abbildung, keine Retail-Messung |
| Sonnenlicht / Schatten | Sky-Sonnenrichtung + Farbe; 3 Cascades bis 600 m optional, standardmäßig AUS | GPU-Runtime, Schatten-Bias/Aliasing, Effekte auf Terrain/Props, FPS/VRAM |
| Fog | Sky-FogStart/End und HorizonFogMod auf Bevy DistanceFog/ClearColor; Sky-Zonenfarbe linear gemischt | Originaler dichter/volumetrischer Nebel, SkyStart/End und CloudFog noch kein Retail-Match |
| Sky-Dome / Himmelsmodelle | Unlit-Dome; Celestial-M3-Preview; keine Shadow-Caster | Visuelle Überlagerung, Tageswechsel/Alphakurven, Depth/Fog-Verhalten |
| Clutter | Native M3-Props, GPU-Wind für erkannte Pflanzen, Shared Materials, VisibilityRange-LOD | Wind-Shader hat bewusst keine passenden Schattenpässe, kombiniert nicht mit M3-Overlayshader |
| World-Streaming | Gestreamte AREA-Props erhalten layered M3-Material-Assets | Tile-Wechsel, Materialcache, Speicher/Laufzeit bei massiven Szenen prüfen |

### Relevante Quellcodedateien

- Formatreader / Daten: `crates/wildstar_formats/src/m3.rs`, `i3.rs`, `tex.rs`, `tex/normal.rs`, `tangents.rs`, `area/`, `sky.rs`.
- M3/I3-Rendering: `src/props.rs`, `src/m3_layers.rs`, `src/m3_layers.wesl`, `src/prop_viewer.rs`.
- Terrain: `src/terrain.rs`, `src/terrain_material.rs`, `src/terrain_splat.rs`, `src/terrain_splat.wesl`, `src/terrain_paint.rs`.
- Wetter/Licht: `src/sky.rs`, `src/main.rs`, `src/water.rs`.
- Clutter/Streaming: `src/clutter.rs`, `src/clutter_wind.rs`, `assets/shaders/clutter_wind.wesl`, `src/streaming.rs`.
- Detaildokumentation: [README_M3_I3.md](README_M3_I3.md), [README_RENDER_OPTIONS.md](README_RENDER_OPTIONS.md).
- Format-/Reverse-Engineering-Quellen im Repo: [../docs/m3_format_spec.md](../docs/m3_format_spec.md), [../docs/m3_materials.md](../docs/m3_materials.md), [../docs/m3_animation_format.md](../docs/m3_animation_format.md), [../docs/i3_shader_notes.md](../docs/i3_shader_notes.md), [../docs/sky_shader_mapping.md](../docs/sky_shader_mapping.md). Einige Angaben dort sind Hypothesen aus Shaderanalyse; nicht automatisch als Engine-Parität verstehen.

## Bedienung / manuelle Prüfung

1. Genesis auf Windows mit einem **legal vorhandenen lokalen** ClientData-Root starten.
2. Eine echte `.area` über **Open AREA...** laden; die rechte **Render**-Registerkarte bietet Bit3/Bit13-Quellen, WorldLayer/Normal/Tint/Debug.
3. `.m3`/`.i3` über **Open Model (.m3/.i3)...** laden; Texturen, Normals, Layer und Materialberichte kontrollieren.
4. **Environment**: `Time of Day`, `Sky ambient intensity`, `Sun illuminance`, `Directional shadows (3 cascades / 600 m)`. Neue Werte gelten nur für die Vorschau.
5. Für eine Zone **Open Zone (World Streaming)...** nutzen; Übergänge, Sky-Gewichte, Props und Clutter am Tile-Rand prüfen.
6. Pro Test Eintrag in [RENDER_PARITY_QA_CHECKLIST.md](RENDER_PARITY_QA_CHECKLIST.md) mit Screenshot, GPU-Typ/Backend, Modell-/AREA-Pfad, Ergebnis/Fehler befüllen.

## Offene Arbeit (geordnet nach Risiko)

**P0 – für verlässliche Vorschau:** WESL-Shader live auf Windows-GPU kompilieren; M3-Layer-Materialien mit realen 1–4 Layern prüfen; Terrain-Tint-/Normalmap-/Fog-Farbvergleich; optionale Cascaded Shadows unter Bevy Forward-PBR testen; keine Pink-/Black-Meshes, keine WGPU-Validation Errors.

**P1 – sichtbare WildStar-Abweichungen:** Originale Layer-Blends aus Mode-Worten und Color1-Masken, Layer-Normalmaps, zweite UVs, Height/Parallax, Specular/SunSpecular, HDR/Tonemapping, Cloud Shadows, Celestial-Fog-Parität, natürliche Farbhelligkeit.

**P2 – größere Systeme:** native Animationen + Skinning, Partikel-/Ribbon-/FX-Renderer, animierte Materialparameter, Wind+Layer+Shadow-Kombination, große Streamed-World-Performance, automatisierter GPU-Screenshot-Regressionstest.

## Historie der Render-Parity-Feature-Commits

| Commit | Inhalt |
|---|---|
| [5905a84](https://github.com/HockPacka/WS-Studio/commit/5905a84f51c7438982589ec64f0263653854555b) | Tangenten aus UV/Dreiecken + Unit-Tests |
| [727096e](https://github.com/HockPacka/WS-Studio/commit/727096e219a391f7a5678aed80d159983293226d) | Bevy Float32x2 UV-Compilerkorrektur |
| [99d6dcb](https://github.com/HockPacka/WS-Studio/commit/99d6dcb820adbc494c1bfd29d97c8362f76f244a) | Texturweite Normalmap-Kanalerkennung |
| [cff0f13](https://github.com/HockPacka/WS-Studio/commit/cff0f13373a79f28047a6b5ba42be961d5c52b0f) | Normalmap-Testkorrektur |
| [2d66704](https://github.com/HockPacka/WS-Studio/commit/2d6670489e7b811bfe81641e90055cc4e4e3515b) | Native M3-Layer 0–3 im Parser + Tests |
| [ad70063](https://github.com/HockPacka/WS-Studio/commit/ad700639bc2aa9f5071a3be3e7520dde5825e16a) | M3 Layer 1–3 mit PBR-WESL-Overlay |
| [b75cc80](https://github.com/HockPacka/WS-Studio/commit/b75cc802c8ea271768a8bf930f47058d8d81d963) | Gestreamte World-Props mit Overlay-Material |
| [1e02758](https://github.com/HockPacka/WS-Studio/commit/1e027581b1f644e868b91ca20bf64c5b8a347972) | Bevy ExtendedMaterial Import / CI erfolgreich |
| [e0871a0](https://github.com/HockPacka/WS-Studio/commit/e0871a03d58042a80da384f6c8a6ef75784823f6) | Sky Ambient PBR, Cascaded Sun Shadows optional, zonenübergreifende Fog-Farben |

**Regel für künftige Änderungen:** Code-Kommentare/Docs und Tests müssen klar zwischen **native dekodiert**, **Shader-Näherung**, **Rust-CI bestanden** und **GPU/Originalvergleich nachgewiesen** unterscheiden. Keine Originaldateien oder großen proprietären ClientData-Dateien committen.
