#ifndef STATE_ESTIMATE_TASK_HEADER____________________
#define STATE_ESTIMATE_TASK_HEADER____________________
#include <string>
#include "stateestimatedef.h"

namespace PRAdequacyBase {
	struct _BpaPRAdequacySetting_;
	typedef struct _BpaPRAdequacySetting_ tagBpaPRAdequacySetting;
};


class StateEstimateTask
{
public:
	StateEstimateTask();
	~StateEstimateTask();

	void setParameter(const std::string &param);

	bool isIdle() const;

	void run();

	int Create(const int nThreadID, PRAdequacyBase::tagBpaPRAdequacySetting* pSetting, send_func sender);


	void setBusy();
private:
	class StateEstimateTaskPrivate;
	//friend class StateEstimateTaskPrivate;

	StateEstimateTaskPrivate *d;



};


#endif

