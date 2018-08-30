#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

extern	void	Log(const char* m_lpszPGMemDBLogFile, const char* pformat, ...);
namespace	PGMemDB
{
	void	PGFormIndexPointer(tagPGBlock* pPGBlock)
	{
		register int	i;
		int		nSub, nVolt, nNode, nDev;
		int		la_1, la_2, la_3, la_4, la_5, la_6, la_7, la_8, la_9, la_10;

		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();
		//	形成电压等级在厂站中的索引
		//	形成厂站的变压器索引
		la_1=0;
		la_2=0;
		la_3=0;
		la_4=0;
		pPGBlock->m_SubstationArray[0].nVoltageLevelRange=(short)la_1;
		pPGBlock->m_SubstationArray[0].nPowerTransformerRange=(short)la_2;
		pPGBlock->m_SubstationArray[0].nTransformerWindingRange=(short)la_3;
		pPGBlock->m_SubstationArray[0].nRectifierInverterRange=(short)la_4;
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=la_1; nVolt<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; nVolt++)
			{
				if (strcmp(pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0)
				{
					la_1 += 1;
				}
				else
				{
					goto STKV;
				}
			}
STKV:		pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange = (short)la_1;

			for (nDev=la_2; nDev<pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]; nDev++)
			{
				if (strcmp(pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_PowerTransformerArray[nDev].szSub) == 0)
				{
					la_2 += 1;
				}
				else
				{
					goto STTRAN;
				}
			}
STTRAN:		pPGBlock->m_SubstationArray[nSub+1].nPowerTransformerRange = (short)la_2;

			for (nDev=la_3; nDev<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nDev++)
			{
				if (strcmp(pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_TransformerWindingArray[nDev].szSub) == 0)
				{
					la_3 += 1;
				}
				else
				{
					goto STWIND;
				}
			}
STWIND:		pPGBlock->m_SubstationArray[nSub+1].nTransformerWindingRange = (short)la_3;

			for (nDev=la_4; nDev<pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER]; nDev++)
			{
				if (strcmp(pPGBlock->m_SubstationArray[nSub].szName, pPGBlock->m_RectifierInverterArray[nDev].szSub) == 0)
				{
					la_4 += 1;
				}
				else
				{
					goto STRI;
				}
			}
