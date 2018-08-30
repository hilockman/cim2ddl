#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"
#include "BpaDictSwiData.h"
#include "../../Common/StringCommon.h"
#include "../../Common/String2Double.hpp"

#include <float.h>
namespace	BpaMemDB
{
	extern	int	BpaMemDB2Files_Swi(tagBpaBlock* pBpaBlock, FILE* fp);
	extern	int	BpaMemDB2Files_Dat(tagBpaBlock* pBpaBlock, FILE* fp);
	extern	int	BpaFiles2MemDB_Dat(tagBpaBlock* pBpaBlock, const char* lpszBpaDatFile, const double fZeroImpendance);
	extern	int	BpaFiles2MemDB_Swi(tagBpaBlock* pBpaBlock, const char* lpszBpaSwiFile);

	int	BpaFiles2MemDB(tagBpaBlock* pBpaBlock, const char* lpszBpaDatFile, const char* lpszBpaSwiFile, const double fZeroImpendance)
	{
		register int	i;
		for (i=0; i<BpaGetTableNum(); i++)
			pBpaBlock->m_nRecordNum[i]=0;

		if (lpszBpaDatFile != NULL)
		{
			if (access(lpszBpaDatFile, 0) == 0)
				BpaFiles2MemDB_Dat(pBpaBlock, lpszBpaDatFile, fZeroImpendance);
		}
		if (lpszBpaSwiFile != NULL)
		{
			if (access(lpszBpaSwiFile, 0) == 0)
				BpaFiles2MemDB_Swi(pBpaBlock, lpszBpaSwiFile);
		}

		return 1;
	}

	int		BpaMemDB2Files(tagBpaBlock* pBpaBlock, const char* lpszBpaDatFile, const char* lpszBpaSwiFile)
	{
		FILE*	fp=NULL;
		if (lpszBpaDatFile)
		{
			fp=fopen(lpszBpaDatFile, "w");
			if (fp != NULL)
			{
				if (!BpaMemDB2Files_Dat(pBpaBlock, fp))
					goto _ErrorOut;

				fflush(fp);
				fclose(fp);
				fp=NULL;
			}
		}
		if (lpszBpaSwiFile)
		{
			fp=fopen(lpszBpaSwiFile, "w");
			if (fp != NULL)
			{
				if (!BpaMemDB2Files_Swi(pBpaBlock, fp))
					goto _ErrorOut;

				fflush(fp);
				fclose(fp);
				fp=NULL;
			}
		}

		return 1;

_ErrorOut:	;
		if (fp != NULL)
		{
			fflush(fp);
			fclose(fp);
		}
		return 0;
	}

	//	设置小数点
	void CheckDecimal(char szFloat[], const int nFloat)
	{
		register int	i;
		int		nChar;
		char	szBuf[MDB_CHARLEN_SHORTER];

		if (strstr(szFloat, ".") != NULL || nFloat == 0)
			return;

		for (i=0; i<(int)strlen(szFloat); i++)
		{
			if (szFloat[i] == ' ')
				szFloat[i]='0';
		}

		nChar=0;
		memset(szBuf, 0, MDB_CHARLEN_SHORTER);
		for (i=0; i<(int)strlen(szFloat); i++)
		{
			if (i == strlen(szFloat)-nFloat)
				szBuf[nChar++]='.';

			szBuf[nChar++]=szFloat[i];
		}
		szBuf[nChar++]='\0';

		strcpy(szFloat, szBuf);
	}

	//	从字符串中提取数据
	void ExtractBpaField(const int nColIni, const int nColEnd, const char* lpszInChar, char* lpszChar)
	{
		register int	i;
		int		nChar;
		unsigned char	bFlag;

		for (i=0; i<nColEnd-nColIni+1; i++)
			lpszChar[i]=' ';
		lpszChar[nColEnd-nColIni+1]='\0';

		nChar=nColEnd-nColIni;
		bFlag=0;

		i=nColEnd-1;
		if (i >= (int)strlen(lpszInChar))	i=(int)strlen(lpszInChar)-1;
		while (i >= nColIni-1)
		{
			if (lpszInChar[i] == '\0' || lpszInChar[i] == '\n' || lpszInChar[i] == '\r')
				break;

			if (lpszInChar[i] != ' ' && lpszInChar[i] != '\t' && lpszInChar[i] != '\0')
				bFlag=1;

			if (lpszInChar[i] != ' ' && lpszInChar[i] != '\t')
				lpszChar[nChar--]=lpszInChar[i];

			i--;
		}
	}

	//	提取BPA关键字
	void BpaResolveLineKey(const char* lpszLine, char* lpszRetKey)
	{
		register int	i, j;

		j=0;
		for (i=0; i<(int)strlen(lpszLine); i++)
		{
			if ((lpszLine[0] == 'F' || lpszLine[0] == 'B') && i >= 3)
				break;

			if (lpszLine[i] == ' ' || lpszLine[i] == '\t' || lpszLine[i] == '\n' || lpszLine[i] == '\0')
				break;
			if (!isascii(lpszLine[i]))
				break;

			lpszRetKey[j++]=lpszLine[i];

			if (lpszLine[i] == '+' && i != 0)
				break;
			if (lpszLine[i] == '#')
				break;
		}
		lpszRetKey[j++]='\0';
		if (j > 9)
			Log("KeyError = %s\n", lpszRetKey);
		//	ASSERT(FALSE);
		TrimRight(lpszRetKey);
	}

	void	BpaString2FieldArray(const int nBpaTable, const int nDictIni, const char* lpszBpaLine, char szField[][MDB_CHARLEN_LONG])
	{
		register int	i;
		int		nDict, nField;

		for (i=0; i<BpaGetTableFieldNum(nBpaTable); i++)
			memset(szField[i], 0, MDB_CHARLEN_LONG);

		for (nDict=nDictIni; nDict<BpaGetDictNum(); nDict++)
		{
			if (stricmp(BpaGetDictCardKey(nDict), BpaGetDictCardKey(nDictIni)) != 0)
				break;

			nField=BpaGetFieldIndex(nBpaTable, BpaGetDictFieldName(nDict));
			if (nField < 0)
				continue;

			ExtractBpaField(BpaGetDictFieldStart(nDict), BpaGetDictFieldEnd(nDict), lpszBpaLine, szField[nField]);
			if (BpaGetDictFieldType(nDict) == MDB_FLOAT && strlen(szField[nField]) > 0)
				CheckDecimal(szField[nField], BpaGetDictFieldDecimal(nDict));
			Trim(szField[nField]);
		}

		BpaFormTableKeyField(nBpaTable, szField);
	}

	int		BpaParseOutFile(tagBpaBlock* pBpaBlock, const char* lpszBpaOutFile)
	{
		return 1;
	}
}