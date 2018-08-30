#include "StdAfx.h"
#include "PGTraceAlgorithm.h"

const	int		g_nTraceDest=8;

CPGTraceAlgorithm::CPGTraceAlgorithm(void)
{
}

CPGTraceAlgorithm::~CPGTraceAlgorithm(void)
{
}

//	由物理节点开始搜索电源，搜索结果包括：路径上的节点集合、路径上的设备集合和终端物理节点集合
void CPGTraceAlgorithm::PGTraceSource(tagPGBlock* pPGBlock, const int bCheckOpen, const int nStartNode, std::vector<int>& nBoundNodeArray, std::vector<tagPGRouter>& routerArray, std::vector<tagPGSource>& endingArray)
{
	register int	i, j;
	int		nDeep, nSrcIndex;
	int		nNodeNum, nNodeArray[1000];
	unsigned char	nCheckStatus=(bCheckOpen != 0) ? Y_CheckStatus : N_CheckStatus;

	routerArray.clear();
	endingArray.clear();

	m_bNodeProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]);
	for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
		m_bNodeProcArray[i]=0;
	for (i=0; i<(int)nBoundNodeArray.size(); i++)
	{
		if (nBoundNodeArray[i] < 0 || nBoundNodeArray[i] >= pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE])
			continue;

		PGTraverseVolt(pPGBlock, nBoundNodeArray[i], nCheckStatus, nCheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
		for (j=0; j<nNodeNum; j++)
			m_bNodeProcArray[nNodeArray[j]]=g_nTraceDest;	//	给节点着色电源
	}

	nDeep=0;

	nSrcIndex = IsNodeSource(pPGBlock, nStartNode);
	if (nSrcIndex >= 0)
	{
		tagPGSource	eBuf;
		eBuf.nEndNode = nStartNode;
		eBuf.fEndLength = 0;
		eBuf.nEndingType = PG_SYNCHRONOUSMACHINE;
		eBuf.nDevIndex = nSrcIndex;
		endingArray.push_back(eBuf);
		return;
	}
	TraceJoint(pPGBlock, bCheckOpen, nStartNode, nDeep, routerArray, endingArray);

	i=0;
	while (i < (int)routerArray.size())
	{
		if (!routerArray[i].bRouter)
			routerArray.erase(routerArray.begin()+i);
		else
			i++;
	}
}

void CPGTraceAlgorithm::PGTraceRange(tagPGBlock* pPGBlock, const int bCheckOpen, const int nStartNode, std::vector<int>& nBoundNodeArray, std::vector<tagPGRouter>& routerArray, std::vector<tagPGSource>& endingArray)
{
	register int	i;
	int		nDeep;
	int		nNodeNum, nNodeArray[1000];
	unsigned char	nCheckStatus=(bCheckOpen != 0) ? Y_CheckStatus : N_CheckStatus;

	routerArray.clear();
	endingArray.clear();

	m_bNodeProcArray.resize(pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]);
	for (i=0; i<pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE]; i++)
		m_bNodeProcArray[i]=0;
	for (i=0; i<(int)nBoundNodeArray.size(); i++)
	{
		if (nBoundNodeArray[i] < 0 || nBoundNodeArray[i] >= pPGBlock->m_nRecordNum[PG_CONNECTIVITYNODE])
			continue;

		PGTraverseVolt(pPGBlock, nBoundNodeArray[i], nCheckStatus, nCheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
		for (i=0; i<nNodeNum; i++)
			m_bNodeProcArray[nNodeArray[i]]=g_nTraceDest;	//	给节点着色
	}

	nDeep=0;
	TraceJoint(pPGBlock, bCheckOpen, nStartNode, nDeep, routerArray, endingArray);
}

