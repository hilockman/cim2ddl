#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"

namespace	BpaMemDB
{
	void BpaTraverseNet(tagBpaBlock* pBpaBlock, const int nStartBus, const float fMinimalVolt, int& nBusNum, int nBusArray[])
	{
		register int	i, j;
		int		nDev, nBus;
		int		nBusNumOfLayer;
		std::vector<int> nMidBusArray;
		std::vector<unsigned char>	bBusUnProcArray;

		nBusNum=0;
		if (fMinimalVolt > 0.0001)
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[nStartBus].fkV <= fMinimalVolt)
				return;
		}

		bBusUnProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			bBusUnProcArray[i]=1;

		nBusArray[nBusNum++]=nStartBus;
		bBusUnProcArray[nStartBus]=0;
		nBusNumOfLayer=0;
		while (1)
		{
			nMidBusArray.clear();
			for (i=nBusNumOfLayer; i<nBusNum; i++)
			{
				if (nBusArray[i] != nStartBus && pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].nStatus != 0)
					continue;

				for (j=pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].nACLineRange; j<pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]+1].nACLineRange; j++)
				{
					nDev=pBpaBlock->m_BpaDat_EdgeLineArray[j].iRLine;;
					if (pBpaBlock->m_BpaDat_ACLineArray[nDev].nStatus != 0)
						continue;
					nBus=(nBusArray[i] == pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus : pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus;
					if (bBusUnProcArray[nBus])
					{
						nMidBusArray.push_back(nBus);
						bBusUnProcArray[nBus]=0;
					}
				}
				for (j=pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].nWindRange; j<pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]+1].nWindRange; j++)
				{
					nDev=pBpaBlock->m_BpaDat_EdgeWindArray[j].iRWind;;
					if (pBpaBlock->m_BpaDat_WindArray[nDev].nStatus != 0)
						continue;
					nBus=(nBusArray[i] == pBpaBlock->m_BpaDat_WindArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_WindArray[nDev].nZBus : pBpaBlock->m_BpaDat_WindArray[nDev].nIBus;
					if (bBusUnProcArray[nBus])
					{
						nMidBusArray.push_back(nBus);
						bBusUnProcArray[nBus]=0;
					}
				}
			}
			if (nMidBusArray.empty())
				break;
			nBusNumOfLayer=nBusNum;
			for (i=0; i<(int)nMidBusArray.size(); i++)
				nBusArray[nBusNum++]=nMidBusArray[i];
		}

		nMidBusArray.clear();
		bBusUnProcArray.clear();
	}

	void BpaTraverseSub(tagBpaBlock* pBpaBlock, const int nStartBus, const double fZIL, int& nBusNum, int nBusArray[])
	{
		register int	i, j;
		int		nDev, nBus;
		int		nBusNumOfLayer;
		std::vector<int> nMidBusArray;
		double	fRX;
		std::vector<unsigned char>	bBusUnProcArray;

		nBusNum=0;

		bBusUnProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			bBusUnProcArray[i]=1;

		nBusArray[nBusNum++]=nStartBus;
		bBusUnProcArray[nStartBus]=0;
		nBusNumOfLayer=0;
		while (1)
		{
			nMidBusArray.clear();
			for (i=nBusNumOfLayer; i<nBusNum; i++)
			{
				if (nBusArray[i] != nStartBus && pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].nStatus != 0)
					continue;

				for (j=pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].nACLineRange; j<pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]+1].nACLineRange; j++)
				{
					nDev=pBpaBlock->m_BpaDat_EdgeLineArray[j].iRLine;;
					fRX=sqrt(pBpaBlock->m_BpaDat_ACLineArray[nDev].fR*pBpaBlock->m_BpaDat_ACLineArray[nDev].fR+pBpaBlock->m_BpaDat_ACLineArray[nDev].fX*pBpaBlock->m_BpaDat_ACLineArray[nDev].fX);
					if (fRX > fZIL)
						continue;
					if (pBpaBlock->m_BpaDat_ACLineArray[nDev].nStatus != 0)
						continue;

					nBus=(nBusArray[i] == pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus : pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus;
					if (nBus < 0)	continue;
					if (bBusUnProcArray[nBus])
					{
						nMidBusArray.push_back(nBus);
						bBusUnProcArray[nBus]=0;
					}
				}
				for (j=pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].nWindRange; j<pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]+1].nWindRange; j++)
				{
					nDev=pBpaBlock->m_BpaDat_EdgeWindArray[j].iRWind;;
					if (pBpaBlock->m_BpaDat_WindArray[nDev].nStatus != 0)
						continue;
					nBus=(nBusArray[i] == pBpaBlock->m_BpaDat_WindArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_WindArray[nDev].nZBus:pBpaBlock->m_BpaDat_WindArray[nDev].nIBus;
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
			nBusNumOfLayer=nBusNum;
			for (i=0; i<(int)nMidBusArray.size(); i++)
				nBusArray[nBusNum++]=nMidBusArray[i];
		}

		nMidBusArray.clear();
		bBusUnProcArray.clear();
	}

	void	BpaIsland(tagBpaBlock* pBpaBlock)
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
