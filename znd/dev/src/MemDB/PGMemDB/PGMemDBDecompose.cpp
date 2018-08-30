#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

namespace PGMemDB 
{
	std::vector<tagPGRadiate>	m_RadiateArray;

	void	FormRadiate(tagPGBlock* pPGBlock, const double fOpenRingVolt, const double fTinyGenMva, const int nBoundNode, tagPGRadiate& bndBuffer)
	{
		register int	i;
		int		nVolt, nNode, nChkNode;
		double	fIslandGen;
		unsigned char	bBound;
		std::vector<unsigned char>	bProcArray;
		int		nNodeNum, *pnNodeArray;
		int		nConnNodeNum, nConnNodeArray[1000];

		pnNodeArray=(int*)malloc(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]*sizeof(int));
		if (pnNodeArray == NULL)
			return;

		bndBuffer.nBoundNode=nBoundNode;
		bndBuffer.fGenP=0;
		bndBuffer.fLoadP=0;
		bndBuffer.fLoadQ=0;
		bndBuffer.nNodeArray.clear();

		PGTraverseVolt(pPGBlock, nBoundNode, Y_CheckStatus, Y_CheckStatus, N_BusBound, N_BreakerBound, nConnNodeNum, nConnNodeArray);

		bProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]);
		for (i=0; i<(int)bProcArray.size(); i++)
		{
			bProcArray[i]=0;
			if (pPGBlock->m_IslandArray[pPGBlock->m_ConnectivityNodeArray[i].nIsland].bDead)
				bProcArray[i]=1;
		}

		for (i=0; i<nConnNodeNum; i++)
		{
			bProcArray[nConnNodeArray[i]] = 1;
			pPGBlock->m_ConnectivityNodeArray[nConnNodeArray[i]].bOpen=1;
		}

		for (nChkNode=0; nChkNode<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; nChkNode++)
		{
			if (bProcArray[nChkNode])
				continue;

			PGTraverseNet(pPGBlock, nChkNode, Y_CheckStatus, 0, nNodeNum, pnNodeArray);	//	搜索结果含nChkNode
			for (nNode=0; nNode<nNodeNum; nNode++)
				bProcArray[pnNodeArray[nNode]]=1;

			fIslandGen=0;
			for (nNode=0; nNode<nNodeNum; nNode++)
			{
				nVolt = pPGBlock->m_ConnectivityNodeArray[pnNodeArray[nNode]].nVoltageLevelPtr;
				if (pPGBlock->m_VoltageLevelArray[nVolt].nominalVoltage > fOpenRingVolt)
				{
					for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
					{
						if (pPGBlock->m_SynchronousMachineArray[i].nNode == pnNodeArray[nNode])
						{
							if (pPGBlock->m_SynchronousMachineArray[i].fPMax > fTinyGenMva && pPGBlock->m_SynchronousMachineArray[i].fPlanP > FLT_MIN)
								fIslandGen += pPGBlock->m_SynchronousMachineArray[i].fPMax;
						}
					}
				}
				if (fIslandGen > FLT_MIN)
					break;
			}

			//	形成孤岛，则节点集合为辐射网
			if (fIslandGen < FLT_MIN)
			{
				for (nNode=0; nNode<nNodeNum; nNode++)
				{
					bBound = 0;
					for (i=0; i<nConnNodeNum; i++)
					{
						if (pnNodeArray[nNode] == nConnNodeArray[i])
						{
							bBound=1;
							break;
						}
					}
					if (bBound)
						continue;

					nVolt = pPGBlock->m_ConnectivityNodeArray[pnNodeArray[nNode]].nVoltageLevelPtr;
					for (i=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; i++)
					{
						bndBuffer.fLoadP += pPGBlock->m_EnergyConsumerArray[i].fPlanP;
						bndBuffer.fLoadQ += pPGBlock->m_EnergyConsumerArray[i].fPlanQ;
					}
					bndBuffer.nNodeArray.push_back(pnNodeArray[nNode]);
				}
			}
		}

		for (i=0; i<nConnNodeNum; i++)
			pPGBlock->m_ConnectivityNodeArray[nConnNodeArray[i]].bOpen=0;

		if (pnNodeArray)
		{
			free(pnNodeArray);
			pnNodeArray=NULL;
		}
	}

	int InRadiate(const int nCheckNode)
	{
		register int	i;
		int	nRadiate;

		for (nRadiate=0; nRadiate<(int)m_RadiateArray.size(); nRadiate++)
		{
			for (i=0; i<(int)m_RadiateArray[nRadiate].nNodeArray.size(); i++)
			{
				if (m_RadiateArray[nRadiate].nNodeArray[i] == nCheckNode)
					return 1;
			}
		}
		return 0;
	}

	void PGRingRadDecompose(tagPGBlock* pPGBlock, const double fOpenRingVolt, const double fTinyGenMva)
	{
		register int	i, j;
		int		nRad, nNode;
		int		nConnNodeNum, nConnNodeArray[1000];
		unsigned char	bFlag;
		tagPGRadiate	rBuffer;
		std::vector<unsigned char>	bProcArray;

		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();

		PGMemDBIsland(pPGBlock);
		m_RadiateArray.clear();

		//////////////////////////////////////////////////////////////////////////
		//	辐射网判断流程
		//	1、变压器中性点不判断
		bProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]);
		for (i=0; i<(int)bProcArray.size(); i++)
			bProcArray[i] = 0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
		{
			if (pPGBlock->m_TransformerWindingArray[i].bTranMidSide == 1)
				bProcArray[pPGBlock->m_TransformerWindingArray[i].nNodeI] = 1;
			if (pPGBlock->m_TransformerWindingArray[i].bTranMidSide == 2)
				bProcArray[pPGBlock->m_TransformerWindingArray[i].nNodeJ] = 1;
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
		{
			if (pPGBlock->m_IslandArray[pPGBlock->m_ConnectivityNodeArray[i].nIsland].bDead)
				bProcArray[i] = 1;
		}

		//	2、形成以节点为起点的辐射网集合
		for (nNode=0; nNode<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; nNode++)
		{
			if (pPGBlock->m_VoltageLevelArray[pPGBlock->m_ConnectivityNodeArray[nNode].nVoltageLevelPtr].nominalVoltage <= fOpenRingVolt)
				continue;

			if (nNode % 1000 == 0)
			{
				dEnd=clock();
				nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
				Log(m_lpszPGMemDBLogFile, "辐射网判断[%d/%d]完成，耗时%d毫秒\n", nNode, pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE], nDur);
			}

			if (bProcArray[nNode])
				continue;
			if (pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange+
				pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange <= 1)
				continue;
			if (InRadiate(nNode))
				continue;

			PGTraverseVolt(pPGBlock, nNode, Y_CheckStatus, Y_CheckStatus, N_BusBound, N_BreakerBound, nConnNodeNum, nConnNodeArray);
			for (i=0; i<nConnNodeNum; i++)
				bProcArray[nConnNodeArray[i]] = 1;

			FormRadiate(pPGBlock, fOpenRingVolt, fTinyGenMva, nNode, rBuffer);
			if (!rBuffer.nNodeArray.empty())
			{
				m_RadiateArray.push_back(rBuffer);
				for (i=0; i<(int)rBuffer.nNodeArray.size(); i++)
					bProcArray[rBuffer.nNodeArray[i]]=1;
			}
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(m_lpszPGMemDBLogFile, "辐射网判断完成，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	辐射网合并流程
		//	3、辐射网合并
		nRad=0;
		while (nRad < (int)m_RadiateArray.size())
		{
			bFlag=0;
			for (i=nRad+1; i<(int)m_RadiateArray.size(); i++)
			{
				for (j=0; j<(int)m_RadiateArray[i].nNodeArray.size(); j++)
				{
					if (m_RadiateArray[nRad].nBoundNode == m_RadiateArray[i].nNodeArray[j])
					{
						bFlag=1;
						break;
					}
				}
				if (bFlag)
					break;
			}

			//	某辐射网的边界节点是另一个辐射网的子节点，则该辐射网删除
			if (bFlag)
				m_RadiateArray.erase(m_RadiateArray.begin()+nRad);
			else
				nRad++;
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(m_lpszPGMemDBLogFile, "Decompose分析耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	形成辐射网设备
		for (nNode=0; nNode<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; nNode++)
			pPGBlock->m_ConnectivityNodeArray[nNode].bInRing=1;

		for (nRad=0; nRad<(int)m_RadiateArray.size(); nRad++)
		{
			m_RadiateArray[nRad].nLineArray.clear();
			m_RadiateArray[nRad].nWindArray.clear();

			PGTraverseVolt(pPGBlock, m_RadiateArray[nRad].nBoundNode, Y_CheckStatus, Y_CheckStatus, N_BusBound, N_BreakerBound, nConnNodeNum, nConnNodeArray);
			for (nNode=0; nNode<(int)m_RadiateArray[nRad].nNodeArray.size(); nNode++)
			{
				bFlag = 0;
				for (i=0; i<nConnNodeNum; i++)
				{
					if (m_RadiateArray[nRad].nNodeArray[nNode] == nConnNodeArray[i])
					{
						bFlag=1;
						break;
					}
				}
				if (bFlag)	//	边界节点
					continue;

				for (i=pPGBlock->m_ConnectivityNodeArray[m_RadiateArray[nRad].nNodeArray[nNode]].nACLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[m_RadiateArray[nRad].nNodeArray[nNode]+1].nACLineSegmentRange; i++)
					m_RadiateArray[nRad].nLineArray.push_back(pPGBlock->m_EdgeACLineSegmentArray[i].nACLineSegment);
				for (i=pPGBlock->m_ConnectivityNodeArray[m_RadiateArray[nRad].nNodeArray[nNode]].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[m_RadiateArray[nRad].nNodeArray[nNode]+1].nTransformerWindingRange; i++)
					m_RadiateArray[nRad].nWindArray.push_back(pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding);
				pPGBlock->m_ConnectivityNodeArray[m_RadiateArray[nRad].nNodeArray[nNode]].bInRing=0;
			}
			for (i=0; i<nConnNodeNum; i++)
				pPGBlock->m_ConnectivityNodeArray[nConnNodeArray[i]].bInRing=2;

			i=0;
			while (i < (int)m_RadiateArray[nRad].nLineArray.size())
			{
				bFlag=0;
				for (j=i+1; j<(int)m_RadiateArray[nRad].nLineArray.size(); j++)
				{
					if (m_RadiateArray[nRad].nLineArray[i] == m_RadiateArray[nRad].nLineArray[j])
					{
						bFlag=1;
						break;
					}
				}
				if (bFlag)
					m_RadiateArray[nRad].nLineArray.erase(m_RadiateArray[nRad].nLineArray.begin()+i);
				else
					i++;
			}

			i=0;
			while (i < (int)m_RadiateArray[nRad].nWindArray.size())
			{
				bFlag=0;
				for (j=i+1; j<(int)m_RadiateArray[nRad].nWindArray.size(); j++)
				{
					if (m_RadiateArray[nRad].nWindArray[i] == m_RadiateArray[nRad].nWindArray[j])
					{
						bFlag=1;
						break;
					}
				}
				if (bFlag)
					m_RadiateArray[nRad].nWindArray.erase(m_RadiateArray[nRad].nWindArray.begin()+i);
				else
					i++;
			}
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(m_lpszPGMemDBLogFile, "合并辐射网完成，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	形成环网信息
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
		{
			pPGBlock->m_ACLineSegmentArray[i].bInRing=0;
			if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ACLineSegmentArray[i].nNodeI].bInRing && pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_ACLineSegmentArray[i].nNodeJ].bInRing)
				pPGBlock->m_ACLineSegmentArray[i].bInRing=1;
		}

		for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
		{
			pPGBlock->m_TransformerWindingArray[i].bInRing=0;
			if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_TransformerWindingArray[i].nNodeI].bInRing && pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_TransformerWindingArray[i].nNodeJ].bInRing)
				pPGBlock->m_TransformerWindingArray[i].bInRing=1;
		}

		//////////////////////////////////////////////////////////////////////////
		//	辐射网填库
		for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
			pPGBlock->m_ConnectivityNodeArray[i].nRadiate=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
			pPGBlock->m_ACLineSegmentArray[i].nRadiate=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
			pPGBlock->m_TransformerWindingArray[i].nRadiate=0;

		int	nRadiate=0;

		nRadiate++;
		for (nNode=0; nNode<(int)m_RadiateArray.size(); nNode++)
		{
			for (i=0; i<(int)m_RadiateArray[nNode].nNodeArray.size(); i++)
			{
				pPGBlock->m_ConnectivityNodeArray[m_RadiateArray[nNode].nNodeArray[i]].nRadiate=nRadiate;
			}
			for (i=0; i<(int)m_RadiateArray[nNode].nLineArray.size(); i++)
				pPGBlock->m_ACLineSegmentArray[m_RadiateArray[nNode].nLineArray[i]].nRadiate=(short)nRadiate;
			for (i=0; i<(int)m_RadiateArray[nNode].nWindArray.size(); i++)
				pPGBlock->m_TransformerWindingArray[m_RadiateArray[nNode].nWindArray[i]].nRadiate=(short)nRadiate;
			nRadiate++;
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(m_lpszPGMemDBLogFile, "数据库操作完成，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//以下用于查错
		//for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
		//{
		//	if (pPGBlock->m_ConnectivityNodeArray[i].bInRing && pPGBlock->m_ConnectivityNodeArray[i].nRadiate != 0)
		//		ASSERT(FALSE);
		//	if (!pPGBlock->m_ConnectivityNodeArray[i].bInRing && pPGBlock->m_ConnectivityNodeArray[i].nRadiate == 0)
		//		ASSERT(FALSE);
		//}
		//for (i=0; i<pPGBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
		//{
		//	if (pPGBlock->m_ACLineSegmentArray[i].bInRing && pPGBlock->m_ACLineSegmentArray[i].nRadiate != 0)
		//		ASSERT(FALSE);
		//	if (!pPGBlock->m_ACLineSegmentArray[i].bInRing && pPGBlock->m_ACLineSegmentArray[i].nRadiate == 0)
		//		ASSERT(FALSE);
		//}
		//for (i=0; i<pPGBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
		//{
		//	if (pPGBlock->m_TransformerWindingArray[i].bInRing && pPGBlock->m_TransformerWindingArray[i].nRadiate != 0)
		//		ASSERT(FALSE);
		//	if (!pPGBlock->m_TransformerWindingArray[i].bInRing && pPGBlock->m_TransformerWindingArray[i].nRadiate == 0)
		//		ASSERT(FALSE);
		//}
	}
}
