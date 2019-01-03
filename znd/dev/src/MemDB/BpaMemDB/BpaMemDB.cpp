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

	char* CBpaMemDBInterface::Init_BpaBlock(const int nBpaBlockKey, const int bCreateMem, const int bClearBaseLog)
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

	void CBpaMemDBInterface::Exit_BpaBlock(char* lpszBlockMap, const int nBpaBlockKey)
	{
		if (nBpaBlockKey > 0)
			MemDBBase::Exit_MDBBlock(lpszBlockMap, nBpaBlockKey);
		else
			MemDBBase::Exit_MDBBlock(lpszBlockMap, g_nBpaBlockKey);
	}

	const int CBpaMemDBInterface::BpaGetFieldEnumNum(const int nTable, const int nField) const
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

	const int CBpaMemDBInterface::BpaGetFieldEnumValue(const int nTable, const int nField, const char* lpszEnumName) const
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

	const char* CBpaMemDBInterface::BpaGetFieldEnumString(const int nTable, const int nField, const int nEnumIndex) const
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

	const int CBpaMemDBInterface::BpaGetFieldEnumStringArray(const int nTable, const int nField, int& nEnumNum, char szEnumArray[][MDB_CHARLEN]) const
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

	const int CBpaMemDBInterface::BpaGetTablePrimaryKeyNum(const int nTable) const
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
			return g_BpaTableDictArray[nTable].sPrimaryKey.nPrimaryKeyNum;

		return 0;
	}

	const int CBpaMemDBInterface::BpaGetTablePrimaryKey(const int nTable, const int nRest) const
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

	const int CBpaMemDBInterface::BpaIsFieldPrimaryKey(const int nTable, const int nField) const
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			for (int nKey=0; nKey<BpaGetTablePrimaryKeyNum(nTable); nKey++)
			{
				if (nField == BpaGetTablePrimaryKey(nTable, nKey))
					return 1;
			}
		}

		return 0;
	}

	const int CBpaMemDBInterface::BpaGetTableNum() const
	{
		return sizeof(g_BpaTableDictArray)/sizeof(tagMemDBTable);
	}

	const int CBpaMemDBInterface::BpaGetTableMax(const int nTable) const
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
		{
			return g_BpaTableDictArray[nTable].nRecordMax;
		}
		return 0;
	}

	const int CBpaMemDBInterface::BpaGetTableFieldNum(const int nTable) const
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
			return g_BpaTableDictArray[nTable].nFieldNum;

		return 0;
	}

	const int CBpaMemDBInterface::BpaGetTableIndex(const char* lpszTableName) const
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

	const int CBpaMemDBInterface::BpaGetFieldIndex(const int nTable, const char* lpszFieldName) const
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

	const char* CBpaMemDBInterface::BpaGetTableName(const int nTable) const
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
			return g_BpaTableDictArray[nTable].lpszName;
		return "";
	}

	const char* CBpaMemDBInterface::BpaGetTableDesp(const int nTable) const
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
			return g_BpaTableDictArray[nTable].lpszDesp;
		return "";
	}

	const int CBpaMemDBInterface::BpaGetTableCategory(const int nTable) const
	{
		if (nTable >= 0 && nTable < BpaGetTableNum())
			return g_BpaTableDictArray[nTable].nCategory;
		return 0;
	}

	const char* CBpaMemDBInterface::BpaGetFieldName(const int nTable, const int nField) const
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

	const char* CBpaMemDBInterface::BpaGetFieldDesp(const int nTable, const int nField) const
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

	const int CBpaMemDBInterface::BpaGetFieldLen(const int nTable, const int nField) const
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

	const int CBpaMemDBInterface::BpaGetFieldType(const int nTable, const int nField) const
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

	const int CBpaMemDBInterface::BpaGetFieldCategory(const int nTable, const int nField) const
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

	const int CBpaMemDBInterface::BpaGetFieldNameArray(const int nTable, char* lpszRetString) const
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

	const int CBpaMemDBInterface::BpaGetFieldDespArray(const int nTable, char* lpszRetString) const
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

	const int CBpaMemDBInterface::BpaGetFieldCategoryArray(const int nTable, char* lpszRetString) const
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

	const int CBpaMemDBInterface::BpaGetFieldTypeArray(const int nTable, char* lpszRetString) const
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

	const int CBpaMemDBInterface::BpaGetFieldLenArray(const int nTable, char* lpszRetString) const
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

	const int CBpaMemDBInterface::BpaGetFieldCategoryNum() const
	{
		return sizeof(MDBFeldCategoryStringArray)/sizeof(char*);
	}

	const char* CBpaMemDBInterface::BpaGetFieldCategoryName(const int nCatrgory) const
	{
		return MDBFeldCategoryStringArray[nCatrgory];
	}

	const int CBpaMemDBInterface::BpaGetFieldCategoryValue(const char* lpszCatrgory) const
	{
		register int	i;
		for (i=0; i<sizeof(MDBFeldCategoryStringArray)/sizeof(char*); i++)
		{
			if (stricmp(lpszCatrgory, MDBFeldCategoryStringArray[i]) == 0)
				return i;
		}
		return -1;
	}


	void CBpaMemDBInterface::BpaFormatDecimalChar(const int nBpaTable, const int nBpaField, char* lpszValue, const int nDataLen, const int nDecimal)
	{
		register int	i;
		unsigned char	bFlag;
		int		nChar, nPointPos;

		if (strlen(lpszValue) <= 0)
			return;

		char	szChar[64];
		memset(szChar, 0, 64);

		//	清除0和空格
		bFlag=1;
		nChar=0;
		for (i=0; i<(int)strlen(lpszValue); i++)
		{
			if (lpszValue[i] == '-')
			{
				szChar[nChar++]=lpszValue[i];
			}
			else
			{
				if (!bFlag)
				{
					if (lpszValue[i] == ' ' || lpszValue[i] == '\t' || lpszValue[i] == '\n' || lpszValue[i] == '\r' || lpszValue[i] == '\0')	//	数字后为空格和0跳出
						break;
				}
				if (bFlag)
				{
					if (lpszValue[i] == ' ' || lpszValue[i] == '0')			//	数字前为空格和0忽略
						continue;
					else
						bFlag=0;
				}
				szChar[nChar++]=lpszValue[i];
			}
		}
		szChar[nChar++]='\0';

		if (strstr(szChar, ".") != NULL)
		{
			for (i=(int)strlen(szChar)-1; i>=0; i--)
			{
				if (szChar[i] == ' ' || szChar[i] == '0')	//	小数点后的空格和0忽略
					szChar[i]='\0';
				else
					break;
			}
		}

		if (nBpaTable == BPA_DAT_ACBUS && nBpaField == BPA_DAT_ACBUS_VHOLD_MAX ||
			nBpaTable == BPA_DAT_ACLINE && nBpaField == BPA_DAT_ACLINE_R ||
			nBpaTable == BPA_DAT_ACLINE && nBpaField == BPA_DAT_ACLINE_X ||
			nBpaTable == BPA_DAT_ACLINE && nBpaField == BPA_DAT_ACLINE_B1 ||
			nBpaTable == BPA_DAT_ACLINE && nBpaField == BPA_DAT_ACLINE_B2 ||
			nBpaTable == BPA_DAT_WIND && nBpaField == BPA_DAT_WIND_R ||
			nBpaTable == BPA_DAT_WIND && nBpaField == BPA_DAT_WIND_X ||
			nBpaTable == BPA_DAT_WIND && nBpaField == BPA_DAT_WIND_TPI ||
			nBpaTable == BPA_DAT_WIND && nBpaField == BPA_DAT_WIND_TPJ ||
			nBpaTable == BPA_DAT_R && nBpaField == BPA_DAT_R_TMAX ||
			nBpaTable == BPA_DAT_R && nBpaField == BPA_DAT_R_TMIN)
		{
			if (strlen(szChar) - nDataLen == 1 && strstr(szChar, ".") != NULL)
			{
				nPointPos = -1;
				nChar = 0;
				bFlag = 0;
				for (i=0; i<strlen(szChar); i++)
				{
					if (bFlag)
						nChar++;
					if (szChar[i] == '.')
					{
						bFlag = 1;
						nPointPos = i;
					}
				}
				if (nPointPos >= 0 && nChar == nDecimal)
				{
					for (i=nPointPos; i<strlen(szChar); i++)
						szChar[i] = szChar[i+1];
				}
			}
		}

		for (i=nDataLen; i<(int)strlen(szChar); i++)	//	按给定长度截断
			szChar[i]='\0';
		strcpy(lpszValue, szChar);
	}
}
