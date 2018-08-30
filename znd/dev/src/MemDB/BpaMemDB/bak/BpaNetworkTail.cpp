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

extern	const	char*	g_lpszLogFileName;
extern	void	Log(const char* lpszLogFile, char* pformat, ...);

int		BpaTailorNetByVolt(tagBpaBlock* pBpaBlock, const unsigned char bDCBoundPV, const unsigned char bDCLine2Load, const char* lpszSlack, const char* lpszDCZone,
											   std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, std::vector<std::string>& strExcludeDCBusArray)
{
	return 1;
}

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


void RemoveLoadTran(tagBpaBlock* pBpaBlock)
{
	register int	i, j;
	int		nTran, nBusT, nBusH;
	int		nLineNum, nBusNum, nBusArray[200];
	unsigned char	bGenSub;
	double	fLoadP, fLoadQ;

	for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
		pBpaBlock->m_BpaDat_ACBusArray[i].nStatus=0;
	for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
		pBpaBlock->m_BpaDat_WindArray[i].nStatus=0;

	for (nTran=0; nTran<pBpaBlock->m_nRecordNum[BPA_DAT_TRAN]; nTran++)
	{
		//Log(g_lpszLogFileName, "判断主变[%d卷变]:(%s.%s)\n", pBpaBlock->m_BpaDat_TransformArray[nTran].nWindNum, pBpaBlock->m_BpaDat_TransformArray[nTran].szWindH);
		if (pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH < 0 || pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL < 0)
			continue;

		nBusH=-1;
		if (pBpaBlock->m_BpaDat_TranArray[nTran].nWindNum > 1)
		{
			nBusT=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus == pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nIBus || pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus == pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindL].nZBus) ?
				pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus;
			nBusH=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus == nBusT) ? pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus;
		}
		else
		{
			nBusH=(pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].fkVI > pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].fkVJ) ? pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nIBus : pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_TranArray[nTran].iRWindH].nZBus;
		}
		if (nBusH < 0)
			continue;

		bGenSub=0;
		BpaTraverseSub(pBpaBlock, nBusH, 0, nBusNum, nBusArray);
		for (i=0; i<nBusNum; i++)
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].bGenerator != 0 || pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].bDCBound != 0)
			{
				bGenSub=1;
				break;
			}
		}
		if (bGenSub)
			continue;

		nLineNum=0;
		for (i=0; i<nBusNum; i++)
		{
			if (nBusArray[i] == nBusH)
				continue;
			nLineNum += pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]+1].nACLineRange - pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].nACLineRange;
		}
		if (nLineNum > 0)
			continue;

		fLoadP = fLoadQ = 0;
		for (i=0; i<nBusNum; i++)
		{
			if (nBusArray[i] == nBusH)
				continue;
			pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].nStatus=1;

			fLoadP += pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fLoadP;
			fLoadQ += pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fLoadQ;

			pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fLoadP=0;
			pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fLoadQ=0;

			for (j=pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].nWindRange; j<pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]+1].nWindRange; j++)
				pBpaBlock->m_BpaDat_WindArray[pBpaBlock->m_BpaDat_EdgeWindArray[j].iRWind].nStatus=1;
		}

		if (fLoadQ > 0)
		{
			fLoadP += 0.001*sqrt(fLoadP*fLoadP+fLoadQ*fLoadQ);
			fLoadQ += 0.08*sqrt(fLoadP*fLoadP+fLoadQ*fLoadQ);
		}
		else
		{
			fLoadQ += 0.1*fLoadP;
		}

		pBpaBlock->m_BpaDat_ACBusArray[nBusH].fLoadP += fLoadP;
		pBpaBlock->m_BpaDat_ACBusArray[nBusH].fLoadQ += fLoadQ;
	}

	i=0;
	while (i < pBpaBlock->m_nRecordNum[BPA_DAT_WIND])
	{
		if (pBpaBlock->m_BpaDat_WindArray[i].nStatus)
		{
			Log(g_lpszLogFileName, "删除变压器:(%s)\n", pBpaBlock->m_BpaDat_WindArray[i].szKeyName);
			BpaRemoveRecord(pBpaBlock, BPA_DAT_WIND, i);
		}
		else
			i++;
	}

	i=0;
	while (i < pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS])
	{
		if (pBpaBlock->m_BpaDat_ACBusArray[i].nStatus)
		{
			Log(g_lpszLogFileName, "删除母线:(%s.%.2f)\n", pBpaBlock->m_BpaDat_ACBusArray[i].szName, pBpaBlock->m_BpaDat_ACBusArray[i].fkV);
			BpaRemoveRecord(pBpaBlock, BPA_DAT_ACBUS, i);
		}
		else
			i++;
	}

	BpaMaint(pBpaBlock);
}
