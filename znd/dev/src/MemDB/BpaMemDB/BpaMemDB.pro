TEMPLATE = lib

!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}
!include(../MemDB.pri){
         error(the file ../MemDB.pri is not exist!!)
}


HEADERS +=  BpaDict.h \               
			BpaDictData.h \           
			BpaDictSwiData.h \        
			BpaMemDB.h \              
			BpaMemDBBlock.h \         
			BpaMemDBDefine.h \        
			BpaMemDBExtern.h \        
			BpaMemDBField.h \         
			BpaMemDBTable.h       

SOURCES += BpaMemDB.cpp \             
			BpaMemDBData.cpp \         
			BpaMemDBDecompose.cpp \    
			BpaMemDBDerived.cpp \      
			BpaMemDBDict.cpp \         
			BpaMemDBFile.cpp \         
			BpaMemDBFileDat.cpp \      
			BpaMemDBFileIn.cpp \       
			BpaMemDBFilePfo.cpp \      
			BpaMemDBFileSwi.cpp \      
			BpaMemDBMaint.cpp \        
			BpaMemDBMisc.cpp \         
			BpaMemDBRecord.cpp \       
			BpaMemDBReduct.cpp \       
			BpaMemDBTopo.cpp \         
			BpaMemDBZil.cpp   
           		   



CONFIG -= qt

DEFINES += _BPAMEMDB_EXPORTS_

LIBS += -lTinyXML


