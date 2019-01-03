#pragma once

#include "BpaPRParam.h"

#include "PRSampleMonteCarlo.h"
#include "PRSampleFastSort.h"
#include "PRSampleState.h"
#include "PRSampleAnalytic.h"
#include "PRAdequacyStateSample.h"

#include "PRAdequacyEstimate.h"
#include "PRAdequacyStateEstimate.h"

#include "PRCopTable.h"
#include "PRSecurity.h"

#include "PRAdequacyBaseExp.h"

namespace	PRAdequacyBase
{
	extern	PRADEQUACYBASE_EXP int		 AppendMStateParam(tagPRBlock* pPRBlock, tagPRDevMState* pMState);
	extern	PRADEQUACYBASE_EXP int		 ModifyMStateParam(tagPRBlock* pPRBlock, const int nModRec, tagPRDevMState* pMState);

	extern	PRADEQUACYBASE_EXP void	 InitBpaPRAdequacySetting(tagBpaPRAdequacySetting* pSetting);
	extern	PRADEQUACYBASE_EXP void  CopyBpaPRAdequacySetting(tagBpaPRAdequacySetting* pFromSetting, tagBpaPRAdequacySetting* pToSetting);
	extern	PRADEQUACYBASE_EXP int	 ReadBpaPRAdequacySetting(const char* lpszSettingFile, tagBpaPRAdequacySetting* pSetting);
	extern	PRADEQUACYBASE_EXP void	 SaveBpaPRAdequacySetting(tagBpaPRAdequacySetting* pSetting);

	extern	unsigned int	__stdcall  GenAdequacyEstimateConThreaad(void* lParam);
	extern	unsigned int	__stdcall  SysAdequacyEstimateConThreaad(void* lParam);
}

extern	PRADEQUACYBASE_EXP void BpaMemDB2PRMemDB(tagBpaBlock* pBpaBlock, tagPRBlock* pPRBlock, const char* lpszBpaDatFile, const char* lpszBpaSwiFile, const unsigned char bGenBusLoadAsAux);
extern PRADEQUACYBASE_EXP void PGMemDB2PRMemDB(tagPGBlock* pPGBlock, tagPRBlock* pPRBlock);
