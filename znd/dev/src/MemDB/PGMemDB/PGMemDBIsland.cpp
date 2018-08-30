#include "stdafx.h"
#include "PGMemDB.h"
#include <float.h>

namespace PGMemDB 
{
	int	getIslandSlack(tagPGBlock* pPGBlock, const int nIsland)
	{
		int		nSub, nVolt, nDev, nMax;
		float	fMaxP;

		fMaxP=0;
		nMax=-1;
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
				{
					if (pPGBlock->m_SynchronousMachineArray[nDev].nNode < 0 || pPGBlock->m_SynchronousMachineArray[nDev].nIsland != nIsland || pPGBlock->m_SynchronousMachineArray[nDev].bOutage)
						continue;
					if (sqrt(pPGBlock->m_SynchronousMachineArray[nDev].fPlanP*pPGBlock->m_SynchronousMachineArray[nDev].fPlanP+pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ*pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ) < FLT_MIN)
						continue;

					if (pPGBlock->m_SynchronousMachineArray[nDev].fPMax > fMaxP)
					{
						nMax=nDev;
						fMaxP=pPGBlock->m_SynchronousMachineArray[nDev].fPMax;
					}
				}
			}
		}
		if (nMax < 0)
		{
			for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
			{
				for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
				{
					for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
					{
						if (pPGBlock->m_SynchronousMachineArray[nDev].nNode < 0 || pPGBlock->m_SynchronousMachineArray[nDev].nIsland != nIsland || pPGBlock->m_SynchronousMachineArray[nDev].bOutage)
							continue;

						if (pPGBlock->m_SynchronousMachineArray[nDev].fPMax > fMaxP)
						{
							nMax=nDev;
							fMaxP=pPGBlock->m_SynchronousMachineArray[nDev].fPMax;
						}
					}
				}
			}
		}
		return nMax;
	}

	void PGMemDBIsland(tagPGBlock* pPGBlock, const int bCheckOpen)
	{
		register int	i;
		int				nSub, nVolt, nDev, nNode, nNodeVolt;
		float			fAuxP, fAuxQ;
		float			fAuxPCon, fAuxPVar, fAuxCoef;
		char			szType[MDB_CHARLEN_LONG];
		int				nJointNodeNum, *pnJointNodeArray;
		std::vector<int>	bProcArray;

		unsigned char	bCheckStatus=(bCheckOpen) ? Y_CheckStatus : N_CheckStatus;

		pnJointNodeArray=(int*)malloc(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]*sizeof(int));
		if (!pnJointNodeArray)
			return;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_GROUNDDISCONNECTOR]; i++)
			pPGBlock->m_GroundDisconnectorArray[i].nStatus=1;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
			pPGBlock->m_ConnectivityNodeArray[i].bOpen=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
			pPGBlock->m_ConnectivityNodeArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
			pPGBlock->m_SynchronousMachineArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; i++)
			pPGBlock->m_EnergyConsumerArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; i++)
			pPGBlock->m_ShuntCompensatorArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
			pPGBlock->m_ACLineSegmentArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SERIESCOMPENSATOR]; i++)
			pPGBlock->m_SeriesCompensatorArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
			pPGBlock->m_TransformerWindingArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER]; i++)
			pPGBlock->m_RectifierInverterArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_BREAKER]; i++)
			pPGBlock->m_BreakerArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; i++)
			pPGBlock->m_DisconnectorArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_GROUNDTRANSFORMER]; i++)
			pPGBlock->m_GroundTransformerArray[i].nIsland=0;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_TOPOBUS]; i++)
			pPGBlock->m_TopoBusArray[i].nIsland=0;

		bProcArray.resize(pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE], 0);
		for (i=0; i<PG_MaxIsland; i++)
			memset(&pPGBlock->m_IslandArray[i], 0, sizeof(tagPGIsland));

		pPGBlock->m_nRecordNum[PG_ISLAND]=1;
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
				{
					if (pPGBlock->m_SynchronousMachineArray[nDev].nNode < 0)
						continue;
					//if (pPGBlock->m_SynchronousMachineArray[nDev].bOutage)
					//	continue;

					if (bProcArray[nDev] != 0)
						continue;

					bProcArray[nDev]=1;

					nJointNodeNum=0;
					PGTraverseNet(pPGBlock, pPGBlock->m_SynchronousMachineArray[nDev].nNode, bCheckStatus, 0, nJointNodeNum, pnJointNodeArray);
					for (nNode=0; nNode<nJointNodeNum; nNode++)
					{
						nNodeVolt=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nVoltageLevelPtr;
						pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
						for (i=0; i<pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER]; i++)
						{
							if (pPGBlock->m_RectifierInverterArray[i].nNode1 == pnJointNodeArray[nNode])
								pPGBlock->m_RectifierInverterArray[i].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
							if (pPGBlock->m_RectifierInverterArray[i].nNode2 == pnJointNodeArray[nNode])
								pPGBlock->m_RectifierInverterArray[i].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
							if (pPGBlock->m_RectifierInverterArray[i].nNode3 == pnJointNodeArray[nNode])
								pPGBlock->m_RectifierInverterArray[i].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
						}

						for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nSynchronousMachineRange; i++)
						{
							if (pPGBlock->m_SynchronousMachineArray[i].nNode == pnJointNodeArray[nNode])
							{
								bProcArray[i]=1;
								pPGBlock->m_SynchronousMachineArray[i].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];

								pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].fUnitP += pPGBlock->m_SynchronousMachineArray[i].fPlanP;
								pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].fUnitQ += pPGBlock->m_SynchronousMachineArray[i].fPlanQ;
								pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].nUnitNum++;

								strcpy(szType, PGGetFieldEnumString(PG_SYNCHRONOUSMACHINE, PG_SYNCHRONOUSMACHINE_TYPE, pPGBlock->m_SynchronousMachineArray[i].nType));
								if (strcmp(szType, "等值机组") != 0 && strcmp(szType, "光伏") != 0 && strcmp(szType, "风机") != 0)
								{
									fAuxP=fAuxQ=0;
									fAuxPCon=pPGBlock->m_SynchronousMachineArray[i].fAuxPca;
									fAuxPVar=pPGBlock->m_SynchronousMachineArray[i].fAuxPva;
									fAuxCoef=0.8f;
									if (pPGBlock->m_SynchronousMachineArray[i].fAuxFactor > 0.5)
										fAuxCoef=pPGBlock->m_SynchronousMachineArray[i].fAuxFactor;

									if (fAuxPCon > 0.001 || fAuxPVar > 0.001)
									{
										fAuxP=pPGBlock->m_SynchronousMachineArray[i].fPMax*fAuxPCon+pPGBlock->m_SynchronousMachineArray[i].fPlanP*fAuxPVar;
										fAuxQ=(float)(fAuxP*sqrt(1-fAuxCoef*fAuxCoef)/fAuxCoef);
									}
									pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].fLoadP += fAuxP;
									pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].fLoadQ += fAuxQ;
								}
							}
						}

						for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nBusbarSectionRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nBusbarSectionRange; i++)
						{
							if (pPGBlock->m_BusbarSectionArray[i].nNode == pnJointNodeArray[nNode])
							{
								pPGBlock->m_BusbarSectionArray[i].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
								pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].nBusNum++;
							}
						}
						for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nEnergyConsumerRange; i++)
						{
							if (pPGBlock->m_EnergyConsumerArray[i].nNode == pnJointNodeArray[nNode])
							{
								pPGBlock->m_EnergyConsumerArray[i].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];

								pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].fLoadP += pPGBlock->m_EnergyConsumerArray[i].fPlanP;
								pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].fLoadQ += pPGBlock->m_EnergyConsumerArray[i].fPlanQ;
								pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].nLoadNum++;
							}
						}
						for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nShuntCompensatorRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nShuntCompensatorRange; i++)
						{
							if (pPGBlock->m_ShuntCompensatorArray[i].nNode == pnJointNodeArray[nNode])
							{
								pPGBlock->m_ShuntCompensatorArray[i].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
								pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].nCapNum++;
							}
						}
						for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nGroundTransformerRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nGroundTransformerRange; i++)
						{
							if (pPGBlock->m_GroundTransformerArray[i].nNode == pnJointNodeArray[nNode])
								pPGBlock->m_GroundTransformerArray[i].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
						}
						for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nACLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nACLineSegmentRange; i++)
						{
							pPGBlock->m_ACLineSegmentArray[pPGBlock->m_EdgeACLineSegmentArray[i].nACLineSegment].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
							pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].nLineNum++;
						}
						for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nTransformerWindingRange; i++)
						{
							pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nNodeI].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nNodeJ].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];

							pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].nTranNum++;
						}
						for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nBreakerRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nBreakerRange; i++)
							pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[i].nBreaker].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
						for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nDisconnectorRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nDisconnectorRange; i++)
							pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
						for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nSeriesCompensatorRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nSeriesCompensatorRange; i++)
							pPGBlock->m_SeriesCompensatorArray[pPGBlock->m_EdgeSeriesCompensatorArray[i].nSeriesCompensator].nIsland=(short)pPGBlock->m_nRecordNum[PG_ISLAND];
					}

					pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].nLineNum /= 2;
					pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].nTranNum /= 2;

					pPGBlock->m_nRecordNum[PG_ISLAND]++;
				}
			}
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_ISLAND]; i++)
		{
			if (pPGBlock->m_IslandArray[i].nUnitNum > 0 && pPGBlock->m_IslandArray[i].nLoadNum > 0)
			{
				pPGBlock->m_IslandArray[i].nSlackGen=(short)getIslandSlack(pPGBlock, i);
				if (pPGBlock->m_IslandArray[i].nSlackGen >= 0)
				{
					strcpy(pPGBlock->m_IslandArray[i].szSlackSub, pPGBlock->m_SynchronousMachineArray[pPGBlock->m_IslandArray[i].nSlackGen].szSub);
					strcpy(pPGBlock->m_IslandArray[i].szSlackGen, pPGBlock->m_SynchronousMachineArray[pPGBlock->m_IslandArray[i].nSlackGen].szName);
				}
				else
				{
					pPGBlock->m_IslandArray[i].bDead=1;
				}
			}
			else
			{
				pPGBlock->m_IslandArray[i].bDead=1;
			}
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
			pPGBlock->m_TopoBusArray[pPGBlock->m_ConnectivityNodeArray[i].nTopoBus].nIsland=pPGBlock->m_ConnectivityNodeArray[i].nIsland;

		free(pnJointNodeArray);
	}
}
