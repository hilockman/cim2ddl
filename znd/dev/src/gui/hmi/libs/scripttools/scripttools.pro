unix{
    CURRENT_PROJECT_PATH = $$system(pwd)
}
win32{
    CURRENT_PROJECT_PATH = .
}
!include($$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}


#load(qfeatures)
requires(!contains(QT_DISABLED_FEATURES, textedit))

TEMPLATE = lib
CONFIG  += dll qt

TARGET     = gscripttools
QT         = core-private
QT_PRIVATE = gui widgets-private script

DEFINES   += QT_NO_USING_NAMESPACE QT_BUILD_SCRIPTTOOLS_LIB
#win32-msvc*|win32-icc:QMAKE_LFLAGS += /BASE:0x66000000
 

QMAKE_DOCS = $$PWD/doc/qtscripttools.qdocconf

#load(qt_module)

include(debugging/debugging.pri)