STRI:		pPGBlock->m_SubstationArray[nSub+1].nRectifierInverterRange = (short)la_4;
		}

		for (nVolt=0; nVolt<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; nVolt++)
		{
			pPGBlock->m_VoltageLevelArray[nVolt].nSubstationPtr=-1;
			for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
			{
				if (strcmp(pPGBlock->m_VoltageLevelArray[nVolt].szSub, pPGBlock->m_SubstationArray[nSub].szName) == 0)
				{
					pPGBlock->m_VoltageLevelArray[nVolt].nSubstationPtr=(short)nSub;
					break;
				}
			}
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; nDev++)
			pPGBlock->m_ConnectivityNodeArray[nDev].nVoltageLevelPtr=-1;

		la_1 = 0;
		la_2 = 0;
		la_3 = 0;
		la_4 = 0;
		la_5 = 0;
		la_6 = 0;
		la_7 = 0;
		la_8 = 0;
		la_9 = 0;
		la_10 = 0;
		pPGBlock->m_VoltageLevelArray[0].nBusbarSectionRange= (short)la_1;
		pPGBlock->m_VoltageLevelArray[0].nSynchronousMachineRange = (short)la_2;
		pPGBlock->m_VoltageLevelArray[0].nEnergyConsumerRange = (short)la_3;
		pPGBlock->m_VoltageLevelArray[0].nShuntCompensatorRange = (short)la_4;
		pPGBlock->m_VoltageLevelArray[0].nSeriesCompensatorRange = (short)la_5;
		pPGBlock->m_VoltageLevelArray[0].nBreakerRange = la_6;
		pPGBlock->m_VoltageLevelArray[0].nDisconnectorRange = la_7;
		pPGBlock->m_VoltageLevelArray[0].nGroundDisconnectorRange = la_8;
		pPGBlock->m_VoltageLevelArray[0].nConnecivityNodeRange = la_9;
		//pPGBlock->m_VoltageLevelArray[0].pRterminal = la_9;
		pPGBlock->m_VoltageLevelArray[0].nGroundTransformerRange = (short)la_10;

		for (nVolt=0; nVolt<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; nVolt++)
		{
			for (nDev=la_1; nDev<pPGBlock->m_nRecordNum[PG_BUSBARSECTION]; nDev++)
			{
				if (strcmp(pPGBlock->m_BusbarSectionArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0 &&
					strcmp(pPGBlock->m_BusbarSectionArray[nDev].szVolt, pPGBlock->m_VoltageLevelArray[nVolt].szName) == 0)
				{
					la_1 += 1;
				}
				else
				{
					goto KVBUS;
				}
			}
KVBUS:		pPGBlock->m_VoltageLevelArray[nVolt+1].nBusbarSectionRange = (short)la_1;

			for (nDev=la_2; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
			{
				if (strcmp(pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0 &&
					strcmp(pPGBlock->m_SynchronousMachineArray[nDev].szVolt, pPGBlock->m_VoltageLevelArray[nVolt].szName) == 0)
				{
					la_2 += 1;
				}
				else
				{
					goto KVUN;
				}
			}
KVUN:		pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange = (short)la_2;

			for (nDev=la_3; nDev<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; nDev++)
			{
				if (strcmp(pPGBlock->m_EnergyConsumerArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0 &&
					strcmp(pPGBlock->m_EnergyConsumerArray[nDev].szVolt, pPGBlock->m_VoltageLevelArray[nVolt].szName) == 0)
				{
					la_3 += 1;
				}
				else
				{
					goto KVLD;
				}
			}
KVLD:		pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange = (short)la_3;

			for (nDev=la_4; nDev<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; nDev++)
			{
				if (strcmp(pPGBlock->m_ShuntCompensatorArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0 &&
					strcmp(pPGBlock->m_ShuntCompensatorArray[nDev].szVolt, pPGBlock->m_VoltageLevelArray[nVolt].szName) == 0)
				{
					la_4 += 1;
				}
				else
				{
					goto KVPCP;
				}
			}
KVPCP:		pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange = (short)la_4;

			for (nDev=la_5; nDev<pPGBlock->m_nRecordNum[PG_SERIESCOMPENSATOR]; nDev++)
			{
				if (strcmp(pPGBlock->m_SeriesCompensatorArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0 &&
					strcmp(pPGBlock->m_SeriesCompensatorArray[nDev].szVolt, pPGBlock->m_VoltageLevelArray[nVolt].szName) == 0)
				{
					la_5 += 1;
				}
				else
				{
					goto KVSCP;
				}
			}
KVSCP:		pPGBlock->m_VoltageLevelArray[nVolt+1].nSeriesCompensatorRange = (short)la_5;

			for (nDev=la_6; nDev<pPGBlock->m_nRecordNum[PG_BREAKER]; nDev++)
			{
				if (strcmp(pPGBlock->m_BreakerArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0 &&
					strcmp(pPGBlock->m_BreakerArray[nDev].szVolt, pPGBlock->m_VoltageLevelArray[nVolt].szName) == 0)
				{
					la_6 += 1;
				}
				else
				{
					goto KVBR;
				}
			}
KVBR:		pPGBlock->m_VoltageLevelArray[nVolt+1].nBreakerRange = la_6;

			for (nDev=la_7; nDev<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; nDev++)
			{
				if (strcmp(pPGBlock->m_DisconnectorArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0 &&
					strcmp(pPGBlock->m_DisconnectorArray[nDev].szVolt, pPGBlock->m_VoltageLevelArray[nVolt].szName) == 0)
				{
					la_7 += 1;
				}
				else
				{
					goto KVSW;
				}
			}
KVSW:		pPGBlock->m_VoltageLevelArray[nVolt+1].nDisconnectorRange = la_7;

			for (nDev=la_8; nDev<pPGBlock->m_nRecordNum[PG_GROUNDDISCONNECTOR]; nDev++)
			{
				if (strcmp(pPGBlock->m_GroundDisconnectorArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0 &&
					strcmp(pPGBlock->m_GroundDisconnectorArray[nDev].szVolt, pPGBlock->m_VoltageLevelArray[nVolt].szName) == 0)
				{
					la_8 += 1;
				}
				else
				{
					goto KVGDIS;
				}
			}
KVGDIS:		pPGBlock->m_VoltageLevelArray[nVolt+1].nGroundDisconnectorRange = la_8;

			for (nDev=la_9; nDev<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; nDev++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nDev].szVolt, pPGBlock->m_VoltageLevelArray[nVolt].szName) == 0)
				{
					pPGBlock->m_ConnectivityNodeArray[nDev].nVoltageLevelPtr=(short)nVolt;
					la_9 += 1;
				}
				else
				{
					goto KVND;
				}
			}
KVND:		pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange = la_9;

			for (nDev=la_10; nDev<pPGBlock->m_nRecordNum[PG_GROUNDTRANSFORMER]; nDev++)
			{
				if (strcmp(pPGBlock->m_GroundTransformerArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0 &&
					strcmp(pPGBlock->m_GroundTransformerArray[nDev].szVolt, pPGBlock->m_VoltageLevelArray[nVolt].szName) == 0)
				{
					la_10 += 1;
				}
				else
				{
					goto KVGTRAN;
				}
			}
KVGTRAN:	pPGBlock->m_VoltageLevelArray[nVolt+1].nGroundTransformerRange = (short)la_10;

			//for (nDev=la_9; nDev<pPGBlock->m_nRecordNum[PG_TERMINAL]; nDev++)
			//{
			//	if (strcmp(pPGBlock->m_TerminalArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0 &&
			//		strcmp(pPGBlock->m_TerminalArray[nDev].szVolt, pPGBlock->m_VoltageLevelArray[nVolt].szName) == 0)
			//	{
			//		la_9 += 1;
			//	}
			//	else
			//	{
			//		goto KVTERM;
			//	}
			//}
			//KVTERM:
			//pPGBlock->m_VoltageLevelArray[nVolt+1].pRterminal = la_9;

			// for (nDev=la_10; nDev<pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER]; nDev++)
			// {
			// 	if (strcmp(pPGBlock->m_RectifierInverterArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szSub) == 0 &&
			// 		strcmp(pPGBlock->m_RectifierInverterArray[nDev].szVolt, pPGBlock->m_VoltageLevelArray[nVolt].szName) == 0)
			// 	{
			// 		la_10 += 1;
			// 	}
			// 	else
			// 	{
			// 		goto KVRI;
			// 	}
			// }
			//KVRI:
			//pPGBlock->m_VoltageLevelArray[nVolt+1].pRri = la_10;
		}

		//	形成节点----设备索引
		la_1 = 0;
		la_2 = 0;
		la_3 = 0;
		la_4 = 0;
		la_5 = 0;
		la_6 = 0;
		pPGBlock->m_ConnectivityNodeArray[0].nBreakerRange = la_1;
		pPGBlock->m_ConnectivityNodeArray[0].nDisconnectorRange = la_2;
		pPGBlock->m_ConnectivityNodeArray[0].nACLineSegmentRange = (short)la_3;
		pPGBlock->m_ConnectivityNodeArray[0].nDCLineSegmentRange = (short)la_4;
		pPGBlock->m_ConnectivityNodeArray[0].nTransformerWindingRange = (short)la_5;
		pPGBlock->m_ConnectivityNodeArray[0].nSeriesCompensatorRange = (short)la_6;
		for (nNode=0; nNode<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; nNode++)
		{
			for (nDev=la_1; nDev<pPGBlock->m_nRecordNum[PG_EDGEBREAKER]; nDev++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szSub, pPGBlock->m_EdgeBreakerArray[nDev].szSub) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szVolt, pPGBlock->m_EdgeBreakerArray[nDev].szVolt) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_EdgeBreakerArray[nDev].szNode) == 0)
				{
					la_1 += 1;
				}
				else
				{
					goto NDBR2;
				}
			}
NDBR2:		pPGBlock->m_ConnectivityNodeArray[nNode+1].nBreakerRange = la_1;

			for (nDev=la_2; nDev<pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]; nDev++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szSub, pPGBlock->m_EdgeDisconnectorArray[nDev].szSub) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szVolt, pPGBlock->m_EdgeDisconnectorArray[nDev].szVolt) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_EdgeDisconnectorArray[nDev].szNode) == 0)
				{
					la_2 += 1;
				}
				else
				{
					goto NDSW2;
				}
			}
