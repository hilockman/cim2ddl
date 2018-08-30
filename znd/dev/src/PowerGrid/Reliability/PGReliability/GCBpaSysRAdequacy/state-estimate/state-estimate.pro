TEMPLATE = app
SOURCES = main.c tinyxmladapter.cpp wrapper.cpp

!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}

REDIS_DIR = $$(ZND_HOME)/dev/thirdparty/redis

SOURCES += $$REDIS_DIR/src/ae.c \
           $$REDIS_DIR/src/adlist.c \
		   $$REDIS_DIR/src/zmalloc.c \
		   #stateestimate.cpp 
		   
#HEADERS += stateestimate.h

INCLUDEPATH += $$REDIS_DIR/deps/hiredis \
               $$REDIS_DIR/src \
			   $$(ZND_HOME)/dev/thirdparty/tinyxml \
			   $$(ZND_HOME)/dev/include

CONFIG += console
CONFIG -= qt
DEFINES += _OFF_T_DEFINED _WIN32 LACKS_STDLIB_H
#DEFINES -= HAVE_PROC_SMAPS
DEFINES -= WIN32_LEAN_AND_MEAN


#TARGET = ../state-estimate # move executable one dire up

#win32: LIBS += -lkernel32 -luser32 -lgdi32 -lwinspool -lcomdlg32 -ladvapi32 -lshell32 -lole32 -loleaut32 -luuid -lodbc32 -lodbccp32       
win32: LIBS += -luser32              
win32: LIBS += -lshell32   
#win32: LIBS += -lLIBCMT      

LIBS += -ltinyxml
 
CONFIG(debug, debug|release) { 
    message("debug mode")    
    win32 {
	   #QMAKE_LFLAGS += /NODEFAULTLIB:MSVCRTD
	   #QMAKE_LFLAGS += /NODEFAULTLIB:MSVCPRTD
       QMAKE_CFLAGS_DEBUG += /MTd  
       QMAKE_CXXFLAGS_DEBUG += /MTd	
	   LIBS += -lhiredis -lWin32_Interop
	}

} else {
    message("release mode")
    win32 {
	   QMAKE_CFLAGS_RELEASE += /MT 
       QMAKE_CXXFLAGS_RELEASE += /MT	
	   LIBS += -lhiredis -lWin32_Interop
	   #QMAKE_LFLAGS += /NODEFAULTLIB:MSVCRT
	   #QMAKE_LFLAGS += /NODEFAULTLIB:MSVCPRT		   
	}
}

LIBS += -lstate-estimate-core -lbase