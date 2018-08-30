#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"

//	电压控制预留，暂时不用
namespace	BpaMemDB
{
	const	static	char*	lpszBusNameFormat="%-8s %.2f";
	const	static	int		nSwiModTables[]=
	{
		BPA_SWI_GEN,
		BPA_SWI_WGEGEN,
		BPA_SWI_GENLN,
		BPA_SWI_EXCIT68,
		BPA_SWI_EXCIT81,
		BPA_SWI_EXCITMV,
		BPA_SWI_EXCITX,
		BPA_SWI_PSSS,
		BPA_SWI_PSSSH,
		//BPA_SWI_PSSSH1,
		//BPA_SWI_PSSSH2,
		BPA_SWI_PSSSI,
		BPA_SWI_PSSSA,
		BPA_SWI_PSSSB,
		BPA_SWI_PSSST,
		BPA_SWI_GG,
		BPA_SWI_GH,
		BPA_SWI_GC,
		BPA_SWI_GS,
		BPA_SWI_GL,
		BPA_SWI_GW,
		BPA_SWI_GA,
		BPA_SWI_GI,
		BPA_SWI_GJ,
		BPA_SWI_GK,
		BPA_SWI_GM,
		BPA_SWI_GD,
		BPA_SWI_GZ,
		BPA_SWI_TA,
		BPA_SWI_TB,
		BPA_SWI_TC,
		BPA_SWI_TD,
		BPA_SWI_TE,
		BPA_SWI_TF,
		BPA_SWI_TW,
		BPA_SWI_GX,
		BPA_SWI_IGV,
		BPA_SWI_FGV,
		BPA_SWI_V,
		BPA_SWI_VG,
		BPA_SWI_LAB,
		BPA_SWI_MI,
		BPA_SWI_ML,
		BPA_SWI_RE,
		BPA_SWI_RW,
	};

	typedef	struct  _BpaHGBus_
	{
		std::string	strBoundHGBus;
		std::string	strBoundACLine;
		float		fBoundHGBuskV;
		float		fHGShunt;
	}	tagBpaHGBus;

	unsigned char IsExcludeBus(std::vector<std::string>& strExcludeBusArray, const char* lpszBusName, const float fBuskV)
	{
		register int	i;
		char	szBuf[260];

		sprintf(szBuf, lpszBusNameFormat, lpszBusName, fBuskV);
		for (i=0; i<(int)strExcludeBusArray.size(); i++)
		{
			if (stricmp(strExcludeBusArray[i].c_str(), szBuf) == 0)
			{
				return 1;
				break;
			}
		}
		return 0;
	}

