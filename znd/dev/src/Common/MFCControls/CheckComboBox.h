#if !defined(AFX_CHECKCOMBOBOX_H__66750D93_95DB_11D3_9325_444553540000__INCLUDED_)
#define AFX_CHECKCOMBOBOX_H__66750D93_95DB_11D3_9325_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxcoll.h>  // for CByteArray

class CCheckComboBox : public CComboBox
{
public:
    CCheckComboBox();

    BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

    // Selects/unselects the specified item
    BOOL SetCheck(int nIndex, BOOL bCheck = TRUE);

    // Returns checked state
    BOOL GetCheck(int nIndex);

    // Checks all/unchecks all
    void CheckAll(BOOL bCheck = TRUE);

protected:
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CCheckComboBox)
    protected:
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
    //}}AFX_VIRTUAL

    //{{AFX_MSG(CCheckComboBox)
    afx_msg LRESULT OnCtlColorListBox(WPARAM wParam, LPARAM lParam);
    afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    //}}AFX_MSG
    afx_msg BOOL OnDropDown();
    afx_msg LRESULT OnAddString(WPARAM wp, LPARAM lp);
    afx_msg LRESULT OnDeleteString(WPARAM wp, LPARAM lp);
    afx_msg LRESULT OnResetContent(WPARAM wp, LPARAM lp);
    DECLARE_MESSAGE_MAP()

protected:
    //CByteArray m_CheckArray;
	std::vector<int>	m_CheckArray;

    // The subclassed COMBOLBOX window (notice the 'L')
    HWND m_hListBox;

    // A flag used in MeasureItem, see comments there
    BOOL m_bItemHeightSet;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKCOMBOBOX_H__66750D93_95DB_11D3_9325_444553540000__INCLUDED_)
