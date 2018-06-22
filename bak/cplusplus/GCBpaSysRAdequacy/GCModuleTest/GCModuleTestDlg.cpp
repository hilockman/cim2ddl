
// GCModuleTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GCModuleTest.h"
#include "GCModuleTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGCModuleTestDlg 对话框
static	unsigned char	m_bFreezeUI = 0;
CGCModuleTestDlg::CGCModuleTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGCModuleTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_nSampleType = 0;
	m_nPRSampleObject=0;
	m_nThreadArray.clear();
}

void CGCModuleTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_PRCOMP_ALL, m_nPRSampleObject);
	DDX_Radio(pDX, IDC_MONTECARLO, m_nSampleType);
}

BEGIN_MESSAGE_MAP(CGCModuleTestDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_DAT_BROWSE, &CGCModuleTestDlg::OnBnClickedDatBrowse)
	ON_BN_CLICKED(IDC_SWI_BROWSE, &CGCModuleTestDlg::OnBnClickedSwiBrowse)
	ON_BN_CLICKED(IDC_RPARAM_BROWSE, &CGCModuleTestDlg::OnBnClickedRparamBrowse)
	ON_EN_CHANGE(IDC_MAXFAULT_GEN, &CGCModuleTestDlg::ResolveRParam)
	ON_EN_CHANGE(IDC_MAXFAULT_BRAN, &CGCModuleTestDlg::ResolveRParam)
	ON_EN_CHANGE(IDC_MCS_SIMULATETIME, &CGCModuleTestDlg::ResolveRParam)
	ON_EN_CHANGE(IDC_MCS_MINSTATEPROB, &CGCModuleTestDlg::ResolveRParam)
	ON_EN_CHANGE(IDC_FST_MAXCUMUPROB, &CGCModuleTestDlg::ResolveRParam)
	ON_EN_CHANGE(IDC_FST_MINSTATEPROB, &CGCModuleTestDlg::ResolveRParam)
	ON_EN_CHANGE(IDC_FST_MAXSTATE, &CGCModuleTestDlg::ResolveRParam)
	ON_EN_CHANGE(IDC_STS_MAXSTATE, &CGCModuleTestDlg::ResolveRParam)
	ON_EN_CHANGE(IDC_ANA_MINSTATEPROB, &CGCModuleTestDlg::ResolveRParam)

	ON_BN_CLICKED(IDC_PRCOMP_ALL, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_PRCOMP_LT, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_PRCOMP_GEN, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_MONTECARLO, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_ANALYTICAL, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_STATESAMPLE, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_FASTSORT, &CGCModuleTestDlg::ResolveRParam)

	ON_BN_CLICKED(IDC_LINE_LIMIT, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_TRAN_LIMIT, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_GEN_ELIMIT, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_UPFC_ELIMIT, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_UPFC_ADJUSTRC, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_AUXLOAD_ADJUST, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_EQGEN_ADJUST, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_EQLOAD_ADJUST, &CGCModuleTestDlg::ResolveRParam)
	ON_EN_CHANGE(IDC_ISLAND_MINIMAL_GLRATIO, &CGCModuleTestDlg::ResolveRParam)

	ON_BN_CLICKED(IDC_GENBUS_LOAD_ASAUX, &CGCModuleTestDlg::ResolveRParam)
	ON_EN_CHANGE(IDC_DC2AC_FACTOR, &CGCModuleTestDlg::ResolveRParam)
	ON_BN_CLICKED(IDC_BPA_LOADER, &CGCModuleTestDlg::OnBnClickedBpaLoader)
	ON_BN_CLICKED(IDC_BPA_2PR, &CGCModuleTestDlg::OnBnClickedBpa2pr)
	ON_BN_CLICKED(IDC_STATE_SAMPLE, &CGCModuleTestDlg::OnBnClickedStateSample)
	ON_BN_CLICKED(IDC_STATE_ESTIMATE, &CGCModuleTestDlg::OnBnClickedStateEstimate)
	ON_BN_CLICKED(IDC_RELIABILITY_INDEX, &CGCModuleTestDlg::OnBnClickedReliabilityIndex)

	ON_EN_CHANGE(IDC_REMOTE_ADDR, &CGCModuleTestDlg::OnEnChangeRemoteAddr)
	ON_EN_CHANGE(IDC_REMOTE_PORT, &CGCModuleTestDlg::OnEnChangeRemotePort)
	ON_EN_CHANGE(IDC_LOCAL_PORT, &CGCModuleTestDlg::OnEnChangeLocalPort)
	ON_BN_CLICKED(IDC_NETWORK_DATAREADY, &CGCModuleTestDlg::OnBnClickedNetworkDataready)
	ON_BN_CLICKED(IDC_CLEAR_MESG, &CGCModuleTestDlg::OnBnClickedClearMesg)
	ON_MESSAGE(UM_MESSAGE,			OnShowMessage)
	ON_BN_CLICKED(IDC_NETWORK_JOBFINISHED, &CGCModuleTestDlg::OnBnClickedNetworkJobfinished)
	ON_BN_CLICKED(IDC_NETWORK_STATEESTIMATE, &CGCModuleTestDlg::OnBnClickedNetworkStateEstimate)
	ON_EN_CHANGE(IDC_THREAD_NUM, &CGCModuleTestDlg::OnEnChangeThreadNum)
