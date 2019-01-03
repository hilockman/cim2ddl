#include "stdafx.h"
#include <algorithm>
#include "../../../include/ilog.h"
#include "../../PowerGrid/Reliability/PGReliability/PRAdequacyBase/PRAdequacyBase.h"
//extern	const	char*	g_lpszLogFile;
//extern	void	Log(const char* lpszLogFile, char* pformat, ...);

const	double	m_fRatedRatio=1.0;
static	CPRMemDBInterface	m_PRMemDBInterface;

//////////////////////////////////////////////////////////////////////////
//	读可靠性线路参数
void BpaMemDB2PRMemDB_ACLine(tagBpaBlock* pBpaBlock, tagPRBlock* pPRBlock, int& nMaxBusNumber)
{
	int		nDev;
	int		nIBus, nZBus;

	nMaxBusNumber=-1;
	for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; nDev++)
	{
		if (pPRBlock->m_nRecordNum[PR_ACLINE] >= m_PRMemDBInterface.PRGetTableMax(PR_ACLINE)-1)
			break;

		if (pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus < 0 || pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus < 0)
			continue;
		memset(&pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]], 0, sizeof(tagPRACLine));
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].nTCSCIndex = -1;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].nUPFCIndex = -1;

		nIBus=pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus+1;
		nZBus=pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus+1;

		strcpy(pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].szName, pBpaBlock->m_BpaDat_ACLineArray[nDev].szKeyName);
		strcpy(pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI);
		strcpy(pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ);
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fkVI=pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fkVJ=pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].cLoop=pBpaBlock->m_BpaDat_ACLineArray[nDev].cLoop;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fLength=pBpaBlock->m_BpaDat_ACLineArray[nDev].fMiles;
		if (pBpaBlock->m_BpaDat_ACLineArray[nDev].fMiles <= FLT_MIN)
		{
			if (pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI < 300)
				pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fLength = 100;
			else if (300 <= pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI && pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI < 450)
				pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fLength = 150;
			else if (450 <= pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI && pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI < 800)
				pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fLength = 300;
			else
				pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fLength = 500;
		}

		strcpy(pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].szIniBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].szIniBusI);
		strcpy(pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].szIniBusJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].szIniBusJ);
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fInikVI=pBpaBlock->m_BpaDat_ACLineArray[nDev].fInikVI;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fInikVJ=pBpaBlock->m_BpaDat_ACLineArray[nDev].fInikVJ;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].cIniLoop=pBpaBlock->m_BpaDat_ACLineArray[nDev].cIniLoop;

		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].nIRadial=pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus].nRadiate;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].nZRadial=pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus].nRadiate;

		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].nIBus = nIBus;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].nZBus = nZBus;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fR = pBpaBlock->m_BpaDat_ACLineArray[nDev].fR;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fX = pBpaBlock->m_BpaDat_ACLineArray[nDev].fX;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fB = pBpaBlock->m_BpaDat_ACLineArray[nDev].fB1;

		if (fabs(pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fX) < FLT_MIN)
			pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fX=(float)0.01;

		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fRtPi = pBpaBlock->m_BpaDat_ACLineArray[nDev].fPi;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fRtPz = pBpaBlock->m_BpaDat_ACLineArray[nDev].fPz;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fRtQi = pBpaBlock->m_BpaDat_ACLineArray[nDev].fQi;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fRtQz = pBpaBlock->m_BpaDat_ACLineArray[nDev].fQz;
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fLossP = fabs(fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fPi)-fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fPz));
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fRated = (float)(m_fRatedRatio*1.732*pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI*pBpaBlock->m_BpaDat_ACLineArray[nDev].fAMP/1000.0);
		pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].nIndex = nDev;

		if (pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fRated < 10)	pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fRated = 0;
		//if (pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI < 200)
		//	pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fRated=0;
		//if (pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI < 300)
		//	pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fRated=0;

		pPRBlock->m_nRecordNum[PR_ACLINE]++;

		if (nMaxBusNumber < nIBus)	nMaxBusNumber = nIBus;
		if (nMaxBusNumber < nZBus)	nMaxBusNumber = nZBus;
	}
}

