#include <Win32_Interop/win32_types.h>

#include <MemDB/PRMemDB/PRMemDB.h>
#include "stateestimate.h"

const int BLOCK_BASE = 150;
static int nThreadID = 0;

// 唯一的应用程序对象
const	char*	g_lpszLogFile = "state-estimate.log";

#include <PRAdequacyBase.h>
using namespace PRAdequacyBase;

class StateEstimatePrivate
{
public:
	CPRMemDBInterface m_PRMemDBInterface;
	tagPRBlock*	 m_pPRWorkBlock;
	int m_nWorkMemID;
	CPRAdequacyStateEstimate *m_pPREstimate;
	StateEstimatePrivate();
};

StateEstimatePrivate::StateEstimatePrivate()
{
	m_nWorkMemID = BLOCK_BASE + 1000 + nThreadID++;
	m_pPRWorkBlock = (tagPRBlock*)m_PRMemDBInterface.Init_PRBlock(m_nWorkMemID);
	m_pPREstimate = new CPRAdequacyStateEstimate();
}
StateEstimate::StateEstimate() : d(new StateEstimatePrivate())
{
	

	//CopyBpaPRAdequacySetting(pSetting, &m_PRAdequacySetting);
}


StateEstimate::~StateEstimate()
{
	delete d;
}
