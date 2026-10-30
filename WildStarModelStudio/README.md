# WildStar Model Studio v0.9 – M3 Animation Player

**Neu:** Echte Skelett-Wiedergabe im Viewport für primäre WildStar-M3-Bone-Tracks (nicht nur Animationseinträge im Inspector).

- Animationen auswählen, abspielen, pausieren, im Loop wiedergeben, Zeit scrubben, Geschwindigkeit von 0,25x bis 4x, Stop/Reset und Bind-Pose-Vergleich.
- WebGL2-GPU-Skinning mittels RGBA32F-Matrixtextur; Bone-Palettes pro Mesh, vier Knochengewichte pro Vertex und parent-hierarchische Bewegungen.
- M3-Scale/ParentScale, Translation und Quaternion-Rotation mit Slerp. Die M3-Clips haben original globale Start-/Endzeiten.
- Unter **Animiertes Demo öffnen** liegt ein synthetisches M3 mit gewichteter Geometrie und echter Trackanimation – ideal zum schnellen Funktionscheck.
- Die bisherigen TEX-Materialanimationen, FX-Atlasvorschau und M3-Parser-DLL bleiben enthalten.
- Tastenkürzel im Viewport: **Leertaste** Play/Pause, **Pfeil links/rechts** 100 ms vor/zurück.

## Start und Verifizierung

1. `start_desktop_windows.bat` starten (Python 3.10+, WebView2); oder mit `build_windows.bat` auf Windows eine eigenständige `.exe` erstellen.
2. **Animiertes Demo öffnen** wählen – hier sollten sich drei Kristalle bewegen, wenn WebGL2 verfügbar ist.
3. Für Originale: `Avatus.m3` öffnen, im **M3 ANIMATION PLAYER** eine Sequenz wählen und Play drücken.
4. **Bind-Pose anzeigen** einschalten, um die starre Originalgeometrie zu vergleichen.

**Teststand:** 48 Python-Tests und JS-Tests erfolgreich. Synthetische gewichtete Geometrie wurde mit der tatsächlichen DLL verarbeitet. Der Browser-UI-Test besteht; die WebGL2-GPU-Verformung konnte hier nicht geprüft werden, weil der Headless-Browser keinen WebGL2-Kontext anbietet. Avatus auf dem Windows-Zielsystem ist ebenfalls noch nicht visuell verifiziert.

**Wichtig:** Sekundäre M3-Pose-Tracks (1/3/5/7), exakte Bone-Vorzeichenkonventionen für alle Sonderfälle, Animationstransitionen, Root-Motion-Semantik und WildStars native `.sho`-Shaderlogik sind noch unvollständig. Dies ist eine bind-pose-erhaltende Vorschau, keine pixel-/pose-genaue Reimplementierung des Originalclients.

---

## Changelog aus früheren Versionen (v0.8 und älter)

*Die nachfolgenden historischen Einschränkungen beziehen sich auf die jeweils ältere Version. Insbesondere die Aussage, dass keine Skelettanimation unterstützt wird, ist durch die neue v0.9-Funktion überholt.*

# WildStar Model Studio v0.8 — Animierte Materialien / TEX

**NEU:** Die vorhandene native M3-DLL (ABI 2) enthält bereits die keyframe-basierten M3-Material-DPs. Ab dieser Version wertet der Viewer diese Keyframes während der Wiedergabe aus, statt immer nur den ersten Wert zu verwenden.

- Animierte M3-Kanäle: **Gloss, Glow, Opacity und ColorMod (RGB)**; lineare Keyframe-Interpolation mit originalen Zeitstempeln in Millisekunden. Andere Materialparameter bleiben im Explorer lesbar, sind aber nicht als Shader-Effekte nachgebildet.
- **Timeline:** globaler M3-Zeitraum oder Clip auswählen; Play/Pause, Scrub, Loop und 0.25×–4× Wiedergabegeschwindigkeit.
- **Manuelle UV-Vorschau:** Scroll U/V, Rotation und Tiling. Diese Werte kommen ausdrücklich *nicht* aus einer bestätigten M3-UV-Animation, sondern sind ein Vorschau-Effekt für .tex-Materialien. Einschalten startet die Wiedergabe.
- **M3-Partikel-Flipbook-Atlas:** nutzt `flipbookCols`, `flipbookRowShift`, `flipbookFrames`, `flipbookSpeed` und die Textur-Referenz aus M3-Emitter-Templates; Einzelbildwiedergabe im Inspector, **keine 3D-Partikelsimulation**. Die Zuordnung von `flipbookSpeed` zu Frames pro Sekunde ist eine Vorschauannahme.
- Material-TEX-Pipeline, Avatus-Paketnavigation, Indexbuffer-Fix und native DLL aus **v0.7.1** bleiben unverändert.

## Start

`start_desktop_windows.bat` starten (Python 3.10+), `Avatus.m3` oder eine andere `.m3` öffnen und rechts unter **ANIMIERTE TEX / MATERIALIEN** die Zeitachse benutzen. Die EXE lässt sich mit `build_windows.bat` unter Windows neu bauen; dazu wurde `material_animation.js` im PyInstaller-Bundle ergänzt. Eine fertig gebaute Windows-EXE liegt im ZIP nicht bei.

