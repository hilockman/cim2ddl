// GCStateEstimateControlThread.cpp : 实现文件
//

#include "stdafx.h"
#include "GCStateEstimateServer.h"
#include "GCStateEstimateControlThread.h"

// CGCStateEstimateControlThread

IMPLEMENT_DYNCREATE(CGCStateEstimateControlThread, CWinThread)

CGCStateEstimateControlThread::CGCStateEstimateControlThread()
{
	m_bAutoDelete		= FALSE;

	m_pMainWnd = NULL;
	m_pParentThread = NULL;
	m_pDataProcThreadArray.clear();
	strcpy(m_szRemoteAddr, "127.0.0.1");
	m_nRemotePort = 9002;
}

CGCStateEstimateControlThread::~CGCStateEstimateControlThread()
{
	if (!m_pDataProcThreadArray.empty())
	{
		for (int nThread=0; nThread<m_pDataProcThreadArray.size(); nThread++)
		{
			if (m_pDataProcThreadArray[nThread])
			{
				m_pDataProcThreadArray[nThread]->Close();
				delete m_pDataProcThreadArray[nThread];
			}
		}

		m_pDataProcThreadArray.clear();
	}
}

BOOL CGCStateEstimateControlThread::InitInstance()
{
	// TODO: 在此执行任意逐线程初始化
	return TRUE;
}

int CGCStateEstimateControlThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CGCStateEstimateControlThread, CWinThread)
	ON_THREAD_MESSAGE(TM_CONNECT,		OnConnect)
	ON_THREAD_MESSAGE(TM_QUIT,			OnQuit)
END_MESSAGE_MAP()


// CGCStateEstimateControlThread 消息处理程序
void CGCStateEstimateControlThread::OnConnect(WPARAM wParam, LPARAM lParam)
{
#ifdef _DEBUG
	SendMessageToWindow("    开始数据处理线程");
#endif

	unsigned char	bNetRecvSuccess;
	clock_t			dBeg, dEnd;
	int				nDur;

	tagThreadArg	tArg;
	memcpy(&tArg, (char*)lParam, sizeof(tagThreadArg));
	GlobalFree((void*)lParam);

	SOCKET	sComm=tArg.sSocket;
	if (sComm == INVALID_SOCKET)
	{
		Log(g_lpszLogFile, "OnConnect INVALID_SOCKET\n");
		return;
	}
	dBeg=clock();

	std::string	strRecv;
	bNetRecvSuccess = g_NetInterface.ReadTCPSocket(sComm, strRecv);

	shutdown(sComm, SD_BOTH);
	closesocket(sComm);

	dEnd=clock();
	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);

#ifdef _DEBUG
	SendMessageToWindow("        网络数据接收完成(%d)，共计 %d 字节，耗时 %d 毫秒", bNetRecvSuccess, strRecv.size(), nDur);

// 	Log(g_lpszLogFile, "网络数据接收完成，共计 %d 字节，耗时 %d 毫秒", strRecv.size(), nDur);
// 	Log(g_lpszLogFile, "\n********************************************************************************\n");
// 	Log(g_lpszLogFile, "%s\n", strRecv.c_str());
// 	Log(g_lpszLogFile, "********************************************************************************\n\n\n");
#endif

	if (bNetRecvSuccess)
		NetworkDataProcess(strRecv);
	else
		SendMessageToWindow("        网络数据接收错误(%d)，共计 %d 字节，耗时 %d 毫秒", bNetRecvSuccess, strRecv.size(), nDur);
}

void CGCStateEstimateControlThread::OnQuit(WPARAM wParam, LPARAM lParam)
{
	Log(g_lpszLogFile, "CGCStateEstimateControlThread OnQuit %d\n", m_pDataProcThreadArray.size());
	if (!m_pDataProcThreadArray.empty())
	{
		for (int nThread=0; nThread<m_pDataProcThreadArray.size(); nThread++)
		{
			if (m_pDataProcThreadArray[nThread])
			{
				m_pDataProcThreadArray[nThread]->Close();
				delete m_pDataProcThreadArray[nThread];
			}
		}
		m_pDataProcThreadArray.clear();
	}

	AfxEndThread(0);

	return;

	UNREFERENCED_PARAMETER(wParam);
	UNREFERENCED_PARAMETER(lParam);
}

//////////////////////////////////////////////////////////////////////////
//	由外部调用
int	CGCStateEstimateControlThread::Create(CWnd* pMainWnd, CWinThread* pParent, const char* lpszRemoteAddr, const int nRemotePort)
{
	m_pMainWnd			= pMainWnd;
	m_pParentThread		= pParent;
	strcpy(m_szRemoteAddr, lpszRemoteAddr);
	m_nRemotePort = nRemotePort;
	m_pMainWnd = pMainWnd;

	if (!CreateThread())
		return 0;

	return 1;
}

