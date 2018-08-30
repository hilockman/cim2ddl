// ExcelAccessor.cpp: implementation of the ExcelAccessor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ExcelAccessor.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define EXCEL_TRY     ClearError(); try {
#define EXCEL_CATCH_ALL  } catch(CException* e) \
{   TCHAR   szCause[255]; \
    e->GetErrorMessage(szCause, 255); \
    m_csLastError=szCause; \
    return false; } \
    catch(...) {  return false;  } \


const COleVariant covOptional(DISP_E_PARAMNOTFOUND, VT_ERROR);

ExcelAccessor::ExcelAccessor(bool showExcel /*= false*/, bool bCloseExcel /* =true*/)
:  m_bShowExcel(showExcel), m_bCloseExcel(bCloseExcel), 
   m_nRow(StartROW), m_nCol(StartCOL),  m_nMinRow(StartROW), m_nMinCol(StartCOL)
{
	ResetPosition();
	m_sDefaultColWindth = 0;
}

ExcelAccessor::~ExcelAccessor(void)
{
	Close();
}

bool ExcelAccessor::Create(const CString& path, const CString& defaultSheetName)
{
	ResetPosition();

    EXCEL_TRY	
    {
		CString fileName = path;
        //Excel could append file extension by it self.
		//fileName += ".xls";


		// If you have not created Excel, create a new instance.
		if (m_oExcel.m_lpDispatch == NULL) {
			m_oExcel.CreateDispatch(_T("Excel.Application"));
		}

		// Show Excel to the user.
		if ( m_bShowExcel)
		{
			m_oExcel.put_Visible(TRUE);
			m_oExcel.put_UserControl(TRUE);
		}
		
		//Create new work book
		m_oExcel.put_SheetsInNewWorkbook(1);

        // the following code will change the Excel options permatally
// 		TCHAR CurDir[MAX_PATH];
// 		GetCurrentDirectory( MAX_PATH, CurDir);
// 		m_oExcel.put_DefaultFilePath(CurDir);

		CWorkbooks oBooks = m_oExcel.get_Workbooks();

		m_oBook = oBooks.Add(covOptional);

		CWorksheets oSheets = m_oBook.get_Worksheets();
		m_oSheet = oSheets.get_Item(COleVariant((short)1));
		if(!defaultSheetName.IsEmpty()) m_oSheet.put_Name(defaultSheetName);

		COleVariant vFileName(fileName);
		m_oBook.SaveAs(vFileName, covOptional, covOptional, covOptional, covOptional, 
			covOptional, 0, covOptional, covOptional, covOptional, covOptional, covOptional);	

		return true;
	}
    EXCEL_CATCH_ALL
}



bool ExcelAccessor::AddCell(const CString& content)
{
	EXCEL_TRY
	{

		CRange oRange = m_oSheet.get_Range(COleVariant(CalCurrentCell()), covOptional);
		oRange.put_Value(covOptional, COleVariant(content));

		m_nCol++;

		return true;
	}
    EXCEL_CATCH_ALL
}

bool ExcelAccessor::MarkCellText(COLORREF txtColor) 
{

	EXCEL_TRY
	{
		CRange oRange = m_oSheet.get_Range(COleVariant(CalCurrentCell()), covOptional);
		CExcelFont oFont = oRange.get_Font();
		oFont.put_Color( COleVariant(( (long)txtColor )));
		return true;
	}
    EXCEL_CATCH_ALL
}


bool ExcelAccessor::FillCell(COLORREF bkColor) 
{
    EXCEL_TRY
    {
		CRange oRange = m_oSheet.get_Range(COleVariant(CalCurrentCell()), covOptional);
		CInterior oInter = oRange.get_Interior();
		oInter.put_Color( COleVariant(( (long)bkColor )));
		return true;
	}
    EXCEL_CATCH_ALL

}


bool ExcelAccessor::NewLine(void)
{
	m_nCol = m_nMinCol;
	m_nRow++;
	return true;
}

bool ExcelAccessor::Flush(void)
{
	EXCEL_TRY
	{
		m_oBook.Save();
		return true;
	}
	EXCEL_CATCH_ALL
}

bool ExcelAccessor::GetFullBookPath(CString& path)
{
    EXCEL_TRY
	{
		if(m_oBook.m_lpDispatch == NULL) return false;
		path = m_oBook.get_Path() + _T("\\") + m_oBook.get_Name();
		return true;
	}
    EXCEL_CATCH_ALL
}

