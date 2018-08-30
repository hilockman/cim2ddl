#ifndef TYNYXMLGLOBAL_HEADER
#define TYNYXMLGLOBAL_HEADER

#include "tinyxml.h"

extern	TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag);
extern	TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag, const char* lpszValue);
extern	TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag, const double fValue);
extern	TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag, const float fValue);
extern	TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag, const int nValue);
extern	TiXmlElement* addXmlAttribute(TiXmlElement* pParent, const char* lpszTag, const char* lpszAttr, const char* lpszValue);
extern	TiXmlElement* addXmlAttribute(TiXmlElement* pParent, const char* lpszTag, const char* lpszAttr, const int nValue);
extern	void AppendXmlFile(const char* lpszFileName, TiXmlElement* pElement, const int nDepth);


#endif