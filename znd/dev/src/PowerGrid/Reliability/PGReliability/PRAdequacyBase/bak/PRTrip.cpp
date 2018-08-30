#include "StdAfx.h"
#include <io.h>
#include "PRTrip.h"
#include "../../../Common/StringCommon.h"
#include "../../../Common/TinyXML/TinyXmlGlobal.h"

CPRTrip::CPRTrip(void)
{
	m_fMatZArray.clear();
}

CPRTrip::~CPRTrip(void)
{
	m_fMatZArray.clear();
}

void CPRTrip::PRTrip(tagPRBlock* pPRBlock, const double fDC2ACRatio, const int nTripMode, const double fDFThreshold, const double fDPThreshold)
{
	register int	i;
	clock_t	dBeg, dEnd;
	int		nDur;

	dBeg=clock();

	pPRBlock->m_nRecordNum[PR_TRIP]=0;
	pPRBlock->m_nRecordNum[PR_TRIPMISLAND]=0;
	pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]=0;

	m_LineDFArray.resize(pPRBlock->m_nRecordNum[PR_ACLINE]);
	m_TranDFArray.resize(pPRBlock->m_nRecordNum[PR_WIND]);
	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
	{
		m_LineDFArray[i].BusDFArray.clear();
		m_LineDFArray[i].LDFArray.clear();
		m_LineDFArray[i].TDFArray.clear();
	}
	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_WIND]; i++)
	{
		m_TranDFArray[i].BusDFArray.clear();
		m_TranDFArray[i].LDFArray.clear();
		m_TranDFArray[i].TDFArray.clear();
	}

	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		pPRBlock->m_ACLineArray[i].bOutage=0;
	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_WIND]; i++)
		pPRBlock->m_WindArray[i].bOutage=0;
	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_HVDC]; i++)
		pPRBlock->m_HVDCArray[i].bOutage=0;

	m_fMatZArray.resize(pPRBlock->m_nRecordNum[PR_ACBUS]*pPRBlock->m_nRecordNum[PR_ACBUS]+pPRBlock->m_nRecordNum[PR_ACBUS]+1);
	for (i=0; i<(int)m_fMatZArray.size(); i++)
		m_fMatZArray[i]=0;

	PRMemDBIsland(pPRBlock);
	m_DCNetwork.PRDCFlow(pPRBlock, 1);
	m_DCNetwork.PRDCMatZ(pPRBlock, 0, m_fMatZArray);

	dEnd=clock();
	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
	Log(g_lpszLogFile, "PRDCFlow & DCMatZ完成，耗时 %d 毫秒\n", nDur);

	OneBusDFactor(pPRBlock, fDFThreshold, fDPThreshold);

	dEnd=clock();
	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
	Log(g_lpszLogFile, "OneBusDFactor完成，耗时 %d 毫秒\n", nDur);

	dBeg=clock();
	OneBranTrip(pPRBlock, fDC2ACRatio, fDFThreshold, fDPThreshold);
	dEnd=clock();
	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
	Log(g_lpszLogFile, "OneBranTrip完成，耗时 %d 毫秒\n", nDur);

	if (nTripMode == 1)
	{
		dBeg=clock();
		TwoBranTrip(pPRBlock, fDC2ACRatio);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "TwoBranTrip完成，耗时 %d 毫秒\n", nDur);
	}

	PRMaint(pPRBlock);
}

void CPRTrip::OneBranTrip(tagPRBlock* pPRBlock, const double fDC2ACRatio, const double fDFThreshold, const double fDPThreshold)
{
	register int	i;
	int		nIsland, nDev, nBran;
	int		nCheck;
	double	fFactor, fPower, fDeltP;
	tagBranDFactor	dfBuf;

	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
	{
		pPRBlock->m_ACLineArray[i].bOutage=0;
		pPRBlock->m_ACLineArray[i].bTrMIsland=0;
	}
	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_WIND]; i++)
	{
		pPRBlock->m_WindArray[i].bOutage=0;
		pPRBlock->m_WindArray[i].bTrMIsland=0;
	}

	clock_t	dBeg, dEnd;
	int		nDur;

	dBeg=clock();

	PRMemDBIsland(pPRBlock);
	int	nNormIslandNum=pPRBlock->m_nRecordNum[PR_ACISLAND];
	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		pPRBlock->m_ACLineArray[i].bTrMIsland=OneTripIsland(pPRBlock, nNormIslandNum, PR_ACLINE, i);

	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_WIND]; i++)
		pPRBlock->m_WindArray[i].bTrMIsland=OneTripIsland(pPRBlock, nNormIslandNum, PR_WIND, i);
	PRMemDBIsland(pPRBlock);

	dEnd=clock();
	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
	Log(g_lpszLogFile, "    一阶孤岛判断完成，耗时 %d 毫秒\n", nDur);

	//	l开断支路，k影响支路
	//	Factor=(X(k, l)/x(k)) / (1-X(l, l)/x(l))
	for (nIsland=1; nIsland<pPRBlock->m_nRecordNum[PR_ACISLAND]; nIsland++)
	{
		for (nDev=0; nDev<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
		{
			if (pPRBlock->m_ACLineArray[nDev].nIsland != nIsland || pPRBlock->m_ACLineArray[nDev].bOutage)
				continue;
			if (pPRBlock->m_ACLineArray[nDev].fRated < FLT_MIN)
				continue;

			//	nBran=开断支路l
			for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nBran++)
			{
				if (nDev == nBran)
					continue;
				if (pPRBlock->m_ACLineArray[nBran].nIsland != nIsland)
					continue;
				if (pPRBlock->m_ACLineArray[nBran].bTrMIsland)
					continue;
				Trip1Factor(pPRBlock, PR_ACLINE, nDev, PR_ACLINE, nBran, fFactor);
				nCheck=_fpclass(fFactor);
				if (nCheck == _FPCLASS_SNAN || nCheck == _FPCLASS_QNAN || nCheck == _FPCLASS_NINF || nCheck == _FPCLASS_PINF)
					Log(g_lpszLogFile, "    Trip1Factor Error1    CalcLine=%s TripLine=%s\n", pPRBlock->m_ACLineArray[nDev].szName, pPRBlock->m_ACLineArray[nBran].szName);
				else
				{
					fDeltP=fFactor*pPRBlock->m_ACLineArray[nBran].fPfPi;
					fPower=pPRBlock->m_ACLineArray[nDev].fPfPi+fDeltP;
					//Log(g_lpszLogFile, "    Trip1  CalcLine=%s(%f) TripLine=%s IniP=%f DltP=%f FinP=%f\n", pPRBlock->m_LineArray[nDev].szName, pPRBlock->m_LineArray[nDev].fRated, pPRBlock->m_LineArray[nBran].szName, pPRBlock->m_LineArray[nDev].fPfPi, fDeltP, fPower);
					if (fabs(fDC2ACRatio*fPower) > pPRBlock->m_ACLineArray[nDev].fRated)
						Record1Trip(pPRBlock, PR_ACLINE, nDev, PR_ACLINE, nBran, (float)(fDC2ACRatio*fPower), (float)pPRBlock->m_ACLineArray[nDev].fRated);

					if (fabs(fFactor) >= fDFThreshold && fabs(fDeltP) > fDPThreshold)
					{
						dfBuf.nBran=nBran;		//	开断支路l
						dfBuf.fFactor=fFactor;
						dfBuf.fDeltP=fFactor*pPRBlock->m_ACLineArray[nBran].fPfPi;
						m_LineDFArray[nDev].LDFArray.push_back(dfBuf);

						pPRBlock->m_ACLineArray[nDev].nTrFactorNum++;
					}
				}
			}
			for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_WIND]; nBran++)
			{
				if (pPRBlock->m_WindArray[nBran].nIsland != nIsland)
					continue;
				if (pPRBlock->m_WindArray[nBran].bTrMIsland)
					continue;

				Trip1Factor(pPRBlock, PR_ACLINE, nDev, PR_WIND, nBran, fFactor);
				nCheck=_fpclass(fFactor);
				if (nCheck == _FPCLASS_SNAN || nCheck == _FPCLASS_QNAN || nCheck == _FPCLASS_NINF || nCheck == _FPCLASS_PINF)
					Log(g_lpszLogFile, "    Trip1Factor Error2    CalcLine=%s TripTran=%s\n", pPRBlock->m_ACLineArray[nDev].szName, pPRBlock->m_WindArray[nBran].szName);
				else
				{
					fDeltP=fFactor*pPRBlock->m_WindArray[nBran].fPfPi;
					fPower=pPRBlock->m_ACLineArray[nDev].fPfPi+fDeltP;
					if (fabs(fDC2ACRatio*fPower) > pPRBlock->m_ACLineArray[nDev].fRated)
						Record1Trip(pPRBlock, PR_ACLINE, nDev, PR_WIND, nBran, (float)(fDC2ACRatio*fPower), (float)pPRBlock->m_ACLineArray[nDev].fRated);

					if (fabs(fFactor) >= fDFThreshold && fabs(fDeltP) > fDPThreshold)
					{
						dfBuf.nBran=nBran;		//	开断支路l
						dfBuf.fFactor=fFactor;
						dfBuf.fDeltP=fFactor*pPRBlock->m_WindArray[nBran].fPfPi;
						m_LineDFArray[nDev].TDFArray.push_back(dfBuf);

						pPRBlock->m_ACLineArray[nDev].nTrFactorNum++;
					}
				}
			}
		}
		for (nDev=0; nDev<(int)pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
		{
			if (pPRBlock->m_WindArray[nDev].nIsland != nIsland || pPRBlock->m_WindArray[nDev].bOutage || pPRBlock->m_WindArray[nDev].bTrMIsland)
				continue;
			if (pPRBlock->m_WindArray[nDev].fRated < FLT_MIN)
				continue;

			for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nBran++)
			{
				if (pPRBlock->m_ACLineArray[nBran].bTrMIsland)
					continue;
				if (pPRBlock->m_ACLineArray[nBran].nIsland != nIsland)
					continue;

				Trip1Factor(pPRBlock, PR_WIND, nDev, PR_ACLINE, nBran, fFactor);
				nCheck=_fpclass(fFactor);
				if (nCheck == _FPCLASS_SNAN || nCheck == _FPCLASS_QNAN || nCheck == _FPCLASS_NINF || nCheck == _FPCLASS_PINF)
					Log(g_lpszLogFile, "    Trip1Factor Error3    CalcTran=%s TripLine=%s\n", pPRBlock->m_WindArray[nDev].szName, pPRBlock->m_ACLineArray[nBran].szName);
				else
				{
					fDeltP=fFactor*pPRBlock->m_ACLineArray[nBran].fPfPi;
					fPower=pPRBlock->m_WindArray[nDev].fPfPi+fDeltP;
					if (fabs(fDC2ACRatio*fPower) > pPRBlock->m_WindArray[nDev].fRated)
						Record1Trip(pPRBlock, PR_WIND, nDev, PR_ACLINE, nBran, (float)(fDC2ACRatio*fPower), pPRBlock->m_WindArray[nDev].fRated);

					if (fabs(fFactor) >= fDFThreshold && fabs(fDeltP) > fDPThreshold)
					{
						dfBuf.nBran=nBran;		//	开断支路l
						dfBuf.fFactor=fFactor;
						dfBuf.fDeltP=fFactor*pPRBlock->m_ACLineArray[nBran].fPfPi;
						m_TranDFArray[nDev].LDFArray.push_back(dfBuf);

						pPRBlock->m_WindArray[nDev].nTrFactorNum++;
					}
				}
			}
			for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_WIND]; nBran++)
			{
				if (nDev == nBran)
					continue;
				if (pPRBlock->m_WindArray[nBran].bTrMIsland)
					continue;
				if (pPRBlock->m_WindArray[nBran].nIsland != nIsland)
					continue;

				Trip1Factor(pPRBlock, PR_WIND, nDev, PR_WIND, nBran, fFactor);
				nCheck=_fpclass(fFactor);
				if (nCheck == _FPCLASS_SNAN || nCheck == _FPCLASS_QNAN || nCheck == _FPCLASS_NINF || nCheck == _FPCLASS_PINF)
					Log(g_lpszLogFile, "    Trip1Factor Error4    CalcTran=%s TripTran=%s\n", pPRBlock->m_WindArray[nDev].szName, pPRBlock->m_WindArray[nBran].szName);
				else
				{
					fDeltP=fFactor*pPRBlock->m_WindArray[nBran].fPfPi;
					fPower=pPRBlock->m_WindArray[nDev].fPfPi+fDeltP;
					if (fabs(fDC2ACRatio*fPower) > pPRBlock->m_WindArray[nDev].fRated)
						Record1Trip(pPRBlock, PR_WIND, nDev, PR_WIND, nBran, (float)(fDC2ACRatio*fPower), pPRBlock->m_WindArray[nDev].fRated);

					if (fabs(fFactor) >= fDFThreshold && fabs(fDeltP) > fDPThreshold)
					{
						dfBuf.nBran=nBran;		//	开断支路l
						dfBuf.fFactor=fFactor;
						dfBuf.fDeltP=fFactor*pPRBlock->m_WindArray[nBran].fPfPi;
						m_TranDFArray[nDev].TDFArray.push_back(dfBuf);

						pPRBlock->m_WindArray[nDev].nTrFactorNum++;
					}
				}
			}
		}
	}
}

