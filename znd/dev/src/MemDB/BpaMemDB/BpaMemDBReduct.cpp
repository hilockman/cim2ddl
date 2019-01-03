#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"

//	电压控制预留，暂时不用
namespace	BpaMemDB
{
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

	void CBpaMemDBInterface::SplitString(const char* lpszString, const char* lpszTokenizer, std::vector<std::string>& strEleArray)
	{
		char	szBuf[260];
		char*	lpszToken;

		strEleArray.clear();
		strcpy(szBuf, lpszString);
		lpszToken = strtok(szBuf, lpszTokenizer);
		while (lpszToken != NULL)
		{
			strEleArray.push_back(lpszToken);
			lpszToken = strtok(NULL, lpszTokenizer);
		}
	}

	unsigned char CBpaMemDBInterface::IsExcludeBus(std::vector<std::string>& strExcludeBusArray, const char* lpszBusName, const float fBuskV)
	{
		register int	i;
		std::vector<std::string> strEleArray;

		for (i=0; i<(int)strExcludeBusArray.size(); i++)
		{
			SplitString(strExcludeBusArray[i].c_str(), " \t\n", strEleArray);
			if (strEleArray.size() < 2)
				continue;
			if (stricmp(strEleArray[0].c_str(), lpszBusName) == 0 && fabs(atof(strEleArray[1].c_str())-fBuskV) < 0.1)
			{
				return 1;
				break;
			}
		}
		return 0;
	}

