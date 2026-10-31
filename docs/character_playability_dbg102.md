# Character models: attachments, animations, key bones (dbg102)

Goal: WildStar character models (and humanoid NPCs) behave like stock WoW characters in the unmodified client logic. Checked on the 13 playable race models (`Art\Character\<Race>\<Race>_<M|F>.m3`) with `m3_to_m2_cli`.

## What the stock client needs (read from the decompiled client in `wowdecomp`)

* `CM2Model::HasBone(4)` / `HasBone(6)` (M2 header array "bone indices by id" = `m_boneIndicesById`) decide `Unit_C::m_animationState` bits 0x80 / 0x100 and the torso key bone (`Unit_C.cpp` ~1378). Key bone 4 (SpineLow) is the root of the upper body: attack / cast animations play on its subtree while the legs keep running; the turn-to-facing twist is `SetBoneProceduralTransform(4, rotation about Z)` up to 45 degrees, the rest on key bone 6 (head) (`Unit_C.cpp` ~1551-1620). Without the lookup table `HasBone` is false: no twist, no head turn, torso animations on the head only.
* The animation ids of `AnimationData.dbc` (3.3.5a) and its fallback chain (`M2Model.cpp` ~1116 / ~1282).
* Attachment ids: 0 shield, 1 hand R, 2 hand L, 5 / 6 shoulder R / L, 11 helm (20 second helm), 12 back, 30 back sheath.

## Problems found

1. The key bone lookup table was never written (only a head flag on the bone): no body rotation, torso key bone = -1.
2. Attachment records were read from the wrong field. The record is `{u16 slot, u16 bone, u16 ModelAttachment id, u16 index}`, the reader took the bone from the first field (0 or 1). Check: for HAND_LF / HAND_RT the parent of the bone in the SECOND field is BIND_Hand_Lf / BIND_Hand_Rt in 14 of 14 character and 124 of 124 creature records, the first field never. Every ModelAttachment based WoW attachment (left hand, helm, shield, ...) therefore sat on the root bone.
3. The helm: WildStar's HEAD attachment is a chest helper bone (z 1.39 on Human_F, head at 1.8), so equipment attachments now come from the real bones first.
4. Two ids of the animation table were wrong: Default_Ready -> 27 (Ready2H) instead of 25 (ReadyUnarmed), Default_Dodge -> 33 (SpellCastArea) instead of 30 (Dodge). Only 15 clips were mapped; a character has 591 clips and the sequence limit of 250 dropped clips by id order.

## Changes

* `M3ToM2.cpp`: `KeyBoneOf` (ModelBone id -> M2 key bone: Spine01 -> 4, Head -> 6, shoulders -> 2 / 3, finger bones -> 8..17) writes `bone.keyBoneId` and the lookup table (27 entries, header 0x34).
* `M3Reader.cpp`: attachment bone from the second field, id from the third.
* `M3ToM2.cpp` attachments: hands, shoulders and head from the named bones (ATT_HAND_LF / RT, shoulder bones, BIND_Head), shield on the left forearm (parent of BIND_Hand_Lf), back / back sheath from BACKPACK_RT or BACK, then the remaining ModelAttachments.
* `M3Anim.cpp`: `kAnimMap` with 44 WildStar -> WoW ids (Stand, Death, Dead, Walk, Run, Walkbackwards, ShuffleLeft / Right, wounds, Stun, HandsClosed, attacks 1H / 2H, Ready 25 / 27 / 28, Dodge, JumpStart / Jump / JumpEnd, SwimIdle / Swim / SwimBackwards, Loot, ReadySpellDirected, SpellCastDirected, ChannelCastDirected, BattleRoar, EmoteTalk, Sheath, Sleep chain, Kneel, UseStanding, Drown, Sprint, Birth); mapped clips are converted first so the 250 sequence limit only drops unmapped clips.
* `Cache.h`: `kCacheVersion` 18.

## Result on the 13 race models

Key bones 4 and 6 present in all 13; all 23 core ids (Stand, Death, Walk, Run, shuffle, strafe-less movement, jump chain, swim, loot, spell ready / cast / channel, talk, sleep, ...) present in all 13; attachments 1, 2, 5, 6, 11 and 0 present in all, back (12) in 12 of 13 (not Mordesh_F).

## Not done / open

* WoW ids a player uses that no WildStar clip supplies directly: StandWound (8), Fall (40), SwimLeft / Right (43 / 44), RunLeft / Right (92 / 93), SpellPrecast / SpellCast (31 / 32), Ready1H (26), Mount (91) and the sit chair set; the client falls back through the AnimationData chain. Making a clip answer several ids needs duplicated sequences.
* Weapon stance clips (`2H_*`, `Pistols_*`, `Claws_*`, `2HGun_*`) are not selectable: WoW has one Stand / Run per model, the unmapped ones stay as 1000 + ws id.
* Emotes: the WildStar Emote_* / Dance_* clips are not mapped to the WoW emote ids yet.
* Mount riding poses, the secondary track set of the bones (tracks 1, 3, 5, 7) and head / eye bones for facial animation.
* Not verified in the game window (attachment orientation of equipment, twist direction, animation blends).