void CGCStateEstimateControlThread::Close()
{
	if (m_hThread)
	{
		DWORD	dwExitCode;
		BOOL	bGet = GetExitCodeThread(m_hThread,&dwExitCode);
		if (bGet && dwExitCode == STILL_ACTIVE)
		{
			PostThreadMessage(TM_QUIT,0,0);
			WaitForSingleObject(m_hThread,1000);
		}
	}
}

int CGCStateEstimateControlThread::NetworkDataProcess(std::string strRecv)
{
	Json::Reader	sReader;
	Json::Value		sRoot, sContent, sData, sNull(nullValue);

	std::string		strCommand, strValue;

	strCommand.clear();
	strValue.clear();
	if (!sReader.parse(strRecv, sRoot, false))
	{
		strValue = "控制线程中 Parse Json 错误, 网络接收数据 = ";
		strValue.append(strRecv);

#ifdef _DEBUG
		SendMessageToWindow("        控制线程中 Parse Json 错误");
		Log(g_lpszLogFile, "        控制线程中 Parse Json 错误\n");
#endif
		SendNetworkData(m_szRemoteAddr, m_nRemotePort, FormResultJSon("Error", "0", strValue.c_str()).c_str());
		return FALSE;
	}

	strCommand = sRoot["Command"].asString();
#ifdef _DEBUG
	SendMessageToWindow("接收Command = %s", strCommand.c_str());
	Log(g_lpszLogFile, "Command = %s\n", strCommand.c_str());
#endif

	if (stricmp(strCommand.c_str(), Command_DataReady) == 0)
	{
		if (!m_pDataProcThreadArray.empty())
		{
#ifdef _DEBUG
			SendMessageToWindow("        当前计算任务没有结束，请先JobFinished");
			Log(g_lpszLogFile, "        当前计算任务没有结束，请先JobFinished\n");
#endif
			SendNetworkData(m_szRemoteAddr, m_nRemotePort, FormResultJSon(strCommand.c_str(), "0", "控制线程中 DataReady命令 计算任务进行中").c_str());
			return FALSE;
		}

		tagBpaPRAdequacySetting	sPRAdequacySetting;
		PRAdequacyBase::InitBpaPRAdequacySetting(&sPRAdequacySetting);

		sContent = sRoot.get("Content", sNull);
		if (!sContent.isNull())
		{
			sData = sContent.get("PRAdequacySetting", sNull);
			if (!sData.isNull())
			{
				ParsePRSetting(sData, &sPRAdequacySetting);
			}
			else
			{
#ifdef _DEBUG
				SendMessageToWindow("        Content中无PRAdequacySetting");
				Log(g_lpszLogFile, "Content中无PRAdequacySetting\n");
#endif
				SendNetworkData(m_szRemoteAddr, m_nRemotePort, FormResultJSon(strCommand.c_str(), "0", "控制线程中 DataReady命令 Content 中无 PRAdequacySetting").c_str());
				return FALSE;
			}
		}
		SendMessageToWindow("        计算线程初始化");
		DataReady(&sPRAdequacySetting);

		char	szMesg[260];
		sprintf(szMesg, "%d", m_pDataProcThreadArray.size());
		SendNetworkData(m_szRemoteAddr, m_nRemotePort, FormResultJSon(strCommand.c_str(), szMesg, "计算线程初始化完成").c_str());
	}
	else if (stricmp(strCommand.c_str(), Command_JobFinished) == 0)
	{
		if (m_pDataProcThreadArray.empty())
		{
#ifdef _DEBUG
			SendMessageToWindow("        当前无计算任务");
			Log(g_lpszLogFile, "        当前无计算任务\n");
#endif
			SendNetworkData(m_szRemoteAddr, m_nRemotePort, FormResultJSon(strCommand.c_str(), "0", "控制线程中 JobFinished命令 当前无计算任务").c_str());
			return FALSE;
		}

		SendMessageToWindow("        关闭计算任务");
		FinishJob();
		SendNetworkData(m_szRemoteAddr, m_nRemotePort, FormResultJSon(strCommand.c_str(), "1", "计算任务关闭完成").c_str());
	}
	else if (stricmp(strCommand.c_str(), Command_StateEstimate) == 0)
	{
		int	nIdleThread = -1;
		for (int nThread=0; nThread<m_pDataProcThreadArray.size(); nThread++)
		{
			if (m_pDataProcThreadArray[nThread]->m_bIdle)
			{
				nIdleThread = nThread;
				break;
			}
		}
		if (nIdleThread >= 0)
		{
			register int	i;
			char*	lpszData = (char*)GlobalAlloc(GPTR, strRecv.size());
			memset(lpszData, 0, strRecv.size());

			for (i=0; i<strRecv.size(); i++)
				lpszData[i] = strRecv[i];

			m_pDataProcThreadArray[nIdleThread]->m_bIdle = 0;
			m_pDataProcThreadArray[nIdleThread]->PostThreadMessage(TM_STATE_ESTIMATE, 0, (LPARAM)lpszData);
		}
		else
		{
			SendNetworkData(m_szRemoteAddr, m_nRemotePort, FormResultJSon(strCommand.c_str(), "0", "控制线程中 无空闲计算线程").c_str());
		}
	}

	return TRUE;
}

