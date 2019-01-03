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

					PGTraverseTopo(pPGBlock, nNode, bCheckStatus, bCheckStatus, nNodeNum, nNodeArray);
					nBranchNum=0;
					for (i=0; i<nNodeNum; i++)
					{
						uProcArray[nNodeArray[i]]=1;
						nBranchNum += (	pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange+
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCLineSegmentRange+
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange+
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nSeriesCompensatorRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nSeriesCompensatorRange+
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nADConverterRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nADConverterRange+
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDDConverterRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDDConverterRange+
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDDConverterRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDDConverterRange+
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCShortCircuitLimitRange - pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCShortCircuitLimitRange);
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
			for (i=pPGBlock->m_VoltageLevelArray[nVolt].nDCBusbarSectionRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nDCBusbarSectionRange; i++)
			{
				pPGBlock->m_DCBusbarSectionArray[i].nTopoBus=-1;
				if (pPGBlock->m_DCBusbarSectionArray[i].nNode < 0)
					continue;
				pPGBlock->m_DCBusbarSectionArray[i].nTopoBus=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DCBusbarSectionArray[i].nNode].nTopoBus;
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

		for (i=0; i<pPGBlock->m_nRecordNum[PG_WINDTURBINE]; i++)
		{
			pPGBlock->m_WindTurbineArray[i].nTopoBus=-1;
			if (pPGBlock->m_WindTurbineArray[i].nNode < 0)
				continue;
			pPGBlock->m_WindTurbineArray[i].nTopoBus=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_WindTurbineArray[i].nNode].nTopoBus;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_PHOTOVOLTAIC]; i++)
		{
			pPGBlock->m_PhotoVoltaicArray[i].nTopoBus=-1;
			if (pPGBlock->m_PhotoVoltaicArray[i].nNode < 0)
				continue;
			pPGBlock->m_PhotoVoltaicArray[i].nTopoBus=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_PhotoVoltaicArray[i].nNode].nTopoBus;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_EVSTATION]; i++)
		{
			pPGBlock->m_EVStationArray[i].nTopoBus=-1;
			if (pPGBlock->m_EVStationArray[i].nNode < 0)
				continue;
			pPGBlock->m_EVStationArray[i].nTopoBus=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EVStationArray[i].nNode].nTopoBus;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ELECTROCHEMICALENERGYSTORAGE]; i++)
		{
			pPGBlock->m_ElectroChemicalEnergyStorageArray[i].nTopoBus=-1;
			if (pPGBlock->m_ElectroChemicalEnergyStorageArray[i].nNode < 0)
				continue;
			pPGBlock->m_ElectroChemicalEnergyStorageArray[i].nTopoBus=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ElectroChemicalEnergyStorageArray[i].nNode].nTopoBus;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SOLARTHERMALMACHINE]; i++)
		{
			pPGBlock->m_SolarThermalMachineArray[i].nTopoBus=-1;
			if (pPGBlock->m_SolarThermalMachineArray[i].nNode < 0)
				continue;
			pPGBlock->m_SolarThermalMachineArray[i].nTopoBus=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SolarThermalMachineArray[i].nNode].nTopoBus;
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
		{
			pPGBlock->m_ACLineSegmentArray[i].nTopoBusI=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ACLineSegmentArray[i].nNodeI].nTopoBus;
			pPGBlock->m_ACLineSegmentArray[i].nTopoBusJ=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ACLineSegmentArray[i].nNodeJ].nTopoBus;
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


		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACDCCONVERTER]; i++)
		{
			pPGBlock->m_ACDCConverterArray[i].nTopoBusAC=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ACDCConverterArray[i].nNodeAC].nTopoBus;
			pPGBlock->m_ACDCConverterArray[i].nTopoBusDC=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ACDCConverterArray[i].nNodeDC].nTopoBus;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCDCCONVERTER]; i++)
		{
			pPGBlock->m_DCDCConverterArray[i].nTopoBusI=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DCDCConverterArray[i].nNodeI].nTopoBus;
			pPGBlock->m_DCDCConverterArray[i].nTopoBusJ=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DCDCConverterArray[i].nNodeJ].nTopoBus;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCSHORTCIRCUITLIMIT]; i++)
		{
			pPGBlock->m_DCShortCircuitLimitArray[i].nTopoBusI=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DCShortCircuitLimitArray[i].nNodeI].nTopoBus;
			pPGBlock->m_DCShortCircuitLimitArray[i].nTopoBusJ=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DCShortCircuitLimitArray[i].nNodeJ].nTopoBus;
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]; i++)
		{
			pPGBlock->m_DCLineSegmentArray[i].nTopoBusI=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DCLineSegmentArray[i].nNodeI].nTopoBus;
			pPGBlock->m_DCLineSegmentArray[i].nTopoBusJ=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DCLineSegmentArray[i].nNodeJ].nTopoBus;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER]; i++)
		{
			pPGBlock->m_RectifierInverterArray[i].nTopBusAC=-1;
			pPGBlock->m_RectifierInverterArray[i].nTopBusDCP=-1;
			pPGBlock->m_RectifierInverterArray[i].nTopBusDCN=-1;

			if (pPGBlock->m_RectifierInverterArray[i].nNodeAC >= 0)
			{
				if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_RectifierInverterArray[i].nNodeAC].nTopoBus > 1)
					pPGBlock->m_RectifierInverterArray[i].nTopBusAC=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_RectifierInverterArray[i].nNodeAC].nTopoBus;
			}
			if (pPGBlock->m_RectifierInverterArray[i].nNodeDCP >= 0)
			{
				if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_RectifierInverterArray[i].nNodeDCP].nTopoBus > 1)
					pPGBlock->m_RectifierInverterArray[i].nTopBusDCP=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_RectifierInverterArray[i].nNodeDCP].nTopoBus;
			}
			if (pPGBlock->m_RectifierInverterArray[i].nNodeDCN >= 0)
			{
				if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_RectifierInverterArray[i].nNodeDCN].nTopoBus > 1)
					pPGBlock->m_RectifierInverterArray[i].nTopBusDCN=pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_RectifierInverterArray[i].nNodeDCN].nTopoBus;
			}
		}
	}
}