//////////////////////////////////////////////////////////////////////////
//	读可靠性主变参数
void BpaMemDB2PRMemDB_Wind(tagBpaBlock* pBpaBlock, tagPRBlock* pPRBlock, int& nMaxBusNumber)
{
	int		nDev;
	int		nIBus, nZBus;
	float	fBuffer;

	for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)
	{
		if (pPRBlock->m_nRecordNum[PR_WIND] >= m_PRMemDBInterface.PRGetTableMax(PR_WIND)-1)
			break;
		{
			if (pBpaBlock->m_BpaDat_WindArray[nDev].nIBus < 0 || pBpaBlock->m_BpaDat_WindArray[nDev].nZBus < 0)
				continue;
			memset(&pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]], 0, sizeof(tagPRWind));

			strcpy(pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].szName, pBpaBlock->m_BpaDat_WindArray[nDev].szKeyName);
			strcpy(pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].szBusI);
			strcpy(pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ);
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fkVI=pBpaBlock->m_BpaDat_WindArray[nDev].fkVI;
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fkVJ=pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ;
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].cLoop=pBpaBlock->m_BpaDat_WindArray[nDev].cLoop;

			strcpy(pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].szIniBusI, pBpaBlock->m_BpaDat_WindArray[nDev].szIniBusI);
			strcpy(pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].szIniBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].szIniBusJ);
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fInikVI=pBpaBlock->m_BpaDat_WindArray[nDev].fInikVI;
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fInikVJ=pBpaBlock->m_BpaDat_WindArray[nDev].fInikVJ;
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].cIniLoop=pBpaBlock->m_BpaDat_WindArray[nDev].cIniLoop;

			if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard == 0)
			{
				pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].nIRadial=pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].nRadiate;
				pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].nZRadial=pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].nRadiate;
			}
			else if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard == 1)
			{
				pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].nIRadial=0;
				pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].nZRadial=pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].nRadiate;
			}
			else if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard == 2)
			{
				pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].nIRadial=pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].nRadiate;
				pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].nZRadial=0;
			}

			nIBus=(pBpaBlock->m_BpaDat_WindArray[nDev].bRCard == 1) ? pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]+pBpaBlock->m_BpaDat_WindArray[nDev].nIBus+1 : pBpaBlock->m_BpaDat_WindArray[nDev].nIBus+1;
			nZBus=(pBpaBlock->m_BpaDat_WindArray[nDev].bRCard == 2) ? pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]+pBpaBlock->m_BpaDat_WindArray[nDev].nZBus+1 : pBpaBlock->m_BpaDat_WindArray[nDev].nZBus+1;

			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].nIBus=nIBus;
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].nZBus=nZBus;
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fR=pBpaBlock->m_BpaDat_WindArray[nDev].fR;
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fX=pBpaBlock->m_BpaDat_WindArray[nDev].fX;
			if (fabs(pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fX) < FLT_MIN)
			{
				pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fX=(float)0.01;
				//ASSERT(FALSE);
			}
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fRtPi = pBpaBlock->m_BpaDat_WindArray[nDev].fPi;
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fRtPz = pBpaBlock->m_BpaDat_WindArray[nDev].fPz;
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fRtQi = pBpaBlock->m_BpaDat_WindArray[nDev].fQi;
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fRtQz = pBpaBlock->m_BpaDat_WindArray[nDev].fQz;
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fLossP = fabs(fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fPi)-fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fPz));
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fRated = (float)(m_fRatedRatio*pBpaBlock->m_BpaDat_WindArray[nDev].fMVA);

			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].nIndex=nDev;
			pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].bGenTran=(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].bGenerator != 0 || pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].bDCBound != 0) ? 1 : 0;
			fBuffer=max(pBpaBlock->m_BpaDat_WindArray[nDev].fkVI, pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ);

			if (pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fRated < 10)	pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fRated = 0;
			//	可临时更改，防止变压器消限
			//if (pBpaBlock->m_BpaDat_WindArray[nDev].fkVI < 200 && pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ < 200)
			//	pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fRated=0;

			pPRBlock->m_nRecordNum[PR_WIND]++;

			if (nMaxBusNumber < nIBus)	nMaxBusNumber = nIBus;
			if (nMaxBusNumber < nZBus)	nMaxBusNumber = nZBus;

			//if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard != 0)
			//	Log(g_lpszLogFile, "读取直流电压调节器 %s iBus=%d jBus=%d\n", pBpaBlock->m_BpaDat_WindArray[nDev].szKeyName, nIBus, nZBus);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
