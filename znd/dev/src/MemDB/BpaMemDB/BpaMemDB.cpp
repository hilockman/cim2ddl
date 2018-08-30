#include "stdafx.h"
#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
#	include <Windows.h>
#endif
#include "BpaMemDB.h"
#include "BpaMemDBTable.h"
#include "BpaMemDBExtern.h"

#define _BPAMDBTEST_
namespace	BpaMemDB
{
	const	char*	g_lpszLogFile="BpaMemDB.log";
	void	ErrorMessage()
	{
		// Retrieve the system error message for the last-error code
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
	}

	static	int getBlockSize(void)
	{
		register int	i;

		int	nSize;

		//nSize=MAXMDBTABLENUM*sizeof(int);
		nSize=MAXMDBTABLENUM*sizeof(int)+sizeof(tagMDBBlockSummy);
		for (i=0; i<sizeof(g_BpaTableDictArray)/sizeof(tagMemDBTable); i++)
		{
			nSize += g_BpaTableDictArray[i].nRecordMax*g_BpaTableDictArray[i].nFieldLen;
		}

		return nSize;
	}

	void assignBlockSummary(tagBpaBlock* pBlock)
	{
		register int	i;
		int	nTable, nField;

		memset(&pBlock->m_MDBSummary, 0, sizeof(tagMDBBlockSummy));

		pBlock->m_MDBSummary.nTableNum=sizeof(g_BpaTableDictArray)/sizeof(tagMemDBTable);
		for (nTable=0; nTable<sizeof(g_BpaTableDictArray)/sizeof(tagMemDBTable); nTable++)
		{
			strcpy(pBlock->m_MDBSummary.sMDBTableArray[nTable].szName, g_BpaTableDictArray[nTable].lpszName);
			strcpy(pBlock->m_MDBSummary.sMDBTableArray[nTable].szDesp, g_BpaTableDictArray[nTable].lpszDesp);
			pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldNum		=g_BpaTableDictArray[nTable].nFieldNum;
			pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen		=g_BpaTableDictArray[nTable].nFieldLen;
			pBlock->m_MDBSummary.sMDBTableArray[nTable].nRecordMax		=g_BpaTableDictArray[nTable].nRecordMax;
			pBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet			=g_BpaTableDictArray[nTable].nOffSet;
			pBlock->m_MDBSummary.sMDBTableArray[nTable].nCategory		=g_BpaTableDictArray[nTable].nCategory;

			pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum	=g_BpaTableDictArray[nTable].sPrimaryKey.nPrimaryKeyNum;
			for (i=0; i<g_nConstMaxPrimaryKey; i++)
				pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[i]	=g_BpaTableDictArray[nTable].sPrimaryKey.nPrimaryKeyId[i];

			for (nField=0; nField<g_BpaTableDictArray[nTable].nFieldNum; nField++)
			{
				strcpy(pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].szName, g_BpaTableDictArray[nTable].sFieldArray[nField].lpszName);
				strcpy(pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].szDesp, g_BpaTableDictArray[nTable].sFieldArray[nField].lpszDesp);
				pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nCategory			=g_BpaTableDictArray[nTable].sFieldArray[nField].nCategory;
				pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType			=g_BpaTableDictArray[nTable].sFieldArray[nField].nDataType;
				pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen			=g_BpaTableDictArray[nTable].sFieldArray[nField].nDataLen;
			}
		}
		for (i=0; i<g_nConstMaxTableFieldContainer; i++)
		{
			pBlock->m_MDBSummary.sMDBContainerArray[i].bCheckType=MDBFieldNone;
			pBlock->m_MDBSummary.sMDBContainerArray[i].nTable=-1;
		}
	}

	void checkBlockValidate(const int nMemSize)
	{
		register int	i;
		int		nTable, nField, nTableLen, nTotalLen;

		nTotalLen = MAXMDBTABLENUM*sizeof(int)+sizeof(tagMDBBlockSummy);
		for (nTable=0; nTable<sizeof(g_BpaTableDictArray)/sizeof(tagMemDBTable); nTable++)
		{
			for (nField=0; nField<g_BpaTableDictArray[nTable].nFieldNum; nField++)
			{
				for (i=nField+1; i<g_BpaTableDictArray[nTable].nFieldNum; i++)
				{
					if (stricmp(g_BpaTableDictArray[nTable].sFieldArray[nField].lpszName, g_BpaTableDictArray[nTable].sFieldArray[i].lpszName) == 0)
					{
						Log(g_lpszLogFile, "          表【%s】定义错误，字段定义相同 %d, %d\n", g_BpaTableDictArray[nTable].lpszDesp, nField, i);
					}
					//if (stricmp(g_BpaTableDictArray[nTable].sFieldArray[nField].szDesp, g_BpaTableDictArray[nTable].sFieldArray[i].szDesp) == 0)
					//{
					//	Log(g_lpszLogFile, "          表【%s】定义错误，字段描述相同 %d, %d\n", g_BpaTableDictArray[nTable].szDesp, nField, i);
					//}
				}
			}
			if (g_BpaTableDictArray[nTable].nOffSet != nTotalLen)
			{
				Log(g_lpszLogFile, "          表【%s】偏移错误，表实际偏移=%d 表定义偏移=%d\n", g_BpaTableDictArray[nTable].lpszDesp, nTotalLen, g_BpaTableDictArray[nTable].nOffSet);
			}
			if (nTable != g_BpaTableDictArray[nTable].nTable)
			{
				Log(g_lpszLogFile, "          表【%s】定义错误，表实际序号=%d 表定义序号=%d\n", g_BpaTableDictArray[nTable].lpszDesp, nTable, g_BpaTableDictArray[nTable].nTable);
			}
			for (nField=0; nField<g_BpaTableDictArray[nTable].nFieldNum; nField++)
			{
				if (nField != g_BpaTableDictArray[nTable].sFieldArray[nField].nField)
				{
					Log(g_lpszLogFile, "          表【%s】字段定义错误，字段实际序号=%d 字段定义序号=%d\n", g_BpaTableDictArray[nTable].lpszDesp, nField, g_BpaTableDictArray[nTable].sFieldArray[nField].nField);
				}
			}

			nTableLen=0;
			for (i=0; i<g_BpaTableDictArray[nTable].nFieldNum; i++)
			{
				nTableLen += g_BpaTableDictArray[nTable].sFieldArray[i].nDataLen;
			}

			if (nTableLen != g_BpaTableDictArray[nTable].nFieldLen)
			{
				Log(g_lpszLogFile, "          表【%s】长度错误，定义长度=%d 实际长度=%d\n",
						g_BpaTableDictArray[nTable].lpszDesp, g_BpaTableDictArray[nTable].nFieldLen, nTableLen);
			}
			else
			{
				Log(g_lpszLogFile, "表【%s】长度正确，定义长度=%d 实际长度=%d 容量=%d 表占用空间=%.3f M(%.3f %% )\n",
						g_BpaTableDictArray[nTable].lpszDesp,
						g_BpaTableDictArray[nTable].nFieldLen,
						nTableLen,
						g_BpaTableDictArray[nTable].nRecordMax,
						g_BpaTableDictArray[nTable].nFieldLen*g_BpaTableDictArray[nTable].nRecordMax/1024.0/1024.0,
						100.0*g_BpaTableDictArray[nTable].nFieldLen*g_BpaTableDictArray[nTable].nRecordMax/sizeof(tagBpaBlock));
			}
			nTotalLen += g_BpaTableDictArray[nTable].nFieldLen*g_BpaTableDictArray[nTable].nRecordMax;

		}

		if (nTotalLen != sizeof(tagBpaBlock))
		{
			Log(g_lpszLogFile, "          内存空间计算长度不正确，实际长度＝%d 计算长度＝%d\n", sizeof(tagBpaBlock), nTotalLen);
		}
		else
		{
			Log(g_lpszLogFile, "内存计算空间长度正确，实际长度＝%d (%d)M 计算长度＝%d\n", sizeof(tagBpaBlock), sizeof(tagBpaBlock)/1024/1024, nTotalLen);
		}

		if (nMemSize != sizeof(tagBpaBlock))
		{
			Log(g_lpszLogFile, "          内存空间定义长度不正确，实际长度＝%d 定义长度＝%d\n", sizeof(tagBpaBlock), nMemSize);
		}
		else
		{
			Log(g_lpszLogFile, "内存空间定义长度正确，实际长度＝%d (%d)M 定义长度＝%d\n", sizeof(tagBpaBlock), sizeof(tagBpaBlock)/1024/1024, nMemSize);
		}
	}

	char* Init_BpaBlock(const int nBpaBlockKey, const int bCreateMem, const int bClearBaseLog)
	{
		char*	lpBlockMap;
		int		nMemSize=getBlockSize();

		ClearLog(g_lpszLogFile);
		if (bClearBaseLog)
			MDBClearLog();

		BpaMaintDict();

#ifdef	_BPAMDBTEST_
		checkBlockValidate(nMemSize);
#endif

		if (nBpaBlockKey > 0)
			lpBlockMap=MemDBBase::Init_MDBBlock(nBpaBlockKey, nMemSize, bCreateMem);
		else
			lpBlockMap=MemDBBase::Init_MDBBlock(g_nBpaBlockKey, nMemSize, bCreateMem);

		if (!lpBlockMap)
			return NULL;

		assignBlockSummary((tagBpaBlock*)lpBlockMap);
		((tagBpaBlock*)lpBlockMap)->m_nRecordNum[BPA_DAT_CASE]=1;
		((tagBpaBlock*)lpBlockMap)->m_nRecordNum[BPA_SWI_CASE]=1;

		return lpBlockMap;
	}

	void Exit_BpaBlock(char* lpszBlockMap, const int nBpaBlockKey)
	{
		if (nBpaBlockKey > 0)
			MemDBBase::Exit_MDBBlock(lpszBlockMap, nBpaBlockKey);
		else
			MemDBBase::Exit_MDBBlock(lpszBlockMap, g_nBpaBlockKey);
	}

	int		BpaGetFieldEnumNum(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nField >= 0 && nField < BpaGetTableFieldNum(nTable))
			{
				return g_BpaTableDictArray[nTable].sFieldArray[nField].nEnumNum;
			}
		}
		return 0;
	}

	int BpaGetFieldEnumValue(const int nTable, const int nField, const char* lpszEnumName)
	{
		register int	i;
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nField >= 0 && nField < BpaGetTableFieldNum(nTable))
			{
				for (i=0; i<g_BpaTableDictArray[nTable].sFieldArray[nField].nEnumNum; i++)
				{
					if (STRICMP(g_BpaTableDictArray[nTable].sFieldArray[nField].pEnumArray[i].lpszEnumString, lpszEnumName) == 0)
						return i;
				}
			}
		}
		return -1;
	}

	int	BpaGetFieldEnumString(const int nTable, const int nField, const int nEnumIndex, char* lpszRetString)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nField >= 0 && nField < BpaGetTableFieldNum(nTable))
			{
				if (nEnumIndex >= 0 && nEnumIndex < g_BpaTableDictArray[nTable].sFieldArray[nField].nEnumNum)
				{
					strcpy(lpszRetString, g_BpaTableDictArray[nTable].sFieldArray[nField].pEnumArray[nEnumIndex].lpszEnumString);
					return 1;
				}
			}
		}
		return 0;
	}

	const char*	BpaGetFieldEnumString(const int nTable, const int nField, const int nEnumIndex)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nField >= 0 && nField < BpaGetTableFieldNum(nTable))
			{
				if (nEnumIndex >= 0 && nEnumIndex < g_BpaTableDictArray[nTable].sFieldArray[nField].nEnumNum)
					return g_BpaTableDictArray[nTable].sFieldArray[nField].pEnumArray[nEnumIndex].lpszEnumString;
			}
		}
		return "";
	}

	int		BpaGetFieldEnumStringArray(const int nTable, const int nField, int& nEnumNum, char szEnumArray[][MDB_CHARLEN])
	{
		register int	i;

		nEnumNum=0;
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nField >= 0 && nField < BpaGetTableFieldNum(nTable))
			{
				nEnumNum=g_BpaTableDictArray[nTable].sFieldArray[nField].nEnumNum;
				for (i=0; i<g_BpaTableDictArray[nTable].sFieldArray[nField].nEnumNum; i++)
				{
					strcpy(szEnumArray[i], g_BpaTableDictArray[nTable].sFieldArray[nField].pEnumArray[i].lpszEnumString);
				}
			}
		}
		return 0;
	}

	int		BpaGetTablePrimaryKeyNum(const int nTable)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
			return g_BpaTableDictArray[nTable].sPrimaryKey.nPrimaryKeyNum;

		return 0;
	}

	int		BpaGetTablePrimaryKey(const int nTable, const int nRest)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nRest >= 0 && nRest < BpaGetTablePrimaryKeyNum(nTable))
			{
				return g_BpaTableDictArray[nTable].sPrimaryKey.nPrimaryKeyId[nRest];
			}
		}

		return -1;
	}

	int		BpaGetTableNum()
	{
		return sizeof(g_BpaTableDictArray)/sizeof(tagMemDBTable);
	}

	int		BpaGetTableMax(const int nTable)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			return g_BpaTableDictArray[nTable].nRecordMax;
		}
		return 0;
	}

	int		BpaGetTableFieldNum(const int nTable)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
			return g_BpaTableDictArray[nTable].nFieldNum;

		return 0;
	}

	int		BpaGetTableIndex(const char* lpszTableName)
	{
		register int	i;

		//Log(g_lpszLogFile, "BpaGetTableIndex=%s\n", lpszTableName);

		for (i=0; i<BpaGetTableNum(); i++)
		{
			if (stricmp(g_BpaTableDictArray[i].lpszName, lpszTableName) == 0)
				return i;
		}
		for (i=0; i<BpaGetTableNum(); i++)
		{
			if (stricmp(g_BpaTableDictArray[i].lpszDesp, lpszTableName) == 0)
				return i;
		}
		for (i=0; i<BpaGetTableNum(); i++)
		{
			if (strlen(g_BpaTableDictArray[i].lpszAlias) <= 0)
				continue;
			if (stricmp(g_BpaTableDictArray[i].lpszAlias, lpszTableName) == 0)
				return i;
		}
		return -1;
	}

	int		BpaGetFieldIndex(const int nTable, const char* lpszFieldName)
	{
		register int	i;

		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			for (i=0; i<BpaGetTableFieldNum(nTable); i++)
			{
				if (stricmp(g_BpaTableDictArray[nTable].sFieldArray[i].lpszName, lpszFieldName) == 0)
					return i;
			}
			for (i=0; i<BpaGetTableFieldNum(nTable); i++)
			{
				if (stricmp(g_BpaTableDictArray[nTable].sFieldArray[i].lpszDesp, lpszFieldName) == 0)
					return i;
			}
		}
		return -1;
	}

	int	BpaGetTableName(const int nTable, char* lpszRetString)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			strcpy(lpszRetString, g_BpaTableDictArray[nTable].lpszName);
			return 1;
		}
		return 0;
	}

	int	BpaGetTableDesp(const int nTable, char* lpszRetString)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			strcpy(lpszRetString, g_BpaTableDictArray[nTable].lpszDesp);
			return 1;
		}
		return 0;
	}

	const char*	BpaGetTableName(const int nTable)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
			return g_BpaTableDictArray[nTable].lpszName;
		return "";
	}

	const char*	BpaGetTableDesp(const int nTable)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
			return g_BpaTableDictArray[nTable].lpszDesp;
		return "";
	}

	int	BpaGetTableCategory(const int nTable)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
			return g_BpaTableDictArray[nTable].nCategory;
		return 0;
	}

	int	BpaGetFieldName(const int nTable, const int nField, char* lpszRetString)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nField >= 0 && nField < BpaGetTableFieldNum(nTable))
			{
				strcpy(lpszRetString, g_BpaTableDictArray[nTable].sFieldArray[nField].lpszName);
				return 1;
			}
		}
		return 0;
	}

	int	BpaGetFieldDesp(const int nTable, const int nField, char* lpszRetString)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nField >= 0 && nField < BpaGetTableFieldNum(nTable))
			{
				strcpy(lpszRetString, g_BpaTableDictArray[nTable].sFieldArray[nField].lpszDesp);
				return 1;
			}
		}
		return 0;
	}

	const char*	BpaGetFieldName(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nField >= 0 && nField < BpaGetTableFieldNum(nTable))
			{
				return g_BpaTableDictArray[nTable].sFieldArray[nField].lpszName;
			}
		}
		return "";
	}

	const char*	BpaGetFieldDesp(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nField >= 0 && nField < BpaGetTableFieldNum(nTable))
			{
				return g_BpaTableDictArray[nTable].sFieldArray[nField].lpszDesp;
			}
		}
		return "";
	}

	int	BpaGetFieldLen(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nField >= 0 && nField < BpaGetTableFieldNum(nTable))
			{
				return g_BpaTableDictArray[nTable].sFieldArray[nField].nDataLen;
			}
		}
		return 0;
	}

	int	BpaGetFieldType(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nField >= 0 && nField < BpaGetTableFieldNum(nTable))
			{
				return g_BpaTableDictArray[nTable].sFieldArray[nField].nDataType;
			}
		}
		return -1;
	}

	int	BpaGetFieldCategory(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			if (nField >= 0 && nField < BpaGetTableFieldNum(nTable))
			{
				return g_BpaTableDictArray[nTable].sFieldArray[nField].nCategory;
			}
		}
		return -1;
	}

	int	BpaGetFieldNameArray(const int nTable, char* lpszRetString)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			strBuf.clear();

			const int nFieldNum=BpaGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				if (strlen(g_BpaTableDictArray[nTable].sFieldArray[nField].lpszName) > 0)
					strBuf.append(g_BpaTableDictArray[nTable].sFieldArray[nField].lpszName);
				else
					strBuf.append("NULL");
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	int	BpaGetFieldDespArray(const int nTable, char* lpszRetString)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			strBuf.clear();

			const int nFieldNum=BpaGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				if (strlen(g_BpaTableDictArray[nTable].sFieldArray[nField].lpszDesp) > 0)
					strBuf.append(g_BpaTableDictArray[nTable].sFieldArray[nField].lpszDesp);
				else
					strBuf.append("NULL");
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	int	BpaGetFieldCategoryArray(const int nTable, char* lpszRetString)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			char		szBuf[260];
			strBuf.clear();

			const int nFieldNum=BpaGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				sprintf(szBuf, "%d", g_BpaTableDictArray[nTable].sFieldArray[nField].nCategory);
				strBuf.append(szBuf);
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	int	BpaGetFieldTypeArray(const int nTable, char* lpszRetString)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			char		szBuf[260];
			strBuf.clear();

			const int nFieldNum=BpaGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				sprintf(szBuf, "%d", g_BpaTableDictArray[nTable].sFieldArray[nField].nDataType);
				strBuf.append(szBuf);
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	int	BpaGetFieldLenArray(const int nTable, char* lpszRetString)
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			char		szBuf[260];
			strBuf.clear();

			const int nFieldNum=BpaGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				sprintf(szBuf, "%d", g_BpaTableDictArray[nTable].sFieldArray[nField].nDataLen);
				strBuf.append(szBuf);
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	const int	BpaGetFieldCategoryNum()
	{
		return sizeof(MDBFeldCategoryStringArray)/sizeof(char*);
	}

	const char*	BpaGetFieldCategoryName(const int nCatrgory)
	{
		return MDBFeldCategoryStringArray[nCatrgory];
	}

	const int	BpaGetFieldCategoryValue(const char* lpszCatrgory)
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
