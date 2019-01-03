#include <process.h>
#include "PRAdequacyStateEstimate.h"

extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	//////////////////////////////////////////////////////////////////////////
	//	计算母线功率时不考虑母线状态，但是调整过程中和事故统计中考虑母线状态
	void CPRAdequacyStateEstimate::CalculateBusPQ(tagPRBlock* pPRBlock, const unsigned char bAuxLoadAdjust, const unsigned char bEQGenAdjust, const unsigned char bEQLoadAdjust)
	{
		register int	i;
		int		nDev, nBus, nConverter;

		for (nBus=0; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
		{
			pPRBlock->m_ACBusArray[nBus].fLoadP=0;
			pPRBlock->m_ACBusArray[nBus].fLoadQ=0;
			pPRBlock->m_ACBusArray[nBus].fGenP=0;
			pPRBlock->m_ACBusArray[nBus].fGenQ=0;
			pPRBlock->m_ACBusArray[nBus].fMaxGenP=0;
			pPRBlock->m_ACBusArray[nBus].fMinGenP=0;
			pPRBlock->m_ACBusArray[nBus].fMinLoadP=0;
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
		{
			nConverter = -1;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_CONVERTER]; i++)
			{
				if (_stricmp(pPRBlock->m_GeneratorArray[nDev].szName, pPRBlock->m_ConverterArray[i].szName) == 0)
				{
					nConverter = i;
					break;
				}
			}
			if (nConverter >= 0)
				continue;

			nBus=pPRBlock->m_GeneratorArray[nDev].nBusIndex;
			if (nBus < 0 || pPRBlock->m_GeneratorArray[nDev].bOutage)
				continue;
			//if (pPRBlock->m_ACBusArray[nBus].bOutage)
			//	continue;

			if (!pPRBlock->m_GeneratorArray[nDev].bMSModel)
			{
				pPRBlock->m_ACBusArray[nBus].fGenP += pPRBlock->m_GeneratorArray[nDev].fP;
				pPRBlock->m_ACBusArray[nBus].fGenQ += pPRBlock->m_GeneratorArray[nDev].fQ;
				if (!bEQGenAdjust && pPRBlock->m_GeneratorArray[nDev].bEQGen)
				{
					pPRBlock->m_ACBusArray[nBus].fMaxGenP += pPRBlock->m_ACBusArray[nBus].fGenP;
					pPRBlock->m_ACBusArray[nBus].fMinGenP += pPRBlock->m_ACBusArray[nBus].fGenP;
				}
				else
				{
					pPRBlock->m_ACBusArray[nBus].fMaxGenP += pPRBlock->m_GeneratorArray[nDev].fPMax;
					pPRBlock->m_ACBusArray[nBus].fMinGenP += pPRBlock->m_GeneratorArray[nDev].fPMin;
				}
			}
			else
			{
				pPRBlock->m_ACBusArray[nBus].fGenP += pPRBlock->m_GeneratorArray[nDev].fMSPout;
				pPRBlock->m_ACBusArray[nBus].fGenQ += pPRBlock->m_GeneratorArray[nDev].fMSPout;
				pPRBlock->m_ACBusArray[nBus].fMaxGenP += pPRBlock->m_GeneratorArray[nDev].fMSPout;
				pPRBlock->m_ACBusArray[nBus].fMinGenP += pPRBlock->m_GeneratorArray[nDev].fMSPout;
			}
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_POWERLOAD]; nDev++)
		{
			nConverter = -1;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_CONVERTER]; i++)
			{
				if (_stricmp(pPRBlock->m_PowerLoadArray[nDev].szName, pPRBlock->m_ConverterArray[i].szName) == 0)
				{
					nConverter = i;
					break;
				}
			}
			if (nConverter >= 0)
				continue;

			nBus=pPRBlock->m_PowerLoadArray[nDev].nBusIndex;
			if (nBus < 0 || pPRBlock->m_PowerLoadArray[nDev].bOutage)
				continue;
			//if (pPRBlock->m_ACBusArray[nBus].bOutage)
			//	continue;

			if (!pPRBlock->m_PowerLoadArray[nDev].bMSModel)
			{
				pPRBlock->m_ACBusArray[nBus].fLoadP += pPRBlock->m_PowerLoadArray[nDev].fP;
				pPRBlock->m_ACBusArray[nBus].fLoadQ += pPRBlock->m_PowerLoadArray[nDev].fQ;
			}
			else
			{
				pPRBlock->m_ACBusArray[nBus].fLoadP += pPRBlock->m_PowerLoadArray[nDev].fMSPout;
				pPRBlock->m_ACBusArray[nBus].fLoadQ += pPRBlock->m_PowerLoadArray[nDev].fQ;
			}
			if (!bEQLoadAdjust && pPRBlock->m_PowerLoadArray[nDev].bEQLoad)
				pPRBlock->m_ACBusArray[nBus].fMinLoadP += pPRBlock->m_PowerLoadArray[nBus].fP;
			if (!bAuxLoadAdjust && pPRBlock->m_PowerLoadArray[nDev].bAuxLoad)
				pPRBlock->m_ACBusArray[nBus].fMinLoadP += pPRBlock->m_PowerLoadArray[nBus].fP;
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_CONVERTER]; nDev++)
		{
			nBus=pPRBlock->m_ConverterArray[nDev].nACBus;
			if (nBus < 0 || pPRBlock->m_ConverterArray[nDev].bOutage)
				continue;
			//if (pPRBlock->m_ACBusArray[nBus].bOutage)
			//	continue;

			if (pPRBlock->m_ConverterArray[nDev].nType == PRConverter_Type_Rectifier)
			{
				pPRBlock->m_ACBusArray[nBus].fLoadP += pPRBlock->m_ConverterArray[nDev].fConverterPower;
				pPRBlock->m_ACBusArray[nBus].fMinLoadP += pPRBlock->m_ConverterArray[nBus].fConverterPower;
			}
			else
			{
				pPRBlock->m_ACBusArray[nBus].fGenP += pPRBlock->m_ConverterArray[nDev].fConverterPower;
				pPRBlock->m_ACBusArray[nBus].fMaxGenP += pPRBlock->m_ConverterArray[nBus].fConverterPower;
				pPRBlock->m_ACBusArray[nBus].fMinGenP += pPRBlock->m_ConverterArray[nBus].fConverterPower;
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	//	平衡发电出力损失：
	//		1、在一个电岛内；
	//		2、先就近平衡再全网平衡
	void CPRAdequacyStateEstimate::BalanceLossGen(tagPRBlock* pPRBlock, const unsigned char bMIslandBalance, const int nFState, const double fLossGenP, const int nIsland, const char* lpszZone)
	{
		int		nBus;
		double	fAdP, fTotLoadP, fTotGenAvailP, fTotGenMaxCapP, fTotLossP;
		double	fAvailCap, fTotalAdP;

		fTotLossP=fLossGenP;

		double	fUnBalanceP = 0;

#ifdef _DEBUG
		Log(g_lpszLogFile, "        BalanceLossGen 平衡发电出力损失=%f\n", fLossGenP);
#endif

		if (strlen(lpszZone) > 0)
		{
			//	统计得到当前状态下系统总的可调发电容量
			//	发电机切除信息已经反映到PGenMax和AdjGenP中。
			fTotGenAvailP=fTotGenMaxCapP=0;
			for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
			{
				if (pPRBlock->m_ACBusArray[nBus].bOutage)				continue;
				if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)	continue;
				if (pPRBlock->m_ACBusArray[nBus].fMaxGenP < FLT_MIN)	continue;
				if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) != 0)
					continue;

				fAvailCap=pPRBlock->m_ACBusArray[nBus].fMaxGenP-(pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP);
				if (fAvailCap > 1)
				{
					fTotGenAvailP += fAvailCap;
					fTotGenMaxCapP += pPRBlock->m_ACBusArray[nBus].fMaxGenP;
				}
			}

#ifdef _AGCDEBUG
			if (bMIslandBalance)	Log(g_lpszLogFile, "        当前区域可用容量=%f[MaxCap=%f] 需增加发电出力或减少负荷功率=%f\n", fTotGenAvailP, fTotGenMaxCapP, fTotLossP);
#endif

			if (fTotGenAvailP > fTotLossP+fUnBalanceP)						//	当前可用容量大于容量缺口
			{
				fTotalAdP=0;
				for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)	//	分区内内按可调容量比例升发电机出力
				{
					if (pPRBlock->m_ACBusArray[nBus].bOutage)				continue;
					if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)	continue;
					if (pPRBlock->m_ACBusArray[nBus].fMaxGenP < FLT_MIN)	continue;
					if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) != 0)
						continue;

					fAvailCap=pPRBlock->m_ACBusArray[nBus].fMaxGenP-(pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP);
					if (fAvailCap > 1)
					{
						fAdP=(fTotLossP+fUnBalanceP)*fAvailCap/fTotGenAvailP;
						fTotalAdP += fAdP;

						pPRBlock->m_ACBusArray[nBus].fAdjGenP += fAdP;
						if (!bMIslandBalance)
							pPRBlock->m_FStateArray[nFState].fAgcInsGen += (float)fAdP;
						else
							pPRBlock->m_FStateArray[nFState].fMIInsGen += (float)fAdP;

#ifdef _AGCDEBUG
						if (bMIslandBalance)	Log(g_lpszLogFile, "            可降容量 大于 缺口【调发电】，区域内发电[%s]增加出力=%f\n", pPRBlock->m_ACBusArray[nBus].szName, fAdP);
#endif
					}
				}