//	读可靠性发电机参数
void BpaMemDB2PRMemDB_ACBusLoadGen(tagBpaBlock* pBpaBlock, tagPRBlock* pPRBlock, const int nMaxBusNumber)
{
	register int	i;
	int		nBus;
	double	fGenRatio, fGenPMax;
	double	fGenPFactor, fGenQFactor, fLoadPFactor, fLoadQFactor;
	unsigned char	bHasSwiGen;

	//	读可靠性交流母线参数
	pPRBlock->m_nRecordNum[PR_ACBUS]=nMaxBusNumber+1;
	for (i=0; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		memset(&pPRBlock->m_ACBusArray[i], 0, sizeof(tagPRACBus));
	strcpy(pPRBlock->m_ACBusArray[0].szName, "        ");

	//////////////////////////////////////////////////////////////////////////
	//	形成母线信息，包括母线注入
	for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
	{
		strcpy(pPRBlock->m_ACBusArray[nBus+1].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName);
		pPRBlock->m_ACBusArray[nBus+1].nRadial=pBpaBlock->m_BpaDat_ACBusArray[nBus].nRadiate;
		pPRBlock->m_ACBusArray[nBus+1].fkV=pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV;
		pPRBlock->m_ACBusArray[nBus+1].nRadial = pBpaBlock->m_BpaDat_ACBusArray[nBus].bInRing ? 0 : pBpaBlock->m_BpaDat_ACBusArray[nBus].nRadiate;
		strcpy(pPRBlock->m_ACBusArray[nBus+1].szZone, pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone);
		pPRBlock->m_ACBusArray[nBus+1].fRtV=pBpaBlock->m_BpaDat_ACBusArray[nBus].fV/pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV;

		fGenPFactor=fGenQFactor=fLoadPFactor=fLoadQFactor=1;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_P]; i++)
		{
			if (stricmp(pBpaBlock->m_BpaDat_PArray[i].szZone, pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone) == 0)
			{
				fGenPFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
				if (pBpaBlock->m_BpaDat_PArray[i].fGenQFactor < FLT_MIN)
					fGenQFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
				else
					fGenQFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenQFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenQFactor : 1;

				fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
				if (pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor < FLT_MIN)
					fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
				else
					fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor : 1;
				break;
			}
		}

		pPRBlock->m_ACBusArray[nBus+1].fGenP  += (float)(fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen  );
		pPRBlock->m_ACBusArray[nBus+1].fGenQ  += (float)(fGenQFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fQsched_Qmax);
		pPRBlock->m_ACBusArray[nBus+1].fLoadP += (float)(fLoadPFactor*(pBpaBlock->m_BpaDat_ACBusArray[nBus].fLoadP+pBpaBlock->m_BpaDat_ACBusArray[nBus].fAddLoadP));
		pPRBlock->m_ACBusArray[nBus+1].fLoadQ += (float)(fLoadQFactor*(pBpaBlock->m_BpaDat_ACBusArray[nBus].fLoadQ+pBpaBlock->m_BpaDat_ACBusArray[nBus].fAddLoadQ));
	}
	//	形成母线信息，包括母线注入
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	//	形成负荷信息
	for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
	{
		if (pPRBlock->m_nRecordNum[PR_POWERLOAD] >= m_PRMemDBInterface.PRGetTableMax(PR_POWERLOAD)-1)
			break;

		fLoadPFactor=fLoadQFactor=1;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_P]; i++)
		{
			if (stricmp(pBpaBlock->m_BpaDat_PArray[i].szZone, pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone) == 0)
			{
				fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
				if (pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor < FLT_MIN)
					fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
				else
					fLoadQFactor=pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor;
				break;
			}
		}

		if (fabs(fLoadPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fLoadP) > FLT_MIN)
		{
			memset(&pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]], 0, sizeof(tagPRPowerLoad));
			pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].nRadial		=	pBpaBlock->m_BpaDat_ACBusArray[nBus].nRadiate;
			strcpy(pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].szBus,		pBpaBlock->m_BpaDat_ACBusArray[nBus].szName);
			pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].fkV			=	pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV;
			strcpy(pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].szZone,		pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone);

			pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].fMSPout		=
			pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].fP				=
			pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].fPMax			=	(float)(fLoadPFactor*(pBpaBlock->m_BpaDat_ACBusArray[nBus].fLoadP+pBpaBlock->m_BpaDat_ACBusArray[nBus].fAddLoadP));
			pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].fQ				=	(float)(fLoadQFactor*(pBpaBlock->m_BpaDat_ACBusArray[nBus].fLoadQ+pBpaBlock->m_BpaDat_ACBusArray[nBus].fAddLoadQ));

			pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].fReferenceP	=	pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].fP;
			pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].fReferenceQ	=	pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].fQ;

			pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].nBusIndex		=	0;
			pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].bAuxLoad		=	0;
			pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].bEQLoad		=	0;

			if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bGenerator != 0 && pBpaBlock->m_BpaDat_ACBusArray[nBus].bGenLn == 0 && pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV < 50)	//	厂用电
				pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].bAuxLoad	=	1;

			if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bReduction)
				pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].bEQLoad	=	1;

			sprintf(pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].szName, "%s%g", pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);
			pPRBlock->m_nRecordNum[PR_POWERLOAD]++;
		}
	}
	//	形成负荷信息
	//////////////////////////////////////////////////////////////////////////

	for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
	{
		if (pPRBlock->m_nRecordNum[PR_GENERATOR] >= m_PRMemDBInterface.PRGetTableMax(PR_GENERATOR)-1)
			break;

		fGenPFactor=fGenQFactor=1;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_P]; i++)
		{
			if (stricmp(pBpaBlock->m_BpaDat_PArray[i].szZone, pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone) == 0)
			{
				fGenPFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
				if (pBpaBlock->m_BpaDat_PArray[i].fGenQFactor < FLT_MIN)
					fGenQFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
				else
					fGenQFactor=pBpaBlock->m_BpaDat_PArray[i].fGenQFactor;
				break;
			}
		}

		if (fabs(pBpaBlock->m_BpaDat_ACBusArray[nBus].fPmax) > FLT_MIN || fabs(pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen) > FLT_MIN || stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBus].szCardKey, "BS") == 0)
			pPRBlock->m_ACBusArray[nBus+1].bSrcBus=1;
		fGenPMax = (pBpaBlock->m_BpaDat_ACBusArray[nBus].fPmax < fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen) ? fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen : pBpaBlock->m_BpaDat_ACBusArray[nBus].fPmax;
		if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBus].szCardKey, "BS") == 0)
		{
			pPRBlock->m_ACBusArray[nBus+1].bSlack=1;
			if (fGenPMax < FLT_MIN)
				fGenPMax = 1000;
		}

		//	有发电机模型的
		//if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bGenerator != 0 && pBpaBlock->m_BpaDat_ACBusArray[nBus].bGenLn == 0 && fGenPMax > FLT_MIN)
		if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bGenerator != 0 && fGenPMax > FLT_MIN)
		{
			bHasSwiGen=0;
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GEN]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaSwi_GenArray[i].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName) == 0 && fabs(pBpaBlock->m_BpaSwi_GenArray[i].fBus_kV - pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV) < 0.15)
				{
					fGenRatio=1;
					if (pBpaBlock->m_BpaSwi_GenArray[i].fP > 0 && pBpaBlock->m_BpaSwi_GenArray[i].fP < 1)
						fGenRatio=pBpaBlock->m_BpaSwi_GenArray[i].fP;

					memset(&pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]], 0, sizeof(tagPRGenerator));

					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].nRadial		=	pBpaBlock->m_BpaDat_ACBusArray[nBus].nRadiate;
					strcpy(pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].szBus,		pBpaBlock->m_BpaDat_ACBusArray[nBus].szName);
					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fkV			=	pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV;
					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].cGenId			=	pBpaBlock->m_BpaSwi_GenArray[i].cID;
					strcpy(pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].szZone,		pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone);

					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fMSPout		=
					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fP				=	(float)(fGenRatio*fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen);
					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fQ				=	(float)(fGenRatio*fGenQFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fQsched_Qmax);

					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fReferenceP	=	pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fP;
					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fReferenceQ	=	pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fQ;

					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fPMax			=	(float)(fGenRatio*fGenPMax);
					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fPMin			=	0;
					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fQMax			=	(float)(fGenRatio*pBpaBlock->m_BpaDat_ACBusArray[nBus].fQsched_Qmax);
					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fQMin			=	0;

					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].nBusIndex		=	nBus;

					if (pBpaBlock->m_BpaSwi_GenArray[i].cID != ' ' && pBpaBlock->m_BpaSwi_GenArray[i].cID != '\0')
						sprintf(pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].szName, "%s%g@%c", pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV, pBpaBlock->m_BpaSwi_GenArray[i].cID);
					else
						sprintf(pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].szName, "%s%g", pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);

					if (1.01*pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fPMax < fGenRatio*fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen)
						pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fPMax = (float)(fGenRatio*fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen);

					pPRBlock->m_nRecordNum[PR_GENERATOR]++;
					bHasSwiGen=1;
				}
			}
			if (!bHasSwiGen)	//	没有发电机模型
			{
				memset(&pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]], 0, sizeof(tagPRGenerator));
				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].nRadial			=		pBpaBlock->m_BpaDat_ACBusArray[nBus].nRadiate;
				strcpy(pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].szBus,				pBpaBlock->m_BpaDat_ACBusArray[nBus].szName);
				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fkV				=		pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV;
				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].cGenId				=		' ';
				strcpy(pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].szZone,				pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone);
																							
				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fMSPout			=
				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fP					=		(float)(fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen);
				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fQ					=		(float)(fGenQFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fQsched_Qmax);

				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fReferenceP		=		pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fP;
				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fReferenceQ		=		pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fQ;

				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fPMax				=		(float)fGenPMax;
				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fPMin				=		0;
				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fQMax				=		pBpaBlock->m_BpaDat_ACBusArray[nBus].fQsched_Qmax;
				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fQMin				=		0;
																							
				pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].nBusIndex			=		nBus;
				sprintf(pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].szName, "%s%g",	pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);
				if (pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fPMax < fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen)
				{
					log_debug("发电机[%s] 调整限值 %f -> %f\n", pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].szName,
						pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fPMax, pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen);
					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fPMax = fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen;
				}

				if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bReduction)
					pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].bEQGen			=	1;
				pPRBlock->m_nRecordNum[PR_GENERATOR]++;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////
