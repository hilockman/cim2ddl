#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"
#include <float.h>

namespace	BpaMemDB
{
	unsigned char CBpaMemDBInterface::IsBpaBusGenerator(tagBpaBlock* pBpaBlock, const int nBus)
	{
		register int	i;

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GEN]; i++)
		{
			if (strcmp(pBpaBlock->m_BpaSwi_GenArray[i].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName) == 0 &&
				fabs(pBpaBlock->m_BpaSwi_GenArray[i].fBus_kV - pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
			{
				//if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBus].szCardKey, "B") != 0 || pBpaBlock->m_BpaDat_ACBusArray[nBus].fPmax > FLT_MIN || pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen > FLT_MIN || pBpaBlock->m_BpaDat_ACBusArray[nBus].fQsched_Qmax > FLT_MIN)
					return 1;
			}
		}

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_WGEGEN]; i++)
		{
			if (strcmp(pBpaBlock->m_BpaSwi_WGEGenArray[i].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName) == 0 &&
				fabs(pBpaBlock->m_BpaSwi_WGEGenArray[i].fBus_kV - pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				return 1;
		}

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_WGWGEN]; i++)
		{
			if (strcmp(pBpaBlock->m_BpaSwi_WGWGenArray[i].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName) == 0 &&
				fabs(pBpaBlock->m_BpaSwi_WGWGenArray[i].fBus_kV - pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				return 1;
		}

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PV]; i++)
		{
			if (strcmp(pBpaBlock->m_BpaSwi_PVArray[i].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName) == 0 &&
				fabs(pBpaBlock->m_BpaSwi_PVArray[i].fBus_kV - pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV) < 0.1)	//	防止出现诸如0.69和0.7之间的误差
				return 1;
		}

