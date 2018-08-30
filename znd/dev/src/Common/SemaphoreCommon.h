#pragma once
#include <Windows.h>

#if !(defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
	/*	打开信号操作，等待型	*/
	struct sembuf  semon = {
		0,-1,SEM_UNDO
	};

	/*	关闭信号操作，等待型	*/
	struct sembuf  semoff = {
		0,1,SEM_UNDO 
	};

	struct sembuf  semwait = {
		0,0,SEM_UNDO
	};

	union	semun {
		int					val;
		struct	semid_ds	*buf;
		u_short*			array;
	}	sem_arg;

#else

	extern	HANDLE	InitSem(const char* lpszSemKey);
	extern	HANDLE	SemOn(const char* lpszSemKey, const int nMillionSecond);
	extern	void	SemOff(HANDLE hSem);

#endif
