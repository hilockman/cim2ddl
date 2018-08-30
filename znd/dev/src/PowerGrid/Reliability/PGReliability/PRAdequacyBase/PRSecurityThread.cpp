#include <process.h>
#include "PRSecurity.h"

extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	static	const char*	g_lpszDeskName = "SecurityDesktop";
	const	int	m_nCalcTimeOut=300000;

	unsigned __stdcall 	SecurityEstimateCalThreaad(void* lParam)
	{
		register int	i;
		clock_t	dBeg, dEnd;
		int		nDur;

		tagSecurityThreadInfo*	pInfo=(tagSecurityThreadInfo*)lParam;
		tagPRBlock*	pPRBlock=(tagPRBlock*)pInfo->pPRBlock;

		int					nFSecurity;
		char				szExec[260];
		STARTUPINFOA		si;
		PROCESS_INFORMATION	pi;

		while (TRUE)
		{
			nFSecurity=-1;
			EnterCriticalSection(&CPRSecurity::m_csLock);
			for (i=0; i<pPRBlock->m_nRecordNum[PR_FSECURITY]; i++)
			{
				if (pPRBlock->m_FSecurityArray[i].bEstimated == 0)
				{
					nFSecurity = i;
					pPRBlock->m_FSecurityArray[i].bEstimated = 1;
					break;
				}
			}
			LeaveCriticalSection(&CPRSecurity::m_csLock);
			if (nFSecurity < 0)
				break;

			Log(g_lpszLogFile, "    Bpa计算进程[%d]开始\n", nFSecurity);
			dBeg = clock();

			sprintf(szExec, "%s/swnt.exe %s %s", pPRBlock->m_System.szSaRunPath, pPRBlock->m_FSecurityArray[nFSecurity].szBseFile, pPRBlock->m_FSecurityArray[nFSecurity].szSwiFile);
			Log(g_lpszLogFile, "稳定计算：%s\n", szExec);


			memset(&si, 0, sizeof(si));
			si.lpDesktop = (LPTSTR)g_lpszDeskName;
			si.cb =sizeof(si);
			si.dwFlags=STARTF_USESHOWWINDOW;
			si.wShowWindow=SW_HIDE;

			pi.hProcess=INVALID_HANDLE_VALUE;

			if (!CreateProcess(NULL, szExec, NULL, NULL, TRUE, DETACHED_PROCESS, NULL, pPRBlock->m_System.szSaDesPath, &si, &pi))
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

				Log(g_lpszLogFile, "Error=%d[%s]", dw, (LPCTSTR)lpMsgBuf);

				LocalFree(lpMsgBuf);
				continue;
			}

			dEnd=clock();
			nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);

			if (WaitForSingleObject(pi.hProcess, m_nCalcTimeOut) == WAIT_OBJECT_0)
			{
				Log(g_lpszLogFile, "        Bpa计算进程[%d]完成，耗时 %d 毫秒\n", nFSecurity, nDur);
				if (pi.hProcess != INVALID_HANDLE_VALUE)	CloseHandle(pi.hProcess);
				if (pi.hThread != INVALID_HANDLE_VALUE)		CloseHandle(pi.hThread);
			}
			else
			{
				if (pi.hProcess != INVALID_HANDLE_VALUE)
				{
					Log(g_lpszLogFile, "        Bpa计算进程[%d]错误，耗时 %d 毫秒\n", nFSecurity, nDur);
					TerminateProcess(pi.hProcess, 0);
					CloseHandle(pi.hProcess);
					if (pi.hThread != INVALID_HANDLE_VALUE)		CloseHandle(pi.hThread);
				}
			}

			PostThreadMessage(pInfo->nMainThreadID, TM_ESTIMATING, 1, 0);
		}

		free(pInfo);
		_endthreadex(0);

		return 0;
	}

	unsigned __stdcall  SecurityEstimateConThreaad(void* lParam)
	{
		register int	i;
		clock_t		dBeg, dEnd;
		int			nDur;
		unsigned int	nChildThreadID;

		dBeg = clock();

		tagSecurityThreadInfo* pParentThreadInfo = (tagSecurityThreadInfo*)lParam;

		PostThreadMessage(pParentThreadInfo->nMainThreadID, TM_ESTIMATEBEG, 0, 0);

		SYSTEM_INFO sysInfo;
		::GetSystemInfo(&sysInfo);
		int		nThreadNum = 1;
		if (pParentThreadInfo->bMultiThread)
			nThreadNum=(int)sysInfo.dwNumberOfProcessors;

		HDESK hDesk = CreateDesktop(g_lpszDeskName, NULL, NULL, 0, GENERIC_ALL, NULL);

		std::vector<HANDLE>	m_CalculateThreadArray;
		m_CalculateThreadArray.resize(nThreadNum);
		for (i=0; i<(int)m_CalculateThreadArray.size(); i++)
		{
			tagSecurityThreadInfo*	pInfo=(tagSecurityThreadInfo*)malloc(sizeof(tagSecurityThreadInfo));
			memcpy(pInfo, pParentThreadInfo, sizeof(tagSecurityThreadInfo));

			m_CalculateThreadArray[i] = INVALID_HANDLE_VALUE;
			m_CalculateThreadArray[i] = (HANDLE)_beginthreadex(NULL, 0, SecurityEstimateCalThreaad, (void*)pInfo, 0, &nChildThreadID);
		}

		for (i=0; i<(int)m_CalculateThreadArray.size(); i++)
		{
			DWORD dwRet = WaitForSingleObject(m_CalculateThreadArray[i], INFINITE);
			if (dwRet == WAIT_OBJECT_0)
				Log(g_lpszLogFile, "        BPA计算控制进程[%d]完成\n", i+1);
			else
				Log(g_lpszLogFile, "        BPA计算控制进程[%d]错误 RetCode = %d\n", i+1, dwRet);
			if (m_CalculateThreadArray[i] != INVALID_HANDLE_VALUE)
				CloseHandle(m_CalculateThreadArray[i]);
		}

		CloseHandle(hDesk);

		PostThreadMessage(pParentThreadInfo->nMainThreadID, TM_ESTIMATEEND, 0, 0);

		free(pParentThreadInfo);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "SecurityEstimateThreaad 完成，耗时 %d 毫秒\n", nDur);

		_endthreadex(0);

		return 0;
	}
}
