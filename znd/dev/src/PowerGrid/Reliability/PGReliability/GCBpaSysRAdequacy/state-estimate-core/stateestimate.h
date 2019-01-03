#ifndef STATE_ESTIMATE_HEADER____________________
#define STATE_ESTIMATE_HEADER____________________
#include "stateestimateexp.h"
#include "stateestimatedef.h"





class STATEESTIMATE_EXP StateEstimate
{
public:
	StateEstimate(send_func f);
	~StateEstimate();


	void setConfig(const char *config);

	void runSample(const char *sample);

	/**
	
	run reliability calculation for config file.
	*/
	void run(const char *configFile);
private:
	class  StateEstimatePrivate;
	StateEstimatePrivate *d;
	
};
//extern "C" void se_func();
//
//extern  STATEESTIMATE_EXP StateEstimate *  createStateEstimate(const char *settingStr);
#endif

