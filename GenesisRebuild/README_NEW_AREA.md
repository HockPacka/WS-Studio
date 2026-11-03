# New AREA in Genesis Editor

File > New, File > New AREA... and the existing NewCentral toolbar control
now open the same New AREA dialog. The previous menu action was a no-op.

Default output: WS-Studio/ClientFiles/Map/GenesisTest/GenesisTest.4040.area
(when started from the GenesisRebuild folder). Output can be changed.

Enter map name, tile X and Z, flat height in metres, optional WorldLayer ID.
Create AREA writes 256 native cells with the existing AreaBuilder, re-reads
the file from disk, and immediately loads its terrain with Standalone enabled.
A height debug/colour view works without WildStar ClientData or TBL files.
New uses create_new and refuses existing destination files.

The default map is an uncompressed Genesis-compatible test AREA; it does
not automatically add TBL rows, new Sky/Zones, Clutter or retail-game
specific optional blocks.

Validation: File > New opens dialog; Create makes file and visible terrain,
including without ClientData; editing with Height Brush and Save As works.
Second Create on the same path fails without overwriting.
Check alternate tile coordinates, invalid paths, and Windows UI scaling.

Build: cargo test -p wildstar_formats; cargo check -p genesis;
cargo check -p genesis --tests. Execute local editor unit tests with
cargo test -p genesis new_area. Windows GPU/manual launch still required.

## Visibility fix: generated flat terrain

Newly created areas now frame the entire 512-m tile in orbit camera mode rather than retaining a previous first-person yaw/pitch. Tiles without a decoded WorldLayer atlas use an unlit Bevy StandardMaterial with the native vertex-colour debug mesh, not the custom WESL splat shader. Switching terrain preview modes still replaces the Mesh3d asset on both material paths. This preserves the original Genesis window layout; it does not yet prove Windows GPU runtime parity.
