@echo off
REM Compile the entire telecom-forfaits project using MinGW g++
g++ -std=c++17 -I GestionForfait/include main.cpp GestionForfait/src/client.cpp GestionForfait/src/forfait.cpp GestionForfait/src/forfaitillimite.cpp GestionForfait/src/operateur.cpp GestionForfait/src/prepayee.cpp -o main.exe
if %ERRORLEVEL% neq 0 (
    echo Compilation failed.
    exit /b %ERRORLEVEL%
)
echo Compilation succeeded: main.exe