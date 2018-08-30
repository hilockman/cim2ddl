// SimpleCurveWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "SimpleCurveWnd.h"

#ifndef XDeviate
#	define	XDeviate	0
#endif
// CSimpleCurveWnd

IMPLEMENT_DYNAMIC(CSimpleCurveWnd, CWnd)

CSimpleCurveWnd::CSimpleCurveWnd()
{
	m_clrBackGround=RGB(0, 0, 0);
	m_clrForeGround=RGB(128, 128, 128);
	m_clrCurve=RGB(255, 0, 0);
	m_clrAxias=RGB(255, 255, 255);

	m_nXGridNum=m_nYGridNum=10;
	m_bAutoMinX = m_bAutoMinY = 1;
	m_bAutoMaxX = m_bAutoMaxY = 1;
	m_fAxisMaxX = 0;
	m_fAxisMaxY = 0;
	m_fAxisMinX = 0;
	m_fAxisMinX = 0;

	initSimpleCurve(m_Curve);
}

CSimpleCurveWnd::~CSimpleCurveWnd()
{
	initSimpleCurve(m_Curve);
}


BEGIN_MESSAGE_MAP(CSimpleCurveWnd, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CSimpleCurveWnd 消息处理程序

void CSimpleCurveWnd::DrawBack(CDC* pDC)
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
	char		szBuf[260], szFormat[260];

	////////////////////////////////////////////////////////////////////
	//	画曲线框

	//	画背景
	GetClientRect(&rect);

	pBrush = new CBrush(m_clrBackGround);
	pOldBrush = pDC->SelectObject(pBrush);
	pDC->FillRect(rect, pBrush);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	m_fWndXUnit=(double)rect.Width() /(m_nXGridNum+1);
	m_fWndYUnit=(double)rect.Height()/(m_nYGridNum+1);

	//	画网格线
	pPen=new CPen(PS_SOLID, 1, m_clrForeGround);
	pOldPen=pDC->SelectObject(pPen);
	for (i=0; i<m_nXGridNum; i++)			//	画纵线
	{
		pDC->MoveTo((int)(XDeviate+m_fWndXUnit+m_fWndXUnit*i), (int)m_fWndYUnit);
		pDC->LineTo((int)(XDeviate+m_fWndXUnit+m_fWndXUnit*i), (int)(m_nYGridNum*m_fWndYUnit));
		//Log(g_lpszLogFile, "Line i=%d X=%.3f\n", i+1, XDeviate+m_fWndXUnit+m_fWndXUnit*i);
	}

	for (i=0; i<m_nYGridNum; i++)			//	画横线
	{
		pDC->MoveTo((int)(XDeviate+m_fWndXUnit),								(int)(m_fWndYUnit+m_fWndYUnit*i));
		pDC->LineTo((int)(XDeviate+m_fWndXUnit+(m_nXGridNum-1)*m_fWndXUnit),	(int)(m_fWndYUnit+m_fWndYUnit*i));
	}

	pDC->SelectObject(pOldPen);
	delete	pPen;

	if (m_Curve.fMaxX < m_Curve.fMinX)
		return;
	if (m_Curve.fMaxY < m_Curve.fMinY)
		return;

	//	画曲线坐标值
	logfont.lfHeight=(int)((m_fWndXUnit<m_fWndYUnit)?m_fWndXUnit/2.25 : m_fWndYUnit/2.25);
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

	//	画横坐标值
	double	fMax, fMin;

	fMin = (m_bAutoMinX) ? m_Curve.fMinX : m_fAxisMinX;
	fMax = (m_bAutoMaxX) ? m_Curve.fMaxX : m_fAxisMaxX;
	const	double	fUnitCurveX = (fMax-fMin)/(m_nXGridNum-1);

	fMin = (m_bAutoMinY) ? m_Curve.fMinY : m_fAxisMinY;
	fMax = (m_bAutoMaxY) ? m_Curve.fMaxY : m_fAxisMaxY;
	const	double	fUnitCurveY = (fMax-fMin)/(m_nYGridNum-1);

	sprintf(szFormat, "%%.%df", m_nXFloatPoint);
	rect.top   =(int)(m_nYGridNum*m_fWndYUnit);
	rect.bottom=(int)((m_fWndXUnit<m_fWndYUnit) ? m_nYGridNum*m_fWndYUnit+m_fWndXUnit : m_nYGridNum*m_fWndYUnit+m_fWndYUnit);
	for (i=0; i<m_nXGridNum; i++)
	{
		if (m_bAutoMinX)
			sprintf(szBuf, szFormat, (m_Curve.fMinX+i*fUnitCurveX));
		else
			sprintf(szBuf, szFormat, (m_fAxisMinX+i*fUnitCurveX));

		rect.left =(int)(XDeviate+m_fWndXUnit*(i+1) - m_fWndXUnit/2);
		rect.right=(int)(XDeviate+m_fWndXUnit*(i+1) + m_fWndXUnit/2);
		pDC->SetBkMode(TRANSPARENT);
		pDC->DrawText(szBuf, &rect, DT_SINGLELINE|DT_VCENTER|DT_CENTER);
	}

	//	画纵坐标值
	sprintf(szFormat, "%%.%df", m_nYFloatPoint);
	rect.left =0;
	rect.right=(int)(m_fWndXUnit*0.8);
	for (i=0; i<m_nYGridNum; i++)
	{
		if (m_bAutoMinY)
			sprintf(szBuf, szFormat, (m_Curve.fMinY+(m_nYGridNum-(i+1))*fUnitCurveY));
		else
			sprintf(szBuf, szFormat, (m_fAxisMinY+(m_nYGridNum-(i+1))*fUnitCurveY));

		rect.top   =(int)((i+1)*m_fWndYUnit-m_fWndYUnit/2);
		rect.bottom=(int)((i+1)*m_fWndYUnit+m_fWndYUnit/2);
		pDC->SetBkMode(TRANSPARENT);
		pDC->DrawText(szBuf, &rect, DT_SINGLELINE|DT_VCENTER|DT_RIGHT);
	}

	//	画Y
	rect.left  =(int)(XDeviate+m_fWndXUnit-m_fWndXUnit/2);
	rect.right =(int)(XDeviate+m_fWndXUnit+m_fWndXUnit/2);
	rect.top   =(int)(0*m_fWndYUnit);
	rect.bottom=(int)(1*m_fWndYUnit);
	pDC->DrawText(m_Curve.strYAxiasName.c_str(), &rect, DT_SINGLELINE|DT_VCENTER|DT_CENTER);

	//	画X
	rect.left  =(int)(XDeviate+m_nXGridNum*m_fWndXUnit);
	rect.right =(int)(XDeviate+m_nXGridNum*m_fWndXUnit+m_fWndXUnit);
	rect.top   =(int)(m_nYGridNum*m_fWndYUnit-m_fWndYUnit/2);
	rect.bottom=(int)(m_nYGridNum*m_fWndYUnit+m_fWndYUnit/2);
	pDC->DrawText(m_Curve.strXAxiasName.c_str(), &rect, DT_SINGLELINE|DT_VCENTER|DT_CENTER);

	pDC->SelectObject(pOldFont);
	pDC->SetTextColor(TextColorSave);
	font.DeleteObject();
}

