#include "stdafx.h"
#include "SvgBasicShape.h"

CSvgBasicShape::CSvgBasicShape(void)
{
	AddAttr(attrCore_XmlBase, "");
	AddAttr(attrCore_XmlLang, "");
	AddAttr(attrCore_XmlSpace, "");

	AddAttr(attrStyle_Class, "");
	AddAttr(attrStyle_Style, "");

	AddAttr(attrPaint_Color, "");
	AddAttr(attrPaint_Fill, "");
	AddAttr(attrPaint_FillRule, "");
	AddAttr(attrPaint_Stroke, "");
	AddAttr(attrPaint_StrokeWidth, "");
	AddAttr(attrPaint_StrokeDashArray, "");
	AddAttr(attrPaint_StrokeDashOffSet, "");
	AddAttr(attrPaint_StrokeLineCap, "");
	AddAttr(attrPaint_StrokeLineJoin, "");
	AddAttr(attrPaint_StrokeMiterLimit, "");
	AddAttr(attrPaint_ColorInterpolation, "");
	AddAttr(attrPaint_ColorInterpolationFilters, "");
	AddAttr(attrPaint_ColorRendering, "");

	AddAttr(attrGraphics_Display, "");
	AddAttr(attrGraphics_PointerEvents, "");
	AddAttr(attrGraphics_ImageRendering, "");
	AddAttr(attrGraphics_ShapeRendering, "");
	AddAttr(attrGraphics_TextRendering, "");
	AddAttr(attrGraphics_Visiblity, "");

	AddAttr(attrOpacity_Opacity, "");
	AddAttr(attrOpacity_FillOpacity, "");
	AddAttr(attrOpacity_StrokeOpacity, "");
}