unsigned char	isIntergerInArray(std::vector<int>& nArray, int nCheckInt)
{
	register int	i;
	for (i=0; i<(int)nArray.size(); i++)
	{
		if (nArray[i] == nCheckInt)
			return 1;
	}
	return 0;
}

void CPRTrip::TwoBranTrip(tagPRBlock* pPRBlock, const double fDC2ACRatio)
{
	register int	i;
	int		nRet;
	int		nIsland, nBran, nTrip;
	int		nTr1, nTr2;
	double	fFactor1, fFactor2, fPower, fDeltP;
	std::vector<short>	nLineIslandArray, nTranIslandArray;


	clock_t	dBeg, dEnd;
	int		nDur;

	PRMemDBIsland(pPRBlock);
	int		nIslandNum=pPRBlock->m_nRecordNum[PR_ACISLAND];

	nLineIslandArray.resize(pPRBlock->m_nRecordNum[PR_ACLINE]);
	nTranIslandArray.resize(pPRBlock->m_nRecordNum[PR_WIND]);
	for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		nLineIslandArray[i]=pPRBlock->m_ACLineArray[i].nIsland;
	for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
		nTranIslandArray[i]=pPRBlock->m_WindArray[i].nIsland;

	int		nMatLen=pPRBlock->m_nRecordNum[PR_ACLINE]+1+pPRBlock->m_nRecordNum[PR_WIND]+1;

//  std::vector<unsigned char>	nMIslandArray;
//  nMIslandArray.resize(nMatLen*nMatLen);
//  for (i=0; i<nMatLen*nMatLen; i++)
//  	nMIslandArray[i]=0;

// 	dBeg=clock();
// 
// 	for (nIsland=1; nIsland<nIslandNum; nIsland++)
// 	{
// 		for (nTr1=0; nTr1<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nTr1++)
// 		{
// 			if (nLineIslandArray[nTr1] != nIsland)
// 				continue;
// 			if (pPRBlock->m_LineArray[nTr1].bTrMIsland)
// 				continue;
// 
// 			for (nTr2=0; nTr2<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nTr2++)
// 			{
// 				if (nLineIslandArray[nTr2] != nIsland)
// 					continue;
// 				if (pPRBlock->m_LineArray[nTr2].bTrMIsland)
// 					continue;
// 				if (nTr1 == nTr2)
// 					continue;
// 
// 				nRet=TwoTripIsland(pPRBlock, nIslandNum, PR_ACLINE, nTr1, PR_ACLINE, nTr2);
// 				if (!nRet)
// 					nMIslandArray[(nTr1+1)*nMatLen+nTr2+1]=1;
// 			}
// 			for (nTr2=0; nTr2<(int)pPRBlock->m_nRecordNum[PR_WIND]; nTr2++)
// 			{
// 				if (nTranIslandArray[nTr2] != nIsland)
// 					continue;
// 				if (pPRBlock->m_WindArray[nTr2].bTrMIsland)
// 					continue;
// 
// 				nRet=TwoTripIsland(pPRBlock, nIslandNum, PR_ACLINE, nTr1, PR_WIND, nTr2);
// 				if (!nRet)
// 					nMIslandArray[(nTr1+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1]=1;
// 			}
// 		}
// 		for (nTr1=0; nTr1<(int)pPRBlock->m_nRecordNum[PR_WIND]; nTr1++)
// 		{
// 			if (nTranIslandArray[nTr1] != nIsland)
// 				continue;
// 			if (pPRBlock->m_WindArray[nTr1].bTrMIsland)
// 				continue;
// 
// 			for (nTr2=0; nTr2<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nTr2++)
// 			{
// 				if (nLineIslandArray[nTr2] != nIsland)
// 					continue;
// 				if (pPRBlock->m_LineArray[nTr2].bTrMIsland)
// 					continue;
// 
// 				nRet=TwoTripIsland(pPRBlock, nIslandNum, PR_WIND, nTr1, PR_ACLINE, nTr2);
// 				if (!nRet)
// 					nMIslandArray[(pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1)*nMatLen+nTr2+1]=1;
// 			}
// 			for (nTr2=0; nTr2<(int)pPRBlock->m_nRecordNum[PR_WIND]; nTr2++)
// 			{
// 				if (nTranIslandArray[nTr2] != nIsland)
// 					continue;
// 				if (pPRBlock->m_WindArray[nTr2].bTrMIsland)
// 					continue;
// 				if (nTr1 == nTr2)
// 					continue;
// 
// 				nRet=TwoTripIsland(pPRBlock, nIslandNum, PR_WIND, nTr1, PR_WIND, nTr2);
// 				if (!nRet)
// 					nMIslandArray[(pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1]=1;
// 			}
// 		}
// 	}
// 
// 	dEnd=clock();
// 	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
// 	Log(g_lpszLogFile, "    二阶孤岛判断完成，耗时 %d 毫秒\n", nDur);
// 
// 	return;

	dBeg=clock();
	std::vector<int>	nTripedArray;
	nTripedArray.clear();

	for (nIsland=1; nIsland<nIslandNum; nIsland++)
	{
		for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nBran++)
		{
			if (nLineIslandArray[nBran] != nIsland)
				continue;
			if (pPRBlock->m_ACLineArray[nBran].fRated <= FLT_MIN)
				continue;

			nTripedArray.clear();
			for (nTrip=0; nTrip<(int)m_LineDFArray[nBran].LDFArray.size(); nTrip++)
			{
				nTr1=m_LineDFArray[nBran].LDFArray[nTrip].nBran;
				if (pPRBlock->m_ACLineArray[nTr1].bTrMIsland)
					continue;

				for (i=0; i<(int)m_LineDFArray[nTr1].LDFArray.size(); i++)
				{
					nTr2=m_LineDFArray[nTr1].LDFArray[i].nBran;
					if (nTr2 == nBran)
						continue;
					if (pPRBlock->m_ACLineArray[nTr2].bTrMIsland)
						continue;

					if (isIntergerInArray(nTripedArray, (nTr1+1)*nMatLen+nTr2+1))
					{
						//Log(g_lpszLogFile, "        计算线路: %s Tr1=%d Tr2=%d已经计算过\n", pPRBlock->m_LineArray[nBran].szName, nTr1, nTr2);
						continue;
					}
					nTripedArray.push_back((nTr1+1)*nMatLen+nTr2+1);
					nTripedArray.push_back((nTr2+1)*nMatLen+nTr1+1);

					//Log(g_lpszLogFile, "    计算线路: %s Tr1=%d Tr2=%d\n", pPRBlock->m_LineArray[nBran].szName, nTr1, nTr2);

					nRet=TwoTripIsland(pPRBlock, nIslandNum, PR_ACLINE, nTr1, PR_ACLINE, nTr2);
					if (nRet == 0 && pPRBlock->m_ACLineArray[nBran].fRated > FLT_MIN)
					{
						Trip2Factor(pPRBlock, PR_ACLINE, nBran, PR_ACLINE, nTr1, PR_ACLINE, nTr2, fFactor1, fFactor2);
						fDeltP=fFactor1*pPRBlock->m_ACLineArray[nTr1].fPfPi + fFactor2*pPRBlock->m_ACLineArray[nTr2].fPfPi;
						fPower=pPRBlock->m_ACLineArray[nBran].fPfPi+fDeltP;

						//Log(g_lpszLogFile, "    Trip2  CalcLine=%s(%f) TripLine1=%s TripLine2=%s IniP=%f DltP=%f FinP=%f\n", 
						//	pPRBlock->m_LineArray[nBran].szName, pPRBlock->m_LineArray[nBran].fRated, pPRBlock->m_LineArray[nTr1].szName, pPRBlock->m_LineArray[nTr2].szName, 
						//	pPRBlock->m_LineArray[nBran].fPfPi, fDeltP, fPower);

						if (fabs(fDC2ACRatio*fPower) > pPRBlock->m_ACLineArray[nBran].fRated)
							Record2Trip(pPRBlock, PR_ACLINE, nBran, PR_ACLINE, nTr1, PR_ACLINE, nTr2, (float)(fDC2ACRatio*fPower), pPRBlock->m_ACLineArray[nBran].fRated);
					}
				}
				for (i=0; i<(int)m_LineDFArray[nTr1].TDFArray.size(); i++)
				{
					nTr2=m_LineDFArray[nTr1].TDFArray[i].nBran;
					if (pPRBlock->m_WindArray[nTr2].bTrMIsland)
						continue;

					if (isIntergerInArray(nTripedArray, (nTr1+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1))
						continue;
					nTripedArray.push_back((nTr1+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1);
					nTripedArray.push_back((pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1)*nMatLen+nTr1+1);

					nRet=TwoTripIsland(pPRBlock, nIslandNum, PR_ACLINE, nTr1, PR_WIND, nTr2);
					if (nRet == 0 && pPRBlock->m_ACLineArray[nBran].fRated > FLT_MIN)
					{
						Trip2Factor(pPRBlock, PR_ACLINE, nBran, PR_ACLINE, nTr1, PR_WIND, nTr2, fFactor1, fFactor2);
						fPower=pPRBlock->m_ACLineArray[nBran].fPfPi+fFactor1*pPRBlock->m_ACLineArray[nTr1].fPfPi + fFactor2*pPRBlock->m_WindArray[nTr2].fPfPi;
						if (fabs(fDC2ACRatio*fPower) > pPRBlock->m_ACLineArray[nBran].fRated)
							Record2Trip(pPRBlock, PR_ACLINE, nBran, PR_ACLINE, nTr1, PR_WIND, nTr2, (float)(fDC2ACRatio*fPower), pPRBlock->m_ACLineArray[nBran].fRated);
					}
				}
			}
			for (nTrip=0; nTrip<(int)m_LineDFArray[nBran].TDFArray.size(); nTrip++)
			{
				nTr1=m_LineDFArray[nBran].TDFArray[nTrip].nBran;
				if (pPRBlock->m_WindArray[nTr1].bTrMIsland)
					continue;
				for (i=0; i<(int)m_TranDFArray[nTr1].LDFArray.size(); i++)
				{
					nTr2=m_TranDFArray[nTr1].LDFArray[i].nBran;
					if (pPRBlock->m_ACLineArray[nTr2].bTrMIsland)
						continue;
					if (nTr2 == nBran)
						continue;

					if (isIntergerInArray(nTripedArray, (pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1)*nMatLen+nTr2+1))
						continue;
					nTripedArray.push_back((pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1)*nMatLen+nTr2+1);
					nTripedArray.push_back((nTr2+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1);

					nRet=TwoTripIsland(pPRBlock, nIslandNum, PR_WIND, nTr1, PR_ACLINE, nTr2);
					if (nRet == 0 && pPRBlock->m_ACLineArray[nBran].fRated > FLT_MIN)
					{
						Trip2Factor(pPRBlock, PR_ACLINE, nBran, PR_WIND, nTr1, PR_ACLINE, nTr2, fFactor1, fFactor2);
						fPower=pPRBlock->m_ACLineArray[nBran].fPfPi + fFactor1*pPRBlock->m_WindArray[nTr1].fPfPi + fFactor2*pPRBlock->m_ACLineArray[nTr2].fPfPi;
						if (fabs(fDC2ACRatio*fPower) > pPRBlock->m_ACLineArray[nBran].fRated)
							Record2Trip(pPRBlock, PR_ACLINE, nBran, PR_WIND, nTr1, PR_ACLINE, nTr2, (float)(fDC2ACRatio*fPower), pPRBlock->m_ACLineArray[nBran].fRated);
					}
				}
				for (i=0; i<(int)m_TranDFArray[nTr1].TDFArray.size(); i++)
				{
					nTr2=m_TranDFArray[nTr1].TDFArray[i].nBran;
					if (pPRBlock->m_WindArray[nTr2].bTrMIsland)
						continue;

					if (isIntergerInArray(nTripedArray, (pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1))
						continue;
					nTripedArray.push_back((pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1);
					nTripedArray.push_back((pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1);

					nRet=TwoTripIsland(pPRBlock, nIslandNum, PR_WIND, nTr1, PR_WIND, nTr2);
					if (nRet == 0 && pPRBlock->m_ACLineArray[nBran].fRated > FLT_MIN)
					{
						Trip2Factor(pPRBlock, PR_ACLINE, nBran, PR_WIND, nTr1, PR_WIND, nTr2, fFactor1, fFactor2);
						fPower=pPRBlock->m_ACLineArray[nBran].fPfPi + fFactor1*pPRBlock->m_WindArray[nTr1].fPfPi + fFactor2*pPRBlock->m_WindArray[nTr2].fPfPi;
						if (fabs(fDC2ACRatio*fPower) > pPRBlock->m_ACLineArray[nBran].fRated)
							Record2Trip(pPRBlock, PR_ACLINE, nBran, PR_WIND, nTr1, PR_WIND, nTr2, (float)(fDC2ACRatio*fPower), pPRBlock->m_ACLineArray[nBran].fRated);
					}
				}
			}

			if (nBran % 100 == 0)
			{
				dEnd=clock();
				nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
				Log(g_lpszLogFile, "    Line[%d] 耗时%d毫秒\n", nBran, nDur);
			}
		}

		for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_WIND]; nBran++)
		{
			if (nTranIslandArray[nBran] != nIsland)
				continue;
			if (pPRBlock->m_WindArray[nBran].fRated <= FLT_MIN)
				continue;

			nTripedArray.clear();
			for (nTrip=0; nTrip<(int)m_TranDFArray[nBran].LDFArray.size(); nTrip++)
			{
				nTr1=m_TranDFArray[nBran].LDFArray[nTrip].nBran;
				if (pPRBlock->m_ACLineArray[nTr1].bTrMIsland)
					continue;

				for (i=0; i<(int)m_LineDFArray[nTr1].LDFArray.size(); i++)
				{
					nTr2=m_LineDFArray[nTr1].LDFArray[i].nBran;
					if (pPRBlock->m_ACLineArray[nTr2].bTrMIsland)
						continue;

					if (isIntergerInArray(nTripedArray, (nTr1+1)*nMatLen+nTr2+1))
						continue;
					nTripedArray.push_back((nTr1+1)*nMatLen+nTr2+1);
					nTripedArray.push_back((nTr2+1)*nMatLen+nTr1+1);

					nRet=TwoTripIsland(pPRBlock, nIslandNum, PR_ACLINE, nTr1, PR_ACLINE, nTr2);
					if (nRet == 0 && pPRBlock->m_WindArray[nBran].fRated > FLT_MIN)
					{
						Trip2Factor(pPRBlock, PR_WIND, nBran, PR_ACLINE, nTr1, PR_ACLINE, nTr2, fFactor1, fFactor2);
						fPower=pPRBlock->m_WindArray[nBran].fPfPi + fFactor1*pPRBlock->m_ACLineArray[nTr1].fPfPi + fFactor2*pPRBlock->m_ACLineArray[nTr2].fPfPi;
						if (fabs(fDC2ACRatio*fPower) > pPRBlock->m_WindArray[nBran].fRated)
							Record2Trip(pPRBlock, PR_WIND, nBran, PR_ACLINE, nTr1, PR_ACLINE, nTr2, (float)(fDC2ACRatio*fPower), pPRBlock->m_WindArray[nBran].fRated);
					}
				}
				for (i=0; i<(int)m_LineDFArray[nTr1].TDFArray.size(); i++)
				{
					nTr2=m_LineDFArray[nTr1].TDFArray[i].nBran;
					if (pPRBlock->m_WindArray[nTr2].bTrMIsland)
						continue;
					if (nTr2 == nBran)
						continue;

					if (isIntergerInArray(nTripedArray, (nTr1+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1))
						continue;
					nTripedArray.push_back((nTr1+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1);
					nTripedArray.push_back((pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1)*nMatLen+nTr1+1);

					nRet=TwoTripIsland(pPRBlock, nIslandNum, PR_ACLINE, nTr1, PR_WIND, nTr2);
					if (nRet == 0 && pPRBlock->m_WindArray[nBran].fRated > FLT_MIN)
					{
						Trip2Factor(pPRBlock, PR_WIND, nBran, PR_ACLINE, nTr1, PR_WIND, nTr2, fFactor1, fFactor2);
						fPower=pPRBlock->m_WindArray[nBran].fPfPi + fFactor1*pPRBlock->m_ACLineArray[nTr1].fPfPi + fFactor2*pPRBlock->m_WindArray[nTr2].fPfPi;
						if (fabs(fDC2ACRatio*fPower) > pPRBlock->m_WindArray[nBran].fRated)
							Record2Trip(pPRBlock, PR_WIND, nBran, PR_ACLINE, nTr1, PR_WIND, nTr2, (float)(fDC2ACRatio*fPower), pPRBlock->m_WindArray[nBran].fRated);
					}
				}
			}
			for (nTrip=0; nTrip<(int)m_TranDFArray[nBran].TDFArray.size(); nTrip++)
			{
				nTr1=m_TranDFArray[nBran].TDFArray[nTrip].nBran;
				if (pPRBlock->m_WindArray[nTr1].bTrMIsland)
					continue;

				for (i=0; i<(int)m_TranDFArray[nTr1].LDFArray.size(); i++)
				{
					nTr2=m_TranDFArray[nTr1].LDFArray[i].nBran;
					if (pPRBlock->m_ACLineArray[nTr2].bTrMIsland)
						continue;

					if (isIntergerInArray(nTripedArray, (pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1)*nMatLen+nTr2+1))
						continue;
					nTripedArray.push_back((pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1)*nMatLen+nTr2+1);
					nTripedArray.push_back((nTr2+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1);

					nRet=TwoTripIsland(pPRBlock, nIslandNum, PR_WIND, nTr1, PR_ACLINE, nTr2);
					if (nRet == 0 && pPRBlock->m_WindArray[nBran].fRated > FLT_MIN)
					{
						Trip2Factor(pPRBlock, PR_WIND, nBran, PR_WIND, nTr1, PR_ACLINE, nTr2, fFactor1, fFactor2);
						fPower=pPRBlock->m_WindArray[nBran].fPfPi + fFactor1*pPRBlock->m_WindArray[nTr1].fPfPi + fFactor2*pPRBlock->m_ACLineArray[nTr2].fPfPi;
						if (fabs(fDC2ACRatio*fPower) > pPRBlock->m_WindArray[nBran].fRated)
							Record2Trip(pPRBlock, PR_WIND, nBran, PR_WIND, nTr1, PR_ACLINE, nTr2, (float)(fDC2ACRatio*fPower), pPRBlock->m_WindArray[nBran].fRated);
					}
				}
				for (i=0; i<(int)m_TranDFArray[nTr1].TDFArray.size(); i++)
				{
					nTr2=m_TranDFArray[nTr1].TDFArray[i].nBran;
					if (pPRBlock->m_WindArray[nTr2].bTrMIsland)
						continue;
					if (nTr2 == nBran)
						continue;

					if (isIntergerInArray(nTripedArray, (pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1))
						continue;
					nTripedArray.push_back((pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1);
					nTripedArray.push_back((pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr2+1)*nMatLen+pPRBlock->m_nRecordNum[PR_ACLINE]+1+nTr1+1);

					nRet=TwoTripIsland(pPRBlock, nIslandNum, PR_WIND, nTr1, PR_WIND, nTr2);
					if (nRet == 0 && pPRBlock->m_WindArray[nBran].fRated > FLT_MIN)
					{
						Trip2Factor(pPRBlock, PR_WIND, nBran, PR_WIND, nTr1, PR_WIND, nTr2, fFactor1, fFactor2);
						fPower=pPRBlock->m_WindArray[nBran].fPfPi + fFactor1*pPRBlock->m_WindArray[nTr1].fPfPi + fFactor2*pPRBlock->m_WindArray[nTr2].fPfPi;
						if (fabs(fDC2ACRatio*fPower) > pPRBlock->m_WindArray[nBran].fRated)
							Record2Trip(pPRBlock, PR_WIND, nBran, PR_WIND, nTr1, PR_WIND, nTr2, (float)(fDC2ACRatio*fPower), pPRBlock->m_WindArray[nBran].fRated);
					}
				}
			}

			if (nBran % 100 == 0)
			{
				dEnd=clock();
				nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
				Log(g_lpszLogFile, "    Tran[%d] 耗时%d毫秒\n", nBran, nDur);
			}
		}
	}
	nTripedArray.clear();
}

int CPRTrip::OneTripIsland(tagPRBlock* pPRBlock, const int nPrevIslandNum, const unsigned char nBTyp, const int nBIdx)
{
	register int	i, j;
	unsigned char	bExist;

	if (nBTyp == PR_ACLINE)
		pPRBlock->m_ACLineArray[nBIdx].bOutage=1;
	else
		pPRBlock->m_WindArray[nBIdx].bOutage=1;

	PRMemDBIsland(pPRBlock);

	if (nBTyp == PR_ACLINE)
		pPRBlock->m_ACLineArray[nBIdx].bOutage=0;
	else
		pPRBlock->m_WindArray[nBIdx].bOutage=0;

	if (pPRBlock->m_nRecordNum[PR_ACISLAND] != nPrevIslandNum)
	{
		bExist=0;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_TRIP]; i++)
		{
			if (pPRBlock->m_TripModeArray[i].nTripDevNum == 1 &&
				pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB1Typ == nBTyp &&
				pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB1Idx == nBIdx)
			{
				bExist=1;
				break;
			}
		}

		if (!bExist && pPRBlock->m_nRecordNum[PR_TRIP] < PRGetTableMax(PR_TRIP)-1)
		{
			memset(&pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]], 0, sizeof(tagPRTrip));
			for (i=1; i<(int)pPRBlock->m_nRecordNum[PR_ACISLAND]; i++)
			{
				if (pPRBlock->m_ACIslandArray[i].bDead || pPRBlock->m_ACIslandArray[i].nSwingBus <= 0)
				{
					pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].fOutageLoadP += (float)pPRBlock->m_ACIslandArray[i].fLoadP;
					for (j=1; j<pPRBlock->m_nRecordNum[PR_ACBUS]; j++)
					{
						if (pPRBlock->m_ACBusArray[j].nIsland == i)
						{
							//if (pPRBlock->m_nRecordNum[PR_TRIPMISLAND] < PRGetTableMax(PR_TRIPMISLAND)-1)
							//if (!pPRBlock->m_ACBusArray[j].bDCBus)
							{
								memset(&pPRBlock->m_TripMIslandArray[pPRBlock->m_nRecordNum[PR_TRIPMISLAND]], 0, sizeof(tagPRTripMIsland));
								pPRBlock->m_TripMIslandArray[pPRBlock->m_nRecordNum[PR_TRIPMISLAND]].nTrip=pPRBlock->m_nRecordNum[PR_TRIP];
								pPRBlock->m_TripMIslandArray[pPRBlock->m_nRecordNum[PR_TRIPMISLAND]].nOutageBus=j;
								pPRBlock->m_TripMIslandArray[pPRBlock->m_nRecordNum[PR_TRIPMISLAND]].fOutageLoadP=(float)pPRBlock->m_ACBusArray[j].fLoadP;
								pPRBlock->m_nRecordNum[PR_TRIPMISLAND]++;
							}
						}
					}
				}
			}

			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nFaultType=PRTrip_FaultType_MIsland;
			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTripDevNum=1;
			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB1Typ=nBTyp;
			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB1Idx=nBIdx;
			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB2Typ=0;
			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB2Idx=0;
			pPRBlock->m_nRecordNum[PR_TRIP]++;
		}

		return 1;
	}
	return 0;
}

int CPRTrip::TwoTripIsland(tagPRBlock* pPRBlock, const int nPrevIslandNum, const unsigned char nB1Typ, const int nB1Idx, const unsigned char nB2Typ, const int nB2Idx)
{
	register int	i, j;
	//clock_t	dBeg, dEnd;
	//int		nDur;
	//dBeg=clock();

// 	for (i=0; i<(int)m_TripModeArray.size(); i++)
// 	{
// 		if (nB1Typ == m_TripModeArray[i].nB1Type && nB1Idx == m_TripModeArray[i].nB1Idx && nB2Typ == m_TripModeArray[i].nB2Type && nB2Idx == m_TripModeArray[i].nB2Idx ||
// 			nB1Typ == m_TripModeArray[i].nB2Type && nB1Idx == m_TripModeArray[i].nB2Idx && nB2Typ == m_TripModeArray[i].nB1Type && nB2Idx == m_TripModeArray[i].nB1Idx)
// 		{
// 			if (m_TripModeArray[i].bMIsland)
// 				return -1;
// 			return 0;
// 		}
// 	}

	if (nB1Typ == PR_ACLINE)
		pPRBlock->m_ACLineArray[nB1Idx].bOutage=1;
	else
		pPRBlock->m_WindArray[nB1Idx].bOutage=1;

	if (nB2Typ == PR_ACLINE)
		pPRBlock->m_ACLineArray[nB2Idx].bOutage=1;
	else
		pPRBlock->m_WindArray[nB2Idx].bOutage=1;

	PRMemDBIsland(pPRBlock);

	if (nB1Typ == PR_ACLINE)
		pPRBlock->m_ACLineArray[nB1Idx].bOutage=0;
	else
		pPRBlock->m_WindArray[nB1Idx].bOutage=0;

	if (nB2Typ == PR_ACLINE)
		pPRBlock->m_ACLineArray[nB2Idx].bOutage=0;
	else
		pPRBlock->m_WindArray[nB2Idx].bOutage=0;

	//dEnd=clock();
	//nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
	//Log(g_lpszLogFile, "DCTripIsland耗时%d毫秒\n", nDur);

	if (pPRBlock->m_nRecordNum[PR_ACISLAND] != nPrevIslandNum)
	{
		memset(&pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]], 0, sizeof(tagPRTrip));
		for (i=1; i<(int)pPRBlock->m_nRecordNum[PR_ACISLAND]; i++)
		{
			if (pPRBlock->m_ACIslandArray[i].bDead)
				pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].fOutageLoadP += (float)pPRBlock->m_ACIslandArray[i].fLoadP;
		}

		if (pPRBlock->m_nRecordNum[PR_TRIP] < PRGetTableMax(PR_TRIP)-1)
		{
			memset(&pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]], 0, sizeof(tagPRTrip));
			for (i=1; i<(int)pPRBlock->m_nRecordNum[PR_ACISLAND]; i++)
			{
				if (pPRBlock->m_ACIslandArray[i].bDead || pPRBlock->m_ACIslandArray[i].nSwingBus <= 0)
				{
					pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].fOutageLoadP += (float)pPRBlock->m_ACIslandArray[i].fLoadP;
					for (j=0; j<pPRBlock->m_nRecordNum[PR_ACBUS]; j++)
					{
						if (pPRBlock->m_ACBusArray[j].nIsland == i)
						{
							//if (!pPRBlock->m_ACBusArray[j].bDCBus)
							{
								if (pPRBlock->m_nRecordNum[PR_TRIPMISLAND] < PRGetTableMax(PR_TRIPMISLAND)-1)
								{
									memset(&pPRBlock->m_TripMIslandArray[pPRBlock->m_nRecordNum[PR_TRIPMISLAND]], 0, sizeof(tagPRTripMIsland));
									pPRBlock->m_TripMIslandArray[pPRBlock->m_nRecordNum[PR_TRIPMISLAND]].nTrip=pPRBlock->m_nRecordNum[PR_TRIP];
									pPRBlock->m_TripMIslandArray[pPRBlock->m_nRecordNum[PR_TRIPMISLAND]].nOutageBus=j;
									pPRBlock->m_TripMIslandArray[pPRBlock->m_nRecordNum[PR_TRIPMISLAND]].fOutageLoadP=(float)pPRBlock->m_ACBusArray[j].fLoadP;
									pPRBlock->m_nRecordNum[PR_TRIPMISLAND]++;
								}
							}
						}
					}
				}
			}

			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nFaultType=PRTrip_FaultType_MIsland;
			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTripDevNum=2;
			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB1Typ=nB1Typ;
			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB1Idx=nB1Idx;
			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB2Typ=nB2Typ;
			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB2Idx=nB2Idx;
			pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].fOutageLoadP=pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].fOutageLoadP;
			pPRBlock->m_nRecordNum[PR_TRIP]++;
		}
		return 1;
	}

	return 0;
}