void CSimpleCurveWnd::DrawCurve(CDC* pDC)
{
	register int	i;
	CRect	rect;
	double	fX0, fY0, fX1, fY1;
	double	fMax, fMin;

	CPen*		pPen;
	CPen*		pOldPen;
	CFont		font;

	if (m_Curve.sDataArray.empty())
		return;
	if (m_Curve.fMaxX < m_Curve.fMinX || m_Curve.fMaxY < m_Curve.fMinY)
		return;

	fMin = (m_bAutoMinX) ? m_Curve.fMinX : m_fAxisMinX;
	fMax = (m_bAutoMaxX) ? m_Curve.fMaxX : m_fAxisMaxX;
	const	double	fUnitCurveX = (fMax-fMin)/(m_nXGridNum-1);
	fMin = (m_bAutoMinY) ? m_Curve.fMinY : m_fAxisMinY;
	fMax = (m_bAutoMaxY) ? m_Curve.fMaxY : m_fAxisMaxY;
	const	double	fUnitCurveY = (fMax-fMin)/(m_nYGridNum-1);
	if (fUnitCurveX < FLT_MIN || fUnitCurveY < FLT_MIN)
		return;

	const	double	fCurveMinX = (m_bAutoMinX) ? m_Curve.fMinX : m_fAxisMinX;
	const	double	fCurveMinY = (m_bAutoMinY) ? m_Curve.fMinY : m_fAxisMinY;

	//	画曲线
	pPen=new CPen(PS_SOLID, 2, m_clrCurve);
	pOldPen=pDC->SelectObject(pPen);

	fX0=XDeviate+m_fWndXUnit					+m_fWndXUnit*(m_Curve.sDataArray[0].fX- fCurveMinX )/fUnitCurveX;
	fY0=m_nYGridNum*m_fWndYUnit				-m_fWndYUnit*(m_Curve.sDataArray[0].fY- fCurveMinY )/fUnitCurveY;

	for (i=0; i<(int)m_Curve.sDataArray.size(); i++)
	{
		fX1=XDeviate+m_fWndXUnit				+m_fWndXUnit*(m_Curve.sDataArray[i].fX- fCurveMinX )/fUnitCurveX;
		fY1=m_nYGridNum*m_fWndYUnit			-m_fWndYUnit*(m_Curve.sDataArray[i].fY- fCurveMinY )/fUnitCurveY;
		pDC->MoveTo((int)fX0, (int)fY0);
		pDC->LineTo((int)fX1, (int)fY1);
		fX0=fX1;
		fY0=fY1;
	}
	pDC->SelectObject(pOldPen);
	delete	pPen;
}

