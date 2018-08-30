#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"
#include <float.h>

namespace	BpaMemDB
{
	extern	void	BpaFormEdge(tagBpaBlock* pBpaBlock);
	extern	void	BpaFormSubstation(tagBpaBlock* pBpaBlock, const double fZIL);
	extern	void	BpaFormTransformer(tagBpaBlock* pBpaBlock);
	extern	void	BpaFormGenerator(tagBpaBlock* pBpaBlock);
	extern	void	BpaFormLoad(tagBpaBlock* pBpaBlock);

	unsigned char	isBpaBusGenerator(tagBpaBlock* pBpaBlock, const int nBus)
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

	unsigned char	isBpaBusWGen(tagBpaBlock* pBpaBlock, const int nBus)
	{
		register int	i;

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_WGEGEN]; i++)
		{
			if (strcmp(pBpaBlock->m_BpaSwi_WGEGenArray[i].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName) == 0 &&
				fabs(pBpaBlock->m_BpaSwi_WGEGenArray[i].fBus_kV - pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				return 1;
		}

		return 0;
	}
	unsigned char	isBpaBusGenLn(tagBpaBlock* pBpaBlock, const int nBus)
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

	void	BpaMaint(tagBpaBlock* pBpaBlock, const double fZIL)
	{
		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();
		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, -1);				//	排序
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "MDBSort完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		MemDBBase::MDBCheckTableExist<tagBpaBlock>(pBpaBlock, -1);	//	数据检查
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "MDBCheckTableExist完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		MemDBBase::MDBCheckTableContainer<tagBpaBlock>(pBpaBlock);	//	数据检查
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "MDBCheckTableContainer完毕，耗时%d毫秒\n", nDur);

		register int	i, j;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bGenerator = isBpaBusGenerator(pBpaBlock, i);

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bWTGen = isBpaBusWGen(pBpaBlock, i);

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bGenLn = isBpaBusGenLn(pBpaBlock, i);

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
			strcpy(szRest[0], pBpaBlock->m_BpaDat_ACLineArray[i].szBusI);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_ACLineArray[i].fkVI);
			pBpaBlock->m_BpaDat_ACLineArray[i].nIBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);

			strcpy(szRest[0], pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ);
			pBpaBlock->m_BpaDat_ACLineArray[i].nZBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "ACLinePointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaDat_LineHGArray[i].szBusI);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_LineHGArray[i].fkVI);
			pBpaBlock->m_BpaDat_LineHGArray[i].nIBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);

			strcpy(szRest[0], pBpaBlock->m_BpaDat_LineHGArray[i].szBusJ);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_LineHGArray[i].fkVJ);
			pBpaBlock->m_BpaDat_LineHGArray[i].nZBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "LineHGPointer完毕，耗时%d毫秒\n", nDur);

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
				strcpy(szRest[0], pBpaBlock->m_BpaDat_WindArray[i].szBusI);
				sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_WindArray[i].fkVI);
				pBpaBlock->m_BpaDat_WindArray[i].nIBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_DCBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]-1, szRest);
				if (pBpaBlock->m_BpaDat_WindArray[i].nIBus < 0)
				{
					pBpaBlock->m_BpaDat_WindArray[i].nIBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
					if (pBpaBlock->m_BpaDat_WindArray[i].nIBus >= 0)	pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].bDCBound = 1;
				}
				else
				{
					pBpaBlock->m_BpaDat_WindArray[i].bRCard=1;
				}

				strcpy(szRest[0], pBpaBlock->m_BpaDat_WindArray[i].szBusJ);
				sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_WindArray[i].fkVJ);
				pBpaBlock->m_BpaDat_WindArray[i].nZBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_DCBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]-1, szRest);
				if (pBpaBlock->m_BpaDat_WindArray[i].nZBus < 0)
				{
					pBpaBlock->m_BpaDat_WindArray[i].nZBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
					if (pBpaBlock->m_BpaDat_WindArray[i].nZBus >= 0)	pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].bDCBound = 1;
				}
				else
				{
					pBpaBlock->m_BpaDat_WindArray[i].bRCard=2;
				}
			}
			else
			{
				strcpy(szRest[0], pBpaBlock->m_BpaDat_WindArray[i].szBusI);
				sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_WindArray[i].fkVI);
				pBpaBlock->m_BpaDat_WindArray[i].nIBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);

				strcpy(szRest[0], pBpaBlock->m_BpaDat_WindArray[i].szBusJ);
				sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_WindArray[i].fkVJ);
				pBpaBlock->m_BpaDat_WindArray[i].nZBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
			}
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "TRANPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaDat_DCBusArray[i].szACName);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_DCBusArray[i].fACkV);
			pBpaBlock->m_BpaDat_DCBusArray[i].nACBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "DCBusPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCLINE]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaDat_DCLineArray[i].szBusR);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_DCLineArray[i].fkVR);
			pBpaBlock->m_BpaDat_DCLineArray[i].nRBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_DCBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]-1, szRest);

			strcpy(szRest[0], pBpaBlock->m_BpaDat_DCLineArray[i].szBusI);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_DCLineArray[i].fkVI);
			pBpaBlock->m_BpaDat_DCLineArray[i].nIBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_DCBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "DCLINEPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_R]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaDat_RArray[i].szBusI);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_RArray[i].fkVI);
			pBpaBlock->m_BpaDat_RArray[i].nIBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);

			strcpy(szRest[0], pBpaBlock->m_BpaDat_RArray[i].szBusJ);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_RArray[i].fkVJ);
			pBpaBlock->m_BpaDat_RArray[i].nZBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_DCBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "RPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_RZ]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaDat_RZArray[i].szBusI);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_RZArray[i].fkVI);
			pBpaBlock->m_BpaDat_RZArray[i].nIBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);

			strcpy(szRest[0], pBpaBlock->m_BpaDat_RZArray[i].szBusJ);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaDat_RZArray[i].fkVJ);
			pBpaBlock->m_BpaDat_RZArray[i].nZBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "RZPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GEN]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GenArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GenArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GenArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);

			j=BpaFindRecordbyKey(pBpaBlock, BPA_SWI_DAMP, pBpaBlock->m_BpaSwi_GenArray[i].szKeyName);
			if (j >= 0)
				pBpaBlock->m_BpaSwi_GenArray[i].fMVA = pBpaBlock->m_BpaSwi_DampArray[j].fMVA;
			else if (pBpaBlock->m_BpaSwi_GenArray[i].nGenBus >= 0)
				pBpaBlock->m_BpaSwi_GenArray[i].fMVA = pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaSwi_GenArray[i].nGenBus].fPmax;
		}

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_DAMP]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_DampArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_DampArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_DampArray[i].nDampBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_WGEGEN]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_WGEGenArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_WGEGenArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_WGEGenArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GENPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]; i++)
		{
			pBpaBlock->m_BpaSwi_GenLnArray[i].nBus=-1;
			if (strlen(pBpaBlock->m_BpaSwi_GenLnArray[i].szBus_Name) > 0)
			{
				pBpaBlock->m_BpaSwi_GenLnArray[i].bDCBus=0;
				strcpy(szRest[0], pBpaBlock->m_BpaSwi_GenLnArray[i].szBus_Name);
				sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GenLnArray[i].fBus_kV);
				pBpaBlock->m_BpaSwi_GenLnArray[i].nBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);

				if (pBpaBlock->m_BpaSwi_GenLnArray[i].nBus < 0)
				{
					pBpaBlock->m_BpaSwi_GenLnArray[i].bDCBus=1;
					pBpaBlock->m_BpaSwi_GenLnArray[i].nBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_DCBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]-1, szRest);
				}
			}

		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GENLNPointer完毕，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	励磁
		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_EXCIT68]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_Exc68Array[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_Exc68Array[i].fBus_kV);
			pBpaBlock->m_BpaSwi_Exc68Array[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "EXCIT68Pointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_EXCIT81]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_Exc81Array[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_Exc81Array[i].fBus_kV);
			pBpaBlock->m_BpaSwi_Exc81Array[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "EXCIT81Pointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_EXCITMV]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_ExcMVArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_ExcMVArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_ExcMVArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "EXCITMVPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_EXCITX]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_ExcXArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_ExcXArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_ExcXArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "EXCITXPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_FZ]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_FZArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_FZArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_FZArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FZPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_FCA]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_FCAArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_FCAArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_FCAArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FCAPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_FCB]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_FCBArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_FCBArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_FCBArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FCBPointer完毕，耗时%d毫秒\n", nDur);


		//////////////////////////////////////////////////////////////////////////
		//	PSS
		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSS]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_PssSArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_PssSArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_PssSArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);

			pBpaBlock->m_BpaSwi_PssSArray[i].nPssRBus=-1;
			if (strlen(pBpaBlock->m_BpaSwi_PssSArray[i].szRBusName) > 0)
			{
				strcpy(szRest[0], pBpaBlock->m_BpaSwi_PssSArray[i].szRBusName);
				sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_PssSArray[i].fRBuskV);
				pBpaBlock->m_BpaSwi_PssSArray[i].nPssRBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
			}
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "PSSSPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSST]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_PssSTArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_PssSTArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_PssSTArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "PSSSTPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSSH]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_PssSHArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_PssSHArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_PssSHArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "PSSSHPointer完毕，耗时%d毫秒\n", nDur);

