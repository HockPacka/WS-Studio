# WildStar runtime debug menu (dbg86)

Client: `WoWClient/WowClient64_dbg86.exe`.
SHA256: `5bffb0a555922eee6f9b6651be4f51c4048cc24454af9835bfec030ee8218060`.

Open **WS Debug** at the top left, beside the existing model browser. In game,
`/wsdebug` and `/wsmaterials` open the same menu. The menu script loads after
the Glue and world UI parents exist. It uses stock button textures without
depending on FrameXML templates that may be unavailable in Glue.

| Setting | Effect |
|---|---|
| `materials` | Stops replacing the stock M2 pixel shader for marked M3 batches. Does not undo converted color atlases or restore the original four-layer WildStar material. |
| `normal` | Chooses the custom shader variant without normal-map sampling. |
| `gloss` | Sets the custom shader's gloss contribution to zero. |
| `glow` | Sets the custom shader's glow contribution to zero. |
| `files` | Rejects new native M3, TEX, AREA and I3 adapter loads, including generated textures, WMO caches, prefetched textures and ADT delivery. Stops scheduling new native model/texture/tile prefetches. |

The three shader features depend on `materials`. Shader changes apply on the
next render. File support does not evict existing models, textures or terrain;
work already running may complete. Existing resource handles can remain visible
and reusable. A full client restart is required for a completely fresh load.
These switches do not disable the already installed DBC/UI/SQL extensions, and
do not alter original assets or server data. Defaults are enabled, session only.
**Alles aktivieren** restores all five flags. Dye is not a separate runtime
toggle because the current character atlas is generated on the CPU.

Lua API (available in Glue and world):

```lua
WSGetDebugSetting("materials")
WSSetDebugSetting("materials", false)
WSSetDebugSetting("materials", true)
```

Accepted keys are exactly the five names above. Unknown names and non-boolean
setter arguments raise Lua errors. Shared flags are atomic for conversion workers.

Validation:

- Release `Wow` and `ws_debug_cli` builds passed.
- `ws_debug_cli tools/analysis/ws_debug_menu_check.lua` uses the client's own
  Lua 5.1 library with a standalone UI fixture. Both Glue and world callbacks,
  checkbox changes, reset, slash registration and strict API arguments passed.
- Generated texture read succeeds, fails with file support off, succeeds after
  re-enabling. This exercises the loader before its generated-texture fast path.
- `plugin_separation_check.py` passed: ten merge/unmerge tables, conflict checks,
  17 byte-identical original tables, direct-server output guards.
- Portable package includes both Lua debug scripts and the new native sources.
- Menu appearance and shader comparison have not yet been inspected in a live
  dbg86 game session; the Lua fixture checks behavior, not pixel layout.
