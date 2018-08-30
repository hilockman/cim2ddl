#ifndef LOG_HEADER______________
#define LOG_HEADER______________

#include "zndexp.h"
#if defined(WIN32) && defined(_MSC_VER) && _MSC_VER < 1600
#include "stdint-msvc2008.h"
#else
#include <stdint.h>
#endif

#include <stdarg.h>

#define  LOG_TRACE 0
#define  LOG_DEBUG 1
#define  LOG_INFO 2
#define  LOG_WARN 3
#define  LOG_ERROR 4
#define  LOG_FATAL 5
#define  LOG_TXD 6
#define  LOG_RXD 7

namespace eco {
	int  ZND_EXP log_reg(int argc, char **argv, const char *date, const char *time);
	int  ZND_EXP log_register(int argc, char **argv, const char *date, const char *time);


	int  ZND_EXP log_reg_v2(int argc, char **argv, const char *date, const char *time, const int std_out_level, const int file_out_level = LOG_INFO);


	void ZND_EXP log_out(const int32_t level, const char *file, const char *function, int line, const char *format, ...);

	void ZND_EXP log_out_t(const int32_t  out_interval_time, const int32_t log_level, const char *file, const char *function, int line, const char *format, ...);
	void ZND_EXP log_out_t(const int32_t  out_interval_time, const int32_t log_level, const char *file, const char *function, int line, const char *format, va_list args);
};
#endif