#ifdef _AGCDEBUG
				if (bMIslandBalance)	Log(g_lpszLogFile, "        可降容量 大于 缺口【调发电】，最终增加出力=%f\n", fTotalAdP);
#endif
				fTotLossP=fUnBalanceP=0;
				return;
			}
			else if (fTotGenAvailP > FLT_MIN)
			{
				//	分区内内发电机出力升满
				for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
				{
					if (pPRBlock->m_ACBusArray[nBus].bOutage)				continue;
					if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)	continue;
					if (pPRBlock->m_ACBusArray[nBus].fMaxGenP < FLT_MIN)	continue;
					if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) != 0)
						continue;

					fAdP=pPRBlock->m_ACBusArray[nBus].fMaxGenP-(pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP);
					if (fAdP > 0.1)
					{
						pPRBlock->m_ACBusArray[nBus].fAdjGenP += fAdP;
						if (!bMIslandBalance)
							pPRBlock->m_FStateArray[nFState].fAgcInsGen += (float)fAdP;
						else
							pPRBlock->m_FStateArray[nFState].fMIInsGen += (float)fAdP;

#ifdef _AGCDEBUG
						if (bMIslandBalance)	Log(g_lpszLogFile, "            可降容量 小于 缺口【调发电】，区域内发电机[%s]增加满出力=%f\n", pPRBlock->m_ACBusArray[nBus].szName, fAdP);
#endif
					}
				}

				fTotLossP -= fTotGenAvailP;
			}
		}

		//	统计得到当前状态下系统总的可调发电容量
		//	发电机切除信息已经反映到PGenMax和AdjGenP中。
		fTotGenAvailP=fTotGenMaxCapP=0;
		for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
		{
			if (pPRBlock->m_ACBusArray[nBus].bOutage)				continue;
			if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)	continue;
			if (pPRBlock->m_ACBusArray[nBus].fMaxGenP < FLT_MIN)	continue;
			if (strlen(lpszZone) > 0)
			{
				if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) == 0)
					continue;
			}

			fTotGenAvailP += pPRBlock->m_ACBusArray[nBus].fMaxGenP-(pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP);
			fTotGenMaxCapP += pPRBlock->m_ACBusArray[nBus].fMaxGenP;
		}
#ifdef _AGCDEBUG
		if (bMIslandBalance)	Log(g_lpszLogFile, "        当前电网可用容量=%f[MaxCap==%f] 需增加发电出力或减少负荷功率=%f\n", fTotGenAvailP, fTotGenMaxCapP, fTotLossP);
#endif
		if (fTotGenAvailP > fTotLossP+fUnBalanceP)						//	当前可用容量大于容量缺口
		{
			for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)	//	分区内内按可调容量比例升发电机出力
			{
				if (pPRBlock->m_ACBusArray[nBus].bOutage)				continue;
				if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)	continue;
				if (pPRBlock->m_ACBusArray[nBus].fMaxGenP < FLT_MIN)	continue;
				if (strlen(lpszZone) > 0)
				{
					if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) == 0)
						continue;
				}

				fAdP=(fTotLossP+fUnBalanceP)*(pPRBlock->m_ACBusArray[nBus].fMaxGenP-(pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP))/fTotGenAvailP;
				if (fAdP > 0.1)
				{
					pPRBlock->m_ACBusArray[nBus].fAdjGenP += fAdP;
					if (!bMIslandBalance)
						pPRBlock->m_FStateArray[nFState].fAgcInsGen += (float)fAdP;
					else
						pPRBlock->m_FStateArray[nFState].fMIInsGen += (float)fAdP;

#ifdef _AGCDEBUG
					if (bMIslandBalance)	Log(g_lpszLogFile, "            可降容量 大于 缺口【调发电】，电网内发电[%s]增加出力=%f\n", pPRBlock->m_ACBusArray[nBus].szName, fAdP);
#endif
				}
			}
			fTotLossP=fUnBalanceP=0;
			return;
		}
		else if (fTotGenAvailP > FLT_MIN)
		{
			//	分区内内发电机出力升满
			for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
			{
				if (pPRBlock->m_ACBusArray[nBus].bOutage)				continue;
				if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)	continue;
				if (pPRBlock->m_ACBusArray[nBus].fMaxGenP < FLT_MIN)	continue;
				if (strlen(lpszZone) > 0)
				{
					if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) == 0)
						continue;
				}

				fAdP=pPRBlock->m_ACBusArray[nBus].fMaxGenP-(pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP);
				if (fAdP > 0.1)
				{
					pPRBlock->m_ACBusArray[nBus].fAdjGenP += fAdP;
					if (!bMIslandBalance)
						pPRBlock->m_FStateArray[nFState].fAgcInsGen += (float)fAdP;
					else
						pPRBlock->m_FStateArray[nFState].fMIInsGen += (float)fAdP;

#ifdef _AGCDEBUG
					if (bMIslandBalance)	Log(g_lpszLogFile, "            可降容量 小于 缺口【调发电】，电网内发电[%s]增加满出力=%f\n", pPRBlock->m_ACBusArray[nBus].szName, fAdP);
#endif
				}
			}

			fTotLossP -= fTotGenAvailP;
		}


		//////////////////////////////////////////////////////////////////////////
		//	使用负荷平衡功率缺额
		if (strlen(lpszZone) > 0)
		{
			fTotLoadP=0;
			for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
			{
				if (pPRBlock->m_ACBusArray[nBus].bOutage)							continue;
				if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)				continue;
				if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) != 0)	continue;

				if (pPRBlock->m_ACBusArray[nBus].fLoadP+pPRBlock->m_ACBusArray[nBus].fAdjLoadP+pPRBlock->m_ACBusArray[nBus].fRadP+pPRBlock->m_ACBusArray[nBus].fAdjRadP-pPRBlock->m_ACBusArray[nBus].fMinLoadP < 0.1 || pPRBlock->m_ACBusArray[nBus].nRadial != 0)
					continue;
				fTotLoadP += (pPRBlock->m_ACBusArray[nBus].fLoadP+pPRBlock->m_ACBusArray[nBus].fAdjLoadP+pPRBlock->m_ACBusArray[nBus].fRadP+pPRBlock->m_ACBusArray[nBus].fAdjRadP-pPRBlock->m_ACBusArray[nBus].fMinLoadP);
			}

