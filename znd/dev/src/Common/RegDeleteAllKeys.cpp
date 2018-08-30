#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

LONG RegDeleteAllKeys(HKEY hKeyDelete, LPCTSTR pszSubKey)
{
	HKEY	hKeyChild;
	TCHAR	szTmp[260];
	LONG	lResult;
	DWORD	dwTmpSize = 260;

	lResult = RegOpenKeyEx(hKeyDelete, 
		pszSubKey, 
		0, 
		KEY_ALL_ACCESS, 
		&hKeyChild);

	if (lResult != ERROR_SUCCESS)
		return lResult;

	lResult = RegEnumKey(hKeyChild, 
		0, 
		szTmp, 
		dwTmpSize);

	while (lResult != ERROR_NO_MORE_ITEMS)
	{
		RegDeleteAllKeys(hKeyChild, szTmp);
		lResult = RegEnumKey(hKeyChild, 
			0, 
			szTmp, 
			dwTmpSize);
	}

	RegCloseKey(hKeyChild);
	lResult = RegDeleteKey(hKeyDelete, pszSubKey);

	return lResult;
} 