## Wichtige Einschränkungen

- Keine native Interpretation unbekannter `ModelPS/ModelVS`-Shaderpermutationen. Die Materialdarstellung und Interpolation sind eine nachgebildete Vorschau, nicht identisch mit dem originalen WildStar-Renderer.
- Für die drei direkt untersuchten Avatus-Nebenmodelle (Gun, HandLf, HandRt) wurden **keine M3-Material-Kanäle mit mehreren Keyframes** gefunden und keine Partikelemitter. Für das große Avatus-Hauptmodell ist diese konkrete Prüfung noch ausstehend. Zum Anschauen von Animationseffekten bei statischen Materialien die Option **UV-Bewegung (Vorschau)** nutzen.
- Es wird **keine Bone-Animation**, SkinFX-Simulation oder Partikelsimulation im 3D-Viewport wiedergegeben.
- Browser-/Desktop-UI in Headless-Chromium ohne JavaScript-Fehler getestet; WebGL2-GPU-Ausgabe im Testsystem nicht verfügbar. Für Windows-GPU und originale Avatus-Hauptdatei ist ein Praxistest nötig.

## Tests

- Python: `python -m unittest discover -s tests -q`
- JavaScript: `node tests/test_material_animation.js` und `node tests/test_material_renderer.js`

---

# WildStar Model Studio v0.7.1 – Avatus Geometrie-Hotfix

**Native Windows-x64-M3-Parser (ABI 2), WebGL2-Materialrenderer und TEX-Decoder.**

## v0.7.1 – Fehler aus `avatus_report.json` behoben

**Ursache:** Der M3-Parser behandelte `Geometry +0x70` als `count * 2` Bytes.
Bei WildStar M3 enthält das Array aber bereits die **Byteanzahl** der u16-Indizes;
`indexCount` an `Geometry +0x68` enthält separat die Anzahl der u16-Indizes.
Der doppelte Faktor 2 führte bei großen Avatus-Modellen zu einem stillen
"out of file bounds" und `meshCount = 0`, obwohl die Binärdateien Meshes enthalten.

**Fix:** Native-DLL liest das Array nun in Bytes und prüft ausdrücklich
`indexByteCount >= 2 * indexCount`. Die statische Geometrie wird wieder
an den Viewer übergeben. Zusätzlich meldet `check_avatus.py` jetzt
`rawMeshCount`, `rawVertexCount`, `rawIndexCount`, `partsWithRenderedMeshes`
und `partsWithLostGeometry` statt fehlende Meshes nur als Warnung zu behandeln.
Ein fehlender Mesh-Output bei nachgewiesenen Roh-Meshes führt zu einem
Fehler-Exitcode. Die BAT akzeptiert nach wie vor sowohl eine `.m3`-Datei
als auch einen Verzeichnispfad.

**Validierung:** 46 Python-Tests + JS-Tests bestanden, einschließlich
End-of-file-Indexbuffer-Regressionstest. Die drei kleineren originalen
Avatus-Dateien wurden außerdem direkt als Binärdateien aus dem Repository
strukturell ausgewertet: Gun 2 Meshes/2.116 Dreiecke,
HandLf 3 Meshes/1.956, HandRt 3 Meshes/1.956, alle lokal indiziert
und ohne ungültige Dreiecke. **Das 4,25 MB große Hauptmodell wurde mit der
neuen DLL auf dem Ziel-Windows-PC noch nicht getestet.**

**Aktualisierung von v0.7:** Die alte Desktop-Anwendung beenden, die Dateien
vollständig aus diesem ZIP ersetzen (insbesondere `native/ws_m3_parser.dll`),
und `start_desktop_windows.bat` erneut starten. Falls du bereits eine
PyInstaller-EXE gebaut hast, musst du sie mit `build_windows.bat` neu bauen.
Danach `check_avatus_windows.bat` mit deinem `Avatus`-Ordner ausführen und
`avatus_report.json` prüfen.


## Avatus direkt öffnen

1. `WS-Tools` als ZIP herunterladen und vollständig entpacken (oder klonen).
2. Verzeichnis `Avatus` muss die Dateien `Avatus.m3`, `Avatus_Gun.m3`, `Avatus_HandLf.m3`, `Avatus_HandRt.m3` und `Textures/*.tex` enthalten.
3. `start_desktop_windows.bat` ausführen, danach **Datei vom PC öffnen** → `Avatus.m3` wählen.
4. Links unter **MODEL PACK** zwischen Hauptkörper, Waffe und linker/rechter Hand wechseln.
5. Rechts unter **MATERIAL PREVIEW** und **ASSET PACK CHECK** die geladenen Texturen und fehlenden Referenzen untersuchen; **M3 DATA EXPLORER** für Bones, Animationstracks, Attachments etc.

### Neu in v0.7

