echo %ZND_HOME%
xcopy /Y %ZND_HOME%\bin_x64 .\bin_x64
del .\bin_x64\*.pdb /f /q
del .\bin_x64\*.lib /f /q
del .\bin_x64\*.suo /f /q
del .\bin_x64\*.exp /f /q
pause