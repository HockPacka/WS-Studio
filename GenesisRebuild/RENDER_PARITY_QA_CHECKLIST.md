# Genesis M3 / I3 / Terrain / Sky – QA-Checkliste

**Branch:** `feature/genesis-m3-i3-render-parity`  
**Codebaseline:** `e0871a03d58042a80da384f6c8a6ef75784823f6` (2026-11-01)  
**Technische Übersicht:** [RENDER_PARITY_STATUS.md](RENDER_PARITY_STATUS.md)

**Bedeutung der Checkboxen:** `[x]` = am angegebenen Commit/CI-Lauf wirklich bestätigt; `[ ]` = **noch offen/nicht nachgewiesen**, nicht „defekt“. Für unimplementierte Features ist ausdrücklich **OPEN / NICHT IMPLEMENTIERT** zu protokollieren, statt einen Test als grün zu markieren. **Rust-CI ist keine GPU-Testfreigabe.**

## 0. Testumgebung vorbereiten

- [ ] Testsystem notiert: Windows-Version, GPU + VRAM, Treiber, API/Backend (DX12/Vulkan), Bildschirmauflösung.
- [ ] Sauberes `git status` und exakter Feature-Branch-Commit dokumentiert; **nicht** auf `main` entwickeln.
- [ ] Lokal referenzierbares WildStar ClientData/ClientDataEN vorhanden und indexiert; **keine proprietären Assets committen**.
- [ ] Test-Assets/Referenzen festgelegt: 1 M3 mit einem Layer, 1 M3 mit 2–4 Layern, 1 Modell mit DXT5nm/RGB-Normalmaps, gespiegelte UVs, 1 FEDI + FEDS, 1 direktes FEDS, mindestens 1 texturiertes AREA mit Bit3/Bit13, eine Zone mit Sky-Wechsel, Clutter/Pflanzen.
- [ ] Referenz-Screenshots des originalen Clients/Editors (gleicher Kamerawinkel, Tageszeit, Wetter) abgelegt oder „nicht vorhanden“ markiert.
- [ ] Bei Save-Tests nur **Kopie** eines AREA verwenden; Hash vor/nach Read-only-Tests vergleichen.

## 1. CI/Compiler (automatisch belegter Baseline-Stand)