int	CPGTraceAlgorithm::IsNodeSource(tagPGBlock* pPGBlock, const int nJudgeNode)
{
	register int	i;
	int		nNodeNum, nNodeArray[1000];
	int		nVolt, nNode;

	PGTraverseVolt(pPGBlock, nJudgeNode, N_CheckStatus, N_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
	for (nNode=0; nNode<nNodeNum; nNode++)
	{
		nVolt=pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nVoltageLevelPtr;
		if (nVolt < 0)
			continue;

		for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
		{
			if (pPGBlock->m_SynchronousMachineArray[i].nNode == nNodeArray[nNode])
				return i;
		}
	}

	return -1;
}

void CPGTraceAlgorithm::RouterRecursive(tagPGBlock* pPGBlock, const int bCheckOpen, tagPGSource& routerEnd, std::vector<tagPGRouter>& routerArray)
{
	register int	i, j;
	int		bFrLinked, bToLinked, nRouterDeep, nWorkRouter;
	unsigned char	nCheckStatus;
	int		nFrNodeNum, nFrNodeArray[1000];
	int		nToNodeNum, nToNodeArray[1000];

	nRouterDeep=routerArray[routerArray.size()-1].nDeep;			//	最大深度
	nWorkRouter=(int)routerArray.size()-1;

	nCheckStatus=(bCheckOpen != 0) ? Y_CheckStatus : N_CheckStatus;
	PGTraverseVolt(pPGBlock, routerArray[nWorkRouter].nFrNode, nCheckStatus, nCheckStatus, N_BusBound, N_BreakerBound, nFrNodeNum, nFrNodeArray);
	PGTraverseVolt(pPGBlock, routerArray[nWorkRouter].nToNode, nCheckStatus, nCheckStatus, N_BusBound, N_BreakerBound, nToNodeNum, nToNodeArray);

	for (i=(int)routerArray.size()-1; i>=0; i--)
	{
		if (routerArray[i].bRouter)									//	已经在路径上
			break;

		if (routerArray[i].nDeep == nRouterDeep)					//	标记Router，即满足起始终止点判据的Router
		{
			bFrLinked=bToLinked=0;
			for (j=0; j<nFrNodeNum; j++)
			{
				if (routerArray[i].nFrNode == nFrNodeArray[j])
				{
					bFrLinked=1;
					break;
				}
			}
			for (j=0; j<nToNodeNum; j++)
			{
				if (routerArray[i].nToNode == nToNodeArray[j])
				{
					bToLinked=1;
					break;
				}
			}
			if (bFrLinked && bToLinked)
				routerArray[i].bRouter=1;
		}
		else if (routerArray[i].nDeep == nRouterDeep-1)				//	向前追溯
		{
			bToLinked=0;
			for (j=0; j<nFrNodeNum; j++)
			{
				if (routerArray[i].nToNode == nFrNodeArray[j])		//	路径的末端为当前搜索路径的起点
				{
					bToLinked=1;
					break;
				}
			}

			if (bToLinked)
			{
				routerArray[i].bRouter=1;
				nRouterDeep--;
				nWorkRouter=i;
				PGTraverseVolt(pPGBlock, routerArray[nWorkRouter].nFrNode, nCheckStatus, nCheckStatus, N_BusBound, N_BreakerBound, nFrNodeNum, nFrNodeArray);
				PGTraverseVolt(pPGBlock, routerArray[nWorkRouter].nToNode, nCheckStatus, nCheckStatus, N_BusBound, N_BreakerBound, nToNodeNum, nToNodeArray);
			}
		}
	}

	nRouterDeep=routerArray[routerArray.size()-1].nDeep;	//	当前路径的深度
	routerEnd.fEndLength=routerArray[routerArray.size()-1].fLength;
	for (i=(int)routerArray.size()-1; i>=0; i--)
	{
		if (routerArray[i].nDeep == nRouterDeep-1)
		{
			routerEnd.fEndLength += routerArray[i].fLength;
			nRouterDeep -= 1;
		}
	}
}

void CPGTraceAlgorithm::TraceJoint(tagPGBlock* pPGBlock, const int bCheckOpen, const int nIniNode, int nDeep, std::vector<tagPGRouter>& routerArray, std::vector<tagPGSource>& sourceArray)
{
	register int	i;
	int				nNode, nOppNode, nBran, nIniChain, nSrcIndex;
	unsigned char	nCheckStatus;
	int				nNodeNum, nNodeArray[1000];
	tagPGRouter		dChain;

	if (m_bNodeProcArray[nIniNode] == g_nTraceDest && nDeep > 0)		//	已经着过色了，而且是着色为电源，则记录终点，剪枝，返回
	{
		tagPGSource	eBuf;
		eBuf.nEndNode = nIniNode;
		eBuf.fEndLength = 0;
		eBuf.nEndingType = PG_BUSBARSECTION;
		eBuf.nDevIndex = pPGBlock->m_ConnectivityNodeArray[nIniNode].nBusbarSectionPtr;
		if (!routerArray.empty())
			RouterRecursive(pPGBlock, bCheckOpen, eBuf, routerArray);
		sourceArray.push_back(eBuf);
		return;
	}

	if (m_bNodeProcArray[nIniNode] != 0)				//	已经着过色了，返回，这种情况一般是需要剪枝的。
		return;

	nCheckStatus=(bCheckOpen != 0) ? Y_CheckStatus : N_CheckStatus;
	PGTraverseVolt(pPGBlock, nIniNode, nCheckStatus, nCheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);
	for (i=0; i<nNodeNum; i++)
		m_bNodeProcArray[nNodeArray[i]]=1;				//	给节点着色

	nSrcIndex = IsNodeSource(pPGBlock, nIniNode);
	if (nSrcIndex >= 0 && nDeep > 0)	//	节点连接电源，返回并记录终点
	{
		tagPGSource	eBuf;
		eBuf.nEndNode = nIniNode;
		eBuf.fEndLength = 0;
		eBuf.nEndingType = PG_SYNCHRONOUSMACHINE;
		eBuf.nDevIndex = nSrcIndex;
		if (!routerArray.empty())
			RouterRecursive(pPGBlock, bCheckOpen, eBuf, routerArray);
		sourceArray.push_back(eBuf);
		return;
	}

	nIniChain=(int)routerArray.size();

	//	先添加后标记
	for (nNode=0; nNode<nNodeNum; nNode++)
	{
		for (i=pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nACLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]+1].nACLineSegmentRange; i++)
		{
			nBran=pPGBlock->m_EdgeACLineSegmentArray[i].nACLineSegment;
			if (nBran < 0)
				continue;

			nOppNode=(nNodeArray[nNode] == pPGBlock->m_ACLineSegmentArray[nBran].nNodeI) ? pPGBlock->m_ACLineSegmentArray[nBran].nNodeJ : pPGBlock->m_ACLineSegmentArray[nBran].nNodeI;
			if (nOppNode < 0)
				continue;
			if (m_bNodeProcArray[nOppNode] != 0)
				continue;

			InitializePGRouterSet(dChain);
			dChain.nDeep=nDeep;
			dChain.nFrNode=nIniNode;
			dChain.nToNode=nOppNode;
			dChain.fLength=FormRouterEdge(pPGBlock, bCheckOpen, nIniNode, nOppNode, dChain.edgeArray);
			routerArray.push_back(dChain);
			TraceJoint(pPGBlock, bCheckOpen, nOppNode, nDeep+1, routerArray, sourceArray);
		}
		for (i=pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]+1].nTransformerWindingRange; i++)
		{
			nBran=pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding;
			if (nBran < 0)
				continue;

			nOppNode=(nNodeArray[nNode] == pPGBlock->m_TransformerWindingArray[nBran].nNodeI) ? pPGBlock->m_TransformerWindingArray[nBran].nNodeJ : pPGBlock->m_TransformerWindingArray[nBran].nNodeI;
			if (nOppNode < 0)
				continue;
			if (m_bNodeProcArray[nOppNode] != 0)
				continue;

			InitializePGRouterSet(dChain);
			dChain.nDeep=nDeep;
			dChain.nFrNode=nIniNode;
			dChain.nToNode=nOppNode;
			dChain.fLength=FormRouterEdge(pPGBlock, bCheckOpen, nIniNode, nOppNode, dChain.edgeArray);
			routerArray.push_back(dChain);
			TraceJoint(pPGBlock, bCheckOpen, nOppNode, nDeep+1, routerArray, sourceArray);
		}
		for (i=pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]].nSeriesCompensatorRange; i<pPGBlock->m_ConnectivityNodeArray[nNodeArray[nNode]+1].nSeriesCompensatorRange; i++)
		{
			nBran=pPGBlock->m_EdgeSeriesCompensatorArray[i].nSeriesCompensator;
			if (nBran < 0)
				continue;

			nOppNode=(nNodeArray[nNode] == pPGBlock->m_SeriesCompensatorArray[nBran].nNodeI) ? pPGBlock->m_SeriesCompensatorArray[nBran].nNodeJ : pPGBlock->m_SeriesCompensatorArray[nBran].nNodeI;
			if (nOppNode < 0)
				continue;
			if (m_bNodeProcArray[nOppNode] != 0)
				continue;

			InitializePGRouterSet(dChain);
			dChain.nDeep=nDeep;
			dChain.nFrNode=nIniNode;
			dChain.nToNode=nOppNode;
			dChain.fLength=FormRouterEdge(pPGBlock, bCheckOpen, nIniNode, nOppNode, dChain.edgeArray);
			routerArray.push_back(dChain);
			TraceJoint(pPGBlock, bCheckOpen, nOppNode, nDeep+1, routerArray, sourceArray);
		}
	}
}

