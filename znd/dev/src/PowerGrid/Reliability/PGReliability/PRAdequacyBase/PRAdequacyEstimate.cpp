#include <process.h>
#include "PRAdequacyEstimate.h"
#include "../../../../../include/ilog.h"
//extern	const	char*	g_lpszLogFile;
//extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface				g_PRMemDBInterface;
	extern	std::vector<tagPRMCSampleState>	g_PRMCSSampleStateArray;
	extern	unsigned int	__stdcall  GenAdequacyEstimateConThreaad(void* lParam);
	extern	unsigned int	__stdcall  SysAdequacyEstimateConThreaad(void* lParam);

	CRITICAL_SECTION CPRAdequacyEstimate::m_csLock;

	CPRAdequacyEstimate::CPRAdequacyEstimate(void)
	{
		InitializeCriticalSection(&CPRAdequacyEstimate::m_csLock);
		m_bEstimating = 0;
	}

	CPRAdequacyEstimate::~CPRAdequacyEstimate(void)
	{
		m_bEstimating = 0;
		DeleteCriticalSection(&CPRAdequacyEstimate::m_csLock);
	}

	void CPRAdequacyEstimate::InitAdequacyEstimate(tagPRBlock* pPRBlock)
	{
		register int	i;

		m_bEstimating = 1;
		//////////////////////////////////////////////////////////////////////////
		//	评估初始化
		pPRBlock->m_System.fPLC		=0;
		pPRBlock->m_System.fEFLC	=0;
		pPRBlock->m_System.fEDLC	=0;
		pPRBlock->m_System.fADLC	=0;
		pPRBlock->m_System.fELC		=0;
		pPRBlock->m_System.fEENS	=0;
		pPRBlock->m_System.fBPECI	=0;
		pPRBlock->m_System.fBPII	=0;
		pPRBlock->m_System.fSI		=0;
		pPRBlock->m_System.fLOLP	=0;
		pPRBlock->m_System.fLOLF	=0;
		pPRBlock->m_System.fLOLE	=0;
		pPRBlock->m_System.nCutLoadState	=0;
		pPRBlock->m_System.fMIslandEENS		=0;
		pPRBlock->m_System.fLossGenEENS		=0;
		pPRBlock->m_System.fERLimitEENS		=0;
		pPRBlock->m_System.fFltGrade0Prob	=0;
		pPRBlock->m_System.fFltGrade1Prob	=0;
		pPRBlock->m_System.fFltGrade2Prob	=0;
		pPRBlock->m_System.fFltGrade3Prob	=0;
		pPRBlock->m_System.fFltGrade4Prob	=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_ZONE]; i++)
			pPRBlock->m_ZoneArray[i].fCutLoadP=0;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATE]; i++)
		{
			pPRBlock->m_FStateArray[i].fFLossGen=0;
			pPRBlock->m_FStateArray[i].fFLossGenCap=0;
			pPRBlock->m_FStateArray[i].fFLossLoad=0;

			pPRBlock->m_FStateArray[i].bMIsland=0;
			pPRBlock->m_FStateArray[i].fMIInsGen=0;
			pPRBlock->m_FStateArray[i].fMICutGen=0;
			pPRBlock->m_FStateArray[i].fMIOutLoad=0;

			pPRBlock->m_FStateArray[i].fAgcInsGen=0;
			pPRBlock->m_FStateArray[i].fAgcCutGen=0;
			pPRBlock->m_FStateArray[i].fEnsCutLoad=0;

			pPRBlock->m_FStateArray[i].bOverLimit=0;
			pPRBlock->m_FStateArray[i].bELCutLoad=0;
			pPRBlock->m_FStateArray[i].fELCutGen=0;
			pPRBlock->m_FStateArray[i].fELInsGen=0;
			pPRBlock->m_FStateArray[i].fELCutLoad=0;
			pPRBlock->m_FStateArray[i].nELResult=PRFState_AdResult_Normal;

			pPRBlock->m_FStateArray[i].nMaxFaultZone = 0;
			pPRBlock->m_FStateArray[i].fMaxFaultRatio = 0;
			pPRBlock->m_FStateArray[i].nFaultGrade = PRFState_FaultGrade_0;

		}
		for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			pPRBlock->m_ACBusArray[i].fPLC	=0;
			pPRBlock->m_ACBusArray[i].fEFLC	=0;
			pPRBlock->m_ACBusArray[i].fEDLC	=0;
			pPRBlock->m_ACBusArray[i].fADLC	=0;
			pPRBlock->m_ACBusArray[i].fELC	=0;
			pPRBlock->m_ACBusArray[i].fEENS	=0;
			pPRBlock->m_ACBusArray[i].fBPECI=0;
			pPRBlock->m_ACBusArray[i].fBPII	=0;
			pPRBlock->m_ACBusArray[i].fSI	=0;

			pPRBlock->m_ACBusArray[i].fAdjGenP	=0;
			pPRBlock->m_ACBusArray[i].fAdjLoadP	=0;
			pPRBlock->m_ACBusArray[i].fAdjRadP	=0;

			pPRBlock->m_ACBusArray[i].fMaxGenP	=0;
			pPRBlock->m_ACBusArray[i].fMinGenP	=0;
			pPRBlock->m_ACBusArray[i].fMinLoadP	=0;
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		{
			pPRBlock->m_ACLineArray[i].nOLmtFreq=0;
			pPRBlock->m_ACLineArray[i].fOLmtValue=0;
			pPRBlock->m_ACLineArray[i].fELmtCutEnergy=0;
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
		{
			pPRBlock->m_WindArray[i].nOLmtFreq=0;
			pPRBlock->m_WindArray[i].fOLmtValue=0;
			pPRBlock->m_WindArray[i].fELmtCutEnergy=0;
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_UPFC]; i++)
		{
			pPRBlock->m_UPFCArray[i].fPControl = 0;
		}

		pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]=0;
		pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]=0;
		pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]=0;
	}

	void CPRAdequacyEstimate::ExitAdequacyEstimate(tagPRBlock* pPRBlock, const double fAc2DcFactor, const char* lpszResultXmlFile)
	{
		register int	i;
		double			fLoadCut;

		g_PRMemDBInterface.PRMaint(pPRBlock);	//	因为调限等数据库记录需要排序

		pPRBlock->m_System.fPLC		=0;
		pPRBlock->m_System.fEFLC	=0;
		pPRBlock->m_System.fEDLC	=0;
		pPRBlock->m_System.fADLC	=0;
		pPRBlock->m_System.fELC		=0;
		pPRBlock->m_System.fEENS	=0;
		pPRBlock->m_System.fBPECI	=0;
		pPRBlock->m_System.fBPII	=0;
		pPRBlock->m_System.fSI		=0;
		pPRBlock->m_System.fLOLP	=0;
		pPRBlock->m_System.fLOLF	=0;
		pPRBlock->m_System.fLOLE	=0;
		pPRBlock->m_System.nCutLoadState	=0;
		pPRBlock->m_System.fMIslandEENS		=0;
		pPRBlock->m_System.fLossGenEENS		=0;
		pPRBlock->m_System.fERLimitEENS		=0;
		pPRBlock->m_System.fFltGrade0Prob	=0;
		pPRBlock->m_System.fFltGrade1Prob	=0;
		pPRBlock->m_System.fFltGrade2Prob	=0;
		pPRBlock->m_System.fFltGrade3Prob	=0;
		pPRBlock->m_System.fFltGrade4Prob	=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATE]; i++)
		{
			fLoadCut=pPRBlock->m_FStateArray[i].fELCutLoad + pPRBlock->m_FStateArray[i].fEnsCutLoad + pPRBlock->m_FStateArray[i].fMIOutLoad;
			if (fLoadCut > FLT_MIN)
			{
				pPRBlock->m_System.fPLC += pPRBlock->m_FStateArray[i].fStateProb;	//	没有问题
				pPRBlock->m_System.fELC += fLoadCut;
				pPRBlock->m_System.fEENS += fLoadCut*pPRBlock->m_FStateArray[i].fStateDur;
				pPRBlock->m_System.fEFLC += pPRBlock->m_FStateArray[i].nStateNum;	//pPRBlock->m_FStateArray[i].nStateNum;

				if (pPRBlock->m_FStateArray[i].fMIOutLoad > FLT_MIN)	pPRBlock->m_System.fMIslandEENS += pPRBlock->m_FStateArray[i].fMIOutLoad*pPRBlock->m_FStateArray[i].fStateDur;
				if (pPRBlock->m_FStateArray[i].fEnsCutLoad > FLT_MIN)	pPRBlock->m_System.fLossGenEENS += pPRBlock->m_FStateArray[i].fEnsCutLoad*pPRBlock->m_FStateArray[i].fStateDur;
				if (pPRBlock->m_FStateArray[i].fELCutLoad > FLT_MIN)	pPRBlock->m_System.fERLimitEENS += pPRBlock->m_FStateArray[i].fELCutLoad*pPRBlock->m_FStateArray[i].fStateDur;
				if (pPRBlock->m_FStateArray[i].fEnsCutLoad > FLT_MIN)
				{
					pPRBlock->m_System.fLOLP += pPRBlock->m_FStateArray[i].fStateProb*pPRBlock->m_FStateArray[i].fStateDur;
					pPRBlock->m_System.fLOLF += pPRBlock->m_FStateArray[i].fStateProb;
					pPRBlock->m_System.fLOLE += pPRBlock->m_FStateArray[i].fStateDur;
				}
			}
			if (pPRBlock->m_FStateArray[i].nFaultGrade == PRFState_FaultGrade_0)		pPRBlock->m_System.fFltGrade0Prob += pPRBlock->m_FStateArray[i].fStateProb;
			else if (pPRBlock->m_FStateArray[i].nFaultGrade == PRFState_FaultGrade_1)	pPRBlock->m_System.fFltGrade1Prob += pPRBlock->m_FStateArray[i].fStateProb;
			else if (pPRBlock->m_FStateArray[i].nFaultGrade == PRFState_FaultGrade_2)	pPRBlock->m_System.fFltGrade2Prob += pPRBlock->m_FStateArray[i].fStateProb;
			else if (pPRBlock->m_FStateArray[i].nFaultGrade == PRFState_FaultGrade_3)	pPRBlock->m_System.fFltGrade3Prob += pPRBlock->m_FStateArray[i].fStateProb;
			else if (pPRBlock->m_FStateArray[i].nFaultGrade == PRFState_FaultGrade_4)	pPRBlock->m_System.fFltGrade4Prob += pPRBlock->m_FStateArray[i].fStateProb;
		}

		if (pPRBlock->m_System.nSampleMethod == PRFState_SamplingMethod_MonteCarlo)
		{
			pPRBlock->m_System.fEFLC=0;
			//////////////////////////////////////////////////////////////////////////
			//	将MCS状态记录更改为临时变量，减少数据库负担
			//for (i=0; i<pPRBlock->m_nRecordNum[PR_MCSAMPLESTATE]; i++)
			//{
			//	pPRBlock->m_MCSampleStateArray[i].bCutLoad=0;
			//	fLoadCut=pPRBlock->m_FStateArray[pPRBlock->m_MCSampleStateArray[i].nFStateNo].fELCutLoad + pPRBlock->m_FStateArray[pPRBlock->m_MCSampleStateArray[i].nFStateNo].fEnsCutLoad + pPRBlock->m_FStateArray[pPRBlock->m_MCSampleStateArray[i].nFStateNo].fMIOutLoad;
			//	if (fLoadCut > FLT_MIN)
			//	{
			//		pPRBlock->m_MCSampleStateArray[i].bCutLoad=1;
			//		pPRBlock->m_System.nCutLoadState++;
			//	}
			//}
			//for (i=0; i<pPRBlock->m_nRecordNum[PR_MCSAMPLESTATE]; i++)
			//{
			//	if (pPRBlock->m_MCSampleStateArray[i].bCutLoad != 0 && pPRBlock->m_MCSampleStateArray[i-1].bCutLoad == 0)
			//		pPRBlock->m_System.fEFLC++;
			//}
			for (i=0; i<(int)g_PRMCSSampleStateArray.size(); i++)
			{
				g_PRMCSSampleStateArray[i].bCutLoad=0;
				fLoadCut=pPRBlock->m_FStateArray[g_PRMCSSampleStateArray[i].nFStateNo].fELCutLoad + pPRBlock->m_FStateArray[g_PRMCSSampleStateArray[i].nFStateNo].fEnsCutLoad + pPRBlock->m_FStateArray[g_PRMCSSampleStateArray[i].nFStateNo].fMIOutLoad;
				if (fLoadCut > FLT_MIN)
				{
					g_PRMCSSampleStateArray[i].bCutLoad=1;
					pPRBlock->m_System.nCutLoadState++;
				}
			}

			for (i=1; i<(int)g_PRMCSSampleStateArray.size(); i++)
			{
				if (g_PRMCSSampleStateArray[i].bCutLoad != 0 && g_PRMCSSampleStateArray[i-1].bCutLoad == 0)
					pPRBlock->m_System.fEFLC++;
			}
			//	将MCS状态记录更改为临时变量，减少数据库负担
			//////////////////////////////////////////////////////////////////////////
		}

		if (pPRBlock->m_System.fMCSSimTime > FLT_MIN)	pPRBlock->m_System.fEFLC = 8760*pPRBlock->m_System.fEFLC/pPRBlock->m_System.fMCSSimTime;
		pPRBlock->m_System.fEDLC = 8760*pPRBlock->m_System.fPLC;
		if (pPRBlock->m_System.fEFLC > FLT_MIN)			pPRBlock->m_System.fADLC = pPRBlock->m_System.fEDLC/pPRBlock->m_System.fEFLC;
		if (pPRBlock->m_System.fMCSSimTime > FLT_MIN)	pPRBlock->m_System.fELC = 8760*pPRBlock->m_System.fELC/pPRBlock->m_System.fMCSSimTime;
		if (pPRBlock->m_System.fMCSSimTime > FLT_MIN)	pPRBlock->m_System.fEENS = 8760*pPRBlock->m_System.fEENS/pPRBlock->m_System.fMCSSimTime;
		if (pPRBlock->m_System.fSysMaxLoadP > FLT_MIN)	pPRBlock->m_System.fBPII = pPRBlock->m_System.fELC/pPRBlock->m_System.fSysMaxLoadP;
		if (pPRBlock->m_System.fSysMaxLoadP > FLT_MIN)	pPRBlock->m_System.fBPECI = pPRBlock->m_System.fEENS/pPRBlock->m_System.fSysMaxLoadP;
		pPRBlock->m_System.fSI = pPRBlock->m_System.fBPECI*60;

		if (pPRBlock->m_System.fMCSSimTime > FLT_MIN)
		{
			pPRBlock->m_System.fMIslandEENS *= 8760/pPRBlock->m_System.fMCSSimTime;
			pPRBlock->m_System.fLossGenEENS *= 8760/pPRBlock->m_System.fMCSSimTime;
			pPRBlock->m_System.fERLimitEENS *= 8760/pPRBlock->m_System.fMCSSimTime;
		}

		for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			if (pPRBlock->m_System.fMCSSimTime > FLT_MIN)	pPRBlock->m_ACBusArray[i].fEFLC = 8760*pPRBlock->m_ACBusArray[i].fEFLC/pPRBlock->m_System.fMCSSimTime;
			pPRBlock->m_ACBusArray[i].fEDLC = 8760*pPRBlock->m_ACBusArray[i].fPLC;
			if (pPRBlock->m_ACBusArray[i].fEFLC > FLT_MIN)	pPRBlock->m_ACBusArray[i].fADLC = pPRBlock->m_ACBusArray[i].fEDLC/pPRBlock->m_ACBusArray[i].fEFLC;
			if (pPRBlock->m_System.fMCSSimTime > FLT_MIN)	pPRBlock->m_ACBusArray[i].fELC = 8760*pPRBlock->m_ACBusArray[i].fELC/pPRBlock->m_System.fMCSSimTime;
			if (pPRBlock->m_System.fMCSSimTime > FLT_MIN)	pPRBlock->m_ACBusArray[i].fEENS = 8760*pPRBlock->m_ACBusArray[i].fEENS/pPRBlock->m_System.fMCSSimTime;
			if (pPRBlock->m_ACBusArray[i].fLoadP > FLT_MIN)	pPRBlock->m_ACBusArray[i].fBPII = pPRBlock->m_ACBusArray[i].fELC/pPRBlock->m_ACBusArray[i].fLoadP;
			if (pPRBlock->m_ACBusArray[i].fLoadP > FLT_MIN)	pPRBlock->m_ACBusArray[i].fBPECI = pPRBlock->m_ACBusArray[i].fEENS/pPRBlock->m_ACBusArray[i].fLoadP;
			pPRBlock->m_ACBusArray[i].fSI = pPRBlock->m_ACBusArray[i].fBPECI*60;
		}

		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]; i++)
		{
			switch (pPRBlock->m_FStateOvlDevArray[i].nDevTyp)
			{
			case	PR_ACLINE:
				pPRBlock->m_ACLineArray[pPRBlock->m_FStateOvlDevArray[i].nDevIdx].nOLmtFreq++;
				pPRBlock->m_ACLineArray[pPRBlock->m_FStateOvlDevArray[i].nDevIdx].fOLmtValue += fabs(fabs(fAc2DcFactor*pPRBlock->m_FStateOvlDevArray[i].fOvLmtP)-pPRBlock->m_FStateOvlDevArray[i].fRated);
				break;
			case	PR_WIND:
				pPRBlock->m_WindArray[pPRBlock->m_FStateOvlDevArray[i].nDevIdx].nOLmtFreq++;
				pPRBlock->m_WindArray[pPRBlock->m_FStateOvlDevArray[i].nDevIdx].fOLmtValue += fabs(fabs(fAc2DcFactor*pPRBlock->m_FStateOvlDevArray[i].fOvLmtP)-pPRBlock->m_FStateOvlDevArray[i].fRated);
				break;
			}
		}

		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		{
			if (pPRBlock->m_ACLineArray[i].nOLmtFreq <= 0)
				continue;

			pPRBlock->m_ACLineArray[i].fOLmtValue /= pPRBlock->m_ACLineArray[i].nOLmtFreq;
			pPRBlock->m_ACLineArray[i].fELmtCutEnergy = ResolveDevELmtCutEnergy(pPRBlock, PR_ACLINE, pPRBlock->m_ACLineArray[i].szName);
		}

		for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
		{
			if (pPRBlock->m_WindArray[i].nOLmtFreq <= 0)
				continue;

			pPRBlock->m_WindArray[i].fOLmtValue /= pPRBlock->m_WindArray[i].nOLmtFreq;
			pPRBlock->m_WindArray[i].fELmtCutEnergy = ResolveDevELmtCutEnergy(pPRBlock, PR_WIND, pPRBlock->m_WindArray[i].szName);
		}

		SaveAdequacyEstimateResult(pPRBlock, lpszResultXmlFile);

		m_bEstimating = 0;
	}

	HANDLE CPRAdequacyEstimate::GenAdequacyEstimate(tagPRBlock* pPRBlock, const unsigned char nMultiThread, const char* lpszResultFileName)	//	基于MCS的发电系统可靠性
	{
	
		if (m_bEstimating)
			return INVALID_HANDLE_VALUE;

		log_info("发电系统充裕度评估: %d\n", nMultiThread);

		char	szRResultFile[260];
		memset(szRResultFile, 0, 260);
		if (!lpszResultFileName)
		{
			// 		char	szTempPath[260];
			// 		GetTempPath(260, szTempPath);
			// 		sprintf(szRResultFile, "%s/%s", szTempPath, g_lpszGenRResultFileName);
		}
		else
			strcpy(szRResultFile, lpszResultFileName);

		unsigned int	nChildThreadID;
		tagAdequacyThreadInfo*	pInfo=(tagAdequacyThreadInfo*)malloc(sizeof(tagAdequacyThreadInfo));
		pInfo->pPRBlock = pPRBlock;
		pInfo->nParentThreadID = GetCurrentThreadId();
		pInfo->nMultiThread = nMultiThread;
		strcpy(pInfo->szResultXmlFile, szRResultFile);
		return (HANDLE)_beginthreadex(NULL, 0, GenAdequacyEstimateConThreaad, (void*)pInfo, 0, &nChildThreadID);
	}

	HANDLE CPRAdequacyEstimate::SysAdequacyEstimate(tagPRBlock* pPRBlock,
		const unsigned char nMultiThread,
		const double fDC2ACRatio,
		const double fMinGLRatio,
		const unsigned char bLineEOvl,
		const unsigned char bTranEOvl,
		const unsigned char bGenEOvl,
		const unsigned char bUPFCEOvl,
		const unsigned char bAuxLoadAdjust,
		const unsigned char	bEQGenAdjust,
		const unsigned char	bEQLoadAdjust,
		const unsigned char bUPFCAdjustRC,
		const char* lpszRResultFileName)
	{
		if (m_bEstimating)
			return INVALID_HANDLE_VALUE;

		char	szRResultFile[260];
		if (!lpszRResultFileName)
		{
			//char	szTempPath[260];
			//GetTempPath(260, szTempPath);
			//sprintf(szRResultFile, "%s/%s", szTempPath, g_lpszSysRResultFileName);
			memset(szRResultFile, 0, 260);
		}
		else
			strcpy(szRResultFile, lpszRResultFileName);

		log_info("发输电系统充裕度评估: %d %f %d %d\n", nMultiThread, fDC2ACRatio, bLineEOvl, bTranEOvl);

		g_PRMemDBInterface.PRMemDBIsland(pPRBlock, 1);

#ifdef _DEBUG
		SaveCompPRParam(pPRBlock);
#endif // _DEBUG

		unsigned int	nChildThreadID;
		tagAdequacyThreadInfo*	pInfo=(tagAdequacyThreadInfo*)malloc(sizeof(tagAdequacyThreadInfo));
		memset(pInfo, 0, sizeof(tagAdequacyThreadInfo));
		pInfo->pPRBlock = pPRBlock;
		pInfo->nParentThreadID = GetCurrentThreadId();
		pInfo->nMultiThread = nMultiThread;
		pInfo->fAC2DCFactor = fDC2ACRatio;
		pInfo->fMinGLRatio = fMinGLRatio;
		pInfo->bLineEOvl = bLineEOvl;
		pInfo->bTranEOvl = bTranEOvl;
		pInfo->bGenEOvl = bGenEOvl;
		pInfo->bUPFCEOvl = bUPFCEOvl;
		pInfo->bAuxLoadAdjust = bAuxLoadAdjust;
		pInfo->bEQGenAdjust = bEQGenAdjust;
		pInfo->bEQLoadAdjust = bEQLoadAdjust;
		pInfo->bUPFCAdjustRC = bUPFCAdjustRC;
		strcpy(pInfo->szResultXmlFile, szRResultFile);

		return (HANDLE)_beginthreadex(NULL, 0, SysAdequacyEstimateConThreaad, (void*)pInfo, 0, &nChildThreadID);
	}
}
