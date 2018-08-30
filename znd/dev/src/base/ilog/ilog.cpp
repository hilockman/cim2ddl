#include <ilog.h>

#if defined(WIN32) && defined(_MSC_VER) && _MSC_VER < 1600
#include "stdint-msvc2008.h"
#else
#include <stdint.h>
#endif
#include <sys/stat.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

#define  _ECO_LOG_TRACE 0
#define  _ECO_LOG_DEBUG 1
#define  _ECO_LOG_INFO 2
#define  _ECO_LOG_WARN 3
#define  _ECO_LOG_ERROR 4
#define  _ECO_LOG_FATAL 5

const char * elog_file_name = "eco.log";

void _eco_set_log_file(const char *logFile) {
	elog_file_name = logFile;
}

void  __eco_lib_log_out__(const int32_t log_level, const char *file, const char *function, int line, const char *format, ...)
{
	const char *LOG_LEVEL_NAME[32] = { "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "LOG_FATAL" };
	if (log_level == _ECO_LOG_TRACE)
	{
		return;
	}
	const int MAX_LOG_CONTENT_LENGTH = 2048;
	char content[MAX_LOG_CONTENT_LENGTH];
	va_list va_para_list;
	va_start(va_para_list, format);

#ifdef WIN32
	_vsnprintf(content, MAX_LOG_CONTENT_LENGTH, format, va_para_list);
#else
	vsnprintf(content, MAX_LOG_CONTENT_LENGTH, format, va_para_list);
#endif	
	va_end(va_para_list);
	for (int i = strlen(content) - 1; i >= 0 && (content[i] == '\n' || content[i] == ' '); --i){ content[i] = 0; }
	time_t time_now = time(NULL);
	struct tm *ptm = localtime(&time_now);
	if (log_level < _ECO_LOG_WARN)
	{
		printf("%4d-%02d-%02d %02d:%02d:%02d ECO_$%s_LOG >> \"%s\"\n",
			ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, LOG_LEVEL_NAME[log_level], content);
	}
	else
	{

		//eco::STD_OUT_COLOR_GUARD color_guard( STD_OUT_RED );
		printf("---------ECO_LOG:%s---------\n%4d-%02d-%02d  %02d:%02d:%02d $[%s / %s() / L:%d]\n\t$LOG>> \"%s\"\n\n",
			LOG_LEVEL_NAME[log_level],
			ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday,
			ptm->tm_hour, ptm->tm_min, ptm->tm_sec, file, function, line, content);
		
		FILE * out = fopen(elog_file_name, "a+");
		if (out == NULL)
		{
			fprintf(stderr, "Can not open outputfile.\n");
			return;
		}
		fprintf(out, "---------ECO_LOG:%s---------\n%4d-%02d-%02d  %02d:%02d:%02d $[%s / %s() / L:%d]\n\t$LOG>> \"%s\"\n\n",
			LOG_LEVEL_NAME[log_level],
			ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday,
			ptm->tm_hour, ptm->tm_min, ptm->tm_sec, file, function, line, content);

		bool is_too_big = false;

		struct stat filestat;
		memset(&filestat, 0, sizeof(filestat));

		int er = fstat(fileno(out), &filestat);
		if (er >= 0)
		{
			if (filestat.st_size > 100 * 1024 * 1024)
			{
				is_too_big = true;
			}
		}
		fclose(out);
		if (is_too_big)
		{
			unlink(elog_file_name);
		}
	}

}


