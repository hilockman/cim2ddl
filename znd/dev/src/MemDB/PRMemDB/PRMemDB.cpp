#include "stdafx.h"
#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
#	include <Windows.h>
#endif
#include "PRMemDB.h"
#include "PRMemDBTable.h"

namespace	PRMemDB
{
	#define _PRTEST_

	const	char*	lpszLogFile="PRMemDB.log";
	void	CPRMemDBInterface::PRMemDBClearLog()
	{
#ifdef _DEBUG
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
#endif
	}

	void	CPRMemDBInterface::PRMemDBLog(const char* pformat, ...)
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

	int CPRMemDBInterface::GetBlockSize(void) const
	{
		register int	i;

		int	nSize;

		//nSize = MAXMDBTABLENUM*sizeof(int);
		nSize = MAXMDBTABLENUM*sizeof(int)+sizeof(tagMDBBlockSummy);
		for (i=0; i<sizeof(g_PRTableDictArray)/sizeof(tagMemDBTable); i++)
			nSize += g_PRTableDictArray[i].nRecordMax*g_PRTableDictArray[i].nFieldLen;

		return nSize;
	}

	void CPRMemDBInterface::AssignBlockSummary(tagPRBlock* pPRBlock)
	{
		register int	i;
		int	nTable, nField;

		memset(&pPRBlock->m_MDBSummary, 0, sizeof(tagMDBBlockSummy));

		pPRBlock->m_MDBSummary.nTableNum=sizeof(g_PRTableDictArray)/sizeof(tagMemDBTable);

		for (nTable=0; nTable<sizeof(g_PRTableDictArray)/sizeof(tagMemDBTable); nTable++)
		{
			strcpy(pPRBlock->m_MDBSummary.sMDBTableArray[nTable].szName, g_PRTableDictArray[nTable].lpszName);
			strcpy(pPRBlock->m_MDBSummary.sMDBTableArray[nTable].szDesp, g_PRTableDictArray[nTable].lpszDesp);
			pPRBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldNum		=g_PRTableDictArray[nTable].nFieldNum;
			pPRBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen		=g_PRTableDictArray[nTable].nFieldLen;
			pPRBlock->m_MDBSummary.sMDBTableArray[nTable].nRecordMax		=g_PRTableDictArray[nTable].nRecordMax;
			pPRBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet			=g_PRTableDictArray[nTable].nOffSet;
			pPRBlock->m_MDBSummary.sMDBTableArray[nTable].nCategory		=g_PRTableDictArray[nTable].nCategory;

 			pPRBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum	=g_PRTableDictArray[nTable].sPrimaryKey.nPrimaryKeyNum;
			for (i=0; i<g_nConstMaxPrimaryKey; i++)
				pPRBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[i]	=g_PRTableDictArray[nTable].sPrimaryKey.nPrimaryKeyId[i];

			for (nField=0; nField<g_PRTableDictArray[nTable].nFieldNum; nField++)
			{
				strcpy(pPRBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].szName, g_PRTableDictArray[nTable].sFieldArray[nField].lpszName);
				strcpy(pPRBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].szDesp, g_PRTableDictArray[nTable].sFieldArray[nField].lpszDesp);
				pPRBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nCategory			=g_PRTableDictArray[nTable].sFieldArray[nField].nCategory;
				pPRBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType			=g_PRTableDictArray[nTable].sFieldArray[nField].nDataType;
				pPRBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen			=g_PRTableDictArray[nTable].sFieldArray[nField].nDataLen;
			}
		}
		for (i=0; i<g_nConstMaxTableFieldContainer; i++)
		{
			pPRBlock->m_MDBSummary.sMDBContainerArray[i].bCheckType=MDBFieldNone;
			pPRBlock->m_MDBSummary.sMDBContainerArray[i].nTable=-1;
		}
		//for (i=0; i<sizeof(g_PGFieldCheckArray)/sizeof(tagMDBContainerCheck); i++)
		//	memcpy(&pPRBlock->m_MDBSummary.sMDBContainerArray[i], &g_PGFieldCheckArray[i], sizeof(tagMDBContainerCheck));
	}

	void CPRMemDBInterface::CheckBlockValidate(const int nMemSize)
	{
		register int	i;
		int		nTable, nField, nTableLen, nTotalLen;

		for (nTable=0; nTable<sizeof(g_PRTableDictArray)/sizeof(tagMemDBTable); nTable++)
		{
			for (nField=0; nField<g_PRTableDictArray[nTable].nFieldNum; nField++)
			{
				for (i=nField+1; i<g_PRTableDictArray[nTable].nFieldNum; i++)
				{
					if (stricmp(g_PRTableDictArray[nTable].sFieldArray[nField].lpszName, g_PRTableDictArray[nTable].sFieldArray[i].lpszName) == 0)
						PRMemDBLog("          表【%s】定义错误，字段定义相同 %d, %d\n", g_PRTableDictArray[nTable].lpszDesp, nField, i);
					if (stricmp(g_PRTableDictArray[nTable].sFieldArray[nField].lpszDesp, g_PRTableDictArray[nTable].sFieldArray[i].lpszDesp) == 0)
						PRMemDBLog("          表【%s】定义错误，字段描述相同 %d, %d\n", g_PRTableDictArray[nTable].lpszDesp, nField, i);
				}
			}
			if (nTable != g_PRTableDictArray[nTable].nTable)
				PRMemDBLog("          表【%s】定义错误，表实际序号＝%d 表定义序号＝%d\n", g_PRTableDictArray[nTable].lpszDesp, nTable, g_PRTableDictArray[nTable].nTable);
			for (nField=0; nField<g_PRTableDictArray[nTable].nFieldNum; nField++)
			{
				if (nField != g_PRTableDictArray[nTable].sFieldArray[nField].nField)
					PRMemDBLog("          表【%s】字段定义错误，字段实际序号＝%d 字段定义序号＝%d\n", g_PRTableDictArray[nTable].lpszDesp, nField, g_PRTableDictArray[nTable].sFieldArray[nField].nField);
			}
		}

		nTotalLen = MAXMDBTABLENUM*sizeof(int)+sizeof(tagMDBBlockSummy);
		for (nTable=0; nTable<sizeof(g_PRTableDictArray)/sizeof(tagMemDBTable); nTable++)
		{
			if (g_PRTableDictArray[nTable].nOffSet != nTotalLen)
				PRMemDBLog("          表【%s】偏移错误，表实际偏移=%d 表定义偏移=%d\n", g_PRTableDictArray[nTable].lpszDesp, nTotalLen, g_PRTableDictArray[nTable].nOffSet);

			nTableLen=0;
			for (i=0; i<g_PRTableDictArray[nTable].nFieldNum; i++)
				nTableLen += g_PRTableDictArray[nTable].sFieldArray[i].nDataLen;

			if (nTableLen != g_PRTableDictArray[nTable].nFieldLen)
			{
				PRMemDBLog("          表【%s】长度错误，定义长度=%d 实际长度=%d\n", g_PRTableDictArray[nTable].lpszDesp, g_PRTableDictArray[nTable].nFieldLen, nTableLen);
			}
			else
			{
				PRMemDBLog("表【%s】长度正确，定义长度=%d 实际长度=%d 容量=%d 表占用空间=%.3f M(%.3f %% )\n", 
						g_PRTableDictArray[nTable].lpszDesp, g_PRTableDictArray[nTable].nFieldLen, nTableLen, g_PRTableDictArray[nTable].nRecordMax, g_PRTableDictArray[nTable].nFieldLen*g_PRTableDictArray[nTable].nRecordMax/1024.0/1024.0, 
						100.0*g_PRTableDictArray[nTable].nFieldLen*g_PRTableDictArray[nTable].nRecordMax/sizeof(tagPRBlock));
			}
			nTotalLen += g_PRTableDictArray[nTable].nFieldLen*g_PRTableDictArray[nTable].nRecordMax;
		}

		//nTotalLen += MAXMDBTABLENUM*sizeof(int);
		if (nTotalLen != sizeof(tagPRBlock))
			PRMemDBLog("          内存空间计算长度不正确，实际长度＝%d(%d)M 计算长度＝%d\n", sizeof(tagPRBlock), sizeof(tagPRBlock)/1024/1024, nTotalLen);
		else
			PRMemDBLog("内存计算空间长度正确，实际长度＝%d(%d)M 计算长度＝%d\n", sizeof(tagPRBlock), sizeof(tagPRBlock)/1024/1024, nTotalLen);

		if (nMemSize != sizeof(tagPRBlock))
			PRMemDBLog("          内存空间定义长度不正确，实际长度＝%d(%d)M 定义长度＝%d\n", sizeof(tagPRBlock), sizeof(tagPRBlock)/1024/1024, nMemSize);
		else
			PRMemDBLog("内存空间定义长度正确，实际长度＝%d(%d)M 定义长度＝%d\n", sizeof(tagPRBlock), sizeof(tagPRBlock)/1024/1024, nMemSize);
	}

	char* CPRMemDBInterface::Init_PRBlock(const int nReliableBlockKey, const int bCreateMem, const int bClearBaseLog)
	{
		char*	lpBlockMap=NULL;
		int		nMemSize=GetBlockSize();

		PRMemDBClearLog();
		if (bClearBaseLog)
			MDBClearLog();
#ifdef	_PRTEST_
		CheckBlockValidate(nMemSize);
#endif

		if (nReliableBlockKey > 0)
			lpBlockMap=MemDBBase::Init_MDBBlock(nReliableBlockKey, nMemSize, bCreateMem);
		else
			lpBlockMap=MemDBBase::Init_MDBBlock(g_nPRBlockKey, nMemSize, bCreateMem);

		if (!lpBlockMap)
			return NULL;

		AssignBlockSummary((tagPRBlock*)lpBlockMap);
		((tagPRBlock*)lpBlockMap)->m_nRecordNum[PR_SYSTEM]=1;

		return lpBlockMap;
	}

	int CPRMemDBInterface::PRGetBlockSize() const
	{
		return GetBlockSize();
	}

	void CPRMemDBInterface::Exit_PRBlock(char* lpszBlockMap, const int nReliableBlockKey)
	{
		if (nReliableBlockKey > 0)
			MemDBBase::Exit_MDBBlock(lpszBlockMap, nReliableBlockKey);
		else
			MemDBBase::Exit_MDBBlock(lpszBlockMap, g_nPRBlockKey);
	}

	int CPRMemDBInterface::PRGetFieldEnumNum(const int nTable, const int nField) const
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			if (nField >= 0 && nField < PRGetTableFieldNum(nTable))
			{
				return g_PRTableDictArray[nTable].sFieldArray[nField].nEnumNum;
			}
		}
		return 0;
	}

	int CPRMemDBInterface::PRGetFieldEnumValue(const int nTable, const int nField, const char* lpszEnumName) const
	{
		register int	i;
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			if (nField >= 0 && nField < PRGetTableFieldNum(nTable))
			{
				for (i=0; i<g_PRTableDictArray[nTable].sFieldArray[nField].nEnumNum; i++)
				{
					if (STRICMP(g_PRTableDictArray[nTable].sFieldArray[nField].pEnumArray[i].lpszEnumString, lpszEnumName) == 0)
						return i;
				}
				return -1;
			}
		}
		return -1;
	}

	const char* CPRMemDBInterface::PRGetFieldEnumString(const int nTable, const int nField, const int nEnumIndex) const 
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			if (nField >= 0 && nField < PRGetTableFieldNum(nTable))
			{
				if (nEnumIndex >= 0 && nEnumIndex < g_PRTableDictArray[nTable].sFieldArray[nField].nEnumNum)
					return g_PRTableDictArray[nTable].sFieldArray[nField].pEnumArray[nEnumIndex].lpszEnumString;
				return "";
			}
		}
		return "";
	}

	int	CPRMemDBInterface::PRGetFieldEnumStringArray(const int nTable, const int nField, int& nEnumNum, char szEnumArray[][MDB_CHARLEN]) const
	{
		register int	i;

		nEnumNum=0;
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			if (nField >= 0 && nField < PRGetTableFieldNum(nTable))
			{
				nEnumNum=g_PRTableDictArray[nTable].sFieldArray[nField].nEnumNum;
				for (i=0; i<g_PRTableDictArray[nTable].sFieldArray[nField].nEnumNum; i++)
					strcpy(szEnumArray[i], g_PRTableDictArray[nTable].sFieldArray[nField].pEnumArray[i].lpszEnumString);
				return 0;
			}
		}
		return 0;
	}

	int CPRMemDBInterface::PRGetTablePrimaryKeyNum(const int nTable) const
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
			return g_PRTableDictArray[nTable].sPrimaryKey.nPrimaryKeyNum;

		return 0;
	}

	int CPRMemDBInterface::PRGetTablePrimaryKey(const int nTable, const int nRest) const
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			if (nRest >= 0 && nRest < PRGetTablePrimaryKeyNum(nTable))
				return g_PRTableDictArray[nTable].sPrimaryKey.nPrimaryKeyId[nRest];
		}

		return -1;
	}

	int CPRMemDBInterface::PRIsFieldPrimaryKey(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			for (int nKey=0; nKey<PRGetTablePrimaryKeyNum(nTable); nKey++)
			{
				if (nField == PRGetTablePrimaryKey(nTable, nKey))
					return 1;
			}
		}

		return 0;
	}

	int CPRMemDBInterface::PRGetTableNum() const
	{
		return sizeof(g_PRTableDictArray)/sizeof(tagMemDBTable);
	}

	int CPRMemDBInterface::PRGetTableMax(const int nTable) const
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
			return g_PRTableDictArray[nTable].nRecordMax;
		return 0;
	}

	int CPRMemDBInterface::PRGetTableFieldNum(const int nTable) const
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
			return g_PRTableDictArray[nTable].nFieldNum;

		return 0;
	}

	int CPRMemDBInterface::PRGetTableIndex(const char* lpszTableName) const
	{
		register int	i;

		if (strlen(lpszTableName) <= 0)
			return -1;

		for (i=0; i<PRGetTableNum(); i++)
		{
			if (stricmp(g_PRTableDictArray[i].lpszName, lpszTableName) == 0)
				return i;
		}
		for (i=0; i<PRGetTableNum(); i++)
		{
			if (stricmp(g_PRTableDictArray[i].lpszDesp, lpszTableName) == 0)
				return i;
		}
		for (i=0; i<PRGetTableNum(); i++)
		{
			if (strlen(g_PRTableDictArray[i].lpszAlias) <= 0)
				continue;
			if (stricmp(g_PRTableDictArray[i].lpszAlias, lpszTableName) == 0)
				return i;
		}
		return -1;
	}

	int CPRMemDBInterface::PRGetFieldIndex(const int nTable, const char* lpszFieldName) const
	{
		register int	i;

		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			for (i=0; i<PRGetTableFieldNum(nTable); i++)
			{
				if (stricmp(g_PRTableDictArray[nTable].sFieldArray[i].lpszName, lpszFieldName) == 0)
					return i;
			}
			for (i=0; i<PRGetTableFieldNum(nTable); i++)
			{
				if (stricmp(g_PRTableDictArray[nTable].sFieldArray[i].lpszDesp, lpszFieldName) == 0)
					return i;
			}
		}
		return -1;
	}

	const char*	CPRMemDBInterface::PRGetTableName(const int nTable) const 
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
			return g_PRTableDictArray[nTable].lpszName;
		return "";
	}

	const char*	CPRMemDBInterface::PRGetTableDesp(const int nTable) const
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
			return g_PRTableDictArray[nTable].lpszDesp;
		return "";
	}

	int CPRMemDBInterface::PRGetTableCategory(const int nTable) const
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
			return g_PRTableDictArray[nTable].nCategory;
		return 0;
	}

	const char*	CPRMemDBInterface::PRGetFieldName(const int nTable, const int nField) const
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			if (nField >= 0 && nField < PRGetTableFieldNum(nTable))
				return g_PRTableDictArray[nTable].sFieldArray[nField].lpszName;
		}
		return "";
	}

	const char*	CPRMemDBInterface::PRGetFieldDesp(const int nTable, const int nField) const
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			if (nField >= 0 && nField < PRGetTableFieldNum(nTable))
				return g_PRTableDictArray[nTable].sFieldArray[nField].lpszDesp;
		}
		return "";
	}

	int CPRMemDBInterface::PRGetFieldLen(const int nTable, const int nField) const
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			if (nField >= 0 && nField < PRGetTableFieldNum(nTable))
				return g_PRTableDictArray[nTable].sFieldArray[nField].nDataLen;
		}
		return 0;
	}

	int CPRMemDBInterface::PRGetFieldType(const int nTable, const int nField) const
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			if (nField >= 0 && nField < PRGetTableFieldNum(nTable))
				return g_PRTableDictArray[nTable].sFieldArray[nField].nDataType;
		}
		return -1;
	}

	int CPRMemDBInterface::PRGetFieldCategory(const int nTable, const int nField) const
	{
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			if (nField >= 0 && nField < PRGetTableFieldNum(nTable))
			{
				return g_PRTableDictArray[nTable].sFieldArray[nField].nCategory;
			}
		}
		return -1;
	}

	int CPRMemDBInterface::PRGetFieldNameArray(const int nTable, char* lpszRetString) const
	{
		strcpy(lpszRetString, "");
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			strBuf.clear();

			const int nFieldNum=PRGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				if (strlen(g_PRTableDictArray[nTable].sFieldArray[nField].lpszName) > 0)
					strBuf.append(g_PRTableDictArray[nTable].sFieldArray[nField].lpszName);
				else
					strBuf.append("NULL");
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	int CPRMemDBInterface::PRGetFieldDespArray(const int nTable, char* lpszRetString) const
	{
		strcpy(lpszRetString, "");
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			strBuf.clear();

			const int nFieldNum=PRGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				if (strlen(g_PRTableDictArray[nTable].sFieldArray[nField].lpszDesp) > 0)
					strBuf.append(g_PRTableDictArray[nTable].sFieldArray[nField].lpszDesp);
				else
					strBuf.append("NULL");
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}


	int CPRMemDBInterface::PRGetFieldCategoryArray(const int nTable, char* lpszRetString) const
	{
		strcpy(lpszRetString, "");
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			char		szBuf[260];
			strBuf.clear();

			const int nFieldNum=PRGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				sprintf(szBuf, "%d", g_PRTableDictArray[nTable].sFieldArray[nField].nCategory);
				strBuf.append(szBuf);
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	int CPRMemDBInterface::PRGetFieldTypeArray(const int nTable, char* lpszRetString) const
	{
		strcpy(lpszRetString, "");
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			char		szBuf[260];
			strBuf.clear();

			const int nFieldNum=PRGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				sprintf(szBuf, "%d", g_PRTableDictArray[nTable].sFieldArray[nField].nDataType);
				strBuf.append(szBuf);
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	int CPRMemDBInterface::PRGetFieldLenArray(const int nTable, char* lpszRetString) const
	{
		strcpy(lpszRetString, "");
		if (nTable >= 0 && nTable < PRGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			char		szBuf[260];
			strBuf.clear();

			const int nFieldNum=PRGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				sprintf(szBuf, "%d", g_PRTableDictArray[nTable].sFieldArray[nField].nDataLen);
				strBuf.append(szBuf);
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	int CPRMemDBInterface::PRGetFieldCategoryNum() const
	{
		return sizeof(MDBFeldCategoryStringArray)/sizeof(char*);
	}

	const char*	CPRMemDBInterface::PRGetFieldCategoryName(const int nCatrgory) const
	{
		return MDBFeldCategoryStringArray[nCatrgory];
	}

	int CPRMemDBInterface::PRGetFieldCategoryValue(const char* lpszCatrgory) const
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
