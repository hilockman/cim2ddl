
// GCStateEstimateServer.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "GCStateEstimateNetwork.h"
#include "GCStateEstimateControlThread.h"

// CGCStateEstimateServerApp:
// 有关此类的实现，请参阅 GCStateEstimateServer.cpp
//

class CGCStateEstimateServerApp : public CWinAppEx
{
public:
	CGCStateEstimateServerApp();

// 重写
	public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CGCStateEstimateServerApp theApp;
extern	tagPRBlock*			g_pPRBlock;
extern	CPRMemDBInterface	g_PRMemDBInterface;

extern	unsigned int	g_nLocalPort;
extern	unsigned int	g_nRemotePort;
extern	char			g_szRemoteAddr[48];

extern	void	ReadIni(void);
extern	void	SaveIni(void);

extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, char* pformat, ...);
extern	void	ClearLog(const char*);
extern	void	ClearMessage();
extern	void	PrintMessage(const char* lpszFormat, ...);

extern	CNetworkInterface		g_NetInterface;

extern	CPRAdequacyEstimate		g_PRAdeEstimate;

extern	CGCStateEstimateControlThread	g_StateEstimateControlThread;
extern	void	StartNetworkService(CWinThread* pDataProcThread, const int nSvrPort);
extern	void	StopNetworkService();
extern	int		SendNetworkData(const char* lpszAddr, const int nPort, const char* lpszData);
