#pragma once

#include "MFCListCtrlEx.h"

// CSubListCtrlEx
#define	UM_SUBLISTCTRL_NMCLICKED		WM_APP+1024
#define	UM_SUBLISTCTRL_NMDBLCLK			WM_APP+1025

class CSubListCtrlEx : public CMFCListCtrlEx
{
	DECLARE_DYNAMIC(CSubListCtrlEx)

public:
	CSubListCtrlEx();
	virtual ~CSubListCtrlEx();
	void	SetParentWindow(CWnd* pParent)	{	m_pParentWnd=pParent;	};

protected:
	afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
	DECLARE_MESSAGE_MAP()

private:
	CWnd*	m_pParentWnd;
};
