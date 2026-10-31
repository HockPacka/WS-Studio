# Sky fog distances (dbg99)

First use of the decoded fields from [sky_field_semantics.md](sky_field_semantics.md): the `FogDistance` track (0x2D0) now drives the WoW fog while the native WildStar sky is active.

* `Area3/Sky`: `SkyFile::fogDistance` reads 0x2D0 (six floats); `SkyState::fog[6]` = FogStart, FogEnd, SkyStart, SkyEnd, CloudFog, SkyFog in WildStar metres. A sky without that track (1160 of 1288 files) gets the original defaults of an empty track: FogStart 50, FogEnd 700, CloudFog 0.5, SkyFog 0 (quality tables at 0x140c55f80 / 0x140c55fe0 / 0x140c56040 / 0x140c560a0, identical for both quality levels). The values are blended with the same normalised sky weights as the lighting.
* `WildStarSky::Fog()` converts metres to WoW yards with the terrain scale 33.333 / 32; `DayNight` applies it after `WildStarSky::Update()`: `m_fogEnd`, `m_fogStartMul = start / end`, and in the exponential fog mode the same `CalcFogRate` conversion as `CalcColors`. The fog colour was already taken from the sky (fog SH group, horizon band).
* Not applied yet: SkyStart / SkyEnd (fog on the sky dome), CloudFog, SkyFog (fog amount on clouds and sky).
* Switch: bit 3 (value 8) of `WoWOverride\sky_debug.txt` keeps the WoW fog distances (A/B comparison). Other bits as before: 1 no dome, 2 no sky models, 4 no cloud field.

Checks: `sky_cli` prints the blended `fog` array; 100 samples on 25 files with a FogDistance track equal the Python sampler (`tools/sky_reader.py`) within 1e-3; the 1290-file native check still passes. Not verified in the game window: how the new fog distances look next to the terrain draw distance.
Executable: `WoWClient/WowClient64_dbg99.exe`.
