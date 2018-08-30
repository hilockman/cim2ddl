#pragma once
#include "SvgElement.h"

class 	CSvgBasicShape : public CSvgElement
{
public:
	CSvgBasicShape(void);
	~CSvgBasicShape(void);
};

class 	CSvgLine : public CSvgBasicShape
{
public:
	CSvgLine(void);
	CSvgLine::CSvgLine(const char* sX1, const char* sY1, const char* sX2, const char* sY2, const char* sColor);
	~CSvgLine(void);
};

class 	CSvgRect : public CSvgBasicShape
{
public:
	CSvgRect(void);
	CSvgRect(const char* sX, const char* sY, const char* sWidth, const char* sHeight, const char* sStrokeWidth, const char* colFill, const char* colStroke);
	~CSvgRect(void);
};

class 	CSvgCircle : public CSvgBasicShape
{
public:
	CSvgCircle(void);
	CSvgCircle(const char* sCX, const char* sCY, const char* sRadius);
	~CSvgCircle(void);
};


class 	CSvgEllipse : public CSvgBasicShape
{
public:
	CSvgEllipse(void);
	CSvgEllipse(const char* sCX, const char* sCY, const char* sRX, const char* sRY);
	~CSvgEllipse(void);
};

class 	CSvgPolyline : public CSvgBasicShape
{
public:
	CSvgPolyline(void);
	CSvgPolyline(const char* sPoints);
	~CSvgPolyline(void);
};

class 	CSvgPolygon : public CSvgBasicShape
{
public:
	CSvgPolygon(void);
	CSvgPolygon(const char* sPoints);
	~CSvgPolygon(void);
};

class 	CSvgPath : public CSvgBasicShape
{
public:
	CSvgPath(void);
	CSvgPath(const char* lpszPathData);
	~CSvgPath(void);
};

class 	CSvgUse : public CSvgBasicShape
{
public:
	CSvgUse(void);
	CSvgUse(const char* sX, const char* sY, const char* sWidth, const char* sHeight, const char* sStrokeWidth, const char* colFill, const char* colStroke);
	~CSvgUse(void);
};