void CGCStateEstimateControlThread::SendMessageToWindow(char* pformat, ...)
{
	va_list args;
	va_start( args, pformat );

	if (m_pMainWnd)
	{
		char	szMesg[1024];
		vsprintf(szMesg, pformat, args);

		int		nMesgLen = strlen(szMesg)+1;
		char*	lpszMesg = (char*)malloc(nMesgLen);
		if (lpszMesg)
		{
			memset(lpszMesg, 0, nMesgLen);
			strcpy(lpszMesg, szMesg);
			m_pMainWnd->PostMessage(UM_MESSAGE, 0, (LPARAM)lpszMesg);
		}
	}

	va_end(args);
}

void CGCStateEstimateControlThread::ParsePRSetting(Json::Value& sData, tagBpaPRAdequacySetting* pSetting)
{
	Json::Value	sObject, sNull(nullValue);

	sObject = sData.get("BpaDatFile", sNull);		if (!sObject.isNull())	pSetting->strBpaDatFile		= sObject.asString();				//潮流输入文件
	sObject = sData.get("BpaSwiFile", sNull);		if (!sObject.isNull())	pSetting->strBpaSwiFile		= sObject.asString();				//稳定输入文件，主要是用于形成发电机模型
	sObject = sData.get("BpaRParamFile", sNull);	if (!sObject.isNull())	pSetting->strBpaRParamFile	= sObject.asString();				//可靠性参数输入文件
	sObject = sData.get("TinyGenThreshold", sNull);	if (!sObject.isNull())	pSetting->fTinyGenThreshold	= sObject.asDouble();	//环辐网分解发电机容量门槛值（容量低于该门槛值的发电机认为不是发电机）
	sObject = sData.get("LowVoltThreshold", sNull);	if (!sObject.isNull())	pSetting->fLowVoltThreshold	= sObject.asDouble();	//环辐网分解发电机低电压门槛值（电压低于该门槛值的发电机认为是负荷而不是发电）
	sObject = sData.get("ZIL", sNull);				if (!sObject.isNull())	pSetting->fZIL				= sObject.asDouble();	//小阻抗清除小阻抗门槛值
	sObject = sData.get("PRSampleObject", sNull);	if (!sObject.isNull())	pSetting->nPRSampleObject	= sObject.asInt();	//抽样对象（全部、发电、支路）
	sObject = sData.get("PRSampleMethod", sNull);	if (!sObject.isNull())	pSetting->nPRSampleMethod	= sObject.asInt();	//抽样类型
	sObject = sData.get("MaxGenFault", sNull);		if (!sObject.isNull())	pSetting->nMaxGenFault		= sObject.asInt();	//MCS, FST, STS, ANA 抽样最大发电机故障重数
	sObject = sData.get("MaxBranFault", sNull);		if (!sObject.isNull())	pSetting->nMaxBranFault		= sObject.asInt();	//MCS, FST, STS, ANA 抽样最大支路故障重数
	sObject = sData.get("LineELimit", sNull);		if (!sObject.isNull())	pSetting->bLineELimit		= sObject.asInt();	//线路消限开关
	sObject = sData.get("TranELimit", sNull);		if (!sObject.isNull())	pSetting->bTranELimit		= sObject.asInt();	//主变消限开关
	sObject = sData.get("GenPELimit", sNull);		if (!sObject.isNull())	pSetting->bGenPELimit		= sObject.asInt();	//发电机参与消限
	sObject = sData.get("UPFCELimit", sNull);		if (!sObject.isNull())	pSetting->bUPFCELimit		= sObject.asInt();	//UPFC参与消限
	sObject = sData.get("AuxLoadAdjust", sNull);	if (!sObject.isNull())	pSetting->bAuxLoadAdjust	= sObject.asInt();	//厂用电负荷参与调整
	sObject = sData.get("EQGenAdjust", sNull);		if (!sObject.isNull())	pSetting->bEQGenAdjust		= sObject.asInt();	//等值发电机参与调整
	sObject = sData.get("EQLoadAdjust", sNull);		if (!sObject.isNull())	pSetting->bEQLoadAdjust		= sObject.asInt();	//等值发电机参与调整
	sObject = sData.get("MCSSimulateTime", sNull);	if (!sObject.isNull())	pSetting->nMCSSimulateTime	= sObject.asInt();	//MCS最大抽样仿真时长
	sObject = sData.get("MCSMinStateProb", sNull);	if (!sObject.isNull())	pSetting->fMCSMinStateProb	= sObject.asInt();	//MCS.get(蒙特卡罗]设备故障概率门槛值
	sObject = sData.get("FSTMaxCumuProb", sNull);	if (!sObject.isNull())	pSetting->fFSTMaxCumuProb	= sObject.asDouble();	//FST.get(快速排序]累积概率
	sObject = sData.get("FSTMinStateProb", sNull);	if (!sObject.isNull())	pSetting->fFSTMinStateProb	= sObject.asDouble();	//FST.get(快速排序]设备故障概率门槛值
	sObject = sData.get("FSTMaxStateNum", sNull);	if (!sObject.isNull())	pSetting->nFSTMaxStateNum	= sObject.asInt();	//FST.get(快速排序]最大状态数
	sObject = sData.get("STSMaxStateNum", sNull);	if (!sObject.isNull())	pSetting->nSTSMaxStateNum	= sObject.asInt();	//STS.get(状态抽样]最大状态数
	sObject = sData.get("ANAMinStateProb", sNull);	if (!sObject.isNull())	pSetting->fANAMinStateProb	= sObject.asDouble();	//ANA.get( 解析法]设备故障概率门槛值
	sObject = sData.get("Dc2AcFactor", sNull);		if (!sObject.isNull())	pSetting->fDc2AcFactor		= sObject.asDouble();	//直流潮流2 交流潮流系数
	sObject = sData.get("MinIslandGLRatio", sNull);	if (!sObject.isNull())	pSetting->fMinIslandGLRatio	= sObject.asDouble();	//孤岛的最小容载比
	sObject = sData.get("MultiThread", sNull);		if (!sObject.isNull())	pSetting->nMultiThread		= sObject.asInt();	//线程数
	sObject = sData.get("UPFCAdjustRC", sNull);		if (!sObject.isNull())	pSetting->bUPFCAdjustRC		= sObject.asInt();	//UPFC采用调整容量法
	sObject = sData.get("GenBusLoadAsAux", sNull);	if (!sObject.isNull())	pSetting->bGenBusLoadAsAux	= sObject.asInt();	//发电机母线负荷按厂用电处理
}

