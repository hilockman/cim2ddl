#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

extern	void	ClearLog(const char* m_lpszPGMemDBLogFile);
extern	void	Log(const char* m_lpszPGMemDBLogFile, const char* pformat, ...);
namespace	PGMemDB
{
	void	PGMemDBAbnorm_Alone(tagPGBlock* pPGBlock)
	{
		register int	i, j;
		int		nSub, nVolt, nDev, nNode, nBranNum;
		int		bAlone;
		int		nNodeNum, nNodeArray[1000];
		std::vector<unsigned char>	nProcArray;

		//	检查发电机连通
		nProcArray.resize(pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE], 0);
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
				{
					if (nProcArray[nDev] != 0)
						continue;
					if (pPGBlock->m_SynchronousMachineArray[nDev].nNode < 0)
						continue;

					nProcArray[nDev]=1;

					PGTraverseVolt(pPGBlock, pPGBlock->m_SynchronousMachineArray[nDev].nNode, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);
					for (i=0; i<nNodeNum; i++)
					{
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; j++)
						{
							if (nDev == j)
								continue;
							if (pPGBlock->m_SynchronousMachineArray[j].nNode < 0)
								continue;

							if (pPGBlock->m_SynchronousMachineArray[j].nNode == nNodeArray[i])
								Log(m_lpszAbnormalLogFile, "可连通发电机 %s %s [%s %s] \n", pPGBlock->m_SynchronousMachineArray[j].szSub, pPGBlock->m_SynchronousMachineArray[j].szVolt, pPGBlock->m_SynchronousMachineArray[nDev].szName, pPGBlock->m_SynchronousMachineArray[j].szName);
						}
					}
				}
			}
		}

		nProcArray.resize(pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING], 0);
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			if (pPGBlock->m_SynchronousMachineArray[nDev].nNode < 0)
				continue;

			bAlone=1;
			PGTraverseVolt(pPGBlock, pPGBlock->m_SynchronousMachineArray[nDev].nNode, N_CheckStatus, N_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);

			for (i=0; i<nNodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange ||
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange ||
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCLineSegmentRange < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCLineSegmentRange ||
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nADConverterRange < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nADConverterRange ||
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDDConverterRange < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDDConverterRange)
				{
					bAlone=0;
					break;
				}
			}
			if (bAlone)
				Log(m_lpszAbnormalLogFile, "孤立设备（发电机）:%-16s %-8s %-16s \n", pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_SynchronousMachineArray[nDev].szVolt, pPGBlock->m_SynchronousMachineArray[nDev].szName);
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; nDev++)
		{
			if (pPGBlock->m_EnergyConsumerArray[nDev].nNode < 0)
				continue;

			PGTraverseVolt(pPGBlock, pPGBlock->m_EnergyConsumerArray[nDev].nNode, N_CheckStatus, N_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);

			nBranNum=0;
			for (i=0; i<nNodeNum; i++)
			{
				nBranNum += (	pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange+
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange+
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCLineSegmentRange+
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nADConverterRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nADConverterRange+
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDDConverterRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDDConverterRange);
			}
			if (!nBranNum)
				Log(m_lpszAbnormalLogFile, "孤立设备（负荷）:%-16s %-8s %-16s \n", pPGBlock->m_EnergyConsumerArray[nDev].szSub, pPGBlock->m_EnergyConsumerArray[nDev].szVolt, pPGBlock->m_EnergyConsumerArray[nDev].szName);
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; nDev++)
		{
			if (pPGBlock->m_ShuntCompensatorArray[nDev].nNode < 0)
				continue;

			bAlone=1;

			PGTraverseVolt(pPGBlock, pPGBlock->m_ShuntCompensatorArray[nDev].nNode, N_CheckStatus, N_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);

			for (i=0; i<nNodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange ||
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange ||
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCLineSegmentRange < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCLineSegmentRange ||
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nADConverterRange < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nADConverterRange ||
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDDConverterRange < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDDConverterRange)
				{
					bAlone=0;
					break;
				}
			}
			if (bAlone)
				Log(m_lpszAbnormalLogFile, "孤立设备（补偿）:%-16s %-8s %-16s \n", pPGBlock->m_ShuntCompensatorArray[nDev].szSub, pPGBlock->m_ShuntCompensatorArray[nDev].szVolt, pPGBlock->m_ShuntCompensatorArray[nDev].szName);
		}

		// 	for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		// 	{
		// 		for (nDev=pPGBlock->m_SubstationArray[nSub].pRWind; nDev<pPGBlock->m_SubstationArray[nSub+1].pRWind; nDev++)
		// 		{
		// 			if (nProcArray[nDev] != 0)
		// 				continue;
		//
		// 			//if (stricmp(pPGBlock->m_SubstationArray[nSub].szName, "4DY21") == 0)
		// 			//	i=0;
		// 			nProcArray[nDev]=1;
		//
		// 			PGGetTranCoil(pPGBlock, nDev, nTranNum, nTranCoil, nTranNode);
		//
		// 			if (nTranNum == 1)
		// 			{
		// 				bAlone=1;
		// 				PGTraverseVolt(pPGBlock, pPGBlock->m_TransformerWindingArray[nDev].iRnd, N_CheckStatus, N_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
		// 				for (i=0; i<nNodeNum; i++)
		// 				{
		// 					if (nNodeArray[i] == pPGBlock->m_TransformerWindingArray[nDev].iRnd)
		// 						continue;
		//
		// 					if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].pRACLineSegment < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].pRACLineSegment ||
		// 						pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].pRTransformerWinding < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].pRTransformerWinding)
		// 					{
		// 						bAlone=0;
		// 						break;
		// 					}
		// 					if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].iRld >= 0)
		// 					{
		// 						bAlone=0;
		// 						break;
		// 					}
		// 					if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].iRcp >= 0)
		// 					{
		// 						bAlone=0;
		// 						break;
		// 					}
		// 					if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].iRun >= 0)
		// 					{
		// 						bAlone=0;
		// 						break;
		// 					}
		// 				}
		// 				if (bAlone)
		// 				{
		// 					PGTraverseVolt(pPGBlock, pPGBlock->m_TransformerWindingArray[nDev].zRnd, N_CheckStatus, N_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
		// 					for (i=0; i<nNodeNum; i++)
		// 					{
		// 						if (nNodeArray[i] == pPGBlock->m_TransformerWindingArray[nDev].zRnd)
		// 							continue;
		//
		// 						if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].pRACLineSegment < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].pRACLineSegment ||
		// 							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].pRTransformerWinding < pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].pRTransformerWinding)
		// 						{
		// 							bAlone=0;
		// 							break;
		// 						}
		// 						if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].iRld >= 0)
		// 						{
		// 							bAlone=0;
		// 							break;
		// 						}
		// 						if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].iRcp >= 0)
		// 						{
		// 							bAlone=0;
		// 							break;
		// 						}
		// 						if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].iRun >= 0)
		// 						{
		// 							bAlone=0;
		// 							break;
		// 						}
		// 					}
		// 					if (bAlone)
		// 					{
		// 							Log(m_lpszAbnormalLogFile, "孤立设备（两卷变压器绕组）:%-16s %-8s %-16s \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szVoltI, pPGBlock->m_TransformerWindingArray[nDev].szName);
		// 					}
		// 				}
		// 			}
		// 			else
		// 			{
		// 				bAlone=1;
		// 				for (i=0; i<nTranNum; i++)
		// 				{
		// 					nProcArray[nTranCoil[i]]=1;
		//
		// 					PGTraverseVolt(pPGBlock, nTranNode[i], N_CheckStatus, N_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
		// 					for (j=0; j<nNodeNum; j++)
		// 					{
		// 						if (nNodeArray[j] == nTranNode[i])
		// 							continue;
		//
		// 						if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].pRACLineSegment < pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]+1].pRACLineSegment ||
		// 							pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].pRTransformerWinding < pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]+1].pRTransformerWinding)
		// 						{
		// 							bAlone=0;
		// 							break;
		// 						}
		// 						if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].iRld >= 0)
		// 						{
		// 							bAlone=0;
		// 							break;
		// 						}
		// 						if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].iRcp >= 0)
		// 						{
		// 							bAlone=0;
		// 							break;
		// 						}
		// 						if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[j]].iRun >= 0)
		// 						{
		// 							bAlone=0;
		// 							break;
		// 						}
		// 					}
		// 				}
		// 				if (bAlone)
		// 				{
		// 					for (i=0; i<nTranNum; i++)
		// 						Log(m_lpszAbnormalLogFile, "孤立设备（三卷变压器绕组）:%-16s %-8s %-16s \n", pPGBlock->m_TransformerWindingArray[nTranCoil[i]].szSub, pPGBlock->m_ConnectivityNodeArray[nTranNode[i]].szVolt, pPGBlock->m_TransformerWindingArray[nTranCoil[i]].szName);
		// 				}
		// 			}
		// 		}
		// 	}

		//	检查设备端点悬空
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				if (pPGBlock->m_VoltageLevelArray[nVolt+1].nDisconnectorRange == pPGBlock->m_VoltageLevelArray[nVolt].nDisconnectorRange)
					continue;

				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (pPGBlock->m_ConnectivityNodeArray[nNode].nBusbarSectionPtr >= 0)
					{
						if (PGIsTConnection(pPGBlock, nNode))
							continue;
					}
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange > 2)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode].bTNode)
						continue;

					nDev=0;
					for (j=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; j++)
					{
						if (pPGBlock->m_EnergyConsumerArray[j].nNode < 0)
							continue;
						if (pPGBlock->m_EnergyConsumerArray[j].nNode == nNode)
							nDev++;
					}
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange +
						pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange + nDev > 1)
					{
						Log(m_lpszAbnormalLogFile, "请检查 设备连接(一个节点连接多个设备)%s-%s-%s \n", pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_VoltageLevelArray[nVolt].szName, pPGBlock->m_ConnectivityNodeArray[nNode].szName);

						for (j=pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange; j<pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange; j++)
							Log(m_lpszAbnormalLogFile, "      %s \n", pPGBlock->m_EdgeACLineSegmentArray[j].szName);
						for (j=pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange; j<pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange; j++)
							Log(m_lpszAbnormalLogFile, "      %s \n", pPGBlock->m_EdgeTransformerWindingArray[j].szName);
						if (nDev > 0)
						{
							Log(m_lpszAbnormalLogFile, "      负荷数：%d \n", nDev);
							for (j=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; j++)
							{
								if (pPGBlock->m_EnergyConsumerArray[j].nNode < 0)
									continue;
								if (pPGBlock->m_EnergyConsumerArray[j].nNode == nNode)
									Log(m_lpszAbnormalLogFile, "      %s \n", pPGBlock->m_EnergyConsumerArray[j].szName);
							}
						}
					}
				}
			}
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange > 0)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange > 0)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nSeriesCompensatorRange - pPGBlock->m_ConnectivityNodeArray[nNode].nSeriesCompensatorRange > 0)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nBreakerRange - pPGBlock->m_ConnectivityNodeArray[nNode].nBreakerRange > 0)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nDisconnectorRange - pPGBlock->m_ConnectivityNodeArray[nNode].nDisconnectorRange > 0)
						continue;

					nDev=0;
					for (j=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; j++)
					{
						if (pPGBlock->m_EnergyConsumerArray[j].nNode < 0)
							continue;
						if (pPGBlock->m_EnergyConsumerArray[j].nNode == nNode)
						{
							nDev++;
							break;
						}
					}
					if (nDev > 0)
						continue;
					for (j=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; j++)
					{
						if (pPGBlock->m_ShuntCompensatorArray[j].nNode < 0)
							continue;
						if (pPGBlock->m_ShuntCompensatorArray[j].nNode == nNode)
						{
							nDev++;
							break;
						}
					}
					if (nDev > 0)
						continue;
					for (j=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; j++)
					{
						if (pPGBlock->m_SynchronousMachineArray[j].nNode == nNode)
						{
							nDev++;
							break;
						}
					}
					if (nDev > 0)
						continue;
					Log(m_lpszAbnormalLogFile, "请检查 节点连接(悬空)%s-%s-%s \n", pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_VoltageLevelArray[nVolt].szName, pPGBlock->m_ConnectivityNodeArray[nNode].szName);
				}
			}
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange; i++)
					{
						if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nBreakerRange - pPGBlock->m_ConnectivityNodeArray[nNode].nBreakerRange +
							pPGBlock->m_ConnectivityNodeArray[nNode+1].nDisconnectorRange - pPGBlock->m_ConnectivityNodeArray[nNode].nDisconnectorRange +
							pPGBlock->m_ConnectivityNodeArray[nNode+1].nSeriesCompensatorRange - pPGBlock->m_ConnectivityNodeArray[nNode].nSeriesCompensatorRange +
							pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange +
							pPGBlock->m_ConnectivityNodeArray[nNode+1].nADConverterRange - pPGBlock->m_ConnectivityNodeArray[nNode].nADConverterRange +
							pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange < 1)
							Log(m_lpszAbnormalLogFile, "请检查 线路连接(悬空)%s-%s-%s \n", pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_VoltageLevelArray[nVolt].szName, pPGBlock->m_EdgeACLineSegmentArray[i].szName);
					}
				}
			}
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange; i++)
					{
						if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nBreakerRange - pPGBlock->m_ConnectivityNodeArray[nNode].nBreakerRange +
							pPGBlock->m_ConnectivityNodeArray[nNode+1].nDisconnectorRange - pPGBlock->m_ConnectivityNodeArray[nNode].nDisconnectorRange +
							pPGBlock->m_ConnectivityNodeArray[nNode+1].nSeriesCompensatorRange - pPGBlock->m_ConnectivityNodeArray[nNode].nSeriesCompensatorRange +
							pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange +
							pPGBlock->m_ConnectivityNodeArray[nNode+1].nADConverterRange - pPGBlock->m_ConnectivityNodeArray[nNode].nADConverterRange +
							pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange < 1)
							Log(m_lpszAbnormalLogFile, "请检查 变压器连接(悬空)%s-%s-%s \n", pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_VoltageLevelArray[nVolt].szName, pPGBlock->m_EdgeTransformerWindingArray[i].szName);
					}
				}
			}
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
				{
					if (pPGBlock->m_SynchronousMachineArray[i].nNode < 0)
					{
						continue;
					}
					if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode+1].nBreakerRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode].nBreakerRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode+1].nDisconnectorRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode].nDisconnectorRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode+1].nSeriesCompensatorRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode].nSeriesCompensatorRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode].nTransformerWindingRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode+1].nDCLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode].nDCLineSegmentRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode+1].nADConverterRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode].nADConverterRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode+1].nDDConverterRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode].nDDConverterRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_SynchronousMachineArray[i].nNode].nACLineSegmentRange < 1)
						Log(m_lpszAbnormalLogFile, "请检查 发电机连接(悬空)%s-%s-%s \n", pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_VoltageLevelArray[nVolt].szName, pPGBlock->m_SynchronousMachineArray[i].szName);
				}
			}
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (i=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; i++)
				{
					if (pPGBlock->m_EnergyConsumerArray[i].nNode < 0)
					{
						continue;
					}
					if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode+1].nBreakerRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode].nBreakerRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode+1].nDisconnectorRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode].nDisconnectorRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode+1].nSeriesCompensatorRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode].nSeriesCompensatorRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode].nTransformerWindingRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode+1].nDCLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode].nDCLineSegmentRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode+1].nADConverterRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode].nADConverterRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode+1].nDDConverterRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode].nDDConverterRange +
						pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[i].nNode].nACLineSegmentRange < 1)
						Log(m_lpszAbnormalLogFile, "请检查 负荷连接(悬空)%s-%s-%s \n", pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_VoltageLevelArray[nVolt].szName, pPGBlock->m_EnergyConsumerArray[i].szName);
				}
			}
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (i=pPGBlock->m_VoltageLevelArray[nVolt].nBreakerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nBreakerRange; i++)
				{
					{
						nDev=0;
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange; j++)
						{
							if (pPGBlock->m_BusbarSectionArray[j].nNode == pPGBlock->m_BreakerArray[i].nNodeI)
								nDev++;
						}
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; j++)
						{
							if (pPGBlock->m_EnergyConsumerArray[j].nNode == pPGBlock->m_BreakerArray[i].nNodeI)
								nDev++;
						}
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; j++)
						{
							if (pPGBlock->m_ShuntCompensatorArray[j].nNode == pPGBlock->m_BreakerArray[i].nNodeI)
								nDev++;
						}
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; j++)
						{
							if (pPGBlock->m_SynchronousMachineArray[j].nNode == pPGBlock->m_BreakerArray[i].nNodeI)
								nDev++;
						}
						if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeI+1].nBreakerRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeI].nBreakerRange <= 1 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeI+1].nDisconnectorRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeI].nBreakerRange <= 0 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeI+1].nSeriesCompensatorRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeI].nSeriesCompensatorRange <= 0 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeI+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeI].nACLineSegmentRange <= 0 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeI+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeI].nTransformerWindingRange <= 0 && nDev < 1)
							Log(m_lpszAbnormalLogFile, "请检查 开关I连接(节点悬空)%s-%s-%s \n", pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_VoltageLevelArray[nVolt].szName, pPGBlock->m_BreakerArray[i].szName);
					}

					{
						nDev=0;
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange; j++)
						{
							if (pPGBlock->m_BusbarSectionArray[j].nNode == pPGBlock->m_BreakerArray[i].nNodeJ)
								nDev++;
						}
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; j++)
						{
							if (pPGBlock->m_EnergyConsumerArray[j].nNode == pPGBlock->m_BreakerArray[i].nNodeJ)
								nDev++;
						}
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; j++)
						{
							if (pPGBlock->m_ShuntCompensatorArray[j].nNode == pPGBlock->m_BreakerArray[i].nNodeJ)
								nDev++;
						}
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; j++)
						{
							if (pPGBlock->m_SynchronousMachineArray[j].nNode == pPGBlock->m_BreakerArray[i].nNodeJ)
								nDev++;
						}
						if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeJ+1].nBreakerRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeJ].nBreakerRange <= 1 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeJ+1].nDisconnectorRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeJ].nDisconnectorRange <= 0 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeJ+1].nSeriesCompensatorRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeJ].nSeriesCompensatorRange <= 0 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeJ+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeJ].nACLineSegmentRange <= 0 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeJ+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_BreakerArray[i].nNodeJ].nTransformerWindingRange <= 0 && nDev < 1)
							Log(m_lpszAbnormalLogFile, "请检查 开关J连接(节点悬空)%s-%s-%s \n", pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_VoltageLevelArray[nVolt].szName, pPGBlock->m_BreakerArray[i].szName);
					}
				}
			}
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (i=pPGBlock->m_VoltageLevelArray[nVolt].nDisconnectorRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nDisconnectorRange; i++)
				{
					{
						nDev=0;
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange; j++)
						{
							if (pPGBlock->m_BusbarSectionArray[j].nNode == pPGBlock->m_DisconnectorArray[i].nNodeI)
								nDev++;
						}
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; j++)
						{
							if (pPGBlock->m_EnergyConsumerArray[j].nNode == pPGBlock->m_DisconnectorArray[i].nNodeI)
								nDev++;
						}
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; j++)
						{
							if (pPGBlock->m_ShuntCompensatorArray[j].nNode == pPGBlock->m_DisconnectorArray[i].nNodeI)
								nDev++;
						}
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; j++)
						{
							if (pPGBlock->m_SynchronousMachineArray[j].nNode == pPGBlock->m_DisconnectorArray[i].nNodeI)
								nDev++;
						}
						if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeI+1].nBreakerRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeI].nBreakerRange <= 0 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeI+1].nDisconnectorRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeI].nDisconnectorRange <= 1 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeI+1].nSeriesCompensatorRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeI].nSeriesCompensatorRange <= 0 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeI+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeI].nACLineSegmentRange <= 0 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeI+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeI].nTransformerWindingRange <= 0 && nDev < 1)
							Log(m_lpszAbnormalLogFile, "请检查 刀闸I连接(节点悬空)%s-%s-%s \n", pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_VoltageLevelArray[nVolt].szName, pPGBlock->m_DisconnectorArray[i].szName);
					}

					{
						nDev=0;
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange; j++)
						{
							if (pPGBlock->m_BusbarSectionArray[j].nNode == pPGBlock->m_DisconnectorArray[i].nNodeJ)
								nDev++;
						}
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; j++)
						{
							if (pPGBlock->m_EnergyConsumerArray[j].nNode == pPGBlock->m_DisconnectorArray[i].nNodeJ)
								nDev++;
						}
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; j++)
						{
							if (pPGBlock->m_ShuntCompensatorArray[j].nNode == pPGBlock->m_DisconnectorArray[i].nNodeJ)
								nDev++;
						}
						for (j=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; j<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; j++)
						{
							if (pPGBlock->m_SynchronousMachineArray[j].nNode == pPGBlock->m_DisconnectorArray[i].nNodeJ)
								nDev++;
						}
						if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeJ+1].nBreakerRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeJ].nBreakerRange <= 0 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeJ+1].nDisconnectorRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeJ].nDisconnectorRange <= 1 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeJ+1].nSeriesCompensatorRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeJ].nSeriesCompensatorRange <= 1 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeJ+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeJ].nACLineSegmentRange <= 0 &&
							pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeJ+1].nTransformerWindingRange - pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_DisconnectorArray[i].nNodeJ].nTransformerWindingRange <= 0 && nDev < 1)
							Log(m_lpszAbnormalLogFile, "请检查 刀闸J连接(节点悬空)%s-%s-%s \n", pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_VoltageLevelArray[nVolt].szName, pPGBlock->m_DisconnectorArray[i].szName);
					}
				}
			}
		}
	}

	void	PGMemDBAbnorm(tagPGBlock* pPGBlock, const int nLossFlag)
	{
		register int	i, j;
		int		nDev;
		float	fR, fX, fYC, fNomVI, fNomVZ;

		ClearLog(m_lpszAbnormalLogFile);

		PGMemDBTopo(pPGBlock);
		PGMemDBStatus(pPGBlock, 0);
		PGMemDBStatistic(pPGBlock, nLossFlag);

		//	检查数据结构
		for (i=0; i<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; i++)
		{
			if (pPGBlock->m_VoltageLevelArray[i].nSubstationPtr < 0)
				Log(m_lpszAbnormalLogFile, "请检查 电压等级表中的厂站指针（指针不对），可能有错，致命错误\r\n错误原因：电压等级中无法索引厂站 \n");
		}
		if (pPGBlock->m_SubstationArray[pPGBlock->m_nRecordNum[PG_SUBSTATION]].nVoltageLevelRange != pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL])					Log(m_lpszAbnormalLogFile, "请检查 厂站表中的电压指针，可能有厂站的电压漏填，致命错误 \n");
		if (pPGBlock->m_SubstationArray[pPGBlock->m_nRecordNum[PG_SUBSTATION]].nTransformerWindingRange != pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING])		Log(m_lpszAbnormalLogFile, "请检查 厂站表中的变压器指针，可能有厂站的变压器有错，致命错误 \n");
		if (pPGBlock->m_SubstationArray[pPGBlock->m_nRecordNum[PG_SUBSTATION]].nRectifierInverterRange != pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER])			Log(m_lpszAbnormalLogFile, "请检查 厂站表中的整流逆变器指针，可能有厂站的整流逆变器有错，致命错误 \n");

		if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]].nConnecivityNodeRange != pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE])		Log(m_lpszAbnormalLogFile, "请检查 电压等级和节点表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]].nSynchronousMachineRange != pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE])	Log(m_lpszAbnormalLogFile, "请检查 电压等级和发电机表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]].nEnergyConsumerRange != pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER])			Log(m_lpszAbnormalLogFile, "请检查 电压等级和负荷表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]].nShuntCompensatorRange != pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR])		Log(m_lpszAbnormalLogFile, "请检查 电压等级和电容、电抗器表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]].nBusbarSectionRange != pPGBlock->m_nRecordNum[PG_BUSBARSECTION])				Log(m_lpszAbnormalLogFile, "请检查 电压等级和母线表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]].nBreakerRange != pPGBlock->m_nRecordNum[PG_BREAKER])							Log(m_lpszAbnormalLogFile, "请检查 电压等级和开关表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]].nDisconnectorRange != pPGBlock->m_nRecordNum[PG_DISCONNECTOR])				Log(m_lpszAbnormalLogFile, "请检查 电压等级和隔离装置表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]].nDCBusbarSectionRange != pPGBlock->m_nRecordNum[PG_DCBUSBARSECTION])			Log(m_lpszAbnormalLogFile, "请检查 电压等级和直流母线表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]].nDCBreakerRange != pPGBlock->m_nRecordNum[PG_DCBREAKER])						Log(m_lpszAbnormalLogFile, "请检查 电压等级和直流断路器表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]].nDCShortCircuitLimitRange != pPGBlock->m_nRecordNum[PG_DCSHORTCIRCUITLIMIT])	Log(m_lpszAbnormalLogFile, "请检查 电压等级和直流短路电流限制器表（指针不对），可能有错，致命错误 \n");
		// 	if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]].pRri != pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER])					Log(m_lpszAbnormalLogFile, "请检查 电压等级和整流逆变器表（指针不对），可能有错，致命错误 \n");

		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].nACLineSegmentRange != pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT])				Log(m_lpszAbnormalLogFile, "请检查 节点和交流线路段表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].nDCLineSegmentRange != pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT])				Log(m_lpszAbnormalLogFile, "请检查 节点和直流线路段表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].nTransformerWindingRange != pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING])	Log(m_lpszAbnormalLogFile, "请检查 节点和变压器绕组表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].nSeriesCompensatorRange != pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR])		Log(m_lpszAbnormalLogFile, "请检查 节点和串联补偿表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].nBreakerRange != pPGBlock->m_nRecordNum[PG_EDGEBREAKER])							Log(m_lpszAbnormalLogFile, "请检查 节点和断路器表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].nDisconnectorRange != pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR])				Log(m_lpszAbnormalLogFile, "请检查 节点和隔离开关表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].nADConverterRange != pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER])					Log(m_lpszAbnormalLogFile, "请检查 节点和AC/DC变换器表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].nDDConverterRange != pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER])					Log(m_lpszAbnormalLogFile, "请检查 节点和DC/DC变换器表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].nDCBreakerRange != pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER])						Log(m_lpszAbnormalLogFile, "请检查 节点和直流断路器表（指针不对），可能有错，致命错误 \n");
		if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].nDCShortCircuitLimitRange != pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT])	Log(m_lpszAbnormalLogFile, "请检查 节点和直流短路限制器表（指针不对），可能有错，致命错误 \n");

		for (i=0; i<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; i++)
		{
			if (fabs(pPGBlock->m_SubcontrolAreaArray[i].fTotalLoadP) < 1 &&
				fabs(pPGBlock->m_SubcontrolAreaArray[i].fTotalLoadQ) < 1 &&
				fabs(pPGBlock->m_SubcontrolAreaArray[i].fTotalGenP) < 1 &&
				fabs(pPGBlock->m_SubcontrolAreaArray[i].fTotalGenQ) < 1 &&
				fabs(pPGBlock->m_SubcontrolAreaArray[i].fTotalCap) < 1 &&
				fabs(pPGBlock->m_SubcontrolAreaArray[i].fTotalReac) < 1)
				continue;

			Log(m_lpszAbnormalLogFile, "区域: %s 负荷： %.1f %.1f \n", pPGBlock->m_SubcontrolAreaArray[i].szName, pPGBlock->m_SubcontrolAreaArray[i].fTotalLoadP, pPGBlock->m_SubcontrolAreaArray[i].fTotalLoadQ);
			Log(m_lpszAbnormalLogFile, "区域: %s 发电： %.1f %.1f \n", pPGBlock->m_SubcontrolAreaArray[i].szName, pPGBlock->m_SubcontrolAreaArray[i].fTotalGenP, pPGBlock->m_SubcontrolAreaArray[i].fTotalGenQ);
			Log(m_lpszAbnormalLogFile, "区域: %s 补偿： %.1f %.1f \n", pPGBlock->m_SubcontrolAreaArray[i].szName, pPGBlock->m_SubcontrolAreaArray[i].fTotalCap, pPGBlock->m_SubcontrolAreaArray[i].fTotalReac);
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_COMPANY]; i++)
		{
			if (fabs(pPGBlock->m_CompanyArray[i].fTotalLoadP) < 1 &&
				fabs(pPGBlock->m_CompanyArray[i].fTotalLoadQ) < 1 &&
				fabs(pPGBlock->m_CompanyArray[i].fTotalGenP) < 1 &&
				fabs(pPGBlock->m_CompanyArray[i].fTotalGenQ) < 1 &&
				fabs(pPGBlock->m_CompanyArray[i].fTotalCap) < 1 &&
				fabs(pPGBlock->m_CompanyArray[i].fTotalReac) < 1)
				continue;

			Log(m_lpszAbnormalLogFile, "公司: %s 负荷： %.1f %.1f \n", pPGBlock->m_CompanyArray[i].szName, pPGBlock->m_CompanyArray[i].fTotalLoadP, pPGBlock->m_CompanyArray[i].fTotalLoadQ);
			Log(m_lpszAbnormalLogFile, "公司: %s 发电： %.1f %.1f \n", pPGBlock->m_CompanyArray[i].szName, pPGBlock->m_CompanyArray[i].fTotalGenP, pPGBlock->m_CompanyArray[i].fTotalGenQ);
			Log(m_lpszAbnormalLogFile, "公司: %s 补偿： %.1f %.1f \n", pPGBlock->m_CompanyArray[i].szName, pPGBlock->m_CompanyArray[i].fTotalCap, pPGBlock->m_CompanyArray[i].fTotalReac);
		}

		Log(m_lpszAbnormalLogFile, "负荷总量    有功: %.1f 无功: %.1f \n", pPGBlock->m_System.fTotalLoadP, pPGBlock->m_System.fTotalLoadQ);
		Log(m_lpszAbnormalLogFile, "发电总量    有功: %.1f 无功: %.1f \n", pPGBlock->m_System.fTotalGenP, pPGBlock->m_System.fTotalGenQ);

		if (pPGBlock->m_System.fTotalGenP < pPGBlock->m_System.fTotalLoadP*1.01f)
			Log(m_lpszAbnormalLogFile, "有功功率可能不够 \n");

		//	检查参数
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			if (pPGBlock->m_SynchronousMachineArray[nDev].nNode < 0 || pPGBlock->m_SynchronousMachineArray[nDev].nTopoBus == 1)
			{
				continue;
			}

			if (fabs(pPGBlock->m_SynchronousMachineArray[nDev].fPlanV) > 0.1)
			{
				if (pPGBlock->m_SynchronousMachineArray[nDev].fPlanV < 0.8 || pPGBlock->m_SynchronousMachineArray[nDev].fPlanV > 1.2)
				{
					Log(m_lpszAbnormalLogFile, "请检查发电机PV值: %s-%s \n", pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_SynchronousMachineArray[nDev].szName);
				}
			}
			for (i=nDev+1; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
			{
				if (pPGBlock->m_SynchronousMachineArray[i].nNode < 0)
				{
					continue;
				}

				if (pPGBlock->m_SynchronousMachineArray[nDev].nTopoBus == pPGBlock->m_SynchronousMachineArray[i].nTopoBus)
				{
					// 				Log(m_lpszAbnormalLogFile, "请检查发电机拓扑（致命错误）: %s-%s-%s 与 %s-%s-%s 连通了，将造成暂态计算错误 \n", 
					// 					pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_SynchronousMachineArray[nDev].szVolt, pPGBlock->m_SynchronousMachineArray[nDev].szName, 
					// 					pPGBlock->m_SynchronousMachineArray[i].szSub, pPGBlock->m_SynchronousMachineArray[i].szVolt, pPGBlock->m_SynchronousMachineArray[i].szName);
				}
			}
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nDev++)
		{
			if (fabs(pPGBlock->m_ACLineSegmentArray[nDev].fR) > 1)
				Log(m_lpszAbnormalLogFile, "请检查交流线路[%s(%s-%s)]参数(r=%f 太大) \n", pPGBlock->m_ACLineSegmentArray[nDev].szName, pPGBlock->m_ACLineSegmentArray[nDev].szSubI, pPGBlock->m_ACLineSegmentArray[nDev].szSubJ, pPGBlock->m_ACLineSegmentArray[nDev].fR);
			if (fabs(pPGBlock->m_ACLineSegmentArray[nDev].fX) > 1)
				Log(m_lpszAbnormalLogFile, "请检查交流线路[%s(%s-%s)]参数(x=%f 太大) \n", pPGBlock->m_ACLineSegmentArray[nDev].szName, pPGBlock->m_ACLineSegmentArray[nDev].szSubI, pPGBlock->m_ACLineSegmentArray[nDev].szSubJ, pPGBlock->m_ACLineSegmentArray[nDev].fX);
			if (fabs(pPGBlock->m_ACLineSegmentArray[nDev].fX) < 0.00001)
				Log(m_lpszAbnormalLogFile, "请检查交流线路[%s(%s-%s)]参数(x为0) \n", pPGBlock->m_ACLineSegmentArray[nDev].szName, pPGBlock->m_ACLineSegmentArray[nDev].szSubI, pPGBlock->m_ACLineSegmentArray[nDev].szSubJ);
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nDev++)
		{
			if (fabs(pPGBlock->m_TransformerWindingArray[nDev].fR) > 0.5)
				Log(m_lpszAbnormalLogFile, "请检查主变[%s %s]参数(r=%f 太大) \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName, pPGBlock->m_TransformerWindingArray[nDev].fX);
			if (fabs(pPGBlock->m_TransformerWindingArray[nDev].fX) > 1)
				Log(m_lpszAbnormalLogFile, "请检查主变[%s %s]参数(x=%f 太大) \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName, pPGBlock->m_TransformerWindingArray[nDev].fX);
			if (fabs(pPGBlock->m_TransformerWindingArray[nDev].fX) < 0.00001)
				Log(m_lpszAbnormalLogFile, "请检查主变[%s %s]参数(x为0) \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName);
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nDev++)
		{
			if (fabs(pPGBlock->m_ACLineSegmentArray[nDev].fR) < 0.0001 && fabs(pPGBlock->m_ACLineSegmentArray[nDev].fX) < 0.00001)
				Log(m_lpszAbnormalLogFile, "请检查交流线路[%s]参数(r, x为0) \n", pPGBlock->m_ACLineSegmentArray[nDev].szName);
			if (fabs(pPGBlock->m_ACLineSegmentArray[nDev].fR) > fabs(pPGBlock->m_ACLineSegmentArray[nDev].fX))
				Log(m_lpszAbnormalLogFile, "请检查交流线路[%s]参数[r=%.4f x=%.4f](r>x) \n", pPGBlock->m_ACLineSegmentArray[nDev].szName, pPGBlock->m_ACLineSegmentArray[nDev].fR, pPGBlock->m_ACLineSegmentArray[nDev].fX);
			if (pPGBlock->m_ACLineSegmentArray[nDev].fB > 2.5)
				Log(m_lpszAbnormalLogFile, "请检查交流线路[%s]电纳=%.4f \n", pPGBlock->m_ACLineSegmentArray[nDev].szName, pPGBlock->m_ACLineSegmentArray[nDev].fB);
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]; nDev++)
		{
			if (fabs(pPGBlock->m_DCLineSegmentArray[nDev].fR) > 1)
				Log(m_lpszAbnormalLogFile, "请检查直流线路[%s(%s-%s)]参数(r=%f 太大) \n", pPGBlock->m_DCLineSegmentArray[nDev].szName, pPGBlock->m_DCLineSegmentArray[nDev].szSubI, pPGBlock->m_DCLineSegmentArray[nDev].szSubJ, pPGBlock->m_DCLineSegmentArray[nDev].fR);
			if (fabs(pPGBlock->m_DCLineSegmentArray[nDev].fR) < 0.00001)
				Log(m_lpszAbnormalLogFile, "请检查直流线路[%s(%s-%s)]参数(r为0) \n", pPGBlock->m_DCLineSegmentArray[nDev].szName, pPGBlock->m_DCLineSegmentArray[nDev].szSubI, pPGBlock->m_DCLineSegmentArray[nDev].szSubJ);
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nDev++)
		{
			int		iTap=pPGBlock->m_TransformerWindingArray[nDev].nTapChangerI;
			int		zTap=pPGBlock->m_TransformerWindingArray[nDev].nTapChangerJ;
			float	t, tz;

			fNomVI=pPGBlock->m_VoltageLevelArray[pPGBlock->m_TransformerWindingArray[nDev].nVoltI].nominalVoltage;
			fNomVZ=pPGBlock->m_VoltageLevelArray[pPGBlock->m_TransformerWindingArray[nDev].nVoltJ].nominalVoltage;

			t=tz=1;
			if (iTap >= 0)
				t=1+(pPGBlock->m_TapChangerArray[iTap].fTapStep/100.0f)*(pPGBlock->m_TransformerWindingArray[nDev].nTapI-pPGBlock->m_TapChangerArray[iTap].nTapNom);
			if (zTap >= 0)
				tz=1+(pPGBlock->m_TapChangerArray[zTap].fTapStep/100.0f)*(pPGBlock->m_TransformerWindingArray[nDev].nTapJ-pPGBlock->m_TapChangerArray[zTap].nTapNom);

			if (pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI >= 0.9*fNomVI && pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI<=1.1*fNomVI)
			{
				fR=pPGBlock->m_TransformerWindingArray[nDev].fR*(tz*pPGBlock->m_TransformerWindingArray[nDev].fRatedkVJ/fNomVZ)*(tz*pPGBlock->m_TransformerWindingArray[nDev].fRatedkVJ/fNomVZ);
				fX=pPGBlock->m_TransformerWindingArray[nDev].fX*(tz*pPGBlock->m_TransformerWindingArray[nDev].fRatedkVJ/fNomVZ)*(tz*pPGBlock->m_TransformerWindingArray[nDev].fRatedkVJ/fNomVZ);
				fYC=t*pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI*fNomVZ/(pPGBlock->m_TransformerWindingArray[nDev].fRatedkVJ*fNomVI*tz);
			}
			else
			{
				fR=pPGBlock->m_TransformerWindingArray[nDev].fR*(t*pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI/fNomVI)*(t*pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI/fNomVI);
				fX=pPGBlock->m_TransformerWindingArray[nDev].fX*(t*pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI/fNomVI)*(t*pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI/fNomVI);
				fYC=tz*pPGBlock->m_TransformerWindingArray[nDev].fRatedkVJ*fNomVI/(t*pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI*fNomVZ);
			}

			if (iTap < 0)
				Log(m_lpszAbnormalLogFile, "请检查变压器[%s %s]参数(I侧分接头名称无法索引) \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName);
			if (zTap < 0)
				Log(m_lpszAbnormalLogFile, "请检查变压器[%s %s]参数(J侧分接头名称无法索引) \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName);
			if (fabs(pPGBlock->m_TransformerWindingArray[nDev].fR) > fabs(pPGBlock->m_TransformerWindingArray[nDev].fX))
				Log(m_lpszAbnormalLogFile, "请检查变压器[%s %s]参数[r=%.4f x=%.4f](R>X) \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName, pPGBlock->m_TransformerWindingArray[nDev].fR, pPGBlock->m_TransformerWindingArray[nDev].fX);
			if (fabs(pPGBlock->m_TransformerWindingArray[nDev].fR) < 0.0005 && fabs(pPGBlock->m_TransformerWindingArray[nDev].fX) < 0.0005)
				Log(m_lpszAbnormalLogFile, "请检查变压器[%s %s]参数(R, X为0): \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName);

			if (pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI < fNomVI*0.8 || pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI > fNomVI*1.2)
				Log(m_lpszAbnormalLogFile, "请检查变压器[%s %s]参数(铭牌电压=%.2f 额定电压=%.2f) \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName, pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI, fNomVI);
			if (pPGBlock->m_TransformerWindingArray[nDev].fRatedkVJ < fNomVZ*0.8 || pPGBlock->m_TransformerWindingArray[nDev].fRatedkVJ > fNomVZ*1.2)
				Log(m_lpszAbnormalLogFile, "请检查变压器[%s %s]参数(铭牌电压=%.2f 额定电压=%.2f) \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName, pPGBlock->m_TransformerWindingArray[nDev].fRatedkVJ, fNomVZ);
			if (strlen(pPGBlock->m_TransformerWindingArray[nDev].szTapChangerI) <= 0)
				Log(m_lpszAbnormalLogFile, "请检查变压器[%s %s]参数(I侧分接头类型为空) \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName);
			if (strlen(pPGBlock->m_TransformerWindingArray[nDev].szTapChangerJ) <= 0)
				Log(m_lpszAbnormalLogFile, "请检查变压器[%s %s]参数(Z侧分接头类型为空) \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName);

			if (pPGBlock->m_TransformerWindingArray[nDev].nTapChangerI >= 0)
			{
				if (pPGBlock->m_TransformerWindingArray[nDev].nTapI > pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerI].nTapMax ||
					pPGBlock->m_TransformerWindingArray[nDev].nTapI < pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerI].nTapMin)
				{
					{
						Log(m_lpszAbnormalLogFile, "请检查 变压器[%s-%s]变比(tap=%d max=%d min=%d) \n", 
							pPGBlock->m_TransformerWindingArray[nDev].szSub, 
							pPGBlock->m_TransformerWindingArray[nDev].szName, 
							pPGBlock->m_TransformerWindingArray[nDev].nTapI, 
							pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerI].nTapMax, 
							pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerI].nTapMin);
					}
				}
			}
			if (pPGBlock->m_TransformerWindingArray[nDev].nTapChangerJ >= 0)
			{
				if (pPGBlock->m_TransformerWindingArray[nDev].nTapJ > pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerJ].nTapMax ||
					pPGBlock->m_TransformerWindingArray[nDev].nTapJ < pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerJ].nTapMin)
				{
					{
						Log(m_lpszAbnormalLogFile, "请检查 变压器[%s-%s]变比(zTap=%d max=%d min=%d) \n", 
							pPGBlock->m_TransformerWindingArray[nDev].szSub, 
							pPGBlock->m_TransformerWindingArray[nDev].szName, 
							pPGBlock->m_TransformerWindingArray[nDev].nTapJ, 
							pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerJ].nTapMax, 
							pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerJ].nTapMin);
					}
				}
			}
			if (fYC != 0 && (fYC > 1.3 || fYC < 0.8))
				Log(m_lpszAbnormalLogFile, "请检查变压器[%s %s]参数(变比=%.2f) \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName, fYC);
		}


		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			if (pPGBlock->m_SynchronousMachineArray[nDev].fPlanP > 1.05*pPGBlock->m_SynchronousMachineArray[nDev].fPMax)
				Log(m_lpszAbnormalLogFile, "请检查发电机[%s %s %s]出力(p>fPMax) p=%.2f fPMax=%.2f \n", pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_SynchronousMachineArray[nDev].szVolt, pPGBlock->m_SynchronousMachineArray[nDev].szName, pPGBlock->m_SynchronousMachineArray[nDev].fPlanP, pPGBlock->m_SynchronousMachineArray[nDev].fPMax);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			if (pPGBlock->m_SynchronousMachineArray[nDev].fPlanP < 0.95*pPGBlock->m_SynchronousMachineArray[nDev].fPMin)
				Log(m_lpszAbnormalLogFile, "请检查发电机[%s %s %s]出力(p<fPMin) p=%.2f fPMin=%.2f \n", pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_SynchronousMachineArray[nDev].szVolt, pPGBlock->m_SynchronousMachineArray[nDev].szName, pPGBlock->m_SynchronousMachineArray[nDev].fPlanP, pPGBlock->m_SynchronousMachineArray[nDev].fPMin);
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			if (pPGBlock->m_SynchronousMachineArray[nDev].bOutage != 0)
				continue;

			if (pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ > 1.05*pPGBlock->m_SynchronousMachineArray[nDev].fQMax)
				Log(m_lpszAbnormalLogFile, "请检查发电机[%s %s %s]出力(q>fQMax) q=%.2f fQMax=%.2f \n", pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_SynchronousMachineArray[nDev].szVolt, pPGBlock->m_SynchronousMachineArray[nDev].szName, pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ, pPGBlock->m_SynchronousMachineArray[nDev].fQMax);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			if (pPGBlock->m_SynchronousMachineArray[nDev].bOutage != 0)
				continue;

			if (pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ < 0.95*pPGBlock->m_SynchronousMachineArray[nDev].fQMin)
				Log(m_lpszAbnormalLogFile, "请检查发电机[%s %s %s]出力(q<fQMin) q=%.2f fQMin=%.2f \n", pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_SynchronousMachineArray[nDev].szVolt, pPGBlock->m_SynchronousMachineArray[nDev].szName, pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ, pPGBlock->m_SynchronousMachineArray[nDev].fQMin);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			if (0.5 < pPGBlock->m_SynchronousMachineArray[nDev].fPlanV && pPGBlock->m_SynchronousMachineArray[nDev].fPlanV < 0.8 || pPGBlock->m_SynchronousMachineArray[nDev].fPlanV > 1.2)
				Log(m_lpszAbnormalLogFile, "请检查发电机[%s %s %s]PV值 pv=%.4f \n", pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_SynchronousMachineArray[nDev].szVolt, pPGBlock->m_SynchronousMachineArray[nDev].szName, pPGBlock->m_SynchronousMachineArray[nDev].fPlanV);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; nDev++)
		{
			if (fabs(pPGBlock->m_ShuntCompensatorArray[nDev].fCap) < 0.001)
				Log(m_lpszAbnormalLogFile, "请检查补偿[%s %s %s]参数(补偿容量为0) \n", pPGBlock->m_ShuntCompensatorArray[nDev].szSub, pPGBlock->m_ShuntCompensatorArray[nDev].szVolt, pPGBlock->m_ShuntCompensatorArray[nDev].szName);
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_BUSBARSECTION]; nDev++)
		{
			if (pPGBlock->m_BusbarSectionArray[nDev].nNode < 0)
				Log(m_lpszAbnormalLogFile, "请检查交流母线[%s %s %s]信息(节点索引错误): \n", pPGBlock->m_BusbarSectionArray[nDev].szSub, pPGBlock->m_BusbarSectionArray[nDev].szVolt, pPGBlock->m_BusbarSectionArray[nDev].szName);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_DCBUSBARSECTION]; nDev++)
		{
			if (pPGBlock->m_DCBusbarSectionArray[nDev].nNode < 0)
				Log(m_lpszAbnormalLogFile, "请检查直流母线[%s %s %s]信息(节点索引错误): \n", pPGBlock->m_DCBusbarSectionArray[nDev].szSub, pPGBlock->m_DCBusbarSectionArray[nDev].szVolt, pPGBlock->m_DCBusbarSectionArray[nDev].szName);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nDev++)
		{
			if (pPGBlock->m_TransformerWindingArray[nDev].nNodeI < 0 || pPGBlock->m_TransformerWindingArray[nDev].nNodeJ < 0)
				Log(m_lpszAbnormalLogFile, "请检查变压器[%s-%s]信息(节点索引错误) \n", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			if (pPGBlock->m_SynchronousMachineArray[nDev].nNode < 0)
				Log(m_lpszAbnormalLogFile, "请检查发电机[%s %s %s]信息(节点索引错误) \n", pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_SynchronousMachineArray[nDev].szVolt, pPGBlock->m_SynchronousMachineArray[nDev].szName);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; nDev++)
		{
			if (pPGBlock->m_EnergyConsumerArray[nDev].nNode < 0)
				Log(m_lpszAbnormalLogFile, "请检查负荷[%s-%s-%s]信息(节点索引错误) \n", pPGBlock->m_EnergyConsumerArray[nDev].szSub, pPGBlock->m_EnergyConsumerArray[nDev].szVolt, pPGBlock->m_EnergyConsumerArray[nDev].szName);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; nDev++)
		{
			if (pPGBlock->m_ShuntCompensatorArray[nDev].nNode < 0)
				Log(m_lpszAbnormalLogFile, "请检查补偿[%s-%s-%s]信息(节点索引错误) \n", pPGBlock->m_ShuntCompensatorArray[nDev].szSub, pPGBlock->m_ShuntCompensatorArray[nDev].szVolt, pPGBlock->m_ShuntCompensatorArray[nDev].szName);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_WINDTURBINE]; nDev++)
		{
			if (pPGBlock->m_WindTurbineArray[nDev].nNode < 0)
				Log(m_lpszAbnormalLogFile, "请检查风机[%s-%s-%s]信息(节点索引错误) \n", pPGBlock->m_WindTurbineArray[nDev].szSub, pPGBlock->m_WindTurbineArray[nDev].szVolt, pPGBlock->m_WindTurbineArray[nDev].szName);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_PHOTOVOLTAIC]; nDev++)
		{
			if (pPGBlock->m_PhotoVoltaicArray[nDev].nNode < 0)
				Log(m_lpszAbnormalLogFile, "请检查光伏[%s-%s-%s]信息(节点索引错误) \n", pPGBlock->m_PhotoVoltaicArray[nDev].szSub, pPGBlock->m_PhotoVoltaicArray[nDev].szVolt, pPGBlock->m_PhotoVoltaicArray[nDev].szName);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_EVSTATION]; nDev++)
		{
			if (pPGBlock->m_EVStationArray[nDev].nNode < 0)
				Log(m_lpszAbnormalLogFile, "请检查电动汽车[%s-%s-%s]信息(节点索引错误) \n", pPGBlock->m_EVStationArray[nDev].szSub, pPGBlock->m_EVStationArray[nDev].szVolt, pPGBlock->m_EVStationArray[nDev].szName);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ELECTROCHEMICALENERGYSTORAGE]; nDev++)
		{
			if (pPGBlock->m_ElectroChemicalEnergyStorageArray[nDev].nNode < 0)
				Log(m_lpszAbnormalLogFile, "请检查电化学储能[%s-%s-%s]信息(节点索引错误) \n", pPGBlock->m_ElectroChemicalEnergyStorageArray[nDev].szSub, pPGBlock->m_ElectroChemicalEnergyStorageArray[nDev].szVolt, pPGBlock->m_ElectroChemicalEnergyStorageArray[nDev].szName);
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SOLARTHERMALMACHINE]; nDev++)
		{
			if (pPGBlock->m_SolarThermalMachineArray[nDev].nNode < 0)
				Log(m_lpszAbnormalLogFile, "请检查光热[%s-%s-%s]信息(节点索引错误) \n", pPGBlock->m_SolarThermalMachineArray[nDev].szSub, pPGBlock->m_SolarThermalMachineArray[nDev].szVolt, pPGBlock->m_SolarThermalMachineArray[nDev].szName);
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_COMPANY]; i++)
		{
			nDev=-1;
			for (j=0; j<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; j++)
			{
				if (strcmp(pPGBlock->m_SynchronousMachineArray[j].szSub, pPGBlock->m_CompanyArray[i].szSlackSub) == 0 &&
					strcmp(pPGBlock->m_SynchronousMachineArray[j].szName, pPGBlock->m_CompanyArray[i].szSlackGen) == 0)
				{
					nDev=j;
					break;
				}
			}

			if (nDev < 0)
			{
				Log(m_lpszAbnormalLogFile, "区域平衡机不存在: %s %s \n", pPGBlock->m_CompanyArray[i].szSlackSub, pPGBlock->m_CompanyArray[i].szSlackGen);
			}
			else
			{
				if (sqrt(pPGBlock->m_SynchronousMachineArray[nDev].fPlanP*pPGBlock->m_SynchronousMachineArray[nDev].fPlanP+pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ*pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ) < 0.001 || pPGBlock->m_SynchronousMachineArray[nDev].bOutage != 0)
					Log(m_lpszAbnormalLogFile, "区域平衡机停运: %s %s \n", pPGBlock->m_CompanyArray[i].szSlackSub, pPGBlock->m_CompanyArray[i].szSlackGen);

				if (pPGBlock->m_SynchronousMachineArray[nDev].fPlanV < 0.1)
					Log(m_lpszAbnormalLogFile, "区域平衡机必须是PV节点: %s %s \n", pPGBlock->m_CompanyArray[i].szSlackSub, pPGBlock->m_CompanyArray[i].szSlackGen);
			}
		}


		//	检查孤立设备
		//PGMemDBAbnorm_Alone(pPGBlock);
	}
}
