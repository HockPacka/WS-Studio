@echo off
setlocal
cd /d "%~dp0"
if "%~1"=="" (
  echo Ziehe den Avatus-Ordner ODER eine einzelne .m3-Datei auf diese BAT.
  echo Beispiel: check_avatus_windows.bat "D:\WS-Tools\Avatus\Avatus.m3"
  pause
  exit /b 2
)
where py >nul 2>&1
if not errorlevel 1 (
  py -3 "%~dp0check_avatus.py" "%~1" --json "%~dp0avatus_report.json"
) else (
  python "%~dp0check_avatus.py" "%~1" --json "%~dp0avatus_report.json"
)
set "code=%ERRORLEVEL%"
echo.
if exist "%~dp0avatus_report.json" echo Bericht: "%~dp0avatus_report.json"
if not "%code%"=="0" echo Ein Fehler wurde erkannt. Bitte die Konsolenausgabe und den Bericht pruefen.
pause
exit /b %code%