- [x] `cargo test -p wildstar_formats` – erfolgreich im Windows-CI-Lauf [41355989748](https://github.com/HockPacka/WS-Studio/actions/runs/41355989748) am Code-Commit `e0871a0`.
- [x] AREA-Bit19/20-Probe mit gebündelter `Hills.area` – erfolgreich im selben Lauf.
- [x] `cargo check -p genesis` – erfolgreich im selben Lauf.
- [x] `cargo check -p genesis --tests` – erfolgreich im selben Lauf (**kompiliert** Testtargets; führt Editor-Tests nicht aus).
- [ ] `cargo test -p genesis` als Laufzeit-Unit-Testlauf lokal oder in CI ausgeführt.
- [ ] `cargo run -p genesis --release` startet ohne Panic/Shaderimportfehler/GPU-Validation-Error.
- [ ] WESL-Fragmente `m3_layers.wesl` und `terrain_splat.wesl` tatsächlich von Bevy/WGPU mit echten Texturen erfolgreich kompiliert.
- [ ] Screenshot-/Render-Regressionstest (automatisch) für M3/AREA; aktuell nicht eingerichtet.

**Reproduzieren** – im Ordner `GenesisRebuild` (PowerShell):

~~~powershell
cargo test -p wildstar_formats
cargo check -p genesis
cargo check -p genesis --tests
cargo test -p genesis
cargo run -p genesis --release
~~~

Im Editor dann ClientData indexieren, über **Open AREA...** und **Open Model (.m3/.i3)...** echte Assets öffnen. Testfehler mit exakter Konsolenausgabe erfassen.

## 2. M3-Modell und Materialien (P0/P1)

- [ ] [P0] M3 v100 mit nur Layer 0: Modell vorhanden, korrekte Bounds, Meshes, UVs, Farbtextur, Beleuchtung, keine Pink/Black-Flächen.
- [ ] [P0] M3 mit 2, 3 und 4 Original-Layern: Anzahl im Objects-Materialbericht korrekt; zusätzliche **Farb-**Layer in Originalreihenfolge gerendert.
- [ ] [P0] Fehlende mittlere Layertextur: spätere Slots verschieben sich nicht; kein Binding-/WGPU-Validation-Fehler, transparenter Fallback.
- [ ] [P0] Layer-1..3-Alpha-Over: Opacity und ColorMod wirken sichtbar; als **Annäherung**, nicht als WildStar-Parität abnehmen.
- [ ] [P0] Alpha Cutout und Transparent/Add/Multiply mit realen M3s: Tiefensortierung, Fog, Glow und Schattenwirkung prüfen.
- [ ] [P0] RGB-Normalmap: reliefartige Beleuchtung bei Kameradrehung plausibel, Normalen bleiben linear und ohne Farbstich.
- [ ] [P0] Alpha/Green-Normalmap: keine per-Pixel-Umschaltung oder Ausreißer; Y-Achsenrichtung und Glanzrichtung dokumentieren.
- [ ] [P0] Gespiegelte UVs/Nahtstellen und degenerierte UV-Dreiecke: keine NaNs/zerstörte Normalen; Seam-Splitting bei Bedarf als Ticket.
- [ ] [P1] Color0 neutral bei 0x80 korrekt; Color1-Daten sind im Parser, aber **Original-Shader-Blending nicht implementiert**.
- [ ] [P1] UV1 und weitere Normal-Layer: **NICHT IMPLEMENTIERT** in M3-Multilayer-PBR, Vorhandensein und visuelles Soll dokumentieren.
- [ ] [P1] Originale 5 Mode-Wörter / Masken / Shader-Permutationen: **NICHT IMPLEMENTIERT** (gegen Originalshader verifizieren).
- [ ] [P1] Glow/Gloss/SunSpecular sowie HDR-Werte >1 auf hellen/dunklen M3-Materialien vergleichen.
- [ ] [P2] Bone-/Clip-Abspielung, GPU-Skinning, SkinFX, Particle, Ribbons, Material-Keyframes: **NICHT IMPLEMENTIERT** bzw. nur Daten gelesen.

**Akzeptanz P0:** alle getesteten Modelle sichtbar und stabil, keine Runtime-Shader-/WGPU-Fehler; zusätzlich ein reproduzierbarer Bildvergleich mit erlaubten Referenzen. Kein „Pixel-Perfect“ ohne nachgewiesene Original-Shadersemantik.

## 3. I3-Innenräume (P0/P1)

- [ ] [P0] FEDI mit mehreren FEDS-Sektoren und `Default_Pass` vollständig sichtbar.
- [ ] [P0] Direkt geöffneter FEDS-Sektor verwendet Geometrie; erwarteter Fallback ohne FEDI-Texturmetadaten.
- [ ] [P0] Collision-only-Submeshes unsichtbar; Default-Pass und Materialindizes korrekt.
- [ ] [P1] UV0/UV1, unterschiedliche Material-Passes, Vertexfarben und Übergänge kontrollieren.
- [ ] [P1] Andere Material-Sets sowie native I3-Color-/UV1-Blends: **noch nicht originalgetreu umgesetzt**.

## 4. Terrain: WorldLayer, Farben und Painting (P0/P1)

- [ ] [P0] Echtes AREA mit 257×257 Terrain-Vertices lädt ohne fehlende Cells zu erfinden.
- [ ] [P0] Vier WorldLayer-Gewichte auf 32-m-Cells: Texturgrenzen und Tiling über Cell-/Tile-Ränder hinweg sichtbar nahtlos.
- [ ] [P0] Terrain-Debug „Lit WorldLayer + PBR“ gegenüber „Unlit WorldLayer albedo“: Lichtänderungen beeinflussen nur Lit.
- [ ] [P0] `Bit 3 RGB565`, `Bit 13 BC2` und `Auto`: richtige Quelle, erwartete Priorität, neutrale fehlende Daten.
- [ ] [P0] Makro-Farbmap 1024×1024 wird pro Pixel auf WorldLayer angewendet; kein Detailverlust durch 257×257-Vertex-Interpolationszwang.
- [ ] [P0] Neutralwert RGB(128,128,128) verfärbt Textur nicht; rote/blaue Testbereiche wirken kontrolliert und ohne Übersättigung.
- [ ] [P0] Tint Strength 0/1, Gamma/Linear-Umschalter, Texture Repeats 0.25–8 und Normal Strength 0–2: UI-Regler verändern die Render-Vorschau wie beschrieben.
- [ ] [P0] Welt-Normalen, Normalmap-Enable und Normal-Y-Richtung bei flacher Ebene und Steilhängen verifizieren.
- [ ] [P1] Debug-Viz: Weight RGB, Gewicht Slot 0–3, Macro RGB, roher Bit13-BC2-Alpha und Normalen; BC2-Alpha **nicht** als Transparenz behandeln.
- [ ] [P1] Color Brush: Color/Darken/Lighten/Smooth, visuelle Aktualisierung und Undo/Redo; Quellenwechsel verändert native Bits nicht ohne expliziten Save.
- [ ] [P1] Speichern auf **Testkopie** und neu laden: unveränderte Blocks byte-identisch; gewollte Farben/Gewichte persistieren; keine Originaldatei überschreiben.
- [ ] [P1] Standalone-AREA-vs-Streaming: Quelle Bit3/13 nur Standalone umschaltbar; sonstige Materialoptionen wirken in beiden Modi.
- [ ] [P2] LandPS t9/Height-/Offset-Blending und exakter Shader-Farbraum: offen, Originalshader-/Bildvergleich nötig.

## 5. Sky, Licht, Schatten und Fog (P0/P1)

- [ ] [P0] Zeit 00:00 / 06:00 / 12:00 / 18:00 / 24:00: Ambients, Sonnenfarbe, Sonnenwinkel, Fog-Werte wechseln plausibel.
- [ ] [P0] Sky-Ambient-Regler 0/1/2 beeinflusst **Terrain und M3/I3-Props**, nicht nur die Himmelskuppel.
- [ ] [P0] Sun illuminance 0/1/2 reagiert ohne Richtungs-/Sky-Sprünge; Sky SunDiffuse-Farbe bleibt erhalten.
- [ ] [P0] Schatten standardmäßig AUS. Beim Zuschalten entstehen auf Boden/Props plausible Sonnenschatten (3 Cascades bis 600 m).
- [ ] [P0] Abschatten ohne falsche Skybox-/Sonne-/Mond-/Dome-Schatten; bei 96-m-Cascade-Grenze und 600-m-Ende keine störenden Linien.
- [ ] [P0] Schatten Bias / Peter-Panning / Acne / dunkle Felsen und Höhenänderungen kontrollieren.
- [ ] [P0] Kamera-FogStart/FogEnd aus .sky, ClearColor und HorizonFogMod-Farbe in Szene korrekt; keine komplett weißen/schwarzen Übergänge.
- [ ] [P0] Zwei angrenzende Sky-Zonen: Hintergrund-/Fog-Farbe kontinuierlich und in linearem Farbraum gemischt; beim Streaming kein Snap.
- [ ] [P1] Sky-/CloudFog-/NightAmbient-/SunSpecular-Konventionen mit Originalbelegen prüfen; **nicht voll an PBR gekoppelt**.
- [ ] [P1] SunSpecular, Tonemapping/Exposure, Reflections/Light Probes und Cloud Shadows: **NICHT ORIGINALGETREU IMPLEMENTIERT**.
- [ ] [P1] Schatten an Vegetation mit GPU-Wind: Wind-Shader derzeit **ohne Shadow-Pass**, Schatten- und Lage-Divergenz als offenes Problem dokumentieren.

## 6. Clutter, Streaming und Performance (P0/P1)

- [ ] [P0] Statisches Modell in AREA und direkt geöffnetes M3 zeigen dieselbe Basismaterial-Textur.
- [ ] [P0] Gestreamte Props nutzen Layer-Materialien ebenfalls (nicht nur Standalone).
- [ ] [P0] Clutter-Wind bewegt passende Pflanzen; Steine/Kristalle bleiben statisch.
- [ ] [P0] Sichtbarkeits-LOD und Distance-Culling verursachen keine verlorenen Kinder oder falsches Re-Spawn.
- [ ] [P1] Clutter-Wind nutzt momentan Standardmaterial statt kombinierter Wind+M3-Layer-Pipeline; Unterschied explizit protokollieren.
- [ ] [P1] Wiederholtes Laden/Entladen und Wechsel zwischen Modellvorschau / AREA / Zone: keine Leaks, Crashs oder stale Material-Handles.
- [ ] [P1] 3×3 und 5×5 Terrain-Tiles: GPU/VRAM/RAM/FPS mit Schatten AUS/EIN vergleichen; Zahlen pro Szene festhalten.
- [ ] [P1] Sonnenlicht/Fog/Shader-Animation funktionieren bei FlyCam-Bewegung und Terrain-Sculpt/Paint-Live-Updates.

## 7. Testprotokoll pro Asset / Screenshot

Test-ID: ________ · Datum: ________ · Tester: ________  
Git SHA: ________ · Windows/GPU/Treiber/Backend: ________  
Originalasset (nur virtueller relativer Pfad): ________  
AREA/Zone/Sky-ID und Uhrzeit: ________  
Einstellungen: Schatten AUS/EIN, Ambient ___, Sun ___, Tint ___, Normal ___, Gamma ___  
Erwartung: ________ · Beobachtung: ________  
Konsole/Fehlertext: ________ · FPS ___ / VRAM ___ / RAM ___  
Screenshots: Genesis ________ / Original-Referenz ________ / Diff ________  
**Ergebnis:** PASS / FAIL / BLOCKED / KNOWN GAP · Ticket/Commit: ________

## 8. Abnahmekriterien

- [ ] **Build:** CI grün auf dem aktuell getesteten SHA (nicht nur auf älterem Commit).
- [ ] **Runtime:** repräsentative M3, I3 und AREA ohne WGPU-Panic/Validation Error auf Windows geladen.
- [ ] **Farbe:** mindestens ein Terrain-Makrofarbenvergleich, ein Layered-M3-Vergleich und ein Sky/Fog-Übergang mit Screenshots.
- [ ] **Schatten:** EIN/AUS getestet, kein Skybox-Schatten, dokumentierte Performance und Qualität.
- [ ] **Speicherung:** Read-only-Test ändert Original-Assets nicht; Save-Roundtrip nur mit Kopie.
- [ ] **Grenzen:** alle bekannten Annäherungen als „KNOWN GAP“ dokumentiert, niemals ungeprüfte Retail-Parität behauptet.
- [ ] **Freigabe:** Testprotokoll inkl. konkretem SHA, Plattform, referenzierten Assets, Ergebnissen und offenem Issue-Link vollständig.

**Priorisierung:** Erst P0-Crashes / WESL-Bindings / 4-Layer-/Terrain-Lighting / Sky-Schatten; dann P1 Originalshadersemantik und Performance; erst danach P2 Animation/FX-Parität.
