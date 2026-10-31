# Granok head size and attachment anchors

2026-10-26. Fix in `Model3/M3Reader`, `M3Anim`; model cache version 20.

## Findings

The raw Granok male face is 0.420 m high and already positioned at the neck.
Its geometry is not a miniature head. The animation converter dropped bone
track 2 (half3 at +0x40), the parent-scale compensation. In the original
evaluator `FUN_140300fd0`, the sampled inherited scale is divided by this
track (saved decompilation `docs/ghidra_anim.c`, lines 1093-1130).
Granok commonly has 0.825195 in both scale and parent-scale. Applying only
scale compounded it through successive joints.

The sign solver also omitted scale when matching the bind pose, but applied
it during export. It now uses the same compensated scale as key generation.
Compensation-only key times are included, including keys inside a clip that
do not coincide with any translation, rotation or own-scale key.

The hand helpers, ModelBone 58/59, have a scaled identity bind matrix
(1.211834 on Granok) with zero translation. The old non-identity test treated
this as a genuine anchor at the origin. For unweighted attachment helpers
whose stored translation is zero, the bind frame now comes from the parent
bind frame and the local tracks. The serialized M2 attachment and animated
bone pivot use this same recovered frame. No hand offsets are hard-coded.
The named-head and shoulder mapping from dbg102 is preserved.

## Measurements on actual serialized M2 keys

Granok male, default customization, Stand first frame, full composed model:

| Measurement | Before | After |
|---|---|---|
| Head skin-matrix axis lengths | 0.495 / 0.477 / 0.480 | 0.998 / 0.999 / 1.002 |
| Left hand bind anchor, WoW xyz | 0 / 0 / 0 | -0.032 / 1.759 / 1.699 |
| Right hand bind anchor, WoW xyz | 0 / 0 / 0 | -0.032 / -1.759 / 1.699 |

After correction, first-frame animated anchors are approximately
`(0.117, 0.953, 1.295)` and `(0.028, -0.970, 1.271)` in Stand.
Positions include the existing character ground-lift correction.

Validation:

- `bone_animation_cli`: inherited scale cancellation, a compensation-only
  intermediate key, zero-divisor guard, scaled identity attachment helper.
- `python tools/analysis/character_attachment_check.py`: 15 available race/sex
  combinations, 135 serialized Stand/Walk/Run samples, 30 hand anchors,
  105 customization-option cycles. All pass. Reconstructs CPU matrices from
  quantized M2 keys and verifies hand helpers remain near their parent hands.
- Results: `build_m3test/character_attachment_check/report.json`.

This verifies model transforms and attachment positions outside the game.
The equipped WoW item orientations, item-specific offsets and transitions
between animations still require an in-game visual check. The general
converter still uses its existing bind-frame/sign approximation; this change
does not claim to reproduce every native nonuniform-scale or secondary-pose
case. Original M3 files and server data are unchanged.
