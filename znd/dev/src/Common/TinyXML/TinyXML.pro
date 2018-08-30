TEMPLATE = lib
SOURCES +=  *.cpp 		   
HEADERS += *.h

DEFINES += TINYXML_EXPORTS 
CONFIG += warn_off


!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}