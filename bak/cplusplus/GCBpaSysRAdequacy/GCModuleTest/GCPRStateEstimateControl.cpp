#include "stdafx.h"
#include "GCModuleTest.h"

extern	HANDLE	SemOn(const char* lpszSemKey, const int nMillionSecond);
extern	void	SemOff(HANDLE hSem);
extern	void	SendMessageToWindow(CWnd* pMesgWnd, char* pformat, ...);

const	char*	g_lpszGCPRStateEstimateSemaphore = "GCPRStateEstimateSemphore";
int				m_nThreadNum;

void PRStateEstimateCalculateInit(tagPRBlock* pPRBlock)
{
	m_nThreadNum = 0;
	for (int i=0; i<pPRBlock->m_nRecordNum[PR_FSTATE]; i++)
		pPRBlock->m_FStateArray[i].bEstimated = 0;
}

void PRStateEstimateCalculateExit()
{
	m_nThreadNum = 0;
}

void	FormRecordJSon(tagPRBlock* pPRBlock, const int nTable, const int nRecord, Json::Value& sField)
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

std::string FormStateEstimateJsonString(const int nEstimateState)
{
	Json::Value			sRoot;
	Json::Value			sContent;
	Json::Value			sField;
	Json::Value			sFieldArray;
	Json::FastWriter	sWriter;

	register int	i;
	int		nTable;
	char	szValue[MDB_CHARLEN_LONG];

	clock_t	dBeg, dEnd;
	int		nDur;
	dBeg=clock();

	sRoot["Command"] = Command_StateEstimate;

	sprintf(szValue, "%d", g_pPRBlock->m_FStateArray[nEstimateState].nFStateId);
	sContent["Value"] = szValue;

	//////////////////////////////////////////////////////////////////////////
	nTable = PR_FSTATE;
	FormRecordJSon(g_pPRBlock, nTable, nEstimateState, sField);
	sContent[g_PRMemDBInterface.PRGetTableName(nTable)].append( sField );

	//////////////////////////////////////////////////////////////////////////
	nTable = PR_FSTATEFDEV;
	for (i=0; i<g_pPRBlock->m_nRecordNum[nTable]; i++)
	{
		if (g_pPRBlock->m_FStateFDevArray[i].nFStateNo != nEstimateState)
			continue;

		FormRecordJSon(g_pPRBlock, nTable, i, sField);
		sContent[g_PRMemDBInterface.PRGetTableName(nTable)].append( sField );
	}
	sRoot["Content"] = sContent;

#ifdef _DEBUG
	Log(g_lpszLogFile, "FormStateEstimateJsonString %s\n", sRoot.toStyledString().c_str());
#endif
	return sWriter.write(sRoot);
}

