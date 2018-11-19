#include "Global.h"
#include "GFunc.h"
#include "GEApp.h"
#include "sys/eproc.h"

#ifdef GLUT
#include <QtOpenGL>
#include "GL/glut.h"
#endif

#ifdef WIN32
#include <windows.h>
#include <process.h>
#else
//#include <X11/Intrinsic.h>
//#include <X11/Shell.h>
//#include <X11/Xlib.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>
#include <arpa/inet.h>
#endif

#ifdef WIN32_OCX
#include "ExplorerWnd.h"
#include <QAxFactory>
QAXFACTORY_BEGIN("{A3535B7D-7753-4e9d-8F0F-587840E061DB}", "{BF583B04-E6BE-4b91-926F-E1DE4E9B3489}")
QAXCLASS(CGExplorerWnd)
QAXFACTORY_END()

#endif

#ifndef WIN32
#ifdef _ALPHA
#include <sys/uswitch.h>
#endif
#endif

#ifdef _SUN
#include <signal.h>
#endif

void DoNothing(int nn=0)
{
}

void ExitProcess(int aa=0)
{
    gInfo("exit_process1\n");
	qApp->exit(0);
}

#ifdef WIN32
BOOL WINAPI console_ctrl_handler(DWORD ctrl_type)
{
	switch (ctrl_type)
	{
	case CTRL_C_EVENT:
	case CTRL_BREAK_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_SHUTDOWN_EVENT:
		ExitProcess(0);
		return TRUE;
	default:
		return FALSE;
	}
}
#endif


int main( int argc, char** argv )
{

#ifdef WIN32
    if (SetConsoleCtrlHandler(console_ctrl_handler, TRUE) ==false)
    {
        printf("Unable to install handler!\n");
    }
#else
#ifdef _ALPHA
    long uval = uswitch(USC_GET, 0);
    uval = uswitch(USC_SET, uval | USW_CORE);
    if (uval < 0)
    {
        perror("uswitch");
        exit(1);
    }
#endif
    sigset(SIGFPE,DoNothing);
    sigset(SIGHUP,DoNothing);
    sigset(SIGALRM,DoNothing);
    sigset(SIGPIPE,DoNothing);
    signal(SIGINT,ExitProcess);
    signal(SIGTERM,ExitProcess);
#endif

#ifdef _ELOG
    int er = log_reg_v2(argc, argv, LOG_DEBUG);
	if (er < 0)
	{
        gWarn("Register log failed.er:%d\n", er);
		if (argc>1)
            er = log_reg_v2(1, argv, LOG_DEBUG);//log reg name max limit 64
	}
	EProc::Init(argc, argv);
#endif

	CGEApp graph_app( argc, argv);


#ifdef GLUT
    gInfo("----------------HMI-opengl init ----------------------------------------");
    if ((QGLFormat::openGLVersionFlags() & QGLFormat::OpenGL_Version_1_5) == 0) {
        QMessageBox::critical(0, "OpenGL features missing",
            "OpenGL version 1.5 or higher is required to run this demo.\n"
            "The program will now exit.");
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
#endif

#ifdef WIN32_OCX
    if(QAxFactory::isServer())
    {
        QDir tmpdir=QCoreApplication::applicationFilePath();
        tmpdir.cd("../../");
        UnqFunc()->SetSysHome(tmpdir.absolutePath());
    }
#endif

    gInfo("----------------DaemonThread start----------------------------------------");
    DaemonThread mythread(&graph_app);
    mythread.start();

    graph_app.RunApp( "");

    int ret=graph_app.exec();

    return ret;
}
