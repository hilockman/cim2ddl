#include "Global.h"
#include "capp.h"
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
    log_info("exit_process1\n");
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


//

int main(int argc, char *argv[])
{
	QString log_name;
    SYS_PID_TYPE nProcessId = SysEnv::GetProcPID();
    log_name = QString("cmdjs_%1").arg(nProcessId);
    gInfo("----------------cmdjs_--%s,start----------------------------------------", log_name.toLocal8Bit().data());

	int svgImpRet = 0;
    CApp a(argc, argv);
#ifndef WIN32
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

#ifdef WIN32
    if (SetConsoleCtrlHandler(console_ctrl_handler, TRUE) == false)
    {
        log_info("Unable to install handler!\n");
    }
#endif
    if (!a.m_exit)
        return a.exec();
    else
		return svgImpRet;
};