END_MESSAGE_MAP()


// CGCModuleTestDlg 消息处理程序

BOOL CGCModuleTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	char	szBuf[260];

	m_bFreezeUI = 1;

	m_nPRSampleObject = g_PRAdeSetting.nPRSampleObject ;
	m_nSampleType = g_PRAdeSetting.nPRSampleMethod-1 ;

	((CButton*)GetDlgItem(IDC_GENBUS_LOAD_ASAUX))->SetCheck(g_PRAdeSetting.bGenBusLoadAsAux);
	sprintf(szBuf, "%.3f", g_PRAdeSetting.fDc2AcFactor);		GetDlgItem(IDC_DC2AC_FACTOR)->SetWindowText(szBuf);

	GetDlgItem(IDC_BPADAT_FILE)		->SetWindowText(g_PRAdeSetting.strBpaDatFile.c_str());
	GetDlgItem(IDC_BPASWI_FILE)		->SetWindowText(g_PRAdeSetting.strBpaSwiFile.c_str());
	GetDlgItem(IDC_BPA_RPARAM_FILE)	->SetWindowText(g_PRAdeSetting.strBpaRParamFile.c_str());

	sprintf(szBuf, "%d", g_PRAdeSetting.nMaxGenFault);		GetDlgItem(IDC_MAXFAULT_GEN)->SetWindowText(szBuf);
	sprintf(szBuf, "%d", g_PRAdeSetting.nMaxBranFault);		GetDlgItem(IDC_MAXFAULT_BRAN)->SetWindowText(szBuf);
	sprintf(szBuf, "%d", g_PRAdeSetting.nMCSSimulateTime);	GetDlgItem(IDC_MCS_SIMULATETIME)->SetWindowText(szBuf);
	sprintf(szBuf, "%g", g_PRAdeSetting.fMCSMinStateProb);	GetDlgItem(IDC_MCS_MINSTATEPROB)->SetWindowText(szBuf);
	sprintf(szBuf, "%d", g_PRAdeSetting.nFSTMaxStateNum);	GetDlgItem(IDC_FST_MAXSTATE)->SetWindowText(szBuf);
	sprintf(szBuf, "%f", g_PRAdeSetting.fFSTMaxCumuProb);	GetDlgItem(IDC_FST_MAXCUMUPROB)->SetWindowText(szBuf);
	sprintf(szBuf, "%g", g_PRAdeSetting.fFSTMinStateProb);	GetDlgItem(IDC_FST_MINSTATEPROB)->SetWindowText(szBuf);
	sprintf(szBuf, "%d", g_PRAdeSetting.nSTSMaxStateNum);	GetDlgItem(IDC_STS_MAXSTATE)->SetWindowText(szBuf);
	sprintf(szBuf, "%g", g_PRAdeSetting.fANAMinStateProb);	GetDlgItem(IDC_ANA_MINSTATEPROB)->SetWindowText(szBuf);

	((CButton*)GetDlgItem(IDC_LINE_LIMIT))		->SetCheck(g_PRAdeSetting.bLineELimit);
	((CButton*)GetDlgItem(IDC_TRAN_LIMIT))		->SetCheck(g_PRAdeSetting.bTranELimit);
	((CButton*)GetDlgItem(IDC_GEN_ELIMIT))		->SetCheck(g_PRAdeSetting.bGenPELimit);
	((CButton*)GetDlgItem(IDC_UPFC_ELIMIT))		->SetCheck(g_PRAdeSetting.bUPFCELimit);
	((CButton*)GetDlgItem(IDC_UPFC_ADJUSTRC))	->SetCheck(g_PRAdeSetting.bUPFCAdjustRC);
	((CButton*)GetDlgItem(IDC_AUXLOAD_ADJUST))	->SetCheck(g_PRAdeSetting.bAuxLoadAdjust);
	((CButton*)GetDlgItem(IDC_EQGEN_ADJUST))	->SetCheck(g_PRAdeSetting.bEQGenAdjust);
	((CButton*)GetDlgItem(IDC_EQLOAD_ADJUST))	->SetCheck(g_PRAdeSetting.bEQLoadAdjust);

	sprintf(szBuf, "%.3f", g_PRAdeSetting.fMinIslandGLRatio);	GetDlgItem(IDC_ISLAND_MINIMAL_GLRATIO)->SetWindowText(szBuf);

	((CButton*)GetDlgItem(IDC_GENBUS_LOAD_ASAUX))->SetCheck(g_PRAdeSetting.bGenBusLoadAsAux);
	sprintf(szBuf, "%.3f", g_PRAdeSetting.fDc2AcFactor);		GetDlgItem(IDC_DC2AC_FACTOR)->SetWindowText(szBuf);

	GetDlgItem(IDC_REMOTE_ADDR)->SetWindowText(g_szRemoteAddr);
	sprintf(szBuf, "%d", g_nRemotePort);
	GetDlgItem(IDC_REMOTE_PORT)->SetWindowText(szBuf);
	sprintf(szBuf, "%d", g_nLocalPort);
	GetDlgItem(IDC_LOCAL_PORT)->SetWindowText(szBuf);
	sprintf(szBuf, "%d", g_nThreadNum);
	GetDlgItem(IDC_THREAD_NUM)->SetWindowText(szBuf);

	m_bFreezeUI = 0;

	StartNetworkService(g_nLocalPort);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGCModuleTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGCModuleTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int CGCModuleTestDlg::GetTextLen(LPCTSTR lpszText)
{
	ASSERT(AfxIsValidString(lpszText));

	CDC *pDC = GetDC();
	ASSERT(pDC);

	CSize size;
	CFont* pOldFont = pDC->SelectObject(GetFont());
	if ((GetStyle() & LBS_USETABSTOPS) == 0)
	{
		size = pDC->GetTextExtent(lpszText, (int) _tcslen(lpszText));
		size.cx += 3;
	}
	else
	{
		// Expand tabs as well
		size = pDC->GetTabbedTextExtent(lpszText, (int) _tcslen(lpszText), 0, NULL);
		size.cx += 2;
	}
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	return size.cx;
}