NDSW2:		pPGBlock->m_ConnectivityNodeArray[nNode+1].nDisconnectorRange = la_2;

			for (nDev=la_3; nDev<pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]; nDev++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szSub, pPGBlock->m_EdgeACLineSegmentArray[nDev].szSub) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szVolt, pPGBlock->m_EdgeACLineSegmentArray[nDev].szVolt) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_EdgeACLineSegmentArray[nDev].szNode) == 0)
				{
					la_3 += 1;
				}
				else
				{
					goto NDACLN2;
				}
			}
NDACLN2:	pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange = (short)la_3;

			for (nDev=la_4; nDev<pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]; nDev++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szSub, pPGBlock->m_EdgeDCLineSegmentArray[nDev].szSub) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szVolt, pPGBlock->m_EdgeDCLineSegmentArray[nDev].szVolt) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_EdgeDCLineSegmentArray[nDev].szNode) == 0)
				{
					la_4 += 1;
				}
				else
				{
					goto NDDCLN2;
				}
			}
NDDCLN2:	pPGBlock->m_ConnectivityNodeArray[nNode+1].nDCLineSegmentRange = (short)la_4;

			for (nDev=la_5; nDev<pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]; nDev++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szSub, pPGBlock->m_EdgeTransformerWindingArray[nDev].szSub) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szVolt, pPGBlock->m_EdgeTransformerWindingArray[nDev].szVolt) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_EdgeTransformerWindingArray[nDev].szNode) == 0)
				{
					la_5 += 1;
				}
				else
				{
					goto NDXF2;
				}
			}
NDXF2:		pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange = (short)la_5;

			for (nDev=la_6; nDev<pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]; nDev++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szSub, pPGBlock->m_EdgeSeriesCompensatorArray[nDev].szSub) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szVolt, pPGBlock->m_EdgeSeriesCompensatorArray[nDev].szVolt) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_EdgeSeriesCompensatorArray[nDev].szNode) == 0)
				{
					la_6 += 1;
				}
				else
				{
					goto NDSCP2;
				}
			}
