#pragma once

#include "PRSampleBase.h"

namespace	PRAdequacyBase
{
	class CPRSampleAnalytic : public CPRSampleBase
	{
	public:
		CPRSampleAnalytic(void);
		~CPRSampleAnalytic(void);

	public:
		int	Sample(tagPRBlock* pPRBlock, const int nMaxGenFault, const int nMaxBranFault, const double fMinStateProb);

	private:
		int	StateAnalyticalCalculateStateProbability(tagPRBlock* pPRBlock, tagPRSampleState* pState, const int nMaxGenFault, const int nMaxBranFault, const double fMinStateProb);
	private:
		double	m_fSysProb;
		std::vector<tagPRSampleState>			m_SAStateArray;
	};
}
