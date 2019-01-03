#include "../state-estimate-core/stateestimate.h"

#include <ilog.h>
#include <stdarg.h>
extern "C" int logReg(int argc, char **argv) {
	return log_reg(argc, argv);
}

extern "C" void logDebug(const char *format, ...) {
	va_list va_para_list;
	va_start(va_para_list, format);
	log_debug(format, va_para_list);
	va_end(va_para_list);
}

extern "C" void logError(const char *format, ...) {
	va_list va_para_list;
	va_start(va_para_list, format);
	log_error(format, va_para_list);
	va_end(va_para_list);
}

extern "C" void logInfo(const char *format, ...) {
	va_list va_para_list;
	va_start(va_para_list, format);
	log_info(format, va_para_list);
	va_end(va_para_list);
}
typedef void(*sendResponsMessage)(const char *msg);

extern "C" StateEstimate *createCalculator(const char *settingStr, sendResponsMessage sender)
{
	StateEstimate *se = new StateEstimate(sender);
	return se;
}


extern "C" void freeCalculator(StateEstimate *se)
{
	delete se;
}

extern "C" void configCalculator(StateEstimate *se, const char *settingStr)
{
	se->setConfig(settingStr);
}



extern "C" void runSample(StateEstimate *se, const char *sampleStr)
{
	if (se)
		se->runSample(sampleStr);
	else {
		log_error("StateEstimate instance is NULL, Cann't process message '%s':%s", sampleStr);
	}
}


extern "C" int calcReliability(const char *configFile){
	StateEstimate se(0);
	se.run(configFile);
	return 0;
}