unix{
   
    CURRENT_PROJECT_PATH = $$system(pwd)
}

win32{
    CURRENT_PROJECT_PATH = .
}

!include($$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}

QT += core script
QT -= gui

CONFIG += c++11   qt

TARGET = cmdjs
CONFIG += console
#CONFIG -= app_bundle
#DEFINES +=MIN_EXPORT11

LIBS       +=  -lelog -leproc -lsysrun
win32:LIBS+=dbghelp.lib

TEMPLATE = app

DEPENDPATH += ./  include ../../include    $$(SMARTSYS_HOME)/dev/include/sys
INCLUDEPATH += $$DEPENDPATH

SOURCES += main.cpp \
    capp.cpp


HEADERS += \
    capp.h

