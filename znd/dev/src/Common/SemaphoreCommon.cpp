#include "stdafx.h"
#include <windows.h>
#include "SemaphoreCommon.h"

#include <string.h>
#include <iostream>
using namespace std;

#if !(defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
int	InitSem(key_t nSemKey)
{
	int nSem=semget(nSemKey,1,IPC_CREAT|0666);
	if (nSem < 0)
		{
		perror("semget error");
		return 0;
		}

	sem_arg.val=1;
	if (semctl(nSem,0,SETVAL,sem_arg) < 0)
		{
		perror("set semval error");
		return 0;
		}

	return nSem;
}

int	OpenSem(key_t nSemKey)
{
	int	nSemID=semget(nSemKey,1,IPC_CREAT|0666);
#ifdef	DEBUG
//	qDebug("OpenSem(%d)=%d",nSemKey,semctl(nSemID,0,GETVAL));
#endif

	return nSemID;
}

int	CloseSem(key_t nSemKey)
{
	int	nSem=OpenSem(nSemKey);
	if (nSem < 0)
		{
//		qDebug("Error in OpenSem %d",nSemKey);
		return 0;
		}
	if (semctl(nSem,0,IPC_RMID,NULL) < 0)
		{
//		qDebug("semctl destroy error");
		return 0;
		}

	return 1;
}

int	SemOn(key_t nSemKey)
{
	int	nSem=OpenSem(nSemKey);
	if (nSem < 0)
		{
		printf("Error in OpenSem %d\n",nSemKey);
		return 0;
		}
	if (semop(nSem,(struct sembuf *)(&semon),1) == -1)
		{
		fprintf(stderr,"error when semop(on) %d\n",nSemKey);
		return 0;
		}
	else
		{
#ifdef	DEBUG
		printf("SemOn(%d)\n",nSemKey);
#endif
		}

	return 1;
}

int	SemOff(key_t nSemKey)
{
	int	nSem=OpenSem(nSemKey);
	if (nSem < 0)
		{
		printf("Error in OpenSem %d\n",nSemKey);
		return 0;
		}
	if (semop(nSem,(struct sembuf *)(&semoff),1) == -1)
		{
		fprintf(stderr,"error when semop(off) %d\n",nSemKey);
		return 0;
		}
	else
		{
#ifdef	DEBUG
		printf("SemOff(%d)\n",nSemKey);
#endif
		}

	return 1;
}

int	IsSemBlock(key_t nSemKey)
{
	int	nSem=OpenSem(nSemKey);
	if (nSem < 0)
		{
		printf("Error in OpenSem %d\n",nSemKey);
		return 0;
		}

	if (semctl(nSem,0,GETVAL) == 0)
		return 0;

	return 1;
}

int	SemBlock(key_t nSemKey)
{
	int	nSem=OpenSem(nSemKey);
	if (nSem < 0)
		{
		printf("Error in OpenSem %d\n",nSemKey);
		return 0;
		}

	sem_arg.val=1;
	if (semctl(nSem,0,SETVAL,sem_arg) < 0)
		{
		perror("set semval error");
		return 0;
		}

	return 1;
}

int	SemWait(key_t nSemKey)
{
	int	nSem=OpenSem(nSemKey);
	if (nSem < 0)
		{
		printf("Error in OpenSem %d\n",nSemKey);
		return 0;
		}

	if (semop(nSem,(struct sembuf *)(&semwait),1) == -1)
		{
		fprintf(stderr,"semop error %d\n",nSemKey);
		return 0;
		}

	return 1;
}

int	SemWaitTimeout(key_t nSemKey, int nTimeout)
{
#ifndef	__alpha
	struct timespec	timeout;
	int	nSem=OpenSem(nSemKey);
	if (nSem < 0)
		{
		printf("Error in OpenSem %d\n",nSemKey);
		return 0;
		}

	timeout.tv_sec=nTimeout/1000;
	timeout.tv_nsec=(nTimeout-1000*timeout.tv_sec)*1000;
	if (semtimedop(nSem,(struct sembuf *)(&semwait),1,&timeout) == -1)
		{
		switch (errno)
			{
			case	EAGAIN:
//				printf("SemWaitTimeout EAGAIN\n");
				break;
			case	EFAULT:
//				printf("SemWaitTimeout EFAULT\n");
				break;
			case	EINVAL:
//				printf("SemWaitTimeout EINVAL\n");
				break;
			default:
				break;
			}
		return 0;
		}
#else
	SemWait(nSemKey);
#endif

	return 1;
}

int	SemSignal(key_t nSemKey)
{
	int	nSem=OpenSem(nSemKey);
	if (nSem < 0)
		{
		printf("Error in OpenSem %d\n",nSemKey);
		return 0;
		}

	sem_arg.val=0;
	if (semctl(nSem,0,SETVAL,sem_arg) < 0)
		{
		perror("set semval error");
		return 0;
		}

	return 1;
}

#else
extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);

HANDLE	InitSem(const char* lpszSemKey)
{
	return CreateSemaphore(NULL, 1, 1, lpszSemKey);
}

HANDLE	SemOn(const char* lpszSemKey, const int nMillionSecond)
{
	HANDLE	hSem=OpenSemaphore(
						SEMAPHORE_ALL_ACCESS | SEMAPHORE_MODIFY_STATE | SYNCHRONIZE,
						TRUE,
						lpszSemKey);
	if (hSem)
	{
		DWORD	dwRet = WaitForSingleObject(hSem, nMillionSecond);
		if (dwRet != WAIT_OBJECT_0)
		{
			Log(g_lpszLogFile, "WaitForSingleObject´íÎó Ret=%d\n", dwRet);
			CloseHandle(hSem);
			return INVALID_HANDLE_VALUE;
		}
		else
		{
		}

		return hSem;
	}
	else
	{
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL 
			);
		Log(g_lpszLogFile, "OpenSemaphore´íÎó Error=%s\n", lpMsgBuf);
		LocalFree( lpMsgBuf );
	}

	return INVALID_HANDLE_VALUE;
}

void	SemOff(HANDLE hSem)
{
	ReleaseSemaphore(hSem,1,NULL);
	CloseHandle(hSem);
}

#endif