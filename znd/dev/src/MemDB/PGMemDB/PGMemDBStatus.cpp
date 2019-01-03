//	在本模块前已经设置岛内所有设备投运，本模块判断岛内投运设备是否单侧停运。
#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

extern	void	Log(const char* m_lpszPGMemDBLogFile, char* pformat, ...);
namespace PGMemDB 
{
	//	对于3/2线路或变压器，因为该接线下所有设备是通过节点判断，在BUSIJ中有所反映。
	void powerGridStatus_CheckLine(tagPGBlock* pPGBlock)
	{
		register int	i;
		int		nConBra, nConSht, nConBus;
		int		nVolt, nLine, nDev;
		int		nNodeNum, nNodeArray[1000];

		//	线路两侧有一侧连系统（可能是单侧备用），本循环就是判断单侧备用
		for (nLine=0; nLine<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nLine++)
		{
			if (pPGBlock->m_ACLineSegmentArray[nLine].bOutage != 0)
				continue;

			//log_info("线路单侧备用判断 %s (%s-%s-%s)\n", pPGBlock->m_ACLineSegmentArray[nLine].szName, pPGBlock->m_ACLineSegmentArray[nLine].szSubI, pPGBlock->m_ACLineSegmentArray[nLine].szSubJ, pPGBlock->m_ACLineSegmentArray[nLine].szVoltI);

			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_ACLineSegmentArray[nLine].szSubI, pPGBlock->m_ACLineSegmentArray[nLine].szVoltI);
			PGTraverseVolt(pPGBlock, pPGBlock->m_ACLineSegmentArray[nLine].nNodeI, Y_CheckStatus, Y_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
			nConSht=nConBra=nConBus=0;
			for (i=0; i<nNodeNum; i++)
			{
				nConBra += (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange+
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange+
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nSeriesCompensatorRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nSeriesCompensatorRange);
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
				{
					if (pPGBlock->m_SynchronousMachineArray[nDev].nNode == nNodeArray[i])
					{
						nConSht++;
						break;
					}
				}
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; nDev++)
				{
					if (pPGBlock->m_EnergyConsumerArray[nDev].nNode == nNodeArray[i])
					{
						nConSht++;
						break;
					}
				}
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; nDev++)
				{
					if (pPGBlock->m_ShuntCompensatorArray[nDev].nNode == nNodeArray[i])
					{
						nConSht++;
						break;
					}
				}
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange; nDev++)
				{
					if (pPGBlock->m_BusbarSectionArray[nDev].nNode == nNodeArray[i])
					{
						nConBus++;
						break;
					}
				}
			}
			if (nConBra <= 1 && nConSht == 0 && nConBus == 0)
			{
				pPGBlock->m_ACLineSegmentArray[nLine].bOutage = 1;
				log_info("    线路I不连接设备 %s (%s-%s-%s)\n", pPGBlock->m_ACLineSegmentArray[nLine].szName, pPGBlock->m_ACLineSegmentArray[nLine].szSubI, pPGBlock->m_ACLineSegmentArray[nLine].szSubJ, pPGBlock->m_ACLineSegmentArray[nLine].szVoltI);
			}

			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_ACLineSegmentArray[nLine].szSubJ, pPGBlock->m_ACLineSegmentArray[nLine].szVoltJ);
			PGTraverseVolt(pPGBlock, pPGBlock->m_ACLineSegmentArray[nLine].nNodeJ, Y_CheckStatus, Y_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
			nConSht=nConBra=nConBus=0;
			for (i=0; i<nNodeNum; i++)
			{
				nConBra += (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange+
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange+
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nSeriesCompensatorRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nSeriesCompensatorRange);
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
				{
					if (pPGBlock->m_SynchronousMachineArray[nDev].nNode == nNodeArray[i])
					{
						nConSht++;
						break;
					}
				}
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; nDev++)
				{
					if (pPGBlock->m_EnergyConsumerArray[nDev].nNode == nNodeArray[i])
					{
						nConSht++;
						break;
					}
				}
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; nDev++)
				{
					if (pPGBlock->m_ShuntCompensatorArray[nDev].nNode == nNodeArray[i])
					{
						nConSht++;
						break;
					}
				}
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange; nDev++)
				{
					if (pPGBlock->m_BusbarSectionArray[nDev].nNode == nNodeArray[i])
					{
						nConBus++;
						break;
					}
				}
			}
			if (nConBra <= 1 && nConSht == 0 && nConBus == 0)
			{
				pPGBlock->m_ACLineSegmentArray[nLine].bOutage += 2;
				log_info("    线路J不连接设备 %s (%s-%s-%s)\n", pPGBlock->m_ACLineSegmentArray[nLine].szName, pPGBlock->m_ACLineSegmentArray[nLine].szSubI, pPGBlock->m_ACLineSegmentArray[nLine].szSubJ, pPGBlock->m_ACLineSegmentArray[nLine].szVoltI);
			}
		}
		
		for (nLine=0; nLine<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nLine++)
		{
			if (pPGBlock->m_ACLineSegmentArray[nLine].bOutage != 0)
			{
				//log_info("检修或备用线路 %s (%d-%d-%d)\n", 
				//	pPGBlock->m_ACLineSegmentArray[nLine].szName, 
				//	pPGBlock->m_ACLineSegmentArray[nLine].bOutage, 
				//	pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_ACLineSegmentArray[nLine].iRln2].lnop, 
				//	pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_ACLineSegmentArray[nLine].zRln2].lnop);
				//log_info("检修或备用线路 %s (%d)\n", pPGBlock->m_ACLineSegmentArray[nLine].szName, pPGBlock->m_ACLineSegmentArray[nLine].bOutage);
			}
		}
	}

	void powerGridStatus_CheckTran_2Coil(tagPGBlock* pPGBlock)
	{
		register int	i;
		int		nConBra, nConSht, nConBus;
		int		nSub, nVolt, nTran, nWind, nDev;
		int		nNodeNum, nNodeArray[1000];

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nTran=pPGBlock->m_SubstationArray[nSub].nPowerTransformerRange; nTran<pPGBlock->m_SubstationArray[nSub+1].nPowerTransformerRange; nTran++)
			{
				if (pPGBlock->m_PowerTransformerArray[nTran].nWindNum != 1)
					continue;

				nWind=pPGBlock->m_PowerTransformerArray[nTran].nWindH;
				if (nWind < 0)
					continue;
				if (pPGBlock->m_TransformerWindingArray[nWind].bOutage != 0)
					continue;

				nVolt=pPGBlock->m_TransformerWindingArray[nWind].nVoltI;
				PGTraverseVolt(pPGBlock, pPGBlock->m_TransformerWindingArray[nWind].nNodeI, Y_CheckStatus, Y_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
				nConSht=nConBra=nConBus=0;
				for (i=0; i<nNodeNum; i++)
				{
					nConBra += (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange+
						pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange+
						pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nSeriesCompensatorRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nSeriesCompensatorRange);
					for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
					{
						if (pPGBlock->m_SynchronousMachineArray[nDev].nNode == nNodeArray[i])
						{
							nConSht++;
							break;
						}
					}
					for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; nDev++)
					{
						if (pPGBlock->m_EnergyConsumerArray[nDev].nNode == nNodeArray[i])
						{
							nConSht++;
							break;
						}
					}
					for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; nDev++)
					{
						if (pPGBlock->m_ShuntCompensatorArray[nDev].nNode == nNodeArray[i])
						{
							nConSht++;
							break;
						}
					}
					for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange; nDev++)
					{
						if (pPGBlock->m_BusbarSectionArray[nDev].nNode == nNodeArray[i])
						{
							nConBus++;
							break;
						}
					}
				}

				//log_info("  I(%d)=%d %d %d\n", pPGBlock->m_TransformerWindingArray[nWind].nNodeI, nConBra, nConSht, nConBus);

				if (nConSht == 0 && nConBus == 0 && nConBra <= 1)
				{
					pPGBlock->m_TransformerWindingArray[nWind].bOutage = 1;
					//log_info("    变压器I不连接设备 %s-%s\n", pPGBlock->m_TransformerWindingArray[nWind].szSub, pPGBlock->m_TransformerWindingArray[nWind].szName);
				}

				nVolt=pPGBlock->m_TransformerWindingArray[nWind].nVoltJ;
				PGTraverseVolt(pPGBlock, pPGBlock->m_TransformerWindingArray[nWind].nNodeJ, Y_CheckStatus, Y_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
				nConSht=nConBra=nConBus=0;
				for (i=0; i<nNodeNum; i++)
				{
					nConBra += (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange+
						pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange+
						pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nSeriesCompensatorRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nSeriesCompensatorRange);
					for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
					{
						if (pPGBlock->m_SynchronousMachineArray[nDev].nNode == nNodeArray[i])
						{
							nConSht++;
							break;
						}
					}
					for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; nDev++)
					{
						if (pPGBlock->m_EnergyConsumerArray[nDev].nNode == nNodeArray[i])
						{
							nConSht++;
							break;
						}
					}
					for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; nDev++)
					{
						if (pPGBlock->m_ShuntCompensatorArray[nDev].nNode == nNodeArray[i])
						{
							nConSht++;
							break;
						}
					}
					for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange; nDev++)
					{
						if (pPGBlock->m_BusbarSectionArray[nDev].nNode == nNodeArray[i])
						{
							nConBus++;
							break;
						}
					}
				}
				//log_info("  J(%d)=%d %d %d\n", pPGBlock->m_TransformerWindingArray[nWind].nNodeJ, nConBra, nConSht, nConBus);
				if (nConSht == 0 && nConBus == 0 && nConBra <= 1)
				{
					pPGBlock->m_TransformerWindingArray[nWind].bOutage = 2;
					//log_info("    变压器J不连接设备 %s-%s\n", pPGBlock->m_TransformerWindingArray[nWind].szSub, pPGBlock->m_TransformerWindingArray[nWind].szName);
				}
			}
		}
	}

	void  powerGridStatus_CheckTran_3Coil(tagPGBlock* pPGBlock)
	{
		register int	i;
		int		nConBra, nConBus, nConSht;
		int		nSub, nVolt, nTran, nWind, nDev;
		int		nNodeNum, nNodeArray[1000];
		std::vector<unsigned char>	bTranProcArray;
		std::vector<int>			nWindArray;
		int		nTranMidNode, nTranWindNode;

		bTranProcArray.resize(pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING], 0);

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nTran=pPGBlock->m_SubstationArray[nSub].nPowerTransformerRange; nTran<pPGBlock->m_SubstationArray[nSub+1].nPowerTransformerRange; nTran++)
			{
				if (pPGBlock->m_PowerTransformerArray[nTran].nWindNum != 3)
					continue;

				nWindArray.clear();
				nWindArray.push_back(pPGBlock->m_PowerTransformerArray[nTran].nWindH);
				nWindArray.push_back(pPGBlock->m_PowerTransformerArray[nTran].nWindM);
				nWindArray.push_back(pPGBlock->m_PowerTransformerArray[nTran].nWindL);
				nTranMidNode =
					(pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindH].nNodeI == pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindL].nNodeI ||
					 pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindH].nNodeI == pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindL].nNodeJ) ?
					nTranMidNode=pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindH].nNodeI : nTranMidNode=pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindH].nNodeJ;

				for (nWind=0; nWind<(int)nWindArray.size(); nWind++)
				{
					if (pPGBlock->m_TransformerWindingArray[nWindArray[nWind]].bOutage != 0)
						continue;

					nTranWindNode=(pPGBlock->m_TransformerWindingArray[nWindArray[nWind]].nNodeI == nTranMidNode) ? pPGBlock->m_TransformerWindingArray[nWindArray[nWind]].nNodeJ : pPGBlock->m_TransformerWindingArray[nWindArray[nWind]].nNodeI;

					nVolt=pPGBlock->m_ConnectivityNodeArray[nTranWindNode].nVoltageLevelPtr;
					PGTraverseVolt(pPGBlock, nTranWindNode, Y_CheckStatus, Y_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
					nConSht=nConBra=nConBus=0;
					for (i=0; i<nNodeNum; i++)
					{
						nConBra += (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange+
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange+
							pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nSeriesCompensatorRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nSeriesCompensatorRange);
						for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
						{
							if (pPGBlock->m_SynchronousMachineArray[nDev].nNode == nNodeArray[i])
							{
								nConSht++;
								break;
							}
						}
						for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; nDev++)
						{
							if (pPGBlock->m_EnergyConsumerArray[nDev].nNode == nNodeArray[i])
							{
								nConSht++;
								break;
							}
						}
						for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; nDev++)
						{
							if (pPGBlock->m_ShuntCompensatorArray[nDev].nNode == nNodeArray[i])
							{
								nConSht++;
								break;
							}
						}
						for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nBusbarSectionRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange; nDev++)
						{
							if (pPGBlock->m_BusbarSectionArray[nDev].nNode == nNodeArray[i])
							{
								nConBus++;
								break;
							}
						}
					}

					if (nConSht == 0 && nConBus == 0 && nConBra <= 1)
					{
						if (pPGBlock->m_TransformerWindingArray[nWindArray[nWind]].nNodeI == nTranWindNode)
							pPGBlock->m_TransformerWindingArray[nWindArray[nWind]].bOutage = 1;
						else
							pPGBlock->m_TransformerWindingArray[nWindArray[nWind]].bOutage = 2;

						log_info("三卷变压器(%d)备用 %s-%s-%s\n", nWind, pPGBlock->m_TransformerWindingArray[nWindArray[nWind]].szSub, pPGBlock->m_TransformerWindingArray[nWindArray[nWind]].szVoltI, pPGBlock->m_TransformerWindingArray[nWindArray[nWind]].szName);
					}
				}
			}
		}

		/*///////////////////////////////////////////////////////////////////////////
		//	变压器的判断过程.
		///////////////////////////////////////////////////////////////////////////*/

		for (nWind=0; nWind<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nWind++)
		{
			if (pPGBlock->m_TransformerWindingArray[nWind].bOutage != 0)
				log_info("变压器状态 %s-%s (检修=%d)\n", pPGBlock->m_TransformerWindingArray[nWind].szSub, pPGBlock->m_TransformerWindingArray[nWind].szName, pPGBlock->m_TransformerWindingArray[nWind].bOutage);
		}
	}

	void  powerGridStatus_CheckTran(tagPGBlock* pPGBlock)
	{
// 		int		nSub, nDev;

		powerGridStatus_CheckTran_2Coil(pPGBlock);
		powerGridStatus_CheckTran_3Coil(pPGBlock);

// 		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
// 		{
// 			for (nDev=pPGBlock->m_SubstationArray[nSub].nTransformerWindingPtr; nDev<pPGBlock->m_SubstationArray[nSub+1].nTransformerWindingPtr; nDev++)
// 			{
// 				pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[nDev].iRWind2].bOutage=0;
// 				pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[nDev].zRWind2].bOutage=0;
// 				if (pPGBlock->m_TransformerWindingArray[nDev].bOutage == 3)
// 				{
// 					pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[nDev].iRWind2].bOutage=1;
// 					pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[nDev].zRWind2].bOutage=1;
// 				}
// 				else
// 				{
// 					if (pPGBlock->m_TransformerWindingArray[nDev].bOutage == 1)
// 					{
// 						pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[nDev].iRWind2].bOutage=1;
// 						pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[nDev].zRWind2].bOutage=0;
// 					}
// 					else if (pPGBlock->m_TransformerWindingArray[nDev].bOutage == 2)
// 					{
// 						pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[nDev].iRWind2].bOutage=0;
// 						pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[nDev].zRWind2].bOutage=1;
// 					}
// 				}
// 			}
// 		}
	}

	//	remove对于单端设备表示投退，对于双端设备，＝1表示I侧退，＝2表示J侧退，＝3表示两侧退
	void	PGMemDBStatus(tagPGBlock* pPGBlock, const int bOneIsland)
	{
		register int	i;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
			pPGBlock->m_ACLineSegmentArray[i].bOutage=0;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
			pPGBlock->m_TransformerWindingArray[i].bOutage=0;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
			pPGBlock->m_SynchronousMachineArray[i].bOutage=0;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; i++)
			pPGBlock->m_EnergyConsumerArray[i].bOutage=0;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; i++)
			pPGBlock->m_ShuntCompensatorArray[i].bOutage=0;
		return;


		float	fMaxIsland;
		int		nMaxIsland;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
			pPGBlock->m_ACLineSegmentArray[i].bOutage=3;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
			pPGBlock->m_TransformerWindingArray[i].bOutage=3;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
			pPGBlock->m_SynchronousMachineArray[i].bOutage=1;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; i++)
			pPGBlock->m_EnergyConsumerArray[i].bOutage=1;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; i++)
			pPGBlock->m_ShuntCompensatorArray[i].bOutage=1;

		/*///////////////////////////////////////////////////////////////////////////
		//	以上是初始化和为状态判断作准备
		///////////////////////////////////////////////////////////////////////////*/

		PGMemDBIsland(pPGBlock);

		std::vector<float>	fIslandUnitPArray;
		fIslandUnitPArray.resize(pPGBlock->m_nRecordNum[PG_ISLAND], 0);
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
			fIslandUnitPArray[pPGBlock->m_SynchronousMachineArray[i].nIsland] += pPGBlock->m_SynchronousMachineArray[i].fPMax;

		fMaxIsland=0;
		nMaxIsland=-1;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ISLAND]; i++)
		{
			if (fIslandUnitPArray[i] > fMaxIsland)
			{
				fMaxIsland=fIslandUnitPArray[i];
				nMaxIsland=i;
			}
		}

		if (bOneIsland)
		{
			//	查找最大的有源岛
			for (i=0; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
			{
				if (pPGBlock->m_SynchronousMachineArray[i].nNode < 0)
					continue;

				if (pPGBlock->m_SynchronousMachineArray[i].nIsland == nMaxIsland)
				{
					pPGBlock->m_SynchronousMachineArray[i].bOutage=0;
				}
				else
				{
					pPGBlock->m_SynchronousMachineArray[i].fP=
						pPGBlock->m_SynchronousMachineArray[i].fQ=
							pPGBlock->m_SynchronousMachineArray[i].fA=
								pPGBlock->m_SynchronousMachineArray[i].fV=
									pPGBlock->m_SynchronousMachineArray[i].fD=0;
				}
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; i++)
			{
				if (pPGBlock->m_EnergyConsumerArray[i].nNode < 0)
					continue;

				if (pPGBlock->m_EnergyConsumerArray[i].nIsland == nMaxIsland)
				{
					pPGBlock->m_EnergyConsumerArray[i].bOutage=0;
				}
				else
				{
					pPGBlock->m_EnergyConsumerArray[i].fP=
						pPGBlock->m_EnergyConsumerArray[i].fQ=
							pPGBlock->m_EnergyConsumerArray[i].fA=0;
				}
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; i++)
			{
				if (pPGBlock->m_ShuntCompensatorArray[i].nNode < 0)
					continue;
				if (pPGBlock->m_ShuntCompensatorArray[i].nIsland == nMaxIsland)
					pPGBlock->m_ShuntCompensatorArray[i].bOutage=0;
				else
					pPGBlock->m_ShuntCompensatorArray[i].fQ=pPGBlock->m_ShuntCompensatorArray[i].fA=0;
			}
			//	岛内所有的设备投运

			//	与岛相连的设备设置投运，在CHECKLINE和CHECKTRAN中判断是否停运
			for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
			{
				if (pPGBlock->m_ACLineSegmentArray[i].nIsland == nMaxIsland)
				{
					pPGBlock->m_ACLineSegmentArray[i].bOutage=0;
					//pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_ACLineSegmentArray[i].iRln2].lnop=pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_ACLineSegmentArray[i].zRln2].lnop=0;
				}
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
			{
				if (pPGBlock->m_TransformerWindingArray[i].nIsland == nMaxIsland)
				{
					pPGBlock->m_TransformerWindingArray[i].bOutage=0;
					//pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[i].iRWind2].bOutage=pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[i].zRWind2].bOutage=0;
				}
			}
		}
		else
		{
			for (i=0; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
			{
				if (pPGBlock->m_SynchronousMachineArray[i].nNode < 0)
					continue;

				if (fabs(pPGBlock->m_IslandArray[pPGBlock->m_SynchronousMachineArray[i].nIsland].fGenP) > 0.1)
				{
					pPGBlock->m_SynchronousMachineArray[i].bOutage=0;
				}
				else
				{
					pPGBlock->m_SynchronousMachineArray[i].fP=
						pPGBlock->m_SynchronousMachineArray[i].fQ=
							pPGBlock->m_SynchronousMachineArray[i].fA=
								pPGBlock->m_SynchronousMachineArray[i].fV=
									pPGBlock->m_SynchronousMachineArray[i].fD=0;
				}
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; i++)
			{
				if (pPGBlock->m_EnergyConsumerArray[i].nNode < 0)
					continue;

				if (pPGBlock->m_IslandArray[pPGBlock->m_EnergyConsumerArray[i].nIsland].fGenP > 0.1)
				{
					pPGBlock->m_EnergyConsumerArray[i].bOutage=0;
				}
				else
				{
					pPGBlock->m_EnergyConsumerArray[i].fP=
						pPGBlock->m_EnergyConsumerArray[i].fQ=
							pPGBlock->m_EnergyConsumerArray[i].fA=0;
				}
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; i++)
			{
				if (pPGBlock->m_ShuntCompensatorArray[i].nNode < 0)
					continue;
				if (pPGBlock->m_IslandArray[pPGBlock->m_ShuntCompensatorArray[i].nIsland].fGenP > 0.1)
					pPGBlock->m_ShuntCompensatorArray[i].bOutage=0;
				else
					pPGBlock->m_ShuntCompensatorArray[i].fQ=pPGBlock->m_ShuntCompensatorArray[i].fA=0;
			}
			//	岛内所有的设备投运

			//	与岛相连的设备设置投运，在CHECKLINE和CHECKTRAN中判断是否停运
			for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
			{
				if (pPGBlock->m_IslandArray[pPGBlock->m_ACLineSegmentArray[i].nIsland].fGenP > 0.1)
				{
					pPGBlock->m_ACLineSegmentArray[i].bOutage=0;
					//pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_ACLineSegmentArray[i].iRln2].lnop=pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_ACLineSegmentArray[i].zRln2].lnop=0;
				}
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
			{
				if (pPGBlock->m_IslandArray[pPGBlock->m_TransformerWindingArray[i].nIsland].fGenP > 0.1)
				{
					pPGBlock->m_TransformerWindingArray[i].bOutage=0;
					//pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[i].iRWind2].bOutage=pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[i].zRWind2].bOutage=0;
				}
			}
		}

		//	当需要删除悬空支路则放开以下两个函数。
// 		//	当线路两侧都能与电岛连接(OPEN), 设置线路备用(单侧或两侧), 对于3/2等特殊接线不考虑
// 		//	不考虑操作模型则不需要考虑设备备用情况。
		powerGridStatus_CheckLine(pPGBlock);
		powerGridStatus_CheckTran(pPGBlock);
	}
}
