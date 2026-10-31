# WildStar Texture Format (.tex) Specification
**Decompiled from `WildStar64.exe` (`FUN_140298f20`, `FUN_1402af030`, table `0x140ae5200`)**

## 1. File Header (112 bytes / 0x70)

All fields are Little-Endian.

| Offset | Type | Field | Description |
|---|---|---|---|
| `0x00` | `uint32` | `magic` | `'XFG\0'` (or `0x00474658`, `\0 G F X`) |
| `0x04` | `uint32` | `version` | Always `3` in WildStar release |
| `0x08` | `uint32` | `width` | Base mip level width in pixels |
| `0x0C` | `uint32` | `height` | Base mip level height in pixels |
| `0x10` | `uint32` | `depth` | Depth / slice count (1 for 2D textures, 6 for cubemaps, >1 for 3D volume textures) |
| `0x14` | `uint32` | `flags` | Category flags (e.g. `6` = Cubemap if width == height and depth == 6) |
| `0x18` | `uint32` | `mip_levels` | Number of mipmap levels present |
| `0x1C` | `uint32` | `pixel_format` | Format enum index (0..26) into engine table `0x140ae5200` |
| `0x20` | `uint32[20]`| `mip_offsets` | Byte offsets or sizes for each mip level (header padded to 112 bytes) |

---

## 2. Engine Pixel Format Table (`0x140ae5200`)

Each entry is 44 bytes (`0x2C`), describing block dimensions, bit shifts, and stride.

| ID | Block W | Block H | Bytes / Block | Direct3D / DXGI Mapping | Common Usage |
|---|---|---|---|---|---|
| **0** | 1 | 1 | 4 | `DXGI_FORMAT_R8G8B8A8_UNORM` | Uncompressed 32-bit RGBA |
| **1** | 1 | 1 | 4 | `DXGI_FORMAT_B8G8R8A8_UNORM` | Uncompressed 32-bit BGRA |
| **2** | 1 | 1 | 2 | `DXGI_FORMAT_B5G6R5_UNORM` | 16-bit RGB 5:6:5 |
| **3** | 1 | 1 | 2 | `DXGI_FORMAT_B5G5R5A1_UNORM` | 16-bit RGBA 5:5:5:1 |
| **4** | 1 | 1 | 2 | `DXGI_FORMAT_B4G4R4A4_UNORM` | 16-bit RGBA 4:4:4:4 |
| **6** | 1 | 1 | 1 | `DXGI_FORMAT_R8_UNORM` | 8-bit Grayscale / Alpha mask |
| **7** | 1 | 1 | 2 | `DXGI_FORMAT_R8G8_UNORM` | 16-bit Dual Channel (UV/Normal) |
| **8** | 1 | 1 | 4 | `DXGI_FORMAT_R10G10B10A2_UNORM`| High-precision Color/Normal |
| **9** | 1 | 1 | 8 | `DXGI_FORMAT_R16G16B16A16_FLOAT`| 64-bit Half-Float HDR |
| **10**| 1 | 1 | 2 | `DXGI_FORMAT_R16_FLOAT` | 16-bit Single-Channel Float |
| **11**| 1 | 1 | 4 | `DXGI_FORMAT_R16G16_FLOAT` | 32-bit Dual-Channel Float |
| **13**| 4 | 4 | 8 | `DXGI_FORMAT_BC1_UNORM` (DXT1) | Opaque / 1-bit Alpha textures |
| **14**| 4 | 4 | 16 | `DXGI_FORMAT_BC2_UNORM` (DXT3) | Sharp alpha textures |
| **15**| 4 | 4 | 16 | `DXGI_FORMAT_BC3_UNORM` (DXT5) | Smooth alpha / normal maps |
| **18**| 1 | 1 | 8 | `DXGI_FORMAT_R32G32_FLOAT` | 64-bit 2-component Float |
| **20**| 1 | 1 | 16 | `DXGI_FORMAT_R32G32B32A32_FLOAT`| 128-bit Full HDR Float |
| **24**| 1 | 1 | Variable | Custom JPEG-compressed | High-res UI and world textures |
