# i3 portal visibility investigation (2026-10-25)

## Implemented and checked (2026-10-26)

The adapter now writes MOHD flag 0x2 (UnifiedRender), retains the original native
portal vertices/indices and merges adjacent triangles only when their union is
convex. Concave openings and holes remain multiple pieces. Pieces have at most
10 corners: the client truncates inputs above 12 and clips through five planes
using 16-vertex scratch buffers. The WMO fallback also respects the fixed
2048-entry client portal-extension array and 16-bit portal vertex offsets.
Reverse records are deduplicated by transformed geometry, not origin alone.
Normal transformation includes inverse scale and preserves the native plane D.

The Pell M3 single-layer fallback now selects the first present color/normal
pair when compatibility layer zero is empty. The combined material/portal client
currently uses cache version 16.

`python tools/analysis/i3_portal_fix_check.py` passes: all 211 models with raw
portals produce 1095 retained openings / 1580 convex pieces with preserved area;
synthetic convex, concave and hole cases pass. The Pell and church WMO fixtures
retain indoor groups and nonempty batch draw loops. The actual Pell M3 output
uses color texture 4 / normal texture 5 for its sparse material, with a nonempty
texture filename. Full isolated Release client build passes.

Client: `WoWClient/WowClient64_MaterialsPortals_test.exe`. Visual verification in a
live world is still outstanding, including the black roof in the screenshot.
The original investigation below describes the pre-fix behavior.

## Confirmed conversion defects

### Interior geometry is dispatched to an empty exterior draw loop

`wowdecomp/WoW/Source/WorldClient/MapObj.cpp:1146` selects the interior renderer
when `m_colorVertexList` exists, rather than selecting it from the indoor group
flag. Otherwise it selects `ExteriorRender`. Without root MOHD flag 0x2,
`ExteriorRender` draws only `m_extBatchCount` batches (line 1363).

The native i3 adapter writes indoor groups with flag 0x2000 and interior batches,
but no MOCV vertex colors. Its root MOHD flags are zero. Consequently an indoor
group with four interior batches and zero exterior batches draws zero batches,
even if portal traversal correctly reaches that group.

Reproduced through the actual `i3_wmo_cli` converter on:

* `Art/Structure/Model/Building_Kits/Pell/Pell_SmallHouse_001/STR_Building_SmPellHouse_000.i3`
* Generated `pell_small_001.wmo`: flags 0x2001, 4 batches, interior count 4,
  exterior count 0, no MOCV; selected exterior draw-loop count is 0.
* The exterior group draws its 9 batches correctly. Three unique real portals
  are retained, so absence of portals is not the cause in this fixture.

A correction must align generated lighting/render data with the selected client
path. Root flag 0x2 enables UnifiedRender, which draws all batches; exporting
proper indoor vertex colors is another route. These are candidate changes,
not fixes applied by this investigation. Marking every room exterior would
discard the intended indoor/outdoor visibility distinction.

### Non-quad native portal meshes are discarded

`Struct3/I3Reader.cpp:263` accepts exactly 4 vertices and 6 indices. Native portals
also contain other triangulated polygon shapes. The inventory covers 413 FEDI
models, including 211 with raw portals; 82 contain portal shapes rejected by
this condition.

Example: `STR_Imperium_SmallChurch.i3` has two directed records for one real
connection, each with 12 vertices and 30 indices. Both are discarded. The
builder's no-real-portal fallback then marks every group exterior. The resulting
church WMO retains synthetic connections between split groups, but loses the
native indoor/outdoor connection and classification.

The current quad reader also hardcodes corner order 0,1,3,2 instead of deriving
the boundary from native triangle indices. This is a further assumption to
validate, not a demonstrated cause in the two fixtures. A general reader should
retain raw vertices/indices, recover polygon boundaries, and handle concave or
multi-boundary meshes explicitly. Taking an unconditional convex hull would
change the original visibility opening.

## Screenshot location is a separate M3 case

Map 5000, X=13660.28, Y=13460.456, Z=796.74854 maps to
`Map/Western/Western.3939.area`. The nearby Pell houses are
`Art/Prop/Constructed/House/Pell/Large/PRP_PellHouse_Large_000.m3`, around
35 units away. The tile's Exolab dungeon placement is about 430 units away.
Thus the pictured round Pell house does not exercise the i3 portal adapter.

The M3 contains a sparse material whose only color/normal pair is in native
layer index 2 (third layer). `M3ToM2.cpp` collects present layers but enables the
layered path only for two or more layers. Its single-texture fallback still
reads the empty compatibility first layer and selects a white fallback.
This explains a missing material and is consistent with the white wall band;
the exact visible submesh and the black roof still require runtime confirmation.

The screenshot's missing VMAP message is a server area/collision query. It does
not explain the client-side zero-batch rendering defect identified above.

## Reproduction and limits

Generated fixtures and JSON results are under
`build_m3test/i3_portal_probe/`. `tools/analysis/i3_portal_visibility_probe.py`
audits native shape counts and replays the client's batch-dispatch conditions
against actual generated WMO chunks. Both fixtures pass `tools/wmo_check.py`:
structural validity alone does not detect these semantic failures.

The initial analysis did not install a functional fix. The subsequent changes
and checks are recorded above. The standalone Struct3 target also links its
existing Model3 debug-options dependency so the diagnostic CLI can build.

## Fixes applied (2026-10-26, dbg93)

* Interior groups drawn through an empty loop: root MOHD flag 0x2 (UnifiedRender) is written by `Struct3/WmoBuilder.cpp`; `ExteriorRender` and `InteriorRender` both delegate to `UnifiedRender` then, so every populated group draws all of its batches. `tools/analysis/i3_portal_visibility_probe.py --fixed` passes (0 invisible groups, indoor flag 0x2000 kept).
* Portals that are not quads: `Struct3/I3Reader.cpp` `PortalPolygons()` rebuilds the polygons from the native triangle indices (shared indexed edges, merging only pieces whose union stays convex, at most `kMaxPortalPolygonVertices` = 10) instead of accepting exactly 4 vertices / 6 indices. The probe lists 82 models whose portals the old reader discarded.
* Sparse M3 materials (only texture in layer slot 1..3): `Model3/M3ToM2.cpp` takes the first present layer as colour / normal of the single texture path (white fallback before). Cache version 11.
* Verified offline with generated fixtures (`pell_small_fixed`, `church_fixed`) and `tools/wmo_check.py`; not yet looked at in game (client `WowClient64_dbg93.exe`).
