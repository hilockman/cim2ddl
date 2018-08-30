// SimpleCurveWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "SimpleMCurveWnd.h"

extern	void	Log(const char* lpszLogFile, char* pformat, ...);
extern	const	char*	g_lpszLogFile;

#ifndef XDeviate
#	define	XDeviate	(m_fWndXUnit/5)
#endif
// CSimpleMCurveWnd

IMPLEMENT_DYNAMIC(CSimpleMCurveWnd, CWnd)

CSimpleMCurveWnd::CSimpleMCurveWnd()
{
	m_clrBackGround=RGB(0, 0, 0);
	m_clrForeGround=RGB(128, 128, 128);
	m_clrCurve=RGB(255, 0, 0);
	m_clrAxias=RGB(255, 255, 255);

	m_CurveArray.clear();
	m_nXGridNum=m_nYGridNum=10;
	m_strCurveName.clear();
	m_strXAxiasName.clear();
	m_strYAxiasName.clear();

	m_fWndXUnit = m_fWndYUnit = 0;

	m_nXFloatPoint = 0;
	m_nYFloatPoint = 3;

	m_bAutoMinX = m_bAutoMinY = 1;
	m_bAutoMaxX = m_bAutoMaxY = 1;
	m_fCurveMaxX = m_fCurveMaxY = 0;
	m_fCurveMinX = m_fCurveMinY = 0;
	m_fAxisMaxX = m_fAxisMaxY = 0;
	m_fAxisMinX = m_fAxisMinY = 0;
}

CSimpleMCurveWnd::~CSimpleMCurveWnd()
{
	m_CurveArray.clear();
}