#ifdef _AGCDEBUG
			if (bMIslandBalance)	Log(g_lpszLogFile, "            当前区域内总负荷=%f 容量缺口=%f\n", fTotLoadP, fTotLossP);
#endif

			if (fTotLoadP > fTotLossP+fUnBalanceP)
			{
				//	分区内内按比例切除
				for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
				{
					if (pPRBlock->m_ACBusArray[nBus].bOutage)							continue;
					if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)				continue;
					if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) != 0)	continue;

					if (pPRBlock->m_ACBusArray[nBus].fLoadP+pPRBlock->m_ACBusArray[nBus].fAdjLoadP+pPRBlock->m_ACBusArray[nBus].fRadP+pPRBlock->m_ACBusArray[nBus].fAdjRadP-pPRBlock->m_ACBusArray[nBus].fMinLoadP < FLT_MIN || pPRBlock->m_ACBusArray[nBus].nRadial != 0)
						continue;

					fAdP=(fTotLossP+fUnBalanceP)*(pPRBlock->m_ACBusArray[nBus].fLoadP+pPRBlock->m_ACBusArray[nBus].fAdjLoadP+pPRBlock->m_ACBusArray[nBus].fRadP+pPRBlock->m_ACBusArray[nBus].fAdjRadP-pPRBlock->m_ACBusArray[nBus].fMinLoadP)/fTotLoadP;
					if (fAdP >= 0.001)
					{
						pPRBlock->m_ACBusArray[nBus].fAdjLoadP -= fAdP;
						if (!bMIslandBalance)
							pPRBlock->m_FStateArray[nFState].fEnsCutLoad += (float)fAdP;
						else
							pPRBlock->m_FStateArray[nFState].fMIOutLoad += (float)fAdP;

						if (pPRBlock->m_ACBusArray[nBus].nZone >= 0)	pPRBlock->m_ZoneArray[pPRBlock->m_ACBusArray[nBus].nZone].fCutLoadP += (float)fAdP;

#ifdef _AGCDEBUG
						if (bMIslandBalance)	Log(g_lpszLogFile, "            可降容量 大于 缺口【调负荷】，区域内负荷[%s]减少功率=%f\n", pPRBlock->m_ACBusArray[nBus].szName, fAdP);
#endif
					}
				}
				fTotLossP=fUnBalanceP=0;
				return;
			}
			else if (fTotLoadP > FLT_MIN)
			{
				//	先将分区内的负荷全部切光
				for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
				{
					if (pPRBlock->m_ACBusArray[nBus].bOutage)							continue;
					if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)				continue;
					if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) != 0)	continue;
					if (pPRBlock->m_ACBusArray[nBus].fLoadP+pPRBlock->m_ACBusArray[nBus].fAdjLoadP+pPRBlock->m_ACBusArray[nBus].fRadP+pPRBlock->m_ACBusArray[nBus].fAdjRadP-pPRBlock->m_ACBusArray[nBus].fMinLoadP < FLT_MIN || pPRBlock->m_ACBusArray[nBus].nRadial != 0)
						continue;

					fAdP=pPRBlock->m_ACBusArray[nBus].fLoadP+pPRBlock->m_ACBusArray[nBus].fAdjLoadP+pPRBlock->m_ACBusArray[nBus].fRadP+pPRBlock->m_ACBusArray[nBus].fAdjRadP-pPRBlock->m_ACBusArray[nBus].fMinLoadP;
					if (fAdP > 0.1)
					{
						pPRBlock->m_ACBusArray[nBus].fAdjLoadP = (float)-fAdP;			//	全部切光
						if (!bMIslandBalance)
							pPRBlock->m_FStateArray[nFState].fEnsCutLoad += (float)fAdP;
						else
							pPRBlock->m_FStateArray[nFState].fMIOutLoad += (float)fAdP;

						if (pPRBlock->m_ACBusArray[nBus].nZone >= 0)	pPRBlock->m_ZoneArray[pPRBlock->m_ACBusArray[nBus].nZone].fCutLoadP += (float)fAdP;

#ifdef _AGCDEBUG
						if (bMIslandBalance)	Log(g_lpszLogFile, "            可降容量 小于 缺口【调负荷】，区域内负荷[%s]减少全部功率=%f\n", pPRBlock->m_ACBusArray[nBus].szName, fAdP);
#endif
					}
				}
				fTotLossP -= fTotLoadP;
			}
		}

		//	全网内按比例切除
		fTotLoadP=0;
		for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
		{
			if (pPRBlock->m_ACBusArray[nBus].bOutage)				continue;
			if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)	continue;
			if (pPRBlock->m_ACBusArray[nBus].nRadial != 0)			continue;

			fTotLoadP += (pPRBlock->m_ACBusArray[nBus].fLoadP+pPRBlock->m_ACBusArray[nBus].fAdjLoadP+pPRBlock->m_ACBusArray[nBus].fRadP+pPRBlock->m_ACBusArray[nBus].fAdjRadP-pPRBlock->m_ACBusArray[nBus].fMinLoadP);
		}
		if (fTotLoadP > FLT_MIN)
		{
			for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
			{
				if (pPRBlock->m_ACBusArray[nBus].bOutage)				continue;
				if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)	continue;
				if (pPRBlock->m_ACBusArray[nBus].nRadial != 0)			continue;
				fAdP=(fTotLossP+fUnBalanceP)*(pPRBlock->m_ACBusArray[nBus].fLoadP+pPRBlock->m_ACBusArray[nBus].fAdjLoadP+pPRBlock->m_ACBusArray[nBus].fRadP-pPRBlock->m_ACBusArray[nBus].fMinLoadP)/fTotLoadP;
				if (fAdP > 0.001)
				{
					pPRBlock->m_ACBusArray[nBus].fAdjLoadP -= (float)fAdP;
					if (!bMIslandBalance)
						pPRBlock->m_FStateArray[nFState].fEnsCutLoad += (float)fAdP;
					else
						pPRBlock->m_FStateArray[nFState].fMIOutLoad += (float)fAdP;

					if (pPRBlock->m_ACBusArray[nBus].nZone >= 0)	pPRBlock->m_ZoneArray[pPRBlock->m_ACBusArray[nBus].nZone].fCutLoadP += (float)fAdP;

#ifdef _AGCDEBUG
					if (bMIslandBalance)	Log(g_lpszLogFile, "            网内负荷[%s]减少功率=%f\n", pPRBlock->m_ACBusArray[nBus].szName, fAdP);
#endif
				}
			}
		}
		fTotLossP=fUnBalanceP=0;
	}

	//////////////////////////////////////////////////////////////////////////
	//	平衡负荷功率损失：
	//		1、在一个电岛内；
	//		2、先就近平衡再全网平衡
	void CPRAdequacyStateEstimate::BalanceLossLoad(tagPRBlock* pPRBlock, const unsigned char bMIslandBalance, const int nFState, const double fLossLoadP, const int nIsland, const char* lpszZone)
	{
		int		nBus;
		double	fAdP, fTotGenAvailP, fTotGenMinCapP, fTotLossP;
		double	fAvailCap, fTotalAdP;

		fTotLossP=fLossLoadP;

#ifdef _DEBUG
		Log(g_lpszLogFile, "    平衡负荷损失=%.3f\n", fLossLoadP);
#endif

		if (strlen(lpszZone) > 0)
		{
			//	统计得到当前状态下系统总的可调发电容量
			//	发电机切除信息已经反映到PGenMin和AdjGenP中。
			fTotGenAvailP=fTotGenMinCapP=0;
			for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
			{
				if (pPRBlock->m_ACBusArray[nBus].bOutage)	continue;
				if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)
					continue;
				if (strlen(lpszZone) > 0)
				{
					if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) != 0)
						continue;
				}

				fAvailCap=(pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP)-pPRBlock->m_ACBusArray[nBus].fMinGenP;
				if (fAvailCap > 1)
				{
					fTotGenAvailP += fAvailCap;
					fTotGenMinCapP += pPRBlock->m_ACBusArray[nBus].fMinGenP;
				}
			}

			// #ifdef _DEBUG
			// 		if (bMIslandBalance)	Log(g_lpszLogFile, "        平衡负荷功率损失=%f  区域当前可用容量=%f[MinCap=%f] 发电需降出力=%f\n", fTotLossP, fTotGenAvailP, fTotGenMinCapP, fTotLossP);
			// #endif

			if (fTotGenAvailP > fTotLossP)						//	当前可降容量大于容量缺口
			{
				fTotalAdP=0;
				for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)	//	分区内内按可调容量比例升发电机出力
				{
					if (pPRBlock->m_ACBusArray[nBus].bOutage)	continue;
					if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)
						continue;
					if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) != 0)
						continue;

					fAvailCap=(pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP)-pPRBlock->m_ACBusArray[nBus].fMinGenP;
					if (fAvailCap > 1)
					{
						fAdP=(fTotLossP)*fAvailCap/fTotGenAvailP;
						fTotalAdP += fAdP;

						pPRBlock->m_ACBusArray[nBus].fAdjGenP -= fAdP;
						if (!bMIslandBalance)
							pPRBlock->m_FStateArray[nFState].fAgcCutGen += (float)fAdP;
						else
							pPRBlock->m_FStateArray[nFState].fMICutGen += (float)fAdP;

						// #ifdef _DEBUG
						// 					if (bMIslandBalance)	Log(g_lpszLogFile, "            可降容量 大于 缺口【调发电】，区域内发电[%s]减少出力=%f\n", pPRBlock->m_ACBusArray[nBus].szName, fAdP);
						// #endif
					}
				}
				// #ifdef _DEBUG
				// 			if (bMIslandBalance)	Log(g_lpszLogFile, "        可降容量 大于 缺口【调发电】，区域内发电最终减少出力=%f\n", fTotalAdP);
				// #endif
				fTotLossP=0;
				return;
			}
			else
			{
				//	分区内内发电机出力升满
				for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
				{
					if (pPRBlock->m_ACBusArray[nBus].bOutage)	continue;
					if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)
						continue;
					if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) != 0)
						continue;

					fAdP=(pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP)-pPRBlock->m_ACBusArray[nBus].fMaxGenP;
					if (fAdP > 0.1)
					{
						pPRBlock->m_ACBusArray[nBus].fAdjGenP -= fAdP;
						if (!bMIslandBalance)
							pPRBlock->m_FStateArray[nFState].fAgcCutGen += (float)fAdP;
						else
							pPRBlock->m_FStateArray[nFState].fMICutGen += (float)fAdP;

						// #ifdef _DEBUG
						// 					if (bMIslandBalance)	Log(g_lpszLogFile, "            可降容量 小于 缺口【调发电】，区域内发电机[%s]减少最小出力=%f\n", pPRBlock->m_ACBusArray[nBus].szName, fAdP);
						// #endif
					}
				}

				fTotLossP -= fTotGenAvailP;
			}
		}

		//	统计得到当前状态下系统总的可调发电容量
		//	发电机切除信息已经反映到PGenMin和AdjGenP中。
		fTotGenAvailP=fTotGenMinCapP=0;
		for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
		{
			if (pPRBlock->m_ACBusArray[nBus].bOutage)	continue;
			if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)
				continue;
			if (strlen(lpszZone) > 0)
			{
				if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) == 0)
					continue;
			}

			fTotGenAvailP += (pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP)-pPRBlock->m_ACBusArray[nBus].fMinGenP;
			fTotGenMinCapP += pPRBlock->m_ACBusArray[nBus].fMinGenP;
		}
		// #ifdef _DEBUG
		// 	if (bMIslandBalance)	Log(g_lpszLogFile, "        平衡负荷功率损失=%f  电网当前可用容量=%f[MinCap=%f] 发电需降出力=%f\n", fTotLossP, fTotGenAvailP, fTotGenMinCapP, fTotLossP);
		// #endif

		if (fTotGenAvailP > fTotLossP)									//	当前可用容量大于容量缺口
		{
			for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)	//	按可调容量比例降发电机出力
			{
				if (pPRBlock->m_ACBusArray[nBus].bOutage)	continue;
				if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)
					continue;
				if (strlen(lpszZone) > 0)
				{
					if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) == 0)
						continue;
				}

				fAdP=(fTotLossP)*((pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP)-pPRBlock->m_ACBusArray[nBus].fMinGenP)/fTotGenAvailP;
				if (fAdP > 0.1)
				{
					pPRBlock->m_ACBusArray[nBus].fAdjGenP -= fAdP;
					if (!bMIslandBalance)
						pPRBlock->m_FStateArray[nFState].fAgcCutGen += (float)fAdP;
					else
						pPRBlock->m_FStateArray[nFState].fMICutGen += (float)fAdP;

					// #ifdef _DEBUG
					// 				if (bMIslandBalance)	Log(g_lpszLogFile, "            可降容量 大于 缺口【调发电】，电网内发电机[%s]减少出力=%f\n", pPRBlock->m_ACBusArray[nBus].szName, fAdP);
					// #endif
				}
			}
			fTotLossP=0;
			return;
		}
		else
		{
			//	分区内内发电机出力降到最小
			for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
			{
				if (pPRBlock->m_ACBusArray[nBus].bOutage)	continue;
				if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland)
					continue;
				if (pPRBlock->m_ACBusArray[nBus].fMaxGenP < FLT_MIN)
					continue;
				if (strlen(lpszZone) > 0)
				{
					if (_stricmp(pPRBlock->m_ACBusArray[nBus].szZone, lpszZone) == 0)
						continue;
				}

				fAdP=(pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP)-pPRBlock->m_ACBusArray[nBus].fMinGenP;
				if (fAdP > 0.1)
				{
					pPRBlock->m_ACBusArray[nBus].fAdjGenP -= fAdP;
					if (!bMIslandBalance)
						pPRBlock->m_FStateArray[nFState].fAgcCutGen += (float)fAdP;
					else
						pPRBlock->m_FStateArray[nFState].fMICutGen += (float)fAdP;

					// #ifdef _DEBUG
					// 				if (bMIslandBalance)	Log(g_lpszLogFile, "            可降容量 小于 缺口【调发电】，电网内发电机[%s]减少出力=%f\n", pPRBlock->m_ACBusArray[nBus].szName, fAdP);
					// #endif
				}
			}

			fTotLossP -= fTotGenAvailP;
		}
		fTotLossP=0;
	}

	void CPRAdequacyStateEstimate::BalanceIsland(tagPRBlock* pPRBlock, const double fMinGLRatio, const int nFState)
	{
		register int	i;
		int		nIsland, nDev;
		double	fTotIslandGen, fTotIslandLoad, fTotIslandDCLoad, fTotIslandDCGen;
		std::vector<float>	fBusLossArray;

		fBusLossArray.resize(pPRBlock->m_nRecordNum[PR_ACBUS]);
		for (nDev=0; nDev<(int)fBusLossArray.size(); nDev++)
			fBusLossArray[nDev]=0;

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
		{
			if (pPRBlock->m_ACLineArray[nDev].bOutage)
				continue;

			fBusLossArray[pPRBlock->m_ACLineArray[nDev].nIBus] += pPRBlock->m_ACLineArray[nDev].fLossP/2;
			fBusLossArray[pPRBlock->m_ACLineArray[nDev].nZBus] += pPRBlock->m_ACLineArray[nDev].fLossP/2;
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
		{
			if (pPRBlock->m_WindArray[nDev].bOutage)
				continue;

			fBusLossArray[pPRBlock->m_WindArray[nDev].nIBus] += pPRBlock->m_WindArray[nDev].fLossP/2;
			fBusLossArray[pPRBlock->m_WindArray[nDev].nZBus] += pPRBlock->m_WindArray[nDev].fLossP/2;
		}

		for (nIsland=1; nIsland<pPRBlock->m_nRecordNum[PR_ACISLAND]; nIsland++)
		{
			if (pPRBlock->m_ACIslandArray[nIsland].bDead)
				continue;

			fTotIslandGen = fTotIslandLoad = fTotIslandDCLoad = fTotIslandDCGen = 0;

			for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
			{
				if (pPRBlock->m_ACBusArray[nDev].nIsland != nIsland)
					continue;

				fTotIslandGen  += (pPRBlock->m_ACBusArray[nDev].fGenP +pPRBlock->m_ACBusArray[nDev].fAdjGenP);
				fTotIslandLoad += (pPRBlock->m_ACBusArray[nDev].fLoadP+pPRBlock->m_ACBusArray[nDev].fAdjLoadP+pPRBlock->m_ACBusArray[nDev].fRadP+pPRBlock->m_ACBusArray[nDev].fAdjRadP+fBusLossArray[nDev]);
			}
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
			{
				if (pPRBlock->m_HVDCArray[nDev].bOutage)
					continue;
				if (pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nRBus].nIsland == nIsland)
				{
					if (fabs(pPRBlock->m_HVDCArray[nDev].fPr) > FLT_MIN)
						fTotIslandDCLoad += fabs(pPRBlock->m_HVDCArray[nDev].fPr);
				}
				if (pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nIBus].nIsland == nIsland)
				{
					if (fabs(pPRBlock->m_HVDCArray[nDev].fPi) > FLT_MIN)
						fTotIslandDCGen += fabs(pPRBlock->m_HVDCArray[nDev].fPi);
				}
			}
			if (fabs(fTotIslandLoad) < FLT_MIN)
				continue;

#ifdef _MISLANDDEBUG
			Log(g_lpszLogFile, "    FState=%d 岛功率平衡[%d]: Gen=%f Load=%f\n", nFState, nIsland, fTotIslandGen+fTotIslandDCGen, fTotIslandLoad+fTotIslandDCLoad);
#endif
			if (fTotIslandGen+fTotIslandDCGen - (fTotIslandLoad+fTotIslandDCLoad) > 0 && fTotIslandGen+fTotIslandDCGen > 1.01*(fTotIslandLoad+fTotIslandDCLoad))	//	考虑1.%的线损率
			{
#ifdef _MISLANDDEBUG
				Log(g_lpszLogFile, "        岛功率平衡[1]      BalanceLossLoad = %f\n", fTotIslandGen - fTotIslandLoad);
#endif
				BalanceLossLoad(pPRBlock, 1, nFState, fTotIslandGen+fTotIslandDCGen - (fTotIslandLoad+fTotIslandDCLoad), nIsland, "");
			}
			else if ((fTotIslandLoad+fTotIslandDCLoad) - (fTotIslandGen+fTotIslandDCGen) > 1)
			{
				if ((fTotIslandGen+fTotIslandDCGen)/(fTotIslandLoad+fTotIslandDCLoad) < fMinGLRatio || (fTotIslandGen+fTotIslandDCGen) < FLT_MIN)
				{
#ifdef _MISLANDDEBUG
					Log(g_lpszLogFile, "        岛无电源      Black = %f\n", fTotIslandLoad);
#endif
					pPRBlock->m_FStateArray[nFState].fMIOutLoad += (float)fTotIslandLoad;
					for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
					{
						if (pPRBlock->m_ACBusArray[i].nIsland == nIsland)
						{
							if (pPRBlock->m_ACBusArray[i].nZone >= 0)
								pPRBlock->m_ZoneArray[pPRBlock->m_ACBusArray[i].nZone].fCutLoadP += (float)(pPRBlock->m_ACBusArray[i].fLoadP+pPRBlock->m_ACBusArray[i].fAdjLoadP+pPRBlock->m_ACBusArray[i].fRadP+pPRBlock->m_ACBusArray[i].fAdjRadP+fBusLossArray[i]);
						}
					}
					if (pPRBlock->m_nRecordNum[PR_FSTATEMISLAND] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEMISLAND)-1)
					{
						memset(&pPRBlock->m_FStateMIslandArray[pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]], 0, sizeof(tagPRFStateMIsland));
						pPRBlock->m_FStateMIslandArray[pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateMIslandArray[pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]].nFStateNo=nFState;
						pPRBlock->m_FStateMIslandArray[pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]].nOutageBus=i;
						pPRBlock->m_FStateMIslandArray[pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]].fOutageLoadP=(float)fTotIslandLoad;
						pPRBlock->m_nRecordNum[PR_FSTATEMISLAND]++;
					}
					else
						Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEMISLAND));
				}
				else
				{
#ifdef _MISLANDDEBUG
					Log(g_lpszLogFile, "        岛功率平衡[2]      BalanceLossGen = %f\n", fTotIslandLoad - fTotIslandGen);
#endif
					BalanceLossGen (pPRBlock, 1, nFState, fTotIslandLoad+fTotIslandDCLoad - (fTotIslandGen+fTotIslandDCGen), nIsland, "");
				}
			}
		}

		fBusLossArray.clear();
	}

	void CPRAdequacyStateEstimate::BalanceGenTrip(tagPRBlock* pPRBlock, const int nFState, const double fUnbalanceP)
	{
		int		nDev;
		double	fAdP, fTotLossGenP, fCurrent, fDCLinePwrI;

		double	fUnBalanceP = 0;
		for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
		{
			if (pPRBlock->m_ACBusArray[nDev].bOutage)	continue;
			if (fabs(pPRBlock->m_ACBusArray[nDev].fMaxGenP) <= FLT_MIN)
				continue;

			fAdP=pPRBlock->m_ACBusArray[nDev].fGenP+pPRBlock->m_ACBusArray[nDev].fAdjGenP;
			if (fAdP > pPRBlock->m_ACBusArray[nDev].fMaxGenP)
			{
#ifdef _DEBUG
				//Log(g_lpszLogFile, "        发电机[%s - %f]超限 GenP=%.2f GenPMax=%.2f\n", pPRBlock->m_ACBusArray[nDev].szName, pPRBlock->m_ACBusArray[nDev].fkV, fAdP, pPRBlock->m_ACBusArray[nDev].fGenPMax);
#endif
				fUnBalanceP += fAdP-pPRBlock->m_ACBusArray[nDev].fMaxGenP;
			}
		}

#ifdef _DEBUG
		if (fUnBalanceP > FLT_MIN)
		{
			//Log(g_lpszLogFile, "        发电机超限调整=%f\n", fUnBalanceP);
			fUnBalanceP=0;
		}
#endif

		//////////////////////////////////////////////////////////////////////////
		//	计算发电机出力损失，即需要增加的发电出力计算
		fTotLossGenP=0;

		//////////////////////////////////////////////////////////////////////////
		//	发电机两状态-停运，发电机多状态-设置出力，多状态发电机不参与调节
		//	1、发电机停运；
		//	2、发电机多状态功率比初值小
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
		{
			if (pPRBlock->m_GeneratorArray[nDev].nBusIndex < 0)
				continue;

			fTotLossGenP=0;
			if (pPRBlock->m_GeneratorArray[nDev].bOutage)
			{
				fTotLossGenP=pPRBlock->m_GeneratorArray[nDev].fP;
				pPRBlock->m_FStateArray[nFState].fFLossGenCap += pPRBlock->m_GeneratorArray[nDev].fPMax;
			}
			else if (pPRBlock->m_GeneratorArray[nDev].bMSModel && pPRBlock->m_GeneratorArray[nDev].fP > pPRBlock->m_GeneratorArray[nDev].fMSPout)
			{
				fTotLossGenP=pPRBlock->m_GeneratorArray[nDev].fP - pPRBlock->m_GeneratorArray[nDev].fMSPout;
			}

			if (fTotLossGenP < FLT_MIN)	//	无出力损失
				continue;
			pPRBlock->m_FStateArray[nFState].fFLossGen += (float)fTotLossGenP;
		}

		//////////////////////////////////////////////////////////////////////////
		//	负荷多状态，负荷多状态功率大于初态功率
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_POWERLOAD]; nDev++)
		{
			if (pPRBlock->m_PowerLoadArray[nDev].nBusIndex < 0)
				continue;

			fTotLossGenP=0;
			if (pPRBlock->m_PowerLoadArray[nDev].bMSModel && pPRBlock->m_PowerLoadArray[nDev].fMSPout > pPRBlock->m_PowerLoadArray[nDev].fP)
				fTotLossGenP=pPRBlock->m_PowerLoadArray[nDev].fMSPout-pPRBlock->m_PowerLoadArray[nDev].fP;

			if (fTotLossGenP < FLT_MIN)	//	无出力损失
				continue;
			pPRBlock->m_FStateArray[nFState].fFLossGen += (float)fTotLossGenP;
		}
		//////////////////////////////////////////////////////////////////////////
		//	直流停运或多状态，
		//	1、直流停运，逆变侧功率；
		//	2、直流多状态，逆变侧多状态功率小于初态功率
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
		{
			if (pPRBlock->m_HVDCArray[nDev].nIBus < 0)
				continue;
			if (pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nIBus].nIsland == pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nRBus].nIsland)
				continue;

			fCurrent=1000*pPRBlock->m_HVDCArray[nDev].fMSPout/pPRBlock->m_HVDCArray[nDev].fRectV;
			fDCLinePwrI=-(pPRBlock->m_HVDCArray[nDev].fMSPout-fCurrent*fCurrent*pPRBlock->m_HVDCArray[nDev].fR/1000000);

			fTotLossGenP=0;
			if (pPRBlock->m_HVDCArray[nDev].bOutage)
				fTotLossGenP=-pPRBlock->m_HVDCArray[nDev].fPi;
			else if (pPRBlock->m_HVDCArray[nDev].bMSModel && fDCLinePwrI > pPRBlock->m_HVDCArray[nDev].fPi)
				fTotLossGenP=fDCLinePwrI-pPRBlock->m_HVDCArray[nDev].fPi;

			if (fTotLossGenP < FLT_MIN)	//	无出力损失
				continue;
			pPRBlock->m_FStateArray[nFState].fFLossGen += (float)fTotLossGenP;
		}
		//	计算发电机出力损失
		//////////////////////////////////////////////////////////////////////////

		if (fabs(pPRBlock->m_FStateArray[nFState].fFLossGen) < fUnbalanceP)
			return;

