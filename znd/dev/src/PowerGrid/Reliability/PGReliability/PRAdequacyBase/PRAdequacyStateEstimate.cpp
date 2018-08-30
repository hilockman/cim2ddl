#include <io.h>
#include <process.h>
#include "PRAdequacyStateEstimate.h"
#include "../../../../Common/TinyXML/tinyxmlglobal.h"

#define	DoPRELmtLog	1
#define	NoPRELmtLog	0

#define	DoUPFCAdjustRated	1
#define	NoUPFCAdjustRated	0

extern	HANDLE	SemOn(const char* lpszSemKey, const int nMillionSecond);
extern	void	SemOff(HANDLE hSem);
extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;
	const	double	g_fOvlmtAdjThreshold=0.1;

	CPRAdequacyStateEstimate::CPRAdequacyStateEstimate(void)
	{
		m_nIslandNum=0;
		if (!m_fMatZSysArray.empty())	m_fMatZSysArray.clear();
		if (!m_fMatZFltArray.empty())	m_fMatZFltArray.clear();
	}

	CPRAdequacyStateEstimate::~CPRAdequacyStateEstimate(void)
	{
		if (!m_fMatZSysArray.empty())	m_fMatZSysArray.clear();
		if (!m_fMatZFltArray.empty())	m_fMatZFltArray.clear();
	}

	//	对UPFC越限支路消限
	void	CPRAdequacyStateEstimate::UPFCInitial(tagPRBlock* pPRBlock,
		const double fDc2AcFactor,
		const int nFState,
		const unsigned char bLTFault,
		const unsigned char bAuxLoadAdjust,
		const unsigned char bGenEOvl,
		const unsigned char bLineEOvl,
		double& fLoadCut)
	{
		unsigned char	bUPFCELimit;
		int				nUpfc;
		double fOLmtP = 0;

		if (!bLineEOvl)
			return;

		bUPFCELimit = 0;
		for (nUpfc=0; nUpfc<pPRBlock->m_nRecordNum[PR_UPFC]; nUpfc++)
		{
			pPRBlock->m_UPFCArray[nUpfc].fPControl=0;
			pPRBlock->m_UPFCArray[nUpfc].fLinePse=0;

			if (pPRBlock->m_UPFCArray[nUpfc].bOutage)
				continue;
			if (pPRBlock->m_UPFCArray[nUpfc].nACLine < 0)
				continue;
			if (pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].bOutage)
				continue;

			if (fabs(fDc2AcFactor*pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fPfPi) > pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fRated+pPRBlock->m_UPFCArray[nUpfc].fCapacity)
			{
				bUPFCELimit=1;
				break;
			}
		}
		if (!bUPFCELimit)
			return;

		m_NetFlt.PRDCFlow(pPRBlock, UPFC_MODE_NO);
		if (bLTFault)
			m_NetFlt.PRDCMatZ(pPRBlock, 0, m_fMatZFltArray);
		m_PROvLmtAd.InitAdjustParameter(pPRBlock);

		for (nUpfc=0; nUpfc<pPRBlock->m_nRecordNum[PR_UPFC]; nUpfc++)
		{
			if (pPRBlock->m_UPFCArray[nUpfc].bOutage)
				continue;
			if (pPRBlock->m_UPFCArray[nUpfc].nACLine < 0)
				continue;
			if (pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].bOutage)
				continue;

			if (fabs(fDc2AcFactor*pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fPfPi) > pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fRated+pPRBlock->m_UPFCArray[nUpfc].fCapacity)
			{
				fOLmtP=(pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fPfPi > 0) ?
					(fDc2AcFactor*pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fPfPi-pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fRated-pPRBlock->m_UPFCArray[nUpfc].fCapacity) :
				(fDc2AcFactor*pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fPfPi+pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fRated+pPRBlock->m_UPFCArray[nUpfc].fCapacity);

				Log(g_lpszLogFile, "        UPFCInitial[%d]    含UPFC线路越限 = %s UPFC PFlow=%f Rated=%f Capacity=%f 调整功率=%f\n", nFState, pPRBlock->m_UPFCArray[nUpfc].szName,
					fDc2AcFactor*pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fPfPi, pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fRated, pPRBlock->m_UPFCArray[nUpfc].fCapacity, fOLmtP);

				// 			if (pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLDEV)-1)
				// 			{
				// 				memset(&pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]], 0, sizeof(tagPRFStateOvlDev));
				// 				pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
				// 				pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nFStateNo=nFState;
				// 				pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nDevTyp=PR_ACLINE;
				// 				pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nDevIdx=pPRBlock->m_UPFCArray[nUpfc].nACLine;
				// 				pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].fOvLmtP=(float)pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fPfPi;
				// 				pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].fRated=pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fRated;
				// 				pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]++;
				// 			}
				// 			else
				// 				Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLDEV));

				pPRBlock->m_FStateArray[nFState].nELResult=m_PROvLmtAd.AdjustLineOverLimit(pPRBlock, bGenEOvl, 0, bAuxLoadAdjust, 0, 0, nFState, pPRBlock->m_UPFCArray[nUpfc].nACLine, 1.001*fOLmtP, fLoadCut, m_fMatZFltArray);
			}
		}
	}

	void CPRAdequacyStateEstimate::UPFCControl(tagPRBlock* pPRBlock, const double fDc2AcFactor)
	{
		register int	i;
		unsigned char	bHasUPFC;
		double	fSign;

		bHasUPFC=0;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_UPFC]; i++)
		{
			if (pPRBlock->m_UPFCArray[i].bOutage)
				continue;
			if (pPRBlock->m_UPFCArray[i].nACLine < 0)
				continue;
			if (pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].bOutage)
				continue;

			bHasUPFC = 1;
			break;
		}
		if (!bHasUPFC)
			return;

		m_NetFlt.PRDCFlow(pPRBlock, UPFC_MODE_NO);	//	计算无UPFC初态
		for (i=0; i<pPRBlock->m_nRecordNum[PR_UPFC]; i++)
		{
			pPRBlock->m_UPFCArray[i].fPControl=0;
			pPRBlock->m_UPFCArray[i].fLinePse=0;

			if (pPRBlock->m_UPFCArray[i].bOutage)
				continue;
			if (pPRBlock->m_UPFCArray[i].nACLine < 0)
				continue;
			if (pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].bOutage)
				continue;
			fSign = (fabs(pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].fPfPi) > FLT_MIN) ? pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].fPfPi/fabs(pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].fPfPi) : 1;

			//	设置UPFC控制参数，包括PSeries和PControl
			if (pPRBlock->m_UPFCArray[i].nSeriesBus == pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].nIBus)	//	线路I侧是串联侧
				pPRBlock->m_UPFCArray[i].fLinePse = -pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].fPfPi;
			else
				pPRBlock->m_UPFCArray[i].fLinePse =  pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].fPfPi;

			pPRBlock->m_UPFCArray[i].fPControl = (fabs(fDc2AcFactor*pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].fPfPi) > pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].fRated) ?
				fSign*(fabs(fDc2AcFactor*pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].fPfPi)-pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].fRated) : 0;

			if (fabs(pPRBlock->m_UPFCArray[i].fPControl) > pPRBlock->m_UPFCArray[i].fCapacity)
				pPRBlock->m_UPFCArray[i].fPControl = fSign*pPRBlock->m_UPFCArray[i].fCapacity;

			//#ifdef _DEBUG
			//if (fabs(pPRBlock->m_UPFCArray[i].fPControl) > FLT_MIN)
			Log(g_lpszLogFile, "            UPFCControl    【%s】UPFC状态初始化  UPFC控制参数 PFlow=%f Rated=%f PControl=%f\n", pPRBlock->m_UPFCArray[i].szName,
				pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].fPfPi*fDc2AcFactor,
				pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].fRated,
				pPRBlock->m_UPFCArray[i].fPControl);
			//#endif // _DEBUG
		}
	}

	//	检查越限并返回最大的越限设备
	int	CPRAdequacyStateEstimate::CheckFState(tagPRBlock* pPRBlock,
		const double fDC2ACRatio,
		const int nRadial,
		const int nFState,
		const unsigned char bOvLmtLog,
		const unsigned char bLineEOvl,
		const unsigned char bTranEOvl,
		const unsigned char bUPFCAdjustRC,
		int& nOLmtLine,
		int& nOLmtTran,
		double& fOLmtP)
	{
		unsigned char	bHasOverLmt;
		double			fMaxOvLmt;
		int				nDev;

		nOLmtLine = nOLmtTran = -1;
		fOLmtP = 0;
		fMaxOvLmt=0;
		bHasOverLmt=0;

		for (nDev=pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]-1; nDev>=0; nDev--)
		{
			if (pPRBlock->m_FStateOvlDevArray[nDev].nFStateNo != nFState)
				break;

			switch (pPRBlock->m_FStateOvlDevArray[nDev].nDevTyp)
			{
			case	PR_ACLINE:
				pPRBlock->m_FStateOvlDevArray[nDev].fAdLmtP=(float)pPRBlock->m_ACLineArray[pPRBlock->m_FStateOvlDevArray[nDev].nDevIdx].fPfPi;
				break;
			case	PR_WIND:
				pPRBlock->m_FStateOvlDevArray[nDev].fAdLmtP=(float)pPRBlock->m_WindArray[pPRBlock->m_FStateOvlDevArray[nDev].nDevIdx].fPfPi;
				break;
			}
		}

		if (bLineEOvl)
		{
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
			{
				if (pPRBlock->m_ACLineArray[nDev].bOutage)
					continue;
				if (pPRBlock->m_ACLineArray[nDev].fRated <= FLT_MIN)
					continue;

				if (nRadial == 0)
				{
					if (pPRBlock->m_ACLineArray[nDev].nIRadial != nRadial || pPRBlock->m_ACLineArray[nDev].nZRadial != nRadial)
						continue;
				}
				else
				{
					if (pPRBlock->m_ACLineArray[nDev].nIRadial != nRadial && pPRBlock->m_ACLineArray[nDev].nZRadial != nRadial)
						continue;
				}

				if (pPRBlock->m_ACLineArray[nDev].nUPFCIndex < 0)
				{
					if (fabs(fDC2ACRatio*pPRBlock->m_ACLineArray[nDev].fPfPi) > pPRBlock->m_ACLineArray[nDev].fRated+0.1)
					{
						bHasOverLmt=1;
						fOLmtP=(pPRBlock->m_ACLineArray[nDev].fPfPi > 0) ? (fDC2ACRatio*pPRBlock->m_ACLineArray[nDev].fPfPi-pPRBlock->m_ACLineArray[nDev].fRated) : (fDC2ACRatio*pPRBlock->m_ACLineArray[nDev].fPfPi+pPRBlock->m_ACLineArray[nDev].fRated);
						if (fabs(fOLmtP) > fabs(fMaxOvLmt) && m_bLineAdjustable[nDev] != PRFState_AdResult_Unadjustable)
						{
							fMaxOvLmt=fOLmtP;
							nOLmtLine=nDev;
							nOLmtTran=-1;
						}

						if (bOvLmtLog)
						{
							if (pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLDEV)-1)
							{
								memset(&pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]], 0, sizeof(tagPRFStateOvlDev));
								pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
								pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nFStateNo=nFState;
								pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nDevTyp=PR_ACLINE;
								pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nDevIdx=nDev;
								pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].fOvLmtP=(float)pPRBlock->m_ACLineArray[nDev].fPfPi;
								pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].fRated=pPRBlock->m_ACLineArray[nDev].fRated;
								pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]++;
							}
							else
								Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLDEV));
						}
					}
				}
				else
				{
					if (bUPFCAdjustRC)
					{
						if (fabs(fDC2ACRatio*pPRBlock->m_ACLineArray[nDev].fPfPi) > pPRBlock->m_ACLineArray[nDev].fRated+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fCapacity)
						{
#ifdef _DEBUG
							Log(g_lpszLogFile, "        CheckFState[%d] 含UPFC线路判断限值 = %s %f\n", nFState, pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].szName, pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fCapacity);
#endif // _DEBUG
							bHasOverLmt=1;
							fOLmtP=(pPRBlock->m_ACLineArray[nDev].fPfPi > 0) ?
								(fDC2ACRatio*pPRBlock->m_ACLineArray[nDev].fPfPi-pPRBlock->m_ACLineArray[nDev].fRated-pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fCapacity)
								:
							(fDC2ACRatio*pPRBlock->m_ACLineArray[nDev].fPfPi+pPRBlock->m_ACLineArray[nDev].fRated+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fCapacity);
							if (fabs(fOLmtP) > fabs(fMaxOvLmt) && m_bLineAdjustable[nDev] != PRFState_AdResult_Unadjustable)
							{
								fMaxOvLmt=fOLmtP;
								nOLmtLine=nDev;
								nOLmtTran=-1;
							}

							if (bOvLmtLog)
							{
								if (pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLDEV)-1)
								{
									memset(&pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]], 0, sizeof(tagPRFStateOvlDev));
									pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
									pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nFStateNo=nFState;
									pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nDevTyp=PR_ACLINE;
									pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nDevIdx=nDev;
									pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].fOvLmtP=(float)pPRBlock->m_ACLineArray[nDev].fPfPi;
									pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].fRated=(pPRBlock->m_ACLineArray[nDev].fRated+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fCapacity);
									pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]++;
								}
								else
									Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLDEV));
							}
						}
					}
					else
					{
						if (fabs(fDC2ACRatio*pPRBlock->m_ACLineArray[nDev].fPfPi) > pPRBlock->m_ACLineArray[nDev].fRated+0.1)
						{
							Log(g_lpszLogFile, "        CheckFState[%d] 含UPFC线路判断越限 = %s UPFC ControlP=%f SeriesP=%f Pi=%f Rated=%f\n", nFState, pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].szName,
								pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl,
								pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse,
								fDC2ACRatio*pPRBlock->m_ACLineArray[nDev].fPfPi, pPRBlock->m_ACLineArray[nDev].fRated);

							// 						bHasOverLmt=1;
							// 						fOLmtP=(pPRBlock->m_ACLineArray[nDev].fPfPi > 0) ?
							// 							(fDC2ACRatio*pPRBlock->m_ACLineArray[nDev].fPfPi-pPRBlock->m_ACLineArray[nDev].fRated) :
							// 						(fDC2ACRatio*pPRBlock->m_ACLineArray[nDev].fPfPi+pPRBlock->m_ACLineArray[nDev].fRated);
							// 						if (fabs(fOLmtP) > fabs(fMaxOvLmt) && m_bLineAdjustable[nDev] != PRFState_AdResult_Unadjustable)
							// 						{
							// 							fMaxOvLmt=fOLmtP;
							// 							nOLmtLine=nDev;
							// 							nOLmtTran=-1;
							// 						}

							if (bOvLmtLog)
							{
								if (pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLDEV)-1)
								{
									memset(&pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]], 0, sizeof(tagPRFStateOvlDev));
									pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
									pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nFStateNo=nFState;
									pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nDevTyp=PR_ACLINE;
									pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nDevIdx=nDev;
									pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].fOvLmtP=(float)pPRBlock->m_ACLineArray[nDev].fPfPi;
									pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].fRated=pPRBlock->m_ACLineArray[nDev].fRated;
									pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]++;
								}
								else
									Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLDEV));
							}
						}
					}
				}
			}
		}
		if (bTranEOvl)
		{
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
			{
				if (pPRBlock->m_WindArray[nDev].bOutage)
					continue;
				if (pPRBlock->m_WindArray[nDev].fRated <= FLT_MIN)
					continue;
				if (pPRBlock->m_WindArray[nDev].bGenTran)	//	发电厂升压变不消限。
					continue;

				if (nRadial == 0)
				{
					if (pPRBlock->m_WindArray[nDev].nIRadial != nRadial || pPRBlock->m_WindArray[nDev].nZRadial != nRadial)
						continue;
				}
				else
				{
					if (pPRBlock->m_WindArray[nDev].nIRadial != nRadial && pPRBlock->m_WindArray[nDev].nZRadial != nRadial)
						continue;
				}

				if (fabs(fDC2ACRatio*pPRBlock->m_WindArray[nDev].fPfPi) > pPRBlock->m_WindArray[nDev].fRated+0.1)
				{
					bHasOverLmt=1;
					fOLmtP=(pPRBlock->m_WindArray[nDev].fPfPi > 0)	? (fDC2ACRatio*pPRBlock->m_WindArray[nDev].fPfPi-pPRBlock->m_WindArray[nDev].fRated) : (fDC2ACRatio*pPRBlock->m_WindArray[nDev].fPfPi+pPRBlock->m_WindArray[nDev].fRated);
					if (fabs(fOLmtP) > fabs(fMaxOvLmt) && m_bTranAdjustable[nDev] != PRFState_AdResult_Unadjustable)
					{
						fMaxOvLmt=fOLmtP;
						nOLmtLine=-1;
						nOLmtTran=nDev;
					}

					if (bOvLmtLog)
					{
						if (pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLDEV)-1)
						{
							memset(&pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]], 0, sizeof(tagPRFStateOvlDev));
							pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
							pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nFStateNo=nFState;
							pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nDevTyp=PR_WIND;
							pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].nDevIdx=nDev;
							pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].fOvLmtP=(float)pPRBlock->m_WindArray[nDev].fPfPi;
							pPRBlock->m_FStateOvlDevArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]].fRated=pPRBlock->m_WindArray[nDev].fRated;
							pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]++;
						}
						else
							Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLDEV));
					}
				}
			}
		}

		fOLmtP=fMaxOvLmt;
		//if (fabs(fOLmtP) < g_fOvlmtAdjThreshold)
		//	bHasOverLmt=0;

		return bHasOverLmt;
	}

	void CPRAdequacyStateEstimate::AdjustRadial(tagPRBlock* pPRBlock, const int nFState, const int nRadial, const double fDC2ACRatio, const unsigned char bLineEOvl, const unsigned char bTranEOvl)
	{
		register int	i;
		int				nOLmtLine, nOLmtTran, nAdjustNum;
		unsigned char	bHasOverLmt;
		double			fOLmtP, fLoadCut;

		m_NetFlt.PRDCFlow(pPRBlock, UPFC_MODE_NO, nRadial);
		m_NetFlt.PRDCMatZ(pPRBlock, nRadial, m_fMatZFltArray);
		bHasOverLmt=CheckFState(pPRBlock, fDC2ACRatio, nRadial, nFState, DoPRELmtLog, bLineEOvl, bTranEOvl, NoUPFCAdjustRated, nOLmtLine, nOLmtTran, fOLmtP);
		if (bHasOverLmt)
		{
			fLoadCut=0;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
				m_bLineAdjustable[i]=PRFState_AdResult_Unknown;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
				m_bTranAdjustable[i]=PRFState_AdResult_Unknown;
#ifdef	_DEBUG
			Log(g_lpszLogFile, "    辐射网 [%d] 存在潮流越限\n", nRadial);
#endif

			nAdjustNum=0;
			while (bHasOverLmt && nAdjustNum < g_nConstMaxAdjustTimes/2)
			{
				if (nOLmtLine >= 0)
				{
					pPRBlock->m_FStateArray[nFState].nELResult=m_PROvLmtAd.AdjustRadialLineOverLimit(pPRBlock, nRadial, nFState, nOLmtLine, 1.0001*fOLmtP, fLoadCut, m_fMatZFltArray);
				}
				else if (nOLmtTran >= 0)
				{
					pPRBlock->m_FStateArray[nFState].nELResult=m_PROvLmtAd.AdjustRadialTranOverLimit(pPRBlock, nRadial, nFState, nOLmtTran, 1.0001*fOLmtP, fLoadCut, m_fMatZFltArray);
				}
				nAdjustNum++;

				m_NetFlt.PRDCFlow(pPRBlock, UPFC_MODE_NO, nRadial);
				bHasOverLmt=CheckFState(pPRBlock, fDC2ACRatio, nRadial, nFState, NoPRELmtLog, bLineEOvl, bTranEOvl, NoUPFCAdjustRated, nOLmtLine, nOLmtTran, fOLmtP);
			}

#ifdef	_DEBUG
			if (bHasOverLmt)
				Log(g_lpszLogFile, "    State----------辐射网 [%d] 存在潮流越限[%d] [%d] [%f]\n", nRadial, nOLmtLine, nOLmtTran, fOLmtP);
#endif

#ifdef	_DEBUG
			Log(g_lpszLogFile, "    辐射网调整次数=%d\n", nAdjustNum);
#endif
			m_fMatZFltArray.assign(m_fMatZSysArray.begin(), m_fMatZSysArray.end());
			if (fabs(fLoadCut) > FLT_MIN)
			{
#ifdef	_DEBUG
				Log(g_lpszLogFile, "        辐射网调整负荷=%.3f\n", fLoadCut);
#endif
				pPRBlock->m_ACBusArray[pPRBlock->m_RadialArray[nRadial].nRingBoundBus].fAdjRadP += fLoadCut;
			}
		}
	}

	void CPRAdequacyStateEstimate::AdjustSystem(tagPRBlock* pPRBlock,
		const int nFState,
		const double fDC2ACRatio,
		const unsigned char bLTFault,
		const unsigned char bLineEOvl,
		const unsigned char bTranEOvl,
		const unsigned char bGenEOvl,
		const unsigned char bUPFCEOvl,
		const unsigned char bAuxLoadAdjust,
		const unsigned char bUPFCAdjustRC)
	{
		register int	i;
		unsigned char	bExist, bCheckGenAdjDirection;
		int				nOLmtLine, nOLmtTran, nAdjustNum;
		unsigned char	bHasOverLmt;
		double			fOLmtP, fLoadCut;
		std::vector<int>	nOLmtLineArray;	//	用于防止线路多次消限
		std::vector<int>	nOLmtTranArray;	//	用于防止变压器多次消限

		nOLmtLineArray.clear();
		nOLmtTranArray.clear();

		// #ifdef	_DEBUG
		// 	Log(g_lpszLogFile, "    [%d]AdjustSystem    LTFault=%d\n", nFState, bLTFault);
		// #endif

		fLoadCut=0;
		pPRBlock->m_FStateArray[nFState].bOverLimit = 0;

		if (bUPFCAdjustRC)
		{
			m_NetFlt.PRDCFlow(pPRBlock, UPFC_MODE_NO);
		}
		else
		{
			//UPFCInitial(pPRBlock, fDC2ACRatio, nFState, bLTFault, bGenEOvl, bAuxLoadAdjust, bLineEOvl, fLoadCut);	//	用于消限
			UPFCControl(pPRBlock, fDC2ACRatio);
			m_NetFlt.PRDCFlow(pPRBlock, UPFC_MODE_UPFC);
		}
		bHasOverLmt=CheckFState(pPRBlock, fDC2ACRatio, 0, nFState, DoPRELmtLog, bLineEOvl, bTranEOvl, bUPFCAdjustRC, nOLmtLine, nOLmtTran, fOLmtP);
		if (bHasOverLmt && (nOLmtLine >= 0 || nOLmtTran >= 0))
		{
			pPRBlock->m_FStateArray[nFState].bOverLimit = 1;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
				m_bLineAdjustable[i]=PRFState_AdResult_Unknown;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
				m_bTranAdjustable[i]=PRFState_AdResult_Unknown;

			if (bLTFault)
				m_NetFlt.PRDCMatZ(pPRBlock, 0, m_fMatZFltArray);
			m_PROvLmtAd.InitAdjustParameter(pPRBlock);

			nAdjustNum=0;
#ifdef	_DEBUG
			Log(g_lpszLogFile, "%d 环网存在潮流越限 :%f  LTFault=%d Line=%d Tran=%d\n", nFState, fOLmtP, bLTFault, nOLmtLine, nOLmtTran);
#endif

			while (bHasOverLmt && nAdjustNum < g_nConstMaxAdjustTimes)
			{
				if (nOLmtLine >= 0)
				{
					bCheckGenAdjDirection = bExist = 0;
					for (i=0; i<(int)nOLmtLineArray.size(); i++)
					{
						if (nOLmtLineArray[i] == nOLmtLine)
						{
							bCheckGenAdjDirection = 1;
							m_bLineAdjustable[nOLmtLine]=PRFState_AdResult_Unadjustable;
							bExist = 1;
							break;
						}
					}
					if (!bExist)
						nOLmtLineArray.push_back(nOLmtLine);

					pPRBlock->m_FStateArray[nFState].nELResult=m_PROvLmtAd.AdjustLineOverLimit(pPRBlock, bGenEOvl, bUPFCEOvl, bAuxLoadAdjust, bUPFCAdjustRC, bCheckGenAdjDirection, nFState, nOLmtLine, 1.001*fOLmtP, fLoadCut, m_fMatZFltArray);
				}
				else if (nOLmtTran >= 0)
				{
					bCheckGenAdjDirection = bExist = 0;
					for (i=0; i<(int)nOLmtTranArray.size(); i++)
					{
						if (nOLmtTranArray[i] == nOLmtTran)
						{
							bCheckGenAdjDirection = 1;
							m_bTranAdjustable[nOLmtTran]=PRFState_AdResult_Unadjustable;
							bExist = 1;
							break;
						}
					}
					if (!bExist)
						nOLmtTranArray.push_back(nOLmtTran);

					pPRBlock->m_FStateArray[nFState].nELResult=m_PROvLmtAd.AdjustTranOverLimit(pPRBlock, bGenEOvl, bUPFCEOvl, bAuxLoadAdjust, bUPFCAdjustRC, bCheckGenAdjDirection, nFState, nOLmtTran, 1.001*fOLmtP, fLoadCut, m_fMatZFltArray);
				}
				else
				{
#ifdef	_DEBUG
					Log(g_lpszLogFile, "                    State[%d], bHasOverLmt=%d 无设备可调 AdjNum = %d 越限=%.2f 切负荷=%.2f\n", nFState, bHasOverLmt, nAdjustNum, fOLmtP, fLoadCut);
#endif
					break;
				}

				nAdjustNum++;

				if (bUPFCAdjustRC)
					m_NetFlt.PRDCFlow(pPRBlock, UPFC_MODE_NO);
				else
					m_NetFlt.PRDCFlow(pPRBlock, UPFC_MODE_UPFC);
				bHasOverLmt=CheckFState(pPRBlock, fDC2ACRatio, 0, nFState, NoPRELmtLog, bLineEOvl, bTranEOvl, bUPFCAdjustRC, nOLmtLine, nOLmtTran, fOLmtP);
#ifdef	_DEBUG
				Log(g_lpszLogFile, "        调整【%d】完成 切负荷=%.3f 越限状态=%d\n", nAdjustNum, fLoadCut, bHasOverLmt);
#endif
			}
#ifdef	_DEBUG
			if (bHasOverLmt)
				Log(g_lpszLogFile, "                    State[%d]----------存在潮流越限[OLmtLine = %d] [OLmtTran = %d] [越限值 = %f] [调整次数 = %d] [切负荷=%.3f] \n", nFState, nOLmtLine, nOLmtTran, fOLmtP, nAdjustNum, fLoadCut);
#endif
			if (bLTFault)
				m_fMatZFltArray.assign(m_fMatZSysArray.begin(), m_fMatZSysArray.end());

#ifdef	_DEBUG
			Log(g_lpszLogFile, "    调整次数=%d 切负荷=%.3f\n", nAdjustNum, fLoadCut);
#endif
		}

		nOLmtLineArray.clear();
		nOLmtTranArray.clear();
	}

	void CPRAdequacyStateEstimate::Zone599Estimate(tagPRBlock* pPRBlock, const int nFState)
	{
		pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_0;

		int		nZone, nNetworkType=PRSystem_NetworkType_2;
		double	fBuffer;

		pPRBlock->m_FStateArray[nFState].fMaxFaultRatio=0;
		pPRBlock->m_FStateArray[nFState].nMaxFaultZone=0;
		for (nZone=0; nZone<pPRBlock->m_nRecordNum[PR_ZONE]; nZone++)
		{
			if (pPRBlock->m_ZoneArray[nZone].fTotLoadP < FLT_MIN)
				continue;

			fBuffer=pPRBlock->m_ZoneArray[nZone].fCutLoadP/pPRBlock->m_ZoneArray[nZone].fTotLoadP;
			if (fBuffer > pPRBlock->m_FStateArray[nFState].fMaxFaultRatio)
			{
				pPRBlock->m_FStateArray[nFState].fMaxFaultRatio=(float)fBuffer;
				pPRBlock->m_FStateArray[nFState].nMaxFaultZone=nZone;
			}
		}
		switch (nNetworkType)
		{
		case	PRSystem_NetworkType_1:		//	区域性电网
			{
				if (pPRBlock->m_FStateArray[nFState].fMaxFaultRatio >= 0.30)																pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_4;
				else if (0.10 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.30)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_3;
				else if (0.07 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.10)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_2;
				else if (0.04 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.07)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_1;
			}
			break;
		case	PRSystem_NetworkType_2:		//	省、自治区电网
			{
				if (pPRBlock->m_System.fSysLoadP >= 20000)
				{
					if (pPRBlock->m_FStateArray[nFState].fMaxFaultRatio >= 0.30)																pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_4;
					else if (0.13 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.30)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_3;
					else if (0.10 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.13)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_2;
					else if (0.05 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.10)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_1;
				}
				else if (5000 <= pPRBlock->m_System.fSysLoadP && pPRBlock->m_System.fSysLoadP < 20000)
				{
					if (pPRBlock->m_FStateArray[nFState].fMaxFaultRatio >= 0.40)																pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_4;
					else if (0.16 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.40)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_3;
					else if (0.12 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.16)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_2;
					else if (0.06 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.12)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_1;
				}
				else if (1000 <= pPRBlock->m_System.fSysLoadP && pPRBlock->m_System.fSysLoadP < 5000)
				{
					if (pPRBlock->m_FStateArray[nFState].fMaxFaultRatio >= 0.50)																pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_3;
					else if (0.20 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.50)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_2;
					else if (0.10 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.20)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_1;
				}
				else if (pPRBlock->m_System.fSysLoadP < 1000)
				{
					if (pPRBlock->m_FStateArray[nFState].fMaxFaultRatio >= 0.40)																pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_2;
					else if (0.25 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.40)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_1;
				}
			}
			break;
		case	PRSystem_NetworkType_3:		//	直辖市电网
			{
				if (pPRBlock->m_FStateArray[nFState].fMaxFaultRatio >= 0.50)																pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_4;
				else if (0.20 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.50)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_3;
				else if (0.10 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.20)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_2;
				else if (0.05 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.10)	pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_1;
			}
			break;
		case	PRSystem_NetworkType_4:		//	省会城市电网
			{
				if (pPRBlock->m_System.fSysLoadP >= 2000 && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio >= 0.60)										pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_4;
				else if (pPRBlock->m_FStateArray[nFState].fMaxFaultRatio >= 0.40)																			pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_3;
				else if (0.20 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.40)					pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_2;
				else if (0.10 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.20)					pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_1;
			}
			break;
		case	PRSystem_NetworkType_5:		//	一般城市电网
			{
				if (pPRBlock->m_System.fSysLoadP >= 2000 && 0.40 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.60)
					pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_3;
				else if (pPRBlock->m_System.fSysLoadP >= 600 && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio >= 0.60)
					pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_3;
				else if (pPRBlock->m_System.fSysLoadP >= 600 && 0.40 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.60)
					pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_2;
				else if (pPRBlock->m_FStateArray[nFState].fMaxFaultRatio >= 0.40)
					pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_2;
				else if (0.20 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.40)
					pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_1;
			}
			break;
		case	PRSystem_NetworkType_6:		//	县级市电网
			{
				if (pPRBlock->m_System.fSysLoadP >= 150 && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio >= 0.60)
					pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_2;
				else if (pPRBlock->m_System.fSysLoadP >= 150 && 0.40 <= pPRBlock->m_FStateArray[nFState].fMaxFaultRatio && pPRBlock->m_FStateArray[nFState].fMaxFaultRatio < 0.60)
					pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_1;
				else if (pPRBlock->m_FStateArray[nFState].fMaxFaultRatio >= 0.40)
					pPRBlock->m_FStateArray[nFState].nFaultGrade=PRFState_FaultGrade_1;
			}
			break;
		}
	}

	void CPRAdequacyStateEstimate::SaveIsland(tagPRBlock* pPRBlock)
	{
		register int	i;

		m_nIslandNum = pPRBlock->m_nRecordNum[PR_ACISLAND];

		m_nBusIslandArray.resize(pPRBlock->m_nRecordNum[PR_ACBUS]);
		m_nLineIslandArray.resize(pPRBlock->m_nRecordNum[PR_ACLINE]);
		m_nTranIslandArray.resize(pPRBlock->m_nRecordNum[PR_WIND]);
		for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
			m_nBusIslandArray[i]=pPRBlock->m_ACBusArray[i].nIsland;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
			m_nLineIslandArray[i]=pPRBlock->m_ACLineArray[i].nIsland;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
			m_nTranIslandArray[i]=pPRBlock->m_WindArray[i].nIsland;
	}

	void CPRAdequacyStateEstimate::LoadIsland(tagPRBlock* pPRBlock)
	{
		register int	i;
		pPRBlock->m_nRecordNum[PR_ACISLAND]=m_nIslandNum;
		for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)	pPRBlock->m_ACBusArray[i].nIsland	=m_nBusIslandArray[i];
		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)	pPRBlock->m_ACLineArray[i].nIsland	=m_nLineIslandArray[i];
		for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)	pPRBlock->m_WindArray[i].nIsland	=m_nTranIslandArray[i];
	}

	void CPRAdequacyStateEstimate::InitAdequacyEstimateState(tagPRBlock* pPRBlock, const int nFState)
	{
		register int	i;
		int		nDevice;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_ZONE]; i++)
			pPRBlock->m_ZoneArray[i].fCutLoadP=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
			pPRBlock->m_ACLineArray[i].bOutage=0;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
			pPRBlock->m_WindArray[i].bOutage=0;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_GENERATOR]; i++)
			pPRBlock->m_GeneratorArray[i].bOutage=0;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_POWERLOAD]; i++)
			pPRBlock->m_PowerLoadArray[i].bOutage=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_CONVERTER]; i++)
			pPRBlock->m_ConverterArray[i].bOutage=0;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_DCLINE]; i++)
			pPRBlock->m_DCLineArray[i].bOutage=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_HVDC]; i++)
			pPRBlock->m_HVDCArray[i].bOutage=0;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_TCSC]; i++)
			pPRBlock->m_TCSCArray[i].bOutage=0;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_UPFC]; i++)
		{
			pPRBlock->m_UPFCArray[i].bOutage=0;
			pPRBlock->m_UPFCArray[i].fPControl=0;
		}

		for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			pPRBlock->m_ACBusArray[i].fAdjGenP = 0;
			pPRBlock->m_ACBusArray[i].fAdjLoadP = 0;
			pPRBlock->m_ACBusArray[i].fAdjRadP = 0;
			pPRBlock->m_ACBusArray[i].fMaxGenP = 0;
			pPRBlock->m_ACBusArray[i].fMinGenP = 0;
			pPRBlock->m_ACBusArray[i].fMinLoadP	=0;

			pPRBlock->m_ACBusArray[i].fPLC=0;
			pPRBlock->m_ACBusArray[i].fEFLC=0;
			pPRBlock->m_ACBusArray[i].fEDLC=0;
			pPRBlock->m_ACBusArray[i].fADLC=0;
			pPRBlock->m_ACBusArray[i].fELC=0;
			pPRBlock->m_ACBusArray[i].fEENS=0;
			pPRBlock->m_ACBusArray[i].fBPECI=0;
			pPRBlock->m_ACBusArray[i].fBPII=0;
			pPRBlock->m_ACBusArray[i].fSI=0;

			pPRBlock->m_ACBusArray[i].nUVOLmtFreq=0;
			pPRBlock->m_ACBusArray[i].nUFOLmtFreq=0;
			pPRBlock->m_ACBusArray[i].nDVOLmtFreq=0;
			pPRBlock->m_ACBusArray[i].nDFOLmtFreq=0;
		}

		for (i=0; i<pPRBlock->m_nRecordNum[PR_GENERATOR]; i++)
		{
			pPRBlock->m_GeneratorArray[i].fP=pPRBlock->m_GeneratorArray[i].fReferenceP;
			pPRBlock->m_GeneratorArray[i].fQ=pPRBlock->m_GeneratorArray[i].fReferenceQ;
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_POWERLOAD]; i++)
		{
			pPRBlock->m_PowerLoadArray[i].fP=pPRBlock->m_PowerLoadArray[i].fReferenceP;
			pPRBlock->m_PowerLoadArray[i].fQ=pPRBlock->m_PowerLoadArray[i].fReferenceQ;
		}

		for (i=0; i<pPRBlock->m_System.nMStateDevNum; i++)
		{
			nDevice=pPRBlock->m_FStateMStateArray[pPRBlock->m_System.nMStateDevNum*pPRBlock->m_FStateArray[nFState].nMSoutIndex+i].nMSDevIdx;
			switch (pPRBlock->m_FStateMStateArray[pPRBlock->m_System.nMStateDevNum*pPRBlock->m_FStateArray[nFState].nMSoutIndex+i].nMSDevType)
			{
			case	PR_GENERATOR:
				pPRBlock->m_GeneratorArray[nDevice].fMSPout=pPRBlock->m_GeneratorArray[i].fP;
				break;
			case	PR_POWERLOAD:
				pPRBlock->m_PowerLoadArray[nDevice].fMSPout=pPRBlock->m_PowerLoadArray[i].fP;
				break;
			case	PR_HVDC:
				pPRBlock->m_HVDCArray[nDevice].fMSPout = (fabs(pPRBlock->m_HVDCArray[nDevice].fPr) < FLT_MIN) ? pPRBlock->m_HVDCArray[nDevice].fDCPower : pPRBlock->m_HVDCArray[nDevice].fPr;
				break;
			}
		}

		if (pPRBlock->m_FStateArray[nFState].nSampleType != PRFState_SamplingMethod_Manual)
		{
			for (i=0; i<pPRBlock->m_System.nMStateDevNum; i++)
			{
				nDevice=pPRBlock->m_FStateMStateArray[pPRBlock->m_System.nMStateDevNum*pPRBlock->m_FStateArray[nFState].nMSoutIndex+i].nMSDevIdx;
				switch (pPRBlock->m_FStateMStateArray[pPRBlock->m_System.nMStateDevNum*pPRBlock->m_FStateArray[nFState].nMSoutIndex+i].nMSDevType)
				{
				case	PR_GENERATOR:
					pPRBlock->m_GeneratorArray[nDevice].fMSPout=pPRBlock->m_FStateMStateArray[pPRBlock->m_System.nMStateDevNum*pPRBlock->m_FStateArray[nFState].nMSoutIndex+i].fStatePout;
					break;
				case	PR_POWERLOAD:
					pPRBlock->m_PowerLoadArray[nDevice].fMSPout=pPRBlock->m_FStateMStateArray[pPRBlock->m_System.nMStateDevNum*pPRBlock->m_FStateArray[nFState].nMSoutIndex+i].fStatePout;
					break;
				case	PR_HVDC:
					pPRBlock->m_HVDCArray[nDevice].fMSPout=pPRBlock->m_FStateMStateArray[pPRBlock->m_System.nMStateDevNum*pPRBlock->m_FStateArray[nFState].nMSoutIndex+i].fStatePout;
					break;
				}
			}
		}

		pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]=0;
		pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]=0;
		pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]=0;

		for (i=0; i<(int)m_bLineAdjustable.size(); i++)
			m_bLineAdjustable[i] = PRFState_AdResult_Unknown;
		for (i=0; i<(int)m_bTranAdjustable.size(); i++)
			m_bTranAdjustable[i] = PRFState_AdResult_Unknown;
	}

	void CPRAdequacyStateEstimate::ExitAdequacyEstimateState(tagPRBlock* pPRBlock, const int nFState)
	{
		register int	i;
		for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			pPRBlock->m_ACBusArray[i].fAdjGenP = 0;
			pPRBlock->m_ACBusArray[i].fAdjLoadP = 0;
			pPRBlock->m_ACBusArray[i].fAdjRadP = 0;
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_UPFC]; i++)
			pPRBlock->m_UPFCArray[i].fPControl = 0;

		LoadIsland(pPRBlock);
	}

	void CPRAdequacyStateEstimate::SysStateEstimate(tagPRBlock* pPRBlock,
		const int nEstimateState,
		const double fAc2DcFactor,
		const double fMinGLRatio,
		const unsigned char bLineEOvl,
		const unsigned char bTranEOvl,
		const unsigned char bGenEOvl,
		const unsigned char bUPFCEOvl,
		const unsigned char bAuxLoadAdjust,
		const unsigned char bEQGenAdjust,
		const unsigned char bEQLoadAdjust,
		const unsigned char bUPFCAdjustRC,
		const char* lpszRResultFileName)
	{
		register int	i;
		int				nDevice, nFDev, nRadial, nIsland;
		unsigned char	bLTFault, bRadialFault;
		int				nCommF;
		unsigned char	nDevStatus;

		InitAdequacyEstimateState(pPRBlock, nEstimateState);

		bLTFault=0;
		bRadialFault=0;

		//////////////////////////////////////////////////////////////////////////
		//	首先发电机故障，完成功率平衡计算
		for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; nFDev++)
		{
			if (pPRBlock->m_FStateFDevArray[nFDev].nFStateNo < nEstimateState)
				continue;
			if (pPRBlock->m_FStateFDevArray[nFDev].nFStateNo > nEstimateState)
				break;

			nDevice=pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx;

			if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_GENERATOR)
				pPRBlock->m_GeneratorArray[nDevice].bOutage=1;
			else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_ACLINE)
			{
				pPRBlock->m_ACLineArray[nDevice].bOutage=1;
				if (pPRBlock->m_ACLineArray[nDevice].nTCSCIndex >= 0)
					pPRBlock->m_TCSCArray[pPRBlock->m_ACLineArray[nDevice].nTCSCIndex].bOutage=1;
				if (pPRBlock->m_ACLineArray[nDevice].nUPFCIndex >= 0)
					pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDevice].nUPFCIndex].bOutage=1;
			}
			else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_WIND)
				pPRBlock->m_WindArray[nDevice].bOutage=1;
			else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_POWERLOAD)
				pPRBlock->m_PowerLoadArray[nDevice].bOutage=1;

			else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_HVDC)
				pPRBlock->m_HVDCArray[nDevice].bOutage=1;
			else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_TCSC)
				pPRBlock->m_TCSCArray[nDevice].bOutage=1;
			else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_UPFC)
				pPRBlock->m_UPFCArray[nDevice].bOutage=1;
			else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_CONVERTER)
				pPRBlock->m_ConverterArray[nDevice].bOutage=1;
			else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_DCLINE)
				pPRBlock->m_DCLineArray[nDevice].bOutage=1;

			if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_ACLINE || pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_WIND)
				bLTFault=1;
		}
		for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_FSTATEMSTATE]; nFDev++)
		{
		}

		CalculateBusPQ(pPRBlock, bAuxLoadAdjust, bEQGenAdjust, bEQLoadAdjust);									//	调整母线发电上下限，并切除发电机功率
		//////////////////////////////////////////////////////////////////////////
		//	岛计算
		if (bLTFault)
		{
			double	fOutageLoad;
			g_PRMemDBInterface.PRMemDBIsland(pPRBlock, 0);
			if (pPRBlock->m_nRecordNum[PR_ACISLAND] != m_nIslandNum)
			{
				pPRBlock->m_FStateArray[nEstimateState].bMIsland=1;
				pPRBlock->m_FStateArray[nEstimateState].fMIInsGen=0;
				pPRBlock->m_FStateArray[nEstimateState].fMICutGen=0;
				pPRBlock->m_FStateArray[nEstimateState].fMIOutLoad=0;

				for (nIsland=1; nIsland<(int)pPRBlock->m_nRecordNum[PR_ACISLAND]; nIsland++)
				{
					if (pPRBlock->m_ACIslandArray[nIsland].bDead)
					{
						for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
						{
							if (pPRBlock->m_ACBusArray[i].nIsland == nIsland && !pPRBlock->m_ACBusArray[i].bDCBus)
							{
								fOutageLoad=pPRBlock->m_ACBusArray[i].fLoadP+pPRBlock->m_ACBusArray[i].fAdjLoadP;
								pPRBlock->m_FStateArray[nEstimateState].fMIOutLoad += (float)fOutageLoad;

								if (pPRBlock->m_ACBusArray[i].nZone >= 0)	pPRBlock->m_ZoneArray[pPRBlock->m_ACBusArray[i].nZone].fCutLoadP += (float)fOutageLoad;

								if (pPRBlock->m_ACBusArray[i].nRadial != 0)
									pPRBlock->m_ACBusArray[pPRBlock->m_RadialArray[pPRBlock->m_ACBusArray[i].nRadial].nRingBoundBus].fAdjRadP -= (float)fOutageLoad;

								if (pPRBlock->m_nRecordNum[PR_FSTATEMISLAND] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEMISLAND)-1)
								{
									memset(&pPRBlock->m_FStateMIslandArray[pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]], 0, sizeof(tagPRFStateMIsland));
									pPRBlock->m_FStateMIslandArray[pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]].nFStateId=pPRBlock->m_FStateArray[nEstimateState].nFStateId;
									pPRBlock->m_FStateMIslandArray[pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]].nFStateNo=nEstimateState;
									pPRBlock->m_FStateMIslandArray[pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]].nOutageBus=i;
									pPRBlock->m_FStateMIslandArray[pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]].fOutageLoadP=(float)fOutageLoad;
									pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]++;
								}
								else
								{
									Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEMISLAND));
								}
							}
						}
					}
				}
