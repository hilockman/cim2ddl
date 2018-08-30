#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaDictData.h"
#include "BpaMemDBExtern.h"

namespace	BpaMemDB
{
	int BpaGetTableDictIndex(const char* lpszKey, const int nCategory)
	{
		register int	i;
		for (i=0; i<sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict); i++)
		{
			if (STRICMP(g_BpaDictArray[i].szCardKey, lpszKey) == 0)
			{
				if (nCategory >= 0)
				{
					if (g_BpaDictArray[i].bFieldCategory == nCategory)
						return i;
				}
				else
					return i;
			}
		}
		return -1;
	}

	const int	BpaGetDictNum()
	{
		return sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict);
	}

	const char*	BpaGetDictTable(const int nDictIndex)
	{
		return g_BpaDictArray[nDictIndex].szTable;
	}

	const char*	BpaGetDictCardKey(const int nDictIndex)
	{
		return g_BpaDictArray[nDictIndex].szCardKey;
	}

	const char*	BpaGetDictFieldName(const int nDictIndex)
	{
		return g_BpaDictArray[nDictIndex].szFieldName;
	}

	const unsigned char	BpaGetDictModified(const int nDictIndex)
	{
		return g_BpaDictArray[nDictIndex].bFieldModabled;
	}

	const int	BpaGetDictFieldType(const int nDictIndex)
	{
		return g_BpaDictArray[nDictIndex].nFieldType;
	}

	const int	BpaGetDictFieldStart(const int nDictIndex)
	{
		return g_BpaDictArray[nDictIndex].nFieldStart;
	}

	const int	BpaGetDictFieldEnd(const int nDictIndex)
	{
		return g_BpaDictArray[nDictIndex].nFieldEnd;
	}

	const int	BpaGetDictFieldLen(const int nDictIndex)
	{
		return g_BpaDictArray[nDictIndex].nFieldLen;
	}

	const int	BpaGetDictFieldDecimal(const int nDictIndex)
	{
		return g_BpaDictArray[nDictIndex].nFieldDecimal;
	}

	int BpaGetFieldDictIndex(const int nDict, const char* lpszField)
	{
		register int	i;
		for (i=nDict; i<sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict); i++)
		{
			if (STRICMP(g_BpaDictArray[i].szCardKey, g_BpaDictArray[nDict].szCardKey) != 0)
				break;

			if (STRICMP(g_BpaDictArray[i].szFieldName, lpszField) == 0)
				return i;
		}
		return -1;
	}

	void	BpaMaintDict()
	{
		register int	i, j;
		tagBpa_Dict	dBuf;

		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();
		for (i=0; i<sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict); i++)
		{
			for (j=i+1; j<sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict); j++)
			{
				if (strcmp(g_BpaDictArray[i].szTable, g_BpaDictArray[j].szTable) > 0 ||
					strcmp(g_BpaDictArray[i].szTable, g_BpaDictArray[j].szTable) == 0 && strcmp(g_BpaDictArray[i].szCardKey, g_BpaDictArray[j].szCardKey) > 0 ||
					strcmp(g_BpaDictArray[i].szTable, g_BpaDictArray[j].szTable) == 0 && strcmp(g_BpaDictArray[i].szCardKey, g_BpaDictArray[j].szCardKey) == 0 && g_BpaDictArray[i].nFieldStart > g_BpaDictArray[j].nFieldStart)
				{
					memcpy(&dBuf, &g_BpaDictArray[i], sizeof(tagBpa_Dict));
					memcpy(&g_BpaDictArray[i], &g_BpaDictArray[j], sizeof(tagBpa_Dict));
					memcpy(&g_BpaDictArray[j], &dBuf, sizeof(tagBpa_Dict));
				}
			}
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "BpaMaintDict完毕，耗时%d毫秒\n", nDur);

		int	nDict, nTable, nField;
		unsigned char	bFind;
		for (nDict=0; nDict<sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict); nDict++)
		{
			bFind=0;
			for (nTable=0; nTable<BpaGetTableNum(); nTable++)
			{
				for (nField=0; nField<BpaGetTableFieldNum(nTable); nField++)
				{
					if (strcmp(BpaGetTableName(nTable), g_BpaDictArray[nDict].szTable) == 0 &&
						strcmp(BpaGetFieldName(nTable, nField), g_BpaDictArray[nDict].szFieldName) == 0)
					{
						bFind=1;
						break;
					}
				}
				if (bFind)
					break;
			}
			if (!bFind)
				Log(g_lpszLogFile, "字典记录(Table=%s Field=%s Card=%s)没有找到\n", g_BpaDictArray[nDict].szTable, g_BpaDictArray[nDict].szFieldName, g_BpaDictArray[nDict].szCardKey);
		}

		//for (i=0; i<sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict); i++)
		//	Log(g_lpszLogFile, "BPADict[%d/%d]=%s %s %s %d\n", i, sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict), g_BpaDictArray[i].szTable, g_BpaDictArray[i].szCardKey, g_BpaDictArray[i].szFieldName, g_BpaDictArray[i].nFieldStart);
	}

	int BpaIsCardKeyAppend(const int nCategory, const char* lpszKey)
	{
		register int	i;
		for (i=0; i<sizeof(g_BpaModifyKeyArray)/sizeof(tagBpaKey2I); i++)
		{
			if (g_BpaModifyKeyArray[i].nInteger == nCategory && stricmp(g_BpaModifyKeyArray[i].szKey, lpszKey) == 0)
				return 0;
		}
		return 1;
	}


	int	BpaGetGeneratorTableByCardKey(const char* lpszKey)
	{
		register int	i;
		for (i=0; i<sizeof(g_GeneratorCardArray)/sizeof(tagBpaKey2I); i++)
		{
			if (STRICMP(g_GeneratorCardArray[i].szKey, lpszKey) == 0)
				return g_GeneratorCardArray[i].nInteger;
		}
		for (i=0; i<sizeof(g_ExciterCardArray)/sizeof(tagBpaKey2I); i++)
		{
			if (STRICMP(g_ExciterCardArray[i].szKey, lpszKey) == 0)
				return g_ExciterCardArray[i].nInteger;
		}
		for (i=0; i<sizeof(g_PssCardArray)/sizeof(tagBpaKey2I); i++)
		{
			if (STRICMP(g_PssCardArray[i].szKey, lpszKey) == 0)
				return g_PssCardArray[i].nInteger;
		}
		for (i=0; i<sizeof(g_GovernorCardArray)/sizeof(tagBpaKey2I); i++)
		{
			if (STRICMP(g_GovernorCardArray[i].szKey, lpszKey) == 0)
				return g_GovernorCardArray[i].nInteger;
		}
		for (i=0; i<sizeof(g_PrimeMoverCardArray)/sizeof(tagBpaKey2I); i++)
		{
			if (STRICMP(g_PrimeMoverCardArray[i].szKey, lpszKey) == 0)
				return g_PrimeMoverCardArray[i].nInteger;
		}
		return -1;
	}
}