- **Sichere Avatus-/Creature-Paketpfade:** `Art\Creature\Avatus\Textures\*.tex` wird bei entsprechendem Modellordner aus `Avatus/Textures/*.tex` gefunden. Case-insensitive; keine Suche nach zufälligen Dateien auf dem gesamten Laufwerk; keine Symlink-Pfadflucht.
- **Modellpaket-Navigation:** verwandte M3-Dateien im selben Verzeichnis auswählen, ohne einen neuen Dateidialog öffnen zu müssen.
- **Zusätzliche TEX-Galerie:** zeigt auch `.tex`-Dateien des Pakets, die nicht direkt zum aktuellen Mesh-Material gehören.
- **Shader-Fixes:** tatsächliche Diffuse-Farben werden nicht mehr durch Platzhalter-Mesh-Farben gefärbt; transparente Materialien nach Opaque-Teilen gerendert.
- **TEX-Caching über Teilwechsel hinweg**, einschließlich WildStar JPEG-like-Texturen.
- **Avatus-Validierungsprogramm:** `check_avatus_windows.bat` mit Avatus-Ordner aufrufen (oder `python check_avatus.py <Avatus-Ordner> --json avatus_report.json`).

### Teststatus

46 Python-Testfälle, JS-Material- und M3-Explorer-Tests bestanden. Aus dem GitHub-Repository wurden drei kleinere Avatus-M3-Dateien strukturell und alle zehn TEX-Header geprüft. **Der originale Hauptkörper und die Bilddaten der JPG-like TEX-Dateien konnten hier nicht als Binärdateien auf dem nativen Parser ausgeführt werden.** Der lokale vollständige Test mit den Originaldateien bleibt notwendig; siehe `AVATUS_COMPATIBILITY.md`.

## Windows-Desktop-Programm

`start_desktop_windows.bat` startet den Viewer (Python 3.10+, pywebview, WebView2). `build_windows.bat` erstellt unter Windows mit PyInstaller eine portable `WildStarModelStudio.exe` samt DLL. Das ZIP enthält die native `ws_m3_parser.dll`, aber **keine bereits kompilierte Windows-EXE**.

### Bekannte Einschränkungen

- Der Viewer rendert einen statischen Bind-Pose-/Mesh-Preview; er **spielt noch keine M3-Bone-Animationen ab**, simuliert keine Partikel und montiert nicht automatisch die Hände/Waffe an Animations-Bones. Die zusätzlichen Modelle sind einzeln einlesbar.
- Diffuse, Normal, Alpha, Gloss, Glow und bis zu vier Layer sind vereinfachte WildStar-Nachbildungen, nicht die originalen `SHO`-Shader-Permutationen.
- JPEG-like TEX TYPE1/2/3 ist implementiert, muss aber an den Originaldateien visuell überprüft werden.
- Eine echte GPU-Vorschau im Windows WebView2 war in der hiesigen Umgebung nicht testbar.

## Andere unterstützte Formate

M3, I3 und AREA bleiben unterstützt. Frühere Funktionen, Testskripte und native DLL-Buildskripte liegen weiterhin im Paket.


## v0.9 – M3 Skelettanimationen (Animation Player)

- Animation Player: normale M3-Clips aus der Originaldatei auswählen, Play/Pause, Scrub, Geschwindigkeit, Bind-Pose und Stop/Reset.
- GPU-Skinning über ein WebGL2 RGBA32F-Bone-Matrix-Texture; unterstützt auch >200 Bones (z. B. Avatus).
- Mesh-Bone-Palettes und vier Vertex-Einflüsse werden korrekt über die native ABI-2-DLL ausgelesen.
- Primäre Tracks: Scale/ParentScale, Quaternion-SLERP, Translation; Clipzeiten sind die globalen M3-Millisekunden.
- Bind-Pose-korrigierte Weltmatrizen mit automatischer Vorzeichen-/Signatur-Suche; ohne aktive Animation bleibt die Geometrie unverändert.

**Grenzen:** Die originalen sekundären Pose-Tracks 1/3/5/7, Clip-Übergänge, Root-Motion-Interpretation und Sonderfälle von WildStar-Mesh-/Shaderpermutationen sind noch nicht vollständig entschlüsselt. Keine pixelgenaue WildStar-Engine-Emulation. Dieser Player verwendet eine Bind-Pose-erhaltende Näherung nach der Analyse in `WS-Tools/wowdecomp/Engine/Source/Model3/M3Anim.cpp`.


## v0.9.1 – Unsichtbare Modelle durch Renderfehler behoben

- **Kritischer Fix:** Der Render-Loop in v0.9 verwendete `usingSkeleton` ohne Initialisierung. Das erzeugte bei jedem Mesh einen `ReferenceError` und ließ alle Modelle verschwinden. `updateSkeletonGPU()` wird jetzt vor der Render-Schleife aufgerufen und der Zustand definiert.
- Die Bone-Textur wird in jedem benötigten Frame aktualisiert. Bisher wurde sie nur einmal mit Identitätsmatrizen angelegt.
- WebGL-GPU-Fehler bei der Bone-Textur-Erstellung und -Aktualisierung deaktivieren Skinning und lassen die statische Geometrie sichtbar.
- Kein erneutes Exportieren der M3-Modelle erforderlich; die bestehende native ABI2-DLL bleibt unverändert.
