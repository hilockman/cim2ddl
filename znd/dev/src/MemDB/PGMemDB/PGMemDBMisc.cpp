#include "stdafx.h"
#include "PGMemDB.h"
#include "../../Common/String2Double.hpp"

namespace	PGMemDB
{
	int	PGGetVoltID(const float fVolt, char* lpszRetString)
	{
		if (fVolt < 0.5)
		{
			strcpy(lpszRetString, "220V");	return 1;
		}
		else if (fVolt < 1)
		{
			strcpy(lpszRetString, "0.69kV");	return 1;
		}
		else if (fVolt < 10)
		{
			strcpy(lpszRetString, "6kV");	return 1;
		}
		else if (fVolt < 12)
		{
			strcpy(lpszRetString, "10kV");	return 1;
		}
		else if (fVolt < 13)
		{
			strcpy(lpszRetString, "12kV");	return 1;
		}
		else if (fVolt < 14)
		{
			strcpy(lpszRetString, "13kV");	return 1;
		}
		else if (fVolt < 16)
		{
			strcpy(lpszRetString, "15kV");	return 1;
		}
		else if (fVolt < 20)
		{
			strcpy(lpszRetString, "18kV");	return 1;
		}
		else if (fVolt < 30)
		{
			strcpy(lpszRetString, "20kV");	return 1;
		}
		else if (fVolt < 40)
		{
			strcpy(lpszRetString, "35kV");	return 1;
		}
		else if (fVolt < 80)
		{
			strcpy(lpszRetString, "66kV");	return 1;
		}
		else if (fVolt < 130)
		{
			strcpy(lpszRetString, "110kV");	return 1;
		}
		else if (fVolt < 160)
		{
			strcpy(lpszRetString, "154kV");	return 1;
		}
		else if (fVolt < 300)
		{
			strcpy(lpszRetString, "220kV");	return 1;
		}
		else if (fVolt < 400)
		{
			strcpy(lpszRetString, "330kV");	return 1;
		}
		else if (fVolt < 450)
		{
			strcpy(lpszRetString, "400kV");	return 1;
		}
		else if (fVolt < 600)
		{
			strcpy(lpszRetString, "500kV");	return 1;
		}
		else if (fVolt < 800)
		{
			strcpy(lpszRetString, "750kV");	return 1;
		}
		else if (fVolt < 900)
		{
			strcpy(lpszRetString, "800kV");	return 1;
		}
		else if (fVolt < 1100)
		{
			strcpy(lpszRetString, "1000kV");	return 1;
		}

		strcpy(lpszRetString, "1");
		return 0;
	}

	void PGGetTranCoil(tagPGBlock* pPGBlock, const int nTran, int& nTranNum, int nTranCoil[], int nTranNode[])
	{
		register int	i, j;
		int		nSub;
		int		nNodeI, nNodeJ;
		int		nTranMidNode;

		float	fVolt, fMax, fMin;
		int		nMax, nMin, nMid, nSameV;
		int		nTranVoltNum;
		char	szTranVoltArray[10][MDB_CHARLEN];

		nTranNum=0;

		nSub=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_TransformerWindingArray[nTran].szSub);
		if (nSub < 0)
			return;

		nTranMidNode=-1;
		nNodeI=pPGBlock->m_TransformerWindingArray[nTran].nNodeI;
		nNodeJ=pPGBlock->m_TransformerWindingArray[nTran].nNodeJ;
		for (i=pPGBlock->m_SubstationArray[nSub].nTransformerWindingRange; i<pPGBlock->m_SubstationArray[nSub+1].nTransformerWindingRange; i++)
		{
			if (i == nTran)
				continue;

			if (pPGBlock->m_TransformerWindingArray[i].nNodeI == nNodeI || pPGBlock->m_TransformerWindingArray[i].nNodeJ == nNodeI)
				nTranMidNode=nNodeI;
			else if (pPGBlock->m_TransformerWindingArray[i].nNodeI == nNodeJ || pPGBlock->m_TransformerWindingArray[i].nNodeJ == nNodeJ)
				nTranMidNode=nNodeJ;
		}
		if (pPGBlock->m_ConnectivityNodeArray[nTranMidNode+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[nTranMidNode].nTransformerWindingRange >= 6)
			nTranMidNode = -1;

		if (nTranMidNode >= 0)
		{
			nSameV=0;
			nTranVoltNum=0;
			for (i=pPGBlock->m_ConnectivityNodeArray[nTranMidNode].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[nTranMidNode+1].nTransformerWindingRange; i++)
			{
				if (nTranMidNode == pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nNodeI)
					strcpy(szTranVoltArray[nTranVoltNum], pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].szVoltJ);
				else
					strcpy(szTranVoltArray[nTranVoltNum], pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].szVoltI);
				nTranVoltNum++;
			}