#ifdef _AGCDEBUG
		Log(g_lpszLogFile, "    BalanceGenTrip 发电出力损失=%f 发电容量损失=%f\n", pPRBlock->m_FStateArray[nFState].fFLossGen, pPRBlock->m_FStateArray[nFState].fFLossGenCap);
#endif
		//if (pPRBlock->m_FStateArray[nFState].fLossGen > 550)
		//	ASSERT(FALSE);

		//////////////////////////////////////////////////////////////////////////
		//	一台机一台机平衡
		//	1、发电机停运；
		//	2、发电机多状态功率比初值小
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
		{
			if (pPRBlock->m_GeneratorArray[nDev].nBusIndex < 0)
				continue;

			fTotLossGenP=0;
			if (pPRBlock->m_GeneratorArray[nDev].bOutage)
				fTotLossGenP=pPRBlock->m_GeneratorArray[nDev].fP;
			else if (pPRBlock->m_GeneratorArray[nDev].bMSModel && pPRBlock->m_GeneratorArray[nDev].fP > pPRBlock->m_GeneratorArray[nDev].fMSPout)
				fTotLossGenP=pPRBlock->m_GeneratorArray[nDev].fP - pPRBlock->m_GeneratorArray[nDev].fMSPout;
			if (fTotLossGenP < FLT_MIN)	//	无出力损失
				continue;

			BalanceLossGen(pPRBlock, 0, nFState, fTotLossGenP, pPRBlock->m_ACBusArray[pPRBlock->m_GeneratorArray[nDev].nBusIndex].nIsland, pPRBlock->m_GeneratorArray[nDev].szZone);
		}

		//////////////////////////////////////////////////////////////////////////
		//	一个直流一个直流平衡，计算逆变侧功率
		//	1、直流停运；
		//	2、直流功率降低（逆变侧功率比初值fPwrI小）
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
		{
			if (pPRBlock->m_HVDCArray[nDev].nIBus < 0)
				continue;

			fCurrent=1000*pPRBlock->m_HVDCArray[nDev].fMSPout/pPRBlock->m_HVDCArray[nDev].fRectV;
			fDCLinePwrI=-(pPRBlock->m_HVDCArray[nDev].fMSPout-fCurrent*fCurrent*pPRBlock->m_HVDCArray[nDev].fR/1000000);

			fTotLossGenP=0;
			if (pPRBlock->m_HVDCArray[nDev].bOutage)
				fTotLossGenP=-pPRBlock->m_HVDCArray[nDev].fPi;
			else if (pPRBlock->m_HVDCArray[nDev].bMSModel && fDCLinePwrI > pPRBlock->m_HVDCArray[nDev].fPi)
				fTotLossGenP=fDCLinePwrI-pPRBlock->m_HVDCArray[nDev].fPi;
			if (fTotLossGenP < FLT_MIN)
				continue;

			BalanceLossGen(pPRBlock, 0, nFState, fTotLossGenP, pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nIBus].nIsland, pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nIBus].szZone);
		}

		//////////////////////////////////////////////////////////////////////////
		//	一个负荷一个负荷平衡
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_POWERLOAD]; nDev++)
		{
			if (pPRBlock->m_PowerLoadArray[nDev].nBusIndex < 0)
				continue;

			fTotLossGenP=0;
			if (pPRBlock->m_PowerLoadArray[nDev].bMSModel && pPRBlock->m_PowerLoadArray[nDev].fMSPout > pPRBlock->m_PowerLoadArray[nDev].fP)
				fTotLossGenP=pPRBlock->m_PowerLoadArray[nDev].fMSPout-pPRBlock->m_PowerLoadArray[nDev].fP;
			if (fTotLossGenP < FLT_MIN)
				continue;

			BalanceLossGen(pPRBlock, 0, nFState, fTotLossGenP, pPRBlock->m_ACBusArray[pPRBlock->m_PowerLoadArray[nDev].nBusIndex].nIsland, pPRBlock->m_ACBusArray[pPRBlock->m_PowerLoadArray[nDev].nBusIndex].szZone);
		}
	}

	void CPRAdequacyStateEstimate::BalanceLoadTrip(tagPRBlock* pPRBlock, const int nFState, const double fUnbalanceP)
	{
		int		nDev;

		//////////////////////////////////////////////////////////////////////////
		//	计算负荷功率损失，即需要减少发电
		double	fTotLossLoadP=0;

		//////////////////////////////////////////////////////////////////////////
		//	负荷两状态，负荷多状态，负荷多状态功率小于初态功率
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_POWERLOAD]; nDev++)
		{
			if (pPRBlock->m_PowerLoadArray[nDev].nBusIndex < 0)
				continue;

			fTotLossLoadP=0;
			if (pPRBlock->m_PowerLoadArray[nDev].bOutage)
				fTotLossLoadP=pPRBlock->m_PowerLoadArray[nDev].fP;
			else if (pPRBlock->m_PowerLoadArray[nDev].bMSModel && pPRBlock->m_PowerLoadArray[nDev].fMSPout < pPRBlock->m_PowerLoadArray[nDev].fP)
				fTotLossLoadP=pPRBlock->m_PowerLoadArray[nDev].fP-pPRBlock->m_PowerLoadArray[nDev].fMSPout;

			if (fTotLossLoadP < FLT_MIN)	//	没有损失
				continue;
			pPRBlock->m_FStateArray[nFState].fFLossLoad += (float)fTotLossLoadP;
		}
		//////////////////////////////////////////////////////////////////////////
		//	发电机多状态-设置出力，多状态发电机不参与调节
		//	发电机多状态功率比初值大
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
		{
			if (pPRBlock->m_GeneratorArray[nDev].nBusIndex < 0)
				continue;

			fTotLossLoadP=0;
			if (pPRBlock->m_GeneratorArray[nDev].bMSModel && pPRBlock->m_GeneratorArray[nDev].fMSPout > pPRBlock->m_GeneratorArray[nDev].fP)
				fTotLossLoadP=pPRBlock->m_GeneratorArray[nDev].fMSPout-pPRBlock->m_GeneratorArray[nDev].fP;

			if (fabs(fTotLossLoadP) < FLT_MIN)																				//	无功率损失
				continue;
			pPRBlock->m_FStateArray[nFState].fFLossLoad += (float)fTotLossLoadP;
		}
		//////////////////////////////////////////////////////////////////////////
		//	直流停运或多状态，
		//	1、直流停运，整流侧功率；
		//	2、直流多状态，整流侧多状态功率小于初态功率
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
		{
			if (pPRBlock->m_HVDCArray[nDev].nIBus < 0)
				continue;
			if (pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nIBus].nIsland == pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nRBus].nIsland)
				continue;

			fTotLossLoadP=0;
			if (pPRBlock->m_HVDCArray[nDev].bOutage)
				fTotLossLoadP=pPRBlock->m_HVDCArray[nDev].fPr;
			else if (pPRBlock->m_HVDCArray[nDev].bMSModel && pPRBlock->m_HVDCArray[nDev].fMSPout < pPRBlock->m_HVDCArray[nDev].fPr)
				fTotLossLoadP=pPRBlock->m_HVDCArray[nDev].fPr-pPRBlock->m_HVDCArray[nDev].fMSPout;

			if (fTotLossLoadP < FLT_MIN)	//	无出力损失
				continue;
			pPRBlock->m_FStateArray[nFState].fFLossLoad += (float)fTotLossLoadP;
		}
		//	计算负荷功率损失
		//////////////////////////////////////////////////////////////////////////

		if (pPRBlock->m_FStateArray[nFState].fFLossLoad < fUnbalanceP)
			return;

