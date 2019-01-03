// PGMemDBTraverse.cpp : 定义 DLL 应用程序的导出函数。
//
#include "stdafx.h"
#include "PGMemDB.h"

namespace PGMemDB 
{
	//	bChkOpen=N_CheckStatus		表示不考虑OPEN状态
	//	bInBus=N_BusBound			表示不以BUS为边界
	//	bChkBreak=Y_BreakerBound	表示不以Breaker为边界
	void PGTraverseTopo(tagPGBlock* pPGBlock, const int nStartNode, const int bChkBreakerOpen, const int bChkSwitchOpen, int& nNodeNum, int nNodeArray[])
	{
		register int	i, j;
		int	nNode, nVolt, nDev;
		int	nNodeNumOfLayer;
		std::vector<unsigned char>	bUnProcArray;
		std::vector<int> nMidNodeArray;

		nNodeNum=0;

		nVolt=-1;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; i++)
		{
			if (strcmp(pPGBlock->m_VoltageLevelArray[i].szSub, pPGBlock->m_ConnectivityNodeArray[nStartNode].szSub) == 0 &&
				strcmp(pPGBlock->m_VoltageLevelArray[i].szName, pPGBlock->m_ConnectivityNodeArray[nStartNode].szVolt) == 0)
			{
				nVolt=i;
				break;
			}
		}
		if (nVolt < 0)
			return;

		bUnProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]);
		for (i=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; i++)
			bUnProcArray[i]=1;

		nNodeArray[nNodeNum++]=nStartNode;
		bUnProcArray[nStartNode]=0;
		nNodeNumOfLayer=0;
		while (1)
		{
			nMidNodeArray.clear();
			for (i=nNodeNumOfLayer; i<nNodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].bOpen != 0 && nNodeArray[i] != nStartNode)
					continue;

				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
				{
					nDev=pPGBlock->m_EdgeBreakerArray[j].nBreaker;
					if (pPGBlock->m_BreakerArray[nDev].bOutage)
						continue;
					if (bChkBreakerOpen == Y_CheckStatus)		//	检查开合
					{
						if (pPGBlock->m_BreakerArray[nDev].nStatus != 0)
							continue;
					}
					nNode=(nNodeArray[i] == pPGBlock->m_BreakerArray[nDev].nNodeI) ? pPGBlock->m_BreakerArray[nDev].nNodeJ:pPGBlock->m_BreakerArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCBreakerRange; j++)
				{
					nDev=pPGBlock->m_EdgeDCBreakerArray[j].nDCBreaker;
					if (pPGBlock->m_DCBreakerArray[nDev].bOutage)
						continue;
					if (bChkBreakerOpen == Y_CheckStatus)		//	检查开合
					{
						if (pPGBlock->m_DCBreakerArray[nDev].nStatus != 0)
							continue;
					}
					nNode=(nNodeArray[i] == pPGBlock->m_DCBreakerArray[nDev].nNodeI) ? pPGBlock->m_DCBreakerArray[nDev].nNodeJ:pPGBlock->m_DCBreakerArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDisconnectorRange; j++)
				{
					nDev=pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector;
					if (pPGBlock->m_DisconnectorArray[nDev].bOutage)
						continue;

					if (bChkSwitchOpen == Y_CheckStatus)		//	检查开合
					{
						if (pPGBlock->m_DisconnectorArray[nDev].nStatus  != 0)
							continue;
					}
					else
					{
						//					if (STRICMP(pPGBlock->m_DisconnectorArray[nDev].szType, "GroundDisconnector") == 0)
						//						continue;
					}

					nNode=(nNodeArray[i] == pPGBlock->m_DisconnectorArray[nDev].nNodeI) ? pPGBlock->m_DisconnectorArray[nDev].nNodeJ:pPGBlock->m_DisconnectorArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
			}
			if (nMidNodeArray.empty())
				break;
			nNodeNumOfLayer=nNodeNum;
			for (i=0; i<(int)nMidNodeArray.size(); i++)
				nNodeArray[nNodeNum++]=nMidNodeArray[i];
		}

		bUnProcArray.clear();
	}

	void PGTraverseVolt(tagPGBlock* pPGBlock, const int nStartNode, const int bChkBreakerOpen, const int bChkSwitchOpen, const int bInBus, const int bChkBreak,  int& nNodeNum, int nNodeArray[])
	{
		register int	i, j;
		int	nNode, nVolt, nDev;
		int	nNodeNumOfLayer;
		std::vector<unsigned char>	bUnProcArray;
		std::vector<int> nMidNodeArray;

		nNodeNum=0;

		nVolt=-1;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_VOLTAGELEVEL]; i++)
		{
			if (strcmp(pPGBlock->m_VoltageLevelArray[i].szSub, pPGBlock->m_ConnectivityNodeArray[nStartNode].szSub) == 0 &&
				strcmp(pPGBlock->m_VoltageLevelArray[i].szName, pPGBlock->m_ConnectivityNodeArray[nStartNode].szVolt) == 0)
			{
				nVolt=i;
				break;
			}
		}
		if (nVolt < 0)
			return;

		bUnProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]);
		for (i=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; i++)
			bUnProcArray[i]=1;

		nNodeArray[nNodeNum++]=nStartNode;
		bUnProcArray[nStartNode]=0;
		nNodeNumOfLayer=0;
		while (1)
		{
			nMidNodeArray.clear();
			for (i=nNodeNumOfLayer; i<nNodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].bOpen != 0 && nNodeArray[i] != nStartNode)
					continue;

				if (bChkBreak == N_BreakerBound)			//	检查开关
				{
					for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
					{
						if (bInBus == Y_BusBound)			//	母线范围内
						{
							if (nNodeArray[i] != nStartNode && pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBusbarSectionPtr >= 0)
								continue;
						}
						nDev=pPGBlock->m_EdgeBreakerArray[j].nBreaker;
						if (pPGBlock->m_BreakerArray[nDev].bOutage)
							continue;

						if (bChkBreakerOpen == Y_CheckStatus)		//	检查开合
						{
							if (pPGBlock->m_BreakerArray[nDev].nStatus != 0)
								continue;
						}

						nNode=(nNodeArray[i] == pPGBlock->m_BreakerArray[nDev].nNodeI) ? pPGBlock->m_BreakerArray[nDev].nNodeJ:pPGBlock->m_BreakerArray[nDev].nNodeI;
						if (nNode < 0)
							continue;
						if (bUnProcArray[nNode])
						{
							nMidNodeArray.push_back(nNode);
							bUnProcArray[nNode]=0;
						}
					}
					for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCBreakerRange; j++)
					{
						if (bInBus == Y_BusBound)			//	母线范围内
						{
							if (nNodeArray[i] != nStartNode && pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBusbarSectionPtr >= 0)
								continue;
						}
						nDev=pPGBlock->m_EdgeDCBreakerArray[j].nDCBreaker;
						if (pPGBlock->m_DCBreakerArray[nDev].bOutage)
							continue;

						if (bChkBreakerOpen == Y_CheckStatus)		//	检查开合
						{
							if (pPGBlock->m_DCBreakerArray[nDev].nStatus != 0)
								continue;
						}

						nNode=(nNodeArray[i] == pPGBlock->m_DCBreakerArray[nDev].nNodeI) ? pPGBlock->m_DCBreakerArray[nDev].nNodeJ:pPGBlock->m_DCBreakerArray[nDev].nNodeI;
						if (nNode < 0)
							continue;
						if (bUnProcArray[nNode])
						{
							nMidNodeArray.push_back(nNode);
							bUnProcArray[nNode]=0;
						}
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDisconnectorRange; j++)
				{
					if (bInBus == Y_BusBound)			//	母线范围内
					{
						if (nNodeArray[i] != nStartNode && pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBusbarSectionPtr >= 0)
							continue;
					}
					nDev=pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector;
					if (pPGBlock->m_DisconnectorArray[nDev].bOutage)
						continue;

					if (bChkSwitchOpen == Y_CheckStatus)		//	检查开合
					{
						if (pPGBlock->m_DisconnectorArray[nDev].nStatus  != 0)
							continue;
					}
					else
					{
						//					if (STRICMP(pPGBlock->m_DisconnectorArray[nDev].szType, "GroundDisconnector") == 0)
						//						continue;
					}

					nNode=(nNodeArray[i] == pPGBlock->m_DisconnectorArray[nDev].nNodeI) ? pPGBlock->m_DisconnectorArray[nDev].nNodeJ:pPGBlock->m_DisconnectorArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nSeriesCompensatorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nSeriesCompensatorRange; j++)
				{
					nDev=pPGBlock->m_EdgeSeriesCompensatorArray[j].nSeriesCompensator;
					if (pPGBlock->m_SeriesCompensatorArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_SeriesCompensatorArray[nDev].nNodeI) ? pPGBlock->m_SeriesCompensatorArray[nDev].nNodeJ : pPGBlock->m_SeriesCompensatorArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCShortCircuitLimitRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCShortCircuitLimitRange; j++)
				{
					nDev=pPGBlock->m_EdgeDCShortCircuitLimitArray[j].nDCShortCircuitLimit;
					if (pPGBlock->m_DCShortCircuitLimitArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_DCShortCircuitLimitArray[nDev].nNodeI) ? pPGBlock->m_DCShortCircuitLimitArray[nDev].nNodeJ : pPGBlock->m_DCShortCircuitLimitArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
			}
			if (nMidNodeArray.empty())
				break;
			nNodeNumOfLayer=nNodeNum;
			for (i=0; i<(int)nMidNodeArray.size(); i++)
				nNodeArray[nNodeNum++]=nMidNodeArray[i];
		}

		bUnProcArray.clear();
	}

	void PGTraverseSub(tagPGBlock* pPGBlock, const int nStartNode, const int bChkOpen, int& nNodeNum, int nNodeArray[])
	{
		register int	i, j;
		int		nDev, nNode;
		int		nNodeNumOfLayer;
		std::vector<unsigned char>	bUnProcArray;
		std::vector<int> nMidNodeArray;

		nNodeNum=0;

		bUnProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]);
		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
			bUnProcArray[i]=1;

		nNodeArray[nNodeNum++]=nStartNode;
		bUnProcArray[nStartNode]=0;
		nNodeNumOfLayer=0;
		while (1)
		{
			nMidNodeArray.clear();
			for (i=nNodeNumOfLayer; i<nNodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].bOpen != 0 && nNodeArray[i] != nStartNode)
					continue;

				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
				{
					nDev=pPGBlock->m_EdgeBreakerArray[j].nBreaker;
					if (pPGBlock->m_BreakerArray[nDev].bOutage)
						continue;
					if (bChkOpen == Y_CheckStatus)
					{
						if (pPGBlock->m_BreakerArray[nDev].nStatus  != 0)
							continue;
					}

					nNode=(nNodeArray[i] == pPGBlock->m_BreakerArray[nDev].nNodeI) ? pPGBlock->m_BreakerArray[nDev].nNodeJ:pPGBlock->m_BreakerArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDisconnectorRange; j++)
				{
					nDev=pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector;
					if (pPGBlock->m_DisconnectorArray[nDev].bOutage)
						continue;
					if (bChkOpen == Y_CheckStatus)
					{
						if (pPGBlock->m_DisconnectorArray[nDev].nStatus  != 0)
							continue;
					}

					nNode=(nNodeArray[i] == pPGBlock->m_DisconnectorArray[nDev].nNodeI) ? pPGBlock->m_DisconnectorArray[nDev].nNodeJ:pPGBlock->m_DisconnectorArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange; j++)
				{
					if (pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[j].nTransformerWinding].bOpen != 0)
						continue;
					if (pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[j].nTransformerWinding].bOutage)
						continue;

					nDev=pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[j].nTransformerWinding].nTran;
					nNode=pPGBlock->m_PowerTransformerArray[nDev].nNodeH;
					if (nNode >= 0 && nNode != nNodeArray[i])
					{
						if (pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nDev].nWindH].bOpen == 0 && bUnProcArray[nNode])
						{
							nMidNodeArray.push_back(nNode);
							bUnProcArray[nNode]=0;
						}
					}
					nNode=pPGBlock->m_PowerTransformerArray[nDev].nNodeM;
					if (nNode >= 0 && nNode != nNodeArray[i])
					{
						if (pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nDev].nWindM].bOpen == 0 && bUnProcArray[nNode])
						{
							nMidNodeArray.push_back(nNode);
							bUnProcArray[nNode]=0;
						}
					}
					nNode=pPGBlock->m_PowerTransformerArray[nDev].nNodeL;
					if (nNode >= 0 && nNode != nNodeArray[i])
					{
						if (pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nDev].nWindL].bOpen == 0 && bUnProcArray[nNode])
						{
							nMidNodeArray.push_back(nNode);
							bUnProcArray[nNode]=0;
						}
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nSeriesCompensatorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nSeriesCompensatorRange; j++)
				{
					nDev=pPGBlock->m_EdgeSeriesCompensatorArray[j].nSeriesCompensator;
					if (pPGBlock->m_SeriesCompensatorArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_SeriesCompensatorArray[nDev].nNodeI) ? pPGBlock->m_SeriesCompensatorArray[nDev].nNodeJ : pPGBlock->m_SeriesCompensatorArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}

				//////////////////////////////////////////////////////////////////////////
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCBreakerRange; j++)
				{
					nDev=pPGBlock->m_EdgeDCBreakerArray[j].nDCBreaker;
					if (pPGBlock->m_DCBreakerArray[nDev].bOutage)
						continue;
					if (bChkOpen == Y_CheckStatus)
					{
						if (pPGBlock->m_DCBreakerArray[nDev].nStatus  != 0)
							continue;
					}

					nNode=(nNodeArray[i] == pPGBlock->m_DCBreakerArray[nDev].nNodeI) ? pPGBlock->m_DCBreakerArray[nDev].nNodeJ:pPGBlock->m_DCBreakerArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nADConverterRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nADConverterRange; j++)
				{
					nDev=pPGBlock->m_EdgeADConverterArray[j].nConverter;
					if (pPGBlock->m_ACDCConverterArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_ACDCConverterArray[nDev].nNodeAC) ? pPGBlock->m_ACDCConverterArray[nDev].nNodeDC : pPGBlock->m_ACDCConverterArray[nDev].nNodeAC;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDDConverterRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDDConverterRange; j++)
				{
					nDev=pPGBlock->m_EdgeDDConverterArray[j].nConverter;
					if (pPGBlock->m_DCDCConverterArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_DCDCConverterArray[nDev].nNodeI) ? pPGBlock->m_DCDCConverterArray[nDev].nNodeJ : pPGBlock->m_DCDCConverterArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCShortCircuitLimitRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCShortCircuitLimitRange; j++)
				{
					nDev=pPGBlock->m_EdgeDCShortCircuitLimitArray[j].nDCShortCircuitLimit;
					if (pPGBlock->m_DCShortCircuitLimitArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_DCShortCircuitLimitArray[nDev].nNodeI) ? pPGBlock->m_DCShortCircuitLimitArray[nDev].nNodeJ : pPGBlock->m_DCShortCircuitLimitArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
			}
			if (nMidNodeArray.empty())
				break;
			nNodeNumOfLayer=nNodeNum;
			for (i=0; i<(int)nMidNodeArray.size(); i++)
				nNodeArray[nNodeNum++]=nMidNodeArray[i];
		}

		bUnProcArray.clear();
	}

	//////////////////////////////////////////////////////////////////////////
	//	PGTraverseNet网络遍历不包含变压器中性点
	void PGTraverseNet(tagPGBlock* pPGBlock, const int nStartNode, const int bChkOpen, const float fMinimalVolt, int& nNodeNum, int nNodeArray[])
	{
		register int	i, j;
		int		nVolt, nDev, nNode;
		int		nNodeNumOfLayer;
		std::vector<unsigned char>	bUnProcArray;
		std::vector<int> nMidNodeArray;

		nNodeNum=0;
		if (fMinimalVolt > 0.0001)
		{
			nVolt=pPGBlock->m_ConnectivityNodeArray[nStartNode].nVoltageLevelPtr;
			if (nVolt < 0)
				return;

			if (pPGBlock->m_VoltageLevelArray[nVolt].nominalVoltage <= fMinimalVolt)
				return;
		}

		bUnProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]);
		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
			bUnProcArray[i]=1;

		nNodeArray[nNodeNum++]=nStartNode;
		bUnProcArray[nStartNode]=0;
		nNodeNumOfLayer=0;
		while (1)
		{
			nMidNodeArray.clear();
			for (i=nNodeNumOfLayer; i<nNodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].bOpen != 0 && nNodeArray[i] != nStartNode)
					continue;

				//////////////////////////////////////////////////////////////////////////
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
				{
					nDev=pPGBlock->m_EdgeBreakerArray[j].nBreaker;
					if (pPGBlock->m_BreakerArray[nDev].bOutage)
						continue;
					if (bChkOpen == Y_CheckStatus)
					{
						if (pPGBlock->m_BreakerArray[nDev].nStatus  != 0)
							continue;
					}
					nNode=(nNodeArray[i] == pPGBlock->m_BreakerArray[nDev].nNodeI) ? pPGBlock->m_BreakerArray[nDev].nNodeJ:pPGBlock->m_BreakerArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDisconnectorRange; j++)
				{
					nDev=pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector;
					if (pPGBlock->m_DisconnectorArray[nDev].bOutage)
						continue;
					if (bChkOpen == Y_CheckStatus)
					{
						if (pPGBlock->m_DisconnectorArray[nDev].nStatus  != 0)
							continue;
					}
					nNode=(nNodeArray[i] == pPGBlock->m_DisconnectorArray[nDev].nNodeI) ? pPGBlock->m_DisconnectorArray[nDev].nNodeJ : pPGBlock->m_DisconnectorArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange; j++)
				{
					nDev=pPGBlock->m_EdgeACLineSegmentArray[j].nACLineSegment;
					if (pPGBlock->m_ACLineSegmentArray[nDev].bOpen != 0)
						continue;
					if (pPGBlock->m_ACLineSegmentArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_ACLineSegmentArray[nDev].nNodeI) ? pPGBlock->m_ACLineSegmentArray[nDev].nNodeJ : pPGBlock->m_ACLineSegmentArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange; j++)
				{
					if (pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[j].nTransformerWinding].bOpen != 0)
						continue;
					if (pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[j].nTransformerWinding].bOutage)
						continue;

					nDev=pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[j].nTransformerWinding].nTran;
					nNode=pPGBlock->m_PowerTransformerArray[nDev].nNodeH;
					if (nNode >= 0 && nNode != nNodeArray[i])
					{
						if (pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nDev].nWindH].bOpen == 0 && bUnProcArray[nNode])
						{
							nMidNodeArray.push_back(nNode);
							bUnProcArray[nNode]=0;
						}
					}
					nNode=pPGBlock->m_PowerTransformerArray[nDev].nNodeM;
					if (nNode >= 0 && nNode != nNodeArray[i])
					{
						if (pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nDev].nWindM].bOpen == 0 && bUnProcArray[nNode])
						{
							nMidNodeArray.push_back(nNode);
							bUnProcArray[nNode]=0;
						}
					}
					nNode=pPGBlock->m_PowerTransformerArray[nDev].nNodeL;
					if (nNode >= 0 && nNode != nNodeArray[i])
					{
						if (pPGBlock->m_TransformerWindingArray[pPGBlock->m_PowerTransformerArray[nDev].nWindL].bOpen == 0 && bUnProcArray[nNode])
						{
							nMidNodeArray.push_back(nNode);
							bUnProcArray[nNode]=0;
						}
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nSeriesCompensatorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nSeriesCompensatorRange; j++)
				{
					nDev=pPGBlock->m_EdgeSeriesCompensatorArray[j].nSeriesCompensator;
					if (pPGBlock->m_SeriesCompensatorArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_SeriesCompensatorArray[nDev].nNodeI) ? pPGBlock->m_SeriesCompensatorArray[nDev].nNodeJ : pPGBlock->m_SeriesCompensatorArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}

				//////////////////////////////////////////////////////////////////////////
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCBreakerRange; j++)
				{
					nDev=pPGBlock->m_EdgeDCBreakerArray[j].nDCBreaker;
					if (pPGBlock->m_DCBreakerArray[nDev].bOutage)
						continue;
					if (bChkOpen == Y_CheckStatus)
					{
						if (pPGBlock->m_DCBreakerArray[nDev].nStatus  != 0)
							continue;
					}
					nNode=(nNodeArray[i] == pPGBlock->m_DCBreakerArray[nDev].nNodeI) ? pPGBlock->m_DCBreakerArray[nDev].nNodeJ:pPGBlock->m_DCBreakerArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCLineSegmentRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCLineSegmentRange; j++)
				{
					nDev=pPGBlock->m_EdgeDCLineSegmentArray[j].nDCLineSegment;
					if (pPGBlock->m_DCLineSegmentArray[nDev].bOpen != 0)
						continue;
					if (pPGBlock->m_DCLineSegmentArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_DCLineSegmentArray[nDev].nNodeI) ? pPGBlock->m_DCLineSegmentArray[nDev].nNodeJ : pPGBlock->m_DCLineSegmentArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCShortCircuitLimitRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCShortCircuitLimitRange; j++)
				{
					nDev=pPGBlock->m_EdgeDCShortCircuitLimitArray[j].nDCShortCircuitLimit;
					if (pPGBlock->m_DCShortCircuitLimitArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_DCShortCircuitLimitArray[nDev].nNodeI) ? pPGBlock->m_DCShortCircuitLimitArray[nDev].nNodeJ : pPGBlock->m_DCShortCircuitLimitArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
			}
			if (nMidNodeArray.empty())
				break;
			nNodeNumOfLayer=nNodeNum;
			for (i=0; i<(int)nMidNodeArray.size(); i++)
				nNodeArray[nNodeNum++]=nMidNodeArray[i];
		}

		bUnProcArray.clear();
	}

	void PGTraverseLine(tagPGBlock* pPGBlock, const int nStartNode, const int bChkOpen, int& nNodeNum, int nNodeArray[])
	{
		register int	i, j;
		int		nDev, nNode;
		int		nNodeNumOfLayer;
		std::vector<unsigned char>	bUnProcArray;
		std::vector<int> nMidNodeArray;

		nNodeNum=0;

		bUnProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]);
		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
			bUnProcArray[i]=1;

		nNodeArray[nNodeNum++]=nStartNode;
		bUnProcArray[nStartNode]=0;
		nNodeNumOfLayer=0;
		while (1)
		{
			nMidNodeArray.clear();
			for (i=nNodeNumOfLayer; i<nNodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].bOpen != 0 && nNodeArray[i] != nStartNode)
					continue;

				//////////////////////////////////////////////////////////////////////////
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
				{
					nDev=pPGBlock->m_EdgeBreakerArray[j].nBreaker;
					if (pPGBlock->m_BreakerArray[nDev].bOutage)
						continue;
					if (bChkOpen == Y_CheckStatus)
					{
						if (pPGBlock->m_BreakerArray[nDev].nStatus  != 0)
							continue;
					}
					nNode=(nNodeArray[i] == pPGBlock->m_BreakerArray[nDev].nNodeI) ? pPGBlock->m_BreakerArray[nDev].nNodeJ:pPGBlock->m_BreakerArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDisconnectorRange; j++)
				{
					nDev=pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector;
					if (pPGBlock->m_DisconnectorArray[nDev].bOutage)
						continue;
					if (bChkOpen == Y_CheckStatus)
					{
						if (pPGBlock->m_DisconnectorArray[nDev].nStatus  != 0)
							continue;
					}

					nNode=(nNodeArray[i] == pPGBlock->m_DisconnectorArray[nDev].nNodeI) ? pPGBlock->m_DisconnectorArray[nDev].nNodeJ : pPGBlock->m_DisconnectorArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange; j++)
				{
					nDev=pPGBlock->m_EdgeACLineSegmentArray[j].nACLineSegment;
					if (pPGBlock->m_ACLineSegmentArray[nDev].bOpen != 0)
						continue;
					if (pPGBlock->m_ACLineSegmentArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_ACLineSegmentArray[nDev].nNodeI) ? pPGBlock->m_ACLineSegmentArray[nDev].nNodeJ : pPGBlock->m_ACLineSegmentArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nSeriesCompensatorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nSeriesCompensatorRange; j++)
				{
					nDev=pPGBlock->m_EdgeSeriesCompensatorArray[j].nSeriesCompensator;
					if (pPGBlock->m_SeriesCompensatorArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_SeriesCompensatorArray[nDev].nNodeI) ? pPGBlock->m_SeriesCompensatorArray[nDev].nNodeJ : pPGBlock->m_SeriesCompensatorArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}

				//////////////////////////////////////////////////////////////////////////
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCBreakerRange; j++)
				{
					nDev=pPGBlock->m_EdgeDCBreakerArray[j].nDCBreaker;
					if (pPGBlock->m_DCBreakerArray[nDev].bOutage)
						continue;
					if (bChkOpen == Y_CheckStatus)
					{
						if (pPGBlock->m_DCBreakerArray[nDev].nStatus  != 0)
							continue;
					}
					nNode=(nNodeArray[i] == pPGBlock->m_DCBreakerArray[nDev].nNodeI) ? pPGBlock->m_DCBreakerArray[nDev].nNodeJ:pPGBlock->m_DCBreakerArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCLineSegmentRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCLineSegmentRange; j++)
				{
					nDev=pPGBlock->m_EdgeDCLineSegmentArray[j].nDCLineSegment;
					if (pPGBlock->m_DCLineSegmentArray[nDev].bOpen != 0)
						continue;
					if (pPGBlock->m_DCLineSegmentArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_DCLineSegmentArray[nDev].nNodeI) ? pPGBlock->m_DCLineSegmentArray[nDev].nNodeJ : pPGBlock->m_DCLineSegmentArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDCShortCircuitLimitRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDCShortCircuitLimitRange; j++)
				{
					nDev=pPGBlock->m_EdgeDCShortCircuitLimitArray[j].nDCShortCircuitLimit;
					if (pPGBlock->m_DCShortCircuitLimitArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_DCShortCircuitLimitArray[nDev].nNodeI) ? pPGBlock->m_DCShortCircuitLimitArray[nDev].nNodeJ : pPGBlock->m_DCShortCircuitLimitArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
			}
			if (nMidNodeArray.empty())
				break;
			nNodeNumOfLayer=nNodeNum;
			for (i=0; i<(int)nMidNodeArray.size(); i++)
				nNodeArray[nNodeNum++]=nMidNodeArray[i];
		}

		bUnProcArray.clear();
	}

	//////////////////////////////////////////////////////////////////////////
	//	PGTraverseZeroNet零序网络遍历不包含变压器中性点
	void PGTraverseZeroNet(tagPGBlock* pPGBlock, const int nStartNode, const int bChkOpen, int& nNodeNum, int nNodeArray[])
	{
		register int	i, j;
		int		nDev, nNode, nWind;
		int		nNodeNumOfLayer;
		std::vector<unsigned char>	bUnProcArray;
		std::vector<int> nMidNodeArray;

		nNodeNum=0;
		bUnProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]);
		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
			bUnProcArray[i]=1;

		nNodeArray[nNodeNum++]=nStartNode;
		bUnProcArray[nStartNode]=0;
		nNodeNumOfLayer=0;
		while (1)
		{
			nMidNodeArray.clear();
			for (i=nNodeNumOfLayer; i<nNodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].bOpen != 0 && nNodeArray[i] != nStartNode)
					continue;

				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
				{
					nDev=pPGBlock->m_EdgeBreakerArray[j].nBreaker;
					if (pPGBlock->m_BreakerArray[nDev].bOutage)
						continue;
					if (bChkOpen == Y_CheckStatus)
					{
						if (pPGBlock->m_BreakerArray[nDev].nStatus  != 0)
							continue;
					}

					nNode=(nNodeArray[i] == pPGBlock->m_BreakerArray[nDev].nNodeI) ? pPGBlock->m_BreakerArray[nDev].nNodeJ:pPGBlock->m_BreakerArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDisconnectorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDisconnectorRange; j++)
				{
					nDev=pPGBlock->m_EdgeDisconnectorArray[j].nDisconnector;
					if (pPGBlock->m_DisconnectorArray[nDev].bOutage)
						continue;
					if (bChkOpen == Y_CheckStatus)
					{
						if (pPGBlock->m_DisconnectorArray[nDev].nStatus  != 0)
							continue;
					}

					nNode=(nNodeArray[i] == pPGBlock->m_DisconnectorArray[nDev].nNodeI) ? pPGBlock->m_DisconnectorArray[nDev].nNodeJ : pPGBlock->m_DisconnectorArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange; j++)
				{
					nDev=pPGBlock->m_EdgeACLineSegmentArray[j].nACLineSegment;
					if (pPGBlock->m_ACLineSegmentArray[nDev].bOpen != 0)
						continue;
					if (pPGBlock->m_ACLineSegmentArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_ACLineSegmentArray[nDev].nNodeI) ? pPGBlock->m_ACLineSegmentArray[nDev].nNodeJ : pPGBlock->m_ACLineSegmentArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange; j++)
				{
					nWind=pPGBlock->m_EdgeTransformerWindingArray[j].nTransformerWinding;
					if (pPGBlock->m_TransformerWindingArray[nWind].bOpen != 0)
						continue;
					if (pPGBlock->m_TransformerWindingArray[nWind].bOutage)
						continue;
					if (pPGBlock->m_TransformerWindingArray[nWind].nWindingType == PGEnumTransformerWinding_WindConnectio_3WD ||
						pPGBlock->m_TransformerWindingArray[nWind].nWindingType == PGEnumTransformerWinding_WindConnectio_2WYD ||
						pPGBlock->m_TransformerWindingArray[nWind].nWindingType == PGEnumTransformerWinding_WindConnectio_2WIND)
						continue;
					else if (pPGBlock->m_TransformerWindingArray[nWind].nWindingType == PGEnumTransformerWinding_WindConnectio_2WYY ||
						pPGBlock->m_TransformerWindingArray[nWind].nWindingType == PGEnumTransformerWinding_WindConnectio_3WY ||
						pPGBlock->m_TransformerWindingArray[nWind].nWindingType == PGEnumTransformerWinding_WindConnectio_3WAuto)
					{
						if (pPGBlock->m_TransformerWindingArray[nWind].bNeutralStatus != 0)
							continue;
					}

					nDev=pPGBlock->m_TransformerWindingArray[pPGBlock->m_EdgeTransformerWindingArray[j].nTransformerWinding].nTran;
					if (pPGBlock->m_PowerTransformerArray[nDev].nWindNum == 1 || pPGBlock->m_PowerTransformerArray[nDev].nWindNum == 2)	//	两卷变
					{
						nNode=pPGBlock->m_PowerTransformerArray[nDev].nNodeH;
						if (nNode >= 0 && nNode != nNodeArray[i])
						{
							if (bUnProcArray[nNode])
							{
								nMidNodeArray.push_back(nNode);
								bUnProcArray[nNode]=0;
							}
						}
						nNode=pPGBlock->m_PowerTransformerArray[nDev].nNodeL;
						if (nNode >= 0 && nNode != nNodeArray[i])
						{
							if (bUnProcArray[nNode])
							{
								nMidNodeArray.push_back(nNode);
								bUnProcArray[nNode]=0;
							}
						}
					}
					else
					{
						nWind=pPGBlock->m_PowerTransformerArray[nDev].nWindH;
						nNode=pPGBlock->m_PowerTransformerArray[nDev].nNodeH;
						if (pPGBlock->m_TransformerWindingArray[nWind].bNeutralStatus == 0 && pPGBlock->m_TransformerWindingArray[nWind].nWindingType == PGEnumTransformerWinding_WindConnectio_3WY)
						{
							if (nNode >= 0 && nNode != nNodeArray[i])
							{
								if (pPGBlock->m_TransformerWindingArray[nWind].bOpen == 0 && bUnProcArray[nNode])
								{
									nMidNodeArray.push_back(nNode);
									bUnProcArray[nNode]=0;
								}
							}
						}

						nWind=pPGBlock->m_PowerTransformerArray[nDev].nWindM;
						nNode=pPGBlock->m_PowerTransformerArray[nDev].nNodeM;
						if (pPGBlock->m_TransformerWindingArray[nWind].bNeutralStatus == 0 && pPGBlock->m_TransformerWindingArray[nWind].nWindingType == PGEnumTransformerWinding_WindConnectio_3WY)
						{
							if (nNode >= 0 && nNode != nNodeArray[i])
							{
								if (pPGBlock->m_TransformerWindingArray[nWind].bOpen == 0 && bUnProcArray[nNode])
								{
									nMidNodeArray.push_back(nNode);
									bUnProcArray[nNode]=0;
								}
							}
						}

						nWind=pPGBlock->m_PowerTransformerArray[nDev].nWindL;
						nNode=pPGBlock->m_PowerTransformerArray[nDev].nNodeL;
						if (pPGBlock->m_TransformerWindingArray[nWind].bNeutralStatus == 0 && pPGBlock->m_TransformerWindingArray[nWind].nWindingType == PGEnumTransformerWinding_WindConnectio_3WY)
						{
							if (nNode >= 0 && nNode != nNodeArray[i])
							{
								if (pPGBlock->m_TransformerWindingArray[nWind].bOpen == 0 && bUnProcArray[nNode])
								{
									nMidNodeArray.push_back(nNode);
									bUnProcArray[nNode]=0;
								}
							}
						}
					}
				}
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nSeriesCompensatorRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nSeriesCompensatorRange; j++)
				{
					nDev=pPGBlock->m_EdgeSeriesCompensatorArray[j].nSeriesCompensator;
					if (pPGBlock->m_SeriesCompensatorArray[nDev].bOutage)
						continue;
					nNode=(nNodeArray[i] == pPGBlock->m_SeriesCompensatorArray[nDev].nNodeI) ? pPGBlock->m_SeriesCompensatorArray[nDev].nNodeJ : pPGBlock->m_SeriesCompensatorArray[nDev].nNodeI;
					if (nNode < 0)
						continue;
					if (bUnProcArray[nNode])
					{
						nMidNodeArray.push_back(nNode);
						bUnProcArray[nNode]=0;
					}
				}
			}
			if (nMidNodeArray.empty())
				break;
			nNodeNumOfLayer=nNodeNum;
			for (i=0; i<(int)nMidNodeArray.size(); i++)
				nNodeArray[nNodeNum++]=nMidNodeArray[i];
		}

		bUnProcArray.clear();
	}

	//////////////////////////////////////////////////////////////////////////
	//	最小树
	void PGKruskal(tagPGBlock* pPGBlock, const int nStartNode, const int bChkOpen, int& nNodeNum, int nNodeArray[])
	{
	}
}