void CPRTrip::FormDFactor(tagPRBlock* pPRBlock, const double fDFThreshold, const double fDPThreshold)
{
	register int	i;

	pPRBlock->m_nRecordNum[PR_TRIP]=0;
	pPRBlock->m_nRecordNum[PR_TRIPMISLAND]=0;
	pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]=0;

	m_LineDFArray.resize(pPRBlock->m_nRecordNum[PR_ACLINE]);
	m_TranDFArray.resize(pPRBlock->m_nRecordNum[PR_WIND]);
	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
	{
		m_LineDFArray[i].BusDFArray.clear();
		m_LineDFArray[i].LDFArray.clear();
		m_LineDFArray[i].TDFArray.clear();
	}
	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_WIND]; i++)
	{
		m_TranDFArray[i].BusDFArray.clear();
		m_TranDFArray[i].LDFArray.clear();
		m_TranDFArray[i].TDFArray.clear();
	}

	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		pPRBlock->m_ACLineArray[i].bOutage=0;
	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_WIND]; i++)
		pPRBlock->m_WindArray[i].bOutage=0;
	for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_HVDC]; i++)
		pPRBlock->m_HVDCArray[i].bOutage=0;

	m_fMatZArray.resize(pPRBlock->m_nRecordNum[PR_ACBUS]*pPRBlock->m_nRecordNum[PR_ACBUS]+pPRBlock->m_nRecordNum[PR_ACBUS]+1);
	for (i=0; i<(int)m_fMatZArray.size(); i++)
		m_fMatZArray[i]=0;

	PRMemDBIsland(pPRBlock);
	m_DCNetwork.PRDCFlow(pPRBlock, 1);
	m_DCNetwork.PRDCMatZ(pPRBlock, 0, m_fMatZArray);
	OneBusDFactor(pPRBlock, fDFThreshold, fDPThreshold);
}

