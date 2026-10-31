# Sky and atmosphere shader assignment

The extracted sky system spans several passes. A `.sky` file supplies parameters and resources to those passes; there is no single shader assigned one-to-one to each file. Associations below use original WildStar64 creation functions plus disassembled shader code, not filenames alone.

**45 SHO files, 15 families, 468 compiled programs** were parsed and disassembled: 234 Shader Model 3 and 234 Shader Model 4 programs. [Manifest](sky_analysis/shaders/shader_manifest.json) retains source SHA-256, offsets, resource declarations, permutation maps, input-layout maps and links to every disassembly.

## Verified associations

Counts are compiled programs / permutation slots **per profile**, identical in both audited profiles. Slots may share compiled programs.

| Family | Programs / slots | Role | Original creator / member |
|---|---:|---|---|
| SkyVS | 2 / 2 | Sky geometry; directional SH + indexed color bands | 1407c3b60 / +1678 |
| SkyPS | 2 / 2 | Sky color output | 1407c3b60 / +1680 |
| M3CloudVS | 9 / 12 | Cloud model geometry and UV generation | 1402eb270 |
| M3CloudPS | 2 / 2 | Cloud lighting, color lookup, sun highlight and fog | 1402eb270 |
| LightSunSkyPS | 96 / 96 | Deferred sun/sky lighting of scene surfaces | 140253a90 / +888 |
| FogVS | 1 / 1 | Fog pass geometry | 140253a90 / +890 |
| FogPS | 80 / 96 | Scene fog variants | 140253a90 / +898 |
| FogDepthPS | 21 / 24 | Depth-dependent fog support | 140253a90 / +8A0 |
| fogSkyps | 1 / 1 | Sky/fog composition | 140253a90 / +848 |
| CompositeEnvMapPS | 5 / 5 | Environment-map composition | 1407c3b60 / +1688 |
| FilterEnvMapPS | 1 / 1 | Environment-map filtering | 1407c3b60 / +1690 |
| DownsampleEnvMapPS | 1 / 1 | Environment-map downsampling | 1407c3b60 / +1698 |
| CompositeCUBEMapPS | 5 / 5 | Cubemap composition | 1407c3b60 / +16A0 |
| CompositePS | 6 / 6 | Scene postprocess/composition | 140253a90 / +868 |
| scatterPS | 2 / 2 | Supporting screen-space scatter effect | 140253a90 / +8E0 |

Creation evidence: [sky manager](sky_analysis/ghidra/FUN_1407c3b60.c), [cloud renderer](sky_analysis/ghidra/FUN_1402eb270.c), [frame renderer](sky_analysis/ghidra/FUN_140253a90.c). Member offsets are hexadecimal.

### Bytecode details that matter for compatibility

`SkyVS` SM4 variant 0 declares CB0[31]. It uses view/projection data, evaluates second-order directional SH from CB0[8..14], and adds one of sixteen color bands from CB0[15..30]. The band index is encoded in input vertex z, scaled by approximately 255. `SkyPS` variant 0 clamps RGB to 1.5 and emits alpha zero. Native sky output therefore combines authored lighting/gradient data and geometry. A generic blue dome would discard that data.

`M3CloudPS` uses the texture's red channel to address a separate color lookup (sample coordinate 0.03125 + 0.9375 × red), and uses texture alpha for coverage. It also applies SH lighting, a sun highlight and fog. Displaying its texture as ordinary model diffuse color cannot reproduce the original appearance.

`LightSunSkyPS` lights scene surfaces; it is not the sky geometry pass. `scatterPS` alone is not evidence of a physical Rayleigh/Mie atmosphere. The exact route from `.sky` LUT at 0x4B0 to a specific CompositePS slot is still open; no slot assignment is claimed here.

## SHO container formats

Generic files such as `SkyVS.sho` are **SHDR v2 dispatch containers**, not compiled bytecode. Header size 0x20, AP at 0x08; its 24-byte entries contain u64 stage selector, UTF-16 count and relative string offset. String base is align16(end of entry table). Selectors 0/1 choose SM3 VS/PS, 2/3 choose SM4 VS/PS.

Profile files such as `SkyVS.vs_4_0.sho` are **STGT v3**, fixed header 0x50:

| Header offset | Content |
|---|---|
| 0x08 | AP of compiled code descriptors: u64 size + u64 relative offset |
| 0x18 | AP of u32 permutation-to-code indices |
| 0x28 | AP of input signature/layout descriptors |
| 0x38 | AP of u32 permutation-to-layout indices |
| 0x48 | Unresolved header word(s) |

Descriptor tables are relative to header end. Payload offsets are relative to the aligned end of their own descriptor table. A layout index of 0xFFFFFFFF is allowed. Input signatures can also begin with DXBC but contain only ISGN/OSGN metadata; scanning for DXBC magic and counting each hit as a shader overcounts programs. The reader keeps metadata separate from SHDR/SHEX programs.

## Next implementation boundary

The raw format and pass inventory are available. The [first client integration, dbg47](sky_integration_dbg47.md), implements spatial/time selection and CPU sky SH/band rendering. [dbg49](sky_integration_dbg49.md) adds authored sky model instances and a D3D9 cloud-shader adaptation with moving CloudSet fields. The complete rendering pipeline needs:

1. WorldSky resolution from AREA corners, spatial blending of up to four skies, and day-time evaluation with per-record semantics.
2. Native SH/band sky geometry and matching shader constants; preserve sun, moon, glare and skybox M3 references.
3. CloudSet/CloudTrack placement plus the dedicated cloud material/color-lookup path.
4. Fog and surface lighting transfer to the WoW frame pipeline, then cubemap and 3D LUT loading/composition.

Some parameter labels, mixed-record components and permutation-bit meanings remain unresolved. Neither the Python linear helper nor the manifest is a complete replacement renderer. The first client integration adapts the sky polynomial to WoW's vertex-color draw path; it does not execute these SHO programs directly.
