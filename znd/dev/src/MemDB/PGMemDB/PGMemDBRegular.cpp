#include "stdafx.h"
#include "PGMemDB.h"

namespace	PGMemDB
{
	void	PGRegularByResID(tagPGBlock* pPGBlock)
	{
		register int	i;
		int		nRec;
		int		bParsed;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
		{
			if (strlen(pPGBlock->m_ACLineSegmentArray[i].szVoltJ) <= 0)
				strcpy(pPGBlock->m_ACLineSegmentArray[i].szVoltJ, pPGBlock->m_ACLineSegmentArray[i].szVoltI);
		}

		//	SubControlArea中确定Company
		for (nRec=0; nRec<pPGBlock->m_nRecordNum[PG_COMPANY]; nRec++)
		{
			if (strlen(pPGBlock->m_CompanyArray[nRec].szResID) <= 0)
				continue;
			for (i=0; i<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; i++)
			{
				bParsed=0;
				if (STRICMP(pPGBlock->m_SubcontrolAreaArray[i].szCompany, pPGBlock->m_CompanyArray[nRec].szResID) == 0)
				{
					strcpy(pPGBlock->m_SubcontrolAreaArray[i].szCompany, pPGBlock->m_CompanyArray[nRec].szName);
					bParsed=1;
					break;
				}
				if (!bParsed)
				{
					//				PGMemDBLog("SubControlArea中[Name=%s]的Company[ResID=%s]无法解析\n", pPGBlock->m_SubcontrolAreaArray[i].szName, pPGBlock->m_SubcontrolAreaArray[i].szCompany);
				}
			}
		}

		//	Substation中确定SubControlArea和Company
		for (nRec=0; nRec<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; nRec++)
		{
			if (strlen(pPGBlock->m_SubcontrolAreaArray[nRec].szResID) <= 0)
				continue;
			for (i=0; i<pPGBlock->m_nRecordNum[PG_SUBSTATION]; i++)
			{
				bParsed=0;
				if (STRICMP(pPGBlock->m_SubstationArray[i].szSubcontrolArea, pPGBlock->m_SubcontrolAreaArray[nRec].szResID) == 0)
				{
					strcpy(pPGBlock->m_SubstationArray[i].szSubcontrolArea, pPGBlock->m_SubcontrolAreaArray[nRec].szName);
					strcpy(pPGBlock->m_SubstationArray[i].szCompany, pPGBlock->m_SubcontrolAreaArray[nRec].szCompany);
					{
						bParsed=1;
						break;
					}
				}
				if (!bParsed)
				{
					//				PGMemDBLog("Substation中[Name=%s]的SubControlArea[ResID=%s]无法解析\n", pPGBlock->m_SubstationArray[i].szName, pPGBlock->m_SubstationArray[i].szSubcontrolArea);
				}
			}
		}

		//	VoltageLevel中确定Substation
		for (nRec=0; nRec<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nRec++)
		{
			if (strlen(pPGBlock->m_SubstationArray[nRec].szResID) <= 0)
				continue;
			for (i=0; i<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; i++)
			{
				bParsed=0;
				if (STRICMP(pPGBlock->m_VoltageLevelArray[i].szSub, pPGBlock->m_SubstationArray[nRec].szResID) == 0)
				{
					strcpy(pPGBlock->m_VoltageLevelArray[i].szSub, pPGBlock->m_SubstationArray[nRec].szName);
					{
						bParsed=1;
						break;
					}
				}
				if (!bParsed)
				{
					//				PGMemDBLog("VoltageLevel中[Name=%s]的Substation[ResID=%s]无法解析\n", pPGBlock->m_VoltageLevelArray[i].szName, pPGBlock->m_VoltageLevelArray[i].szSub);
				}
			}
		}

		// 	//	Terminal中确定Substation和VoltageLevel
		// 	for (nRec=0; nRec<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; nRec++)
		// 	{
		// 		if (strlen(pPGBlock->m_VoltageLevelArray[nRec].szResID) <= 0)
		// 		{
		// 			continue;
		// 		}
		// 		for (i=0; i<pPGBlock->m_nRecordNum[PG_TERMINAL]; i++)
		// 		{
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_TerminalArray[i].szVolt, pPGBlock->m_VoltageLevelArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_TerminalArray[i].szSub, pPGBlock->m_VoltageLevelArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_TerminalArray[i].szVolt, pPGBlock->m_VoltageLevelArray[nRec].szName);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("Terminal中[Name=%s]的VoltageLevel[ResID=%s]无法解析\n", pPGBlock->m_TerminalArray[i].szName, pPGBlock->m_TerminalArray[i].szVolt);
		// 			}
		// 		}
		// 	}
		// 
		// 	for (nRec=0; nRec<pPGBlock->m_nRecordNum[PG_TERMINAL]; nRec++)
		// 	{
		// 		if (strlen(pPGBlock->m_TerminalArray[nRec].szResID) <= 0)
		// 		{
		// 			continue;
		// 		}
		// 		//	由BusbarSection的Terminal确定BusbarSection的Substation、VoltageLevel和ConnectivityNode
		// 		for (i=0; i<pPGBlock->m_nRecordNum[PG_BUSBARSECTION]; i++)
		// 		{
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_BusbarSectionArray[i].szTerminal, pPGBlock->m_TerminalArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_BusbarSectionArray[i].szSub, pPGBlock->m_TerminalArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_BusbarSectionArray[i].szVolt, pPGBlock->m_TerminalArray[nRec].szVolt);
		// 				strcpy(pPGBlock->m_BusbarSectionArray[i].szTerminal, pPGBlock->m_TerminalArray[nRec].szName);
		// 				strcpy(pPGBlock->m_BusbarSectionArray[i].szNode, pPGBlock->m_TerminalArray[nRec].szNode);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("BusbarSection中[Name=%s]的Terminal[ResID=%s]无法解析\n", pPGBlock->m_BusbarSectionArray[i].szName, pPGBlock->m_BusbarSectionArray[i].szTerminal);
		// 			}
		// 		}
		// 		//	由SynchronousMachine的Terminal确定SynchronousMachine的Substation、VoltageLevel和ConnectivityNode
		// 		for (i=0; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
		// 		{
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_SynchronousMachineArray[i].szTerminal, pPGBlock->m_TerminalArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_SynchronousMachineArray[i].szSub, pPGBlock->m_TerminalArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_SynchronousMachineArray[i].szVolt, pPGBlock->m_TerminalArray[nRec].szVolt);
		// 				strcpy(pPGBlock->m_SynchronousMachineArray[i].szTerminal, pPGBlock->m_TerminalArray[nRec].szName);
		// 				strcpy(pPGBlock->m_SynchronousMachineArray[i].szNode, pPGBlock->m_TerminalArray[nRec].szNode);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("SynchronousMachine中[Name=%s]的Terminal[ResID=%s]无法解析\n", pPGBlock->m_SynchronousMachineArray[i].szName, pPGBlock->m_SynchronousMachineArray[i].szTerminal);
		// 			}
		// 		}
		// 		//	由EnergyConsumer的Terminal确定EnergyConsumer的Substation、VoltageLevel和ConnectivityNode
		// 		for (i=0; i<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; i++)
		// 		{
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_EnergyConsumerArray[i].szTerminal, pPGBlock->m_TerminalArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_EnergyConsumerArray[i].szSub, pPGBlock->m_TerminalArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_EnergyConsumerArray[i].szVolt, pPGBlock->m_TerminalArray[nRec].szVolt);
		// 				strcpy(pPGBlock->m_EnergyConsumerArray[i].szTerminal, pPGBlock->m_TerminalArray[nRec].szName);
		// 				strcpy(pPGBlock->m_EnergyConsumerArray[i].szNode, pPGBlock->m_TerminalArray[nRec].szNode);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("EnergyConsumer中[Name=%s]的Terminal[ResID=%s]无法解析\n", pPGBlock->m_EnergyConsumerArray[i].szName, pPGBlock->m_EnergyConsumerArray[i].szTerminal);
		// 			}
		// 		}
		// 		//	由ShuntCompensator的Terminal确定ShuntCompensator的Substation、VoltageLevel和ConnectivityNode
		// 		for (i=0; i<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; i++)
		// 		{
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_ShuntCompensatorArray[i].szTerminal, pPGBlock->m_TerminalArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_ShuntCompensatorArray[i].szSub, pPGBlock->m_TerminalArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_ShuntCompensatorArray[i].szVolt, pPGBlock->m_TerminalArray[nRec].szVolt);
		// 				strcpy(pPGBlock->m_ShuntCompensatorArray[i].szTerminal, pPGBlock->m_TerminalArray[nRec].szName);
		// 				strcpy(pPGBlock->m_ShuntCompensatorArray[i].szNode, pPGBlock->m_TerminalArray[nRec].szNode);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("ShuntCompensator中[Name=%s]的Terminal[ResID=%s]无法解析\n", pPGBlock->m_ShuntCompensatorArray[i].szName, pPGBlock->m_ShuntCompensatorArray[i].szTerminal);
		// 			}
		// 		}
		// 		//	由ACLineSegment的Terminal确定ACLineSegment的Substation、VoltageLevel和ConnectivityNode
		// 		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
		// 		{
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_ACLineSegmentArray[i].szTerminalI, pPGBlock->m_TerminalArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szSubI, pPGBlock->m_TerminalArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szVoltI, pPGBlock->m_TerminalArray[nRec].szVolt);
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szTerminalI, pPGBlock->m_TerminalArray[nRec].szName);
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szNodeI, pPGBlock->m_TerminalArray[nRec].szNode);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("ACLineSegment中[Name=%s]的TerminalI[ResID=%s]无法解析\n", pPGBlock->m_ACLineSegmentArray[i].szName, pPGBlock->m_ACLineSegmentArray[i].szTerminalI);
		// 			}
		// 
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_ACLineSegmentArray[i].szTerminalJ, pPGBlock->m_TerminalArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szSubJ, pPGBlock->m_TerminalArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szVoltJ, pPGBlock->m_TerminalArray[nRec].szVolt);
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szTerminalJ, pPGBlock->m_TerminalArray[nRec].szName);
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szNodeJ, pPGBlock->m_TerminalArray[nRec].szNode);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("ACLineSegment中[Name=%s]的TerminalZ[ResID=%s]无法解析\n", pPGBlock->m_ACLineSegmentArray[i].szName, pPGBlock->m_ACLineSegmentArray[i].szTerminalJ);
		// 			}
		// 		}
		// 		//	由TransformerWinding的Terminal确定TransformerWinding的Substation、VoltageLevel和ConnectivityNode
		// 		for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
		// 		{
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_TransformerWindingArray[i].szTerminalI, pPGBlock->m_TerminalArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szSub, pPGBlock->m_TerminalArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szVoltI, pPGBlock->m_TerminalArray[nRec].szVolt);
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szTerminalI, pPGBlock->m_TerminalArray[nRec].szName);
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szNodeI, pPGBlock->m_TerminalArray[nRec].szNode);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("TransformerWinding中[Name=%s]的TerminalI[ResID=%s]无法解析\n", pPGBlock->m_TransformerWindingArray[i].szName, pPGBlock->m_TransformerWindingArray[i].szTerminalI);
		// 			}
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_TransformerWindingArray[i].szTerminalJ, pPGBlock->m_TerminalArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szSub, pPGBlock->m_TerminalArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szVoltJ, pPGBlock->m_TerminalArray[nRec].szVolt);
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szTerminalJ, pPGBlock->m_TerminalArray[nRec].szName);
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szNodeJ, pPGBlock->m_TerminalArray[nRec].szNode);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("TransformerWinding中[Name=%s]的TerminalZ[ResID=%s]无法解析\n", pPGBlock->m_TransformerWindingArray[i].szName, pPGBlock->m_TransformerWindingArray[i].szTerminalJ);
		// 			}
		// 		}
		// 		for (i=0; i<pPGBlock->m_nRecordNum[PG_BREAKER]; i++)
		// 		{
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_BreakerArray[i].szTerminalI, pPGBlock->m_TerminalArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_BreakerArray[i].szSub, pPGBlock->m_TerminalArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_BreakerArray[i].szVolt, pPGBlock->m_TerminalArray[nRec].szVolt);
		// 				strcpy(pPGBlock->m_BreakerArray[i].szTerminalI, pPGBlock->m_TerminalArray[nRec].szName);
		// 				strcpy(pPGBlock->m_BreakerArray[i].szNodeI, pPGBlock->m_TerminalArray[nRec].szNode);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("Breaker中[Name=%s]的TerminalI[ResID=%s]无法解析\n", pPGBlock->m_BreakerArray[i].szName, pPGBlock->m_BreakerArray[i].szTerminalI);
		// 			}
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_BreakerArray[i].szTerminalJ, pPGBlock->m_TerminalArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_BreakerArray[i].szSub, pPGBlock->m_TerminalArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_BreakerArray[i].szVolt, pPGBlock->m_TerminalArray[nRec].szVolt);
		// 				strcpy(pPGBlock->m_BreakerArray[i].szTerminalJ, pPGBlock->m_TerminalArray[nRec].szName);
		// 				strcpy(pPGBlock->m_BreakerArray[i].szNodeJ, pPGBlock->m_TerminalArray[nRec].szNode);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("Breaker中[Name=%s]的TerminalZ[ResID=%s]无法解析\n", pPGBlock->m_BreakerArray[i].szName, pPGBlock->m_BreakerArray[i].szTerminalJ);
		// 			}
		// 		}
		// 		for (i=0; i<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; i++)
		// 		{
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_DisconnectorArray[i].szTerminalI, pPGBlock->m_TerminalArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szSub, pPGBlock->m_TerminalArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szVolt, pPGBlock->m_TerminalArray[nRec].szVolt);
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szTerminalI, pPGBlock->m_TerminalArray[nRec].szName);
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szNodeI, pPGBlock->m_TerminalArray[nRec].szNode);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("Disconnector中[Name=%s]的TerminalI[ResID=%s]无法解析\n", pPGBlock->m_DisconnectorArray[i].szName, pPGBlock->m_DisconnectorArray[i].szTerminalI);
		// 			}
		// 			bParsed=0;
		// 			if (STRICMP(pPGBlock->m_DisconnectorArray[i].szTerminalJ, pPGBlock->m_TerminalArray[nRec].szResID) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szSub, pPGBlock->m_TerminalArray[nRec].szSub);
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szVolt, pPGBlock->m_TerminalArray[nRec].szVolt);
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szTerminalJ, pPGBlock->m_TerminalArray[nRec].szName);
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szNodeJ, pPGBlock->m_TerminalArray[nRec].szNode);
		// 				{
		// 					bParsed=1;
		// 					break;
		// 				}
		// 			}
		// 			if (!bParsed)
		// 			{
		// //				PGMemDBLog("Disconnector中[Name=%s]的TerminalZ[ResID=%s]无法解析\n", pPGBlock->m_DisconnectorArray[i].szName, pPGBlock->m_DisconnectorArray[i].szTerminalJ);
		// 			}
		// 		}
		// 	}
	}

	void	PGRegularByName(tagPGBlock* pPGBlock)
	{
		register int	i, j;

		//	Substation中确定SubControlArea和Company
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SUBSTATION]; i++)
		{
			for (j=0; j<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; j++)
			{
				if (STRICMP(pPGBlock->m_SubstationArray[i].szSubcontrolArea, pPGBlock->m_SubcontrolAreaArray[j].szName) == 0)
				{
					strcpy(pPGBlock->m_SubstationArray[i].szCompany, pPGBlock->m_SubcontrolAreaArray[j].szCompany);
					break;
				}
			}
		}

		// 	//	由BusbarSection的Terminal确定BusbarSection的Substation、VoltageLevel和ConnectivityNode
		// 	for (i=0; i<pPGBlock->m_nRecordNum[PG_BUSBARSECTION]; i++)
		// 	{
		// 		for (j=0; j<pPGBlock->m_nRecordNum[PG_TERMINAL]; j++)
		// 		{
		// 			if (STRICMP(pPGBlock->m_BusbarSectionArray[i].szTerminal, pPGBlock->m_TerminalArray[j].szName) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_BusbarSectionArray[i].szSub, pPGBlock->m_TerminalArray[j].szSub);
		// 				strcpy(pPGBlock->m_BusbarSectionArray[i].szVolt, pPGBlock->m_TerminalArray[j].szVolt);
		// 				strcpy(pPGBlock->m_BusbarSectionArray[i].szNode, pPGBlock->m_TerminalArray[j].szNode);
		// 				break;
		// 			}
		// 		}
		// 	}
		// 
		// 	//	由SynchronousMachine的Terminal确定SynchronousMachine的Substation、VoltageLevel和ConnectivityNode
		// 	for (i=0; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
		// 	{
		// 		for (j=0; j<pPGBlock->m_nRecordNum[PG_TERMINAL]; j++)
		// 		{
		// 			if (STRICMP(pPGBlock->m_SynchronousMachineArray[i].szTerminal, pPGBlock->m_TerminalArray[j].szName) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_SynchronousMachineArray[i].szSub, pPGBlock->m_TerminalArray[j].szSub);
		// 				strcpy(pPGBlock->m_SynchronousMachineArray[i].szVolt, pPGBlock->m_TerminalArray[j].szVolt);
		// 				strcpy(pPGBlock->m_SynchronousMachineArray[i].szNode, pPGBlock->m_TerminalArray[j].szNode);
		// 				break;
		// 			}
		// 		}
		// 	}
		// 
		// 	//	由EnergyConsumer的Terminal确定EnergyConsumer的Substation、VoltageLevel和ConnectivityNode
		// 	for (i=0; i<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; i++)
		// 	{
		// 		for (j=0; j<pPGBlock->m_nRecordNum[PG_TERMINAL]; j++)
		// 		{
		// 			if (STRICMP(pPGBlock->m_EnergyConsumerArray[i].szTerminal, pPGBlock->m_TerminalArray[j].szName) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_EnergyConsumerArray[i].szSub, pPGBlock->m_TerminalArray[j].szSub);
		// 				strcpy(pPGBlock->m_EnergyConsumerArray[i].szVolt, pPGBlock->m_TerminalArray[j].szVolt);
		// 				strcpy(pPGBlock->m_EnergyConsumerArray[i].szNode, pPGBlock->m_TerminalArray[j].szNode);
		// 				break;
		// 			}
		// 		}
		// 	}
		// 
		// 	//	由ShuntCompensator的Terminal确定ShuntCompensator的Substation、VoltageLevel和ConnectivityNode
		// 	for (i=0; i<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; i++)
		// 	{
		// 		for (j=0; j<pPGBlock->m_nRecordNum[PG_TERMINAL]; j++)
		// 		{
		// 			if (STRICMP(pPGBlock->m_ShuntCompensatorArray[i].szTerminal, pPGBlock->m_TerminalArray[j].szName) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_ShuntCompensatorArray[i].szSub, pPGBlock->m_TerminalArray[j].szSub);
		// 				strcpy(pPGBlock->m_ShuntCompensatorArray[i].szVolt, pPGBlock->m_TerminalArray[j].szVolt);
		// 				strcpy(pPGBlock->m_ShuntCompensatorArray[i].szNode, pPGBlock->m_TerminalArray[j].szNode);
		// 				break;
		// 			}
		// 		}
		// 	}
		// 
		// 	//	由ACLineSegment的Terminal确定ACLineSegment的Substation、VoltageLevel和ConnectivityNode
		// 	for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
		// 	{
		// 		if (strlen(pPGBlock->m_ACLineSegmentArray[i].szVoltJ) <= 0)
		// 		{
		// 			strcpy(pPGBlock->m_ACLineSegmentArray[i].szVoltJ, pPGBlock->m_ACLineSegmentArray[i].szVoltI);
		// 		}
		// 
		// 		for (j=0; j<pPGBlock->m_nRecordNum[PG_TERMINAL]; j++)
		// 		{
		// 			if (STRICMP(pPGBlock->m_ACLineSegmentArray[i].szTerminalI, pPGBlock->m_TerminalArray[j].szName) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szSubI, pPGBlock->m_TerminalArray[j].szSub);
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szVoltI, pPGBlock->m_TerminalArray[j].szVolt);
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szNodeI, pPGBlock->m_TerminalArray[j].szNode);
		// 				break;
		// 			}
		// 		}
		// 		for (j=0; j<pPGBlock->m_nRecordNum[PG_TERMINAL]; j++)
		// 		{
		// 			if (STRICMP(pPGBlock->m_ACLineSegmentArray[i].szTerminalJ, pPGBlock->m_TerminalArray[j].szName) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szSubJ, pPGBlock->m_TerminalArray[j].szSub);
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szVoltJ, pPGBlock->m_TerminalArray[j].szVolt);
		// 				strcpy(pPGBlock->m_ACLineSegmentArray[i].szNodeJ, pPGBlock->m_TerminalArray[j].szNode);
		// 				break;
		// 			}
		// 		}
		// 	}
		// 
		// 	//	由TransformerWinding的Terminal确定TransformerWinding的Substation、VoltageLevel和ConnectivityNode
		// 	for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
		// 	{
		// 		for (j=0; j<pPGBlock->m_nRecordNum[PG_TERMINAL]; j++)
		// 		{
		// 			if (STRICMP(pPGBlock->m_TransformerWindingArray[i].szTerminalI, pPGBlock->m_TerminalArray[j].szName) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szSub, pPGBlock->m_TerminalArray[j].szSub);
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szVoltI, pPGBlock->m_TerminalArray[j].szVolt);
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szNodeI, pPGBlock->m_TerminalArray[j].szNode);
		// 				break;
		// 			}
		// 		}
		// 		for (j=0; j<pPGBlock->m_nRecordNum[PG_TERMINAL]; j++)
		// 		{
		// 			if (STRICMP(pPGBlock->m_TransformerWindingArray[i].szTerminalJ, pPGBlock->m_TerminalArray[j].szName) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szSub, pPGBlock->m_TerminalArray[j].szSub);
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szVoltJ, pPGBlock->m_TerminalArray[j].szVolt);
		// 				strcpy(pPGBlock->m_TransformerWindingArray[i].szNodeJ, pPGBlock->m_TerminalArray[j].szNode);
		// 				break;
		// 			}
		// 		}
		// 	}
		// 
		// 	for (i=0; i<pPGBlock->m_nRecordNum[PG_BREAKER]; i++)
		// 	{
		// 		for (j=0; j<pPGBlock->m_nRecordNum[PG_TERMINAL]; j++)
		// 		{
		// 			if (STRICMP(pPGBlock->m_BreakerArray[i].szTerminalI, pPGBlock->m_TerminalArray[j].szName) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_BreakerArray[i].szSub, pPGBlock->m_TerminalArray[j].szSub);
		// 				strcpy(pPGBlock->m_BreakerArray[i].szVolt, pPGBlock->m_TerminalArray[j].szVolt);
		// 				strcpy(pPGBlock->m_BreakerArray[i].szNodeI, pPGBlock->m_TerminalArray[j].szNode);
		// 				break;
		// 			}
		// 		}
		// 		for (j=0; j<pPGBlock->m_nRecordNum[PG_TERMINAL]; j++)
		// 		{
		// 			if (STRICMP(pPGBlock->m_BreakerArray[i].szTerminalJ, pPGBlock->m_TerminalArray[j].szName) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_BreakerArray[i].szSub, pPGBlock->m_TerminalArray[j].szSub);
		// 				strcpy(pPGBlock->m_BreakerArray[i].szVolt, pPGBlock->m_TerminalArray[j].szVolt);
		// 				strcpy(pPGBlock->m_BreakerArray[i].szNodeJ, pPGBlock->m_TerminalArray[j].szNode);
		// 				break;
		// 			}
		// 		}
		// 	}
		// 	for (i=0; i<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; i++)
		// 	{
		// 		for (j=0; j<pPGBlock->m_nRecordNum[PG_TERMINAL]; j++)
		// 		{
		// 			if (STRICMP(pPGBlock->m_DisconnectorArray[i].szTerminalI, pPGBlock->m_TerminalArray[j].szName) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szSub, pPGBlock->m_TerminalArray[j].szSub);
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szVolt, pPGBlock->m_TerminalArray[j].szVolt);
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szNodeI, pPGBlock->m_TerminalArray[j].szNode);
		// 				break;
		// 			}
		// 		}
		// 		for (j=0; j<pPGBlock->m_nRecordNum[PG_TERMINAL]; j++)
		// 		{
		// 			if (STRICMP(pPGBlock->m_DisconnectorArray[i].szTerminalJ, pPGBlock->m_TerminalArray[j].szName) == 0)
		// 			{
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szSub, pPGBlock->m_TerminalArray[j].szSub);
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szVolt, pPGBlock->m_TerminalArray[j].szVolt);
		// 				strcpy(pPGBlock->m_DisconnectorArray[i].szNodeJ, pPGBlock->m_TerminalArray[j].szNode);
		// 				break;
		// 			}
		// 		}
		// 	}
	}

	void	regular(tagPGBlock* pPGBlock)
	{
		int		nDev;
		//char	szBuf[MDB_CHARLEN_LONG];

		PGRegularByResID(pPGBlock);	//	可是在名称中存储的是RESOURCEID
		PGRegularByName(pPGBlock);	//	在名称中存储的是名称

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nDev++)
		{
			if (strlen(pPGBlock->m_ACLineSegmentArray[nDev].szVoltI) <= 0)
				strcpy(pPGBlock->m_ACLineSegmentArray[nDev].szVoltI, pPGBlock->m_ACLineSegmentArray[nDev].szVoltJ);
			else if (strlen(pPGBlock->m_ACLineSegmentArray[nDev].szVoltJ) <= 0)
				strcpy(pPGBlock->m_ACLineSegmentArray[nDev].szVoltJ, pPGBlock->m_ACLineSegmentArray[nDev].szVoltI);
		}