//close cur workbook but keep the excel runing
bool ExcelAccessor::CloseXls(void)
{
    ResetPosition();
    EXCEL_TRY
    {

        if (m_oSheet.m_lpDispatch != NULL)
        {
            m_oSheet.ReleaseDispatch();
        }
        if (m_oBook.m_lpDispatch != NULL)
        {    
            m_oBook.Close(covOptional, covOptional, covOptional);
            m_oBook.ReleaseDispatch();

        }
        return true;
   }
   EXCEL_CATCH_ALL

}

bool ExcelAccessor::Close(void)
{
	ResetPosition();
    EXCEL_TRY
    {
	    if (m_oSheet.m_lpDispatch != NULL)
	    {
		    m_oSheet.ReleaseDispatch();
	    }
	    if (m_oBook.m_lpDispatch != NULL)
        {    
		    if(m_bCloseExcel)
			    m_oBook.Close(covOptional, covOptional, covOptional);

		    m_oBook.ReleaseDispatch();

	    }
	    if (m_oExcel.m_lpDispatch != NULL)
	    {
		    if(m_bCloseExcel)
			    m_oExcel.Quit();
		    m_oExcel.ReleaseDispatch();
	    }

	    return true;
    }
    EXCEL_CATCH_ALL
}

const CString ExcelAccessor::CalCurrentCell(void) const
{		
	return CalCurrentCell(m_nRow, m_nCol);
}

const CString ExcelAccessor::CalCurrentCell(int row, int col) const
{		

	TCHAR cellCol[3];

	if (col <= 26)
	{
		cellCol[0] = _T('A') + col  - 1 ;
		cellCol[1] = _T('\0');
	}
	else
	{
		cellCol[0] = _T('A') + (col-1) / 26-1;
		cellCol[1] = _T('A') + (col-1) % 26;
		cellCol[2] = _T('\0');
	}

	CString cell;
	cell.Format(_T("%s%d"), cellCol, row);

	return cell;
}


bool ExcelAccessor::AddSheet(LPCTSTR sheetname)
{
	try
	{
        CWorksheets oSheets = m_oBook.get_Worksheets();
        m_oSheet = oSheets.get_Item(COleVariant((short)1));
		CRange oRange = m_oSheet.get_Columns();
		if( m_sDefaultColWindth > 0 ) 
			oRange.put_ColumnWidth(COleVariant(m_sDefaultColWindth));
// 		oRange.AutoFit();
		oRange.ReleaseDispatch();

		m_oSheet = oSheets.Add(covOptional, covOptional, covOptional, covOptional);

		ResetPosition();
		m_oSheet.put_Name(sheetname);
		return true;
	}
	catch(...)
	{
		return false;
	}
}

void ExcelAccessor::Skip(int row, int col)
{
	m_nCol += col;
	m_nRow += row;
}

int ExcelAccessor::AddCell(long value)
{
	EXCEL_TRY
	{
		CRange oRange = m_oSheet.get_Range(COleVariant(CalCurrentCell()), covOptional);
		oRange.put_Value(covOptional, COleVariant(value));

		m_nCol++;

		return true;
	}
	EXCEL_CATCH_ALL
}

bool ExcelAccessor::Open(/*const CString &path, const CString &defaultSheetName*/)
{
    EXCEL_TRY
    {
	    // If you have not created Excel, create a new instance.
	    if (m_oExcel.m_lpDispatch == NULL) {
		    m_oExcel.CreateDispatch(_T("Excel.Application"));
	    }
	    ASSERT( m_oExcel.m_lpDispatch != NULL);

	    // Show Excel to the user.
	    if( m_bShowExcel )
	    {
		    m_oExcel.put_Visible(TRUE);
		    m_oExcel.put_UserControl(TRUE);
	    }

        // Disable all warning dialog when excel is running in Hide mode
        m_oExcel.put_DisplayAlerts(m_bShowExcel);

	    //Create new work book
	    //m_oExcel.put_SheetsInNewWorkbook(1);

    // 	TCHAR CurDir[MAX_PATH];
    // 	GetCurrentDirectory( MAX_PATH, CurDir);
    // 
    // 	m_oExcel.put_DefaultFilePath(CurDir);

	    //m_oBooks = m_oExcel.get_Workbooks();


	    return true;
    }
    EXCEL_CATCH_ALL

}

