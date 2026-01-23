@echo off
setlocal

REM Compile (MSVC cl.exe). Run from Developer Command Prompt for VS.
REM Adjust file names if yours differ.

cl /nologo /W4 /Iinclude src\*.c /Fe:bracket_demo.exe
if errorlevel 1 exit /b 1

echo.
echo Running demo:
bracket_demo.exe %*
