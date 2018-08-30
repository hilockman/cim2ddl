#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBTable.h"
#include "PGMemDBExtern.h"

namespace	PGMemDB
{
	#define _PGTEST_

	int getBlockSize(void)
	{
		register int	i;

		int	nSize;

		//nSize = MAXMDBTABLENUM*sizeof(int);
		nSize = MAXMDBTABLENUM*sizeof(int)+sizeof(tagMDBBlockSummy);
		for (i=0; i<sizeof(g_PGTableDictArray)/sizeof(tagMemDBTable); i++)
		{
			nSize += g_PGTableDictArray[i].nRecordMax*g_PGTableDictArray[i].nFieldLen;
		}

		return nSize;
	}

	void assignBlockSummary(tagPGBlock* pPGBlock)
	{
		register int	i;
		int	nTable, nField;

		memset(&pPGBlock->m_MDBSummary, 0, sizeof(tagMDBBlockSummy));

		pPGBlock->m_MDBSummary.nTableNum=sizeof(g_PGTableDictArray)/sizeof(tagMemDBTable);

		for (nTable=0; nTable<sizeof(g_PGTableDictArray)/sizeof(tagMemDBTable); nTable++)
		{
			strcpy(pPGBlock->m_MDBSummary.sMDBTableArray[nTable].szName, g_PGTableDictArray[nTable].lpszName);
			strcpy(pPGBlock->m_MDBSummary.sMDBTableArray[nTable].szDesp, g_PGTableDictArray[nTable].lpszDesp);
			pPGBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldNum		=g_PGTableDictArray[nTable].nFieldNum;
			pPGBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen		=g_PGTableDictArray[nTable].nFieldLen;
			pPGBlock->m_MDBSummary.sMDBTableArray[nTable].nRecordMax		=g_PGTableDictArray[nTable].nRecordMax;
			pPGBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet			=g_PGTableDictArray[nTable].nOffSet;
			pPGBlock->m_MDBSummary.sMDBTableArray[nTable].nCategory		=g_PGTableDictArray[nTable].nCategory;

 			pPGBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum	=g_PGTableDictArray[nTable].sPrimaryKey.nPrimaryKeyNum;
			for (i=0; i<g_nConstMaxPrimaryKey; i++)
				pPGBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[i]	=g_PGTableDictArray[nTable].sPrimaryKey.nPrimaryKeyId[i];

			for (nField=0; nField<g_PGTableDictArray[nTable].nFieldNum; nField++)
			{
				strcpy(pPGBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].szName, g_PGTableDictArray[nTable].sFieldArray[nField].lpszName);
				strcpy(pPGBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].szDesp, g_PGTableDictArray[nTable].sFieldArray[nField].lpszDesp);
				pPGBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nCategory			=g_PGTableDictArray[nTable].sFieldArray[nField].nCategory;
				pPGBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType			=g_PGTableDictArray[nTable].sFieldArray[nField].nDataType;
				pPGBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen			=g_PGTableDictArray[nTable].sFieldArray[nField].nDataLen;
			}
		}
		for (i=0; i<g_nConstMaxTableFieldContainer; i++)
		{
			pPGBlock->m_MDBSummary.sMDBContainerArray[i].bCheckType=MDBFieldNone;
			pPGBlock->m_MDBSummary.sMDBContainerArray[i].nTable=-1;
		}
		for (i=0; i<sizeof(g_PGTableFieldContainerArray)/sizeof(tagMDBTableFieldContainer); i++)
			memcpy(&pPGBlock->m_MDBSummary.sMDBContainerArray[i], &g_PGTableFieldContainerArray[i], sizeof(tagMDBTableFieldContainer));
	}

	void checkBlockValidate(const int nMemSize)
	{
		register int	i;
		int		nTable, nField, nTableLen, nTotalLen;

		for (nTable=0; nTable<sizeof(g_PGTableDictArray)/sizeof(tagMemDBTable); nTable++)
		{
			for (nField=0; nField<g_PGTableDictArray[nTable].nFieldNum; nField++)
			{
				for (i=nField+1; i<g_PGTableDictArray[nTable].nFieldNum; i++)
				{
					if (stricmp(g_PGTableDictArray[nTable].sFieldArray[nField].lpszName, g_PGTableDictArray[nTable].sFieldArray[i].lpszName) == 0)
					{
						Log(m_lpszPGMemDBLogFile, "          表【%s】定义错误，字段定义相同 %d, %d\n", g_PGTableDictArray[nTable].lpszDesp, nField, i);
					}
					if (stricmp(g_PGTableDictArray[nTable].sFieldArray[nField].lpszDesp, g_PGTableDictArray[nTable].sFieldArray[i].lpszDesp) == 0)
					{
						Log(m_lpszPGMemDBLogFile, "          表【%s】定义错误，字段描述相同 %d, %d\n", g_PGTableDictArray[nTable].lpszDesp, nField, i);
					}
				}
			}
			if (nTable != g_PGTableDictArray[nTable].nTable)
			{
				Log(m_lpszPGMemDBLogFile, "          表【%s】定义错误，表实际序号＝%d 表定义序号＝%d\n", g_PGTableDictArray[nTable].lpszDesp, nTable, g_PGTableDictArray[nTable].nTable);
			}
			for (nField=0; nField<g_PGTableDictArray[nTable].nFieldNum; nField++)
			{
				if (nField != g_PGTableDictArray[nTable].sFieldArray[nField].nField)
				{
					Log(m_lpszPGMemDBLogFile, "          表【%s】字段定义错误，字段实际序号＝%d 字段定义序号＝%d\n", g_PGTableDictArray[nTable].lpszDesp, nField, g_PGTableDictArray[nTable].sFieldArray[nField].nField);
				}
			}
		}

		nTotalLen = MAXMDBTABLENUM*sizeof(int)+sizeof(tagMDBBlockSummy);
		for (nTable=0; nTable<sizeof(g_PGTableDictArray)/sizeof(tagMemDBTable); nTable++)
		{
			if (g_PGTableDictArray[nTable].nOffSet != nTotalLen)
			{
				Log(m_lpszPGMemDBLogFile, "          表【%s】偏移错误，表实际偏移=%d 表定义偏移=%d\n", g_PGTableDictArray[nTable].lpszDesp, nTotalLen, g_PGTableDictArray[nTable].nOffSet);
			}
			nTableLen=0;
			for (i=0; i<g_PGTableDictArray[nTable].nFieldNum; i++)
			{
				nTableLen += g_PGTableDictArray[nTable].sFieldArray[i].nDataLen;
			}

			if (nTableLen != g_PGTableDictArray[nTable].nFieldLen)
			{
				Log(m_lpszPGMemDBLogFile, "          表【%s】长度错误，定义长度=%d 实际长度=%d\n", g_PGTableDictArray[nTable].lpszDesp, g_PGTableDictArray[nTable].nFieldLen, nTableLen);
			}
			else
			{
				Log(m_lpszPGMemDBLogFile, "表【%s】长度正确，定义长度=%d 实际长度=%d 容量=%d 表占用空间=%.3f M(%.3f %% )\n", 
						g_PGTableDictArray[nTable].lpszDesp, g_PGTableDictArray[nTable].nFieldLen, nTableLen, g_PGTableDictArray[nTable].nRecordMax, g_PGTableDictArray[nTable].nFieldLen*g_PGTableDictArray[nTable].nRecordMax/1024.0/1024.0, 
						100.0*g_PGTableDictArray[nTable].nFieldLen*g_PGTableDictArray[nTable].nRecordMax/sizeof(tagPGBlock));
			}
			nTotalLen += g_PGTableDictArray[nTable].nFieldLen*g_PGTableDictArray[nTable].nRecordMax;
		}

		//nTotalLen += MAXMDBTABLENUM*sizeof(int);
		if (nTotalLen != sizeof(tagPGBlock))
		{
			Log(m_lpszPGMemDBLogFile, "          内存空间计算长度不正确，实际长度＝%d 计算长度＝%d\n", sizeof(tagPGBlock), nTotalLen);
		}
		else
		{
			Log(m_lpszPGMemDBLogFile, "内存计算空间长度正确，实际长度＝%d (%d)M 计算长度＝%d\n", sizeof(tagPGBlock), sizeof(tagPGBlock)/1024/1024, nTotalLen);
		}

		if (nMemSize != sizeof(tagPGBlock))
		{
			Log(m_lpszPGMemDBLogFile, "          内存空间定义长度不正确，实际长度＝%d 定义长度＝%d\n", sizeof(tagPGBlock), nMemSize);
		}
		else
		{
			Log(m_lpszPGMemDBLogFile, "内存空间定义长度正确，实际长度＝%d (%d)M 定义长度＝%d\n", sizeof(tagPGBlock), sizeof(tagPGBlock)/1024/1024, nMemSize);
		}

	}

	char* Init_PGBlock(const int nPGBlockKey, const int bCreateMem, const int bClearBaseLog)
	{
		char*	lpBlockMap=NULL;
		int		nMemSize=getBlockSize();

		ClearLog(m_lpszPGMemDBLogFile);
		if (bClearBaseLog)
			MDBClearLog();
#ifdef	_PGTEST_
		checkBlockValidate(nMemSize);
#endif

		if (nPGBlockKey > 0)
			lpBlockMap=MemDBBase::Init_MDBBlock(nPGBlockKey, nMemSize, bCreateMem);
		else
			lpBlockMap=MemDBBase::Init_MDBBlock(g_nPGBlockKey, nMemSize, bCreateMem);

		if (!lpBlockMap)
			return NULL;

		assignBlockSummary((tagPGBlock*)lpBlockMap);
		((tagPGBlock*)lpBlockMap)->m_nRecordNum[PG_SYSTEM]=1;

		return lpBlockMap;
	}

	void Exit_PGBlock(char* lpszBlockMap, const int nPGBlockKey)
	{
		if (nPGBlockKey > 0)
			MemDBBase::Exit_MDBBlock(lpszBlockMap, nPGBlockKey);
		else
			MemDBBase::Exit_MDBBlock(lpszBlockMap, g_nPGBlockKey);
	}

	int		PGGetFieldEnumNum(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			if (nField >= 0 && nField < PGGetTableFieldNum(nTable))
			{
				return g_PGTableDictArray[nTable].sFieldArray[nField].nEnumNum;
			}
		}
		return 0;
	}

	int PGGetFieldEnumValue(const int nTable, const int nField, const char* lpszEnumName)
	{
		register int	i;
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			if (nField >= 0 && nField < PGGetTableFieldNum(nTable))
			{
				for (i=0; i<g_PGTableDictArray[nTable].sFieldArray[nField].nEnumNum; i++)
				{
					if (STRICMP(g_PGTableDictArray[nTable].sFieldArray[nField].pEnumArray[i].lpszEnumString, lpszEnumName) == 0)
						return i;
				}
			}
		}
		return -1;
	}

	const char* PGGetFieldEnumString(const int nTable, const int nField, const int nEnumIndex)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			if (nField >= 0 && nField < PGGetTableFieldNum(nTable))
			{
				if (nEnumIndex >= 0 && nEnumIndex < g_PGTableDictArray[nTable].sFieldArray[nField].nEnumNum)
					return g_PGTableDictArray[nTable].sFieldArray[nField].pEnumArray[nEnumIndex].lpszEnumString;
			}
		}
		return "";
	}

	int	PGGetFieldEnumStringArray(const int nTable, const int nField, int& nEnumNum, char szEnumArray[][MDB_CHARLEN])
	{
		register int	i;

		nEnumNum=0;
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			if (nField >= 0 && nField < PGGetTableFieldNum(nTable))
			{
				nEnumNum=g_PGTableDictArray[nTable].sFieldArray[nField].nEnumNum;
				for (i=0; i<g_PGTableDictArray[nTable].sFieldArray[nField].nEnumNum; i++)
					strcpy(szEnumArray[i], g_PGTableDictArray[nTable].sFieldArray[nField].pEnumArray[i].lpszEnumString);
			}
		}
		return 0;
	}

	int		PGGetTablePrimaryKeyNum(const int nTable)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
			return g_PGTableDictArray[nTable].sPrimaryKey.nPrimaryKeyNum;

		return 0;
	}

	int		PGGetTablePrimaryKey(const int nTable, const int nRest)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			if (nRest >= 0 && nRest < PGGetTablePrimaryKeyNum(nTable))
				return g_PGTableDictArray[nTable].sPrimaryKey.nPrimaryKeyId[nRest];
		}

		return -1;
	}

	const int PGIsFieldPrimaryKey(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			for (int nKey=0; nKey<PGGetTablePrimaryKeyNum(nTable); nKey++)
			{
				if (nField == PGGetTablePrimaryKey(nTable, nKey))
					return 1;
			}
		}

		return 0;
	}

	int		PGGetTableNum()
	{
		return sizeof(g_PGTableDictArray)/sizeof(tagMemDBTable);
	}

	int		PGGetTableMax(const int nTable)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
			return g_PGTableDictArray[nTable].nRecordMax;
		return 0;
	}

	int		PGGetTableFieldNum(const int nTable)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
			return g_PGTableDictArray[nTable].nFieldNum;

		return 0;
	}

	int		PGGetTableIndex(const char* lpszTableName)
	{
		register int	i;

		for (i=0; i<PGGetTableNum(); i++)
		{
			if (stricmp(g_PGTableDictArray[i].lpszName, lpszTableName) == 0)
				return i;
		}
		for (i=0; i<PGGetTableNum(); i++)
		{
			if (stricmp(g_PGTableDictArray[i].lpszDesp, lpszTableName) == 0)
				return i;
		}
		for (i=0; i<PGGetTableNum(); i++)
		{
			if (strlen(g_PGTableDictArray[i].lpszAlias) <= 0)
				continue;
			if (stricmp(g_PGTableDictArray[i].lpszAlias, lpszTableName) == 0)
				return i;
		}
		return -1;
	}

	int		PGGetFieldIndex(const int nTable, const char* lpszFieldName)
	{
		register int	i;

		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			for (i=0; i<PGGetTableFieldNum(nTable); i++)
			{
				if (stricmp(g_PGTableDictArray[nTable].sFieldArray[i].lpszName, lpszFieldName) == 0)
					return i;
			}
			for (i=0; i<PGGetTableFieldNum(nTable); i++)
			{
				if (stricmp(g_PGTableDictArray[nTable].sFieldArray[i].lpszDesp, lpszFieldName) == 0)
					return i;
			}
		}
		return -1;
	}

	const char*	PGGetTableName(const int nTable)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
			return g_PGTableDictArray[nTable].lpszName;
		return "";
	}

	const char*	PGGetTableDesp(const int nTable)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
			return g_PGTableDictArray[nTable].lpszDesp;
		return "";
	}

	int	PGGetTableCategory(const int nTable)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
			return g_PGTableDictArray[nTable].nCategory;
		return 0;
	}

	const char*	PGGetFieldName(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			if (nField >= 0 && nField < PGGetTableFieldNum(nTable))
				return g_PGTableDictArray[nTable].sFieldArray[nField].lpszName;
		}
		return "";
	}

	const char*	PGGetFieldDesp(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			if (nField >= 0 && nField < PGGetTableFieldNum(nTable))
				return g_PGTableDictArray[nTable].sFieldArray[nField].lpszDesp;
		}
		return "";
	}

	int	PGGetFieldLen(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			if (nField >= 0 && nField < PGGetTableFieldNum(nTable))
				return g_PGTableDictArray[nTable].sFieldArray[nField].nDataLen;
		}
		return 0;
	}

	int	PGGetFieldType(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			if (nField >= 0 && nField < PGGetTableFieldNum(nTable))
				return g_PGTableDictArray[nTable].sFieldArray[nField].nDataType;
		}
		return -1;
	}

	int	PGGetFieldCategory(const int nTable, const int nField)
	{
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			if (nField >= 0 && nField < PGGetTableFieldNum(nTable))
			{
				return g_PGTableDictArray[nTable].sFieldArray[nField].nCategory;
			}
		}
		return -1;
	}

	int	PGGetFieldNameArray(const int nTable, char* lpszRetString)
	{
		strcpy(lpszRetString, "");
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			strBuf.clear();

			const int nFieldNum=PGGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				if (strlen(g_PGTableDictArray[nTable].sFieldArray[nField].lpszName) > 0)
					strBuf.append(g_PGTableDictArray[nTable].sFieldArray[nField].lpszName);
				else
					strBuf.append("NULL");
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	int	PGGetFieldDespArray(const int nTable, char* lpszRetString)
	{
		strcpy(lpszRetString, "");
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			strBuf.clear();

			const int nFieldNum=PGGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				if (strlen(g_PGTableDictArray[nTable].sFieldArray[nField].lpszDesp) > 0)
					strBuf.append(g_PGTableDictArray[nTable].sFieldArray[nField].lpszDesp);
				else
					strBuf.append("NULL");
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}


	int	PGGetFieldCategoryArray(const int nTable, char* lpszRetString)
	{
		strcpy(lpszRetString, "");
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			char		szBuf[260];
			strBuf.clear();

			const int nFieldNum=PGGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				sprintf(szBuf, "%d", g_PGTableDictArray[nTable].sFieldArray[nField].nCategory);
				strBuf.append(szBuf);
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	int	PGGetFieldTypeArray(const int nTable, char* lpszRetString)
	{
		strcpy(lpszRetString, "");
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			char		szBuf[260];
			strBuf.clear();

			const int nFieldNum=PGGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				sprintf(szBuf, "%d", g_PGTableDictArray[nTable].sFieldArray[nField].nDataType);
				strBuf.append(szBuf);
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	int	PGGetFieldLenArray(const int nTable, char* lpszRetString)
	{
		strcpy(lpszRetString, "");
		if (nTable >= 0 && nTable < PGGetTableNum())
		{
			int		nField;

			std::string	strBuf;
			char		szBuf[260];
			strBuf.clear();

			const int nFieldNum=PGGetTableFieldNum(nTable);
			for (nField=0; nField<nFieldNum; nField++)
			{
				sprintf(szBuf, "%d", g_PGTableDictArray[nTable].sFieldArray[nField].nDataLen);
				strBuf.append(szBuf);
				strBuf.append("\\");
			}

			strcpy(lpszRetString, strBuf.c_str());
			return 1;
		}
		return 0;
	}

	void PGFormResourceId(tagPGBlock* pPGBlock, const int nTable, const int nRecord, char* lpszRetResID)
	{
		register int	i;
		char			szField[MDB_CHARLEN_LONG];
		std::string		strBuffer;

		const	int		nRestNum=PGGetTablePrimaryKeyNum(nTable);
		sprintf(lpszRetResID, "%d.%d", nTable, nRecord);
		if (nRestNum <= 0)
			return;

		strBuffer.clear();
		for (i=0; i<nRestNum; i++)
		{
			if (i > 0)	strBuffer.append("/"); 
			PGGetRecordValue(pPGBlock, nTable, PGGetTablePrimaryKey(nTable, i), nRecord, szField);
			strBuffer.append(szField);
		}
		MemDBBase::CalculateResourceId(strBuffer.c_str(), lpszRetResID);
	}

	void	PGCalcResourceId(const char* lpszInString, char* lpszRetResID)
	{
		MemDBBase::CalculateResourceId(lpszInString, lpszRetResID);
	}

	const int	PGGetFieldCategoryNum()
	{
		return sizeof(MDBFeldCategoryStringArray)/sizeof(char*);
	}

	const char*	PGGetFieldCategoryName(const int nCatrgory)
	{
		return MDBFeldCategoryStringArray[nCatrgory];
	}

	const int	PGGetFieldCategoryValue(const char* lpszCatrgory)
	{
		register int	i;
		for (i=0; i<sizeof(MDBFeldCategoryStringArray)/sizeof(char*); i++)
		{
			if (stricmp(lpszCatrgory, MDBFeldCategoryStringArray[i]) == 0)
				return i;
		}
		return -1;
	}

	const int	PGGetTableFieldContainerNum()
	{
		return sizeof(g_PGTableFieldContainerArray)/sizeof(tagMDBTableFieldContainer);
	}

	tagMDBTableFieldContainer*	PGGetTableFieldContainerPtr(const int nContainer)
	{
		if (nContainer >= 0 && nContainer < PGGetTableFieldContainerNum())
			return &g_PGTableFieldContainerArray[nContainer];

		return NULL;
	}
}
