#include "stdafx.h"
#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
#	include <Windows.h>
#endif
#include "MemDBHash.h"
#include "MemDBBase.h"

namespace	MemDBBase
{
	const	char*	lpszLogFile="MemDBBase.log";
	void	MDBClearLog()
	{
		char	szTempPath[260], szFileName[260];

#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
		GetTempPath(260, szTempPath);
#else
		strcpy(szTempPath, "/tmp");
#endif

		sprintf(szFileName, "%s/%s", szTempPath, lpszLogFile);
		FILE*	fp=fopen(szFileName, "w");
		fflush(fp);
		fclose(fp);
	}

	void MDBLog(const char* pformat, ...)
	{
		va_list args;
		va_start( args, pformat );

#ifdef _DEBUG
		char	szTempPath[260], szFileName[260];
		FILE*	fp;

#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
		GetTempPath(260, szTempPath);
#else
		strcpy(szTempPath, "/tmp");
#endif

		sprintf(szFileName, "%s/%s", szTempPath, lpszLogFile);
		fp=fopen(szFileName, "a");
		if (fp != NULL)
		{
			vfprintf(fp, pformat, args);

			fflush(fp);
			fclose(fp);
		}
#endif

		va_end(args);
	}

	char* Init_MDBBlock(const int nMemDBKey, const int nMemSize, const int bCreateMem, char* lpszRetMesg)
	{
		char*	lpBlockMap=NULL;

		MDBClearLog();

#if (!defined(_WIN32) && !defined(__WIN32__) && !defined(WIN32) && !defined(_WIN64) && !defined(__WIN64__) && !defined(WIN64))
		int		nSemID;
		int		nPid;
		int		nShmID;
		char*	lpShmAddr;

		nShmID=shmget(nMemDBKey, nMemSize, IPC_CREAT|0666);
		if (nShmID < 0)
		{
			if (lpszRetMesg)	strcpy(lpszRetMesg, "�����ڴ��С���ԣ����ͷ��ڴ������");
			return 0;
		}

		lpBlockMap=(char*)shmat(nShmID, 0, 0);
		if (lpBlockMap == (void*)-1)
		{
			if (lpszRetMesg)	strcpy(lpszRetMesg, "�����ڴ�ӳ��������ͷ��ڴ������");
			return 0;
		}

#else
		HANDLE		hMemFile;
		char		szMemName[260];

		sprintf(szMemName, "MemDBBlock_%d", nMemDBKey);

		hMemFile=OpenFileMapping(FILE_MAP_WRITE|FILE_MAP_READ, 0, szMemName);
		if (hMemFile == NULL)
		{
			//if (!bCreateMem)
			//{
			//	MDBLog("��ȡ�ļ�ӡ��ʧ�ܣ�Key=%d Size=%d\n", nMemDBKey, nMemSize);
			//	return NULL;
			//}
			MDBLog("�����ļ�ӡ��\n");
			//		�����ļ�ӡ��
			hMemFile=CreateFileMapping(
				INVALID_HANDLE_VALUE, 
				NULL, 
				PAGE_READWRITE, 
				0, 
				nMemSize, 
				szMemName);
			if (!hMemFile)
			{
				if (lpszRetMesg)	strcpy(lpszRetMesg, "�����ļ�ӳ�����");
				MDBLog("�����ļ�ӳ�����\n");
				return 0;
			}

			//			ӳ���ڴ�ӡ���ļ�
			lpBlockMap=(char*)MapViewOfFile(
				(HANDLE)hMemFile, 
				FILE_MAP_ALL_ACCESS, 
				0, 
				0, 
				0);
			if (!lpBlockMap)
			{
				if (lpszRetMesg)	strcpy(lpszRetMesg, "ӳ���ļ�ӳ�����");
				MDBLog("ӳ���ļ�ӳ�����1\n");
				return 0;
			}
		}
		else
		{
			MDBLog("��ȡ�ļ�ӡ��\n");
			lpBlockMap=(char*)MapViewOfFile((HANDLE)hMemFile, 
				FILE_MAP_ALL_ACCESS, 
				0, 
				0, 
				0);
			if (!lpBlockMap)
			{
				if (lpszRetMesg)	strcpy(lpszRetMesg, "ӳ���ļ�ӳ�����");
				MDBLog("ӳ���ļ�ӳ�����2\n");
				return 0;
			}
		}
#endif

		//	if (lpszRetMesg)	sprintf(lpszRetMesg, "�����ڴ��С=%d ��", nMemSize/1024/1024);
		return lpBlockMap;
	}

	void Exit_MDBBlock(char* lpszBlockMap, const int nMemDBKey)
	{
#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
		UnmapViewOfFile((LPVOID)lpszBlockMap);
#else
		int		nShmID;
		int		nSize=sizeof(int);

		if ((nShmID=shmget(nMemDBKey, nSize, IPC_CREAT | 0666)) < 0)
		{
			return;
		}
		if (shmctl(nShmID, IPC_RMID, (struct shmid_ds *)NULL) < 0)
		{
			return;
		}
#endif
	}

	template<typename T>	int MDBGetTableIndex(T* pBlock, const char* lpszTable)
	{
		register int	i;
		int		nTable;

		nTable=-1;
		for (i=0; i<<pBlock->m_MDBSummary.nTableNum; i++)
		{
			if (stricmp(pBlock->m_MDBSummary.sMDBTableArray[i].szName, lpszTable) == 0)
			{
				nTable=i;
				break;
			}
		}
		return nTable;
	}

	template<typename T>	int MDBGetFieldIndex(T* pBlock, const int nTable, const char* lpszField)
	{
		register int	i;

		if (nTable < 0)
			return -1;

		for (i=0; i<pBlock->m_MDBSummary.nTableNum; i++)
		{
			if (STRICMP(pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[i].szName, lpszField) == 0)
				return i;
		}
		return -1;
	}

	void CalculateResourceId(const char* lpszString, char* lpszRetResID)
	{
		unsigned int	nKeyA, nKeyB, nKeyC, nKeyD;
		nKeyA=Hash_ELF	(lpszString);
		nKeyB=Hash_SDBM	(lpszString);
		nKeyC=Hash_AP	(lpszString);
		nKeyD=Hash_RS	(lpszString);
		sprintf(lpszRetResID, "%.8x%.8x%.8x%.8x", nKeyA, nKeyB, nKeyC, nKeyD);
	}

	const int		GetFieldCategoryNum()
	{
		return sizeof(MDBFeldCategoryStringArray)/sizeof(char*);
	}

	const char*	GetFieldCategoryName(const int nCatrgory)
	{
		return MDBFeldCategoryStringArray[nCatrgory];
	}

	const int	GetFieldCategoryValue(const char* lpszCatrgory)
	{
		register int	i;
		for (i=0; i<sizeof(MDBFeldCategoryStringArray)/sizeof(char*); i++)
		{
			if (stricmp(lpszCatrgory, MDBFeldCategoryStringArray[i]) == 0)
				return i;
		}
		return -1;
	}

}
