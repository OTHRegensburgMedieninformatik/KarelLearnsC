@echo off 
title Build StarteProject
echo This is the first build up script for a Clion StarterProject 
echo Search Cmake ...
SET CURRENT_PATH=%cd%
if exist "%CURRENT_PATH%\cmake_path.txt" (
set /p CMAKE=<"%CURRENT_PATH%\cmake_path.txt"
) else (   
where /R c:\ cmake.exe > cmake_path.txt
set /p CMAKE=<cmake_path.txt
)>NUL
echo Cmake was found
rem echo %CURRENT_PATH%
rem echo %CMAKE%

if exist "%CURRENT_PATH%\cmake-build-debug" del /Q /S "%CURRENT_PATH%\cmake-build-debug">NUL
if not exist "%CURRENT_PATH%\cmake-build-debug" md "%CURRENT_PATH%\cmake-build-debug" > NUL

cd "%CURRENT_PATH%\cmake-build-debug" > NUL
"%CMAKE%" -DCMAKE_BUILD_TYPE=Debug -G "MSYS Makefiles" %CURRENT_PATH%
pause
