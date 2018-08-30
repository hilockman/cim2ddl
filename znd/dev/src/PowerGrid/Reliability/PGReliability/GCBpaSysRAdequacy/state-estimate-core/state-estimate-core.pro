TEMPLATE = lib
#CONFIG += staticlib
SOURCES +=  stateestimate.cpp stateestimatetask.cpp
HEADERS += stateestimate.h ThreadPool.h stateestimatetask.h

!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}

CONFIG += console
CONFIG -= qt

DEFINES += STATEESTIMATE_EXPORTS

#DEFINES += _OFF_T_DEFINED _WIN32 LACKS_STDLIB_H
#DEFINES -= HAVE_PROC_SMAPS

 # move executable one dire up

win32: LIBS += -lkernel32 -luser32 -lgdi32 -lwinspool -lcomdlg32 -ladvapi32 -lshell32 -lole32 -loleaut32 -luuid -lodbc32 -lodbccp32       
#win32: LIBS += -luser32              
#win32: LIBS += -lshell32   
#win32: LIBS += -lLIBCMT      

ZND_HOME = $$(ZND_HOME)


#HEADERS += common/SemaphoreCommon.h ilog.h
#HEADERS += ilog.h log.h
#SOURCES +=  common/SemaphoreCommon.cpp \
#			common/Log.cpp \
#SOURCES +=  ilog.cpp log.cpp
           

message("ZND_HOME=" $$ZND_HOME )

INCLUDEPATH += $$ZND_HOME/dev/src \
               $$ZND_HOME/dev/src/PowerGrid/Reliability/PGReliability/PRAdequacyBase \
			   $$ZND_HOME/dev/include

LIBS += -lbase -llibJson -lPRAdequacyBase -lTinyXml -lPRMemDB -lDCNetwork
 
CONFIG(debug, debug|release) { 
    message("debug mode")    
       #QMAKE_CFLAGS_DEBUG += /MTd  
       #QMAKE_CXXFLAGS_DEBUG += /MTd	
	#LIBS += -L$$ZND_HOME/lib_x64 -llibJsonMDd -llibPRAdequacyBaseMDd -llibTinyXmlMDd -lPRMemDB -llibDCNetworkMDd
} else {
   QMAKE_CXXFLAGS_WARN_ON-= -w34100 -w34189 -w34251 -w4217 -w4049
    message("release mode")
	   QMAKE_CFLAGS_RELEASE += /MT 
       QMAKE_CXXFLAGS_RELEASE += /MT
	   QMAKE_LFLAGS += /NODEFAULTLIB:MSVCRT
	#LIBS += -L$$ZND_HOME/lib_x64 -llibJsonMD -llibPRAdequacyBaseMD -llibTinyXmlMD -lPRMemDB	-llibDCNetworkMD
}