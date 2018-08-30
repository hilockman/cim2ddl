#include "stdafx.h"
#include "SvgDoc.h"
#include <Windows.h>

const	static	double	g_fScale=0.2;

std::string ConvertUtf8ToGBK(const char* lpszUtf8) 
{
	int len=MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)lpszUtf8, -1, NULL, 0);
	unsigned short * wszGBK = new unsigned short[len+1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)lpszUtf8, -1, (LPWSTR)wszGBK, len);

	len = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wszGBK, -1, NULL, 0, NULL, NULL);
	char *szGBK=new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte (CP_ACP, 0, (LPCWSTR)wszGBK, -1, szGBK, len, NULL, NULL);

	std::string strReturn=szGBK;
	delete[] szGBK;
	delete[] wszGBK;

	return strReturn;
}

std::string ConvertGBKToUtf8(const char* lpszGBK)
{
	int len=MultiByteToWideChar(CP_ACP, 0, (LPCSTR)lpszGBK, -1, NULL, 0);
	unsigned short * wszUtf8 = new unsigned short[len+1];
	memset(wszUtf8, 0, len * 2 + 2);
	MultiByteToWideChar(CP_ACP, 0, (LPCSTR)lpszGBK, -1, (LPWSTR)wszUtf8, len);

	len = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)wszUtf8, -1, NULL, 0, NULL, NULL);
	char *szUtf8=new char[len + 1];
	memset(szUtf8, 0, len + 1);
	WideCharToMultiByte (CP_UTF8, 0, (LPCWSTR)wszUtf8, -1, szUtf8, len, NULL, NULL);

	std::string strReturn = szUtf8;
	delete[] szUtf8;
	delete[] wszUtf8;

	return strReturn;
}
std::string Color2String(const int nRed, const int nGreen, const int nBlue)
{
	char	szBuf[260];
	std::string sColor = "#";

	sprintf(szBuf, "%x", nRed);	sColor.append(szBuf);
	sprintf(szBuf, "%x", nGreen);	sColor.append(szBuf);
	sprintf(szBuf, "%x", nBlue);	sColor.append(szBuf);

	return sColor;
}

CSvgDoc::CSvgDoc(void)
{
	m_nNextId = 1;
	m_pRoot=NULL;

	//InitSvgAttributes();
	//m_sXmlDeclaration = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
	m_sXmlDeclaration = "<?xml version=\"1.0\" encoding=\"GB2312\" ?>";
	//m_sXmlDeclaration = "<?xml version=\"1.0\"  ?>";
	m_sXmlDocType = "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">";
}

CSvgDoc::~CSvgDoc(void)
{
	for (int i=0; i<(int)m_elements.size(); i++)
		delete m_elements[i];
	m_elements.clear();

	//ClearSvgAttributes();
}

CSvgRoot* CSvgDoc::CreateNewDocument()
{
	if (m_pRoot != NULL)
	{
		m_pRoot = NULL;
		m_nNextId = 1;
		for (int i=0; i<(int)m_elements.size(); i++)
			delete m_elements[i];
		m_elements.clear();
	}

	m_pRoot = new CSvgRoot();
	m_pRoot->setInternalId(m_nNextId++);

	m_elements.push_back(m_pRoot);

	m_pRoot->SetAttributeValue(attrSvg_XmlNs, "http://www.w3.org/2000/svg");
	m_pRoot->SetAttributeValue(attrSvg_XmlNsXLink, "http://www.w3.org/1999/xlink");
	m_pRoot->SetAttributeValue(attrSvg_XmlNsCge, "http://iec.ch/TC57/2005/SVG-schema#");
	m_pRoot->SetAttributeValue(attrSvg_Version, "1.1");

	return m_pRoot;
}

unsigned char CSvgDoc::LoadFromFile(const char* lpszFilename, const unsigned char bUtf8)
{
	TiXmlDocument doc(lpszFilename);
	if (!doc.LoadFile())
		return 0;

	if ( m_pRoot != NULL )
	{
		m_pRoot = NULL;
		m_nNextId = 1;
		for (int i=0; i<(int)m_elements.size(); i++)
			delete m_elements[i];
		m_elements.clear();
	}

	std::string tmp;
	CSvgElement* pEleParent = NULL;
	TiXmlNode* pXmlEle = doc.RootElement();

	parseSvgNode(pXmlEle, pEleParent, bUtf8);

	doc.Clear();

	return 1;
}

