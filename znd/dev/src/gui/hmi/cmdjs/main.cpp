
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
    int ret=-1;
    QString log_name="cmdjs";

	int er = log_reg_v2(argc, argv, LOG_DEBUG);
	if (er < 0)
		log_warn("Register log failed.er:%d\n", er);



    SYS_PID_TYPE nProcessId = SysEnv::GetProcPID();
    log_name = log_name+QString("_%1").arg(nProcessId);
    log_info("----------------cmdjs_--%s,start----------------------------------------", log_name.toLocal8Bit().data());

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
        return ret;
};


