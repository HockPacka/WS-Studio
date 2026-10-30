# GenesisRebuild – Responsive UI und klassische Menüs

Die Oberfläche bleibt am originalen Genesis-Look orientiert: heller Windows-Header, schmale Werkzeug-Icons, großer 3D-Viewport, Eigenschaften-/Palettenfenster und untere Occlusion-Leiste. Die Menüs sind zunächst Platzhalter, soweit nicht ausdrücklich anders bezeichnet.

## Anpassung an die Fenstergröße

- **Obere Menüleiste:** `File, Edit, View, Select, Terrain, Objects, Clutter, Water, Environment, Zones, Window, Help`. Bei geringer Breite umbrechende Menüeinträge; Symbolleiste in Gruppen (`Main, Terrain, Props, Environment, Zones`).
- **Mittiger 3D-Viewport:** Füllt immer den Rest zwischen Header, Dock und Bottom-Panels. Der Bevy-Kamera-Viewport nutzt echte Fenster-Pixelkoordinaten, einschließlich Windows-DPI und egui-Zoom.
- **Rechter Dock:** Durch Ziehen an der linken Kante in der Breite verstellbar (188–440 logische Pixel); Tabs `Brush, Palette, Texture, Clutter, Objects, World, AREA`; Inhalte sind vertikal scrollbar.
- **Unterer Workspace:** Durch Ziehen an seiner oberen Kante in der Höhe verstellbar (46–190 logische Pixel), ein-/ausblendbar. Tabs `Occlusion, Layers, Selection, Navigation, Output`. Unterste Statusleiste bleibt sichtbar.
- **Kompaktmodus:** Unter ca. 1000 logischen Pixeln erscheinen gruppierte Symbolleisten, unter ca. 610 logischen Pixeln wird der rechte Dock zugunsten des 3D-Viewports ausgeblendet. Für sehr schmale Fenster können Werkzeugfenster über `Window → Float Properties` geöffnet werden.
- **Zoom:** `View → UI 80%`, `UI 100%`, `UI 125%`, `UI 150%`. Der native Monitor-Skalierungsfaktor bleibt erhalten.
- **Original-Floating-Modus:** Über `Window → Float Properties` wiederherstellbar; zurück zu den verstellbaren Bereichen über `Window → Dock Properties`.

## Bedienung

Im bestehenden Branch `feature/genesis-raw-area-3d`:

```powershell
cd GenesisRebuild
cargo run -- "../WildStarModelStudio/demo/Hills.area"
```

Über `File → Open AREA...` kann eine andere originale WildStar-`.area` geladen werden.

Die Eigenschaftenfenster sind weiterhin reine UI-Platzhalter; der 3D-Viewport und der Raw-AREA-Leser bleiben funktionsfähig. Die Höhe, Layer- und Zonen-IDs im AREA-Tab stammen direkt aus dem eingelesenen Rohformat. Es werden keine AREA-Dateien verändert.

## Windows-Buildprüfung

```powershell
cargo check
cargo test --bin genesis
```

Die GitHub Actions in `.github/workflows/genesis-ui.yml` führen Compile- und AREA-Leser-Tests aus. Die tatsächliche Anordnung auf mehreren Windows-DPI-Einstellungen und die visuelle Ähnlichkeit mit den zehn perspektivischen Referenzaufnahmen müssen zusätzlich in einem geöffneten Fenster geprüft werden.
