# Cutout coverage rule (dbg101): why parts of creatures were not drawn

Case: Bleakwing Knifetalon (Creature2 61568, `Art\Creature\Raptaruk\Raptaruk.m3`, display 21559, ModelMesh 74 = group 1). The converted bind pose geometry is complete (checked by rasterising the converted M2 / skin), but in game large parts of the body were missing.

## Cause

`M3ToM2` marked a layer as "the colour alpha is coverage" when the layer word at +0x08 (`modes[1]`) was not 0. The batch of Raptaruk got shader id 0x8AC0 = layered | normal map | **coverage bit of layer 1**. The layered pixel shader then used `alpha = lerp(1, t1.a, 1) * w1 + ...` in the regions weighted to layer 1, and the colour alpha of `Raptaruk_Color.tex` is only a mask: 99.6 % of its alpha is below 128, so the alpha test cut the body away.

## Measurement

`scratchpad/cover*.py` decoded the colour texture of every layer of every cutout / blended material (header[5] = 1 or 2) and compared its alpha statistics with the layer words (`words[i]` of the reader = `modes[i]` of the converter, at +0x04 + 4 i):

| layer words | meaning supported by the data |
|---|---|
| `modes[2] == 5` | alpha is the cutout shape: bimodal, 71 % opaque on average (170 layers) |
| `modes[1] == 1` | foliage cutout, alpha bimodal, about half transparent (205 layers) |
| `modes[2] == 1` | alpha is a tint / dye mask, 92 % of it below 128 (1326 layers); the shape (if any) is in the normal map, whose R and B channels are bimodal |
| `modes[1] in (3, 5, 6)` with `modes[2] == 1` | same, mask only |

Rule used now: coverage = `modes[1] == 1 || modes[2] == 5 || (modes[1] == 0 && modes[2] == 0)`.

| group | layers with coverage, alpha mostly transparent (old rule -> new rule) | real cutouts lost (old -> new) |
|---|---|---|
| Creature (683 layers) | 246 -> 29 | 20 -> 2 |
| Prop / Natural (374) | 83 -> 21 | 5 -> 0 |
| Prop / Constructed (225) | 68 -> 20 | 9 -> 0 |

Raptaruk now converts to shader id 0x88C0 (no coverage bit): opaque body, no alpha test cut.

## Not solved

* The words 3 and 4, and the exact meaning of `modes[2] == 1` (cutout shape in the normal map: `coverage = dot(cb1[4+k], (colour.a, normal.b, normal.r, 1))` in the original) are still not implemented: layers whose shape lives only in the normal map are drawn as full surfaces.
* The remaining "alpha mostly transparent" layers (29 creature layers) are probably legitimate blended / additive effects; not checked one by one.
* Not verified in the game window. `kCacheVersion` is 17, textures keep their cache (`kTexCacheVersion` 16).