LRESULT CGCModuleTestDlg::OnShowMessage(WPARAM wParam, LPARAM lParam)
{
	const char*	pChar = (char*)lParam;
	CListBox*	pListBox=(CListBox*)GetDlgItem(IDC_MESG_LIST);
	int	iExt = GetTextLen(pChar);
	if (iExt > pListBox->GetHorizontalExtent())
		pListBox->SetHorizontalExtent(iExt);
	pListBox->AddString(pChar);
	pListBox->SetCurSel(pListBox->GetCount()-1);
	GlobalFree((HGLOBAL)pChar);

	return 0;
}

void CGCModuleTestDlg::ClearMessage()
{
	CListBox*	pListBox=(CListBox*)GetDlgItem(IDC_MESG_LIST);
	pListBox->ResetContent();
}

void CGCModuleTestDlg::PrintMessage(char* pformat, ...)
{
	va_list args;
	va_start( args, pformat );

	char	szMesg[1024];
	CListBox*	pListBox=(CListBox*)GetDlgItem(IDC_MESG_LIST);

	if (pListBox->GetCount() > 2400)
		pListBox->ResetContent();

	vsprintf(szMesg, pformat, args);

	int	iExt = GetTextLen(szMesg);
	if (iExt > pListBox->GetHorizontalExtent())
		pListBox->SetHorizontalExtent(iExt);
	pListBox->AddString(szMesg);
	pListBox->SetCurSel(pListBox->GetCount()-1);

	va_end(args);
}

