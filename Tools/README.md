# Tools for WildStar decompilation / extraction

All repos are shallow clones (`git clone --depth 1`) in this folder.

## WildStar side
| Tool | Path | Purpose |
|---|---|---|
| Halon (Python) | `Halon/halon.py` | list / find / extract `.index` + `.archive` (`python -I halon.py <archive> list\|find\|extract`). Needs `<name>.index` + `<name>.archive` side by side. |
| NexusVault CLI (Java) | `NexusVault-CLI-0.4.1-bin/Nexusvault/NexusvaultCLI.exe` (source: `NexusVault-CLI/`) | search / export archive content, converts to common formats. Commands: `archive "path"`, `search <regex>`, `show search`, `export`. |
| NexusVault-Java | `NexusVault-Java/` | library incl. M3 -> glTF exporter (`nexusvault.format.m3.export.gltf`) and **010-Editor binary templates** for ARCHIVE, AREA, BIN, M3 (v100), TBL, TEX in `docs/binary-templates/`. Main format reference for this project. |
| Nexus.Archive (C#) | `Nexus.Archive/` | .NET library for reading/writing WildStar index/archive. Needs .NET SDK. |
| NexusForever (C#) | `NexusForever/Source/NexusForever.IO` | reference readers: `.area` (`Area/*`: CHNK, CURT, CURD, DHMO, PROP, WATG, WBSP) and `.map`. `NexusForever.MapGenerator` shows how the archive is used. |
| DtblReader (C#) | `DtblReader/` | `.tbl` game table viewer. |
| wildstar-api-docs | `wildstar-api-docs/` | Lua API docs. |
| Ghidra 12.1.4 | `../ghidra_12.1.4_PUBLIC/` | RE of `Client64/WildStar64.exe` (needed for `.m3`, no public reader exists). |

## WoW 3.3.5a side
| Tool | Path | Purpose |
|---|---|---|
| warcraft-rs (Rust) | `warcraft-rs/` | M2 / ADT / WDT / BLP / MPQ crates, usable from Bevy. |
| StormLib (C) | `StormLib/` | MPQ read/write, to pack a 3.3.5a patch MPQ. |
| WoWDBDefs | `WoWDBDefs/` | DBC column definitions (CreatureModelData, etc.). |

## Raw extraction
`../extract_raw.cmd` runs `extract_raw.py` (Halon-based, resumable, supports deflate/LZMA) and writes to `../extracted/<archive>/`. Optional argument: sub-folder, e.g. `extract_raw.cmd Art\Creature`.

## Notes
- The installed index is `Patch/ClientData_16042.index`; Halon expects `ClientData.index`. `_archive_link/` holds a copy of the index and a hard link to the archive so Halon can open it without touching `WildStar/Patch`.
- `.m3`, `.tex`, `.area`, `.tbl` are documented as binary templates in `NexusVault-Java/docs/binary-templates/`; Ghidra on `WildStar64.exe` is for filling gaps/verifying.

## M3 decoding tools (this project)
| Tool | Purpose |
|---|---|
| `validate_formats.py`, `validate_m3_*.py`, `validate_emitters.py`, `validate_materials.py` | per-format / per-block validation on every extracted file |
| `validate_blocks.py` | layouts of the rare header blocks (0x2B8, 0x308, 0x318, 0x328, 0x490, 0x4A0, 0x510-0x5C0) from the engine loader, bounds on all models |
| `validate_semantics.py` | cross references (bone / sound / camera / animation indices, kd-tree consistency) -> `docs/m3_blocks_semantics.json` |
| `m3walk.py`, `analysis/coverage.py` | structure model of the whole file and its byte coverage -> `docs/m3_coverage.json` (99.9 % explained) |
| `test_extras.py` | runs `wildstar_m3/extras.py` over all models |
| `analysis/block_stats.py`, `block_dump.py`, `flat_stats.py`, `field_ref_test.py`, `dp_ref_test.py`, `check_ids.py` | exploration helpers (field statistics, which array an index field points into, which game table an id belongs to) |
| `analysis/header_scalars.py`, `bounds_groups.py`, `special_bones.py` | header scalar region (bounding volumes, head bone ...) |
| `ghidra_scripts/` | headless Ghidra helpers (`DecompAt`, `FindDisp`, `RefsTo`, `FindConst`, `FindString`) |
