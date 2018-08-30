#ifndef TYNYXMLGLOBAL_HEADER
#define TYNYXMLGLOBAL_HEADER

#include "tinyxml.h"
#include "tinyxmlexp.h"

//extern	TiXmlElement* TINYXML_EXP addXmlElement(TiXmlElement* pParent, const char* lpszTag);
//extern	TiXmlElement* TINYXML_EXP addXmlElement(TiXmlElement* pParent, const char* lpszTag, const char* lpszValue);
//extern	TiXmlElement* TINYXML_EXP addXmlElement(TiXmlElement* pParent, const char* lpszTag, const double fValue);
//extern	TiXmlElement* TINYXML_EXP addXmlElement(TiXmlElement* pParent, const char* lpszTag, const float fValue);
//extern	TiXmlElement* TINYXML_EXP addXmlElement(TiXmlElement* pParent, const char* lpszTag, const int nValue);
//extern	TiXmlElement* TINYXML_EXP addXmlAttribute(TiXmlElement* pParent, const char* lpszTag, const char* lpszAttr, const char* lpszValue);
//extern	TiXmlElement* TINYXML_EXP addXmlAttribute(TiXmlElement* pParent, const char* lpszTag, const char* lpszAttr, const int nValue);
//extern	void TINYXML_EXP AppendXmlFile(const char* lpszFileName, TiXmlElement* pElement, const int nDepth);

extern 	TINYXML_EXP TiXmlElement*  addXmlElement(TiXmlElement* pParent, const char* lpszTag);
extern 	TINYXML_EXP TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag, const char* lpszValue);
extern 	TINYXML_EXP TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag, const double fValue);
extern 	TINYXML_EXP TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag, const float fValue);
extern	TINYXML_EXP TiXmlElement* addXmlElement(TiXmlElement* pParent, const char* lpszTag, const int nValue);
extern	TINYXML_EXP TiXmlElement* addXmlAttribute(TiXmlElement* pParent, const char* lpszTag, const char* lpszAttr, const char* lpszValue);
extern	TINYXML_EXP TiXmlElement* addXmlAttribute(TiXmlElement* pParent, const char* lpszTag, const char* lpszAttr, const int nValue);
extern	TINYXML_EXP void AppendXmlFile(const char* lpszFileName, TiXmlElement* pElement, const int nDepth);


#endif