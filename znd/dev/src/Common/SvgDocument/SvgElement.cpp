#include "stdafx.h"
#include "SvgElement.h"

extern	std::string GetSvgAttributeName(const _SvgAttributeType nType);
extern	void getAttributeXMLNode(TiXmlElement* pElement, tagSvgAttr* pAttr);
extern	std::string getAttributeXML(tagSvgAttr* pAttr);
CSvgElement::CSvgElement()
{
	m_nInternalId=0;

	m_attributes.clear();

	AddAttr(attrCore_Id, "");

	m_pParent = NULL;
	m_pChild = NULL;
	m_pNext = NULL;
	m_pPrevious = NULL;

	m_sElementName = "unsupported";
	m_sElementValue.clear();
	m_bElementHasValue = 0;
	m_ElementType = typeUnsupported;
}

CSvgElement::~CSvgElement(void)
{
	m_pParent = NULL;
	m_pChild = NULL;
	m_pNext = NULL;
	m_pPrevious = NULL;

	m_attributes.clear();
}

void CSvgElement::AddAttr(_SvgAttributeType type, std::string objValue)
{
	tagSvgAttr eleToAdd;
	eleToAdd.nAttrType=type;
	eleToAdd.strAttrValue=objValue;
	eleToAdd.bAttrHasValue=0;
	m_attributes.push_back(eleToAdd);
}

std::string CSvgElement::ElementInfo()
{
	char	szBuf[65];
	std::string sMsg = "InternalId:";
	itoa(m_nInternalId, szBuf, 10);	sMsg.append(szBuf);

	if (m_pParent != NULL)
	{
		sMsg.append(" - Parent:");
		itoa(m_pParent->getInternalId(), szBuf, 10);	sMsg.append(szBuf);
	}

	if (m_pPrevious != NULL)
	{
		sMsg.append(" - Previous:");
		itoa(m_pPrevious->getInternalId(), szBuf, 10);	sMsg.append(szBuf);
	}

	if (m_pNext != NULL)
	{
		sMsg.append(" - Next:");
		itoa(m_pNext->getInternalId(), szBuf, 10);	sMsg.append(szBuf);
	}

	if (m_pChild != NULL)
	{
		sMsg.append(" - Child:");
		itoa(m_pChild->getInternalId(), szBuf, 10);	sMsg.append(szBuf);
	}

	return sMsg;
}

int CSvgElement::GetAttribute(const _SvgAttributeType type)
{
	for (int i = 0; i<(int)m_attributes.size(); i++)
	{
		if (m_attributes[i].nAttrType == type)
		{
			return i;
		}
	}

	return -1;
}

int CSvgElement::GetAttribute(const char* lpszName)
{
	for (int i = 0; i<(int)m_attributes.size(); i++)
	{
		if (m_attributes[i].strAttrValue == lpszName)
			return i;
	}

	return -1;
}

std::string CSvgElement::GetAttributeValue(const _SvgAttributeType type)
{
	for (int i = 0; i<(int)m_attributes.size(); i++)
	{
		if (m_attributes[i].nAttrType == type)
			return m_attributes[i].strAttrValue;
	}

	return "";
}

CSvgElement* CSvgElement::getChild()
{
	return m_pChild;
}

std::string CSvgElement::getElementName()
{
	return m_sElementName;
}

_SvgElementType CSvgElement::getElementType()
{
	return m_ElementType;
}

char*	CSvgElement::getElementTypeName(const int nType)
{
	register int	i;
	for (i=0; i<sizeof(elementType)/sizeof(tagSVGElementType); i++)
	{
		if (nType == elementType[i].nType)
			return elementType[i].lpszType;
	}
	return "";
}

std::string CSvgElement::getElementValue()
{
	return m_sElementValue;
}

std::string CSvgElement::getId()
{
	return GetAttributeValue(attrCore_Id);
}

int CSvgElement::getInternalId()
{
	return m_nInternalId;
}

CSvgElement* CSvgElement::getNext()
{
	return m_pNext;
}

CSvgElement* CSvgElement::getParent()
{
	return m_pParent;
}

CSvgElement* CSvgElement::getPrevious()
{
	return m_pPrevious;
}