//	读可靠性直流母线参数，将直流母线按交流母线处理（因可靠性计算中直流是解耦的）
void BpaMemDB2PRMemDB_DCBus(tagBpaBlock* pBpaBlock, tagPRBlock* pPRBlock)
{
	int		nBus;

	for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; nBus++)
	{
		strcpy(pPRBlock->m_ACBusArray[pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]+nBus+1].szName, pBpaBlock->m_BpaDat_DCBusArray[nBus].szName);
		pPRBlock->m_ACBusArray[pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]+nBus+1].fkV=pBpaBlock->m_BpaDat_DCBusArray[nBus].fkV;
		pPRBlock->m_ACBusArray[pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]+nBus+1].nRadial=0;
		pPRBlock->m_ACBusArray[pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]+nBus+1].bDCBus=1;
		strcpy(pPRBlock->m_ACBusArray[pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]+nBus+1].szZone, pBpaBlock->m_BpaDat_DCBusArray[nBus].szZone);
		pPRBlock->m_ACBusArray[pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]+nBus+1].fRtV=pBpaBlock->m_BpaDat_DCBusArray[nBus].fDCV/pBpaBlock->m_BpaDat_DCBusArray[nBus].fkV;
	}
}

//////////////////////////////////////////////////////////////////////////
//	直流等效负荷
void BpaMemDB2PRMemDB_DCSystem(tagBpaBlock* pBpaBlock, tagPRBlock* pPRBlock)
{
	int		nDev, nIBus, nZBus;
	double	fCurrent;

	for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_DCLINE]; nDev++)
	{
		if (pPRBlock->m_nRecordNum[PR_HVDC] >= m_PRMemDBInterface.PRGetTableMax(PR_HVDC)-1)
			break;
		//	直流损耗归算
		fCurrent=1000*pBpaBlock->m_BpaDat_DCLineArray[nDev].fDCPOWER/pBpaBlock->m_BpaDat_DCLineArray[nDev].fRVOLT;

		memset(&pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]], 0, sizeof(tagPRHVDC));

		nIBus=pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]+pBpaBlock->m_BpaDat_DCLineArray[nDev].nRBus+1;
		nZBus=pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]+pBpaBlock->m_BpaDat_DCLineArray[nDev].nIBus+1;

		strcpy(pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].szName, pBpaBlock->m_BpaDat_DCLineArray[nDev].szKeyName);
		strcpy(pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].szACBusR, pBpaBlock->m_BpaDat_DCLineArray[nDev].szBusR);
		strcpy(pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].szACBusI, pBpaBlock->m_BpaDat_DCLineArray[nDev].szBusI);
		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fkVR=pBpaBlock->m_BpaDat_DCLineArray[nDev].fkVR;
		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fkVI=pBpaBlock->m_BpaDat_DCLineArray[nDev].fkVI;

		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fR=pBpaBlock->m_BpaDat_DCLineArray[nDev].fR;
		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fL=pBpaBlock->m_BpaDat_DCLineArray[nDev].fL;
		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fC=pBpaBlock->m_BpaDat_DCLineArray[nDev].fC;
		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].cCon=pBpaBlock->m_BpaDat_DCLineArray[nDev].cControl;

		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fRatedC=pBpaBlock->m_BpaDat_DCLineArray[nDev].fAMP;
		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fRectV=pBpaBlock->m_BpaDat_DCLineArray[nDev].fRVOLT;
		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fRatedP=pBpaBlock->m_BpaDat_DCLineArray[nDev].fAMP*pBpaBlock->m_BpaDat_DCLineArray[nDev].fRVOLT/1000;
		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fLength=pBpaBlock->m_BpaDat_DCLineArray[nDev].fLength;

		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fDCPower=pBpaBlock->m_BpaDat_DCLineArray[nDev].fDCPOWER;

		strcpy(pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].szIniBusR, pBpaBlock->m_BpaDat_DCLineArray[nDev].szBusR);
		strcpy(pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].szIniBusI, pBpaBlock->m_BpaDat_DCLineArray[nDev].szBusI);

		if (fabs(pBpaBlock->m_BpaDat_DCLineArray[nDev].fPr) < FLT_MIN)
		{
			fCurrent=1000*pBpaBlock->m_BpaDat_DCLineArray[nDev].fDCPOWER/pBpaBlock->m_BpaDat_DCLineArray[nDev].fRVOLT;
			pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fPr=pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fIniPr=pBpaBlock->m_BpaDat_DCLineArray[nDev].fDCPOWER;
			pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fPi=pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fIniPi=(float)(pBpaBlock->m_BpaDat_DCLineArray[nDev].fDCPOWER-fCurrent*fCurrent*pBpaBlock->m_BpaDat_DCLineArray[nDev].fR/1000000);
			pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fLossP = (float)(fCurrent*fCurrent*pBpaBlock->m_BpaDat_DCLineArray[nDev].fR/1000000);
			pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fMSPout=pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fPr;
		}
		else
		{
			pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fPr=pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fIniPr=pBpaBlock->m_BpaDat_DCLineArray[nDev].fPr;
			pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fPi=pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fIniPi=pBpaBlock->m_BpaDat_DCLineArray[nDev].fPi;
			pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fLossP = (float)(pBpaBlock->m_BpaDat_DCLineArray[nDev].fPr + pBpaBlock->m_BpaDat_DCLineArray[nDev].fPi);
		}
		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fMSPout=pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fPr;

		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].nRBus=nIBus;
		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].nIBus=nZBus;

		pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].nIndex=nDev;

		pPRBlock->m_nRecordNum[PR_HVDC]++;
	}
}

