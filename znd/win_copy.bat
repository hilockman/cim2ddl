rem copy release from release folder to root bin folder
if exist binary\win64\release\bin\*.dll copy /y binary\win64\release\bin\*.dll bin
if exist binary\win64\release\bin\*.exe copy /y binary\win64\release\bin\*.exe bin
pause