# AREA Bits 19/20 – Read-only Validation Research

## What the sources prove (and what they don't)

The original WildStar64.exe AREA cell descriptor (documented in
`WS-Tools/docs/area_format.md`) links the uncompressed bit 29 65×65 four-nibble
weight map to compressed blocks **19 and 20**. Both compressed blocks occupy
17×17 BC1 blocks (2312 bytes) covering 65×65 logical samples.

The confirmed parallel pair is **bit 17 base RGB weights / bit 18 signed RGB
correction**, linked to uncompressed bit 2. The original LandPS shader reads
the base weights and adds a signed correction texture, with four terrain
WorldLayer weights derived from RGB and an implicit fourth contribution.

**Not proved:** whether bit 19 uses precisely the same shader permutation,
correction scale, transparency/alpha coverage, priority, or conditions as the
17/18 pair. A numerical agreement with bit 29 is evidence for a hypothesis,
not proof that a native 19/20 encoder is ready.

## New read-only research

Open a native standalone `.area` and use:

**Render → Bit 19/20 Weight Research → Analyze full AREA (read-only)**

- Enumerate cells with a complete pair 19/20 and separate bit 29.
- Decode all **65×65** logical samples, not a sparse 4-pixel grid.
- Honor both BC1 endpoint-order modes: `endpoint0 > endpoint1` 4-color,
  `endpoint0 <= endpoint1` 3-color mode, including transparent selector 3.
- Count source base/correction 3-color blocks and transparent base samples.
- Compare the normalized raw bit 29 RGBA nibble weights to four explicit
  **hypotheses**, all read-only:
  1. **direct**: base + full signed correction (consistent with known 17/18 notes)
  2. **half**: base + half correction (the earlier Genesis diagnostic assumption)
  3. **direct_coverage**: direct with decoded base BC1 coverage
  4. **half_coverage**: half with decoded base BC1 coverage
- Produce mean absolute error (MAE), maximum absolute channel error, and the
  percentage of texels whose largest channel error is at most 2/255 and 10/255.
- Report both full-AREA aggregates and the currently selected cell's details.
- Export `Genesis_Bit19_20_Research.csv` with **one row per loaded AREA cell**,
  including availability, sample coverage, BC1 statistics and all four
  hypotheses. CSV is Save As / `create_new` and does not overwrite files.

Cells lacking either compressed block cannot be evaluated, and raw-29 samples
whose four nibbles sum to zero are **excluded** from error comparisons. These
cases are explicitly counted and are never treated as matching data. Each
raw29 sample is divided by its original total to yield 0..1 contributions.

## Implementation

- `crates/wildstar_formats/src/area/weight_research.rs`: independent
  decoder / statistical comparison, independent from the production shader
  and serializing writers. Includes synthetic regressions for BC1 transparent
  and four-color modes, 4225-sample counts, zero-data cases and CSV structure.
- `src/main.rs`: cached on-demand research UI (recomputed only when requested),
  per-cell/aggregate results and safe CSV Save As.
- Existing `area/metadata.rs::candidate_weights_19_20` is intentionally **not
  changed**, so results from the old fixed-four-color/half-correction model
  remain available for historical comparison.

## Next evidence required

1. Run reports on several **original** `WildStar` maps that contain both
   bit29 and bit19+20, recording which cells match and where they diverge.
2. Inspect client disassembly for the precise bit19/20 branch and LandPS
   texture selection and alpha semantics.
3. Inspect whether 17/18 and 19/20 alternate by terrain flags, LOD, revision
   or another resource. Do not infer this from file presence alone.
4. Validate the winning interpretation against original GPU output.
5. Only after native shader and decode behavior are verified, implement and
   roundtrip-test a bit19/20 encoder. **Writer remains blocked** until then.

No original ClientData files are modified by this research.