void CGCModuleTestDlg::ResolveRParam()
{
	if (m_bFreezeUI)
		return;

	char	szBuffer[260];

	UpdateData();

	g_PRAdeSetting.nPRSampleObject = m_nPRSampleObject;
	switch (m_nSampleType)
	{
	case	0:	g_PRAdeSetting.nPRSampleMethod = PRFState_SamplingMethod_MonteCarlo;	break;
	case	1:	g_PRAdeSetting.nPRSampleMethod = PRFState_SamplingMethod_StateSample;	break;
	case	2:	g_PRAdeSetting.nPRSampleMethod = PRFState_SamplingMethod_Analytical;	break;
	case	3:	g_PRAdeSetting.nPRSampleMethod = PRFState_SamplingMethod_FastSort;		break;
	default:	g_PRAdeSetting.nPRSampleMethod = PRFState_SamplingMethod_Unknown;		break;
	}

	GetDlgItem(IDC_MAXFAULT_GEN)->GetWindowText(szBuffer, 260);					g_PRAdeSetting.nMaxGenFault=atoi(szBuffer);
	GetDlgItem(IDC_MAXFAULT_BRAN)->GetWindowText(szBuffer, 260);				g_PRAdeSetting.nMaxBranFault=atoi(szBuffer);
	GetDlgItem(IDC_MCS_SIMULATETIME)->GetWindowText(szBuffer, 260);				g_PRAdeSetting.nMCSSimulateTime=atoi(szBuffer);
	GetDlgItem(IDC_MCS_MINSTATEPROB)->GetWindowText(szBuffer, 260);				g_PRAdeSetting.fMCSMinStateProb=atof(szBuffer);
	GetDlgItem(IDC_FST_MAXCUMUPROB)->GetWindowText(szBuffer, 260);				g_PRAdeSetting.fFSTMaxCumuProb=atof(szBuffer);
	GetDlgItem(IDC_FST_MAXSTATE)->GetWindowText(szBuffer, 260);					g_PRAdeSetting.nFSTMaxStateNum=atoi(szBuffer);
	GetDlgItem(IDC_FST_MINSTATEPROB)->GetWindowText(szBuffer, 260);				g_PRAdeSetting.fFSTMinStateProb=atof(szBuffer);
	GetDlgItem(IDC_STS_MAXSTATE)->GetWindowText(szBuffer, 260);					g_PRAdeSetting.nSTSMaxStateNum=atoi(szBuffer);
	GetDlgItem(IDC_ANA_MINSTATEPROB)->GetWindowText(szBuffer, 260);				g_PRAdeSetting.fANAMinStateProb=atof(szBuffer);

	g_PRAdeSetting.bLineELimit		= ((CButton*)GetDlgItem(IDC_LINE_LIMIT))	->GetCheck();
	g_PRAdeSetting.bTranELimit		= ((CButton*)GetDlgItem(IDC_TRAN_LIMIT))	->GetCheck();
	g_PRAdeSetting.bGenPELimit		= ((CButton*)GetDlgItem(IDC_GEN_ELIMIT))	->GetCheck();
	g_PRAdeSetting.bUPFCELimit		= ((CButton*)GetDlgItem(IDC_UPFC_ELIMIT))	->GetCheck();
	g_PRAdeSetting.bAuxLoadAdjust	= ((CButton*)GetDlgItem(IDC_AUXLOAD_ADJUST))->GetCheck();
	g_PRAdeSetting.bEQGenAdjust		= ((CButton*)GetDlgItem(IDC_EQGEN_ADJUST))	->GetCheck();
	g_PRAdeSetting.bEQLoadAdjust	= ((CButton*)GetDlgItem(IDC_EQLOAD_ADJUST))	->GetCheck();
	g_PRAdeSetting.bUPFCAdjustRC	= ((CButton*)GetDlgItem(IDC_UPFC_ADJUSTRC))	->GetCheck();

	GetDlgItem(IDC_ISLAND_MINIMAL_GLRATIO)->GetWindowText(szBuffer, 260);	g_PRAdeSetting.fMinIslandGLRatio=atof(szBuffer);

	g_PRAdeSetting.bGenBusLoadAsAux = ((CButton*)GetDlgItem(IDC_GENBUS_LOAD_ASAUX))->GetCheck();
	GetDlgItem(IDC_DC2AC_FACTOR)->GetWindowText(szBuffer, 260);					g_PRAdeSetting.fDc2AcFactor=atof(szBuffer);
	if (g_PRAdeSetting.fDc2AcFactor < 1 || g_PRAdeSetting.fDc2AcFactor > 2)
		g_PRAdeSetting.fDc2AcFactor=1.15;

	SaveBpaPRAdequacySetting(&g_PRAdeSetting);
}

void CGCModuleTestDlg::OnBnClickedDatBrowse()
{
	// TODO: 在此添加控件通知处理程序代码
	CString	fileExt=_T("dat");
	CString	defaultFileName=g_PRAdeSetting.strBpaDatFile.c_str();
	CString	fileFilter=_T("BPA潮流文件(*.dat)|*.dat;*.DAT|所有文件(*.*)|*.*||");
	DWORD	dwFlags = OFN_ENABLESIZING | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR;

	CFileDialog	dlg(TRUE,fileExt,
		defaultFileName,
		dwFlags,
		fileFilter,
		NULL);

	dlg.m_ofn.lpstrTitle=_T("打开BPA潮流文件");
	dlg.m_ofn.lpstrInitialDir=_T("");
	dlg.m_ofn.lStructSize=sizeof(dlg.m_ofn);

	if (dlg.DoModal() == IDCANCEL)
		return;

	g_PRAdeSetting.strBpaDatFile = dlg.GetPathName();
	GetDlgItem(IDC_BPADAT_FILE)->SetWindowText(g_PRAdeSetting.strBpaDatFile.c_str());
	SaveBpaPRAdequacySetting(&g_PRAdeSetting);
}

void CGCModuleTestDlg::OnBnClickedSwiBrowse()
{
	// TODO: 在此添加控件通知处理程序代码
	CString	fileExt=_T("swi");
	CString	defaultFileName=g_PRAdeSetting.strBpaSwiFile.c_str();
	CString	fileFilter=_T("BPA稳定文件(*.swi)|*.swi;*.SWI|所有文件(*.*)|*.*||");
	DWORD	dwFlags = OFN_ENABLESIZING | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR;

	CFileDialog	dlg(TRUE,fileExt,
		defaultFileName,
		dwFlags,
		fileFilter,
		NULL);

	dlg.m_ofn.lpstrTitle=_T("打开BPA稳定文件");
	dlg.m_ofn.lpstrInitialDir=_T("");
	dlg.m_ofn.lStructSize=sizeof(dlg.m_ofn);

	if (dlg.DoModal() == IDCANCEL)
		return;

	g_PRAdeSetting.strBpaSwiFile = dlg.GetPathName();
	GetDlgItem(IDC_BPASWI_FILE)->SetWindowText(g_PRAdeSetting.strBpaSwiFile.c_str());
	SaveBpaPRAdequacySetting(&g_PRAdeSetting);
}

