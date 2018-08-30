#pragma once

#include <list>
#include <vector>
using namespace std;

enum _SvgAttributeType
{
	attrSvg_XmlNs=0,
	attrSvg_XmlNsXLink,
	attrSvg_XmlNsCge,
	attrSvg_Version,
	attrCore_Id,
	attrCore_XmlBase,
	attrCore_XmlLang,
	attrCore_XmlSpace,
	attrSpecific_Description,
	attrSpecific_Latitude,
	attrSpecific_X,
	attrSpecific_Y,
	attrSpecific_CX,
	attrSpecific_CY,
	attrSpecific_Width,
	attrSpecific_Height,
	attrSpecific_R,
	attrSpecific_RX,
	attrSpecific_RY,
	attrSpecific_DX,
	attrSpecific_DY,
	attrSpecific_X1,
	attrSpecific_Y1,
	attrSpecific_X2,
	attrSpecific_Y2,
	attrSpecific_Transform,
	attrSpecific_Rotate,
	attrSpecific_TextLength,
	attrSpecific_LengthAdjust,
	attrSpecific_PathData,
	attrSpecific_PathLength,
	attrSpecific_Points,
	attrSpecific_Viewbox,
	attrSpecific_preserveAspectRatio,
	attrStyle_Class,
	attrStyle_Style,
	attrStyle_CDATA,
	attrPaint_Color,
	attrPaint_Fill,
	attrPaint_FillRule,
	attrPaint_Stroke,
	attrPaint_StrokeWidth,
	attrPaint_StrokeDashArray,
	attrPaint_StrokeDashOffSet,
	attrPaint_StrokeLineCap,
	attrPaint_StrokeLineJoin,
	attrPaint_StrokeMiterLimit,
	attrPaint_ColorInterpolation,
	attrPaint_ColorInterpolationFilters,
	attrPaint_ColorRendering,
	attrOpacity_Opacity,
	attrOpacity_FillOpacity,
	attrOpacity_StrokeOpacity,
	attrGraphics_Display,
	attrGraphics_ImageRendering,
	attrGraphics_PointerEvents,
	attrGraphics_ShapeRendering,
	attrGraphics_TextRendering,
	attrGraphics_Visiblity,
	attrFont_Family,
	attrFont_Size,
	attrFont_SizeAdjust,
	attrFont_Stretch,
	attrFont_Style,
	attrFont_Variant,
	attrFont_Weight,
	attrXLink_Type,
	attrXLink_Role,
	attrXLink_Title,
	attrXLink_Show,
	attrXLink_Actuate,
	attrXLink_HRef,
	attrXLink_Target,
	attrText_Anchor,
	attrCge_PSR_ObjectId,
	attrCge_CN_ObjectId,
	attrCge_Layer_ObjectName,
	attrCge_LinkObjectIDnd,
	attrCge_LinkObjectIDznd,
};

enum _SvgAttributeDataType
{
	SvgAttributeDataType_datatypeNone=0,
	SvgAttributeDataType_datatypeString,
	SvgAttributeDataType_datatypeEnum,
	SvgAttributeDataType_datatypeColor,
	SvgAttributeDataType_datatypeHRef,
};

enum _SvgAttributeGroup
{
	groupUnknown=0,
	groupSvg,
	groupSvg11,
	groupSvgCge,
	groupCore,
	groupElementSpecific,
	groupStyle,
	groupPaint,
	groupGraphics,
	groupOpacity,
	groupFont,
	groupXLink,
};

enum _SvgColorInterpolation
{
	SvgColorInterpolation_not_set=0,
	SvgColorInterpolation_auto,
	SvgColorInterpolation_sRGB,
	SvgColorInterpolation_linearRGB,
	SvgColorInterpolation_inherit,
};

enum _SvgColorRendering
{
	SvgColorRendering_not_set=0,
	SvgColorRendering_auto,
	SvgColorRendering_optimizeSpeed,
	SvgColorRendering_optimizeQuality,
	SvgColorRendering_inherit,
};

enum _SvgFillRule
{
	SvgFillRule_not_set=0,
	SvgFillRule_nonzero,
	SvgFillRule_evenodd,
	SvgFillRule_inherit,
};