// 		if (pBpaBlock->m_BpaDat_ACBusArray[nBus].fPmax > FLT_MIN ||
// 			pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen > FLT_MIN ||
// 			stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBus].szCardKey, "BS") == 0 ||
// 			stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBus].szCardKey, "BQ") == 0 ||
// 			stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBus].szCardKey, "BE") == 0 ||
// 			stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBus].szCardKey, "BG") == 0)
// 			return 1;
		if (pBpaBlock->m_BpaDat_ACBusArray[nBus].fPmax > FLT_MIN ||
			fabs(pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen) > FLT_MIN ||
			stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBus].szCardKey, "BS") == 0 ||
			stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBus].szCardKey, "BG") == 0)
			return 1;

		return 0;
	}

	unsigned char CBpaMemDBInterface::IsBpaBusWTGen(tagBpaBlock* pBpaBlock, const int nBus)
	{
		register int	i;

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_WGEGEN]; i++)
		{
			if (strcmp(pBpaBlock->m_BpaSwi_WGEGenArray[i].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName) == 0 &&
				fabs(pBpaBlock->m_BpaSwi_WGEGenArray[i].fBus_kV - pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				return 1;
		}
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_WGWGEN]; i++)
		{
			if (strcmp(pBpaBlock->m_BpaSwi_WGWGenArray[i].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName) == 0 &&
				fabs(pBpaBlock->m_BpaSwi_WGWGenArray[i].fBus_kV - pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				return 1;
		}

		return 0;
	}
	unsigned char CBpaMemDBInterface::IsBpaBusPVGen(tagBpaBlock* pBpaBlock, const int nBus)
	{
		register int	i;

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PV]; i++)
		{
			if (strcmp(pBpaBlock->m_BpaSwi_PVArray[i].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName) == 0 &&
				fabs(pBpaBlock->m_BpaSwi_PVArray[i].fBus_kV - pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				return 1;
		}

		return 0;
	}
	unsigned char CBpaMemDBInterface::IsBpaBusGenLn(tagBpaBlock* pBpaBlock, const int nBus)
	{
		register int	i;

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]; i++)
		{
			if (strcmp(pBpaBlock->m_BpaSwi_GenLnArray[i].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName) == 0 &&
				fabs(pBpaBlock->m_BpaSwi_GenLnArray[i].fBus_kV - pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				return 1;
		}

		return 0;
	}

	void CBpaMemDBInterface::BpaMaint(tagBpaBlock* pBpaBlock, const double fZIL)
	{
		clock_t	dBeg, dEnd;

		pBpaBlock->m_nRecordNum[BPA_DAT_SUB]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_GEN] = 0;
		pBpaBlock->m_nRecordNum[BPA_DAT_LOAD] = 0;
		pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]=0;

		dBeg=clock();
		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, -1);				//	排序
		dEnd=clock();
		Log(g_lpszLogFile, "BpaMaint MDBSort完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		MemDBBase::MDBCheckTableExist<tagBpaBlock>(pBpaBlock, -1);	//	数据检查
		dEnd=clock();
		Log(g_lpszLogFile, "BpaMaint MDBCheckTableExist完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		MemDBBase::MDBCheckTableContainer<tagBpaBlock>(pBpaBlock);	//	数据检查
		dEnd=clock();
		Log(g_lpszLogFile, "BpaMaint MDBCheckTableContainer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		register int	i, j;
		char	szBuffer[MDB_CHARLEN_LONG];

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bGenerator = IsBpaBusGenerator(pBpaBlock, i);

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bWTGen = IsBpaBusWTGen(pBpaBlock, i);
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bPVGen = IsBpaBusPVGen(pBpaBlock, i);

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bGenLn = IsBpaBusGenLn(pBpaBlock, i);

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bInRing=1;

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
			pBpaBlock->m_BpaDat_ACLineArray[i].bInRing=1;

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
			pBpaBlock->m_BpaDat_WindArray[i].bInRing=1;

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
			pBpaBlock->m_BpaDat_LineHGArray[i].bInRing=1;

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_ACLineArray[i].fkVI);
			pBpaBlock->m_BpaDat_ACLineArray[i].nIBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaDat_ACLineArray[i].szBusI, szBuffer);

			sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ);
			pBpaBlock->m_BpaDat_ACLineArray[i].nZBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "ACLinePointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_LineHGArray[i].fkVI);
			pBpaBlock->m_BpaDat_LineHGArray[i].nIBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaDat_LineHGArray[i].szBusI, szBuffer);

			sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_LineHGArray[i].fkVJ);
			pBpaBlock->m_BpaDat_LineHGArray[i].nZBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaDat_LineHGArray[i].szBusJ, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "LineHGPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
		{
			pBpaBlock->m_BpaDat_WindArray[i].bRCard=0;
			for (j=0; j<pBpaBlock->m_nRecordNum[BPA_DAT_R]; j++)
			{
				if ((strcmp(pBpaBlock->m_BpaDat_RArray[j].szBusI, pBpaBlock->m_BpaDat_WindArray[i].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[j].fkVI-pBpaBlock->m_BpaDat_WindArray[i].fkVI) < 0.15 &&
					strcmp(pBpaBlock->m_BpaDat_RArray[j].szBusJ, pBpaBlock->m_BpaDat_WindArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[j].fkVJ-pBpaBlock->m_BpaDat_WindArray[i].fkVJ) < 0.15) ||
					(strcmp(pBpaBlock->m_BpaDat_RArray[j].szBusI, pBpaBlock->m_BpaDat_WindArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[j].fkVI-pBpaBlock->m_BpaDat_WindArray[i].fkVJ) < 0.15 &&
					strcmp(pBpaBlock->m_BpaDat_RArray[j].szBusJ, pBpaBlock->m_BpaDat_WindArray[i].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_RArray[j].fkVJ-pBpaBlock->m_BpaDat_WindArray[i].fkVI) < 0.15))	//	防止出现诸如0.69和0.7之间的误差
				{
					pBpaBlock->m_BpaDat_WindArray[i].bRCard=1;
					break;
				}
			}

			if (pBpaBlock->m_BpaDat_WindArray[i].bRCard)
			{
				sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_WindArray[i].fkVI);
				pBpaBlock->m_BpaDat_WindArray[i].nIBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, pBpaBlock->m_BpaDat_WindArray[i].szBusI, szBuffer);
				if (pBpaBlock->m_BpaDat_WindArray[i].nIBus < 0)
				{
					pBpaBlock->m_BpaDat_WindArray[i].nIBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaDat_WindArray[i].szBusI, szBuffer);
					if (pBpaBlock->m_BpaDat_WindArray[i].nIBus >= 0)	pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].bDCBound = 1;
				}
				else
				{
					pBpaBlock->m_BpaDat_WindArray[i].bRCard=1;
				}

				sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_WindArray[i].fkVJ);
				pBpaBlock->m_BpaDat_WindArray[i].nZBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, pBpaBlock->m_BpaDat_WindArray[i].szBusJ, szBuffer);
				if (pBpaBlock->m_BpaDat_WindArray[i].nZBus < 0)
				{
					pBpaBlock->m_BpaDat_WindArray[i].nZBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaDat_WindArray[i].szBusJ, szBuffer);
					if (pBpaBlock->m_BpaDat_WindArray[i].nZBus >= 0)	pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].bDCBound = 1;
				}
				else
				{
					pBpaBlock->m_BpaDat_WindArray[i].bRCard=2;
				}
			}
			else
			{
				sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_WindArray[i].fkVI);
				pBpaBlock->m_BpaDat_WindArray[i].nIBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaDat_WindArray[i].szBusI, szBuffer);

				sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_WindArray[i].fkVJ);
				pBpaBlock->m_BpaDat_WindArray[i].nZBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaDat_WindArray[i].szBusJ, szBuffer);
			}
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "TRANPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_DCBusArray[i].fACkV);
			pBpaBlock->m_BpaDat_DCBusArray[i].nACBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaDat_DCBusArray[i].szACName, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "DCBusPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCLINE]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_DCLineArray[i].fkVR);
			pBpaBlock->m_BpaDat_DCLineArray[i].nRBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, pBpaBlock->m_BpaDat_DCLineArray[i].szBusR, szBuffer);

			sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_DCLineArray[i].fkVI);
			pBpaBlock->m_BpaDat_DCLineArray[i].nIBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, pBpaBlock->m_BpaDat_DCLineArray[i].szBusI, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "DCLINEPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_R]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_RArray[i].fkVI);
			pBpaBlock->m_BpaDat_RArray[i].nIBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaDat_RArray[i].szBusI, szBuffer);

			sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_RArray[i].fkVJ);
			pBpaBlock->m_BpaDat_RArray[i].nZBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, pBpaBlock->m_BpaDat_RArray[i].szBusJ, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "RPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_RZ]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_RZArray[i].fkVI);
			pBpaBlock->m_BpaDat_RZArray[i].nIBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaDat_RZArray[i].szBusI, szBuffer);

			sprintf(szBuffer, "%f", pBpaBlock->m_BpaDat_RZArray[i].fkVJ);
			pBpaBlock->m_BpaDat_RZArray[i].nZBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaDat_RZArray[i].szBusJ, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "RZPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GEN]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GenArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GenArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GenArray[i].szBus_Name, szBuffer);

			j=BpaFindRecordbyKey(pBpaBlock, BPA_SWI_DAMP, pBpaBlock->m_BpaSwi_GenArray[i].szKeyName);
			if (j >= 0)
				pBpaBlock->m_BpaSwi_GenArray[i].fMVA = pBpaBlock->m_BpaSwi_DampArray[j].fMVA;
			else if (pBpaBlock->m_BpaSwi_GenArray[i].nGenBus >= 0)
				pBpaBlock->m_BpaSwi_GenArray[i].fMVA = pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaSwi_GenArray[i].nGenBus].fPmax;
		}

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_DAMP]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_DampArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_DampArray[i].nDampBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_DampArray[i].szBus_Name, szBuffer);
		}

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_WGEGEN]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_WGEGenArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_WGEGenArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_WGEGenArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "WTGEPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_WGWGEN]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_WGWGenArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_WGWGenArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_WGWGenArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "WTGWPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PV]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_PVArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_PVArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_PVArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "PVPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]; i++)
		{
			pBpaBlock->m_BpaSwi_GenLnArray[i].nBus=-1;
			if (strlen(pBpaBlock->m_BpaSwi_GenLnArray[i].szBus_Name) > 0)
			{
				pBpaBlock->m_BpaSwi_GenLnArray[i].bDCBus=0;
				sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GenLnArray[i].fBus_kV);
				pBpaBlock->m_BpaSwi_GenLnArray[i].nBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GenLnArray[i].szBus_Name, szBuffer);

				if (pBpaBlock->m_BpaSwi_GenLnArray[i].nBus < 0)
				{
					pBpaBlock->m_BpaSwi_GenLnArray[i].bDCBus=1;
					pBpaBlock->m_BpaSwi_GenLnArray[i].nBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, pBpaBlock->m_BpaSwi_GenLnArray[i].szBus_Name, szBuffer);
				}
			}

		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GENLNPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		//////////////////////////////////////////////////////////////////////////
		//	励磁
		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_EXCIT68]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_Exc68Array[i].fBus_kV);
			pBpaBlock->m_BpaSwi_Exc68Array[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_Exc68Array[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "EXCIT68Pointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_EXCIT81]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_Exc81Array[i].fBus_kV);
			pBpaBlock->m_BpaSwi_Exc81Array[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_Exc81Array[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "EXCIT81Pointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_EXCITMV]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_ExcMVArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_ExcMVArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_ExcMVArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "EXCITMVPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_EXCITX]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_ExcXArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_ExcXArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_ExcXArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "EXCITXPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_FZ]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_FZArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_FZArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_FZArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "FZPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_FCA]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_FCAArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_FCAArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_FCAArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "FCAPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_FCB]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_FCBArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_FCBArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_FCBArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "FCBPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));


		//////////////////////////////////////////////////////////////////////////
		//	PSS
		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSS]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_PssSArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_PssSArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_PssSArray[i].szBus_Name, szBuffer);

			pBpaBlock->m_BpaSwi_PssSArray[i].nPssRBus=-1;
			if (strlen(pBpaBlock->m_BpaSwi_PssSArray[i].szRBusName) > 0)
			{
				sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_PssSArray[i].fRBuskV);
				pBpaBlock->m_BpaSwi_PssSArray[i].nPssRBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_PssSArray[i].szRBusName, szBuffer);
			}
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "PSSSPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSST]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_PssSTArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_PssSTArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_PssSTArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "PSSSTPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSSH]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_PssSHArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_PssSHArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_PssSHArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "PSSSHPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

