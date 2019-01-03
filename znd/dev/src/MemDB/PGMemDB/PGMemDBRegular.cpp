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

		//	SubControlArea��ȷ��Company
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
					//				PGMemDBLog("SubControlArea��[Name=%s]��Company[ResID=%s]�޷�����\n", pPGBlock->m_SubcontrolAreaArray[i].szName, pPGBlock->m_SubcontrolAreaArray[i].szCompany);
				}
			}
		}

		//	Substation��ȷ��SubControlArea��Company
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
					//				PGMemDBLog("Substation��[Name=%s]��SubControlArea[ResID=%s]�޷�����\n", pPGBlock->m_SubstationArray[i].szName, pPGBlock->m_SubstationArray[i].szSubcontrolArea);
				}
			}
		}

		//	VoltageLevel��ȷ��Substation
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
					//				PGMemDBLog("VoltageLevel��[Name=%s]��Substation[ResID=%s]�޷�����\n", pPGBlock->m_VoltageLevelArray[i].szName, pPGBlock->m_VoltageLevelArray[i].szSub);
				}
			}
		}

		// 	//	Terminal��ȷ��Substation��VoltageLevel
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
		// //				PGMemDBLog("Terminal��[Name=%s]��VoltageLevel[ResID=%s]�޷�����\n", pPGBlock->m_TerminalArray[i].szName, pPGBlock->m_TerminalArray[i].szVolt);
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
		// 		//	��BusbarSection��Terminalȷ��BusbarSection��Substation��VoltageLevel��ConnectivityNode
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
		// //				PGMemDBLog("BusbarSection��[Name=%s]��Terminal[ResID=%s]�޷�����\n", pPGBlock->m_BusbarSectionArray[i].szName, pPGBlock->m_BusbarSectionArray[i].szTerminal);
		// 			}
		// 		}
		// 		//	��SynchronousMachine��Terminalȷ��SynchronousMachine��Substation��VoltageLevel��ConnectivityNode
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
		// //				PGMemDBLog("SynchronousMachine��[Name=%s]��Terminal[ResID=%s]�޷�����\n", pPGBlock->m_SynchronousMachineArray[i].szName, pPGBlock->m_SynchronousMachineArray[i].szTerminal);
		// 			}
		// 		}
		// 		//	��EnergyConsumer��Terminalȷ��EnergyConsumer��Substation��VoltageLevel��ConnectivityNode
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
		// //				PGMemDBLog("EnergyConsumer��[Name=%s]��Terminal[ResID=%s]�޷�����\n", pPGBlock->m_EnergyConsumerArray[i].szName, pPGBlock->m_EnergyConsumerArray[i].szTerminal);
		// 			}
		// 		}
		// 		//	��ShuntCompensator��Terminalȷ��ShuntCompensator��Substation��VoltageLevel��ConnectivityNode
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
		// //				PGMemDBLog("ShuntCompensator��[Name=%s]��Terminal[ResID=%s]�޷�����\n", pPGBlock->m_ShuntCompensatorArray[i].szName, pPGBlock->m_ShuntCompensatorArray[i].szTerminal);
		// 			}
		// 		}
		// 		//	��ACLineSegment��Terminalȷ��ACLineSegment��Substation��VoltageLevel��ConnectivityNode
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
		// //				PGMemDBLog("ACLineSegment��[Name=%s]��TerminalI[ResID=%s]�޷�����\n", pPGBlock->m_ACLineSegmentArray[i].szName, pPGBlock->m_ACLineSegmentArray[i].szTerminalI);
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
		// //				PGMemDBLog("ACLineSegment��[Name=%s]��TerminalZ[ResID=%s]�޷�����\n", pPGBlock->m_ACLineSegmentArray[i].szName, pPGBlock->m_ACLineSegmentArray[i].szTerminalJ);
		// 			}
		// 		}
		// 		//	��TransformerWinding��Terminalȷ��TransformerWinding��Substation��VoltageLevel��ConnectivityNode
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
		// //				PGMemDBLog("TransformerWinding��[Name=%s]��TerminalI[ResID=%s]�޷�����\n", pPGBlock->m_TransformerWindingArray[i].szName, pPGBlock->m_TransformerWindingArray[i].szTerminalI);
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
		// //				PGMemDBLog("TransformerWinding��[Name=%s]��TerminalZ[ResID=%s]�޷�����\n", pPGBlock->m_TransformerWindingArray[i].szName, pPGBlock->m_TransformerWindingArray[i].szTerminalJ);
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
		// //				PGMemDBLog("Breaker��[Name=%s]��TerminalI[ResID=%s]�޷�����\n", pPGBlock->m_BreakerArray[i].szName, pPGBlock->m_BreakerArray[i].szTerminalI);
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
		// //				PGMemDBLog("Breaker��[Name=%s]��TerminalZ[ResID=%s]�޷�����\n", pPGBlock->m_BreakerArray[i].szName, pPGBlock->m_BreakerArray[i].szTerminalJ);
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
		// //				PGMemDBLog("Disconnector��[Name=%s]��TerminalI[ResID=%s]�޷�����\n", pPGBlock->m_DisconnectorArray[i].szName, pPGBlock->m_DisconnectorArray[i].szTerminalI);
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
		// //				PGMemDBLog("Disconnector��[Name=%s]��TerminalZ[ResID=%s]�޷�����\n", pPGBlock->m_DisconnectorArray[i].szName, pPGBlock->m_DisconnectorArray[i].szTerminalJ);
		// 			}
		// 		}
		// 	}
	}

	void	PGRegularByName(tagPGBlock* pPGBlock)
	{
		register int	i, j;

		//	Substation��ȷ��SubControlArea��Company
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

		// 	//	��BusbarSection��Terminalȷ��BusbarSection��Substation��VoltageLevel��ConnectivityNode
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
		// 	//	��SynchronousMachine��Terminalȷ��SynchronousMachine��Substation��VoltageLevel��ConnectivityNode
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
		// 	//	��EnergyConsumer��Terminalȷ��EnergyConsumer��Substation��VoltageLevel��ConnectivityNode
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
		// 	//	��ShuntCompensator��Terminalȷ��ShuntCompensator��Substation��VoltageLevel��ConnectivityNode
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
		// 	//	��ACLineSegment��Terminalȷ��ACLineSegment��Substation��VoltageLevel��ConnectivityNode
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
		// 	//	��TransformerWinding��Terminalȷ��TransformerWinding��Substation��VoltageLevel��ConnectivityNode
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

		PGRegularByResID(pPGBlock);	//	�����������д洢����RESOURCEID
		PGRegularByName(pPGBlock);	//	�������д洢��������

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
