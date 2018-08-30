#include "stdafx.h"
#include <stdio.h>
#include <io.h>
#include <windows.h>

const	char*	lpszProcessLog="Process.log";
void	ProcessLog(char* pformat, ...)
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

	sprintf(szFileName, "%s/%s", szTempPath, lpszProcessLog);
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


int	StartProcess(char* lpszCmd, const char* lpszPath, WORD swType)
{
	STARTUPINFO         si;
	PROCESS_INFORMATION pi;
	int					bRet;

	memset(&si, 0, sizeof(si));
	si.cb =sizeof(si);
	//si.dwFlags=STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
	si.dwFlags=STARTF_USESHOWWINDOW;
	si.wShowWindow=swType;
	si.hStdOutput = GetStdHandle(STD_ERROR_HANDLE);

	_flushall();

	if (lpszPath)
	{
		if (!SetCurrentDirectory(lpszPath))
		{
			LPVOID	lpMsgBuf;
			DWORD dw = GetLastError(); 

			FormatMessage(
				FORMAT_MESSAGE_ALLOCATE_BUFFER | 
				FORMAT_MESSAGE_FROM_SYSTEM |
				FORMAT_MESSAGE_IGNORE_INSERTS, 
				NULL, 
				dw, 
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
				(LPTSTR) &lpMsgBuf, 
				0, NULL );

			// Display the error message and exit the process
			ProcessLog("SetCurrentDirectory Error=%d[%s]\n", dw, (LPCTSTR)lpMsgBuf);
			LocalFree(lpMsgBuf);
			return 0;
		}
	}

	bRet=CreateProcess(NULL, 
		lpszCmd, 
		NULL, 
		NULL, 
		FALSE,	//TRUE, 
		NORMAL_PRIORITY_CLASS,	//DETACHED_PROCESS, 
		NULL, 
		lpszPath, 
		&si, 
		&pi);
	if (bRet)
	{
		DWORD dwRet=WaitForSingleObject(pi.hProcess, INFINITE);
		if (dwRet == WAIT_OBJECT_0)
		{
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
		}
	}
	else
	{
		LPVOID	lpMsgBuf;
		DWORD dw = GetLastError(); 

		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS, 
			NULL, 
			dw, 
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
			(LPTSTR) &lpMsgBuf, 
			0, NULL );

		// Display the error message and exit the process

		ProcessLog("CreateProcess Error=%d %s", dw, (LPCTSTR)lpMsgBuf);
		LocalFree(lpMsgBuf);
	}

	return bRet;
}