void CSvgDoc::parseSvgNode(TiXmlNode* pXmlNode, CSvgElement* pSvgElement, const unsigned char bUtf8)
{
	while (pXmlNode != NULL)
	{
		switch (pXmlNode->Type())
		{
			//case XmlNodeType.Attribute:
			//	tmp = reader.Name;
			//	tmp = reader.Value;
			//	break;
		case TiXmlNode::TINYXML_ELEMENT:
			{
				TiXmlElement*	pXmlElement=pXmlNode->ToElement();
				CSvgElement* pSvgEle = AddElement(pSvgElement, pXmlNode->Value());
				if ( pSvgEle != NULL )
				{
					TiXmlAttribute*	pAttr=pXmlElement->FirstAttribute();
					while (pAttr != NULL)
					{
						if (bUtf8)
							pSvgEle->SetAttributeValue(pAttr->Name(), ConvertUtf8ToGBK(pAttr->Value()).c_str());
						else
							pSvgEle->SetAttributeValue(pAttr->Name(), pAttr->Value());
						pAttr=pAttr->Next();
					}

					TiXmlNode* pNode=pXmlNode->FirstChild();
					if (pNode != NULL)
						parseSvgNode(pNode, pSvgEle, bUtf8);
				}
			}
			break;

		case TiXmlNode::TINYXML_TEXT:
			{
				const TiXmlText*	pText=pXmlNode->ToText();
				if (pText)
				{
					if (pText->CDATA())
					{
						CSvgElement* pSvgEle=AddCDATASection(pSvgElement);
						pSvgEle->setElementValue(pText->Value());
					}
					else
					{
						if (bUtf8)
							pSvgElement->setElementValue(ConvertUtf8ToGBK(pText->Value()).c_str());
						else
							pSvgElement->setElementValue(pText->Value());
					}
				}
			}

			break;

		//case XmlNodeType.CDATA:
		//	break;
		//case XmlNodeType.ProcessingInstruction:
		//	break;
		case TiXmlNode::TINYXML_COMMENT:
			{
				TiXmlText*	pText=(TiXmlText*)pXmlNode;
				//if ( pText->CDATA() )
				//	ASSERT(FALSE);
			}
			break;

		case TiXmlNode::TINYXML_DECLARATION:
			m_sXmlDeclaration = "<?xml ";
			m_sXmlDeclaration.append(pXmlNode->Value());
			m_sXmlDeclaration.append("?>");
			break;

		case TiXmlNode::TINYXML_DOCUMENT:
			{
				TiXmlText*	pText=(TiXmlText*)pXmlNode;
				//if ( pText->CDATA() )
				//	ASSERT(FALSE);
			}
			break;

			//case XmlNodeType.DocumentType:
			//	{
			//		std::string sDTD1;
			//		std::string sDTD2;
			//
			//		sDTD1 = reader.GetAttribute("PUBLIC");
			//		sDTD2 = reader.GetAttribute("SYSTEM");
			//
			//		m_sXmlDocType = "<!DOCTYPE svg PUBLIC \"" + sDTD1 + "\" \"" + sDTD2 + "\">";
			//	}
			//	break;

			//case XmlNodeType.EntityReference:
			//	break;
			//case XmlNodeType.EndElement:
			//	if ( pEleParent != NULL )
			//	{
			//		pEleParent = pEleParent.getParent();
			//	}
			//	break;
		}
		pXmlNode = pXmlNode->NextSibling();
	}
}

unsigned char CSvgDoc::SaveToFile(const char* lpszFilename)
{
	FILE*	fp=fopen(lpszFilename, "wt");
	if (fp == NULL)
		return 0;


	//GetXML();
	std::string	strXml=GetXML();
	fprintf(fp, "%s", strXml.c_str());
	fflush(fp);
	fclose(fp);

//	TiXmlDocument*	pDocument = new TiXmlDocument();								//创建一个XML的文档对象。
//	GetXmlNode(pDocument);					//保存到文件
//	pDocument->SaveFile(lpszFilename);					//保存到文件
//
//	pDocument->Clear();
//	delete pDocument;
	return 1;
}

