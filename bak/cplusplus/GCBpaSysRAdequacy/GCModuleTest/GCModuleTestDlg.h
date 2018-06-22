
// GCModuleTestDlg.h : 头文件
//

#pragma once


// CGCModuleTestDlg 对话框
class CGCModuleTestDlg : public CDialog
{
// 构造
public:
	CGCModuleTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GCMODULETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedDatBrowse();
	afx_msg void OnBnClickedSwiBrowse();
	afx_msg void OnBnClickedRparamBrowse();
	afx_msg void OnBnClickedGenbusLoadAsaux();
	afx_msg void OnEnChangeDc2acFactor();
	afx_msg void OnBnClickedBpaLoader();
	afx_msg void OnBnClickedBpa2pr();
	afx_msg void OnBnClickedStateSample();
	afx_msg void OnBnClickedStateEstimate();
	afx_msg void OnBnClickedReliabilityIndex();
	afx_msg void OnEnChangeRemoteAddr();
	afx_msg void OnEnChangeRemotePort();
	afx_msg void OnEnChangeLocalPort();
	afx_msg void OnBnClickedNetworkDataready();
	afx_msg LRESULT OnShowMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedClearMesg();
	afx_msg void OnBnClickedNetworkJobfinished();
	afx_msg void OnBnClickedNetworkStateEstimate();
	afx_msg void OnEnChangeThreadNum();
	DECLARE_MESSAGE_MAP()

private:
	int		m_nSampleType;
	int		m_nPRSampleObject;
	std::vector<int>	m_nThreadArray;

private:
	void	ResolveRParam();
private:
	std::string	FormCommandJSon(const char* lpszCommand, const unsigned char bSendSetting = 0);

public:
	void	ClearMessage();
	void	PrintMessage(char* pformat, ...);
private:
	int		GetTextLen(LPCTSTR lpszText);
public:
};
