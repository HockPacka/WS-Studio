# New AREA – erster Genesis-Test

Erzeugt native unkomprimierte aera-Dateien **ohne Vorlage und ohne TBL-Schreibzugriff**. Die Kompatibilität mit dem originalen WildStar-Spielclient ist bisher nicht bestätigt.

~~~powershell
cd GenesisRebuild
cargo run -p wildstar_formats --bin area_new -- --out "GenesisTest.4040.area"
~~~

Optional: --height 10 --layer-id 1234. Die ID 1234 ist nur ein Beispiel; für eine echte Textur muss sie in der vorhandenen WorldLayer.tbl existieren. Default-ID 0 bedeutet kein verpflichtender TBL-Bezug.

- 512 x 512 Meter, 256 Cells je 32 x 32 Meter.
- Bit 0: 19x19 Height einschließlich Halo (u16; native Einheit 1/8 m).
- Bit 1: vier Layer-IDs mit optionalem ersten Slot.
- Bit 2: 65x65 Authoring-Gewichte, 100 % auf Slot 0.
- Bit 3: 65x65 neutrale RGB565-Terrainfarbe.
- Andere Originalmetadaten (Zone/Sky/Clutter/Props/LOD, unbekannte Bits) werden **nicht** erfunden.
- New-File-Writer verwendet create_new und verhindert Überschreiben.

Eine Kopie für den normalen Genesis-Importer/Streamer in einer **separaten ClientData-Arbeitskopie** ablegen:

~~~text
ClientData/
  Map/
    GenesisTest/
      GenesisTest.4040.area
~~~

Die Koordinate 4040 ist Z=0x40, X=0x40 am Weltursprung. Für den ersten Test in Genesis Standalone AREA aktivieren und über File -> Open AREA laden. Ein indexierter ClientData-Root ist erforderlich. Danach Height-Sculpt, RGB-Preview/Color-Brush, Save-As auf eine Kopie und Reload testen.

Alle Tests: cargo test -p wildstar_formats. Eine erfolgreiche Rust-Parser-Roundtrip-Prüfung sagt **noch nichts** über Pflichtblöcke des Originalclients aus. TBL-Registrierung kommt **nach** dem erfolgreichen ersten AREA-Test.
