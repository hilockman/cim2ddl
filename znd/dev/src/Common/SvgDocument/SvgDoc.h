#pragma once
#include "SvgElement.h"
#include "SvgBasicShape.h"

class 	CSvgDoc
{
//	friend class CSvgRoot;

public:
	CSvgDoc(void);
	~CSvgDoc(void);

public:
	std::vector<CSvgElement*>	m_elements;

public:
	CSvgRoot*	CreateNewDocument();
	void AddElement(CSvgElement* pParent, CSvgElement* pEleToAdd);
	unsigned char	LoadFromFile(const char* lpszFilename, const unsigned char bUtf8=0);
	unsigned char	SaveToFile(const char* lpszFilename);

public:
	CSvgElement* AddElement(CSvgElement* pParent, const char* lpszName);
	CSvgUnsupported* AddUnsupported(CSvgElement* pParent, const char* lpszName);
	CSvgDefs* AddDefs(CSvgElement* pParent);
	CSvgStyle* AddStyle(CSvgElement* pParent);
	CSvgCDATASection* AddCDATASection(CSvgElement* pParent);
	CSvgDesc* AddDesc(CSvgElement* pParent);
	CSvgGroup* AddGroup(CSvgElement* pParent);
	CSvgA* AddA(CSvgElement* pParent);
	CSvgText* AddText(CSvgElement* pParent);
	CSvgRect* AddRect(CSvgElement* pParent);
	CSvgCircle* AddCircle(CSvgElement* pParent);
	CSvgEllipse* AddEllipse(CSvgElement* pParent);
	CSvgLine* AddLine(CSvgElement* pParent);
	CSvgPath* AddPath(CSvgElement* pParent);
	CSvgPolygon* AddPolygon(CSvgElement* pParent);
	CSvgPolyline* AddPolyline(CSvgElement* pParent);
	CSvgImage* AddImage(CSvgElement* pParent);
	CSvgSymbol* AddSymbol(CSvgElement* pParent);
	CSvgUse* AddUse(CSvgElement* pParent);
	CSvgMetadata* AddMetaData(CSvgElement* pParent);
	CSvgPSR_Ref* AddPSR_Ref(CSvgElement* pParent);
	CSvgCN_Ref* AddCN_Ref(CSvgElement* pParent);

private:
	std::string GetXML();
	void GetXML(FILE* fp);
	void GetXmlNode(TiXmlDocument* pDocument);
	unsigned char IsLastSibling(CSvgElement* pEle);
	CSvgElement* GetLastSibling(CSvgElement* pEle);
	void parseSvgNode(TiXmlNode* pXmlNode, CSvgElement* pSvgElement, const unsigned char bUtf8=0);

private:
	CSvgRoot* m_pRoot;
	int m_nNextId;
	std::string m_sXmlDeclaration;
	std::string m_sXmlDocType;
};
