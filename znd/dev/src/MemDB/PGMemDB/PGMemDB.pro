TEMPLATE = lib

COMMON_DIR = $$(ZND_HOME)/dev/src/Common
MEMDB_DIR = $$(ZND_HOME)/dev/src/MemDB/MemDBBase
HEADERS +=  $$MEMDB_DIR/MemDBBase.h \
			$$MEMDB_DIR/MemDBBase_Check.hpp \
			$$MEMDB_DIR/MemDBBase_Record.hpp \
			$$MEMDB_DIR/MemDBBase_Sort.hpp \
			$$MEMDB_DIR/MemDBHash.h \
			$$COMMON_DIR/StringCommon.h \
			PGMemDB.h \
			PGMemDBBlock.h \
			PGMemDBDefine.h \
			PGMemDBEnum.h \
			PGMemDBExtern.h \
			PGMemDBField.h \
			PGMemDBTable.h 
#			PGMemDBDefine_DCGrid.h \
#			PGMemDBDefine_Distribution.h \
#			PGMemDBDefine_Enum.h \
#			PGMemDBDefine_Graph.h \
#			PGMemDBDefine_Misc.h \
#			PGMemDBDefine_Relay.h \
#			PGMemDBField_DCGrid.h \
#			PGMemDBField_Distribution.h \
#			PGMemDBField_Graph.h \
#			PGMemDBField_Misc.h \
#			PGMemDBField_Relay.h
			
SOURCES += $$MEMDB_DIR/MemDBBase.cpp	 \
           PGMemDB.cpp \
		   PGMemDBAbnorm.cpp \
		   PGMemDBBreakerType.cpp \
		   PGMemDBBusType.cpp \
		   PGMemDBDecompose.cpp \
		   PGMemDBDerived.cpp \
		   PGMemDBIsland.cpp \
		   PGMemDBMaint.cpp \
		   PGMemDBMisc.cpp \
		   PGMemDBPFAmend.cpp \
		   PGMemDBPointer.cpp \
		   PGMemDBRecord.cpp \
		   PGMemDBRegular.cpp \
		   PGMemDBStat.cpp \ 
		   PGMemDBStatus.cpp \ 
		   PGMemDBTopo.cpp \ 
		   PGMemDBTrav.cpp \ 
		   PGMemDBVolt32.cpp \
			$$COMMON_DIR/StringCommon.cpp \
			$$COMMON_DIR/Log.cpp
           		   

!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}


CONFIG -= qt

DEFINES += _PGMEMDB_EXPORTS_

LIBS += -lbase


