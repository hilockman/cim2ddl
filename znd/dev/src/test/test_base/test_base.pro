TEMPLATE = app

!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}

CONFIG += console
CONFIG -= qt


INCLUDEPATH += $$(ZND_HOME)/dev/include


SOURCES +=  main.cpp
            
LIBS += -lbase			
           



