#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaDictData.h"
#include "BpaMemDBExtern.h"

namespace	BpaMemDB
{
	const int CBpaMemDBInterface::BpaGetTableDictIndex(const char* lpszKey, const int nCategory) const
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

	const int CBpaMemDBInterface::BpaGetDictNum() const
	{
		return sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict);
	}

	const char* CBpaMemDBInterface::BpaGetDictTable(const int nDictIndex) const
	{
		return (nDictIndex >= 0 && nDictIndex < sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict)) ? g_BpaDictArray[nDictIndex].szTable : "";
	}

	const char*	CBpaMemDBInterface::BpaGetDictCardKey(const int nDictIndex) const
	{
		return (nDictIndex >= 0 && nDictIndex < sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict)) ? g_BpaDictArray[nDictIndex].szCardKey : "";
	}

	const char*	CBpaMemDBInterface::BpaGetDictFieldName(const int nDictIndex) const
	{
		return (nDictIndex >= 0 && nDictIndex < sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict)) ? g_BpaDictArray[nDictIndex].szFieldName : 0;
	}

	const unsigned char	CBpaMemDBInterface::BpaGetDictModified(const int nDictIndex) const
	{
		return (nDictIndex >= 0 && nDictIndex < sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict)) ? g_BpaDictArray[nDictIndex].bFieldModabled : 0;
	}

	const int CBpaMemDBInterface::BpaGetDictFieldType(const int nDictIndex) const
	{
		return (nDictIndex >= 0 && nDictIndex < sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict)) ? g_BpaDictArray[nDictIndex].nFieldType : 0;
	}

	const int CBpaMemDBInterface::BpaGetDictFieldStart(const int nDictIndex) const
	{
		return (nDictIndex >= 0 && nDictIndex < sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict)) ? g_BpaDictArray[nDictIndex].nFieldStart : 0;
	}

	const int CBpaMemDBInterface::BpaGetDictFieldEnd(const int nDictIndex) const
	{
		return (nDictIndex >= 0 && nDictIndex < sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict)) ? g_BpaDictArray[nDictIndex].nFieldEnd : 0;
	}

	const int CBpaMemDBInterface::BpaGetDictFieldLen(const int nDictIndex) const
	{
		return (nDictIndex >= 0 && nDictIndex < sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict)) ? g_BpaDictArray[nDictIndex].nFieldLen : 0;
	}

	const int CBpaMemDBInterface::BpaGetDictFieldDecimal(const int nDictIndex) const
	{
		return (nDictIndex >= 0 && nDictIndex < sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict)) ? g_BpaDictArray[nDictIndex].nFieldDecimal : 0;
	}

	const int CBpaMemDBInterface::BpaGetFieldDictIndex(const int nDict, const char* lpszField) const
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

	void CBpaMemDBInterface::BpaMaintDict()
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
		Log(g_lpszLogFile, "BpaMaintDict��ϣ���ʱ%d����\n", nDur);

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
				Log(g_lpszLogFile, "�ֵ��¼(Table=%s Field=%s Card=%s)û���ҵ�\n", g_BpaDictArray[nDict].szTable, g_BpaDictArray[nDict].szFieldName, g_BpaDictArray[nDict].szCardKey);
		}

		//for (i=0; i<sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict); i++)
		//	Log(g_lpszLogFile, "BPADict[%d/%d]=%s %s %s %d\n", i, sizeof(g_BpaDictArray)/sizeof(tagBpa_Dict), g_BpaDictArray[i].szTable, g_BpaDictArray[i].szCardKey, g_BpaDictArray[i].szFieldName, g_BpaDictArray[i].nFieldStart);
	}

	int CBpaMemDBInterface::BpaIsCardKeyAppend(const int nCategory, const char* lpszKey)
	{
		register int	i;
		for (i=0; i<sizeof(g_BpaModifyKeyArray)/sizeof(tagBpaKey2I); i++)
		{
			if (g_BpaModifyKeyArray[i].nInteger == nCategory && stricmp(g_BpaModifyKeyArray[i].szKey, lpszKey) == 0)
				return 0;
		}
		return 1;
	}


	int	CBpaMemDBInterface::BpaGetGeneratorTableByCardKey(const char* lpszKey)
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