float CPGTraceAlgorithm::FormRouterEdge(tagPGBlock* pPGBlock, const unsigned char bCheckOpen, const int nNodeI, const int nNodeJ, std::vector<tagPGEdge>& edgeArray)
{
	register int	i, j;
	int		nEdge, nOppNode;
	unsigned char	bExist;
	tagPGEdge	devBuf;
	int		nFrNode, nFrNodeNum, nFrNodeArray[1000];
	int		nToNode, nToNodeNum, nToNodeArray[1000];
	unsigned char	nCheckStatus=(bCheckOpen != 0) ? Y_CheckStatus : N_CheckStatus;
	float	fRouterLength;

	fRouterLength=0;

	edgeArray.clear();
	PGTraverseVolt(pPGBlock, nNodeI, nCheckStatus, nCheckStatus, N_BusBound, N_BreakerBound, nFrNodeNum, nFrNodeArray);
	PGTraverseVolt(pPGBlock, nNodeJ, nCheckStatus, nCheckStatus, N_BusBound, N_BreakerBound, nToNodeNum, nToNodeArray);

	for (nFrNode=0; nFrNode<nFrNodeNum; nFrNode++)
	{
		for (i=pPGBlock->m_ConnectivityNodeArray[nFrNodeArray[nFrNode]].nACLineSegmentRange; i<pPGBlock->m_ConnectivityNodeArray[nFrNodeArray[nFrNode]+1].nACLineSegmentRange; i++)
		{
			nEdge=pPGBlock->m_EdgeACLineSegmentArray[i].nACLineSegment;
			nOppNode=(pPGBlock->m_ACLineSegmentArray[nEdge].nNodeI == nFrNodeArray[nFrNode]) ? pPGBlock->m_ACLineSegmentArray[nEdge].nNodeJ : pPGBlock->m_ACLineSegmentArray[nEdge].nNodeI;

			bExist=0;
			for (nToNode=0; nToNode<nToNodeNum; nToNode++)
			{
				if (nToNodeArray[nToNode] == nOppNode)
				{
					bExist=1;
					break;
				}
			}
			if (bExist)
			{
				bExist=0;
				for (j=0; j<(int)edgeArray.size(); j++)
				{
					if (edgeArray[j].nDevType == PG_ACLINESEGMENT && edgeArray[j].nDevIndex == nEdge)
					{
						bExist=1;
						break;
					}
				}
				if (!bExist)
				{
					memset(&devBuf, 0, sizeof(tagPGEdge));
					devBuf.nDevType = PG_ACLINESEGMENT;
					devBuf.nDevIndex = nEdge;
					devBuf.fLength = pPGBlock->m_ACLineSegmentArray[nEdge].fLength;
					devBuf.fRerr = pPGBlock->m_ACLineSegmentArray[nEdge].ri_Rerr;
					devBuf.fTrep = pPGBlock->m_ACLineSegmentArray[nEdge].ri_Trep;
					devBuf.fRchk = pPGBlock->m_ACLineSegmentArray[nEdge].ri_Rchk;
					devBuf.fTchk = pPGBlock->m_ACLineSegmentArray[nEdge].ri_Tchk;
					devBuf.fRSwitch = pPGBlock->m_ACLineSegmentArray[nEdge].ri_RSwitch;
					devBuf.fTSwitch = pPGBlock->m_ACLineSegmentArray[nEdge].ri_TSwitch;

					fRouterLength=(fRouterLength < FLT_MIN) ? pPGBlock->m_ACLineSegmentArray[nEdge].fLength : min(fRouterLength, pPGBlock->m_ACLineSegmentArray[nEdge].fLength);
					edgeArray.push_back(devBuf);
				}
			}
		}
		for (i=pPGBlock->m_ConnectivityNodeArray[nFrNodeArray[nFrNode]].nTransformerWindingRange; i<pPGBlock->m_ConnectivityNodeArray[nFrNodeArray[nFrNode]+1].nTransformerWindingRange; i++)
		{
			nEdge=pPGBlock->m_EdgeTransformerWindingArray[i].nTransformerWinding;
			nOppNode=(pPGBlock->m_TransformerWindingArray[nEdge].nNodeI == nFrNodeArray[nFrNode]) ? pPGBlock->m_TransformerWindingArray[nEdge].nNodeJ : pPGBlock->m_TransformerWindingArray[nEdge].nNodeI;

			bExist=0;
			for (nToNode=0; nToNode<nToNodeNum; nToNode++)
			{
				if (nToNodeArray[nToNode] == nOppNode)
				{
					bExist=1;
					break;
				}
			}
			if (bExist)
			{
				bExist=0;
				for (j=0; j<(int)edgeArray.size(); j++)
				{
					if (edgeArray[j].nDevType == PG_TRANSFORMERWINDING && edgeArray[j].nDevIndex == nEdge)
					{
						bExist=1;
						break;
					}
				}
				if (!bExist)
				{
					memset(&devBuf, 0, sizeof(tagPGEdge));
					devBuf.nDevType=PG_TRANSFORMERWINDING;
					devBuf.nDevIndex=nEdge;
					devBuf.fRerr = pPGBlock->m_TransformerWindingArray[nEdge].ri_Rerr;
					devBuf.fTrep = pPGBlock->m_TransformerWindingArray[nEdge].ri_Trep;
					devBuf.fRchk = pPGBlock->m_TransformerWindingArray[nEdge].ri_Rchk;
					devBuf.fTchk = pPGBlock->m_TransformerWindingArray[nEdge].ri_Tchk;
					devBuf.fRSwitch = pPGBlock->m_TransformerWindingArray[nEdge].ri_RSwitch;
					devBuf.fTSwitch = pPGBlock->m_TransformerWindingArray[nEdge].ri_TSwitch;

					edgeArray.push_back(devBuf);
				}
			}
		}
		for (i=pPGBlock->m_ConnectivityNodeArray[nFrNodeArray[nFrNode]].nSeriesCompensatorRange; i<pPGBlock->m_ConnectivityNodeArray[nFrNodeArray[nFrNode]+1].nSeriesCompensatorRange; i++)
		{
			nEdge=pPGBlock->m_EdgeSeriesCompensatorArray[i].nSeriesCompensator;
			nOppNode=(pPGBlock->m_SeriesCompensatorArray[nEdge].nNodeI == nFrNodeArray[nFrNode]) ? pPGBlock->m_SeriesCompensatorArray[nEdge].nNodeJ : pPGBlock->m_SeriesCompensatorArray[nEdge].nNodeI;

			bExist=0;
			for (nToNode=0; nToNode<nToNodeNum; nToNode++)
			{
				if (nToNodeArray[nToNode] == nOppNode)
				{
					bExist=1;
					break;
				}
			}
			if (bExist)
			{
				bExist=0;
				for (j=0; j<(int)edgeArray.size(); j++)
				{
					if (edgeArray[j].nDevType == PG_SERIESCOMPENSATOR && edgeArray[j].nDevIndex == nEdge)
					{
						bExist=1;
						break;
					}
				}
				if (!bExist)
				{
					memset(&devBuf, 0, sizeof(tagPGEdge));
					devBuf.nDevType=PG_SERIESCOMPENSATOR;
					devBuf.nDevIndex=nEdge;
					devBuf.fRerr = pPGBlock->m_SeriesCompensatorArray[nEdge].ri_Rerr;
					devBuf.fTrep = pPGBlock->m_SeriesCompensatorArray[nEdge].ri_Trep;
					devBuf.fRchk = pPGBlock->m_SeriesCompensatorArray[nEdge].ri_Rchk;
					devBuf.fTchk = pPGBlock->m_SeriesCompensatorArray[nEdge].ri_Tchk;

					edgeArray.push_back(devBuf);
				}
			}
		}
	}

	return fRouterLength;
}

