#pragma once

#include <afxwin.h>
#include <afxext.h>
#include "SimpleCurve.h"

// CSimpleCurveWnd

class CSimpleCurveWnd : public CWnd
{
	DECLARE_DYNAMIC(CSimpleCurveWnd)

public:
	CSimpleCurveWnd();
	virtual ~CSimpleCurveWnd();

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
private:
	void	DrawCurve(CDC* pDC);
	void	DrawBack(CDC* pDC);

private:
	tagSimpleCurve	m_Curve;

public:
	void	SetCurve(tagSimpleCurve* pCurve);
	void	SetColor(COLORREF clrBack, COLORREF clrFore, COLORREF clrCurve, COLORREF clrAxias);
	void	SetCurveGrid(const int nXPace, const int nYPace);
	void	SetXAxisName(const char* lpszYAxisName);
	void	SetYAxisName(const char* lpszYAxisName);
	void	SetXYFloatPoint(const int nXFPoint, const int nYFPoint);
	void	SetXAxisMinMax(const unsigned char bMinAutoFit, const double fMinX, const unsigned char bMaxAutoFit, const double fMaxX);
	void	SetYAxisMinMax(const unsigned char bMinAutoFit, const double fMinY, const unsigned char bMaxAutoFit, const double fMaxY);

	int		ExportCurve(const char* lpszFileName);

private:
	int			m_nXGridNum,	m_nYGridNum;	//	曲线的网格线个数
	int			m_nXFloatPoint, m_nYFloatPoint;	//	坐标的小数点位数

	unsigned char	m_bAutoMinX, m_bAutoMaxX, m_bAutoMinY, m_bAutoMaxY;	//	XY坐标自适应
	double			m_fAxisMinX, m_fAxisMaxX, m_fAxisMinY, m_fAxisMaxY;				//	XY坐标最大最小值

	COLORREF	m_clrBackGround;
	COLORREF	m_clrForeGround;
	COLORREF	m_clrCurve;
	COLORREF	m_clrAxias;

private:
	double	m_fWndXUnit;
	double	m_fWndYUnit;
};
