#include <io.h>
#include "tinyxml.h"

TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag)
{
	TiXmlElement*	pElement=new TiXmlElement(lpszTag);
	pParent->LinkEndChild(pElement);

	return pElement;
}

TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag, const char* lpszValue)
{
	TiXmlElement*	pElement=new TiXmlElement(lpszTag);
	pElement->LinkEndChild(new TiXmlText(lpszValue));
	pParent->LinkEndChild(pElement);

	return pElement;
}

TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag, const double fValue)
{
	char	szBuf[260];
	sprintf(szBuf, "%f", fValue);
	TiXmlElement*	pElement=new TiXmlElement(lpszTag);
	pElement->LinkEndChild(new TiXmlText(szBuf));
	pParent->LinkEndChild(pElement);

	return pElement;
}

TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag, const float fValue)
{
	char	szBuf[260];
	sprintf(szBuf, "%f", fValue);
	TiXmlElement*	pElement=new TiXmlElement(lpszTag);
	pElement->LinkEndChild(new TiXmlText(szBuf));
	pParent->LinkEndChild(pElement);

	return pElement;
}

TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag, const int nValue)
{
	char	szBuf[260];
	sprintf(szBuf, "%d", nValue);
	TiXmlElement*	pElement=new TiXmlElement(lpszTag);
	pElement->LinkEndChild(new TiXmlText(szBuf));
	pParent->LinkEndChild(pElement);

	return pElement;
}

TiXmlElement* addXmlAttribute(TiXmlElement* pParent, const char* lpszTag, const char* lpszAttr, const char* lpszValue)
{
	TiXmlElement*	pField=new TiXmlElement(lpszTag);
	pField->SetAttribute(lpszAttr, lpszValue);
	pParent->LinkEndChild(pField);

	return pField;
}

TiXmlElement* addXmlAttribute(TiXmlElement* pParent, const char* lpszTag, const char* lpszAttr, const int nValue)
{
	TiXmlElement*	pField=new TiXmlElement(lpszTag);
	pField->SetAttribute(lpszAttr, nValue);
	pParent->LinkEndChild(pField);

	return pField;
}

void AppendXmlFile(const char* lpszFileName, TiXmlElement* pElement, const int nDepth)
{
	if (access(lpszFileName, 0) != 0)
		return;

	FILE*	fp=fopen(lpszFileName, "a");
	if (fp != NULL)
	{
		pElement->Print(fp, nDepth);
		fprintf(fp, "\n");
		fflush(fp);
		fclose(fp);
	}
}