void CPGTraceAlgorithm::FormLoadSourceTracer(IN tagPGBlock* pPGBlock, IN const unsigned char bCheckOpen, OUT std::vector<tagPGLoadTraceSource>& sLoadTraceSourceArray)
{
	register int	i;
	int		nSub, nVolt, nDev;
	tagPGLoadTraceSource	stBuffer;

	std::vector<int>		nBoundNodeArray;
	nBoundNodeArray.clear();

	sLoadTraceSourceArray.clear();
	for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
	{
		for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
		{
			for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; nDev++)
			{
				if (pPGBlock->m_EnergyConsumerArray[nDev].nNode < 0)
					continue;

				stBuffer.strLoad = pPGBlock->m_EnergyConsumerArray[nDev].szSub;	stBuffer.strLoad += ".";
				stBuffer.strLoad += pPGBlock->m_EnergyConsumerArray[nDev].szVolt;	stBuffer.strLoad += ".";
				stBuffer.strLoad += pPGBlock->m_EnergyConsumerArray[nDev].szName;
				stBuffer.fLoadMva = sqrt(pPGBlock->m_EnergyConsumerArray[nDev].fPlanP*pPGBlock->m_EnergyConsumerArray[nDev].fPlanP+pPGBlock->m_EnergyConsumerArray[nDev].fPlanQ*pPGBlock->m_EnergyConsumerArray[nDev].fPlanQ);
				stBuffer.fRadius = 0;
				stBuffer.sSArray.clear();
				stBuffer.sRArray.clear();

				PGTraceSource(pPGBlock, bCheckOpen, pPGBlock->m_EnergyConsumerArray[nDev].nNode, nBoundNodeArray, stBuffer.sRArray, stBuffer.sSArray);
				for (i=0; i<(int)stBuffer.sSArray.size(); i++)
				{
					if (stBuffer.fRadius == 0 || stBuffer.fRadius < stBuffer.sSArray[i].fEndLength)
						stBuffer.fRadius = stBuffer.sSArray[i].fEndLength;
				}

				sLoadTraceSourceArray.push_back(stBuffer);
			}
		}
	}
}


