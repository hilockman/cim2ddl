#pragma once

#include "BpaPRDataDefine.h"
#include "PRSampleMonteCarlo.h"
#include "PRSampleFastSort.h"
#include "PRSampleState.h"
#include "PRSampleAnalytic.h"

#include "PRAdequacyBaseExp.h"

namespace	PRAdequacyBase
{
	class PRADEQUACYBASE_EXP CPRAdequacyStateSample
	{
	public:
		CPRAdequacyStateSample(void);
		~CPRAdequacyStateSample(void);

		int	 Sample(tagPRBlock* pPRBlock, const int nSampleObject, const int nSampleMethod, tagBpaPRAdequacySetting* pSetting);

	private:	//	��������
		CPRSampleMonteCarlo	m_PRSampleMCS;			//	���ؿ���״̬����
		CPRSampleFastSort	m_PRSampleFST;			//	��������״̬����
		CPRSampleState		m_PRSampleSTS;			//	״̬����
		CPRSampleAnalytic	m_PRSampleANA;			//	������

	private:	//	��������
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
		void FormPRSampleObject(tagPRBlock* pPRBlock, const int nPRCompObject=PRSystem_SampleObject_All);	//	�γɿɿ��Լ�������
		void CalcPRSampleObjectProbability(tagPRBlock* pPRBlock, const double fForcastTime);	//	��������ʵ�

	private:
		void CommonFState(tagPRBlock* pPRBlock);
		void ManualFState(tagPRBlock* pPRBlock);
		double ManualFStateProb(tagPRBlock* pPRBlock, const int nManual);
	};
}