void CGCModuleTestDlg::OnBnClickedRparamBrowse()
{
	// TODO: 在此添加控件通知处理程序代码
	CString	fileExt=_T("XML");
	CString	defaultFileName=g_PRAdeSetting.strBpaRParamFile.c_str();
	CString	fileFilter=_T("可靠性设备参数文件(*.xml)|*.xml;*.XML|所有文件(*.*)|*.*||");
	DWORD	dwFlags = OFN_ENABLESIZING | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR;

	CFileDialog	dlg(TRUE,fileExt,
		defaultFileName,
		dwFlags,
		fileFilter,
		NULL);

	dlg.m_ofn.lpstrTitle=_T("可靠性设备参数文件");
	dlg.m_ofn.lpstrInitialDir=_T("");
	dlg.m_ofn.lStructSize=sizeof(dlg.m_ofn);

	if (dlg.DoModal() == IDCANCEL)
		return;

	g_PRAdeSetting.strBpaRParamFile = dlg.GetPathName();
	GetDlgItem(IDC_BPA_RPARAM_FILE)->SetWindowText(g_PRAdeSetting.strBpaRParamFile.c_str());
	SaveBpaPRAdequacySetting(&g_PRAdeSetting);
}

void CGCModuleTestDlg::OnBnClickedBpaLoader()
{
	// TODO: 在此添加控件通知处理程序代码
	char	szExce[260];
	sprintf(szExce, "%s/GCBPALoader %s %s %s", g_szRunDir, g_szRunDir, g_PRAdeSetting.strBpaDatFile.c_str(), g_PRAdeSetting.strBpaSwiFile.c_str());
	Log(g_lpszLogFile, "Exec = %s\n", szExce);
	system(szExce);
}

void CGCModuleTestDlg::OnBnClickedBpa2pr()
{
	// TODO: 在此添加控件通知处理程序代码
	char	szExce[260];
	sprintf(szExce, "%s/GCBPA2PR %s %s %s %s", g_szRunDir, g_szRunDir, g_PRAdeSetting.strBpaDatFile.c_str(), g_PRAdeSetting.strBpaSwiFile.c_str(), g_PRAdeSetting.strBpaRParamFile.c_str());
	Log(g_lpszLogFile, "Exec = %s\n", szExce);
	system(szExce);
}

void CGCModuleTestDlg::OnBnClickedStateSample()
{
	// TODO: 在此添加控件通知处理程序代码
	char	szBuffer[260];
	std::string	strExec;

	strExec.clear();
	sprintf(szBuffer, "%s/GCStateSample %s ", g_szRunDir, g_szRunDir);	strExec.append(szBuffer);
	sprintf(szBuffer, "%d ", g_PRAdeSetting.nPRSampleObject);		strExec.append(szBuffer); //抽样对象类型，全部；支路；发电机
	sprintf(szBuffer, "%d ", g_PRAdeSetting.nPRSampleMethod);		strExec.append(szBuffer); //抽样类型
	sprintf(szBuffer, "%d ", g_PRAdeSetting.nMaxGenFault);			strExec.append(szBuffer); // 抽样最大发电机故障重数
	sprintf(szBuffer, "%d ", g_PRAdeSetting.nMaxBranFault);			strExec.append(szBuffer); //抽样最大支路故障重数
	sprintf(szBuffer, "%d ", g_PRAdeSetting.nMCSSimulateTime);		strExec.append(szBuffer); //MCS最大抽样仿真时长
	sprintf(szBuffer, "%f ", g_PRAdeSetting.fMCSMinStateProb);		strExec.append(szBuffer); //MCS[蒙特卡罗]设备故障概率门槛值
	sprintf(szBuffer, "%f ", g_PRAdeSetting.fFSTMaxCumuProb);		strExec.append(szBuffer); //FST[快速排序]累积概率
	sprintf(szBuffer, "%f ", g_PRAdeSetting.fFSTMinStateProb);		strExec.append(szBuffer); //FST[快速排序]设备故障概率门槛值
	sprintf(szBuffer, "%d ", g_PRAdeSetting.nFSTMaxStateNum);		strExec.append(szBuffer); //FST[快速排序]最大状态数
	sprintf(szBuffer, "%d ", g_PRAdeSetting.nSTSMaxStateNum);		strExec.append(szBuffer); //STS[状态抽样]最大状态数
	sprintf(szBuffer, "%f ", g_PRAdeSetting.fANAMinStateProb);		strExec.append(szBuffer); //ANA[解析法]设备故障概率门槛值

	Log(g_lpszLogFile, "Exec = %s\n", strExec.c_str());
	system(strExec.c_str());
}

