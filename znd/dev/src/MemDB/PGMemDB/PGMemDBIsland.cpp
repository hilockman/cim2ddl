#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"
#include <float.h>

namespace PGMemDB 
{
	int	GetACIslandSlackGen(tagPGBlock* pPGBlock, const int nIsland)
	{
		int		nSub, nVolt, nDev, nMax;
		float	fMaxP;

		fMaxP=-FLT_MAX;
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

	int	GetACIslandSlackACDCConverter(tagPGBlock* pPGBlock, const int nIsland)
	{
		int		nSub, nDev, nMax;
		float	fMaxP;

		//////////////////////////////////////////////////////////////////////////
		//	首先选择定电压控制模式的变换器
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nDev=pPGBlock->m_SubstationArray[nSub].nADConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nADConverterRange; nDev++)
			{
				if (pPGBlock->m_ACDCConverterArray[nDev].nNodeAC < 0 || pPGBlock->m_ACDCConverterArray[nDev].nIslandAC != nIsland || pPGBlock->m_ACDCConverterArray[nDev].bOutage)
					continue;

				if (strlen(pPGBlock->m_ACDCConverterArray[nDev].szElectronicTransformer) > 0 && (pPGBlock->m_ACDCConverterArray[nDev].fControlVac > 0.8 && pPGBlock->m_ACDCConverterArray[nDev].fControlVac < 1.2))
					return nDev;
			}
		}

