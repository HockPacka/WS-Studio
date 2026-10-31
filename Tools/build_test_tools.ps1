# Builds the standalone test executables (m3_to_m2_cli, tex_to_blp_cli, area_dump_cli, adt_build_cli, m3_dump_metadata_cli, i3_wmo_cli) with MSVC into build_m3test\
$vs = 'C:\Program Files\Microsoft Visual Studio\2022\Community'
$root = Split-Path -Parent $PSScriptRoot
$m3 = Join-Path $root 'wowdecomp\Engine\Source\Model3'
$area = Join-Path $root 'wowdecomp\Engine\Source\Area3'
$struct = Join-Path $root 'wowdecomp\Engine\Source\Struct3'
$out = Join-Path $root 'build_m3test'
New-Item -ItemType Directory -Force $out | Out-Null
$cmd = "`"$vs\VC\Auxiliary\Build\vcvars64.bat`" >nul 2>&1 && cd /d `"$root\wowdecomp`" && " +
    "cl /nologo /std:c++17 /EHsc /O2 /I. `"$m3\M3Reader.cpp`" `"$m3\M3ToM2.cpp`" `"$m3\M3Anim.cpp`" `"$m3\Tests\m3_to_m2_cli.cpp`" /Fe:`"$out\m3_to_m2_cli.exe`" /Fo:`"$out\\`" && " +
    "cl /nologo /std:c++17 /EHsc /O2 /I. `"$m3\M3Reader.cpp`" `"$m3\Tests\m3_dump_metadata_cli.cpp`" /Fe:`"$out\m3_dump_metadata_cli.exe`" /Fo:`"$out\\`" && " +
    "cl /nologo /std:c++17 /EHsc /O2 /I. `"$m3\TexToBlp.cpp`" `"$m3\TexJpg.cpp`" `"$m3\Cache.cpp`" `"$m3\DebugOptions.cpp`" `"$m3\Tests\tex_to_blp_cli.cpp`" /Fe:`"$out\tex_to_blp_cli.exe`" /Fo:`"$out\\`" && " +
    "cl /nologo /std:c++17 /EHsc /O2 /I. `"$area\AreaReader.cpp`" `"$area\Tests\area_dump_cli.cpp`" /Fe:`"$out\area_dump_cli.exe`" /Fo:`"$out\\`" && " +
    "cl /nologo /std:c++17 /EHsc /O2 /I. `"$area\AreaReader.cpp`" `"$area\AdtBuilder.cpp`" `"$area\WaterBuilder.cpp`" `"$area\TerrainBlend.cpp`" `"$area\Clutter.cpp`" `"$area\Tbl.cpp`" `"$struct\I3Reader.cpp`" `"$struct\WmoBuilder.cpp`" `"$struct\WmoCache.cpp`" `"$m3\Cache.cpp`" `"$m3\DebugOptions.cpp`" `"$area\Tests\adt_build_cli.cpp`" /Fe:`"$out\adt_build_cli.exe`" /Fo:`"$out\\`" && " +
    "cl /nologo /std:c++17 /EHsc /O2 /I. `"$struct\I3Reader.cpp`" `"$struct\WmoBuilder.cpp`" `"$struct\WmoCache.cpp`" `"$m3\Cache.cpp`" `"$m3\DebugOptions.cpp`" `"$struct\Tests\i3_wmo_cli.cpp`" /Fe:`"$out\i3_wmo_cli.exe`" /Fo:`"$out\\`""
cmd /c $cmd 2>&1 | Select-String 'error|warning C4996' | Select-Object -First 10
Get-ChildItem $out -Filter *.exe | Select-Object Name, LastWriteTime
