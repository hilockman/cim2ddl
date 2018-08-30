#include "DCNetwork.h"
#include "../../Common/TinyXML/tinyxml.h"

extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	DCNetwork
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	void CDCNetwork::PRDCNetwork_SaveDataFile(tagPRBlock* pPRBlock, const char* lpszFileName)
	{
		register int	i;
		TiXmlElement*	pElement;

		clock_t	dBeg, dEnd;
		int		nDur;
		int		nBuf;

		dBeg=clock();

		TiXmlDocument*		pDocument = new TiXmlDocument();								//创建一个XML的文档对象。
		TiXmlDeclaration*	pDeclare = new TiXmlDeclaration("1.0", "GB2312", "no");
		pDocument->LinkEndChild(pDeclare);
		TiXmlElement*		pRoot = new TiXmlElement("DCFlowData");			//创建一个根元素并连接。
		pDocument->LinkEndChild(pRoot);

		pElement = new TiXmlElement("Common");
		pElement->SetDoubleAttribute("BaseMva", pPRBlock->m_System.fMvaBase);
		pRoot->LinkEndChild(pElement);

		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		{
			pElement = new TiXmlElement("ACLine");

			pElement->SetAttribute("Name",			pPRBlock->m_ACLineArray[i].szName);
			pElement->SetAttribute("BusNameI",		pPRBlock->m_ACLineArray[i].szBusI);
			pElement->SetAttribute("BusNameJ",		pPRBlock->m_ACLineArray[i].szBusJ);
			pElement->SetDoubleAttribute("kVI",		(double)pPRBlock->m_ACLineArray[i].fkVI);
			pElement->SetDoubleAttribute("kVJ",		(double)pPRBlock->m_ACLineArray[i].fkVJ);
			pElement->SetAttribute("BusI",			pPRBlock->m_ACLineArray[i].nIBus);
			pElement->SetAttribute("BusJ",			pPRBlock->m_ACLineArray[i].nZBus);
			pElement->SetDoubleAttribute("R",		(double)pPRBlock->m_ACLineArray[i].fR);
			pElement->SetDoubleAttribute("X",		(double)pPRBlock->m_ACLineArray[i].fX);
			pElement->SetDoubleAttribute("AcPi",	(double)pPRBlock->m_ACLineArray[i].fRtPi);
			pElement->SetDoubleAttribute("AcPz",	(double)pPRBlock->m_ACLineArray[i].fRtPz);
			pElement->SetDoubleAttribute("LossP",	(double)pPRBlock->m_ACLineArray[i].fLossP);
			pElement->SetDoubleAttribute("Rate",	(double)pPRBlock->m_ACLineArray[i].fRated);
			pElement->SetDoubleAttribute("Index",	pPRBlock->m_ACLineArray[i].nIndex);

			pRoot->LinkEndChild(pElement);
		}
		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_WIND]; i++)
		{
			pElement = new TiXmlElement("Wind");

			pElement->SetAttribute("Name",			pPRBlock->m_WindArray[i].szName);
			pElement->SetAttribute("BusNameI",		pPRBlock->m_WindArray[i].szBusI);
			pElement->SetAttribute("BusNameJ",		pPRBlock->m_WindArray[i].szBusJ);
			pElement->SetDoubleAttribute("kVI",		(double)pPRBlock->m_WindArray[i].fkVI);
			pElement->SetDoubleAttribute("kVJ",		(double)pPRBlock->m_WindArray[i].fkVJ);
			pElement->SetAttribute("BusI",			pPRBlock->m_WindArray[i].nIBus);
			pElement->SetAttribute("BusJ",			pPRBlock->m_WindArray[i].nZBus);
			pElement->SetDoubleAttribute("R",		(double)pPRBlock->m_WindArray[i].fR);
			pElement->SetDoubleAttribute("X",		(double)pPRBlock->m_WindArray[i].fX);
			pElement->SetDoubleAttribute("AcPi",	(double)pPRBlock->m_WindArray[i].fRtPi);
			pElement->SetDoubleAttribute("AcPz",	(double)pPRBlock->m_WindArray[i].fRtPz);
			pElement->SetDoubleAttribute("LossP",	(double)pPRBlock->m_WindArray[i].fLossP);
			pElement->SetDoubleAttribute("Rate",	(double)pPRBlock->m_WindArray[i].fRated);
			pElement->SetDoubleAttribute("Index",	pPRBlock->m_WindArray[i].nIndex);

			pRoot->LinkEndChild(pElement);
		}
		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_HVDC]; i++)
		{
			pElement = new TiXmlElement("HVDC");

			pElement->SetAttribute("Name",			pPRBlock->m_HVDCArray[i].szName);
			pElement->SetAttribute("BusNameR",		pPRBlock->m_HVDCArray[i].szACBusR);
			pElement->SetAttribute("BusNameI",		pPRBlock->m_HVDCArray[i].szACBusI);
			pElement->SetDoubleAttribute("kVR",		(double)pPRBlock->m_HVDCArray[i].fkVR);
			pElement->SetDoubleAttribute("kVI",		(double)pPRBlock->m_HVDCArray[i].fkVI);
			pElement->SetAttribute("BusR",			pPRBlock->m_HVDCArray[i].nRBus);
			pElement->SetAttribute("BusI",			pPRBlock->m_HVDCArray[i].nIBus);
			pElement->SetDoubleAttribute("R",		(double)pPRBlock->m_HVDCArray[i].fR);
			pElement->SetDoubleAttribute("L",		(double)pPRBlock->m_HVDCArray[i].fL);
			pElement->SetDoubleAttribute("C",		(double)pPRBlock->m_HVDCArray[i].fC);
			pElement->SetDoubleAttribute("DCPower",	(double)pPRBlock->m_HVDCArray[i].fDCPower);
			pElement->SetDoubleAttribute("LossP",	(double)pPRBlock->m_HVDCArray[i].fLossP);

			nBuf = (pPRBlock->m_HVDCArray[i].cCon == 'R' || pPRBlock->m_HVDCArray[i].cCon == 'r') ? 0 : 1;
			pElement->SetAttribute("Control",			nBuf);

			pElement->SetDoubleAttribute("Index",	pPRBlock->m_HVDCArray[i].nIndex);

			pRoot->LinkEndChild(pElement);
		}
		for (i=1; i<(int)pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			pElement = new TiXmlElement("ACBus");

			pElement->SetAttribute("Name",				pPRBlock->m_ACBusArray[i].szName);
			pElement->SetDoubleAttribute("NormV",		pPRBlock->m_ACBusArray[i].fkV);
			pElement->SetDoubleAttribute("GenP",		pPRBlock->m_ACBusArray[i].fGenP);
			pElement->SetDoubleAttribute("LoadP",		pPRBlock->m_ACBusArray[i].fLoadP);
			pElement->SetAttribute("TMid",				pPRBlock->m_ACBusArray[i].bMidBus);
			pElement->SetAttribute("Src",				pPRBlock->m_ACBusArray[i].bSrcBus);
			pElement->SetAttribute("Slack",				pPRBlock->m_ACBusArray[i].bSlack);

			pRoot->LinkEndChild(pElement);
		}
		for (i=1; i<(int)pPRBlock->m_nRecordNum[PR_GENERATOR]; i++)
		{
			pElement = new TiXmlElement("Gen");

			pElement->SetAttribute("Name",				pPRBlock->m_GeneratorArray[i].szName);
			pElement->SetAttribute("Bus",				pPRBlock->m_GeneratorArray[i].szBus);
			pElement->SetDoubleAttribute("kV",			pPRBlock->m_GeneratorArray[i].fkV);
			pElement->SetDoubleAttribute("P",			pPRBlock->m_GeneratorArray[i].fP);
			pElement->SetDoubleAttribute("Q",			pPRBlock->m_GeneratorArray[i].fQ);
			pElement->SetDoubleAttribute("PMax",		pPRBlock->m_GeneratorArray[i].fPMax);
			pElement->SetDoubleAttribute("QMax",		pPRBlock->m_GeneratorArray[i].fQMax);
			pElement->SetDoubleAttribute("PMin",		pPRBlock->m_GeneratorArray[i].fPMin);
			pElement->SetDoubleAttribute("QMin",		pPRBlock->m_GeneratorArray[i].fQMin);

			pRoot->LinkEndChild(pElement);
		}
		for (i=1; i<(int)pPRBlock->m_nRecordNum[PR_POWERLOAD]; i++)
		{
			pElement = new TiXmlElement("Load");

			pElement->SetAttribute("Name",				pPRBlock->m_PowerLoadArray[i].szName);
			pElement->SetAttribute("Bus",				pPRBlock->m_PowerLoadArray[i].szBus);
			pElement->SetDoubleAttribute("kV",			pPRBlock->m_PowerLoadArray[i].fkV);
			pElement->SetDoubleAttribute("P",			pPRBlock->m_PowerLoadArray[i].fP);
			pElement->SetDoubleAttribute("Q",			pPRBlock->m_PowerLoadArray[i].fQ);

			pRoot->LinkEndChild(pElement);
		}
		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_TCSC]; i++)
		{
			pElement = new TiXmlElement("TCSC");

			pElement->SetAttribute("Name",			pPRBlock->m_TCSCArray[i].szName);
			pElement->SetDoubleAttribute("X",		(double)pPRBlock->m_TCSCArray[i].fX);
			pElement->SetAttribute("InstBus",		pPRBlock->m_TCSCArray[i].szInstBus);

			pRoot->LinkEndChild(pElement);
		}
		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_UPFC]; i++)
		{
			pElement = new TiXmlElement("UPFC");

			pElement->SetAttribute("Name",			pPRBlock->m_UPFCArray[i].szName);
			pElement->SetDoubleAttribute("MVA",		(double)pPRBlock->m_UPFCArray[i].fCapacity);
			pElement->SetAttribute("SeriesBus",			pPRBlock->m_UPFCArray[i].szSeriesBus);

			pRoot->LinkEndChild(pElement);
		}
		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_CONVERTER]; i++)
		{
			pElement = new TiXmlElement("Converter");

			pElement->SetAttribute("Name",			pPRBlock->m_ConverterArray[i].szName);
			pElement->SetDoubleAttribute("MVA",		(double)pPRBlock->m_ConverterArray[i].fConverterPower);

			pRoot->LinkEndChild(pElement);
		}

		pDocument->SaveFile(lpszFileName);					//保存到文件
		pDocument->Clear();
		delete pDocument;

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszDCNetworkLogFile, "DCNetwork_SaveData，耗时%d毫秒\n", nDur);
	}

	int CDCNetwork::PRDCNetwork_ReadDataFile(tagPRBlock* pPRBlock, const char* lpszFileName)
	{
		int		nBuffer;

		TiXmlDocument doc(lpszFileName);
		if (!doc.LoadFile())
		{
			//Log(g_lpszDCNetworkLogFile, "No File\n"));
			return 0;
		}

		TiXmlElement* pRoot = doc.RootElement();
		if (stricmp(pRoot->Value(), "DCFlowData") != 0)
		{
			doc.Clear();
			return 0;
		}

		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();

		double	fBuf;
		int		nBuf;
		TiXmlElement* pElement = pRoot->FirstChildElement();
		while (pElement != NULL)
		{
			if (stricmp(pElement->Value(), "Common") == 0)
			{
				pElement->Attribute("BaseMva", &fBuf);	pPRBlock->m_System.fMvaBase=(float)fBuf;
			}
			else if (stricmp(pElement->Value(), "ACLine") == 0)
			{
				strcpy(pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].szName, pElement->Attribute("Name"));
				strcpy(pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].szBusI, pElement->Attribute("BusNameI"));
				strcpy(pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].szBusJ, pElement->Attribute("BusNameJ"));
				pElement->Attribute("kVI",	&fBuf);	pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fkVI=(float)fBuf;
				pElement->Attribute("kVJ",	&fBuf);	pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fkVJ=(float)fBuf;
				pElement->Attribute("BusI", &pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].nIBus);
				pElement->Attribute("BusJ", &pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].nZBus);
				pElement->Attribute("R",	&fBuf);	pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fR=(float)fBuf;
				pElement->Attribute("X",	&fBuf);	pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fX=(float)fBuf;
				pElement->Attribute("AcPi",	&fBuf);	pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fRtPi=(float)fBuf;
				pElement->Attribute("AcPz",	&fBuf);	pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fRtPz=(float)fBuf;
				pElement->Attribute("LossP", &fBuf);	pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fLossP=(float)fBuf;
				pElement->Attribute("Rate", &fBuf);	pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].fRated=(float)fBuf;
				pElement->Attribute("Index", &pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].nIndex);

				pElement->Attribute("TCSC", &nBuffer);
				pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].nTCSCIndex = nBuffer;
				pElement->Attribute("UPFC", &nBuffer);
				pPRBlock->m_ACLineArray[pPRBlock->m_nRecordNum[PR_ACLINE]].nUPFCIndex = nBuffer;

				pPRBlock->m_nRecordNum[PR_ACLINE]++;
			}
			else if (stricmp(pElement->Value(), "Wind") == 0)
			{
				strcpy(pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].szName, pElement->Attribute("Name"));
				strcpy(pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].szBusI, pElement->Attribute("BusNameI"));
				strcpy(pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].szBusJ, pElement->Attribute("BusNameJ"));
				pElement->Attribute("kVI",	&fBuf);	pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fkVI=(float)fBuf;
				pElement->Attribute("kVJ",	&fBuf);	pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fkVJ=(float)fBuf;

				pElement->Attribute("BusI", &pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].nIBus);
				pElement->Attribute("BusJ", &pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].nZBus);
				pElement->Attribute("R",	&fBuf);	pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fR=(float)fBuf;
				pElement->Attribute("X",	&fBuf);	pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fX=(float)fBuf;
				pElement->Attribute("AcPi",	&fBuf);	pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fRtPi=(float)fBuf;
				pElement->Attribute("AcPz",	&fBuf);	pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fRtPz=(float)fBuf;
				pElement->Attribute("LossP", &fBuf);	pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fLossP=(float)fBuf;
				pElement->Attribute("Rate", &fBuf);	pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].fRated=(float)fBuf;
				pElement->Attribute("Index", &pPRBlock->m_WindArray[pPRBlock->m_nRecordNum[PR_WIND]].nIndex);
				pPRBlock->m_nRecordNum[PR_WIND]++;
			}
			else if (stricmp(pElement->Value(), "HVDC") == 0)
			{
				strcpy(pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].szName, pElement->Attribute("Name"));
				strcpy(pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].szACBusR, pElement->Attribute("BusNameR"));
				strcpy(pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].szACBusI, pElement->Attribute("BusNameI"));
				pElement->Attribute("kVR",		&fBuf);	pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fkVR=(float)fBuf;
				pElement->Attribute("kVI",		&fBuf);	pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fkVI=(float)fBuf;

				pElement->Attribute("BusR",		&pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].nRBus);
				pElement->Attribute("BusI",		&pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].nIBus);
				pElement->Attribute("R",		&fBuf);	pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fR=(float)fBuf;
				pElement->Attribute("L",		&fBuf);	pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fL=(float)fBuf;
				pElement->Attribute("C",		&fBuf);	pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fC=(float)fBuf;
				pElement->Attribute("DCPower",	&fBuf);	pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fDCPower=(float)fBuf;
				pElement->Attribute("LossP",	&fBuf);	pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].fLossP=(float)fBuf;

				pElement->Attribute("Control",	&nBuf);	pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].cCon=(nBuf == 0) ? 'R' : 'I';

				pElement->Attribute("Index",	&pPRBlock->m_HVDCArray[pPRBlock->m_nRecordNum[PR_HVDC]].nIndex);
				pPRBlock->m_nRecordNum[PR_HVDC]++;
			}
			else if (stricmp(pElement->Value(), "ACBus") == 0)
			{
				strcpy(pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].szName, pElement->Attribute("Name"));
				pElement->Attribute("NormV",	&fBuf);		pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].fkV=(float)fBuf;
				pElement->Attribute("GenP",		&fBuf);		pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].fGenP=(float)fBuf;
				pElement->Attribute("LoadP",	&fBuf);		pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].fLoadP=(float)fBuf;
				pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].bMidBus=atoi(pElement->Attribute("TMid"));
				pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].bSrcBus=atoi(pElement->Attribute("Src"));
				pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].bSlack=atoi(pElement->Attribute("Slack"));
				pPRBlock->m_nRecordNum[PR_ACBUS]++;
			}
			else if (stricmp(pElement->Value(), "Gen") == 0)
			{
				strcpy(pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].szName, pElement->Attribute("Name"));
				strcpy(pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].szBus, pElement->Attribute("Bus"));
				pElement->Attribute("kV",		&fBuf);		pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fkV=(float)fBuf;
				pElement->Attribute("P",		&fBuf);		pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fP=(float)fBuf;
				pElement->Attribute("Q",		&fBuf);		pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fQ=(float)fBuf;
				pElement->Attribute("PMax",		&fBuf);		pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fPMax=(float)fBuf;
				pElement->Attribute("QMax",		&fBuf);		pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fQMax=(float)fBuf;
				pElement->Attribute("PMin",		&fBuf);		pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fPMin=(float)fBuf;
				pElement->Attribute("QMin",		&fBuf);		pPRBlock->m_GeneratorArray[pPRBlock->m_nRecordNum[PR_GENERATOR]].fQMin=(float)fBuf;
				pPRBlock->m_nRecordNum[PR_GENERATOR]++;
			}
			else if (stricmp(pElement->Value(), "Load") == 0)
			{
				strcpy(pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].szName, pElement->Attribute("Name"));
				strcpy(pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].szBus, pElement->Attribute("Bus"));
				pElement->Attribute("kV",		&fBuf);		pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].fkV=(float)fBuf;
				pElement->Attribute("P",		&fBuf);		pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].fP=(float)fBuf;
				pElement->Attribute("Q",		&fBuf);		pPRBlock->m_PowerLoadArray[pPRBlock->m_nRecordNum[PR_POWERLOAD]].fQ=(float)fBuf;
				pPRBlock->m_nRecordNum[PR_POWERLOAD]++;
			}
			else if (stricmp(pElement->Value(), "TCSC") == 0)
			{
				strcpy(pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].szName, pElement->Attribute("Name"));
				pElement->Attribute("X",		&fBuf);		pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].fX=(float)fBuf;
				strcpy(pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].szInstBus, pElement->Attribute("InstBus"));
				pPRBlock->m_nRecordNum[PR_TCSC]++;
			}
			else if (stricmp(pElement->Value(), "UPFC") == 0)
			{
				strcpy(pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].szName, pElement->Attribute("Name"));
				pElement->Attribute("MVA",			&fBuf);		pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].fCapacity=(float)fBuf;
				strcpy(pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].szSeriesBus, pElement->Attribute("SeriesBus"));
				pPRBlock->m_nRecordNum[PR_UPFC]++;
			}
			else if (stricmp(pElement->Value(), "Converter") == 0)
			{
				strcpy(pPRBlock->m_ConverterArray[pPRBlock->m_nRecordNum[PR_CONVERTER]].szName, pElement->Attribute("Name"));
				pElement->Attribute("MVA",			&fBuf);		pPRBlock->m_ConverterArray[pPRBlock->m_nRecordNum[PR_CONVERTER]].fConverterPower=(float)fBuf;
				pPRBlock->m_nRecordNum[PR_CONVERTER]++;
			}

			pElement = pElement->NextSiblingElement();
		}

		doc.Clear();

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszDCNetworkLogFile, "DCNetwork_ReadData，耗时%d毫秒\n", nDur);

		g_PRMemDBInterface.PRMaint(pPRBlock);

		return 1;
	}
}
