#include "stdafx.h"
#include "SvgAttribute.h"

#include "../TinyXML/tinyxml.h"


std::vector<tagAttrInfo>	g_mapAttrInfo;
static	int					m_bAttributeInited;

_SvgAttributeDataType getAttributeDataType(const _SvgAttributeType nType)
{
	register int	i;
	for (i=0; i<(int)g_mapAttrInfo.size(); i++)
	{
		if (g_mapAttrInfo[i]._type == nType)
		{
			return g_mapAttrInfo[i]._datatype;
		}
	}
	return SvgAttributeDataType_datatypeNone;
}

std::vector<std::string> getAttributeEnumValues(const _SvgAttributeType nType)
{
	register int	i;
	for (i=0; i<(int)g_mapAttrInfo.size(); i++)
	{
		if (g_mapAttrInfo[i]._type == nType)
		{
			return g_mapAttrInfo[i]._enumvalues;
		}
	}

	std::vector<std::string> strNull;
	strNull.clear();
	return strNull;
}

_SvgAttributeGroup getAttributeGroup(const _SvgAttributeType nType)
{
	register int	i;
	for (i=0; i<(int)g_mapAttrInfo.size(); i++)
	{
		if (g_mapAttrInfo[i]._type == nType)
		{
			return g_mapAttrInfo[i]._group;
		}
	}
	return groupUnknown;
}

std::string GetSvgAttributeName(const _SvgAttributeType nType)
{
	register int	i;
	for (i=0; i<(int)g_mapAttrInfo.size(); i++)
	{
		if (g_mapAttrInfo[i]._type == nType)
		{
			return g_mapAttrInfo[i]._name;
		}
	}
	return "";
}

std::string getAttributeXML(tagSvgAttr* pAttr)
{
	// check if the value has not been initialized
	if (pAttr->strAttrValue.empty())
		return "";

	std::string sValue;
	sValue.clear();

	switch (getAttributeDataType(pAttr->nAttrType))
	{
		case SvgAttributeDataType_datatypeString:
		case SvgAttributeDataType_datatypeHRef:
		case SvgAttributeDataType_datatypeColor:
			sValue.append(pAttr->strAttrValue);
			break;

		case SvgAttributeDataType_datatypeEnum: // for enum attribute the 0 item means that the attribute is empty
			{
				int nValue = atoi(pAttr->strAttrValue.c_str());

				std::vector<std::string>	strEnums=getAttributeEnumValues(pAttr->nAttrType);
				if (nValue >= 0 && nValue < (int)strEnums.size())
				{
					sValue.append(strEnums[nValue]);
				}
			}
			break;
	}

	if (sValue.empty())
		return "";

	std::string	sReturn;
	sReturn.clear();
	sReturn=" ";
	sReturn.append(GetSvgAttributeName(pAttr->nAttrType));
	sReturn.append("=\"");
	sReturn.append(sValue);
	sReturn.append("\"");
	return sReturn;
}

void getAttributeXMLNode(TiXmlElement* pElement, tagSvgAttr* pAttr)
{
	// check if the value has not been initialized
	if (pAttr->strAttrValue.empty())
		return;

	std::string sValue;
	sValue.clear();
	switch (getAttributeDataType(pAttr->nAttrType))
	{
	case SvgAttributeDataType_datatypeString:
	case SvgAttributeDataType_datatypeHRef:
	case SvgAttributeDataType_datatypeColor:
		sValue.append(pAttr->strAttrValue);
		break;

	case SvgAttributeDataType_datatypeEnum: // for enum attribute the 0 item means that the attribute is empty
		{
			int nValue = atoi(pAttr->strAttrValue.c_str());

			std::vector<std::string>	strEnums=getAttributeEnumValues(pAttr->nAttrType);
			if (nValue >= 0 && nValue < (int)strEnums.size())
			{
				sValue.append(strEnums[nValue]);
			}
		}
		break;
	}

	if (sValue.empty())
		return;

	pElement->SetAttribute(GetSvgAttributeName(pAttr->nAttrType), sValue);
}

void InitCoreAttribute()
{
	tagAttrInfo	info;

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSvg_XmlNs;
	info._group = groupSvg;
	info._name = "xmlns";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSvg_XmlNsXLink;
	info._group = groupSvg;
	info._name = "xmlns:xlink";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSvg_XmlNsCge;
	info._group = groupSvg;
	info._name = "xmlns:cge";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSvg_Version;
	info._group = groupSvg;
	info._name = "version";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrCore_Id;
	info._group = groupCore;
	info._name = "id";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrCore_XmlBase;
	info._group = groupCore;
	info._name = "xml:base";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrCore_XmlLang;
	info._group = groupCore;
	info._name = "xml:lang";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrCore_XmlSpace;
	info._group = groupCore;
	info._name = "xml:space";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("default");
	info._enumvalues.push_back("preserve");
	g_mapAttrInfo.push_back(info);
	// ---
}