//////////////////////////////////////////////////////////////////////////
//	环辐网边界等效负荷
void BpaMemDB2PRMemDB_Radiate(tagBpaBlock* pBpaBlock, tagPRBlock* pPRBlock)
{
	int		nDev;
	float	fBuffer;

	for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; nDev++)
	{
		if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus].bInRing != pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus].bInRing)
		{
			fBuffer=fabs(fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fPi)-fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fPz))/2;
			if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus].bInRing)
			{
				pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus+1].bRingBound=1;
				pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus+1].fRadP += pBpaBlock->m_BpaDat_ACLineArray[nDev].fPi;
				//pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus+1].fBusLossP -= fBuffer;
				//pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus+1].fBusLossP += fBuffer;
				//Log(g_lpszLogFile, "边界线路I母线[%s%g]设置负荷 = %g [%g]\n", 
				//	pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus].szName, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus].fkV, 
				//	pBpaBlock->m_BpaDat_ACLineArray[nDev].fPi, pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus+1].fRadP);

			}
			else
			{
				pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus+1].bRingBound = 1;
				pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus+1].fRadP += pBpaBlock->m_BpaDat_ACLineArray[nDev].fPz;
				//pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus+1].fBusLossP -= fBuffer;
				//pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus+1].fBusLossP += fBuffer;
				//Log(g_lpszLogFile, "边界线路J母线[%s%g]设置负荷 = %g [%g]\n", 
				//	pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus].szName, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus].fkV, 
				//	pBpaBlock->m_BpaDat_ACLineArray[nDev].fPz, pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus+1].fRadP);
			}
		}
	}

	for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)
	{
		if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard)
			continue;

		if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].bInRing != pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].bInRing)
		{
			fBuffer=fabs(fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fPi)-fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fPz))/2;
			if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].bInRing)
			{
				pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus+1].bRingBound = 1;
				pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus+1].fRadP += pBpaBlock->m_BpaDat_WindArray[nDev].fPi;
				//pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus+1].fBusLossP -= fBuffer;
				//pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus+1].fBusLossP += fBuffer;
				//Log(g_lpszLogFile, "边界变压器I母线[%s%g]设置负荷 = %g [%g]\n", 
				//	pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].szName, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].fkV, 
				//	pBpaBlock->m_BpaDat_WindArray[nDev].fPi, pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus+1].fRadP);
			}
			else
			{
				pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus+1].bRingBound = 1;
				pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus+1].fRadP += pBpaBlock->m_BpaDat_WindArray[nDev].fPz;
				//pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus+1].fBusLossP -= fBuffer;
				//pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus+1].fBusLossP += fBuffer;
				//Log(g_lpszLogFile, "边界变压器J母线[%s%g]设置负荷 = %g [%g]\n", 
				//	pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].szName, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].fkV, 
				//	pBpaBlock->m_BpaDat_WindArray[nDev].fPz, pPRBlock->m_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus+1].fRadP);
			}
		}
	}
}

