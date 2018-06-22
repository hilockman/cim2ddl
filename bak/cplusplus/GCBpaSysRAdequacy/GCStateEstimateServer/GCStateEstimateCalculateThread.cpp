// GCStateEstimateCalculateThread.cpp : 实现文件
//

#include "stdafx.h"
#include "GCStateEstimateServer.h"
#include "GCStateEstimateCalculateThread.h"


// CGCStateEstimateCalculateThread

IMPLEMENT_DYNCREATE(CGCStateEstimateCalculateThread, CWinThread)

CGCStateEstimateCalculateThread::CGCStateEstimateCalculateThread()
{
	m_bAutoDelete		= FALSE;

	m_pMainWnd = NULL;
	m_pParentThread = NULL;
	strcpy(m_szRemoteAddr, "127.0.0.1");
	m_nRemotePort = 9002;

	m_nWorkMemID = 0;
	m_pPREstimate = NULL;
	m_pPRWorkBlock = NULL;

	m_bIdle = 1;
	PRAdequacyBase::InitBpaPRAdequacySetting(&m_PRAdequacySetting);
}

CGCStateEstimateCalculateThread::~CGCStateEstimateCalculateThread()
{
}

BOOL CGCStateEstimateCalculateThread::InitInstance()
{
	// TODO: 在此执行任意逐线程初始化
	return TRUE;
}

int CGCStateEstimateCalculateThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	if (m_pPRWorkBlock)
		m_PRMemDBInterface.Exit_PRBlock((char*)m_pPRWorkBlock, m_nWorkMemID);
	delete m_pPREstimate;

	m_nWorkMemID = 0;
	m_pPREstimate = NULL;
	m_pPRWorkBlock = NULL;
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CGCStateEstimateCalculateThread, CWinThread)
	ON_THREAD_MESSAGE(TM_STATE_ESTIMATE,	OnCalculate)
	ON_THREAD_MESSAGE(TM_QUIT,				OnQuit)
END_MESSAGE_MAP()


// CGCStateEstimateCalculateThread 消息处理程序

//////////////////////////////////////////////////////////////////////////
//	由外部调用
int	CGCStateEstimateCalculateThread::Create(CWnd* pMainWnd, CWinThread* pParent, const int nThreadID, tagBpaPRAdequacySetting* pSetting, const char* lpszRemoteAddr, const int nRemotePort)
{
	m_pMainWnd			= pMainWnd;
	m_pParentThread		= pParent;
	strcpy(m_szRemoteAddr, lpszRemoteAddr);
	m_nRemotePort = nRemotePort;

	m_nWorkMemID=g_nPRBlockKey+1000+nThreadID;
	CopyBpaPRAdequacySetting(pSetting, &m_PRAdequacySetting);

	m_pPREstimate = new CPRAdequacyStateEstimate();
	if (!m_pPREstimate)
	{
		Log(g_lpszLogFile, "建立发输电系统充裕度评估评估类错误，内存空间可能不够\n");
		return 0;
	}

	m_pPRWorkBlock=(tagPRBlock*)m_PRMemDBInterface.Init_PRBlock(m_nWorkMemID);
	if (!m_pPRWorkBlock)
	{
		Log(g_lpszLogFile, "获取PR工作内存库错误\n");
		delete m_pPREstimate;
		return 0;
	}

	memcpy(m_pPRWorkBlock, m_PRMemDBInterface.Init_PRBlock(), sizeof(tagPRBlock));
	m_pPREstimate->PrepareSysStateEstimate(m_pPRWorkBlock, 0);

	if (!CreateThread())
	{
		if (m_pPRWorkBlock)
			g_PRMemDBInterface.Exit_PRBlock((char*)m_pPRWorkBlock, m_nWorkMemID);
		delete m_pPREstimate;
		return 0;
	}

	return 1;
}

void CGCStateEstimateCalculateThread::Close()
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

void CGCStateEstimateCalculateThread::OnQuit(WPARAM wParam, LPARAM lParam)
{
	Log(g_lpszLogFile, "CGCStateEstimateCalculateThread OnQuit\n");
	if (m_pPRWorkBlock)
	{
		g_PRMemDBInterface.Exit_PRBlock((char*)m_pPRWorkBlock, m_nWorkMemID);
		m_pPRWorkBlock = NULL;
	}
	if (m_pPREstimate)
	{
		delete m_pPREstimate;
		m_pPREstimate = NULL;
	}

	AfxEndThread(0);

	return;

	UNREFERENCED_PARAMETER(wParam);
	UNREFERENCED_PARAMETER(lParam);
}

