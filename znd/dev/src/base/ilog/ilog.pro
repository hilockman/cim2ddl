TEMPLATE = lib

!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}

CONFIG += console
CONFIG -= qt

DEFINES += ZND_EXPORTS


 # move executable one dire up

  

ZND_HOME = $$(ZND_HOME)


INCLUDE_PATH = $$ZND_HOME/dev/include

INCLUDEPATH += $$ZND_HOME/dev/include

HEADERS += $$INCLUDE_PATH/ilog.h \
           $$INCLUDE_PATH/log.h

SOURCES +=  ilog.cpp log.cpp
           


