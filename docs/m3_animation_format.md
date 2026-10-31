# WildStar .m3 – bone animation tracks (build 16042)

Status: track layout **verified on all 34,733 models** (`tools/validate_m3_tracks.py`, `docs/m3_track_validation.json`).
Clip table (which time range is which animation) still open, see bottom.

## Pointers
`DPointer = { u64 count; u64 keyOffset; u64 valueOffset }`.
Bone-level DPointers are relative to `align16(boneArray.address + boneCount * 0x160)` (not to the header end).
Header-level arrays/DPointers stay relative to `0x630`.

## Bone (0x160 bytes)
| Off | Type | Meaning |
|---|---|---|
| 0x04 | i16 | parent bone, -1 = root |
| 0x10 | DPointer[4] | tracks 0-3: key u32 ms, value 3 x half (6 B) – semantics open (looks like scale-like, values near 1.0; track 0/2 count mirrors the parent's) |
| 0x70 | DPointer[2] | tracks 4-5: key u32 ms, value 4 x i16 = quaternion xyzw, **16384 = 1.0** (all 114,099 sampled are unit length) |
| 0xA0 | DPointer[2] | tracks 6-7: key u32 ms, value 3 x f32 (12 B), translation-like |
| 0xD0, 0x110 | f32[16] x2 | matrices (bind/inverse bind – to confirm) |
| 0x150 | f32[3] | pivot xyz |

Per track the value array directly follows the key array (16-byte aligned). Keys are milliseconds on a single
shared timeline; tracks 5/7 (and 1/3) typically only start at 176,667 ms, tracks 4/6/0/2 at 33 ms – i.e. the timeline is
split into two groups of clips. One timeline holds many clips back to back (e.g. Grund: segments 0-23,367, 26,667-53,400 ...).

## Track semantics (verified by data, not by client code)
| Track | Meaning | Evidence |
|---|---|---|
| 0 | **scale** xyz (half3) | values 1.0 (0x3C00); non-uniform in 65 % of 6,850 sampled tracks |
| 2 | **parent scale** copy | identical keys+values to the parent's track 0 in **4,060 / 4,060** cases |
| 4 | **rotation** quaternion xyzw (i16 / 16384) | unit length 100 %; equals the bind-matrix rotation at rest |
| 6 | **translation**, *local to the parent frame* | bone 4 of Grund: world delta (0.346,-0.288,-0.073) projected on the parent's bind axes = (0.288,0.072,0.346) = track 6 value |
| 1, 3, 5, 7 | secondary set: scale / parent scale / rotation / translation | key arrays disjoint from the primary track in 96 % (5,657 / 5,900 for 5 vs 4); only ~2 % of clips contain keys from this set; role in playback still a hypothesis (additive/pose layer) |

Matrices at bone +0xD0 / +0x110: **B is the exact inverse of A** in 43,717 / 43,717 sampled bones. A = world bind matrix
(row-vector convention, translation in the 4th row), B = inverse bind matrix (needed for skinning / M2 `bone pivot`).
The float3 at +0x150 is the bone pivot; it equals A's translation for ~49 % of bones (the rest are 0), so use A for the pivot.

For a WoW M2 export: track 4 -> rotation, track 6 -> translation. Track 2 must be sampled as well as track 0:
the effective inherited scale is `abs(track0 / track2)` (missing track defaults to one; near-zero divisors are guarded).
The native evaluator `FUN_140300fd0` samples the half3 at bone+0x40 and divides the inherited scale by its components
(`docs/ghidra_anim.c`, around lines 1093-1130). Dropping this compensation made Granok's 0.825 scale compound through
the hierarchy: the exported Stand head shrank to 0.477-0.495 before this correction. See
`docs/granok_scale_attachments.md` for the regression measurements and current export limitations.
The secondary set is ignored until its role is proven.

## Verification (all 34,733 models)
- 7,947 models animated, 26,786 static
- 349,222 tracks: 0 out of bounds, all key arrays sorted, value array starts at align16(keys end) for 100 %
- per track counts: t0 35,668 / t1 3,141 / t2 25,036 / t3 2,087 / t4 101,596 / t5 12,503 / t6 163,586 / t7 5,605

## Event track (from Ghidra, FUN_140300fd0 in WildStar64.exe)
Header DPointer @0x290 (keys = ms, values = u16 index) + array @0x280 (8 B: u16 type, u16 bone, u32 param) trigger
effects/attachments at a time. Not animation clips.

## Clip table (header array @0x010) – verified
`ArrayPointer { count, offset }` at header 0x010, **count x 0x70-byte records**, address = offset + 0x630.

| Off | Type | Meaning |
|---|---|---|
| 0x00 | u16 | animation id (sorted ascending in all 34,733 models) – game-side animation/sequence id (e.g. 86, 94, 150-164 ...) |
| 0x02 | u16 | variant / subtype bit mask (0, 1, 2, 3, 14, 15, 31 ...) |
| 0x04 | u16 | usually 1 |
| 0x06 | u16 | 0/1 flag |
| 0x08 | u16 | blend-in in ms (100 typical) – assumption |
| 0x0A | u16 | blend-out in ms (150 / 0 / 500 ...) – assumption |
| 0x0C | u32 | start time ms on the shared timeline |
| 0x10 | u32 | end time ms (start == end = single pose) |
| 0x14 | f32 | seen 8.0 / 3.0 / negative values -> speed-like, only for some clips |
| 0x20, 0x40 | vec4 x2 | bounds min/max (stored twice) |

Verification (`tools/validate_m3_clips.py`, `docs/m3_clip_validation.json`): 75,741 clips in 34,733 models;
ids sorted in 100 % of models; start < end for 99.0 %; in the 45,856 clips of animated models 96.8 % end inside the keyframe
timeline and 91.7 % start exactly on a keyframe. Static models (no bone tracks) also carry a clip table (29,885 clips).

## Animation id -> name (solved)
`DB/ModelSequence.tbl` (columns `ID, description, FallBackID, flag`, 7,287 rows) names the id. Dumped by `tools/tbl_dump.py`
(`extracted/tables_csv/`), joined by `tools/clip_names.py` into `docs/animation_ids.csv`:
1,338 distinct ids in the models, 1,328 named, **99.92 % of all 75,741 clips named**. Unnamed: 158, 265, 499, 509, 597, 672, 673, 7877-7879.
`FallBackID` gives the substitute when a model lacks a clip (e.g. Default_Walk -> Default_Run). Other related tables:
`ModelSequenceByMode/ByWeapon/BySeatPosture/Transition`, `ModelEvent`, `ModelPose`, `Emotes`.
Draft WoW mapping for the core clips: `docs/wow_animation_map_proposal.csv` (unverified against AnimationData.dbc).

## Still open
- Meaning of u16 @0x02/0x04/0x06 and the float @0x14.
- Role of the secondary track set (1, 3, 5, 7) during playback.
- 0x1E0 (0x98 per entry, same track types, non-bone nodes).
