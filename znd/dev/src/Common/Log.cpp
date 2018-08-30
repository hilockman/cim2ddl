#include "stdafx.h"
#include <io.h>
#include <stdio.h>
#include <Windows.h>

void	ClearLog(const char* lpszLogFile)
{
	char	szTempPath[260], szFileName[260];

#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
	GetTempPathA(260, szTempPath);
#else
	strcpy(szTempPath, "/tmp");
#endif

	sprintf(szFileName, "%s/%s", szTempPath, lpszLogFile);
	FILE*	fp=fopen(szFileName, "w");
	fflush(fp);
	fclose(fp);
}

void	Log(const char* lpszLogFile, const char* pformat, ...)
{
	va_list args;
	va_start( args, pformat );

	char	szTempPath[260], szFileName[260];
	FILE*	fp;

#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
	GetTempPathA(260, szTempPath);
#else
	strcpy(szTempPath, "/tmp");
#endif

	sprintf(szFileName, "%s/%s", szTempPath, lpszLogFile);
	if (_access(szFileName, 0) != 0)
	{
		fp=fopen(szFileName, "w");
		if (fp != NULL)
		{
			fflush(fp);
			fclose(fp);
		}
		else
			return;
	}
	fp=fopen(szFileName, "a");
	if (fp != NULL)
	{
		vfprintf(fp, pformat, args);

		fflush(fp);
		fclose(fp);
	}

	va_end(args);
}

