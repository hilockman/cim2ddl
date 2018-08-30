#include "log.h"

using namespace eco;

extern void  __eco_lib_log_out__(const int32_t log_level, const char *file, const char *function, int line, const char *format, ...);

int eco::log_reg(int argc, char **argv, const char *date, const char *time)
{
	return 0;
}


void eco::log_out_t(const int32_t  out_interval_time, const int32_t log_level, const char *src_file, const char *function, int line, const char *format, ...) {
	va_list va_para_list;
	va_start(va_para_list, format);

	__eco_lib_log_out__(log_level, src_file, function, line, format, va_para_list);
}