enum _SvgFontStretch
{
	SvgFontStretch_not_set=0,
	SvgFontStretch_normal,
	SvgFontStretch_wider,
	SvgFontStretch_narrower,
	SvgFontStretch_ultracondensed,
	SvgFontStretch_extracondensed,
	SvgFontStretch_condensed,
	SvgFontStretch_semicondensed,
	SvgFontStretch_semiexpanded,
	SvgFontStretch_expanded,
	SvgFontStretch_extraexpanded,
	SvgFontStretch_ultraexpanded,
	SvgFontStretch_inherit,
};

enum _SvgGraphicsDisplay
{
	SvgGraphicsDisplay_not_set=0,
	SvgGraphicsDisplay_auto,
	SvgGraphicsDisplay_block,
	SvgGraphicsDisplay_list_item,
	SvgGraphicsDisplay_run_in,
	SvgGraphicsDisplay_compact,
	SvgGraphicsDisplay_marker,
	SvgGraphicsDisplay_table,
	SvgGraphicsDisplay_inline_table,
	SvgGraphicsDisplay_table_row_group,
	SvgGraphicsDisplay_table_header_group,
	SvgGraphicsDisplay_table_footer_group,
	SvgGraphicsDisplay_table_row,
	SvgGraphicsDisplay_table_column_group,
	SvgGraphicsDisplay_table_column,
	SvgGraphicsDisplay_table_cell,
	SvgGraphicsDisplay_table_caption,
	SvgGraphicsDisplay_none,
	SvgGraphicsDisplay_inherit,
};

enum _SvgImageRendering
{
	SvgImageRendering_not_set=0,
	SvgImageRendering_optimizeSpeed,
	SvgImageRendering_optimizeQuality,
	SvgImageRendering_inherit,
};

enum _SvgLengthAdjust
{
	SvgLengthAdjust_not_set=0,
	SvgLengthAdjust_spacing,
	SvgLengthAdjust_spacingAndGlyphs,
};

enum _SvgLineCap
{
	SvgLineCap_not_set=0,
	SvgLineCap_butt,
	SvgLineCap_round,
	SvgLineCap_square,
	SvgLineCap_inherit,
};

enum _SvgLineJoin {
	SvgLineJoin_not_set=0,
	SvgLineJoin_miter,
	SvgLineJoin_round,
	SvgLineJoin_bevel,
	SvgLineJoin_inherit,
};

enum _SvgPointerEvents {
	SvgPointerEvents_not_set=0,
	SvgPointerEvents_visiblePainted,
	SvgPointerEvents_visibleFill,
	SvgPointerEvents_visibleStroke,
	SvgPointerEvents_visible,
	SvgPointerEvents_painted,
	SvgPointerEvents_fill,
	SvgPointerEvents_stroke,
	SvgPointerEvents_all,
	SvgPointerEvents_none,
	SvgPointerEvents_inherit,
};

enum _SvgShapeRendering {
	SvgShapeRendering_not_set=0,
	SvgShapeRendering_auto,
	SvgShapeRendering_optimizeSpeed,
	SvgShapeRendering_crispEdges,
	SvgShapeRendering_geometricPrecision,
	SvgShapeRendering_inherit,
};

enum _SvgTextRendering {
	SvgTextRendering_not_set=0,
	SvgTextRendering_auto,
	SvgTextRendering_optimizeSpeed,
	SvgTextRendering_optimizeLegibility,
	SvgTextRendering_geometricPrecision,
	SvgTextRendering_inherit,
};

enum _SvgVisibility {
	SvgVisibility_not_set=0,
	SvgVisibility_visible,
	SvgVisibility_hidden,
	SvgVisibility_collapse,
	SvgVisibility_inherit,
};

typedef	struct _AttrInfo
{
	_SvgAttributeType _type;
	_SvgAttributeGroup _group;
	_SvgAttributeDataType _datatype;
	std::string _name;
	std::string _groupname;
	std::string _help;
	std::vector<std::string> _enumvalues;
}	tagAttrInfo;

typedef	struct _SvgAttr
{
	_SvgAttributeType	nAttrType;
	std::string		strAttrValue;
	unsigned char	bAttrHasValue;
}	tagSvgAttr;