#ifdef	_MISLANDDEBUG
				Log(g_lpszLogFile, "        孤岛(BlackOut)损失负荷=%f\n", pPRBlock->m_FStateArray[nEstimateState].fMIOutLoad);
#endif
			}
		}

		//////////////////////////////////////////////////////////////////////////
		//	功率共因
		for (nCommF=0; nCommF<pPRBlock->m_nRecordNum[PR_COMMONFAULT]; nCommF++)
		{
			if (pPRBlock->m_CommonFaultArray[nCommF].nDevIndex < 0)
				continue;
			if (pPRBlock->m_CommonFaultArray[nCommF].nCommonFaultType == PRCommonFault_CommonFaultType_Status)
				continue;
			if (pPRBlock->m_CommonFaultArray[nCommF].nDeviceCommonType != PRCommonFault_DeviceCommonType_Resion)
				continue;

			nDevStatus = 1;
			switch (pPRBlock->m_CommonFaultArray[nCommF].nDevType)
			{
			case	PR_GENERATOR:
				if (pPRBlock->m_GeneratorArray[pPRBlock->m_CommonFaultArray[nCommF].nDevIndex].bOutage)
					nDevStatus &= pPRBlock->m_GeneratorArray[pPRBlock->m_CommonFaultArray[nCommF].nDevIndex].bOutage;
				break;
			case	PR_POWERLOAD:
				if (pPRBlock->m_PowerLoadArray[pPRBlock->m_CommonFaultArray[nCommF].nDevIndex].bOutage)
					nDevStatus &= pPRBlock->m_PowerLoadArray[pPRBlock->m_CommonFaultArray[nCommF].nDevIndex].bOutage;
				break;
			}
			if (!nDevStatus)	//	功率共因，因设备无故障
				continue;

			BalanceCommonFault(pPRBlock, nEstimateState, nCommF);
		}

		//if (pPRBlock->m_System.bAGCMIslandAdjust)
		{
			if (pPRBlock->m_FStateArray[nEstimateState].bMIsland)
				BalanceIsland(pPRBlock, fMinGLRatio, nEstimateState);
		}

		BalanceGenTrip (pPRBlock, nEstimateState, 0.01*pPRBlock->m_System.fSysLoadP);							//	平衡因失去发电机而造成的系统功率不平衡
		BalanceLoadTrip(pPRBlock, nEstimateState, 0.01*pPRBlock->m_System.fSysLoadP);							//	平衡因损失负荷而造成的系统功率不平衡
		if (pPRBlock->m_FStateArray[nEstimateState].nFDevNum > 0 || fabs(pPRBlock->m_FStateArray[nEstimateState].fFLossGen) > 1 || fabs(pPRBlock->m_FStateArray[nEstimateState].fFLossLoad) > 1)
		{
			//////////////////////////////////////////////////////////////////////////
			//	辐射网功率计算
			for (nRadial=0; nRadial<pPRBlock->m_nRecordNum[PR_RADIAL]; nRadial++)
			{
				for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
				{
					if (pPRBlock->m_ACBusArray[i].nRadial != nRadial)
						continue;

					if (fabs(pPRBlock->m_ACBusArray[i].fAdjLoadP) > FLT_MIN)
						pPRBlock->m_ACBusArray[pPRBlock->m_RadialArray[nRadial].nRingBoundBus].fAdjRadP += pPRBlock->m_ACBusArray[i].fAdjLoadP;
				}
			}

			bLTFault=0;
			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; nFDev++)
			{
				if (pPRBlock->m_FStateFDevArray[nFDev].nFStateNo < nEstimateState)
					continue;
				if (pPRBlock->m_FStateFDevArray[nFDev].nFStateNo > nEstimateState)
					break;

				nDevice=pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx;
				if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_ACLINE)
				{
					if (pPRBlock->m_ACLineArray[nDevice].nIRadial != 0 || pPRBlock->m_ACLineArray[nDevice].nZRadial != 0)
					{
						nRadial=(pPRBlock->m_ACLineArray[nDevice].nIRadial != 0) ? pPRBlock->m_ACLineArray[nDevice].nIRadial : pPRBlock->m_ACLineArray[nDevice].nZRadial;
						AdjustRadial(pPRBlock, nEstimateState, nRadial, fAc2DcFactor, bLineEOvl, bTranEOvl);						//	辐射网计算，计算结果反映在环辐网边界点上
					}
					else
					{
						bLTFault=1;
					}
				}
				else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_WIND)
				{
					if (pPRBlock->m_WindArray[nDevice].nIRadial != 0 || pPRBlock->m_WindArray[nDevice].nZRadial != 0)
					{
						nRadial=(pPRBlock->m_WindArray[nDevice].nIRadial != 0) ? pPRBlock->m_WindArray[nDevice].nIRadial : pPRBlock->m_WindArray[nDevice].nZRadial;
						AdjustRadial(pPRBlock, nEstimateState, nRadial, fAc2DcFactor, bLineEOvl, bTranEOvl);						//	辐射网计算，计算结果反映在环辐网边界点上
					}
					else
					{
						bLTFault=1;
					}
				}
			}

			//////////////////////////////////////////////////////////////////////////
			//	环网消限计算
			AdjustSystem(pPRBlock, nEstimateState, fAc2DcFactor, bLTFault, bLineEOvl, bTranEOvl, bGenEOvl, bUPFCEOvl, bAuxLoadAdjust, bUPFCAdjustRC);	//	环网网计算
		}
		Zone599Estimate(pPRBlock, nEstimateState);

		//	统计母线指标
		for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			if (pPRBlock->m_ACBusArray[i].fAdjLoadP < -FLT_MIN)
			{
				pPRBlock->m_ACBusArray[i].fPLC += pPRBlock->m_FStateArray[nEstimateState].fStateProb;
				pPRBlock->m_ACBusArray[i].fEFLC += pPRBlock->m_FStateArray[nEstimateState].nStateNum;

				pPRBlock->m_ACBusArray[i].fELC -= pPRBlock->m_ACBusArray[i].fAdjLoadP;
				pPRBlock->m_ACBusArray[i].fEENS -= pPRBlock->m_ACBusArray[i].fAdjLoadP*pPRBlock->m_FStateArray[nEstimateState].fStateDur;
			}
		}

		ExitAdequacyEstimateState(pPRBlock, nEstimateState);

		SaveAdequacyStateXml(pPRBlock, nEstimateState, lpszRResultFileName);
	}

	void CPRAdequacyStateEstimate::PrepareSysStateEstimate(tagPRBlock* pPRBlock, const unsigned char bUPFCAdjustRC)
	{
		clock_t	dBeg, dEnd;
		int		nDur;
		//////////////////////////////////////////////////////////////////////////
		//	评估初始化
		dBeg=clock();

		m_bLineAdjustable.resize(pPRBlock->m_nRecordNum[PR_ACLINE], PRFState_AdResult_Unknown);
		m_bTranAdjustable.resize(pPRBlock->m_nRecordNum[PR_WIND], PRFState_AdResult_Unknown);
		m_fMatZSysArray.resize(pPRBlock->m_nRecordNum[PR_ACBUS]*pPRBlock->m_nRecordNum[PR_ACBUS]+pPRBlock->m_nRecordNum[PR_ACBUS]+1, 0);
		m_fMatZFltArray.resize(pPRBlock->m_nRecordNum[PR_ACBUS]*pPRBlock->m_nRecordNum[PR_ACBUS]+pPRBlock->m_nRecordNum[PR_ACBUS]+1, 0);

		if (bUPFCAdjustRC)
			m_NetAll.PRDCFlow(pPRBlock, UPFC_MODE_NO);	//	全模型
		else
			m_NetAll.PRDCFlow(pPRBlock, UPFC_MODE_UPFC);	//	全模型

		SaveIsland(pPRBlock);

		m_NetAll.PRDCMatZ(pPRBlock, 0, m_fMatZSysArray);
		m_fMatZFltArray.assign(m_fMatZSysArray.begin(), m_fMatZSysArray.end());

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);