void CPRTrip::OneBusDFactor(tagPRBlock* pPRBlock, const double fDFThreshold, const double fDPThreshold)
{
	int		nIsland, nDev, nBus;
	int		nBusI, nBusJ;
	tagBusDFactor	dfBuf;

	for (nIsland=1; nIsland<pPRBlock->m_nRecordNum[PR_ACISLAND]; nIsland++)
	{
		for (nDev=0; nDev<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
		{
			if (pPRBlock->m_ACLineArray[nDev].nIsland != nIsland || pPRBlock->m_ACLineArray[nDev].bOutage)
				continue;

			nBusI=pPRBlock->m_ACLineArray[nDev].nIBus;
			nBusJ=pPRBlock->m_ACLineArray[nDev].nZBus;
			for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
			{
				if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland || pPRBlock->m_ACBusArray[nBus].bSlack)
					continue;

				dfBuf.nBus=nBus;
				dfBuf.fDFactor=-(m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusI+nBus]-m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusJ+nBus])/pPRBlock->m_ACLineArray[nDev].fX;
				if (fabs(dfBuf.fDFactor) >= fDFThreshold)
				{
					dfBuf.fGDeltP=dfBuf.fDFactor*pPRBlock->m_ACBusArray[dfBuf.nBus].fGenP;
					dfBuf.fLDeltP=-dfBuf.fDFactor*pPRBlock->m_ACBusArray[dfBuf.nBus].fLoadP;
					if (fabs(dfBuf.fGDeltP) > 1 || fabs(dfBuf.fLDeltP) > g_fTripDeltPThreshold)
						m_LineDFArray[nDev].BusDFArray.push_back(dfBuf);
				}
			}
		}
		for (nDev=0; nDev<(int)pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
		{
			if (pPRBlock->m_WindArray[nDev].nIsland != nIsland || pPRBlock->m_WindArray[nDev].bOutage)
				continue;

			nBusI=pPRBlock->m_WindArray[nDev].nIBus;
			nBusJ=pPRBlock->m_WindArray[nDev].nZBus;
			for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
			{
				if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland || pPRBlock->m_ACBusArray[nBus].bSlack)
					continue;

				dfBuf.nBus=nBus;
				dfBuf.fDFactor=-(m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusI+nBus]-m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusJ+nBus])/pPRBlock->m_WindArray[nDev].fX;
				if (fabs(dfBuf.fDFactor) >= fDFThreshold)
				{
					dfBuf.fGDeltP=dfBuf.fDFactor*pPRBlock->m_ACBusArray[dfBuf.nBus].fGenP;
					dfBuf.fLDeltP=-dfBuf.fDFactor*pPRBlock->m_ACBusArray[dfBuf.nBus].fLoadP;
					if (fabs(dfBuf.fGDeltP) > 1 || fabs(dfBuf.fLDeltP) > g_fTripDeltPThreshold)
						m_TranDFArray[nDev].BusDFArray.push_back(dfBuf);
				}
			}
		}
	}

	for (nDev=0; nDev<(int)m_LineDFArray.size(); nDev++)
		SortLBusDFactor(m_LineDFArray[nDev].BusDFArray, 0, (int)m_LineDFArray[nDev].BusDFArray.size()-1);
	for (nDev=0; nDev<(int)m_TranDFArray.size(); nDev++)
		SortLBusDFactor(m_TranDFArray[nDev].BusDFArray, 0, (int)m_TranDFArray[nDev].BusDFArray.size()-1);

