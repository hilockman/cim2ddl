@echo off
rem execute multiple time to kill all ads-
taskkill /f /FI "WINDOWTITLE eq ads-*"
taskkill /f /FI "WINDOWTITLE eq ads-*"
taskkill /f /im GCStateEstimateServer.exe


