#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"

namespace	BpaMemDB
{
	void	BpaFormEdge(tagBpaBlock* pBpaBlock)
	{
		register int	i;
		clock_t	dBeg, dEnd;
		int		nDur;

		pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINE]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]=0;
		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
		{
			strcpy(pBpaBlock->m_BpaDat_EdgeLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINE]].szBusName,			pBpaBlock->m_BpaDat_ACLineArray[i].szBusI);
			pBpaBlock->m_BpaDat_EdgeLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINE]].fBuskV=pBpaBlock->m_BpaDat_ACLineArray[i].fkVI;
			strcpy(pBpaBlock->m_BpaDat_EdgeLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINE]].szLineName,			pBpaBlock->m_BpaDat_ACLineArray[i].szKeyName);
			pBpaBlock->m_BpaDat_EdgeLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINE]].iRLine=i;
			pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINE]++;

			strcpy(pBpaBlock->m_BpaDat_EdgeLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINE]].szBusName,			pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ);
			pBpaBlock->m_BpaDat_EdgeLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINE]].fBuskV=pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ;
			strcpy(pBpaBlock->m_BpaDat_EdgeLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINE]].szLineName,			pBpaBlock->m_BpaDat_ACLineArray[i].szKeyName);
			pBpaBlock->m_BpaDat_EdgeLineArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINE]].iRLine=i;
			pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINE]++;
		}
		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_EDGELINE);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FormACBus2Line，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
		{
			if (pBpaBlock->m_BpaDat_WindArray[i].bRCard)
				continue;

			strcpy(pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].szBusName,			pBpaBlock->m_BpaDat_WindArray[i].szBusI);
			pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].fBuskV=pBpaBlock->m_BpaDat_WindArray[i].fkVI;
			strcpy(pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].szWindName,			pBpaBlock->m_BpaDat_WindArray[i].szKeyName);
			pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].iRWind=i;
			pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]++;

			strcpy(pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].szBusName,			pBpaBlock->m_BpaDat_WindArray[i].szBusJ);
			pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].fBuskV=pBpaBlock->m_BpaDat_WindArray[i].fkVJ;
			strcpy(pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].szWindName,			pBpaBlock->m_BpaDat_WindArray[i].szKeyName);
			pBpaBlock->m_BpaDat_EdgeWindArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]].iRWind=i;
			pBpaBlock->m_nRecordNum[BPA_DAT_EDGEWIND]++;
		}
		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_EDGEWIND);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FormACBus2Tran，耗时%d毫秒\n", nDur);

		dBeg=clock();
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
		{
			strcpy(pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].szBusName,			pBpaBlock->m_BpaDat_LineHGArray[i].szBusI);
			pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].fBuskV=pBpaBlock->m_BpaDat_LineHGArray[i].fkVI;
			strcpy(pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].szLineHGName,				pBpaBlock->m_BpaDat_LineHGArray[i].szKeyName);
			pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].nLineHG=i;
			pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]++;

			if (strlen(pBpaBlock->m_BpaDat_LineHGArray[i].szBusJ) > 0)
			{
				strcpy(pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].szBusName,			pBpaBlock->m_BpaDat_LineHGArray[i].szBusJ);
				pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].fBuskV=pBpaBlock->m_BpaDat_LineHGArray[i].fkVJ;
				strcpy(pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].szLineHGName,				pBpaBlock->m_BpaDat_LineHGArray[i].szKeyName);
				pBpaBlock->m_BpaDat_EdgeLineHGArray[pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]].nLineHG=i;
				pBpaBlock->m_nRecordNum[BPA_DAT_EDGELINEHG]++;
			}
		}
		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_EDGELINEHG);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FormACBus2HG，耗时%d毫秒\n", nDur);
	}

	std::string	GetSubString(tagBpaBlock* pBpaBlock, const int nJointBusNum, const int nJointBussArray[])
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

		return pBpaBlock->m_BpaDat_ACBusArray[nJointBussArray[nMaxBusVolt]].szName;
	}

	void	BpaFormSubstation(tagBpaBlock* pBpaBlock, const double fZIL)
	{
		register int	i;
		int		nBus, nSubNum;
		std::vector<unsigned char>	bBusProcArray;
		int		nJointBusNum, *pnJointBusArray;
		std::string	strSub;

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

			strcpy(pBpaBlock->m_BpaDat_SubArray[pBpaBlock->m_nRecordNum[BPA_DAT_SUB]].szName, strSub.c_str());
			pBpaBlock->m_BpaDat_SubArray[pBpaBlock->m_nRecordNum[BPA_DAT_SUB]].nSubType = 0;
			for (i=0; i<nJointBusNum; i++)
			{
				strcpy(pBpaBlock->m_BpaDat_ACBusArray[pnJointBusArray[i]].szBpaSub, strSub.c_str());
				if (fabs(pBpaBlock->m_BpaDat_ACBusArray[pnJointBusArray[i]].fPGen) > FLT_MIN || pBpaBlock->m_BpaDat_ACBusArray[pnJointBusArray[i]].fPmax > FLT_MIN)
					pBpaBlock->m_BpaDat_SubArray[pBpaBlock->m_nRecordNum[BPA_DAT_SUB]].nSubType = 1;
			}
			pBpaBlock->m_nRecordNum[BPA_DAT_SUB]++;
		}
		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_SUB);				//	排序

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; i++)
			strcpy(pBpaBlock->m_BpaDat_DCBusArray[i].szSub, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_DCBusArray[i].nACBus].szBpaSub);

		free(pnJointBusArray);
		bBusProcArray.clear();

		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
			strcpy(szRest[0], pBpaBlock->m_BpaDat_ACBusArray[nBus].szBpaSub);
			pBpaBlock->m_BpaDat_ACBusArray[nBus].nSubPtr = MemDBBase::MDBFindRecordQuick(pBpaBlock, BPA_DAT_SUB, 0, pBpaBlock->m_nRecordNum[BPA_DAT_SUB]-1, szRest);
		}
	}

	void	BpaFormTransformer(tagBpaBlock* pBpaBlock)
	{
		register int	i, j;
		int		nBus, nDev, nTranBus1, nTranBus2;
		unsigned char	bFlag;
		float	fMaxV, fMinV;
		int		nMaxT, nMinT, nMidT;
		tagBpaDat_Tran	tBuffer;

		pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]=0;
		memset(&tBuffer, 0, sizeof(tagBpaDat_Tran));

		//	形成变压器中性点标记
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].bTMid=0;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nDev++)
		{
			if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[nDev].szCardKey, "B") != 0)
				continue;
			if (pBpaBlock->m_BpaDat_ACBusArray[nDev+1].nWindRange-pBpaBlock->m_BpaDat_ACBusArray[nDev].nWindRange != 3)
				continue;
			if (pBpaBlock->m_BpaDat_ACBusArray[nDev+1].nACLineRange-pBpaBlock->m_BpaDat_ACBusArray[nDev].nACLineRange > 0)
				continue;
			if (fabs(pBpaBlock->m_BpaDat_ACBusArray[nDev].fLoadP) > FLT_MIN || fabs(pBpaBlock->m_BpaDat_ACBusArray[nDev].fPGen) > FLT_MIN || fabs(pBpaBlock->m_BpaDat_ACBusArray[nDev].fPmax) > FLT_MIN)
				continue;
			if (pBpaBlock->m_BpaDat_ACBusArray[nDev].bGenerator != 0 || pBpaBlock->m_BpaDat_ACBusArray[nDev].bDCBound != 0)
				continue;

			bFlag=0;
			for (i=pBpaBlock->m_BpaDat_ACBusArray[nDev].nWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[nDev+1].nWindRange; i++)
			{
				nTranBus1=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[i].iRWind].nIBus == nDev) ?
					pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[i].iRWind].nZBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[i].iRWind].nIBus;
				for (j=i+1; j<pBpaBlock->m_BpaDat_ACBusArray[nDev+1].nWindRange; j++)
				{
					nTranBus2=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[j].iRWind].nIBus == nDev) ?
						pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[j].iRWind].nZBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[j].iRWind].nIBus;

					if (fabs(pBpaBlock->m_BpaDat_ACBusArray[nTranBus1].fkV-pBpaBlock->m_BpaDat_ACBusArray[nTranBus2].fkV) < 0.15)
					{
						bFlag=1;
						break;
					}
				}
				if (bFlag)
					break;
			}

			if (!bFlag)
				pBpaBlock->m_BpaDat_ACBusArray[nDev].bTMid=1;
		}

		double	fMinX=10000;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)
		{
			bFlag=0;
			if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].bTMid && pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].bTMid)
			{
				pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].bTMid=0;
				pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].bTMid=0;
				for (i=pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus].nWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nIBus+1].nWindRange; i++)
				{
					if (fMinX > pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[i].iRWind].fX)
					{
						bFlag=1;
						fMinX = pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[i].iRWind].fX;
					}
				}
				for (i=pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus].nWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[nDev].nZBus+1].nWindRange; i++)
				{
					if (fMinX > pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[i].iRWind].fX)
					{
						bFlag=2;
						fMinX = pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[i].iRWind].fX;
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
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus+1].nWindRange-pBpaBlock->m_BpaDat_ACBusArray[nBus].nWindRange > 3)
			{
				Log(g_lpszLogFile, "变压器中性点(%s %.2f)连接变压器错误\n", pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);
				continue;
			}

			fMaxV=-9999;
			fMinV=9999;
			nMaxT=nMinT=nMidT=-1;
			for (i=pBpaBlock->m_BpaDat_ACBusArray[nBus].nWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[nBus+1].nWindRange; i++)
			{
				nDev=pBpaBlock->m_BpaDat_EdgeWindArray[i].iRWind;
				bWindProcArray[nDev]=1;

				nTranBus1=(pBpaBlock->m_BpaDat_WindArray[nDev].nIBus == nBus) ? pBpaBlock->m_BpaDat_WindArray[nDev].nZBus : pBpaBlock->m_BpaDat_WindArray[nDev].nIBus;
				if (pBpaBlock->m_BpaDat_ACBusArray[nTranBus1].fkV > fMaxV)
				{
					fMaxV=pBpaBlock->m_BpaDat_ACBusArray[nTranBus1].fkV;
					nMaxT=nDev;
				}
				if (pBpaBlock->m_BpaDat_ACBusArray[nTranBus1].fkV < fMinV)
				{
					fMinV=pBpaBlock->m_BpaDat_ACBusArray[nTranBus1].fkV;
					nMinT=nDev;
				}
			}

			memset(&tBuffer, 0, sizeof(tagBpaDat_Tran));
			tBuffer.nWindNum=0;
			tBuffer.iRWindH=tBuffer.iRWindM=tBuffer.iRWindL=-1;

			strcpy(tBuffer.szWindH, pBpaBlock->m_BpaDat_WindArray[nMaxT].szKeyName);
			tBuffer.iRWindH=nMaxT;
			tBuffer.nWindNum++;

			strcpy(tBuffer.szWindL, pBpaBlock->m_BpaDat_WindArray[nMinT].szKeyName);
			tBuffer.iRWindL=nMinT;
			tBuffer.nWindNum++;

			for (i=pBpaBlock->m_BpaDat_ACBusArray[nBus].nWindRange; i<pBpaBlock->m_BpaDat_ACBusArray[nBus+1].nWindRange; i++)
			{
				if (pBpaBlock->m_BpaDat_EdgeWindArray[i].iRWind == nMaxT || pBpaBlock->m_BpaDat_EdgeWindArray[i].iRWind == nMinT)
					continue;
				nMidT=pBpaBlock->m_BpaDat_EdgeWindArray[i].iRWind;
			}
			if (nMidT >= 0)
			{
				strcpy(tBuffer.szWindM, pBpaBlock->m_BpaDat_WindArray[nMidT].szKeyName);
				tBuffer.iRWindM=nMidT;
				tBuffer.nWindNum++;
			}
			memcpy(&pBpaBlock->m_BpaDat_TranArray[pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]++], &tBuffer, sizeof(tagBpaDat_Tran));
		}

		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)
		{
			if (bWindProcArray[nDev])
				continue;

			memset(&tBuffer, 0, sizeof(tagBpaDat_Tran));
			tBuffer.nWindNum=1;
			tBuffer.iRWindH=tBuffer.iRWindM=tBuffer.iRWindL=-1;

			strcpy(tBuffer.szWindH, pBpaBlock->m_BpaDat_WindArray[nDev].szKeyName);
			strcpy(tBuffer.szWindL, pBpaBlock->m_BpaDat_WindArray[nDev].szKeyName);
			tBuffer.iRWindH=tBuffer.iRWindL=nDev;
			memcpy(&pBpaBlock->m_BpaDat_TranArray[pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]++], &tBuffer, sizeof(tagBpaDat_Tran));
		}

		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_TRAN);				//	排序
	}

	void	BpaFormGenerator(tagBpaBlock* pBpaBlock)
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
					fGenQFactor=(pBpaBlock->m_BpaDat_PArray[i].fGenQFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fGenQFactor : 1;
					break;
				}
			}

			//	有发电机模型的
			fGenPMax = (pBpaBlock->m_BpaDat_ACBusArray[nBus].fPmax < pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen) ? pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen : pBpaBlock->m_BpaDat_ACBusArray[nBus].fPmax;
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bGenerator == 0)
				continue;
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bGenLn != 0)
				continue;

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
				pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].bWGen			=	(pBpaBlock->m_BpaDat_ACBusArray[nBus].bWTGen) ? 1 : 0;
				if (pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fPMax < pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen)
					pBpaBlock->m_BpaDat_GenArray[pBpaBlock->m_nRecordNum[BPA_DAT_GEN]].fPMax = pBpaBlock->m_BpaDat_ACBusArray[nBus].fPGen;

				pBpaBlock->m_nRecordNum[BPA_DAT_GEN]++;
			}
		}

		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_GEN);				//	排序
	}

	void	BpaFormLoad(tagBpaBlock* pBpaBlock)
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
					fLoadQFactor=(pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor > FLT_MIN) ? pBpaBlock->m_BpaDat_PArray[i].fLoadQFactor : 1;
					break;
				}
			}

			if (fabs(pBpaBlock->m_BpaDat_ACBusArray[nBus].fLoadP) > FLT_MIN)
			{
				memset(&pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]], 0, sizeof(tagBpaDat_Load));

				sprintf(pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].szName,	"%s%g",	pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);
				strcpy(pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].szBus,		pBpaBlock->m_BpaDat_ACBusArray[nBus].szName);
				pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].fkV			=	pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV;

				pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].fP				=	(float)(fLoadPFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fLoadP);
				pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].fQ				=	(float)(fLoadQFactor*pBpaBlock->m_BpaDat_ACBusArray[nBus].fLoadQ);

				pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].nACBusIndex	=	nBus;
				pBpaBlock->m_BpaDat_LoadArray[pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]].bAux			=	(pBpaBlock->m_BpaDat_ACBusArray[nBus].bGenerator != 0 && pBpaBlock->m_BpaDat_ACBusArray[nBus].bGenLn == 0 && pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV < 50) ? 1 : 0;

				pBpaBlock->m_nRecordNum[BPA_DAT_LOAD]++;
			}
		}

		MemDBBase::MDBSort<tagBpaBlock>(pBpaBlock, BPA_DAT_LOAD);				//	排序
	}
}