int	CPGTraceAlgorithm::FindSourceRouter(const int nSourceNode, std::vector<tagPGRouter>& sRArray)
{
	register int	i;

	for (i=(int)sRArray.size()-1; i>=0; i--)
	{
		if (sRArray[i].nToNode == nSourceNode)
			return i;
	}

	return -1;
}

void CPGTraceAlgorithm::FormSourceLoadRouter(IN tagPGBlock* pPGBlock, IN std::vector<tagPGLoadTraceSource>& sLoadTraceSourceArray, OUT std::vector<tagPGLoadSourceRouter>& sLoadSourceRouterArray)
{
	int		nLoad, nSource, nRouter, nESRouter, nDeep;

	sLoadSourceRouterArray.resize(sLoadTraceSourceArray.size());
	for (nLoad=0; nLoad<(int)sLoadSourceRouterArray.size(); nLoad++)
	{
		sLoadSourceRouterArray[nLoad].strLoad = sLoadTraceSourceArray[nLoad].strLoad;
		sLoadSourceRouterArray[nLoad].fLoadMva = sLoadTraceSourceArray[nLoad].fLoadMva;
		sLoadSourceRouterArray[nLoad].fRadius = sLoadTraceSourceArray[nLoad].fRadius;
		sLoadSourceRouterArray[nLoad].sSArray.clear();
	}

	for (nLoad=0; nLoad<(int)sLoadTraceSourceArray.size(); nLoad++)
	{
		sLoadSourceRouterArray[nLoad].sSArray.resize(sLoadTraceSourceArray[nLoad].sSArray.size());

		for (nSource=0; nSource<(int)sLoadSourceRouterArray[nLoad].sSArray.size(); nSource++)
		{
			memcpy(&sLoadSourceRouterArray[nLoad].sSArray[nSource].infSource, &sLoadTraceSourceArray[nLoad].sSArray[nSource], sizeof(tagPGSource));
			sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource.clear();
			sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray.clear();
			sLoadSourceRouterArray[nLoad].sSArray[nSource].fRadius = 0;
			sLoadSourceRouterArray[nLoad].sSArray[nSource].fR = 0;
			sLoadSourceRouterArray[nLoad].sSArray[nSource].fT = 0;
			sLoadSourceRouterArray[nLoad].sSArray[nSource].fU = 0;

			if (sLoadSourceRouterArray[nLoad].sSArray[nSource].infSource.nEndingType == PG_SYNCHRONOUSMACHINE)
			{
				sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource = pPGBlock->m_SynchronousMachineArray[sLoadSourceRouterArray[nLoad].sSArray[nSource].infSource.nDevIndex].szSub;
				sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource.append(" ");
				sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource.append(pPGBlock->m_SynchronousMachineArray[sLoadSourceRouterArray[nLoad].sSArray[nSource].infSource.nDevIndex].szVolt);
				sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource.append(" ");
				sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource.append(pPGBlock->m_SynchronousMachineArray[sLoadSourceRouterArray[nLoad].sSArray[nSource].infSource.nDevIndex].szName);
			}
			else
			{
				sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource = pPGBlock->m_BusbarSectionArray[sLoadSourceRouterArray[nLoad].sSArray[nSource].infSource.nDevIndex].szSub;
				sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource.append(" ");
				sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource.append(pPGBlock->m_BusbarSectionArray[sLoadSourceRouterArray[nLoad].sSArray[nSource].infSource.nDevIndex].szVolt);
				sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource.append(" ");
				sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource.append(pPGBlock->m_BusbarSectionArray[sLoadSourceRouterArray[nLoad].sSArray[nSource].infSource.nDevIndex].szName);
			}

			nESRouter = FindSourceRouter(sLoadSourceRouterArray[nLoad].sSArray[nSource].infSource.nEndNode, sLoadTraceSourceArray[nLoad].sRArray);
			if (nESRouter < 0)
			{
				//Log(g_lpszLogFile, "    Source[%d/%d] = %s ESRouter=%d\n", nSource, sLoadSourceRouterArray[nLoad].sSArray.size(), sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource.c_str(), nESRouter);
				continue;
			}

			nDeep = sLoadTraceSourceArray[nLoad].sRArray[nESRouter].nDeep;
			for (nRouter=nESRouter; nRouter>=0; nRouter--)
			{
				if (sLoadTraceSourceArray[nLoad].sRArray[nRouter].nDeep == nDeep)
				{
					sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray.push_back(sLoadTraceSourceArray[nLoad].sRArray[nRouter]);
					nDeep--;
				}
			}

			sLoadSourceRouterArray[nLoad].sSArray[nSource].fRadius=0;
			for (nRouter=0; nRouter<(int)sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray.size(); nRouter++)
				sLoadSourceRouterArray[nLoad].sSArray[nSource].fRadius += sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].fLength;
		}
	}
}

