@echo off
setlocal
cd /d "%~dp0"
where py >nul 2>&1 && (set "PY=py -3") || (set "PY=python")
%PY% -c "import webview" >nul 2>&1
if errorlevel 1 (
    echo Einmalige Installation des Desktop-Fensters...
    %PY% -m pip install -r requirements.txt
    if errorlevel 1 (
        echo Fehler bei der Installation. Python 3.10+ erforderlich.
        pause
        exit /b 1
    )
)
%PY% desktop.py %*
if errorlevel 1 pause
