#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define	 _CRT_SECURE_NO_WARNINGS
#endif

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include <time.h>
#include <sstream>
#include <vector>
using namespace	std;

#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
#	ifndef	STRICMP
#		define	STRICMP		stricmp
#		define	STRNICMP	strnicmp
#	endif
// #	pragma warning (disable:4251)
// #	pragma warning (disable:4018)
// #	pragma warning (disable:4996)
// #	pragma	warning(disable:4819)
// #	pragma	warning(disable:4100)
#else
#	include <sys/types.h>
#	include <sys/ipc.h>
#	include <sys/shm.h>
#	ifndef	STRICMP
#		define	STRICMP		strcasecmp
#		define	STRNICMP	strncasecmp
#	endif
#endif

#include "../include/MDBDefine.h"

namespace	MemDBBase
{
	extern	char*		Init_MDBBlock(const int nMemDBKey, const int nMemSize, const int bCreateMem=0, char* lpszRetMesg=NULL);
	extern	void		Exit_MDBBlock(char* lpszBlockMap, const int nMemDBKey=0);
	extern	void		CalculateResourceId(const char* lpszString, char* lpszRetResID);
	extern const int	GetFieldCategoryNum();
	extern const char*	GetFieldCategoryName(const int nCatrgory);
	extern const int	GetFieldCategoryValue(const char* lpszCatrgory);
}