			for (i=0; i<nTranVoltNum; i++)
			{
				for (j=i+1; j<nTranVoltNum; j++)
				{
					if (strcmp(szTranVoltArray[i], szTranVoltArray[j]) == 0)
					{
						nSameV=1;
						break;
					}
				}
				if (nSameV)
					break;
			}
			if (nSameV != 0)
				nTranMidNode=-1;
		}

		if (nTranMidNode >= 0)
		{
			if (pPGBlock->m_ConnectivityNodeArray[nTranMidNode+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[nTranMidNode].nTransformerWindingRange != 3)
			{
				if (nTranNum < 9)
				{
					nTranCoil[nTranNum]=nTran;
					nTranNode[nTranNum]=pPGBlock->m_TransformerWindingArray[nTran].nNodeI;
					nTranNum++;
				}
			}
			else
			{
				fMax=0;
				fMin=100000;
				nMax=nMin=nMid=-1;

				for (i=pPGBlock->m_ConnectivityNodeArray[nTranMidNode].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[nTranMidNode+1].nTransformerWindingRange; i++)
				{
					fVolt=(nTranMidNode == pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nNodeI) ?
						pPGBlock->m_VoltageLevelArray[pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nVoltJ].nominalVoltage :
					pPGBlock->m_VoltageLevelArray[pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nVoltI].nominalVoltage;
					if (fMax < fVolt)
					{
						fMax=fVolt;
						nMax=pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding;
					}
				}

				for (i=pPGBlock->m_ConnectivityNodeArray[nTranMidNode].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[nTranMidNode+1].nTransformerWindingRange; i++)
				{
					if (nMax == pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding)
						continue;
					fVolt=(nTranMidNode == pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nNodeI) ?
						pPGBlock->m_VoltageLevelArray[pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nVoltJ].nominalVoltage :
					pPGBlock->m_VoltageLevelArray[pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nVoltI].nominalVoltage;
					if (fMin > fVolt)
					{
						fMin=fVolt;
						nMin=pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding;
					}
				}
				for (i=pPGBlock->m_ConnectivityNodeArray[nTranMidNode].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[nTranMidNode+1].nTransformerWindingRange; i++)
				{
					fVolt=(nTranMidNode == pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nNodeI) ?
						pPGBlock->m_VoltageLevelArray[pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nVoltJ].nominalVoltage :
					pPGBlock->m_VoltageLevelArray[pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nVoltI].nominalVoltage;

					if (pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding != nMin && pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding != nMax)
					{
						nMid=pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding;
						break;
					}
				}

				if (nMax >= 0)
				{
					if (nTranNum < 9)
					{
						nTranCoil[nTranNum]=nMax;
						nTranNode[nTranNum]=(pPGBlock->m_TransformerWindingArray[nMax].nNodeI == nTranMidNode) ? pPGBlock->m_TransformerWindingArray[nMax].nNodeJ : pPGBlock->m_TransformerWindingArray[nMax].nNodeI;
						nTranNum++;
					}
				}
				if (nMid >= 0)
				{
					if (nTranNum < 9)
					{
						nTranCoil[nTranNum]=nMid;
						nTranNode[nTranNum]=(pPGBlock->m_TransformerWindingArray[nMid].nNodeI == nTranMidNode) ? pPGBlock->m_TransformerWindingArray[nMid].nNodeJ : pPGBlock->m_TransformerWindingArray[nMid].nNodeI;
						nTranNum++;
					}
				}
				if (nMin >= 0)
				{
					if (nTranNum < 9)
					{
						nTranCoil[nTranNum]=nMin;
						nTranNode[nTranNum]=(pPGBlock->m_TransformerWindingArray[nMin].nNodeI == nTranMidNode) ? pPGBlock->m_TransformerWindingArray[nMin].nNodeJ : pPGBlock->m_TransformerWindingArray[nMin].nNodeI;
						nTranNum++;
					}
				}
			}
		}
		else
		{
			if (nTranNum < 9)
			{
				nTranCoil[nTranNum]=nTran;
				nTranNode[nTranNum]=pPGBlock->m_TransformerWindingArray[nTran].nNodeI;
				nTranNum++;
			}
		}
	}


	//	判断母线是否是T接厂站母线
	int	PGIsTConnection(tagPGBlock* pPGBlock, const int nJudgeNode)
	{
		register int	i, j;
		int		nLineNum, nTranNum, nBreakNum;
		int		nNodeNum, nNodeArray[1000];

		nLineNum=nTranNum=nBreakNum=0;
		if (nJudgeNode < 0)
			return 0;

		PGTraverseVolt(pPGBlock, nJudgeNode, N_CheckStatus, N_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
		for (i=0; i<nNodeNum; i++)
		{
			nLineNum += (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange);
			nTranNum += (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange);
			for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
				nBreakNum++;
		}

		if (nLineNum > 1 && nTranNum <= 0 && nBreakNum == 0)
			return 1;

		return 0;
	}


	int	PGGetTranRatio(tagPGBlock* pPGBlock, const int nWind, float& fTapRatio)
	{
		int		nVolt, nTranMid, nTapChanger;
		double	fTapDeviate;

		fTapRatio=1.0;

		if (pPGBlock->m_PowerTransformerArray[pPGBlock->m_TransformerWindingArray[nWind].nTran].nWindNum == 3)
		{
			int	nWindH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_TransformerWindingArray[nWind].nTran].nWindH;
			int	nWindM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_TransformerWindingArray[nWind].nTran].nWindM;

			nTranMid=(pPGBlock->m_TransformerWindingArray[nWindH].nNodeI == pPGBlock->m_TransformerWindingArray[nWindM].nNodeI || pPGBlock->m_TransformerWindingArray[nWindH].nNodeI == pPGBlock->m_TransformerWindingArray[nWindM].nNodeJ) ?
				pPGBlock->m_TransformerWindingArray[nWindH].nNodeI : pPGBlock->m_TransformerWindingArray[nWindH].nNodeJ;

			if (nTranMid == pPGBlock->m_TransformerWindingArray[nWind].nNodeJ)
			{
				nVolt=pPGBlock->m_TransformerWindingArray[nWind].nVoltI;
				nTapChanger=pPGBlock->m_TransformerWindingArray[nWind].nTapChangerI;
				if (nVolt < 0 || nTapChanger < 0)
					return 0;

				if (pPGBlock->m_TapChangerArray[nTapChanger].nTapMax < pPGBlock->m_TapChangerArray[nTapChanger].nTapMin ||
					pPGBlock->m_TransformerWindingArray[nWind].nTapI < pPGBlock->m_TapChangerArray[nTapChanger].nTapMin ||
					pPGBlock->m_TransformerWindingArray[nWind].nTapI > pPGBlock->m_TapChangerArray[nTapChanger].nTapMax)
					return 0;

				fTapDeviate= 1+(pPGBlock->m_TapChangerArray[nTapChanger].fTapStep/100.0f)*(pPGBlock->m_TransformerWindingArray[nWind].nTapI-pPGBlock->m_TapChangerArray[nTapChanger].nTapNom);
				fTapRatio=(float)(fTapDeviate*pPGBlock->m_TransformerWindingArray[nWind].fRatedkVI/pPGBlock->m_VoltageLevelArray[nVolt].nominalVoltage);
				if (fTapRatio < 0.8 || fTapRatio > 1.2)
				{
					//fTapRatio=1.0;
					return 0;
				}
			}
			else
			{
				nVolt=pPGBlock->m_TransformerWindingArray[nWind].nVoltJ;
				nTapChanger=pPGBlock->m_TransformerWindingArray[nWind].nTapChangerJ;
				if (nVolt < 0 || nTapChanger < 0)
					return 0;

				if (pPGBlock->m_TapChangerArray[nTapChanger].nTapMax <= pPGBlock->m_TapChangerArray[nTapChanger].nTapMin &&
					pPGBlock->m_TransformerWindingArray[nWind].nTapJ < pPGBlock->m_TapChangerArray[nTapChanger].nTapMin &&
					pPGBlock->m_TransformerWindingArray[nWind].nTapJ > pPGBlock->m_TapChangerArray[nTapChanger].nTapMax)
					return 0;

				fTapDeviate=1+(pPGBlock->m_TapChangerArray[nTapChanger].fTapStep/100.0f)*(pPGBlock->m_TransformerWindingArray[nWind].nTapJ-pPGBlock->m_TapChangerArray[nTapChanger].nTapNom);
				fTapRatio=(float)(fTapDeviate*pPGBlock->m_TransformerWindingArray[nWind].fRatedkVJ/pPGBlock->m_VoltageLevelArray[nVolt].nominalVoltage);
				if (fTapRatio < 0.8 || fTapRatio > 1.2)
				{
					//fTapRatio=1.0;
					return 0;
				}
			}
		}
		else
		{
			if (pPGBlock->m_TransformerWindingArray[nWind].fRatedkVI > pPGBlock->m_TransformerWindingArray[nWind].fRatedkVJ)
			{
				nVolt=pPGBlock->m_TransformerWindingArray[nWind].nVoltI;
				nTapChanger=pPGBlock->m_TransformerWindingArray[nWind].nTapChangerI;
				if (nVolt < 0 || nTapChanger < 0)
					return 0;

				if (pPGBlock->m_TapChangerArray[nTapChanger].nTapMax < pPGBlock->m_TapChangerArray[nTapChanger].nTapMin ||
					pPGBlock->m_TransformerWindingArray[nWind].nTapI < pPGBlock->m_TapChangerArray[nTapChanger].nTapMin ||
					pPGBlock->m_TransformerWindingArray[nWind].nTapI > pPGBlock->m_TapChangerArray[nTapChanger].nTapMax)
					return 0;

				fTapDeviate= 1+(pPGBlock->m_TapChangerArray[nTapChanger].fTapStep/100.0f)*(pPGBlock->m_TransformerWindingArray[nWind].nTapI-pPGBlock->m_TapChangerArray[nTapChanger].nTapNom);
				fTapRatio=(float)(fTapDeviate*pPGBlock->m_TransformerWindingArray[nWind].fRatedkVI/pPGBlock->m_VoltageLevelArray[nVolt].nominalVoltage);
				if (fTapRatio < 0.8 || fTapRatio > 1.2)
				{
					//fTapRatio=1.0;
					return 0;
				}
			}
			else
			{
				nVolt=pPGBlock->m_TransformerWindingArray[nWind].nVoltJ;
				nTapChanger=pPGBlock->m_TransformerWindingArray[nWind].nTapChangerJ;
				if (nVolt < 0 || nTapChanger < 0)
					return 0;

				if (pPGBlock->m_TapChangerArray[nTapChanger].nTapMax <= pPGBlock->m_TapChangerArray[nTapChanger].nTapMin &&
					pPGBlock->m_TransformerWindingArray[nWind].nTapJ < pPGBlock->m_TapChangerArray[nTapChanger].nTapMin &&
					pPGBlock->m_TransformerWindingArray[nWind].nTapJ > pPGBlock->m_TapChangerArray[nTapChanger].nTapMax)
					return 0;

				fTapDeviate=1+(pPGBlock->m_TapChangerArray[nTapChanger].fTapStep/100.0f)*(pPGBlock->m_TransformerWindingArray[nWind].nTapJ-pPGBlock->m_TapChangerArray[nTapChanger].nTapNom);
				fTapRatio=(float)(fTapDeviate*pPGBlock->m_TransformerWindingArray[nWind].fRatedkVJ/pPGBlock->m_VoltageLevelArray[nVolt].nominalVoltage);
				if (fTapRatio < 0.8 || fTapRatio > 1.2)
				{
					//fTapRatio=1.0;
					return 0;
				}
			}
		}

		return	1;
	}

	void PGGetParallelACLine(tagPGBlock* pPGBlock, const int nLine, const unsigned char bCheckStatus, int& nParaLineNum, int nParaLineArray[])
	{
		register int	i;
		int		nINode, nZNode;
		unsigned char	bInNode;
		int	nINodeNum, nINodeArray[1000];
		int	nZNodeNum, nZNodeArray[1000];

		nParaLineNum=0;
		PGTraverseVolt(pPGBlock, pPGBlock->m_ACLineSegmentArray[nLine].nNodeI, bCheckStatus, bCheckStatus, N_BusBound, N_BreakerBound, nINodeNum, nINodeArray);
		PGTraverseVolt(pPGBlock, pPGBlock->m_ACLineSegmentArray[nLine].nNodeJ, bCheckStatus, bCheckStatus, N_BusBound, N_BreakerBound, nZNodeNum, nZNodeArray);

		for (nINode=0; nINode<nINodeNum; nINode++)
		{
			for (i=pPGBlock->m_ConnectivityNodeArray[nINodeArray[nINode]].nACLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[nINodeArray[nINode]+1].nACLineSegmentRange; i++)
			{
				bInNode=0;
				for (nZNode=0; nZNode<nZNodeNum; nZNode++)
				{
					if (pPGBlock->m_ACLineSegmentArray[pPGBlock->m_EdgeACLineSegmentArray[i].nACLineSegment].nNodeI == nZNodeArray[nZNode] ||
						pPGBlock->m_ACLineSegmentArray[pPGBlock->m_EdgeACLineSegmentArray[i].nACLineSegment].nNodeJ == nZNodeArray[nZNode])
					{
						bInNode=1;
						break;
					}
				}
				if (bInNode)
					nParaLineArray[nParaLineNum++] = pPGBlock->m_EdgeACLineSegmentArray[i].nACLineSegment;
			}
		}
	}

	void PGGetParallelDCLine(tagPGBlock* pPGBlock, const int nLine, const unsigned char bCheckStatus, int& nParaLineNum, int nParaLineArray[])
	{
		register int	i;
		int		nINode, nZNode;
		unsigned char	bInNode;
		int	nINodeNum, nINodeArray[1000];
		int	nZNodeNum, nZNodeArray[1000];

		nParaLineNum=0;
		PGTraverseVolt(pPGBlock, pPGBlock->m_DCLineSegmentArray[nLine].nNodeI, bCheckStatus, bCheckStatus, N_BusBound, N_BreakerBound, nINodeNum, nINodeArray);
		PGTraverseVolt(pPGBlock, pPGBlock->m_DCLineSegmentArray[nLine].nNodeJ, bCheckStatus, bCheckStatus, N_BusBound, N_BreakerBound, nZNodeNum, nZNodeArray);

		for (nINode=0; nINode<nINodeNum; nINode++)
		{
			for (i=pPGBlock->m_ConnectivityNodeArray[nINodeArray[nINode]].nDCLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[nINodeArray[nINode]+1].nDCLineSegmentRange; i++)
			{
				bInNode=0;
				for (nZNode=0; nZNode<nZNodeNum; nZNode++)
				{
					if (pPGBlock->m_DCLineSegmentArray[pPGBlock->m_EdgeDCLineSegmentArray[i].nDCLineSegment].nNodeI == nZNodeArray[nZNode] ||
						pPGBlock->m_DCLineSegmentArray[pPGBlock->m_EdgeDCLineSegmentArray[i].nDCLineSegment].nNodeJ == nZNodeArray[nZNode])
					{
						bInNode=1;
						break;
					}
				}
				if (bInNode)
					nParaLineArray[nParaLineNum++] = pPGBlock->m_EdgeDCLineSegmentArray[i].nDCLineSegment;
			}
		}
	}

	int IntegerInIntArray(const int nInteger, int nLen, int nArray[])
	{
		register int	i;
		for (i=0; i<nLen; i++)
		{
			if (nInteger == nArray[i])
				return 1;
		}
		return 0;
	}

	void PGGetParallelTran(tagPGBlock* pPGBlock, const int nTran, const unsigned char bCheckStatus, int& nParaTranNum, int nParaTranArray[])
	{
		int		nSub, nDev;
		unsigned char	bHIn, bMIn, bLIn;
		int	nHNodeNum, nHNodeArray[1000];
		int	nMNodeNum, nMNodeArray[1000];
		int	nLNodeNum, nLNodeArray[1000];

		nParaTranNum=0;
		nParaTranArray[nParaTranNum++] = nTran;

		nSub = PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_PowerTransformerArray[nTran].szSub);
		if (nSub < 0)
			return;

		if (pPGBlock->m_PowerTransformerArray[nTran].nWindNum == 2)
		{
			PGTraverseSub(pPGBlock, pPGBlock->m_PowerTransformerArray[nTran].nNodeH, bCheckStatus, nHNodeNum, nHNodeArray);
			PGTraverseSub(pPGBlock, pPGBlock->m_PowerTransformerArray[nTran].nNodeL, bCheckStatus, nLNodeNum, nLNodeArray);

			for (nDev=pPGBlock->m_SubstationArray[nSub].nPowerTransformerRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nPowerTransformerRange; nDev++)
			{
				if (nDev == nTran)
					continue;

				bHIn = IntegerInIntArray(pPGBlock->m_PowerTransformerArray[nDev].nNodeH, nHNodeNum, nHNodeArray);
				bLIn = IntegerInIntArray(pPGBlock->m_PowerTransformerArray[nDev].nNodeL, nLNodeNum, nLNodeArray);
				if (bHIn && bLIn)
					nParaTranArray[nParaTranNum++] = nDev;
			}
		}
		else
		{
			PGTraverseSub(pPGBlock, pPGBlock->m_PowerTransformerArray[nTran].nNodeH, bCheckStatus, nHNodeNum, nHNodeArray);
			PGTraverseSub(pPGBlock, pPGBlock->m_PowerTransformerArray[nTran].nNodeM, bCheckStatus, nMNodeNum, nMNodeArray);
			PGTraverseSub(pPGBlock, pPGBlock->m_PowerTransformerArray[nTran].nNodeL, bCheckStatus, nLNodeNum, nLNodeArray);

			for (nDev=pPGBlock->m_SubstationArray[nSub].nPowerTransformerRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nPowerTransformerRange; nDev++)
			{
				if (nDev == nTran)
					continue;

				bHIn = IntegerInIntArray(pPGBlock->m_PowerTransformerArray[nDev].nNodeH, nHNodeNum, nHNodeArray);
				bMIn = IntegerInIntArray(pPGBlock->m_PowerTransformerArray[nDev].nNodeM, nMNodeNum, nMNodeArray);
				bLIn = IntegerInIntArray(pPGBlock->m_PowerTransformerArray[nDev].nNodeL, nLNodeNum, nLNodeArray);
				if (bHIn && bMIn && bLIn)
					nParaTranArray[nParaTranNum++] = nDev;
			}
		}
	}

	void	PGDataPtr2FieldArray(IN const int nTable, IN const char* lpszDataPtr, OUT char szField[][MDB_CHARLEN_LONG])
	{
		register int	i;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		int		nField, nFieldLen, nLen;

		if (nTable < 0 || nTable >= PGGetTableNum())
			return;

		for (i=0; i<MAXMDBFIELDNUM; i++)
			memset(szField[i], 0, MDB_CHARLEN_LONG);

		for (nField=0; nField<PGGetTableFieldNum(nTable); nField++)
		{
			nFieldLen=PGGetFieldLen(nTable, nField);
			switch (PGGetFieldType(nTable, nField))
			{
			case	MDB_STRING:
				nLen=(int)strlen(lpszDataPtr);
				if (nLen >= nFieldLen)
					nLen=( isascii(lpszDataPtr[nFieldLen-1]) ) ? nFieldLen-1 : nFieldLen-2;
				for (i=0; i<nLen; i++)
					szField[nField][i]=(char)lpszDataPtr[i];
				szField[nField][i]='\0';
				break;
			case	MDB_DOUBLE:
				memcpy(&dBuf, lpszDataPtr, nFieldLen);
				sprintf(szField[nField], "%lf", dBuf);
				break;
			case	MDB_FLOAT:
				memcpy(&fBuf, lpszDataPtr, nFieldLen);
				sprintf(szField[nField], "%f", fBuf);
				break;
			case	MDB_INT:
				memcpy(&nBuf, lpszDataPtr, nFieldLen);
				sprintf(szField[nField], "%d", nBuf);
				break;
			case	MDB_SHORT:
				memcpy(&sBuf, lpszDataPtr, nFieldLen);
				sprintf(szField[nField], "%d", sBuf);
				break;
			case	MDB_BIT:
				memcpy(&uBuf, lpszDataPtr, nFieldLen);
				sprintf(szField[nField], "%d", uBuf);
				break;
			case	MDB_CHAR:
				szField[nField][0]=(char)lpszDataPtr[0];
				break;
			}
			lpszDataPtr += nFieldLen;
		}
	}

	void	PGFieldArray2DataPtr(IN const int nTable, IN const char szField[][MDB_CHARLEN_LONG], OUT char* lpszDataPtr)
	{
		register int	i;
		int		nField;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		char*	lpszAddr;
		int		nFieldLen, nLen;

		if (nTable < 0 || nTable >= PGGetTableNum())
			return;

		for (nField=0; nField<PGGetTableFieldNum(nTable); nField++)
		{
			lpszAddr=lpszDataPtr;
			for (i=0; i<nField; i++)
				lpszAddr += PGGetFieldLen(nTable, i);

			switch (PGGetFieldType(nTable, nField))
			{
			case	MDB_STRING:
				nFieldLen=PGGetFieldLen(nTable, nField);
				nLen=(int)strlen(szField[nField]);
				if (nLen >= nFieldLen)
					nLen=(isascii(szField[nField][nFieldLen-1])) ? nFieldLen-1 : nFieldLen-2;
				for (i=0; i<nLen; i++)
					lpszAddr[i]=szField[nField][i];
				lpszAddr[i]='\0';
				break;
			case	MDB_DOUBLE:
				dBuf=atof(szField[nField]);
				memcpy(lpszAddr, &dBuf, sizeof(double));
				break;
			case	MDB_FLOAT:
				fBuf=(float)atof(szField[nField]);
				memcpy(lpszAddr, &fBuf, sizeof(float));
				break;
			case	MDB_INT:
				nBuf=atoi(szField[nField]);
				memcpy(lpszAddr, &nBuf, sizeof(int));
				break;
			case	MDB_SHORT:
				sBuf=(short)atoi(szField[nField]);
				memcpy(lpszAddr, &sBuf, sizeof(short));
				break;
			case	MDB_BIT:
				uBuf=(unsigned char)atoi(szField[nField]);
				memcpy(lpszAddr, &uBuf, sizeof(unsigned char));
				break;
			case	MDB_CHAR:
				lpszAddr[0]=szField[nField][0];
				break;
			}
		}
	}

	int	PGGetDataPtrFieldValue(IN const int nTable, IN const int nField, IN const char* lpszDataPtr, OUT char* lpszRetValue)
	{
		register int	i;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		int		nLen, nFieldLen;

		if (nTable < 0 || nTable >= PGGetTableNum())
			return 0;

		if (nField < 0 || nField >= PGGetTableFieldNum(nTable))
			return 0;

		nFieldLen=PGGetFieldLen(nTable, nField);
		for (i=0; i<nField; i++)
			lpszDataPtr += PGGetFieldLen(nTable, i);

		switch (PGGetFieldType(nTable, nField))
		{
		case	MDB_STRING:
			nLen=(int)strlen(lpszDataPtr);
			if (nLen >= nFieldLen)
				nLen=(isascii(lpszDataPtr[nFieldLen-1])) ? nFieldLen-1 : nFieldLen-2;
			for (i=0; i<nLen; i++)
				lpszRetValue[i]=(char)lpszDataPtr[i];
			lpszRetValue[i]='\0';
			break;
		case	MDB_DOUBLE:
			memcpy(&dBuf, lpszDataPtr, nFieldLen);
			sprintf(lpszRetValue, "%lf", dBuf);
			break;
		case	MDB_FLOAT:
			memcpy(&fBuf, lpszDataPtr, nFieldLen);
			sprintf(lpszRetValue, "%f", fBuf);
			break;
		case	MDB_INT:
			memcpy(&nBuf, lpszDataPtr, nFieldLen);
			sprintf(lpszRetValue, "%d", nBuf);
			break;
		case	MDB_SHORT:
			memcpy(&sBuf, lpszDataPtr, nFieldLen);
			sprintf(lpszRetValue, "%d", sBuf);
			break;
		case	MDB_BIT:
			memcpy(&uBuf, lpszDataPtr, nFieldLen);
			sprintf(lpszRetValue, "%d", uBuf);
			break;
		case	MDB_CHAR:
			lpszRetValue[0]=(char)lpszDataPtr[0];
			break;
		default:
			return 0;
			break;
		}
		return 1;
	}

	int	PGSetDataPtrFieldValue(IN const int nTable, IN const int nField, IN const char* lpszSetValue, OUT char* lpszDataPtr)
	{
		register int	i;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		int		nLen, nFieldLen;

		if (nTable < 0 || nTable >= PGGetTableNum())
			return 0;

		if (nField < 0 || nField >= PGGetTableFieldNum(nTable))
			return 0;

		for (i=0; i<nField; i++)
			lpszDataPtr += PGGetFieldLen(nTable, i);;
		switch (PGGetFieldType(nTable, nField))
		{
		case	MDB_STRING:
			nFieldLen=PGGetFieldLen(nTable, nField);
			nLen=(int)strlen(lpszSetValue);
			if (nLen >= nFieldLen)
				nLen=(isascii(lpszSetValue[nFieldLen-1])) ? nFieldLen-1 : nFieldLen-2;
			for (i=0; i<nLen; i++)
				lpszDataPtr[i]=lpszSetValue[i];
			lpszDataPtr[i]='\0';
			break;
		case	MDB_DOUBLE:
			dBuf=atof(lpszSetValue);
			memcpy(lpszDataPtr, &dBuf, sizeof(double));
			break;
		case	MDB_FLOAT:
			fBuf=(float)atof(lpszSetValue);
			memcpy(lpszDataPtr, &fBuf, sizeof(float));
			break;
		case	MDB_INT:
			nBuf=atoi(lpszSetValue);
			memcpy(lpszDataPtr, &nBuf, sizeof(int));
			break;
		case	MDB_SHORT:
			sBuf=(short)atoi(lpszSetValue);
			memcpy(lpszDataPtr, &sBuf, sizeof(short));
			break;
		case	MDB_BIT:
			uBuf=(unsigned char)atoi(lpszSetValue);
			memcpy(lpszDataPtr, &uBuf, sizeof(unsigned char));
			break;
		case	MDB_CHAR:
			lpszDataPtr[0]=lpszSetValue[0];
			break;
		default:
			return 0;
			break;
		}
		return 1;
	}

	int	PGGetDataPtrFieldString(const int nTable, const int nField, const char* lpszPGDataAddr, const unsigned char nFloatPoint, char* lpszRetValue)
	{
		register int	i;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		int		nLen, nFieldLen;
		char	szFormat[260];

		if (nTable < 0 || nTable >= PGGetTableNum())
			return 0;

		if (nField < 0 || nField >= PGGetTableFieldNum(nTable))
			return 0;

		char*	lpszAddr=(char*)lpszPGDataAddr;
		for (i=0; i<nField; i++)
			lpszAddr += PGGetFieldLen(nTable, i);
		switch (PGGetFieldType(nTable, nField))
		{
		case	MDB_STRING:
			nFieldLen=PGGetFieldLen(nTable, nField);
			nLen=(int)strlen(lpszAddr);
			if (nLen >= nFieldLen)
				nLen=(isascii(lpszAddr[nFieldLen-1])) ? nFieldLen-1 : nFieldLen-2;
			for (i=0; i<nLen; i++)
				lpszRetValue[i]=lpszAddr[i];
			lpszRetValue[i]='\0';
			break;
		case	MDB_DOUBLE:
			memcpy(&dBuf, lpszAddr, sizeof(double));
			if (nFloatPoint > 0)
			{
				sprintf(szFormat, "%%.%df", nFloatPoint);
				sprintf(lpszRetValue, szFormat, dBuf);
			}
			else
			{
				sprintf(lpszRetValue, "%lf", dBuf);
			}

			break;
		case	MDB_FLOAT:
			memcpy(&fBuf, lpszAddr, sizeof(float));
			if (nFloatPoint > 0)
			{
				sprintf(szFormat, "%%.%df", nFloatPoint);
				sprintf(lpszRetValue, szFormat, fBuf);
			}
			else
				sprintf(lpszRetValue, "%f", fBuf);
			break;
		case	MDB_INT:
			memcpy(&nBuf, lpszAddr, sizeof(int));
			sprintf(lpszRetValue, "%d", nBuf);
			if (PGGetFieldEnumNum(nTable, nField) > 0 && (nBuf >= 0 && nBuf < PGGetFieldEnumNum(nTable, nField)))
				strcpy(lpszRetValue, PGGetFieldEnumString(nTable, nField, nBuf));
			break;
		case	MDB_SHORT:
			memcpy(&sBuf, lpszAddr, sizeof(short));
			sprintf(lpszRetValue, "%d", sBuf);
			if (PGGetFieldEnumNum(nTable, nField) > 0 && (sBuf >= 0 && sBuf < PGGetFieldEnumNum(nTable, nField)))
				strcpy(lpszRetValue, PGGetFieldEnumString(nTable, nField, sBuf));
			break;
		case	MDB_BIT:
			memcpy(&uBuf, lpszAddr, sizeof(unsigned char));
			sprintf(lpszRetValue, "%d", uBuf);
			if (PGGetFieldEnumNum(nTable, nField) > 0 && (uBuf >= 0 && uBuf < PGGetFieldEnumNum(nTable, nField)))
				strcpy(lpszRetValue, PGGetFieldEnumString(nTable, nField, uBuf));
			break;
		case	MDB_CHAR:
			lpszRetValue[0]=lpszAddr[0];
			break;
		default:
			return 0;
			break;
		}
		return 1;
	}

	int	PGGetDataPtrFieldString(const int nTable, const int nField, const char* lpszPGDataAddr, char* lpszRetValue)
	{
		return PGGetDataPtrFieldString(nTable, nField, lpszPGDataAddr, 0, lpszRetValue);
	}

	int	PGSetDataPtrFieldString(const int nTable, const int nField, const char* lpszValue, char* lpszPGDataAddr)
	{
		register int	i;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		int		nLen, nFieldLen;

		if (nTable < 0 || nTable >= PGGetTableNum())
			return 0;

		if (nField < 0 || nField >= PGGetTableFieldNum(nTable))
			return 0;

		for (i=0; i<nField; i++)
			lpszPGDataAddr += PGGetFieldLen(nTable, i);
		switch (PGGetFieldType(nTable, nField))
		{
		case	MDB_STRING:
			nFieldLen=PGGetFieldLen(nTable, nField);
			nLen=(int)strlen(lpszValue);
			if (nLen >= nFieldLen)
				nLen=(isascii(lpszValue[nFieldLen-1])) ? nFieldLen-1 : nFieldLen-2;
			for (i=0; i<nLen; i++)
				lpszPGDataAddr[i]=lpszValue[i];
			lpszPGDataAddr[i]='\0';
			break;
		case	MDB_DOUBLE:
			dBuf=atof(lpszValue);
			memcpy(lpszPGDataAddr, &dBuf, sizeof(double));
			break;
		case	MDB_FLOAT:
			fBuf=(float)atof(lpszValue);
			memcpy(lpszPGDataAddr, &fBuf, sizeof(float));
			break;
		case	MDB_INT:
			if (PGGetFieldEnumNum(nTable, nField) > 0)
			{
				nBuf=PGGetFieldEnumValue(nTable, nField, lpszValue);
				if (nBuf < 0 || nBuf >= PGGetFieldEnumNum(nTable, nField))	nBuf=0;
			}
			else
				nBuf=atoi(lpszValue);
			memcpy(lpszPGDataAddr, &nBuf, sizeof(int));
			break;
		case	MDB_SHORT:
			if (PGGetFieldEnumNum(nTable, nField) > 0)
			{
				sBuf=(short)PGGetFieldEnumValue(nTable, nField, lpszValue);
				if (sBuf < 0 || sBuf >= PGGetFieldEnumNum(nTable, nField))	sBuf=0;
			}
			else
				sBuf=(short)atoi(lpszValue);
			memcpy(lpszPGDataAddr, &sBuf, sizeof(short));
			break;
		case	MDB_BIT:
			if (PGGetFieldEnumNum(nTable, nField) > 0)
			{
				uBuf=(unsigned char)PGGetFieldEnumValue(nTable, nField, lpszValue);
				if (uBuf < 0 || uBuf >= PGGetFieldEnumNum(nTable, nField))	uBuf=0;
			}
			else
				uBuf=(unsigned char)atoi(lpszValue);
			memcpy(lpszPGDataAddr, &uBuf, sizeof(unsigned char));
			break;
		case	MDB_CHAR:
			lpszPGDataAddr[0]=lpszValue[0];
			break;
		default:
			return 0;
			break;
		}
		return 1;
	}
}