//	下文中的可靠性参数中没有考虑直流
void BpaMemDB2PRMemDB(tagBpaBlock* pBpaBlock, tagPRBlock* pPRBlock, const char* lpszBpaDatFile, const char* lpszBpaSwiFile, const unsigned char bGenBusLoadAsAux)
{
	register int	i;
	int		nRadial, nDev, nBus;
	int		nMaxBusNumber;

	pPRBlock->m_nRecordNum[PR_SYSTEM]=1;
	pPRBlock->m_nRecordNum[PR_RADIAL]=0;
	pPRBlock->m_nRecordNum[PR_ACBUS]=0;
	pPRBlock->m_nRecordNum[PR_ACLINE]=0;
	pPRBlock->m_nRecordNum[PR_WIND]=0;
	pPRBlock->m_nRecordNum[PR_DCBUS]=0;
	pPRBlock->m_nRecordNum[PR_CONVERTER]=0;
	pPRBlock->m_nRecordNum[PR_DCLINE]=0;
	pPRBlock->m_nRecordNum[PR_HVDC]=0;
	pPRBlock->m_nRecordNum[PR_TCSC]=0;
	pPRBlock->m_nRecordNum[PR_UPFC]=0;
	pPRBlock->m_nRecordNum[PR_GENERATOR]=0;
	pPRBlock->m_nRecordNum[PR_POWERLOAD]=0;
	pPRBlock->m_nRecordNum[PR_ZONE]=0;

	pPRBlock->m_System.fMvaBase=pBpaBlock->m_BpaDat_Case.fMVABase;
	if (pPRBlock->m_System.fMvaBase < FLT_MIN)	pPRBlock->m_System.fMvaBase=100;
	strcpy(pPRBlock->m_System.szBpaDatFile, lpszBpaDatFile);
	strcpy(pPRBlock->m_System.szBpaSwiFile, lpszBpaSwiFile);

	if (pBpaBlock->m_nRecordNum[BPA_DAT_RADIATE] <= 0)
	{
		memset(&pPRBlock->m_RadialArray[pPRBlock->m_nRecordNum[PR_RADIAL]], 0, sizeof(tagPRRadial));
		pPRBlock->m_nRecordNum[PR_RADIAL]++;
	}
	for (nRadial=0; nRadial<pBpaBlock->m_nRecordNum[BPA_DAT_RADIATE]; nRadial++)
	{
		memset(&pPRBlock->m_RadialArray[pPRBlock->m_nRecordNum[PR_RADIAL]], 0, sizeof(tagPRRadial));
		strcpy(pPRBlock->m_RadialArray[pPRBlock->m_nRecordNum[PR_RADIAL]].szRingBus, pBpaBlock->m_BpaDat_RadiateArray[nRadial].szBoundBusName);
		pPRBlock->m_RadialArray[pPRBlock->m_nRecordNum[PR_RADIAL]].fRingkV=pBpaBlock->m_BpaDat_RadiateArray[nRadial].fBoundBuskV;
		pPRBlock->m_RadialArray[pPRBlock->m_nRecordNum[PR_RADIAL]].fLoadP=pBpaBlock->m_BpaDat_RadiateArray[nRadial].fLoadP;
		pPRBlock->m_nRecordNum[PR_RADIAL]++;
	}

	//////////////////////////////////////////////////////////////////////////
	//	读BPA分区数据
	memset(&pPRBlock->m_ZoneArray[pPRBlock->m_nRecordNum[PR_ZONE]], 0, sizeof(tagPRZone));
	pPRBlock->m_nRecordNum[PR_ZONE]++;
	for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ZONE]; nDev++)
	{
		if (strlen(pBpaBlock->m_BpaDat_ZoneArray[nDev].szName) <= 0)
			continue;

		memset(&pPRBlock->m_ZoneArray[pPRBlock->m_nRecordNum[PR_ZONE]], 0, sizeof(tagPRZone));
		strcpy(pPRBlock->m_ZoneArray[pPRBlock->m_nRecordNum[PR_ZONE]].szName, pBpaBlock->m_BpaDat_ZoneArray[nDev].szName);
		strcpy(pPRBlock->m_ZoneArray[pPRBlock->m_nRecordNum[PR_ZONE]].szArea, pBpaBlock->m_BpaDat_ZoneArray[nDev].szArea);
		pPRBlock->m_nRecordNum[PR_ZONE]++;
	}

	BpaMemDB2PRMemDB_ACLine(pBpaBlock, pPRBlock, nMaxBusNumber);

	BpaMemDB2PRMemDB_Wind(pBpaBlock, pPRBlock, nMaxBusNumber);

	log_debug("最大母线号=%d ACBusNum=%d DCBusNum=%d\n", nMaxBusNumber, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS], pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]);

	BpaMemDB2PRMemDB_ACBusLoadGen(pBpaBlock, pPRBlock, nMaxBusNumber);

	BpaMemDB2PRMemDB_DCBus(pBpaBlock, pPRBlock);

	BpaMemDB2PRMemDB_DCSystem(pBpaBlock, pPRBlock);

	BpaMemDB2PRMemDB_Radiate(pBpaBlock, pPRBlock);

	nBus=1;
	while (nBus < pPRBlock->m_nRecordNum[PR_ACBUS])
	{
		if (strlen(pPRBlock->m_ACBusArray[nBus].szName) <= 0)
			m_PRMemDBInterface.PRRemoveRecord(pPRBlock, PR_ACBUS, nBus);
		else
			nBus++;
	}

	m_PRMemDBInterface.PRMaint(pPRBlock);

	//////////////////////////////////////////////////////////////////////////
	//	容量初始化(由BPA初始化，此时多状态模型还未读入，所以使用BPA数据进行初始化)
	pPRBlock->m_System.fSysGenP=0;
	pPRBlock->m_System.fSysLoadP=0;
	pPRBlock->m_System.fSysDCP=0;
	pPRBlock->m_System.fSysAvailGenP=0;
	pPRBlock->m_System.fSysMaxLoadP=0;
	for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
	{
		pPRBlock->m_ACBusArray[nBus].fMaxGenP=0;
		pPRBlock->m_ACBusArray[nBus].fMinGenP=0;
		pPRBlock->m_ACBusArray[nBus].fMinLoadP=0;

		pPRBlock->m_System.fSysGenP  += (float)(pPRBlock->m_ACBusArray[nBus].fGenP );
		pPRBlock->m_System.fSysLoadP += (float)(pPRBlock->m_ACBusArray[nBus].fLoadP);
	}
	for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
	{
		if (pPRBlock->m_GeneratorArray[nDev].nBusIndex < 0)
			continue;

		nBus=pPRBlock->m_GeneratorArray[nDev].nBusIndex;
		pPRBlock->m_ACBusArray[nBus].fMaxGenP += pPRBlock->m_GeneratorArray[nDev].fPMax;
		pPRBlock->m_ACBusArray[nBus].fMinGenP += pPRBlock->m_GeneratorArray[nDev].fPMin;
		pPRBlock->m_System.fSysAvailGenP += pPRBlock->m_GeneratorArray[nDev].fPMax;
	}
	for (nBus=0; nBus<pPRBlock->m_nRecordNum[PR_HVDC]; nBus++)
	{
		pPRBlock->m_System.fSysDCP += pPRBlock->m_HVDCArray[nBus].fDCPower;
	}

	pPRBlock->m_System.fSysMaxLoadP=pPRBlock->m_System.fSysLoadP;

	//////////////////////////////////////////////////////////////////////////
	//	分区信息初始化
	int		nZone;
	for (nZone=0; nZone<pPRBlock->m_nRecordNum[PR_ZONE]; nZone++)
	{
		pPRBlock->m_ZoneArray[nZone].fTotGenP = 0;
		pPRBlock->m_ZoneArray[nZone].fTotLoadP = 0;
	}
	for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
	{
		nBus=pPRBlock->m_GeneratorArray[nDev].nBusIndex;
		if (nBus < 0)	continue;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_ZONE]; i++)
		{
			if (stricmp(pPRBlock->m_ACBusArray[nBus].szZone, pPRBlock->m_ZoneArray[i].szName) == 0)
			{
				pPRBlock->m_ZoneArray[i].fTotGenP += pPRBlock->m_GeneratorArray[nDev].fP;
				break;
			}
		}
	}
	for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_POWERLOAD]; nDev++)
	{
		nBus=pPRBlock->m_PowerLoadArray[nDev].nBusIndex;
		if (nBus < 0)
			continue;

		if (bGenBusLoadAsAux)
		{
			if (pPRBlock->m_ACBusArray[nBus].bSrcBus)
				continue;
		}

		for (i=0; i<pPRBlock->m_nRecordNum[PR_ZONE]; i++)
		{
			if (stricmp(pPRBlock->m_ACBusArray[nBus].szZone, pPRBlock->m_ZoneArray[i].szName) == 0)
			{
				pPRBlock->m_ZoneArray[i].fTotLoadP += pPRBlock->m_PowerLoadArray[nDev].fP;
				break;
			}
		}
	}
	for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
	{
		pPRBlock->m_ACBusArray[nBus].nZone=-1;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_ZONE]; i++)
		{
			if (stricmp(pPRBlock->m_ZoneArray[i].szName, pPRBlock->m_ACBusArray[nBus].szZone) == 0)
			{
				pPRBlock->m_ACBusArray[nBus].nZone=i;
				break;
			}
		}
	}
}