int CSvgElement::SetAttributeValue(const _SvgAttributeType type, const char* objValue)
{
	for (int i=0; i<(int)m_attributes.size(); i++)
	{
		if (m_attributes[i].nAttrType == type)
		{
			m_attributes[i].strAttrValue=objValue;
			m_attributes[i].bAttrHasValue=1;
			return 1;
		}
	}

	return 0;
}

int CSvgElement::SetAttributeValue(const char* lpszName, const char* sValue)
{
	for (int i=0; i<(int)m_attributes.size(); i++)
	{
		std::string	strName=GetSvgAttributeName(m_attributes[i].nAttrType);
		if (stricmp(strName.c_str(), lpszName) == 0)
		{
			m_attributes[i].strAttrValue=sValue;
			m_attributes[i].bAttrHasValue=1;
			return 1;
		}
	}

	return 0;
}

void CSvgElement::setChild(CSvgElement* pEle)
{
	m_pChild = pEle;
}

void CSvgElement::setElementValue(const char* lpszValue)
{
	m_sElementValue.clear();
	m_sElementValue=lpszValue;
	//TRACE("%s %d\n", m_sElementValue.c_str(), m_sElementValue.length());
}

void CSvgElement::setId(const char* value)
{
	SetAttributeValue(attrCore_Id, value);
}

void CSvgElement::setInternalId(int nId)
{
	m_nInternalId = nId;
}

void CSvgElement::setNext(CSvgElement* pEle)
{
	m_pNext = pEle;
}

void CSvgElement::setParent(CSvgElement* pEle)
{
	m_pParent = pEle;
}

void CSvgElement::setPrevious(CSvgElement* pEle)
{
	m_pPrevious = pEle;
}

//extern	void	Log(char* pformat, ...);
void CSvgElement::GetXML(FILE* fp)
{
	//Log(g_lpszLogFile, "GetXml[%d] Id=%d ", m_ElementType, m_nInternalId);
	if (m_ElementType != typeUnsupported)
	{
		if (getElementType() == typeCDATASection)
		{
			fprintf(fp, "\n<![CDATA[");
			fprintf(fp, "%s", m_sElementValue.c_str());
			fprintf(fp, "]]>\r\n");
		}
		else
		{
			//if (m_ElementType == typeText)
			//	Log(g_lpszLogFile, "    String=%s\n", m_sElementValue.c_str());
			OpenXmlTag(fp);
			if (m_pChild != NULL)
				m_pChild->GetXML(fp);
			CloseXmlTag(fp);
			//fflush(fp);
		}
	}
	//Log(g_lpszLogFile, "        OK\n", m_ElementType);

	CSvgElement* pEle = m_pNext;
	if (pEle != NULL)
		pEle->GetXML(fp);
}

std::string CSvgElement::GetXML()
{
	std::string sXML;
	sXML.clear();

	if (m_ElementType != typeUnsupported)
	{
		if (getElementType() == typeCDATASection)
		{
			sXML.append("\n<![CDATA[");
			sXML.append(m_sElementValue);
			sXML.append("]]>");
			sXML.append("\r\n");
		}
		else
		{
			sXML = OpenXmlTag();
			if (m_pChild != NULL)
				sXML.append( m_pChild->GetXML() );
			sXML.append( CloseXmlTag() );
		}
	}

	CSvgElement* pEle = m_pNext;
	if (pEle != NULL)
		sXML.append( pEle->GetXML() );

	return sXML;
}

std::string CSvgElement::GetTagXml()
{
	std::string sXML;

	sXML = OpenXmlTag();
	sXML.append( CloseXmlTag() );

	return sXML;
}

void CSvgElement::OpenXmlTag(FILE* fp)
{
	fprintf(fp, "<");
	fprintf(fp, "%s", m_sElementName.c_str());
	for (int i=0; i<(int)m_attributes.size(); i++)
		fprintf(fp, getAttributeXML(&m_attributes[i]).c_str());

	if (m_sElementValue.empty())
	{
		if (m_pChild == NULL)
			fprintf(fp, " />\r\n");
		else
			fprintf(fp, ">\r\n");
	}
	else
	{
		char	szBuf[260];
		fprintf(fp, ">");
		strcpy(szBuf, m_sElementValue.c_str());
		fprintf(fp, "%s", szBuf);
	}
}

void CSvgElement::CloseXmlTag(FILE* fp)
{
	if ((m_sElementValue.empty()) && (m_pChild == NULL))
	{
	}
	else
	{
		fprintf(fp, "</%s>\r\n", m_sElementName.c_str());
	}
}