void CPGTraceAlgorithm::SourceLoadRouterReliable(IN OUT std::vector<tagPGLoadSourceRouter>& sLoadSourceRouterArray)
{
	int		nLoad, nSource, nRouter, nEdge, nDev;
	double	fR, fT;
	double	fFR1, fFT1, fFR2, fFT2, fFR3, fFT3;
	double	fAR1, fAT1, fAR2, fAT2, fAR3, fAT3;

	for (nLoad=0; nLoad<(int)sLoadSourceRouterArray.size(); nLoad++)
	{
		//Log(g_lpszLogFile, "负荷=%s \n", sLoadSourceRouterArray[nLoad].strLoad.c_str());
		for (nSource=0; nSource<(int)sLoadSourceRouterArray[nLoad].sSArray.size(); nSource++)
		{
			sLoadSourceRouterArray[nLoad].sSArray[nSource].fR=0;	//	电源路径故障率
			sLoadSourceRouterArray[nLoad].sSArray[nSource].fT=0;	//	电源路径每次停电平均持续时间
			sLoadSourceRouterArray[nLoad].sSArray[nSource].fU=0;	//	电源路径修复时间
			for (nRouter=0; nRouter<(int)sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray.size(); nRouter++)
			{
				sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].fR=0;	//	等效停运率
				sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].fT=0;	//	等效停运时间

				fFR1 = fFR2 = fFR3 = fFT1 = fFT2 = fFT3 = 0;
				fAR1 = fAR2 = fAR3 = fAT1 = fAT2 = fAT3 = 0;

				for (nEdge=0; nEdge<(int)sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray.size(); nEdge++)
				{
					nDev=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].nDevIndex;

					if (nEdge == 0)
					{
						fFR1=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].fRerr;
						fFT1=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].fTrep;

						fAR1=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].fRchk;
						fAT1=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].fTchk;
					}
					else if (nEdge == 1)
					{
						fFR2=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].fRerr;
						fFT2=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].fTrep;

						fAR2=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].fRchk;
						fAT2=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].fTchk;
					}
					else if (nEdge == 2)
					{
						fFR3=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].fRerr;
						fFT3=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].fTrep;

						fAR3=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].fRchk;
						fAT3=sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray[nEdge].fTchk;
					}
				}

				fR = fT = 0;
				if (sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray.size() == 1)
				{
					fR=fFR1+fAR1;			//一阶割集中的元素考虑检修
					if (fR > FLT_MIN)
						fT=(fFR1*fFT1+fAR1*fAT1)/fR;
				}
				else if (sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray.size() == 2)
				{
					fR=fFR1*fFR2*(fFT1+fFT2)/8760+fFR2*fAR1*fAT1/8760+fFR1*fAR2*fAT2/8760;
					if (8760*fR > FLT_MIN)
					{
						fT=fFR1*fFR2*fFT1*fFT2;
						if (fAT1+fFT2 > FLT_MIN)	fT += fFR2*fAR1*fAT1*(fAT1*fFT2)/(fAT1+fFT2);
						if (fFT1+fAT2 > FLT_MIN)	fT += fFR1*fAR2*fAT2*(fFT1*fAT2)/(fFT1+fAT2);
						fT /= (8760*fR);
					}
				}
				else if (sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray.size() >= 3)
				{
					fR=fFR1*fFR2*fFR3*(fFT1*fFT2+fFT1*fFT3+fFT2*fFT3)/(8760*8760)+
						fFR2*fFR3*(fFT2+fFT3)*fAR1*fAT1/(8760*8760)+
						fFR1*fFR3*(fFT1+fFT3)*fAR2*fAT2/(8760*8760)+
						fFR1*fFR2*(fFT1+fFT2)*fAR3*fAT3/(8760*8760);
					if (8760*8760*fR > FLT_MIN)
					{
						fT = 0;
						if ((fFT1*fFT2+fFT1*fFT3+fFT2*fFT3) > FLT_MIN)	fT += fFR1*fFR2*fFR3*(fFT1*fFT2+fFT1*fFT3+fFT2*fFT3)*(fFT1*fFT2*fFT3)/(fFT1*fFT2+fFT1*fFT3+fFT2*fFT3);
						if ((fAT1*fFT2+fAT1*fFT3+fFT2*fFT3) > FLT_MIN)	fT += fFR2*fFR3*(fFT2+fFT3)*fAR1*fAT1*(fAT1*fFT2*fFT3)/(fAT1*fFT2+fAT1*fFT3+fFT2*fFT3);
						if ((fFT1*fAT2+fFT1*fFT3+fAT2*fFT3) > FLT_MIN)	fT += fFR1*fFR3*(fFT1+fFT3)*fAR2*fAT2*(fFT1*fAT2*fFT3)/(fFT1*fAT2+fFT1*fFT3+fAT2*fFT3);
						if ((fFT1*fFT2+fFT1*fAT3+fFT2*fAT3) > FLT_MIN)	fT += fFR1*fFR2*(fFT1+fFT2)*fAR3*fAT3*(fFT1*fFT2*fAT3)/(fFT1*fFT2+fFT1*fAT3+fFT2*fAT3);
						fT /= (8760*8760*fR);
					}
				}
				if (fR > FLT_MIN && fT > FLT_MIN)
				{
					sLoadSourceRouterArray[nLoad].sSArray[nSource].fR += fR;
					sLoadSourceRouterArray[nLoad].sSArray[nSource].fU += fR*fT;
				}

				//Log(g_lpszLogFile, "    Router[%d]EdgeNum=%d FR1=%f FT1=%f FR2=%f FT2=%f FR3=%f FT3=%f AR1=%f AT1=%f AR2=%f AT2=%f AR3=%f AT3=%f R=%lf T=%lf\n", 
				//	nRouter, sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].edgeArray.size(), fFR1, fFT1, fFR2, fFT2, fFR3, fFT3, fAR1, fAT1, fAR2, fAT2, fAR3, fAT3, fR, fT);

				sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].fR = fR;
				sLoadSourceRouterArray[nLoad].sSArray[nSource].sRArray[nRouter].fT = fT;
			}
			if (sLoadSourceRouterArray[nLoad].sSArray[nSource].fR > FLT_MIN)
				sLoadSourceRouterArray[nLoad].sSArray[nSource].fT = sLoadSourceRouterArray[nLoad].sSArray[nSource].fU / sLoadSourceRouterArray[nLoad].sSArray[nSource].fR;

			//Log(g_lpszLogFile, "        电源=%s R=%f T=%f U=%f\n", sLoadSourceRouterArray[nLoad].sSArray[nSource].strSource.c_str(), sLoadSourceRouterArray[nLoad].sSArray[nSource].fR, sLoadSourceRouterArray[nLoad].sSArray[nSource].fT, sLoadSourceRouterArray[nLoad].sSArray[nSource].fU);
		}
	}
}