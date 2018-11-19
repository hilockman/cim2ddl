@echo off
SetLocal EnableDelayedExpansion
(set PATH=D:\GitHub\cim2ddl\znd\dev\src\gui\3rdparty\Charts\2.0\Src\bin;E:\Qt\5.11.0\msvc2017_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=E:\Qt\5.11.0\msvc2017_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=E:\Qt\5.11.0\msvc2017_64\plugins
)
%*
EndLocal
