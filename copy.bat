@echo off

xcopy /E /S /I %~dp0\.vscode           %1\.vscode
xcopy /E /S /I %~dp0\test              %1\test
copy           %~dp0\main.cpp          %1
copy           %~dp0\.clang-format     %1
copy           %~dp0\.editorconfig     %1
copy           %~dp0\.gitignore        %1
copy           %~dp0\CMakeLists.txt    %1