@echo off
set JAVA_HOME=.\java
PATH=%JAVA_HOME%\bin;.\bin_x64;%PATH%
set CLASSPATH=.;%JAVA_HOME%\lib\dt.jar;%JAVA_HOME%\lib\tools.jar
echo %PATH%
java -version

start .\bin_x64\GCStateEstimateServer.exe
start "ads-console"  call ads-console.bat


