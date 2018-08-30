#pragma once

#include "BpaPRDataDefine.h"
#include "PRSampleMonteCarlo.h"
#include "PRSampleFastSort.h"
#include "PRSampleState.h"
#include "PRSampleAnalytic.h"

namespace	PRAdequacyBase
{
	class CPRAdequacyStateSample
	{
	public:
		CPRAdequacyStateSample(void);
		~CPRAdequacyStateSample(void);

		int	 Sample(tagPRBlock* pPRBlock, const int nSampleObject, const int nSampleMethod, tagBpaPRAdequacySetting* pSetting);

	private:	//	抽样方法
		CPRSampleMonteCarlo	m_PRSampleMCS;			//	蒙特卡洛状态抽样
		CPRSampleFastSort	m_PRSampleFST;			//	快速排序状态抽样
		CPRSampleState		m_PRSampleSTS;			//	状态抽样
		CPRSampleAnalytic	m_PRSampleANA;			//	解析法

	private:	//	抽样方法
		int	MCSSample(tagPRBlock* pPRBlock, const double fSimTime, const int nMaxGenFault, const int nMaxBranFault, const double fStateProbThreshold=0)
		{
			return m_PRSampleMCS.Sample(pPRBlock, fSimTime, nMaxGenFault, nMaxBranFault, fStateProbThreshold);
		};
		int	FSTSample(tagPRBlock* pPRBlock, const double fProbPrecision, const int nMaxState, const int nMaxGenFault, const int nMaxBranFault, const double fStateProbThreshold)
		{
			return m_PRSampleFST.Sample(pPRBlock, fProbPrecision, nMaxState, nMaxGenFault, nMaxBranFault, fStateProbThreshold);
		};
		int	STSSample(tagPRBlock* pPRBlock, const int nMaxSample)
		{
			return m_PRSampleSTS.Sample(pPRBlock, nMaxSample);
		};
		int	ANASample(tagPRBlock* pPRBlock, const int nMaxGenFault, const int nMaxBranFault, const double fMinStateProb)
		{
			return m_PRSampleANA.Sample(pPRBlock, nMaxGenFault, nMaxBranFault, fMinStateProb);
		};

	private:
		void FormPRSampleObject(tagPRBlock* pPRBlock, const int nPRCompObject=PRSystem_SampleObject_All);	//	形成可靠性计算数据
		void CalcPRSampleObjectProbability(tagPRBlock* pPRBlock, const double fForcastTime);	//	计算完好率等

	private:
		void CommonFState(tagPRBlock* pPRBlock);
		void ManualFState(tagPRBlock* pPRBlock);
		double ManualFStateProb(tagPRBlock* pPRBlock, const int nManual);
	};
}
