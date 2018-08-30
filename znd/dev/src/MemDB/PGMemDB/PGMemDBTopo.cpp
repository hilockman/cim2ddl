// PGMemDBTopper.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

namespace PGMemDB 
{
	static	int		m_nNextBs=3;				//	拓扑节点链
	static	int		m_nNullBs=1;				//	拓扑节点链
	static	int		m_nNulavBs=2;				//	拓扑节点链

	void	PGMemDBTopo(tagPGBlock* pPGBlock, const int bCheckOpen)
	{
		register int	i;
		int		nSub, nVolt, nNode;
		int		nBranchNum, nNodeNum, nNodeArray[1000];
		std::vector<unsigned char>	uProcArray;

		unsigned char	bCheckStatus=(bCheckOpen) ? Y_CheckStatus : N_CheckStatus;

		uProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE], 0);

		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
			pPGBlock->m_ConnectivityNodeArray[i].bOpen=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
			pPGBlock->m_ConnectivityNodeArray[i].nTopoBus=m_nNullBs;

		m_nNextBs=3;
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (uProcArray[nNode])
						continue;

					PGTraverseTopo(pPGBlock, nNode, bCheckStatus, bCheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
					nBranchNum=0;
					for (i=0; i<nNodeNum; i++)
					{
						uProcArray[nNodeArray[i]]=1;
						nBranchNum += (	pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange+
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCLineSegmentRange+
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange+
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nSeriesCompensatorRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nSeriesCompensatorRange);
					}
					if (nBranchNum > 0)
					{
						pPGBlock->m_TopoBusArray[m_nNextBs].nVolt = (short)nVolt;
						for (i=0; i<nNodeNum; i++)
						{
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTopoBus=m_nNextBs;
						}
						m_nNextBs++;
					}
				}
			}
		}
		pPGBlock->m_nRecordNum[PG_TOPOBUS]=m_nNextBs+1;

		for (nVolt=0; nVolt<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; nVolt++)
		{
			for (i=pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange; i++)
			{
				pPGBlock->m_BusbarSectionArray[i].nTopoBus=-1;
				if (pPGBlock->m_BusbarSectionArray[i].nNode < 0)
					continue;
				pPGBlock->m_BusbarSectionArray[i].nTopoBus=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BusbarSectionArray[i].nNode].nTopoBus;
			}

			for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
			{
				pPGBlock->m_SynchronousMachineArray[i].nTopoBus=-1;
				if (pPGBlock->m_SynchronousMachineArray[i].nNode < 0)
					continue;
				pPGBlock->m_SynchronousMachineArray[i].nTopoBus=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode].nTopoBus;
			}

			for (i=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; i++)
			{
				pPGBlock->m_EnergyConsumerArray[i].nTopoBus=-1;
				if (pPGBlock->m_EnergyConsumerArray[i].nNode < 0)
					continue;
				pPGBlock->m_EnergyConsumerArray[i].nTopoBus=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode].nTopoBus;
			}

			for (i=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; i++)
			{
				pPGBlock->m_ShuntCompensatorArray[i].nTopoBus=-1;
				if (pPGBlock->m_ShuntCompensatorArray[i].nNode < 0)
					continue;
				pPGBlock->m_ShuntCompensatorArray[i].nTopoBus=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ShuntCompensatorArray[i].nNode].nTopoBus;
			}

			for (i=pPGBlock->m_VoltageLevelArray[nVolt].nGroundTransformerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nGroundTransformerRange; i++)
			{
				pPGBlock->m_GroundTransformerArray[i].nTopoBus=-1;
				if (pPGBlock->m_GroundTransformerArray[i].nNode < 0)
					continue;
				pPGBlock->m_GroundTransformerArray[i].nTopoBus=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_GroundTransformerArray[i].nNode].nTopoBus;
			}
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
		{
			pPGBlock->m_ACLineSegmentArray[i].nTopoBusI=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ACLineSegmentArray[i].nNodeI].nTopoBus;
			pPGBlock->m_ACLineSegmentArray[i].nTopoBusJ=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ACLineSegmentArray[i].nNodeJ].nTopoBus;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]; i++)
		{
			pPGBlock->m_DCLineSegmentArray[i].nTopoBusI=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DCLineSegmentArray[i].nNodeI].nTopoBus;
			pPGBlock->m_DCLineSegmentArray[i].nTopoBusJ=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DCLineSegmentArray[i].nNodeJ].nTopoBus;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]; i++)
		{
			pPGBlock->m_PowerTransformerArray[i].nTopoBusH=-1;
			pPGBlock->m_PowerTransformerArray[i].nTopoBusM=-1;
			pPGBlock->m_PowerTransformerArray[i].nTopoBusL=-1;

			if (pPGBlock->m_PowerTransformerArray[i].nNodeH >= 0)
				pPGBlock->m_PowerTransformerArray[i].nTopoBusH=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_PowerTransformerArray[i].nNodeH].nTopoBus;
			if (pPGBlock->m_PowerTransformerArray[i].nNodeM >= 0)
				pPGBlock->m_PowerTransformerArray[i].nTopoBusM=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_PowerTransformerArray[i].nNodeM].nTopoBus;
			if (pPGBlock->m_PowerTransformerArray[i].nNodeL >= 0)
				pPGBlock->m_PowerTransformerArray[i].nTopoBusL=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_PowerTransformerArray[i].nNodeL].nTopoBus;
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
		{
			pPGBlock->m_TransformerWindingArray[i].nTopoBusI=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_TransformerWindingArray[i].nNodeI].nTopoBus;
			pPGBlock->m_TransformerWindingArray[i].nTopoBusJ=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_TransformerWindingArray[i].nNodeJ].nTopoBus;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SERIESCOMPENSATOR]; i++)
		{
			pPGBlock->m_SeriesCompensatorArray[i].nTopoBusI=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SeriesCompensatorArray[i].nNodeI].nTopoBus;
			pPGBlock->m_SeriesCompensatorArray[i].nTopoBusJ=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SeriesCompensatorArray[i].nNodeJ].nTopoBus;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER]; i++)
		{
			pPGBlock->m_RectifierInverterArray[i].nTopBus1=-1;
			pPGBlock->m_RectifierInverterArray[i].nTopBus2=-1;
			pPGBlock->m_RectifierInverterArray[i].nTopBus3=-1;

			if (pPGBlock->m_RectifierInverterArray[i].nNode1 >= 0)
			{
				if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_RectifierInverterArray[i].nNode1].nTopoBus > 1)
					pPGBlock->m_RectifierInverterArray[i].nTopBus1=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_RectifierInverterArray[i].nNode1].nTopoBus;
			}
			if (pPGBlock->m_RectifierInverterArray[i].nNode2 >= 0)
			{
				if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_RectifierInverterArray[i].nNode2].nTopoBus > 1)
					pPGBlock->m_RectifierInverterArray[i].nTopBus2=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_RectifierInverterArray[i].nNode2].nTopoBus;
			}
			if (pPGBlock->m_RectifierInverterArray[i].nNode3 >= 0)
			{
				if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_RectifierInverterArray[i].nNode3].nTopoBus > 1)
					pPGBlock->m_RectifierInverterArray[i].nTopBus3=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_RectifierInverterArray[i].nNode3].nTopoBus;
			}
		}
	}
}