void CGCStateEstimateCalculateThread::OnCalculate(WPARAM wParam, LPARAM lParam)
{
	int				nRec, nTable, nField;
	char			szValue[MDB_CHARLEN_LONG];
	char*			lpszData = (char*)lParam;

	Json::Reader	sReader;
	Json::Value		sRoot, sContent, sData, sRecArray, sObject, sNull(nullValue);

	bool	bSuccess = sReader.parse(lpszData, sRoot, false);
	GlobalFree(lpszData);
	if (!bSuccess)
	{
		SendNetworkData(m_szRemoteAddr, m_nRemotePort, FormResultJSon(Command_StateEstimate, "0", "计算线程中 Parse Json 错误").c_str());
		m_bIdle = 1;
		return;
	}

#ifdef _DEBUG
	SendMessageToWindow("        ********** 开始计算任务 **********");
#endif

	m_pPRWorkBlock->m_nRecordNum[PR_FSTATE]=0;
	m_pPRWorkBlock->m_nRecordNum[PR_FSTATEFDEV]=0;
	m_pPRWorkBlock->m_nRecordNum[PR_FSTATEMSTATE]=0;
	m_pPRWorkBlock->m_nRecordNum[PR_FSTATEMISLAND]=0;
	m_pPRWorkBlock->m_nRecordNum[PR_FSTATEOVLDEV]=0;
	m_pPRWorkBlock->m_nRecordNum[PR_FSTATEOVLAD]=0;

	sContent = sRoot.get("Content", sNull);
	if (!sContent.isNull())
	{
		//////////////////////////////////////////////////////////////////////////
		nTable = PR_FSTATE;
		sRecArray = sContent.get(g_PRMemDBInterface.PRGetTableName(nTable), sNull);
		if (!sRecArray.isNull() || !sRecArray.isArray())
		{
			for (nRec=0; nRec<sRecArray.size(); nRec++)
			{
				sObject = sRecArray.get(nRec, sNull);
				if (sObject.isNull() || !sObject.isObject())
					continue;

				memset(&m_pPRWorkBlock->m_FStateArray[m_pPRWorkBlock->m_nRecordNum[nTable]], 0, sizeof(tagPRFState));
				Json::ValueIterator iter = sObject.begin();
				for (; iter != sObject.end(); iter++)
				{
					sData = sObject.get(iter.memberName(), sNull);
					if (!sData.isNull())
					{
						nField = g_PRMemDBInterface.PRGetFieldIndex(nTable, iter.memberName());

						if (nField >= 0 && nField < g_PRMemDBInterface.PRGetTableFieldNum(nTable))
						{
							memset(szValue, 0, MDB_CHARLEN_LONG);
							if (sData.isString())
								strcpy(szValue, sData.asString().c_str());
							else if (sData.isDouble()) {
								std::stringstream os;
								double v = sData.asDouble();
								os << v;
								strcpy(szValue, os.str().c_str());
								//sprintf(szValue, "%lf", v);
							} else if (sData.isInt())
								sprintf(szValue, "%d", sData.asInt());

#ifdef _DEBUG
							Log(g_lpszLogFile, "OnCalculate Table[%s] Field[%s] = %s\n", g_PRMemDBInterface.PRGetTableDesp(nTable), g_PRMemDBInterface.PRGetFieldDesp(nTable, nField), szValue);
#endif
							g_PRMemDBInterface.PRSetRecordValue(m_pPRWorkBlock, nTable, nField, m_pPRWorkBlock->m_nRecordNum[nTable], szValue);
						}
					}
				}
			}
			m_pPRWorkBlock->m_nRecordNum[nTable]++;
		}
		else
		{
#ifdef _DEBUG
			SendMessageToWindow("        Content中无%s", g_PRMemDBInterface.PRGetTableName(nTable));
#endif
			char	szMesg[260];
			sprintf(szMesg, "计算线程解析Json错误：Content中无%s", g_PRMemDBInterface.PRGetTableName(nTable));
			SendNetworkData(m_szRemoteAddr, m_nRemotePort, FormResultJSon(Command_StateEstimate, "0", szMesg).c_str());
			m_bIdle = 1;
			return;
		}

		//////////////////////////////////////////////////////////////////////////
		nTable = PR_FSTATEFDEV;
		sRecArray = sContent.get(g_PRMemDBInterface.PRGetTableName(nTable), sNull);
		if (!sRecArray.isNull() || !sRecArray.isArray())
		{
			for (nRec=0; nRec<sRecArray.size(); nRec++)
			{
				sObject = sRecArray.get(nRec, sNull);
				if (sObject.isNull() || !sObject.isObject())
					continue;

				memset(&m_pPRWorkBlock->m_FStateFDevArray[m_pPRWorkBlock->m_nRecordNum[nTable]], 0, sizeof(tagPRFStateFDev));
				Json::ValueIterator iter = sObject.begin();
				for (; iter != sObject.end(); iter++)
				{
					sData = sObject.get(iter.memberName(), sNull);
					if (!sData.isNull())
					{
						nField = g_PRMemDBInterface.PRGetFieldIndex(nTable, iter.memberName());
						if (nField >= 0 && nField < g_PRMemDBInterface.PRGetTableFieldNum(nTable))
						{
							memset(szValue, 0, MDB_CHARLEN_LONG);
							if (sData.isString())
								strcpy(szValue, sData.asString().c_str());
							else if (sData.isDouble())
								sprintf(szValue, "%lf", sData.asDouble());
							else if (sData.isInt())
								sprintf(szValue, "%d", sData.asInt());

#ifdef _DEBUG
							Log(g_lpszLogFile, "OnCalculate Table[%s] Field[%s] = %s\n", g_PRMemDBInterface.PRGetTableDesp(nTable), g_PRMemDBInterface.PRGetFieldDesp(nTable, nField), szValue);
#endif
							g_PRMemDBInterface.PRSetRecordValue(m_pPRWorkBlock, nTable, nField, m_pPRWorkBlock->m_nRecordNum[nTable], szValue);
						}
					}
				}
				m_pPRWorkBlock->m_FStateFDevArray[m_pPRWorkBlock->m_nRecordNum[nTable]].nFStateNo = 0;
				m_pPRWorkBlock->m_nRecordNum[nTable]++;
			}
		}
	}
	else
	{
#ifdef _DEBUG
		SendMessageToWindow("        root中无Content");
#endif
		SendNetworkData(m_szRemoteAddr, m_nRemotePort, FormResultJSon(Command_StateEstimate, "0", "计算线程解析Json错误：root中无Content").c_str());
		m_bIdle = 1;
		return;
	}

	m_pPREstimate->SysStateEstimate(m_pPRWorkBlock,
		0,
		m_PRAdequacySetting.fDc2AcFactor,
		m_PRAdequacySetting.fMinIslandGLRatio,
		m_PRAdequacySetting.bLineELimit,
		m_PRAdequacySetting.bTranELimit,
		m_PRAdequacySetting.bGenPELimit,
		m_PRAdequacySetting.bUPFCELimit,
		m_PRAdequacySetting.bAuxLoadAdjust,
		m_PRAdequacySetting.bEQGenAdjust,
		m_PRAdequacySetting.bEQLoadAdjust,
		m_PRAdequacySetting.bUPFCAdjustRC,
		NULL);

	char	szMesg[260];
	sprintf(szMesg, "        FStateID = %d 计算完成", m_pPRWorkBlock->m_FStateArray[0].nFStateId);

	SendMessageToWindow("        FStateID = %d 计算完成", m_pPRWorkBlock->m_FStateArray[0].nFStateId);
	SendNetworkData(m_szRemoteAddr, m_nRemotePort, FormResultJSon(m_pPRWorkBlock, szMesg, 0).c_str());

	m_bIdle = 1;
}

