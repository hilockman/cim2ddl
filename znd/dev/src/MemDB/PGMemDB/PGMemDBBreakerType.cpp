#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

namespace	PGMemDB
{
	void	FormBrswInnerType_Volt32(tagPGBlock* pPGBlock, const int nVolt)
	{
		register int	i, j;
		int		nNode, nDev;
		int		nBreakNum;
		int		nIBusNum, nIBreakNum;
		int		nZBusNum, nZBreakNum;
		int		nINodeNum, nINodeArray[1000];
		int		nZNodeNum, nZNodeArray[1000];

		for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nBreakerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nBreakerRange; nDev++)
			pPGBlock->m_BreakerArray[nDev].nInnerType = PGEnum_BreakerInnerType_Br32;
		for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nDisconnectorRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nDisconnectorRange; nDev++)
			pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_Sw32;

		for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nBreakerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nBreakerRange; nDev++)
		{
			PGTraverseVolt(pPGBlock, pPGBlock->m_BreakerArray[nDev].nNodeI, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nINodeNum, nINodeArray);
			nIBusNum=nIBreakNum=0;
			for (i=0; i<nINodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBusbarSectionPtr >= 0)
				{
					nIBusNum++;
					continue;
				}
				nIBreakNum += pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBreakerRange;
			}
			if (nIBusNum > 1 || nIBusNum <= 0)
				continue;
			if (nIBreakNum > 1)
				continue;

			PGTraverseVolt(pPGBlock, pPGBlock->m_BreakerArray[nDev].nNodeJ, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nZNodeNum, nZNodeArray);
			nZBusNum=nZBreakNum=0;
			for (i=0; i<nZNodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nBusbarSectionPtr >= 0)
					nZBusNum++;
				nZBreakNum += pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nBreakerRange;
			}
			if (nZBusNum > 1 || nZBusNum <= 0)
				continue;
			if (nZBreakNum > 1)
				continue;

			pPGBlock->m_BreakerArray[nDev].nInnerType=PGEnum_BreakerInnerType_BrBus;
			for (i=0; i<nINodeNum; i++)
			{
				for (j=pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nDisconnectorRange; j++)
					pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType=PGEnum_DisconnectorInnerType_SwBuslink;
			}
			for (i=0; i<nZNodeNum; i++)
			{
				for (j=pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]+1].nDisconnectorRange; j++)
					pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType=PGEnum_DisconnectorInnerType_SwBuslink;
			}
		}

		for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; nDev++)
		{
			if (pPGBlock->m_EnergyConsumerArray[nDev].nNode < 0)	continue;
			if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[nDev].nNode].nBusbarSectionPtr >= 0)	continue;

			nBreakNum=0;
			PGTraverseVolt(pPGBlock, pPGBlock->m_EnergyConsumerArray[nDev].nNode, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nINodeNum, nINodeArray);
			for (i=0; i<nINodeNum; i++)
				nBreakNum += pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBreakerRange;

			if (nBreakNum == 1)
			{
				for (i=0; i<nINodeNum; i++)
				{
					for (j=pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nBreakerRange; j++)
						pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[j].nBreaker].nInnerType = PGEnum_BreakerInnerType_BrLnXf;
					for (j=pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nDisconnectorRange; j++)
						pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType = PGEnum_DisconnectorInnerType_SwLnXf;
				}
			}
		}

		for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; nDev++)
		{
			if (pPGBlock->m_ShuntCompensatorArray[nDev].nNode < 0)	continue;

			nBreakNum=0;
			PGTraverseVolt(pPGBlock, pPGBlock->m_ShuntCompensatorArray[nDev].nNode, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nINodeNum, nINodeArray);
			for (i=0; i<nINodeNum; i++)
				nBreakNum += pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBreakerRange;

			if (nBreakNum == 1)
			{
				for (i=0; i<nINodeNum; i++)
				{
					for (j=pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nBreakerRange; j++)
						pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[j].nBreaker].nInnerType = PGEnum_BreakerInnerType_BrLnXf;
					for (j=pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nDisconnectorRange; j++)
						pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType = PGEnum_DisconnectorInnerType_SwLnXf;
				}
			}
		}

		for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
		{
			for (nDev=pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange; nDev<pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange; nDev++)
			{
				nBreakNum=0;
				PGTraverseVolt(pPGBlock, nNode, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nINodeNum, nINodeArray);
				for (i=0; i<nINodeNum; i++)
					nBreakNum += pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBreakerRange;

				if (nBreakNum == 1)
				{
					for (i=0; i<nINodeNum; i++)
					{
						for (j=pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nBreakerRange; j++)
							pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[j].nBreaker].nInnerType = PGEnum_BreakerInnerType_BrLnXf;
						for (j=pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nDisconnectorRange; j++)
							pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType = PGEnum_DisconnectorInnerType_SwLnXf;
					}
				}
			}
		}

		for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
		{
			for (nDev=pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange; nDev<pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange; nDev++)
			{
				nBreakNum=0;
				PGTraverseVolt(pPGBlock, nNode, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nINodeNum, nINodeArray);
				for (i=0; i<nINodeNum; i++)
					nBreakNum += pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBreakerRange;

				if (nBreakNum == 1)
				{
					for (i=0; i<nINodeNum; i++)
					{
						for (j=pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nBreakerRange; j++)
							pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[j].nBreaker].nInnerType = PGEnum_BreakerInnerType_BrLnXf;
						for (j=pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nDisconnectorRange; j++)
							pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType = PGEnum_DisconnectorInnerType_SwLnXf;
					}
				}
			}
		}
	}

	void	FormBrswInnerType_DevBrsw(tagPGBlock* pPGBlock, const int nVolt)
	{
		register int	i, j, k;
		int		nNode, nDev;
		unsigned char	bFlag;
		int		nBreakNum;
		int		nNodeNum, nNodeArray[1000];

		//	与母线直接连接的开关刀闸置状态，这是冗余设计，设计开关刀闸状态在后面设置
		for (i=pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange; i++)
		{
			if (pPGBlock->m_BusbarSectionArray[i].nNode < 0)
				continue;

			if (pPGBlock->m_BusbarSectionArray[i].bBypass != 0)
			{
				for (j=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[i].nNode].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[i].nNode+1].nBreakerRange; j++)
					pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[j].nBreaker].nInnerType=PGEnum_BreakerInnerType_BrBypass;
				for (j=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[i].nNode].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[i].nNode+1].nDisconnectorRange; j++)
					pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType=PGEnum_DisconnectorInnerType_SwLnXfBypass;
			}
			else
			{
				for (j=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[i].nNode].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[i].nNode+1].nDisconnectorRange; j++)
					pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType=PGEnum_DisconnectorInnerType_SwBusbar;
			}
		}
		for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
		{
			if (pPGBlock->m_SynchronousMachineArray[i].nNode < 0)	continue;
			if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode].nBusbarSectionPtr >= 0)	continue;

			bFlag=0;
			PGMemDB::PGTraverseVolt(pPGBlock, pPGBlock->m_SynchronousMachineArray[i].nNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);
			for (nNode=0; nNode<nNodeNum; nNode++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nBusbarSectionPtr >= 0)
					continue;
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]+1].nBreakerRange; j++)
				{
					pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[j].nBreaker].nInnerType = PGEnum_BreakerInnerType_BrLnXf;
					bFlag=1;
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]+1].nDisconnectorRange; j++)
				{
					pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType = PGEnum_DisconnectorInnerType_SwLnXf;
					bFlag=1;
				}
			}

			if (!bFlag)
			{
				nBreakNum=0;
				PGMemDB::PGTraverseVolt(pPGBlock, pPGBlock->m_SynchronousMachineArray[i].nNode, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);
				for (j=0; j<nNodeNum; j++)
					nBreakNum += pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].nBreakerRange;
				if (nBreakNum == 1)
				{
					for (j=0; j<nNodeNum; j++)
					{
						for (k=pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].nBreakerRange; k<pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]+1].nBreakerRange; k++)
							pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[k].nBreaker].nInnerType = PGEnum_BreakerInnerType_BrLnXf;
						for (k=pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].nDisconnectorRange; k<pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]+1].nDisconnectorRange; k++)
							pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[k].nDisconnector].nInnerType = PGEnum_DisconnectorInnerType_SwLnXf;
					}
				}
			}
		}
		for (i=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; i++)
		{
			if (pPGBlock->m_EnergyConsumerArray[i].nNode < 0)	continue;
			if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode].nBusbarSectionPtr >= 0)	continue;

			nBreakNum=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode].nBreakerRange;

			PGMemDB::PGTraverseVolt(pPGBlock, pPGBlock->m_EnergyConsumerArray[i].nNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);
			for (nNode=0; nNode<nNodeNum; nNode++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nBusbarSectionPtr >= 0)	continue;
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]+1].nBreakerRange; j++)
					pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[j].nBreaker].nInnerType = PGEnum_BreakerInnerType_BrLnXf;

				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]+1].nDisconnectorRange; j++)
				{
					nDev=pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector;
					pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXf;
					if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeI].nBusbarSectionPtr >= 0)
					{
						if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeI].nBusbarSectionPtr].bBypass != 0)
							pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
						else if (nBreakNum > 1)
							pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
					}
					if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeJ].nBusbarSectionPtr >= 0)
					{
						if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeJ].nBusbarSectionPtr].bBypass != 0)
							pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
						else if (nBreakNum > 1)
							pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
					}
				}
			}
		}
		for (i=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; i++)
		{
			if (pPGBlock->m_ShuntCompensatorArray[i].nNode < 0)	continue;
			if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ShuntCompensatorArray[i].nNode].nBusbarSectionPtr >= 0)	continue;

			nBreakNum=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ShuntCompensatorArray[i].nNode+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ShuntCompensatorArray[i].nNode].nBreakerRange;

			PGMemDB::PGTraverseVolt(pPGBlock, pPGBlock->m_ShuntCompensatorArray[i].nNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);
			for (nNode=0; nNode<nNodeNum; nNode++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nBusbarSectionPtr >= 0)	continue;
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]+1].nBreakerRange; j++)
					pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[j].nBreaker].nInnerType = PGEnum_BreakerInnerType_BrLnXf;

				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]+1].nDisconnectorRange; j++)
				{
					nDev=pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector;
					pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXf;
					if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeI].nBusbarSectionPtr >= 0)
					{
						if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeI].nBusbarSectionPtr].bBypass != 0)
							pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
						else if (nBreakNum > 1)
							pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
					}
					if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeJ].nBusbarSectionPtr >= 0)
					{
						if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeJ].nBusbarSectionPtr].bBypass != 0)
							pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
						else if (nBreakNum > 1)
							pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
					}
				}
			}
		}
		for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
		{
			for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange; i++)
			{
				nBreakNum=pPGBlock->m_ConnectivityNodeArray[nNode+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nNode].nBreakerRange;

				PGMemDB::PGTraverseVolt(pPGBlock, nNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);
				for (j=0; j<nNodeNum; j++)
				{
					if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].nBusbarSectionPtr >= 0)	continue;
					for (k=pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].nBreakerRange; k<pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]+1].nBreakerRange; k++)
						pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[k].nBreaker].nInnerType = PGEnum_BreakerInnerType_BrLnXf;

					for (k=pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].nDisconnectorRange; k<pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]+1].nDisconnectorRange; k++)
					{
						nDev=pPGBlock->m_EdgeDisconnectorArray[k].nDisconnector;
						pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXf;
						bFlag=1;

						if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeI].nBusbarSectionPtr >= 0)
						{
							if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeI].nBusbarSectionPtr].bBypass != 0)
								pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
							else if (nBreakNum > 1)
								pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
						}
						if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeJ].nBusbarSectionPtr >= 0)
						{
							if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeJ].nBusbarSectionPtr].bBypass != 0)
								pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
							else if (nBreakNum > 1)
								pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
						}
					}
				}
			}

			for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange; i++)
			{
				nBreakNum=pPGBlock->m_ConnectivityNodeArray[nNode+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nNode].nBreakerRange;

				PGMemDB::PGTraverseVolt(pPGBlock, nNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);
				for (j=0; j<nNodeNum; j++)
				{
					if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].nBusbarSectionPtr >= 0)	continue;
					for (k=pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].nBreakerRange; k<pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]+1].nBreakerRange; k++)
						pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[k].nBreaker].nInnerType = PGEnum_BreakerInnerType_BrLnXf;

					for (k=pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].nDisconnectorRange; k<pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]+1].nDisconnectorRange; k++)
					{
						nDev=pPGBlock->m_EdgeDisconnectorArray[k].nDisconnector;
						pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXf;
						bFlag=1;

						if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeI].nBusbarSectionPtr >= 0)
						{
							if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeI].nBusbarSectionPtr].bBypass != 0)
								pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
							else if (nBreakNum > 1)
								pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
						}
						if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeJ].nBusbarSectionPtr >= 0)
						{
							if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeJ].nBusbarSectionPtr].bBypass != 0)
								pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
							else if (nBreakNum > 1)
								pPGBlock->m_DisconnectorArray[nDev].nInnerType = PGEnum_DisconnectorInnerType_SwLnXfBypass;
						}
					}
				}
			}
		}
	}

	void	FormBrswInnerType_BusBrsw(tagPGBlock* pPGBlock, const int nVolt)
	{
		register int	i, j;
		int		nDev;
		int		nIBusNum, nIBreakNum, nIDevNum;
		int		nZBusNum, nZBreakNum, nZDevNum;
		int		nINodeNum, nINodeArray[1000];
		int		nZNodeNum, nZNodeArray[1000];
		unsigned char	bIHasPangBus, bZHasPangBus;

		for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nBreakerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nBreakerRange; nDev++)
		{
			bIHasPangBus=bZHasPangBus=0;

			PGTraverseVolt(pPGBlock, pPGBlock->m_BreakerArray[nDev].nNodeI, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nINodeNum, nINodeArray);
			nIBusNum=nIDevNum=nIBreakNum=0;
			for (i=0; i<nINodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBusbarSectionPtr >= 0)
				{
					nIBusNum++;
					if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBusbarSectionPtr].bBypass != 0)
						bIHasPangBus=1;

					continue;
				}
				nIDevNum += pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nACLineSegmentRange +
					pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nTransformerWindingRange +
					pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nSeriesCompensatorRange-pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nSeriesCompensatorRange;
				for (j=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; j++)
				{
					if (pPGBlock->m_EnergyConsumerArray[j].nNode == nINodeArray[i])
						nIDevNum++;
				}
				for (j=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; j++)
				{
					if (pPGBlock->m_EnergyConsumerArray[j].nNode == nINodeArray[i])
						nIDevNum++;
				}
				nIBreakNum += pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBreakerRange;
			}
			if (nIBusNum <= 0 || nIBreakNum > 1 || nIDevNum > 0)
				continue;

			PGTraverseVolt(pPGBlock, pPGBlock->m_BreakerArray[nDev].nNodeJ, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nZNodeNum, nZNodeArray);
			nZBusNum=nZDevNum=nZBreakNum=0;
			for (i=0; i<nZNodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nBusbarSectionPtr >= 0)
				{
					if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nBusbarSectionPtr].bBypass != 0)
						bZHasPangBus=1;

					nZBusNum++;
					continue;
				}
				nZBreakNum += pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]+1].nBreakerRange-pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nBreakerRange;
				nZDevNum += pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nACLineSegmentRange +
					pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nTransformerWindingRange +
					pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]+1].nSeriesCompensatorRange-pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nSeriesCompensatorRange;
				for (j=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; j++)
				{
					if (pPGBlock->m_EnergyConsumerArray[j].nNode == nZNodeArray[i])
						nZDevNum++;
				}
				for (j=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; j++)
				{
					if (pPGBlock->m_EnergyConsumerArray[j].nNode == nZNodeArray[i])
						nZDevNum++;
				}
			}
			if (nZBusNum <= 0 || nZBreakNum > 1 || nZDevNum > 0)
				continue;

			if ((nIBusNum > 1 && bIHasPangBus) || (nZBusNum > 1 && bZHasPangBus))
				pPGBlock->m_BreakerArray[nDev].nInnerType=PGEnum_BreakerInnerType_BrBusBypass;
			else if ((nIBusNum == 1 && bIHasPangBus) || (nZBusNum == 1 && bZHasPangBus))
				pPGBlock->m_BreakerArray[nDev].nInnerType=PGEnum_BreakerInnerType_BrBypass;
			else
				pPGBlock->m_BreakerArray[nDev].nInnerType=PGEnum_BreakerInnerType_BrBus;
			for (i=0; i<nINodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBusbarSectionPtr >= 0)
					continue;

				for (j=pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nDisconnectorRange; j++)
					pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType=PGEnum_DisconnectorInnerType_SwBuslink;
				if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBusbarSectionPtr > 0)
				{
					if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nBusbarSectionPtr].bBypass != 0)
					{
						for (j=pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nINodeArray[i]+1].nDisconnectorRange; j++)
							pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType=PGEnum_DisconnectorInnerType_SwBusBypass;
					}
				}
			}
			for (i=0; i<nZNodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nBusbarSectionPtr >= 0)
					continue;

				for (j=pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]+1].nDisconnectorRange; j++)
					pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType=PGEnum_DisconnectorInnerType_SwBuslink;
				if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nBusbarSectionPtr > 0)
				{
					if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nBusbarSectionPtr].bBypass != 0)
					{
						for (j=pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nZNodeArray[i]+1].nDisconnectorRange; j++)
							pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector].nInnerType=PGEnum_DisconnectorInnerType_SwBusBypass;
					}
				}
			}
		}

		for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nDisconnectorRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nDisconnectorRange; nDev++)
		{
			if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeI].nBusbarSectionPtr >= 0 && pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeJ].nBusbarSectionPtr >= 0)
			{
				if (pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeI].nBusbarSectionPtr].bBypass != 0 ||
					pPGBlock->m_BusbarSectionArray[pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeJ].nBusbarSectionPtr].bBypass != 0)
					pPGBlock->m_DisconnectorArray[nDev].nInnerType=PGEnum_DisconnectorInnerType_BypassCross;
				else
					pPGBlock->m_DisconnectorArray[nDev].nInnerType=PGEnum_DisconnectorInnerType_SwBuslink;
			}
		}
	}

	void	PGFormBreakerDisconnectorInnerType(tagPGBlock* pPGBlock)
	{
		register int	i;
		int		nSub, nVolt;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_BREAKER]; i++)
			pPGBlock->m_BreakerArray[i].nInnerType=UNPROCBREAK;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; i++)
			pPGBlock->m_DisconnectorArray[i].nInnerType=UNPROCSWITCH;

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				if (PGIsVolt32(pPGBlock, nVolt))
				{
					FormBrswInnerType_Volt32(pPGBlock, nVolt);
				}
				else
				{
					FormBrswInnerType_DevBrsw(pPGBlock, nVolt);
					FormBrswInnerType_BusBrsw(pPGBlock, nVolt);
				}
			}
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_BREAKER]; i++)
		{
			if (pPGBlock->m_BreakerArray[i].nInnerType == UNPROCBREAK)
				pPGBlock->m_BreakerArray[i].nInnerType=PGEnum_BreakerInnerType_BrLnXf;
		}

		for (i=1; i<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; i++)
		{
			if (pPGBlock->m_DisconnectorArray[i].nInnerType == UNPROCSWITCH)
				pPGBlock->m_DisconnectorArray[i].nInnerType=PGEnum_DisconnectorInnerType_SwLnXf;
		}
	}

	void	PGFormBreakerDisconnectorJointDeviceType(tagPGBlock* pPGBlock)
	{
		register int	i;//, j;
		int		nSub, nVolt, nDev, nNode;
		int		nTypeI, nIndexI, nTypeZ, nIndexZ;
		int		nINodeNum, nINodeArray[1000];
		int		nZNodeNum, nZNodeArray[1000];
		std::vector<unsigned char>	nBStatusArray;
		std::vector<unsigned char>	nSStatusArray;

		nBStatusArray.resize(pPGBlock->m_nRecordNum[PG_BREAKER]);
		nSStatusArray.resize(pPGBlock->m_nRecordNum[PG_DISCONNECTOR]);
		for (i=0; i<pPGBlock->m_nRecordNum[PG_BREAKER]; i++)
		{
			pPGBlock->m_BreakerArray[i].nJointDevType=0;
			pPGBlock->m_BreakerArray[i].nJointDevIndex=-1;
			nBStatusArray[i]=pPGBlock->m_BreakerArray[i].nStatus ;
			pPGBlock->m_BreakerArray[i].nStatus=1;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; i++)
		{
			pPGBlock->m_DisconnectorArray[i].nJointDevType=0;
			pPGBlock->m_DisconnectorArray[i].nJointDevIndex=-1;
			nSStatusArray[i]=pPGBlock->m_DisconnectorArray[i].nStatus ;
			pPGBlock->m_DisconnectorArray[i].nStatus =0;
		}
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nDisconnectorRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nDisconnectorRange; nDev++)
				{
					if (pPGBlock->m_DisconnectorArray[nDev].nJointDevType > 0)
						continue;

					nTypeI=nTypeZ=0;
					nIndexI=nIndexZ=-1;
					nINodeNum=nZNodeNum=0;

					//if (stricmp(pPGBlock->m_SubstationArray[nSub].szName, "直属.安定") == 0 &&
					//	stricmp(pPGBlock->m_VoltageLevelArray[nVolt].szName, "A033.500kV") == 0 &&
					//	stricmp(pPGBlock->m_DisconnectorArray[nDev].szName, "安定5091-1刀闸") == 0)
					//	j=0;

					pPGBlock->m_DisconnectorArray[nDev].nStatus =1;

					if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeI].nBusbarSectionPtr < 0)
					{
						PGTraverseVolt(pPGBlock, pPGBlock->m_DisconnectorArray[nDev].nNodeI, N_CheckStatus, Y_CheckStatus, Y_BusBound, Y_BreakerBound, nINodeNum, nINodeArray);
						if (nTypeI <= 0)
						{
							for (nNode=0; nNode<nINodeNum; nNode++)
							{
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
								{
									if (nINodeArray[nNode] == pPGBlock->m_SynchronousMachineArray[i].nNode)
									{
										nTypeI=PG_SYNCHRONOUSMACHINE;
										nIndexI=i;
										break;
									}
								}
								if (nTypeI > 0)	break;
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; i++)
								{
									if (nINodeArray[nNode] == pPGBlock->m_EnergyConsumerArray[i].nNode)
									{
										nTypeI=PG_ENERGYCONSUMER;
										nIndexI=i;
										break;
									}
								}
								if (nTypeI > 0)	break;
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; i++)
								{
									if (nINodeArray[nNode] == pPGBlock->m_ShuntCompensatorArray[i].nNode)
									{
										nTypeI=PG_SHUNTCOMPENSATOR;
										nIndexI=i;
										break;
									}
								}
								if (nTypeI > 0)	break;
							}
						}
						if (nTypeI <= 0)
						{
							for (nNode=0; nNode<nINodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]+1].nACLineSegmentRange > pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nACLineSegmentRange)
								{
									nTypeI=PG_ACLINESEGMENT;
									nIndexI=pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nACLineSegmentRange].nACLineSegment;
									break;
								}
							}
						}
						if (nTypeI <= 0)
						{
							for (nNode=0; nNode<nINodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]+1].nTransformerWindingRange > pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nTransformerWindingRange)
								{
									nTypeI=PG_TRANSFORMERWINDING;
									nIndexI=pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nTransformerWindingRange].nTransformerWinding;
									break;
								}
							}
						}
						if (nTypeI <= 0)
						{
							for (nNode=0; nNode<nINodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]+1].nSeriesCompensatorRange > pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nSeriesCompensatorRange)
								{
									nTypeI=PG_SERIESCOMPENSATOR;
									nIndexI=pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nSeriesCompensatorRange].nSeriesCompensator;
									break;
								}
							}
						}
					}

					if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[nDev].nNodeJ].nBusbarSectionPtr < 0)
					{
						PGTraverseVolt(pPGBlock, pPGBlock->m_DisconnectorArray[nDev].nNodeJ, N_CheckStatus, Y_CheckStatus, Y_BusBound, Y_BreakerBound, nZNodeNum, nZNodeArray);
						if (nTypeZ <= 0)
						{
							for (nNode=0; nNode<nZNodeNum; nNode++)
							{
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
								{
									if (nZNodeArray[nNode] == pPGBlock->m_SynchronousMachineArray[i].nNode)
									{
										nTypeZ=PG_SYNCHRONOUSMACHINE;
										nIndexZ=i;
										break;
									}
								}
								if (nTypeZ > 0)	break;
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; i++)
								{
									if (nZNodeArray[nNode] == pPGBlock->m_EnergyConsumerArray[i].nNode)
									{
										nTypeZ=PG_ENERGYCONSUMER;
										nIndexZ=i;
										break;
									}
								}
								if (nTypeZ > 0)	break;
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; i++)
								{
									if (nZNodeArray[nNode] == pPGBlock->m_ShuntCompensatorArray[i].nNode)
									{
										nTypeZ=PG_SHUNTCOMPENSATOR;
										nIndexZ=i;
										break;
									}
								}
								if (nTypeZ > 0)	break;
							}
						}
						if (nTypeZ <= 0)
						{
							for (nNode=0; nNode<nZNodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]+1].nACLineSegmentRange > pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nACLineSegmentRange)
								{
									nTypeZ=PG_ACLINESEGMENT;
									nIndexZ=pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nACLineSegmentRange].nACLineSegment;
									break;
								}
							}
						}
						if (nTypeZ <= 0)
						{
							for (nNode=0; nNode<nZNodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]+1].nTransformerWindingRange > pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nTransformerWindingRange)
								{
									nTypeZ=PG_TRANSFORMERWINDING;
									nIndexZ=pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nTransformerWindingRange].nTransformerWinding;
									break;
								}
							}
						}
						if (nTypeZ <= 0)
						{
							for (nNode=0; nNode<nZNodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]+1].nSeriesCompensatorRange > pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nSeriesCompensatorRange)
								{
									nTypeZ=PG_SERIESCOMPENSATOR;
									nIndexZ=pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nSeriesCompensatorRange].nSeriesCompensator;
									break;
								}
							}
						}
					}

					if (nTypeI > 0 && nTypeZ == 0)
					{
						pPGBlock->m_DisconnectorArray[nDev].nJointDevType=(unsigned char)nTypeI;
						pPGBlock->m_DisconnectorArray[nDev].nJointDevIndex=nIndexI;
					}
					else if (nTypeI == 0 && nTypeZ > 0)
					{
						pPGBlock->m_DisconnectorArray[nDev].nJointDevType=(unsigned char)nTypeZ;
						pPGBlock->m_DisconnectorArray[nDev].nJointDevIndex=nIndexZ;
					}
					pPGBlock->m_DisconnectorArray[nDev].nStatus =0;
				}
			}
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nBreakerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nBreakerRange; nDev++)
				{
					nTypeI=nTypeZ=0;
					nIndexI=nIndexZ=-1;
					nINodeNum=nZNodeNum=0;

					if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[nDev].nNodeI].nBusbarSectionPtr < 0)
					{
						PGTraverseVolt(pPGBlock, pPGBlock->m_BreakerArray[nDev].nNodeI, Y_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nINodeNum, nINodeArray);
						if (nTypeI <= 0)
						{
							for (nNode=0; nNode<nINodeNum; nNode++)
							{
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
								{
									if (nINodeArray[nNode] == pPGBlock->m_SynchronousMachineArray[i].nNode)
									{
										nTypeI=PG_SYNCHRONOUSMACHINE;
										nIndexI=i;
										break;
									}
								}
								if (nTypeI > 0)	break;
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; i++)
								{
									if (nINodeArray[nNode] == pPGBlock->m_EnergyConsumerArray[i].nNode)
									{
										nTypeI=PG_ENERGYCONSUMER;
										nIndexI=i;
										break;
									}
								}
								if (nTypeI > 0)	break;
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; i++)
								{
									if (nINodeArray[nNode] == pPGBlock->m_ShuntCompensatorArray[i].nNode)
									{
										nTypeI=PG_SHUNTCOMPENSATOR;
										nIndexI=i;
										break;
									}
								}
								if (nTypeI > 0)	break;
							}
						}
						if (nTypeI <= 0)
						{
							for (nNode=0; nNode<nINodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]+1].nACLineSegmentRange > pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nACLineSegmentRange)
								{
									nTypeI=PG_ACLINESEGMENT;
									nIndexI=pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nACLineSegmentRange].nACLineSegment;
									break;
								}
							}
						}
						if (nTypeI <= 0)
						{
							for (nNode=0; nNode<nINodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]+1].nTransformerWindingRange > pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nTransformerWindingRange)
								{
									nTypeI=PG_TRANSFORMERWINDING;
									nIndexI=pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nTransformerWindingRange].nTransformerWinding;
									break;
								}
							}
						}
						if (nTypeI <= 0)
						{
							for (nNode=0; nNode<nINodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]+1].nSeriesCompensatorRange > pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nSeriesCompensatorRange)
								{
									nTypeI=PG_SERIESCOMPENSATOR;
									nIndexI=pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nSeriesCompensatorRange].nSeriesCompensator;
									break;
								}
							}
						}
					}

					if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[nDev].nNodeJ].nBusbarSectionPtr < 0)
					{
						PGTraverseVolt(pPGBlock, pPGBlock->m_BreakerArray[nDev].nNodeJ, Y_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nZNodeNum, nZNodeArray);
						if (nTypeZ <= 0)
						{
							for (nNode=0; nNode<nZNodeNum; nNode++)
							{
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
								{
									if (nZNodeArray[nNode] == pPGBlock->m_SynchronousMachineArray[i].nNode)
									{
										nTypeZ=PG_SYNCHRONOUSMACHINE;
										nIndexZ=i;
										break;
									}
								}
								if (nTypeZ > 0)	break;
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; i++)
								{
									if (nZNodeArray[nNode] == pPGBlock->m_EnergyConsumerArray[i].nNode)
									{
										nTypeZ=PG_ENERGYCONSUMER;
										nIndexZ=i;
										break;
									}
								}
								if (nTypeZ > 0)	break;
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; i++)
								{
									if (nZNodeArray[nNode] == pPGBlock->m_ShuntCompensatorArray[i].nNode)
									{
										nTypeZ=PG_SHUNTCOMPENSATOR;
										nIndexZ=i;
										break;
									}
								}
								if (nTypeZ > 0)	break;
							}
						}
						if (nTypeZ <= 0)
						{
							for (nNode=0; nNode<nZNodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]+1].nACLineSegmentRange > pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nACLineSegmentRange)
								{
									nTypeZ=PG_ACLINESEGMENT;
									nIndexZ=pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nACLineSegmentRange].nACLineSegment;
									break;
								}
							}
						}
						if (nTypeZ <= 0)
						{
							for (nNode=0; nNode<nZNodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]+1].nTransformerWindingRange > pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nTransformerWindingRange)
								{
									nTypeZ=PG_TRANSFORMERWINDING;
									nIndexZ=pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nTransformerWindingRange].nTransformerWinding;
									break;
								}
							}
						}
						if (nTypeZ <= 0)
						{
							for (nNode=0; nNode<nZNodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]+1].nSeriesCompensatorRange > pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nSeriesCompensatorRange)
								{
									nTypeZ=PG_SERIESCOMPENSATOR;
									nIndexZ=pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nSeriesCompensatorRange].nSeriesCompensator;
									break;
								}
							}
						}
					}

					if (nTypeI > 0 && nTypeZ == 0)
					{
						pPGBlock->m_BreakerArray[nDev].nJointDevType=(unsigned char)nTypeI;
						pPGBlock->m_BreakerArray[nDev].nJointDevIndex=nIndexI;
						for (nNode=0; nNode<nINodeNum; nNode++)
						{
							if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nBusbarSectionPtr >= 0)
								continue;
							for (i=pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nDisconnectorRange; i<pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]+1].nDisconnectorRange; i++)
							{
								if (pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nJointDevType == 0)
								{
									pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nJointDevType=(unsigned char)nTypeI;
									pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nJointDevIndex=nIndexI;
								}
							}
						}
						for (nNode=0; nNode<nZNodeNum; nNode++)
						{
							if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nBusbarSectionPtr >= 0)
								continue;
							for (i=pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nDisconnectorRange; i<pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]+1].nDisconnectorRange; i++)
							{
								if (pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nJointDevType == 0)
								{
									pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nJointDevType=(unsigned char)nTypeI;
									pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nJointDevIndex=nIndexI;
								}
							}
						}
					}
					else if (nTypeI == 0 && nTypeZ > 0)
					{
						pPGBlock->m_BreakerArray[nDev].nJointDevType=(unsigned char)nTypeZ;
						pPGBlock->m_BreakerArray[nDev].nJointDevIndex=nIndexZ;
						for (nNode=0; nNode<nINodeNum; nNode++)
						{
							if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nBusbarSectionPtr >= 0)
								continue;
							for (i=pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nDisconnectorRange; i<pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]+1].nDisconnectorRange; i++)
							{
								if (pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nJointDevType == 0)
								{
									pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nJointDevType=(unsigned char)nTypeZ;
									pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nJointDevIndex=nIndexZ;
								}
							}
						}
						for (nNode=0; nNode<nZNodeNum; nNode++)
						{
							if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nBusbarSectionPtr >= 0)
								continue;
							for (i=pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nDisconnectorRange; i<pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]+1].nDisconnectorRange; i++)
							{
								pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nJointDevType=(unsigned char)nTypeZ;
								pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nJointDevIndex=nIndexZ;
							}
						}
					}
				}
			}
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_BREAKER]; i++)
			pPGBlock->m_BreakerArray[i].nStatus=nBStatusArray[i];
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; i++)
			pPGBlock->m_DisconnectorArray[i].nStatus=nSStatusArray[i];
	}

	void	PGFormDCBreakerJointDeviceType(tagPGBlock* pPGBlock)
	{
		register int	i;//, j;
		int		nSub, nVolt, nDev, nNode;
		int		nTypeI, nIndexI, nTypeZ, nIndexZ;
		int		nINodeNum, nINodeArray[1000];
		int		nZNodeNum, nZNodeArray[1000];
		std::vector<unsigned char>	nBStatusArray;
		std::vector<unsigned char>	nSStatusArray;

		nBStatusArray.resize(pPGBlock->m_nRecordNum[PG_DCBREAKER]);
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCBREAKER]; i++)
		{
			pPGBlock->m_DCBreakerArray[i].nJointDevType=0;
			pPGBlock->m_DCBreakerArray[i].nJointDevIndex=-1;
			nBStatusArray[i]=pPGBlock->m_DCBreakerArray[i].nStatus ;
			pPGBlock->m_DCBreakerArray[i].nStatus=1;
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nDCBreakerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nDCBreakerRange; nDev++)
				{
					nTypeI=nTypeZ=0;
					nIndexI=nIndexZ=-1;
					nINodeNum=nZNodeNum=0;

					PGTraverseVolt(pPGBlock, pPGBlock->m_DCBreakerArray[nDev].nNodeI, Y_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nINodeNum, nINodeArray);
					if (nTypeI <= 0)
					{
						for (nNode=0; nNode<nINodeNum; nNode++)
						{
							for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
							{
								if (nINodeArray[nNode] == pPGBlock->m_SynchronousMachineArray[i].nNode)
								{
									nTypeI=PG_SYNCHRONOUSMACHINE;
									nIndexI=i;
									break;
								}
							}
							if (nTypeI > 0)	break;
							for (i=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; i++)
							{
								if (nINodeArray[nNode] == pPGBlock->m_EnergyConsumerArray[i].nNode)
								{
									nTypeI=PG_ENERGYCONSUMER;
									nIndexI=i;
									break;
								}
							}
							if (nTypeI > 0)	break;
						}
					}
					if (nTypeI <= 0)
					{
						for (nNode=0; nNode<nINodeNum; nNode++)
						{
							if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]+1].nDCLineSegmentRange > pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nDCLineSegmentRange)
							{
								nTypeI=PG_DCLINESEGMENT;
								nIndexI=pPGBlock->m_EdgeDCLineSegmentArray[pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nDCLineSegmentRange].nDCLineSegment;
								break;
							}
						}
					}
					if (nTypeI <= 0)
					{
						for (nNode=0; nNode<nINodeNum; nNode++)
						{
							if (pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]+1].nDCShortCircuitLimitRange > pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nDCShortCircuitLimitRange)
							{
								nTypeI=PG_DCSHORTCIRCUITLIMIT;
								nIndexI=pPGBlock->m_EdgeDCShortCircuitLimitArray[pPGBlock->m_ConnectivityNodeArray[nINodeArray[nNode]].nDCShortCircuitLimitRange].nDCShortCircuitLimit;
								break;
							}
						}
					}

					if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DCBreakerArray[nDev].nNodeJ].nBusbarSectionPtr < 0)
					{
						PGTraverseVolt(pPGBlock, pPGBlock->m_DCBreakerArray[nDev].nNodeJ, Y_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nZNodeNum, nZNodeArray);
						if (nTypeZ <= 0)
						{
							for (nNode=0; nNode<nZNodeNum; nNode++)
							{
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
								{
									if (nZNodeArray[nNode] == pPGBlock->m_SynchronousMachineArray[i].nNode)
									{
										nTypeZ=PG_SYNCHRONOUSMACHINE;
										nIndexZ=i;
										break;
									}
								}
								if (nTypeZ > 0)	break;
								for (i=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; i++)
								{
									if (nZNodeArray[nNode] == pPGBlock->m_EnergyConsumerArray[i].nNode)
									{
										nTypeZ=PG_ENERGYCONSUMER;
										nIndexZ=i;
										break;
									}
								}
								if (nTypeZ > 0)	break;
							}
						}
						if (nTypeZ <= 0)
						{
							for (nNode=0; nNode<nZNodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]+1].nDCLineSegmentRange > pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nDCLineSegmentRange)
								{
									nTypeZ=PG_DCLINESEGMENT;
									nIndexZ=pPGBlock->m_EdgeDCLineSegmentArray[pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nDCLineSegmentRange].nDCLineSegment;
									break;
								}
							}
						}
						if (nTypeZ <= 0)
						{
							for (nNode=0; nNode<nZNodeNum; nNode++)
							{
								if (pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]+1].nDCShortCircuitLimitRange > pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nDCShortCircuitLimitRange)
								{
									nTypeZ=PG_DCSHORTCIRCUITLIMIT;
									nIndexZ=pPGBlock->m_EdgeDCShortCircuitLimitArray[pPGBlock->m_ConnectivityNodeArray[nZNodeArray[nNode]].nDCShortCircuitLimitRange].nDCShortCircuitLimit;
									break;
								}
							}
						}
					}

					if (nTypeI > 0 && nTypeZ == 0)
					{
						pPGBlock->m_DCBreakerArray[nDev].nJointDevType=(unsigned char)nTypeI;
						pPGBlock->m_DCBreakerArray[nDev].nJointDevIndex=nIndexI;
					}
					else if (nTypeI == 0 && nTypeZ > 0)
					{
						pPGBlock->m_DCBreakerArray[nDev].nJointDevType=(unsigned char)nTypeZ;
						pPGBlock->m_DCBreakerArray[nDev].nJointDevIndex=nIndexZ;
					}
				}
			}
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCBREAKER]; i++)
			pPGBlock->m_DCBreakerArray[i].nStatus=nBStatusArray[i];
	}

}