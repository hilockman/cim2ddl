@echo off
set  profile=%1
echo profile is %profile%

set srcfile=.\JavaWorkspace\ClusterServersConfig_%profile%.cfg
set targetfile=ClusterServersConfig.cfg

echo on
copy /Y %srcfile%  %targetfile%
xcopy /Y .\JavaWorkspace  .\src\ei-ads-web\JavaWorkspace
xcopy /Y .\JavaWorkspace  .\src\ei-ads-console\JavaWorkspace

@echo off

set srcfile=.\src\ei-ads-web\src\main\resources\redissonnode_%profile%.yaml
set targetfile=.\src\ei-ads-web\src\main\resources\redissonnode.yaml

echo on
copy /Y %srcfile%  %targetfile%

@echo off
set srcfile=.\src\ei-ads-console\src\main\resources\redissonnode_%profile%.yaml
set targetfile=.\src\ei-ads-console\src\main\resources\redissonnode.yaml

echo on
copy /Y %srcfile%  %targetfile%
 
pause