CSvgBasicShape::~CSvgBasicShape(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgLine
//////////////////////////////////////////////////////////////////////////
CSvgLine::CSvgLine(void)
{
	m_sElementName = "line";
	m_ElementType = typeLine;

	AddAttr(attrSpecific_X1, "");
	AddAttr(attrSpecific_Y1, "");
	AddAttr(attrSpecific_X2, "");
	AddAttr(attrSpecific_Y2, "");
}

CSvgLine::CSvgLine(const char* sX1, const char* sY1, const char* sX2, const char* sY2, const char* sColor)
{
	m_sElementName = "line";
	m_ElementType = typeLine;

	AddAttr(attrSpecific_X1, "");
	AddAttr(attrSpecific_Y1, "");
	AddAttr(attrSpecific_X2, "");
	AddAttr(attrSpecific_Y2, "");

	SetAttributeValue(attrSpecific_X1, sX1);
	SetAttributeValue(attrSpecific_X2, sX2);
	SetAttributeValue(attrSpecific_Y1, sY1);
	SetAttributeValue(attrSpecific_Y2, sY2);
	SetAttributeValue(attrPaint_Stroke, sColor);
}

CSvgLine::~CSvgLine(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgRect
//////////////////////////////////////////////////////////////////////////
CSvgRect::CSvgRect(void)
{
	m_sElementName = "rect";
	m_ElementType = typeRect;

	AddAttr(attrSpecific_X, "");
	AddAttr(attrSpecific_Y, "");
	AddAttr(attrSpecific_Width, "");
	AddAttr(attrSpecific_Height, "");
	AddAttr(attrSpecific_RX, "");
	AddAttr(attrSpecific_RY, "");
}

CSvgRect::CSvgRect(const char* sX, const char* sY, const char* sWidth, const char* sHeight, const char* sStrokeWidth, const char* colFill, const char* colStroke)
{
	m_sElementName = "rect";
	m_ElementType = typeRect;

	AddAttr(attrSpecific_X, "");
	AddAttr(attrSpecific_Y, "");
	AddAttr(attrSpecific_Width, "");
	AddAttr(attrSpecific_Height, "");
	AddAttr(attrSpecific_RX, "");
	AddAttr(attrSpecific_RY, "");

	SetAttributeValue(attrSpecific_X, sX);
	SetAttributeValue(attrSpecific_Y, sY);
	SetAttributeValue(attrSpecific_Width, sWidth);
	SetAttributeValue(attrSpecific_Height, sHeight);
	SetAttributeValue(attrPaint_Fill, colFill);
	SetAttributeValue(attrPaint_Stroke, colStroke);
}

CSvgRect::~CSvgRect(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgCircle
//////////////////////////////////////////////////////////////////////////
CSvgCircle::CSvgCircle(void)
{
	m_sElementName = "circle";
	m_ElementType = typeCircle;

	AddAttr(attrSpecific_CX, "");
	AddAttr(attrSpecific_CY, "");
	AddAttr(attrSpecific_R, "");
}

CSvgCircle::CSvgCircle(const char* sCX, const char* sCY, const char* sRadius)
{
	m_sElementName = "circle";
	m_ElementType = typeCircle;

	AddAttr(attrSpecific_CX, "");
	AddAttr(attrSpecific_CY, "");
	AddAttr(attrSpecific_R, "");

	SetAttributeValue(attrSpecific_CX, sCX);
	SetAttributeValue(attrSpecific_CY, sCY);
	SetAttributeValue(attrSpecific_R, sRadius);
}

CSvgCircle::~CSvgCircle(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgEllipse
//////////////////////////////////////////////////////////////////////////
CSvgEllipse::CSvgEllipse(void)
{
	m_sElementName = "ellipse";
	m_ElementType = typeEllipse;

	AddAttr(attrSpecific_CX, "");
	AddAttr(attrSpecific_CY, "");
	AddAttr(attrSpecific_RX, "");
	AddAttr(attrSpecific_RY, "");
}

CSvgEllipse::CSvgEllipse(const char* sCX, const char* sCY, const char* sRX, const char* sRY)
{
	m_sElementName = "ellipse";
	m_ElementType = typeEllipse;

	AddAttr(attrSpecific_CX, "");
	AddAttr(attrSpecific_CY, "");
	AddAttr(attrSpecific_RX, "");
	AddAttr(attrSpecific_RY, "");

	SetAttributeValue(attrSpecific_CX, sCX);
	SetAttributeValue(attrSpecific_CY, sCY);
	SetAttributeValue(attrSpecific_RX, sRX);
	SetAttributeValue(attrSpecific_RY, sRY);
}

CSvgEllipse::~CSvgEllipse(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgPolyline
//////////////////////////////////////////////////////////////////////////
CSvgPolyline::CSvgPolyline(void)
{
	m_sElementName = "polygon";
	m_ElementType = typePolyline;

	AddAttr(attrSpecific_Points, "");
}

CSvgPolyline::CSvgPolyline(const char* sPoints)
{
	m_sElementName = "polygon";
	m_ElementType = typePolyline;

	AddAttr(attrSpecific_Points, "");

	SetAttributeValue(attrSpecific_Points, sPoints);
}

CSvgPolyline::~CSvgPolyline(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgPolygon
//////////////////////////////////////////////////////////////////////////
CSvgPolygon::CSvgPolygon(void)
{
	m_sElementName = "polygon";
	m_ElementType = typePolygon;

	AddAttr(attrSpecific_Points, "");
}

CSvgPolygon::CSvgPolygon(const char* sPoints)
{
	m_sElementName = "polygon";
	m_ElementType = typePolygon;

	AddAttr(attrSpecific_Points, "");

	SetAttributeValue(attrSpecific_Points, sPoints);
}

CSvgPolygon::~CSvgPolygon(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgPath
//////////////////////////////////////////////////////////////////////////
CSvgPath::CSvgPath(void)
{
	m_sElementName = "path";
	m_ElementType = typePath;

	AddAttr(attrSpecific_PathData, "");
	AddAttr(attrSpecific_PathLength, "");
}

CSvgPath::CSvgPath(const char* lpszPathData)
{
	m_sElementName = "path";
	m_ElementType = typePath;

	AddAttr(attrSpecific_PathData, "");
	AddAttr(attrSpecific_PathLength, "");

	SetAttributeValue(attrSpecific_PathData, lpszPathData);
}

CSvgPath::~CSvgPath(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgUse
//////////////////////////////////////////////////////////////////////////
CSvgUse::CSvgUse(void)
{
	m_sElementName = "use";
	m_ElementType = typeUse;

	AddAttr(attrSpecific_X, "");
	AddAttr(attrSpecific_Y, "");
	AddAttr(attrSpecific_Width, "");
	AddAttr(attrSpecific_Height, "");
	AddAttr(attrSpecific_RX, "");
	AddAttr(attrSpecific_RY, "");

	AddAttr(attrSpecific_Transform, "");
	AddAttr(attrXLink_HRef, "");
}

CSvgUse::CSvgUse(const char* sX, const char* sY, const char* sWidth, const char* sHeight, const char* sStrokeWidth, const char* colFill, const char* colStroke)
{
	m_sElementName = "use";
	m_ElementType = typeUse;

	AddAttr(attrSpecific_X, "");
	AddAttr(attrSpecific_Y, "");
	AddAttr(attrSpecific_Width, "");
	AddAttr(attrSpecific_Height, "");
	AddAttr(attrSpecific_RX, "");
	AddAttr(attrSpecific_RY, "");

	AddAttr(attrSpecific_Transform, "");
	AddAttr(attrXLink_HRef, "");

	SetAttributeValue(attrSpecific_X, sX);
	SetAttributeValue(attrSpecific_Y, sY);
	SetAttributeValue(attrSpecific_Width, sWidth);
	SetAttributeValue(attrSpecific_Height, sHeight);
	SetAttributeValue(attrPaint_StrokeWidth, sStrokeWidth);
	SetAttributeValue(attrPaint_Fill, colFill);
	SetAttributeValue(attrPaint_Stroke, colStroke);
}

CSvgUse::~CSvgUse(void)
{
}