std::string CSvgElement::OpenXmlTag()
{
	std::string sXML;

	sXML.clear();
	sXML.append("<");
	sXML.append(m_sElementName);
	for (int i=0; i<(int)m_attributes.size(); i++)
		sXML.append(getAttributeXML(&m_attributes[i]));

	if (m_sElementValue.empty())
	{
		if (m_pChild == NULL)
			sXML.append(" />\r\n");
		else
			sXML.append(">\r\n");
	}
	else
	{
		sXML.append(">");
		sXML.append(m_sElementValue);
	}

	return sXML;
}

std::string CSvgElement::CloseXmlTag()
{
	if ((m_sElementValue.empty()) && (m_pChild == NULL))
	{
		return "";
	}
	else
	{
		return "</" + m_sElementName + ">\r\n";
	}
}

void CSvgElement::GetXmlNode(TiXmlNode* pParent)
{
	if (m_ElementType != typeUnsupported)
	{
		if (getElementType() == typeCDATASection)
		{
			TiXmlText* pText=new TiXmlText(m_sElementValue);
			pText->SetCDATA(true);
			pParent->LinkEndChild(pText);
		}
		else
		{
			TiXmlElement*	pElement=new TiXmlElement(m_sElementName);
			OpenXmlNodeTag(pElement);
			pParent->LinkEndChild(pElement);
			if (m_pChild != NULL)
				m_pChild->GetXmlNode(pElement);
		}
	}

	CSvgElement* pEle = m_pNext;
	if (pEle != NULL)
		pEle->GetXmlNode(pParent);
}

void CSvgElement::OpenXmlNodeTag(TiXmlNode* pElement)
{
	for (int i=0; i<(int)m_attributes.size(); i++)
		getAttributeXMLNode((TiXmlElement *)pElement, &m_attributes[i]);

	//std::string	strBuf;
	if (!m_sElementValue.empty())
	{
		//TRACE("%s\n", m_sElementValue.c_str());
		//mbstowcs(wszBuf, m_sElementValue.c_str(), 260);
		//strBuf=wszBuf;

		//TiXmlElement->TiXmlBase.en

		TiXmlText*	pXmlText=new TiXmlText(m_sElementValue);
		//pXmlText->TiXmlBase

		pElement->LinkEndChild(pXmlText);
	}
}

//////////////////////////////////////////////////////////////////////////
//	CSvgRoot
//////////////////////////////////////////////////////////////////////////
CSvgRoot::CSvgRoot()
{
	m_sElementName = "svg";
	m_ElementType = typeSvg;

	AddAttr(attrSvg_XmlNs, "");
	AddAttr(attrSvg_XmlNsXLink, "");
	AddAttr(attrSvg_XmlNsCge, "");
	AddAttr(attrSvg_Version, "");

	AddAttr(attrSpecific_Description, "");
	AddAttr(attrSpecific_Latitude, "");
	AddAttr(attrSpecific_Width, "");
	AddAttr(attrSpecific_Height, "");
	AddAttr(attrSpecific_Viewbox, "");
	AddAttr(attrSpecific_preserveAspectRatio, "");

	SetAttributeValue(attrSvg_XmlNs, "http://www.w3.org/2000/svg");
	SetAttributeValue(attrSvg_XmlNsXLink, "http://www.w3.org/1999/xlink");
	SetAttributeValue(attrSvg_XmlNsCge, "http://iec.ch/TC57/2005/SVG-schema#");
}

