#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"

namespace	BpaMemDB
{
	void CBpaMemDBInterface::BpaTraverseNet(tagBpaBlock* pBpaBlock, const int nStartBus, const float fMinimalVolt, int& nACBusNum, int nACBusArray[])
	{
		register int	i, j;
		int		nDev, nBus;
		int		nBusNumOfLayer;
		std::vector<int> nMidBusArray;
		std::vector<unsigned char>	bBusUnProcArray;

		nACBusNum=0;
		if (fMinimalVolt > 0.0001)
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[nStartBus].fkV <= fMinimalVolt)
				return;
		}

		bBusUnProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			bBusUnProcArray[i]=1;

		nACBusArray[nACBusNum++]=nStartBus;
		bBusUnProcArray[nStartBus]=0;
		nBusNumOfLayer=0;
		while (1)
		{
			nMidBusArray.clear();
			for (i=nBusNumOfLayer; i<nACBusNum; i++)
			{
				if (nACBusArray[i] != nStartBus && pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]].nStatus != 0)
					continue;

				for (j=pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]].nEdgeACLineRange; j<pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]+1].nEdgeACLineRange; j++)
				{
					nDev=pBpaBlock->m_BpaDat_EdgeACLineArray[j].nACLinePtr;
					if (pBpaBlock->m_BpaDat_ACLineArray[nDev].nStatus != 0)
						continue;
					nBus=(nACBusArray[i] == pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus : pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus;
					if (bBusUnProcArray[nBus])
					{
						nMidBusArray.push_back(nBus);
						bBusUnProcArray[nBus]=0;
					}
				}
				for (j=pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]].nEdgeWindRange; j<pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]+1].nEdgeWindRange; j++)
				{
					nDev=pBpaBlock->m_BpaDat_EdgeWindArray[j].nWindPtr;
					if (pBpaBlock->m_BpaDat_WindArray[nDev].nStatus != 0)
						continue;
					if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard != 0)
						continue;
					nBus=(nACBusArray[i] == pBpaBlock->m_BpaDat_WindArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_WindArray[nDev].nZBus : pBpaBlock->m_BpaDat_WindArray[nDev].nIBus;
					if (bBusUnProcArray[nBus])
					{
						nMidBusArray.push_back(nBus);
						bBusUnProcArray[nBus]=0;
					}
				}
			}
			if (nMidBusArray.empty())
				break;
			nBusNumOfLayer=nACBusNum;
			for (i=0; i<(int)nMidBusArray.size(); i++)
				nACBusArray[nACBusNum++]=nMidBusArray[i];
		}

		nMidBusArray.clear();
		bBusUnProcArray.clear();
	}

	void CBpaMemDBInterface::BpaTraverseSub(tagBpaBlock* pBpaBlock, const int nStartBus, const double fZIL, int& nACBusNum, int nACBusArray[])
	{
		register int	i, j;
		int		nDev, nBus;
		int		nBusNumOfLayer;
		std::vector<int> nMidBusArray;
		double	fRX;
		std::vector<unsigned char>	bBusUnProcArray;

		nACBusNum=0;

		bBusUnProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			bBusUnProcArray[i]=1;

		nACBusArray[nACBusNum++]=nStartBus;
		bBusUnProcArray[nStartBus]=0;
		nBusNumOfLayer=0;
		while (1)
		{
			nMidBusArray.clear();
			for (i=nBusNumOfLayer; i<nACBusNum; i++)
			{
				if (nACBusArray[i] != nStartBus && pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]].nStatus != 0)
					continue;

				for (j=pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]].nEdgeACLineRange; j<pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]+1].nEdgeACLineRange; j++)
				{
					nDev=pBpaBlock->m_BpaDat_EdgeACLineArray[j].nACLinePtr;
					fRX=sqrt(pBpaBlock->m_BpaDat_ACLineArray[nDev].fR*pBpaBlock->m_BpaDat_ACLineArray[nDev].fR+pBpaBlock->m_BpaDat_ACLineArray[nDev].fX*pBpaBlock->m_BpaDat_ACLineArray[nDev].fX);
					if (fRX > fZIL)
						continue;
					if (pBpaBlock->m_BpaDat_ACLineArray[nDev].nStatus != 0)
						continue;

					nBus=(nACBusArray[i] == pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus : pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus;
					if (nBus < 0)	continue;
					if (bBusUnProcArray[nBus])
					{
						nMidBusArray.push_back(nBus);
						bBusUnProcArray[nBus]=0;
					}
				}
				for (j=pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]].nEdgeWindRange; j<pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]+1].nEdgeWindRange; j++)
				{
					nDev=pBpaBlock->m_BpaDat_EdgeWindArray[j].nWindPtr;
					if (pBpaBlock->m_BpaDat_WindArray[nDev].nStatus != 0)
						continue;
					if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard != 0)
						continue;
					nBus=(nACBusArray[i] == pBpaBlock->m_BpaDat_WindArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_WindArray[nDev].nZBus:pBpaBlock->m_BpaDat_WindArray[nDev].nIBus;
					if (nBus < 0)	continue;
					if (bBusUnProcArray[nBus])
					{
						nMidBusArray.push_back(nBus);
						bBusUnProcArray[nBus]=0;
					}
				}
			}
			if (nMidBusArray.empty())
				break;
			nBusNumOfLayer=nACBusNum;
			for (i=0; i<(int)nMidBusArray.size(); i++)
				nACBusArray[nACBusNum++]=nMidBusArray[i];
		}

		nMidBusArray.clear();
		bBusUnProcArray.clear();
	}

	void CBpaMemDBInterface::BpaTraverseVolt(tagBpaBlock* pBpaBlock, const int nStartBus, const float fMinVolt, int& nACBusNum, int nACBusArray[])
	{
		register int	i, j;
		int		nDev, nTran, nBus;
		int		nBusNumOfLayer;
		std::vector<int> nMidBusArray;
		std::vector<unsigned char>	bBusUnProcArray;

		nACBusNum=0;
		if (fMinVolt > 0.01)
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[nStartBus].fkV < fMinVolt)
				return;
		}

		bBusUnProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			bBusUnProcArray[i]=1;

		nACBusArray[nACBusNum++]=nStartBus;
		bBusUnProcArray[nStartBus]=0;
		nBusNumOfLayer=0;
		while (1)
		{
			nMidBusArray.clear();
			for (i=nBusNumOfLayer; i<nACBusNum; i++)
			{
				if (nACBusArray[i] != nStartBus && pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]].nStatus != 0)
					continue;

				for (j=pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]].nEdgeACLineRange; j<pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]+1].nEdgeACLineRange; j++)
				{
					nDev=pBpaBlock->m_BpaDat_EdgeACLineArray[j].nACLinePtr;
					if (pBpaBlock->m_BpaDat_ACLineArray[nDev].nStatus != 0)
						continue;
					nBus=(nACBusArray[i] == pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus : pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus;
					if (pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV >= fMinVolt && bBusUnProcArray[nBus])
					{
						nMidBusArray.push_back(nBus);
						bBusUnProcArray[nBus]=0;
					}
				}
				for (j=pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]].nEdgeWindRange; j<pBpaBlock->m_BpaDat_ACBusArray[nACBusArray[i]+1].nEdgeWindRange; j++)
				{
					nDev=pBpaBlock->m_BpaDat_EdgeWindArray[j].nWindPtr;
					if (pBpaBlock->m_BpaDat_WindArray[nDev].nStatus != 0)
						continue;
					if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard != 0)
						continue;

					nTran = pBpaBlock->m_BpaDat_WindArray[nDev].nTran;
					if (pBpaBlock->m_BpaDat_TranArray[nTran].nWindNum > 1)
					{
						if (pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH >= 0)
						{
							nBus=pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus;
							if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bTMid)
								nBus=pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus;
							if (pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV >= fMinVolt && bBusUnProcArray[nBus])
							{
								nMidBusArray.push_back(nBus);
								bBusUnProcArray[nBus]=0;
							}
						}
						if (pBpaBlock->m_BpaDat_TranArray[nTran].iRWindM >= 0)
						{
							nBus=pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindM].nIBus;
							if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bTMid)
								nBus=pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindM].nZBus;
							if (pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV >= fMinVolt && bBusUnProcArray[nBus])
							{
								nMidBusArray.push_back(nBus);
								bBusUnProcArray[nBus]=0;
							}
						}
						if (pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL >= 0)
						{
							nBus=pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nIBus;
							if (pBpaBlock->m_BpaDat_ACBusArray[nBus].bTMid)
								nBus=pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nZBus;
							if (pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV >= fMinVolt && bBusUnProcArray[nBus])
							{
								nMidBusArray.push_back(nBus);
								bBusUnProcArray[nBus]=0;
							}
						}
					}
					else
					{
						nBus=(nACBusArray[i] == pBpaBlock->m_BpaDat_WindArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_WindArray[nDev].nZBus : pBpaBlock->m_BpaDat_WindArray[nDev].nIBus;
						if (pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV >= fMinVolt && bBusUnProcArray[nBus])
						{
							nMidBusArray.push_back(nBus);
							bBusUnProcArray[nBus]=0;
						}
					}
				}
			}
			if (nMidBusArray.empty())
				break;
			nBusNumOfLayer=nACBusNum;
			for (i=0; i<(int)nMidBusArray.size(); i++)
				nACBusArray[nACBusNum++]=nMidBusArray[i];
		}

		nMidBusArray.clear();
		bBusUnProcArray.clear();
	}

	void CBpaMemDBInterface::BpaIsland(tagBpaBlock* pBpaBlock)
	{
		register int	i;
		int		nBus, nBusNum, *pnBusArray;
		double	fIslandGen;
		std::vector<unsigned char>	bProcArray;

		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();

		pnBusArray=(int*)malloc(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]*sizeof(int));
		if (pnBusArray == NULL)
			return;

		pBpaBlock->m_BpaDat_Case.nIslandNum=1;
		bProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<(int)bProcArray.size(); i++)
			bProcArray[i]=0;
		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
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

			if (fIslandGen > FLT_MIN)
			{
				for (i=0; i<nBusNum; i++)
					pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].nACIsland=pBpaBlock->m_BpaDat_Case.nIslandNum;
				pBpaBlock->m_BpaDat_Case.nIslandNum++;
			}
			else
			{
				for (i=0; i<nBusNum; i++)
					pBpaBlock->m_BpaDat_ACBusArray[pnBusArray[i]].nACIsland=0;
			}
		}

		if (pnBusArray)
		{
			free(pnBusArray);
			pnBusArray=NULL;
		}

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
		{
			if (pBpaBlock->m_BpaDat_WindArray[i].bRCard == 0)
				continue;

			if (pBpaBlock->m_BpaDat_WindArray[i].bRCard == 1)
				pBpaBlock->m_BpaDat_DCBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].nACIsland = pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].nACIsland;
			else if (pBpaBlock->m_BpaDat_WindArray[i].bRCard == 2)
				pBpaBlock->m_BpaDat_DCBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].nACIsland = pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].nACIsland;
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "电岛完成，合计%d电岛，耗时%d毫秒\n", pBpaBlock->m_BpaDat_Case.nIslandNum, nDur);
	}
}
