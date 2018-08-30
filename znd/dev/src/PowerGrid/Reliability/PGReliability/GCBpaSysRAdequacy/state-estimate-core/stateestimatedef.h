#ifndef STATEESTIMATEDEF_HEADER______________________
#define STATEESTIMATEDEF_HEADER______________________

#define	Command_DataReady		"DataReady"
#define	Command_StateEstimate	"StateEstimate"
#define	Command_JobFinished		"JobFinished"

typedef void(*send_func)(const char *msg);

#endif