void InitElementSpecificAttribute() {
	_AttrInfo info;

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_Description;
	info._group = groupElementSpecific;
	info._name = "Description";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_Latitude;
	info._group = groupElementSpecific;
	info._name = "Latitude";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_Width;
	info._group = groupElementSpecific;
	info._name = "width";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_Height;
	info._group = groupElementSpecific;
	info._name = "height";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_X;
	info._group = groupElementSpecific;
	info._name = "x";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_Y;
	info._group = groupElementSpecific;
	info._name = "y";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_CX;
	info._group = groupElementSpecific;
	info._name = "cx";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_CY;
	info._group = groupElementSpecific;
	info._name = "cy";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_R;
	info._group = groupElementSpecific;
	info._name = "r";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_RX;
	info._group = groupElementSpecific;
	info._name = "rx";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_RY;
	info._group = groupElementSpecific;
	info._name = "ry";
	info._groupname = "specific";
	info._help = "For rounded rectangles, the y-axis radius of the ellipse used to round off the corners of the rectangle.";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_DX;
	info._group = groupElementSpecific;
	info._name = "dx";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_DY;
	info._group = groupElementSpecific;
	info._name = "dy";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_Rotate;
	info._group = groupElementSpecific;
	info._name = "rotate";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_TextLength;
	info._group = groupElementSpecific;
	info._name = "textLength";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_LengthAdjust;
	info._group = groupElementSpecific;
	info._name = "lengthAdjust";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("spacing");
	info._enumvalues.push_back("spacingAndGlyphs");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_X1;
	info._group = groupElementSpecific;
	info._name = "x1";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_Y1;
	info._group = groupElementSpecific;
	info._name = "y1";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_X2;
	info._group = groupElementSpecific;
	info._name = "x2";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_Y2;
	info._group = groupElementSpecific;
	info._name = "y2";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_Transform;
	info._group = groupElementSpecific;
	info._name = "transform";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_PathData;
	info._group = groupElementSpecific;
	info._name = "d";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_PathLength;
	info._group = groupElementSpecific;
	info._name = "pathLength";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_Points;
	info._group = groupElementSpecific;
	info._name = "points";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_Viewbox;
	info._group = groupElementSpecific;
	info._name = "viewbox";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrSpecific_preserveAspectRatio;
	info._group = groupSvg11;
	info._name = "preserveAspectRatio";

	g_mapAttrInfo.push_back(info);
	// ---
}

void InitFontAttribute()
{
	_AttrInfo info;

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrFont_Family;
	info._group = groupFont;
	info._name = "font-family";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrFont_Size;
	info._group = groupFont;
	info._name = "font-size";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrFont_SizeAdjust;
	info._group = groupFont;
	info._name = "font-size-adjust";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrFont_Stretch;
	info._group = groupFont;
	info._name = "font-stretch";

	info._datatype = SvgAttributeDataType_datatypeEnum;

	info._enumvalues.push_back("normal");
	info._enumvalues.push_back("wider");
	info._enumvalues.push_back("narrower");
	info._enumvalues.push_back("ultra-condensed");
	info._enumvalues.push_back("extra-condensed");
	info._enumvalues.push_back("condensed");
	info._enumvalues.push_back("semi-condensed");
	info._enumvalues.push_back("semi-expanded");
	info._enumvalues.push_back("expanded");
	info._enumvalues.push_back("extra-expanded");
	info._enumvalues.push_back("ultra-expanded");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrFont_Style;
	info._group = groupFont;
	info._name = "font-style";
	info._groupname = "font";
	info._help = "This property specifies whether the text is to be rendered using a normal, italic or oblique face.";

	/*
	* !!! info._datatype = SvgAttributeDataType_datatypeEnum;
	* 
	* info._enumvalues.Add("normal"); info._enumvalues.Add("italic");
	* info._enumvalues.Add("oblique"); info._enumvalues.Add("inherit");
	*/

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrFont_Variant;
	info._group = groupFont;
	info._name = "font-variant";
	info._groupname = "font";
	info._help = "This property indicates whether the text is to be rendered using the normal glyphs for lowercase characters or using small-caps glyphs for lowercase characters.";

	info._datatype = SvgAttributeDataType_datatypeEnum;

	info._enumvalues.push_back("normal");
	info._enumvalues.push_back("small-caps");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrFont_Weight;
	info._group = groupFont;
	info._name = "font-weight";
	info._groupname = "font";
	info._help = "This property refers to the boldness or lightness of the glyphs used to render the text, relative to other fonts in the same font family.";
	/*
	* !!! info._datatype = SvgAttributeDataType_datatypeEnum;
	* 
	* info._enumvalues.Add("normal"); info._enumvalues.Add("bold");
	* info._enumvalues.Add("bolder"); info._enumvalues.Add("lighter");
	* info._enumvalues.Add("100"); info._enumvalues.Add("200");
	* info._enumvalues.Add("300"); info._enumvalues.Add("400");
	* info._enumvalues.Add("500"); info._enumvalues.Add("600");
	* info._enumvalues.Add("700"); info._enumvalues.Add("800");
	* info._enumvalues.Add("900"); info._enumvalues.Add("inherit");
	*/

	g_mapAttrInfo.push_back(info);
	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrText_Anchor;
	info._group = groupFont;
	info._name = "text-anchor";
	info._groupname = "font";
	info._help = "This property specifies whether the text is to be rendered using a normal, italic or oblique face.";
	g_mapAttrInfo.push_back(info);
	// ---
}

