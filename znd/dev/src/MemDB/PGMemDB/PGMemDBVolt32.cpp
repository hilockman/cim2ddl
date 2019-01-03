#include "stdafx.h"
#include "PGMemDB.h"

namespace	PGMemDB
{
	int	IsBreaksLoop(tagPGBlock* pPGBlock, const int nBreakI, const int nBreakJ)
	{
		register int	i;
		int		nINodeNum, nINodeJointArray[1000];
		int		nJNodeNum, nJNodeJointArray[1000];
		int		nConI, nConJ;

		PGTraverseVolt(pPGBlock, pPGBlock->m_BreakerArray[nBreakI].nNodeI, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nINodeNum, nINodeJointArray);	//	Switch
		PGTraverseVolt(pPGBlock, pPGBlock->m_BreakerArray[nBreakJ].nNodeI, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nJNodeNum, nJNodeJointArray);	//	Switch
		nConI=0;
		for (i=0; i<nINodeNum; i++)
		{
			if (nINodeJointArray[i] == pPGBlock->m_BreakerArray[nBreakI].nNodeJ)
			{
				nConI=1;
				break;
			}
		}
		if (nConI)
			return 1;

		nConJ=0;
		for (i=0; i<nJNodeNum; i++)
		{
			if (nJNodeJointArray[i] == pPGBlock->m_BreakerArray[nBreakJ].nNodeJ)
			{
				nConJ=1;
				break;
			}
		}
		if (nConJ)
			return 1;

		nConI=nConJ=0;
		for (i=0; i<nINodeNum; i++)
		{
			if (nINodeJointArray[i] == pPGBlock->m_BreakerArray[nBreakJ].nNodeI)
			{
				nConI += 1;
				break;
			}
			if (nINodeJointArray[i] == pPGBlock->m_BreakerArray[nBreakJ].nNodeJ)
			{
				nConI += 2;
				break;
			}
		}
		if (!nConI)
			return 0;

		for (i=0; i<nJNodeNum; i++)
		{
			if (nJNodeJointArray[i] == pPGBlock->m_BreakerArray[nBreakI].nNodeI)
			{
				nConJ += 1;
				break;
			}
			if (nJNodeJointArray[i] == pPGBlock->m_BreakerArray[nBreakI].nNodeJ)
			{
				nConJ += 2;
				break;
			}
		}
		if (!nConJ)
			return 0;

		if (nConI >= 1 && nConJ >= 1)
			return 1;

		return 0;
	}

