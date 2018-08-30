// CheckComboBox.cpp 
//
// Written by Magnus Egelberg (magnus.egelberg@lundalogik.se)
//
// Copyright (C) 1999, Lundalogik AB, Sweden. All rights reserved.
// 
//

/////////////////////////////////////////////////////////////////////////////
//
// original source downloaded from :
//    http://www.codeproject.com/combobox/checkcombo.asp
//
// Modifications Copyright ?2004, PJ Arends
//
// Dec 2003 - Modified by PJ Arends (pja@telus.net) to show check
//            boxes in the static portion of the combobox
//          - removed the dependancy on the item data and used
//            an array instead, from the suggestion by Miszou at
//            http://www.codeproject.com/combobox/checkcombo.asp?msg=401000#xx401000xx
// Jan 2004 - improved the handling of check boxes in the drop down list
// Feb 2004 - added the BN_CLICKED message that is sent to the parent window
//            when the user changes a check box state
//          - small bug fix and code clean up.
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CheckComboBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static WNDPROC m_pWndProc = NULL;
static CCheckComboBox *m_pComboBox = NULL;

BEGIN_MESSAGE_MAP(CCheckComboBox, CComboBox)
	//{{AFX_MSG_MAP(CCheckComboBox)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_CONTROL_REFLECT_EX(CBN_DROPDOWN, OnDropDown)
	ON_MESSAGE(CB_ADDSTRING, OnAddString)
	ON_MESSAGE(CB_DELETESTRING, OnDeleteString)
	ON_MESSAGE(CB_INSERTSTRING, OnAddString)
	ON_MESSAGE(CB_RESETCONTENT, OnResetContent)
	ON_MESSAGE(WM_CTLCOLORLISTBOX, OnCtlColorListBox)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
//
//  ComboBoxListBoxProc  (Global window procedure)
//    Subclasses the combo box's dropdown list box
//
//  Parameters :
//    hWnd   [in] - The list box's window handle
//    nMsg   [in] - The current windows message
//    wParam [in] - The message's WPARAM parameter
//    lParam [in] - The message's LPARAM parameter
//
//  Returns :
//    0 if the message was handled here or else
//    whatever the default message handler returns
//
//  Note :
//    Sends a BN_CLICKED message to the parent window
//    when a checkbox is clicked
//
/////////////////////////////////////////////////////////////////////////////