void	EstimateStateDataProc(CWnd* pMainWnd, Json::Value& sContent)
{
	int				nEstimateState;
	Json::Value		sData, sRecArray, sObject, sNull(nullValue);
	char			szValue[MDB_CHARLEN_LONG];
	if (sContent.isNull())
	{
		SendMessageToWindow(pMainWnd, "StateEstimate, Content is Null");
		return;
	}

	int			nRec, nTable, nField;
	std::string	strValue;
	tagPRFState	sFState;

	sData = sContent.get("Value", sNull);
	if (!sData.isNull())
	{
		strValue = sData.asString();
#ifdef _DEBUG
		SendMessageToWindow(pMainWnd, "        ReturnCommandValue = %s", strValue.c_str());
		Log(g_lpszLogFile, "        ReturnCommandValue = %s\n", strValue.c_str());
#endif
	}

	nEstimateState = -1;

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
						Log(g_lpszLogFile, "EstimateStateDataProc Table[%s] Field[%s] = %s\n", g_PRMemDBInterface.PRGetTableDesp(nTable), g_PRMemDBInterface.PRGetFieldDesp(nTable, nField), szValue);
#endif
						g_PRMemDBInterface.PRSetDataPtrFieldValue(nTable, nField, szValue, (char*)&sFState);
					}
				}
			}
		}

		for (nRec=0; nRec<g_pPRBlock->m_nRecordNum[nTable]; nRec++)
		{
			if (g_pPRBlock->m_FStateArray[nRec].nFStateId == sFState.nFStateId)
			{
				nEstimateState = nRec;
				break;
			}
		}
		if (nEstimateState >= 0)
		{
			g_pPRBlock->m_FStateArray[nEstimateState].fFLossGen = 			sFState.fFLossGen;
			g_pPRBlock->m_FStateArray[nEstimateState].fFLossGenCap = 		sFState.fFLossGenCap;
			g_pPRBlock->m_FStateArray[nEstimateState].fFLossLoad = 			sFState.fFLossLoad;
			g_pPRBlock->m_FStateArray[nEstimateState].bMIsland = 			sFState.bMIsland;
			g_pPRBlock->m_FStateArray[nEstimateState].fMIInsGen = 			sFState.fMIInsGen;
			g_pPRBlock->m_FStateArray[nEstimateState].fMICutGen = 			sFState.fMICutGen;
			g_pPRBlock->m_FStateArray[nEstimateState].fMIOutLoad = 			sFState.fMIOutLoad;
			g_pPRBlock->m_FStateArray[nEstimateState].fAgcInsGen = 			sFState.fAgcInsGen;
			g_pPRBlock->m_FStateArray[nEstimateState].fAgcCutGen = 			sFState.fAgcCutGen;
			g_pPRBlock->m_FStateArray[nEstimateState].fEnsCutLoad = 		sFState.fEnsCutLoad;
			g_pPRBlock->m_FStateArray[nEstimateState].bOverLimit = 			sFState.bOverLimit;
			g_pPRBlock->m_FStateArray[nEstimateState].bELCutLoad = 			sFState.bELCutLoad;
			g_pPRBlock->m_FStateArray[nEstimateState].fELCutGen = 			sFState.fELCutGen;
			g_pPRBlock->m_FStateArray[nEstimateState].fELInsGen = 			sFState.fELInsGen;
			g_pPRBlock->m_FStateArray[nEstimateState].fELCutLoad = 			sFState.fELCutLoad;
			g_pPRBlock->m_FStateArray[nEstimateState].nELResult = 			sFState.nELResult;
		}
	}
	else
	{
		SendMessageToWindow(pMainWnd, "Content中无FState");
		return;
	}

	if (nEstimateState < 0)
		return;

	//////////////////////////////////////////////////////////////////////////
	nTable = PR_FSTATEMISLAND;
	sRecArray = sContent.get(g_PRMemDBInterface.PRGetTableName(nTable), sNull);
	if (!sRecArray.isNull() || !sRecArray.isArray())
	{
		for (nRec=0; nRec<sRecArray.size(); nRec++)
		{
			sObject = sRecArray.get(nRec, sNull);
			if (sObject.isNull() || !sObject.isObject())
				continue;

			memset(&g_pPRBlock->m_FStateMIslandArray[g_pPRBlock->m_nRecordNum[nTable]], 0, sizeof(tagPRFStateMIsland));
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
						Log(g_lpszLogFile, "EstimateStateDataProc Table[%s] Field[%s] = %s\n", g_PRMemDBInterface.PRGetTableDesp(nTable), g_PRMemDBInterface.PRGetFieldDesp(nTable, nField), szValue);
#endif
						g_PRMemDBInterface.PRSetRecordValue(g_pPRBlock, nTable, nField, g_pPRBlock->m_nRecordNum[nTable], szValue);
					}
				}
			}
			g_pPRBlock->m_FStateMIslandArray[g_pPRBlock->m_nRecordNum[nTable]].nFStateNo = nEstimateState;
			g_pPRBlock->m_nRecordNum[nTable]++;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	nTable = PR_FSTATEOVLDEV;
	sRecArray = sContent.get(g_PRMemDBInterface.PRGetTableName(nTable), sNull);
	if (!sRecArray.isNull() || !sRecArray.isArray())
	{
		for (nRec=0; nRec<sRecArray.size(); nRec++)
		{
			sObject = sRecArray.get(nRec, sNull);
			if (sObject.isNull() || !sObject.isObject())
				continue;

			memset(&g_pPRBlock->m_FStateMIslandArray[g_pPRBlock->m_nRecordNum[nTable]], 0, sizeof(tagPRFStateMIsland));
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
						Log(g_lpszLogFile, "EstimateStateDataProc Table[%s] Field[%s] = %s\n", g_PRMemDBInterface.PRGetTableDesp(nTable), g_PRMemDBInterface.PRGetFieldDesp(nTable, nField), szValue);
#endif
						g_PRMemDBInterface.PRSetRecordValue(g_pPRBlock, nTable, nField, g_pPRBlock->m_nRecordNum[nTable], szValue);
					}
				}
			}
			g_pPRBlock->m_FStateOvlDevArray[g_pPRBlock->m_nRecordNum[nTable]].nFStateNo = nEstimateState;
			g_pPRBlock->m_nRecordNum[nTable]++;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	nTable = PR_FSTATEOVLAD;
	sRecArray = sContent.get(g_PRMemDBInterface.PRGetTableName(nTable), sNull);
	if (!sRecArray.isNull() || !sRecArray.isArray())
	{
		for (nRec=0; nRec<sRecArray.size(); nRec++)
		{
			sObject = sRecArray.get(nRec, sNull);
			if (sObject.isNull() || !sObject.isObject())
				continue;

			memset(&g_pPRBlock->m_FStateMIslandArray[g_pPRBlock->m_nRecordNum[nTable]], 0, sizeof(tagPRFStateMIsland));
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
						Log(g_lpszLogFile, "EstimateStateDataProc Table[%s] Field[%s] = %s\n", g_PRMemDBInterface.PRGetTableDesp(nTable), g_PRMemDBInterface.PRGetFieldDesp(nTable, nField), szValue);
#endif
						g_PRMemDBInterface.PRSetRecordValue(g_pPRBlock, nTable, nField, g_pPRBlock->m_nRecordNum[nTable], szValue);
					}
				}
			}
			g_pPRBlock->m_FStateOvlAdArray[g_pPRBlock->m_nRecordNum[nTable]].nFStateNo = nEstimateState;
			g_pPRBlock->m_nRecordNum[nTable]++;
		}
	}
}

