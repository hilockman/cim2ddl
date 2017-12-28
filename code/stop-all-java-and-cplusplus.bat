@echo off
rem execute multiple time to kill all ads-
taskkill /f /FI "WINDOWTITLE eq ads-*"
taskkill /f /FI "WINDOWTITLE eq ads-*"
taskkill /f /im GCStateEstimateServer.exe
taskkill /f /im GCStateSample.exe
taskkill /f /im GCModuleTest.exe
taskkill /f /im BpaSysRAdequacyUI.exe 
taskkill /f /im MemDBViewer.exe
taskkill /f /im MemStarter.exe


