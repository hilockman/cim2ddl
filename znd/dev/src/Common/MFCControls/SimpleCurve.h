#pragma once

#include <Windows.h>
#include <vector>
#include <string>
#include <float.h>
using namespace std;

typedef	struct	_CurveData_
{
	double	fX;
	double	fY;
}	tagCurveData;

typedef	struct	_SimpleCurve_
{
	std::string	strCurveName;
	std::string	strXAxiasName;
	std::string	strYAxiasName;
	int			clrCurve;
	unsigned short	nStroke;
	std::vector<tagCurveData>	sDataArray;

	double		fMaxY;
	double		fMinY;
	double		fMaxY_X;
	double		fMinY_X;

	double		fMaxX;
	double		fMinX;
	double		fMaxX_Y;
	double		fMinX_Y;
}	tagSimpleCurve;

inline	void	initSimpleCurve(tagSimpleCurve& sCurve)
{
	sCurve.strCurveName.clear();
	sCurve.strXAxiasName.clear();
	sCurve.strYAxiasName.clear();

	sCurve.nStroke=2;
	sCurve.fMaxX=
	sCurve.fMinX=
	sCurve.fMaxY=
	sCurve.fMinY=0;
	sCurve.fMaxX_Y=
	sCurve.fMinX_Y=
	sCurve.fMaxY_X=
	sCurve.fMinY_X=0;
	sCurve.clrCurve=RGB(255, 0, 0);

	sCurve.sDataArray.clear();
}

inline	void	cloneSimpleCurve(tagSimpleCurve* pSrc, tagSimpleCurve* pDes)
{
	pDes->strCurveName = pSrc->strCurveName;			
	pDes->strXAxiasName = pSrc->strXAxiasName;		
	pDes->strYAxiasName = pSrc->strYAxiasName;		
																				
	pDes->nStroke = pSrc->nStroke;					
	pDes->fMaxX = pSrc->fMaxX;					
	pDes->fMinX = pSrc->fMinX;					
	pDes->fMaxY = pSrc->fMaxY;						
	pDes->fMinY = pSrc->fMinY;						
	pDes->fMaxX_Y =	pSrc->fMaxX_Y;						
	pDes->fMinX_Y =	pSrc->fMinX_Y;						
	pDes->fMaxY_X =	pSrc->fMaxY_X;						
	pDes->fMinY_X =	pSrc->fMinY_X;					
	pDes->clrCurve = pSrc->clrCurve;		
																				
	pDes->sDataArray.assign(pSrc->sDataArray.begin(), pSrc->sDataArray.end());			
}

inline	void	getSimpleCurveMinMax(tagSimpleCurve& sCurve)
{
	register int	i;

	sCurve.fMaxX=sCurve.fMaxY=-FLT_MAX;
	sCurve.fMinX=sCurve.fMinY=FLT_MAX;

	for (i=0; i<(int)sCurve.sDataArray.size(); i++)
	{
		if (sCurve.fMaxX < sCurve.sDataArray[i].fX)
		{
			sCurve.fMaxX=sCurve.sDataArray[i].fX;
			sCurve.fMaxX_Y=sCurve.sDataArray[i].fY;
		}
		if (sCurve.fMinX > sCurve.sDataArray[i].fX)
		{
			sCurve.fMinX=sCurve.sDataArray[i].fX;
			sCurve.fMinX_Y=sCurve.sDataArray[i].fY;
		}

		if (sCurve.fMaxY < sCurve.sDataArray[i].fY && (-FLT_MAX < sCurve.sDataArray[i].fY && sCurve.sDataArray[i].fY < FLT_MAX))
		{
			sCurve.fMaxY=sCurve.sDataArray[i].fY;
			sCurve.fMaxY_X=sCurve.sDataArray[i].fX;
		}
		if (sCurve.fMinY > sCurve.sDataArray[i].fY && (-FLT_MAX < sCurve.sDataArray[i].fY && sCurve.sDataArray[i].fY < FLT_MAX))
		{
			sCurve.fMinY=sCurve.sDataArray[i].fY;
			sCurve.fMinY_X=sCurve.sDataArray[i].fX;
		}
	}
}