void CSvgDoc::GetXmlNode(TiXmlDocument* pDocument)
{
	TiXmlDeclaration*	pDeclare = new TiXmlDeclaration("1.0", "UTF-8", "no");
	pDocument->LinkEndChild(pDeclare);
	m_pRoot->GetXmlNode(pDocument);
}

std::string CSvgDoc::GetXML()
{
	if (m_pRoot == NULL )
		return "";

	std::string sXML;

	sXML = m_sXmlDeclaration;
	sXML.append("\r\n");
	//////////////////////////////////////////////////////////////////////////
	//递归调用，用以StackOverflow
	//sXML.append(m_pRoot->GetXML());

	sXML.append(m_pRoot->OpenXmlTag());
	CSvgElement* pEle = m_pRoot->getChild();
	while (pEle != NULL)
	{
		if (pEle->getElementType() != typeUnsupported)
		{
			if (pEle->getElementType() == typeCDATASection)
			{
				sXML.append("\n<![CDATA[");
				sXML.append(pEle->getElementValue());
				sXML.append("]]>");
				sXML.append("\r\n");
			}
			else
			{
				sXML.append(pEle->OpenXmlTag());
				CSvgElement* pChild1=pEle->getChild();
				while (pChild1 != NULL)
				{
					if (pChild1->getElementType() != typeUnsupported)
					{
						if (pChild1->getElementType() == typeCDATASection)
						{
							sXML.append("\n<![CDATA[");
							sXML.append(pChild1->getElementValue());
							sXML.append("]]>");
							sXML.append("\r\n");
						}
						else
						{
							sXML.append(pChild1->OpenXmlTag());
							CSvgElement* pChild2=pChild1->getChild();
							while (pChild2 != NULL)
							{
								if (pChild2->getElementType() != typeUnsupported)
								{
									if (pChild2->getElementType() == typeCDATASection)
									{
										sXML.append("\n<![CDATA[");
										sXML.append(pChild2->getElementValue());
										sXML.append("]]>");
										sXML.append("\r\n");
									}
									else
									{
										sXML.append(pChild2->OpenXmlTag());
										CSvgElement* pChild3=pChild2->getChild();
										while (pChild3 != NULL)
										{
											if (pChild3->getElementType() != typeUnsupported)
											{
												if (pChild3->getElementType() == typeCDATASection)
												{
													sXML.append("\n<![CDATA[");
													sXML.append(pChild3->getElementValue());
													sXML.append("]]>");
													sXML.append("\r\n");
												}
												else
												{
													sXML.append(pChild3->OpenXmlTag());
													CSvgElement* pChild4=pChild3->getChild();
													while (pChild4 != NULL)
													{
														if (pChild4->getElementType() != typeUnsupported)
														{
															if (pChild4->getElementType() == typeCDATASection)
															{
																sXML.append("\n<![CDATA[");
																sXML.append(pChild4->getElementValue());
																sXML.append("]]>");
																sXML.append("\r\n");
															}
															else
															{
																sXML.append(pChild4->OpenXmlTag());
																CSvgElement* pChild5=pChild4->getChild();
																while (pChild5 != NULL)
																{
																	if (pChild5->getElementType() != typeUnsupported)
																	{
																		if (pChild5->getElementType() == typeCDATASection)
																		{
																			sXML.append("\n<![CDATA[");
																			sXML.append(pChild5->getElementValue());
																			sXML.append("]]>");
																			sXML.append("\r\n");
																		}
																		else
																		{
																			sXML.append(pChild5->OpenXmlTag());

																			sXML.append(pChild5->CloseXmlTag());
																		}
																	}
																	pChild5=pChild5->getNext();
																}
																sXML.append(pChild4->CloseXmlTag());
															}
														}
														pChild4=pChild4->getNext();
													}
													sXML.append(pChild3->CloseXmlTag());
												}
											}
											pChild3=pChild2->getNext();
										}
										sXML.append(pChild2->CloseXmlTag());
									}
								}
								pChild2=pChild2->getNext();
							}
							sXML.append(pChild1->CloseXmlTag());
						}
					}
					pChild1=pChild1->getNext();
				}
				sXML.append(pEle->CloseXmlTag());
			}
		}
		pEle=pEle->getNext();
	}
	sXML.append(m_pRoot->CloseXmlTag());
	return sXML;
}

