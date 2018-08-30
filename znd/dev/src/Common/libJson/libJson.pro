TEMPLATE = lib

HEADERS +=  include/autolink.h \     
include/features.h \    
include/forwards.h \    
include/json.h \        
include/reader.h \      
include/value.h \       
include/writer.h \
src/json_batchallocator.h \
src/json_internalarray.inl \
src/json_internalmap.inl \
src/json_valueiterator.inl


SOURCES += src/json_reader.cpp \
src/json_value.cpp \ 
src/json_writer.cpp \


DEFINES += JSON_DLL_BUILD 


!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}