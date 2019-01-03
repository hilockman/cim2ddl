#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

extern	void	Log(const char* m_lpszPGMemDBLogFile, char* pformat, ...);
namespace	PGMemDB
{
	typedef	struct	_TempNode_
	{
		std::string	strSub;
		std::string	strVolt;
		std::string	strName;
	}	tagTempNode;
	static	tagTempNode	nodeBuf;
	std::vector<tagTempNode>	m_tNodeArray;

	static	void sortTempNodeArray(int nDn0, int nUp0)
	{
		int nDn = nDn0;
		int nUp = nUp0;

		if (nUp0 <= nDn0)
			return;

		std::string	strSub=m_tNodeArray[(nDn0+nUp0)/2].strSub;
		std::string	strVolt=m_tNodeArray[(nDn0+nUp0)/2].strVolt;
		std::string	strName=m_tNodeArray[(nDn0+nUp0)/2].strName;
		while (nDn <= nUp)
		{
// 			if (strcmp(m_tNodeArray[nDn].szSub, szSub) < 0
// 				|| strcmp(m_tNodeArray[nDn].szSub, szSub) == 0 && strcmp(m_tNodeArray[nDn].szVolt, szVolt) < 0
// 				|| strcmp(m_tNodeArray[nDn].szSub, szSub) == 0 && strcmp(m_tNodeArray[nDn].szVolt, szVolt) == 0 && strcmp(m_tNodeArray[nDn].szName, szName) < 0)
// 				return -1;
// 			else if (strcmp(m_tNodeArray[nDn].szSub, szSub) == 0 && strcmp(m_tNodeArray[nDn].szVolt, szVolt) == 0 && strcmp(m_tNodeArray[nDn].szName, szName) == 0)
// 				return 0;
// 			else if (strcmp(m_tNodeArray[nDn].szSub, szSub) > 0
// 				|| (strcmp(m_tNodeArray[nDn].szSub, szSub) == 0 && strcmp(m_tNodeArray[nDn].szVolt, szVolt) > 0)
// 				|| (strcmp(m_tNodeArray[nDn].szSub, szSub) == 0 && strcmp(m_tNodeArray[nDn].szVolt, szVolt) == 0 && strcmp(m_tNodeArray[nDn].szName, szName) > 0))
// 				return 1;

			while (nDn < nUp0 &&
				(strcmp(m_tNodeArray[nDn].strSub.c_str(), strSub.c_str()) < 0
						|| (strcmp(m_tNodeArray[nDn].strSub.c_str(), strSub.c_str()) == 0 && strcmp(m_tNodeArray[nDn].strVolt.c_str(), strVolt.c_str()) < 0)
						|| (strcmp(m_tNodeArray[nDn].strSub.c_str(), strSub.c_str()) == 0 && strcmp(m_tNodeArray[nDn].strVolt.c_str(), strVolt.c_str()) == 0 && strcmp(m_tNodeArray[nDn].strName.c_str(), strName.c_str()) < 0)))
				++nDn;
			while (nUp > nDn0 &&
				(strcmp(m_tNodeArray[nUp].strSub.c_str(), strSub.c_str()) > 0
						|| (strcmp(m_tNodeArray[nUp].strSub.c_str(), strSub.c_str()) == 0 && strcmp(m_tNodeArray[nUp].strVolt.c_str(), strVolt.c_str()) > 0)
						|| (strcmp(m_tNodeArray[nUp].strSub.c_str(), strSub.c_str()) == 0 && strcmp(m_tNodeArray[nUp].strVolt.c_str(), strVolt.c_str()) == 0 && strcmp(m_tNodeArray[nUp].strName.c_str(), strName.c_str()) > 0)))
				--nUp;

			if (nDn <= nUp)
			{
				std::swap(m_tNodeArray[nDn], m_tNodeArray[nUp]);
				++nDn;
				--nUp;
			}
		}
		strSub.clear();
		strVolt.clear();
		strName.clear();

		if (nDn0 < nUp)
			sortTempNodeArray(nDn0, nUp);
		if (nDn < nUp0 )
			sortTempNodeArray(nDn, nUp0);
	}

