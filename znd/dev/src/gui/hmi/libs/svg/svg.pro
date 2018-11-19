unix{
	CURRENT_PROJECT_PATH = $$system(pwd)
}
win32{
	CURRENT_PROJECT_PATH = .
}
!include($$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}

TEMPLATE = lib
CONFIG  += dll qt  

TARGET     = gsvg
 
DEFINES   += QT_NO_USING_NAMESPACE QT_NO_COMPRESS
win32-msvc*|win32-icc:QMAKE_LFLAGS += /BASE:0x66000000
solaris-cc*:QMAKE_CXXFLAGS_RELEASE -= -O2

QT += svg widgets script
contains(DEFINES,WEBVIEW){
QT += webenginewidgets
}
DEPENDPATH +=  ./ ../gcore/include
INCLUDEPATH += $$DEPENDPATH

HEADERS += \
    qsvggraphics_p.h        \
    qsvghandler_p.h         \
    qsvgnode_p.h            \
    qsvgstructure_p.h       \
    qsvgstyle_p.h           \
    qsvgfont_p.h            \
    qsvgtinydocument_p.h    \
    qtsvgglobal.h


SOURCES += \
    qsvggraphics.cpp        \
    qsvghandler.cpp         \
    qsvgnode.cpp            \
    qsvgstructure.cpp       \
    qsvgstyle.cpp           \
    qsvgfont.cpp            \
    qsvgtinydocument.cpp    

LIBS       += -lgcore -lrtdb_client -ldatastream -ldbclient -leproc -lsysrun -ldbsync
