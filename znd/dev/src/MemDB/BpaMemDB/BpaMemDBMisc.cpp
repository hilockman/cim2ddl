#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"
#include "../../Common/StringCommon.h"

namespace	BpaMemDB
{
	void	BpaDictKey2BpaCardKey(char* lpszKey)
	{
		if (stricmp(lpszKey, "FX+") == 0)
			strcpy(lpszKey, "F+");
// 		else if (stricmp(lpszKey, "SH1") == 0 || stricmp(lpszKey, "SH2") == 0)
// 			strcpy(lpszKey, "SH");
// 		else if (stricmp(lpszKey, "SH1+") == 0 || stricmp(lpszKey, "SH2+") == 0)
// 			strcpy(lpszKey, "SH+");
		else if (stricmp(lpszKey, "UV+") == 0)
			strcpy(lpszKey, "U+");
		else if (stricmp(lpszKey, "UF+") == 0)
			strcpy(lpszKey, "U+");
	}

	void	BpaBpaCardKey2DictKey(char* lpszKey, const char* lpszDataLine)
	{
		register int	i;
		unsigned char	bBlank=1;
		if (stricmp(lpszKey, "F+") == 0)
		{
			for (i=34; i<71; i++)
			{
				if (lpszDataLine[i] != ' ')
				{
					bBlank=0;
					break;
				}
			}
			if (bBlank)
				strcpy(lpszKey, "FX+");
		}
// 		else if (stricmp(lpszKey, "SH") == 0)
// 		{
// 			for (i=16; i<20; i++)
// 			{
// 				if (lpszDataLine[i] != ' ')
// 				{
// 					bBlank=0;
// 					break;
// 				}
// 			}
// 			if (bBlank)
// 				strcpy(lpszKey, "SH2");
// 			else
// 				strcpy(lpszKey, "SH1");
// 		}
// 		else if (stricmp(lpszKey, "SH+") == 0)
// 		{
// 			for (i=16; i<60; i++)
// 			{
// 				if (lpszDataLine[i] != ' ')
// 				{
// 					bBlank=0;
// 					break;
// 				}
// 			}
// 			if (bBlank)
// 				strcpy(lpszKey, "SH1+");
// 			else
// 				strcpy(lpszKey, "SH2+");
// 		}
	}

	void	BpaBpaCardKey2DictKey(char* lpszKey, const std::vector<std::string> strPrevCardArray)
	{
		register int	i;
		unsigned char	bBlank=1;
		if (stricmp(lpszKey, "U+") == 0)
		{
			for (i=(int)strPrevCardArray.size()-1; i>=0; i--)
			{
				if (stricmp(strPrevCardArray[i].c_str(), "UF") == 0)
				{
					strcpy(lpszKey, "UF+");
					return;
				}
				else if (stricmp(strPrevCardArray[i].c_str(), "UV") == 0)
				{
					strcpy(lpszKey, "UV+");
					return;
				}
			}
		}
	}
}