unix{
   
    CURRENT_PROJECT_PATH = $$system(pwd)
}

win32{
    CURRENT_PROJECT_PATH = .
}

!include($$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}

QT += core script widgets svg
#QT -= gui

CONFIG += c++11   qt

TARGET = guicmdjs
CONFIG += console

DEFINES += CMDJS_GUI _ELOG GSVG

LIBS       += -lgcore   -lelog -leproc -lsysrun -lgsvg
win32:LIBS+=dbghelp.lib

TEMPLATE = app

DEPENDPATH += ./  include ../../include  ../libs/gcore/include ../shared $$(SMARTSYS_HOME)/dev/include/sys ../libs/svg
INCLUDEPATH += $$DEPENDPATH

SOURCES += ../cmdjs/main.cpp \
          ../cmdjs/capp.cpp


HEADERS += ../cmdjs/capp.h

