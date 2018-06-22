#pragma once

#include "../../../../../Network/NetworkBase/NetworkInterface.h"

#ifndef UM_MESSAGE
#	define UM_MESSAGE			WM_APP+1000
#endif

#ifndef TM_CONNECT
#	define TM_CONNECT			WM_APP+1001
#endif

#ifndef TM_QUIT
#	define TM_QUIT				WM_APP+1002
#endif

#ifndef TM_DATA_COME
#	define TM_DATA_COME			WM_APP+1003
#endif

#ifndef TM_DATA_READY
#	define TM_DATA_READY		WM_APP+1011
#endif

#ifndef TM_STATE_ESTIMATE
#	define TM_STATE_ESTIMATE	WM_APP+1012
#endif

#ifndef TM_JOB_FINISHED
#	define TM_JOB_FINISHED		WM_APP+1013
#endif

#define	Command_DataReady		"DataReady"
#define	Command_StateEstimate	"StateEstimate"
#define	Command_JobFinished		"JobFinished"

typedef	void (*vFun_v)(void*);
typedef struct	_Thread_Arg_
{
	SOCKET			sSocket;
	char			szPeerAddr[48];
	unsigned int	nPeerPort;
	CWnd*			pMainWnd;
	CWinThread*		pDataProcThread;
	vFun_v			pDataProcFunc;	//	短连接数据处理模块
	void*			pDataPtr;
}	tagThreadArg;

extern	CNetworkInterface		g_NetInterface;
