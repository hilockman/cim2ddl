#include "stdafx.h"
#include <io.h>
#include <float.h>
#include <vector>
#include <stack>
using namespace	std;
#include "../../Common/TinyXML/tinyxml.h"
#include "../../Common/TinyXML/tinyxmlglobal.h"

#include "BpaMemDB.h"
using	namespace	BpaMemDB;

extern	CBpaMemDBInterface	g_BpaMemDBInterface;
extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, char* pformat, ...);

int	LoadTailorSet(const char* lpszFileName, unsigned char& bRetainTieHG, unsigned char& bDCBoundPV, char* lpszSlack, std::vector<std::string>& strRetainAreaArray, std::vector<std::string>& strExcludeACBusArray, std::vector<std::string>& strExcludeDCBusArray)
{
	bDCBoundPV=0;
	strRetainAreaArray.clear();
	strExcludeACBusArray.clear();
	strExcludeDCBusArray.clear();

	TiXmlDocument doc(lpszFileName);
	if (!doc.LoadFile())
		return 0;

	TiXmlElement* pRoot = doc.RootElement();
	if (stricmp(pRoot->Value(), "BpaPowerGridTailorSet") != 0)
	{
		doc.Clear();
		return 0;
	}

	// Traverse children of pRoot, populating the list of lines
	TiXmlElement*	pElement = pRoot->FirstChildElement();
	while (pElement != NULL)
	{
		if (stricmp(pElement->Value(), "RetainZone") == 0)			strRetainAreaArray.push_back(pElement->Attribute("Name"));
		else if (stricmp(pElement->Value(), "ExcludeACBus") == 0)	strExcludeACBusArray.push_back(pElement->Attribute("Name"));
		else if (stricmp(pElement->Value(), "ExcludeDCBus") == 0)	strExcludeDCBusArray.push_back(pElement->Attribute("Name"));
		else if (stricmp(pElement->Value(), "Slack") == 0)			strcpy(lpszSlack, pElement->Attribute("Name"));
		else if (stricmp(pElement->Value(), "RetainTieHG") == 0)	bRetainTieHG=atoi(pElement->Attribute("Name"));
		else if (stricmp(pElement->Value(), "DCBoundPV") == 0)		bDCBoundPV=atoi(pElement->Attribute("Name"));

		pElement = pElement->NextSiblingElement();
	}

	doc.Clear();

	return 1;
}

void	SaveTailorSet(const char* lpszFileName, const unsigned char bRetainTieHG, const unsigned char bDCBoundPV, const char* lpszSlack, std::vector<std::string>& strRetainAreaArray, std::vector<std::string>& strExcludeACBusArray, std::vector<std::string>& strExcludeDCBusArray)
{
	TiXmlElement*		pField;
	TiXmlDocument*		pDocument = new TiXmlDocument();								//创建一个XML的文档对象。
	TiXmlDeclaration*	pDeclare = new TiXmlDeclaration("1.0", "GB2312", "no");
	pDocument->LinkEndChild(pDeclare);

	TiXmlElement*		pRoot=new TiXmlElement("BpaPowerGridTailorSet");
	pDocument->LinkEndChild(pRoot);

	int				nItem;

	pField=new TiXmlElement("RetainTieHG");
	pField->SetAttribute("Name", bRetainTieHG);
	pRoot->LinkEndChild(pField);

	pField=new TiXmlElement("DCBoundPV");
	pField->SetAttribute("Name", bDCBoundPV);
	pRoot->LinkEndChild(pField);

	pField=new TiXmlElement("Slack");
	pField->SetAttribute("Name", lpszSlack);
	pRoot->LinkEndChild(pField);

	//addXmlAttribute(pRoot, "RetainTieHG", "Name", (int)bRetainTieHG);
	//addXmlAttribute(pRoot, "DCBoundPV", "Name", (int)bDCBoundPV);
	//addXmlAttribute(pRoot, "Slack", "Name", lpszSlack);
	for (nItem=0; nItem<(int)strRetainAreaArray.size(); nItem++)
	{
		pField=new TiXmlElement("RetainZone");
		pField->SetAttribute("Name", strRetainAreaArray[nItem].c_str());
		pRoot->LinkEndChild(pField);
		//addXmlAttribute(pRoot, "RetainZone", "Name", strRetainAreaArray[nItem].c_str());
	}
	for (nItem=0; nItem<(int)strExcludeACBusArray.size(); nItem++)
	{
		pField=new TiXmlElement("ExcludeACBus");
		pField->SetAttribute("Name", strExcludeACBusArray[nItem].c_str());
		pRoot->LinkEndChild(pField);
		//addXmlAttribute(pRoot, "ExcludeACBus", "Name", strExcludeACBusArray[nItem].c_str());
	}
	for (nItem=0; nItem<(int)strExcludeDCBusArray.size(); nItem++)
	{
		pField=new TiXmlElement("ExcludeDCBus");
		pField->SetAttribute("Name", strExcludeDCBusArray[nItem].c_str());
		pRoot->LinkEndChild(pField);
		//addXmlAttribute(pRoot, "ExcludeDCBus", "Name", strExcludeDCBusArray[nItem].c_str());
	}

	pDocument->SaveFile(lpszFileName);					//保存到文件
	pDocument->Clear();
	delete pDocument;
}
