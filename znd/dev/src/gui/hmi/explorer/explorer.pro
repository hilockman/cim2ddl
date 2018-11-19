unix{
	CURRENT_PROJECT_PATH = $$system(pwd)
}
win32{
	CURRENT_PROJECT_PATH = .
}
!include($$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}

include(../hmi.conf)

TEMPLATE = app
TARGET   = ge

QT += xml script svg widgets printsupport
CONFIG += qt

DEPENDPATH +=  ../  ../../  ../include  ../shared   ../libs/gcore/include ../libs/scripttools/debugging ../libs/svg
INCLUDEPATH += 	$$DEPENDPATH
			
LIBS       += -lgcore   -lelog  -leproc -lgscripttools
win32:LIBS+=dbghelp.lib
        
HEADERS += GEApp.h \
           ExplorerView.h \
           ExplorerScene.h \
           ExplorerWnd.h \
           ../shared/GApp.h \
           ../shared/GWnd.h \
           ../shared/AnimateDriver.h \
           ../shared/CommunicatePluginMng.h
              
SOURCES += GEApp.cpp \
           ExplorerView.cpp \
           ExplorerScene.cpp\
           ExplorerWnd.cpp \
           ../shared/GApp.cpp \
           ../shared/GWnd.cpp \
           ../shared/AnimateDriver.cpp \
           ../shared/CommunicatePluginMng.cpp \
    GEMain.cpp

RESOURCE += 	   
FORMS +=  


contains(DEFINES,WEBVIEW){
QT += webenginewidgets webchannel  websockets
HEADERS += websocketclientwrapper.h
SOURCES += websocketclientwrapper.cpp
}

contains(DEFINES,QML){
QT +=qml quick quickwidgets
}
#win32:CONFIG +=  qaxserver