int CGCStateEstimateControlThread::DataReady(tagBpaPRAdequacySetting* pSetting)
{
	CGCStateEstimateCalculateThread* pThread;
	SYSTEM_INFO sysInfo;
	::GetSystemInfo(&sysInfo);

	int		nThreadNum = pSetting->nMultiThread;
	if (nThreadNum <= 0)
		nThreadNum = 1;
	if (nThreadNum > sysInfo.dwNumberOfProcessors)
		nThreadNum = sysInfo.dwNumberOfProcessors;

	for (int nThread=0; nThread<nThreadNum; nThread++)
	{
		pThread = new CGCStateEstimateCalculateThread();
		if (pThread)
		{
			if (!pThread->Create(m_pMainWnd, this, nThread+1, pSetting, m_szRemoteAddr, m_nRemotePort))
			{
				SendMessageToWindow("    建立计算分析线程[%d]失败!", nThread+1);
				Log(g_lpszLogFile, "建立计算分析线程[%d]失败!\n", nThread+1);
				continue;
			}
			SendMessageToWindow("    建立计算分析线程[%d]完成!\n", nThread+1);
			Log(g_lpszLogFile, "建立计算分析线程[%d]完成!\n", nThread+1);
			m_pDataProcThreadArray.push_back(pThread);
		}
	}
	return 1;
}

int CGCStateEstimateControlThread::FinishJob()
{
	for (int nThread=0; nThread<m_pDataProcThreadArray.size(); nThread++)
	{
		CGCStateEstimateCalculateThread* pThread=(CGCStateEstimateCalculateThread*)m_pDataProcThreadArray[nThread];
		pThread->Close();
		delete pThread;
	}

	m_pDataProcThreadArray.clear();

	return 1;
}

std::string	CGCStateEstimateControlThread::FormResultJSon(const char* lpszCommand, const char* lpszRetValue, const char* lpszMesg)
{
	Json::Value sRoot;
	Json::Value sContent;
	Json::FastWriter writer;

	//sprintf(szValue, "%d", nRetValue);
	sRoot["Command"] = lpszCommand;
	sContent["Value"] = lpszRetValue;
	sContent["Message"] = lpszMesg;
	sRoot["Content"] = sContent;

	return writer.write(sRoot);
}