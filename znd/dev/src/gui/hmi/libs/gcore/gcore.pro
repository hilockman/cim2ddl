unix{
	CURRENT_PROJECT_PATH = $$system(pwd)
}
win32{
	CURRENT_PROJECT_PATH = .
}
!include($$(ZND_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(ZND_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}
include(../../hmi.conf)
TEMPLATE = lib
CONFIG  += dll qt  

TARGET   = gcore
unix:QMAKE_CXXFLAGS +=-w
DEFINES -= UNICODE
#DEFINES += KDCHART
include(QtAwesome/QtAwesome.pri)

QT += xml script svg  widgets uitools printsupport
win32:QT += axcontainer


DEPENDPATH += ./  include ../../include   checkcombobox
INCLUDEPATH += $$DEPENDPATH

win32:DEFINES   += DLL_OUT

HEADERS += include/GraphView.h \
           include/GraphScene.h \
           include/ItemFactory.h \
           include/BaseData.h \
           include/GraphItem.h \
           include/GroupItem.h \
           include/WidgetItem.h \
           include/IconMng.h \
           include/CQScriptWrap.h \
           include/CQWidgetWrap.h \
            include/GFunc.h \
            include/GraphSvgRW.h \
            include/CGrid.h \
            include/CManhattanStyle.h \
        include/Colorbutton.h \
		widgets/qxtcheckcombobox.h\
		include/gloweffect.h
         
SOURCES += GraphView.cpp \
           GraphScene.cpp \
           BaseData.cpp \
           GraphItem.cpp \
           GroupItem.cpp \
           WidgetItem.cpp \
           IconMng.cpp \
           ItemFactory.cpp \
           CQScriptWrap.cpp \
           CQWidgetWrap.cpp \
            GFunc.cpp \
        CGrid.cpp \
        GraphSvgRW.cpp \
        CManhattanStyle.cpp \
        widgets/Colorbutton.cpp \
		widgets/qxtcheckcombobox.cpp\
		gloweffect.cpp



#contains(DEFINES,KDCHART){
#DEPENDPATH +=  3rdparty/KDChart
#INCLUDEPATH  = $$DEPENDPATH
#LIBS       += -lkdchart2
#HEADERS += include/ChartTableModel.h \
#           include/ChartWrap.h \
#        widgets/ChartPropertyDlg.h \
#        widgets/ColorTriangle.h
		
#SOURCES += ChartTableModel.cpp \
#           ChartWrap.cpp \
#        widgets/ChartPropertyDlg.cpp \
#        widgets/ColorTriangle.cpp
#}

TRANSLATIONS =    guicore_zh_CN.ts

#################

contains(DEFINES,QML){
QT +=qml quick quickwidgets
}
contains(DEFINES,WEBVIEW){
QT += webenginewidgets
}
contains(DEFINES,CHARTS){
QT += charts
HEADERS += include/GChartItem.h 
SOURCES += GChartItem.cpp
}

