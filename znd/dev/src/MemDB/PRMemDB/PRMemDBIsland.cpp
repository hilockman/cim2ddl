#include "stdafx.h"
#include <float.h>
#include "PRMemDB.h"
#include "PRMemDBExtern.h"

namespace PRMemDB
{
	//	只能内部使用，因为使用了STL
	void	CPRMemDBInterface::PRTraverseACNet(tagPRBlock* pPRBlock, const unsigned char bRingIslandOnly, const int nStartBus, std::vector<int>& nJointBusArray)
	{
		register int	i, j;
		int	nBus, nBran, nLayerBusNum;
		std::vector<int>	nMidBusArray;
		std::vector<unsigned char>	bBusProcArray;

		nJointBusArray.clear();
		nJointBusArray.push_back(nStartBus);

		bBusProcArray.resize(pPRBlock->m_nRecordNum[PR_ACBUS]);
		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
			bBusProcArray[i]=0;
		bBusProcArray[nStartBus]=1;

		nLayerBusNum=0;
		while (1)
		{
			nMidBusArray.clear();
			for (i=nLayerBusNum; i<(int)nJointBusArray.size(); i++)
			{
				for (j=pPRBlock->m_ACBusArray[nJointBusArray[i]].nLineRange; j<pPRBlock->m_ACBusArray[nJointBusArray[i]+1].nLineRange; j++)
				{
					nBran=pPRBlock->m_ACLineEdgeArray[j].nLine;
					if (pPRBlock->m_ACLineArray[nBran].bOutage)
						continue;
					if (bRingIslandOnly && (pPRBlock->m_ACLineArray[nBran].nIRadial != 0 || pPRBlock->m_ACLineArray[nBran].nZRadial != 0))
						continue;

					nBus=(nJointBusArray[i] == pPRBlock->m_ACLineArray[nBran].nIBus) ? abs(pPRBlock->m_ACLineArray[nBran].nZBus) : pPRBlock->m_ACLineArray[nBran].nIBus;
					if (nBus < 0)
						continue;

					if (!bBusProcArray[nBus])
					{
						nMidBusArray.push_back(nBus);
						bBusProcArray[nBus]=1;
					}
				}
				for (j=pPRBlock->m_ACBusArray[nJointBusArray[i]].nTranRange; j<pPRBlock->m_ACBusArray[nJointBusArray[i]+1].nTranRange; j++)
				{
					nBran=pPRBlock->m_ACWindEdgeArray[j].nTran;
					if (pPRBlock->m_WindArray[nBran].bOutage)
						continue;
					if (bRingIslandOnly && (pPRBlock->m_WindArray[nBran].nIRadial != 0 || pPRBlock->m_WindArray[nBran].nZRadial != 0))
						continue;

					nBus=(nJointBusArray[i] == pPRBlock->m_WindArray[nBran].nIBus) ? abs(pPRBlock->m_WindArray[nBran].nZBus) : pPRBlock->m_WindArray[nBran].nIBus;
					if (nBus < 0)
						continue;

					if (!bBusProcArray[nBus])
					{
						nMidBusArray.push_back(nBus);
						bBusProcArray[nBus]=1;
					}
				}
			}
			if (nMidBusArray.empty())
				break;
			nLayerBusNum=(int)nJointBusArray.size();
			for (i=0; i<(int)nMidBusArray.size(); i++)
				nJointBusArray.push_back(nMidBusArray[i]);
		}

		bBusProcArray.clear();
		nMidBusArray.clear();
	}