void CSimpleCurveWnd::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()
	DrawBack(&dc);
	DrawCurve(&dc);
}

void CSimpleCurveWnd::SetCurve(tagSimpleCurve* pCurve)
{
	m_Curve.clrCurve = pCurve->clrCurve;
	m_Curve.nStroke = pCurve->nStroke;
	m_Curve.sDataArray.assign(pCurve->sDataArray.begin(), pCurve->sDataArray.end());

	getSimpleCurveMinMax(m_Curve);

	pCurve->fMaxX=m_Curve.fMaxX;
	pCurve->fMaxY=m_Curve.fMaxY;
	pCurve->fMinX=m_Curve.fMinX;
	pCurve->fMinY=m_Curve.fMinY;

	pCurve->fMaxY_X=m_Curve.fMaxY_X;
	pCurve->fMinY_X=m_Curve.fMinY_X;
	pCurve->fMaxX_Y=m_Curve.fMaxX_Y;
	pCurve->fMinX_Y=m_Curve.fMinX_Y;

	if (m_bAutoMaxX)	m_fAxisMaxX = pCurve->fMaxX;
	if (m_bAutoMaxY)	m_fAxisMaxY = pCurve->fMaxY;
	if (m_bAutoMinX)	m_fAxisMinX = pCurve->fMinX;
	if (m_bAutoMinY)	m_fAxisMinY = pCurve->fMinY;

	Invalidate();
}

void CSimpleCurveWnd::SetColor(COLORREF clrBack, COLORREF clrFore, COLORREF clrCurve, COLORREF clrAxias)
{
	m_clrBackGround=clrBack;
	m_clrForeGround=clrFore;
	m_clrCurve=clrCurve;
	m_clrAxias=clrAxias;
	Invalidate();
}

void CSimpleCurveWnd::SetCurveGrid(const int nMaxXPoint, const int nMaxYPoint)
{
	m_nXGridNum=nMaxXPoint;
	m_nYGridNum=nMaxYPoint;
}

void CSimpleCurveWnd::SetXAxisName(const char* lpszXAxiasName)
{
	m_Curve.strXAxiasName=lpszXAxiasName;
}

void CSimpleCurveWnd::SetYAxisName(const char* lpszYAxiasName)
{
	m_Curve.strYAxiasName=lpszYAxiasName;
}

void CSimpleCurveWnd::SetXYFloatPoint(const int nXFPoint, const int nYFPoint)
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

void CSimpleCurveWnd::SetXAxisMinMax(const unsigned char bMinAutoFit, const double fMinX, const unsigned char bMaxAutoFit, const double fMaxX)
{
	m_bAutoMinX = bMinAutoFit;
	m_bAutoMaxX = bMaxAutoFit;
	m_fAxisMinX = fMinX;
	m_fAxisMaxX = fMaxX;
}

void CSimpleCurveWnd::SetYAxisMinMax(const unsigned char bMinAutoFit, const double fMinY, const unsigned char bMaxAutoFit, const double fMaxY)
{
	m_bAutoMinY = bMinAutoFit;
	m_bAutoMaxY = bMaxAutoFit;
	m_fAxisMinY = fMinY;
	m_fAxisMaxY = fMaxY;
}

int CSimpleCurveWnd::ExportCurve(const char* lpszFileName)
{
	CMetaFileDC	mDC;
	mDC.CreateEnhanced(NULL, CString(lpszFileName), NULL, NULL);

	DrawBack(&mDC);
	DrawCurve(&mDC);

	HENHMETAFILE hemf=mDC.CloseEnhanced();
	DeleteEnhMetaFile(hemf);						//关闭图元句柄，完成图元的创建

	return 1;
}