#ifdef	_DEBUG
		Log(g_lpszLogFile, "评估初始化完成，耗时%d毫秒\n", nDur);
#endif
	}

	void CPRAdequacyStateEstimate::PrepareGenStateEstimate(tagPRBlock* pPRBlock)
	{
		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();

		m_NetAll.PRDCFlow(pPRBlock, UPFC_MODE_NO);	//	全模型
		SaveIsland(pPRBlock);

		if (!m_bLineAdjustable.empty())	m_bLineAdjustable.clear();
		if (!m_bTranAdjustable.empty())	m_bTranAdjustable.clear();
		if (!m_fMatZSysArray.empty())	m_fMatZSysArray.clear();
		if (!m_fMatZFltArray.empty())	m_fMatZFltArray.clear();

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);

#ifdef	_DEBUG
		Log(g_lpszLogFile, "评估初始化完成，耗时%d毫秒\n", nDur);
#endif
	}

	void CPRAdequacyStateEstimate::GenStateEstimate(tagPRBlock* pPRBlock, const int nEstimateState, const char* lpszRResultFileName)
	{
		int				nDevice, nFDev;

		InitAdequacyEstimateState(pPRBlock, nEstimateState);

		//////////////////////////////////////////////////////////////////////////
		//	首先发电机故障，完成功率平衡计算
		for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; nFDev++)
		{
			if (pPRBlock->m_FStateFDevArray[nFDev].nFStateNo < nEstimateState)
				continue;
			if (pPRBlock->m_FStateFDevArray[nFDev].nFStateNo > nEstimateState)
				break;

			nDevice=pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx;

			if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_GENERATOR)
				pPRBlock->m_GeneratorArray[nDevice].bOutage=1;
		}
		for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_FSTATEMSTATE]; nFDev++)
		{
		}

		CalculateBusPQ(pPRBlock);																			//	调整母线发电上下限，并切除发电机功率

		BalanceGenTrip (pPRBlock, nEstimateState, 0.01*pPRBlock->m_System.fSysLoadP);							//	平衡因失去发电机而造成的系统功率不平衡
		Zone599Estimate(pPRBlock, nEstimateState);
		for (nDevice=1; nDevice<pPRBlock->m_nRecordNum[PR_ACBUS]; nDevice++)
		{
			if (pPRBlock->m_ACBusArray[nDevice].fAdjLoadP < -FLT_MIN)
			{
				pPRBlock->m_ACBusArray[nDevice].fPLC += pPRBlock->m_FStateArray[nEstimateState].fStateProb;
				pPRBlock->m_ACBusArray[nDevice].fEFLC += pPRBlock->m_FStateArray[nEstimateState].nStateNum;
				pPRBlock->m_ACBusArray[nDevice].fELC -= pPRBlock->m_ACBusArray[nDevice].fAdjLoadP;
				pPRBlock->m_ACBusArray[nDevice].fEENS -= pPRBlock->m_ACBusArray[nDevice].fAdjLoadP*pPRBlock->m_FStateArray[nEstimateState].fStateDur;
			}
		}

		ExitAdequacyEstimateState(pPRBlock, nEstimateState);

		SaveAdequacyStateXml(pPRBlock, nEstimateState, lpszRResultFileName);
	}

	void CPRAdequacyStateEstimate::SaveAdequacyStateXml(tagPRBlock* pPRBlock, const int nEstimateState, const char* lpszResultFileName)
	{
		register int	i;
		char	szValue[MDB_CHARLEN_LONG];

		if (!lpszResultFileName)
			return;
		if (_access(lpszResultFileName, 0) != 0)
			return;

		TiXmlElement*	pSubElement;
		TiXmlElement*	pStateElement= new TiXmlElement(g_PRMemDBInterface.PRGetTableName(PR_FSTATE));

		pStateElement->SetAttribute("ID",														nEstimateState											);
		pStateElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_FDEVNUM),				pPRBlock->m_FStateArray[nEstimateState].nFDevNum		);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_PROBABILITY),		pPRBlock->m_FStateArray[nEstimateState].fStateProb		);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_DURITION),		pPRBlock->m_FStateArray[nEstimateState].fStateDur		);
		pStateElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_STATENUM),				pPRBlock->m_FStateArray[nEstimateState].nStateNum		);

		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_FLOSSGEN),		pPRBlock->m_FStateArray[nEstimateState].fFLossGen		);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_FLOSSLOAD),		pPRBlock->m_FStateArray[nEstimateState].fFLossLoad		);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_FLOSSGENCAP),		pPRBlock->m_FStateArray[nEstimateState].fFLossGenCap	);

		pStateElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_MISLAND),				pPRBlock->m_FStateArray[nEstimateState].bMIsland		);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_MIINSGEN),		pPRBlock->m_FStateArray[nEstimateState].fMIInsGen		);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_MICUTGEN),		pPRBlock->m_FStateArray[nEstimateState].fMICutGen		);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_MICUTLOAD),		pPRBlock->m_FStateArray[nEstimateState].fMIOutLoad		);

		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_AGCINSGEN),		pPRBlock->m_FStateArray[nEstimateState].fAgcInsGen		);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_AGCCUTGEN),		pPRBlock->m_FStateArray[nEstimateState].fAgcCutGen		);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_AGCCUTLOAD),		pPRBlock->m_FStateArray[nEstimateState].fEnsCutLoad		);

		pStateElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_OVERLIMIT),				pPRBlock->m_FStateArray[nEstimateState].bOverLimit		);
		pStateElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_ELCUTLOAD),				pPRBlock->m_FStateArray[nEstimateState].bELCutLoad		);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_ELCUTGEN),		pPRBlock->m_FStateArray[nEstimateState].fELCutGen		);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_ELINSGEN),		pPRBlock->m_FStateArray[nEstimateState].fELInsGen		);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_ELCUTLOAD),		pPRBlock->m_FStateArray[nEstimateState].fELCutLoad		);
		pStateElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_ELRESULT),				pPRBlock->m_FStateArray[nEstimateState].nELResult		);

		pStateElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_MAXFAULTZONE),			pPRBlock->m_FStateArray[nEstimateState].nMaxFaultZone	);
		pStateElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_MAXFAULTRATIO),	pPRBlock->m_FStateArray[nEstimateState].fMaxFaultRatio	);
		pStateElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE, PR_FSTATE_FAULTGRADE),			pPRBlock->m_FStateArray[nEstimateState].nFaultGrade		);

		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; i++)
		{
			if (pPRBlock->m_FStateFDevArray[i].nFStateNo < nEstimateState)
				continue;
			if (pPRBlock->m_FStateFDevArray[i].nFStateNo > nEstimateState)
				break;

			pSubElement= new TiXmlElement(g_PRMemDBInterface.PRGetTableName(PR_FSTATEFDEV));
			pStateElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATEFDEV, PR_FSTATEFDEV_FDEVTYP),		g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_FStateFDevArray[i].nFDevTyp)	);
			switch (pPRBlock->m_FStateFDevArray[i].nFDevTyp)
			{
			case	PR_GENERATOR:
				pSubElement->SetAttribute("DevName",											pPRBlock->m_GeneratorArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].szName);
				break;
			case	PR_POWERLOAD:
				pSubElement->SetAttribute("DevName",											pPRBlock->m_PowerLoadArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].szName);
				break;
			case	PR_ACLINE:
				pSubElement->SetAttribute("DevName",											pPRBlock->m_ACLineArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].szName);
				break;
			case	PR_WIND:
				pSubElement->SetAttribute("DevName",											pPRBlock->m_WindArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].szName);
				break;
			case	PR_HVDC:
				pSubElement->SetAttribute("DevName",											pPRBlock->m_HVDCArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].szName);
				break;
			case	PR_TCSC:
				pSubElement->SetAttribute("DevName",											pPRBlock->m_TCSCArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].szName);
				break;
			case	PR_UPFC:
				pSubElement->SetAttribute("DevName",											pPRBlock->m_UPFCArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].szName);
				break;
			case	PR_CONVERTER:
				pSubElement->SetAttribute("DevName",											pPRBlock->m_ConverterArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].szName);
				break;
			case	PR_DCLINE:
				pSubElement->SetAttribute("DevName",											pPRBlock->m_DCLineArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].szName);
				break;
			}
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]; i++)
		{
			pSubElement= new TiXmlElement(g_PRMemDBInterface.PRGetTableName(PR_FSTATEMISLAND));
			pStateElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE_MISLAND, PR_FSTATEMISLAND_OUTAGEBUS),			pPRBlock->m_FStateMIslandArray[i].nOutageBus	);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATE_MISLAND, PR_FSTATEMISLAND_OUTAGELOADP),	pPRBlock->m_FStateMIslandArray[i].fOutageLoadP	);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]; i++)
		{
			pSubElement= new TiXmlElement(g_PRMemDBInterface.PRGetTableName(PR_FSTATEOVLDEV));
			pStateElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATEOVLDEV, PR_FSTATEOVLDEV_DEVTYP),			g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_FStateOvlDevArray[i].nDevTyp));
			switch (pPRBlock->m_FStateOvlDevArray[i].nDevTyp)
			{
			case	PR_ACLINE:
				pSubElement->SetAttribute("DevName",													pPRBlock->m_ACLineArray[pPRBlock->m_FStateOvlDevArray[i].nDevIdx].szName);
				break;
			case	PR_WIND:
				pSubElement->SetAttribute("DevName",													pPRBlock->m_WindArray[pPRBlock->m_FStateOvlDevArray[i].nDevIdx].szName);
				break;
			}

			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATEOVLDEV, PR_FSTATEOVLDEV_OVLMTP),	pPRBlock->m_FStateOvlDevArray[i].fOvLmtP	);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATEOVLDEV, PR_FSTATEOVLDEV_RATED),		pPRBlock->m_FStateOvlDevArray[i].fRated		);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATEOVLDEV, PR_FSTATEOVLDEV_ADLMTP),	pPRBlock->m_FStateOvlDevArray[i].fAdLmtP	);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]; i++)
		{
			pSubElement= new TiXmlElement(g_PRMemDBInterface.PRGetTableName(PR_FSTATEOVLAD));
			pStateElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATEOVLAD, PR_FSTATEOVLAD_ADJDEVTYP),			g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_FStateOvlAdArray[i].nAdjDevTyp));

			memset(szValue, 0, MDB_CHARLEN_LONG);
			if (pPRBlock->m_FStateOvlAdArray[i].nAdjDevTyp == PR_UPFC)
				g_PRMemDBInterface.PRGetRecordValue(pPRBlock, pPRBlock->m_FStateOvlAdArray[i].nAdjDevTyp, PR_UPFC_NAME, pPRBlock->m_FStateOvlAdArray[i].nAdjDevIdx, szValue);
			else
				g_PRMemDBInterface.PRGetRecordValue(pPRBlock, PR_ACBUS, PR_ACBUS_NAME, pPRBlock->m_FStateOvlAdArray[i].nAdjDevIdx, szValue);
			pSubElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATEOVLAD, PR_FSTATEOVLAD_ADJDEVICE),			szValue);

			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_FSTATEOVLAD, PR_FSTATEOVLAD_ADJVALUE),		pPRBlock->m_FStateOvlAdArray[i].fAdValue	);
		}

		HANDLE hSem = SemOn(g_lpszRResultSemaphore, 20000);
		if (hSem != INVALID_HANDLE_VALUE)
		{
			AppendXmlFile(lpszResultFileName, pStateElement, 1);
			SemOff(hSem);
		}
		else
		{
			// 		LPVOID lpMsgBuf;
			// 		FormatMessage( 
			// 			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			// 			FORMAT_MESSAGE_FROM_SYSTEM | 
			// 			FORMAT_MESSAGE_IGNORE_INSERTS,
			// 			NULL,
			// 			GetLastError(),
			// 			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			// 			(LPTSTR) &lpMsgBuf,
			// 			0,
			// 			NULL 
			// 			);
			// 		Log(g_lpszLogFile, "获取文件互斥锁错误 %d Error=%s\n", nEstimateState, lpMsgBuf);
			// 		LocalFree( lpMsgBuf );
		}

		pStateElement->Clear();
		delete pStateElement;
	}
}
