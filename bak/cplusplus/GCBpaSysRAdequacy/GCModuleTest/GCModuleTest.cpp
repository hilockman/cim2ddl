
// GCModuleTest.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "GCModuleTest.h"
#include "GCModuleTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGCModuleTestApp

BEGIN_MESSAGE_MAP(CGCModuleTestApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CGCModuleTestApp 构造

CGCModuleTestApp::CGCModuleTestApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CGCModuleTestApp 对象

CGCModuleTestApp		theApp;
tagBpaBlock*			g_pBpaBlock;
tagPRBlock*				g_pPRBlock;
CPRMemDBInterface		g_PRMemDBInterface;
tagBpaPRAdequacySetting	g_PRAdeSetting;

char					g_szRemoteAddr[48];
unsigned int			g_nRemotePort;
unsigned int			g_nLocalPort;
int						g_nThreadNum;
char					g_szRunDir[260];

// CGCModuleTestApp 初始化
const	char*	g_lpszLogFile="GCModuleTest.log";
const	char*	g_lpszIniFile="GCModuleTest.xml";

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

BOOL CGCModuleTestApp::InitInstance()
{
	if (!CreateOneAppMutex("ZhongND_GCModuleTest"))
	{
		AfxMessageBox("网络服务已经存在");
		return FALSE;
	}
	HANDLE hEstStateSem = InitSem(g_lpszGCPRStateEstimateSemaphore);

	GetCurrentDirectory(260, g_szRunDir);
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
		AfxMessageBox("网络初始化错误");
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

	ClearLog(g_lpszLogFile);

	strcpy(g_szRemoteAddr, "127.0.0.1");
	g_nRemotePort = 8950;
	g_nLocalPort = 9002;
	g_nThreadNum = 2;

	g_pBpaBlock=(tagBpaBlock*)Init_BpaBlock();
	if (!g_pBpaBlock)
	{
		AfxMessageBox("获取Bpa内存库错误");
		return FALSE;
	}

	g_pPRBlock=(tagPRBlock*)g_PRMemDBInterface.Init_PRBlock();
	if (!g_pPRBlock)
	{
		AfxMessageBox("获取PR内存库错误");
		return FALSE;
	}

	InitBpaPRAdequacySetting(&g_PRAdeSetting);
	char	szFileName[260];
	sprintf(szFileName, "%s/Ini", g_szRunDir);
	if (access(szFileName, 0) == 0)
	{
		sprintf(szFileName, "%s/Ini/%s", g_szRunDir, g_lpszIniFile);
		if (access(szFileName, 0) != 0)
			sprintf(szFileName, "%s/%s", g_szRunDir, g_lpszIniFile);
	}
	else
		sprintf(szFileName, "%s/%s", g_szRunDir, g_lpszIniFile);
	ReadBpaPRAdequacySetting(szFileName, &g_PRAdeSetting);

	CGCModuleTestDlg dlg;
	m_pMainWnd = &dlg;
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

	if (hEstStateSem != INVALID_HANDLE_VALUE)
		CloseHandle(hEstStateSem);

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

void	PrintMessage(const char* lpszFormat, ...)
{
	va_list args;
	va_start( args, lpszFormat );

	char	szMesg[1024];
	vsprintf(szMesg, lpszFormat, args);

	CGCModuleTestDlg* pDlg=(CGCModuleTestDlg*)AfxGetMainWnd();
	if (pDlg)
		pDlg->PrintMessage(szMesg);

	va_end(args);
}
