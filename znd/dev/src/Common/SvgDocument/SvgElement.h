#pragma once

#include "SvgAttribute.h"
#include "../../Common/TinyXML/tinyxml.h"

enum _SvgElementType
{
	typeUnsupported=0,
	typeSvg,
	typeTitle,
	typeDesc,
	typeDefs,
	typeStyle,
	typeCDATASection,
	typeText,
	typeTspan,
	typeA,
	typeGroup,
	typeUse,
	typeRect,
	typeCircle,
	typeEllipse,
	typeLine,
	typePath,
	typePolygon,
	typePolyline,
	typeImage,
	typeSymbol,
	typeMetadata,
	typeCgePSR_Ref,
	typeCgeLayer_Ref,
	typeCgeCN_Ref
};

typedef	struct
{
	_SvgElementType	nType;
	char*	lpszType;
}	tagSVGElementType;

static	tagSVGElementType	elementType[]=
{
	{typeUnsupported,	"不支持"},
	{typeSvg,			"根"	},
	{typeTitle,			"头"	},
	{typeDesc,			"描述"	},
	{typeDefs,			"定义"	},
	{typeStyle,			"样式"	},
	{typeCDATASection,	"CDATA"	},
	{typeText,			"文本"	},
	{typeTspan,			"文本"	},
	{typeA,				"索引"	},
	{typeGroup,			"组"	},
	{typeUse,			"引用"	},
	{typeRect,			"方"	},
	{typeCircle,		"圆"	},
	{typeEllipse,		"椭圆"	},
	{typeLine,			"线"	},
	{typePath,			"路径"	},
	{typePolygon,		"多边形"},
	{typePolyline,		"折线"	},
	{typeImage,			"图象"	},
	{typeSymbol,		"模板"	},
	{typeMetadata,		"元数据"},
};

typedef	struct  {
	unsigned long rgb;
	char const *name;
}	tagSvgColorIndex;

