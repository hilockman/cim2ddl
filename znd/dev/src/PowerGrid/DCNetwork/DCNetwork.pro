TEMPLATE = lib
SOURCES += DCNetwork.cpp \
           DCNetwork_MatZ.cpp \
		   DCNetwork_PGFlow.cpp \
		   DCNetwork_PRFlow.cpp \
		   DCNetwork_PRMisc.cpp

HEADERS += DCNetwork.h

!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}

!include(../PowerGrid.pri){
         error(the file ../PowerGrid.pri is not exist!!)
}


CONFIG -= qt

LIBS += -ltinyxml -lbase -lPRMemDB -lPGMemDB

DEFINES += DCNETWORK_EXPORTS