void InitGraphicsAttribute()
{
	_AttrInfo info;

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrGraphics_Display;
	info._group = groupGraphics;
	info._name = "display";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("auto");
	info._enumvalues.push_back("block");
	info._enumvalues.push_back("list-item");
	info._enumvalues.push_back("run-in");
	info._enumvalues.push_back("compact");
	info._enumvalues.push_back("marker");
	info._enumvalues.push_back("table");
	info._enumvalues.push_back("inline-table");
	info._enumvalues.push_back("table-row-group");
	info._enumvalues.push_back("table-header-group");
	info._enumvalues.push_back("table-footer-group");
	info._enumvalues.push_back("table-row");
	info._enumvalues.push_back("table-column-group");
	info._enumvalues.push_back("table-column");
	info._enumvalues.push_back("table-cell");
	info._enumvalues.push_back("table-caption");
	info._enumvalues.push_back("none");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrGraphics_ImageRendering;
	info._group = groupGraphics;
	info._name = "image-rendering";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("auto");
	info._enumvalues.push_back("optimizeSpeed");
	info._enumvalues.push_back("optimizeQuality");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrGraphics_PointerEvents;
	info._group = groupGraphics;
	info._name = "pointer-events";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("visiblePainted");
	info._enumvalues.push_back("visibleFill");
	info._enumvalues.push_back("visibleStroke");
	info._enumvalues.push_back("visible");
	info._enumvalues.push_back("painted");
	info._enumvalues.push_back("fill");
	info._enumvalues.push_back("stroke");
	info._enumvalues.push_back("all");
	info._enumvalues.push_back("none");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrGraphics_ShapeRendering;
	info._group = groupGraphics;
	info._name = "shape-rendering";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("auto");
	info._enumvalues.push_back("optimizeSpeed");
	info._enumvalues.push_back("crispEdges");
	info._enumvalues.push_back("geometricPrecision");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrGraphics_TextRendering;
	info._group = groupGraphics;
	info._name = "text-rendering";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("auto");
	info._enumvalues.push_back("optimizeSpeed");
	info._enumvalues.push_back("optimizeLegibility");
	info._enumvalues.push_back("geometricPrecision");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrGraphics_Visiblity;
	info._group = groupGraphics;
	info._name = "visibility";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("visible");
	info._enumvalues.push_back("hidden");
	info._enumvalues.push_back("collapse");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---
}

void InitLeftAttribute()
{
	_AttrInfo info;

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrCge_Layer_ObjectName;
	info._group = groupSvgCge;
	info._name = "ObjectName";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrCge_PSR_ObjectId;
	info._group = groupSvgCge;
	info._name = "ObjectId";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrCge_CN_ObjectId;
	info._group = groupSvgCge;
	info._name = "ObjectId";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrCge_LinkObjectIDnd;
	info._group = groupSvgCge;
	info._name = "LinkObjectIDnd";

	g_mapAttrInfo.push_back(info);

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrCge_LinkObjectIDznd;
	info._group = groupSvgCge;
	info._name = "LinkObjectIDznd";

	g_mapAttrInfo.push_back(info);
	// ---
}