	unsigned char CBpaMemDBInterface::IsACBusInRetainZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, const char* lpszBusName, const float fBuskV)
	{
		register int	i;
		int		nBus;
		unsigned char	bInArea;
		char	szBuf[260];
		std::vector<std::string> strEleArray;

		sprintf(szBuf, "%g", fBuskV);
		nBus = BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, lpszBusName, szBuf);
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

		for (i=0; i<(int)strExcludeACBusArray.size(); i++)
		{
			SplitString(strExcludeACBusArray[i].c_str(), " \t\n", strEleArray);
			if (strEleArray.size() < 2)
				continue;

			if (stricmp(strEleArray[0].c_str(), lpszBusName) == 0 && fabs(atof(strEleArray[1].c_str())-fBuskV) < 0.1)
				return 0;
		}

		return 1;
	}

	unsigned char CBpaMemDBInterface::IsDCBusInRetainZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeDCBusArray, const char* lpszBusName, const float fBuskV)
	{
		register int	i;
		int		nBus;
		unsigned char	bInArea;
		char	szBuf[260];
		std::vector<std::string> strEleArray;

		sprintf(szBuf, "%g", fBuskV);
		nBus = BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, lpszBusName, szBuf);
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

		for (i=0; i<(int)strExcludeDCBusArray.size(); i++)
		{
			SplitString(strExcludeDCBusArray[i].c_str(), " \t\n", strEleArray);
			if (strEleArray.size() < 2)
				continue;

			if (stricmp(strEleArray[0].c_str(), lpszBusName) == 0 && fabs(atof(strEleArray[1].c_str())-fBuskV) < 0.1)
				return 0;
		}

		return 1;
	}

	void CBpaMemDBInterface::BpaGetTieACLineByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, int& nTieNum, int nTieACLineArray[])
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

	void CBpaMemDBInterface::BpaGetTieLineHGByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, int& nTieNum, int nTieLineHGArray[])
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

	void CBpaMemDBInterface::BpaGetTieDCLineByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeDCBusArray, int& nTieNum, int nTieDCLineArray[])
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

	void CBpaMemDBInterface::BpaGetTieTranByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, std::vector<std::string>& strExcludeDCBusArray, int& nTieNum, int nTieTranArray[])
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

	int CBpaMemDBInterface::BpaTailorNetByZone_FormBoundGenLoadByACTieLine(tagBpaBlock* pBpaBlock, const int nTieACLineNum, int nTieACLineArray[])
	{
		register int	i;
		int		nDev, nGen, nBoundBus, nTieLine;
		double	fGenPFactor, fGenQFactor, fLoadPFactor, fLoadQFactor;
		unsigned char	bFindGen;

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
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].bReduction = 1;

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
					if (pBpaBlock->m_BpaDat_PArray[i].fGenQFactor < FLT_MIN)
						fGenQFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
					else
						fGenQFactor=pBpaBlock->m_BpaDat_PArray[i].fGenQFactor;

					fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
					if (pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor < FLT_MIN)
						fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
					else
						fLoadQFactor=pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor;
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
					for (nGen=0; nGen<pBpaBlock->m_nRecordNum[BPA_SWI_WGWGEN]; nGen++)
					{
						if (stricmp(pBpaBlock->m_BpaSwi_WGWGenArray[nGen].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName) == 0 &&
							fabs(pBpaBlock->m_BpaSwi_WGWGenArray[nGen].fBus_kV-pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV) < 0.1)
						{
							bFindGen=1;
							break;
						}
					}
				}
				if (!bFindGen)
				{
					for (nGen=0; nGen<pBpaBlock->m_nRecordNum[BPA_SWI_PV]; nGen++)
					{
						if (stricmp(pBpaBlock->m_BpaSwi_PVArray[nGen].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName) == 0 &&
							fabs(pBpaBlock->m_BpaSwi_PVArray[nGen].fBus_kV-pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV) < 0.1)
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

		return 1;
	}

	int CBpaMemDBInterface::BpaTailorNetByZone_FormBoundGenLoadByACTieTran(tagBpaBlock* pBpaBlock, const int nTieTranNum, int nTieTranArray[])
	{
		register int	i;
		int		nDev, nGen, nBoundBus, nTieLine;
		double	fGenPFactor, fGenQFactor, fLoadPFactor, fLoadQFactor;
		unsigned char	bFindGen;

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
			pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].bReduction = 1;

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
					if (pBpaBlock->m_BpaDat_PArray[i].fGenQFactor < FLT_MIN)
						fGenQFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
					else
						fGenQFactor=pBpaBlock->m_BpaDat_PArray[i].fGenQFactor;

					fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
					if (pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor < FLT_MIN)
						fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
					else
						fLoadQFactor=pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor;
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
					for (nGen=0; nGen<pBpaBlock->m_nRecordNum[BPA_SWI_WGWGEN]; nGen++)
					{
						if (stricmp(pBpaBlock->m_BpaSwi_WGWGenArray[nGen].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName) == 0 &&
							fabs(pBpaBlock->m_BpaSwi_WGWGenArray[nGen].fBus_kV-pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV) < 0.1)
						{
							bFindGen=1;
							break;
						}
					}
				}
				if (!bFindGen)
				{
					for (nGen=0; nGen<pBpaBlock->m_nRecordNum[BPA_SWI_PV]; nGen++)
					{
						if (stricmp(pBpaBlock->m_BpaSwi_PVArray[nGen].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].szName) == 0 &&
							fabs(pBpaBlock->m_BpaSwi_PVArray[nGen].fBus_kV-pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].fkV) < 0.1)
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

		return 1;
	}

	int CBpaMemDBInterface::BpaTailorNetByZone_FormBoundGenLoadByDCTieLine(tagBpaBlock* pBpaBlock, const unsigned char bDCBoundPV, const int nTieDCLineNum, int nTieDCLineArray[])
	{
		register int	i, j;
		int		nDev, nDCBus, nRCard, nTieLine;
		float	fDCLoad;
		double	fGenPFactor, fGenQFactor, fLoadPFactor, fLoadQFactor;
		unsigned char	bDCRSide;
		char	szBuf[260];
		std::vector<std::string>	strDCBoundBusArray;	//	直流等效交流母线，即交直流边界母线

		strDCBoundBusArray.clear();
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
							if (pBpaBlock->m_BpaDat_PArray[j].fGenQFactor < FLT_MIN)
								fGenQFactor=(pBpaBlock->m_BpaDat_PArray[j].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fGenPFactor : 1;
							else
								fGenQFactor=pBpaBlock->m_BpaDat_PArray[j].fGenQFactor;

							fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[j].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fLoadPFactor : 1;
							if (pBpaBlock->m_BpaDat_PArray[j].fLoadQFactor < FLT_MIN)
								fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[j].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fLoadPFactor : 1;
							else
								fLoadQFactor=pBpaBlock->m_BpaDat_PArray[j].fLoadQFactor;
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

					sprintf(szBuf, "%s %g", pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].szName, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].fkV);
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
							if (pBpaBlock->m_BpaDat_PArray[j].fGenQFactor < FLT_MIN)
								fGenQFactor=(pBpaBlock->m_BpaDat_PArray[j].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fGenPFactor : 1;
							else
								fGenQFactor=pBpaBlock->m_BpaDat_PArray[j].fGenQFactor;

							fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[j].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fLoadPFactor : 1;
							if (pBpaBlock->m_BpaDat_PArray[j].fLoadQFactor < FLT_MIN)
								fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[j].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[j].fLoadPFactor : 1;
							else
								fLoadQFactor=pBpaBlock->m_BpaDat_PArray[j].fLoadQFactor;
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

					sprintf(szBuf, "%s %g", pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].szName, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].fkV);
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

		return 1;
	}

	int CBpaMemDBInterface::BpaTailorNetByZone(tagBpaBlock* pBpaBlock,
		const unsigned char bRetainTieHG,
		const unsigned char bDCBoundPV,
		const char* lpszSlack,
		std::vector<std::string>& strRetainZoneArray,
		std::vector<std::string>& strExcludeACBusArray,
		std::vector<std::string>& strExcludeDCBusArray)
	{
		register int	i;
		int		nDev, nBusI, nBusJ, nBoundBus, nTieLine;
		int		nTable, nField;
		int	nTieACLineNum, nTieACLineArray[1600];
		int	nTieLineHGNum, nTieLineHGArray[1000];
		int	nTieDCLineNum, nTieDCLineArray[100];
		int	nTieTranNum, nTieTranArray[800];
		std::vector<tagBpaHGBus>	sBpaHGBusArray;
		tagBpaHGBus	sHGBus;

		char	szBuf[260];

		Log(g_lpszLogFile, "BpaTailorNetByZone Slack=%s RetainHG=%d DCPV=%d\n", lpszSlack, bRetainTieHG, bDCBoundPV);

		BpaGetTieACLineByZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, nTieACLineNum, nTieACLineArray);
		BpaGetTieLineHGByZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, nTieLineHGNum, nTieLineHGArray);
		BpaGetTieDCLineByZone(pBpaBlock, strRetainZoneArray, strExcludeDCBusArray, nTieDCLineNum, nTieDCLineArray);
		BpaGetTieTranByZone(pBpaBlock, strRetainZoneArray, strExcludeACBusArray, strExcludeDCBusArray, nTieTranNum, nTieTranArray);

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bReduction = 0;

		BpaTailorNetByZone_FormBoundGenLoadByACTieLine(pBpaBlock, nTieACLineNum, nTieACLineArray);

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

		BpaTailorNetByZone_FormBoundGenLoadByACTieTran(pBpaBlock, nTieTranNum, nTieTranArray);					//	通过联络变形成交流边界的发电和负荷
		BpaTailorNetByZone_FormBoundGenLoadByDCTieLine(pBpaBlock, bDCBoundPV, nTieDCLineNum, nTieDCLineArray);	//	生成直流等值系统

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
			std::vector<std::string> strEleArray;
			SplitString(lpszSlack, " \t\n", strEleArray);
			if (strEleArray.size() >= 2)
			{
				nDev = BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, strEleArray[0].c_str(), strEleArray[1].c_str());
				if (nDev >= 0)
				{
					strcpy(pBpaBlock->m_BpaDat_ACBusArray[i].szCardKey, "BS");
					bHasSlack=1;
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

	void CBpaMemDBInterface::BpaSearchVoltTailorNet(tagBpaBlock* pBpaBlock, const double fMinVoltage, int& nRangeACBusNum, int& nRangeDCBusNum, int nRangeACBusArray[], int nRangeDCBusArray[])
	{
		register int	i;
		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();

		nRangeACBusNum = nRangeDCBusNum = 0;

		int		nJointBusNum;
		int*	pnJointBusArray;
		pnJointBusArray = (int*)malloc(sizeof(int)*pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		if (!pnJointBusArray)
			return;

		int		nBus, nDev, nTran, nBusT, nBusH, nBusM, nBusL, nDCBus;
		int		nBusNum, nBusArray[200];
		unsigned char	bGenSub;
		std::vector<unsigned char>	bACBusFlagArray, bDCBusFlagArray, bProcArray;
		std::vector<int>			nRetainACBusArray, nBoundACWindArray;

		bACBusFlagArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		bDCBusFlagArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]);
		for (i=0; i<(int)bACBusFlagArray.size(); i++)
			bACBusFlagArray[i] = 0;
		for (i=0; i<(int)bDCBusFlagArray.size(); i++)
			bDCBusFlagArray[i] = 0;

		//////////////////////////////////////////////////////////////////////////
		//	按电压等级搜索母线，搜索结果为nRetainACBusArray
		nRetainACBusArray.clear();
		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
			if (bACBusFlagArray[nBus])
				continue;
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bTMid)
				continue;
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV < fMinVoltage)
				continue;

			BpaTraverseVolt(pBpaBlock, nBus, fMinVoltage, nJointBusNum, pnJointBusArray);
			for (i=0; i<nJointBusNum; i++)
			{
				nRetainACBusArray.push_back(pnJointBusArray[i]);
				bACBusFlagArray[pnJointBusArray[i]] = 1;
			}
		}
		free(pnJointBusArray);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "搜索区域内交流母线完毕，耗时 %d 毫秒\n", nDur);

		bProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]);
		for (i=0; i<(int)bProcArray.size(); i++)
			bProcArray[i] = 0;
		for (i=0; i<(int)bACBusFlagArray.size(); i++)
			bACBusFlagArray[i] = 0;
		for (i=0; i<(int)bDCBusFlagArray.size(); i++)
			bDCBusFlagArray[i] = 0;
		for (i=0; i<nRetainACBusArray.size(); i++)
			bACBusFlagArray[nRetainACBusArray[i]] = 1;

		//////////////////////////////////////////////////////////////////////////
		//	直流系统
		for (nBus=0; nBus<nRetainACBusArray.size(); nBus++)
		{
			for (nDev=pBpaBlock->m_BpaDat_ACBusArray[nRetainACBusArray[nBus]].nEdgeWindRange; nDev<pBpaBlock->m_BpaDat_ACBusArray[nRetainACBusArray[nBus]+1].nEdgeWindRange; nDev++)
			{
				if (pBpaBlock->m_BpaDat_EdgeWindArray[nDev].nWindPtr < 0)
					continue;
				if (pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[nDev].nWindPtr].bRCard == 0)	//	直流调压器
					continue;

				nDCBus = (pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[nDev].nWindPtr].bRCard == 1) ?
					pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[nDev].nWindPtr].nIBus :
				pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[nDev].nWindPtr].nZBus;
				bDCBusFlagArray[nDCBus] = 1;
			}
		}
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCLINE]; i++)
		{
			if (!bDCBusFlagArray[pBpaBlock->m_BpaDat_DCLineArray[i].nRBus] || !bDCBusFlagArray[pBpaBlock->m_BpaDat_DCLineArray[i].nIBus])
			{
				bDCBusFlagArray[pBpaBlock->m_BpaDat_DCLineArray[i].nRBus] = 0;
				bDCBusFlagArray[pBpaBlock->m_BpaDat_DCLineArray[i].nIBus] = 0;
			}
		}
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; i++)
		{
			if (bDCBusFlagArray[i])
				nRangeDCBusArray[nRangeDCBusNum++] = i;
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "直流系统分析完毕，耗时 %d 毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	将电厂、变压器低压侧和中性点加入
		for (nBus=0; nBus<nRetainACBusArray.size(); nBus++)
		{
			for (nDev=pBpaBlock->m_BpaDat_ACBusArray[nRetainACBusArray[nBus]].nEdgeWindRange; nDev<pBpaBlock->m_BpaDat_ACBusArray[nRetainACBusArray[nBus]+1].nEdgeWindRange; nDev++)
			{
				if (pBpaBlock->m_BpaDat_EdgeWindArray[nDev].nWindPtr < 0)
					continue;
				if (pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[nDev].nWindPtr].bRCard != 0)	//	直流调压器
					continue;

				nTran = pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[nDev].nWindPtr].nTran;
				if (nTran < 0)
					continue;
				if (bProcArray[nTran])
					continue;
				bProcArray[nTran]=1;

				if (pBpaBlock->m_BpaDat_TranArray[nTran].nWindNum > 1)
				{
					nBusT=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus == pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nIBus ||
						pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus == pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nZBus) ?
						pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus;

					nBusH=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus == nBusT) ?
						pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus;
					nBusM=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindM].nIBus == nBusT) ?
						pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindM].nZBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindM].nIBus;
					nBusL=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nIBus == nBusT) ?
						pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nZBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nIBus;

					bGenSub=0;
					BpaTraverseSub(pBpaBlock, nBusH, 0, nBusNum, nBusArray);
					for (i=0; i<nBusNum; i++)
					{
						if (pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].bGenerator != 0 ||
							pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].bDCBound != 0)
						{
							bGenSub=1;
							break;
						}
					}

					if (!bACBusFlagArray[nBusM] && !bACBusFlagArray[nBusL] && !bGenSub)
					{
					}
					else
					{
						bACBusFlagArray[nBusH] = 1;
						bACBusFlagArray[nBusM] = 1;
						bACBusFlagArray[nBusL] = 1;
						bACBusFlagArray[nBusT] = 1;
						if (bGenSub)
						{
							for (i=0; i<nBusNum; i++)
								bACBusFlagArray[nBusArray[i]] = 1;
						}
					}
				}
				else
				{
					nBusH=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].fkVI > pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].fkVJ) ?
						pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus;
					nBusL=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].fkVI > pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].fkVJ) ?
						pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus;

					bGenSub=0;
					BpaTraverseSub(pBpaBlock, nBusH, 0, nBusNum, nBusArray);
					for (i=0; i<nBusNum; i++)
					{
						if (pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].bGenerator != 0 ||
							pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].bDCBound != 0)
						{
							bGenSub=1;
							break;
						}
					}

					if (!bACBusFlagArray[nBusL] && !bGenSub)
					{
					}
					else
					{
						bACBusFlagArray[nBusH] = 1;
						bACBusFlagArray[nBusL] = 1;
						if (bGenSub)
						{
							for (i=0; i<nBusNum; i++)
								bACBusFlagArray[nBusArray[i]] = 1;
						}
					}
				}
			}
		}

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
		{
			if (bACBusFlagArray[i])
				nRangeACBusArray[nRangeACBusNum++] = i;
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "发电机、变压器低压侧和中性点完毕，耗时 %d 毫秒\n", nDur);
	}

	//////////////////////////////////////////////////////////////////////////
	//	按电压等级裁剪边界母线一定是变压器母线。
	void CBpaMemDBInterface::BpaTailorNetByVolt(tagBpaBlock* pBpaBlock, const double fMinVoltage)
	{
		register int	i;
		int		nEdge, nBusH;

		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();

		int		nRangeACBusNum, nRangeDCBusNum;
		int*	nRangeACBusArray = (int*)malloc(sizeof(int)*pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		int*	nRangeDCBusArray = (int*)malloc(sizeof(int)*pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]);
		if (!nRangeACBusArray || !nRangeDCBusArray)
			return;
		BpaSearchVoltTailorNet(pBpaBlock, fMinVoltage, nRangeACBusNum, nRangeDCBusNum, nRangeACBusArray, nRangeDCBusArray);
		if (nRangeACBusNum <= 0 && nRangeDCBusNum <= 0)
			return;

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "SearchVoltTailorNet完毕，耗时 %d 毫秒\n", nDur);

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bReduction = 0;

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].nStatus = 1;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; i++)
			pBpaBlock->m_BpaDat_DCBusArray[i].nStatus = 1;

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
			pBpaBlock->m_BpaDat_ACLineArray[i].nStatus = 0;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
			pBpaBlock->m_BpaDat_WindArray[i].nStatus = 0;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
			pBpaBlock->m_BpaDat_LineHGArray[i].nStatus = 0;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCLINE]; i++)
			pBpaBlock->m_BpaDat_DCLineArray[i].nStatus = 0;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_R]; i++)
			pBpaBlock->m_BpaDat_RArray[i].nStatus = 0;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]; i++)
			pBpaBlock->m_BpaDat_TranArray[i].nStatus = 0;

		for (i=0; i<nRangeACBusNum; i++)
			pBpaBlock->m_BpaDat_ACBusArray[nRangeACBusArray[i]].nStatus = 0;
		for (i=0; i<nRangeDCBusNum; i++)
			pBpaBlock->m_BpaDat_DCBusArray[nRangeDCBusArray[i]].nStatus = 0;

		free(nRangeACBusArray);
		free(nRangeDCBusArray);

		//////////////////////////////////////////////////////////////////////////
		//	设置边界变压器负荷
		int		nWind, nOppBus;
		double	fPFLoadP, fPFLoadQ;
		double	fGenPFactor, fGenQFactor, fLoadPFactor, fLoadQFactor;
		std::vector<unsigned char>	bProcArray;

		bProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<(int)bProcArray.size(); i++)
			bProcArray[i] = 0;
		for (nEdge=0; nEdge<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nEdge++)
		{
			nBusH = -1;
			if (pBpaBlock->m_BpaDat_WindArray[nEdge].bRCard == 0)
			{
				if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nEdge].nIBus].nStatus == pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nEdge].nZBus].nStatus)
					continue;
				nBusH=(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nEdge].nIBus].nStatus == 0) ? pBpaBlock->m_BpaDat_WindArray[nEdge].nIBus : pBpaBlock->m_BpaDat_WindArray[nEdge].nZBus;
			}
			else if (pBpaBlock->m_BpaDat_WindArray[nEdge].bRCard == 1)
			{
				if (pBpaBlock->m_BpaDat_DCBusArray[pBpaBlock->m_BpaDat_WindArray[nEdge].nIBus].nStatus == pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nEdge].nZBus].nStatus)
					continue;
				nBusH=pBpaBlock->m_BpaDat_WindArray[nEdge].nZBus;
			}
			else if (pBpaBlock->m_BpaDat_WindArray[nEdge].bRCard == 2)
			{
				if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nEdge].nIBus].nStatus == pBpaBlock->m_BpaDat_DCBusArray[pBpaBlock->m_BpaDat_WindArray[nEdge].nZBus].nStatus)
					continue;
				nBusH=pBpaBlock->m_BpaDat_WindArray[nEdge].nIBus;
			}
			if (nBusH < 0)
				continue;
			if (bProcArray[nBusH])
				continue;
			bProcArray[nBusH] = 1;

			fPFLoadP = 0;
			fPFLoadQ = 0;
			for (i=pBpaBlock->m_BpaDat_ACBusArray[nBusH].nEdgeWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[nBusH+1].nEdgeWindRange; i++)
			{
				nWind = pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr;
				nOppBus = (pBpaBlock->m_BpaDat_WindArray[nWind].nIBus == nBusH) ? pBpaBlock->m_BpaDat_WindArray[nWind].nZBus : pBpaBlock->m_BpaDat_WindArray[nWind].nIBus;
				if (pBpaBlock->m_BpaDat_WindArray[nWind].bRCard == 0 && pBpaBlock->m_BpaDat_ACBusArray[nOppBus].nStatus == 0)
				{
					Log(g_lpszLogFile, "         母线[%s %g] 边界变压器[%s]非边界\n", pBpaBlock->m_BpaDat_ACBusArray[nBusH].szName, pBpaBlock->m_BpaDat_ACBusArray[nBusH].fkV, pBpaBlock->m_BpaDat_WindArray[nWind].szKeyName);
					continue;
				}
				if (pBpaBlock->m_BpaDat_WindArray[nWind].bRCard != 0 && pBpaBlock->m_BpaDat_DCBusArray[nOppBus].nStatus == 0)
				{
					Log(g_lpszLogFile, "         母线[%s %g] 边界变压器[%s]非边界\n", pBpaBlock->m_BpaDat_ACBusArray[nBusH].szName, pBpaBlock->m_BpaDat_ACBusArray[nBusH].fkV, pBpaBlock->m_BpaDat_WindArray[nWind].szKeyName);
					continue;
				}
				if (pBpaBlock->m_BpaDat_WindArray[nWind].nIBus == nBusH)
				{
					fPFLoadP += pBpaBlock->m_BpaDat_WindArray[nWind].fPi;
					fPFLoadQ += pBpaBlock->m_BpaDat_WindArray[nWind].fQi;
				}
				else
				{
					fPFLoadP += pBpaBlock->m_BpaDat_WindArray[nWind].fPz;
					fPFLoadQ += pBpaBlock->m_BpaDat_WindArray[nWind].fQz;
				}
			}
			fGenPFactor=fGenQFactor=fLoadPFactor=fLoadQFactor=1;
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_P]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaDat_PArray[i].szZone, pBpaBlock->m_BpaDat_ACBusArray[nBusH].szZone) == 0)
				{
					fGenPFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
					if (pBpaBlock->m_BpaDat_PArray[i].fGenQFactor < FLT_MIN)
						fGenQFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
					else
						fGenQFactor=pBpaBlock->m_BpaDat_PArray[i].fGenQFactor;

					fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
					if (pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor < FLT_MIN)
						fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
					else
						fLoadQFactor=pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor;
					break;
				}
			}

			pBpaBlock->m_BpaDat_ACBusArray[nBusH].bReduction = 1;
			if (fPFLoadP < 0)
			{
				if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBusH].szCardKey, "B") == 0)
				{
					strcpy(pBpaBlock->m_BpaDat_ACBusArray[nBusH].szCardKey, "BQ");
					pBpaBlock->m_BpaDat_ACBusArray[nBusH].fQsched_Qmax = 1500;
					pBpaBlock->m_BpaDat_ACBusArray[nBusH].fVHold_max = pBpaBlock->m_BpaDat_ACBusArray[nBusH].fV/pBpaBlock->m_BpaDat_ACBusArray[nBusH].fkV;
				}
				pBpaBlock->m_BpaDat_ACBusArray[nBusH].fPGen += -fPFLoadP/fGenPFactor;
			}
			else
			{
				pBpaBlock->m_BpaDat_ACBusArray[nBusH].fLoadP += fPFLoadP/fLoadPFactor;
			}
			pBpaBlock->m_BpaDat_ACBusArray[nBusH].fLoadQ += fPFLoadQ/fLoadQFactor;
		}

		//////////////////////////////////////////////////////////////////////////
		//	设置边界线路负荷
		for (i=0; i<(int)bProcArray.size(); i++)
			bProcArray[i] = 0;
		for (nEdge=0; nEdge<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; nEdge++)
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nEdge].nIBus].nStatus == pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nEdge].nZBus].nStatus)
				continue;
			nBusH=(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[nEdge].nIBus].nStatus == 0) ? pBpaBlock->m_BpaDat_ACLineArray[nEdge].nIBus : pBpaBlock->m_BpaDat_ACLineArray[nEdge].nZBus;
			if (nBusH < 0)
				continue;
			if (bProcArray[nBusH])
				continue;
			bProcArray[nBusH] = 1;

			fPFLoadP = 0;
			fPFLoadQ = 0;
			for (i=pBpaBlock->m_BpaDat_ACBusArray[nBusH].nEdgeACLineRange; i<pBpaBlock->m_BpaDat_ACBusArray[nBusH+1].nEdgeACLineRange; i++)
			{
				if (pBpaBlock->m_BpaDat_ACLineArray[pBpaBlock->m_BpaDat_EdgeACLineArray[i].nACLinePtr].nIBus == nBusH)
				{
					fPFLoadP += pBpaBlock->m_BpaDat_ACLineArray[pBpaBlock->m_BpaDat_EdgeACLineArray[i].nACLinePtr].fPi;
					fPFLoadQ += pBpaBlock->m_BpaDat_ACLineArray[pBpaBlock->m_BpaDat_EdgeACLineArray[i].nACLinePtr].fQi;
				}
				else
				{
					fPFLoadP += pBpaBlock->m_BpaDat_ACLineArray[pBpaBlock->m_BpaDat_EdgeACLineArray[i].nACLinePtr].fPz;
					fPFLoadQ += pBpaBlock->m_BpaDat_ACLineArray[pBpaBlock->m_BpaDat_EdgeACLineArray[i].nACLinePtr].fQz;
				}
			}
			fGenPFactor=fGenQFactor=fLoadPFactor=fLoadQFactor=1;
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_P]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaDat_PArray[i].szZone, pBpaBlock->m_BpaDat_ACBusArray[nBusH].szZone) == 0)
				{
					fGenPFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
					if (pBpaBlock->m_BpaDat_PArray[i].fGenQFactor < FLT_MIN)
						fGenQFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
					else
						fGenQFactor=pBpaBlock->m_BpaDat_PArray[i].fGenQFactor;

					fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
					if (pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor < FLT_MIN)
						fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
					else
						fLoadQFactor=pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor;
					break;
				}
			}

			pBpaBlock->m_BpaDat_ACBusArray[nBusH].bReduction = 1;
			if (fPFLoadP < 0)
			{
				if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBusH].szCardKey, "B") == 0)
				{
					strcpy(pBpaBlock->m_BpaDat_ACBusArray[nBusH].szCardKey, "BQ");
					pBpaBlock->m_BpaDat_ACBusArray[nBusH].fQsched_Qmax = 1500;
					pBpaBlock->m_BpaDat_ACBusArray[nBusH].fVHold_max = pBpaBlock->m_BpaDat_ACBusArray[nBusH].fV/pBpaBlock->m_BpaDat_ACBusArray[nBusH].fkV-0.01;
				}
				pBpaBlock->m_BpaDat_ACBusArray[nBusH].fPGen += -fPFLoadP/fGenPFactor;
			}
			else
			{
				pBpaBlock->m_BpaDat_ACBusArray[nBusH].fLoadP += fPFLoadP/fLoadPFactor;
			}
			pBpaBlock->m_BpaDat_ACBusArray[nBusH].fLoadQ += fPFLoadQ/fLoadQFactor;
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "设置边界主变和线路负荷完毕，耗时 %d 毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	孤岛分析
		int		nBus, nBusNum, *pnBusArray;
		double			fIslandGen;
		unsigned char	bHasSlack=0;
		pnBusArray=(int*)malloc(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]*sizeof(int));
		if (pnBusArray == NULL)
			return;

		bProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<(int)bProcArray.size(); i++)
			bProcArray[i]=0;
		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus].nStatus != 0)
				continue;
			if (bProcArray[nBus])
				continue;
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bTMid)
				continue;

			BpaTraverseNet(pBpaBlock, nBus, 0, nBusNum, pnBusArray);
			fIslandGen=0;
			for (i=0; i<nBusNum; i++)
			{
				bProcArray[pnBusArray[i]]=1;
				fIslandGen += pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].fPGen;
			}

			if (fabs(fIslandGen) < FLT_MIN)
			{
				for (i=0; i<nBusNum; i++)
				{
					Log(g_lpszLogFile, "    孤岛母线:(%s %g)\n", pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].szName, pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].fkV);
					pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].nStatus = 1;
				}
			}
			else
			{
				for (i=0; i<nBusNum; i++)
				{
					if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].szCardKey, "BS") == 0)
					{
						bHasSlack=1;
						break;
					}
				}
				if (!bHasSlack)
				{
					float	fMaxPMax=-9999;
					int		nMaxPMax=-1;
					for (i=0; i<nBusNum; i++)
					{
						if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].szCardKey, "BQ") == 0)
						{
							if (fMaxPMax < pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].fPmax)
							{
								nMaxPMax=pnBusArray[i];
								fMaxPMax=pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].fPmax;
							}
						}
					}
					if (nMaxPMax >= 0)
						strcpy(pBpaBlock->m_BpaDat_ACBusArray[nMaxPMax].szCardKey, "BS");
					else
					{
						for (i=0; i<nBusNum; i++)
						{
							Log(g_lpszLogFile, "    孤岛母线:(%s %g)\n", pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].szName, pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].fkV);
							pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].nStatus = 1;
						}
					}
				}
			}
		}
		free(pnBusArray);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "孤岛分析完成，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	设置设备状态
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
			pBpaBlock->m_BpaDat_ACLineArray[i].nStatus= (!pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[i].nIBus].nStatus && !pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[i].nZBus].nStatus) ? 0 : 1;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCLINE]; i++)
			pBpaBlock->m_BpaDat_DCLineArray[i].nStatus= (!pBpaBlock->m_BpaDat_DCBusArray[pBpaBlock->m_BpaDat_DCLineArray[i].nRBus].nStatus && !pBpaBlock->m_BpaDat_DCBusArray[pBpaBlock->m_BpaDat_DCLineArray[i].nIBus].nStatus) ? 0 : 1;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
		{
			if (pBpaBlock->m_BpaDat_WindArray[i].bRCard == 0)
				pBpaBlock->m_BpaDat_WindArray[i].nStatus= (!pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].nStatus && !pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].nStatus) ? 0 : 1;
			else if (pBpaBlock->m_BpaDat_WindArray[i].bRCard == 1)
				pBpaBlock->m_BpaDat_WindArray[i].nStatus= (!pBpaBlock->m_BpaDat_DCBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].nStatus && !pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].nStatus) ? 0 : 1;
			else if (pBpaBlock->m_BpaDat_WindArray[i].bRCard == 2)
				pBpaBlock->m_BpaDat_WindArray[i].nStatus= (!pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].nStatus && !pBpaBlock->m_BpaDat_DCBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].nStatus) ? 0 : 1;
		}
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
			pBpaBlock->m_BpaDat_LineHGArray[i].nStatus= (!pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_LineHGArray[i].nIBus].nStatus && !pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_LineHGArray[i].nZBus].nStatus) ? 0 : 1;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_R]; i++)
		{
			nEdge = BpaFindRecordbyKey(pBpaBlock, BPA_DAT_WIND, pBpaBlock->m_BpaDat_RArray[i].szKeyName);
			if (nEdge < 0)
				pBpaBlock->m_BpaDat_RArray[i].nStatus= 1;
			else
				pBpaBlock->m_BpaDat_RArray[i].nStatus= pBpaBlock->m_BpaDat_WindArray[nEdge].nStatus;
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "设置设备状态完毕，耗时 %d 毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	删除网络
		i=0;
		while (i < pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE])
		{
			if (pBpaBlock->m_BpaDat_ACLineArray[i].nStatus)
			{
				//Log(g_lpszLogFile, "删除交流线路:(%s)\n", pBpaBlock->m_BpaDat_ACLineArray[i].szKeyName);
				BpaRemoveRecord(pBpaBlock, BPA_DAT_ACLINE, i);
			}
			else
				i++;
		}

		i=0;
		while (i < pBpaBlock->m_nRecordNum[BPA_DAT_WIND])
		{
			if (pBpaBlock->m_BpaDat_WindArray[i].nStatus)
			{
				//Log(g_lpszLogFile, "删除变压器:(%s)\n", pBpaBlock->m_BpaDat_WindArray[i].szKeyName);
				BpaRemoveRecord(pBpaBlock, BPA_DAT_WIND, i);
			}
			else
				i++;
		}

		i=0;
		while (i < pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG])
		{
			if (pBpaBlock->m_BpaDat_LineHGArray[i].nStatus)
			{
				//Log(g_lpszLogFile, "删除线路高抗:(%s)\n", pBpaBlock->m_BpaDat_LineHGArray[i].szKeyName);
				BpaRemoveRecord(pBpaBlock, BPA_DAT_LINEHG, i);
			}
			else
				i++;
		}

		i=0;
		while (i < pBpaBlock->m_nRecordNum[BPA_DAT_DCLINE])
		{
			if (pBpaBlock->m_BpaDat_DCLineArray[i].nStatus)
			{
				//Log(g_lpszLogFile, "删除直流线路:(%s)\n", pBpaBlock->m_BpaDat_DCLineArray[i].szKeyName);
				BpaRemoveRecord(pBpaBlock, BPA_DAT_DCLINE, i);
			}
			else
				i++;
		}

		i=0;
		while (i < pBpaBlock->m_nRecordNum[BPA_DAT_R])
		{
			if (pBpaBlock->m_BpaDat_RArray[i].nStatus)
			{
				//Log(g_lpszLogFile, "删除直流调压装置:(%s)\n", pBpaBlock->m_BpaDat_RArray[i].szKeyName);
				BpaRemoveRecord(pBpaBlock, BPA_DAT_R, i);
			}
			else
				i++;
		}

		i=0;
		while (i < pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS])
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[i].nStatus)
			{
				//Log(g_lpszLogFile, "删除交流母线:(%s.%.2f)\n", pBpaBlock->m_BpaDat_ACBusArray[i].szName, pBpaBlock->m_BpaDat_ACBusArray[i].fkV);
				BpaRemoveRecord(pBpaBlock, BPA_DAT_ACBUS, i);
			}
			else
				i++;
		}

		i=0;
		while (i < pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS])
		{
			if (pBpaBlock->m_BpaDat_DCBusArray[i].nStatus)
			{
				//Log(g_lpszLogFile, "删除直流母线:(%s.%.2f)\n", pBpaBlock->m_BpaDat_DCBusArray[i].szName, pBpaBlock->m_BpaDat_DCBusArray[i].fkV);
				BpaRemoveRecord(pBpaBlock, BPA_DAT_DCBUS, i);
			}
			else
				i++;
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "删除区域网设备完毕，耗时 %d 毫秒\n", nDur);

		BpaMaint(pBpaBlock);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "按电压等级裁剪完毕，耗时 %d 毫秒\n", nDur);
	}

	void CBpaMemDBInterface::BpaSearchLoadTran(tagBpaBlock* pBpaBlock, int& nLoadTranNum, int nLoadTranArray[])
	{
		register int	i;
		int		nTran, nBusT, nBusH;
		int		nLineNum, nBusNum, nBusArray[200];
		unsigned char	bGenSub;

		nLoadTranNum = 0;
		for (nTran=0; nTran<pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]; nTran++)
		{
			//Log(g_lpszLogFile, "判断主变[%d卷变]:(%s.%s)\n", pBpaBlock->m_BpaDat_TransformArray[nTran].nWindNum, pBpaBlock->m_BpaDat_TransformArray[nTran].szWindH);
			if (pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH < 0 || pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL < 0)
				continue;

			nBusH=-1;
			if (pBpaBlock->m_BpaDat_TranArray[nTran].nWindNum > 1)
			{
				nBusT=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus == pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nIBus ||
					pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus == pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nZBus) ?
					pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus;
				nBusH=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus == nBusT) ?
					pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus;
			}
			else
			{
				nBusH=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].fkVI > pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].fkVJ) ?
					pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus;
			}
			if (nBusH < 0)
				continue;

			bGenSub=0;
			BpaTraverseSub(pBpaBlock, nBusH, 0, nBusNum, nBusArray);
			for (i=0; i<nBusNum; i++)
			{
				if (pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].bGenerator != 0 || pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].bDCBound != 0)
				{
					bGenSub=1;
					break;
				}
			}
			if (bGenSub)
				continue;

			nLineNum=0;
			for (i=0; i<nBusNum; i++)
			{
				if (nBusArray[i] == nBusH)
					continue;
				nLineNum += pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]+1].nEdgeACLineRange - pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].nEdgeACLineRange;
			}
			if (nLineNum > 0)
				continue;

			nLoadTranArray[nLoadTranNum++] = nTran;
		}
	}

	void CBpaMemDBInterface::BpaRemoveLoadTran(tagBpaBlock* pBpaBlock, const int bUsePFlowResult)
	{
		register int	i, j;
		int		nDev, nTran, nWind, nBusT, nBusH;
		int		nBusNum, nBusArray[200];
		std::vector<unsigned char>	bBusProcArray;
		double	fPFLoadP, fPFLoadQ;
		double	fLoadP, fLoadQ;
		double	fGenPFactor, fGenQFactor, fLoadPFactor, fLoadQFactor;

		int		nLoadTranNum;
		int*	nLoadTranArray = (int*)malloc(sizeof(int)*pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]);
		if (!nLoadTranArray)
			return;
		BpaSearchLoadTran(pBpaBlock, nLoadTranNum, nLoadTranArray);

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].nStatus=0;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
			pBpaBlock->m_BpaDat_WindArray[i].nStatus=0;

		bBusProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<(int)bBusProcArray.size(); i++)
			bBusProcArray[i] = 0;

		for (nDev=0; nDev<nLoadTranNum; nDev++)
		{
			nTran = nLoadTranArray[nDev];
			nBusH=-1;
			if (pBpaBlock->m_BpaDat_TranArray[nTran].nWindNum > 1)
			{
				nBusT=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus == pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nIBus ||
					pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus == pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nZBus) ?
					pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus;
				nBusH=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus == nBusT) ?
					pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus;
			}
			else
			{
				nBusH=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].fkVI > pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].fkVJ) ?
					pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus;
			}
			if (nBusH < 0)
				continue;
			if (bBusProcArray[nBusH])
				continue;
			bBusProcArray[nBusH] = 1;

			BpaTraverseSub(pBpaBlock, nBusH, 0, nBusNum, nBusArray);

			fGenPFactor=fGenQFactor=fLoadPFactor=fLoadQFactor=1;
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_P]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaDat_PArray[i].szZone, pBpaBlock->m_BpaDat_ACBusArray[nBusH].szZone) == 0)
				{
					fGenPFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
					if (pBpaBlock->m_BpaDat_PArray[i].fGenQFactor < FLT_MIN)
						fGenQFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenPFactor : 1;
					else
						fGenQFactor=pBpaBlock->m_BpaDat_PArray[i].fGenQFactor;

					fLoadPFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
					if (pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor < FLT_MIN)
						fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadPFactor : 1;
					else
						fLoadQFactor=pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor;
					break;
				}
			}

			//////////////////////////////////////////////////////////////////////////
			//	统计厂站负荷，置厂站变压器和母线标识
			fLoadP = 0;
			fLoadQ = 0;
			for (i=0; i<nBusNum; i++)
			{
				if (nBusArray[i] == nBusH)
					continue;
				pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].nStatus=1;

				fLoadP += pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fLoadP;
				fLoadQ += pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fLoadQ;

				pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fLoadP=0;
				pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fLoadQ=0;

				for (j=pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].nEdgeWindRange; j<pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]+1].nEdgeWindRange; j++)
					pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[j].nWindPtr].nStatus=1;
			}
			if (fLoadQ > 0)
			{
				double	fBuffer = sqrt(fLoadP*fLoadP+fLoadQ*fLoadQ);
				fLoadP += 0.01*fBuffer;
				fLoadQ += 0.08*fBuffer;
			}
			else
			{
				fLoadQ += 0.1*fLoadP;
			}

			//////////////////////////////////////////////////////////////////////////
			//	统计高压侧母线所连接变压器绕组的功率
			fPFLoadP = 0;
			fPFLoadQ = 0;
			for (i=pBpaBlock->m_BpaDat_ACBusArray[nBusH].nEdgeWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[nBusH+1].nEdgeWindRange; i++)
			{
				nWind = pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr;
				if (pBpaBlock->m_BpaDat_WindArray[nWind].nIBus == nBusH)
				{
					fPFLoadP += pBpaBlock->m_BpaDat_WindArray[nWind].fPi;
					fPFLoadQ += pBpaBlock->m_BpaDat_WindArray[nWind].fQi;
				}
				else
				{
					fPFLoadP += pBpaBlock->m_BpaDat_WindArray[nWind].fPz;
					fPFLoadQ += pBpaBlock->m_BpaDat_WindArray[nWind].fQz;
				}
			}

			//Log(g_lpszLogFile, "删除变压器:(%s) 有功[%.2f %.2f], 无功[%.2f %.2f]\n", pBpaBlock->m_BpaDat_TranArray[nTran].szWindH, fPFLoadP, fLoadP, fPFLoadQ, fLoadQ);

			if (bUsePFlowResult)
			{
				pBpaBlock->m_BpaDat_ACBusArray[nBusH].fLoadP += fPFLoadP/fLoadPFactor;
				pBpaBlock->m_BpaDat_ACBusArray[nBusH].fLoadQ += fPFLoadQ/fLoadQFactor;
			}
			else
			{
				pBpaBlock->m_BpaDat_ACBusArray[nBusH].fLoadP += fLoadP/fLoadPFactor;
				pBpaBlock->m_BpaDat_ACBusArray[nBusH].fLoadQ += fLoadQ/fLoadQFactor;
			}
		}
		bBusProcArray.clear();
		free(nLoadTranArray);

		i=0;
		while (i < pBpaBlock->m_nRecordNum[BPA_DAT_WIND])
		{
			if (pBpaBlock->m_BpaDat_WindArray[i].nStatus)
			{
				//Log(g_lpszLogFile, "删除变压器:(%s)\n", pBpaBlock->m_BpaDat_WindArray[i].szKeyName);
				BpaRemoveRecord(pBpaBlock, BPA_DAT_WIND, i);
			}
			else
				i++;
		}

		i=0;
		while (i < pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS])
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[i].nStatus)
			{
				//Log(g_lpszLogFile, "删除母线:(%s.%.2f)\n", pBpaBlock->m_BpaDat_ACBusArray[i].szName, pBpaBlock->m_BpaDat_ACBusArray[i].fkV);
				BpaRemoveRecord(pBpaBlock, BPA_DAT_ACBUS, i);
			}
			else
				i++;
		}

		BpaMaint(pBpaBlock);
	}
}
