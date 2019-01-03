#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

namespace	PGMemDB
{
	extern	void	fromDerivedDevice(tagPGBlock* pPGBlock);
	extern	void	PGFormRangePointer(tagPGBlock* pPGBlock);
	extern	void	PGFormIndexPointer(tagPGBlock* pPGBlock);
	extern	void	regular(tagPGBlock* pPGBlock);

	extern	void	PGFormBusbarSectionType(tagPGBlock* pPGBlock);
	extern	void	PGFormBreakerDisconnectorInnerType(tagPGBlock* pPGBlock);
	extern	void	PGFormBreakerDisconnectorJointDeviceType(tagPGBlock* pPGBlock);
	extern	void	PGFormDCBreakerJointDeviceType(tagPGBlock* pPGBlock);

	void PGFillResourceId(tagPGBlock* pPGBlock)
	{
		int				nTable, nField, nDev;
		char			szResId[MDB_CHARLEN];

		for (nTable=0; nTable<PGGetTableNum(); nTable++)
		{
			nField=PGGetFieldIndex(nTable, "ResourceId");
			if (nField < 0)
				continue;

			for (nDev=0; nDev<pPGBlock->m_nRecordNum[nTable]; nDev++)
			{
				memset(szResId, 0, MDB_CHARLEN);
				PGGetRecordValue(pPGBlock, nTable, nField, nDev, szResId);
				if (strlen(szResId) <= 0)
				{
					PGFormResourceId(pPGBlock, nTable, nDev, szResId);
					PGSetRecordValue(pPGBlock, nTable, nField, nDev, szResId);
				}
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
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]; i++)
		{
			memset(&pPGBlock->m_LineArray[pPGBlock->m_nRecordNum[PG_LINE]], 0, sizeof(tagPGLine));
			strcpy(pPGBlock->m_LineArray[pPGBlock->m_nRecordNum[PG_LINE]].szResID, pPGBlock->m_DCLineSegmentArray[i].szResID);
			if (strlen(pPGBlock->m_DCLineSegmentArray[i].szLine) > 0)
				strcpy(pPGBlock->m_LineArray[pPGBlock->m_nRecordNum[PG_LINE]].szName, pPGBlock->m_DCLineSegmentArray[i].szLine);
			else
				strcpy(pPGBlock->m_LineArray[pPGBlock->m_nRecordNum[PG_LINE]].szName, pPGBlock->m_DCLineSegmentArray[i].szName);

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

				nFind=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_ACLineSegmentArray[i].szSubI);
				if (nFind < 0)
					nFind=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_ACLineSegmentArray[i].szSubJ);
				if (nFind >= 0)
					strcpy(pPGBlock->m_LineArray[nLine].szSubcontrolArea, pPGBlock->m_SubstationArray[nFind].szSubcontrolArea);
			}
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]; i++)
		{
			if (strlen(pPGBlock->m_DCLineSegmentArray[i].szLine) > 0)
				nLine=PGFindRecordbyKey(pPGBlock, PG_LINE, pPGBlock->m_DCLineSegmentArray[i].szLine);
			else
				nLine=PGFindRecordbyKey(pPGBlock, PG_LINE, pPGBlock->m_DCLineSegmentArray[i].szName);

			if (nLine >= 0)
			{
				strcpy(pPGBlock->m_LineArray[nLine].szVolt, pPGBlock->m_DCLineSegmentArray[i].szVoltI);
				pPGBlock->m_LineArray[nLine].fLineLength += pPGBlock->m_DCLineSegmentArray[i].fLength;

				nFind=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_DCLineSegmentArray[i].szSubI);
				if (nFind < 0)
					nFind=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_DCLineSegmentArray[i].szSubJ);
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
		pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeT=-1;
		pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltH=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltM=pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltL=-1;

		bWindProc.resize(pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING], 0);
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nTran=pPGBlock->m_SubstationArray[nSub].nTransformerWindingRange; nTran<pPGBlock->m_SubstationArray[nSub+1].nTransformerWindingRange; nTran++)
			{
				if (bWindProc[nTran])
					continue;

				bWindProc[nTran]=1;
				if (strlen(pPGBlock->m_TransformerWindingArray[nTran].szPowerTransformer) <= 0)
				{
					PGGetTranCoil(pPGBlock, nTran, nTranNum, nTranCoil, nTranNode);
					if (nTranNum == 3)
					{
						memset(&pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]], 0, sizeof(tagPGPowerTransformer));
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=-1;

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeT=-1;

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltL=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltT=-1;

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szResID,	pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szResID);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szName,	pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szName);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szDesp,	pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szDesp);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szSub,	pPGBlock->m_SubstationArray[nSub].szName);
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindNum=(unsigned char)nTranNum;

						nTranMid=(pPGBlock->m_TransformerWindingArray[nTranCoil[0]].nNodeI == pPGBlock->m_TransformerWindingArray[nTranCoil[1]].nNodeI ||
							pPGBlock->m_TransformerWindingArray[nTranCoil[0]].nNodeI == pPGBlock->m_TransformerWindingArray[nTranCoil[1]].nNodeJ) ?
							pPGBlock->m_TransformerWindingArray[nTranCoil[0]].nNodeI : pPGBlock->m_TransformerWindingArray[nTranCoil[0]].nNodeJ;

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltT, pPGBlock->m_ConnectivityNodeArray[nTranMid].szVolt);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeT, pPGBlock->m_ConnectivityNodeArray[nTranMid].szName);
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeT=nTranMid;

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
							strcpy(pPGBlock->m_TransformerWindingArray[nTranCoil[i]].szPowerTransformer, pPGBlock->m_TransformerWindingArray[nTranCoil[0]].szName);
							bWindProc[nTranCoil[i]]=1;
						}
					}
					else
					{
						memset(&pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]], 0, sizeof(tagPGPowerTransformer));
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=-1;

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeT=-1;

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltL=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltT=-1;

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

						strcpy(pPGBlock->m_TransformerWindingArray[nTran].szPowerTransformer, pPGBlock->m_TransformerWindingArray[nTran].szName);
					}
				}
				else
				{
					nWindArray.clear();
					for (i=pPGBlock->m_SubstationArray[nSub].nTransformerWindingRange; i<pPGBlock->m_SubstationArray[nSub+1].nTransformerWindingRange; i++)
					{
						if (strcmp(pPGBlock->m_TransformerWindingArray[nTran].szPowerTransformer, pPGBlock->m_TransformerWindingArray[i].szPowerTransformer) == 0)
							nWindArray.push_back((short)i);
					}

					for (i=0; i<(int)nWindArray.size(); i++)
						bWindProc[nWindArray[i]]=1;

					if (nWindArray.size() == 1)
					{
						memset(&pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]], 0, sizeof(tagPGPowerTransformer));
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=-1;

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeT=-1;

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltL=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltT=-1;

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szResID,	pPGBlock->m_TransformerWindingArray[nWindArray[0]].szResID);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szName,	pPGBlock->m_TransformerWindingArray[nWindArray[0]].szPowerTransformer);
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
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=-1;

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeT=-1;

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltL=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltT=-1;

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szResID,	pPGBlock->m_TransformerWindingArray[nWindArray[0]].szResID);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szName,	pPGBlock->m_TransformerWindingArray[nWindArray[0]].szPowerTransformer);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szDesp,	pPGBlock->m_TransformerWindingArray[nWindArray[0]].szDesp);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szSub,	pPGBlock->m_SubstationArray[nSub].szName);
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

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltT, pPGBlock->m_ConnectivityNodeArray[nTranMid].szVolt);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeT, pPGBlock->m_ConnectivityNodeArray[nTranMid].szName);
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeT=nTranMid;

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
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=-1;

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeT=-1;

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltH=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltM=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltL=
							pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nVoltT=-1;

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szResID,	pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].szResID);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szName,	pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].szPowerTransformer);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szDesp,	pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].szDesp);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szSub,	pPGBlock->m_SubstationArray[nSub].szName);
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindNum=(unsigned char)nWindArray.size();

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltH, pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].szVoltI);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltM, pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].szVoltI);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltL, pPGBlock->m_TransformerWindingArray[nWindArray[nMinVWind]].szVoltI);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szVoltT, pPGBlock->m_ConnectivityNodeArray[nTranMid].szVolt);

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeH, pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].szNodeI);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeM, pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].szNodeI);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeL, pPGBlock->m_TransformerWindingArray[nWindArray[nMinVWind]].szNodeI);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szNodeT, pPGBlock->m_ConnectivityNodeArray[nTranMid].szName);

						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindH, pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].szName);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindM, pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].szName);
						strcpy(pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].szWindL, pPGBlock->m_TransformerWindingArray[nWindArray[nMinVWind]].szName);

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindH=nWindArray[nMaxVWind];
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindM=nWindArray[nMidVWind];
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nWindL=nWindArray[nMinVWind];

						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeH=(pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].nNodeI == nTranMid) ? pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].nNodeJ : pPGBlock->m_TransformerWindingArray[nWindArray[nMaxVWind]].nNodeI;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeM=(pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].nNodeI == nTranMid) ? pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].nNodeJ : pPGBlock->m_TransformerWindingArray[nWindArray[nMidVWind]].nNodeI;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeL=(pPGBlock->m_TransformerWindingArray[nWindArray[nMinVWind]].nNodeI == nTranMid) ? pPGBlock->m_TransformerWindingArray[nWindArray[nMinVWind]].nNodeJ : pPGBlock->m_TransformerWindingArray[nWindArray[nMinVWind]].nNodeI;
						pPGBlock->m_PowerTransformerArray[pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]].nNodeT=nTranMid;

						pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]++;
					}
				}
			}
		}
		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_POWERTRANSFORMER);
		MemDBBase::MDBCheckTableExist<tagPGBlock>(pPGBlock, PG_POWERTRANSFORMER);		//	数据检查

		for (nTran=0; nTran<pPGBlock->m_nRecordNum[PG_POWERTRANSFORMER]; nTran++)
		{
			pPGBlock->m_PowerTransformerArray[nTran].nVoltH=pPGBlock->m_PowerTransformerArray[nTran].nVoltM=pPGBlock->m_PowerTransformerArray[nTran].nVoltL=-1;
			if (strlen(pPGBlock->m_PowerTransformerArray[nTran].szVoltH) > 0)	pPGBlock->m_PowerTransformerArray[nTran].nVoltH=(short)PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_PowerTransformerArray[nTran].szSub, pPGBlock->m_PowerTransformerArray[nTran].szVoltH);
			if (strlen(pPGBlock->m_PowerTransformerArray[nTran].szVoltM) > 0)	pPGBlock->m_PowerTransformerArray[nTran].nVoltM=(short)PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_PowerTransformerArray[nTran].szSub, pPGBlock->m_PowerTransformerArray[nTran].szVoltM);
			if (strlen(pPGBlock->m_PowerTransformerArray[nTran].szVoltL) > 0)	pPGBlock->m_PowerTransformerArray[nTran].nVoltL=(short)PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_PowerTransformerArray[nTran].szSub, pPGBlock->m_PowerTransformerArray[nTran].szVoltL);
			if (strlen(pPGBlock->m_PowerTransformerArray[nTran].szVoltT) > 0)	pPGBlock->m_PowerTransformerArray[nTran].nVoltT=(short)PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_PowerTransformerArray[nTran].szSub, pPGBlock->m_PowerTransformerArray[nTran].szVoltT);
		}
		for (nTran=0; nTran<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nTran++)
		{
			pPGBlock->m_TransformerWindingArray[nTran].bTranMidSide=0;
			pPGBlock->m_TransformerWindingArray[nTran].nTran=-1;
			if (strlen(pPGBlock->m_TransformerWindingArray[nTran].szPowerTransformer) > 0)
				pPGBlock->m_TransformerWindingArray[nTran].nTran=(short)PGFindRecordbyKey(pPGBlock, PG_POWERTRANSFORMER, pPGBlock->m_TransformerWindingArray[nTran].szSub, pPGBlock->m_TransformerWindingArray[nTran].szPowerTransformer);
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


	void Converter2ElectronicTransformer(tagPGBlock* pPGBlock)
	{
		int	nSub, nVolt, nNode, nDev, nConverter;
		int	nBuffer, nMaxConverter;
		unsigned char	bFlag;
		double	fMaxVolt;

		std::vector<short>	nWindArray;
		std::vector<unsigned char>	bWindProc;

		pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]=0;

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange > 0)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nDCLineSegmentRange - pPGBlock->m_ConnectivityNodeArray[nNode].nDCLineSegmentRange > 0)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nSeriesCompensatorRange - pPGBlock->m_ConnectivityNodeArray[nNode].nSeriesCompensatorRange > 0)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nBreakerRange - pPGBlock->m_ConnectivityNodeArray[nNode].nBreakerRange > 0)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nDisconnectorRange - pPGBlock->m_ConnectivityNodeArray[nNode].nDisconnectorRange > 0)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nDCBreakerRange - pPGBlock->m_ConnectivityNodeArray[nNode].nDCBreakerRange > 0)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nDCShortCircuitLimitRange - pPGBlock->m_ConnectivityNodeArray[nNode].nDCShortCircuitLimitRange > 0)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nADConverterRange - pPGBlock->m_ConnectivityNodeArray[nNode].nADConverterRange <= 0)
						continue;
					if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nDDConverterRange - pPGBlock->m_ConnectivityNodeArray[nNode].nDDConverterRange <= 0)
						continue;

					nMaxConverter=-1;
					fMaxVolt=-FLT_MAX;
					for (nDev=pPGBlock->m_ConnectivityNodeArray[nNode].nADConverterRange; nDev<pPGBlock->m_ConnectivityNodeArray[nNode+1].nADConverterRange; nDev++)
					{
						nConverter = pPGBlock->m_EdgeADConverterArray[nDev].nConverter;
						nBuffer = PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_ACDCConverterArray[nConverter].szSub, pPGBlock->m_ACDCConverterArray[nConverter].szVoltAC);
						if (nBuffer < 0)
							continue;
						if (fMaxVolt < pPGBlock->m_VoltageLevelArray[nBuffer].nominalVoltage)
						{
							nMaxConverter = nConverter;
							fMaxVolt = pPGBlock->m_VoltageLevelArray[nBuffer].nominalVoltage;
						}
					}
					if (nMaxConverter < 0)
						continue;
					if (strlen(pPGBlock->m_ACDCConverterArray[nMaxConverter].szElectronicTransformer) <= 0)
						continue;

					memset(&pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]], 0, sizeof(tagPGElectronicTransformer));
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltACH = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltACL1 = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltACL2 = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltDCL1 = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltDCL2 = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltDCT = -1;

					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nADConverterH = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nADConverterL1 = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nADConverterL2 = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nDDConverterL1 = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nDDConverterL2 = -1;

					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeACH = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeACL1 = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeACL2 = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeDCL1 = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeDCL2 = -1;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeDCT = -1;

					strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szSub, pPGBlock->m_ACDCConverterArray[nMaxConverter].szSub);
					strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szName, pPGBlock->m_ACDCConverterArray[nMaxConverter].szElectronicTransformer);

					strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szVoltACH, pPGBlock->m_ACDCConverterArray[nMaxConverter].szVoltAC);
					strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szADConverterH, pPGBlock->m_ACDCConverterArray[nMaxConverter].szName);
					strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szNodeACH, pPGBlock->m_ACDCConverterArray[nMaxConverter].szNodeAC);
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nADConverterH = nMaxConverter;
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltACH = PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_ACDCConverterArray[nMaxConverter].szSub, pPGBlock->m_ACDCConverterArray[nMaxConverter].szVoltAC);
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeACH = PGFindRecordbyKey(pPGBlock, PG_CONNECTIVITYNODE, pPGBlock->m_ACDCConverterArray[nMaxConverter].szSub, pPGBlock->m_ACDCConverterArray[nMaxConverter].szVoltAC, pPGBlock->m_ACDCConverterArray[nMaxConverter].szNodeAC);
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nADConverterNum++;

					strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szVoltDCT, pPGBlock->m_ACDCConverterArray[nMaxConverter].szVoltDC);
					strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szNodeDCT, pPGBlock->m_ACDCConverterArray[nMaxConverter].szNodeDC);
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltDCT = PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_ACDCConverterArray[nMaxConverter].szSub, pPGBlock->m_ACDCConverterArray[nMaxConverter].szVoltDC);
					pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeDCT = PGFindRecordbyKey(pPGBlock, PG_CONNECTIVITYNODE, pPGBlock->m_ACDCConverterArray[nMaxConverter].szSub, pPGBlock->m_ACDCConverterArray[nMaxConverter].szVoltDC, pPGBlock->m_ACDCConverterArray[nMaxConverter].szNodeDC);

					bFlag = 0;
					for (nDev=pPGBlock->m_ConnectivityNodeArray[nNode].nADConverterRange; nDev<pPGBlock->m_ConnectivityNodeArray[nNode+1].nADConverterRange; nDev++)
					{
						nConverter = pPGBlock->m_EdgeADConverterArray[nDev].nConverter;
						if (nConverter == nMaxConverter)
							continue;

						if (bFlag == 0)
						{
							bFlag = 1;
							strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szVoltACL1, pPGBlock->m_ACDCConverterArray[nConverter].szVoltAC);
							strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szADConverterL1, pPGBlock->m_ACDCConverterArray[nConverter].szName);
							strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szNodeACL1, pPGBlock->m_ACDCConverterArray[nConverter].szNodeAC);
							pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nADConverterL1 = nConverter;
							pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltACL1 = PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_ACDCConverterArray[nConverter].szSub, pPGBlock->m_ACDCConverterArray[nConverter].szVoltAC);
							pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeACL1 = PGFindRecordbyKey(pPGBlock, PG_CONNECTIVITYNODE, pPGBlock->m_ACDCConverterArray[nConverter].szSub, pPGBlock->m_ACDCConverterArray[nConverter].szVoltAC, pPGBlock->m_ACDCConverterArray[nConverter].szNodeAC);
							pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nADConverterNum++;
						}
						else
						{
							strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szVoltACL2, pPGBlock->m_ACDCConverterArray[nConverter].szVoltAC);
							strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szADConverterL2, pPGBlock->m_ACDCConverterArray[nConverter].szName);
							strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szNodeACL2, pPGBlock->m_ACDCConverterArray[nConverter].szNodeAC);
							pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nADConverterL2 = nConverter;
							pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltACL2 = PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_ACDCConverterArray[nConverter].szSub, pPGBlock->m_ACDCConverterArray[nConverter].szVoltAC);
							pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeACL2 = PGFindRecordbyKey(pPGBlock, PG_CONNECTIVITYNODE, pPGBlock->m_ACDCConverterArray[nConverter].szSub, pPGBlock->m_ACDCConverterArray[nConverter].szVoltAC, pPGBlock->m_ACDCConverterArray[nConverter].szNodeAC);
							pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nADConverterNum++;
						}
					}

					bFlag = 0;
					for (nDev=pPGBlock->m_ConnectivityNodeArray[nNode].nDDConverterRange; nDev<pPGBlock->m_ConnectivityNodeArray[nNode+1].nDDConverterRange; nDev++)
					{
						nConverter = pPGBlock->m_EdgeDDConverterArray[nDev].nConverter;
						if (bFlag == 0)
						{
							bFlag = 1;
							if (pPGBlock->m_DCDCConverterArray[nConverter].nNodeI == nNode)
							{
								strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szVoltDCL1, pPGBlock->m_DCDCConverterArray[nConverter].szVoltJ);
								strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szDDConverterL1, pPGBlock->m_DCDCConverterArray[nConverter].szName);
								strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szNodeDCL1, pPGBlock->m_DCDCConverterArray[nConverter].szNodeJ);
								pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nDDConverterL1 = nConverter;
								pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltDCL1 = PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_DCDCConverterArray[nConverter].szSub, pPGBlock->m_DCDCConverterArray[nConverter].szVoltJ);
								pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeDCL1 = PGFindRecordbyKey(pPGBlock, PG_CONNECTIVITYNODE, pPGBlock->m_DCDCConverterArray[nConverter].szSub, pPGBlock->m_DCDCConverterArray[nConverter].szVoltJ, pPGBlock->m_DCDCConverterArray[nConverter].szNodeJ);
							}
							else
							{
								strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szVoltDCL1, pPGBlock->m_DCDCConverterArray[nConverter].szVoltI);
								strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szDDConverterL1, pPGBlock->m_DCDCConverterArray[nConverter].szName);
								strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szNodeDCL1, pPGBlock->m_DCDCConverterArray[nConverter].szNodeI);
								pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nDDConverterL1 = nConverter;
								pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltDCL1 = PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_DCDCConverterArray[nConverter].szSub, pPGBlock->m_DCDCConverterArray[nConverter].szVoltI);
								pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeDCL1 = PGFindRecordbyKey(pPGBlock, PG_CONNECTIVITYNODE, pPGBlock->m_DCDCConverterArray[nConverter].szSub, pPGBlock->m_DCDCConverterArray[nConverter].szVoltI, pPGBlock->m_DCDCConverterArray[nConverter].szNodeI);
							}
							pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nDDConverterNum++;
						}
						else
						{
							if (pPGBlock->m_DCDCConverterArray[nConverter].nNodeI == nNode)
							{
								strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szVoltDCL2, pPGBlock->m_DCDCConverterArray[nConverter].szVoltJ);
								strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szDDConverterL2, pPGBlock->m_DCDCConverterArray[nConverter].szName);
								strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szNodeDCL2, pPGBlock->m_DCDCConverterArray[nConverter].szNodeJ);
								pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nDDConverterL2 = nConverter;
								pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltDCL2 = PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_DCDCConverterArray[nConverter].szSub, pPGBlock->m_DCDCConverterArray[nConverter].szVoltJ);
								pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeDCL2 = PGFindRecordbyKey(pPGBlock, PG_CONNECTIVITYNODE, pPGBlock->m_DCDCConverterArray[nConverter].szSub, pPGBlock->m_DCDCConverterArray[nConverter].szVoltJ, pPGBlock->m_DCDCConverterArray[nConverter].szNodeJ);
							}
							else
							{
								strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szVoltDCL2, pPGBlock->m_DCDCConverterArray[nConverter].szVoltI);
								strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szDDConverterL2, pPGBlock->m_DCDCConverterArray[nConverter].szName);
								strcpy(pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].szNodeDCL2, pPGBlock->m_DCDCConverterArray[nConverter].szNodeI);
								pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nDDConverterL2 = nConverter;
								pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nVoltDCL2 = PGFindRecordbyKey(pPGBlock, PG_VOLTAGELEVEL, pPGBlock->m_DCDCConverterArray[nConverter].szSub, pPGBlock->m_DCDCConverterArray[nConverter].szVoltI);
								pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nNodeDCL2 = PGFindRecordbyKey(pPGBlock, PG_CONNECTIVITYNODE, pPGBlock->m_DCDCConverterArray[nConverter].szSub, pPGBlock->m_DCDCConverterArray[nConverter].szVoltI, pPGBlock->m_DCDCConverterArray[nConverter].szNodeI);
							}
							pPGBlock->m_ElectronicTransformerArray[pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]].nDDConverterNum++;
						}
					}
					pPGBlock->m_nRecordNum[PG_ELECTRONICTRANSFORMER]++;
				}
			}
		}
		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_ELECTRONICTRANSFORMER);
		MemDBBase::MDBCheckTableExist<tagPGBlock>(pPGBlock, PG_ELECTRONICTRANSFORMER);		//	数据检查
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
						pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].nMCRType=PGEnumInjection_MCRType_Line;
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
						pPGBlock->m_EnergyConsumerArray[pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]].nMCRType=PGEnumInjection_MCRType_Line;
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
			pPGBlock->m_nRecordNum[PG_TIELINE]=0;

			pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]=0;
			pPGBlock->m_nRecordNum[PG_EDGEBREAKER]=0;
			pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]=0;
			pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]=0;
			pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]=0;
			pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]=0;

			pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]=0;
			pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER]=0;
			pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER]=0;
			pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER]=0;
			pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT]=0;

			dBeg=clock();
			    log_info("Prev MDBCheckTableNull DCLineSegment=%d\n", pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]);
				MemDBBase::MDBCheckTableNull<tagPGBlock>(pPGBlock, -1);			//	主键不为空
				log_info("    Post DCLineSegment=%d\n", pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]);
			dEnd=clock();
			nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
			MDBLog("MDBCheckTableNull，耗时%d毫秒\n", nDur);

			dBeg=clock();
			    log_info("Prev MDBCheckTableContainer DCLineSegment=%d\n", pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]);
				MemDBBase::MDBCheckTableContainer<tagPGBlock>(pPGBlock);		//	容器检查
				log_info("    Post DCLineSegment=%d\n", pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]);
			dEnd=clock();
			nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
			MDBLog("MDBCheckTableContainer，耗时%d毫秒\n", nDur);

			dBeg=clock();
			log_info("Prev MDBCheckTableExist DCLineSegment=%d\n", pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]);
				MemDBBase::MDBCheckTableExist<tagPGBlock>(pPGBlock, -1);		//	数据不重复
				log_info("    Post DCLineSegment=%d\n", pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]);
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

		PGFormRangePointer(pPGBlock);				//	形成索引和指针
		PGFormIndexPointer(pPGBlock);				//	形成索引和指针

		//	形成开关操作模型和开关控制设备模型
		PGMemDBType(pPGBlock);

		dBeg=clock();
			TransformerWinding2PowerTransformer(pPGBlock);
			Converter2ElectronicTransformer(pPGBlock);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		MDBLog("TransformerWinding2PowerTransformer，耗时%d毫秒\n", nDur);

		PGFormRangePointer(pPGBlock);				//	形成索引和指针
		PGFormIndexPointer(pPGBlock);				//	形成索引和指针
		PGFillResourceId(pPGBlock);

		pPGBlock->m_nRecordNum[PG_ISLAND]=0;
		pPGBlock->m_nRecordNum[PG_TOPOBUS]=0;
	}

	void	PGMemDBType(tagPGBlock* pPGBlock)
	{
		PGFormBusbarSectionType(pPGBlock);
		PGFormBreakerDisconnectorInnerType(pPGBlock);
		PGFormBreakerDisconnectorJointDeviceType(pPGBlock);
		PGFormDCBreakerJointDeviceType(pPGBlock);
	}
}
