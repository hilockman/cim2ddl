
// GCStateEstimateServerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#define ID_DIALOG_TIMER			180
#define	DIALOG_STEP_PACE		1000

// CGCStateEstimateServerDlg 对话框
class CGCStateEstimateServerDlg : public CDialog
{
// 构造
public:
	CGCStateEstimateServerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GCSTATEESTIMATE_SERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedStartNetSvr();
	afx_msg void OnBnClickedStopNetSvr();
	afx_msg void OnEnChangeLocalPort();
	afx_msg void OnEnChangeRemotePort();
	afx_msg void OnEnChangeRemoteAddr();
	afx_msg void OnBnClickedClearMesg();
	afx_msg void OnBnClickedJsonWrite();
	afx_msg void OnBnClickedComm();
	afx_msg void OnBnClickedJsonRead();
	afx_msg LRESULT OnShowMessage(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	void	ClearMessage();
	void	PrintMessage(char* pformat, ...);

private:
	void		FormRecordJSon(tagPRBlock* pPRBlock, const int nTable, const int nRecord, Json::Value& sField);
	std::string	FormJsonString(const int nEstimateFState);
	int			GetTextLen(LPCTSTR lpszText);

public:
};