		fMaxP=-FLT_MAX;
		nMax=-1;
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nDev=pPGBlock->m_SubstationArray[nSub].nADConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nADConverterRange; nDev++)
			{
				if (pPGBlock->m_ACDCConverterArray[nDev].nNodeAC < 0 || pPGBlock->m_ACDCConverterArray[nDev].nIslandAC != nIsland || pPGBlock->m_ACDCConverterArray[nDev].bOutage)
					continue;

				if (pPGBlock->m_ACDCConverterArray[nDev].fRatedPower > fMaxP && (pPGBlock->m_ACDCConverterArray[nDev].fControlVac > 0.8 && pPGBlock->m_ACDCConverterArray[nDev].fControlVac < 1.2))
				{
					nMax=nDev;
					fMaxP=pPGBlock->m_ACDCConverterArray[nDev].fRatedPower;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		//	网内选择Converter
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nDev=pPGBlock->m_SubstationArray[nSub].nADConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nADConverterRange; nDev++)
			{
				if (pPGBlock->m_ACDCConverterArray[nDev].nNodeAC < 0 || pPGBlock->m_ACDCConverterArray[nDev].nIslandAC != nIsland || pPGBlock->m_ACDCConverterArray[nDev].bOutage)
					continue;

				if (strlen(pPGBlock->m_ACDCConverterArray[nDev].szElectronicTransformer) > 0)
					return nDev;
			}
		}

		fMaxP=-FLT_MAX;
		nMax=-1;
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nDev=pPGBlock->m_SubstationArray[nSub].nADConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nADConverterRange; nDev++)
			{
				if (pPGBlock->m_ACDCConverterArray[nDev].nNodeAC < 0 || pPGBlock->m_ACDCConverterArray[nDev].nIslandAC != nIsland || pPGBlock->m_ACDCConverterArray[nDev].bOutage)
					continue;

				if (pPGBlock->m_ACDCConverterArray[nDev].fRatedPower > fMaxP)
				{
					nMax=nDev;
					fMaxP=pPGBlock->m_ACDCConverterArray[nDev].fRatedPower;
				}
			}
		}
		return nMax;
	}

	int	GetDCIslandSlackACDCConverter(tagPGBlock* pPGBlock, const int nIsland, const unsigned char bStrict)
	{
		int		nSub, nDev, nMax;
		int		nMaxGen;

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nDev=pPGBlock->m_SubstationArray[nSub].nADConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nADConverterRange; nDev++)
			{
				if (pPGBlock->m_ACDCConverterArray[nDev].nNodeDC < 0 || pPGBlock->m_ACDCConverterArray[nDev].nIslandDC != nIsland || pPGBlock->m_ACDCConverterArray[nDev].bOutage)
					continue;

				if (strlen(pPGBlock->m_ACDCConverterArray[nDev].szElectronicTransformer) > 0 && pPGBlock->m_ACDCConverterArray[nDev].nDCControlMode == PGEnumConverterDCControlMode_VConst)
				{
					if (pPGBlock->m_ACDCConverterArray[nDev].fDCControlValue < 0.8 || pPGBlock->m_ACDCConverterArray[nDev].fDCControlValue > 1.2)
						pPGBlock->m_ACDCConverterArray[nDev].fDCControlValue = 1.0;
					log_info("电岛=%d 设置AC/DCConverter %s 为平衡机\n", nIsland, pPGBlock->m_ACDCConverterArray[nDev].szName);
					return nDev;
				}
			}
		}
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nDev=pPGBlock->m_SubstationArray[nSub].nADConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nADConverterRange; nDev++)
			{
				if (pPGBlock->m_ACDCConverterArray[nDev].nNodeDC < 0 || pPGBlock->m_ACDCConverterArray[nDev].nIslandDC != nIsland || pPGBlock->m_ACDCConverterArray[nDev].bOutage)
					continue;

				if (pPGBlock->m_ACDCConverterArray[nDev].nDCControlMode == PGEnumConverterDCControlMode_VConst)
				{
					if (pPGBlock->m_ACDCConverterArray[nDev].fDCControlValue < 0.8 || pPGBlock->m_ACDCConverterArray[nDev].fDCControlValue > 1.2)
						pPGBlock->m_ACDCConverterArray[nDev].fDCControlValue = 1.0;
					log_info("电岛=%d 设置AC/DCConverter %s 为平衡机\n", nIsland, pPGBlock->m_ACDCConverterArray[nDev].szName);
					return nDev;
				}
			}
		}

		if (!bStrict)
		{
			nMaxGen=0;
			nMax=-1;
			for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
			{
				for (nDev=pPGBlock->m_SubstationArray[nSub].nADConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nADConverterRange; nDev++)
				{
					if (pPGBlock->m_ACDCConverterArray[nDev].nNodeDC < 0 || pPGBlock->m_ACDCConverterArray[nDev].nIslandDC != nIsland || pPGBlock->m_ACDCConverterArray[nDev].bOutage)
						continue;

					if (pPGBlock->m_IslandArray[pPGBlock->m_ACDCConverterArray[nDev].nIslandAC].nGenNum > nMaxGen)
					{
						nMax=nDev;
						nMaxGen=pPGBlock->m_IslandArray[pPGBlock->m_ACDCConverterArray[nDev].nIslandAC].nGenNum;

						log_info("电岛=%d 设置AC/DCConverter %s 为平衡机\n", nIsland, pPGBlock->m_ACDCConverterArray[nDev].szName);
					}
				}
			}
			return nMax;
		}
		return -1;
	}

	int	GetDCIslandSlackDCDCConverter(tagPGBlock* pPGBlock, const int nIsland, const unsigned char bStrict)
	{
		int	nSub, nDev, nMax;
		int	nMaxLine;

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nDev=pPGBlock->m_SubstationArray[nSub].nDDConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nDDConverterRange; nDev++)
			{
				if (pPGBlock->m_DCDCConverterArray[nDev].nNodeI < 0 || pPGBlock->m_DCDCConverterArray[nDev].nNodeJ < 0)
					continue;
				if (pPGBlock->m_DCDCConverterArray[nDev].bOutage)
					continue;
				if (strlen(pPGBlock->m_DCDCConverterArray[nDev].szElectronicTransformer) <= 0)
					continue;

				if (pPGBlock->m_DCDCConverterArray[nDev].nIslandI == nIsland)
				{
					if (pPGBlock->m_DCDCConverterArray[nDev].nControlModeI == PGEnumConverterDCControlMode_VConst)
					{
						if (pPGBlock->m_DCDCConverterArray[nDev].fControlValueI < 0.8 || pPGBlock->m_DCDCConverterArray[nDev].fControlValueI > 1.2)
							pPGBlock->m_DCDCConverterArray[nDev].fControlValueI = 1.0;

						log_info("电岛=%d 设置DC/DCConverter %s 为平衡机\n", nIsland, pPGBlock->m_DCDCConverterArray[nDev].szName);
						return nDev;
					}
				}
				else if (pPGBlock->m_DCDCConverterArray[nDev].nIslandJ == nIsland)
				{
					if (pPGBlock->m_DCDCConverterArray[nDev].nControlModeJ == PGEnumConverterDCControlMode_VConst)
					{
						if (pPGBlock->m_DCDCConverterArray[nDev].fControlValueJ < 0.8 || pPGBlock->m_DCDCConverterArray[nDev].fControlValueJ > 1.2)
							pPGBlock->m_DCDCConverterArray[nDev].fControlValueJ = 1.0;

						log_info("电岛=%d 设置DC/DCConverter %s 为平衡机\n", nIsland, pPGBlock->m_DCDCConverterArray[nDev].szName);
						return nDev;
					}
				}
			}
		}

		if (!bStrict)
		{
			for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
			{
				for (nDev=pPGBlock->m_SubstationArray[nSub].nDDConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nDDConverterRange; nDev++)
				{
					if (pPGBlock->m_DCDCConverterArray[nDev].nNodeI < 0 || pPGBlock->m_DCDCConverterArray[nDev].nNodeJ < 0)
						continue;
					if (pPGBlock->m_DCDCConverterArray[nDev].bOutage)
						continue;

					if (pPGBlock->m_DCDCConverterArray[nDev].nIslandI == nIsland || pPGBlock->m_DCDCConverterArray[nDev].nIslandJ == nIsland)
					{
						if (strlen(pPGBlock->m_DCDCConverterArray[nDev].szElectronicTransformer) > 0)
						{
							log_info("电岛=%d 设置DC/DCConverter %s 为平衡机\n", nIsland, pPGBlock->m_DCDCConverterArray[nDev].szName);
							return nDev;
						}
					}
				}
			}
		}

		if (!bStrict)
		{
			nMaxLine=0;
			nMax=-1;
			for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
			{
				for (nDev=pPGBlock->m_SubstationArray[nSub].nDDConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nDDConverterRange; nDev++)
				{
					if (pPGBlock->m_DCDCConverterArray[nDev].nNodeI < 0 || pPGBlock->m_DCDCConverterArray[nDev].nNodeJ < 0)
						continue;
					if (pPGBlock->m_DCDCConverterArray[nDev].bOutage)
						continue;

					if (pPGBlock->m_DCDCConverterArray[nDev].nIslandI == nIsland)
					{
						if (pPGBlock->m_IslandArray[pPGBlock->m_DCDCConverterArray[nDev].nIslandJ].nDCLineNum > nMaxLine)
						{
							nMax=nDev;
							nMaxLine=pPGBlock->m_IslandArray[pPGBlock->m_DCDCConverterArray[nDev].nIslandJ].nDCLineNum;
						}
					}
					else if (pPGBlock->m_DCDCConverterArray[nDev].nIslandJ == nIsland)
					{
						if (pPGBlock->m_IslandArray[pPGBlock->m_DCDCConverterArray[nDev].nIslandI].nDCLineNum > nMaxLine)
						{
							nMax=nDev;
							nMaxLine=pPGBlock->m_IslandArray[pPGBlock->m_DCDCConverterArray[nDev].nIslandI].nDCLineNum;
							log_info("电岛=%d 设置DC/DCConverter %s 为平衡机\n", nIsland, pPGBlock->m_DCDCConverterArray[nDev].szName);
						}
					}
				}
			}
			return nMax;
		}
		return -1;
	}

	int PGMemDBIslandRadiant(tagPGBlock* pPGBlock, const int nIsland)
	{
		register int	i;
		int		nSub, nVolt, nNode, nDev, nONode;
		unsigned char	bRinged;
		int		nParallelNum, nParallelArray[100];
		int		nNodeNum, *nNodeArray;

		std::vector<unsigned char>	bLineProcArray;

		nNodeArray=(int*)malloc(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]*sizeof(int));
		if (nNodeArray == NULL)
			return 0;

		bLineProcArray.resize(pPGBlock->m_nRecordNum[PG_ACLINESEGMENT], 0);
		for (i=0; i<bLineProcArray.size(); i++)
			bLineProcArray[i] = 0;
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					for (nDev=pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange; nDev<pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange; nDev++)
					{
						if (bLineProcArray[pPGBlock->m_EdgeACLineSegmentArray[nDev].nACLineSegment])
							continue;
						if (pPGBlock->m_ACLineSegmentArray[pPGBlock->m_EdgeACLineSegmentArray[nDev].nACLineSegment].nIsland != nIsland)
							continue;

						PGGetParallelACLine(pPGBlock, pPGBlock->m_EdgeACLineSegmentArray[nDev].nACLineSegment, 0, nParallelNum, nParallelArray);
						for (i=0; i<nParallelNum; i++)
						{
							pPGBlock->m_ACLineSegmentArray[nParallelArray[i]].bOpen=1;
							bLineProcArray[nParallelArray[i]] = 1;
						}

						nONode=(pPGBlock->m_ACLineSegmentArray[pPGBlock->m_EdgeACLineSegmentArray[nDev].nACLineSegment].nNodeI == nNode) ?
							pPGBlock->m_ACLineSegmentArray[pPGBlock->m_EdgeACLineSegmentArray[nDev].nACLineSegment].nNodeJ : pPGBlock->m_ACLineSegmentArray[pPGBlock->m_EdgeACLineSegmentArray[nDev].nACLineSegment].nNodeI;

						bRinged=0;
						PGTraverseNet(pPGBlock, nNode, N_CheckStatus, 0, nNodeNum, nNodeArray);
						for (i=0; i<nNodeNum; i++)
						{
							if (nNodeArray[i] == nONode)
							{
								bRinged=1;
								break;
							}
						}

						for (i=0; i<nParallelNum; i++)
							pPGBlock->m_ACLineSegmentArray[nParallelArray[i]].bOpen=0;

						if (bRinged)
						{
							free(nNodeArray);
							return 0;
						}
					}
				}
			}
		}

		bLineProcArray.resize(pPGBlock->m_nRecordNum[PG_DCLINESEGMENT], 0);
		for (i=0; i<bLineProcArray.size(); i++)
			bLineProcArray[i] = 0;
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
				{
					for (nDev=pPGBlock->m_ConnectivityNodeArray[nNode].nDCLineSegmentRange; nDev<pPGBlock->m_ConnectivityNodeArray[nNode+1].nDCLineSegmentRange; nDev++)
					{
						if (bLineProcArray[pPGBlock->m_EdgeDCLineSegmentArray[nDev].nDCLineSegment])
							continue;
						if (pPGBlock->m_DCLineSegmentArray[pPGBlock->m_EdgeDCLineSegmentArray[nDev].nDCLineSegment].nIsland != nIsland)
							continue;

						PGGetParallelDCLine(pPGBlock, pPGBlock->m_EdgeDCLineSegmentArray[nDev].nDCLineSegment, 0, nParallelNum, nParallelArray);
						for (i=0; i<nParallelNum; i++)
						{
							pPGBlock->m_DCLineSegmentArray[nParallelArray[i]].bOpen=1;
							bLineProcArray[nParallelArray[i]] = 1;
						}

						nONode=(pPGBlock->m_DCLineSegmentArray[pPGBlock->m_EdgeDCLineSegmentArray[nDev].nDCLineSegment].nNodeI == nNode) ?
							pPGBlock->m_DCLineSegmentArray[pPGBlock->m_EdgeDCLineSegmentArray[nDev].nDCLineSegment].nNodeJ : pPGBlock->m_DCLineSegmentArray[pPGBlock->m_EdgeDCLineSegmentArray[nDev].nDCLineSegment].nNodeI;

						bRinged=0;
						PGTraverseNet(pPGBlock, nNode, N_CheckStatus, 0, nNodeNum, nNodeArray);
						for (i=0; i<nNodeNum; i++)
						{
							if (nNodeArray[i] == nONode)
							{
								bRinged=1;
								break;
							}
						}

						for (i=0; i<nParallelNum; i++)
							pPGBlock->m_DCLineSegmentArray[nParallelArray[i]].bOpen=0;

						if (bRinged)
						{
							free(nNodeArray);
							return 0;
						}
					}
				}
			}
		}

		free(nNodeArray);

		return 1;
	}

	void PGMemDBIslandStatistic(tagPGBlock* pPGBlock)
	{
		int		nIsland, nDev;

		for (nIsland=0; nIsland<pPGBlock->m_nRecordNum[PG_ISLAND]; nIsland++)
		{
			pPGBlock->m_IslandArray[nIsland].fGenP=0;
			pPGBlock->m_IslandArray[nIsland].fGenQ=0;
			pPGBlock->m_IslandArray[nIsland].fLoadP=0;
			pPGBlock->m_IslandArray[nIsland].fLoadQ=0;
			pPGBlock->m_IslandArray[nIsland].fShuntQ=0;
			pPGBlock->m_IslandArray[nIsland].fLossP=0;
			pPGBlock->m_IslandArray[nIsland].fLossQ=0;

			pPGBlock->m_IslandArray[nIsland].nGenNum=0;
			pPGBlock->m_IslandArray[nIsland].nLoadNum=0;
			pPGBlock->m_IslandArray[nIsland].nCapNum=0;
			pPGBlock->m_IslandArray[nIsland].nSReacNum=0;
			pPGBlock->m_IslandArray[nIsland].nACBusNum=0;
			pPGBlock->m_IslandArray[nIsland].nACLineNum=0;
			pPGBlock->m_IslandArray[nIsland].nWindNum=0;

			pPGBlock->m_IslandArray[nIsland].nWTNum=0;
			pPGBlock->m_IslandArray[nIsland].nPVNum=0;
			pPGBlock->m_IslandArray[nIsland].nEVNum=0;
			pPGBlock->m_IslandArray[nIsland].nECSNum=0;
			pPGBlock->m_IslandArray[nIsland].nSTMNum=0;

			pPGBlock->m_IslandArray[nIsland].nDCBusNum=0;
			pPGBlock->m_IslandArray[nIsland].nDCLineNum=0;
			pPGBlock->m_IslandArray[nIsland].nADConverterNum=0;
			pPGBlock->m_IslandArray[nIsland].nDDConverterNum=0;
			pPGBlock->m_IslandArray[nIsland].nDCFCLNum=0;
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_SynchronousMachineArray[nDev].nIsland].nGenNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_SynchronousMachineArray[nDev].nIsland].fGenP += pPGBlock->m_SynchronousMachineArray[nDev].fPlanP;
			pPGBlock->m_IslandArray[pPGBlock->m_SynchronousMachineArray[nDev].nIsland].fGenQ += pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ;


			if (pPGBlock->m_SynchronousMachineArray[nDev].nType != PGEnumSynchronousMachine_Type_WindTurbine &&
				pPGBlock->m_SynchronousMachineArray[nDev].nType != PGEnumSynchronousMachine_Type_PhotoVoltaic &&
				pPGBlock->m_SynchronousMachineArray[nDev].nType != PGEnumSynchronousMachine_Type_Equivalent)
			{
				double fAuxP=0, fAuxQ=0;
				double fAuxPCon=pPGBlock->m_SynchronousMachineArray[nDev].fAuxPca;
				double fAuxPVar=pPGBlock->m_SynchronousMachineArray[nDev].fAuxPva;
				double fAuxCoef=0.8f;
				if (pPGBlock->m_SynchronousMachineArray[nDev].fAuxFactor > 0.5)
					fAuxCoef=pPGBlock->m_SynchronousMachineArray[nDev].fAuxFactor;

				if (fAuxPCon > 0.001 || fAuxPVar > 0.001)
				{
					fAuxP=pPGBlock->m_SynchronousMachineArray[nDev].fPMax*fAuxPCon+pPGBlock->m_SynchronousMachineArray[nDev].fPlanP*fAuxPVar;
					fAuxQ=(float)(fAuxP*sqrt(1-fAuxCoef*fAuxCoef)/fAuxCoef);
				}
				pPGBlock->m_IslandArray[pPGBlock->m_SynchronousMachineArray[nDev].nIsland].fLoadP += fAuxP;
				pPGBlock->m_IslandArray[pPGBlock->m_SynchronousMachineArray[nDev].nIsland].fLoadQ += fAuxQ;
			}
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_EnergyConsumerArray[nDev].nIsland].nLoadNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_EnergyConsumerArray[nDev].nIsland].fLoadP += pPGBlock->m_EnergyConsumerArray[nDev].fPlanP;
			pPGBlock->m_IslandArray[pPGBlock->m_EnergyConsumerArray[nDev].nIsland].fLoadQ += pPGBlock->m_EnergyConsumerArray[nDev].fPlanQ;
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SHUNTCOMPENSATOR]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_ShuntCompensatorArray[nDev].nIsland].nCapNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_ShuntCompensatorArray[nDev].nIsland].fShuntQ += pPGBlock->m_ShuntCompensatorArray[nDev].fCap;
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SERIESCOMPENSATOR]; nDev++)
			pPGBlock->m_IslandArray[pPGBlock->m_SeriesCompensatorArray[nDev].nIsland].nSReacNum++;

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_BUSBARSECTION]; nDev++)
			pPGBlock->m_IslandArray[pPGBlock->m_BusbarSectionArray[nDev].nIsland].nACBusNum++;

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_ACLineSegmentArray[nDev].nIsland].nACLineNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_ACLineSegmentArray[nDev].nIsland].fLossP += pPGBlock->m_ACLineSegmentArray[nDev].fLossP;
			pPGBlock->m_IslandArray[pPGBlock->m_ACLineSegmentArray[nDev].nIsland].fLossQ += pPGBlock->m_ACLineSegmentArray[nDev].fLossQ;
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_TransformerWindingArray[nDev].nIsland].nWindNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_TransformerWindingArray[nDev].nIsland].fLossP += pPGBlock->m_TransformerWindingArray[nDev].fLossP;
			pPGBlock->m_IslandArray[pPGBlock->m_TransformerWindingArray[nDev].nIsland].fLossQ += pPGBlock->m_TransformerWindingArray[nDev].fLossQ;
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_WINDTURBINE]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_WindTurbineArray[nDev].nIsland].nWTNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_WindTurbineArray[nDev].nIsland].fGenP += pPGBlock->m_WindTurbineArray[nDev].fPlanP;
			pPGBlock->m_IslandArray[pPGBlock->m_WindTurbineArray[nDev].nIsland].fGenQ += pPGBlock->m_WindTurbineArray[nDev].fPlanQ;
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_PHOTOVOLTAIC]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_PhotoVoltaicArray[nDev].nIsland].nPVNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_PhotoVoltaicArray[nDev].nIsland].fGenP += pPGBlock->m_PhotoVoltaicArray[nDev].fPlanP;
			pPGBlock->m_IslandArray[pPGBlock->m_PhotoVoltaicArray[nDev].nIsland].fGenQ += pPGBlock->m_PhotoVoltaicArray[nDev].fPlanQ;
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_EVSTATION]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_EVStationArray[nDev].nIsland].nEVNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_EVStationArray[nDev].nIsland].fLoadP += pPGBlock->m_EVStationArray[nDev].fPlanP;
			pPGBlock->m_IslandArray[pPGBlock->m_EVStationArray[nDev].nIsland].fLoadQ += pPGBlock->m_EVStationArray[nDev].fPlanQ;
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ELECTROCHEMICALENERGYSTORAGE]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_ElectroChemicalEnergyStorageArray[nDev].nIsland].nECSNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_ElectroChemicalEnergyStorageArray[nDev].nIsland].fLoadP += pPGBlock->m_ElectroChemicalEnergyStorageArray[nDev].fPlanP;
			pPGBlock->m_IslandArray[pPGBlock->m_ElectroChemicalEnergyStorageArray[nDev].nIsland].fLoadQ += pPGBlock->m_ElectroChemicalEnergyStorageArray[nDev].fPlanQ;
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SOLARTHERMALMACHINE]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_SolarThermalMachineArray[nDev].nIsland].nSTMNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_SolarThermalMachineArray[nDev].nIsland].fGenP += pPGBlock->m_SolarThermalMachineArray[nDev].fPlanP;
			pPGBlock->m_IslandArray[pPGBlock->m_SolarThermalMachineArray[nDev].nIsland].fGenQ += pPGBlock->m_SolarThermalMachineArray[nDev].fPlanQ;
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_DCBUSBARSECTION]; nDev++)
			pPGBlock->m_IslandArray[pPGBlock->m_DCBusbarSectionArray[nDev].nIsland].nDCBusNum++;

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ACDCCONVERTER]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_ACDCConverterArray[nDev].nIslandAC].nADConverterNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_ACDCConverterArray[nDev].nIslandDC].nADConverterNum++;

			pPGBlock->m_IslandArray[pPGBlock->m_ACDCConverterArray[nDev].nIslandAC].fLossP += pPGBlock->m_ACDCConverterArray[nDev].fLoss/2;
			pPGBlock->m_IslandArray[pPGBlock->m_ACDCConverterArray[nDev].nIslandDC].fLossP += pPGBlock->m_ACDCConverterArray[nDev].fLoss/2;
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_DCDCCONVERTER]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_DCDCConverterArray[nDev].nIslandI].nDDConverterNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_DCDCConverterArray[nDev].nIslandJ].nDDConverterNum++;

			pPGBlock->m_IslandArray[pPGBlock->m_DCDCConverterArray[nDev].nIslandI].fLossP += pPGBlock->m_DCDCConverterArray[nDev].fLoss/2;
			pPGBlock->m_IslandArray[pPGBlock->m_DCDCConverterArray[nDev].nIslandJ].fLossP += pPGBlock->m_DCDCConverterArray[nDev].fLoss/2;
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_DCSHORTCIRCUITLIMIT]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_DCShortCircuitLimitArray[nDev].nIsland].nDCFCLNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_DCShortCircuitLimitArray[nDev].nIsland].fLossP += pPGBlock->m_DCShortCircuitLimitArray[nDev].fLoss;
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]; nDev++)
		{
			pPGBlock->m_IslandArray[pPGBlock->m_DCLineSegmentArray[nDev].nIsland].nDCLineNum++;
			pPGBlock->m_IslandArray[pPGBlock->m_DCLineSegmentArray[nDev].nIsland].fLossP += pPGBlock->m_DCLineSegmentArray[nDev].fLossP;
		}
	}

	void PGMemDBSetJointNodeACIsland(tagPGBlock* pPGBlock, const int nIsland, int nJointNodeNum, int* pnJointNodeArray)
	{
		register int	i;
		int				nNode, nNodeVolt;

		for (nNode=0; nNode<nJointNodeNum; nNode++)
		{
			nNodeVolt=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nVoltageLevelPtr;
			pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nIsland=(short)nIsland;

			for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nSynchronousMachineRange; i++)
			{
				if (pPGBlock->m_SynchronousMachineArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_SynchronousMachineArray[i].nIsland=(short)nIsland;
			}

			for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nBusbarSectionRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nBusbarSectionRange; i++)
			{
				if (pPGBlock->m_BusbarSectionArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_BusbarSectionArray[i].nIsland=(short)nIsland;
			}
			for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nEnergyConsumerRange; i++)
			{
				if (pPGBlock->m_EnergyConsumerArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_EnergyConsumerArray[i].nIsland=(short)nIsland;
			}
			for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nShuntCompensatorRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nShuntCompensatorRange; i++)
			{
				if (pPGBlock->m_ShuntCompensatorArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_ShuntCompensatorArray[i].nIsland=(short)nIsland;
			}
			for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nGroundTransformerRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nGroundTransformerRange; i++)
			{
				if (pPGBlock->m_GroundTransformerArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_GroundTransformerArray[i].nIsland=(short)nIsland;
			}
			for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nACLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nACLineSegmentRange; i++)
				pPGBlock->m_ACLineSegmentArray[pPGBlock->m_EdgeACLineSegmentArray[i].nACLineSegment].nIsland=(short)nIsland;

			for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nTransformerWindingRange; i++)
			{
				pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nIsland=(short)nIsland;
				pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nNodeI].nIsland=(short)nIsland;
				pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding].nNodeJ].nIsland=(short)nIsland;
			}

			for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nSeriesCompensatorRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nSeriesCompensatorRange; i++)
				pPGBlock->m_SeriesCompensatorArray[pPGBlock->m_EdgeSeriesCompensatorArray[i].nSeriesCompensator].nIsland=(short)nIsland;

			for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nBreakerRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nBreakerRange; i++)
				pPGBlock->m_BreakerArray[pPGBlock->m_EdgeBreakerArray[i].nBreaker].nIsland=(short)nIsland;

			for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nDisconnectorRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nDisconnectorRange; i++)
				pPGBlock->m_DisconnectorArray[pPGBlock->m_EdgeDisconnectorArray[i].nDisconnector].nIsland=(short)nIsland;

			for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nADConverterRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nADConverterRange; i++)
				pPGBlock->m_ACDCConverterArray[pPGBlock->m_EdgeADConverterArray[i].nConverter].nIslandAC=(short)nIsland;

			for (i=0; i<pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER]; i++)
			{
				if (pPGBlock->m_RectifierInverterArray[i].nNodeAC == pnJointNodeArray[nNode])
					pPGBlock->m_RectifierInverterArray[i].nIslandAC=(short)nIsland;
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_WINDTURBINE]; i++)
			{
				if (pPGBlock->m_WindTurbineArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_WindTurbineArray[i].nIsland=(short)nIsland;
			}

			for (i=0; i<pPGBlock->m_nRecordNum[PG_PHOTOVOLTAIC]; i++)
			{
				if (pPGBlock->m_PhotoVoltaicArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_PhotoVoltaicArray[i].nIsland=(short)nIsland;
			}

			for (i=0; i<pPGBlock->m_nRecordNum[PG_EVSTATION]; i++)
			{
				if (pPGBlock->m_EVStationArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_EVStationArray[i].nIsland=(short)nIsland;
			}

			for (i=0; i<pPGBlock->m_nRecordNum[PG_ELECTROCHEMICALENERGYSTORAGE]; i++)
			{
				if (pPGBlock->m_ElectroChemicalEnergyStorageArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_ElectroChemicalEnergyStorageArray[i].nIsland=(short)nIsland;
			}

			for (i=0; i<pPGBlock->m_nRecordNum[PG_SOLARTHERMALMACHINE]; i++)
			{
				if (pPGBlock->m_SolarThermalMachineArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_SolarThermalMachineArray[i].nIsland=(short)nIsland;
			}
		}
	}

	void PGMemDBACIsland(tagPGBlock* pPGBlock, const int bCheckOpen)
	{
		register int	i;
		int				nSub, nVolt, nDev;
		int				nJointNodeNum, *pnJointNodeArray;
		std::vector<int>	bProcArray;

		unsigned char	bCheckStatus=(bCheckOpen) ? Y_CheckStatus : N_CheckStatus;

		pnJointNodeArray=(int*)malloc(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]*sizeof(int));
		if (!pnJointNodeArray)
			return;

		bProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE], 0);
		for (i=0; i<bProcArray.size(); i++)
			bProcArray[i] = 0;
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
				{
					if (pPGBlock->m_SynchronousMachineArray[nDev].nNode < 0)
						continue;

					if (bProcArray[pPGBlock->m_SynchronousMachineArray[nDev].nNode] != 0)
						continue;

					bProcArray[pPGBlock->m_SynchronousMachineArray[nDev].nNode]=1;
					nJointNodeNum=0;
					PGTraverseNet(pPGBlock, pPGBlock->m_SynchronousMachineArray[nDev].nNode, bCheckStatus, 0, nJointNodeNum, pnJointNodeArray);
					for (i=0; i<nJointNodeNum; i++)
						bProcArray[pnJointNodeArray[i]] = 1;

					PGMemDBSetJointNodeACIsland(pPGBlock, pPGBlock->m_nRecordNum[PG_ISLAND], nJointNodeNum, pnJointNodeArray);

					pPGBlock->m_nRecordNum[PG_ISLAND]++;
				}
			}

			for (nDev=pPGBlock->m_SubstationArray[nSub].nADConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nADConverterRange; nDev++)
			{
				if (pPGBlock->m_ACDCConverterArray[nDev].nNodeAC < 0)
					continue;

				if (bProcArray[pPGBlock->m_ACDCConverterArray[nDev].nNodeAC] != 0)
					continue;

				bProcArray[pPGBlock->m_ACDCConverterArray[nDev].nNodeAC]=1;
				nJointNodeNum=0;
				PGTraverseNet(pPGBlock, pPGBlock->m_ACDCConverterArray[nDev].nNodeAC, bCheckStatus, 0, nJointNodeNum, pnJointNodeArray);
				for (i=0; i<nJointNodeNum; i++)
					bProcArray[pnJointNodeArray[i]] = 1;

				PGMemDBSetJointNodeACIsland(pPGBlock, pPGBlock->m_nRecordNum[PG_ISLAND], nJointNodeNum, pnJointNodeArray);

				pPGBlock->m_nRecordNum[PG_ISLAND]++;
			}
		}
		free(pnJointNodeArray);
	}

	void PGMemDBSetJointNodeDCIsland(tagPGBlock* pPGBlock, const int nIsland, int nJointNodeNum, int* pnJointNodeArray)
	{
		register int	i;
		int		nNode, nNodeVolt;

		for (nNode=0; nNode<nJointNodeNum; nNode++)
		{
			nNodeVolt=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nVoltageLevelPtr;
			pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nIsland=(short)nIsland;
			pPGBlock->m_IslandArray[nIsland].bDCIsland = 1;

			for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nSynchronousMachineRange; i++)
			{
				if (pPGBlock->m_SynchronousMachineArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_SynchronousMachineArray[i].nIsland=(short)nIsland;
			}
			for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nEnergyConsumerRange; i++)
			{
				if (pPGBlock->m_EnergyConsumerArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_EnergyConsumerArray[i].nIsland=(short)nIsland;
			}
			for (i=pPGBlock->m_VoltageLevelArray[nNodeVolt].nDCBusbarSectionRange; i<pPGBlock->m_VoltageLevelArray[nNodeVolt+1].nDCBusbarSectionRange; i++)
			{
				if (pPGBlock->m_DCBusbarSectionArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_DCBusbarSectionArray[i].nIsland=(short)nIsland;
			}

			for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nDCLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nDCLineSegmentRange; i++)
				pPGBlock->m_DCLineSegmentArray[pPGBlock->m_EdgeDCLineSegmentArray[i].nDCLineSegment].nIsland=(short)nIsland;

			for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nDCShortCircuitLimitRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nDCShortCircuitLimitRange; i++)
				pPGBlock->m_DCShortCircuitLimitArray[pPGBlock->m_EdgeDCShortCircuitLimitArray[i].nDCShortCircuitLimit].nIsland=(short)nIsland;

			for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nDCBreakerRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nDCBreakerRange; i++)
				pPGBlock->m_DCBreakerArray[pPGBlock->m_EdgeDCBreakerArray[i].nDCBreaker].nIsland=(short)nIsland;

			for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nADConverterRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nADConverterRange; i++)
				pPGBlock->m_ACDCConverterArray[pPGBlock->m_EdgeADConverterArray[i].nConverter].nIslandDC=(short)nIsland;

			for (i=pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]].nDDConverterRange; i<pPGBlock->m_ConnectivityNodeArray[pnJointNodeArray[nNode]+1].nDDConverterRange; i++)
			{
				if (pPGBlock->m_DCDCConverterArray[pPGBlock->m_EdgeDDConverterArray[i].nConverter].nNodeI == pnJointNodeArray[nNode])
					pPGBlock->m_DCDCConverterArray[pPGBlock->m_EdgeDDConverterArray[i].nConverter].nIslandI=(short)nIsland;
				else
					pPGBlock->m_DCDCConverterArray[pPGBlock->m_EdgeDDConverterArray[i].nConverter].nIslandJ=(short)nIsland;
			}

			for (i=0; i<pPGBlock->m_nRecordNum[PG_WINDTURBINE]; i++)
			{
				if (pPGBlock->m_WindTurbineArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_WindTurbineArray[i].nIsland=(short)nIsland;
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_PHOTOVOLTAIC]; i++)
			{
				if (pPGBlock->m_PhotoVoltaicArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_PhotoVoltaicArray[i].nIsland=(short)nIsland;
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_EVSTATION]; i++)
			{
				if (pPGBlock->m_EVStationArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_EVStationArray[i].nIsland=(short)nIsland;
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_ELECTROCHEMICALENERGYSTORAGE]; i++)
			{
				if (pPGBlock->m_ElectroChemicalEnergyStorageArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_ElectroChemicalEnergyStorageArray[i].nIsland=(short)nIsland;
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_SOLARTHERMALMACHINE]; i++)
			{
				if (pPGBlock->m_SolarThermalMachineArray[i].nNode == pnJointNodeArray[nNode])
					pPGBlock->m_SolarThermalMachineArray[i].nIsland=(short)nIsland;
			}
		}
	}

	void PGMemDBDCIsland(tagPGBlock* pPGBlock, const int bCheckOpen)
	{
		register int	i;
		int				nSub, nDev;
		int				nJointNodeNum, *pnJointNodeArray;
		std::vector<int>	bProcArray;

		unsigned char	bCheckStatus=(bCheckOpen) ? Y_CheckStatus : N_CheckStatus;
		pnJointNodeArray=(int*)malloc(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]*sizeof(int));
		if (!pnJointNodeArray)
			return;

		bProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE], 0);
		for (i=0; i<bProcArray.size(); i++)
			bProcArray[i] = 0;
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nDev=pPGBlock->m_SubstationArray[nSub].nADConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nADConverterRange; nDev++)
			{
				if (pPGBlock->m_ACDCConverterArray[nDev].nNodeAC < 0 || pPGBlock->m_ACDCConverterArray[nDev].nNodeDC < 0)
					continue;
				if (bProcArray[pPGBlock->m_ACDCConverterArray[nDev].nNodeDC] != 0)
					continue;
				bProcArray[pPGBlock->m_ACDCConverterArray[nDev].nNodeDC]=1;

				pPGBlock->m_IslandArray[pPGBlock->m_nRecordNum[PG_ISLAND]].bDead = pPGBlock->m_IslandArray[pPGBlock->m_ACDCConverterArray[nDev].nNodeAC].bDead;

				nJointNodeNum=0;
				PGTraverseNet(pPGBlock, pPGBlock->m_ACDCConverterArray[nDev].nNodeDC, bCheckStatus, 0, nJointNodeNum, pnJointNodeArray);
				for (i=0; i<nJointNodeNum; i++)
					bProcArray[pnJointNodeArray[i]] = 1;
				PGMemDBSetJointNodeDCIsland(pPGBlock, pPGBlock->m_nRecordNum[PG_ISLAND], nJointNodeNum, pnJointNodeArray);
				pPGBlock->m_nRecordNum[PG_ISLAND]++;
			}

			for (nDev=pPGBlock->m_SubstationArray[nSub].nDDConverterRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nDDConverterRange; nDev++)
			{
				if (pPGBlock->m_DCDCConverterArray[nDev].nNodeI < 0 || pPGBlock->m_DCDCConverterArray[nDev].nNodeJ < 0)
					continue;

				if (bProcArray[pPGBlock->m_DCDCConverterArray[nDev].nNodeI] == 0)
				{
					bProcArray[pPGBlock->m_DCDCConverterArray[nDev].nNodeI]=1;
					nJointNodeNum=0;
					PGTraverseNet(pPGBlock, pPGBlock->m_DCDCConverterArray[nDev].nNodeI, bCheckStatus, 0, nJointNodeNum, pnJointNodeArray);
					for (i=0; i<nJointNodeNum; i++)
						bProcArray[pnJointNodeArray[i]] = 1;
					PGMemDBSetJointNodeDCIsland(pPGBlock, pPGBlock->m_nRecordNum[PG_ISLAND], nJointNodeNum, pnJointNodeArray);
					pPGBlock->m_nRecordNum[PG_ISLAND]++;
				}
				if (bProcArray[pPGBlock->m_DCDCConverterArray[nDev].nNodeJ] == 0)
				{
					bProcArray[pPGBlock->m_DCDCConverterArray[nDev].nNodeJ]=1;
					nJointNodeNum=0;
					PGTraverseNet(pPGBlock, pPGBlock->m_DCDCConverterArray[nDev].nNodeJ, bCheckStatus, 0, nJointNodeNum, pnJointNodeArray);
					for (i=0; i<nJointNodeNum; i++)
						bProcArray[pnJointNodeArray[i]] = 1;
					PGMemDBSetJointNodeDCIsland(pPGBlock, pPGBlock->m_nRecordNum[PG_ISLAND], nJointNodeNum, pnJointNodeArray);
					pPGBlock->m_nRecordNum[PG_ISLAND]++;
				}
			}
		}

		free(pnJointNodeArray);
	}

	void PGMemDBIslandSlack(tagPGBlock* pPGBlock)
	{
		register int	i;
		unsigned char	bSlacked;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_ISLAND]; i++)
		{
			if (pPGBlock->m_IslandArray[i].bDCIsland)
				continue;

			bSlacked = 0;
			if (!bSlacked)
			{
				if (pPGBlock->m_IslandArray[i].nGenNum > 0)
				{
					pPGBlock->m_IslandArray[i].nSlackDev=(short)GetACIslandSlackGen(pPGBlock, i);
					if (pPGBlock->m_IslandArray[i].nSlackDev >= 0)
					{
						pPGBlock->m_IslandArray[i].nSlackDevType=PG_SYNCHRONOUSMACHINE;
						strcpy(pPGBlock->m_IslandArray[i].szSlackSub, pPGBlock->m_SynchronousMachineArray[pPGBlock->m_IslandArray[i].nSlackDev].szSub);
						strcpy(pPGBlock->m_IslandArray[i].szSlackDevName, pPGBlock->m_SynchronousMachineArray[pPGBlock->m_IslandArray[i].nSlackDev].szName);
						bSlacked = 1;
					}
				}
			}

			if (!bSlacked)
			{
				if (pPGBlock->m_IslandArray[i].nADConverterNum > 0)
				{
					pPGBlock->m_IslandArray[i].nSlackDev=(short)GetACIslandSlackACDCConverter(pPGBlock, i);
					if (pPGBlock->m_IslandArray[i].nSlackDev >= 0)
					{
						pPGBlock->m_IslandArray[i].nSlackDevType=PG_ACDCCONVERTER;
						strcpy(pPGBlock->m_IslandArray[i].szSlackSub, pPGBlock->m_ACDCConverterArray[pPGBlock->m_IslandArray[i].nSlackDev].szSub);
						strcpy(pPGBlock->m_IslandArray[i].szSlackDevName, pPGBlock->m_ACDCConverterArray[pPGBlock->m_IslandArray[i].nSlackDev].szName);
						bSlacked = 1;
					}
				}
			}

			if (!bSlacked)
				pPGBlock->m_IslandArray[i].bDead=1;
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_ISLAND]; i++)
		{
			if (!pPGBlock->m_IslandArray[i].bDCIsland)
				continue;

			bSlacked = 0;
			if (pPGBlock->m_IslandArray[i].nADConverterNum > 0)
			{
				pPGBlock->m_IslandArray[i].nSlackDev=(short)GetDCIslandSlackACDCConverter(pPGBlock, i, 1);
				if (pPGBlock->m_IslandArray[i].nSlackDev >= 0)
				{
					pPGBlock->m_IslandArray[i].nSlackDevType=PG_ACDCCONVERTER;
					strcpy(pPGBlock->m_IslandArray[i].szSlackSub, pPGBlock->m_ACDCConverterArray[pPGBlock->m_IslandArray[i].nSlackDev].szSub);
					strcpy(pPGBlock->m_IslandArray[i].szSlackDevName, pPGBlock->m_ACDCConverterArray[pPGBlock->m_IslandArray[i].nSlackDev].szName);
					bSlacked = 1;
				}
			}
			if (!bSlacked)
			{
				if (pPGBlock->m_IslandArray[i].nDDConverterNum > 0)
				{
					pPGBlock->m_IslandArray[i].nSlackDev=(short)GetDCIslandSlackDCDCConverter(pPGBlock, i , 1);
					if (pPGBlock->m_IslandArray[i].nSlackDev >= 0)
					{
						pPGBlock->m_IslandArray[i].nSlackDevType=PG_DCDCCONVERTER;
						strcpy(pPGBlock->m_IslandArray[i].szSlackSub, pPGBlock->m_DCDCConverterArray[pPGBlock->m_IslandArray[i].nSlackDev].szSub);
						strcpy(pPGBlock->m_IslandArray[i].szSlackDevName, pPGBlock->m_DCDCConverterArray[pPGBlock->m_IslandArray[i].nSlackDev].szName);
						bSlacked = 1;
					}
				}
			}
			if (!bSlacked)
			{
				if (pPGBlock->m_IslandArray[i].nADConverterNum > 0)
				{
					pPGBlock->m_IslandArray[i].nSlackDev=(short)GetDCIslandSlackACDCConverter(pPGBlock, i, 0);
					if (pPGBlock->m_IslandArray[i].nSlackDev >= 0)
					{
						pPGBlock->m_IslandArray[i].nSlackDevType=PG_ACDCCONVERTER;
						strcpy(pPGBlock->m_IslandArray[i].szSlackSub, pPGBlock->m_ACDCConverterArray[pPGBlock->m_IslandArray[i].nSlackDev].szSub);
						strcpy(pPGBlock->m_IslandArray[i].szSlackDevName, pPGBlock->m_ACDCConverterArray[pPGBlock->m_IslandArray[i].nSlackDev].szName);
						bSlacked = 1;
					}
				}
			}
			if (!bSlacked)
			{
				if (pPGBlock->m_IslandArray[i].nDDConverterNum > 0)
				{
					pPGBlock->m_IslandArray[i].nSlackDev=(short)GetDCIslandSlackDCDCConverter(pPGBlock, i , 0);
					if (pPGBlock->m_IslandArray[i].nSlackDev >= 0)
					{
						pPGBlock->m_IslandArray[i].nSlackDevType=PG_DCDCCONVERTER;
						strcpy(pPGBlock->m_IslandArray[i].szSlackSub, pPGBlock->m_DCDCConverterArray[pPGBlock->m_IslandArray[i].nSlackDev].szSub);
						strcpy(pPGBlock->m_IslandArray[i].szSlackDevName, pPGBlock->m_DCDCConverterArray[pPGBlock->m_IslandArray[i].nSlackDev].szName);
						bSlacked = 1;
					}
				}
			}

			if (!bSlacked)
				pPGBlock->m_IslandArray[i].bDead=1;
		}
	}

	void PGMemDBIsland(tagPGBlock* pPGBlock, const int bCheckOpen)
	{
		register int	i;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_GROUNDDISCONNECTOR]; i++)
			pPGBlock->m_GroundDisconnectorArray[i].nStatus=1;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
			pPGBlock->m_ConnectivityNodeArray[i].bOpen=0;

		//////////////////////////////////////////////////////////////////////////
		//	交流设备电岛初始化
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
		for (i=0; i<pPGBlock->m_nRecordNum[PG_BREAKER]; i++)
			pPGBlock->m_BreakerArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DISCONNECTOR]; i++)
			pPGBlock->m_DisconnectorArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_GROUNDTRANSFORMER]; i++)
			pPGBlock->m_GroundTransformerArray[i].nIsland=0;

		//////////////////////////////////////////////////////////////////////////
		//	直流设备电岛初始化
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCLINESEGMENT]; i++)
			pPGBlock->m_DCLineSegmentArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_RECTIFIERINVERTER]; i++)
			pPGBlock->m_RectifierInverterArray[i].nIslandAC=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACDCCONVERTER]; i++)
		{
			pPGBlock->m_ACDCConverterArray[i].nIslandAC=0;
			pPGBlock->m_ACDCConverterArray[i].nIslandDC=0;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_DCDCCONVERTER]; i++)
		{
			pPGBlock->m_DCDCConverterArray[i].nIslandI=0;
			pPGBlock->m_DCDCConverterArray[i].nIslandJ=0;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ELECTROCHEMICALENERGYSTORAGE]; i++)
			pPGBlock->m_ElectroChemicalEnergyStorageArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SOLARTHERMALMACHINE]; i++)
			pPGBlock->m_SolarThermalMachineArray[i].nIsland=0;

		//////////////////////////////////////////////////////////////////////////
		//	交直流设备电岛初始化
		for (i=0; i<pPGBlock->m_nRecordNum[PG_WINDTURBINE]; i++)
			pPGBlock->m_WindTurbineArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_PHOTOVOLTAIC]; i++)
			pPGBlock->m_PhotoVoltaicArray[i].nIsland=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_EVSTATION]; i++)
			pPGBlock->m_EVStationArray[i].nIsland=0;

		//////////////////////////////////////////////////////////////////////////
		for (i=0; i<pPGBlock->m_nRecordNum[PG_TOPOBUS]; i++)
			pPGBlock->m_TopoBusArray[i].nIsland=0;
		for (i=0; i<PG_MaxIsland; i++)
			memset(&pPGBlock->m_IslandArray[i], 0, sizeof(tagPGIsland));

		pPGBlock->m_nRecordNum[PG_ISLAND]=1;

		PGMemDBACIsland(pPGBlock, bCheckOpen);
		PGMemDBDCIsland(pPGBlock, bCheckOpen);

		PGMemDBIslandStatistic(pPGBlock);
		PGMemDBIslandSlack(pPGBlock);

		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
			pPGBlock->m_TopoBusArray[pPGBlock->m_ConnectivityNodeArray[i].nTopoBus].nIsland=pPGBlock->m_ConnectivityNodeArray[i].nIsland;
	}
}
