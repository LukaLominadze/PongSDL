vendor\bin\premake\premake5 --help
@echo off
@echo \
@echo \
@echo \
@echo \
@echo \
@echo ---------------------------------------------------
@echo Enter the build option from the ACTIONS list above:
@echo ---------------------------------------------------
set /p build_option=

rem Run Premake with the entered build option
vendor\bin\premake\premake5 %build_option%

pause