static tagSvgColorIndex const svg_color_named[] = {
	{ 0xF0F8FF, "aliceblue" },
	{ 0xFAEBD7, "antiquewhite" },
	{ 0x00FFFF, "aqua" },
	{ 0x7FFFD4, "aquamarine" },
	{ 0xF0FFFF, "azure" },
	{ 0xF5F5DC, "beige" },
	{ 0xFFE4C4, "bisque" },
	{ 0x000000, "black" },
	{ 0xFFEBCD, "blanchedalmond" },
	{ 0x0000FF, "blue" },
	{ 0x8A2BE2, "blueviolet" },
	{ 0xA52A2A, "brown" },
	{ 0xDEB887, "burlywood" },
	{ 0x5F9EA0, "cadetblue" },
	{ 0x7FFF00, "chartreuse" },
	{ 0xD2691E, "chocolate" },
	{ 0xFF7F50, "coral" },
	{ 0x6495ED, "cornflowerblue" },
	{ 0xFFF8DC, "cornsilk" },
	{ 0xDC143C, "crimson" },
	{ 0x00FFFF, "cyan" },
	{ 0x00008B, "darkblue" },
	{ 0x008B8B, "darkcyan" },
	{ 0xB8860B, "darkgoldenrod" },
	{ 0xA9A9A9, "darkgray" },
	{ 0x006400, "darkgreen" },
	{ 0xA9A9A9, "darkgrey" },
	{ 0xBDB76B, "darkkhaki" },
	{ 0x8B008B, "darkmagenta" },
	{ 0x556B2F, "darkolivegreen" },
	{ 0xFF8C00, "darkorange" },
	{ 0x9932CC, "darkorchid" },
	{ 0x8B0000, "darkred" },
	{ 0xE9967A, "darksalmon" },
	{ 0x8FBC8F, "darkseagreen" },
	{ 0x483D8B, "darkslateblue" },
	{ 0x2F4F4F, "darkslategray" },
	{ 0x2F4F4F, "darkslategrey" },
	{ 0x00CED1, "darkturquoise" },
	{ 0x9400D3, "darkviolet" },
	{ 0xFF1493, "deeppink" },
	{ 0x00BFFF, "deepskyblue" },
	{ 0x696969, "dimgray" },
	{ 0x696969, "dimgrey" },
	{ 0x1E90FF, "dodgerblue" },
	{ 0xB22222, "firebrick" },
	{ 0xFFFAF0, "floralwhite" },
	{ 0x228B22, "forestgreen" },
	{ 0xFF00FF, "fuchsia" },
	{ 0xDCDCDC, "gainsboro" },
	{ 0xF8F8FF, "ghostwhite" },
	{ 0xFFD700, "gold" },
	{ 0xDAA520, "goldenrod" },
	{ 0x808080, "gray" },
	{ 0x808080, "grey" },
	{ 0x008000, "green" },
	{ 0xADFF2F, "greenyellow" },
	{ 0xF0FFF0, "honeydew" },
	{ 0xFF69B4, "hotpink" },
	{ 0xCD5C5C, "indianred" },
	{ 0x4B0082, "indigo" },
	{ 0xFFFFF0, "ivory" },
	{ 0xF0E68C, "khaki" },
	{ 0xE6E6FA, "lavender" },
	{ 0xFFF0F5, "lavenderblush" },
	{ 0x7CFC00, "lawngreen" },
	{ 0xFFFACD, "lemonchiffon" },
	{ 0xADD8E6, "lightblue" },
	{ 0xF08080, "lightcoral" },
	{ 0xE0FFFF, "lightcyan" },
	{ 0xFAFAD2, "lightgoldenrodyellow" },
	{ 0xD3D3D3, "lightgray" },
	{ 0x90EE90, "lightgreen" },
	{ 0xD3D3D3, "lightgrey" },
	{ 0xFFB6C1, "lightpink" },
	{ 0xFFA07A, "lightsalmon" },
	{ 0x20B2AA, "lightseagreen" },
	{ 0x87CEFA, "lightskyblue" },
	{ 0x778899, "lightslategray" },
	{ 0x778899, "lightslategrey" },
	{ 0xB0C4DE, "lightsteelblue" },
	{ 0xFFFFE0, "lightyellow" },
	{ 0x00FF00, "lime" },
	{ 0x32CD32, "limegreen" },
	{ 0xFAF0E6, "linen" },
	{ 0xFF00FF, "magenta" },
	{ 0x800000, "maroon" },
	{ 0x66CDAA, "mediumaquamarine" },
	{ 0x0000CD, "mediumblue" },
	{ 0xBA55D3, "mediumorchid" },
	{ 0x9370DB, "mediumpurple" },
	{ 0x3CB371, "mediumseagreen" },
	{ 0x7B68EE, "mediumslateblue" },
	{ 0x00FA9A, "mediumspringgreen" },
	{ 0x48D1CC, "mediumturquoise" },
	{ 0xC71585, "mediumvioletred" },
	{ 0x191970, "midnightblue" },
	{ 0xF5FFFA, "mintcream" },
	{ 0xFFE4E1, "mistyrose" },
	{ 0xFFE4B5, "moccasin" },
	{ 0xFFDEAD, "navajowhite" },
	{ 0x000080, "navy" },
	{ 0xFDF5E6, "oldlace" },
	{ 0x808000, "olive" },
	{ 0x6B8E23, "olivedrab" },
	{ 0xFFA500, "orange" },
	{ 0xFF4500, "orangered" },
	{ 0xDA70D6, "orchid" },
	{ 0xEEE8AA, "palegoldenrod" },
	{ 0x98FB98, "palegreen" },
	{ 0xAFEEEE, "paleturquoise" },
	{ 0xDB7093, "palevioletred" },
	{ 0xFFEFD5, "papayawhip" },
	{ 0xFFDAB9, "peachpuff" },
	{ 0xCD853F, "peru" },
	{ 0xFFC0CB, "pink" },
	{ 0xDDA0DD, "plum" },
	{ 0xB0E0E6, "powderblue" },
	{ 0x800080, "purple" },
	{ 0xFF0000, "red" },
	{ 0xBC8F8F, "rosybrown" },
	{ 0x4169E1, "royalblue" },
	{ 0x8B4513, "saddlebrown" },
	{ 0xFA8072, "salmon" },
	{ 0xF4A460, "sandybrown" },
	{ 0x2E8B57, "seagreen" },
	{ 0xFFF5EE, "seashell" },
	{ 0xA0522D, "sienna" },
	{ 0xC0C0C0, "silver" },
	{ 0x87CEEB, "skyblue" },
	{ 0x6A5ACD, "slateblue" },
	{ 0x708090, "slategray" },
	{ 0x708090, "slategrey" },
	{ 0xFFFAFA, "snow" },
	{ 0x00FF7F, "springgreen" },
	{ 0x4682B4, "steelblue" },
	{ 0xD2B48C, "tan" },
	{ 0x008080, "teal" },
	{ 0xD8BFD8, "thistle" },
	{ 0xFF6347, "tomato" },
	{ 0x40E0D0, "turquoise" },
	{ 0xEE82EE, "violet" },
	{ 0xF5DEB3, "wheat" },
	{ 0xFFFFFF, "white" },
	{ 0xF5F5F5, "whitesmoke" },
	{ 0xFFFF00, "yellow" },
	{ 0x9ACD32, "yellowgreen" }
};