#ifdef _DEBUG
	// 	Log(g_lpszLogFile, "线路发电机母线灵敏度\n");
	// 	for (nDev=0; nDev<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
	// 	{
	// 		//if (stricmp(pPRBlock->m_LineArray[nDev].szName, "B1680[230]-B1716[230]") == 0)
	// 		{
	// 			Log(g_lpszLogFile, "Line[%d/%d] = %s\n", nDev+1, pPRBlock->m_nRecordNum[PR_ACLINE], pPRBlock->m_LineArray[nDev].szName);
	// 			for (nBus=0; nBus<(int)m_LineDFArray[nDev].BusDFArray.size(); nBus++)
	// 			{
	// 				if (!pPRBlock->m_BusArray[m_LineDFArray[nDev].BusDFArray[nBus].nBus].bSrcBus)
	// 					continue;
	// 				Log(g_lpszLogFile, "        Bus=%s Factor=%g\n", pPRBlock->m_BusArray[m_LineDFArray[nDev].BusDFArray[nBus].nBus].szName, m_LineDFArray[nDev].BusDFArray[nBus].fDFactor);
	// 			}
	// 		}
	// 	}
	// 	Log(g_lpszLogFile, "线路负荷母线灵敏度\n");
	// 	for (nDev=0; nDev<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
	// 	{
	// 		//if (stricmp(pPRBlock->m_LineArray[nDev].szName, "B1680[230]-B1716[230]") == 0)
	// 		{
	// 			Log(g_lpszLogFile, "Line[%d/%d] = %s\n", nDev+1, pPRBlock->m_nRecordNum[PR_ACLINE], pPRBlock->m_LineArray[nDev].szName);
	// 			for (nBus=0; nBus<(int)m_LineDFArray[nDev].BusDFArray.size(); nBus++)
	// 			{
	// 				if (fabs(pPRBlock->m_BusArray[m_LineDFArray[nDev].BusDFArray[nBus].nBus].fLoadP) < FLT_MIN)
	// 					continue;
	// 				Log(g_lpszLogFile, "        Bus=%s Factor=%g\n", pPRBlock->m_BusArray[m_LineDFArray[nDev].BusDFArray[nBus].nBus].szName, m_LineDFArray[nDev].BusDFArray[nBus].fDFactor);
	// 			}
	// 		}
	// 	}
	// 	
	// 	Log(g_lpszLogFile, "变压器发电机母线灵敏度\n");
	// 	for (nDev=0; nDev<(int)pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
	// 	{
	// 		Log(g_lpszLogFile, "Tran[%d/%d] = %s\n", nDev+1, pPRBlock->m_nRecordNum[PR_WIND], pPRBlock->m_WindArray[nDev].szName);
	// 		for (nBus=0; nBus<(int)m_TranDFArray[nDev].BusDFArray.size(); nBus++)
	// 		{
	// 			if (!pPRBlock->m_BusArray[m_TranDFArray[nDev].BusDFArray[nBus].nBus].bSrcBus)
	// 				continue;
	// 			Log(g_lpszLogFile, "        Bus=%s Factor=%g\n", pPRBlock->m_BusArray[m_TranDFArray[nDev].BusDFArray[nBus].nBus].szName, m_TranDFArray[nDev].BusDFArray[nBus].fDFactor);
	// 		}
	// 	}
	// 	Log(g_lpszLogFile, "变压器负荷母线灵敏度\n");
	// 	for (nDev=0; nDev<(int)pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
	// 	{
	// 		Log(g_lpszLogFile, "Tran[%d/%d] = %s\n", nDev+1, pPRBlock->m_nRecordNum[PR_WIND], pPRBlock->m_WindArray[nDev].szName);
	// 		for (nBus=0; nBus<(int)m_TranDFArray[nDev].BusDFArray.size(); nBus++)
	// 		{
	// 			if (fabs(pPRBlock->m_BusArray[m_TranDFArray[nDev].BusDFArray[nBus].nBus].fLoadP) < FLT_MIN)
	// 				continue;
	// 			Log(g_lpszLogFile, "        Bus=%s Factor=%g\n", pPRBlock->m_BusArray[m_TranDFArray[nDev].BusDFArray[nBus].nBus].szName, m_TranDFArray[nDev].BusDFArray[nBus].fDFactor);
	// 		}
	// 	}
