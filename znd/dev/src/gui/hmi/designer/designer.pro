unix{
    KDCHART_HOME = $$system(printenv KDCHART_HOME) 
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
TARGET   = gd

QT += xml script svg  widgets  printsupport
CONFIG += qt

DEFINES -= UNICODE

DEPENDPATH +=  ../    ../include GDesigner  Dialog  ../explorer ../shared  ../libs/gcore/include  ../libs/scripttools/debugging  ../../plugins/propertyeditor  ../libs/svg
INCLUDEPATH += $$DEPENDPATH
			
LIBS       += -lgcore  -lproperty -lgscripttools
win32:LIBS+=dbghelp.lib
        
HEADERS += GDApp.h \
           ConstString.h \
           GDesigner/DesignerView.h \
           GDesigner/DesignerScene.h \
           GDesigner/DesignerWnd.h \
           GDesigner/GlobalToolBar.h \
		GDesigner/ObjectInspector.h	\
		GDesigner/NameManager.h	\
	   GDesigner/ItemBox.h	\
	   GDesigner/BoxItemView.h \
	   GDesigner/Mdi.h \
	   GDesigner/DrawManager.h \
	   GDesigner/DrawTool.h\
	   GDesigner/Commands.h	\
	   GDesigner/ActionManager.h \
	   GDesigner/CursorManager.h \
       GDesigner/ItemCreator.h    \
	   GDesigner/ActionEnum_p.h \         
	   Dialog/CNaviDialog.h \
	   Dialog/CDyTableItemDelegate.h \	  
	   Dialog/IconDlg.h \
	   Dialog/ReplaceDlg.h \
../explorer/ExplorerView.h \
../explorer/ExplorerScene.h \
           ../shared/GApp.h \
           ../shared/GWnd.h \
	   ../shared/AnimationDlg.h \
	   ../shared/CommunicatePluginMng.h \
	   ../shared/AnimateDriver.h 
              
SOURCES += GDApp.cpp \
           main.cpp \
           ConstString.cpp \
           GDesigner/DesignerView.cpp \
           GDesigner/DesignerScene.cpp \
           GDesigner/DesignerWnd.cpp \
           GDesigner/ObjectInspector.cpp \
           GDesigner/NameManager.cpp	\
           GDesigner/GlobalToolBar.cpp \
	   GDesigner/ItemBox.cpp	\
	   GDesigner/BoxItemView.cpp\
	   GDesigner/Mdi.cpp \
	   GDesigner/DrawManager.cpp \
	   GDesigner/DrawTool.cpp \
	   GDesigner/Commands.cpp	\
	   GDesigner/ActionManager.cpp \
	   GDesigner/CursorManager.cpp \
           GDesigner/ItemCreator.cpp \
	   Dialog/CNaviDialog.cpp \
	   Dialog/CDyTableItemDelegate.cpp \
	   Dialog/IconDlg.cpp \
	   Dialog/ReplaceDlg.cpp \
../explorer/ExplorerView.cpp \
../explorer/ExplorerScene.cpp \
           ../shared/GApp.cpp \
           ../shared/GWnd.cpp \
	   ../shared/AnimationDlg.cpp \
	   ../shared/CommunicatePluginMng.cpp \
	   ../shared/AnimateDriver.cpp 

RESOURCE += 
	   
FORMS +=  ../shared/AnimationDlg.ui Dialog/icon-setting.ui Dialog/ReplaceDlg.ui 

TRANSLATIONS    = gui_zh_CN.ts 

RESOURCES += \
    editor.qrc

#######################################
#win32:QT += axcontainer axserver

contains(DEFINES,WEBVIEW){
QT += webenginewidgets
}
contains(DEFINES,GSVG){
LIBS += -lgsvg
}
contains(DEFINES,_ELOG){
LIBS += -lelog -leproc
}