NDSCP2:		pPGBlock->m_ConnectivityNodeArray[nNode+1].nSeriesCompensatorRange = (short)la_6;
		}
		//	形成节点-设备索引

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; nDev++)
		{
			//pPGBlock->m_ConnectivityNodeArray[nDev].iRBus=pPGBlock->m_ConnectivityNodeArray[nDev].iRun=pPGBlock->m_ConnectivityNodeArray[nDev].iRld=pPGBlock->m_ConnectivityNodeArray[nDev].iRcp=-1;
			pPGBlock->m_ConnectivityNodeArray[nDev].nBusbarSectionPtr=-1;
		}

		//	形成节点母线索引
		//	形成母线电压和节点索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_BUSBARSECTION]; nDev++)
		{
			pPGBlock->m_BusbarSectionArray[nDev].nNode=-1;
			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_BusbarSectionArray[nDev].szSub, pPGBlock->m_BusbarSectionArray[nDev].szVolt);
			if (nVolt >= 0)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_BusbarSectionArray[nDev].szNode) == 0)
					{
						pPGBlock->m_BusbarSectionArray[nDev].nNode=nNode;
						pPGBlock->m_ConnectivityNodeArray[nNode].nBusbarSectionPtr=(short)nDev;
						break;
					}
				}
			}
		}
		//	形成母线电压和节点索引
		//	形成节点母线索引

		//	形成发电机节点索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			pPGBlock->m_SynchronousMachineArray[nDev].nNode=-1;
			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_SynchronousMachineArray[nDev].szVolt);
			if (nVolt < 0)
				continue;

			for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_SynchronousMachineArray[nDev].szNode) == 0)
				{
					pPGBlock->m_SynchronousMachineArray[nDev].nNode=nNode;
					//pPGBlock->m_ConnectivityNodeArray[nNode].iRun=(short)nDev;
					break;
				}
			}
		}
		//	形成发电机节点索引

		//	形成负荷类型和节点索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; nDev++)
		{
			pPGBlock->m_EnergyConsumerArray[nDev].nNode=-1;
			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_EnergyConsumerArray[nDev].szSub, pPGBlock->m_EnergyConsumerArray[nDev].szVolt);
			if (nVolt < 0)
				continue;

			for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_EnergyConsumerArray[nDev].szNode) == 0)
				{
					pPGBlock->m_EnergyConsumerArray[nDev].nNode=nNode;
					//pPGBlock->m_ConnectivityNodeArray[nNode].iRld=(short)nDev;
					break;
				}
			}
		}
		//	形成负荷类型和节点索引

		//	形成电容电抗器节点索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; nDev++)
		{
			pPGBlock->m_ShuntCompensatorArray[nDev].nNode=-1;
			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_ShuntCompensatorArray[nDev].szSub, pPGBlock->m_ShuntCompensatorArray[nDev].szVolt);
			if (nVolt < 0)
				continue;

			for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_ShuntCompensatorArray[nDev].szNode) == 0)
				{
					pPGBlock->m_ShuntCompensatorArray[nDev].nNode=nNode;
					//pPGBlock->m_ConnectivityNodeArray[nNode].iRcp=(short)nDev;
				break;
				}
			}
		}
		//	形成电容电抗器节点索引

		//	形成开关节点和设备索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_BREAKER]; nDev++)
		{
			pPGBlock->m_BreakerArray[nDev].nNodeI=pPGBlock->m_BreakerArray[nDev].nNodeJ=-1;
			pPGBlock->m_BreakerArray[nDev].nEdgeI=pPGBlock->m_BreakerArray[nDev].nEdgeJ=-1;
			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_BreakerArray[nDev].szSub, pPGBlock->m_BreakerArray[nDev].szVolt);
			if (nVolt < 0)
				continue;

			for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_BreakerArray[nDev].szNodeI) == 0)
				{
					pPGBlock->m_BreakerArray[nDev].nNodeI=nNode;
					for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nBreakerRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nBreakerRange; i++)
					{
						if (strcmp(pPGBlock->m_EdgeBreakerArray[i].szName, pPGBlock->m_BreakerArray[nDev].szName) == 0)
						{
							pPGBlock->m_EdgeBreakerArray[i].nBreaker=nDev;
							pPGBlock->m_BreakerArray[nDev].nEdgeI=i;
							break;
						}
					}
					break;
				}
			}
			for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_BreakerArray[nDev].szNodeJ) == 0)
				{
					pPGBlock->m_BreakerArray[nDev].nNodeJ=nNode;
					for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nBreakerRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nBreakerRange; i++)
					{
						if (strcmp(pPGBlock->m_EdgeBreakerArray[i].szName, pPGBlock->m_BreakerArray[nDev].szName) == 0)
						{
							pPGBlock->m_EdgeBreakerArray[i].nBreaker=nDev;
							pPGBlock->m_BreakerArray[nDev].nEdgeJ=i;
							break;
						}
					}
					break;
				}
			}
		}
		//	形成开关节点索引

		//	形成刀闸节点和设备索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; nDev++)
		{
			pPGBlock->m_DisconnectorArray[nDev].nNodeI=pPGBlock->m_DisconnectorArray[nDev].nNodeJ=-1;
			pPGBlock->m_DisconnectorArray[nDev].nEdgeI=pPGBlock->m_DisconnectorArray[nDev].nEdgeJ=-1;
			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_DisconnectorArray[nDev].szSub, pPGBlock->m_DisconnectorArray[nDev].szVolt);
			if (nVolt < 0)
				continue;

			for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_DisconnectorArray[nDev].szNodeI) == 0)
				{
					pPGBlock->m_DisconnectorArray[nDev].nNodeI=nNode;
					for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nDisconnectorRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nDisconnectorRange; i++)
					{
						if (strcmp(pPGBlock->m_EdgeDisconnectorArray[i].szName, pPGBlock->m_DisconnectorArray[nDev].szName) == 0)
						{
							pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector=nDev;
							pPGBlock->m_DisconnectorArray[nDev].nEdgeI=i;
							break;
						}
					}
					break;
				}
			}
			for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_DisconnectorArray[nDev].szNodeJ) == 0)
				{
					pPGBlock->m_DisconnectorArray[nDev].nNodeJ=nNode;
					for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nDisconnectorRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nDisconnectorRange; i++)
					{
						if (strcmp(pPGBlock->m_EdgeDisconnectorArray[i].szName, pPGBlock->m_DisconnectorArray[nDev].szName) == 0)
						{
							pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector=nDev;
							pPGBlock->m_DisconnectorArray[nDev].nEdgeJ=i;
							break;
						}
					}
					break;
				}
			}
		}
		//	形成刀闸节点索引

		//	形成接地刀闸节点和设备索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_GROUNDDISCONNECTOR]; nDev++)
		{
			pPGBlock->m_GroundDisconnectorArray[nDev].nNode=-1;
			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_GroundDisconnectorArray[nDev].szSub, pPGBlock->m_GroundDisconnectorArray[nDev].szVolt);
			if (nVolt < 0)
				continue;

			for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_GroundDisconnectorArray[nDev].szNode) == 0)
				{
					pPGBlock->m_GroundDisconnectorArray[nDev].nNode=nNode;
					break;
				}
			}
		}
		//	形成接地刀闸节点索引

		//	形成接地变节点和设备索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_GROUNDTRANSFORMER]; nDev++)
		{
			pPGBlock->m_GroundTransformerArray[nDev].nNode=-1;
			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_GroundTransformerArray[nDev].szSub, pPGBlock->m_GroundTransformerArray[nDev].szVolt);
			if (nVolt < 0)
				continue;

			for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_GroundTransformerArray[nDev].szNode) == 0)
				{
					pPGBlock->m_GroundTransformerArray[nDev].nNode=nNode;
					break;
				}
			}
		}
		//	形成接地变节点索引

		//	形成交流线路节点和设备索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nDev++)
		{
			pPGBlock->m_ACLineSegmentArray[nDev].nNodeI=
				pPGBlock->m_ACLineSegmentArray[nDev].nNodeJ=
				pPGBlock->m_ACLineSegmentArray[nDev].nEdgeI=
				pPGBlock->m_ACLineSegmentArray[nDev].nEdgeJ=-1;

			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_ACLineSegmentArray[nDev].szSubI, pPGBlock->m_ACLineSegmentArray[nDev].szVoltI);
			if (nVolt >= 0)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_ACLineSegmentArray[nDev].szNodeI) == 0)
					{
						pPGBlock->m_ACLineSegmentArray[nDev].nNodeI=nNode;
						for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange; i++)
						{
							if (strcmp(pPGBlock->m_ACLineSegmentArray[nDev].szName,	pPGBlock->m_EdgeACLineSegmentArray[i].szName) == 0 &&
								strcmp(pPGBlock->m_ACLineSegmentArray[nDev].szNodeI,	pPGBlock->m_EdgeACLineSegmentArray[i].szNode) == 0)
							{
								pPGBlock->m_EdgeACLineSegmentArray[i].nACLineSegment=(short)nDev;
								pPGBlock->m_ACLineSegmentArray[nDev].nEdgeI=(short)i;
								break;
							}
						}
						break;
					}
				}
			}

			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_ACLineSegmentArray[nDev].szSubJ, pPGBlock->m_ACLineSegmentArray[nDev].szVoltJ);
			if (nVolt >= 0)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_ACLineSegmentArray[nDev].szNodeJ) == 0)
					{
						pPGBlock->m_ACLineSegmentArray[nDev].nNodeJ=nNode;
						for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange; i++)
						{
							if (strcmp(pPGBlock->m_ACLineSegmentArray[nDev].szName,	pPGBlock->m_EdgeACLineSegmentArray[i].szName) == 0 &&
								strcmp(pPGBlock->m_ACLineSegmentArray[nDev].szNodeJ,	pPGBlock->m_EdgeACLineSegmentArray[i].szNode) == 0)
							{
								pPGBlock->m_EdgeACLineSegmentArray[i].nACLineSegment=(short)nDev;
								pPGBlock->m_ACLineSegmentArray[nDev].nEdgeJ=(short)i;
								break;
							}
						}
						break;
					}
				}
			}
			if (strlen(pPGBlock->m_ACLineSegmentArray[nDev].szLine) > 0)
			{
				for (i=0; i<pPGBlock->m_nRecordNum[PG_LINE]; i++)
				{
					if (strcmp(pPGBlock->m_ACLineSegmentArray[nDev].szLine, pPGBlock->m_LineArray[i].szName) == 0)
					{
						pPGBlock->m_ACLineSegmentArray[nDev].nLine=(short)i;
						break;
					}
				}
			}
		}
		//	形成交流线路节点和设备索引

		//	形成直流线路节点和设备索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]; nDev++)
		{
			pPGBlock->m_DCLineSegmentArray[nDev].nNodeI=
				pPGBlock->m_DCLineSegmentArray[nDev].nNodeJ=
				pPGBlock->m_DCLineSegmentArray[nDev].iRln2=
				pPGBlock->m_DCLineSegmentArray[nDev].zRln2=-1;

			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_DCLineSegmentArray[nDev].szSubI, pPGBlock->m_DCLineSegmentArray[nDev].szVoltI);
			if (nVolt >= 0)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_DCLineSegmentArray[nDev].szNodeI) == 0)
					{
						pPGBlock->m_DCLineSegmentArray[nDev].nNodeI=nNode;
						for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nDCLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nDCLineSegmentRange; i++)
						{
							if (strcmp(pPGBlock->m_DCLineSegmentArray[nDev].szName,	pPGBlock->m_EdgeDCLineSegmentArray[i].szName) == 0 &&
								strcmp(pPGBlock->m_DCLineSegmentArray[nDev].szNodeI,	pPGBlock->m_EdgeDCLineSegmentArray[i].szNode) == 0)
							{
								pPGBlock->m_EdgeDCLineSegmentArray[i].nDCLineSegment=(short)nDev;
								pPGBlock->m_DCLineSegmentArray[nDev].iRln2=(short)i;
								break;
							}
						}
						break;
					}
				}
			}

			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_DCLineSegmentArray[nDev].szSubJ, pPGBlock->m_DCLineSegmentArray[nDev].szVoltJ);
			if (nVolt >= 0)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_DCLineSegmentArray[nDev].szNodeJ) == 0)
					{
						pPGBlock->m_DCLineSegmentArray[nDev].nNodeJ=nNode;
						for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nDCLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nDCLineSegmentRange; i++)
						{
							if (strcmp(pPGBlock->m_DCLineSegmentArray[nDev].szName,	pPGBlock->m_EdgeDCLineSegmentArray[i].szName) == 0 &&
								strcmp(pPGBlock->m_DCLineSegmentArray[nDev].szNodeJ,	pPGBlock->m_EdgeDCLineSegmentArray[i].szNode) == 0)
							{
								pPGBlock->m_EdgeDCLineSegmentArray[i].nDCLineSegment=(short)nDev;
								pPGBlock->m_DCLineSegmentArray[nDev].zRln2=(short)i;
								break;
							}
						}
						break;
					}
				}
			}
			if (strlen(pPGBlock->m_DCLineSegmentArray[nDev].szLine) > 0)
			{
				for (i=0; i<pPGBlock->m_nRecordNum[PG_LINE]; i++)
				{
					if (strcmp(pPGBlock->m_DCLineSegmentArray[nDev].szLine, pPGBlock->m_LineArray[i].szName) == 0)
					{
						pPGBlock->m_DCLineSegmentArray[nDev].nLine=(short)i;
						break;
					}
				}
			}
		}
		//	形成直流线路节点和设备索引

		//	形成串联补偿节点和设备索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SERIESCOMPENSATOR]; nDev++)
		{
			pPGBlock->m_SeriesCompensatorArray[nDev].nNodeI=
				pPGBlock->m_SeriesCompensatorArray[nDev].nNodeJ=
				pPGBlock->m_SeriesCompensatorArray[nDev].iRscp2=
				pPGBlock->m_SeriesCompensatorArray[nDev].zRscp2=-1;

			nVolt=PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_SeriesCompensatorArray[nDev].szSub, pPGBlock->m_SeriesCompensatorArray[nDev].szVolt);
			if (nVolt >= 0)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_SeriesCompensatorArray[nDev].szNodeI) == 0)
					{
						pPGBlock->m_SeriesCompensatorArray[nDev].nNodeI=nNode;
						for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nSeriesCompensatorRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nSeriesCompensatorRange; i++)
						{
							if (strcmp(pPGBlock->m_SeriesCompensatorArray[nDev].szName,	pPGBlock->m_EdgeSeriesCompensatorArray[i].szName) == 0 &&
								strcmp(pPGBlock->m_SeriesCompensatorArray[nDev].szNodeI,	pPGBlock->m_EdgeSeriesCompensatorArray[i].szNode) == 0)
							{
								pPGBlock->m_EdgeSeriesCompensatorArray[i].nSeriesCompensator=(short)nDev;
								pPGBlock->m_SeriesCompensatorArray[nDev].iRscp2=(short)i;
								break;
							}
						}
						break;
					}
				}
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_SeriesCompensatorArray[nDev].szNodeJ) == 0)
					{
						pPGBlock->m_SeriesCompensatorArray[nDev].nNodeJ=nNode;
						for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nSeriesCompensatorRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nSeriesCompensatorRange; i++)
						{
							if (strcmp(pPGBlock->m_SeriesCompensatorArray[nDev].szName,	pPGBlock->m_EdgeSeriesCompensatorArray[i].szName) == 0 &&
								strcmp(pPGBlock->m_SeriesCompensatorArray[nDev].szNodeJ,	pPGBlock->m_EdgeSeriesCompensatorArray[i].szNode) == 0)
							{
								pPGBlock->m_EdgeSeriesCompensatorArray[i].nSeriesCompensator=(short)nDev;
								pPGBlock->m_SeriesCompensatorArray[nDev].zRscp2=(short)i;
								break;
							}
						}
						break;
					}
				}
			}
		}
		//	形成串联补偿节点和设备索引

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]; nDev++)
		{
			pPGBlock->m_PowerTransformerArray[nDev].nWindH=
				pPGBlock->m_PowerTransformerArray[nDev].nWindM=
				pPGBlock->m_PowerTransformerArray[nDev].nWindL=-1;

			if (strlen(pPGBlock->m_PowerTransformerArray[nDev].szWindH) > 0)
				pPGBlock->m_PowerTransformerArray[nDev].nWindH=(short)PGFindRecordbyKey(pPGBlock, PG_TRANSFORMERWINDING, pPGBlock->m_PowerTransformerArray[nDev].szSub, pPGBlock->m_PowerTransformerArray[nDev].szWindH);
			if (strlen(pPGBlock->m_PowerTransformerArray[nDev].szWindM) > 0)
				pPGBlock->m_PowerTransformerArray[nDev].nWindM=(short)PGFindRecordbyKey(pPGBlock, PG_TRANSFORMERWINDING, pPGBlock->m_PowerTransformerArray[nDev].szSub, pPGBlock->m_PowerTransformerArray[nDev].szWindM);
			if (strlen(pPGBlock->m_PowerTransformerArray[nDev].szWindL) > 0)
				pPGBlock->m_PowerTransformerArray[nDev].nWindL=(short)PGFindRecordbyKey(pPGBlock, PG_TRANSFORMERWINDING, pPGBlock->m_PowerTransformerArray[nDev].szSub, pPGBlock->m_PowerTransformerArray[nDev].szWindL);
		}
		//	形成变压器分接头类型、节点和设备索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nDev++)
		{
			pPGBlock->m_TransformerWindingArray[nDev].nNodeI=
				pPGBlock->m_TransformerWindingArray[nDev].nNodeJ=-1;
			pPGBlock->m_TransformerWindingArray[nDev].nTapChangerI=
				pPGBlock->m_TransformerWindingArray[nDev].nTapChangerJ=
				pPGBlock->m_TransformerWindingArray[nDev].nTran=
				pPGBlock->m_TransformerWindingArray[nDev].nEdgeI=
				pPGBlock->m_TransformerWindingArray[nDev].nEdgeJ=
				pPGBlock->m_TransformerWindingArray[nDev].nVoltI=
				pPGBlock->m_TransformerWindingArray[nDev].nVoltJ=-1;

			if (strlen(pPGBlock->m_TransformerWindingArray[nDev].szTran) > 0)
			{
				pPGBlock->m_TransformerWindingArray[nDev].nTran=(short)PGFindRecordbyKey(pPGBlock, PG_POWERTRANSFORMER, pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szTran);

				//for (i=0; i<pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]; i++)
				//{
				//	if (strcmp(pPGBlock->m_TransformerWindingArray[nDev].szTran, pPGBlock->m_PowerTransformerArray[i].szName) == 0)
				//	{
				//		pPGBlock->m_TransformerWindingArray[nDev].iRxf=(short)i;
				//		break;
				//	}
				//}
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_TAPCHANGER]; i++)
			{
				if (strcmp(pPGBlock->m_TransformerWindingArray[nDev].szTapChangerI, pPGBlock->m_TapChangerArray[i].szName) == 0)
				{
					pPGBlock->m_TransformerWindingArray[nDev].nTapChangerI=(short)i;
					break;
				}
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_TAPCHANGER]; i++)
			{
				if (strcmp(pPGBlock->m_TransformerWindingArray[nDev].szTapChangerJ, pPGBlock->m_TapChangerArray[i].szName) == 0)
				{
					pPGBlock->m_TransformerWindingArray[nDev].nTapChangerJ=(short)i;
					break;
				}
			}

			nVolt=pPGBlock->m_TransformerWindingArray[nDev].nVoltI=(short)PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szVoltI);
			if (pPGBlock->m_TransformerWindingArray[nDev].nVoltI >= 0)
			{
				if (pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI <= 0)
				{
					pPGBlock->m_TransformerWindingArray[nDev].fRatedkVI=pPGBlock->m_VoltageLevelArray[nVolt].nominalVoltage;
				}
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_TransformerWindingArray[nDev].szNodeI) == 0)
					{
						pPGBlock->m_TransformerWindingArray[nDev].nNodeI=nNode;
						for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange; i++)
						{
							if (strcmp(pPGBlock->m_TransformerWindingArray[nDev].szName,	pPGBlock->m_EdgeTransformerWindingArray[i].szName) == 0 &&
								strcmp(pPGBlock->m_TransformerWindingArray[nDev].szSub,	pPGBlock->m_EdgeTransformerWindingArray[i].szSub) == 0 &&
								strcmp(pPGBlock->m_TransformerWindingArray[nDev].szNodeI,	pPGBlock->m_EdgeTransformerWindingArray[i].szNode) == 0)
							{
								pPGBlock->m_TransformerWindingArray[nDev].nEdgeI=(short)i;
								break;
							}
						}
						break;
					}
				}
			}

			nVolt=pPGBlock->m_TransformerWindingArray[nDev].nVoltJ=(short)PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szVoltJ);
			if (pPGBlock->m_TransformerWindingArray[nDev].nVoltJ >= 0)
			{
				if (pPGBlock->m_TransformerWindingArray[nDev].fRatedkVJ <= 0)
				{
					pPGBlock->m_TransformerWindingArray[nDev].fRatedkVJ=pPGBlock->m_VoltageLevelArray[nVolt].nominalVoltage;
				}
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_TransformerWindingArray[nDev].szNodeJ)==0)
					{
						pPGBlock->m_TransformerWindingArray[nDev].nNodeJ=nNode;
						for (i=pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange; i++)
						{
							if (strcmp(pPGBlock->m_TransformerWindingArray[nDev].szName,	pPGBlock->m_EdgeTransformerWindingArray[i].szName) == 0 &&
								strcmp(pPGBlock->m_TransformerWindingArray[nDev].szSub,	pPGBlock->m_EdgeTransformerWindingArray[i].szSub) == 0 &&
								strcmp(pPGBlock->m_TransformerWindingArray[nDev].szNodeJ,	pPGBlock->m_EdgeTransformerWindingArray[i].szNode) == 0)
							{
								pPGBlock->m_TransformerWindingArray[nDev].nEdgeJ=(short)i;
								break;
							}
						}
						break;
					}
				}
			}
		}

		//	形成整流逆变器节点和设备索引
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER]; nDev++)
		{
			pPGBlock->m_RectifierInverterArray[nDev].nVolt1=pPGBlock->m_RectifierInverterArray[nDev].nVolt2=pPGBlock->m_RectifierInverterArray[nDev].nVolt3=-1;
			pPGBlock->m_RectifierInverterArray[nDev].nNode1=pPGBlock->m_RectifierInverterArray[nDev].nNode2=pPGBlock->m_RectifierInverterArray[nDev].nNode3=-1;

			pPGBlock->m_RectifierInverterArray[nDev].nVolt1=(short)PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_RectifierInverterArray[nDev].szSub, pPGBlock->m_RectifierInverterArray[nDev].szVolt1);
			if (pPGBlock->m_RectifierInverterArray[nDev].nVolt1 >= 0)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[pPGBlock->m_RectifierInverterArray[nDev].nVolt1].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[pPGBlock->m_RectifierInverterArray[nDev].nVolt1+1].nConnecivityNodeRange; nNode++)
				{
					if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_RectifierInverterArray[nDev].szNode1) == 0)
					{
						pPGBlock->m_RectifierInverterArray[nDev].nNode1=nNode;
						break;
					}
				}
			}
			pPGBlock->m_RectifierInverterArray[nDev].nVolt2=(short)PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_RectifierInverterArray[nDev].szSub, pPGBlock->m_RectifierInverterArray[nDev].szVolt2);
			if (pPGBlock->m_RectifierInverterArray[nDev].nVolt2 >= 0)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[pPGBlock->m_RectifierInverterArray[nDev].nVolt2].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[pPGBlock->m_RectifierInverterArray[nDev].nVolt2+1].nConnecivityNodeRange; nNode++)
				{
					if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_RectifierInverterArray[nDev].szNode2) == 0)
					{
						pPGBlock->m_RectifierInverterArray[nDev].nNode2=nNode;
						break;
					}
				}
			}
			pPGBlock->m_RectifierInverterArray[nDev].nVolt3=(short)PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_RectifierInverterArray[nDev].szSub, pPGBlock->m_RectifierInverterArray[nDev].szVolt3);
			if (pPGBlock->m_RectifierInverterArray[nDev].nVolt3 >= 0)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[pPGBlock->m_RectifierInverterArray[nDev].nVolt3].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[pPGBlock->m_RectifierInverterArray[nDev].nVolt3+1].nConnecivityNodeRange; nNode++)
				{
					if (strcmp(pPGBlock->m_ConnectivityNodeArray[nNode].szName, pPGBlock->m_RectifierInverterArray[nDev].szNode3) == 0)
					{
						pPGBlock->m_RectifierInverterArray[nDev].nNode3=nNode;
						break;
					}
				}
			}
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_BREAKER]; i++)
		{
			pPGBlock->m_EdgeBreakerArray[pPGBlock->m_BreakerArray[i].nEdgeI].nBreaker=i;
			pPGBlock->m_EdgeBreakerArray[pPGBlock->m_BreakerArray[i].nEdgeJ].nBreaker=i;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; i++)
		{
			pPGBlock->m_EdgeDisconnectorArray[pPGBlock->m_DisconnectorArray[i].nEdgeI].nDisconnector=i;
			pPGBlock->m_EdgeDisconnectorArray[pPGBlock->m_DisconnectorArray[i].nEdgeJ].nDisconnector=i;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
		{
			pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_ACLineSegmentArray[i].nEdgeI].nACLineSegment=(short)i;
			pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_ACLineSegmentArray[i].nEdgeJ].nACLineSegment=(short)i;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]; i++)
		{
			pPGBlock->m_EdgeDCLineSegmentArray[pPGBlock->m_DCLineSegmentArray[i].iRln2].nDCLineSegment=(short)i;
			pPGBlock->m_EdgeDCLineSegmentArray[pPGBlock->m_DCLineSegmentArray[i].zRln2].nDCLineSegment=(short)i;
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_SERIESCOMPENSATOR]; i++)
		{
			pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_SeriesCompensatorArray[i].iRscp2].nSeriesCompensator=(short)i;
			pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_SeriesCompensatorArray[i].zRscp2].nSeriesCompensator=(short)i;
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
		{
			pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[i].nEdgeI].nTransformerWinding=(short)i;
			pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_TransformerWindingArray[i].nEdgeJ].nTransformerWinding=(short)i;
		}

		//	形成厂站类型
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nDev++)
		{
			pPGBlock->m_SubstationArray[nDev].st_type = PGEnumst_type_Substation;
			for (i=0; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
			{
				if (strcmp(pPGBlock->m_SynchronousMachineArray[i].szSub, pPGBlock->m_SubstationArray[nDev].szName) == 0)
				{
					pPGBlock->m_SubstationArray[nDev].st_type = PGEnumst_type_Plant;
					break;
				}
			}
		}
		//	形成厂站类型

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(m_lpszPGMemDBLogFile, "formIndexPointer，耗时%d毫秒\n", nDur);
	}
}
