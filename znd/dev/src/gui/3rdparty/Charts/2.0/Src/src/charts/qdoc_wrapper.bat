@echo off
SetLocal EnableDelayedExpansion
(set QT_VERSION=2.0.0)
(set QT_VER=2.0)
(set QT_VERSION_TAG=200)
(set QT_INSTALL_DOCS=E:/Qt/Docs/Qt-5.11.0)
(set BUILDDIR=D:/GitHub/cim2ddl/znd/dev/src/gui/3rdparty/Charts/2.0/Src/src/charts)
E:\Qt\5.11.0\msvc2017_64\bin\qdoc.exe %*
EndLocal
