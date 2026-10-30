# WildStar M3 native parser — ABI v2 (Model Studio 0.4)

This is a **self-contained native C11 reader**, not a binary writer, animation player or proprietary engine emulator. `ws_m3_parser.dll` is a Windows x64 DLL with no third-party runtime DLL requirement; `libws_m3_parser.so` is the Linux test build. The DLL owns its returned JSON buffer and the caller must release it using `ws_m3_free`.

## Binary format

LDOM v100, 0x630-byte file header; all top-level array descriptors are relative to 0x630. Nested arrays/tracks use separate alignment bases. Decoding follows `HockPacka/WS-Tools` `docs/m3_format_spec.md` and `M3Reader.cpp`.

## Implemented parsing

- Geometry and submeshes, local triangle indices, mesh flags, LOD/variant group and cluster IDs. Rendering output is limited to 350 meshes / 750,000 vertices for the WebGL preview; the complete **geometry inventory** is still returned.
- Packed or float positions, octahedral normals/tangents/bitangents, both UV sets (half floats), two vertex color channels, local bone indices and weights; per-mesh bone-palette ranges.
- All 8 tracks per bone (scale, parent scale, rotation, translation, and four secondary tracks), with packed float values and time arrays; bind matrices, inverse binds, pivot, parent, depth, IDs and bone map. **Parsing is not animation playback or weight deformation.**
- Animation clip start/end, duration, blend metadata, variant and speed; texture paths (UTF-16), IDs, flags; material headers and all four material layers, with float-parameter tracks (gloss/glow/opacity etc.) as packed arrays.
- Attachments, cameras and lights (raw descriptors plus known IDs), particle/ribbon emitters (known fields, visibility curves, texture/shape/flipbook, particle properties, and record descriptors), collision record inventory, complete raw header for unresolved fields, plus sound event/emitter, state animation, mesh display, face-customization and collision-proxy tables.
- FX-only/metadata-only M3 is valid even without drawable triangles; error messages for damaged pointers, wrong versions and impossible vertex layouts.

All track `times`/`values` fields are base64 encoded arrays of little-endian `uint32` / `float32`, respectively. Mesh positions/normals/tangents/UVs are likewise packed `float32`, colors and weights packed `uint8`, indices packed `uint32`.

## Explicitly not complete yet

- The full original-game semantics of the rare/opaque header blocks, secondary pose logic and unknown effect parameters remain under reverse engineering. Raw header/material/FX descriptors are exposed so they are not silently guessed.
- The `.tex` image decoder / color, normal, gloss, glow, alpha shaders, mesh skinning, animation playback and GPU FX have **not** been implemented in the viewer. The parser reports data; the renderer must use it.
- Large model preview still has limits; parsed geometry outside the preview budget is reported but not drawn.
- Only synthetic source-compatible fixtures were run in this environment. Actual WildStar asset acceptance and visual equivalence need dedicated corpus and Windows runtime tests. This version should not be called 100% complete.

## ABI

```c
uint32_t ws_m3_abi_version(void); /* 2 */
int ws_m3_parse_json(const void *bytes, size_t size, const char *filename,
                     char **json, char **error);
void ws_m3_free(void *pointer);
```

Both successful and error pointers are owned by the parser; never release them with `free()` from a different runtime. The bridge in `native_m3.py` checks ABI version **2**.

## Build / validate

Windows: run `native/build_windows_msvc.bat` in a Visual Studio Developer Command Prompt, or use the bundled precompiled x64 DLL.

Linux:

```sh
cc -std=c11 -O2 -fPIC -shared native/ws_m3_parser.c -o native/libws_m3_parser.so
python -m unittest discover -s tests -v
python diagnose_m3.py demo/Crystal.m3 --export-json crystal.json
```


### v0.7.1 Avatus Indexbuffer-Fix

The 16-byte geometry array descriptor at `geometry + 0x70` contains the
**byte length** of the u16 index stream, not the element count. The u16
index count is separately stored as u32 at `geometry + 0x68`. Use AP stride
1, then check `ap_count >= indexCount * 2`. The previous stride 2 multiplied
the physical byte count twice and silently skipped valid Avatus meshes.

Regression: `python -m unittest tests.test_m3_real_index_layout -v`.
Windows DLL build: `bash native/build_windows_cross.sh` from project root.
ABI remains 2; compiled Windows consumers must replace the DLL.
