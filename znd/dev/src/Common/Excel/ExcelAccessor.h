// ExcelAccessor.h: interface for the ExcelAccessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXCELACCESSOR_H__B7640A8E_6E3E_4D09_8F65_E6C71044757B__INCLUDED_)
#define AFX_EXCELACCESSOR_H__B7640A8E_6E3E_4D09_8F65_E6C71044757B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CApplication.h"
#include "CRange.h"
#include "CWorkbook.h"
#include "CWorkbooks.h"
#include "CWorksheet.h"
#include "CWorksheets.h"
#include "CExcelfont.h"
#include "CInterior.h"

#define StartROW 1
#define StartCOL 1

class ExcelAccessor  
{
public:
	ExcelAccessor(bool showExcel = false, bool bCloseExcel = true );
	virtual ~ExcelAccessor();
public:
	bool SetWrapText(bool bWrap);
	void SetDefaultColumnWidth(short width);
	bool SaveAndClose();
    CString ReadCellText(int row, int col);
    bool WriteCellText(int row, int col, const CString& txt);
	bool SetCurSheet(const CString& sheetName);
	bool SetCurSheet(short index);
	bool OpenXls(const CString &name);
	bool Open(/*const CString& path, const CString& defaultSheetName*/);
	virtual bool AddSheet(LPCTSTR sheetname);
	virtual bool Create(const CString& path, const CString& defaultSheetName = _T(""));
	virtual bool Flush(void);
	virtual bool Close(void);
	virtual bool GetFullBookPath(CString& path);
    static bool ShowXlsOnly(const CString &name);
    bool InsertRow(int row);
    bool DeleteRow( int row );
    bool CloseXls(void);

    // Autofit current sheet
    bool AutoFit();

    virtual bool MarkCellText(COLORREF txtColor);
    virtual bool FillCell(COLORREF bkColor);
    int AddCell(long value);
    void Skip(int row, int col);
    virtual bool AddCell(const CString& content);
    virtual bool NewLine(void);
    bool SetLeftTop(int minrow, int mincol); 
    void ResetPosition();
    bool RunMacro(const CString& macroname);
    bool GetAllSheetNames(CStringArray& sheetnames);


    const CString& GetLastError() { return m_csLastError; }


private:
    const CString CalCurrentCell(void) const;
    const CString CalCurrentCell(int row, int col) const ;
    void ClearError() { m_csLastError.Empty(); }


	short m_sDefaultColWindth;
	CApplication m_oExcel;
	CWorksheet m_oSheet;
	CWorkbook m_oBook;
	bool m_bShowExcel;
	bool m_bCloseExcel;
    int m_nRow;
    int m_nCol;
    int m_nMinRow;
    int m_nMinCol;

    
    CString m_csLastError;
};

#endif // !defined(AFX_EXCELACCESSOR_H__B7640A8E_6E3E_4D09_8F65_E6C71044757B__INCLUDED_)