bool ExcelAccessor::OpenXls(const CString &name)
{
    EXCEL_TRY
	{
		CWorkbooks oBooks = m_oExcel.get_Workbooks();
		m_oBook = oBooks.Open(name, covOptional, covOptional, covOptional, covOptional, 
			covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional);
		ASSERT(m_oBook.m_lpDispatch != NULL);
        return true;
	}
    EXCEL_CATCH_ALL

}

bool ExcelAccessor::ShowXlsOnly(const CString &name)
{

    try
    {
		CApplication oExcel;
		CWorkbook oBook;


		// If you have not created Excel, create a new instance.
		if (oExcel.m_lpDispatch == NULL) {
			oExcel.CreateDispatch(_T("Excel.Application"));
		}

		// Show Excel to the user.
		//if ( m_bShowExcel)
		{
			oExcel.put_Visible(TRUE);
			oExcel.put_UserControl(TRUE);
		}

		CWorkbooks oBooks = oExcel.get_Workbooks();
		oBook = oBooks.Open(name, covOptional, covOptional, covOptional, covOptional, 
			covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional, covOptional);
		ASSERT(oBook.m_lpDispatch != NULL);

        oBook.ReleaseDispatch();
        oExcel.ReleaseDispatch();
        return true;
	}
    catch(...)
    {
        return false;
    }
}


bool ExcelAccessor::SetCurSheet(const CString &sheetName)
{
    EXCEL_TRY
    {
// 		if( NULL != m_oSheet.m_lpDispatch)
// 		{
// 			CRange orange = m_oSheet.get_Columns();
// 			orange.AutoFit();
// 		}
		
		ASSERT(m_oBook.m_lpDispatch != NULL);

		CWorksheets oSheets = m_oBook.get_Worksheets();

		m_oSheet = oSheets.get_Item( COleVariant(sheetName));
		ASSERT(m_oSheet.get_Name().CompareNoCase(sheetName) == 0);
		ResetPosition();
		return true;
    }
    EXCEL_CATCH_ALL

}


bool ExcelAccessor::SetCurSheet(short index)
{
    EXCEL_TRY
	{
// 		if( NULL != m_oSheet.m_lpDispatch)
// 		{
// 			CRange orange = m_oSheet.get_Columns();
// 			orange.AutoFit();
// 		}
		ASSERT(m_oBook.m_lpDispatch != NULL);

		CWorksheets oSheets = m_oBook.get_Worksheets();
		if( oSheets.get_Count() < index) return false;

		m_oSheet = oSheets.get_Item( COleVariant(index));
		m_oSheet.Activate();
		ResetPosition();

        return true;
	}
    EXCEL_CATCH_ALL
}

bool ExcelAccessor::GetAllSheetNames(CStringArray& sheetnames)
{
    EXCEL_TRY
    {
        ASSERT(m_oBook.m_lpDispatch != NULL);
        sheetnames.RemoveAll();

        CWorksheets oSheets = m_oBook.get_Worksheets();
        long cnt = oSheets.get_Count();
        
        for(short i = 1; i<= cnt; i++)
        {
            CWorksheet osheet = oSheets.get_Item( COleVariant(i));
            sheetnames.Add(osheet.get_Name());
                
        }

        return true;
    }
    EXCEL_CATCH_ALL
}


bool ExcelAccessor::WriteCellText( int row, int col, const CString& txt )
{
    EXCEL_TRY
    {

        ASSERT(m_oSheet.m_lpDispatch != NULL);

        CRange oRange = m_oSheet.get_Range(COleVariant(CalCurrentCell(row, col)), covOptional);
        oRange.put_Value(covOptional, COleVariant(txt.GetString()));
        return true;

   }
    EXCEL_CATCH_ALL

}


CString ExcelAccessor::ReadCellText(int row, int col)
{
	CString res;
	try 
	{
		ASSERT(m_oSheet.m_lpDispatch != NULL);

		CRange oRange = m_oSheet.get_Range(COleVariant(CalCurrentCell(row, col)), covOptional);

		
		VARIANT vText = oRange.get_Text();
		if( vText.vt == VT_BSTR)
		{
			if( vText.bstrVal != NULL)
			{
				res = CString(vText.bstrVal); 
				res.TrimLeft();
				res.TrimRight();
			}
		}
		VariantClear(&vText);
	}
	catch(...)
	{

	}
	return res;
}