BEGIN_MESSAGE_MAP(CSimpleMCurveWnd, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CSimpleCurveWnd 消息处理程序


void CSimpleMCurveWnd::DrawBack(CDC* pDC)
{
	register int	i;
	CRect	rect;

	CPen*		pPen;
	CPen*		pOldPen;
	CBrush*		pBrush;
	CBrush*		pOldBrush;
	CFont		font;
	CFont*		pOldFont;
	LOGFONT		logfont;
	COLORREF	TextColorSave;
	char		szFormat[260];
	char		szBuf[260];

	////////////////////////////////////////////////////////////////////
	//	画曲线框

	//	画背景
	GetClientRect(&rect);

	pBrush = new CBrush(m_clrBackGround);
	Log(g_lpszLogFile, "DrawBack BackColor=%d\n", m_clrBackGround);

	pOldBrush = pDC->SelectObject(pBrush);
	pDC->FillRect(rect, pBrush);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	if (m_nXGridNum <= 0 || m_nYGridNum <= 0)
		return;

	m_fWndXUnit=(double)rect.Width() /(m_nXGridNum+1);
	m_fWndYUnit=(double)rect.Height()/(m_nYGridNum+1);

	//	画网格线
	pPen=new CPen(PS_SOLID, 1, m_clrForeGround);
	pOldPen=pDC->SelectObject(pPen);
	for (i=0; i<m_nXGridNum; i++)		//	画纵线
	{
		pDC->MoveTo((int)(XDeviate+m_fWndXUnit+m_fWndXUnit*i), (int)m_fWndYUnit);
		pDC->LineTo((int)(XDeviate+m_fWndXUnit+m_fWndXUnit*i), (int)(m_nYGridNum*m_fWndYUnit));
		//Log(g_lpszLogFile, "Line i=%d X=%.3f\n", i+1, XDeviate+m_fWndXUnit+m_fWndXUnit*i);
	}

	for (i=0; i<m_nYGridNum; i++)							//	画横线
	{
		pDC->MoveTo((int)(XDeviate+m_fWndXUnit),								(int)(m_fWndYUnit+m_fWndYUnit*i));
		pDC->LineTo((int)(XDeviate+m_fWndXUnit+(m_nXGridNum-1)*m_fWndXUnit),	(int)(m_fWndYUnit+m_fWndYUnit*i));
	}

	pDC->SelectObject(pOldPen);
	delete	pPen;

	if (!GetMinMax())
		return;

	//	画曲线坐标
	logfont.lfHeight=(int)((m_fWndXUnit<m_fWndYUnit) ? m_fWndXUnit/2.2 : m_fWndYUnit/2.2);
	logfont.lfWidth=0;
	logfont.lfEscapement=0;
	logfont.lfOrientation=0;
	logfont.lfWeight=FW_BOLD;
	logfont.lfItalic=0;
	logfont.lfUnderline=0;
	logfont.lfStrikeOut=0;
	logfont.lfCharSet=ANSI_CHARSET;
	logfont.lfOutPrecision=OUT_DEFAULT_PRECIS;
	logfont.lfClipPrecision=CLIP_DEFAULT_PRECIS;
	logfont.lfQuality=PROOF_QUALITY;
	logfont.lfPitchAndFamily=VARIABLE_PITCH | FF_ROMAN;
#ifdef	UNICODE
	wcscpy(logfont.lfFaceName, _T("Times New Roman"));
#else
	strcpy(logfont.lfFaceName, "Times New Roman");
#endif

	font.CreateFontIndirect(&logfont);
	pOldFont=pDC->SelectObject(&font);
	TextColorSave=pDC->SetTextColor(m_clrAxias);

	double	fMax, fMin;
	fMin = (m_bAutoMinX) ? m_fCurveMinX : m_fAxisMinX;
	fMax = (m_bAutoMaxX) ? m_fCurveMaxX : m_fAxisMaxX;
	const	double	fUnitCurveX = (fMax-fMin)/(m_nXGridNum-1);

	fMin = (m_bAutoMinY) ? m_fCurveMinY : m_fAxisMinY;
	fMax = (m_bAutoMaxY) ? m_fCurveMaxY : m_fAxisMaxY;
	const	double	fUnitCurveY = (fMax-fMin)/(m_nYGridNum-1);

	//	画横坐标
	sprintf(szFormat, "%%.%df", m_nXFloatPoint);
	rect.top   =(int)(m_nYGridNum*m_fWndYUnit);
	rect.bottom=(int)((m_fWndXUnit<m_fWndYUnit) ? m_nYGridNum*m_fWndYUnit+m_fWndXUnit : m_nYGridNum*m_fWndYUnit+m_fWndYUnit);
	for (i=0; i<m_nXGridNum; i++)
	{
		if (m_bAutoMinX)
			sprintf(szBuf, szFormat, (m_fCurveMinX+i*fUnitCurveX));
		else
			sprintf(szBuf, szFormat, (m_fAxisMinX+i*fUnitCurveX));

		rect.left =(int)(XDeviate+m_fWndXUnit*(i+1) - m_fWndXUnit/2);
		rect.right=(int)(XDeviate+m_fWndXUnit*(i+1) + m_fWndXUnit/2);
		pDC->SetBkMode(TRANSPARENT);
		pDC->DrawText(szBuf, &rect, DT_SINGLELINE|DT_VCENTER|DT_CENTER);
	}

	//	画纵坐标
	sprintf(szFormat, "%%.%df", m_nYFloatPoint);
	rect.left =0;
	rect.right=(int)(m_fWndXUnit*1.0);
	for (i=0; i<m_nYGridNum; i++)
	{
		if (m_bAutoMinY)
			sprintf(szBuf, szFormat, (m_fCurveMinY+(m_nYGridNum-(i+1))*fUnitCurveY));
		else
			sprintf(szBuf, szFormat, (m_fAxisMinY+(m_nYGridNum-(i+1))*fUnitCurveY));

		rect.top   =(int)((i+1)*m_fWndYUnit-m_fWndYUnit/2);
		rect.bottom=(int)((i+1)*m_fWndYUnit+m_fWndYUnit/2);
		pDC->SetBkMode(TRANSPARENT);
		pDC->DrawText(szBuf, &rect, DT_SINGLELINE|DT_VCENTER|DT_RIGHT);
	}

	//	画曲线名
	rect.left =(int)(m_fWndXUnit);
	rect.right=(int)(11*m_fWndXUnit);
	rect.top   =(int)(0.1*m_fWndYUnit);
	rect.bottom=(int)(0.9*m_fWndYUnit);
	pDC->DrawText(m_strCurveName.c_str(), &rect, DT_SINGLELINE|DT_VCENTER|DT_CENTER);

	//	画Y
	rect.left =(int)(XDeviate+m_fWndXUnit-m_fWndXUnit/2);
	rect.right=(int)(XDeviate+m_fWndXUnit+m_fWndXUnit/2);
	rect.top   =(int)(0.1*m_fWndYUnit);
	rect.bottom=(int)(0.9*m_fWndYUnit);
	pDC->DrawText(m_strYAxiasName.c_str(), &rect, DT_SINGLELINE|DT_VCENTER|DT_CENTER);

	//	画X
	rect.left =(int)(XDeviate+(m_nXGridNum+0)*m_fWndXUnit);
	rect.right=(int)(XDeviate+(m_nXGridNum+1)*m_fWndXUnit);
	rect.top   =(int)(m_nYGridNum*m_fWndYUnit-0.5*m_fWndYUnit);
	rect.bottom=(int)(m_nYGridNum*m_fWndYUnit+0.5*m_fWndYUnit);
	pDC->DrawText(m_strXAxiasName.c_str(), &rect, DT_SINGLELINE|DT_VCENTER|DT_CENTER);

	pDC->SelectObject(pOldFont);
	pDC->SetTextColor(TextColorSave);
	font.DeleteObject();
}

void CSimpleMCurveWnd::DrawCurve(CDC* pDC)
{
	register int	i;
	int			nCurve;
	double		fX0, fY0, fX1, fY1;
	double		fMax, fMin;

	if (m_nXGridNum <= 0 || m_nYGridNum <= 0)
		return;

	if (m_fCurveMaxX <= m_fCurveMinX || m_fCurveMaxY <= m_fCurveMinY)
		return;

	CPen*	pPen;
	CPen*	pOldPen;
	
	fMin = (m_bAutoMinX) ? m_fCurveMinX : m_fAxisMinX;
	fMax = (m_bAutoMaxX) ? m_fCurveMaxX : m_fAxisMaxX;
	const	double	fUnitCurveX = (fMax-fMin)/(m_nXGridNum-1);
	fMin = (m_bAutoMinY) ? m_fCurveMinY : m_fAxisMinY;
	fMax = (m_bAutoMaxY) ? m_fCurveMaxY : m_fAxisMaxY;
	const	double	fUnitCurveY = (fMax-fMin)/(m_nYGridNum-1);
	if (fUnitCurveX < FLT_MIN || fUnitCurveY < FLT_MIN)
		return;
	const	double	fCurveMinX = (m_bAutoMinX) ? m_fCurveMinX : m_fAxisMinX;
	const	double	fCurveMinY = (m_bAutoMinY) ? m_fCurveMinY : m_fAxisMinY;

	for (nCurve=0; nCurve<(int)m_CurveArray.size(); nCurve++)
	{
		if (m_CurveArray[nCurve].sDataArray.empty())
			continue;

		pPen=new CPen(PS_SOLID, m_CurveArray[nCurve].nStroke, m_CurveArray[nCurve].clrCurve);
		pOldPen=pDC->SelectObject(pPen);

		//XDeviate+m_fWndXUnit+m_fWndXUnit*i;

		fX0=XDeviate+m_fWndXUnit			+m_fWndXUnit*(m_CurveArray[nCurve].sDataArray[0].fX-fCurveMinX)/fUnitCurveX;
		fY0=m_nYGridNum*m_fWndYUnit			-m_fWndYUnit*(m_CurveArray[nCurve].sDataArray[0].fY-fCurveMinY)/fUnitCurveY;

		//Log(g_lpszLogFile, "i=0 X=%.3f\n", fX0);
		for (i=1; i<(int)m_CurveArray[nCurve].sDataArray.size(); i++)
		{
			if (m_CurveArray[nCurve].sDataArray[i].fY <= -FLT_MAX || m_CurveArray[nCurve].sDataArray[i].fY >= FLT_MAX)
				continue;

			fX1=XDeviate+m_fWndXUnit		+m_fWndXUnit*(m_CurveArray[nCurve].sDataArray[i].fX-fCurveMinX)/fUnitCurveX;
			fY1=m_nYGridNum*m_fWndYUnit		-m_fWndYUnit*(m_CurveArray[nCurve].sDataArray[i].fY-fCurveMinY)/fUnitCurveY;
			pDC->MoveTo((int)fX0, (int)fY0);
			pDC->LineTo((int)fX1, (int)fY1);

			fX0=fX1;
			fY0=fY1;
			//Log(g_lpszLogFile, "i=%d X=%.3f\n", i, fX0);
		}
		pDC->SelectObject(pOldPen);
		delete	pPen;
	}
}

int CSimpleMCurveWnd::GetMinMax()
{
	register int	i;
	int		nCurve;

	if (m_CurveArray.empty())
		return 0;

	for (nCurve=0; nCurve<(int)m_CurveArray.size(); nCurve++)
		getSimpleCurveMinMax(m_CurveArray[nCurve]);

	m_fCurveMaxY=m_fCurveMaxX=-FLT_MAX;
	m_fCurveMinY=m_fCurveMinX=FLT_MAX;
	for (i=0; i<(int)m_CurveArray.size(); i++)
	{
		if (m_fCurveMaxX < m_CurveArray[i].fMaxX)
			m_fCurveMaxX=m_CurveArray[i].fMaxX;
		if (m_fCurveMinX > m_CurveArray[i].fMinX)
			m_fCurveMinX=m_CurveArray[i].fMinX;

		if (m_fCurveMaxY < m_CurveArray[i].fMaxY)
			m_fCurveMaxY=m_CurveArray[i].fMaxY;
		if (m_fCurveMinY > m_CurveArray[i].fMinY)
			m_fCurveMinY=m_CurveArray[i].fMinY;
	}

	if (m_fCurveMaxX <= m_fCurveMinX)
		return 0;
	if (m_fCurveMaxY < m_fCurveMinY)
		return 0;

	//Log(g_lpszLogFile, "GetMinMax Min(%.3f, %.1f), Max(%.3f, %.1f)\n", m_fMinCurveX, m_fMinCurveY, m_fMaxCurveX, m_fMaxCurveY);

	return 1;
}

void CSimpleMCurveWnd::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()
	DrawBack(&dc);
	DrawCurve(&dc);
}

