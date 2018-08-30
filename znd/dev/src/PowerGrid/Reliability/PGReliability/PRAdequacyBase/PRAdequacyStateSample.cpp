#include <float.h>
#include "PRAdequacyStateSample.h"

extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	CPRAdequacyStateSample::CPRAdequacyStateSample(void)
	{
	}

	CPRAdequacyStateSample::~CPRAdequacyStateSample(void)
	{
	}

	int	 CPRAdequacyStateSample::Sample(tagPRBlock* pPRBlock, const int nSampleObject, const int nSampleMethod, tagBpaPRAdequacySetting* pSetting)
	{
		FormPRSampleObject(pPRBlock, nSampleObject);
		if (pPRBlock->m_nRecordNum[PR_R2STATECOMP] <= 0)
		{
			Log(g_lpszLogFile, "可靠性参数为空\n");
			return 0;
		}

		int	nStateNum=0;
		switch (nSampleMethod)
		{
		case	PRFState_SamplingMethod_StateSample:	//	"状态抽样"
			nStateNum=STSSample(pPRBlock, pSetting->nSTSMaxStateNum);
			break;
		case	PRFState_SamplingMethod_Analytical:		//	"解析法"
			nStateNum=ANASample(pPRBlock, pSetting->nMaxGenFault, pSetting->nMaxBranFault, pSetting->fANAMinStateProb);
			break;
		case	PRFState_SamplingMethod_MonteCarlo:		//	"蒙特卡洛"
			nStateNum = MCSSample(pPRBlock, pSetting->nMCSSimulateTime, pSetting->nMaxGenFault, pSetting->nMaxBranFault, pSetting->fMCSMinStateProb);
			break;
		case	PRFState_SamplingMethod_FastSort:		//	"快速排序",
			nStateNum=FSTSample(pPRBlock, pSetting->fFSTMaxCumuProb, pSetting->nFSTMaxStateNum, pSetting->nMaxGenFault, pSetting->nMaxBranFault, pSetting->fFSTMinStateProb);
			break;
		}

		CommonFState(pPRBlock);
		ManualFState(pPRBlock);

		return nStateNum;
	}

	void CPRAdequacyStateSample::FormPRSampleObject(tagPRBlock* pPRBlock, const int nPRCompObject)
	{
		register int	i;
		int		nDev;
		int		nConverter;

		pPRBlock->m_System.nSampleObject=nPRCompObject;

		pPRBlock->m_nRecordNum[PR_R2STATECOMP]=0;
		pPRBlock->m_nRecordNum[PR_RMSTATECOMP]=0;

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
		{
			pPRBlock->m_GeneratorArray[nDev].bMSModel = 0;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_DEVMSTATE]; i++)
			{
				if (pPRBlock->m_DevMStateArray[i].nType == PR_GENERATOR &&
					stricmp(pPRBlock->m_DevMStateArray[i].szName, pPRBlock->m_GeneratorArray[nDev].szName) == 0)
				{
					pPRBlock->m_GeneratorArray[nDev].bMSModel = 1;
					break;
				}
			}
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_POWERLOAD]; nDev++)
		{
			pPRBlock->m_PowerLoadArray[nDev].bMSModel = 0;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_DEVMSTATE]; i++)
			{
				if (pPRBlock->m_DevMStateArray[i].nType == PR_POWERLOAD &&
					stricmp(pPRBlock->m_DevMStateArray[i].szName, pPRBlock->m_PowerLoadArray[nDev].szName) == 0)
				{
					pPRBlock->m_PowerLoadArray[nDev].bMSModel = 1;
					break;
				}
			}
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
		{
			pPRBlock->m_HVDCArray[nDev].bMSModel = 0;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_DEVMSTATE]; i++)
			{
				if (pPRBlock->m_DevMStateArray[i].nType == PR_HVDC &&
					stricmp(pPRBlock->m_DevMStateArray[i].szName, pPRBlock->m_HVDCArray[nDev].szName) == 0)
				{
					pPRBlock->m_HVDCArray[nDev].bMSModel = 1;
					break;
				}
			}
		}

		if (nPRCompObject == 0 || nPRCompObject == 2)
		{
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
			{
				nConverter = -1;
				for (i=0; i<pPRBlock->m_nRecordNum[PR_CONVERTER]; i++)
				{
					if (stricmp(pPRBlock->m_GeneratorArray[nDev].szName, pPRBlock->m_ConverterArray[i].szName) == 0)
					{
						nConverter = i;
						break;
					}
				}
				if (nConverter >= 0)
					continue;

				if (!pPRBlock->m_GeneratorArray[nDev].bMSModel)
				{
					if (pPRBlock->m_GeneratorArray[nDev].fRerr < FLT_MIN || pPRBlock->m_GeneratorArray[nDev].fTrep < FLT_MIN)
						continue;

					if (pPRBlock->m_nRecordNum[PR_R2STATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_R2STATECOMP)-1)
					{
						memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
						pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_GENERATOR;
						pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
						pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;
					}
					else
						Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_R2STATECOMP));
				}
				else
				{
					if (pPRBlock->m_nRecordNum[PR_RMSTATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_RMSTATECOMP)-1)
					{
						memset(&pPRBlock->m_RMStateCompArray[pPRBlock->m_nRecordNum[PR_RMSTATECOMP]], 0, sizeof(tagPRMStateComp));
						pPRBlock->m_RMStateCompArray[pPRBlock->m_nRecordNum[PR_RMSTATECOMP]].nType=PR_GENERATOR;
						pPRBlock->m_RMStateCompArray[pPRBlock->m_nRecordNum[PR_RMSTATECOMP]].nIndex=nDev;
						pPRBlock->m_nRecordNum[PR_RMSTATECOMP]++;
					}
					else
						Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_RMSTATECOMP));
				}
			}
		}
		if (nPRCompObject == 0 || nPRCompObject == 1)
		{
			for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
			{
				if (pPRBlock->m_ACBusArray[nDev].fRerr < FLT_MIN || pPRBlock->m_ACBusArray[nDev].fTrep < FLT_MIN)
					continue;

				if (pPRBlock->m_nRecordNum[PR_R2STATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_R2STATECOMP)-1)
				{
					memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_ACBUS;
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
					pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;
				}
				else
					Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_R2STATECOMP));
			}

			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
			{
				if (pPRBlock->m_ACLineArray[nDev].fRerr < FLT_MIN || pPRBlock->m_ACLineArray[nDev].fTrep < FLT_MIN)
					continue;

				if (pPRBlock->m_nRecordNum[PR_R2STATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_R2STATECOMP)-1)
				{
					memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_ACLINE;
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
					pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;
				}
				else
					Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_R2STATECOMP));
			}
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
			{
				if (pPRBlock->m_WindArray[nDev].fRerr < FLT_MIN || pPRBlock->m_WindArray[nDev].fTrep < FLT_MIN)
					continue;

				if (pPRBlock->m_nRecordNum[PR_R2STATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_R2STATECOMP)-1)
				{
					memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_WIND;
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
					pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;
				}
				else
					Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_R2STATECOMP));
			}
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_POWERLOAD]; nDev++)
			{
				nConverter = -1;
				for (i=0; i<pPRBlock->m_nRecordNum[PR_CONVERTER]; i++)
				{
					if (stricmp(pPRBlock->m_PowerLoadArray[nDev].szName, pPRBlock->m_ConverterArray[i].szName) == 0)
					{
						nConverter = i;
						break;
					}
				}
				if (nConverter >= 0)
					continue;

				if (!pPRBlock->m_PowerLoadArray[nDev].bMSModel)
				{
					if (pPRBlock->m_PowerLoadArray[nDev].fRerr < FLT_MIN || pPRBlock->m_PowerLoadArray[nDev].fTrep < FLT_MIN)
						continue;

					if (pPRBlock->m_nRecordNum[PR_R2STATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_R2STATECOMP)-1)
					{
						memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
						pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_POWERLOAD;
						pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
						pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;
					}
					else
						Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_R2STATECOMP));
				}
				else
				{
					if (pPRBlock->m_nRecordNum[PR_RMSTATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_RMSTATECOMP)-1)
					{
						memset(&pPRBlock->m_RMStateCompArray[pPRBlock->m_nRecordNum[PR_RMSTATECOMP]], 0, sizeof(tagPRMStateComp));
						pPRBlock->m_RMStateCompArray[pPRBlock->m_nRecordNum[PR_RMSTATECOMP]].nType=PR_POWERLOAD;
						pPRBlock->m_RMStateCompArray[pPRBlock->m_nRecordNum[PR_RMSTATECOMP]].nIndex=nDev;
						pPRBlock->m_nRecordNum[PR_RMSTATECOMP]++;
					}
					else
						Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_RMSTATECOMP));
				}
			}
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
			{
				if (!pPRBlock->m_HVDCArray[nDev].bMSModel)
				{
					if (pPRBlock->m_HVDCArray[nDev].fRerr < FLT_MIN || pPRBlock->m_HVDCArray[nDev].fTrep < FLT_MIN)
						continue;

					if (pPRBlock->m_nRecordNum[PR_R2STATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_R2STATECOMP)-1)
					{
						memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
						pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_HVDC;
						pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
						pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;
					}
					else
						Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_R2STATECOMP));
				}
				else
				{
					if (pPRBlock->m_nRecordNum[PR_RMSTATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_RMSTATECOMP)-1)
					{
						memset(&pPRBlock->m_RMStateCompArray[pPRBlock->m_nRecordNum[PR_RMSTATECOMP]], 0, sizeof(tagPRMStateComp));
						pPRBlock->m_RMStateCompArray[pPRBlock->m_nRecordNum[PR_RMSTATECOMP]].nType=PR_HVDC;
						pPRBlock->m_RMStateCompArray[pPRBlock->m_nRecordNum[PR_RMSTATECOMP]].nIndex=nDev;
						pPRBlock->m_nRecordNum[PR_RMSTATECOMP]++;
					}
					else
						Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_RMSTATECOMP));
				}
			}
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_TCSC]; nDev++)
			{
				if (pPRBlock->m_TCSCArray[nDev].fRerr < FLT_MIN || pPRBlock->m_TCSCArray[nDev].fTrep < FLT_MIN)
					continue;

				if (pPRBlock->m_nRecordNum[PR_R2STATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_R2STATECOMP)-1)
				{
					memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_TCSC;
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
					pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;
				}
				else
					Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_R2STATECOMP));
			}
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_UPFC]; nDev++)
			{
				if (pPRBlock->m_UPFCArray[nDev].fRerr < FLT_MIN || pPRBlock->m_UPFCArray[nDev].fTrep < FLT_MIN)
					continue;

				if (pPRBlock->m_nRecordNum[PR_R2STATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_R2STATECOMP)-1)
				{
					memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_UPFC;
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
					pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;
				}
				else
					Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_R2STATECOMP));
			}
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_CONVERTER]; nDev++)
			{
				if (pPRBlock->m_ConverterArray[nDev].fRerr < FLT_MIN || pPRBlock->m_ConverterArray[nDev].fTrep < FLT_MIN)
					continue;

				if (pPRBlock->m_nRecordNum[PR_R2STATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_R2STATECOMP)-1)
				{
					memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_CONVERTER;
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
					pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;
				}
				else
					Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_R2STATECOMP));
			}
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_DCLINE]; nDev++)
			{
				if (pPRBlock->m_DCLineArray[nDev].fRerr < FLT_MIN || pPRBlock->m_DCLineArray[nDev].fTrep < FLT_MIN)
					continue;

				if (pPRBlock->m_nRecordNum[PR_R2STATECOMP] < g_PRMemDBInterface.PRGetTableMax(PR_R2STATECOMP)-1)
				{
					memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_DCLINE;
					pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
					pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;
				}
				else
					Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_R2STATECOMP));
			}
		}

		pPRBlock->m_System.nMStateDevNum=pPRBlock->m_nRecordNum[PR_RMSTATECOMP];

		CalcPRSampleObjectProbability(pPRBlock, 0);
	}

	//计算短期故障概率
	void CPRAdequacyStateSample::CalcPRSampleObjectProbability(tagPRBlock* pPRBlock, const double fForcastTime)
	{
		register int	i;
		double fRerr, fRrep;
		//if (fForcastTime < 0.01)
		//{
		//	//平稳状态概率
		//	for (i=0; i<pPRBlock->m_nRecordNum[PR_RCOMP]; i++)
		//	{
		//		fRerr = pPRBlock->m_RCompArray[i].fRerr;
		//		fRrep = pPRBlock->m_RCompArray[i].fRrep;
		//		if (pPRBlock->m_RCompArray[i].fRerr > 8760)
		//		{
		//			//ASSERT(FALSE);
		//			pPRBlock->m_RCompArray[i].fFailProb = 1.0;
		//			pPRBlock->m_RCompArray[i].fGoodProb = 0.0;
		//		}
		//		else
		//		{
		//			if (fRerr+fRrep < FLT_MIN)
		//				pPRBlock->m_RCompArray[i].fFailProb = 0;
		//			else
		//				pPRBlock->m_RCompArray[i].fFailProb = fRerr/(fRerr+fRrep);
		//
		//			pPRBlock->m_RCompArray[i].fGoodProb = 1.0-pPRBlock->m_RCompArray[i].fFailProb;
		//		}
		//	}
		//}
		//else
		//{
		//	//瞬时状态概率，不考虑修复率
		//	for (i=0; i<pPRBlock->m_nRecordNum[PR_RCOMP]; i++)
		//	{
		//		fRerr = pPRBlock->m_RCompArray[i].fRerr;
		//
		//		pPRBlock->m_RCompArray[i].fGoodProb = exp(-fRerr*fForcastTime/8760.0);
		//		if (pPRBlock->m_RCompArray[i].fRerr >= pPRBlock->m_RCompArray[i].fRerrMax)
		//		{
		//			pPRBlock->m_RCompArray[i].fGoodProb = 0.9;
		//		}
		//		if (pPRBlock->m_RCompArray[i].fRerr == 0)
		//		{
		//			pPRBlock->m_RCompArray[i].fGoodProb = 1;
		//		}
		//		if (pPRBlock->m_RCompArray[i].fGoodProb > 0.99999)
		//		{
		//			pPRBlock->m_RCompArray[i].fGoodProb = 1;
		//		}			
		//		pPRBlock->m_RCompArray[i].fFailProb = 1.0 - pPRBlock->m_RCompArray[i].fGoodProb;
		//	}
		//}
		if (fForcastTime < 0.01)
		{
			//平稳状态概率
			for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
			{
				if (pPRBlock->m_ACBusArray[i].fRrep < FLT_MIN && pPRBlock->m_ACBusArray[i].fTrep > FLT_MIN)
				{
					if (pPRBlock->m_ACBusArray[i].fTrep > FLT_MIN)
						pPRBlock->m_ACBusArray[i].fRrep=(float)(8760.0/pPRBlock->m_ACBusArray[i].fTrep);
				}

				fRerr = pPRBlock->m_ACBusArray[i].fRerr;
				fRrep = pPRBlock->m_ACBusArray[i].fRrep;
				if (fRerr > 8760)
				{
					pPRBlock->m_ACBusArray[i].fFailProb = 1.0;
					pPRBlock->m_ACBusArray[i].fGoodProb = 0.0;
				}
				else
				{
					if (fRerr+fRrep < FLT_MIN)
						pPRBlock->m_ACBusArray[i].fFailProb = 0;
					else
						pPRBlock->m_ACBusArray[i].fFailProb = fRerr/(fRerr+fRrep);

					pPRBlock->m_ACBusArray[i].fGoodProb = 1.0-pPRBlock->m_ACBusArray[i].fFailProb;
				}
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
			{
				if (pPRBlock->m_ACLineArray[i].fRrep < FLT_MIN && pPRBlock->m_ACLineArray[i].fTrep > FLT_MIN)
				{
					if (pPRBlock->m_ACLineArray[i].fTrep > FLT_MIN)
						pPRBlock->m_ACLineArray[i].fRrep=(float)(8760.0/pPRBlock->m_ACLineArray[i].fTrep);
				}

				fRerr = pPRBlock->m_ACLineArray[i].fRerr;
				fRrep = pPRBlock->m_ACLineArray[i].fRrep;
				if (fRerr > 8760)
				{
					//ASSERT(FALSE);
					pPRBlock->m_ACLineArray[i].fFailProb = 1.0;
					pPRBlock->m_ACLineArray[i].fGoodProb = 0.0;
				}
				else
				{
					if (fRerr+fRrep < FLT_MIN)
						pPRBlock->m_ACLineArray[i].fFailProb = 0;
					else
						pPRBlock->m_ACLineArray[i].fFailProb = fRerr/(fRerr+fRrep);

					pPRBlock->m_ACLineArray[i].fGoodProb = 1.0-pPRBlock->m_ACLineArray[i].fFailProb;
				}
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
			{
				if (pPRBlock->m_WindArray[i].fRrep < FLT_MIN && pPRBlock->m_WindArray[i].fTrep > FLT_MIN)
				{
					if (pPRBlock->m_WindArray[i].fTrep > FLT_MIN)
						pPRBlock->m_WindArray[i].fRrep=(float)(8760.0/pPRBlock->m_WindArray[i].fTrep);
				}

				fRerr = pPRBlock->m_WindArray[i].fRerr;
				fRrep = pPRBlock->m_WindArray[i].fRrep;
				if (fRerr > 8760)
				{
					pPRBlock->m_WindArray[i].fFailProb = 1.0;
					pPRBlock->m_WindArray[i].fGoodProb = 0.0;
				}
				else
				{
					if (fRerr+fRrep < FLT_MIN)
						pPRBlock->m_WindArray[i].fFailProb = 0;
					else
						pPRBlock->m_WindArray[i].fFailProb = fRerr/(fRerr+fRrep);

					pPRBlock->m_WindArray[i].fGoodProb = 1.0-pPRBlock->m_WindArray[i].fFailProb;
				}
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_GENERATOR]; i++)
			{
				if (pPRBlock->m_GeneratorArray[i].fRrep < FLT_MIN && pPRBlock->m_GeneratorArray[i].fTrep > FLT_MIN)
				{
					if (pPRBlock->m_GeneratorArray[i].fTrep > FLT_MIN)
						pPRBlock->m_GeneratorArray[i].fRrep=(float)(8760.0/pPRBlock->m_GeneratorArray[i].fTrep);
				}

				fRerr = pPRBlock->m_GeneratorArray[i].fRerr;
				fRrep = pPRBlock->m_GeneratorArray[i].fRrep;
				if (fRerr > 8760)
				{
					pPRBlock->m_GeneratorArray[i].fFailProb = 1.0;
					pPRBlock->m_GeneratorArray[i].fGoodProb = 0.0;
				}
				else
				{
					if (fRerr+fRrep < FLT_MIN)
						pPRBlock->m_GeneratorArray[i].fFailProb = 0;
					else
						pPRBlock->m_GeneratorArray[i].fFailProb = fRerr/(fRerr+fRrep);

					pPRBlock->m_GeneratorArray[i].fGoodProb = 1.0-pPRBlock->m_GeneratorArray[i].fFailProb;
				}
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_POWERLOAD]; i++)
			{
				if (pPRBlock->m_PowerLoadArray[i].fRrep < FLT_MIN && pPRBlock->m_PowerLoadArray[i].fTrep > FLT_MIN)
				{
					if (pPRBlock->m_PowerLoadArray[i].fTrep > FLT_MIN)
						pPRBlock->m_PowerLoadArray[i].fRrep=(float)(8760.0/pPRBlock->m_PowerLoadArray[i].fTrep);
				}

				fRerr = pPRBlock->m_PowerLoadArray[i].fRerr;
				fRrep = pPRBlock->m_PowerLoadArray[i].fRrep;
				if (fRerr > 8760)
				{
					pPRBlock->m_PowerLoadArray[i].fFailProb = 1.0;
					pPRBlock->m_PowerLoadArray[i].fGoodProb = 0.0;
				}
				else
				{
					if (fRerr+fRrep < FLT_MIN)
						pPRBlock->m_PowerLoadArray[i].fFailProb = 0;
					else
						pPRBlock->m_PowerLoadArray[i].fFailProb = fRerr/(fRerr+fRrep);

					pPRBlock->m_PowerLoadArray[i].fGoodProb = 1.0-pPRBlock->m_PowerLoadArray[i].fFailProb;
				}
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_HVDC]; i++)
			{
				if (pPRBlock->m_HVDCArray[i].fRrep < FLT_MIN && pPRBlock->m_HVDCArray[i].fTrep > FLT_MIN)
				{
					if (pPRBlock->m_HVDCArray[i].fTrep > FLT_MIN)
						pPRBlock->m_HVDCArray[i].fRrep=(float)(8760.0/pPRBlock->m_HVDCArray[i].fTrep);
				}

				fRerr = pPRBlock->m_HVDCArray[i].fRerr;
				fRrep = pPRBlock->m_HVDCArray[i].fRrep;
				if (fRerr > 8760)
				{
					pPRBlock->m_HVDCArray[i].fFailProb = 1.0;
					pPRBlock->m_HVDCArray[i].fGoodProb = 0.0;
				}
				else
				{
					if (fRerr+fRrep < FLT_MIN)
						pPRBlock->m_HVDCArray[i].fFailProb = 0;
					else
						pPRBlock->m_HVDCArray[i].fFailProb = fRerr/(fRerr+fRrep);

					pPRBlock->m_HVDCArray[i].fGoodProb = 1.0-pPRBlock->m_HVDCArray[i].fFailProb;
				}
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_TCSC]; i++)
			{
				if (pPRBlock->m_TCSCArray[i].fRrep < FLT_MIN && pPRBlock->m_TCSCArray[i].fTrep > FLT_MIN)
				{
					if (pPRBlock->m_TCSCArray[i].fTrep > FLT_MIN)
						pPRBlock->m_TCSCArray[i].fRrep=(float)(8760.0/pPRBlock->m_TCSCArray[i].fTrep);
				}

				fRerr = pPRBlock->m_TCSCArray[i].fRerr;
				fRrep = pPRBlock->m_TCSCArray[i].fRrep;
				if (fRerr > 8760)
				{
					pPRBlock->m_TCSCArray[i].fFailProb = 1.0;
					pPRBlock->m_TCSCArray[i].fGoodProb = 0.0;
				}
				else
				{
					if (fRerr+fRrep < FLT_MIN)
						pPRBlock->m_TCSCArray[i].fFailProb = 0;
					else
						pPRBlock->m_TCSCArray[i].fFailProb = fRerr/(fRerr+fRrep);

					pPRBlock->m_TCSCArray[i].fGoodProb = 1.0-pPRBlock->m_TCSCArray[i].fFailProb;
				}
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_UPFC]; i++)
			{
				if (pPRBlock->m_UPFCArray[i].fRrep < FLT_MIN && pPRBlock->m_UPFCArray[i].fTrep > FLT_MIN)
				{
					if (pPRBlock->m_UPFCArray[i].fTrep > FLT_MIN)
						pPRBlock->m_UPFCArray[i].fRrep=(float)(8760.0/pPRBlock->m_UPFCArray[i].fTrep);
				}

				fRerr = pPRBlock->m_UPFCArray[i].fRerr;
				fRrep = pPRBlock->m_UPFCArray[i].fRrep;
				if (fRerr > 8760)
				{
					pPRBlock->m_UPFCArray[i].fFailProb = 1.0;
					pPRBlock->m_UPFCArray[i].fGoodProb = 0.0;
				}
				else
				{
					if (fRerr+fRrep < FLT_MIN)
						pPRBlock->m_UPFCArray[i].fFailProb = 0;
					else
						pPRBlock->m_UPFCArray[i].fFailProb = fRerr/(fRerr+fRrep);

					pPRBlock->m_UPFCArray[i].fGoodProb = 1.0-pPRBlock->m_UPFCArray[i].fFailProb;
				}
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_CONVERTER]; i++)
			{
				if (pPRBlock->m_ConverterArray[i].fRrep < FLT_MIN && pPRBlock->m_ConverterArray[i].fTrep > FLT_MIN)
				{
					if (pPRBlock->m_ConverterArray[i].fTrep > FLT_MIN)
						pPRBlock->m_ConverterArray[i].fRrep=(float)(8760.0/pPRBlock->m_ConverterArray[i].fTrep);
				}

				fRerr = pPRBlock->m_ConverterArray[i].fRerr;
				fRrep = pPRBlock->m_ConverterArray[i].fRrep;
				if (fRerr > 8760)
				{
					pPRBlock->m_ConverterArray[i].fFailProb = 1.0;
					pPRBlock->m_ConverterArray[i].fGoodProb = 0.0;
				}
				else
				{
					if (fRerr+fRrep < FLT_MIN)
						pPRBlock->m_ConverterArray[i].fFailProb = 0;
					else
						pPRBlock->m_ConverterArray[i].fFailProb = fRerr/(fRerr+fRrep);

					pPRBlock->m_ConverterArray[i].fGoodProb = 1.0-pPRBlock->m_ConverterArray[i].fFailProb;
				}
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_DCLINE]; i++)
			{
				if (pPRBlock->m_DCLineArray[i].fRrep < FLT_MIN && pPRBlock->m_DCLineArray[i].fTrep > FLT_MIN)
				{
					if (pPRBlock->m_DCLineArray[i].fTrep > FLT_MIN)
						pPRBlock->m_DCLineArray[i].fRrep=(float)(8760.0/pPRBlock->m_DCLineArray[i].fTrep);
				}

				fRerr = pPRBlock->m_DCLineArray[i].fRerr;
				fRrep = pPRBlock->m_DCLineArray[i].fRrep;
				if (fRerr > 8760)
				{
					pPRBlock->m_DCLineArray[i].fFailProb = 1.0;
					pPRBlock->m_DCLineArray[i].fGoodProb = 0.0;
				}
				else
				{
					if (fRerr+fRrep < FLT_MIN)
						pPRBlock->m_DCLineArray[i].fFailProb = 0;
					else
						pPRBlock->m_DCLineArray[i].fFailProb = fRerr/(fRerr+fRrep);

					pPRBlock->m_DCLineArray[i].fGoodProb = 1.0-pPRBlock->m_DCLineArray[i].fFailProb;
				}
			}
		}
		else
		{
			for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
			{
				fRerr = pPRBlock->m_ACBusArray[i].fRerr;

				pPRBlock->m_ACBusArray[i].fGoodProb = exp(-fRerr*fForcastTime/8760.0);
				if (pPRBlock->m_ACBusArray[i].fRerr >= pPRBlock->m_ACBusArray[i].fRerrMax)
				{
					pPRBlock->m_ACBusArray[i].fGoodProb = 0.9;
				}
				if (pPRBlock->m_ACBusArray[i].fRerr == 0)
				{
					pPRBlock->m_ACBusArray[i].fGoodProb = 1;
				}
				if (pPRBlock->m_ACBusArray[i].fGoodProb > 0.99999)
				{
					pPRBlock->m_ACBusArray[i].fGoodProb = 1;
				}			
				pPRBlock->m_ACBusArray[i].fFailProb = 1.0 - pPRBlock->m_ACBusArray[i].fGoodProb;
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
			{
				fRerr = pPRBlock->m_ACLineArray[i].fRerr;

				pPRBlock->m_ACLineArray[i].fGoodProb = exp(-fRerr*fForcastTime/8760.0);
				if (pPRBlock->m_ACLineArray[i].fRerr >= pPRBlock->m_ACLineArray[i].fRerrMax)
				{
					pPRBlock->m_ACLineArray[i].fGoodProb = 0.9;
				}
				if (pPRBlock->m_ACLineArray[i].fRerr == 0)
				{
					pPRBlock->m_ACLineArray[i].fGoodProb = 1;
				}
				if (pPRBlock->m_ACLineArray[i].fGoodProb > 0.99999)
				{
					pPRBlock->m_ACLineArray[i].fGoodProb = 1;
				}			
				pPRBlock->m_ACLineArray[i].fFailProb = 1.0 - pPRBlock->m_ACLineArray[i].fGoodProb;
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
			{
				fRerr = pPRBlock->m_WindArray[i].fRerr;

				pPRBlock->m_WindArray[i].fGoodProb = exp(-fRerr*fForcastTime/8760.0);
				if (pPRBlock->m_WindArray[i].fRerr >= pPRBlock->m_WindArray[i].fRerrMax)
				{
					pPRBlock->m_WindArray[i].fGoodProb = 0.9;
				}
				if (pPRBlock->m_WindArray[i].fRerr == 0)
				{
					pPRBlock->m_WindArray[i].fGoodProb = 1;
				}
				if (pPRBlock->m_WindArray[i].fGoodProb > 0.99999)
				{
					pPRBlock->m_WindArray[i].fGoodProb = 1;
				}			
				pPRBlock->m_WindArray[i].fFailProb = 1.0 - pPRBlock->m_WindArray[i].fGoodProb;
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_GENERATOR]; i++)
			{
				fRerr = pPRBlock->m_GeneratorArray[i].fRerr;

				pPRBlock->m_GeneratorArray[i].fGoodProb = exp(-fRerr*fForcastTime/8760.0);
				if (pPRBlock->m_GeneratorArray[i].fRerr >= pPRBlock->m_GeneratorArray[i].fRerrMax)
				{
					pPRBlock->m_GeneratorArray[i].fGoodProb = 0.9;
				}
				if (pPRBlock->m_GeneratorArray[i].fRerr == 0)
				{
					pPRBlock->m_GeneratorArray[i].fGoodProb = 1;
				}
				if (pPRBlock->m_GeneratorArray[i].fGoodProb > 0.99999)
				{
					pPRBlock->m_GeneratorArray[i].fGoodProb = 1;
				}			
				pPRBlock->m_GeneratorArray[i].fFailProb = 1.0 - pPRBlock->m_GeneratorArray[i].fGoodProb;
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_HVDC]; i++)
			{
				fRerr = pPRBlock->m_HVDCArray[i].fRerr;

				pPRBlock->m_HVDCArray[i].fGoodProb = exp(-fRerr*fForcastTime/8760.0);
				if (pPRBlock->m_HVDCArray[i].fRerr >= pPRBlock->m_HVDCArray[i].fRerrMax)
				{
					pPRBlock->m_HVDCArray[i].fGoodProb = 0.9;
				}
				if (pPRBlock->m_HVDCArray[i].fRerr == 0)
				{
					pPRBlock->m_HVDCArray[i].fGoodProb = 1;
				}
				if (pPRBlock->m_HVDCArray[i].fGoodProb > 0.99999)
				{
					pPRBlock->m_HVDCArray[i].fGoodProb = 1;
				}			
				pPRBlock->m_HVDCArray[i].fFailProb = 1.0 - pPRBlock->m_HVDCArray[i].fGoodProb;
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_TCSC]; i++)
			{
				fRerr = pPRBlock->m_TCSCArray[i].fRerr;

				pPRBlock->m_TCSCArray[i].fGoodProb = exp(-fRerr*fForcastTime/8760.0);
				if (pPRBlock->m_TCSCArray[i].fRerr >= pPRBlock->m_TCSCArray[i].fRerrMax)
				{
					pPRBlock->m_TCSCArray[i].fGoodProb = 0.9;
				}
				if (pPRBlock->m_TCSCArray[i].fRerr == 0)
				{
					pPRBlock->m_TCSCArray[i].fGoodProb = 1;
				}
				if (pPRBlock->m_TCSCArray[i].fGoodProb > 0.99999)
				{
					pPRBlock->m_TCSCArray[i].fGoodProb = 1;
				}			
				pPRBlock->m_TCSCArray[i].fFailProb = 1.0 - pPRBlock->m_TCSCArray[i].fGoodProb;
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_UPFC]; i++)
			{
				fRerr = pPRBlock->m_UPFCArray[i].fRerr;

				pPRBlock->m_UPFCArray[i].fGoodProb = exp(-fRerr*fForcastTime/8760.0);
				if (pPRBlock->m_UPFCArray[i].fRerr >= pPRBlock->m_UPFCArray[i].fRerrMax)
				{
					pPRBlock->m_UPFCArray[i].fGoodProb = 0.9;
				}
				if (pPRBlock->m_UPFCArray[i].fRerr == 0)
				{
					pPRBlock->m_UPFCArray[i].fGoodProb = 1;
				}
				if (pPRBlock->m_UPFCArray[i].fGoodProb > 0.99999)
				{
					pPRBlock->m_UPFCArray[i].fGoodProb = 1;
				}			
				pPRBlock->m_UPFCArray[i].fFailProb = 1.0 - pPRBlock->m_UPFCArray[i].fGoodProb;
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_CONVERTER]; i++)
			{
				fRerr = pPRBlock->m_ConverterArray[i].fRerr;

				pPRBlock->m_ConverterArray[i].fGoodProb = exp(-fRerr*fForcastTime/8760.0);
				if (pPRBlock->m_ConverterArray[i].fRerr >= pPRBlock->m_ConverterArray[i].fRerrMax)
				{
					pPRBlock->m_ConverterArray[i].fGoodProb = 0.9;
				}
				if (pPRBlock->m_ConverterArray[i].fRerr == 0)
				{
					pPRBlock->m_ConverterArray[i].fGoodProb = 1;
				}
				if (pPRBlock->m_ConverterArray[i].fGoodProb > 0.99999)
				{
					pPRBlock->m_ConverterArray[i].fGoodProb = 1;
				}			
				pPRBlock->m_ConverterArray[i].fFailProb = 1.0 - pPRBlock->m_ConverterArray[i].fGoodProb;
			}
			for (i=0; i<pPRBlock->m_nRecordNum[PR_DCLINE]; i++)
			{
				fRerr = pPRBlock->m_DCLineArray[i].fRerr;

				pPRBlock->m_DCLineArray[i].fGoodProb = exp(-fRerr*fForcastTime/8760.0);
				if (pPRBlock->m_DCLineArray[i].fRerr >= pPRBlock->m_DCLineArray[i].fRerrMax)
				{
					pPRBlock->m_DCLineArray[i].fGoodProb = 0.9;
				}
				if (pPRBlock->m_DCLineArray[i].fRerr == 0)
				{
					pPRBlock->m_DCLineArray[i].fGoodProb = 1;
				}
				if (pPRBlock->m_DCLineArray[i].fGoodProb > 0.99999)
				{
					pPRBlock->m_DCLineArray[i].fGoodProb = 1;
				}			
				pPRBlock->m_DCLineArray[i].fFailProb = 1.0 - pPRBlock->m_DCLineArray[i].fGoodProb;
			}
		}
	}

	void CPRAdequacyStateSample::CommonFState(tagPRBlock* pPRBlock)
	{
		register int	i;
		int				nFState, nFDev, nCommID, nCommF;
		unsigned char	bExist;
		int				nCommDevNum, nFltDevNum;
		std::vector<tagPRFStateFDev>	sFDevArray;
		tagPRFStateFDev	sFDev;

		i=0;
		while (i < pPRBlock->m_nRecordNum[PR_FSTATEFDEV])
		{
			if (pPRBlock->m_FStateFDevArray[i].nDFltTyp == PRFState_FaultType_CommonFault)
				g_PRMemDBInterface.PRRemoveRecord(pPRBlock, PR_FSTATEFDEV, i);
			else
				i++;
		}

		//////////////////////////////////////////////////////////////////////////
		//	状态共因
		for (nFState=0; nFState<pPRBlock->m_nRecordNum[PR_FSTATE]; nFState++)
		{
			sFDevArray.clear();
			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; nFDev++)
			{
				if (pPRBlock->m_FStateFDevArray[nFDev].nFStateNo < nFState)
					continue;
				if (pPRBlock->m_FStateFDevArray[nFDev].nFStateNo > nFState)
					break;

				sFDevArray.push_back(pPRBlock->m_FStateFDevArray[nFDev]);
			}

			for (i=0; i<pPRBlock->m_nRecordNum[PR_COMMONFAULT]; i++)
				pPRBlock->m_CommonFaultArray[i].bProc=0;

			for (nCommID=0; nCommID<pPRBlock->m_nRecordNum[PR_COMMONFAULT]; nCommID++)
			{
				if (pPRBlock->m_CommonFaultArray[nCommID].bProc)
					continue;

				for (nCommF=0; nCommF<pPRBlock->m_nRecordNum[PR_COMMONFAULT]; nCommF++)	//	共因故障中所有故障设备均故障了
				{
					if (stricmp(pPRBlock->m_CommonFaultArray[nCommF].szName, pPRBlock->m_CommonFaultArray[nCommID].szName) != 0)
						continue;
					pPRBlock->m_CommonFaultArray[nCommF].bProc = 1;
				}

				nCommDevNum = nFltDevNum = 0;
				for (nCommF=0; nCommF<pPRBlock->m_nRecordNum[PR_COMMONFAULT]; nCommF++)	//	共因故障中所有故障设备均故障了
				{
					if (pPRBlock->m_CommonFaultArray[nCommF].nDevIndex < 0)
						continue;
					if (stricmp(pPRBlock->m_CommonFaultArray[nCommF].szName, pPRBlock->m_CommonFaultArray[nCommID].szName) != 0)
						continue;
					if (pPRBlock->m_CommonFaultArray[nCommF].nCommonFaultType != PRCommonFault_CommonFaultType_Status)
						continue;
					if (pPRBlock->m_CommonFaultArray[nCommF].nDeviceCommonType != PRCommonFault_DeviceCommonType_Resion)
						continue;

					nCommDevNum++;
					for (i=0; i<(int)sFDevArray.size(); i++)
					{
						if (pPRBlock->m_CommonFaultArray[nCommF].nDevType == sFDevArray[i].nFDevTyp &&
							pPRBlock->m_CommonFaultArray[nCommF].nDevIndex == sFDevArray[i].nFDevIdx)
						{
							nFltDevNum++;
							break;
						}
					}
				}
				if (nCommDevNum == 0 || nCommDevNum != nFltDevNum)
					continue;

				for (nCommF=0; nCommF<pPRBlock->m_nRecordNum[PR_COMMONFAULT]; nCommF++)
				{
					if (stricmp(pPRBlock->m_CommonFaultArray[nCommF].szName, pPRBlock->m_CommonFaultArray[nCommID].szName) != 0)
						continue;
					if (pPRBlock->m_CommonFaultArray[nCommF].nDeviceCommonType != PRCommonFault_DeviceCommonType_Result)
						continue;

					bExist = 0;
					for (i=0; i<(int)sFDevArray.size(); i++)
					{
						if (sFDevArray[i].nFDevTyp == pPRBlock->m_CommonFaultArray[nCommF].nDevType &&
							sFDevArray[i].nFDevIdx == pPRBlock->m_CommonFaultArray[nCommF].nDevIndex)
						{
							bExist=1;
							break;
						}
					}
					if (!bExist)
					{
						memset(&sFDev, 0, sizeof(tagPRFStateFDev));
						sFDev.nFDevTyp = pPRBlock->m_CommonFaultArray[nCommF].nDevType;
						sFDev.nFDevIdx = pPRBlock->m_CommonFaultArray[nCommF].nDevIndex;
						sFDevArray.push_back(sFDev);

						if (pPRBlock->m_nRecordNum[PR_FSTATEFDEV] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEFDEV)-1)
						{
							memset(&pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]], 0, sizeof(tagPRFStateFDev));
							pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
							pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateNo=nFState;
							pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevTyp=pPRBlock->m_CommonFaultArray[nCommF].nDevType;
							pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevIdx=pPRBlock->m_CommonFaultArray[nCommF].nDevIndex;
							pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nDFltTyp=PRFState_FaultType_CommonFault;
							pPRBlock->m_nRecordNum[PR_FSTATEFDEV]++;

							switch (pPRBlock->m_CommonFaultArray[nCommF].nDevType)
							{
							case	PR_ACLINE:
								Log(g_lpszLogFile, "        CommonFState[%d] 状态共因，设置%s[%s]停运\n", nCommID, g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_CommonFaultArray[nCommF].nDevType), pPRBlock->m_CommonFaultArray[nCommF].szDevName);
								break;
							case	PR_WIND:
								Log(g_lpszLogFile, "        CommonFState[%d] 状态共因，设置%s[%s]停运\n", nCommID, g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_CommonFaultArray[nCommF].nDevType), pPRBlock->m_CommonFaultArray[nCommF].szDevName);
								break;
							case	PR_GENERATOR:
								Log(g_lpszLogFile, "        CommonFState[%d] 状态共因，设置%s[%s]停运\n", nCommID, g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_CommonFaultArray[nCommF].nDevType), pPRBlock->m_CommonFaultArray[nCommF].szDevName);
								break;
							case	PR_POWERLOAD:
								Log(g_lpszLogFile, "        CommonFState[%d] 状态共因，设置%s[%s]停运\n", nCommID, g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_CommonFaultArray[nCommF].nDevType), pPRBlock->m_CommonFaultArray[nCommF].szDevName);
								break;
							case	PR_HVDC:
								Log(g_lpszLogFile, "        CommonFState[%d] 状态共因，设置%s[%s]停运\n", nCommID, g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_CommonFaultArray[nCommF].nDevType), pPRBlock->m_CommonFaultArray[nCommF].szDevName);
								break;
							case	PR_TCSC:
								Log(g_lpszLogFile, "        CommonFState[%d] 状态共因，设置%s[%s]停运\n", nCommID, g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_CommonFaultArray[nCommF].nDevType), pPRBlock->m_CommonFaultArray[nCommF].szDevName);
								break;
							case	PR_UPFC:
								Log(g_lpszLogFile, "        CommonFState[%d] 状态共因，设置%s[%s]停运\n", nCommID, g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_CommonFaultArray[nCommF].nDevType), pPRBlock->m_CommonFaultArray[nCommF].szDevName);
								break;
							case	PR_CONVERTER:
								if (pPRBlock->m_ConverterArray[pPRBlock->m_CommonFaultArray[nCommF].nDevIndex].nType == PRConverter_Type_Rectifier)
									Log(g_lpszLogFile, "        CommonFState[%d] 状态共因，设置%s[%s]停运 损失负荷 %.2f\n", nCommID, g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_CommonFaultArray[nCommF].nDevType), pPRBlock->m_CommonFaultArray[nCommF].szDevName, pPRBlock->m_ConverterArray[pPRBlock->m_CommonFaultArray[nCommF].nDevIndex].fConverterPower);
								else
									Log(g_lpszLogFile, "        CommonFState[%d] 状态共因，设置%s[%s]停运 损失发电 %.2f\n", nCommID, g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_CommonFaultArray[nCommF].nDevType), pPRBlock->m_CommonFaultArray[nCommF].szDevName, pPRBlock->m_ConverterArray[pPRBlock->m_CommonFaultArray[nCommF].nDevIndex].fConverterPower);
								break;
							case	PR_DCLINE:
								Log(g_lpszLogFile, "        CommonFState[%d] 状态共因，设置%s[%s]停运\n", nCommID, g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_CommonFaultArray[nCommF].nDevType), pPRBlock->m_CommonFaultArray[nCommF].szDevName);
								break;
							}
						}
						else
							Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEFDEV));

						pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFDevNum++;
					}
				}
			}
		}

		g_PRMemDBInterface.PRMaint(pPRBlock);
	}

	void CPRAdequacyStateSample::ManualFState(tagPRBlock* pPRBlock)
	{
		register int	i;
		int		nFStat, nFDev, nMFault;

		for (nFStat=0; nFStat<pPRBlock->m_nRecordNum[PR_FSTATE]; nFStat++)
		{
			if (pPRBlock->m_FStateArray[nFStat].nSampleType == PRFState_SamplingMethod_Manual)
				pPRBlock->m_FStateArray[nFStat].nStateNum=-1;
		}
		for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; nFDev++)
		{
			if (pPRBlock->m_FStateArray[pPRBlock->m_FStateFDevArray[nFDev].nFStateNo].nStateNum < 0)
				pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx = -1;
		}

		nFStat=0;
		while (nFStat < pPRBlock->m_nRecordNum[PR_FSTATE])
		{
			if (pPRBlock->m_FStateArray[nFStat].nStateNum < 0)
				g_PRMemDBInterface.PRRemoveRecord(pPRBlock, PR_FSTATE, nFStat);
			else
				nFStat++;
		}

		nFDev=0;
		while (nFDev < pPRBlock->m_nRecordNum[PR_FSTATEFDEV])
		{
			if (pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx < 0)
				g_PRMemDBInterface.PRRemoveRecord(pPRBlock, PR_FSTATEFDEV, nFDev);
			else
				nFDev++;
		}

		int	nFDevNum;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; i++)
		{
			pPRBlock->m_ManualFaultArray[i].bProc = 0;
			pPRBlock->m_ManualFaultArray[i].nFDevIndex = -1;
		}

		for (nMFault=0; nMFault<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nMFault++)
		{
			nFDevNum = 0;
			if (pPRBlock->m_ManualFaultArray[nMFault].bProc)
				continue;

			for (nFDev=nMFault; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
			{
				if (stricmp(pPRBlock->m_ManualFaultArray[nMFault].szName, pPRBlock->m_ManualFaultArray[nFDev].szName) != 0)
					continue;
				pPRBlock->m_ManualFaultArray[nFDev].bProc = 1;

				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevType == PR_ACBUS)
				{
					for (i=0; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
					{
						if (_stricmp(pPRBlock->m_ACBusArray[i].szName, pPRBlock->m_ManualFaultArray[nFDev].szFDevName) == 0)
						{
							pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex = i;
							nFDevNum++;
							break;
						}
					}
				}
				else
				{
					pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex = g_PRMemDBInterface.PRFindRecordbyKey(pPRBlock, pPRBlock->m_ManualFaultArray[nFDev].nFDevType, pPRBlock->m_ManualFaultArray[nFDev].szFDevName);
					nFDevNum++;
				}
			}

			if (nFDevNum > 0)
			{
				memset(&pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]], 0, sizeof(tagPRFState));
				pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFStateId=pPRBlock->m_nRecordNum[PR_FSTATE]+1;
				pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nSampleType=PRFState_SamplingMethod_Manual;

				pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].fStateProb=ManualFStateProb(pPRBlock, nMFault);
				pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nStateNum=1;

				for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
				{
					if (stricmp(pPRBlock->m_ManualFaultArray[nMFault].szName, pPRBlock->m_ManualFaultArray[nFDev].szName) != 0)
						continue;
					if (pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex < 0)
						continue;

					if (pPRBlock->m_nRecordNum[PR_FSTATEFDEV] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEFDEV)-1)
					{
						memset(&pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]], 0, sizeof(tagPRFStateFDev));
						pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateId=pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFStateId;
						pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateNo=pPRBlock->m_nRecordNum[PR_FSTATE];
						pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevTyp=pPRBlock->m_ManualFaultArray[nFDev].nFDevType;
						pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevIdx=pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex;
						pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nDFltTyp=PRFState_FaultType_Trip;

						pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFDevNum++;
						pPRBlock->m_nRecordNum[PR_FSTATEFDEV]++;
					}
					else
						Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEFDEV));
				}
				pPRBlock->m_nRecordNum[PR_FSTATE]++;
			}
		}
	}

	double CPRAdequacyStateSample::ManualFStateProb(tagPRBlock* pPRBlock, const int nManual)
	{
		int		nDev, nFDev;
		unsigned char	bExist;
		double	fStateProb = 1.0;

		for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
		{
			bExist=0;
			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
			{
				if (stricmp(pPRBlock->m_ManualFaultArray[nManual].szName, pPRBlock->m_ManualFaultArray[nFDev].szName) != 0)
					continue;
				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex < 0)
					continue;

				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevType == PR_ACBUS && pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex == nDev)
				{
					bExist=1;
					break;
				}
			}
			if (!bExist)
				fStateProb *= pPRBlock->m_ACBusArray[nDev].fGoodProb;
			else
				fStateProb *= pPRBlock->m_ACBusArray[nDev].fFailProb;
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
		{
			bExist=0;
			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
			{
				if (stricmp(pPRBlock->m_ManualFaultArray[nManual].szName, pPRBlock->m_ManualFaultArray[nFDev].szName) != 0)
					continue;
				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex < 0)
					continue;

				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevType == PR_ACLINE && pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex == nDev)
				{
					bExist=1;
					break;
				}
			}
			if (!bExist)
				fStateProb *= pPRBlock->m_ACLineArray[nDev].fGoodProb;
			else
				fStateProb *= pPRBlock->m_ACLineArray[nDev].fFailProb;
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
		{
			bExist=0;
			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
			{
				if (stricmp(pPRBlock->m_ManualFaultArray[nManual].szName, pPRBlock->m_ManualFaultArray[nFDev].szName) != 0)
					continue;
				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex < 0)
					continue;

				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevType == PR_WIND && pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex == nDev)
				{
					bExist=1;
					break;
				}
			}
			if (!bExist)
				fStateProb *= pPRBlock->m_WindArray[nDev].fGoodProb;
			else
				fStateProb *= pPRBlock->m_WindArray[nDev].fFailProb;
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
		{
			bExist=0;
			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
			{
				if (stricmp(pPRBlock->m_ManualFaultArray[nManual].szName, pPRBlock->m_ManualFaultArray[nFDev].szName) != 0)
					continue;
				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex < 0)
					continue;

				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevType == PR_GENERATOR && pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex == nDev)
				{
					bExist=1;
					break;
				}
			}
			if (!bExist)
				fStateProb *= pPRBlock->m_GeneratorArray[nDev].fGoodProb;
			else
				fStateProb *= pPRBlock->m_GeneratorArray[nDev].fFailProb;
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_POWERLOAD]; nDev++)
		{
			bExist=0;
			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
			{
				if (stricmp(pPRBlock->m_ManualFaultArray[nManual].szName, pPRBlock->m_ManualFaultArray[nFDev].szName) != 0)
					continue;
				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex < 0)
					continue;

				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevType == PR_POWERLOAD && pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex == nDev)
				{
					bExist=1;
					break;
				}
			}
			if (!bExist)
				fStateProb *= pPRBlock->m_PowerLoadArray[nDev].fGoodProb;
			else
				fStateProb *= pPRBlock->m_PowerLoadArray[nDev].fFailProb;
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
		{
			bExist=0;
			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
			{
				if (stricmp(pPRBlock->m_ManualFaultArray[nManual].szName, pPRBlock->m_ManualFaultArray[nFDev].szName) != 0)
					continue;
				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex < 0)
					continue;

				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevType == PR_HVDC && pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex == nDev)
				{
					bExist=1;
					break;
				}
			}
			if (!bExist)
				fStateProb *= pPRBlock->m_HVDCArray[nDev].fGoodProb;
			else
				fStateProb *= pPRBlock->m_HVDCArray[nDev].fFailProb;
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_TCSC]; nDev++)
		{
			bExist=0;
			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
			{
				if (stricmp(pPRBlock->m_ManualFaultArray[nManual].szName, pPRBlock->m_ManualFaultArray[nFDev].szName) != 0)
					continue;
				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex < 0)
					continue;

				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevType == PR_TCSC && pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex == nDev)
				{
					bExist=1;
					break;
				}
			}
			if (!bExist)
				fStateProb *= pPRBlock->m_TCSCArray[nDev].fGoodProb;
			else
				fStateProb *= pPRBlock->m_TCSCArray[nDev].fFailProb;
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_UPFC]; nDev++)
		{
			bExist=0;
			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
			{
				if (stricmp(pPRBlock->m_ManualFaultArray[nManual].szName, pPRBlock->m_ManualFaultArray[nFDev].szName) != 0)
					continue;
				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex < 0)
					continue;

				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevType == PR_UPFC && pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex == nDev)
				{
					bExist=1;
					break;
				}
			}
			if (!bExist)
				fStateProb *= pPRBlock->m_UPFCArray[nDev].fGoodProb;
			else
				fStateProb *= pPRBlock->m_UPFCArray[nDev].fFailProb;
		}
		for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
		{
			bExist=0;
			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
			{
				if (stricmp(pPRBlock->m_ManualFaultArray[nManual].szName, pPRBlock->m_ManualFaultArray[nFDev].szName) != 0)
					continue;
				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex < 0)
					continue;

				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevType == PR_CONVERTER && pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex == nDev)
				{
					bExist=1;
					break;
				}
			}
			if (!bExist)
				fStateProb *= pPRBlock->m_ConverterArray[nDev].fGoodProb;
			else
				fStateProb *= pPRBlock->m_ConverterArray[nDev].fFailProb;
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_DCLINE]; nDev++)
		{
			bExist=0;
			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nFDev++)
			{
				if (stricmp(pPRBlock->m_ManualFaultArray[nManual].szName, pPRBlock->m_ManualFaultArray[nFDev].szName) != 0)
					continue;
				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex < 0)
					continue;

				if (pPRBlock->m_ManualFaultArray[nFDev].nFDevType == PR_DCLINE && pPRBlock->m_ManualFaultArray[nFDev].nFDevIndex == nDev)
				{
					bExist=1;
					break;
				}
			}
			if (!bExist)
				fStateProb *= pPRBlock->m_DCLineArray[nDev].fGoodProb;
			else
				fStateProb *= pPRBlock->m_DCLineArray[nDev].fFailProb;
		}

		return fStateProb;
	}
}