	void CPRMemDBInterface::PRMemDBIsland(tagPRBlock* pPRBlock, const unsigned char bRingIslandOnly)
	{
		register int	i;
		int		nBus, nDev, nBran;
		std::vector<int>			nJointBusArray;
		std::vector<unsigned char>	bBusProcArray;

		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
			pPRBlock->m_ACBusArray[i].nIsland=0;
		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
			pPRBlock->m_ACLineArray[i].nIsland=0;
		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_WIND]; i++)
			pPRBlock->m_WindArray[i].nIsland=0;
		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_HVDC]; i++)
		{
			pPRBlock->m_HVDCArray[i].nIslandR=0;
			pPRBlock->m_HVDCArray[i].nIslandI=0;
		}

		pPRBlock->m_nRecordNum[PR_ACISLAND]=0;
		memset(&pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]], 0, sizeof(tagPRACIsland));
		pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]].bDead=1;
		pPRBlock->m_nRecordNum[PR_ACISLAND]++;

		bBusProcArray.resize(pPRBlock->m_nRecordNum[PR_ACBUS]);
		for (i=0; i<(int)bBusProcArray.size(); i++)
			bBusProcArray[i]=0;
		for (nBus=0; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
		{
			if (bRingIslandOnly && pPRBlock->m_ACBusArray[nBus].nRadial != 0)
				continue;
			if (bBusProcArray[nBus])
				continue;
			if (pPRBlock->m_ACBusArray[nBus+1].nLineRange-pPRBlock->m_ACBusArray[nBus].nLineRange <= 0 &&
				pPRBlock->m_ACBusArray[nBus+1].nTranRange-pPRBlock->m_ACBusArray[nBus].nTranRange <= 0)
				continue;

			memset(&pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]], 0, sizeof(tagPRACIsland));
			pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]].fGenP=pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]].fLoadP=0;
			pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]].bDead=0;
			PRTraverseACNet(pPRBlock, bRingIslandOnly, nBus, nJointBusArray);
			for (i=0; i<(int)nJointBusArray.size(); i++)
			{
				pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]].nBusNum++;
				pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]].fGenP += pPRBlock->m_ACBusArray[nJointBusArray[i]].fGenP+pPRBlock->m_ACBusArray[nJointBusArray[i]].fAdjGenP+pPRBlock->m_ACBusArray[nJointBusArray[i]].fRadP;
				pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]].fLoadP += pPRBlock->m_ACBusArray[nJointBusArray[i]].fLoadP+pPRBlock->m_ACBusArray[nJointBusArray[i]].fAdjLoadP;
				if (pPRBlock->m_ACBusArray[nJointBusArray[i]].bSlack)
				{
					pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]].nSwingBus = nJointBusArray[i];
					if (pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]].fGenP < FLT_MIN)
						pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]].fGenP += 1000;
				}
			}
			if (fabs(pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]].fGenP) < FLT_MIN)
				pPRBlock->m_ACIslandArray[pPRBlock->m_nRecordNum[PR_ACISLAND]].bDead=1;

			for (i=0; i<(int)nJointBusArray.size(); i++)
			{
				bBusProcArray[nJointBusArray[i]]=1;

#ifdef	_DEBUG
				if (pPRBlock->m_ACBusArray[nJointBusArray[i]].nIsland != 0)
					PRMemDBLog("母线[%d]已经属于其他岛，[%s] = %d\n", nJointBusArray[i], pPRBlock->m_ACBusArray[nJointBusArray[i]].szName, pPRBlock->m_ACBusArray[nJointBusArray[i]].nIsland);
#endif
				pPRBlock->m_ACBusArray[nJointBusArray[i]].nIsland=(short)pPRBlock->m_nRecordNum[PR_ACISLAND];

				for (nDev=pPRBlock->m_ACBusArray[nJointBusArray[i]].nLineRange; nDev<pPRBlock->m_ACBusArray[nJointBusArray[i]+1].nLineRange; nDev++)
				{
					nBran=pPRBlock->m_ACLineEdgeArray[nDev].nLine;
					if (pPRBlock->m_ACLineArray[nBran].bOutage)
						continue;

#ifdef	_DEBUG
					if (pPRBlock->m_ACLineArray[nBran].nIsland != 0 && pPRBlock->m_ACLineArray[nBran].nIsland != pPRBlock->m_nRecordNum[PR_ACISLAND])
						PRMemDBLog("线路[%d]已经属于其他岛，[%s] = %d\n", nBran, pPRBlock->m_ACLineArray[nBran].szName, pPRBlock->m_ACLineArray[nBran].nIsland);
#endif
					pPRBlock->m_ACLineArray[nBran].nIsland=(short)pPRBlock->m_nRecordNum[PR_ACISLAND];
				}
				for (nDev=pPRBlock->m_ACBusArray[nJointBusArray[i]].nTranRange; nDev<pPRBlock->m_ACBusArray[nJointBusArray[i]+1].nTranRange; nDev++)
				{
					nBran=pPRBlock->m_ACWindEdgeArray[nDev].nTran;
					if (pPRBlock->m_WindArray[nBran].bOutage)
						continue;

#ifdef	_DEBUG
					if (pPRBlock->m_WindArray[nBran].nIsland != 0 && pPRBlock->m_WindArray[nBran].nIsland != pPRBlock->m_nRecordNum[PR_ACISLAND])
						PRMemDBLog("变压器[%d]已经属于其他岛，[%s] = %d\n", nBran, pPRBlock->m_WindArray[nBran].szName, pPRBlock->m_WindArray[nBran].nIsland);
#endif
					pPRBlock->m_WindArray[nBran].nIsland=(short)pPRBlock->m_nRecordNum[PR_ACISLAND];
				}
			}
			pPRBlock->m_nRecordNum[PR_ACISLAND]++;
		}

		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_HVDC]; i++)
		{
			pPRBlock->m_HVDCArray[i].nIslandR=pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[i].nRBus].nIsland;
			pPRBlock->m_HVDCArray[i].nIslandI=pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[i].nIBus].nIsland;

			pPRBlock->m_ACIslandArray[pPRBlock->m_HVDCArray[i].nIslandR].fHVDCP += pPRBlock->m_HVDCArray[i].fPr;
			pPRBlock->m_ACIslandArray[pPRBlock->m_HVDCArray[i].nIslandI].fHVDCP += pPRBlock->m_HVDCArray[i].fPi;
		}

		nJointBusArray.clear();
		bBusProcArray.clear();
	}

	void	CPRMemDBInterface::PRTraverseRadial(tagPRBlock* pPRBlock, const int nRadial, int& nBusNum, int* pnBusArray)
	{
		register int	i, j;
		int		nStartBus;
		int		nBus, nBran, nLayerBusNum;
		std::vector<int>	nMidBusArray;
		std::vector<unsigned char>	bBusProcArray;

		nBusNum=0;
		nStartBus=pPRBlock->m_RadialArray[nRadial].nRingBoundBus;
		if (nStartBus < 0)
			return;

		nBusNum=0;
		pnBusArray[nBusNum++]=nStartBus;

		bBusProcArray.resize(pPRBlock->m_nRecordNum[PR_ACBUS]);
		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
			bBusProcArray[i]=0;
		bBusProcArray[nStartBus]=1;

		nLayerBusNum=0;
		while (1)
		{
			nMidBusArray.clear();
			for (i=nLayerBusNum; i<nBusNum; i++)
			{
				for (j=pPRBlock->m_ACBusArray[pnBusArray[i]].nLineRange; j<pPRBlock->m_ACBusArray[pnBusArray[i]+1].nLineRange; j++)
				{
					nBran=pPRBlock->m_ACLineEdgeArray[j].nLine;
					if (pPRBlock->m_ACLineArray[nBran].bOutage)
						continue;

					nBus=(pnBusArray[i] == pPRBlock->m_ACLineArray[nBran].nIBus) ? abs(pPRBlock->m_ACLineArray[nBran].nZBus) : pPRBlock->m_ACLineArray[nBran].nIBus;
					if (nBus < 0)
						continue;

					if (pPRBlock->m_ACBusArray[nBus].nRadial != nRadial)
						continue;
					if (!bBusProcArray[nBus])
					{
						nMidBusArray.push_back(nBus);
						bBusProcArray[nBus]=1;
					}
				}
				for (j=pPRBlock->m_ACBusArray[pnBusArray[i]].nTranRange; j<pPRBlock->m_ACBusArray[pnBusArray[i]+1].nTranRange; j++)
				{
					nBran=pPRBlock->m_ACWindEdgeArray[j].nTran;
					if (pPRBlock->m_WindArray[nBran].bOutage)
						continue;

					nBus=(pnBusArray[i] == pPRBlock->m_WindArray[nBran].nIBus) ? abs(pPRBlock->m_WindArray[nBran].nZBus) : pPRBlock->m_WindArray[nBran].nIBus;
					if (nBus < 0)
						continue;

					if (pPRBlock->m_ACBusArray[nBus].nRadial != nRadial)
						continue;
					if (!bBusProcArray[nBus])
					{
						nMidBusArray.push_back(nBus);
						bBusProcArray[nBus]=1;
					}
				}
			}
			if (nMidBusArray.empty())
				break;
			nLayerBusNum=nBusNum;
			for (i=0; i<(int)nMidBusArray.size(); i++)
				pnBusArray[nBusNum++]=nMidBusArray[i];
		}

		nMidBusArray.clear();
		bBusProcArray.clear();
	}
}
