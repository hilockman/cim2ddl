#pragma once

#include "PRSampleBase.h"

namespace	PRAdequacyBase
{
	class CPRSampleState : public CPRSampleBase
	{
	public:
		CPRSampleState(void);
		~CPRSampleState(void);

	public:
		int	Sample(tagPRBlock* pPRBlock, const int nMaxState);

	private:
		std::vector<tagPRSampleState>			m_StateArray;
	};
}
