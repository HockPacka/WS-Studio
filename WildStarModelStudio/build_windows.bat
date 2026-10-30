@echo off
setlocal
cd /d "%~dp0"
where py >nul 2>&1 && (set "PY=py -3") || (set "PY=python")
%PY% -m pip install --upgrade pip
%PY% -m pip install -r requirements.txt "pyinstaller>=6.10,<7"
if errorlevel 1 goto :error
if not exist native\ws_m3_parser.dll (
  echo FEHLER: native\ws_m3_parser.dll fehlt.
  pause
  exit /b 1
)
%PY% diagnose_m3.py demo\Crystal.m3
if errorlevel 1 goto :error
%PY% -m PyInstaller --noconfirm --clean WildStarModelStudio.spec
if errorlevel 1 goto :error
echo.
echo FERTIG: dist\WildStarModelStudio\WildStarModelStudio.exe
echo Den gesamten Ordner dist\WildStarModelStudio verteilen.
pause
exit /b 0
:error
echo Build fehlgeschlagen. Siehe Fehlermeldung oben.
pause
exit /b 1