	//	�ж�3/2����ԭ��
	//		���󲿷��豸���ǲ�ͨ��ĸ�߲���2�����������Ͽ��ؿ���
	//		�����豸����ͨ��2�����ؿ��ƣ�ͬʱ����ÿһ��ֻ�ܿ���һ���豸
	PGMEMDB_EXPORTS	int	PGIsVolt32(tagPGBlock* pPGBlock, const int nVolt)
	{
		register int	i, j, k;
		int		nNode, nDev;
		int		nOutLineNum, nConLineNum, nDisconnectorNum;
		int		nNodeNum, nNodeArray[1000];
		std::vector<int>	nConBreakerArray;
		int		bExist;

		std::vector<int>	nRingBreakArray;

		if (pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange == pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange)
			return 0;

		nOutLineNum=0;
		for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
		{
			if (pPGBlock->m_ConnectivityNodeArray[nNode].nBusbarSectionPtr >= 0)
				continue;
			for (nDev=pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange; nDev<pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange; nDev++)
			{
				nOutLineNum++;
				PGTraverseVolt(pPGBlock, nNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);	//	Breaker

				nConLineNum=0;
				for (i=0; i<nNodeNum; i++)
				{
					nConLineNum += pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange +
						pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange;
				}
				for (i=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; i++)
				{
					if (pPGBlock->m_EnergyConsumerArray[i].nNode == nNode)
						nConLineNum++;
				}
				if (nConLineNum > 1)
					return 0;

				nDisconnectorNum=0;
				for (i=0; i<nNodeNum; i++)
					nDisconnectorNum += pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDisconnectorRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDisconnectorRange;
				nDisconnectorNum /= 2;
				if (nDisconnectorNum > 3)
					return 0;

				nConBreakerArray.clear();
				for (i=0; i<nNodeNum; i++)
				{
					if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBusbarSectionPtr >= 0)
						continue;
					for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
					{
						bExist=0;
						for (k=0; k<(int)nConBreakerArray.size(); k++)
						{
							if (nConBreakerArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
							{
								bExist=1;
								break;
							}
						}
						if (!bExist)
							nConBreakerArray.push_back(pPGBlock->m_EdgeBreakerArray[j].nBreaker);
					}
				}
				if (nConBreakerArray.size() <= 1)
					return 0;
			}
		}
		for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; nDev++)
		{
			nNode=pPGBlock->m_EnergyConsumerArray[nDev].nNode;
			if (nNode < 0)
				continue;
			if (pPGBlock->m_ConnectivityNodeArray[nNode].nBusbarSectionPtr >= 0)
				continue;

			nOutLineNum++;
			PGTraverseVolt(pPGBlock, nNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);	//	Breaker

			nConLineNum=0;
			for (i=0; i<nNodeNum; i++)
			{
				nConLineNum += pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nACLineSegmentRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nACLineSegmentRange +
					pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nTransformerWindingRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nTransformerWindingRange;
			}
			for (i=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; i++)
			{
				if (pPGBlock->m_EnergyConsumerArray[i].nNode == nNode)
					nConLineNum++;
			}
			if (nConLineNum > 1)
				return 0;

			nDisconnectorNum=0;
			for (i=0; i<nNodeNum; i++)
				nDisconnectorNum += pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nDisconnectorRange-pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nDisconnectorRange;
			nDisconnectorNum /= 2;
			if (nDisconnectorNum > 3)
				return 0;

			nConBreakerArray.clear();
			for (i=0; i<nNodeNum; i++)
			{
				if (pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBusbarSectionPtr >= 0)
					continue;
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
				{
					bExist=0;
					for (k=0; k<(int)nConBreakerArray.size(); k++)
					{
						if (nConBreakerArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
						{
							bExist=1;
							break;
						}
					}
					if (!bExist)
						nConBreakerArray.push_back(pPGBlock->m_EdgeBreakerArray[j].nBreaker);
				}
			}
			if (nConBreakerArray.size() <= 1)
				return 0;
		}

		if (nOutLineNum > 0)
			return 1;

		return 0;
	}


	//	�ж�3/2����ԭ��
	//		���󲿷��豸���ǲ�ͨ��ĸ�߲���2�����������Ͽ��ؿ���
	//		�����豸����ͨ��2�����ؿ��ƣ�ͬʱ����ÿһ��ֻ�ܿ���һ���豸
	int	PGIsVolt32_Old(tagPGBlock* pPGBlock, const int nVolt)
	{
		register int	i, j, k;
		int		nNode, nDev;
		int		nNodeNum, nNodeArray[1000];
		std::vector<int>	nConBreakerArray;
		int		nOneNum, nTwoNum;
		int		bExist;

		std::vector<int>	nRingBreakArray;

		if (pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange == pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange)
			return 0;

		nRingBreakArray.clear();

		//	�Ժϻ���·��
		for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nBreakerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nBreakerRange; nDev++)
		{
			PGTraverseVolt(pPGBlock, pPGBlock->m_BreakerArray[nDev].nNodeI, N_CheckStatus, N_CheckStatus, N_BusBound, N_BreakerBound, nNodeNum, nNodeArray);	//	Breaker
			bExist=0;
			for (i=0; i<nNodeNum; i++)
			{
				if (nNodeArray[i] == pPGBlock->m_BreakerArray[nDev].nNodeJ)
				{
					nRingBreakArray.push_back(nDev);
					break;
				}
			}
		}
		if (nRingBreakArray.empty())
			return 0;

		//	for (i=0; i<nRingBreakNum; i++)
		//		TRACE("%s.%s.%s\n", pPGBlock->m_BreakerArray[nRingBreakArray[i]].szSub, pPGBlock->m_BreakerArray[nRingBreakArray[i]].szVolt, pPGBlock->m_BreakerArray[nRingBreakArray[i]].szName);