	void fromDerivedDevice(tagPGBlock* pPGBlock)
	{
		register int	i, j;
		int		nCorpI, nCorpZ, nDivI, nDivZ, nSubI, nSubZ;

		clock_t	dBeg, dEnd;
		int		nDur;

		pPGBlock->m_nRecordNum[PG_TIELINE]=0;
		pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]=0;
		pPGBlock->m_nRecordNum[PG_EDGEBREAKER]=0;
		pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]=0;
		pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]=0;
		pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]=0;
		pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]=0;

		pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]=0;
		pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER]=0;
		pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER]=0;
		pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER]=0;
		pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT]=0;

		dBeg=clock();
		if (pPGBlock->m_nRecordNum[PG_COMPANY] >= 2)
		{
			for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
			{
				nCorpI=nCorpZ=nDivI=nDivZ=nSubI=nSubZ=-1;
				for (j=0; j<pPGBlock->m_nRecordNum[PG_SUBSTATION]; j++)
				{
					if (strcmp(pPGBlock->m_ACLineSegmentArray[i].szSubI, pPGBlock->m_SubstationArray[j].szName) == 0)
					{
						nSubI=j;
						break;
					}
				}
				if (nSubI < 0)
					continue;

				for (j=0; j<pPGBlock->m_nRecordNum[PG_SUBSTATION]; j++)
				{
					if (strcmp(pPGBlock->m_ACLineSegmentArray[i].szSubJ, pPGBlock->m_SubstationArray[j].szName) == 0)
					{
						nSubZ=j;
						break;
					}
				}
				if (nSubZ < 0)
					continue;

				for (j=0; j<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; j++)
				{
					if (strcmp(pPGBlock->m_SubstationArray[nSubI].szSubcontrolArea, pPGBlock->m_SubcontrolAreaArray[j].szName) == 0)
					{
						nDivI=j;
						break;
					}
				}
				if (nDivI < 0)
					continue;

				for (j=0; j<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; j++)
				{
					if (strcmp(pPGBlock->m_SubstationArray[nSubZ].szSubcontrolArea, pPGBlock->m_SubcontrolAreaArray[j].szName) == 0)
					{
						nDivZ=j;
						break;
					}
				}
				if (nDivZ < 0)
					continue;

				for (j=0; j<pPGBlock->m_nRecordNum[PG_COMPANY]; j++)
				{
					if (strcmp(pPGBlock->m_SubstationArray[nSubI].szCompany, pPGBlock->m_CompanyArray[j].szName) == 0)
					{
						nCorpI=j;
						break;
					}
				}
				if (nCorpI < 0)
					continue;

				for (j=0; j<pPGBlock->m_nRecordNum[PG_COMPANY]; j++)
				{
					if (strcmp(pPGBlock->m_SubstationArray[nSubZ].szCompany, pPGBlock->m_CompanyArray[j].szName) == 0)
					{
						nCorpZ=j;
						break;
					}
				}
				if (nCorpZ < 0)
					continue;

				if (nCorpI != nCorpZ)
				{
					memset(&pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]], 0, sizeof(tagPGTieLine));
					if (nDivI < nDivZ)
					{
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szCompanyI,	pPGBlock->m_CompanyArray[nCorpI].szName);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szCompanyZ,	pPGBlock->m_CompanyArray[nCorpZ].szName);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubcontrolAreaI,		pPGBlock->m_SubcontrolAreaArray[nDivI].szName);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubcontrolAreaZ,		pPGBlock->m_SubcontrolAreaArray[nDivZ].szName);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubI,		pPGBlock->m_SubstationArray[nSubI].szName);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubJ,		pPGBlock->m_SubstationArray[nSubZ].szName);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szVoltI,	pPGBlock->m_ACLineSegmentArray[i].szVoltI);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szVoltJ,	pPGBlock->m_ACLineSegmentArray[i].szVoltJ);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szName,		pPGBlock->m_ACLineSegmentArray[i].szName);
					}
					else
					{
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szCompanyI,	pPGBlock->m_CompanyArray[nCorpZ].szName);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szCompanyZ,	pPGBlock->m_CompanyArray[nCorpI].szName);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubcontrolAreaI,		pPGBlock->m_SubcontrolAreaArray[nDivZ].szName);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubcontrolAreaZ,		pPGBlock->m_SubcontrolAreaArray[nDivI].szName);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubI,		pPGBlock->m_SubstationArray[nSubZ].szName);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubJ,		pPGBlock->m_SubstationArray[nSubI].szName);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szVoltI,	pPGBlock->m_ACLineSegmentArray[i].szVoltJ);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szVoltJ,	pPGBlock->m_ACLineSegmentArray[i].szVoltI);
						strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szName,		pPGBlock->m_ACLineSegmentArray[i].szName);
					}

					pPGBlock->m_nRecordNum[PG_TIELINE]++;
				}
				else
				{
					if (nDivI != nDivZ)
					{
						memset(&pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]], 0, sizeof(tagPGTieLine));
						if (nDivI < nDivZ)
						{
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szCompanyI,	pPGBlock->m_CompanyArray[nCorpI].szName);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szCompanyZ,	pPGBlock->m_CompanyArray[nCorpZ].szName);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubcontrolAreaI,		pPGBlock->m_SubcontrolAreaArray[nDivI].szName);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubcontrolAreaZ,		pPGBlock->m_SubcontrolAreaArray[nDivZ].szName);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubI,		pPGBlock->m_SubstationArray[nSubI].szName);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubJ,		pPGBlock->m_SubstationArray[nSubZ].szName);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szVoltI,	pPGBlock->m_ACLineSegmentArray[i].szVoltI);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szVoltJ,	pPGBlock->m_ACLineSegmentArray[i].szVoltJ);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szName,		pPGBlock->m_ACLineSegmentArray[i].szName);
						}
						else
						{
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szCompanyI,	pPGBlock->m_CompanyArray[nCorpZ].szName);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szCompanyZ,	pPGBlock->m_CompanyArray[nCorpI].szName);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubcontrolAreaI,		pPGBlock->m_SubcontrolAreaArray[nDivZ].szName);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubcontrolAreaZ,		pPGBlock->m_SubcontrolAreaArray[nDivI].szName);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubI,		pPGBlock->m_SubstationArray[nSubZ].szName);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szSubJ,		pPGBlock->m_SubstationArray[nSubI].szName);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szVoltI,	pPGBlock->m_ACLineSegmentArray[i].szVoltJ);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szVoltJ,	pPGBlock->m_ACLineSegmentArray[i].szVoltI);
							strcpy(pPGBlock->m_TielineArray[pPGBlock->m_nRecordNum[PG_TIELINE]].szName,		pPGBlock->m_ACLineSegmentArray[i].szName);
						}
						pPGBlock->m_nRecordNum[PG_TIELINE]++;
					}
				}
			}
			MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_TIELINE);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("FormTieline£¨∫ƒ ±%d∫¡√Î\n", nDur);

		dBeg=clock();
		m_tNodeArray.clear();
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; i++)
		{
			nodeBuf.strSub	=(	pPGBlock->m_DisconnectorArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_DisconnectorArray[i].szVolt);
			nodeBuf.strName	=(	pPGBlock->m_DisconnectorArray[i].szNodeI);
			m_tNodeArray.push_back(nodeBuf);

			nodeBuf.strSub	=(	pPGBlock->m_DisconnectorArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_DisconnectorArray[i].szVolt);
			nodeBuf.strName	=(	pPGBlock->m_DisconnectorArray[i].szNodeJ);
			m_tNodeArray.push_back(nodeBuf);
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_BREAKER]; i++)
		{
			nodeBuf.strSub	=(	pPGBlock->m_BreakerArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_BreakerArray[i].szVolt);
			nodeBuf.strName	=(	pPGBlock->m_BreakerArray[i].szNodeI);
			m_tNodeArray.push_back(nodeBuf);

			nodeBuf.strSub	=(	pPGBlock->m_BreakerArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_BreakerArray[i].szVolt);
			nodeBuf.strName	=(	pPGBlock->m_BreakerArray[i].szNodeJ);
			m_tNodeArray.push_back(nodeBuf);
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
		{
			nodeBuf.strSub	=(	pPGBlock->m_ACLineSegmentArray[i].szSubI);
			nodeBuf.strVolt	=(	pPGBlock->m_ACLineSegmentArray[i].szVoltI);
			nodeBuf.strName	=(	pPGBlock->m_ACLineSegmentArray[i].szNodeI);
			m_tNodeArray.push_back(nodeBuf);

			nodeBuf.strSub	=(	pPGBlock->m_ACLineSegmentArray[i].szSubJ);
			nodeBuf.strVolt	=(	pPGBlock->m_ACLineSegmentArray[i].szVoltJ);
			nodeBuf.strName	=(	pPGBlock->m_ACLineSegmentArray[i].szNodeJ);
			m_tNodeArray.push_back(nodeBuf);
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
		{
			nodeBuf.strSub	=(	pPGBlock->m_TransformerWindingArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_TransformerWindingArray[i].szVoltI);
			nodeBuf.strName	=(	pPGBlock->m_TransformerWindingArray[i].szNodeI);
			m_tNodeArray.push_back(nodeBuf);

			nodeBuf.strSub	=(	pPGBlock->m_TransformerWindingArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_TransformerWindingArray[i].szVoltJ);
			nodeBuf.strName	=(	pPGBlock->m_TransformerWindingArray[i].szNodeJ);
			m_tNodeArray.push_back(nodeBuf);
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SERIESCOMPENSATOR]; i++)
		{
			nodeBuf.strSub	=(	pPGBlock->m_SeriesCompensatorArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_SeriesCompensatorArray[i].szVolt);
			nodeBuf.strName	=(	pPGBlock->m_SeriesCompensatorArray[i].szNodeI);
			m_tNodeArray.push_back(nodeBuf);

			nodeBuf.strSub	=(	pPGBlock->m_SeriesCompensatorArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_SeriesCompensatorArray[i].szVolt);
			nodeBuf.strName	=(	pPGBlock->m_SeriesCompensatorArray[i].szNodeJ);
			m_tNodeArray.push_back(nodeBuf);
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]; i++)
		{
			nodeBuf.strSub	=(	pPGBlock->m_DCLineSegmentArray[i].szSubI);
			nodeBuf.strVolt	=(	pPGBlock->m_DCLineSegmentArray[i].szVoltI);
			nodeBuf.strName	=(	pPGBlock->m_DCLineSegmentArray[i].szNodeI);
			m_tNodeArray.push_back(nodeBuf);

			nodeBuf.strSub	=(	pPGBlock->m_DCLineSegmentArray[i].szSubJ);
			nodeBuf.strVolt	=(	pPGBlock->m_DCLineSegmentArray[i].szVoltJ);
			nodeBuf.strName	=(	pPGBlock->m_DCLineSegmentArray[i].szNodeJ);
			m_tNodeArray.push_back(nodeBuf);
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER]; i++)
		{
			nodeBuf.strSub	=(	pPGBlock->m_RectifierInverterArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_RectifierInverterArray[i].szVoltAC);
			nodeBuf.strName	=(	pPGBlock->m_RectifierInverterArray[i].szNodeAC);
			m_tNodeArray.push_back(nodeBuf);

			nodeBuf.strSub	=(	pPGBlock->m_RectifierInverterArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_RectifierInverterArray[i].szVoltDC);
			nodeBuf.strName	=(	pPGBlock->m_RectifierInverterArray[i].szNodeDCP);
			m_tNodeArray.push_back(nodeBuf);

			nodeBuf.strSub	=(	pPGBlock->m_RectifierInverterArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_RectifierInverterArray[i].szVoltDC);
			nodeBuf.strName	=(	pPGBlock->m_RectifierInverterArray[i].szNodeDCN);
			m_tNodeArray.push_back(nodeBuf);
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACDCCONVERTER]; i++)
		{
			nodeBuf.strSub	=(	pPGBlock->m_ACDCConverterArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_ACDCConverterArray[i].szVoltAC);
			nodeBuf.strName	=(	pPGBlock->m_ACDCConverterArray[i].szNodeAC);
			m_tNodeArray.push_back(nodeBuf);

			nodeBuf.strSub	=(	pPGBlock->m_ACDCConverterArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_ACDCConverterArray[i].szVoltDC);
			nodeBuf.strName	=(	pPGBlock->m_ACDCConverterArray[i].szNodeDC);
			m_tNodeArray.push_back(nodeBuf);
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCDCCONVERTER]; i++)
		{
			nodeBuf.strSub	=(	pPGBlock->m_DCDCConverterArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_DCDCConverterArray[i].szVoltI);
			nodeBuf.strName	=(	pPGBlock->m_DCDCConverterArray[i].szNodeI);
			m_tNodeArray.push_back(nodeBuf);

			nodeBuf.strSub	=(	pPGBlock->m_DCDCConverterArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_DCDCConverterArray[i].szVoltJ);
			nodeBuf.strName	=(	pPGBlock->m_DCDCConverterArray[i].szNodeJ);
			m_tNodeArray.push_back(nodeBuf);
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCBREAKER]; i++)
		{
			nodeBuf.strSub	=(	pPGBlock->m_DCBreakerArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_DCBreakerArray[i].szVolt);
			nodeBuf.strName	=(	pPGBlock->m_DCBreakerArray[i].szNodeI);
			m_tNodeArray.push_back(nodeBuf);

			nodeBuf.strSub	=(	pPGBlock->m_DCBreakerArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_DCBreakerArray[i].szVolt);
			nodeBuf.strName	=(	pPGBlock->m_DCBreakerArray[i].szNodeJ);
			m_tNodeArray.push_back(nodeBuf);
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCSHORTCIRCUITLIMIT]; i++)
		{
			nodeBuf.strSub	=(	pPGBlock->m_DCShortCircuitLimitArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_DCShortCircuitLimitArray[i].szVolt);
			nodeBuf.strName	=(	pPGBlock->m_DCShortCircuitLimitArray[i].szNodeI);
			m_tNodeArray.push_back(nodeBuf);

			nodeBuf.strSub	=(	pPGBlock->m_DCShortCircuitLimitArray[i].szSub);
			nodeBuf.strVolt	=(	pPGBlock->m_DCShortCircuitLimitArray[i].szVolt);
			nodeBuf.strName	=(	pPGBlock->m_DCShortCircuitLimitArray[i].szNodeJ);
			m_tNodeArray.push_back(nodeBuf);
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("FormConnectivityNode£¨∫ƒ ±%d∫¡√Î\n", nDur);

		dBeg=clock();
		sortTempNodeArray(0, (int)m_tNodeArray.size()-1);

		i=0;
		while (i < (int)m_tNodeArray.size())
		{
			strcpy(pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].szSub,	m_tNodeArray[i].strSub.c_str());
			strcpy(pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].szVolt,	m_tNodeArray[i].strVolt.c_str());
			strcpy(pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].szName,	m_tNodeArray[i].strName.c_str());

			j=i+1;
			while (j < (int)m_tNodeArray.size())
			{
				if (strcmp(pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].szSub,	m_tNodeArray[j].strSub.c_str()) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].szVolt,	m_tNodeArray[j].strVolt.c_str()) == 0 &&
					strcmp(pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]].szName,	m_tNodeArray[j].strName.c_str()) == 0)
				{
					i++;
					j++;
				}
				else
				{
					break;
				}
			}
			i++;

			pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]++;
		}
		m_tNodeArray.clear();
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("ProcConnectivityNode£¨∫ƒ ±%d∫¡√Î\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		dBeg=clock();
		for (i=0; i<pPGBlock->m_nRecordNum[PG_BREAKER]; i++)
		{
			strcpy(pPGBlock->m_EdgeBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEBREAKER]].szSub,	pPGBlock->m_BreakerArray[i].szSub);
			strcpy(pPGBlock->m_EdgeBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEBREAKER]].szVolt,	pPGBlock->m_BreakerArray[i].szVolt);
			strcpy(pPGBlock->m_EdgeBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEBREAKER]].szNode,	pPGBlock->m_BreakerArray[i].szNodeI);
			strcpy(pPGBlock->m_EdgeBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEBREAKER]].szName,	pPGBlock->m_BreakerArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEBREAKER]++;

			strcpy(pPGBlock->m_EdgeBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEBREAKER]].szSub,	pPGBlock->m_BreakerArray[i].szSub);
			strcpy(pPGBlock->m_EdgeBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEBREAKER]].szVolt,	pPGBlock->m_BreakerArray[i].szVolt);
			strcpy(pPGBlock->m_EdgeBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEBREAKER]].szNode,	pPGBlock->m_BreakerArray[i].szNodeJ);
			strcpy(pPGBlock->m_EdgeBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEBREAKER]].szName,	pPGBlock->m_BreakerArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEBREAKER]++;
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("FormBreaker2£¨∫ƒ ±%d∫¡√Î\n", nDur);

		dBeg=clock();
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; i++)
		{
			strcpy(pPGBlock->m_EdgeDisconnectorArray[pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]].szSub,	pPGBlock->m_DisconnectorArray[i].szSub);
			strcpy(pPGBlock->m_EdgeDisconnectorArray[pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]].szVolt,	pPGBlock->m_DisconnectorArray[i].szVolt);
			strcpy(pPGBlock->m_EdgeDisconnectorArray[pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]].szNode,	pPGBlock->m_DisconnectorArray[i].szNodeI);
			strcpy(pPGBlock->m_EdgeDisconnectorArray[pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]].szName,	pPGBlock->m_DisconnectorArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]++;

			strcpy(pPGBlock->m_EdgeDisconnectorArray[pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]].szSub,	pPGBlock->m_DisconnectorArray[i].szSub);
			strcpy(pPGBlock->m_EdgeDisconnectorArray[pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]].szVolt,	pPGBlock->m_DisconnectorArray[i].szVolt);
			strcpy(pPGBlock->m_EdgeDisconnectorArray[pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]].szNode,	pPGBlock->m_DisconnectorArray[i].szNodeJ);
			strcpy(pPGBlock->m_EdgeDisconnectorArray[pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]].szName,	pPGBlock->m_DisconnectorArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEDISCONNECTOR]++;
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("FormDisconnector2£¨∫ƒ ±%d∫¡√Î\n", nDur);

		dBeg=clock();
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
		{
			strcpy(pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]].szSub,	pPGBlock->m_ACLineSegmentArray[i].szSubI);
			strcpy(pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]].szVolt,	pPGBlock->m_ACLineSegmentArray[i].szVoltI);
			strcpy(pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]].szNode,	pPGBlock->m_ACLineSegmentArray[i].szNodeI);
			strcpy(pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]].szName,	pPGBlock->m_ACLineSegmentArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]++;

			strcpy(pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]].szSub,	pPGBlock->m_ACLineSegmentArray[i].szSubJ);
			strcpy(pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]].szVolt,	pPGBlock->m_ACLineSegmentArray[i].szVoltJ);
			strcpy(pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]].szNode,	pPGBlock->m_ACLineSegmentArray[i].szNodeJ);
			strcpy(pPGBlock->m_EdgeACLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]].szName,	pPGBlock->m_ACLineSegmentArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEACLINESEGMENT]++;
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("FormACLineSegment2£¨∫ƒ ±%d∫¡√Î\n", nDur);

		dBeg=clock();
		for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
		{
			strcpy(pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]].szSub,	pPGBlock->m_TransformerWindingArray[i].szSub);
			strcpy(pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]].szVolt,	pPGBlock->m_TransformerWindingArray[i].szVoltI);
			strcpy(pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]].szNode,	pPGBlock->m_TransformerWindingArray[i].szNodeI);
			strcpy(pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]].szName,	pPGBlock->m_TransformerWindingArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]++;

			strcpy(pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]].szSub,	pPGBlock->m_TransformerWindingArray[i].szSub);
			strcpy(pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]].szVolt,	pPGBlock->m_TransformerWindingArray[i].szVoltJ);
			strcpy(pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]].szNode,	pPGBlock->m_TransformerWindingArray[i].szNodeJ);
			strcpy(pPGBlock->m_EdgeTransformerWindingArray[pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]].szName,	pPGBlock->m_TransformerWindingArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGETRANSFORMERWINDING]++;
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("FormTransformerWinding2£¨∫ƒ ±%d∫¡√Î\n", nDur);

		dBeg=clock();
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SERIESCOMPENSATOR]; i++)
		{
			strcpy(pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]].szSub,	pPGBlock->m_SeriesCompensatorArray[i].szSub);
			strcpy(pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]].szVolt,	pPGBlock->m_SeriesCompensatorArray[i].szVolt);
			strcpy(pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]].szNode,	pPGBlock->m_SeriesCompensatorArray[i].szNodeI);
			strcpy(pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]].szName,	pPGBlock->m_SeriesCompensatorArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]++;

			strcpy(pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]].szSub,	pPGBlock->m_SeriesCompensatorArray[i].szSub);
			strcpy(pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]].szVolt,	pPGBlock->m_SeriesCompensatorArray[i].szVolt);
			strcpy(pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]].szNode,	pPGBlock->m_SeriesCompensatorArray[i].szNodeJ);
			strcpy(pPGBlock->m_EdgeSeriesCompensatorArray[pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]].szName,	pPGBlock->m_SeriesCompensatorArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGESERIESCOMPENSATOR]++;
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("FormSeriesCompensator2£¨∫ƒ ±%d∫¡√Î\n", nDur);

		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_EDGEBREAKER);
		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_EDGEDISCONNECTOR);
		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_EDGEACLINESEGMENT);
		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_EDGETRANSFORMERWINDING);
		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_EDGESERIESCOMPENSATOR);

		//////////////////////////////////////////////////////////////////////////
		dBeg=clock();
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]; i++)
		{
			strcpy(pPGBlock->m_EdgeDCLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]].szSub,	pPGBlock->m_DCLineSegmentArray[i].szSubI);
			strcpy(pPGBlock->m_EdgeDCLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]].szVolt,	pPGBlock->m_DCLineSegmentArray[i].szVoltI);
			strcpy(pPGBlock->m_EdgeDCLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]].szNode,	pPGBlock->m_DCLineSegmentArray[i].szNodeI);
			strcpy(pPGBlock->m_EdgeDCLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]].szName,	pPGBlock->m_DCLineSegmentArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]++;

			strcpy(pPGBlock->m_EdgeDCLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]].szSub,	pPGBlock->m_DCLineSegmentArray[i].szSubJ);
			strcpy(pPGBlock->m_EdgeDCLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]].szVolt,	pPGBlock->m_DCLineSegmentArray[i].szVoltJ);
			strcpy(pPGBlock->m_EdgeDCLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]].szNode,	pPGBlock->m_DCLineSegmentArray[i].szNodeJ);
			strcpy(pPGBlock->m_EdgeDCLineSegmentArray[pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]].szName,	pPGBlock->m_DCLineSegmentArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEDCLINESEGMENT]++;
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("FormDCLineSegment2£¨∫ƒ ±%d∫¡√Î\n", nDur);

		dBeg=clock();
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACDCCONVERTER]; i++)
		{
			strcpy(pPGBlock->m_EdgeADConverterArray[pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER]].szSub,	pPGBlock->m_ACDCConverterArray[i].szSub);
			strcpy(pPGBlock->m_EdgeADConverterArray[pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER]].szVolt,	pPGBlock->m_ACDCConverterArray[i].szVoltAC);
			strcpy(pPGBlock->m_EdgeADConverterArray[pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER]].szNode,	pPGBlock->m_ACDCConverterArray[i].szNodeAC);
			strcpy(pPGBlock->m_EdgeADConverterArray[pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER]].szName,	pPGBlock->m_ACDCConverterArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER]++;

			strcpy(pPGBlock->m_EdgeADConverterArray[pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER]].szSub,	pPGBlock->m_ACDCConverterArray[i].szSub);
			strcpy(pPGBlock->m_EdgeADConverterArray[pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER]].szVolt,	pPGBlock->m_ACDCConverterArray[i].szVoltDC);
			strcpy(pPGBlock->m_EdgeADConverterArray[pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER]].szNode,	pPGBlock->m_ACDCConverterArray[i].szNodeDC);
			strcpy(pPGBlock->m_EdgeADConverterArray[pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER]].szName,	pPGBlock->m_ACDCConverterArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEADCONVERTER]++;
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("FormACDCConverter2£¨∫ƒ ±%d∫¡√Î\n", nDur);

		dBeg=clock();
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCDCCONVERTER]; i++)
		{
			strcpy(pPGBlock->m_EdgeDDConverterArray[pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER]].szSub,	pPGBlock->m_DCDCConverterArray[i].szSub);
			strcpy(pPGBlock->m_EdgeDDConverterArray[pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER]].szVolt,	pPGBlock->m_DCDCConverterArray[i].szVoltI);
			strcpy(pPGBlock->m_EdgeDDConverterArray[pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER]].szNode,	pPGBlock->m_DCDCConverterArray[i].szNodeI);
			strcpy(pPGBlock->m_EdgeDDConverterArray[pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER]].szName,	pPGBlock->m_DCDCConverterArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER]++;

			strcpy(pPGBlock->m_EdgeDDConverterArray[pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER]].szSub,	pPGBlock->m_DCDCConverterArray[i].szSub);
			strcpy(pPGBlock->m_EdgeDDConverterArray[pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER]].szVolt,	pPGBlock->m_DCDCConverterArray[i].szVoltJ);
			strcpy(pPGBlock->m_EdgeDDConverterArray[pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER]].szNode,	pPGBlock->m_DCDCConverterArray[i].szNodeJ);
			strcpy(pPGBlock->m_EdgeDDConverterArray[pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER]].szName,	pPGBlock->m_DCDCConverterArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEDDCONVERTER]++;
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("FormDCDCConverter2£¨∫ƒ ±%d∫¡√Î\n", nDur);

		dBeg=clock();
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCBREAKER]; i++)
		{
			strcpy(pPGBlock->m_EdgeDCBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER]].szSub,	pPGBlock->m_DCBreakerArray[i].szSub);
			strcpy(pPGBlock->m_EdgeDCBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER]].szVolt,	pPGBlock->m_DCBreakerArray[i].szVolt);
			strcpy(pPGBlock->m_EdgeDCBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER]].szNode,	pPGBlock->m_DCBreakerArray[i].szNodeI);
			strcpy(pPGBlock->m_EdgeDCBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER]].szName,	pPGBlock->m_DCBreakerArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER]++;

			strcpy(pPGBlock->m_EdgeDCBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER]].szSub,	pPGBlock->m_DCBreakerArray[i].szSub);
			strcpy(pPGBlock->m_EdgeDCBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER]].szVolt,	pPGBlock->m_DCBreakerArray[i].szVolt);
			strcpy(pPGBlock->m_EdgeDCBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER]].szNode,	pPGBlock->m_DCBreakerArray[i].szNodeJ);
			strcpy(pPGBlock->m_EdgeDCBreakerArray[pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER]].szName,	pPGBlock->m_DCBreakerArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEDCBREAKER]++;
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("FormDCBreaker2£¨∫ƒ ±%d∫¡√Î\n", nDur);

		dBeg=clock();
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCSHORTCIRCUITLIMIT]; i++)
		{
			strcpy(pPGBlock->m_EdgeDCShortCircuitLimitArray[pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT]].szSub,	pPGBlock->m_DCShortCircuitLimitArray[i].szSub);
			strcpy(pPGBlock->m_EdgeDCShortCircuitLimitArray[pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT]].szVolt,	pPGBlock->m_DCShortCircuitLimitArray[i].szVolt);
			strcpy(pPGBlock->m_EdgeDCShortCircuitLimitArray[pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT]].szNode,	pPGBlock->m_DCShortCircuitLimitArray[i].szNodeI);
			strcpy(pPGBlock->m_EdgeDCShortCircuitLimitArray[pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT]].szName,	pPGBlock->m_DCShortCircuitLimitArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT]++;

			strcpy(pPGBlock->m_EdgeDCShortCircuitLimitArray[pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT]].szSub,	pPGBlock->m_DCShortCircuitLimitArray[i].szSub);
			strcpy(pPGBlock->m_EdgeDCShortCircuitLimitArray[pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT]].szVolt,	pPGBlock->m_DCShortCircuitLimitArray[i].szVolt);
			strcpy(pPGBlock->m_EdgeDCShortCircuitLimitArray[pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT]].szNode,	pPGBlock->m_DCShortCircuitLimitArray[i].szNodeJ);
			strcpy(pPGBlock->m_EdgeDCShortCircuitLimitArray[pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT]].szName,	pPGBlock->m_DCShortCircuitLimitArray[i].szName);
			pPGBlock->m_nRecordNum[PG_EDGEDCSHORTCIRCUITLIMIT]++;
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("FormDCShortCircuitLimit2£¨∫ƒ ±%d∫¡√Î\n", nDur);

		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_EDGEDCLINESEGMENT);
		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_EDGEADCONVERTER);
		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_EDGEDDCONVERTER);
		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_EDGEDCBREAKER);
		MemDBBase::MDBSort<tagPGBlock>(pPGBlock, PG_EDGEDCSHORTCIRCUITLIMIT);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		log_info("fromDerivedDevice£¨∫ƒ ±%d∫¡√Î \n", nDur);
	}
}
