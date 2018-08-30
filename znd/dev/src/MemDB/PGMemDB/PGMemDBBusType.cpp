#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

namespace	PGMemDB
{
	//	旁路判断原则：
	//		1、跨过刀闸直接连设备
	//		2、跨过刀闸连接的开关必然是不连设备的开关
	//		3、旁母连接的设备只能通过刀闸连接旁母，而不能连接其他母线。
	//		4、设备不能只连接一条母线
	int PGIsBypassBus(tagPGBlock* pPGBlock, const int nVolt, const int nBus)
	{
		register int	i, j;
		int		nDev, nNode, nOppNode, nDevNum, nOppDevNum, nBreakerNum;
		int		nNodeNum, nNodeArray[200];

		if (PGIsVolt32(pPGBlock, nVolt))
			return 0;
		if (pPGBlock->m_BusbarSectionArray[nBus].nNode < 0)
			return 0;
		if (pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange-pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange < 2)
			return 0;
		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[nBus].nNode+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[nBus].nNode].nACLineSegmentRange > 0)
			return 0;
		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[nBus].nNode+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[nBus].nNode].nTransformerWindingRange > 0)
			return 0;
		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[nBus].nNode+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[nBus].nNode].nBreakerRange > 0)
			return 0;

		nDevNum=0;
		nOppDevNum=nBreakerNum=0;
		for (i=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[nBus].nNode].nDisconnectorRange; i<pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[nBus].nNode+1].nDisconnectorRange; i++)
		{
			nDev=pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector;
			nOppNode=(pPGBlock->m_DisconnectorArray[nDev].nNodeI == pPGBlock->m_BusbarSectionArray[nBus].nNode) ? pPGBlock->m_DisconnectorArray[nDev].nNodeJ : pPGBlock->m_DisconnectorArray[nDev].nNodeI;

			if (pPGBlock->m_ConnectivityNodeArray[nOppNode+1].nACLineSegmentRange > pPGBlock->m_ConnectivityNodeArray[nOppNode].nACLineSegmentRange)
			{
				nOppDevNum += pPGBlock->m_ConnectivityNodeArray[nOppNode+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nOppNode].nACLineSegmentRange;
				PGTraverseVolt(pPGBlock, nOppNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);
				nBreakerNum=0;
				for (nNode=0; nNode<nNodeNum; nNode++)
					nBreakerNum += pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nBreakerRange;

				if (nBreakerNum <= 0)
					return 0;
			}
			for (j=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; j++)
			{
				if (pPGBlock->m_EnergyConsumerArray[j].nNode == nOppNode)
				{
					nOppDevNum++;
					PGTraverseVolt(pPGBlock, nOppNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);
					nBreakerNum=0;
					for (nNode=0; nNode<nNodeNum; nNode++)
						nBreakerNum += pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nBreakerRange;

					if (nBreakerNum <= 0)
						return 0;
				}
			}
		}
		if (nOppDevNum > 0)// && nBreakerNum <= 0)
			return 1;

		return 0;
	}

	void	PGFormBusbarSectionType(tagPGBlock* pPGBlock)
	{
		register int	i;
		int		nSub, nVolt;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_BUSBARSECTION]; i++)
			pPGBlock->m_BusbarSectionArray[i].bBypass=0;
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (i=pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange; i++)
				{
					if (pPGBlock->m_BusbarSectionArray[i].nNode < 0)
						continue;
					if (PGIsBypassBus(pPGBlock, nVolt, i))
						pPGBlock->m_BusbarSectionArray[i].bBypass = 1;
				}
			}
		}
	}
}