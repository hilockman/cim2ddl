#pragma once

// CGCStateEstimateCalculateThread

class CGCStateEstimateCalculateThread : public CWinThread
{
	DECLARE_DYNCREATE(CGCStateEstimateCalculateThread)

public:
	CGCStateEstimateCalculateThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CGCStateEstimateCalculateThread();
	unsigned char	m_bIdle;

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	afx_msg void	OnCalculate(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnQuit(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

public:
	int		Create(CWnd* pMainWnd, CWinThread* pParent, const int nThreadID, tagBpaPRAdequacySetting* pSetting, const char* lpszRemoteAddr, const int nRemotePort);
	void	Close();

private:
	CWnd*		m_pMainWnd;
	CWinThread*	m_pParentThread;	//	消息响应窗口
	char		m_szRemoteAddr[48];
	int			m_nRemotePort;

private:
	void		SendMessageToWindow(char* pformat, ...);
	std::string	FormResultJSon(tagPRBlock* pPRBlock, const char* lpszMesg, const int nEstimateState);
	std::string	FormResultJSon(const char* lpszCommand, const char* lpszRetValue, const char* lpszMesg);
	void		FormRecordJSon(tagPRBlock* pPRBlock, const int nTable, const int nRecord, Json::Value& sField);

private:
	int							m_nWorkMemID;
	CPRAdequacyStateEstimate*	m_pPREstimate;
	tagPRBlock*					m_pPRWorkBlock;
	CPRMemDBInterface			m_PRMemDBInterface;
	tagBpaPRAdequacySetting		m_PRAdequacySetting;
};