// 		dBeg=clock();
// 		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSSH1]; i++)
// 		{
// 			strcpy(szRest[0], pBpaBlock->m_BpaSwi_PssSH1Array[i].szBus_Name);
// 			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_PssSH1Array[i].fBus_kV);
// 			pBpaBlock->m_BpaSwi_PssSH1Array[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
// 		}
// 		dEnd=clock();
// 		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
// 		Log(g_lpszLogFile, "PSSSH1Pointer完毕，耗时%d毫秒\n", nDur);
//
// 		dBeg=clock();
// 		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSSH2]; i++)
// 		{
// 			strcpy(szRest[0], pBpaBlock->m_BpaSwi_PssSH2Array[i].szBus_Name);
// 			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_PssSH2Array[i].fBus_kV);
// 			pBpaBlock->m_BpaSwi_PssSH2Array[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
// 		}
// 		dEnd=clock();
// 		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
// 		Log(g_lpszLogFile, "PSSSH2Pointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSSI]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_PssSIArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_PssSIArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_PssSIArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "PSSSIPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_PSSSA]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_PssSAArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_PssSAArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_PssSAArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "PSSSAPointer完毕，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	调速及伺服
		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GG]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GGArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GGArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GGArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GGPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GH]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GHArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GHArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GHArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GHPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GC]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GCArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GCArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GCArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GCPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GS]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GSArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GSArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GSArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GSPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GL]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GLArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GLArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GLArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GLPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GW]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GWArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GWArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GWArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GWPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GA]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GAArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GAArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GAArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GAPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GI]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GIArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GIArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GIArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GIPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GJ]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GJArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GJArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GJArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GJPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GK]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GKArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GKArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GKArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GKPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GM]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GMArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GMArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GMArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GMPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GD]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GDArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GDArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GDArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GDPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GZ]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GZArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GZArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GZArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GZPointer完毕，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	原动机
		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TA]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_TAArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_TAArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TAArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "TAPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TB]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_TBArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_TBArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TBArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "TBPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TC]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_TCArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_TCArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TCArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "TCPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TD]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_TDArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_TDArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TDArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "TDPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TE]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_TEArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_TEArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TEArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "TEPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TF]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_TFArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_TFArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TFArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "TFPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_TW]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_TWArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_TWArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_TWArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "TWPointer完毕，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	
		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GX]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_GXArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_GXArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_GXArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "GXPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_IGV]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_IGVArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_IGVArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_IGVArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "IGVPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_FGV]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_FGVArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_FGVArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_FGVArray[i].nGenBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FGVPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_D]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_DArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_DArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_DArray[i].nDCBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_DCBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "VPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_V]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_VArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_VArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_VArray[i].iRBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "VPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_VG]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_VGArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_VGArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_VGArray[i].iRBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "VGPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_MI]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_MIArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_MIArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_MIArray[i].iRBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "MIPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_ML]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_MLArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_MLArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_MLArray[i].iRBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "MLPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_RE]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_REArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_REArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_REArray[i].iRBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "REPointer完毕，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_RW]; i++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaSwi_RWArray[i].szBus_Name);
			sprintf(szRest[1], "%f", pBpaBlock->m_BpaSwi_RWArray[i].fBus_kV);
			pBpaBlock->m_BpaSwi_RWArray[i].iRBus=MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_ACBUS, 0, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]-1, szRest);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "RWPointer完毕，耗时%d毫秒\n", nDur);

		BpaFormEdge(pBpaBlock);

		int	la_1, la_2, la_3;
		la_1 = 0;
		la_2 = 0;
		la_3 = 0;
		pBpaBlock->m_BpaDat_ACBusArray[0].nACLineRange = la_1;
		pBpaBlock->m_BpaDat_ACBusArray[0].nWindRange = la_2;
		pBpaBlock->m_BpaDat_ACBusArray[0].nLineHGRange = la_3;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
		{
			for (j=la_1; j<pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINE]; j++)
			{
				if (strcmp(pBpaBlock->m_BpaDat_ACBusArray[i].szName, pBpaBlock->m_BpaDat_EdgeLineArray[j].szBusName) == 0 &&
					fabs(pBpaBlock->m_BpaDat_ACBusArray[i].fkV - pBpaBlock->m_BpaDat_EdgeLineArray[j].fBuskV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				{
					la_1 += 1;
				}
				else
				{
					goto Bus2Line;
				}
			}
Bus2Line:	pBpaBlock->m_BpaDat_ACBusArray[i+1].nACLineRange = la_1;

			for (j=la_2; j<pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]; j++)
			{
				if (strcmp(pBpaBlock->m_BpaDat_ACBusArray[i].szName, pBpaBlock->m_BpaDat_EdgeWindArray[j].szBusName) == 0 &&
					fabs(pBpaBlock->m_BpaDat_ACBusArray[i].fkV - pBpaBlock->m_BpaDat_EdgeWindArray[j].fBuskV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				{
					la_2 += 1;
				}
				else
				{
					goto Bus2Tran;
				}
			}
Bus2Tran:	pBpaBlock->m_BpaDat_ACBusArray[i+1].nWindRange = la_2;

			for (j=la_3; j<pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]; j++)
			{
				if (strcmp(pBpaBlock->m_BpaDat_ACBusArray[i].szName, pBpaBlock->m_BpaDat_EdgeLineHGArray[j].szBusName) == 0 &&
					fabs(pBpaBlock->m_BpaDat_ACBusArray[i].fkV - pBpaBlock->m_BpaDat_EdgeLineHGArray[j].fBuskV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				{
					la_3 += 1;
				}
				else
				{
					goto Bus2HG;
				}
			}
Bus2HG:	pBpaBlock->m_BpaDat_ACBusArray[i+1].nLineHGRange = la_3;
		}

		BpaFormSubstation(pBpaBlock, fZIL);
		BpaFormTransformer(pBpaBlock);
		BpaFormGenerator(pBpaBlock);
		BpaFormLoad(pBpaBlock);
	}
}