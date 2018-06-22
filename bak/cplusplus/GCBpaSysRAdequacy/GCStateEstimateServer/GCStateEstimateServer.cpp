
// GCStateEstimateServer.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "GCStateEstimateServer.h"
#include "GCStateEstimateServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGCStateEstimateServerApp

BEGIN_MESSAGE_MAP(CGCStateEstimateServerApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CGCStateEstimateServerApp 构造

CGCStateEstimateServerApp::CGCStateEstimateServerApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CGCStateEstimateServerApp 对象

CGCStateEstimateServerApp theApp;
const	char*	g_lpszLogFile="GCStateEstimateServer.log";
const	static	char*	lpszIniFile="GCStateEstimateServer.ini";

// CGCStateEstimateServerApp 初始化
unsigned int			g_nLocalPort;
unsigned int			g_nRemotePort;
char					g_szRemoteAddr[48];
tagPRBlock*				g_pPRBlock;
CPRMemDBInterface		g_PRMemDBInterface;

CNetworkInterface		g_NetInterface;

CPRAdequacyEstimate		g_PRAdeEstimate;

CGCStateEstimateControlThread	g_StateEstimateControlThread;

HANDLE CreateOneAppMutex(const char* lpszName)
{
	HANDLE	hMutex = CreateMutex(NULL, 1, lpszName);   // Create mutex
	switch (GetLastError())
	{
	case ERROR_SUCCESS:
		//
		// Mutex created successfully. There is no instances running
		//
		break;

	case ERROR_ALREADY_EXISTS:
		//
		// Mutex already exists so there is a running instance of our app.
		//
		hMutex = NULL;
		break;

	default:
		//
		// Failed to create mutex by unkniown reason
		//
		break;
	}

	return hMutex;
}

BOOL CGCStateEstimateServerApp::InitInstance()
{
	//_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(1276);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	if (!CreateOneAppMutex("ZhongND_GCStateEstimateService"))
	{
		AfxMessageBox("网络服务已经存在");
		return FALSE;
	}

	ReadIni();
	ClearLog(g_lpszLogFile);

	g_pPRBlock=(tagPRBlock*)g_PRMemDBInterface.Init_PRBlock();
	if (!g_pPRBlock)
	{
		AfxMessageBox("初始化可靠性数据库错误");
		return FALSE;
	}

	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CGCStateEstimateServerDlg dlg;
	m_pMainWnd = &dlg;

	if (!g_StateEstimateControlThread.Create(m_pMainWnd, this, g_szRemoteAddr, g_nRemotePort))
	{
		AfxMessageBox("建立终端网络线程失败!");
		return FALSE;
	}

	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	g_StateEstimateControlThread.Close();

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

void ReadIni(void)
{
	char	szLine[1024];
	int		nReadContent, nIndex;
	int		nRow, nCol;
	std::vector<std::string>	strEleArray;
	FILE*	fp;

	g_nLocalPort=8950;
	g_nRemotePort=9002;
	strcpy(g_szRemoteAddr, "127.0.0.1");

	fp=fopen(lpszIniFile, "r");
	if (fp == NULL)
		return;

	nIndex=nRow=nCol=0;
	nReadContent=0;
	while (!feof(fp))
	{
		memset(szLine, 0, 1024);
		fgets(szLine, 1024, fp);
		if (strstr(szLine, "[GCStateEstimateServiceConfig]") != NULL)
		{
			nReadContent=1;
			continue;
		}
		else if (strstr(szLine, "[END]") != NULL || strstr(szLine, "[End_GCStateEstimateServiceConfig]") != NULL)
		{
			nReadContent=0;
			continue;
		}
		if (nReadContent == 1)
		{
			strEleArray.clear();
			char*	lpszToken=strtok(szLine, " \t\n=");
			while (lpszToken != NULL)
			{
				strEleArray.push_back(lpszToken);
				lpszToken=strtok(NULL, " \t\n=");
			}
			if (strEleArray.size() == 2)
			{
				if (strstr(szLine, "LocalPort") != NULL)		g_nLocalPort=atoi(strEleArray[1].c_str());
				else if (strstr(szLine, "RemoteAddr") != NULL)	strcpy(g_szRemoteAddr, strEleArray[1].c_str());
				else if (strstr(szLine, "RemotePort") != NULL)	g_nRemotePort=atoi(strEleArray[1].c_str());
			}
		}
	}
}

void SaveIni(void)
{
	FILE*	fp;

	fp=fopen(lpszIniFile, "w");
	if (fp == NULL)
		return;

	fprintf(fp, "[GCStateEstimateServiceConfig]\n");
	fprintf(fp, "LocalPort=%d\n",	g_nLocalPort);
	fprintf(fp, "RemoteAddr=%s\n",	g_szRemoteAddr);
	fprintf(fp, "RemotePort=%d\n",	g_nRemotePort);
	fprintf(fp, "[End_GCStateEstimateServiceConfig]\n");

	fprintf(fp, "[END]\n");

	fflush(fp);
	fclose(fp);
}

void	ClearMessage()
{
	CGCStateEstimateServerDlg*	pFrame=(CGCStateEstimateServerDlg*)theApp.GetMainWnd();
	pFrame->ClearMessage();
}

void	PrintMessage(const char* lpszFormat, ...)
{
	va_list args;
	va_start( args, lpszFormat );

	char	szMesg[1024];
	vsprintf(szMesg, lpszFormat, args);

	CGCStateEstimateServerDlg* pDlg=(CGCStateEstimateServerDlg*)AfxGetMainWnd();
	if (pDlg)
		pDlg->PrintMessage(szMesg);

	va_end(args);
}