std::string	CGCStateEstimateCalculateThread::FormResultJSon(const char* lpszCommand, const char* lpszRetValue, const char* lpszMesg)
{
	Json::Value sRoot;
	Json::Value sContent;
	Json::FastWriter writer;

	sRoot["Command"] = lpszCommand;
	sContent["Value"] = lpszRetValue;
	sContent["Message"] = lpszMesg;
	sRoot["Content"] = sContent;

	return writer.write(sRoot);
}

void	CGCStateEstimateCalculateThread::FormRecordJSon(tagPRBlock* pPRBlock, const int nTable, const int nRecord, Json::Value& sField)
{
	int		nField, nFieldType;
	char	szValue[MDB_CHARLEN_LONG];

	sField.clear();
	for (nField=0; nField<g_PRMemDBInterface.PRGetTableFieldNum(nTable); nField++)
	{
		g_PRMemDBInterface.PRGetRecordValue(pPRBlock, nTable, nField, nRecord, szValue);
		nFieldType = g_PRMemDBInterface.PRGetFieldType(nTable, nField);
		switch (nFieldType)
		{
		case	MDB_STRING:
			sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = szValue;
			break;
		case	MDB_DOUBLE:
			sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = atof(szValue);
			break;
		case	MDB_FLOAT:
			sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = atof(szValue);
			break;
		case	MDB_INT:
			sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = atoi(szValue);
			break;
		case	MDB_SHORT:
			sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = atoi(szValue);
			break;
		case	MDB_BIT:
			sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = atoi(szValue);
			break;
		case	MDB_CHAR:
			sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = (int)szValue[0];
			break;
		default:
			sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = szValue;
			break;
		}
	}
}

