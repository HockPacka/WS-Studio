@echo off
setlocal
cd /d "%~dp0"
where cl >nul 2>&1 || (
  echo Benutze eine Visual Studio Developer Command Prompt mit MSVC C11.
  exit /b 1
)
cl /nologo /LD /O2 /W4 /std:c11 /TC ws_m3_parser.c /link /OUT:ws_m3_parser.dll kernel32.lib
if errorlevel 1 exit /b 1
echo DLL erfolgreich gebaut: %cd%\ws_m3_parser.dll