	unsigned char IsACBusInRetainZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, const char* lpszBusName, const float fBuskV)
	{
		register int	i;
		int		nBus;
		unsigned char	bInArea;
		char	szBuf[260];

		nBus=-1;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
		{
			if (strcmp(lpszBusName, pBpaBlock->m_BpaDat_ACBusArray[i].szName) == 0 && fabs(fBuskV-pBpaBlock->m_BpaDat_ACBusArray[i].fkV) < 0.1)
			{
				nBus=i;
				break;
			}
		}
		if (nBus < 0)
			return 0;

		bInArea=0;
		for (i=0; i<(int)strRetainZoneArray.size(); i++)
		{
			if (strcmp(pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone, strRetainZoneArray[i].c_str()) == 0)
			{
				bInArea=1;
				break;
			}
		}
		if (!bInArea)
			return 0;

		sprintf(szBuf, lpszBusNameFormat, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);
		for (i=0; i<(int)strExcludeACBusArray.size(); i++)
		{
			if (stricmp(strExcludeACBusArray[i].c_str(), szBuf) == 0)
				return 0;
		}

		return 1;
	}

	unsigned char IsDCBusInRetainZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeDCBusArray, const char* lpszBusName, const float fBuskV)
	{
		register int	i;
		int		nBus;
		unsigned char	bInArea;
		char	szBuf[260];

		nBus=-1;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; i++)
		{
			if (strcmp(lpszBusName, pBpaBlock->m_BpaDat_DCBusArray[i].szName) == 0 && fabs(fBuskV-pBpaBlock->m_BpaDat_DCBusArray[i].fkV) < 0.1)
			{
				nBus=i;
				break;
			}
		}
		if (nBus < 0)
			return 0;

		bInArea=0;
		for (i=0; i<(int)strRetainZoneArray.size(); i++)
		{
			if (strcmp(pBpaBlock->m_BpaDat_DCBusArray[nBus].szZone, strRetainZoneArray[i].c_str()) == 0)
			{
				bInArea=1;
				break;
			}
		}
		if (!bInArea)
			return 0;

		sprintf(szBuf, lpszBusNameFormat, pBpaBlock->m_BpaDat_DCBusArray[nBus].szName, pBpaBlock->m_BpaDat_DCBusArray[nBus].fkV);
		for (i=0; i<(int)strExcludeDCBusArray.size(); i++)
		{
			if (stricmp(strExcludeDCBusArray[i].c_str(), szBuf) == 0)
				return 0;
		}

		return 1;
	}

	void BpaGetTieACLineByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, int& nTieNum, int nTieACLineArray[])
	{
		int		nDev, nInAreaI, nInAreaJ;

		nTieNum=0;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; nDev++)
		{
			nInAreaI=IsACBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI);
			nInAreaJ=IsACBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ);
			if (nInAreaI != nInAreaJ)
			{
				if (nInAreaI != 0)
					nTieACLineArray[nTieNum++] = nDev+1;
				else
					nTieACLineArray[nTieNum++] = -nDev-1;
			}
		}
	}

	void BpaGetTieLineHGByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, int& nTieNum, int nTieLineHGArray[])
	{
		int		nDev, nInAreaI, nInAreaJ;

		nTieNum=0;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; nDev++)
		{
			nInAreaI=IsACBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusI, pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVI);
			nInAreaJ=IsACBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusJ, pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVJ);
			if (nInAreaI != nInAreaJ)
			{
				if (nInAreaI != 0)
					nTieLineHGArray[nTieNum++] = nDev+1;
				else
					nTieLineHGArray[nTieNum++] = -nDev-1;
			}
		}
	}

	void BpaGetTieDCLineByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeDCBusArray, int& nTieNum, int nTieDCLineArray[])
	{
		int		nDev, nInAreaI, nInAreaJ;

		nTieNum=0;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_DCLINE]; nDev++)
		{
			nInAreaI=IsDCBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeDCBusArray, pBpaBlock->m_BpaDat_DCLineArray[nDev].szBusR, pBpaBlock->m_BpaDat_DCLineArray[nDev].fkVR);
			nInAreaJ=IsDCBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeDCBusArray, pBpaBlock->m_BpaDat_DCLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_DCLineArray[nDev].fkVI);
			if (nInAreaI != nInAreaJ)
			{
				if (nInAreaI != 0)
					nTieDCLineArray[nTieNum++] = nDev+1;	//	表明R侧等值，整流侧等效为负荷
				else
					nTieDCLineArray[nTieNum++] = -nDev-1;	//	表明I侧等值，逆变侧等效为负荷
			}
		}
	}

	void BpaGetTieTranByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, std::vector<std::string>& strExcludeDCBusArray, int& nTieNum, int nTieTranArray[])
	{
		int		nDev, nInAreaI, nInAreaJ;

		nTieNum=0;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)
		{
			if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard == 0)
			{
				nInAreaI=IsACBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].fkVI);
				nInAreaJ=IsACBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ);
				if (nInAreaI != nInAreaJ)
				{
					if (nInAreaI != 0)
						nTieTranArray[nTieNum++] = nDev+1;
					else
						nTieTranArray[nTieNum++] = -nDev-1;
				}
			}
			else if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard == 1)
			{
				nInAreaI=IsDCBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeDCBusArray, pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].fkVI);
				nInAreaJ=IsACBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ);
				if (nInAreaI != nInAreaJ)
				{
					if (nInAreaI != 0)
						nTieTranArray[nTieNum++] = nDev+1;
					else
						nTieTranArray[nTieNum++] = -nDev-1;
				}
			}
			else if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard == 2)
			{
				nInAreaI=IsACBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].fkVI);
				nInAreaJ=IsDCBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeDCBusArray, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ);
				if (nInAreaI != nInAreaJ)
				{
					if (nInAreaI != 0)
						nTieTranArray[nTieNum++] = nDev+1;
					else
						nTieTranArray[nTieNum++] = -nDev-1;
				}
			}
		}
	}

	int BpaTailorNetByZone(tagBpaBlock* pBpaBlock, const unsigned char bRetainTieHG, const unsigned char bDCBoundPV, const char* lpszSlack, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, std::vector<std::string>& strExcludeDCBusArray)
	{
		register int	i, j;
		int		nDev, nGen, nBusI, nBusJ, nBoundBus, nDCBus, nRCard, nTieLine;
		int		nTable, nField;
		float	fDCLoad;
		double	fGenPFactor, fGenQFactor, fLoadPFactor, fLoadQFactor;
		unsigned char	bFindGen, bDCRSide;
		int	nTieACLineNum, nTieACLineArray[1000];
		int	nTieLineHGNum, nTieLineHGArray[1000];
		int	nTieDCLineNum, nTieDCLineArray[100];
		int	nTieTranNum, nTieTranArray[500];
		std::vector<tagBpaHGBus>	sBpaHGBusArray;
		tagBpaHGBus	sHGBus;

		char	szBuf[260];
		std::vector<std::string>	strDCBoundBusArray;	//	直流等效交流母线，即交直流边界母线

		strDCBoundBusArray.clear();

		Log(g_lpszLogFile, "BpaTailorNetByZone Slack=%s RetainHG=%d DCPV=%d\n", lpszSlack, bRetainTieHG, bDCBoundPV);

		BpaGetTieACLineByZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, nTieACLineNum, nTieACLineArray);
		BpaGetTieLineHGByZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, nTieLineHGNum, nTieLineHGArray);
		BpaGetTieDCLineByZone(pBpaBlock, strRetainZoneArray, strExcludeDCBusArray, nTieDCLineNum, nTieDCLineArray);
		BpaGetTieTranByZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, strExcludeDCBusArray, nTieTranNum, nTieTranArray);

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bRedcution = 0;

		//////////////////////////////////////////////////////////////////////////
		//	通过联络线形成交流边界的发电和负荷
		for (nDev=0; nDev<nTieACLineNum; nDev++)
		{
			nTieLine=abs(nTieACLineArray[nDev])-1;
			if (nTieACLineArray[nDev] > 0)
				nBoundBus=pBpaBlock->m_BpaDat_ACLineArray[nTieLine].nIBus;
			else
				nBoundBus=pBpaBlock->m_BpaDat_ACLineArray[nTieLine].nZBus;

			if (nBoundBus < 0)
			{
				Log(g_lpszLogFile, "    交流联络线【%s】边界母线错误\n", pBpaBlock->m_BpaDat_ACLineArray[nTieLine].szKeyName);
				continue;
			}
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].bRedcution = 1;

			strcpy(pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szCardKey, "BQ");
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fVHold_max=pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fV/pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV;
			if (pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fVHold_max < 0.8 || pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fVHold_max > 1.2)
				pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fVHold_max=1.0;
			Log(g_lpszLogFile, "    联络线-发电机 Bus=%s\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName);

			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fPmax = 0;
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQsched_Qmax = 0;
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQmin = 0;

			fGenPFactor=fGenQFactor=fLoadPFactor=fLoadQFactor=1;
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_P]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaDat_PArray[i].szZone, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szZone) == 0)
				{
					fGenPFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
					fGenQFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenQFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenQFactor : 1;
					fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
					fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor : 1;
					break;
				}
			}

			if (pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fPi > 0 && nTieACLineArray[nDev] > 0 || pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fPi < 0 && nTieACLineArray[nDev] < 0)
			{
				if (nTieACLineArray[nDev] > 0)
				{
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fLoadP += pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fPi/fLoadPFactor;
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fLoadQ += pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fQi/fLoadQFactor;
					Log(g_lpszLogFile, "    联络线-负荷 Bus=%s Load=%.1f %.1f\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName, pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fPi, pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fQi);
				}
				else
				{
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fLoadP += pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fPz/fLoadPFactor;
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fLoadQ += pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fQz/fLoadQFactor;
					Log(g_lpszLogFile, "    联络线-负荷 Bus=%s Load=%.1f %.1f\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName, pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fPz, pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fQz);
				}
			}
			else
			{
				if (nTieACLineArray[nDev] > 0)
				{
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fPGen        -= pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fPi/fGenPFactor;
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQsched_Qmax -= pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fQi/fGenQFactor;
					Log(g_lpszLogFile, "    联络线-发电 Bus=%s Load=%.1f %.1f\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName, pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fPi, pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fQi);
				}
				else
				{
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fPGen        -= pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fPz/fGenPFactor;
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQsched_Qmax -= pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fQz/fGenQFactor;
					Log(g_lpszLogFile, "    联络线-发电 Bus=%s Load=%.1f %.1f\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName, pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fPz, pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fQz);
				}

				bFindGen=0;
				for (nGen=0; nGen<pBpaBlock->m_nRecordNum[BPA_SWI_GEN]; nGen++)
				{
					if (stricmp(pBpaBlock->m_BpaSwi_GenArray[nGen].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName) == 0 &&
						fabs(pBpaBlock->m_BpaSwi_GenArray[nGen].fBus_kV-pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV) < 0.1)
					{
						bFindGen=1;
						break;
					}
				}
				if (!bFindGen)
				{
					for (nGen=0; nGen<pBpaBlock->m_nRecordNum[BPA_SWI_WGEGEN]; nGen++)
					{
						if (stricmp(pBpaBlock->m_BpaSwi_WGEGenArray[nGen].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName) == 0 &&
							fabs(pBpaBlock->m_BpaSwi_WGEGenArray[nGen].fBus_kV-pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV) < 0.1)
						{
							bFindGen=1;
							break;
						}
					}
				}
				if (!bFindGen)
				{
					for (nGen=0; nGen<pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]; nGen++)
					{
						if (stricmp(pBpaBlock->m_BpaSwi_GenLnArray[nGen].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName) == 0 &&
							fabs(pBpaBlock->m_BpaSwi_GenLnArray[nGen].fBus_kV-pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV) < 0.1)
						{
							bFindGen=1;
							break;
						}
					}
				}
				if (!bFindGen)
				{
					memset(&pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]], 0, sizeof(tagBpaSwi_Gen));
					strcpy(pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]].szCardKey, "MC");
					strcpy(pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName);
					pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]].fBus_kV=pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV;
					pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]].fEmws=999;
					pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]].fXdp=0.01f;
					sprintf(pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]].szKeyName, "%s%.0f", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV);
					pBpaBlock->m_nRecordNum[BPA_SWI_GEN]++;
					Log(g_lpszLogFile, "    联络线-边界发电机模型 Bus=%s\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName);
				}
			}
		}
		for (nDev=0; nDev<nTieACLineNum; nDev++)
		{
			nTieLine=abs(nTieACLineArray[nDev])-1;
			if (nTieACLineArray[nDev] > 0)
				nBoundBus=pBpaBlock->m_BpaDat_ACLineArray[nTieLine].nIBus;
			else
				nBoundBus=pBpaBlock->m_BpaDat_ACLineArray[nTieLine].nZBus;

			if (nBoundBus < 0)
				continue;
			if (pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fPi > 0 && nTieACLineArray[nDev] > 0 || pBpaBlock->m_BpaDat_ACLineArray[nTieLine].fPi < 0 && nTieACLineArray[nDev] < 0)
				continue;

			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fPmax = pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fPGen;
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQmin = (pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQsched_Qmax > 0) ? 0 : pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQsched_Qmax;
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQsched_Qmax = 2000;
		}

		//////////////////////////////////////////////////////////////////////////
		//	通过联络线形成交流边界的补偿
		sBpaHGBusArray.clear();
		for (nDev=0; nDev<nTieLineHGNum; nDev++)
		{
			nTieLine=abs(nTieLineHGArray[nDev])-1;
			if (nTieLineHGArray[nDev] > 0)
				nBoundBus=pBpaBlock->m_BpaDat_LineHGArray[nTieLine].nIBus;
			else
				nBoundBus=pBpaBlock->m_BpaDat_LineHGArray[nTieLine].nZBus;

			if (nBoundBus < 0)
			{
				Log(g_lpszLogFile, "    交流联络线【%s】边界母线错误\n", pBpaBlock->m_BpaDat_LineHGArray[nTieLine].szKeyName);
				continue;
			}

			sHGBus.strBoundHGBus = pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName;
			sHGBus.fBoundHGBuskV = pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV;
			sHGBus.strBoundACLine = pBpaBlock->m_BpaDat_LineHGArray[nTieLine].szKeyName;
			sHGBus.fHGShunt = 0;
			if ((pBpaBlock->m_BpaDat_LineHGArray[nTieLine].fShuntI) > FLT_MIN && nTieLineHGArray[nDev] > 0)
			{
				sHGBus.fHGShunt += pBpaBlock->m_BpaDat_LineHGArray[nTieLine].fShuntI;
				Log(g_lpszLogFile, "    联络线-补偿I Bus=%s Shunt=%.1f Line=%s\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName, pBpaBlock->m_BpaDat_LineHGArray[nTieLine].fShuntI, pBpaBlock->m_BpaDat_LineHGArray[nTieLine].szKeyName);
			}
			if ((pBpaBlock->m_BpaDat_LineHGArray[nTieLine].fShuntJ) > FLT_MIN && nTieLineHGArray[nDev] < 0)
			{
				sHGBus.fHGShunt += pBpaBlock->m_BpaDat_LineHGArray[nTieLine].fShuntJ;
				Log(g_lpszLogFile, "    联络线-补偿J Bus=%s Shunt=%.1f Line=%s\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName, pBpaBlock->m_BpaDat_LineHGArray[nTieLine].fShuntJ, pBpaBlock->m_BpaDat_LineHGArray[nTieLine].szKeyName);
			}

			if ((sHGBus.fHGShunt) > FLT_MIN)
				sBpaHGBusArray.push_back(sHGBus);
		}

		//////////////////////////////////////////////////////////////////////////
		//	通过联络变形成交流边界的发电和负荷
		for (nDev=0; nDev<nTieTranNum; nDev++)
		{
			nTieLine=abs(nTieTranArray[nDev])-1;
			if (nTieTranArray[nDev] > 0)
				nBoundBus=pBpaBlock->m_BpaDat_WindArray[nTieLine].nIBus;
			else
				nBoundBus=pBpaBlock->m_BpaDat_WindArray[nTieLine].nZBus;

			if (nBoundBus < 0)
			{
				Log(g_lpszLogFile, "    联络变压器【%s】边界母线错误\n", pBpaBlock->m_BpaDat_WindArray[nTieLine].szKeyName);
				continue;
			}
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].bRedcution = 1;

			strcpy(pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szCardKey, "BQ");
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fVHold_max=pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fV/pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV;
			if (pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fVHold_max < 0.8 || pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fVHold_max > 1.2)
				pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fVHold_max=1.0;
			Log(g_lpszLogFile, "    联络变压器-发电机 Bus=%s\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName);

			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fPmax = 0;
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQsched_Qmax = 0;
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQmin = 0;

			fGenPFactor=fGenQFactor=fLoadPFactor=fLoadQFactor=1;
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_P]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaDat_PArray[i].szZone, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szZone) == 0)
				{
					fGenPFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
					fGenQFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenQFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenQFactor : 1;
					fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
					fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor : 1;
					break;
				}
			}

			if (pBpaBlock->m_BpaDat_WindArray[nTieLine].fPi > 0 && nTieTranArray[nDev] > 0 || pBpaBlock->m_BpaDat_WindArray[nTieLine].fPi < 0 && nTieTranArray[nDev] < 0)
			{
				if (nTieTranArray[nDev] > 0)
				{
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fLoadP += pBpaBlock->m_BpaDat_WindArray[nTieLine].fPi/fLoadPFactor;
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fLoadQ += pBpaBlock->m_BpaDat_WindArray[nTieLine].fQi/fLoadQFactor;
					Log(g_lpszLogFile, "    联络变压器-负荷 Bus=%s Load=%.1f %.1f\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName, pBpaBlock->m_BpaDat_WindArray[nTieLine].fPi, pBpaBlock->m_BpaDat_WindArray[nTieLine].fQi);
				}
				else
				{
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fLoadP += pBpaBlock->m_BpaDat_WindArray[nTieLine].fPz/fLoadPFactor;
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fLoadQ += pBpaBlock->m_BpaDat_WindArray[nTieLine].fQz/fLoadQFactor;
					Log(g_lpszLogFile, "    联络变压器-负荷 Bus=%s Load=%.1f %.1f\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName, pBpaBlock->m_BpaDat_WindArray[nTieLine].fPz, pBpaBlock->m_BpaDat_WindArray[nTieLine].fQz);
				}
			}
			else
			{
				if (nTieTranArray[nDev] > 0)
				{
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fPGen        -= pBpaBlock->m_BpaDat_WindArray[nTieLine].fPi/fGenPFactor;
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQsched_Qmax -= pBpaBlock->m_BpaDat_WindArray[nTieLine].fQi/fGenQFactor;
					Log(g_lpszLogFile, "    联络变压器-发电 Bus=%s Load=%.1f %.1f\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName, pBpaBlock->m_BpaDat_WindArray[nTieLine].fPi, pBpaBlock->m_BpaDat_WindArray[nTieLine].fQi);
				}
				else
				{
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fPGen        -= pBpaBlock->m_BpaDat_WindArray[nTieLine].fPz/fGenPFactor;
					pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQsched_Qmax -= pBpaBlock->m_BpaDat_WindArray[nTieLine].fQz/fGenQFactor;
					Log(g_lpszLogFile, "    联络变压器-发电 Bus=%s Load=%.1f %.1f\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName, pBpaBlock->m_BpaDat_WindArray[nTieLine].fPz, pBpaBlock->m_BpaDat_WindArray[nTieLine].fQz);
				}

				bFindGen=0;
				for (nGen=0; nGen<pBpaBlock->m_nRecordNum[BPA_SWI_GEN]; nGen++)
				{
					if (stricmp(pBpaBlock->m_BpaSwi_GenArray[nGen].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName) == 0 &&
						fabs(pBpaBlock->m_BpaSwi_GenArray[nGen].fBus_kV-pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV) < 0.1)
					{
						bFindGen=1;
						break;
					}
				}
				if (!bFindGen)
				{
					for (nGen=0; nGen<pBpaBlock->m_nRecordNum[BPA_SWI_WGEGEN]; nGen++)
					{
						if (stricmp(pBpaBlock->m_BpaSwi_WGEGenArray[nGen].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName) == 0 &&
							fabs(pBpaBlock->m_BpaSwi_WGEGenArray[nGen].fBus_kV-pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV) < 0.1)
						{
							bFindGen=1;
							break;
						}
					}
				}
				if (!bFindGen)
				{
					for (nGen=0; nGen<pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]; nGen++)
					{
						if (stricmp(pBpaBlock->m_BpaSwi_GenLnArray[nGen].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName) == 0 &&
							fabs(pBpaBlock->m_BpaSwi_GenLnArray[nGen].fBus_kV-pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV) < 0.1)
						{
							bFindGen=1;
							break;
						}
					}
				}
				if (!bFindGen)
				{
					memset(&pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]], 0, sizeof(tagBpaSwi_Gen));
					strcpy(pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]].szCardKey, "MC");
					strcpy(pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName);
					pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]].fBus_kV=pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV;
					pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]].fEmws=999;
					pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]].fXdp=0.01f;
					sprintf(pBpaBlock->m_BpaSwi_GenArray[pBpaBlock->m_nRecordNum[BPA_SWI_GEN]].szKeyName, "%s%.0f", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV);
					pBpaBlock->m_nRecordNum[BPA_SWI_GEN]++;
					Log(g_lpszLogFile, "    联络变压器-边界发电机模型 Bus=%s\n", pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName);
				}
			}
		}

		for (nDev=0; nDev<nTieTranNum; nDev++)
		{
			nTieLine=abs(nTieTranArray[nDev])-1;
			if (nTieTranArray[nDev] > 0)
				nBoundBus=pBpaBlock->m_BpaDat_WindArray[nTieLine].nIBus;
			else
				nBoundBus=pBpaBlock->m_BpaDat_WindArray[nTieLine].nZBus;

			if (nBoundBus < 0)
				continue;
			if (pBpaBlock->m_BpaDat_WindArray[nTieLine].fPi > 0 && nTieTranArray[nDev] > 0 || pBpaBlock->m_BpaDat_WindArray[nTieLine].fPi < 0 && nTieTranArray[nDev] < 0)
				continue;

			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fPmax = pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fPGen;
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQmin = (pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQsched_Qmax > 0) ? 0 : pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQsched_Qmax;
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fQsched_Qmax = 2000;
		}

		//////////////////////////////////////////////////////////////////////////
		//	生成直流等值系统
		for (nDev=0; nDev<nTieDCLineNum; nDev++)
		{
			nTieLine=abs(nTieDCLineArray[nDev])-1;

			nDCBus=-1;
			bDCRSide=0;	//	直流边界是否为整流侧
			if (nTieDCLineArray[nDev] > 0)
			{
				bDCRSide=1;

				nDCBus=pBpaBlock->m_BpaDat_DCLineArray[nTieLine].nRBus;
				if (fabs(pBpaBlock->m_BpaDat_DCLineArray[nTieLine].fPr) > FLT_MIN)
					fDCLoad = pBpaBlock->m_BpaDat_DCLineArray[nTieLine].fPr;
				else
					fDCLoad = pBpaBlock->m_BpaDat_DCLineArray[nTieLine].fDCPOWER;
			}
			else
			{
				nDCBus=pBpaBlock->m_BpaDat_DCLineArray[nTieLine].nIBus;
				if (fabs(pBpaBlock->m_BpaDat_DCLineArray[nTieLine].fPi) > FLT_MIN)
					fDCLoad = pBpaBlock->m_BpaDat_DCLineArray[nTieLine].fPi;
				else
					fDCLoad = -pBpaBlock->m_BpaDat_DCLineArray[nTieLine].fDCPOWER;
			}
			if (nDCBus < 0)
			{
				Log(g_lpszLogFile, "    直流联络线【%s】边界母线错误\n", pBpaBlock->m_BpaDat_DCLineArray[nTieLine].szKeyName);
				continue;
			}

			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
			{
				if (!pBpaBlock->m_BpaDat_WindArray[i].bRCard)
					continue;

				nRCard=-1;
				for (j=0; j<pBpaBlock->m_nRecordNum[BPA_DAT_R]; j++)
				{
					if ((strcmp(pBpaBlock->m_BpaDat_RArray[j].szBusI, pBpaBlock->m_BpaDat_WindArray[i].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[j].fkVI-pBpaBlock->m_BpaDat_WindArray[i].fkVI) < 0.15 &&
						strcmp(pBpaBlock->m_BpaDat_RArray[j].szBusJ, pBpaBlock->m_BpaDat_WindArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[j].fkVJ-pBpaBlock->m_BpaDat_WindArray[i].fkVJ) < 0.15) ||
						(strcmp(pBpaBlock->m_BpaDat_RArray[j].szBusI, pBpaBlock->m_BpaDat_WindArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[j].fkVI-pBpaBlock->m_BpaDat_WindArray[i].fkVJ) < 0.15 &&
						strcmp(pBpaBlock->m_BpaDat_RArray[j].szBusJ, pBpaBlock->m_BpaDat_WindArray[i].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[j].fkVJ-pBpaBlock->m_BpaDat_WindArray[i].fkVI) < 0.15))	//	防止出现诸如0.69和0.7之间的误差
					{
						nRCard=j;
						break;
					}
				}

				if (pBpaBlock->m_BpaDat_WindArray[i].bRCard == 1 && pBpaBlock->m_BpaDat_WindArray[i].nIBus == nDCBus)	//	主变I侧为直流母线
				{
					fGenPFactor=fGenQFactor=fLoadPFactor=fLoadQFactor=1;
					for (j=0; j<pBpaBlock->m_nRecordNum[BPA_DAT_P]; j++)
					{
						if (stricmp(pBpaBlock->m_BpaDat_PArray[j].szZone, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].szZone) == 0)
						{
							fGenPFactor=(pBpaBlock->m_BpaDat_PArray[j].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fGenPFactor : 1;
							fGenQFactor=(pBpaBlock->m_BpaDat_PArray[j].fGenQFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fGenQFactor : 1;
							fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[j].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fLoadPFactor : 1;
							fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[j].fLoadQFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fLoadQFactor : 1;
							break;
						}
					}

					if (bDCRSide)																		//	直流为整流侧或者直流线路转负荷，在变压器Z侧添加负荷
					{
						pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fLoadP += pBpaBlock->m_BpaDat_WindArray[i].fPz/fLoadPFactor;
						pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fLoadQ += pBpaBlock->m_BpaDat_WindArray[i].fQz/fLoadQFactor;
						Log(g_lpszLogFile, "    联络线-直流负荷 Bus=%s Load=%.1f %.1f\n", pBpaBlock->m_BpaDat_WindArray[i].szBusJ, pBpaBlock->m_BpaDat_WindArray[i].fPz, pBpaBlock->m_BpaDat_WindArray[i].fQz);
						if (fabs(pBpaBlock->m_BpaDat_WindArray[i].fPz) < FLT_MIN && fabs(fDCLoad) > FLT_MIN)	//	用直流设定值
						{
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fLoadP += fDCLoad/fLoadPFactor;
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fShuntQ = 0;
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fVHold_max = 0;
							Log(g_lpszLogFile, "        联络线-直流负荷 Bus=%s Load=%.1f\n", pBpaBlock->m_BpaDat_WindArray[i].szBusJ, fDCLoad);
						}
					}
					else																								//	直流为逆变侧且直流线路不转负荷，在变压器Z侧添加电源
					{
						pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fPGen        -= pBpaBlock->m_BpaDat_WindArray[i].fPz/fGenPFactor;
						pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fQsched_Qmax -= pBpaBlock->m_BpaDat_WindArray[i].fQz/fGenQFactor;
						Log(g_lpszLogFile, "    联络线-直流电源 Bus=%s Load=%.1f %.1f\n", pBpaBlock->m_BpaDat_WindArray[i].szBusJ, pBpaBlock->m_BpaDat_WindArray[i].fPz, pBpaBlock->m_BpaDat_WindArray[i].fQz);
						if (fabs(pBpaBlock->m_BpaDat_WindArray[i].fPz) < FLT_MIN && fabs(fDCLoad) > FLT_MIN)	//	用直流设定值
						{
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fPGen -= fDCLoad/fGenPFactor;
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fShuntQ = 0;
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fVHold_max = 0;
							Log(g_lpszLogFile, "        联络线-直流电源 Bus=%s Load=%.1f\n", pBpaBlock->m_BpaDat_WindArray[i].szBusJ, fDCLoad);
						}
						pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fPmax = pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fPGen;
					}

					if (bDCBoundPV || !bDCRSide)														//	直流做电源等效，设置PV节点
					{
						if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].szCardKey, "BS") != 0 &&
							stricmp(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].szCardKey, "BQ") != 0 &&
							stricmp(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].szCardKey, "BE") != 0)
						{
							strcpy(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].szCardKey, "BQ");
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fVHold_max=pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fV/pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fkV;
							if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fVHold_max < 0.8 || pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fVHold_max > 1.2)
								pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fVHold_max=1.0;
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fQsched_Qmax = 2000;
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fQmin = 0;
						}
					}

					sprintf(szBuf, lpszBusNameFormat, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].szName, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fkV);
					strDCBoundBusArray.push_back(szBuf);
					break;
				}
				else if (pBpaBlock->m_BpaDat_WindArray[i].bRCard == 2 && pBpaBlock->m_BpaDat_WindArray[i].nZBus == nDCBus)	//	主变Z侧为直流母线
				{
					fGenPFactor=fGenQFactor=fLoadPFactor=fLoadQFactor=1;
					for (j=0; j<pBpaBlock->m_nRecordNum[BPA_DAT_P]; j++)
					{
						if (stricmp(pBpaBlock->m_BpaDat_PArray[j].szZone, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].szZone) == 0)
						{
							fGenPFactor=(pBpaBlock->m_BpaDat_PArray[j].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fGenPFactor : 1;
							fGenQFactor=(pBpaBlock->m_BpaDat_PArray[j].fGenQFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fGenQFactor : 1;
							fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[j].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fLoadPFactor : 1;
							fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[j].fLoadQFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fLoadQFactor : 1;
							break;
						}
					}

					if (bDCRSide)																			//	直流为整流侧或者直流线路转负荷，在变压器I侧添加负荷
					{
						pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fLoadP += pBpaBlock->m_BpaDat_WindArray[i].fPi/fLoadPFactor;
						pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fLoadQ += pBpaBlock->m_BpaDat_WindArray[i].fQi/fLoadQFactor;
						Log(g_lpszLogFile, "    联络线-直流负荷 Bus=%s Load=%.1f %.1f\n", pBpaBlock->m_BpaDat_WindArray[i].szBusI, pBpaBlock->m_BpaDat_WindArray[i].fPi, pBpaBlock->m_BpaDat_WindArray[i].fQi);
						if (fabs(pBpaBlock->m_BpaDat_WindArray[i].fPi) < FLT_MIN && fabs(fDCLoad) > FLT_MIN)	//	用直流设定值
						{
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fLoadP += fDCLoad/fLoadPFactor;
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fShuntQ = 0;
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fVHold_max=0;
							Log(g_lpszLogFile, "        联络线-直流负荷 Bus=%s Load=%.1f\n", pBpaBlock->m_BpaDat_WindArray[i].szBusI, fDCLoad);
						}
					}
					else																									//	直流为逆变侧且直流线路不转负荷，在变压器I侧添加电源
					{
						pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fPGen        -= pBpaBlock->m_BpaDat_WindArray[i].fPi/fGenPFactor;
						pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fQsched_Qmax -= pBpaBlock->m_BpaDat_WindArray[i].fQi/fGenQFactor;
						Log(g_lpszLogFile, "    联络线-直流电源 Bus=%s Load=%.1f %.1f\n", pBpaBlock->m_BpaDat_WindArray[i].szBusI, pBpaBlock->m_BpaDat_WindArray[i].fPi, pBpaBlock->m_BpaDat_WindArray[i].fQi);
						if (fabs(pBpaBlock->m_BpaDat_WindArray[i].fPi) < FLT_MIN && fabs(fDCLoad) > FLT_MIN)	//	用直流设定值
						{
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fPGen -= fDCLoad/fGenPFactor;
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fShuntQ = 0;
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fVHold_max=0;
							Log(g_lpszLogFile, "        联络线-直流电源 Bus=%s Load=%.1f\n", pBpaBlock->m_BpaDat_WindArray[i].szBusI, fDCLoad);
						}
						pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fPmax = pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fPGen;
					}

					if (bDCBoundPV || !bDCRSide)															//	直流做电源等效，设置PV节点
					{
						if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].szCardKey, "BS") != 0 &&
							stricmp(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].szCardKey, "BQ") != 0 &&
							stricmp(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].szCardKey, "BE") != 0)
						{
							strcpy(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].szCardKey, "BQ");
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fVHold_max=pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fV/pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fkV;
							if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fVHold_max < 0.8 || pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fVHold_max > 1.2)
								pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fVHold_max=1.0;
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fQsched_Qmax = 2000;
							pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fQmin = 0;
						}
					}

					sprintf(szBuf, lpszBusNameFormat, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].szName, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fkV);
					strDCBoundBusArray.push_back(szBuf);
					break;
				}
			}
		}

		if (!strDCBoundBusArray.empty())
		{
			for (i=0; i<(int)strDCBoundBusArray.size(); i++)
				Log(g_lpszLogFile, "        直流边界母线[%d/%d]=%s\n", i+1, strDCBoundBusArray.size(), strDCBoundBusArray[i].c_str());
		}

		//////////////////////////////////////////////////////////////////////////
		//	将所有相关设备设置删除标记
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nDev++)	pBpaBlock->m_BpaDat_ACBusArray[nDev].nStatus=1;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; nDev++)	pBpaBlock->m_BpaDat_ACLineArray[nDev].nStatus=1;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; nDev++)	pBpaBlock->m_BpaDat_LineHGArray[nDev].nStatus=1;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)	pBpaBlock->m_BpaDat_WindArray[nDev].nStatus=1;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; nDev++)	pBpaBlock->m_BpaDat_DCBusArray[nDev].nStatus=1;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_DCLINE]; nDev++)	pBpaBlock->m_BpaDat_DCLineArray[nDev].nStatus=1;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_R]; nDev++)		pBpaBlock->m_BpaDat_RArray[nDev].nStatus=1;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_RZ]; nDev++)		pBpaBlock->m_BpaDat_RZArray[nDev].nStatus=1;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_P]; nDev++)		pBpaBlock->m_BpaDat_PArray[nDev].nStatus=1;

		//	交流母线在保留区域内，同时该母线有不在排除母线表中，则该母线保留。
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nDev++)
		{
			for (i=0; i<(int)strRetainZoneArray.size(); i++)
			{
				if (strcmp(pBpaBlock->m_BpaDat_ACBusArray[nDev].szZone, strRetainZoneArray[i].c_str()) == 0)
				{
					if (!IsExcludeBus(strExcludeACBusArray, pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, pBpaBlock->m_BpaDat_ACBusArray[nDev].fkV))
						pBpaBlock->m_BpaDat_ACBusArray[nDev].nStatus=0;
					break;
				}
			}
		}

		//	直流母线在保留区域内，同时该母线不在排除母线表中，则该母线保留。
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; nDev++)
		{
			for (i=0; i<(int)strRetainZoneArray.size(); i++)
			{
				if (strcmp(pBpaBlock->m_BpaDat_DCBusArray[nDev].szZone, strRetainZoneArray[i].c_str()) == 0)
				{
					if (!IsExcludeBus(strExcludeDCBusArray, pBpaBlock->m_BpaDat_DCBusArray[nDev].szName, pBpaBlock->m_BpaDat_DCBusArray[nDev].fkV))
						pBpaBlock->m_BpaDat_DCBusArray[nDev].nStatus=0;
					break;
				}
			}
		}

		//	交流线路两侧母线均为保留母线则该线路保留
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; nDev++)
		{
			nBusI=nBusJ=-1;
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			{
				if (pBpaBlock->m_BpaDat_ACBusArray[i].nStatus != 0)
					continue;

				if (strcmp(pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACBusArray[i].szName) == 0 && fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI-pBpaBlock->m_BpaDat_ACBusArray[i].fkV) < 0.1)
				{
					nBusI=i;
					break;
				}
			}
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			{
				if (pBpaBlock->m_BpaDat_ACBusArray[i].nStatus != 0)
					continue;

				if (strcmp(pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACBusArray[i].szName) == 0 && fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ-pBpaBlock->m_BpaDat_ACBusArray[i].fkV) < 0.1)
				{
					nBusJ=i;
					break;
				}
			}
			if (nBusI >= 0 && nBusJ >= 0)
				pBpaBlock->m_BpaDat_ACLineArray[nDev].nStatus=0;
		}

		//	直流线路必须两侧均为保留母线则该线路保留，两侧母线保留，这点与交流母线是有区别的。
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_DCLINE]; nDev++)
		{
			if (IsDCBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeDCBusArray, pBpaBlock->m_BpaDat_DCLineArray[nDev].szBusR, pBpaBlock->m_BpaDat_DCLineArray[nDev].fkVR) &&
				IsDCBusInRetainZone(pBpaBlock, strRetainZoneArray, strExcludeDCBusArray, pBpaBlock->m_BpaDat_DCLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_DCLineArray[nDev].fkVI))
			{
				pBpaBlock->m_BpaDat_DCLineArray[nDev].nStatus=0;
			}
			else
			{
				pBpaBlock->m_BpaDat_DCBusArray[pBpaBlock->m_BpaDat_DCLineArray[nDev].nRBus].nStatus=1;
				pBpaBlock->m_BpaDat_DCBusArray[pBpaBlock->m_BpaDat_DCLineArray[nDev].nIBus].nStatus=1;
			}
		}
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; nDev++)
		{
			nBusI=nBusJ=-1;
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			{
				if (pBpaBlock->m_BpaDat_ACBusArray[i].nStatus != 0)
					continue;

				if (strcmp(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACBusArray[i].szName) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVI-pBpaBlock->m_BpaDat_ACBusArray[i].fkV) < 0.1)
				{
					nBusI=i;
					break;
				}
			}
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			{
				if (pBpaBlock->m_BpaDat_ACBusArray[i].nStatus != 0)
					continue;

				if (strcmp(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACBusArray[i].szName) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVJ-pBpaBlock->m_BpaDat_ACBusArray[i].fkV) < 0.1)
				{
					nBusJ=i;
					break;
				}
			}
			if (nBusI >= 0 && nBusJ >= 0)
				pBpaBlock->m_BpaDat_LineHGArray[nDev].nStatus=0;
		}

		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)
		{
			if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard == 1)	//	I侧为直流
			{
				nBusI=nBusJ=-1;
				for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; i++)
				{
					if (pBpaBlock->m_BpaDat_DCBusArray[i].nStatus != 0)
						continue;

					if (strcmp(pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_DCBusArray[i].szName) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVI-pBpaBlock->m_BpaDat_DCBusArray[i].fkV) < 0.1)
					{
						nBusI=i;
						break;
					}
				}
				for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
				{
					if (pBpaBlock->m_BpaDat_ACBusArray[i].nStatus != 0)
						continue;

					if (strcmp(pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACBusArray[i].szName) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ-pBpaBlock->m_BpaDat_ACBusArray[i].fkV) < 0.1)
					{
						nBusJ=i;
						break;
					}
				}
				if (nBusI >= 0 && nBusJ >= 0)
				{
					pBpaBlock->m_BpaDat_WindArray[nDev].nStatus=0;
					for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_R]; i++)
					{
						if (stricmp(pBpaBlock->m_BpaDat_RArray[i].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[i].fkVI-pBpaBlock->m_BpaDat_WindArray[nDev].fkVI) < 0.1 &&
							stricmp(pBpaBlock->m_BpaDat_RArray[i].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[i].fkVJ-pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ) < 0.1 ||
							stricmp(pBpaBlock->m_BpaDat_RArray[i].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[i].fkVI-pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ) < 0.1 &&
							stricmp(pBpaBlock->m_BpaDat_RArray[i].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[i].fkVJ-pBpaBlock->m_BpaDat_WindArray[nDev].fkVI) < 0.1)
						{
							pBpaBlock->m_BpaDat_RArray[i].nStatus=0;
							break;
						}
					}
				}
			}
			else if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard == 2)	//	J侧为直流
			{
				nBusI=nBusJ=-1;
				for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
				{
					if (pBpaBlock->m_BpaDat_ACBusArray[i].nStatus != 0)
						continue;

					if (strcmp(pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACBusArray[i].szName) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVI-pBpaBlock->m_BpaDat_ACBusArray[i].fkV) < 0.001)
					{
						nBusI=i;
						break;
					}
				}
				for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; i++)
				{
					if (pBpaBlock->m_BpaDat_DCBusArray[i].nStatus != 0)
						continue;

					if (strcmp(pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, pBpaBlock->m_BpaDat_DCBusArray[i].szName) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ-pBpaBlock->m_BpaDat_DCBusArray[i].fkV) < 0.001)
					{
						nBusJ=i;
						break;
					}
				}
				if (nBusI >= 0 && nBusJ >= 0)
				{
					pBpaBlock->m_BpaDat_WindArray[nDev].nStatus=0;
					for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_R]; i++)
					{
						if (stricmp(pBpaBlock->m_BpaDat_RArray[i].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[i].fkVI-pBpaBlock->m_BpaDat_WindArray[nDev].fkVI) < 0.001 &&
							stricmp(pBpaBlock->m_BpaDat_RArray[i].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[i].fkVJ-pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ) < 0.001 ||
							stricmp(pBpaBlock->m_BpaDat_RArray[i].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[i].fkVI-pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ) < 0.001 &&
							stricmp(pBpaBlock->m_BpaDat_RArray[i].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[i].fkVJ-pBpaBlock->m_BpaDat_WindArray[nDev].fkVI) < 0.001)
						{
							pBpaBlock->m_BpaDat_RArray[i].nStatus=0;
							break;
						}
					}
				}
			}
			else
			{
				nBusI=nBusJ=-1;
				for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
				{
					if (pBpaBlock->m_BpaDat_ACBusArray[i].nStatus != 0)
						continue;

					if (strcmp(pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACBusArray[i].szName) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVI-pBpaBlock->m_BpaDat_ACBusArray[i].fkV) < 0.001)
					{
						nBusI=i;
						break;
					}
				}
				for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
				{
					if (pBpaBlock->m_BpaDat_ACBusArray[i].nStatus != 0)
						continue;

					if (strcmp(pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACBusArray[i].szName) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ-pBpaBlock->m_BpaDat_ACBusArray[i].fkV) < 0.001)
					{
						nBusJ=i;
						break;
					}
				}
				if (nBusI >= 0 && nBusJ >= 0)
					pBpaBlock->m_BpaDat_WindArray[nDev].nStatus=0;
			}
		}

		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_P]; nDev++)
		{
			for (i=0; i<(int)strRetainZoneArray.size(); i++)
			{
				if (strcmp(pBpaBlock->m_BpaDat_PArray[nDev].szZone, strRetainZoneArray[i].c_str()) == 0)
				{
					pBpaBlock->m_BpaDat_PArray[nDev].nStatus=0;
					break;
				}
			}
		}

		nDev=0;
		while (nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS])
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[nDev].nStatus)
				BpaRemoveRecord(pBpaBlock, BPA_DAT_ACBUS, nDev);
			else
				nDev++;
		}

		nDev=0;
		while (nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE])
		{
			if (pBpaBlock->m_BpaDat_ACLineArray[nDev].nStatus)
				BpaRemoveRecord(pBpaBlock, BPA_DAT_ACLINE, nDev);
			else
				nDev++;
		}

		nDev=0;
		while (nDev<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG])
		{
			if (pBpaBlock->m_BpaDat_LineHGArray[nDev].nStatus)
				BpaRemoveRecord(pBpaBlock, BPA_DAT_LINEHG, nDev);
			else
				nDev++;
		}

		nDev=0;
		while (nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND])
		{
			if (pBpaBlock->m_BpaDat_WindArray[nDev].nStatus)
				BpaRemoveRecord(pBpaBlock, BPA_DAT_WIND, nDev);
			else
				nDev++;
		}

		nDev=0;
		while (nDev<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS])
		{
			if (pBpaBlock->m_BpaDat_DCBusArray[nDev].nStatus)
				BpaRemoveRecord(pBpaBlock, BPA_DAT_DCBUS, nDev);
			else
				nDev++;
		}

		nDev=0;
		while (nDev<pBpaBlock->m_nRecordNum[BPA_DAT_DCLINE])
		{
			if (pBpaBlock->m_BpaDat_DCLineArray[nDev].nStatus)
				BpaRemoveRecord(pBpaBlock, BPA_DAT_DCLINE, nDev);
			else
				nDev++;
		}

		nDev=0;
		while (nDev<pBpaBlock->m_nRecordNum[BPA_DAT_R])
		{
			if (pBpaBlock->m_BpaDat_RArray[nDev].nStatus)
				BpaRemoveRecord(pBpaBlock, BPA_DAT_R, nDev);
			else
				nDev++;
		}

		nDev=0;
		while (nDev<pBpaBlock->m_nRecordNum[BPA_DAT_RZ])
		{
			if (pBpaBlock->m_BpaDat_RZArray[nDev].nStatus)
				BpaRemoveRecord(pBpaBlock, BPA_DAT_RZ, nDev);
			else
				nDev++;
		}

		nDev=0;
		while (nDev<pBpaBlock->m_nRecordNum[BPA_DAT_P])
		{
			if (pBpaBlock->m_BpaDat_PArray[nDev].nStatus)
				BpaRemoveRecord(pBpaBlock, BPA_DAT_P, nDev);
			else
				nDev++;
		}

		BpaMaint(pBpaBlock);

		for (nTable=0; nTable<sizeof(nSwiModTables)/sizeof(int); nTable++)
		{
			nField=BpaGetFieldIndex(nSwiModTables[nTable], "BusPtr");
			if (nField <= 0)
				continue;

			nDev=0;
			while (nDev<pBpaBlock->m_nRecordNum[nSwiModTables[nTable]])
			{
				BpaGetRecordValue(pBpaBlock, nSwiModTables[nTable], nField, nDev, szBuf);
				nBusI = atoi(szBuf);
				//BpaGetRecordIntValue(pBpaBlock, nSwiModTables[nTable], nField, nDev, nBusI);
				if (nBusI < 0)
					BpaRemoveRecord(pBpaBlock, nSwiModTables[nTable], nDev);
				else
					nDev++;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		//	形成BS卡
		unsigned char	bHasSlack=0;
		if (strlen(lpszSlack) > 0)
		{
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			{
				sprintf(szBuf, lpszBusNameFormat, pBpaBlock->m_BpaDat_ACBusArray[i].szName, pBpaBlock->m_BpaDat_ACBusArray[i].fkV);
				if (stricmp(szBuf, lpszSlack) == 0)
				{
					strcpy(pBpaBlock->m_BpaDat_ACBusArray[i].szCardKey, "BS");
					bHasSlack=1;
					break;
				}
			}
		}
		else
		{
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[i].szCardKey, "BS") == 0)
				{
					bHasSlack=1;
					break;
				}
			}
		}

		if (!bHasSlack)
		{
			float	fMaxPMax=-9999;
			int		nMaxPMax=-1;

			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[i].szCardKey, "BQ") == 0)
				{
					if (fMaxPMax < pBpaBlock->m_BpaDat_ACBusArray[i].fPmax)
					{
						nMaxPMax=i;
						fMaxPMax=pBpaBlock->m_BpaDat_ACBusArray[i].fPmax;
					}
				}
			}
			if (nMaxPMax >= 0)
				strcpy(pBpaBlock->m_BpaDat_ACBusArray[nMaxPMax].szCardKey, "BS");
		}

		if (fabs(pBpaBlock->m_BpaDat_Case.fMVABase - 1000) < 1)
		{
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
			{
				if (sqrt(pBpaBlock->m_BpaDat_ACLineArray[i].fR*pBpaBlock->m_BpaDat_ACLineArray[i].fR+pBpaBlock->m_BpaDat_ACLineArray[i].fX*pBpaBlock->m_BpaDat_ACLineArray[i].fX) <= 0.00012)
				{
					pBpaBlock->m_BpaDat_ACLineArray[i].fR=0;
					pBpaBlock->m_BpaDat_ACLineArray[i].fX=0.001;
				}
			}
		}
		else if (fabs(pBpaBlock->m_BpaDat_Case.fMVABase - 100) < 1)
		{
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
			{
				if (sqrt(pBpaBlock->m_BpaDat_ACLineArray[i].fR*pBpaBlock->m_BpaDat_ACLineArray[i].fR+pBpaBlock->m_BpaDat_ACLineArray[i].fX*pBpaBlock->m_BpaDat_ACLineArray[i].fX) <= 0.000012)
				{
					pBpaBlock->m_BpaDat_ACLineArray[i].fR=0;
					pBpaBlock->m_BpaDat_ACLineArray[i].fX=0.0001;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		//	修正高抗
		if (bRetainTieHG)
		{
			int	nHGBus, nLineHGI, nLineHGJ;
			for (nDev=0; nDev<sBpaHGBusArray.size(); nDev++)
			{
				nHGBus = nLineHGI = nLineHGJ = -1;
				for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
				{
					if (strcmp(sBpaHGBusArray[nDev].strBoundHGBus.c_str(), pBpaBlock->m_BpaDat_ACBusArray[i].szName) == 0 && fabs(sBpaHGBusArray[nDev].fBoundHGBuskV-pBpaBlock->m_BpaDat_ACBusArray[i].fkV) < 0.1)
					{
						nHGBus = i;
						break;
					}
				}
				if (nHGBus < 0)
				{
					Log(g_lpszLogFile, "    联络线-母线错误 Bus=%s(%.1f) Shunt=%.1f Line=%s\n", sBpaHGBusArray[nDev].strBoundHGBus.c_str(), sBpaHGBusArray[nDev].fBoundHGBuskV, sBpaHGBusArray[nDev].fHGShunt, sBpaHGBusArray[nDev].strBoundACLine.c_str());
					continue;
				}
				for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
				{
					if (strcmp(sBpaHGBusArray[nDev].strBoundHGBus.c_str(), pBpaBlock->m_BpaDat_LineHGArray[i].szBusI) == 0 && fabs(sBpaHGBusArray[nDev].fBoundHGBuskV-pBpaBlock->m_BpaDat_LineHGArray[i].fkVI) < 0.1)
					{
						Log(g_lpszLogFile, "        联络线高抗I Bus=%s(%.1f) Shunt=%.1f Line=%s\n", sBpaHGBusArray[nDev].strBoundHGBus.c_str(), sBpaHGBusArray[nDev].fBoundHGBuskV, sBpaHGBusArray[nDev].fHGShunt, pBpaBlock->m_BpaDat_LineHGArray[i].szKeyName);
						nLineHGI = i;
						break;
					}
				}
				for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
				{
					if (strcmp(sBpaHGBusArray[nDev].strBoundHGBus.c_str(), pBpaBlock->m_BpaDat_LineHGArray[i].szBusJ) == 0 && fabs(sBpaHGBusArray[nDev].fBoundHGBuskV-pBpaBlock->m_BpaDat_LineHGArray[i].fkVJ) < 0.1)
					{
						Log(g_lpszLogFile, "        联络线高抗J Bus=%s(%.1f) Shunt=%.1f Line=%s\n", sBpaHGBusArray[nDev].strBoundHGBus.c_str(), sBpaHGBusArray[nDev].fBoundHGBuskV, sBpaHGBusArray[nDev].fHGShunt, pBpaBlock->m_BpaDat_LineHGArray[i].szKeyName);
						nLineHGJ = i;
						break;
					}
				}

				if (nLineHGI < 0 && nLineHGJ < 0)
				{
					pBpaBlock->m_BpaDat_ACBusArray[nHGBus].fShuntQ -= sBpaHGBusArray[nDev].fHGShunt;
					Log(g_lpszLogFile, "    联络线-母线高抗 Bus=%s(%.1f) Shunt=%.1f Line=%s\n", sBpaHGBusArray[nDev].strBoundHGBus.c_str(), sBpaHGBusArray[nDev].fBoundHGBuskV, sBpaHGBusArray[nDev].fHGShunt, sBpaHGBusArray[nDev].strBoundACLine.c_str());
				}
				else
				{
					Log(g_lpszLogFile, "    联络线-线路高抗 Bus=%s(%.1f) Shunt=%.1f Line=%s\n", sBpaHGBusArray[nDev].strBoundHGBus.c_str(), sBpaHGBusArray[nDev].fBoundHGBuskV, sBpaHGBusArray[nDev].fHGShunt, sBpaHGBusArray[nDev].strBoundACLine.c_str());
					if (nLineHGI >= 0)
						pBpaBlock->m_BpaDat_LineHGArray[nLineHGI].fShuntI += sBpaHGBusArray[nDev].fHGShunt;
					else
						pBpaBlock->m_BpaDat_LineHGArray[nLineHGJ].fShuntJ += sBpaHGBusArray[nDev].fHGShunt;
				}
			}
		}

		return 1;
	}
}