void CGCModuleTestDlg::OnBnClickedStateEstimate()
{
	// TODO: 在此添加控件通知处理程序代码
	char	szBuffer[260];
	std::string	strExec;

	strExec.clear();
	sprintf(szBuffer, "%s/GCStateEstimate %s ", g_szRunDir, g_szRunDir);	strExec.append(szBuffer);
	sprintf(szBuffer, "%f ", g_PRAdeSetting.fDc2AcFactor);		strExec.append(szBuffer); //直流潮流2 交流潮流系数
	sprintf(szBuffer, "%d ", g_PRAdeSetting.bLineELimit);		strExec.append(szBuffer); //线路消限
	sprintf(szBuffer, "%d ", g_PRAdeSetting.bTranELimit);		strExec.append(szBuffer); //主变消限
	sprintf(szBuffer, "%d ", g_PRAdeSetting.bGenPELimit);		strExec.append(szBuffer); //调整发电机消限
	sprintf(szBuffer, "%d ", g_PRAdeSetting.bUPFCELimit);		strExec.append(szBuffer); //调整UPFC消限
	sprintf(szBuffer, "%d ", g_PRAdeSetting.bAuxLoadAdjust);	strExec.append(szBuffer); //厂用电参与消限
	sprintf(szBuffer, "%d ", g_PRAdeSetting.bEQGenAdjust);		strExec.append(szBuffer); //等值发电机参与消限
	sprintf(szBuffer, "%d ", g_PRAdeSetting.bEQLoadAdjust);		strExec.append(szBuffer); //等值负荷参与消限
	sprintf(szBuffer, "%f ", g_PRAdeSetting.fMinIslandGLRatio);	strExec.append(szBuffer); //孤岛的最小容载比
	sprintf(szBuffer, "%d ", g_PRAdeSetting.bUPFCAdjustRC);		strExec.append(szBuffer); //UPFC采用变容法

	Log(g_lpszLogFile, "Exec = %s\n", strExec.c_str());
	system(strExec.c_str());
}


void CGCModuleTestDlg::OnBnClickedReliabilityIndex()
{
	// TODO: 在此添加控件通知处理程序代码
	char	szExce[260];
	sprintf(szExce, "%s/GCReliabilityIndex %s %f", g_szRunDir, g_szRunDir, g_PRAdeSetting.fDc2AcFactor);
	Log(g_lpszLogFile, "Exec = %s\n", szExce);
	system(szExce);
}

void CGCModuleTestDlg::OnEnChangeRemoteAddr()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	if (m_bFreezeUI)
		return;

	char	szBuffer[260];
	GetDlgItem(IDC_REMOTE_ADDR)->GetWindowText(szBuffer, 260);
	if (strlen(szBuffer) > 0)
	{
		strcpy(g_szRemoteAddr, szBuffer);
	}
}

void CGCModuleTestDlg::OnEnChangeRemotePort()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	if (m_bFreezeUI)
		return;

	char	szBuffer[260];
	GetDlgItem(IDC_REMOTE_PORT)->GetWindowText(szBuffer, 260);
	int		nPort=atoi(szBuffer);
	if (nPort != g_nRemotePort && nPort != 0)
	{
		g_nRemotePort=atoi(szBuffer);
	}
}

void CGCModuleTestDlg::OnEnChangeLocalPort()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	if (m_bFreezeUI)
		return;

	char	szBuffer[260];
	GetDlgItem(IDC_LOCAL_PORT)->GetWindowText(szBuffer, 260);
	int		nPort=atoi(szBuffer);
	if (nPort != g_nLocalPort && nPort != 0)
	{
		g_nLocalPort=atoi(szBuffer);
	}
}

void CGCModuleTestDlg::OnEnChangeThreadNum()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	if (m_bFreezeUI)
		return;

	SYSTEM_INFO sysInfo;
	::GetSystemInfo(&sysInfo);

	char	szBuffer[260];
	GetDlgItem(IDC_THREAD_NUM)->GetWindowText(szBuffer, 260);
	g_nThreadNum=atoi(szBuffer);
	if (g_nThreadNum <= 0)
		g_nThreadNum=1;
	if (g_nThreadNum > sysInfo.dwNumberOfProcessors)
		g_nThreadNum=sysInfo.dwNumberOfProcessors;
}

void CGCModuleTestDlg::OnBnClickedClearMesg()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox*	pListBox=(CListBox*)GetDlgItem(IDC_MESG_LIST);
	pListBox->ResetContent();
}

