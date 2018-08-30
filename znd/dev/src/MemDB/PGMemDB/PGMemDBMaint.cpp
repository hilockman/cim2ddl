#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

namespace	PGMemDB
{
	extern	void	fromDerivedDevice(tagPGBlock* pPGBlock);
	extern	void	PGFormIndexPointer(tagPGBlock* pPGBlock);
	extern	void	regular(tagPGBlock* pPGBlock);

	extern	void	PGFormBusbarSectionType(tagPGBlock* pPGBlock);
	extern	void	PGFormBreakerDisconnectorInnerType(tagPGBlock* pPGBlock);
	extern	void	PGFormBreakerDisconnectorJointDeviceType(tagPGBlock* pPGBlock);

	void PGFillResourceId(tagPGBlock* pPGBlock)
	{
		int				nDev;
		char			szBuffer[3*MDB_CHARLEN];

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_COMPANY]; nDev++)
		{
			if (strlen(pPGBlock->m_CompanyArray[nDev].szResID) <= 0)
			{
				MemDBBase::CalculateResourceId(pPGBlock->m_CompanyArray[nDev].szName, pPGBlock->m_CompanyArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; nDev++)
		{
			if (strlen(pPGBlock->m_SubcontrolAreaArray[nDev].szResID) <= 0)
			{
				MemDBBase::CalculateResourceId(pPGBlock->m_SubcontrolAreaArray[nDev].szName, pPGBlock->m_SubcontrolAreaArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nDev++)
		{
			if (strlen(pPGBlock->m_ACLineSegmentArray[nDev].szResID) <= 0)
			{
				MemDBBase::CalculateResourceId(pPGBlock->m_ACLineSegmentArray[nDev].szName, pPGBlock->m_ACLineSegmentArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]; nDev++)
		{
			if (strlen(pPGBlock->m_DCLineSegmentArray[nDev].szResID) <= 0)
			{
				MemDBBase::CalculateResourceId(pPGBlock->m_DCLineSegmentArray[nDev].szName, pPGBlock->m_DCLineSegmentArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_LINE]; nDev++)
		{
			if (strlen(pPGBlock->m_LineArray[nDev].szResID) <= 0)
			{
				MemDBBase::CalculateResourceId(pPGBlock->m_LineArray[nDev].szName, pPGBlock->m_LineArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]; nDev++)
		{
			if (strlen(pPGBlock->m_PowerTransformerArray[nDev].szResID) <= 0)
			{
				sprintf(szBuffer, "%s/%s", pPGBlock->m_PowerTransformerArray[nDev].szSub, pPGBlock->m_PowerTransformerArray[nDev].szName);
				MemDBBase::CalculateResourceId(szBuffer, pPGBlock->m_PowerTransformerArray[nDev].szResID);
			}
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nDev++)
		{
			if (strlen(pPGBlock->m_SubstationArray[nDev].szResID) <= 0)
			{
				MemDBBase::CalculateResourceId(pPGBlock->m_SubstationArray[nDev].szName, pPGBlock->m_SubstationArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nDev++)
		{
			if (strlen(pPGBlock->m_TransformerWindingArray[nDev].szResID) <= 0)
			{
				sprintf(szBuffer, "%s/%s", pPGBlock->m_TransformerWindingArray[nDev].szSub, pPGBlock->m_TransformerWindingArray[nDev].szName);
				MemDBBase::CalculateResourceId(szBuffer, pPGBlock->m_TransformerWindingArray[nDev].szResID);
			}
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; nDev++)
		{
			if (strlen(pPGBlock->m_VoltageLevelArray[nDev].szResID) <= 0)
			{
				sprintf(szBuffer, "%s/%s", pPGBlock->m_VoltageLevelArray[nDev].szSub, pPGBlock->m_VoltageLevelArray[nDev].szName);
				MemDBBase::CalculateResourceId(szBuffer, pPGBlock->m_VoltageLevelArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_BUSBARSECTION]; nDev++)
		{
			if (strlen(pPGBlock->m_BusbarSectionArray[nDev].szResID) <= 0)
			{
				sprintf(szBuffer, "%s/%s/%s", pPGBlock->m_BusbarSectionArray[nDev].szSub, pPGBlock->m_BusbarSectionArray[nDev].szVolt, pPGBlock->m_BusbarSectionArray[nDev].szName);
				MemDBBase::CalculateResourceId(szBuffer, pPGBlock->m_BusbarSectionArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			if (strlen(pPGBlock->m_SynchronousMachineArray[nDev].szResID) <= 0)
			{
				sprintf(szBuffer, "%s/%s/%s", pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_SynchronousMachineArray[nDev].szVolt, pPGBlock->m_SynchronousMachineArray[nDev].szName);
				MemDBBase::CalculateResourceId(szBuffer, pPGBlock->m_SynchronousMachineArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; nDev++)
		{
			if (strlen(pPGBlock->m_EnergyConsumerArray[nDev].szResID) <= 0)
			{
				sprintf(szBuffer, "%s/%s/%s", pPGBlock->m_EnergyConsumerArray[nDev].szSub, pPGBlock->m_EnergyConsumerArray[nDev].szVolt, pPGBlock->m_EnergyConsumerArray[nDev].szName);
				MemDBBase::CalculateResourceId(szBuffer, pPGBlock->m_EnergyConsumerArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; nDev++)
		{
			if (strlen(pPGBlock->m_ShuntCompensatorArray[nDev].szResID) <= 0)
			{
				sprintf(szBuffer, "%s/%s/%s", pPGBlock->m_ShuntCompensatorArray[nDev].szSub, pPGBlock->m_ShuntCompensatorArray[nDev].szVolt, pPGBlock->m_ShuntCompensatorArray[nDev].szName);
				MemDBBase::CalculateResourceId(szBuffer, pPGBlock->m_ShuntCompensatorArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SERIESCOMPENSATOR]; nDev++)
		{
			if (strlen(pPGBlock->m_SeriesCompensatorArray[nDev].szResID) <= 0)
			{
				sprintf(szBuffer, "%s/%s/%s", pPGBlock->m_SeriesCompensatorArray[nDev].szSub, pPGBlock->m_SeriesCompensatorArray[nDev].szVolt, pPGBlock->m_SeriesCompensatorArray[nDev].szName);
				MemDBBase::CalculateResourceId(szBuffer, pPGBlock->m_SeriesCompensatorArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_BREAKER]; nDev++)
		{
			if (strlen(pPGBlock->m_BreakerArray[nDev].szResID) <= 0)
			{
				sprintf(szBuffer, "%s/%s/%s", pPGBlock->m_BreakerArray[nDev].szSub, pPGBlock->m_BreakerArray[nDev].szVolt, pPGBlock->m_BreakerArray[nDev].szName);
				MemDBBase::CalculateResourceId(szBuffer, pPGBlock->m_BreakerArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; nDev++)
		{
			if (strlen(pPGBlock->m_DisconnectorArray[nDev].szResID) <= 0)
			{
				sprintf(szBuffer, "%s/%s/%s", pPGBlock->m_DisconnectorArray[nDev].szSub, pPGBlock->m_DisconnectorArray[nDev].szVolt, pPGBlock->m_DisconnectorArray[nDev].szName);
				MemDBBase::CalculateResourceId(szBuffer, pPGBlock->m_DisconnectorArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_GROUNDDISCONNECTOR]; nDev++)
		{
			if (strlen(pPGBlock->m_GroundDisconnectorArray[nDev].szResID) <= 0)
			{
				sprintf(szBuffer, "%s/%s/%s", pPGBlock->m_GroundDisconnectorArray[nDev].szSub, pPGBlock->m_GroundDisconnectorArray[nDev].szVolt, pPGBlock->m_GroundDisconnectorArray[nDev].szName);
				MemDBBase::CalculateResourceId(szBuffer, pPGBlock->m_GroundDisconnectorArray[nDev].szResID);
			}
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER]; nDev++)
		{
			if (strlen(pPGBlock->m_RectifierInverterArray[nDev].szResID) <= 0)
			{
				sprintf(szBuffer, "%s/%s", pPGBlock->m_RectifierInverterArray[nDev].szSub, pPGBlock->m_RectifierInverterArray[nDev].szName);
				MemDBBase::CalculateResourceId(szBuffer, pPGBlock->m_RectifierInverterArray[nDev].szResID);
			}
		}
	}

	void LineSegment2Line(tagPGBlock* pPGBlock)
	{
		register int	i;
		int		nLine, nFind;

		pPGBlock->m_nRecordNum[PG_LINE]=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
		{
			memset(&pPGBlock->m_LineArray[pPGBlock->m_nRecordNum[PG_LINE]], 0, sizeof(tagPGLine));
			strcpy(pPGBlock->m_LineArray[pPGBlock->m_nRecordNum[PG_LINE]].szResID, pPGBlock->m_ACLineSegmentArray[i].szResID);
			if (strlen(pPGBlock->m_ACLineSegmentArray[i].szLine) > 0)
				strcpy(pPGBlock->m_LineArray[pPGBlock->m_nRecordNum[PG_LINE]].szName, pPGBlock->m_ACLineSegmentArray[i].szLine);
			else
				strcpy(pPGBlock->m_LineArray[pPGBlock->m_nRecordNum[PG_LINE]].szName, pPGBlock->m_ACLineSegmentArray[i].szName);

			pPGBlock->m_nRecordNum[PG_LINE]++;
		}

		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_LINE);
		MemDBBase::MDBCheckTableExist<tagPGBlock>(pPGBlock, PG_LINE);		//	数据检查

		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
		{
			if (strlen(pPGBlock->m_ACLineSegmentArray[i].szLine) > 0)
				nLine=PGFindRecordbyKey(pPGBlock, PG_LINE, pPGBlock->m_ACLineSegmentArray[i].szLine);
			else
				nLine=PGFindRecordbyKey(pPGBlock, PG_LINE, pPGBlock->m_ACLineSegmentArray[i].szName);

			if (nLine >= 0)
			{
				strcpy(pPGBlock->m_LineArray[nLine].szVolt, pPGBlock->m_ACLineSegmentArray[i].szVoltI);
				pPGBlock->m_LineArray[nLine].fLineLength += pPGBlock->m_ACLineSegmentArray[i].fLength;

// 				if (pPGBlock->m_ACLineSegmentArray[i].nConMode > 0)	pPGBlock->m_LineArray[nLine].nConMode=pPGBlock->m_ACLineSegmentArray[i].nConMode;
// 				if (pPGBlock->m_LineArray[nLine].fMaxCapacity < 0.001)
// 					pPGBlock->m_LineArray[nLine].fMaxCapacity=pPGBlock->m_ACLineSegmentArray[i].fRatedCur;
// 				if (pPGBlock->m_ACLineSegmentArray[i].fRatedCur > 0.1)
// 					pPGBlock->m_LineArray[nLine].fMaxCapacity=min(pPGBlock->m_LineArray[nLine].fMaxCapacity, pPGBlock->m_ACLineSegmentArray[i].fRatedCur);
// 
// 				pPGBlock->m_LineArray[nLine].fMaxCapacity = max(pPGBlock->m_LineArray[nLine].fMaxCapacity, pPGBlock->m_ACLineSegmentArray[i].fRatedCur);
// 				pPGBlock->m_LineArray[nLine].fMaxCurrent = max(pPGBlock->m_LineArray[nLine].fMaxCurrent, pPGBlock->m_ACLineSegmentArray[i].fMaxCurrent);
// 				pPGBlock->m_LineArray[nLine].nDistranAmount += pPGBlock->m_ACLineSegmentArray[i].nDistranAmount;
// 				pPGBlock->m_LineArray[nLine].fDistranCapacity += pPGBlock->m_ACLineSegmentArray[i].fDistranCapacity;
// 				pPGBlock->m_LineArray[nLine].nPublicDistran += pPGBlock->m_ACLineSegmentArray[i].nPublicDistran;
// 				pPGBlock->m_LineArray[nLine].fPublicCapacity += pPGBlock->m_ACLineSegmentArray[i].fPublicCapacity;

				nFind=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_ACLineSegmentArray[i].szSubI);
				if (nFind < 0)
				{
					nFind=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_ACLineSegmentArray[i].szSubJ);
				}
				if (nFind >= 0)
					strcpy(pPGBlock->m_LineArray[nLine].szSubcontrolArea, pPGBlock->m_SubstationArray[nFind].szSubcontrolArea);
			}
		}
	}

	void TransformerWinding2PowerTransformer(tagPGBlock* pPGBlock)
	{
		register int	i;
		int	nSub, nTran, nTranNum, nTranCoil[10], nTranNode[10];
		int	nTranMid;

		std::vector<short>	nWindArray;
		std::vector<unsigned char>	bWindProc;

		pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]=0;
		memset(&pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]], 0, sizeof(tagPGPowerTransformer));
		pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=-1;
		pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=-1;
		pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltL=-1;

		bWindProc.resize(pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING], 0);
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nTran=pPGBlock->m_SubstationArray[nSub].nTransformerWindingRange; nTran<pPGBlock->m_SubstationArray[nSub+1].nTransformerWindingRange; nTran++)
			{
				if (bWindProc[nTran])
					continue;

				bWindProc[nTran]=1;
				if (strlen(pPGBlock->m_TransformerWindingArray[nTran].szTran) <= 0)
				{
					PGGetTranCoil(pPGBlock, nTran, nTranNum, nTranCoil, nTranNode);
					if (nTranNum == 3)
					{
						memset(&pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]], 0, sizeof(tagPGPowerTransformer));
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=-1;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=-1;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltL=-1;

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szResID,	pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szResID);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szName,	pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szName);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szDesp,	pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szDesp);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szSub,	pPGBlock->m_SubstationArray[nSub].szName);
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindNum=(unsigned char)nTranNum;

						nTranMid=(pPGBlock->m_TransformerWindingArray[nTranCoil[0]].nNodeI == pPGBlock->m_TransformerWindingArray[nTranCoil[1]].nNodeI || pPGBlock->m_TransformerWindingArray[nTranCoil[0]].nNodeI == pPGBlock->m_TransformerWindingArray[nTranCoil[1]].nNodeJ) ?
							pPGBlock->m_TransformerWindingArray[nTranCoil[0]].nNodeI : pPGBlock->m_TransformerWindingArray[nTranCoil[0]].nNodeJ;

						if (nTranMid == pPGBlock->m_TransformerWindingArray[nTranCoil[0]].nNodeI)
						{
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltH, pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szVoltJ);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeH, pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szNodeJ);
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_TransformerWindingArray[nTranCoil[0]].nNodeJ;
						}
						else
						{
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltH, pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szVoltI);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeH, pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szNodeI);
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_TransformerWindingArray[nTranCoil[0]].nNodeI;
						}

						if (nTranMid == pPGBlock->m_TransformerWindingArray[nTranCoil[1]].nNodeI)
						{
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltM, pPGBlock->m_TransformerWindingArray[nTranCoil[1]].szVoltJ);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeM, pPGBlock->m_TransformerWindingArray[nTranCoil[1]].szNodeJ);
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=pPGBlock->m_TransformerWindingArray[nTranCoil[1]].nNodeJ;
						}
						else
						{
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltM, pPGBlock->m_TransformerWindingArray[nTranCoil[1]].szVoltI);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeM, pPGBlock->m_TransformerWindingArray[nTranCoil[1]].szNodeI);
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=pPGBlock->m_TransformerWindingArray[nTranCoil[1]].nNodeI;
						}

						if (nTranMid == pPGBlock->m_TransformerWindingArray[nTranCoil[2]].nNodeI)
						{
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltL, pPGBlock->m_TransformerWindingArray[nTranCoil[2]].szVoltJ);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeL, pPGBlock->m_TransformerWindingArray[nTranCoil[2]].szNodeJ);
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=pPGBlock->m_TransformerWindingArray[nTranCoil[2]].nNodeJ;
						}
						else
						{
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltL, pPGBlock->m_TransformerWindingArray[nTranCoil[2]].szVoltI);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeL, pPGBlock->m_TransformerWindingArray[nTranCoil[2]].szNodeI);
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=pPGBlock->m_TransformerWindingArray[nTranCoil[2]].nNodeI;
						}

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindH, pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szName);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindM, pPGBlock->m_TransformerWindingArray[nTranCoil[1]].szName);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindL, pPGBlock->m_TransformerWindingArray[nTranCoil[2]].szName);
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=(short)nTranCoil[0];
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=(short)nTranCoil[1];
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=(short)nTranCoil[2];
						pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]++;

						for (i=0; i<nTranNum; i++)
						{
							strcpy(pPGBlock->m_TransformerWindingArray[nTranCoil[i]].szTran, pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szName);
							bWindProc[nTranCoil[i]]=1;
						}
					}
					else
					{
						memset(&pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]], 0, sizeof(tagPGPowerTransformer));
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=-1;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=-1;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltL=-1;

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szResID,	pPGBlock->m_TransformerWindingArray[nTran].szResID);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szName,	pPGBlock->m_TransformerWindingArray[nTran].szName);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szDesp,	pPGBlock->m_TransformerWindingArray[nTran].szDesp);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szSub,	pPGBlock->m_SubstationArray[nSub].szName);
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindNum=1;

						if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_TransformerWindingArray[nTran].nVoltI].nominalVoltage >= pPGBlock->m_VoltageLevelArray[pPGBlock->m_TransformerWindingArray[nTran].nVoltJ].nominalVoltage)
						{
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltH, pPGBlock->m_TransformerWindingArray[nTran].szVoltI);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltM, "");
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltL, pPGBlock->m_TransformerWindingArray[nTran].szVoltJ);

							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeH, pPGBlock->m_TransformerWindingArray[nTran].szNodeI);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeM, "");
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeL, pPGBlock->m_TransformerWindingArray[nTran].szNodeJ);

							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindH, pPGBlock->m_TransformerWindingArray[nTran].szName);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindM, "");
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindL, pPGBlock->m_TransformerWindingArray[nTran].szName);

							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_TransformerWindingArray[nTran].nNodeI;
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=pPGBlock->m_TransformerWindingArray[nTran].nNodeJ;
						}
						else
						{
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltH, pPGBlock->m_TransformerWindingArray[nTran].szVoltJ);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltM, "");
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltL, pPGBlock->m_TransformerWindingArray[nTran].szVoltI);

							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeH, pPGBlock->m_TransformerWindingArray[nTran].szNodeJ);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeM, "");
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeL, pPGBlock->m_TransformerWindingArray[nTran].szNodeI);

							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindH, pPGBlock->m_TransformerWindingArray[nTran].szName);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindM, "");
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindL, pPGBlock->m_TransformerWindingArray[nTran].szName);

							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_TransformerWindingArray[nTran].nNodeJ;
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=pPGBlock->m_TransformerWindingArray[nTran].nNodeI;
						}

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=(short)nTran;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=(short)nTran;
						pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]++;

						strcpy(pPGBlock->m_TransformerWindingArray[nTran].szTran, pPGBlock->m_TransformerWindingArray[nTran].szName);
					}
				}
				else
				{
					nWindArray.clear();
					for (i=pPGBlock->m_SubstationArray[nSub].nTransformerWindingRange; i<pPGBlock->m_SubstationArray[nSub+1].nTransformerWindingRange; i++)
					{
						if (strcmp(pPGBlock->m_TransformerWindingArray[nTran].szTran, pPGBlock->m_TransformerWindingArray[i].szTran) == 0)
							nWindArray.push_back((short)i);
					}

					for (i=0; i<(int)nWindArray.size(); i++)
						bWindProc[nWindArray[i]]=1;

					if (nWindArray.size() == 1)
					{
						memset(&pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]], 0, sizeof(tagPGPowerTransformer));
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=-1;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=-1;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltL=-1;

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szResID,	pPGBlock->m_TransformerWindingArray[nWindArray[0]].szResID);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szName,	pPGBlock->m_TransformerWindingArray[nWindArray[0]].szTran);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szDesp,	pPGBlock->m_TransformerWindingArray[nWindArray[0]].szDesp);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szSub,	pPGBlock->m_SubstationArray[nSub].szName);
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindNum=(unsigned char)nWindArray.size();

						if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_TransformerWindingArray[nTran].nVoltI].nominalVoltage >= pPGBlock->m_VoltageLevelArray[pPGBlock->m_TransformerWindingArray[nTran].nVoltJ].nominalVoltage)
						{
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltH, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szVoltI);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltM, "");
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltL, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szVoltJ);

							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeH, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szNodeI);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeM, "");
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeL, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szNodeJ);

							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindH, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szName);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindM, "");
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindL, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szName);

							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_TransformerWindingArray[nWindArray[0]].nNodeI;
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=pPGBlock->m_TransformerWindingArray[nWindArray[0]].nNodeJ;
						}
						else
						{
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltH, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szVoltJ);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltM, "");
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltL, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szVoltI);

							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeH, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szNodeJ);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeM, "");
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeL, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szNodeI);

							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindH, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szName);
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindM, "");
							strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindL, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szName);

							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_TransformerWindingArray[nWindArray[0]].nNodeJ;
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=pPGBlock->m_TransformerWindingArray[nWindArray[0]].nNodeI;
						}

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=nWindArray[0];
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=nWindArray[0];

						pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]++;
					}
					else if (nWindArray.size() == 2)
					{
						float	fVoltI, fVoltZ;

						fVoltI=fVoltZ=0;
						for (i=0; i<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; i++)
						{
							if (strcmp(pPGBlock->m_VoltageLevelArray[i].szName, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szVoltI) == 0)
							{
								fVoltI=pPGBlock->m_VoltageLevelArray[i].nominalVoltage;
								break;
							}
						}
						for (i=0; i<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; i++)
						{
							if (strcmp(pPGBlock->m_VoltageLevelArray[i].szName, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szVoltJ) == 0)
							{
								fVoltZ=pPGBlock->m_VoltageLevelArray[i].nominalVoltage;
								break;
							}
						}
						if (fVoltI < fVoltZ)
							std::swap(nWindArray[0], nWindArray[1]);

						nTranMid=(pPGBlock->m_TransformerWindingArray[nWindArray[0]].nNodeI == pPGBlock->m_TransformerWindingArray[nWindArray[1]].nNodeI || pPGBlock->m_TransformerWindingArray[nWindArray[0]].nNodeI == pPGBlock->m_TransformerWindingArray[nWindArray[1]].nNodeJ) ?
							pPGBlock->m_TransformerWindingArray[nWindArray[0]].nNodeI : pPGBlock->m_TransformerWindingArray[nWindArray[0]].nNodeJ;

						memset(&pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]], 0, sizeof(tagPGPowerTransformer));
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=-1;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=-1;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltL=-1;

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szResID,	pPGBlock->m_TransformerWindingArray[nWindArray[0]].szResID);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szName,		pPGBlock->m_TransformerWindingArray[nWindArray[0]].szTran);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szDesp,		pPGBlock->m_TransformerWindingArray[nWindArray[0]].szDesp);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szSub,		pPGBlock->m_SubstationArray[nSub].szName);
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindNum=(unsigned char)nWindArray.size();

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltH, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szVoltI);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltM, "");
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltL, pPGBlock->m_TransformerWindingArray[nWindArray[1]].szVoltI);

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeH, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szNodeI);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeM, "");
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeL, pPGBlock->m_TransformerWindingArray[nWindArray[1]].szNodeI);

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindH, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szName);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindM, "");
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindL, pPGBlock->m_TransformerWindingArray[nWindArray[1]].szName);

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=nWindArray[0];
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=nWindArray[1];

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=(pPGBlock->m_TransformerWindingArray[nWindArray[0]].nNodeI == nTranMid) ? pPGBlock->m_TransformerWindingArray[nWindArray[0]].nNodeJ : pPGBlock->m_TransformerWindingArray[nWindArray[0]].nNodeI;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=(pPGBlock->m_TransformerWindingArray[nWindArray[1]].nNodeI == nTranMid) ? pPGBlock->m_TransformerWindingArray[nWindArray[1]].nNodeJ : pPGBlock->m_TransformerWindingArray[nWindArray[1]].nNodeI;

						pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]++;
					}
					else if (nWindArray.size() == 3)
					{
						int		nMinVWind, nMaxVWind, nMidVWind;
						float	fMinVolt, fMaxVolt;

						nMinVWind=nMaxVWind=nMidVWind=0;
						for (i=0; i<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; i++)
						{
							if (strcmp(pPGBlock->m_VoltageLevelArray[i].szName, pPGBlock->m_TransformerWindingArray[nWindArray[0]].szVoltI) == 0)
							{
								fMinVolt=fMaxVolt=pPGBlock->m_VoltageLevelArray[i].nominalVoltage;
								break;
							}
						}
						for (i=0; i<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; i++)
						{
							if (strcmp(pPGBlock->m_VoltageLevelArray[i].szName, pPGBlock->m_TransformerWindingArray[nWindArray[1]].szVoltI) == 0)
							{
								if (fMinVolt > pPGBlock->m_VoltageLevelArray[i].nominalVoltage)
								{
									nMinVWind=1;
									fMinVolt=pPGBlock->m_VoltageLevelArray[i].nominalVoltage;
								}
								if (fMaxVolt < pPGBlock->m_VoltageLevelArray[i].nominalVoltage)
								{
									nMaxVWind=1;
									fMaxVolt=pPGBlock->m_VoltageLevelArray[i].nominalVoltage;
								}
								break;
							}
						}
						for (i=0; i<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; i++)
						{
							if (strcmp(pPGBlock->m_VoltageLevelArray[i].szName, pPGBlock->m_TransformerWindingArray[nWindArray[2]].szVoltI) == 0)
							{
								if (fMinVolt > pPGBlock->m_VoltageLevelArray[i].nominalVoltage)
								{
									nMinVWind=2;
									fMinVolt=pPGBlock->m_VoltageLevelArray[i].nominalVoltage;
								}
								if (fMaxVolt < pPGBlock->m_VoltageLevelArray[i].nominalVoltage)
								{
									nMaxVWind=2;
									fMaxVolt=pPGBlock->m_VoltageLevelArray[i].nominalVoltage;
								}
								break;
							}
						}
						for (i=0; i<(int)nWindArray.size(); i++)
						{
							if (nMinVWind == i)
								continue;

							if (nMaxVWind == i)
								continue;

							nMidVWind=i;
							break;
						}

						nTranMid=(pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].nNodeI == pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].nNodeI || pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].nNodeI == pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].nNodeJ) ?
							pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].nNodeI : pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].nNodeJ;

						memset(&pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]], 0, sizeof(tagPGPowerTransformer));
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=-1;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=-1;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltL=-1;

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szResID,	pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].szResID);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szName,	pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].szTran);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szDesp,	pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].szDesp);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szSub,	pPGBlock->m_SubstationArray[nSub].szName);
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindNum=(unsigned char)nWindArray.size();

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltH, pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].szVoltI);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltM, pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].szVoltI);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltL, pPGBlock->m_TransformerWindingArray[nWindArray[nMinVWind]].szVoltI);

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeH, pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].szNodeI);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeM, pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].szNodeI);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeL, pPGBlock->m_TransformerWindingArray[nWindArray[nMinVWind]].szNodeI);

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindH, pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].szName);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindM, pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].szName);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindL, pPGBlock->m_TransformerWindingArray[nWindArray[nMinVWind]].szName);

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=nWindArray[nMaxVWind];
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=nWindArray[nMidVWind];
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=nWindArray[nMinVWind];

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=(pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].nNodeI == nTranMid) ? pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].nNodeJ : pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].nNodeI;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=(pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].nNodeI == nTranMid) ? pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].nNodeJ : pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].nNodeI;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=(pPGBlock->m_TransformerWindingArray[nWindArray[nMinVWind]].nNodeI == nTranMid) ? pPGBlock->m_TransformerWindingArray[nWindArray[nMinVWind]].nNodeJ : pPGBlock->m_TransformerWindingArray[nWindArray[nMinVWind]].nNodeI;

						pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]++;
					}
				}
			}
		}
		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_POWERTRANSFORMER);
		MemDBBase::MDBCheckTableExist<tagPGBlock>(pPGBlock, PG_POWERTRANSFORMER);		//	数据检查

		for (nTran=0; nTran<pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]; nTran++)
		{
		//	pPGBlock->m_PowerTransformerArray[nTran].iRWindH=
		//		pPGBlock->m_PowerTransformerArray[nTran].iRWindM=
		//		pPGBlock->m_PowerTransformerArray[nTran].iRWindL=-1;
		//
		//	strcpy(szKeyValArray[0], pPGBlock->m_PowerTransformerArray[nTran].szSub);
		//	if (strlen(pPGBlock->m_PowerTransformerArray[nTran].szWindH) > 0)
		//	{
		//		strcpy(szKeyValArray[1], pPGBlock->m_PowerTransformerArray[nTran].szWindH);
		//		pPGBlock->m_PowerTransformerArray[nTran].iRWindH=(short)PGFindRecordbyKey(pPGBlock, PG_TRANSFORMERWINDING, szKeyValArray);
		//	}
		//	if (strlen(pPGBlock->m_PowerTransformerArray[nTran].szWindM) > 0)
		//	{
		//		strcpy(szKeyValArray[1], pPGBlock->m_PowerTransformerArray[nTran].szWindM);
		//		pPGBlock->m_PowerTransformerArray[nTran].iRWindM=(short)PGFindRecordbyKey(pPGBlock, PG_TRANSFORMERWINDING, szKeyValArray);
		//	}
		//	if (strlen(pPGBlock->m_PowerTransformerArray[nTran].szWindL) > 0)
		//	{
		//		strcpy(szKeyValArray[1], pPGBlock->m_PowerTransformerArray[nTran].szWindL);
		//		pPGBlock->m_PowerTransformerArray[nTran].iRWindL=(short)PGFindRecordbyKey(pPGBlock, PG_TRANSFORMERWINDING, szKeyValArray);
		//	}
			pPGBlock->m_PowerTransformerArray[nTran].nVoltH=pPGBlock->m_PowerTransformerArray[nTran].nVoltM=pPGBlock->m_PowerTransformerArray[nTran].nVoltL=-1;
			if (strlen(pPGBlock->m_PowerTransformerArray[nTran].szVoltH) > 0)	pPGBlock->m_PowerTransformerArray[nTran].nVoltH=(short)PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_PowerTransformerArray[nTran].szSub, pPGBlock->m_PowerTransformerArray[nTran].szVoltH);
			if (strlen(pPGBlock->m_PowerTransformerArray[nTran].szVoltM) > 0)	pPGBlock->m_PowerTransformerArray[nTran].nVoltM=(short)PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_PowerTransformerArray[nTran].szSub, pPGBlock->m_PowerTransformerArray[nTran].szVoltM);
			if (strlen(pPGBlock->m_PowerTransformerArray[nTran].szVoltL) > 0)	pPGBlock->m_PowerTransformerArray[nTran].nVoltL=(short)PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_PowerTransformerArray[nTran].szSub, pPGBlock->m_PowerTransformerArray[nTran].szVoltL);
		}
		for (nTran=0; nTran<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nTran++)
		{
			pPGBlock->m_TransformerWindingArray[nTran].bTranMidSide=0;
			pPGBlock->m_TransformerWindingArray[nTran].nTran=-1;
			if (strlen(pPGBlock->m_TransformerWindingArray[nTran].szTran) > 0)
				pPGBlock->m_TransformerWindingArray[nTran].nTran=(short)PGFindRecordbyKey(pPGBlock, PG_POWERTRANSFORMER, pPGBlock->m_TransformerWindingArray[nTran].szSub, pPGBlock->m_TransformerWindingArray[nTran].szTran);
		}

		for (nTran=0; nTran<pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]; nTran++)
		{
			if (pPGBlock->m_PowerTransformerArray[nTran].nWindNum != 3)
				continue;

			nTranMid = (pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindH].nNodeI == pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindM].nNodeI ||
				pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindH].nNodeI == pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindM].nNodeJ) ?
				pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindH].nNodeI : pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindH].nNodeJ;

			pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindH].bTranMidSide=(pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindH].nNodeI == nTranMid) ? 1 : 2;
			pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindM].bTranMidSide=(pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindM].nNodeI == nTranMid) ? 1 : 2;
			pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindL].bTranMidSide=(pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nTran].nWindL].nNodeI == nTranMid) ? 1 : 2;
		}
	}

	//	这个函数是不考虑数据排序的
	void ACLine2EnergyConsumer(tagPGBlock* pPGBlock)
	{
		register int	i;
		int		nLine;
		unsigned char		bHasError, bExist;

		bHasError=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
		{
			if ((strlen(pPGBlock->m_ACLineSegmentArray[i].szSubI ) <= 0 || strlen(pPGBlock->m_ACLineSegmentArray[i].szSubJ) <= 0) &&
				(strlen(pPGBlock->m_ACLineSegmentArray[i].szSubI ) > 0 || strlen(pPGBlock->m_ACLineSegmentArray[i].szSubJ) > 0))
			{
				bHasError=1;
				break;
			}
		}
		if (bHasError)
		{
			nLine=0;
			while (nLine < pPGBlock->m_nRecordNum[PG_ACLINESEGMENT])
			{
				if (strlen(pPGBlock->m_ACLineSegmentArray[nLine].szSubI) <= 0)
				{
					bExist=0;
					for (i=0; i<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; i++)
					{
						if (strcmp(pPGBlock->m_EnergyConsumerArray[i].szSub, pPGBlock->m_ACLineSegmentArray[nLine].szSubJ) == 0 &&
							strcmp(pPGBlock->m_EnergyConsumerArray[i].szVolt, pPGBlock->m_ACLineSegmentArray[nLine].szVoltJ) == 0 &&
							strcmp(pPGBlock->m_EnergyConsumerArray[i].szName, pPGBlock->m_ACLineSegmentArray[nLine].szName) == 0)
						{
							bExist=1;
							break;
						}
					}
					if (!bExist)
					{
						memset(&pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]], 0, sizeof(tagPGEnergyConsumer));
						strcpy(pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].szResID,	pPGBlock->m_ACLineSegmentArray[nLine].szResID);
						strcpy(pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].szSub,	pPGBlock->m_ACLineSegmentArray[nLine].szSubJ);
						strcpy(pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].szVolt,	pPGBlock->m_ACLineSegmentArray[nLine].szVoltJ);
						strcpy(pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].szName,	pPGBlock->m_ACLineSegmentArray[nLine].szName);
						strcpy(pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].szNode,	pPGBlock->m_ACLineSegmentArray[nLine].szNodeJ);
						pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].bDistribution=pPGBlock->m_ACLineSegmentArray[nLine].bDistribution;
						pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]++;
					}

					for (i=nLine; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
						memcpy(&pPGBlock->m_ACLineSegmentArray[i], &pPGBlock->m_ACLineSegmentArray[i+1], sizeof(tagPGACLineSegment));
					pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]--;
				}
				else if (strlen(pPGBlock->m_ACLineSegmentArray[nLine].szSubJ) <= 0)
				{
					bExist=0;
					for (i=0; i<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; i++)
					{
						if (strcmp(pPGBlock->m_EnergyConsumerArray[i].szSub, pPGBlock->m_ACLineSegmentArray[nLine].szSubI) == 0 &&
							strcmp(pPGBlock->m_EnergyConsumerArray[i].szVolt, pPGBlock->m_ACLineSegmentArray[nLine].szVoltI) == 0 &&
							strcmp(pPGBlock->m_EnergyConsumerArray[i].szName, pPGBlock->m_ACLineSegmentArray[nLine].szName) == 0)
						{
							bExist=1;
							break;
						}
					}
					if (!bExist)
					{
						memset(&pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]], 0, sizeof(tagPGEnergyConsumer));
						strcpy(pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].szResID,	pPGBlock->m_ACLineSegmentArray[nLine].szResID);
						strcpy(pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].szSub,	pPGBlock->m_ACLineSegmentArray[nLine].szSubI);
						strcpy(pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].szVolt,	pPGBlock->m_ACLineSegmentArray[nLine].szVoltI);
						strcpy(pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].szName,	pPGBlock->m_ACLineSegmentArray[nLine].szName);
						strcpy(pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].szNode,	pPGBlock->m_ACLineSegmentArray[nLine].szNodeI);
						pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].bDistribution=pPGBlock->m_ACLineSegmentArray[nLine].bDistribution;
						pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]++;
					}

					for (i=nLine; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
						memcpy(&pPGBlock->m_ACLineSegmentArray[i], &pPGBlock->m_ACLineSegmentArray[i+1], sizeof(tagPGACLineSegment));
					pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]--;
				}
				else
				{
					nLine++;
				}
			}
		}

		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_ENERGYCONSUMER);
		MemDBBase::MDBCheckTableExist<tagPGBlock>(pPGBlock, PG_ENERGYCONSUMER);		//	数据检查
	}

	void	PGMaint(tagPGBlock* pPGBlock, const int bFormDerived)
	{
		clock_t	dBeg, dEnd;
		int		nDur;

		MDBClearLog();

		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, -1);

		if (bFormDerived)
		{
			pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]=0;
			pPGBlock->m_nRecordNum[PG_EDGEBREAKER]=0;
			pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]=0;
			pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]=0;
			pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]=0;
			pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]=0;
			pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]=0;

			dBeg=clock();
				MemDBBase::MDBCheckTableNull<tagPGBlock>(pPGBlock, -1);			//	主键不为空
			dEnd=clock();
			nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
			MDBLog("MDBCheckTableNull，耗时%d毫秒\n", nDur);

			dBeg=clock();
				MemDBBase::MDBCheckTableContainer<tagPGBlock>(pPGBlock);		//	容器检查
			dEnd=clock();
			nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
			MDBLog("MDBCheckTableContainer，耗时%d毫秒\n", nDur);

			dBeg=clock();
				MemDBBase::MDBCheckTableExist<tagPGBlock>(pPGBlock, -1);		//	数据不重复
			dEnd=clock();
			nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
			MDBLog("MDBCheckTableExist，耗时%d毫秒\n", nDur);

			dBeg=clock();
				ACLine2EnergyConsumer(pPGBlock);
			dEnd=clock();
			nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
			MDBLog("ACLine2EnergyConsumer，耗时%d毫秒\n", nDur);

			dBeg=clock();
				LineSegment2Line(pPGBlock);
			dEnd=clock();
			nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
			MDBLog("LineSegment2Line，耗时%d毫秒\n", nDur);

			fromDerivedDevice(pPGBlock);
		}

		PGFormIndexPointer(pPGBlock);				//	形成索引和指针

		//	形成开关操作模型和开关控制设备模型
		PGMemDBType(pPGBlock);

		dBeg=clock();
			TransformerWinding2PowerTransformer(pPGBlock);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		MDBLog("TransformerWinding2PowerTransformer，耗时%d毫秒\n", nDur);
		PGFormIndexPointer(pPGBlock);				//	形成索引和指针

		pPGBlock->m_nRecordNum[PG_ISLAND]=0;
		pPGBlock->m_nRecordNum[PG_TOPOBUS]=0;
	}

	void	PGMemDBType(tagPGBlock* pPGBlock)
	{
		PGFormBusbarSectionType(pPGBlock);
		PGFormBreakerDisconnectorInnerType(pPGBlock);
		PGFormBreakerDisconnectorJointDeviceType(pPGBlock);
	}
}