void PRStateEstimateReturn(CWnd* pMainWnd, Json::Value& sContent)
{
	HANDLE hSem = SemOn(g_lpszGCPRStateEstimateSemaphore, 1000);
	if (hSem != INVALID_HANDLE_VALUE)
	{
#ifdef _DEBUG
		SendMessageToWindow(pMainWnd, "        释放计算资源完成");
#endif
		EstimateStateDataProc(pMainWnd, sContent);
		m_nThreadNum--;
		SemOff(hSem);
//add by wangheng 2017/12/12
PRStateEstimateCalculateDispatch(AfxGetMainWnd(),g_pPRBlock);
		
	}
	else
	{
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL );
		SendMessageToWindow(pMainWnd, "获取状态互斥锁错误 Error=%s", lpMsgBuf);
		LocalFree( lpMsgBuf );// Free the buffer.
	}
}

void PRStateEstimateCalculateDispatch(CWnd* pMainWnd, tagPRBlock* pPRBlock)
{
	register int	i;
	if (m_nThreadNum < g_nThreadNum)
	{
		HANDLE hSem = SemOn(g_lpszGCPRStateEstimateSemaphore, 1000);
		if (hSem != INVALID_HANDLE_VALUE)
		{
			int	nEstimateState = -1;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATE]; i++)
			{
				if (!pPRBlock->m_FStateArray[i].bEstimated)
				{
					nEstimateState = i;
					pPRBlock->m_FStateArray[i].bEstimated = 1;
					break;
				}
			}

			m_nThreadNum++;
			if (nEstimateState >= 0)
			{
				SendMessageToWindow(pMainWnd, "    开始 %d 状态评估", nEstimateState);
				SendNetworkData(g_szRemoteAddr, g_nRemotePort, FormStateEstimateJsonString(nEstimateState).c_str());
			}
			else
			{
				SendMessageToWindow(pMainWnd, "    当前无待状态评估");
			}
			SemOff(hSem);
		}
		else
		{
			LPVOID lpMsgBuf;
			FormatMessage( 
				FORMAT_MESSAGE_ALLOCATE_BUFFER | 
				FORMAT_MESSAGE_FROM_SYSTEM | 
				FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL,
				GetLastError(),
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
				(LPTSTR) &lpMsgBuf,
				0,
				NULL );
			// Process any inserts in lpMsgBuf.
			// ...
			// Display the string.
			Log(g_lpszLogFile, "获取状态互斥锁错误 Error=%s\n", lpMsgBuf);
			PrintMessage("获取状态互斥锁错误 Error=%s", lpMsgBuf);
			LocalFree( lpMsgBuf );// Free the buffer.
		}
	}
	else
	{
		SendMessageToWindow(pMainWnd, "    当前无空闲计算线程[%d %d]", m_nThreadNum, g_nThreadNum);
	}
}