bool ExcelAccessor::SaveAndClose()
{
	ResetPosition();
    EXCEL_TRY
    {
	    if (m_oSheet.m_lpDispatch != NULL)
	    {
		    CRange oRange = m_oSheet.get_Columns();
		    if( m_sDefaultColWindth > 0 ) 
			    oRange.put_ColumnWidth(COleVariant(m_sDefaultColWindth));
    // 		oRange.AutoFit();
		    oRange.ReleaseDispatch();
		    m_oSheet.ReleaseDispatch();
	    }
	    if (m_oBook.m_lpDispatch != NULL)
	    {
		    m_oBook.Save();
		    if(m_bCloseExcel)
			    m_oBook.Close(covOptional, covOptional, covOptional);
		    m_oBook.ReleaseDispatch();

	    }
	    if (m_oExcel.m_lpDispatch != NULL)
	    {
		    if(m_bCloseExcel)
			    m_oExcel.Quit();
		    m_oExcel.ReleaseDispatch();

	    }

	    return true;
    }
    EXCEL_CATCH_ALL

}

void ExcelAccessor::ResetPosition()
{
	m_nRow = m_nMinRow;
	m_nCol = m_nMinCol;
}

void ExcelAccessor::SetDefaultColumnWidth(short width)
{
	m_sDefaultColWindth = width;
}

bool ExcelAccessor::SetWrapText(bool bWrap)
{
	try
	{
		CRange oRange = m_oSheet.get_Range(COleVariant(CalCurrentCell()), covOptional);
		VARIANT vWrapText;
		vWrapText.vt = VT_BOOL;
		vWrapText.boolVal = bWrap? 1: 0;
		oRange.put_WrapText(vWrapText);
		return true;
	}
	catch(...)
	{
		return false;
	}

}

bool ExcelAccessor::SetLeftTop(int minrow, int mincol)
{
    m_nMinCol = mincol;
    m_nCol = m_nCol > mincol? m_nCol : mincol;

    m_nMinRow = minrow;
    m_nRow = m_nRow > minrow ? m_nRow : minrow;
    return true;
}

bool ExcelAccessor::RunMacro( const CString& macroname )
{
    EXCEL_TRY 
    {
    	CString	s;
        CString title = m_oBook.get_Name();
        //CString s="'"+title+"'!"+macroname;
        s.Format(_T("'%s'!%s"), title, macroname);
        m_oExcel.Run( COleVariant(s) , 
            covOptional, covOptional, covOptional, covOptional, covOptional, 
            covOptional, covOptional, covOptional, covOptional, covOptional, 
            covOptional, covOptional, covOptional, covOptional, covOptional, 
            covOptional, covOptional, covOptional, covOptional, covOptional, 
            covOptional, covOptional, covOptional, covOptional, covOptional, 
            covOptional, covOptional, covOptional, covOptional, covOptional
            
            );
        return true;
    }
    EXCEL_CATCH_ALL

}

bool ExcelAccessor::InsertRow( int row )
{
    EXCEL_TRY 
    {
        ASSERT(m_oSheet.m_lpDispatch);
        CString cname = CalCurrentCell(row, 1);

        CRange oRange = m_oSheet.get_Range(COleVariant(cname), covOptional);

        CRange rng = oRange.get_EntireRow(); 
        rng.Insert(covOptional, covOptional);
        return true;
    }
    EXCEL_CATCH_ALL

}

bool ExcelAccessor::DeleteRow( int row )
{
    EXCEL_TRY 
    {
        CString cname = CalCurrentCell(row, 1);

        CRange oRange = m_oSheet.get_Range(COleVariant(cname), covOptional);

        CRange rng = oRange.get_EntireRow(); 
        rng.Delete(covOptional);
        return true;
    }
    EXCEL_CATCH_ALL

}

bool ExcelAccessor::AutoFit()
{
    EXCEL_TRY
    {
        if( NULL != m_oSheet.m_lpDispatch)
        {
            CRange orange = m_oSheet.get_Columns();
            orange.AutoFit();
        }
        return true;
    }
    EXCEL_CATCH_ALL 


}


