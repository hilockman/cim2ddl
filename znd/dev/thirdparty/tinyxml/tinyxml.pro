TEMPLATE = lib
SOURCES +=  *.cpp 		   
HEADERS += *.h

DEFINES += TINYXML_EXPORTS 
CONFIG += warn_on
QMAKE_CFLAGS_WARN_ON -= -W4251
QMAKE_CXXFLAGS_WARN_ON -= -W4251

!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}