		//	ͨ��������ͨ�ж�, ������ѹ�д󲿷ֿ��ز���ͨ, ��һ������3/2����, ��ҪĿ����Ϊ�˷�ֹ��ѹ���жϴ���.
		//	����nOneNum��ʾ��ͨ���أ�nTwoNum��ʾ����ͨ���أ�����ͨ�������࣬���ʾһ������3/2����
		nOneNum=nTwoNum=0;
		for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nBreakerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nBreakerRange; nDev++)
		{
			nConBreakerArray.clear();
			PGTraverseVolt(pPGBlock, pPGBlock->m_BreakerArray[nDev].nNodeI, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);	//	Switch
			for (i=0; i<nNodeNum; i++)
			{
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
				{
					bExist=0;
					for (k=0; k<(int)nConBreakerArray.size(); k++)
					{
						if (nConBreakerArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
						{
							bExist=1;
							break;
						}
					}
					if (!bExist)
						nConBreakerArray.push_back(pPGBlock->m_EdgeBreakerArray[j].nBreaker);
				}
			}
			if (nConBreakerArray.size() > 1)
				nOneNum++;
			else
				nTwoNum++;

			nConBreakerArray.clear();
			PGTraverseVolt(pPGBlock, pPGBlock->m_BreakerArray[nDev].nNodeJ, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);	//	Switch
			for (i=0; i<nNodeNum; i++)
			{
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
				{
					bExist=0;
					for (k=0; k<(int)nConBreakerArray.size(); k++)
					{
						if (nConBreakerArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
						{
							bExist=1;
							break;
						}
					}
					if (!bExist)
						nConBreakerArray.push_back(pPGBlock->m_EdgeBreakerArray[j].nBreaker);
				}
			}
			if (nConBreakerArray.size() > 1)
				nOneNum++;
			else
				nTwoNum++;
		}
		if (nOneNum <= nTwoNum)
		{
			//TRACE("���ز���ͨ %s-%s %d %d\n", pPGBlock->m_VoltageLevelArray[nVolt].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szName, nOneNum, nTwoNum);
			return 0;
		}

		//	ͨ���豸���ƿ������жϡ�.
		//	nOneNum��ʾ���ƿ����� <2���豸��
		//	nTwoNum��ʾ���ƿ�����>=2���豸��
		//	��nTwoNum > nOneNum����3/2����
		//	���ڽ��ν��ߣ��ж���ĸ���ں��⡣
		nOneNum=nTwoNum=0;
		for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; nDev++)
		{
			if (pPGBlock->m_EnergyConsumerArray[nDev].nNode < 0)
				continue;
			if (pPGBlock->m_ConnectivityNodeArray[pPGBlock->m_EnergyConsumerArray[nDev].nNode].nBusbarSectionPtr >= 0)
				continue;
			nConBreakerArray.clear();
			PGTraverseVolt(pPGBlock, pPGBlock->m_EnergyConsumerArray[nDev].nNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);	//	Switch
			for (i=0; i<nNodeNum; i++)
			{
				for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
				{
					bExist=0;
					for (k=0; k<(int)nRingBreakArray.size(); k++)
					{
						if (nRingBreakArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
						{
							bExist=1;
							break;
						}
					}
					if (!bExist)
						continue;
					bExist=0;
					for (k=0; k<(int)nConBreakerArray.size(); k++)
					{
						if (nConBreakerArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
						{
							bExist=1;
							break;
						}
					}
					if (!bExist)
					{
						nConBreakerArray.push_back(pPGBlock->m_EdgeBreakerArray[j].nBreaker);
					}
				}
			}
			if (nConBreakerArray.empty())
			{
				PGTraverseVolt(pPGBlock, pPGBlock->m_EnergyConsumerArray[nDev].nNode, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);	//	Switch
				for (i=0; i<nNodeNum; i++)
				{
					for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
					{
						bExist=0;
						for (k=0; k<(int)nRingBreakArray.size(); k++)
						{
							if (nRingBreakArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
							{
								bExist=1;
								break;
							}
						}
						if (!bExist)
							continue;
						bExist=0;
						for (k=0; k<(int)nConBreakerArray.size(); k++)
						{
							if (nConBreakerArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
							{
								bExist=1;
								break;
							}
						}
						if (!bExist)
						{
							nConBreakerArray.push_back(pPGBlock->m_EdgeBreakerArray[j].nBreaker);
						}
					}
				}
			}
			if (0 <= nConBreakerArray.size() && nConBreakerArray.size() < 2)
			{
				nOneNum++;
			}
			else if (nConBreakerArray.size() >= 2)
			{
				if (!IsBreaksLoop(pPGBlock, nConBreakerArray[0], nConBreakerArray[1]))
					nTwoNum++;
			}
		}

		if (pPGBlock->m_VoltageLevelArray[nVolt].nominalVoltage < 100)
		{
			for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; nDev++)
			{
				if (pPGBlock->m_ShuntCompensatorArray[nDev].nNode < 0)
					continue;

				nConBreakerArray.clear();
				PGTraverseVolt(pPGBlock, pPGBlock->m_ShuntCompensatorArray[nDev].nNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);	//	Switch
				for (i=0; i<nNodeNum; i++)
				{
					for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
					{
						bExist=0;
						for (k=0; k<(int)nRingBreakArray.size(); k++)
						{
							if (nRingBreakArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
							{
								bExist=1;
								break;
							}
						}
						if (!bExist)
							continue;
						bExist=0;
						for (k=0; k<(int)nConBreakerArray.size(); k++)
						{
							if (nConBreakerArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
							{
								bExist=1;
								break;
							}
						}
						if (!bExist)
						{
							nConBreakerArray.push_back(pPGBlock->m_EdgeBreakerArray[j].nBreaker);
						}
					}
				}
				if (nConBreakerArray.empty())
				{
					PGTraverseVolt(pPGBlock, pPGBlock->m_ShuntCompensatorArray[nDev].nNode, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);	//	Switch
					for (i=0; i<nNodeNum; i++)
					{
						for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
						{
							bExist=0;
							for (k=0; k<(int)nRingBreakArray.size(); k++)
							{
								if (nRingBreakArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
								{
									bExist=1;
									break;
								}
							}
							if (!bExist)
								continue;
							bExist=0;
							for (k=0; k<(int)nConBreakerArray.size(); k++)
							{
								if (nConBreakerArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
								{
									bExist=1;
									break;
								}
							}
							if (!bExist)
							{
								nConBreakerArray.push_back(pPGBlock->m_EdgeBreakerArray[j].nBreaker);
							}
						}
					}
				}
				if (0 <= nConBreakerArray.size() && nConBreakerArray.size() < 2)
				{
					nOneNum++;
				}
				else if (nConBreakerArray.size() >= 2)
				{
					if (!IsBreaksLoop(pPGBlock, nConBreakerArray[0], nConBreakerArray[1]))
						nTwoNum++;
				}
			}
		}

		for (nNode=pPGBlock->m_VoltageLevelArray[nVolt].nConnecivityNodeRange; nNode<pPGBlock->m_VoltageLevelArray[nVolt+1].nConnecivityNodeRange; nNode++)
		{
			if (pPGBlock->m_ConnectivityNodeArray[nNode].bTNode)
				continue;
			for (nDev=pPGBlock->m_ConnectivityNodeArray[nNode].nACLineSegmentRange; nDev<pPGBlock->m_ConnectivityNodeArray[nNode+1].nACLineSegmentRange; nDev++)
			{
				nConBreakerArray.clear();
				PGTraverseVolt(pPGBlock, nNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);	//	Switch
				for (i=0; i<nNodeNum; i++)
				{
					for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
					{
						bExist=0;
						for (k=0; k<(int)nRingBreakArray.size(); k++)
						{
							if (nRingBreakArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
							{
								bExist=1;
								break;
							}
						}
						if (!bExist)
							continue;
						bExist=0;
						for (k=0; k<(int)nConBreakerArray.size(); k++)
						{
							if (nConBreakerArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
							{
								bExist=1;
								break;
							}
						}
						if (!bExist)
						{
							nConBreakerArray.push_back(pPGBlock->m_EdgeBreakerArray[j].nBreaker);
						}
					}
				}
				if (nConBreakerArray.empty())
				{
					PGTraverseVolt(pPGBlock, nNode, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);	//	Switch
					for (i=0; i<nNodeNum; i++)
					{
						for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
						{
							bExist=0;
							for (k=0; k<(int)nRingBreakArray.size(); k++)
							{
								if (nRingBreakArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
								{
									bExist=1;
									break;
								}
							}
							if (!bExist)
								continue;
							bExist=0;
							for (k=0; k<(int)nConBreakerArray.size(); k++)
							{
								if (nConBreakerArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
								{
									bExist=1;
									break;
								}
							}
							if (!bExist)
							{
								nConBreakerArray.push_back(pPGBlock->m_EdgeBreakerArray[j].nBreaker);
							}
						}
					}
				}
				if (0 <= nConBreakerArray.size() && nConBreakerArray.size() < 2)
				{
					nOneNum++;
				}
				else if (nConBreakerArray.size() >= 2)
				{
					if (!IsBreaksLoop(pPGBlock, nConBreakerArray[0], nConBreakerArray[1]))
						nTwoNum++;
				}
			}
			for (nDev=pPGBlock->m_ConnectivityNodeArray[nNode].nTransformerWindingRange; nDev<pPGBlock->m_ConnectivityNodeArray[nNode+1].nTransformerWindingRange; nDev++)
			{
				nConBreakerArray.clear();
				PGTraverseVolt(pPGBlock, nNode, N_CheckStatus, N_CheckStatus, Y_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);	//	Switch
				for (i=0; i<nNodeNum; i++)
				{
					for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
					{
						bExist=0;
						for (k=0; k<(int)nRingBreakArray.size(); k++)
						{
							if (nRingBreakArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
							{
								bExist=1;
								break;
							}
						}
						if (!bExist)
							continue;
						bExist=0;
						for (k=0; k<(int)nConBreakerArray.size(); k++)
						{
							if (nConBreakerArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
							{
								bExist=1;
								break;
							}
						}
						if (!bExist)
						{
							nConBreakerArray.push_back(pPGBlock->m_EdgeBreakerArray[j].nBreaker);
						}
					}
				}
				if (nConBreakerArray.empty())
				{
					PGTraverseVolt(pPGBlock, nNode, N_CheckStatus, N_CheckStatus, N_BusBound, Y_BreakerBound, nNodeNum, nNodeArray);	//	Switch
					for (i=0; i<nNodeNum; i++)
					{
						for (j=pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]].nBreakerRange; j<pPGBlock->m_ConnectivityNodeArray[nNodeArray[i]+1].nBreakerRange; j++)
						{
							bExist=0;
							for (k=0; k<(int)nRingBreakArray.size(); k++)
							{
								if (nRingBreakArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
								{
									bExist=1;
									break;
								}
							}
							if (!bExist)
								continue;
							bExist=0;
							for (k=0; k<(int)nConBreakerArray.size(); k++)
							{
								if (nConBreakerArray[k] == pPGBlock->m_EdgeBreakerArray[j].nBreaker)
								{
									bExist=1;
									break;
								}
							}
							if (!bExist)
							{
								nConBreakerArray.push_back(pPGBlock->m_EdgeBreakerArray[j].nBreaker);
							}
						}
					}
				}
				if (0 <= nConBreakerArray.size() && nConBreakerArray.size() < 2)
				{
					nOneNum++;
				}
				else if (nConBreakerArray.size() >= 2)
				{
					if (!IsBreaksLoop(pPGBlock, nConBreakerArray[0], nConBreakerArray[1]))
						nTwoNum++;
				}
			}
		}

		//	nLineTwo >= nTranTwo	��ֹ���Ž��ߣ���������ĸ��û��ʲô�÷�����
		if (nTwoNum > 0 && nTwoNum > nOneNum)
		{
			//		TRACE("3/2���� %s-%s %d %d\n", pPGBlock->m_VoltageLevelArray[nVolt].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szName, nOneNum, nTwoNum);
			return 1;
		}

		//	TRACE("          %s-%s %d %d\n", pPGBlock->m_VoltageLevelArray[nVolt].szSub, pPGBlock->m_VoltageLevelArray[nVolt].szName, nOneNum, nTwoNum);
		return 0;
	}
}
