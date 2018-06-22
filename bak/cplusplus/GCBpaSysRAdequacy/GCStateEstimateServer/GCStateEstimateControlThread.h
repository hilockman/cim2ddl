#pragma once

#include "GCStateEstimateCalculateThread.h"
// CGCStateEstimateControlThread

class CGCStateEstimateControlThread : public CWinThread
{
	DECLARE_DYNCREATE(CGCStateEstimateControlThread)

public:
	CGCStateEstimateControlThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CGCStateEstimateControlThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	afx_msg void	OnConnect(WPARAM wParam, LPARAM lParam);
	afx_msg void	OnQuit(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

public:
	int		Create(CWnd* pMainWnd, CWinThread* pParent, const char* lpszRemoteAddr, const int nRemotePort);
	void	Close();

private:
	CWnd*		m_pMainWnd;
	CWinThread*	m_pParentThread;	//	消息响应窗口
	char		m_szRemoteAddr[48];
	int			m_nRemotePort;
	std::vector<CGCStateEstimateCalculateThread*>	m_pDataProcThreadArray;

private:
	int		NetworkDataProcess(std::string strRecv);

	int		DataReady(tagBpaPRAdequacySetting* pSetting);
	int		FinishJob();


private:
	void		ParsePRSetting(Json::Value& sData, tagBpaPRAdequacySetting* pSetting);
	std::string	FormResultJSon(const char* lpszCommand, const char* lpszRetValue, const char* lpszMesg);
	void		SendMessageToWindow(char* pformat, ...);
};


