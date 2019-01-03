#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"
#include "../../Common/StringCommon.h"

namespace	BpaMemDB
{
	void CBpaMemDBInterface::BpaDictKey2BpaCardKey(char* lpszKey)
	{
		if (stricmp(lpszKey, "FX+") == 0)
			strcpy(lpszKey, "F+");
		else if (stricmp(lpszKey, "UV+") == 0)
			strcpy(lpszKey, "U+");
		else if (stricmp(lpszKey, "UF+") == 0)
			strcpy(lpszKey, "U+");
		else if (stricmp(lpszKey, "DNZ") == 0)
			strcpy(lpszKey, "DZ");
		else if (stricmp(lpszKey, "DMZ") == 0)
			strcpy(lpszKey, "DZ");
		else if (stricmp(lpszKey, "DAZ") == 0)
			strcpy(lpszKey, "DZ");
	}

	void CBpaMemDBInterface::BpaBpaCardKey2DictKeyFx(char* lpszKey, const char* lpszDataLine)
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
	}

	void CBpaMemDBInterface::BpaBpaCardKey2DictKey(char* lpszKey, const char* lpszPrevKey)
	{
		unsigned char	bBlank=1;
		if (stricmp(lpszKey, "U+") == 0)
		{
			if (stricmp(lpszPrevKey, "UF") == 0)
			{
				strcpy(lpszKey, "UF+");
				return;
			}
			else if (stricmp(lpszPrevKey, "UV") == 0)
			{
				strcpy(lpszKey, "UV+");
				return;
			}
		}
		else if (stricmp(lpszKey, "DZ") == 0)
		{
			if (stricmp(lpszPrevKey, "DM") == 0)
			{
				strcpy(lpszKey, "DMZ");
				return;
			}
			else if (stricmp(lpszPrevKey, "DN") == 0)
			{
				strcpy(lpszKey, "DNZ");
				return;
			}
			else if (stricmp(lpszPrevKey, "DA") == 0)
			{
				strcpy(lpszKey, "DAZ");
				return;
			}
		}
	}
}