class 	CSvgElement
{
public:
	CSvgElement();
	~CSvgElement(void);

protected:
	CSvgElement* m_pParent;
	CSvgElement* m_pChild;
	CSvgElement* m_pNext;
	CSvgElement* m_pPrevious;

	int m_nInternalId;

	std::string m_sElementName;
	std::string m_sElementValue;
	unsigned char m_bElementHasValue;
	_SvgElementType m_ElementType;

public:
	std::vector<tagSvgAttr> m_attributes;

protected:
	void AddAttr(_SvgAttributeType type, std::string objValue);
	int GetAttribute(const _SvgAttributeType type);
	int GetAttribute(const char* lpszName);

public:
	std::string ElementInfo();
	std::string GetAttributeValue(const _SvgAttributeType type);

public:
	CSvgElement* getParent();
	CSvgElement* getChild();
	CSvgElement* getPrevious();
	CSvgElement* getNext();

	std::string getElementName();
	_SvgElementType getElementType();
	std::string getElementValue();
	std::string getId();
	int getInternalId();

	char*	getElementTypeName(const int nType);


public:
	int SetAttributeValue(const _SvgAttributeType type, const char* objValue);
	int SetAttributeValue(const char* lpszName, const char* sValue);

public:
	void setParent(CSvgElement* pEle);
	void setChild(CSvgElement* pEle);
	void setPrevious(CSvgElement* pEle);
	void setNext(CSvgElement* pEle);
	void setInternalId(int nId);
	void setId(const char* value);

	void setElementValue(const char* lpszValue);

	std::string GetTagXml();
	std::string GetXML();
	void GetXML(FILE* fp);
	void GetXmlNode(TiXmlNode* pParent);

public:
	std::string CloseXmlTag();
	std::string OpenXmlTag();

	void CloseXmlTag(FILE* fp);
	void OpenXmlTag(FILE* fp);
protected:
	void OpenXmlNodeTag(TiXmlNode* pElement);
};

class 	CSvgRoot : public CSvgElement
{
public:
	CSvgRoot();
	~CSvgRoot(void);
};

class 	CSvgDesc : public CSvgElement
{
public:
	CSvgDesc(void);
	CSvgDesc(std::string sValue);
	~CSvgDesc(void);
};

class 	CSvgDefs : public CSvgElement
{
public:
	CSvgDefs(void);
	~CSvgDefs(void);
};

class 	CSvgTitle : public CSvgElement
{
public:
	CSvgTitle(void);
	CSvgTitle(const char* lpszValue);
	~CSvgTitle(void);
};

class 	CSvgStyle : public CSvgElement
{
public:
	CSvgStyle(void);
	~CSvgStyle(void);
};

class 	CSvgCDATASection : public CSvgElement
{
public:
	CSvgCDATASection(void);
	~CSvgCDATASection(void);
};

class 	CSvgGroup : public CSvgElement
{
public:
	CSvgGroup(void);
	~CSvgGroup(void);
};

class 	CSvgA : public CSvgElement
{
public:
	CSvgA();
	CSvgA(const char* sX, const char* sY, const char* sWidth, const char* sHeight, const char* sHRef);
	~CSvgA(void);
};

class 	CSvgText : public CSvgElement
{
public:
	CSvgText(void);
	~CSvgText(void);
};

class 	CSvgTspan : public CSvgElement
{
public:
	CSvgTspan(void);
	~CSvgTspan(void);
};

class 	CSvgImage : public CSvgElement
{
public:
	CSvgImage(void);
	CSvgImage(const char* lpszX, const char* lpszY, const char* lpszWidth, const char* lpszHeight, const char* lpszHRef);
	~CSvgImage(void);
};

class 	CSvgSymbol : public CSvgElement
{
public:
	CSvgSymbol(void);
	~CSvgSymbol(void);
};


class 	CSvgMetadata : public CSvgElement
{
public:
	CSvgMetadata(void);
	~CSvgMetadata(void);
};

class 	CSvgPSR_Ref : public CSvgElement
{
public:
	CSvgPSR_Ref(void);
	~CSvgPSR_Ref(void);
};

class 	CSvgCN_Ref : public CSvgElement
{
public:
	CSvgCN_Ref(void);
	~CSvgCN_Ref(void);
};

class 	CSvgLayer_Ref : public CSvgElement
{
public:
	CSvgLayer_Ref(void);
	~CSvgLayer_Ref(void);
};

class 	CSvgUnsupported : public CSvgElement
{
public:
	CSvgUnsupported(const char* lpszName);
	~CSvgUnsupported(void);
};
