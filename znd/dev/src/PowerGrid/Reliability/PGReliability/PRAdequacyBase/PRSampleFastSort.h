#pragma once

#include "PRSampleBase.h"

namespace	PRAdequacyBase
{
	//////////////////////////////////////////////////////////////////////////
	//	快速排序法中间信息
	typedef	struct	_FastSortTransient_
	{
		int				nCompIndex;	//	在CompArray中的序号
		unsigned char	nStatus;	//	设备状态
		double			fProb;		//	概率
	}	tagFastSortTransient;

	class CPRSampleFastSort : public CPRSampleBase
	{
	public:
		CPRSampleFastSort(void);
		~CPRSampleFastSort(void);

		//////////////////////////////////////////////////////////////////////////
		//	快速排序状态抽样
	public:
		int	Sample(tagPRBlock* pPRBlock, const double fProbPrecision, const int nMaxState, const int nMaxGenFault, const int nMaxBranFault, const double fStateProbThreshold=0);

	private:
		void FastSortExperiment(tagPRBlock* pPRBlock);
		void SortFastSortTransient(std::vector<tagFastSortTransient>& tArray, int nDn0, int nUp0);

		void FastSortCalculateStateProbability(tagPRSampleState* pState);
		void FastSortCalculateStateFrequency(tagPRBlock* pPRBlock, tagPRSampleState* pState);
		void ExpandNeighbourhood(tagPRSampleState* pState);

		int FastSortAddState(tagPRBlock* pPRBlock, tagPRSampleState* pState, const int nMaxGenFault, const int nMaxBranFault, const int nMode);
		int FastSortAddNeighbourState(tagPRSampleState& stAdd);

		void ModCompModel(tagPRBlock* pPRBlock);	//	计算实时故障率, 指数模型

	private:
		double								m_fActualProbility;
		std::vector<tagFastSortTransient>	m_FSTransientArray;
		std::vector<tagPRSampleState>				m_FSStateArray;
		std::vector<tagPRSampleState>				m_FSNeighbourStateArray;

	private:
		void SortPRStateProb(std::vector<tagPRSampleState>& tArray, int nDn0, int nUp0);
	};
}