#endif // _DEBUG
}

void CPRTrip::Trip1Factor(tagPRBlock* pPRBlock, const unsigned char nBranTyp, const int nBran, const unsigned char nTripTyp, const int nTrip, double& fFactor)
{
	int		nBusI, nBusJ, nBusM, nBusN;
	double	fXk, fXj;
	double	fBuf1, fBuf2;
	double	fZMI, fZMJ, fZNI, fZNJ;
	double	fZMM, fZNN, fZMN;

	fFactor=0;

	//	k
	if (nBranTyp == PR_ACLINE)
	{
		nBusI=pPRBlock->m_ACLineArray[nBran].nIBus;
		nBusJ=pPRBlock->m_ACLineArray[nBran].nZBus;
		fXk=pPRBlock->m_ACLineArray[nBran].fX;
	}
	else
	{
		nBusI=pPRBlock->m_WindArray[nBran].nIBus;
		nBusJ=pPRBlock->m_WindArray[nBran].nZBus;
		fXk=pPRBlock->m_WindArray[nBran].fX;
	}
	//	l
	if (nTripTyp == PR_ACLINE)
	{
		nBusM=pPRBlock->m_ACLineArray[nTrip].nIBus;
		nBusN=pPRBlock->m_ACLineArray[nTrip].nZBus;
		fXj=pPRBlock->m_ACLineArray[nTrip].fX;

		//if (stricmp(pPRBlock->m_LineArray[nTrip].szName, "BUS_7138-BUS_8138") == 0)
		//	ASSERT(FALSE);
	}
	else
	{
		nBusM=pPRBlock->m_WindArray[nTrip].nIBus;
		nBusN=pPRBlock->m_WindArray[nTrip].nZBus;
		fXj=pPRBlock->m_WindArray[nTrip].fX;
	}

	//if (fXk < FLT_MIN)
	//	ASSERT(FALSE);

	//if (fXj < FLT_MIN)
	//	ASSERT(FALSE);

	fZMI=m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusM+nBusI];
	fZMJ=m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusM+nBusJ];
	fZNI=m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusN+nBusI];
	fZNJ=m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusN+nBusJ];
	fBuf1=((fZMI-fZMJ)-(fZNI-fZNJ))/fXk;

	fZMM=m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusM+nBusM];
	fZNN=m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusN+nBusN];
	fZMN=m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusM+nBusN];
	fBuf2=1.0-(fZMM+fZNN-2*fZMN)/fXj;
	//if (fBuf2 < FLT_MIN)
	//	fFactor=0;
	//else
	fFactor=fBuf1/fBuf2;
}