CSvgRoot::~CSvgRoot(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgA
//////////////////////////////////////////////////////////////////////////
CSvgA::CSvgA()
{
	m_sElementName = "a";
	m_ElementType = typeA;

	AddAttr(attrSpecific_X, "");
	AddAttr(attrSpecific_Y, "");
	AddAttr(attrSpecific_Width, "");
	AddAttr(attrSpecific_Height, "");
	AddAttr(attrXLink_HRef, "");
}

CSvgA::CSvgA(const char* sX, const char* sY, const char* sWidth, const char* sHeight, const char* sHRef)
{
	m_sElementName = "a";
	m_ElementType = typeA;

	AddAttr(attrSpecific_X, "");
	AddAttr(attrSpecific_Y, "");
	AddAttr(attrSpecific_Width, "");
	AddAttr(attrSpecific_Height, "");
	AddAttr(attrXLink_HRef, "");

	SetAttributeValue(attrSpecific_X, sX);
	SetAttributeValue(attrSpecific_Y, sY);
	SetAttributeValue(attrSpecific_Width, sWidth);
	SetAttributeValue(attrSpecific_Height, sHeight);
	SetAttributeValue(attrXLink_HRef, sHRef);
}

CSvgA::~CSvgA(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgGroup
//////////////////////////////////////////////////////////////////////////
CSvgGroup::CSvgGroup(void)
{
	m_sElementName = "g";
	m_ElementType = typeGroup;
}

CSvgGroup::~CSvgGroup(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgMetadata
//////////////////////////////////////////////////////////////////////////
CSvgMetadata::CSvgMetadata(void)
{
	m_sElementName = "metadata";
	m_ElementType = typeMetadata;
}

CSvgMetadata::~CSvgMetadata(void)
{
}

CSvgPSR_Ref::CSvgPSR_Ref(void)
{
	m_sElementName = "cge:PSR_Ref";
	m_ElementType = typeCgePSR_Ref;

	AddAttr(attrCge_PSR_ObjectId, "");
}

CSvgPSR_Ref::~CSvgPSR_Ref(void)
{
}

CSvgCN_Ref::CSvgCN_Ref(void)
{
	m_sElementName = "cge:CN_Ref";
	m_ElementType = typeCgeCN_Ref;

	AddAttr(attrCge_CN_ObjectId, "");
}

CSvgCN_Ref::~CSvgCN_Ref(void)
{
}

CSvgLayer_Ref::CSvgLayer_Ref(void)
{
	m_sElementName = "cge:Layer_Ref";
	m_ElementType = typeCgeLayer_Ref;

	AddAttr(attrCge_Layer_ObjectName, "");
}

CSvgLayer_Ref::~CSvgLayer_Ref(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgSymbol
//////////////////////////////////////////////////////////////////////////
CSvgSymbol::CSvgSymbol(void)
{
	m_sElementName = "symbol";
	m_ElementType = typeSymbol;

	AddAttr(attrSpecific_Width, "");
	AddAttr(attrSpecific_Height, "");
	AddAttr(attrSpecific_Viewbox, "");
	AddAttr(attrSpecific_preserveAspectRatio, "");
}

CSvgSymbol::~CSvgSymbol(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgText
//////////////////////////////////////////////////////////////////////////
CSvgText::CSvgText(void)
{
	m_sElementName = "text";
	m_bElementHasValue = 0;
	m_ElementType = typeText;

	AddAttr(attrCore_XmlBase, "");
	AddAttr(attrCore_XmlLang, "");
	AddAttr(attrCore_XmlSpace, "");
	AddAttr(attrPaint_Fill, "");
	AddAttr(attrPaint_Stroke, "");

	AddAttr(attrSpecific_X, "");
	AddAttr(attrSpecific_Y, "");
	AddAttr(attrSpecific_DX, "");
	AddAttr(attrSpecific_DY, "");
	AddAttr(attrSpecific_Rotate, "");
	AddAttr(attrSpecific_TextLength, "");
	AddAttr(attrSpecific_LengthAdjust, "");
	AddAttr(attrText_Anchor, "");

	AddAttr(attrStyle_Class, "");
	AddAttr(attrStyle_Style, "");

	AddAttr(attrFont_Family, "");
	AddAttr(attrFont_Size, "");
	AddAttr(attrFont_SizeAdjust, "");
	AddAttr(attrFont_Stretch, "");
	AddAttr(attrFont_Style, "");
	AddAttr(attrFont_Variant, "");
	AddAttr(attrFont_Weight, "");
}

CSvgText::~CSvgText(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgTspan
//////////////////////////////////////////////////////////////////////////
CSvgTspan::CSvgTspan(void)
{
	m_sElementName = "tspan";
	m_bElementHasValue = 0;
	m_ElementType = typeTspan;

	AddAttr(attrCore_XmlBase, "");
	AddAttr(attrCore_XmlLang, "");
	AddAttr(attrCore_XmlSpace, "");
	AddAttr(attrPaint_Fill, "");

	AddAttr(attrSpecific_X, "");
	AddAttr(attrSpecific_Y, "");
	AddAttr(attrSpecific_DX, "");
	AddAttr(attrSpecific_DY, "");
	AddAttr(attrSpecific_Rotate, "");
	AddAttr(attrSpecific_TextLength, "");
	AddAttr(attrSpecific_LengthAdjust, 0);
	AddAttr(attrText_Anchor, "");

	AddAttr(attrStyle_Class, "");
	AddAttr(attrStyle_Style, "");

	AddAttr(attrFont_Family, "");
	AddAttr(attrFont_Size, "");
	AddAttr(attrFont_SizeAdjust, "");
	AddAttr(attrFont_Stretch, 0);
	AddAttr(attrFont_Style, "");
	AddAttr(attrFont_Variant, "");
	AddAttr(attrFont_Weight, "");
}

CSvgTspan::~CSvgTspan(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgImage
//////////////////////////////////////////////////////////////////////////
CSvgImage::CSvgImage(void)
{
	m_sElementName = "image";
	m_ElementType = typeImage;

	AddAttr(attrSpecific_X, "");
	AddAttr(attrSpecific_Y, "");
	AddAttr(attrSpecific_Width, "");
	AddAttr(attrSpecific_Height, "");

	AddAttr(attrXLink_HRef, "");

	AddAttr(attrStyle_Class, "");
	AddAttr(attrStyle_Style, "");
}

CSvgImage::CSvgImage(const char* lpszX, const char* lpszY, const char* lpszWidth, const char* lpszHeight, const char* lpszHRef)
{
	m_sElementName = "image";
	m_ElementType = typeImage;

	AddAttr(attrSpecific_X, "");
	AddAttr(attrSpecific_Y, "");
	AddAttr(attrSpecific_Width, "");
	AddAttr(attrSpecific_Height, "");

	AddAttr(attrXLink_HRef, "");

	AddAttr(attrStyle_Class, "");
	AddAttr(attrStyle_Style, "");

	SetAttributeValue(attrSpecific_X, lpszX);
	SetAttributeValue(attrSpecific_Y, lpszY);
	SetAttributeValue(attrSpecific_Width, lpszWidth);
	SetAttributeValue(attrSpecific_Height, lpszHeight);
	SetAttributeValue(attrXLink_HRef, lpszHRef);
}

CSvgImage::~CSvgImage(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgTitle
//////////////////////////////////////////////////////////////////////////
CSvgTitle::CSvgTitle(void)
{
	m_sElementName = "title";
	m_bElementHasValue = 0;
	m_ElementType = typeTitle;
}

CSvgTitle::CSvgTitle(const char* lpszValue)
{
	m_sElementName = "title";
	m_bElementHasValue = 1;
	m_ElementType = typeTitle;

	m_sElementValue=lpszValue;
}

CSvgTitle::~CSvgTitle(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgUnsupported
//////////////////////////////////////////////////////////////////////////
CSvgUnsupported::CSvgUnsupported(const char* lpszName)
{
	m_sElementName = lpszName;
	m_sElementName.append(":unsupported");
	m_ElementType = typeUnsupported;
}

CSvgUnsupported::~CSvgUnsupported(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgCDATASection
//////////////////////////////////////////////////////////////////////////
CSvgCDATASection::CSvgCDATASection(void)
{
	m_sElementName = "CDATASection";
	m_ElementType = typeCDATASection;
}

CSvgCDATASection::~CSvgCDATASection(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgStyle
//////////////////////////////////////////////////////////////////////////
CSvgStyle::CSvgStyle(void)
{
	m_sElementName = "style";
	m_ElementType = typeStyle;

	AddAttr(attrStyle_Style, "");
	AddAttr(attrStyle_CDATA, "");
}

CSvgStyle::~CSvgStyle(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgDesc
//////////////////////////////////////////////////////////////////////////
CSvgDesc::CSvgDesc(void)
{
	m_sElementName = "desc";
	m_bElementHasValue = 0;
	m_ElementType = typeDesc;
}

CSvgDesc::CSvgDesc(const std::string sValue)
{
	m_sElementName = "desc";
	m_sElementValue=sValue;
	m_bElementHasValue = 1;
	m_ElementType = typeDesc;
}

CSvgDesc::~CSvgDesc(void)
{
}

//////////////////////////////////////////////////////////////////////////
//	CSvgDefs
//////////////////////////////////////////////////////////////////////////
CSvgDefs::CSvgDefs(void)
{
	m_sElementName = "defs";
	m_ElementType = typeDefs;
}

CSvgDefs::~CSvgDefs(void)
{
}
