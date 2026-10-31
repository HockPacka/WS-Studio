# dbg109 startup hang and world-only debug menus

2026-10-28. Reproduced before the login screen. Two live debugger stack samples
show the main thread waiting in D3D9 Present -> dwmapi shared-surface synchronization.
The earlier GranokAttachments test build also failed to reach login with the same
configuration. Setting gxVSync to 0 made the unchanged dbg109 reach login and the
user subsequently entered the world. No renderer, sky or armor code was disabled.

Config backup: build_m3test/startup_config_original_20261028.wtf.
Live config: WoWClient/WTF/Config.wtf, gxVSync=0.
Debugger evidence: build_m3test/startup_dbg109_stacks_v2.txt and startup_dbg109_live.txt.
This is a local workaround for the observed windowed D3D9/DWM synchronization stall,
not a general conclusion about all graphics drivers.

The WS browser and WS Debug menu now return immediately in Glue. In the world UI
they create only an event listener, and defer actual frames until PLAYER_ENTERING_WORLD.
PLAYER_LEAVING_WORLD hides launchers and panels; re-entry reuses them.
The old automatic preview setting was preserved as
Interface/WildStarDebug/startup.txt.disabled_manual_menu; menus open manually.
No new executable is required: dbg109 reads the modified Lua files from disk.

Validation: tools/analysis/ws_debug_menu_check.lua in the client Lua 5.1 host checks
no widgets in Glue, no menu frames before world entry, all five material toggles,
slash commands, leaving-world hiding and idempotent re-entry for both menus.