void CSvgDoc::GetXML(FILE* fp)
{
	if (m_pRoot == NULL )
		return;

	fprintf(fp, "%s\r\n", m_sXmlDeclaration.c_str());
	//////////////////////////////////////////////////////////////////////////
	//递归调用，用以StackOverflow
	//m_pRoot->GetXML(fp);

	m_pRoot->OpenXmlTag(fp);
	CSvgElement* pEle = m_pRoot->getChild();
	while (pEle != NULL)
	{
		if (pEle->getElementType() != typeUnsupported)
		{
			if (pEle->getElementType() == typeCDATASection)
			{
				fprintf(fp, "\n<![CDATA[");
				fprintf(fp, "%s", pEle->getElementValue().c_str());
				fprintf(fp, "]]>\r\n");
			}
			else
			{
				pEle->OpenXmlTag(fp);
				CSvgElement* pChild1=pEle->getChild();
				while (pChild1 != NULL)
				{
					if (pChild1->getElementType() != typeUnsupported)
					{
						if (pChild1->getElementType() == typeCDATASection)
						{
							fprintf(fp, "\n<![CDATA[");
							fprintf(fp, "%s", pChild1->getElementValue().c_str());
							fprintf(fp, "]]>\r\n");
						}
						else
						{
							pChild1->OpenXmlTag(fp);
							CSvgElement* pChild2=pChild1->getChild();
							while (pChild2 != NULL)
							{
								if (pChild2->getElementType() != typeUnsupported)
								{
									if (pChild2->getElementType() == typeCDATASection)
									{
										fprintf(fp, "\n<![CDATA[");
										fprintf(fp, "%s", pChild2->getElementValue().c_str());
										fprintf(fp, "]]>\r\n");
									}
									else
									{
										pChild2->OpenXmlTag(fp);
										CSvgElement* pChild3=pChild2->getChild();
										while (pChild3 != NULL)
										{
											if (pChild3->getElementType() != typeUnsupported)
											{
												if (pChild3->getElementType() == typeCDATASection)
												{
													fprintf(fp, "\n<![CDATA[");
													fprintf(fp, "%s", pChild3->getElementValue().c_str());
													fprintf(fp, "]]>\r\n");
												}
												else
												{
													pChild3->OpenXmlTag(fp);
													CSvgElement* pChild4=pChild3->getChild();
													while (pChild4 != NULL)
													{
														if (pChild4->getElementType() != typeUnsupported)
														{
															if (pChild4->getElementType() == typeCDATASection)
															{
																fprintf(fp, "\n<![CDATA[");
																fprintf(fp, "%s", pChild4->getElementValue().c_str());
																fprintf(fp, "]]>\r\n");
															}
															else
															{
																pChild4->OpenXmlTag(fp);
																CSvgElement* pChild5=pChild4->getChild();
																while (pChild5 != NULL)
																{
																	if (pChild5->getElementType() != typeUnsupported)
																	{
																		if (pChild5->getElementType() == typeCDATASection)
																		{
																			fprintf(fp, "\n<![CDATA[");
																			fprintf(fp, "%s", pChild5->getElementValue().c_str());
																			fprintf(fp, "]]>\r\n");
																		}
																		else
																		{
																			pChild5->OpenXmlTag(fp);

																			pChild5->CloseXmlTag(fp);
																		}
																	}
																	pChild5=pChild5->getNext();
																}
																pChild4->CloseXmlTag(fp);
															}
														}
														pChild4=pChild4->getNext();
													}
													pChild3->CloseXmlTag(fp);
												}
											}
											pChild3=pChild2->getNext();
										}
										pChild2->CloseXmlTag(fp);
									}
								}
								pChild2=pChild2->getNext();
							}
							pChild1->CloseXmlTag(fp);
						}
					}
					pChild1=pChild1->getNext();
				}
				pEle->CloseXmlTag(fp);
			}
		}
		pEle=pEle->getNext();
	}
	m_pRoot->CloseXmlTag(fp);
}

