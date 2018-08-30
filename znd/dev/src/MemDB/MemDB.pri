COMMON_DIR = $$(ZND_HOME)/dev/src/Common
MEMDB_DIR = $$(ZND_HOME)/dev/src/MemDB/MemDBBase
HEADERS +=  $$MEMDB_DIR/MemDBBase.h \
			$$MEMDB_DIR/MemDBBase_Check.hpp \
			$$MEMDB_DIR/MemDBBase_Record.hpp \
			$$MEMDB_DIR/MemDBBase_Sort.hpp \
			$$MEMDB_DIR/MemDBHash.h \
			$$COMMON_DIR/StringCommon.h 
SOURCES += $$MEMDB_DIR/MemDBBase.cpp	 \
			$$COMMON_DIR/StringCommon.cpp \
			$$COMMON_DIR/Log.cpp
			
		