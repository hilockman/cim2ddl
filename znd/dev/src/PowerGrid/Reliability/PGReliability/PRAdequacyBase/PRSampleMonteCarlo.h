#pragma once

#include "PRSampleBase.h"

namespace	PRAdequacyBase
{
	//////////////////////////////////////////////////////////////////////////
	//	蒙特卡洛抽样
	typedef	struct	_MCSDevState_
	{
		int				nCompIndex;	//	在CompArray中的序号
		double			fRerr;		//	故障率，多状态无效
		double			fRrep;		//	修复率，多状态无效
		unsigned char	nStatus;	//	记录两状态模型的下一状态, 两状态则为GOOD和FAIL，多状态模型不使用该数据

		unsigned char	bMState;
		double			fMSPout;	//	多状态模型的当前出力，下一状态需要单独计算，这点与两状态模型是有区别的

		double			fEvtTime;	//	当前状态到下一状态持续时间
	}	tagMCSDevState;

	class CPRSampleMonteCarlo : public CPRSampleBase
	{
	public:
		CPRSampleMonteCarlo(void);
		~CPRSampleMonteCarlo(void);

		//////////////////////////////////////////////////////////////////////////
		//	蒙特卡洛状态抽样
	public:
		int Sample(tagPRBlock* pPRBlock, const double fSimTime, const int nMaxGenFault, const int nMaxBranFault, const double fProbThreshold=0);

	private:
		int MonteCarlo2StateAddFDev(tagPRBlock* pPRBlock, tagPRSampleState* pState, const int nMaxGenFault, const int nMaxBranFault, const int nCompIndex);
		void MonteCarlo2StateDelFDev(tagPRBlock* pPRBlock, tagPRSampleState* pState, const int nCompIndex);
		void MCSDev2StateDuration_Calc(tagMCSDevState* pDevState);

		void MonteCarloMState(tagPRBlock* pPRBlock, tagPRSampleState* pState, const int nMStateDev);
		void MCSDevMStateDuration_Calc(tagPRBlock* pPRBlock, tagMCSDevState* pDevState);
		void MCSDevStateDuration_Sort(std::vector<tagMCSDevState>& evtArray, int nDn0, int nUp0);

	public:
		std::vector<tagMCSDevState>		m_MCSDevStateArray;
		std::vector<tagPRSampleState>	m_MCSSysStateArray;

	private:
		int ComparePRSampleMStatePout(tagPRSampleState& stA, tagPRSampleState& stB);
		void SortPRSampleMStatePout(std::vector<tagPRSampleState>& stArray, int nDn0, int nUp0);
		int FindPRSampleMStatePout(std::vector<tagPRSampleState>& stArray, int nLeft, int nRight, tagPRSampleState& stBuf);
	};
}