// 		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nDev++)
// 		{
// 			if (strcmp(pPGBlock->m_ACLineSegmentArray[nDev].szSubI, pPGBlock->m_ACLineSegmentArray[nDev].szSubJ) < 0)
// 			{
// 			}
// 			else
// 			{
// 				strcpy(szBuf, pPGBlock->m_ACLineSegmentArray[nDev].szSubI);
// 				strcpy(pPGBlock->m_ACLineSegmentArray[nDev].szSubI, pPGBlock->m_ACLineSegmentArray[nDev].szSubJ);
// 				strcpy(pPGBlock->m_ACLineSegmentArray[nDev].szSubJ, szBuf);
// 
// 				strcpy(szBuf, pPGBlock->m_ACLineSegmentArray[nDev].szVoltI);
// 				strcpy(pPGBlock->m_ACLineSegmentArray[nDev].szVoltI, pPGBlock->m_ACLineSegmentArray[nDev].szVoltJ);
// 				strcpy(pPGBlock->m_ACLineSegmentArray[nDev].szVoltJ, szBuf);
// 
// 				strcpy(szBuf, pPGBlock->m_ACLineSegmentArray[nDev].szNodeI);
// 				strcpy(pPGBlock->m_ACLineSegmentArray[nDev].szNodeI, pPGBlock->m_ACLineSegmentArray[nDev].szNodeJ);
// 				strcpy(pPGBlock->m_ACLineSegmentArray[nDev].szNodeJ, szBuf);
// 			}
// 		}
	}
}
