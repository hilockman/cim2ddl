#pragma once
#include <math.h>
#include <float.h>

#include <afxcmn.h>
#include <afxlistctrl.h>

class CMFCListCtrlEx : public CMFCListCtrl
{
public:
	virtual COLORREF OnGetCellTextColor(int nRow, int nColum)
	{
		return(nRow % 2) == 0 ? RGB(128, 37, 0) : RGB(0, 0, 0);
	}
	virtual COLORREF OnGetCellBkColor(int nRow, int nColum)
	{
		if (m_bMarkSortedColumn && nColum == m_iSortedColumn)
		{
			return(nRow % 2) == 0 ? RGB(233, 221, 229) : RGB(176, 218, 234);
		}
		return(nRow % 2) == 0 ? RGB(253, 241, 249) : RGB(196, 238, 254);
	}

	virtual int OnCompareItems(LPARAM lParam1, LPARAM lParam2, int iColumn)
	{
		if (lParam1 == lParam2)
			return 0;

		CString strItem1,strItem2;

		LVFINDINFO lvfi;
		lvfi.flags=LVFI_PARAM;

		//Log(g_lpszLogFile, "OnCompareItems: Param1=%d Param2=%d Column=%d\n", lParam1, lParam2, iColumn);

		lvfi.lParam=lParam1;
		strItem1=GetItemText(FindItem(&lvfi,-1), iColumn);

		lvfi.lParam=lParam2;
		strItem2=GetItemText(FindItem(&lvfi,-1), iColumn);

		if (strItem1.IsEmpty())
			return -1;
		if (strItem2.IsEmpty())
			return 1;

		if (isStringNumeric(strItem1) && isStringNumeric(strItem2))
		{
			double	fDiff;
#ifdef UNICODE
			fDiff=_wtof(strItem1)-_wtof(strItem2);
#else
			fDiff=atof(strItem1)-atof(strItem2);
#endif // UNICODE
			if (fabs(fDiff) <= FLT_MIN)
				return 0;
			else if (fDiff < 0)
				return -1;
			else
				return 1;
		}
		else
			return _tcsicmp(strItem1, strItem2);	// ÅÅÐò ´¿´â×Ö·û´®±È½Ï
	}

private:
	int isStringNumeric(CString strString)
	{
		register int	i;

		if (strString.IsEmpty())
			return 0;

		for (i=0; i<strString.GetLength(); i++)
		{
			if (!isascii(strString[i]))
				return 0;

			if (!isdigit(strString[i]) && strString[i] != '-' && strString[i] != '.')
				return 0;
		}
		return 1;
	}
};