void CPRTrip::Trip2Factor(tagPRBlock* pPRBlock, const unsigned char nBranTyp, const int nBran, const unsigned char nTrip1Typ, const int nTrip1, const unsigned char nTrip2Typ, const int nTrip2, double& fFactor1, double& fFactor2)
{
	int		nBusI, nBusJ, nBusK, nBusL, nBusM, nBusN;
	double	fBuf1, fBuf2;
	double	fXj, fXk, fXl;
	int		nBusNum;

	nBusNum=pPRBlock->m_nRecordNum[PR_ACBUS];

	double	fX11, fX12, fX21, fX22;
	double	fIX11, fIX12, fIX21, fIX22;

	fFactor1=fFactor2=0;

	//	j(i-j)
	if (nBranTyp == PR_ACLINE)
	{
		nBusI=pPRBlock->m_ACLineArray[nBran].nIBus;
		nBusJ=pPRBlock->m_ACLineArray[nBran].nZBus;
		fXj=pPRBlock->m_ACLineArray[nBran].fX;
	}
	else
	{
		nBusI=pPRBlock->m_WindArray[nBran].nIBus;
		nBusJ=pPRBlock->m_WindArray[nBran].nZBus;
		fXj=pPRBlock->m_WindArray[nBran].fX;
	}
	//	k(k-l)
	if (nTrip1Typ == PR_ACLINE)
	{
		nBusK=pPRBlock->m_ACLineArray[nTrip1].nIBus;
		nBusL=pPRBlock->m_ACLineArray[nTrip1].nZBus;
		fXk=pPRBlock->m_ACLineArray[nTrip1].fX;
	}
	else
	{
		nBusK=pPRBlock->m_WindArray[nTrip1].nIBus;
		nBusL=pPRBlock->m_WindArray[nTrip1].nZBus;
		fXk=pPRBlock->m_WindArray[nTrip1].fX;
	}
	//	l(m-n)
	if (nTrip2Typ == PR_ACLINE)
	{
		nBusM=pPRBlock->m_ACLineArray[nTrip2].nIBus;
		nBusN=pPRBlock->m_ACLineArray[nTrip2].nZBus;
		fXl=pPRBlock->m_ACLineArray[nTrip2].fX;
	}
	else
	{
		nBusM=pPRBlock->m_WindArray[nTrip2].nIBus;
		nBusN=pPRBlock->m_WindArray[nTrip2].nZBus;
		fXl=pPRBlock->m_WindArray[nTrip2].fX;
	}

	//	1-Z(k, k)/x(k)
	fX11=1-(m_fMatZArray[nBusNum*nBusK+nBusK]+m_fMatZArray[nBusNum*nBusL+nBusL]-2*m_fMatZArray[nBusNum*nBusK+nBusL])/fXk;
	//	-Z(k, l)/x(k)
	fX12=-((m_fMatZArray[nBusNum*nBusK+nBusM]-m_fMatZArray[nBusNum*nBusK+nBusN])-(m_fMatZArray[nBusNum*nBusL+nBusM]-m_fMatZArray[nBusNum*nBusL+nBusN]))/fXk;
	//	-Z(l, k)/x(l)
	fX21 = -((m_fMatZArray[nBusNum*nBusM+nBusK]-m_fMatZArray[nBusNum*nBusM+nBusL])-(m_fMatZArray[nBusNum*nBusN+nBusK]-m_fMatZArray[nBusNum*nBusN+nBusL]))/fXl;
	//	1-Z(l, l)/x(l)
	fX22 = 1-(m_fMatZArray[nBusNum*nBusM+nBusM]+m_fMatZArray[nBusNum*nBusN+nBusN]-2*m_fMatZArray[nBusNum*nBusM+nBusN])/fXl;

	double	fBase=fX11*fX22-fX12*fX21;
	if (fBase < FLT_MIN)
		return;

	fIX11=fX22/fBase;
	fIX22=fX11/fBase;
	fIX12=-fX12/fBase;
	fIX21=-fX21/fBase;

	//	Z(j, k)/x(j)
	fBuf1 = ((m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusI+nBusK]-m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusI+nBusL])-(m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusJ+nBusK]-m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusJ+nBusL]))/fXj;
	//	Z(j, l)/x(j)
	fBuf2 = ((m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusI+nBusM]-m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusI+nBusN])-(m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusJ+nBusM]-m_fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusJ+nBusN]))/fXj;

	fFactor1 = fBuf1*fIX11 + fBuf2*fIX21;
	fFactor2 = fBuf1*fIX12 + fBuf2*fIX22;
}

void CPRTrip::Record1Trip(tagPRBlock* pPRBlock, const short nOvlmType, const int nOvlmBran, const short nTripType, const int nTripBran, const float fFlow, const float fRated)
{
	register int	i;
	int		nExist;

	nExist=-1;
	for (i=0; i<pPRBlock->m_nRecordNum[PR_TRIP]; i++)
	{
		if (pPRBlock->m_TripModeArray[i].nTripDevNum == 1 && pPRBlock->m_TripModeArray[i].nTrB1Typ == nTripType && pPRBlock->m_TripModeArray[i].nTrB1Idx == nTripBran)
		{
			nExist=i;
			break;
		}
	}
	if (nExist < 0)
	{
		if (pPRBlock->m_nRecordNum[PR_TRIP] >= PRGetTableMax(PR_TRIP))
			return;

		memset(&pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]], 0, sizeof(tagPRTrip));
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nFaultType=PRTrip_FaultType_OverLmt;
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTripDevNum=1;
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB1Typ=(unsigned char)nTripType;
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB1Idx=nTripBran;
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB2Typ=0;
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB2Idx=0;
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].bOverLimit=1;
		if (pPRBlock->m_nRecordNum[PR_TRIPOVLDEV] < PRGetTableMax(PR_TRIPOVLDEV)-1)
		{
			memset(&pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]], 0, sizeof(tagPRTripOvlDev));
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].nTrip=pPRBlock->m_nRecordNum[PR_TRIP];
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].nDevTyp=(unsigned char)nOvlmType;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].nDevIdx=nOvlmBran;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].fOvLmtP=fFlow;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].fRated=fRated;
			pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]++;
		}
		pPRBlock->m_nRecordNum[PR_TRIP]++;
	}
	else
	{
		pPRBlock->m_TripModeArray[nExist].bOverLimit=1;
		if (pPRBlock->m_TripModeArray[nExist].nFaultType == PRTrip_FaultType_MIsland)
			pPRBlock->m_TripModeArray[nExist].nFaultType=PRTrip_FaultType_MiAndOl;

		if (pPRBlock->m_nRecordNum[PR_TRIPOVLDEV] < PRGetTableMax(PR_TRIPOVLDEV)-1)
		{
			memset(&pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]], 0, sizeof(tagPRTripOvlDev));
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].nTrip=nExist;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].nDevTyp=(unsigned char)nOvlmType;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].nDevIdx=nOvlmBran;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].fOvLmtP=fFlow;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].fRated=fRated;
			pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]++;
		}
	}
}