// 		dBeg=clock();
// 		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSSH1]; i++)
// 		{
// 			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_PssSH1Array[i].fBus_kV);
// 			pBpaBlock->m_BpaSwi_PssSH1Array[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_PssSH1Array[i].szBus_Name, szBuffer);
// 		}
// 		dEnd=clock();
// 		//Log(g_lpszLogFile, "PSSSH1Pointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));
//
// 		dBeg=clock();
// 		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSSH2]; i++)
// 		{
// 			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_PssSH2Array[i].fBus_kV);
// 			pBpaBlock->m_BpaSwi_PssSH2Array[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_PssSH2Array[i].szBus_Name, szBuffer);
// 		}
// 		dEnd=clock();
// 		//Log(g_lpszLogFile, "PSSSH2Pointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSSI]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_PssSIArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_PssSIArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_PssSIArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "PSSSIPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSSA]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_PssSAArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_PssSAArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_PssSAArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "PSSSAPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		//////////////////////////////////////////////////////////////////////////
		//	调速及伺服
		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GG]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GGArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GGArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GGArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GGPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GH]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GHArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GHArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GHArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GHPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GC]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GCArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GCArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GCArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GCPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GS]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GSArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GSArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GSArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GSPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GL]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GLArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GLArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GLArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GLPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GW]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GWArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GWArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GWArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GWPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GA]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GAArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GAArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GAArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GAPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GI]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GIArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GIArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GIArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GIPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GJ]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GJArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GJArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GJArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GJPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GK]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GKArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GKArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GKArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GKPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GM]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GMArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GMArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GMArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GMPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GD]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GDArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GDArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GDArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GDPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GZ]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GZArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GZArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GZArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GZPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		//////////////////////////////////////////////////////////////////////////
		//	原动机
		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TA]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_TAArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TAArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_TAArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "TAPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TB]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_TBArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TBArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_TBArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "TBPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TC]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_TCArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TCArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_TCArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "TCPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TD]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_TDArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TDArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_TDArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "TDPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TE]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_TEArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TEArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_TEArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "TEPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TF]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_TFArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TFArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_TFArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "TFPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TW]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_TWArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TWArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_TWArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "TWPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		//////////////////////////////////////////////////////////////////////////
		//	
		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GX]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_GXArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GXArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_GXArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "GXPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_IGV]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_IGVArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_IGVArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_IGVArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "IGVPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_FGV]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_FGVArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_FGVArray[i].nGenBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_FGVArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "FGVPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_D]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_DArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_DArray[i].nDCBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, pBpaBlock->m_BpaSwi_DArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "DPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_DT]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_DTArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_DTArray[i].nDCBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, pBpaBlock->m_BpaSwi_DTArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "DTPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_DF]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_DFArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_DFArray[i].nDCBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, pBpaBlock->m_BpaSwi_DFArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "DFPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_DM]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_DMArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_DMArray[i].nDCBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, pBpaBlock->m_BpaSwi_DMArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "DMPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_DN]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_DNArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_DNArray[i].nDCBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, pBpaBlock->m_BpaSwi_DNArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "DNPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_DA]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_DAArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_DAArray[i].nDCBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, pBpaBlock->m_BpaSwi_DAArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "DAPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_V]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_VArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_VArray[i].iRBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_VArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "VPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_VG]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_VGArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_VGArray[i].iRBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_VGArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "VGPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_MI]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_MIArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_MIArray[i].iRBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_MIArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "MIPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_ML]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_MLArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_MLArray[i].iRBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_MLArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "MLPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_RE]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_REArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_REArray[i].iRBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_REArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "REPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_RW]; i++)
		{
			sprintf(szBuffer, "%f", pBpaBlock->m_BpaSwi_RWArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_RWArray[i].iRBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, pBpaBlock->m_BpaSwi_RWArray[i].szBus_Name, szBuffer);
		}
		dEnd=clock();
		//Log(g_lpszLogFile, "RWPointer完毕，耗时%d毫秒\n", (int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC));

		BpaFormEdge(pBpaBlock);
		BpaFormSubstation(pBpaBlock, fZIL);	
		BpaFormTransformer(pBpaBlock);		
		BpaFormGenerator(pBpaBlock);		
		BpaFormLoad(pBpaBlock);				
	}
}