void CGCModuleTestDlg::OnBnClickedNetworkDataready()
{
	// TODO: 在此添加控件通知处理程序代码
	char	szBuf[260];
	GetDlgItem(IDC_THREAD_NUM)->GetWindowText(szBuf, 260);
	SendNetworkData(g_szRemoteAddr, g_nRemotePort, FormCommandJSon(Command_DataReady, 1).c_str());
	m_nThreadArray.resize(atoi(szBuf), 0);
}

void CGCModuleTestDlg::OnBnClickedNetworkJobfinished()
{
	// TODO: 在此添加控件通知处理程序代码
	SendNetworkData(g_szRemoteAddr, g_nRemotePort, FormCommandJSon(Command_JobFinished, 0).c_str());
}

std::string	CGCModuleTestDlg::FormCommandJSon(const char* lpszCommand, const unsigned char bSendSetting)
{
	Json::Value			sRoot;
	Json::Value			sContent;
	Json::Value			sObject;
	Json::FastWriter	sWriter;

	ResolveRParam();

	sRoot["Command"] = lpszCommand;

	if (bSendSetting)
	{
		sObject["BpaDatFile"] = g_PRAdeSetting.strBpaDatFile;				//潮流输入文件
		sObject["BpaSwiFile"] = g_PRAdeSetting.strBpaSwiFile;				//稳定输入文件，主要是用于形成发电机模型
		sObject["BpaRParamFile"] = g_PRAdeSetting.strBpaRParamFile;			//可靠性参数输入文件
// 		sprintf(szBuffer, "%f", g_PRAdeSetting.fTinyGenThreshold);	sObject["TinyGenThreshold"] = szBuffer;	//环辐网分解发电机容量门槛值（容量低于该门槛值的发电机认为不是发电机）
// 		sprintf(szBuffer, "%f", g_PRAdeSetting.fLowVoltThreshold);	sObject["LowVoltThreshold"] = szBuffer;	//环辐网分解发电机低电压门槛值（电压低于该门槛值的发电机认为是负荷而不是发电）
// 		sprintf(szBuffer, "%f", g_PRAdeSetting.fZIL				);	sObject["ZIL"] = szBuffer;				//小阻抗清除小阻抗门槛值
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.nPRSampleObject	);	sObject["PRSampleObject"] = szBuffer;	//抽样对象（全部、发电、支路）
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.nPRSampleMethod	);	sObject["PRSampleMethod"] = szBuffer;	//抽样类型
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.nMaxGenFault		);	sObject["MaxGenFault"] = szBuffer;		//MCS, FST, STS, ANA 抽样最大发电机故障重数
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.nMaxBranFault	);	sObject["MaxBranFault"] = szBuffer;		//MCS, FST, STS, ANA 抽样最大支路故障重数
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.bLineELimit		);	sObject["LineELimit"] = szBuffer;		//线路消限开关
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.bTranELimit		);	sObject["TranELimit"] = szBuffer;		//主变消限开关
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.bGenPELimit		);	sObject["GenPELimit"] = szBuffer;		//发电机参与消限
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.bUPFCELimit		);	sObject["UPFCELimit"] = szBuffer;		//UPFC参与消限
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.bAuxLoadAdjust	);	sObject["AuxLoadAdjust"] = szBuffer;	//厂用电负荷参与调整
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.bEQGenAdjust		);	sObject["EQGenAdjust"] = szBuffer;		//等值发电机参与调整
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.bEQLoadAdjust	);	sObject["EQLoadAdjust"] = szBuffer;		//等值发电机参与调整
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.nMCSSimulateTime	);	sObject["MCSSimulateTime"] = szBuffer;	//MCS最大抽样仿真时长
// 		sprintf(szBuffer, "%f", g_PRAdeSetting.fMCSMinStateProb	);	sObject["MCSMinStateProb"] = szBuffer;	//MCS.get(蒙特卡罗]设备故障概率门槛值
// 		sprintf(szBuffer, "%f", g_PRAdeSetting.fFSTMaxCumuProb	);	sObject["FSTMaxCumuProb"] = szBuffer;	//FST.get(快速排序]累积概率
// 		sprintf(szBuffer, "%f", g_PRAdeSetting.fFSTMinStateProb	);	sObject["FSTMinStateProb"] = szBuffer;	//FST.get(快速排序]设备故障概率门槛值
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.nFSTMaxStateNum	);	sObject["FSTMaxStateNum"] = szBuffer;	//FST.get(快速排序]最大状态数
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.nSTSMaxStateNum	);	sObject["STSMaxStateNum"] = szBuffer;	//STS.get(状态抽样]最大状态数
// 		sprintf(szBuffer, "%f", g_PRAdeSetting.fANAMinStateProb	);	sObject["ANAMinStateProb"] = szBuffer;	//ANA.get( 解析法]设备故障概率门槛值
// 		sprintf(szBuffer, "%f", g_PRAdeSetting.fDc2AcFactor		);	sObject["Dc2AcFactor"] = szBuffer;		//直流潮流2 交流潮流系数
// 		sprintf(szBuffer, "%f", g_PRAdeSetting.fMinIslandGLRatio);	sObject["MinIslandGLRatio"] = szBuffer;	//孤岛的最小容载比
// 		sprintf(szBuffer, "%d", g_nThreadNum					);	sObject["MultiThread"] = szBuffer;	//线程数
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.bUPFCAdjustRC	);	sObject["UPFCAdjustRC"] = szBuffer;		//UPFC采用调整容量法
// 		sprintf(szBuffer, "%d", g_PRAdeSetting.bGenBusLoadAsAux	);	sObject["GenBusLoadAsAux"] = szBuffer;	//发电机母线负荷按厂用电处理

		sObject["TinyGenThreshold"] = g_PRAdeSetting.fTinyGenThreshold	;	//环辐网分解发电机容量门槛值（容量低于该门槛值的发电机认为不是发电机）
		sObject["LowVoltThreshold"] = g_PRAdeSetting.fLowVoltThreshold	;	//环辐网分解发电机低电压门槛值（电压低于该门槛值的发电机认为是负荷而不是发电）
		sObject["ZIL"]				= g_PRAdeSetting.fZIL				;	//小阻抗清除小阻抗门槛值
		sObject["PRSampleObject"]	= g_PRAdeSetting.nPRSampleObject	;	//抽样对象（全部、发电、支路）
		sObject["PRSampleMethod"]	= g_PRAdeSetting.nPRSampleMethod	;	//抽样类型
		sObject["MaxGenFault"]		= g_PRAdeSetting.nMaxGenFault		;	//MCS, FST, STS, ANA 抽样最大发电机故障重数
		sObject["MaxBranFault"]		= g_PRAdeSetting.nMaxBranFault		;	//MCS, FST, STS, ANA 抽样最大支路故障重数
		sObject["LineELimit"]		= g_PRAdeSetting.bLineELimit		;	//线路消限开关
		sObject["TranELimit"]		= g_PRAdeSetting.bTranELimit		;	//主变消限开关
		sObject["GenPELimit"]		= g_PRAdeSetting.bGenPELimit		;	//发电机参与消限
		sObject["UPFCELimit"]		= g_PRAdeSetting.bUPFCELimit		;	//UPFC参与消限
		sObject["AuxLoadAdjust"]	= g_PRAdeSetting.bAuxLoadAdjust		;	//厂用电负荷参与调整
		sObject["EQGenAdjust"]		= g_PRAdeSetting.bEQGenAdjust		;	//等值发电机参与调整
		sObject["EQLoadAdjust"]		= g_PRAdeSetting.bEQLoadAdjust		;	//等值发电机参与调整
		sObject["MCSSimulateTime"]	= g_PRAdeSetting.nMCSSimulateTime	;	//MCS最大抽样仿真时长
		sObject["MCSMinStateProb"]	= g_PRAdeSetting.fMCSMinStateProb	;	//MCS.get(蒙特卡罗]设备故障概率门槛值
		sObject["FSTMaxCumuProb"]	= g_PRAdeSetting.fFSTMaxCumuProb	;	//FST.get(快速排序]累积概率
		sObject["FSTMinStateProb"]	= g_PRAdeSetting.fFSTMinStateProb	;	//FST.get(快速排序]设备故障概率门槛值
		sObject["FSTMaxStateNum"]	= g_PRAdeSetting.nFSTMaxStateNum	;	//FST.get(快速排序]最大状态数
		sObject["STSMaxStateNum"]	= g_PRAdeSetting.nSTSMaxStateNum	;	//STS.get(状态抽样]最大状态数
		sObject["ANAMinStateProb"]	= g_PRAdeSetting.fANAMinStateProb	;	//ANA.get( 解析法]设备故障概率门槛值
		sObject["Dc2AcFactor"]		= g_PRAdeSetting.fDc2AcFactor		;	//直流潮流2 交流潮流系数
		sObject["MinIslandGLRatio"] = g_PRAdeSetting.fMinIslandGLRatio	;	//孤岛的最小容载比
		sObject["MultiThread"]		= g_nThreadNum						;	//线程数
		sObject["UPFCAdjustRC"]		= g_PRAdeSetting.bUPFCAdjustRC		;	//UPFC采用调整容量法
		sObject["GenBusLoadAsAux"]	= g_PRAdeSetting.bGenBusLoadAsAux	;	//发电机母线负荷按厂用电处理

		sContent["PRAdequacySetting"] = sObject;
	}

	sRoot["Content"] = sContent;

	return sWriter.write(sRoot);
}

void CGCModuleTestDlg::OnBnClickedNetworkStateEstimate()
{
	// TODO: 在此添加控件通知处理程序代码
	PRStateEstimateCalculateDispatch(AfxGetMainWnd(), g_pPRBlock);
}