extern "C" LRESULT FAR PASCAL ComboBoxListBoxProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	static bool bCloseOnLButtonUp = false;

	switch (nMsg)
	{
	case WM_CHAR:
		{
			if (wParam == VK_SPACE && (lParam & 1 << 30) == 0)
			{
				// Get the current selection
				INT nIndex = CallWindowProc(m_pWndProc, hWnd, LB_GETCURSEL, wParam, lParam);

				CRect rcItem;
				SendMessage(hWnd, LB_GETITEMRECT, nIndex, (LONG)(VOID *)&rcItem);
				InvalidateRect(hWnd, rcItem, FALSE);

				// Invert the check mark
				m_pComboBox->SetCheck(nIndex, !m_pComboBox->GetCheck(nIndex));

				// Notify that check state has changed
				m_pComboBox->GetParent()->SendMessage(WM_COMMAND, MAKELONG(GetWindowLong(m_pComboBox->m_hWnd, GWL_ID), BN_CLICKED), (LPARAM)m_pComboBox->m_hWnd);
				return 0;
			}
			break;
		}

	case WM_LBUTTONDBLCLK:
	case WM_LBUTTONDOWN:
		{
			CRect rc;
			GetClientRect(hWnd, rc);

			CPoint pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);

			if (PtInRect(rc, pt))
			{
				INT nItemHeight = SendMessage(hWnd, LB_GETITEMHEIGHT, 0, 0);
				INT nTopIndex   = SendMessage(hWnd, LB_GETTOPINDEX, 0, 0);

				// Compute which index to check/uncheck
				INT nIndex = nTopIndex + pt.y / nItemHeight;

				SendMessage(hWnd, LB_GETITEMRECT, nIndex, (LONG)(VOID *)&rc);

				if (PtInRect(rc, pt))
				{
					// Invalidate this window
					InvalidateRect(hWnd, rc, FALSE);

					// Notify that selection has changed
					m_pComboBox->GetParent()->SendMessage(WM_COMMAND, MAKELONG(GetWindowLong(m_pComboBox->m_hWnd, GWL_ID), CBN_SELCHANGE), (LPARAM)m_pComboBox->m_hWnd);

					// Was the click on the check box?
					HDC hdc = GetDC(hWnd);
					TEXTMETRIC metrics;
					GetTextMetrics(hdc, &metrics);
					ReleaseDC(hWnd, hdc);
					rc.right = rc.left + metrics.tmHeight + metrics.tmExternalLeading + 6;

					if (PtInRect(rc, pt))
					{
						// Toggle the check state
						m_pComboBox->SetCheck(nIndex, !m_pComboBox->GetCheck(nIndex));

						// Notify that check state has changed
						m_pComboBox->GetParent()->SendMessage(WM_COMMAND, MAKELONG(GetWindowLong(m_pComboBox->m_hWnd, GWL_ID), BN_CLICKED), (LPARAM)m_pComboBox->m_hWnd);
					}
					else
					{
						bCloseOnLButtonUp = true;
					}
				}
			}

			// Do the default handling now
			break;
		}

	case WM_LBUTTONUP:
		{
			if (!bCloseOnLButtonUp)
				return 0;
			bCloseOnLButtonUp = false;
		}
	}

	return CallWindowProc(m_pWndProc, hWnd, nMsg, wParam, lParam);
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::CCheckComboBox()  (public member function)
//    Class constructor. Initializes member variables
//
//  Parameters :
//    None
//
//  Returns :
//    Nothing
//
/////////////////////////////////////////////////////////////////////////////

