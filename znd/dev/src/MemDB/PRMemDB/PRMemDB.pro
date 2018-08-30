TEMPLATE = lib

!include(../MemDB.pri){
         error(the file ../MemDB.pri is not exist!!)
}


HEADERS +=  PRMemDB.h \
			PRMemDBBlock.h \
			PRMemDBDefine.h \
			PRMemDBExtern.h \
			PRMemDBField.h \
			PRMemDBTable.h
			
SOURCES += PRMemDB.cpp \
		   PRMemDBIsland.cpp \
		   PRMemDBMaint.cpp \
		   PRMemDBRecord.cpp 
           		   

!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}


CONFIG -= qt

DEFINES += _PRMEMDB_EXPORTS_