void CSimpleMCurveWnd::ClearCurve(void)
{
	register int	i;
	for (i=0; i<(int)m_CurveArray.size(); i++)
		m_CurveArray[i].sDataArray.clear();
	m_CurveArray.clear();
	Invalidate();
}

void CSimpleMCurveWnd::AddCurve(tagSimpleCurve& cData)
{
	m_CurveArray.push_back(cData);
	Invalidate();
}

void CSimpleMCurveWnd::SetColor(COLORREF clrBack, COLORREF clrFore, COLORREF clrCurve, COLORREF clrAxias)
{
	m_clrBackGround=clrBack;
	m_clrForeGround=clrFore;
	m_clrCurve=clrCurve;
	m_clrAxias=clrAxias;
	Invalidate();
}

void CSimpleMCurveWnd::SetCurveGrid(const int nXPace, const int nYPace)
{
	m_nXGridNum=nXPace;
	m_nYGridNum=nYPace;
}

void CSimpleMCurveWnd::SetCurveName(const char* lpszCurveName)
{
	m_strCurveName=lpszCurveName;
}

void CSimpleMCurveWnd::SetXAxisName(const char* lpszXAxiasName)
{
	m_strXAxiasName=lpszXAxiasName;
}

void CSimpleMCurveWnd::SetYAxisName(const char* lpszYAxiasName)
{
	m_strYAxiasName=lpszYAxiasName;
}