CCheckComboBox::CCheckComboBox()
{
	m_hListBox = NULL;
	m_bItemHeightSet = FALSE;
	//m_CheckArray.SetSize(0, 10);
	m_CheckArray.clear();
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::CheckAll  (public member function)
//    Checks/unchecks all items in the list
//
//  Parameters :
//    bCheck [in] - The new check state of all the check boxes
//
//  Returns :
//    Nothing
//
/////////////////////////////////////////////////////////////////////////////

void CCheckComboBox::CheckAll(BOOL bCheck)
{
	int nCount = GetCount();

	for (int i = 0; i < nCount; i++)
		SetCheck(i, bCheck);
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::Create  (public member function)
//    Creates the CCheckComboBox in any window
//
//  Parameters :
//    dwStyle    [in] - Windows and ComboBox control styles ( WS_* and CBS_* )
//    rect       [in] - The position and size of the control
//    pParentWnd [in] - Pointer to the control's parent window
//    nID        [in] - the control's ID
//
//  Returns :
//    Nothing
//
/////////////////////////////////////////////////////////////////////////////

BOOL CCheckComboBox::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	// Remove the CBS_SIMPLE and CBS_DROPDOWN styles and add the one I'm designed for
	dwStyle &= ~(CBS_SIMPLE | CBS_DROPDOWN); // 0xF;
	dwStyle |= CBS_DROPDOWNLIST;

	// Make sure to use the CBS_OWNERDRAWVARIABLE style
	dwStyle |= CBS_OWNERDRAWVARIABLE;

	return CComboBox::Create(dwStyle, rect, pParentWnd, nID);
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::DrawItem  (protected member function)
//    Called by the framework when a visual aspect of an owner-draw combo box
//     changes. 
//
//  Parameters :
//    lpDrawItemStruct [in] - A pointer to a DRAWITEMSTRUCT structure that
//     contains information about the type of drawing required.
//
//  Returns :
//    Nothing
//
/////////////////////////////////////////////////////////////////////////////

void CCheckComboBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	if (static_cast<int>(lpDrawItemStruct->itemID) < 0 && GetCount() > 0)
	{
		SetCurSel(0); // forces an item to be selected and will cause WM_DRAWITEM to be sent again
		return;
	}

	HDC dc = lpDrawItemStruct->hDC;

	CRect rcBitmap = lpDrawItemStruct->rcItem;
	CRect rcText   = lpDrawItemStruct->rcItem;

	CString strText;

	// 0 - No check, 1 - Empty check, 2 - Checked
	INT nCheck = 0;

	// ensure there is an item to draw
	if (static_cast<int>(lpDrawItemStruct->itemID) >= 0)
	{ 
		GetLBText(lpDrawItemStruct->itemID, strText);
		nCheck = 1 + GetCheck(lpDrawItemStruct->itemID);

		TEXTMETRIC metrics;
		GetTextMetrics(dc, &metrics);

		rcBitmap.left    = 0;
		rcBitmap.right   = rcBitmap.left + metrics.tmHeight + metrics.tmExternalLeading + 6;
		rcBitmap.top    += 1;
		rcBitmap.bottom -= 1;

		rcText.left = rcBitmap.right;
	}

	if (nCheck > 0)
	{
		SetBkColor(dc, GetSysColor(COLOR_WINDOW));
		SetTextColor(dc, GetSysColor(COLOR_WINDOWTEXT));

		UINT nState = DFCS_BUTTONCHECK;

		if (nCheck > 1)
			nState |= DFCS_CHECKED;

		if (!IsWindowEnabled())
			nState |= DFCS_INACTIVE;

		// Draw the checkmark using DrawFrameControl
		DrawFrameControl(dc, rcBitmap, DFC_BUTTON, nState);
	}

	if (lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		SetBkColor(dc, GetSysColor(COLOR_HIGHLIGHT));
		SetTextColor(dc, GetSysColor(COLOR_HIGHLIGHTTEXT));
	}
	else
	{
		if (IsWindowEnabled())
		{
			SetBkColor(dc, GetSysColor(COLOR_WINDOW));
			SetTextColor(dc, GetSysColor(COLOR_WINDOWTEXT));
		}
		else
		{
			SetBkColor(dc, GetSysColor(COLOR_3DFACE));
			SetTextColor(dc, GetSysColor(COLOR_GRAYTEXT));
		}
	}

	// Erase and draw
	ExtTextOut(dc, 0, 0, ETO_OPAQUE, &rcText, 0, 0, 0);
	DrawText(dc, ' ' + strText, strText.GetLength() + 1, &rcText, DT_SINGLELINE|DT_VCENTER|DT_END_ELLIPSIS);

	if ((lpDrawItemStruct->itemState & (ODS_FOCUS|ODS_SELECTED)) == (ODS_FOCUS|ODS_SELECTED))
		DrawFocusRect(dc, &rcText);
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::GetCheck  (public member function)
//    Gets the check state of an item in the list
//
//  Parameters :
//    nIndex [in] - The index of the item to check
//
//  Returns :
//    TRUE if the item is checked
//    FALSE if not
//
/////////////////////////////////////////////////////////////////////////////

BOOL CCheckComboBox::GetCheck(int nIndex)
{
	//return (m_CheckArray.GetAt(nIndex) ? TRUE : FALSE);
	return (m_CheckArray[nIndex] ? TRUE : FALSE);
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::MeasureItem  (protected member function)
//    Called by the framework when a combo box with an owner-draw style is created.
//
//  Parameters :
//    lpMeasureItemStruct [in/out] - A pointer to a MEASUREITEMSTRUCT structure.
//
//  Returns :
//    Nothing
//
/////////////////////////////////////////////////////////////////////////////

void CCheckComboBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	CClientDC dc(this);
	CFont *pFont = dc.SelectObject(GetFont());

	if (pFont != 0)
	{
		TEXTMETRIC metrics;
		dc.GetTextMetrics(&metrics);

		lpMeasureItemStruct->itemHeight = metrics.tmHeight + metrics.tmExternalLeading;

		// An extra height of 2 looks good I think. 
		// Otherwise the list looks a bit crowded...
		lpMeasureItemStruct->itemHeight += 2;

		// This is needed since the WM_MEASUREITEM message is sent before
		// MFC hooks everything up if used in a dialog. So adjust the
		// static portion of the combo box now
		if (!m_bItemHeightSet)
		{
			m_bItemHeightSet = TRUE;
			SetItemHeight(-1, lpMeasureItemStruct->itemHeight);
		}

		dc.SelectObject(pFont);
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::OnAddString  (protected member function)
//    Handles the CB_ADDSTRING and CB_INSERTSTRING messages
//     Adds a new entry into the m_CheckArray array
//
//  Parameters :
//    None
//
//  Returns :
//    The index of the new string
//
/////////////////////////////////////////////////////////////////////////////

LRESULT CCheckComboBox::OnAddString(WPARAM, LPARAM)
{
	int	nNewVal=0;
	int nIndex = Default();
	if (nIndex >= 0)
	{
		m_CheckArray.insert(m_CheckArray.begin()+nIndex, 1, 0);
		//m_CheckArray.InsertAt(nIndex, 0, 1);
	}
	return nIndex;
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::OnChar  (protected member function)
//    Handles the WM_CHAR message.
//     Uses the space bar to toggle the check state of the currently selected item
//
//  Parameters :
//    nChar   [in] - The virtual key code
//    nRepCnt [in] - not used here, passed on to the base class
//    nFlags  [in] - Uses the previous button state bit
//
//  Returns :
//    Nothing
//
//  Note :
//    Sends a BN_CLICKED message to the parent window
//
/////////////////////////////////////////////////////////////////////////////

void CCheckComboBox::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (nChar == VK_SPACE && !GetDroppedState() && (nFlags & 1 << 14) == 0)
	{
		int nIndex = GetCurSel();
		if (nIndex != CB_ERR)
		{
			SetCheck(nIndex, !GetCheck(nIndex));
			GetParent()->SendMessage(WM_COMMAND, MAKEWPARAM(GetDlgCtrlID(), BN_CLICKED), (LPARAM)m_hWnd);
			return;
		}
	}
	CComboBox::OnChar(nChar, nRepCnt, nFlags);
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::OnCtlColorListBox  (protected member function)
//    Handles the WM_CTLCOLORLISTBOX that is sent by the drop down list box
//     to the combo box. It is used here to grab the HWND of the list box so
//     we can subclass it.
//
//  Parameters :
//     lParam [in] - The list box's handle
//
//  Returns :
//    Whatever the default message handler returns
//
/////////////////////////////////////////////////////////////////////////////

LRESULT CCheckComboBox::OnCtlColorListBox(WPARAM, LPARAM lParam) 
{
	// If the listbox hasn't been subclassed yet, do so...
	if (m_hListBox == NULL)
	{
		HWND hWnd = reinterpret_cast<HWND>(lParam);

		if (hWnd != 0 && hWnd != m_hWnd)
		{
			// Save the listbox handle
			m_hListBox = hWnd;

			// Do the subclassing
			m_pWndProc = reinterpret_cast<WNDPROC>(GetWindowLong(m_hListBox, GWLP_WNDPROC));
			SetWindowLong(m_hListBox, GWLP_WNDPROC, reinterpret_cast<long>(ComboBoxListBoxProc));
		}
	}

	return Default();
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::OnDeleteString  (protected member function)
//    Handles the CB_DELETESTRING message
//     Deletes the corresponding entry in the m_CheckArray array
//
//  Parameters :
//    wp [in] - The index of the item to delete
//
//  Returns :
//    The number of items left
//
/////////////////////////////////////////////////////////////////////////////

LRESULT CCheckComboBox::OnDeleteString(WPARAM wp, LPARAM)
{
	int nCount = Default();
	if (nCount != CB_ERR)
		m_CheckArray.erase(m_CheckArray.begin()+wp);
	//m_CheckArray.RemoveAt(wp);
	return nCount;
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::OnDropDown  (protected member function)
//    Handles the CBN_DROPDOWN notification message
//     Sets the global m_pComboBox variable to this control so that the
//     ComboboxListBoxProc knows which combo box it is handling
//
//  Parameters :
//    None
//
//  Returns :
//    FALSE
//
/////////////////////////////////////////////////////////////////////////////

BOOL CCheckComboBox::OnDropDown() 
{
	m_pComboBox = this;
	return FALSE; // Parent window will also receive this notification
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::OnKeyDown  (protected member function)
//    Handles the WM_KEYDOWN message
//     Prevents the space bar from resetting the current selection
//     to zero before the OnChar handler has had a chance to run.
//
//  Parameters :
//    nChar   [in] - The virtual key code
//    nRepCnt [in] - not used here, passed on to the base class
//    nFlags  [in] - not used here, passed on to the base class
//
//  Returns :
//    Nothing
//
/////////////////////////////////////////////////////////////////////////////

void CCheckComboBox::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (nChar == VK_SPACE)
		return;

	CComboBox::OnKeyDown(nChar, nRepCnt, nFlags);
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::OnLButtonDblClk  (protected member function)
//    Handles the WM_LBUTTONDBLCLK message.
//     Makes the second click of a double click act as another click
//
//  Parameters :
//    nFlags [in] - not used here, passed on to the base class
//    point  [in] - not used here, passed on to the base class
//
//  Returns :
//    Nothing
//
/////////////////////////////////////////////////////////////////////////////

void CCheckComboBox::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	OnLButtonDown(nFlags, point);
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::OnLButtonDown  (protected member function)
//    Handles the WM_LBUTTONDOWN message.
//     Toggles the check state of the currently selected item when the user
//     clicks on the check box in the static text area of the control.
//
//  Parameters :
//    nFlags [in] - not used here, passed on to the base class
//    point  [in] - the location of the mouse cursor
//
//  Returns :
//    Nothing
//
//  Note :
//    Sends a BN_CLICKED message to the parent window
//
/////////////////////////////////////////////////////////////////////////////

void CCheckComboBox::OnLButtonDown(UINT nFlags, CPoint point) 
{
	int nIndex = GetCurSel();
	if (!GetDroppedState() && nIndex != CB_ERR)
	{
		CClientDC dc(this);
		TEXTMETRIC metrics;
		GetTextMetrics(dc, &metrics);

		CRect rc;
		GetClientRect(&rc);

		rc.right = metrics.tmHeight + metrics.tmExternalLeading + 6;

		if (rc.PtInRect(point))
		{
			if (GetFocus() != this)
				SetFocus();
			SetCheck(nIndex, !GetCheck(nIndex));
			GetParent()->SendMessage(WM_COMMAND, MAKEWPARAM(GetDlgCtrlID(), BN_CLICKED), (LPARAM)m_hWnd);
			return;
		}
	}
	CComboBox::OnLButtonDown(nFlags, point);
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::OnResetContent  (protected member function)
//    Handles the CB_RESETCONTENT message
//     Clears the m_CheckArray array
//
//  Parameters :
//    None
//
//  Returns :
//    CB_OKAY
//
/////////////////////////////////////////////////////////////////////////////

LRESULT CCheckComboBox::OnResetContent(WPARAM, LPARAM)
{
	//m_CheckArray.RemoveAll();
	m_CheckArray.clear();
	return Default();
}

/////////////////////////////////////////////////////////////////////////////
//
//  CCheckComboBox::SetCheck  (public member function)
//    Checks/unchecks an item in the list
//
//  Parameters :
//    nIndex [in] - The index of the item to check
//    bCheck [in] - The new check state
//
//  Returns :
//    The previous check state
//
/////////////////////////////////////////////////////////////////////////////

BOOL CCheckComboBox::SetCheck(int nIndex, BOOL bCheck)
{
	bCheck = bCheck ? TRUE : FALSE;
	BOOL ret = GetCheck(nIndex);
	if (ret != bCheck)
	{
		//m_CheckArray.SetAt(nIndex, (BYTE)bCheck);
		m_CheckArray[nIndex]=bCheck;

		// Redraw the window
		Invalidate(FALSE);
	}

	return ret;
}

/////////////////////////////////////////////////////////////////////////////
//
//  End of CheckComboBox.cpp
//
/////////////////////////////////////////////////////////////////////////////