void	CPRTrip::Record2Trip(tagPRBlock* pPRBlock, const short nOvlmType, const int nOvlmBran, const short nTrip1Type, const int nTrip1Bran, const short nTrip2Type, const int nTrip2Bran, const float fFlow, const float fRated)
{
	register int	i;
	int		nExist;

	nExist=-1;
	for (i=0; i<pPRBlock->m_nRecordNum[PR_TRIP]; i++)
	{
		if (pPRBlock->m_TripModeArray[i].nTripDevNum == 2 &&
			(
			(pPRBlock->m_TripModeArray[i].nTrB1Typ == nTrip1Type && pPRBlock->m_TripModeArray[i].nTrB1Idx == nTrip1Bran && pPRBlock->m_TripModeArray[i].nTrB2Typ == nTrip2Type && pPRBlock->m_TripModeArray[i].nTrB2Idx == nTrip2Bran) ||
			(pPRBlock->m_TripModeArray[i].nTrB1Typ == nTrip2Type && pPRBlock->m_TripModeArray[i].nTrB1Idx == nTrip2Bran && pPRBlock->m_TripModeArray[i].nTrB2Typ == nTrip1Type && pPRBlock->m_TripModeArray[i].nTrB2Idx == nTrip1Bran)
			)
			)
		{
			nExist=i;
			break;
		}
	}
	if (nExist < 0)
	{
		if (pPRBlock->m_nRecordNum[PR_TRIP] >= PRGetTableMax(PR_TRIP))
			return;
		memset(&pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]], 0, sizeof(tagPRTrip));
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nFaultType=PRTrip_FaultType_OverLmt;
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTripDevNum=2;
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB1Typ=(unsigned char)nTrip1Type;
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB1Idx=nTrip1Bran;
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB2Typ=(unsigned char)nTrip2Type;
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].nTrB2Idx=nTrip2Bran;
		pPRBlock->m_TripModeArray[pPRBlock->m_nRecordNum[PR_TRIP]].bOverLimit=1;
		if (pPRBlock->m_nRecordNum[PR_TRIPOVLDEV] < PRGetTableMax(PR_TRIPOVLDEV)-1)
		{
			memset(&pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]], 0, sizeof(tagPRTripOvlDev));
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].nTrip=pPRBlock->m_nRecordNum[PR_TRIP];
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].nDevTyp=(unsigned char)nOvlmType;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].nDevIdx=nOvlmBran;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].fOvLmtP=fFlow;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].fRated=fRated;
			pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]++;
		}
		pPRBlock->m_nRecordNum[PR_TRIP]++;
	}
	else
	{
		pPRBlock->m_TripModeArray[nExist].bOverLimit=1;
		if (pPRBlock->m_TripModeArray[nExist].nFaultType == PRTrip_FaultType_MIsland)
			pPRBlock->m_TripModeArray[nExist].nFaultType=PRTrip_FaultType_MiAndOl;

		if (pPRBlock->m_nRecordNum[PR_TRIPOVLDEV] < PRGetTableMax(PR_TRIPOVLDEV)-1)
		{
			memset(&pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]], 0, sizeof(tagPRTripOvlDev));
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].nTrip=nExist;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].nDevTyp=(unsigned char)nOvlmType;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].nDevIdx=nOvlmBran;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].fOvLmtP=fFlow;
			pPRBlock->m_TripOvlDevArray[pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]].fRated=fRated;
			pPRBlock->m_nRecordNum[PR_TRIPOVLDEV]++;
		}
	}
}

void CPRTrip::SortBranDFactor(std::vector<tagBranDFactor>& dfArray, int nDn0, int nUp0)
{
	if (nUp0 <= nDn0)
		return;

	int nDn = nDn0;
	int nUp = nUp0;

	double fFactor=dfArray[(nDn0+nUp0)/2].fFactor;
	while (nDn <= nUp)
	{
		while (nDn < nUp0 && dfArray[nDn].fFactor > fFactor)
			++nDn;								 
		while (nUp > nDn0 && dfArray[nUp].fFactor < fFactor)
			--nUp;

		if (nDn <= nUp)
		{
			std::swap(dfArray[nDn], dfArray[nUp]);

			++nDn;
			--nUp;
		}
	}

	if (nDn0 < nUp)
		SortBranDFactor(dfArray, nDn0, nUp);

	if (nDn < nUp0 )
		SortBranDFactor(dfArray, nDn, nUp0);
}

void CPRTrip::SortLBusDFactor(std::vector<tagBusDFactor>& dfArray, int nDn0, int nUp0)
{
	if (nUp0 <= nDn0)
		return;

	int nDn = nDn0;
	int nUp = nUp0;

	double fDFactor=dfArray[(nDn0+nUp0)/2].fDFactor;
	while (nDn <= nUp)
	{
		while (nDn < nUp0 && dfArray[nDn].fDFactor > fDFactor)
			++nDn;								 
		while (nUp > nDn0 && dfArray[nUp].fDFactor < fDFactor)
			--nUp;

		if (nDn <= nUp)
		{
			std::swap(dfArray[nDn], dfArray[nUp]);

			++nDn;
			--nUp;
		}
	}

	if (nDn0 < nUp)
		SortLBusDFactor(dfArray, nDn0, nUp);

	if (nDn < nUp0 )
		SortLBusDFactor(dfArray, nDn, nUp0);
}


int CPRTrip::ComparePRTrip(tagPRTrip& mdA, tagPRTrip& mdB)
{
	if (mdA.nFaultType < mdB.nFaultType)
		return -1;
	else if (mdA.nFaultType > mdB.nFaultType)
		return 1;

	if (mdA.nTripDevNum < mdB.nTripDevNum)
		return -1;
	if (mdA.nTripDevNum > mdB.nTripDevNum)
		return -1;

	if (mdA.nTripDevNum >= 1)
	{
		if (100000*mdA.nTrB1Typ+mdA.nTrB1Idx < 100000*mdB.nTrB1Typ+mdB.nTrB1Idx)
			return -1;
		else if (100000*mdA.nTrB1Typ+mdA.nTrB1Idx > 100000*mdB.nTrB1Typ+mdB.nTrB1Idx)
			return 1;
	}
	if (mdA.nTripDevNum >= 2)
	{
		if (100000*mdA.nTrB2Typ+mdA.nTrB2Idx < 100000*mdB.nTrB2Typ+mdB.nTrB2Idx)
			return -1;
		else if (100000*mdA.nTrB2Typ+mdA.nTrB2Idx > 100000*mdB.nTrB2Typ+mdB.nTrB2Idx)
			return 1;
	}

	// 	if (mdA.nFaultType == PRTrip_FaultType_OverLmt)
	// 	{
	// 		if (100000*mdA.nOLmtBTyp+mdA.nOLmtBran < 100000*mdB.nOLmtBTyp+mdB.nOLmtBran)
	// 			return -1;
	// 		else if (100000*mdA.nOLmtBTyp+mdA.nOLmtBran > 100000*mdB.nOLmtBTyp+mdB.nOLmtBran)
	// 			return 1;
	// 	}

	return 0;
}

void CPRTrip::SortPRFMode(tagPRBlock* pBlock, int nDn0, int nUp0)
{
	if (nUp0 <= nDn0)
		return;

	tagPRTrip	mdMid, mdBuf;
	int nDn = nDn0;
	int nUp = nUp0;

	memcpy(&mdMid, &pBlock->m_TripModeArray[(nDn0+nUp0)/2], sizeof(tagPRTrip));
	while (nDn <= nUp)
	{
		while (nDn < nUp0 && ComparePRTrip(pBlock->m_TripModeArray[nDn], mdMid) < 0)
			++nDn;							 
		while (nUp > nDn0 && ComparePRTrip(pBlock->m_TripModeArray[nUp], mdMid) > 0)
			--nUp;

		if (nDn <= nUp)
		{
			memcpy(&mdBuf, &pBlock->m_TripModeArray[nDn], sizeof(tagPRTrip));
			memcpy(&pBlock->m_TripModeArray[nDn], &pBlock->m_TripModeArray[nUp], sizeof(tagPRTrip));
			memcpy(&pBlock->m_TripModeArray[nUp], &mdBuf, sizeof(tagPRTrip));

			++nDn;
			--nUp;
		}
	}

	if (nDn0 < nUp)
		SortPRFMode(pBlock, nDn0, nUp);

	if (nDn < nUp0 )
		SortPRFMode(pBlock, nDn, nUp0);
}
