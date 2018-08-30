#pragma once

#include <afxwin.h>
#include <afxext.h>
#include "SimpleCurve.h"
// CSimpleCurveWnd

class CSimpleMCurveWnd : public CWnd
{
	DECLARE_DYNAMIC(CSimpleMCurveWnd)

public:
	CSimpleMCurveWnd();
	virtual ~CSimpleMCurveWnd();

	void	DrawCurve(CDC* pDC);
	void	DrawBack(CDC* pDC);
	int		ExportCurve(const char* lpszFileName);

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

private:
	std::vector<tagSimpleCurve>	m_CurveArray;

public:
	int		GetMinMax();
	void	ClearCurve(void);
	void	AddCurve(tagSimpleCurve& cData);
	void	SetCurveName(const char* lpszCurveName);
	void	SetXAxisName(const char* lpszYAxisName);
	void	SetYAxisName(const char* lpszYAxisName);
	void	SetColor(COLORREF clrBack, COLORREF clrFore, COLORREF clrCurve, COLORREF clrAxias);
	void	SetCurveGrid(const int nXPace, const int nYPace);
	void	SetXYFloatPoint(const int nXFPoint, const int nYFPoint);
	void	SetXAxisMinMax(const unsigned char bMinAutoFit, const double fMinX, const unsigned char bMaxAutoFit, const double fMaxX);
	void	SetYAxisMinMax(const unsigned char bMinAutoFit, const double fMinY, const unsigned char bMaxAutoFit, const double fMaxY);

private:
	std::string		m_strCurveName, m_strXAxiasName, m_strYAxiasName;

	int				m_nXGridNum, m_nYGridNum;
	int				m_nXFloatPoint, m_nYFloatPoint;

	unsigned char	m_bAutoMinX, m_bAutoMaxX, m_bAutoMinY, m_bAutoMaxY;	//	XY坐标自适应
	double			m_fAxisMinX, m_fAxisMaxX, m_fAxisMinY, m_fAxisMaxY;				//	XY坐标最大最小值
	double			m_fCurveMinX, m_fCurveMaxX, m_fCurveMinY, m_fCurveMaxY;			//	XY曲线最大最小值

	COLORREF	m_clrBackGround;
	COLORREF	m_clrForeGround;
	COLORREF	m_clrCurve;
	COLORREF	m_clrAxias;

private:
	double	m_fWndXUnit;
	double	m_fWndYUnit;
};


