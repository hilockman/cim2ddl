#include <process.h>
#include "../../../../MemDB/PRMemDB/PRMemDB.h"
#include "PRAdequacyEstimate.h"
#include "PRAdequacyStateEstimate.h"

extern	HANDLE	InitSem(const char* lpszSemKey);
extern	HANDLE	SemOn(const char* lpszSemKey, const int nMillionSecond);
extern	void	SemOff(HANDLE hSem);
extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	const	int		g_nProgressStep = 10;
	const	char*	g_lpszAdequacyEstimateStateSemaphore = "AdequacyEstimateStateSemphore";

	CPRAdequacyEstimate		m_PRAdeEstimate;

	void WorkMem2MainMem(tagPRBlock* pMainBlock, tagPRBlock* pWorkBlock, const int nEstimateState)
	{
		register int	i;

		EnterCriticalSection(&CPRAdequacyEstimate::m_csLock);

		pMainBlock->m_FStateArray[nEstimateState].fFLossGen			=pWorkBlock->m_FStateArray[nEstimateState].fFLossGen		;
		pMainBlock->m_FStateArray[nEstimateState].fFLossLoad		=pWorkBlock->m_FStateArray[nEstimateState].fFLossLoad		;
		pMainBlock->m_FStateArray[nEstimateState].fFLossGenCap		=pWorkBlock->m_FStateArray[nEstimateState].fFLossGenCap		;

		pMainBlock->m_FStateArray[nEstimateState].bMIsland			=pWorkBlock->m_FStateArray[nEstimateState].bMIsland			;
		pMainBlock->m_FStateArray[nEstimateState].fMIInsGen			=pWorkBlock->m_FStateArray[nEstimateState].fMIInsGen		;
		pMainBlock->m_FStateArray[nEstimateState].fMICutGen			=pWorkBlock->m_FStateArray[nEstimateState].fMICutGen		;
		pMainBlock->m_FStateArray[nEstimateState].fMIOutLoad		=pWorkBlock->m_FStateArray[nEstimateState].fMIOutLoad		;

		pMainBlock->m_FStateArray[nEstimateState].fAgcInsGen		=pWorkBlock->m_FStateArray[nEstimateState].fAgcCutGen		;
		pMainBlock->m_FStateArray[nEstimateState].fAgcCutGen		=pWorkBlock->m_FStateArray[nEstimateState].fAgcCutGen		;
		pMainBlock->m_FStateArray[nEstimateState].fEnsCutLoad		=pWorkBlock->m_FStateArray[nEstimateState].fEnsCutLoad		;

		pMainBlock->m_FStateArray[nEstimateState].bOverLimit		=pWorkBlock->m_FStateArray[nEstimateState].bOverLimit		;
		pMainBlock->m_FStateArray[nEstimateState].bELCutLoad		=pWorkBlock->m_FStateArray[nEstimateState].bELCutLoad		;
		pMainBlock->m_FStateArray[nEstimateState].fELCutGen			=pWorkBlock->m_FStateArray[nEstimateState].fELCutGen		;
		pMainBlock->m_FStateArray[nEstimateState].fELInsGen			=pWorkBlock->m_FStateArray[nEstimateState].fELInsGen		;
		pMainBlock->m_FStateArray[nEstimateState].fELCutLoad		=pWorkBlock->m_FStateArray[nEstimateState].fELCutLoad		;
		pMainBlock->m_FStateArray[nEstimateState].nELResult			=pWorkBlock->m_FStateArray[nEstimateState].nELResult		;

		pMainBlock->m_FStateArray[nEstimateState].nMaxFaultZone		=pWorkBlock->m_FStateArray[nEstimateState].nMaxFaultZone	;
		pMainBlock->m_FStateArray[nEstimateState].fMaxFaultRatio	=pWorkBlock->m_FStateArray[nEstimateState].fMaxFaultRatio	;
		pMainBlock->m_FStateArray[nEstimateState].nFaultGrade		=pWorkBlock->m_FStateArray[nEstimateState].nFaultGrade		;
		pMainBlock->m_FStateArray[nEstimateState].bEstimated		=1		;

		for (i=0; i<pMainBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			pMainBlock->m_ACBusArray[i].fPLC += pWorkBlock->m_ACBusArray[i].fPLC ;
			pMainBlock->m_ACBusArray[i].fELC += pWorkBlock->m_ACBusArray[i].fELC ;
			pMainBlock->m_ACBusArray[i].fEENS +=pWorkBlock->m_ACBusArray[i].fEENS;
			pMainBlock->m_ACBusArray[i].fEFLC +=pWorkBlock->m_ACBusArray[i].fEFLC;
		}

		for (i=0; i<pWorkBlock->m_nRecordNum[PR_FSTATEMISLAND]; i++)
		{
			if (pMainBlock->m_nRecordNum[PR_FSTATEMISLAND] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEMISLAND)-1)
				memcpy(&pMainBlock->m_FStateMIslandArray[pMainBlock->m_nRecordNum[PR_FSTATEMISLAND]++], &pWorkBlock->m_FStateMIslandArray[i], sizeof(tagPRFStateMIsland));
			else
				Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEMISLAND));
		}
		for (i=0; i<pWorkBlock->m_nRecordNum[PR_FSTATEOVLDEV]; i++)
		{
			if (pMainBlock->m_nRecordNum[PR_FSTATEOVLDEV] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLDEV)-1)
				memcpy(&pMainBlock->m_FStateOvlDevArray[pMainBlock->m_nRecordNum[PR_FSTATEOVLDEV]++], &pWorkBlock->m_FStateOvlDevArray[i], sizeof(tagPRFStateOvlDev));
			else
				Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLDEV));
		}
		for (i=0; i<pWorkBlock->m_nRecordNum[PR_FSTATEOVLAD]; i++)
		{
			if (pMainBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
				memcpy(&pMainBlock->m_FStateOvlAdArray[pMainBlock->m_nRecordNum[PR_FSTATEOVLAD]++], &pWorkBlock->m_FStateOvlAdArray[i], sizeof(tagPRFStateOvlAd));
			else
				Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));
		}

		LeaveCriticalSection(&CPRAdequacyEstimate::m_csLock);
	}

	unsigned int	__stdcall  SysAdequacyEstimateCalThreaad(void* lParam)
	{
		register int	i;
		int		nEstimatePace, nEstimateState;
		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();

		tagAdequacyThreadInfo*	pThreadInfo = (tagAdequacyThreadInfo*)lParam;
		CPRAdequacyStateEstimate* pPREstimate = new CPRAdequacyStateEstimate();
		if (!pPREstimate)
		{
			Log(g_lpszLogFile, "建立发输电系统充裕度评估评估类错误，内存空间可能不够\n");
			return 0;
		}

		const int	nWorkMemID=g_nPRBlockKey+1000+pThreadInfo->nThreadID;

		tagPRBlock*	pPRBlock = pThreadInfo->pPRBlock;
		tagPRBlock*	pPRWorkBlock=(tagPRBlock*)g_PRMemDBInterface.Init_PRBlock(nWorkMemID);
		if (!pPRWorkBlock)
		{
			Log(g_lpszLogFile, "获取PR工作内存库错误\n");
			delete pPREstimate;
			return 0;
		}
		memcpy(pPRWorkBlock, pPRBlock, sizeof(tagPRBlock));
		//Sleep(1000);

		nEstimatePace = 0;
		pPREstimate->PrepareSysStateEstimate(pPRWorkBlock, pThreadInfo->bUPFCAdjustRC);
		while (TRUE)
		{
			nEstimateState = -1;

			HANDLE hSem = SemOn(g_lpszAdequacyEstimateStateSemaphore, 1000);
			if (hSem != INVALID_HANDLE_VALUE)
			{
				for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATE]; i++)
				{
					if (!pPRBlock->m_FStateArray[i].bEstimated)
					{
						nEstimateState = i;
						pPRBlock->m_FStateArray[i].bEstimated = 1;
						break;
					}
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
					NULL 
					);
				// Process any inserts in lpMsgBuf.
				// ...
				// Display the string.
				Log(g_lpszLogFile, "获取状态互斥锁错误 %d Error=%s\n", nEstimateState, lpMsgBuf);
				// Free the buffer.
				LocalFree( lpMsgBuf );
			}

			if (nEstimateState < 0)
				break;

			pPREstimate->SysStateEstimate(pPRWorkBlock,
				nEstimateState,
				pThreadInfo->fAC2DCFactor,
				pThreadInfo->fMinGLRatio,
				pThreadInfo->bLineEOvl,
				pThreadInfo->bTranEOvl,
				pThreadInfo->bGenEOvl,
				pThreadInfo->bUPFCEOvl,
				pThreadInfo->bAuxLoadAdjust,
				pThreadInfo->bEQGenAdjust,
				pThreadInfo->bEQLoadAdjust,
				pThreadInfo->bUPFCAdjustRC,
				pThreadInfo->szResultXmlFile);
			WorkMem2MainMem(pPRBlock, pPRWorkBlock, nEstimateState);

			nEstimatePace++;
			if (nEstimatePace > 0 && nEstimatePace % g_nProgressStep == 0)
				PostThreadMessage(pThreadInfo->nParentThreadID, TM_ESTIMATING, g_nProgressStep, 0);
		}

		if (pPRWorkBlock)
			g_PRMemDBInterface.Exit_PRBlock((char*)pPRWorkBlock, nWorkMemID);
		delete pPREstimate;

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "发输电系统充裕度评估，线程 = %d 完成，耗时 %d 毫秒\n", pThreadInfo->nThreadID, nDur);

		free(pThreadInfo);
		_endthreadex( 0 );

		return 0;
	}

	unsigned int	__stdcall  SysAdequacyEstimateConThreaad(void* lParam)
	{
		register int		i;
		clock_t				dBeg, dEnd;
		int					nDur;
		unsigned int		nChildThreadID;
		std::vector<HANDLE>	hThreadArray;

		dBeg = clock();

		tagAdequacyThreadInfo*	pParentThreadInfo = (tagAdequacyThreadInfo*)lParam;
		tagPRBlock*	pPRBlock = pParentThreadInfo->pPRBlock;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATE]; i++)
			pPRBlock->m_FStateArray[i].bEstimated = 0;

		SYSTEM_INFO sysInfo;
		::GetSystemInfo(&sysInfo);

		int		nThreadNum = 1;
		if (pParentThreadInfo->bMultiThread)
			nThreadNum=(int)sysInfo.dwNumberOfProcessors;

		hThreadArray.resize(nThreadNum);
		for (i=0; i<nThreadNum; i++)
			hThreadArray[i] = INVALID_HANDLE_VALUE;

		HANDLE hEstStateSem = InitSem(g_lpszAdequacyEstimateStateSemaphore);
		HANDLE hEstResultSem = InitSem(g_lpszRResultSemaphore);
		m_PRAdeEstimate.InitAdequacyXmlFile(pParentThreadInfo->szResultXmlFile, "SysAdequacyResult");
		m_PRAdeEstimate.InitAdequacyEstimate(pPRBlock);

		PostThreadMessage(pParentThreadInfo->nParentThreadID, TM_ESTIMATEBEG, pPRBlock->m_nRecordNum[PR_FSTATE], 0);

		for (i=0; i<nThreadNum; i++)
		{
			tagAdequacyThreadInfo*	pInfo=(tagAdequacyThreadInfo*)malloc(sizeof(tagAdequacyThreadInfo));
			memcpy(pInfo, pParentThreadInfo, sizeof(tagAdequacyThreadInfo));
			pInfo->nThreadID = i+1;
			pInfo->pPRBlock = pPRBlock;
			hThreadArray[i] = (HANDLE)_beginthreadex(NULL, 0, SysAdequacyEstimateCalThreaad, (void*)pInfo, 0, &nChildThreadID);
		}

		for (i=0; i<(int)hThreadArray.size(); i++)
		{
			DWORD dwRet=WaitForSingleObject(hThreadArray[i], INFINITE);
			if (dwRet == WAIT_OBJECT_0)
				Log(g_lpszLogFile, "        可靠性评估计算进程[%d]完成\n", i+1);
			else
				Log(g_lpszLogFile, "        可靠性评估计算进程[%d]错误 RetCode = %d\n", i+1, dwRet);
			if (hThreadArray[i] != INVALID_HANDLE_VALUE)
				CloseHandle(hThreadArray[i]);
		}
		hThreadArray.clear();

		m_PRAdeEstimate.ExitAdequacyEstimate(pPRBlock, pParentThreadInfo->fAC2DCFactor, pParentThreadInfo->szResultXmlFile);
		m_PRAdeEstimate.ExitAdequacyXmlFile(pParentThreadInfo->szResultXmlFile, "SysAdequacyResult");

		CloseHandle(hEstResultSem);
		CloseHandle(hEstStateSem);

		PostThreadMessage(pParentThreadInfo->nParentThreadID, TM_ESTIMATEEND, pPRBlock->m_nRecordNum[PR_FSTATE], 0);
		//Sleep(1000);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "发输电系统可靠性评估 完成，耗时 %d 毫秒\n", nDur);

		free(pParentThreadInfo);
		_endthreadex( 0 );

		return 0;
	}

	unsigned int	__stdcall  GenAdequacyEstimateCalThreaad(void* lParam)
	{
		register int	i;
		int		nEstimatePace, nEstimateState;
		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();

		tagAdequacyThreadInfo*	pThreadInfo = (tagAdequacyThreadInfo*)lParam;
		CPRAdequacyStateEstimate*	pPREstimate = new CPRAdequacyStateEstimate();
		if (!pPREstimate)
		{
			Log(g_lpszLogFile, "new GenAdequacyEstimateCalThreaad 错误\n");
			return 0;
		}

		const int	nWorkMemID=g_nPRBlockKey+1000+pThreadInfo->nThreadID;

		tagPRBlock*	pPRBlock = pThreadInfo->pPRBlock;
		tagPRBlock*	pPRWorkBlock=(tagPRBlock*)g_PRMemDBInterface.Init_PRBlock(nWorkMemID);
		if (!pPRWorkBlock)
		{
			Log(g_lpszLogFile, "获取PR工作内存库错误\n");
			return 0;
		}
		memcpy(pPRWorkBlock, pPRBlock, g_PRMemDBInterface.PRGetBlockSize());

		nEstimatePace = 0;
		pPREstimate->PrepareGenStateEstimate(pPRWorkBlock);
		while (TRUE)
		{
			nEstimateState = -1;

			HANDLE hSem = SemOn(g_lpszAdequacyEstimateStateSemaphore, 1000);
			if (hSem != INVALID_HANDLE_VALUE)
			{
				for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATE]; i++)
				{
					if (!pPRBlock->m_FStateArray[i].bEstimated)
					{
						nEstimateState = i;
						pPRBlock->m_FStateArray[i].bEstimated = 1;
						break;
					}
				}
				SemOff(hSem);
			}
			else
			{
				Log(g_lpszLogFile, "获取状态互斥锁错误\n");
			}

			if (nEstimateState < 0)
				break;

			pPREstimate->GenStateEstimate(pPRWorkBlock, nEstimateState, pThreadInfo->szResultXmlFile);
			WorkMem2MainMem(pPRBlock, pPRWorkBlock, nEstimateState);

			nEstimatePace++;
			if (nEstimatePace > 0 && nEstimatePace % g_nProgressStep == 0)
				PostThreadMessage(pThreadInfo->nParentThreadID, TM_ESTIMATING, g_nProgressStep, 0);
		}

		//	将工作内存中计算结果导入基本内存
		if (pPRWorkBlock)
			g_PRMemDBInterface.Exit_PRBlock((char*)pPRWorkBlock, nWorkMemID);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "发电系统充裕度进行进程 %d 完成，耗时 %d 毫秒\n", pThreadInfo->nThreadID, nDur);

		free(pThreadInfo);
		delete pPREstimate;

		_endthreadex(0);

		return 0;
	}

	unsigned int	__stdcall  GenAdequacyEstimateConThreaad(void* lParam)
	{
		register int		i;
		clock_t				dBeg, dEnd;
		int					nDur;
		unsigned int		nChildThreadID;
		std::vector<HANDLE>	hThreadArray;

		dBeg = clock();

		tagAdequacyThreadInfo*	pParentThreadInfo = (tagAdequacyThreadInfo*)lParam;
		tagPRBlock*	pPRBlock = pParentThreadInfo->pPRBlock;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATE]; i++)
			pPRBlock->m_FStateArray[i].bEstimated = 0;

		SYSTEM_INFO sysInfo;
		::GetSystemInfo(&sysInfo);
		int	nThreadNum = 1;
		if (pParentThreadInfo->bMultiThread)
			nThreadNum=(int)sysInfo.dwNumberOfProcessors;

		hThreadArray.resize(nThreadNum);
		for (i=0; i<nThreadNum; i++)
			hThreadArray[i] = INVALID_HANDLE_VALUE;
		HANDLE hEstStateSem = InitSem(g_lpszAdequacyEstimateStateSemaphore);
		HANDLE hEstResultSem = InitSem(g_lpszRResultSemaphore);
		m_PRAdeEstimate.InitAdequacyXmlFile(pParentThreadInfo->szResultXmlFile, "GenAdequacyResult");
		m_PRAdeEstimate.InitAdequacyEstimate(pPRBlock);

		PostThreadMessage(pParentThreadInfo->nParentThreadID, TM_ESTIMATEBEG, pPRBlock->m_nRecordNum[PR_FSTATE], 0);

		for (i=0; i<nThreadNum; i++)
		{
			tagAdequacyThreadInfo*	pInfo=(tagAdequacyThreadInfo*)malloc(sizeof(tagAdequacyThreadInfo));
			memcpy(pInfo, pParentThreadInfo, sizeof(tagAdequacyThreadInfo));
			pInfo->nThreadID = i+1;
			hThreadArray[i] = (HANDLE)_beginthreadex(NULL, 0, &GenAdequacyEstimateCalThreaad, (void*)pInfo, 0, &nChildThreadID);
		}

		for (i=0; i<(int)hThreadArray.size(); i++)
		{
			DWORD dwRet=WaitForSingleObject(hThreadArray[i], INFINITE);

			if (dwRet == WAIT_OBJECT_0)
				Log(g_lpszLogFile, "        发电系统可靠性评估计算进程[%d]完成\n", i+1);
			else
				Log(g_lpszLogFile, "        发电系统可靠性评估计算进程[%d]错误 RetCode = %d\n", i+1, dwRet);

			if (hThreadArray[i] != INVALID_HANDLE_VALUE)
				CloseHandle(hThreadArray[i]);
		}
		hThreadArray.clear();

		m_PRAdeEstimate.ExitAdequacyEstimate(pPRBlock, pParentThreadInfo->fAC2DCFactor, pParentThreadInfo->szResultXmlFile);
		m_PRAdeEstimate.ExitAdequacyXmlFile(pParentThreadInfo->szResultXmlFile, "GenAdequacyResult");

		CloseHandle(hEstResultSem);
		CloseHandle(hEstStateSem);

		PostThreadMessage(pParentThreadInfo->nParentThreadID, TM_ESTIMATEEND, pPRBlock->m_nRecordNum[PR_FSTATE], 0);
		//Sleep(1000);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "发电系统充裕度评估 完成，耗时 %d 毫秒\n", nDur);

		free(pParentThreadInfo);
		_endthreadex( 0 );

		return 0;
	}
}
