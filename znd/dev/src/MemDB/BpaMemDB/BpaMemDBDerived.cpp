#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"

namespace	BpaMemDB
{
	void CBpaMemDBInterface::BpaFormEdge(tagBpaBlock* pBpaBlock)
	{
		register int	i, j;
		clock_t	dBeg, dEnd;
		int		nDur;

		pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]=0;

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
		{
			strcpy(pBpaBlock->m_BpaDat_EdgeACLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]].szACBusName,			pBpaBlock->m_BpaDat_ACLineArray[i].szBusI);
			pBpaBlock->m_BpaDat_EdgeACLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]].fACBuskV=pBpaBlock->m_BpaDat_ACLineArray[i].fkVI;
			strcpy(pBpaBlock->m_BpaDat_EdgeACLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]].szACLineName,			pBpaBlock->m_BpaDat_ACLineArray[i].szKeyName);
			pBpaBlock->m_BpaDat_EdgeACLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]].nACLinePtr=i;
			pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]++;

			strcpy(pBpaBlock->m_BpaDat_EdgeACLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]].szACBusName,			pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ);
			pBpaBlock->m_BpaDat_EdgeACLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]].fACBuskV=pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ;
			strcpy(pBpaBlock->m_BpaDat_EdgeACLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]].szACLineName,			pBpaBlock->m_BpaDat_ACLineArray[i].szKeyName);
			pBpaBlock->m_BpaDat_EdgeACLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]].nACLinePtr=i;
			pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]++;
		}
		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_EDGEACLINE);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FormACBus2Line，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
		{
			if (pBpaBlock->m_BpaDat_WindArray[i].bRCard != 1)
			{
				strcpy(pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].szACBusName,			pBpaBlock->m_BpaDat_WindArray[i].szBusI);
				pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].fACBuskV=pBpaBlock->m_BpaDat_WindArray[i].fkVI;
				strcpy(pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].szWindName,			pBpaBlock->m_BpaDat_WindArray[i].szKeyName);
				pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].nWindPtr=i;
				pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]++;
			}

			if (pBpaBlock->m_BpaDat_WindArray[i].bRCard != 2)
			{
				strcpy(pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].szACBusName,			pBpaBlock->m_BpaDat_WindArray[i].szBusJ);
				pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].fACBuskV=pBpaBlock->m_BpaDat_WindArray[i].fkVJ;
				strcpy(pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].szWindName,			pBpaBlock->m_BpaDat_WindArray[i].szKeyName);
				pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].nWindPtr=i;
				pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]++;
			}
		}
		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_EDGEWIND);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FormACBus2Tran，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
		{
			strcpy(pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].szACBusName,			pBpaBlock->m_BpaDat_LineHGArray[i].szBusI);
			pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].fACBuskV=pBpaBlock->m_BpaDat_LineHGArray[i].fkVI;
			strcpy(pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].szLineHGName,				pBpaBlock->m_BpaDat_LineHGArray[i].szKeyName);
			pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].nLineHG=i;
			pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]++;

			if (strlen(pBpaBlock->m_BpaDat_LineHGArray[i].szBusJ) > 0)
			{
				strcpy(pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].szACBusName,			pBpaBlock->m_BpaDat_LineHGArray[i].szBusJ);
				pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].fACBuskV=pBpaBlock->m_BpaDat_LineHGArray[i].fkVJ;
				strcpy(pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].szLineHGName,				pBpaBlock->m_BpaDat_LineHGArray[i].szKeyName);
				pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].nLineHG=i;
				pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]++;
			}
		}
		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_EDGELINEHG);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FormACBus2HG，耗时%d毫秒\n", nDur);


		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCLINE]; i++)
		{
			strcpy(pBpaBlock->m_BpaDat_EdgeDCLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]].szDCBusName,			pBpaBlock->m_BpaDat_DCLineArray[i].szBusR);
			pBpaBlock->m_BpaDat_EdgeDCLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]].fDCBuskV=pBpaBlock->m_BpaDat_DCLineArray[i].fkVR;
			strcpy(pBpaBlock->m_BpaDat_EdgeDCLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]].szDCLineName,			pBpaBlock->m_BpaDat_DCLineArray[i].szKeyName);
			pBpaBlock->m_BpaDat_EdgeDCLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]].nDCLinePtr=i;
			pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]++;

			strcpy(pBpaBlock->m_BpaDat_EdgeDCLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]].szDCBusName,			pBpaBlock->m_BpaDat_DCLineArray[i].szBusI);
			pBpaBlock->m_BpaDat_EdgeDCLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]].fDCBuskV=pBpaBlock->m_BpaDat_DCLineArray[i].fkVI;
			strcpy(pBpaBlock->m_BpaDat_EdgeDCLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]].szDCLineName,			pBpaBlock->m_BpaDat_DCLineArray[i].szKeyName);
			pBpaBlock->m_BpaDat_EdgeDCLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]].nDCLinePtr=i;
			pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]++;
		}
		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_EDGEDCLINE);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FormDCBus2Line，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
		{
			if (pBpaBlock->m_BpaDat_WindArray[i].bRCard == 1)
			{
				strcpy(pBpaBlock->m_BpaDat_EdgeRArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]].szDCBusName,		pBpaBlock->m_BpaDat_WindArray[i].szBusI);
				pBpaBlock->m_BpaDat_EdgeRArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]].fDCBuskV=pBpaBlock->m_BpaDat_WindArray[i].fkVI;
				strcpy(pBpaBlock->m_BpaDat_EdgeRArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]].szRName,			pBpaBlock->m_BpaDat_WindArray[i].szKeyName);
				pBpaBlock->m_BpaDat_EdgeRArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]].nRPtr=i;
				pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]++;
			}

			if (pBpaBlock->m_BpaDat_WindArray[i].bRCard == 2)
			{
				strcpy(pBpaBlock->m_BpaDat_EdgeRArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]].szDCBusName,		pBpaBlock->m_BpaDat_WindArray[i].szBusJ);
				pBpaBlock->m_BpaDat_EdgeRArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]].fDCBuskV=pBpaBlock->m_BpaDat_WindArray[i].fkVJ;
				strcpy(pBpaBlock->m_BpaDat_EdgeRArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]].szRName,			pBpaBlock->m_BpaDat_WindArray[i].szKeyName);
				pBpaBlock->m_BpaDat_EdgeRArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]].nRPtr=i;
				pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]++;
			}
		}
		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_EDGER);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FormACBus2Tran，耗时%d毫秒\n", nDur);

		int	la_1, la_2, la_3;
		la_1 = 0;
		la_2 = 0;
		la_3 = 0;
		pBpaBlock->m_BpaDat_ACBusArray[0].nEdgeACLineRange = la_1;
		pBpaBlock->m_BpaDat_ACBusArray[0].nEdgeWindRange = la_2;
		pBpaBlock->m_BpaDat_ACBusArray[0].nEdgeLineHGRange = la_3;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
		{
			for (j=la_1; j<pBpaBlock->m_nRecordNum[BPA_DAT_EDGEACLINE]; j++)
			{
				if (strcmp(pBpaBlock->m_BpaDat_ACBusArray[i].szName, pBpaBlock->m_BpaDat_EdgeACLineArray[j].szACBusName) == 0 &&
					fabs(pBpaBlock->m_BpaDat_ACBusArray[i].fkV - pBpaBlock->m_BpaDat_EdgeACLineArray[j].fACBuskV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				{
					la_1 += 1;
				}
				else
				{
					goto ACBus2ACLine;
				}
			}
ACBus2ACLine:	pBpaBlock->m_BpaDat_ACBusArray[i+1].nEdgeACLineRange = la_1;

			for (j=la_2; j<pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]; j++)
			{
				if (strcmp(pBpaBlock->m_BpaDat_ACBusArray[i].szName, pBpaBlock->m_BpaDat_EdgeWindArray[j].szACBusName) == 0 &&
					fabs(pBpaBlock->m_BpaDat_ACBusArray[i].fkV - pBpaBlock->m_BpaDat_EdgeWindArray[j].fACBuskV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				{
					la_2 += 1;
				}
				else
				{
					goto ACBus2Wind;
				}
			}
ACBus2Wind:	pBpaBlock->m_BpaDat_ACBusArray[i+1].nEdgeWindRange = la_2;

			for (j=la_3; j<pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]; j++)
			{
				if (strcmp(pBpaBlock->m_BpaDat_ACBusArray[i].szName, pBpaBlock->m_BpaDat_EdgeLineHGArray[j].szACBusName) == 0 &&
					fabs(pBpaBlock->m_BpaDat_ACBusArray[i].fkV - pBpaBlock->m_BpaDat_EdgeLineHGArray[j].fACBuskV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				{
					la_3 += 1;
				}
				else
				{
					goto ACBus2HG;
				}
			}
ACBus2HG:	pBpaBlock->m_BpaDat_ACBusArray[i+1].nEdgeLineHGRange = la_3;
		}

		la_1 = 0;
		la_2 = 0;
		pBpaBlock->m_BpaDat_DCBusArray[0].nEdgeDCLineRange = la_1;
		pBpaBlock->m_BpaDat_DCBusArray[0].nEdgeRRange = la_2;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; i++)
		{
			for (j=la_1; j<pBpaBlock->m_nRecordNum[BPA_DAT_EDGEDCLINE]; j++)
			{
				if (strcmp(pBpaBlock->m_BpaDat_DCBusArray[i].szName, pBpaBlock->m_BpaDat_EdgeDCLineArray[j].szDCBusName) == 0 &&
					fabs(pBpaBlock->m_BpaDat_DCBusArray[i].fkV - pBpaBlock->m_BpaDat_EdgeDCLineArray[j].fDCBuskV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				{
					la_1 += 1;
				}
				else
				{
					goto DCBus2DCLine;
				}
			}
DCBus2DCLine:	pBpaBlock->m_BpaDat_DCBusArray[i+1].nEdgeDCLineRange = la_1;

			for (j=la_2; j<pBpaBlock->m_nRecordNum[BPA_DAT_EDGER]; j++)
			{
				if (strcmp(pBpaBlock->m_BpaDat_DCBusArray[i].szName, pBpaBlock->m_BpaDat_EdgeRArray[j].szDCBusName) == 0 &&
					fabs(pBpaBlock->m_BpaDat_DCBusArray[i].fkV - pBpaBlock->m_BpaDat_EdgeRArray[j].fDCBuskV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				{
					la_2 += 1;
				}
				else
				{
					goto DCBus2Wind;
				}
			}
DCBus2Wind:	pBpaBlock->m_BpaDat_DCBusArray[i+1].nEdgeRRange = la_2;
		}
	}

	std::string	CBpaMemDBInterface::GetSubString(tagBpaBlock* pBpaBlock, const int nJointBusNum, const int nJointBussArray[])
	{
		register int	i;
		double	fMaxBusVolt;
		int		nMaxBusVolt;

		if (nJointBusNum <= 0)
			return "";

		nMaxBusVolt=-1;
		fMaxBusVolt=0;
		for (i=0; i<nJointBusNum; i++)
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[nJointBussArray[i]].bTMid)
				continue;
			if (fMaxBusVolt < pBpaBlock->m_BpaDat_ACBusArray[nJointBussArray[i]].fkV)
			{
				fMaxBusVolt=pBpaBlock->m_BpaDat_ACBusArray[nJointBussArray[i]].fkV;
				nMaxBusVolt=i;
			}
		}
		if (nMaxBusVolt < 0)
		{
			for (i=0; i<nJointBusNum; i++)
			{
				if (fMaxBusVolt < pBpaBlock->m_BpaDat_ACBusArray[nJointBussArray[i]].fkV)
				{
					fMaxBusVolt=pBpaBlock->m_BpaDat_ACBusArray[nJointBussArray[i]].fkV;
					nMaxBusVolt=i;
				}
			}
		}
		if (nMaxBusVolt < 0)
			return "";

// 		std::string	strSub;
// 		char	szVolt[260];
// 		sprintf(szVolt, "%.0fkV", fMaxBusVolt);
// 		strSub = szVolt;
// 		strSub.append(pBpaBlock->m_BpaDat_ACBusArray[nJointBussArray[nMaxBusVolt]].szName);
// 		return strSub;

		return pBpaBlock->m_BpaDat_ACBusArray[nJointBussArray[nMaxBusVolt]].szName;
	}

	void CBpaMemDBInterface::BpaFormSubstation(tagBpaBlock* pBpaBlock, const double fZIL)
	{
		register int	i;
		int		nBus, nSubNum;
		std::vector<unsigned char>	bBusProcArray;
		int		nJointBusNum, *pnJointBusArray;
		std::string	strSub;
		char	szZone[MDB_CHARLEN_SHORTEST];

		pBpaBlock->m_nRecordNum[BPA_DAT_SUB]=0;

		nJointBusNum=0;
		pnJointBusArray=(int*)malloc((pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]+1)*sizeof(int));
		if (!pnJointBusArray)
			return;

		nSubNum=0;
		bBusProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS], 0);
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			bBusProcArray[i]=0;
		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
			if (bBusProcArray[nBus])
				continue;
			bBusProcArray[nBus]=1;

			BpaTraverseSub(pBpaBlock, nBus, fZIL, nJointBusNum, pnJointBusArray);
			for (i=0; i<nJointBusNum; i++)
				bBusProcArray[pnJointBusArray[i]]=1;

			strSub = GetSubString(pBpaBlock, nJointBusNum, pnJointBusArray);
			memset(szZone, 0, MDB_CHARLEN_SHORTEST);

			strcpy(pBpaBlock->m_BpaDat_SubArray[pBpaBlock->m_nRecordNum[BPA_DAT_SUB]].szName, strSub.c_str());
			pBpaBlock->m_BpaDat_SubArray[pBpaBlock->m_nRecordNum[BPA_DAT_SUB]].nSubType = 0;
			for (i=0; i<nJointBusNum; i++)
			{
				strcpy(pBpaBlock->m_BpaDat_ACBusArray[pnJointBusArray[i]].szBpaSub, strSub.c_str());
				if (fabs(pBpaBlock->m_BpaDat_ACBusArray[pnJointBusArray[i]].fPGen) > FLT_MIN || pBpaBlock->m_BpaDat_ACBusArray[pnJointBusArray[i]].fPmax > FLT_MIN)
					pBpaBlock->m_BpaDat_SubArray[pBpaBlock->m_nRecordNum[BPA_DAT_SUB]].nSubType = 1;

				if (strlen(pBpaBlock->m_BpaDat_ACBusArray[pnJointBusArray[i]].szZone) > 0)
					strcpy(szZone, pBpaBlock->m_BpaDat_ACBusArray[pnJointBusArray[i]].szZone);
			}
			if (strlen(szZone) > 0)
			{
				for (i=0; i<nJointBusNum; i++)
				{
					if (strlen(pBpaBlock->m_BpaDat_ACBusArray[pnJointBusArray[i]].szZone) <= 0)
						strcpy(pBpaBlock->m_BpaDat_ACBusArray[pnJointBusArray[i]].szZone, szZone);
				}
			}
			pBpaBlock->m_nRecordNum[BPA_DAT_SUB]++;
		}
		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_SUB);				//	排序
		MemDBBase::MDBCheckTableExist<tagBpaBlock>(pBpaBlock, BPA_DAT_SUB);		//	数据检查

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; i++)
			strcpy(pBpaBlock->m_BpaDat_DCBusArray[i].szSub, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_DCBusArray[i].nACBus].szBpaSub);

		free(pnJointBusArray);
		bBusProcArray.clear();

		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
			pBpaBlock->m_BpaDat_ACBusArray[nBus].nSubPtr = BpaFindRecordbyKey(pBpaBlock, BPA_DAT_SUB, pBpaBlock->m_BpaDat_ACBusArray[nBus].szBpaSub);

		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
			if (strlen(pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone) > 0)
				continue;

			for (i=pBpaBlock->m_BpaDat_ACBusArray[nBus].nEdgeACLineRange; i<pBpaBlock->m_BpaDat_ACBusArray[nBus+1].nEdgeACLineRange; i++)
			{
				int	nLine=pBpaBlock->m_BpaDat_EdgeACLineArray[i].nACLinePtr;
				int nOppBus = (pBpaBlock->m_BpaDat_ACLineArray[nLine].nIBus == nBus) ? pBpaBlock->m_BpaDat_ACLineArray[nLine].nZBus : pBpaBlock->m_BpaDat_ACLineArray[nLine].nIBus;

				if (strlen(pBpaBlock->m_BpaDat_ACBusArray[nOppBus].szZone) > 0)
					strcpy(pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone, pBpaBlock->m_BpaDat_ACBusArray[nOppBus].szZone);
			}
		}

		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
			if (strlen(pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone) > 0)
				continue;

			for (i=pBpaBlock->m_BpaDat_ACBusArray[nBus].nEdgeLineHGRange; i<pBpaBlock->m_BpaDat_ACBusArray[nBus+1].nEdgeLineHGRange; i++)
			{
				int	nHCap=pBpaBlock->m_BpaDat_EdgeLineHGArray[i].nLineHG;
				int nOppBus = (pBpaBlock->m_BpaDat_LineHGArray[nHCap].nIBus == nBus) ? pBpaBlock->m_BpaDat_LineHGArray[nHCap].nZBus : pBpaBlock->m_BpaDat_LineHGArray[nHCap].nIBus;

				if (strlen(pBpaBlock->m_BpaDat_ACBusArray[nOppBus].szZone) > 0)
					strcpy(pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone, pBpaBlock->m_BpaDat_ACBusArray[nOppBus].szZone);
			}
		}

		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
			if (strlen(pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone) > 0)
				continue;

			for (i=pBpaBlock->m_BpaDat_ACBusArray[nBus].nEdgeWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[nBus+1].nEdgeWindRange; i++)
			{
				int	nTran=pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr;
				int nOppBus = (pBpaBlock->m_BpaDat_WindArray[nTran].nIBus == nBus) ? pBpaBlock->m_BpaDat_WindArray[nTran].nZBus : pBpaBlock->m_BpaDat_WindArray[nTran].nIBus;

				if (strlen(pBpaBlock->m_BpaDat_ACBusArray[nOppBus].szZone) > 0)
					strcpy(pBpaBlock->m_BpaDat_ACBusArray[nBus].szZone, pBpaBlock->m_BpaDat_ACBusArray[nOppBus].szZone);
			}
		}
	}

	void CBpaMemDBInterface::BpaFormTransformer(tagBpaBlock* pBpaBlock)
	{
		register int	i, j;
		int		nBus, nDev, nWind1, nWind2, nWindBus1, nWindBus2;
		unsigned char	bFlag;
		float	fMaxV, fMinV;
		int		nMaxT, nMinT, nMidT;
		int		nOppBusNum, nOppBusArray[10];
		tagBpaDat_Tran	tTran;

		pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]=0;
		memset(&tTran, 0, sizeof(tagBpaDat_Tran));

		//	形成变压器中性点标记
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bTMid=0;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nDev++)
		{
			if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[nDev].szCardKey, "B") != 0)
				continue;
			if (pBpaBlock->m_BpaDat_ACBusArray[nDev+1].nEdgeWindRange-pBpaBlock->m_BpaDat_ACBusArray[nDev].nEdgeWindRange != 3)
				continue;
			if (pBpaBlock->m_BpaDat_ACBusArray[nDev+1].nEdgeACLineRange-pBpaBlock->m_BpaDat_ACBusArray[nDev].nEdgeACLineRange > 0)
				continue;
			if (fabs(pBpaBlock->m_BpaDat_ACBusArray[nDev].fLoadP) > FLT_MIN || fabs(pBpaBlock->m_BpaDat_ACBusArray[nDev].fPGen) > FLT_MIN || fabs(pBpaBlock->m_BpaDat_ACBusArray[nDev].fPmax) > FLT_MIN)
				continue;
			if (pBpaBlock->m_BpaDat_ACBusArray[nDev].bGenerator != 0 || pBpaBlock->m_BpaDat_ACBusArray[nDev].bDCBound != 0)
				continue;

			//if (strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁华德") != NULL ||
			//	strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁临厂") != NULL ||
			//	strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁十里") != NULL)
			//	Log(g_lpszLogFile, "预判中性点 = %s %g\n", pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, pBpaBlock->m_BpaDat_ACBusArray[nDev].fkV);

			nOppBusNum = 0;
			for (i=pBpaBlock->m_BpaDat_ACBusArray[nDev].nEdgeWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[nDev+1].nEdgeWindRange; i++)
			{
				nWind1 = pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr;
				nOppBusArray[nOppBusNum++] = (pBpaBlock->m_BpaDat_WindArray[nWind1].nIBus == nDev) ? pBpaBlock->m_BpaDat_WindArray[nWind1].nZBus : pBpaBlock->m_BpaDat_WindArray[nWind1].nIBus;
			}

			bFlag=1;
			for (i=0; i<nOppBusNum; i++)
			{
				for (j=i+1; j<nOppBusNum; j++)
				{
					if (nOppBusArray[i] == nOppBusArray[j])
					{
						//if (strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁华德") != NULL ||
						//	strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁临厂") != NULL ||
						//	strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁十里") != NULL)
						//{
						//	Log(g_lpszLogFile, "    [%s %g] 对侧母线 [%s %g] 母线比较\n",
						//		pBpaBlock->m_BpaDat_ACBusArray[nOppBusArray[i]].szName, pBpaBlock->m_BpaDat_ACBusArray[nOppBusArray[i]].fkV,
						//		pBpaBlock->m_BpaDat_ACBusArray[nOppBusArray[j]].szName, pBpaBlock->m_BpaDat_ACBusArray[nOppBusArray[j]].fkV);
						//}

						bFlag = 0;
						break;
					}
				}
				if (!bFlag)
					break;
			}
			if (bFlag)
			{
				bFlag = 0;
				for (i=pBpaBlock->m_BpaDat_ACBusArray[nDev].nEdgeWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[nDev+1].nEdgeWindRange; i++)
				{
					nWind1 = pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr;
					nWindBus1=(pBpaBlock->m_BpaDat_WindArray[nWind1].nIBus == nDev) ? pBpaBlock->m_BpaDat_WindArray[nWind1].nZBus : pBpaBlock->m_BpaDat_WindArray[nWind1].nIBus;
					if (pBpaBlock->m_BpaDat_ACBusArray[nWindBus1].fkV <= 1.0)
						break;

					for (j=i+1; j<pBpaBlock->m_BpaDat_ACBusArray[nDev+1].nEdgeWindRange; j++)
					{
						nWind2 = pBpaBlock->m_BpaDat_EdgeWindArray[j].nWindPtr;
						nWindBus2=(pBpaBlock->m_BpaDat_WindArray[nWind2].nIBus == nDev) ? pBpaBlock->m_BpaDat_WindArray[nWind2].nZBus : pBpaBlock->m_BpaDat_WindArray[nWind2].nIBus;

						if (fabs(pBpaBlock->m_BpaDat_ACBusArray[nWindBus1].fkV-pBpaBlock->m_BpaDat_ACBusArray[nWindBus2].fkV) > 0.15)
						{
							//if (strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁华德") != NULL ||
							//	strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁临厂") != NULL ||
							//	strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁十里") != NULL)
							//{
							//	Log(g_lpszLogFile, "    [%s %g] 对侧母线 [%s %g] 电压比较\n",
							//		pBpaBlock->m_BpaDat_ACBusArray[nWindBus1].szName, pBpaBlock->m_BpaDat_ACBusArray[nWindBus1].fkV,
							//		pBpaBlock->m_BpaDat_ACBusArray[nWindBus2].szName, pBpaBlock->m_BpaDat_ACBusArray[nWindBus2].fkV);
							//}
							bFlag=1;
							break;
						}
					}
				}
			}

			if (bFlag)
			{
				pBpaBlock->m_BpaDat_ACBusArray[nDev].bTMid=1;
				//if (strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁华德") != NULL ||
				//	strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁临厂") != NULL ||
				//	strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁十里") != NULL)
				//	Log(g_lpszLogFile, "    确认中性点\n");
			}
			else
			{
				//if (strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁华德") != NULL ||
				//	strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁临厂") != NULL ||
				//	strstr(pBpaBlock->m_BpaDat_ACBusArray[nDev].szName, "鲁十里") != NULL)
				//	Log(g_lpszLogFile, "    确认非中性点\n");
			}
		}

		double	fMinX=10000;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)
		{
			bFlag=0;
			fMinX=10000;
			if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].bTMid && pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].bTMid)
			{
				//Log(g_lpszLogFile, "两侧中性点 = %s\n", pBpaBlock->m_BpaDat_WindArray[nDev].szKeyName);

				pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].bTMid=0;
				pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].bTMid=0;
				for (i=pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].nEdgeWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus+1].nEdgeWindRange; i++)
				{
					if (fMinX > pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr].fX)
					{
						bFlag=1;
						fMinX = pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr].fX;
					}
				}
				for (i=pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].nEdgeWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus+1].nEdgeWindRange; i++)
				{
					if (fMinX > pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr].fX)
					{
						bFlag=2;
						fMinX = pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr].fX;
					}
				}
			}
			if (bFlag == 1)
				pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].bTMid=1;
			else if (bFlag == 2)
				pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].bTMid=1;
		}

		std::vector<unsigned char> bWindProcArray;
		bWindProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_WIND]);
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
			bWindProcArray[i]=0;

		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
			if (!pBpaBlock->m_BpaDat_ACBusArray[nBus].bTMid)
				continue;
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus+1].nEdgeWindRange-pBpaBlock->m_BpaDat_ACBusArray[nBus].nEdgeWindRange > 3)
			{
				Log(g_lpszLogFile, "变压器中性点(%s %.2f)连接变压器错误\n", pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);
				continue;
			}

			fMaxV=-9999;
			fMinV=9999;
			nMaxT=nMinT=nMidT=-1;
			for (i=pBpaBlock->m_BpaDat_ACBusArray[nBus].nEdgeWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[nBus+1].nEdgeWindRange; i++)
			{
				nDev=pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr;
				bWindProcArray[nDev]=1;

				nWindBus1=(pBpaBlock->m_BpaDat_WindArray[nDev].nIBus == nBus) ? pBpaBlock->m_BpaDat_WindArray[nDev].nZBus : pBpaBlock->m_BpaDat_WindArray[nDev].nIBus;
				if (pBpaBlock->m_BpaDat_ACBusArray[nWindBus1].fkV > fMaxV)
				{
					fMaxV=pBpaBlock->m_BpaDat_ACBusArray[nWindBus1].fkV;
					nMaxT=nDev;
				}
				if (pBpaBlock->m_BpaDat_ACBusArray[nWindBus1].fkV < fMinV)
				{
					fMinV=pBpaBlock->m_BpaDat_ACBusArray[nWindBus1].fkV;
					nMinT=nDev;
				}
			}

			memset(&tTran, 0, sizeof(tagBpaDat_Tran));
			tTran.nWindNum=0;
			tTran.iRWindH=tTran.iRWindM=tTran.iRWindL=-1;

			strcpy(tTran.szWindH, pBpaBlock->m_BpaDat_WindArray[nMaxT].szKeyName);
			tTran.iRWindH=nMaxT;
			tTran.nWindNum++;

			strcpy(tTran.szWindL, pBpaBlock->m_BpaDat_WindArray[nMinT].szKeyName);
			tTran.iRWindL=nMinT;
			tTran.nWindNum++;

			for (i=pBpaBlock->m_BpaDat_ACBusArray[nBus].nEdgeWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[nBus+1].nEdgeWindRange; i++)
			{
				if (pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr == nMaxT || pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr == nMinT)
					continue;
				nMidT=pBpaBlock->m_BpaDat_EdgeWindArray[i].nWindPtr;
			}
			if (nMidT >= 0)
			{
				strcpy(tTran.szWindM, pBpaBlock->m_BpaDat_WindArray[nMidT].szKeyName);
				tTran.iRWindM=nMidT;
				tTran.nWindNum++;
			}
			memcpy(&pBpaBlock->m_BpaDat_TranArray[pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]++], &tTran, sizeof(tagBpaDat_Tran));
		}

		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)
		{
			if (bWindProcArray[nDev])
				continue;

			memset(&tTran, 0, sizeof(tagBpaDat_Tran));
			tTran.nWindNum=1;
			tTran.iRWindH=tTran.iRWindM=tTran.iRWindL=-1;

			strcpy(tTran.szWindH, pBpaBlock->m_BpaDat_WindArray[nDev].szKeyName);
			strcpy(tTran.szWindL, pBpaBlock->m_BpaDat_WindArray[nDev].szKeyName);
			tTran.iRWindH=tTran.iRWindL=nDev;
			memcpy(&pBpaBlock->m_BpaDat_TranArray[pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]++], &tTran, sizeof(tagBpaDat_Tran));
		}

		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_TRAN);				//	排序
		MemDBBase::MDBCheckTableExist<tagBpaBlock>(pBpaBlock, BPA_DAT_TRAN);	//	数据检查

		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)
			pBpaBlock->m_BpaDat_WindArray[nDev].nTran = -1;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]; nDev++)
		{
			if (pBpaBlock->m_BpaDat_TranArray[nDev].iRWindH >= 0)	pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nDev].iRWindH].nTran = nDev;
			if (pBpaBlock->m_BpaDat_TranArray[nDev].iRWindM >= 0)	pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nDev].iRWindM].nTran = nDev;
			if (pBpaBlock->m_BpaDat_TranArray[nDev].iRWindL >= 0)	pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nDev].iRWindL].nTran = nDev;
		}
	}

	void CBpaMemDBInterface::BpaFormGenerator(tagBpaBlock* pBpaBlock)
	{
		register int	i;
		int		nBus;
		double	fGenRatio, fGenPMax;
		double	fGenPFactor, fGenQFactor;
		unsigned char	bHasSwiGen;

		pBpaBlock->m_nRecordNum[BPA_DAT_GEN] = 0;

		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
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

			//	有发电机模型的
			fGenPMax = (pBpaBlock->m_BpaDat_ACBusArray[nBus].fPmax < pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen) ? pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen : pBpaBlock->m_BpaDat_ACBusArray[nBus].fPmax;
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bGenerator == 0)
				continue;

			if (strstr(pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, "柔昌平") != NULL)
			{
				Log(g_lpszLogFile, "====================Name=%s kV=%g\n", pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);
			}
			if (fGenPMax < FLT_MIN)
			{
				if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBus].szCardKey, "BS") != 0)
					continue;
			}


			bHasSwiGen=0;
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_SWI_GEN]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaSwi_GenArray[i].szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nBus].szName) == 0 && fabs(pBpaBlock->m_BpaSwi_GenArray[i].fBus_kV - pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV) < 0.15)
				{
					memset(&pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]], 0, sizeof(tagBpaDat_Gen));

					fGenRatio=1;
					if (pBpaBlock->m_BpaSwi_GenArray[i].fP > 0 && pBpaBlock->m_BpaSwi_GenArray[i].fP < 1)
						fGenRatio=pBpaBlock->m_BpaSwi_GenArray[i].fP;

					if (pBpaBlock->m_BpaSwi_GenArray[i].cID != ' ' && pBpaBlock->m_BpaSwi_GenArray[i].cID != '\0')
						sprintf(pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].szName, "%s%g@%c", pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV, pBpaBlock->m_BpaSwi_GenArray[i].cID);
					else
						sprintf(pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].szName, "%s%g", pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);
					strcpy(pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].szBus,	pBpaBlock->m_BpaDat_ACBusArray[nBus].szName);
					pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fkV				=	pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV;
					pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].cID				=	pBpaBlock->m_BpaSwi_GenArray[i].cID;

					pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fP				=	(float)(fGenRatio*fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen		);
					pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fQ				=	(float)(fGenRatio*fGenQFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fQsched_Qmax	);
					pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fPMax			=	(float)(fGenPMax*fGenRatio);
					pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fQMax			=	(float)(pBpaBlock->m_BpaDat_ACBusArray[nBus].fQsched_Qmax*fGenRatio);

					pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].nACBusIndex		=	nBus;
					if (pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fPMax < fGenRatio*fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen)
						pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fPMax = (float)(fGenRatio*fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen);

					if (strstr(pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, "柔昌平") != NULL)
					{
						Log(g_lpszLogFile, "    ==========AddGen 1 %s\n", pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].szName);
					}
					pBpaBlock->m_nRecordNum[BPA_DAT_GEN]++;
					bHasSwiGen=1;
				}
			}

			if (!bHasSwiGen)	//	没有发电机模型
			{
				memset(&pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]], 0, sizeof(tagBpaDat_Gen));

				sprintf(pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].szName, "%s%g",	pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);
				strcpy(pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].szBus,	pBpaBlock->m_BpaDat_ACBusArray[nBus].szName);
				pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fkV				=	pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV;
				pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].cID				=	' ';

				pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fP				=	(float)(fGenPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen);
				pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fQ				=	(float)(fGenQFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fQsched_Qmax);
				pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fPMax			=	(float)fGenPMax;
				pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fQMax			=	pBpaBlock->m_BpaDat_ACBusArray[nBus].fQsched_Qmax;

				pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].nACBusIndex		=	nBus;
				pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].bWTGen			=	(pBpaBlock->m_BpaDat_ACBusArray[nBus].bWTGen) ? 1 : 0;
				pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].bPVGen			=	(pBpaBlock->m_BpaDat_ACBusArray[nBus].bPVGen) ? 1 : 0;
				if (pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fPMax < pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen)
					pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fPMax = pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen;

				if (strstr(pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, "柔昌平") != NULL)
				{
					Log(g_lpszLogFile, "    ==========AddGen 2 %s\n", pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].szName);
				}
				pBpaBlock->m_nRecordNum[BPA_DAT_GEN]++;
			}
		}

		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_GEN);			//	排序
		MemDBBase::MDBCheckTableExist<tagBpaBlock>(pBpaBlock, BPA_DAT_GEN);	//	数据检查
	}

	void CBpaMemDBInterface::BpaFormLoad(tagBpaBlock* pBpaBlock)
	{
		register int	i;
		int		nBus;
		double	fLoadPFactor, fLoadQFactor;

		pBpaBlock->m_nRecordNum[BPA_DAT_LOAD] = 0;

		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
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

			if (fabs(pBpaBlock->m_BpaDat_ACBusArray[nBus].fLoadP) > FLT_MIN)
			{
				memset(&pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]], 0, sizeof(tagBpaDat_Load));

				sprintf(pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].szName,	"%s%g",	pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);
				strcpy(pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].szBus,		pBpaBlock->m_BpaDat_ACBusArray[nBus].szName);
				pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].fkV			=	pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV;

				pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].fP				=	(float)(fLoadPFactor*(pBpaBlock->m_BpaDat_ACBusArray[nBus].fLoadP+pBpaBlock->m_BpaDat_ACBusArray[nBus].fAddLoadP));
				pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].fQ				=	(float)(fLoadQFactor*(pBpaBlock->m_BpaDat_ACBusArray[nBus].fLoadQ+pBpaBlock->m_BpaDat_ACBusArray[nBus].fAddLoadQ));

				pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].nACBusIndex	=	nBus;
				pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].bAux			=	(pBpaBlock->m_BpaDat_ACBusArray[nBus].bGenerator != 0 && pBpaBlock->m_BpaDat_ACBusArray[nBus].bGenLn == 0 && pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV < 50) ? 1 : 0;

				pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]++;
			}
		}

		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_LOAD);				//	排序
		MemDBBase::MDBCheckTableExist<tagBpaBlock>(pBpaBlock, BPA_DAT_LOAD);	//	数据检查
	}
}