@echo off
setlocal
cd /d "%~dp0"
if "%~1"=="" (
  echo Ziehe eine .m3-Datei auf diese Batch-Datei oder nutze:
  echo diagnose_m3_windows.bat "C:\Pfad\zu\Modell.m3"
  pause
  exit /b 1
)
where py >nul 2>&1 && (set "PY=py -3") || (set "PY=python")
%PY% diagnose_m3.py "%~1"
pause
