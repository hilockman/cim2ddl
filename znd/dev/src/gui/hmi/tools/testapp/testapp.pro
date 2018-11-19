unix{
	CURRENT_PROJECT_PATH = $$system(pwd)
}
win32{
	CURRENT_PROJECT_PATH = .
}
!include($$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}

TEMPLATE = app
TARGET   = testapp

QT += xml script svg widgets  qml quick  webenginewidgets printsupport webchannel  websockets
CONFIG += qt


#win32:CONFIG +=  qaxserver

DEPENDPATH +=  $$(SMARTSYS_HOME)/dev/src/gui/plugins/hmi_basesrv_plugin
INCLUDEPATH += 	$$DEPENDPATH
			

LIBS       += -lhmi_basesrv_plugin
win32:LIBS+=dbghelp.lib
        
HEADERS += 
              
SOURCES += main.cpp

RESOURCE += 
	   
FORMS +=  
