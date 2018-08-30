#include "stdafx.h"
#include "ExcelAccessor.h"
#include "io.h"

void	SaveListAsExcel(CListCtrl* pListCtrl, const char* lpszExcelSheetName, const char* lpszFileName, const unsigned char bShowExcel)
{
	register int	i;
	int				nRow, nCol;
	CString			str1, str2;
	int				nRowNum, nColNum;
	int				nColArray[1024];
	LVCOLUMN		lvc;
	CString			strItem;

	for (i=0; i<1024; i++)
		nColArray[i]=-1;
	nRowNum=pListCtrl->GetItemCount();
	pListCtrl->GetColumnOrderArray(nColArray);

	nColNum=0;
	for (i=0; i<1024; i++)
	{
		if (nColArray[i] < 0)
		{
			nColNum=i;
			break;
		}
	}
	if (nRowNum <= 0 && nColNum <= 0)
	{
		//AfxMessageBox("没有表内容");
		return;
	}

	ExcelAccessor	xls;
	//ExcelAccessor* pExcel=new ExcelAccessor(true, true);

	if (_access(lpszFileName, 0) != 0)
		xls.Create(CString(lpszFileName));
	else
	{
		if (!xls.Open())
		{
			return;
		}
		if (!xls.OpenXls(CString(lpszFileName)))
		{
			return;
		}
	}

//	unsigned char	bExist;
	CStringArray	strSheetNameArray;
	xls.GetAllSheetNames(strSheetNameArray);

// 	bExist=0;
// 	for (i=0; i<strSheetNameArray.GetSize(); i++)
// 	{
// 		if (strSheetNameArray[i].CompareNoCase(lpszExcelSheetName))
// 		{
// 			bExist=1;
// 			break;
// 		}
// 	}

	//if (!bExist)
		xls.AddSheet(CString(lpszExcelSheetName));
	xls.SetCurSheet(CString(lpszExcelSheetName));
	//pExcel->Create(lpszExcelName);

	for (nCol=0; nCol<nColNum; nCol++)
	{
		lvc.mask = LVCF_TEXT;
		lvc.pszText = strItem.GetBufferSetLength(260);
		lvc.cchTextMax = 260;
		pListCtrl->GetColumn(nCol, &lvc);

		xls.AddCell(strItem);

		strItem.ReleaseBuffer();
	}

	for (nRow=0; nRow<nRowNum; nRow++)
	{
		xls.NewLine();
		for (nCol=0; nCol<nColNum; nCol++)
		{
			strItem=pListCtrl->GetItemText(nRow, nCol);
			xls.AddCell(strItem);
			strItem.ReleaseBuffer();
		}
	}
	xls.Flush();
	xls.SaveAndClose();

	//delete pExcel;

	if (bShowExcel)
		ExcelAccessor::ShowXlsOnly(CString(lpszFileName));
}