CSvgElement* CSvgDoc::AddElement(CSvgElement* pParent, const char* lpszName)
{
	CSvgElement* eleToReturn = NULL;

	if ( stricmp(lpszName, "svg" ) == 0)
	{
		m_pRoot = new CSvgRoot();
		m_pRoot->setInternalId(m_nNextId++);

		m_elements.push_back(m_pRoot);
		eleToReturn = m_pRoot;
	}
	else if ( stricmp(lpszName, "desc" ) == 0)
	{
		eleToReturn = AddDesc(pParent);
	}
	else if ( stricmp(lpszName, "style" ) == 0)
	{
		eleToReturn = AddStyle(pParent);
	}
	else if ( stricmp(lpszName, "text" ) == 0)
	{
		eleToReturn = AddText(pParent);
	}
	else if ( stricmp(lpszName, "a" ) == 0)
	{
		eleToReturn = AddA(pParent);
	}
	else if ( stricmp(lpszName, "defs" ) == 0)
	{
		eleToReturn = AddDefs(pParent);
	}
	else if ( stricmp(lpszName, "g" ) == 0)
	{
		eleToReturn = AddGroup(pParent);
	}
	else if ( stricmp(lpszName, "rect" ) == 0)
	{
		eleToReturn = AddRect(pParent);
	}
	else if ( stricmp(lpszName, "circle" ) == 0)
	{
		eleToReturn = AddCircle(pParent);
	}
	else if ( stricmp(lpszName, "ellipse" ) == 0)
	{
		eleToReturn = AddEllipse(pParent);
	}
	else if ( stricmp(lpszName, "line" ) == 0)
	{
		eleToReturn = AddLine(pParent);
	}
	else if ( stricmp(lpszName, "path" ) == 0)
	{
		eleToReturn = AddPath(pParent);
	}
	else if ( stricmp(lpszName, "polygon" ) == 0)
	{
		eleToReturn = AddPolygon(pParent);
	}
	else if ( stricmp(lpszName, "image" ) == 0)
	{
		eleToReturn = AddImage(pParent);
	}
	else if ( stricmp(lpszName, "symbol" ) == 0)
	{
		eleToReturn = AddSymbol(pParent);
	}
	else if ( stricmp(lpszName, "use" ) == 0)
	{
		eleToReturn = AddUse(pParent);
	}
	else if ( stricmp(lpszName, "metadata" ) == 0)
	{
		eleToReturn = AddMetaData(pParent);
	}
	else if ( stricmp(lpszName, "cge:PSR_Ref") == 0)
	{
		eleToReturn = AddPSR_Ref(pParent);
	}
	else if ( stricmp(lpszName, "polyline" ) == 0)
	{
		eleToReturn = AddPolyline(pParent);
	}
	else
	{
		if ( pParent != NULL )
		{
			eleToReturn = AddUnsupported(pParent, lpszName);
		}
	}

	return eleToReturn;
}

void CSvgDoc::AddElement(CSvgElement* pParent, CSvgElement* pEleToAdd)
{
	if ( pEleToAdd == NULL || m_pRoot == NULL )
		return;

	CSvgElement* pParentToAdd = m_pRoot;
	if ( pParent != NULL )
	{
		pParentToAdd = pParent;
	}

	pEleToAdd->setInternalId(m_nNextId++);
	m_elements.push_back(pEleToAdd);

	pEleToAdd->setParent(pParentToAdd);
	if (pParentToAdd->getChild() == NULL )
	{
		// the element is the first child
		pParentToAdd->setChild(pEleToAdd);
	}
	else
	{
		// add the element as the last sibling
		CSvgElement* pLast = GetLastSibling(pParentToAdd->getChild());

		if ( pLast != NULL )
		{
			pLast->setNext(pEleToAdd);
			pEleToAdd->setPrevious(pLast);
		}
	}
}

CSvgUnsupported* CSvgDoc::AddUnsupported(CSvgElement* pParent, const char* lpszName)
{
	CSvgUnsupported* uns = new CSvgUnsupported(lpszName);

	AddElement(pParent, uns);

	return uns;
}

CSvgDesc* CSvgDoc::AddDesc(CSvgElement* pParent)
{
	CSvgDesc* desc = new CSvgDesc();

	AddElement(pParent, desc);

	return desc;
}

CSvgDefs* CSvgDoc::AddDefs(CSvgElement* pParent)
{
	CSvgDefs* pEle = new CSvgDefs();

	AddElement(pParent, pEle);

	return pEle;
}