void CSimpleMCurveWnd::SetXYFloatPoint(const int nXFPoint, const int nYFPoint)
{
	m_nXFloatPoint = nXFPoint;
	m_nYFloatPoint = nYFPoint;

	if (m_nXFloatPoint < 0)
		m_nXFloatPoint = 0;
	else if (m_nXFloatPoint > 4)
		m_nXFloatPoint = 4;

	if (m_nYFloatPoint < 0)
		m_nYFloatPoint = 0;
	else if (m_nYFloatPoint > 7)
		m_nYFloatPoint = 7;
}

void CSimpleMCurveWnd::SetXAxisMinMax(const unsigned char bMinAutoFit, const double fMinX, const unsigned char bMaxAutoFit, const double fMaxX)
{
	m_bAutoMinX = bMinAutoFit;
	m_bAutoMaxX = bMaxAutoFit;
	m_fAxisMinX = fMinX;
	m_fAxisMaxX = fMaxX;
}

void CSimpleMCurveWnd::SetYAxisMinMax(const unsigned char bMinAutoFit, const double fMinY, const unsigned char bMaxAutoFit, const double fMaxY)
{
	m_bAutoMinY = bMinAutoFit;
	m_bAutoMaxY = bMaxAutoFit;
	m_fAxisMinY = fMinY;
	m_fAxisMaxY = fMaxY;
}

int CSimpleMCurveWnd::ExportCurve(const char* lpszFileName)
{
	CMetaFileDC	mDC;
	mDC.CreateEnhanced(NULL, CString(lpszFileName), NULL, NULL);

	DrawBack(&mDC);
	DrawCurve(&mDC);

	HENHMETAFILE hemf=mDC.CloseEnhanced();
	DeleteEnhMetaFile(hemf);						//关闭图元句柄，完成图元的创建

	return 1;
}