void InitOpacityAttribute()
{
	_AttrInfo info;

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrOpacity_Opacity;
	info._group = groupOpacity;
	info._name = "opacity";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrOpacity_FillOpacity;
	info._group = groupOpacity;
	info._name = "fill-opacity";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrOpacity_StrokeOpacity;
	info._group = groupOpacity;
	info._name = "stroke-opacity";

	g_mapAttrInfo.push_back(info);
	// ---
}

void InitPaintAttribute()
{
	_AttrInfo info;

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_Color;
	info._group = groupPaint;
	info._name = "color";
	info._datatype = SvgAttributeDataType_datatypeColor;

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_Fill;
	info._group = groupPaint;
	info._name = "fill";
	info._datatype = SvgAttributeDataType_datatypeColor;

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_FillRule;
	info._group = groupPaint;
	info._name = "fill-rule";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("nonzero");
	info._enumvalues.push_back("evenodd");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_Stroke;
	info._group = groupPaint;
	info._name = "stroke";
	info._datatype = SvgAttributeDataType_datatypeColor;

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_StrokeWidth;
	info._group = groupPaint;
	info._name = "stroke-width";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_StrokeDashArray;
	info._group = groupPaint;
	info._name = "stroke-dasharray";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_StrokeDashOffSet;
	info._group = groupPaint;
	info._name = "stroke-dashoffset";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_StrokeLineCap;
	info._group = groupPaint;
	info._name = "stroke-linecap";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("butt");
	info._enumvalues.push_back("round");
	info._enumvalues.push_back("square");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_StrokeLineJoin;
	info._group = groupPaint;
	info._name = "stroke-linejoin";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("miter");
	info._enumvalues.push_back("round");
	info._enumvalues.push_back("bevel");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_StrokeMiterLimit;
	info._group = groupPaint;
	info._name = "stroke-miterlimit";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_ColorInterpolation;
	info._group = groupPaint;
	info._name = "color-interpolation";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("auto");
	info._enumvalues.push_back("sRGB");
	info._enumvalues.push_back("linearRGB");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_ColorInterpolationFilters;
	info._group = groupPaint;
	info._name = "color-interpolation-filters";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("auto");
	info._enumvalues.push_back("sRGB");
	info._enumvalues.push_back("linearRGB");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrPaint_ColorRendering;
	info._group = groupPaint;
	info._name = "color-rendering";

	info._datatype = SvgAttributeDataType_datatypeEnum;
	info._enumvalues.push_back("auto");
	info._enumvalues.push_back("optimizeSpeed");
	info._enumvalues.push_back("optimizeQuality");
	info._enumvalues.push_back("inherit");

	g_mapAttrInfo.push_back(info);
	// ---
}

void InitStyleAttribute()
{
	_AttrInfo info;

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrStyle_Class;
	info._group = groupStyle;
	info._name = "class";
	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrStyle_Style;
	info._group = groupStyle;
	//info._name = "style";
	info._name = "type";
	g_mapAttrInfo.push_back(info);
	// ---

// 	// ---
// 	info._enumvalues.clear();
// 	info._datatype=SvgAttributeDataType_datatypeString;
// 	info._type = attrStyle_CDATA;
// 	info._group = groupStyle;
// 	info._name = "#cdata-section";
// 	g_mapAttrInfo.push_back(info);
	// ---
}


void InitXLinkAttribute()
{
	_AttrInfo info;

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrXLink_Actuate;
	info._group = groupXLink;
	info._name = "xlink:actuate";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrXLink_HRef;
	info._group = groupXLink;
	info._name = "xlink:href";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrXLink_Role;
	info._group = groupXLink;
	info._name = "xlink:role";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrXLink_Show;
	info._group = groupXLink;
	info._name = "xlink:show";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrXLink_Target;
	info._group = groupXLink;
	info._name = "target";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrXLink_Title;
	info._group = groupXLink;
	info._name = "xlink:title";

	g_mapAttrInfo.push_back(info);
	// ---

	// ---
	info._enumvalues.clear();
	info._datatype=SvgAttributeDataType_datatypeString;
	info._type = attrXLink_Type;
	info._group = groupXLink;
	info._name = "xlink:type";

	g_mapAttrInfo.push_back(info);
	// ---
}

void InitSvgAttributes()
{
	if (m_bAttributeInited)
		return;
	m_bAttributeInited = true;

	g_mapAttrInfo.clear();			

	InitCoreAttribute();			
	InitElementSpecificAttribute();	
	InitStyleAttribute();			
	InitPaintAttribute();			
	InitGraphicsAttribute();		
	InitOpacityAttribute();			
	InitFontAttribute();			
	InitXLinkAttribute();			
	InitLeftAttribute();			
}

void ClearSvgAttributes()
{
	g_mapAttrInfo.clear();
}