#ifdef _AGCDEBUG
		Log(g_lpszLogFile, "    负荷功率损失=%f 发电容量损失=%f\n", pPRBlock->m_FStateArray[nFState].fFLossLoad, pPRBlock->m_FStateArray[nFState].fFLossGenCap);
#endif

		//////////////////////////////////////////////////////////////////////////
		//	负荷两状态，负荷多状态，负荷多状态功率小于初态功率
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_POWERLOAD]; nDev++)
		{
			if (pPRBlock->m_PowerLoadArray[nDev].nBusIndex < 0)
				continue;

			fTotLossLoadP=0;
			if (pPRBlock->m_PowerLoadArray[nDev].bOutage)
				fTotLossLoadP=pPRBlock->m_PowerLoadArray[nDev].fP;
			else if (pPRBlock->m_PowerLoadArray[nDev].bMSModel && pPRBlock->m_PowerLoadArray[nDev].fMSPout < pPRBlock->m_PowerLoadArray[nDev].fP)
				fTotLossLoadP=pPRBlock->m_PowerLoadArray[nDev].fP-pPRBlock->m_PowerLoadArray[nDev].fMSPout;

			if (fTotLossLoadP < FLT_MIN)	//	没有损失
				continue;
			BalanceLossLoad(pPRBlock, 0, nFState, fTotLossLoadP, pPRBlock->m_ACBusArray[pPRBlock->m_PowerLoadArray[nDev].nBusIndex].nIsland, pPRBlock->m_ACBusArray[pPRBlock->m_PowerLoadArray[nDev].nBusIndex].szZone);
		}
		//////////////////////////////////////////////////////////////////////////
		//	发电机多状态-设置出力，多状态发电机不参与调节
		//	发电机多状态功率比初值大
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
		{
			if (pPRBlock->m_GeneratorArray[nDev].nBusIndex < 0)
				continue;

			fTotLossLoadP=0;
			if (pPRBlock->m_GeneratorArray[nDev].bMSModel && pPRBlock->m_GeneratorArray[nDev].fMSPout > pPRBlock->m_GeneratorArray[nDev].fP)
				fTotLossLoadP=pPRBlock->m_GeneratorArray[nDev].fMSPout-pPRBlock->m_GeneratorArray[nDev].fP;

			if (fabs(fTotLossLoadP) < FLT_MIN)																				//	无功率损失
				continue;
			BalanceLossLoad(pPRBlock, 0, nFState, fTotLossLoadP, pPRBlock->m_ACBusArray[pPRBlock->m_GeneratorArray[nDev].nBusIndex].nIsland, pPRBlock->m_ACBusArray[pPRBlock->m_GeneratorArray[nDev].nBusIndex].szZone);
		}
		//////////////////////////////////////////////////////////////////////////
		//	直流停运或多状态，
		//	1、直流停运，整流侧功率；
		//	2、直流多状态，整流侧多状态功率小于初态功率
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
		{
			if (pPRBlock->m_HVDCArray[nDev].nIBus < 0)
				continue;

			fTotLossLoadP=0;
			if (pPRBlock->m_HVDCArray[nDev].bOutage)
				fTotLossLoadP=pPRBlock->m_HVDCArray[nDev].fPr;
			else if (pPRBlock->m_HVDCArray[nDev].bMSModel && pPRBlock->m_HVDCArray[nDev].fMSPout < pPRBlock->m_HVDCArray[nDev].fPr)
				fTotLossLoadP=pPRBlock->m_HVDCArray[nDev].fPr-pPRBlock->m_HVDCArray[nDev].fMSPout;

			if (fTotLossLoadP < FLT_MIN)	//	无出力损失
				continue;
			BalanceLossLoad(pPRBlock, 0, nFState, fTotLossLoadP, pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nRBus].nIsland, pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nRBus].szZone);
		}
	}

	void CPRAdequacyStateEstimate::BalanceCommonFault(tagPRBlock* pPRBlock, const int nFState, const int nCommonFault)
	{
		register int	i;
		int		nBus;
		double	fPGap, fPTot, fAdP;
		std::vector<int>	nAdDevArray;

		if (pPRBlock->m_CommonFaultArray[nCommonFault].nDevIndex < 0 || pPRBlock->m_CommonFaultArray[nCommonFault].nDevIndex >= pPRBlock->m_nRecordNum[pPRBlock->m_CommonFaultArray[nCommonFault].nDevType])
			return;

		nAdDevArray.clear();
		switch (pPRBlock->m_CommonFaultArray[nCommonFault].nDevType)
		{
		case	PR_GENERATOR:
			fPGap = pPRBlock->m_GeneratorArray[pPRBlock->m_CommonFaultArray[nCommonFault].nDevIndex].fP;
			fPTot = 0;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_COMMONFAULT]; i++)
			{
				if (i == nCommonFault)
					continue;
				if (stricmp(pPRBlock->m_CommonFaultArray[i].szName, pPRBlock->m_CommonFaultArray[nCommonFault].szName) != 0)
					continue;
				if (pPRBlock->m_CommonFaultArray[i].nDeviceCommonType == PRCommonFault_DeviceCommonType_Resion)
					continue;

				if (pPRBlock->m_CommonFaultArray[i].nDevType == PR_POWERLOAD)
				{
					if (!pPRBlock->m_PowerLoadArray[pPRBlock->m_CommonFaultArray[i].nDevIndex].bOutage)
					{
						fPTot += pPRBlock->m_PowerLoadArray[pPRBlock->m_CommonFaultArray[i].nDevIndex].fP;
						nAdDevArray.push_back(pPRBlock->m_CommonFaultArray[i].nDevIndex);
					}
				}
			}

			if (fPGap < 0.1 || fPTot < 0.1)
				return;

			//#ifdef _DEBUG
			Log(g_lpszLogFile, "                功率共因，故障设备 = %s[%s] 损失发电功率=%f[%f]\n", g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_CommonFaultArray[nCommonFault].nDevType), pPRBlock->m_CommonFaultArray[nCommonFault].szDevName, fPGap, fPTot);
			//#endif
			if (fPTot > fPGap)
			{
				for (i=0; i<(int)nAdDevArray.size(); i++)
				{
					nBus = pPRBlock->m_PowerLoadArray[nAdDevArray[i]].nBusIndex;
					fAdP=fPGap*pPRBlock->m_PowerLoadArray[nAdDevArray[i]].fP/fPTot;
					if (fAdP > 0.1)
					{
						pPRBlock->m_ACBusArray[nBus].fAdjLoadP -= (float)fAdP;
						if (!pPRBlock->m_PowerLoadArray[nAdDevArray[i]].bEQLoad)
						{
							pPRBlock->m_FStateArray[nFState].fEnsCutLoad += (float)fAdP;
							if (pPRBlock->m_ACBusArray[nBus].nZone >= 0)	pPRBlock->m_ZoneArray[pPRBlock->m_ACBusArray[nBus].nZone].fCutLoadP += (float)fAdP;
						}
						BalanceLossLoad(pPRBlock, 0, nFState, fAdP, pPRBlock->m_ACBusArray[nBus].nIsland, pPRBlock->m_ACBusArray[nBus].szZone);
					}
				}
			}
			else
			{
				for (i=0; i<(int)nAdDevArray.size(); i++)
				{
					nBus = pPRBlock->m_PowerLoadArray[nAdDevArray[i]].nBusIndex;
					fAdP=pPRBlock->m_PowerLoadArray[nAdDevArray[i]].fP;
					if (fAdP > 0.1)
					{
						pPRBlock->m_ACBusArray[nBus].fAdjLoadP -= (float)fAdP;
						if (!pPRBlock->m_PowerLoadArray[nAdDevArray[i]].bEQLoad)
						{
							pPRBlock->m_FStateArray[nFState].fEnsCutLoad += (float)fAdP;
							if (pPRBlock->m_ACBusArray[nBus].nZone >= 0)	pPRBlock->m_ZoneArray[pPRBlock->m_ACBusArray[nBus].nZone].fCutLoadP += (float)fAdP;
						}
						BalanceLossLoad(pPRBlock, 0, nFState, fAdP, pPRBlock->m_ACBusArray[nBus].nIsland, pPRBlock->m_ACBusArray[nBus].szZone);
					}
				}
			}
			break;
		case	PR_POWERLOAD:
			fPGap = pPRBlock->m_PowerLoadArray[pPRBlock->m_CommonFaultArray[nCommonFault].nDevIndex].fP;
			fPTot = 0;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_COMMONFAULT]; i++)
			{
				if (i == nCommonFault)
					continue;
				if (stricmp(pPRBlock->m_CommonFaultArray[i].szName, pPRBlock->m_CommonFaultArray[nCommonFault].szName) != 0)
					continue;
				if (pPRBlock->m_CommonFaultArray[i].nDeviceCommonType == PRCommonFault_DeviceCommonType_Resion)
					continue;

				if (pPRBlock->m_CommonFaultArray[i].nDevType == PR_GENERATOR)
				{
					if (!pPRBlock->m_GeneratorArray[pPRBlock->m_CommonFaultArray[i].nDevIndex].bOutage)
					{
						fPTot += pPRBlock->m_GeneratorArray[pPRBlock->m_CommonFaultArray[i].nDevIndex].fP;
						nAdDevArray.push_back(pPRBlock->m_CommonFaultArray[i].nDevIndex);
					}
				}
			}

			if (fPGap < 0.1 || fPTot < 0.1)
				return;

			//#ifdef _DEBUG
			Log(g_lpszLogFile, "                功率共因，故障设备 = %s[%s]损失负荷功率=%f[%f]\n", g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_CommonFaultArray[nCommonFault].nDevType), pPRBlock->m_CommonFaultArray[nCommonFault].szDevName, fPGap, fPTot);
			//#endif // _DEBUG

			if (fPTot > fPGap)
			{
				for (i=0; i<(int)nAdDevArray.size(); i++)
				{
					nBus = pPRBlock->m_GeneratorArray[nAdDevArray[i]].nBusIndex;
					fAdP=fPGap*pPRBlock->m_GeneratorArray[nAdDevArray[i]].fP/fPTot;
					if (fAdP > 0.1)
					{
						pPRBlock->m_ACBusArray[nBus].fAdjGenP -= (float)fAdP;
						if (!pPRBlock->m_GeneratorArray[nAdDevArray[i]].bEQGen)
							pPRBlock->m_FStateArray[nFState].fAgcCutGen += (float)fAdP;
						BalanceLossGen(pPRBlock, 0, nFState, fAdP, pPRBlock->m_ACBusArray[nBus].nIsland, pPRBlock->m_ACBusArray[nBus].szZone);
					}
				}
			}
			else
			{
				for (i=0; i<(int)nAdDevArray.size(); i++)
				{
					nBus = pPRBlock->m_GeneratorArray[nAdDevArray[i]].nBusIndex;
					fAdP=pPRBlock->m_GeneratorArray[nAdDevArray[i]].fP;
					if (fAdP > 0.1)
					{
						pPRBlock->m_ACBusArray[nBus].fAdjGenP -= (float)fAdP;
						if (!pPRBlock->m_GeneratorArray[nAdDevArray[i]].bEQGen)
							pPRBlock->m_FStateArray[nFState].fAgcCutGen += (float)fAdP;
						BalanceLossGen(pPRBlock, 0, nFState, fAdP, pPRBlock->m_ACBusArray[nBus].nIsland, pPRBlock->m_ACBusArray[nBus].szZone);
					}
				}
			}
			break;
		}

		nAdDevArray.clear();
	}
}