std::string	CGCStateEstimateCalculateThread::FormResultJSon(tagPRBlock* pPRBlock, const char* lpszMesg, const int nEstimateState)
{
	register int	i;
	int		nTable;
	Json::Value sRoot;
	Json::Value sContent;
	Json::Value sField;
	Json::Value sFieldArray;
	Json::FastWriter writer;

	clock_t	dBeg, dEnd;
	int		nDur;
	dBeg=clock();

	sRoot.clear();
	sContent.clear();

	sRoot["Command"] = Command_StateEstimate;
	sContent["Message"] = lpszMesg;
	sContent["Value"] = "1";

	//////////////////////////////////////////////////////////////////////////
	nTable = PR_FSTATE;
	FormRecordJSon(pPRBlock, nTable, nEstimateState, sField);
	sContent[g_PRMemDBInterface.PRGetTableName(nTable)].append( sField );

	//////////////////////////////////////////////////////////////////////////
	nTable = PR_FSTATEMISLAND;
	for (i=0; i<pPRBlock->m_nRecordNum[nTable]; i++)
	{
		if (pPRBlock->m_FStateMIslandArray[i].nFStateNo != nEstimateState)
			continue;
		FormRecordJSon(pPRBlock, nTable, i, sField);
		sContent[g_PRMemDBInterface.PRGetTableName(nTable)].append( sField );
	}

	//////////////////////////////////////////////////////////////////////////
	nTable = PR_FSTATEOVLDEV;
	for (i=0; i<pPRBlock->m_nRecordNum[nTable]; i++)
	{
		if (pPRBlock->m_FStateOvlDevArray[i].nFStateNo != nEstimateState)
			continue;

		FormRecordJSon(pPRBlock, nTable, i, sField);
		sContent[g_PRMemDBInterface.PRGetTableName(nTable)].append( sField );
	}

	//////////////////////////////////////////////////////////////////////////
	nTable = PR_FSTATEOVLAD;
	for (i=0; i<pPRBlock->m_nRecordNum[nTable]; i++)
	{
		if (pPRBlock->m_FStateOvlAdArray[i].nFStateNo != nEstimateState)
			continue;

		FormRecordJSon(pPRBlock, nTable, i, sField);
		sContent[g_PRMemDBInterface.PRGetTableName(nTable)].append( sField );
	}

	for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
	{
		sField.clear();
		sField[g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_NAME)]  = pPRBlock->m_ACBusArray[i].szName;
		sField[g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_KV)]  = pPRBlock->m_ACBusArray[i].fkV;
		sField[g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_PLC)]  = pPRBlock->m_ACBusArray[i].fPLC ;
		sField[g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_ELC)]  = pPRBlock->m_ACBusArray[i].fELC ;
		sField[g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_EENS)] = pPRBlock->m_ACBusArray[i].fEENS;
		sField[g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_EFLC)] = pPRBlock->m_ACBusArray[i].fEFLC;
		sContent[g_PRMemDBInterface.PRGetTableName(PR_ACBUS)].append( sField );
	}

	sRoot["Content"] = sContent;

	dEnd=clock();
	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
#ifdef _DEBUG
	SendMessageToWindow("        形成计算结果JSON完成，耗时%d毫秒\n", nDur);
	//Log(g_lpszLogFile, "ReturnJson = %d %d %d\n%s\n\n", pPRBlock->m_nRecordNum[PR_FSTATEMISLAND], pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV], pPRBlock->m_nRecordNum[PR_FSTATEOVLAD], sRoot.toStyledString().c_str());
#endif

	return writer.write(sRoot);
}

void CGCStateEstimateCalculateThread::SendMessageToWindow(char* pformat, ...)
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
