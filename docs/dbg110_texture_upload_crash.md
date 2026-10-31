# dbg110 crash: single-level WildStar BLP upload

Dump: `WoWClient/Errors/2026-10-28 18.25.10 Crash.dmp`.
Report: same timestamp `.txt`. Player in Tremor Ridge / Western Algoroc.

Local CDB stack: VCRUNTIME140!memmove -> Blit -> CGxDeviceD3d::ITexUpload -> ITexMarkAsUpdated -> GxTexUpdate -> PumpBlpTextureAsync -> CreateBlpTexture -> TextureCreate -> CM2Shared::Initialize / FinishLoading / LoadM3. The failure is a read of 65536 bytes through invalid source 0x2373e6614d4 while uploading a 256x256 level.

Preserved PumpBlpTextureAsync RDI identifies CTexture at 0x237e95e94c0. Its filename at +0xC0 is:
`WS\UI\Interface\Overheads\friends_family\UI_Overhead_NotEligible_FF_Color`.
CDB evidence: `build_m3test/dbg110_dump_stack.txt`, `dbg110_dump_texture.txt`.

The actual TEX contains one 512x512 DXT5 level. Independent conversion yields a 263316-byte BLP: no-mips header, mip0 offset 1172 / size 262144, all remaining offsets/sizes zero. The pump fills only mip0. Its old non-mip filtering restriction applied only to widths below 256. For this 512 texture, ITexWHDStartEnd requests a full chain under mip filtering and encounters stale shared s_mipBits pointers at subsequent levels. This is an upload-level count mismatch, not evidence of a malformed character model or race icon.

Fix: TextureConstrainMipFilter in Services/TextureMipPolicy.h applies the single-level policy for every size. It preserves nearest filtering below 256, uses linear filtering for larger textures, and disables forced mip tracking so the device requests only level zero. Complete mip chains and GPU-generated mip paths keep their flags. PumpBlpTextureAsync uses the helper before allocating/uploading the GPU texture. Conversion output/cache versions are unchanged; clearing asset caches is unnecessary.

`texture_upload_cli` converts the actual crash TEX and checks that every input filter/tracking combination meets the engine's single-level upload precondition; its available mip0 payload is in bounds and copied successfully. It also checks the prior small-texture policy, unchanged full-chain flags and unchanged GPU-generation flags. Flag construction in this CPU test is headless; no GPU device/upload is exercised. Test log: `build_m3test/texture_upload_regression.log`.

Release output: `WoWClient/WowClient64_TextureUploadFix_test.exe`. The live in-game GPU verification at the reported location remains outstanding. Original assets and server data were not changed.