CSvgStyle* CSvgDoc::AddStyle(CSvgElement* pParent)
{
	CSvgStyle* pEle = new CSvgStyle();

	AddElement(pParent, pEle);

	return pEle;
}

CSvgCDATASection* CSvgDoc::AddCDATASection(CSvgElement* pParent)
{
	CSvgCDATASection* pEle = new CSvgCDATASection();

	AddElement(pParent, pEle);

	return pEle;
}

CSvgGroup* CSvgDoc::AddGroup(CSvgElement* pParent)
{
	CSvgGroup* grp = new CSvgGroup();

	AddElement(pParent, grp);

	return grp;
}

CSvgA* CSvgDoc::AddA(CSvgElement* pParent)
{
	CSvgA* pA = new CSvgA();

	AddElement(pParent, pA);

	return pA;
}

CSvgText* CSvgDoc::AddText(CSvgElement* pParent)
{
	CSvgText* txt = new CSvgText();

	AddElement(pParent, txt);

	return txt;
}

CSvgRect* CSvgDoc::AddRect(CSvgElement* pParent)
{
	CSvgRect* rect = new CSvgRect();

	AddElement(pParent, rect);

	return rect;
}

CSvgCircle* CSvgDoc::AddCircle(CSvgElement* pParent)
{
	CSvgCircle* circle = new CSvgCircle();

	AddElement(pParent, circle);

	return circle;
}

CSvgEllipse* CSvgDoc::AddEllipse(CSvgElement* pParent)
{
	CSvgEllipse* pEle = new CSvgEllipse();

	AddElement(pParent, pEle);

	return pEle;
}

CSvgLine* CSvgDoc::AddLine(CSvgElement* pParent)
{
	CSvgLine* pEle = new CSvgLine();

	AddElement(pParent, pEle);

	return pEle;
}

CSvgPath* CSvgDoc::AddPath(CSvgElement* pParent)
{
	CSvgPath* path = new CSvgPath();

	AddElement(pParent, path);

	return path;
}

CSvgPolygon* CSvgDoc::AddPolygon(CSvgElement* pParent)
{
	CSvgPolygon* pEle = new CSvgPolygon();

	AddElement(pParent, pEle);

	return pEle;
}

CSvgPolyline* CSvgDoc::AddPolyline(CSvgElement* pParent)
{
	CSvgPolyline* pEle = new CSvgPolyline();

	AddElement(pParent, pEle);

	return pEle;
}

CSvgImage* CSvgDoc::AddImage(CSvgElement* pParent)
{
	CSvgImage* pEle = new CSvgImage();

	AddElement(pParent, pEle);

	return pEle;
}

CSvgSymbol* CSvgDoc::AddSymbol(CSvgElement* pParent)
{
	CSvgSymbol* pEle = new CSvgSymbol();

	AddElement(pParent, pEle);

	return pEle;
}

CSvgUse* CSvgDoc::AddUse(CSvgElement* pParent)
{
	CSvgUse* pEle = new CSvgUse();

	AddElement(pParent, pEle);

	return pEle;
}

CSvgMetadata* CSvgDoc::AddMetaData(CSvgElement* pParent)
{
	CSvgMetadata* pEle = new CSvgMetadata();

	AddElement(pParent, pEle);

	return pEle;
}

CSvgPSR_Ref* CSvgDoc::AddPSR_Ref(CSvgElement* pParent)
{
	CSvgPSR_Ref* pEle = new CSvgPSR_Ref();

	AddElement(pParent, pEle);

	return pEle;
}

CSvgCN_Ref* CSvgDoc::AddCN_Ref(CSvgElement* pParent)
{
	CSvgCN_Ref* pEle = new CSvgCN_Ref();

	AddElement(pParent, pEle);

	return pEle;
}

unsigned char CSvgDoc::IsLastSibling(CSvgElement* pEle)
{
	CSvgElement* pLast = GetLastSibling(pEle);

	if ( pLast == NULL )
	{
		return false;
	}

	return (pEle->getInternalId() == pLast->getInternalId());
}

CSvgElement* CSvgDoc::GetLastSibling(CSvgElement* pEle)
{
	if ( pEle == NULL )
		return NULL;

	CSvgElement* pLast = pEle;
	while (pLast->getNext() != NULL)
	{
		pLast = pLast->getNext();
	}

	return pLast;
}
