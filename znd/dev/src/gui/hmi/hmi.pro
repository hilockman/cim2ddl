TEMPLATE = subdirs
DEFINES +=_ELOG GSVG WEBVIEW
CONFIG += qt
contains( DEFINES, GLUT )
{
    LIBS += -lfreeglut
    QT   += opengl
}

SUBDIRS = libs/gcore 	\
          libs/scripttools    \
	      libs/svg 	\
  	      designer \
  	      explorer \
          cmdjs \
		  guicmdjs

