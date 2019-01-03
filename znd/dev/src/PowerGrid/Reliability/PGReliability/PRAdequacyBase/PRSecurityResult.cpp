#include "PRSecurity.h"
#include "../../../../Common/TinyXML/tinyxmlglobal.h"
#include "../../../../Common/StringCommon.h"

extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	void CPRSecurity::ResolveCurveName(const char* lpszLine, char* lpszCurveName)
	{
		register int	i;
		int		nObj;
		unsigned char	bObj;

		bObj=0;
		nObj=0;
		for (i=0; i<(int)strlen(lpszLine); i++)
		{
			if (lpszLine[i] == ' ' || lpszLine[i] == '*')
				continue;

			if (lpszLine[i] == '\"')
			{
				if (bObj == 0)
				{
					bObj=1;
					continue;
				}
				else
				{
					break;
				}
			}
			lpszCurveName[nObj++]=lpszLine[i];
		}
		lpszCurveName[nObj]='\0';
	}

	int CPRSecurity::ParseBpaOutFile(IN const char* lpszOutFile)
	{
		int		nItem, nLine;
		unsigned char	bOutSection, bSwiSmartFinished;
		char	szLine[1024], szCurveName[260];;
		char*	lpszToken;
		std::vector<std::string>	strEleArray;
		std::vector<std::string>	strOutLineArray;
		FILE*	fp;

		tagCurveData	dMxDBuf;
		tagCurveData	dMnVBuf;
		tagCurveData	dMxVBuf;
		tagCurveData	dMnFBuf;
		tagCurveData	dMxFBuf;
		tagCurveData	dBuf;
		tagSimpleCurve	curveBuf;

		curveBuf.strXAxiasName="周";

		g_BpaOutCurveMaxAng. sDataArray.clear();
		g_BpaOutCurveMinVolt.sDataArray.clear();
		g_BpaOutCurveMaxVolt.sDataArray.clear();
		g_BpaOutCurveMinFreq.sDataArray.clear();
		g_BpaOutCurveMaxFreq.sDataArray.clear();

		g_BpaOutCurveMaxAng. strCurveName="发电机最大相对功角";
		g_BpaOutCurveMinVolt.strCurveName="最低节点电压";
		g_BpaOutCurveMaxVolt.strCurveName="最高节点电压";
		g_BpaOutCurveMinFreq.strCurveName="最低节点频率";
		g_BpaOutCurveMaxFreq.strCurveName="最高节点频率";

		g_BpaOutCurveMaxAng. strXAxiasName="周波";
		g_BpaOutCurveMinVolt.strXAxiasName="周波";
		g_BpaOutCurveMaxVolt.strXAxiasName="周波";
		g_BpaOutCurveMinFreq.strXAxiasName="周波";
		g_BpaOutCurveMaxFreq.strXAxiasName="周波";

		g_BpaOutCurveMaxAng. strYAxiasName="度";
		g_BpaOutCurveMinVolt.strYAxiasName="pu";
		g_BpaOutCurveMaxVolt.strYAxiasName="pu";
		g_BpaOutCurveMinFreq.strYAxiasName="Hz";
		g_BpaOutCurveMaxFreq.strYAxiasName="Hz";

		g_BpaOutCurveArray.clear();

		bOutSection=0;
		strOutLineArray.clear();

		//sprintf(szFileName, "%s/GanSu.out", lpszWorkDir);
		fp=fopen(lpszOutFile, "r");
		if (fp == NULL)
			return 0;

		bSwiSmartFinished=0;

		while (!feof(fp))
		{
			memset(szLine, 0, 1024);
			fgets(szLine, 1024, fp);

			TrimEnd(szLine);
			TrimRight(szLine);

			if (strstr(szLine, "SWING CASE") != NULL)
			{
				if (strstr(szLine, "* * *  输 出 信 息  * * *") != NULL)
					bOutSection=1;
				else
					bOutSection=0;
				continue;
			}

			if (strstr(szLine, "稳定计算完毕") != NULL)
				bSwiSmartFinished=1;

			if (bOutSection)
				strOutLineArray.push_back(szLine);
		}

		fclose(fp);

		nLine=0;
		bOutSection=0;
		while (nLine < (int)strOutLineArray.size())
		{
			if (!strOutLineArray[nLine].empty())
			{
				if (strOutLineArray[nLine].find("计算过程中的监视曲线数据列表") != string::npos)
				{
					bOutSection=1;
					nLine++;	//	本行
					nLine++;
					nLine++;
					nLine++;
					continue;
				}
				else if (strOutLineArray[nLine].find("输出数据列表") != string::npos)
				{
					bOutSection=2;
					memset(szCurveName, 0, 260);
					ResolveCurveName(strOutLineArray[nLine].c_str(), szCurveName);

					nLine++;	//	本行
					nLine++;
					continue;
				}
				else if (strOutLineArray[nLine][1] == '*')
				{
					bOutSection=0;
					nLine++;
					continue;
				}
			}

			strcpy(szLine, strOutLineArray[nLine].c_str());
			nLine++;

			if (bOutSection == 1)
			{
				strEleArray.clear();
				lpszToken=strtok(szLine, " \t\n");
				while (lpszToken != NULL)
				{
					strEleArray.push_back(lpszToken);
					lpszToken=strtok(NULL, " \t\n");
				}
				memset(&dMxDBuf, 0, sizeof(tagCurveData));
				memset(&dMnVBuf, 0, sizeof(tagCurveData));
				memset(&dMxVBuf, 0, sizeof(tagCurveData));
				memset(&dMnFBuf, 0, sizeof(tagCurveData));
				memset(&dMxFBuf, 0, sizeof(tagCurveData));

				nItem=0;
				if ((int)strEleArray.size() > nItem)
				{
					dMxDBuf.fX=(float)atof(strEleArray[nItem].c_str());
					dMnVBuf.fX=(float)atof(strEleArray[nItem].c_str());
					dMxVBuf.fX=(float)atof(strEleArray[nItem].c_str());
					dMnFBuf.fX=(float)atof(strEleArray[nItem].c_str());
					dMxFBuf.fX=(float)atof(strEleArray[nItem].c_str());

					//Log(g_lpszLogFile, "X=%.2f ", dMxDBuf.fX);

					nItem++;
				}

				if ((int)strEleArray.size() > nItem)	nItem++;	else	continue;
				if ((int)strEleArray.size() > nItem)	nItem++;	else	continue;

				if ((int)strEleArray.size() > nItem)	nItem++;	else	continue;
				if ((int)strEleArray.size() > nItem)	nItem++;	else	continue;
				if ((int)strEleArray.size() > nItem)	dMxDBuf.fY=atof(strEleArray[nItem++].c_str());	else	continue;

				if ((int)strEleArray.size() > nItem)	nItem++;	else	continue;
				if ((int)strEleArray.size() > nItem)	nItem++;	else	continue;
				if ((int)strEleArray.size() > nItem)	dMnVBuf.fY=atof(strEleArray[nItem++].c_str());	else	continue;

				if ((int)strEleArray.size() > nItem)	nItem++;	else	continue;
				if ((int)strEleArray.size() > nItem)	nItem++;	else	continue;
				if ((int)strEleArray.size() > nItem)	dMxVBuf.fY=atof(strEleArray[nItem++].c_str());	else	continue;

				if ((int)strEleArray.size() > nItem)	nItem++;	else	continue;
				if ((int)strEleArray.size() > nItem)	nItem++;	else	continue;
				if ((int)strEleArray.size() > nItem)	dMnFBuf.fY=atof(strEleArray[nItem++].c_str());	else	continue;

				if ((int)strEleArray.size() > nItem)	nItem++;	else	continue;
				if ((int)strEleArray.size() > nItem)	nItem++;	else	continue;
				if ((int)strEleArray.size() > nItem)	dMxFBuf.fY=atof(strEleArray[nItem++].c_str());	else	continue;

				//Log(g_lpszLogFile, "MxD=%.2f MnV=%.2f MxV=%.2f MnF=%.2f MxF=%.2f\n", dMxDBuf.fY, dMnVBuf.fY, dMxVBuf.fY, dMnFBuf.fY, dMxFBuf.fY);

				g_BpaOutCurveMaxAng. sDataArray.push_back(dMxDBuf);
				g_BpaOutCurveMinVolt.sDataArray.push_back(dMnVBuf);
				g_BpaOutCurveMaxVolt.sDataArray.push_back(dMxVBuf);
				g_BpaOutCurveMinFreq.sDataArray.push_back(dMnFBuf);
				g_BpaOutCurveMaxFreq.sDataArray.push_back(dMxFBuf);
			}
			else if (bOutSection == 2)
			{
				curveBuf.sDataArray.clear();
				curveBuf.strCurveName=szCurveName;

				strEleArray.clear();
				lpszToken=strtok(szLine, " \t\n/=");
				while (lpszToken != NULL)
				{
					strEleArray.push_back(lpszToken);
					lpszToken=strtok(NULL, " \t\n/=");
				}

				nItem=0;
				if ((int)strEleArray.size() > nItem)	curveBuf.strCurveName.append("-").append(strEleArray[nItem++]);	else	{	bOutSection=0;	continue;	}
				if ((int)strEleArray.size() > nItem)	curveBuf.strYAxiasName=strEleArray[nItem++];					else	{	bOutSection=0;	continue;	}
				if ((int)strEleArray.size() > nItem)	nItem++;														else	{	bOutSection=0;	continue;	}
				if ((int)strEleArray.size() > nItem)	curveBuf.fMaxY=atof(strEleArray[nItem++].c_str());				else	{	bOutSection=0;	continue;	}
				if ((int)strEleArray.size() > nItem)	curveBuf.fMaxX=atof(strEleArray[nItem++].c_str());				else	{	bOutSection=0;	continue;	}
				if ((int)strEleArray.size() > nItem)	nItem++;														else	{	bOutSection=0;	continue;	}
				if ((int)strEleArray.size() > nItem)	curveBuf.fMinY=atof(strEleArray[nItem++].c_str());				else	{	bOutSection=0;	continue;	}
				if ((int)strEleArray.size() > nItem)	curveBuf.fMinX=atof(strEleArray[nItem++].c_str());				else	{	bOutSection=0;	continue;	}

				bOutSection=3;
			}
			else if (bOutSection == 3)
			{
				if (strlen(szLine) <= 0)
				{
					if (!curveBuf.strCurveName.empty() && !curveBuf.sDataArray.empty())
						g_BpaOutCurveArray.push_back(curveBuf);
					bOutSection=2;
					continue;
				}

				memset(&dBuf, 0, sizeof(tagCurveData));
				strEleArray.clear();
				lpszToken=strtok(szLine, " \t\n");
				while (lpszToken != NULL)
				{
					strEleArray.push_back(lpszToken);
					lpszToken=strtok(NULL, " \t\n");
				}

				nItem=0;
				while (nItem < (int)strEleArray.size()-1)
				{
					dBuf.fX=atof(strEleArray[nItem++].c_str());
					dBuf.fY=atof(strEleArray[nItem++].c_str());

					curveBuf.sDataArray.push_back(dBuf);
				}
			}
		}

		getSimpleCurveMinMax(g_BpaOutCurveMaxAng );
		getSimpleCurveMinMax(g_BpaOutCurveMinVolt);
		getSimpleCurveMinMax(g_BpaOutCurveMaxVolt);
		getSimpleCurveMinMax(g_BpaOutCurveMinFreq);
		getSimpleCurveMinMax(g_BpaOutCurveMaxFreq);

		strOutLineArray.clear();

		return bSwiSmartFinished;
	}

	int CPRSecurity::IsBpaOutStable(const char* lpszOutFile, 
		const double fMaxAngle,		//	最大功角差
		const double fMaxVolt,		//	最高电压
		const double fMaxVDur,		//	最高电压持续时间
		const double fMinVolt,		//	最低电压
		const double fMinVDur,		//	最低电压持续时间
		const double fMaxFreq,		//	最高频率
		const double fMaxFDur,		//	最高频率持续时间
		const double fMinFreq,		//	最低频率
		const double fMinFDur)		//	最低频率持续时间
	{
		register int	i;
		if (!ParseBpaOutFile(lpszOutFile))
			return PRFSecurity_Result_Unknown;

		for (i=0; i<(int)g_BpaOutCurveMaxAng.sDataArray.size(); i++)
		{
			if (fabs(g_BpaOutCurveMaxAng.sDataArray[i].fY) >= fMaxAngle)
				return PRFSecurity_Result_InSecure;
		}

		double	fElapse, fLastX;
		fElapse=0;
		fLastX=-1;
		for (i=0; i<(int)g_BpaOutCurveMinVolt.sDataArray.size(); i++)
		{
			if (fabs(g_BpaOutCurveMinVolt.sDataArray[i].fY) < fMinVolt)
			{
				if (fLastX < 0)
				{
					fElapse=0;
					fLastX=g_BpaOutCurveMinVolt.sDataArray[i].fX;
				}
				else
				{
					fElapse += (g_BpaOutCurveMinVolt.sDataArray[i].fX-fLastX);
					fLastX=g_BpaOutCurveMinVolt.sDataArray[i].fX;
				}

				if (fElapse > fMinVDur*50)
					return PRFSecurity_Result_InSecure;
			}
			else
			{
				fElapse=0;
				fLastX=-1;
			}
		}

		fElapse=0;
		fLastX=-1;
		for (i=0; i<(int)g_BpaOutCurveMaxVolt.sDataArray.size(); i++)
		{
			if (fabs(g_BpaOutCurveMaxVolt.sDataArray[i].fY) > fMaxVolt)
			{
				if (fLastX < 0)
				{
					fElapse=0;
					fLastX=g_BpaOutCurveMaxVolt.sDataArray[i].fX;
				}
				else
				{
					fElapse += (g_BpaOutCurveMaxVolt.sDataArray[i].fX-fLastX);
					fLastX=g_BpaOutCurveMaxVolt.sDataArray[i].fX;
				}

				if (fElapse > fMaxVDur*50)
					return PRFSecurity_Result_InSecure;
			}
			else
			{
				fElapse=0;
				fLastX=-1;
			}
		}

		fElapse=0;
		fLastX=-1;
		for (i=0; i<(int)g_BpaOutCurveMinFreq.sDataArray.size(); i++)
		{
			if (fabs(g_BpaOutCurveMinFreq.sDataArray[i].fY) < fMinFreq)
			{
				if (fLastX < 0)
				{
					fElapse=0;
					fLastX=g_BpaOutCurveMinFreq.sDataArray[i].fX;
				}
				else
				{
					fElapse += (g_BpaOutCurveMinFreq.sDataArray[i].fX-fLastX);
					fLastX=g_BpaOutCurveMinFreq.sDataArray[i].fX;
				}

				if (fElapse > fMinFDur*50)
					return PRFSecurity_Result_InSecure;
			}
			else
			{
				fElapse=0;
				fLastX=-1;
			}
		}

		fElapse=0;
		fLastX=-1;
		for (i=0; i<(int)g_BpaOutCurveMaxFreq.sDataArray.size(); i++)
		{
			if (fabs(g_BpaOutCurveMaxFreq.sDataArray[i].fY) > fMaxFreq)
			{
				if (fLastX < 0)
				{
					fElapse=0;
					fLastX=g_BpaOutCurveMaxFreq.sDataArray[i].fX;
				}
				else
				{
					fElapse += (g_BpaOutCurveMaxFreq.sDataArray[i].fX-fLastX);
					fLastX=g_BpaOutCurveMaxFreq.sDataArray[i].fX;
				}

				if (fElapse > fMaxFDur*50)
					return PRFSecurity_Result_InSecure;
			}
			else
			{
				fElapse=0;
				fLastX=-1;
			}
		}

		return PRFSecurity_Result_Secure;
	}

	void CPRSecurity::ReadRSResult(const char* lpszRSResultDir)
	{
		char			szFileName[260];
		TiXmlElement*	pElement;
		TiXmlElement*	pChildEle;
		TiXmlElement*	pLine;
		TiXmlNode*		pNode;

		tagRSResult	ssaBuf;
		tagRSFDevice	devBuf;

		m_nRSFState=0;
		m_nRSFSecurity=0;
		m_fPLOS=0;
		m_fFLOS=0;
		m_fMTTIS=0;

		sprintf(szFileName, "%s/RSResult.xml", lpszRSResultDir);
		m_RSResultArray.clear();
		if (access(szFileName, 0) != 0)
			return;

		TiXmlDocument doc(szFileName);
		if (!doc.LoadFile())
			return;

		TiXmlElement* pRoot = doc.RootElement();
		if (stricmp(pRoot->Value(), "ReliablitySecurityEstimateResult") != 0)
		{
			doc.Clear();
			return;
		}

		// Traverse children of pRoot, populating the list of lines
		pLine = pRoot->FirstChildElement();
		while (pLine != NULL)
		{
			if (stricmp(pLine->Value(), "RSystem") == 0)
			{
				pElement = pLine->FirstChildElement();
				while (pElement != NULL)
				{
					pNode = pElement->FirstChild();
					if (pNode && pNode->Type() == TiXmlNode::TINYXML_TEXT)
					{
						if (stricmp(pElement->Value(), "FState") == 0)				{	m_nRSFState=atoi(pNode->Value());			}
						else if (stricmp(pElement->Value(), "FSecurity") == 0)		{	m_nRSFSecurity=atoi(pNode->Value());		}
						else if (stricmp(pElement->Value(), "PLOS") == 0)			{	m_fPLOS=atof(pNode->Value());			}
						else if (stricmp(pElement->Value(), "FLOS") == 0)			{	m_fFLOS=atof(pNode->Value());			}
						else if (stricmp(pElement->Value(), "MTTIS") == 0)			{	m_fMTTIS=atof(pNode->Value());			}
					}
					pElement = pElement->NextSiblingElement();
				}
			}
			else if (stricmp(pLine->Value(), "RState") == 0)
			{
				ssaBuf.nFStateNo=0;
				ssaBuf.bMIsland=0;
				ssaBuf.bLTFault=0;
				ssaBuf.fLossGenP=0;
				ssaBuf.strBseFile.clear();
				ssaBuf.strSwiFile.clear();
				ssaBuf.strOutFile.clear();
				ssaBuf.fStateProb=0;
				ssaBuf.fStateDur=0;
				ssaBuf.nStateNum=0;
				ssaBuf.strSsaResult.clear();
				ssaBuf.fDevArray.clear();

				pElement = pLine->FirstChildElement();
				while (pElement != NULL)
				{
					pNode = pElement->FirstChild();
					if (pNode && pNode->Type() == TiXmlNode::TINYXML_TEXT)
					{
						if (stricmp(pElement->Value(), "FState") == 0)				{	ssaBuf.nFStateNo=atoi(pNode->Value());	}
						else if (stricmp(pElement->Value(), "StateProb") == 0)		{	ssaBuf.fStateProb=(float)atof(pNode->Value());	}
						else if (stricmp(pElement->Value(), "StateDur") == 0)		{	ssaBuf.fStateDur=(float)atof(pNode->Value());	}
						else if (stricmp(pElement->Value(), "StateNum") == 0)		{	ssaBuf.nStateNum=atoi(pNode->Value());	}
						else if (stricmp(pElement->Value(), "SaResult") == 0)		{	ssaBuf.strSsaResult=pNode->Value();		}
						else if (stricmp(pElement->Value(), "LossGenP") == 0)		{	ssaBuf.fLossGenP=(float)atof(pNode->Value());	}
						else if (stricmp(pElement->Value(), "MIsland") == 0)		{	ssaBuf.bMIsland=atoi(pNode->Value());	}
						else if (stricmp(pElement->Value(), "LTFault") == 0)		{	ssaBuf.bLTFault=atoi(pNode->Value());	}
						else if (stricmp(pElement->Value(), "BseFile") == 0)		{	ssaBuf.strBseFile=pNode->Value();		}
						else if (stricmp(pElement->Value(), "SwiFile") == 0)		{	ssaBuf.strSwiFile=pNode->Value();		}
						else if (stricmp(pElement->Value(), "OutFile") == 0)		{	ssaBuf.strOutFile=pNode->Value();		}
					}
					else if (pNode)
					{
						if (stricmp(pElement->Value(), "FaultDevice") == 0)
						{
							devBuf.strFDevType.clear();
							devBuf.strFDevName.clear();
							devBuf.strFaultType.clear();
							devBuf.fFaultPos=0;

							pChildEle=pElement->FirstChildElement();
							while (pChildEle != NULL)
							{
								pNode = pChildEle->FirstChild();
								if (pNode && pNode->Type() == TiXmlNode::TINYXML_TEXT)
								{
									if (stricmp(pChildEle->Value(), "FDevType") == 0)		devBuf.strFDevType=pNode->Value();
									else if (stricmp(pChildEle->Value(), "FDevName") == 0)	devBuf.strFDevName=pNode->Value();
									else if (stricmp(pChildEle->Value(), "FaultType") == 0)	devBuf.strFaultType=pNode->Value();
									else if (stricmp(pChildEle->Value(), "FaultPosi") == 0)	devBuf.fFaultPos=(float)atof(pNode->Value());
								}
								pChildEle = pChildEle->NextSiblingElement();
							}
							ssaBuf.fDevArray.push_back(devBuf);
						}
					}
					pElement = pElement->NextSiblingElement();
				}

				m_RSResultArray.push_back(ssaBuf);
			}

			pLine = pLine->NextSiblingElement();
		}

		doc.Clear();
	}

	void CPRSecurity::SaveRSResult(const char* lpszRSResultDir)
	{
		char	szFileName[260];
		int		nFSecurity, nFStateDev;
		char	szBuf[260];

		sprintf(szFileName, "%s/RSResult.xml", lpszRSResultDir);

		TiXmlDocument*		pDocument = new TiXmlDocument();								//创建一个XML的文档对象。
		TiXmlDeclaration*	pDeclare = new TiXmlDeclaration("1.0", "GB2312", "no");
		pDocument->LinkEndChild(pDeclare);

		TiXmlElement*		pRoot=new TiXmlElement("ReliablitySecurityEstimateResult");
		pDocument->LinkEndChild(pRoot);

		TiXmlElement*	pFSecurity;
		TiXmlElement*	pFaultDev;

		pFSecurity=new TiXmlElement("RSystem");
		pRoot->LinkEndChild(pFSecurity);

		addXmlElement(pFSecurity, "FState",			m_nRSFState);
		addXmlElement(pFSecurity, "FSecurity",		m_nRSFSecurity);
		addXmlElement(pFSecurity, "PLOS",			m_fPLOS);
		addXmlElement(pFSecurity, "FLOS",			m_fFLOS);
		addXmlElement(pFSecurity, "MTTIS",			m_fMTTIS);

		for (nFSecurity=0; nFSecurity<(int)m_RSResultArray.size(); nFSecurity++)
		{
			sprintf(szBuf, "%d", nFSecurity+1);
			pFSecurity=addXmlAttribute(pRoot, "RState", "State", szBuf);

			addXmlElement(pFSecurity, "FState",			m_RSResultArray[nFSecurity].nFStateNo);
			addXmlElement(pFSecurity, "StateProb",		m_RSResultArray[nFSecurity].fStateProb);
			addXmlElement(pFSecurity, "StateDur",		m_RSResultArray[nFSecurity].fStateDur);
			addXmlElement(pFSecurity, "StateNum",		m_RSResultArray[nFSecurity].nStateNum);
			addXmlElement(pFSecurity, "SaResult",		m_RSResultArray[nFSecurity].strSsaResult.c_str());
			addXmlElement(pFSecurity, "LossGenP",		m_RSResultArray[nFSecurity].fLossGenP);
			addXmlElement(pFSecurity, "MIsland",		m_RSResultArray[nFSecurity].bMIsland);
			addXmlElement(pFSecurity, "LTFault",		m_RSResultArray[nFSecurity].bLTFault);
			addXmlElement(pFSecurity, "BseFile",		m_RSResultArray[nFSecurity].strBseFile.c_str());
			addXmlElement(pFSecurity, "SwiFile",		m_RSResultArray[nFSecurity].strSwiFile.c_str());
			addXmlElement(pFSecurity, "OutFile",		m_RSResultArray[nFSecurity].strOutFile.c_str());

			for (nFStateDev=0; nFStateDev<(int)m_RSResultArray[nFSecurity].fDevArray.size(); nFStateDev++)
			{
				pFaultDev=new TiXmlElement("FaultDevice");

				addXmlElement(pFaultDev, "FDevType",		m_RSResultArray[nFSecurity].fDevArray[nFStateDev].strFDevType.c_str());
				addXmlElement(pFaultDev, "FDevName",		m_RSResultArray[nFSecurity].fDevArray[nFStateDev].strFDevName.c_str());
				addXmlElement(pFaultDev, "FaultType",		m_RSResultArray[nFSecurity].fDevArray[nFStateDev].strFaultType.c_str());
				addXmlElement(pFaultDev, "FaultPosi",		(float)m_RSResultArray[nFSecurity].fDevArray[nFStateDev].fFaultPos);

				pFSecurity->LinkEndChild(pFaultDev);
			}
		}
		pDocument->SaveFile(szFileName);					//保存到文件

		pDocument->Clear();
		delete pDocument;
	}

	void CPRSecurity::ReCalculateRSResult(const char* lpszRSResultDir, 
		const double fMaxAngle,		//	最大功角差
		const double fMaxVolt,		//	最高电压
		const double fMaxVDur,		//	最高电压持续时间
		const double fMinVolt,		//	最低电压
		const double fMinVDur,		//	最低电压持续时间
		const double fMaxFreq,		//	最高频率
		const double fMaxFDur,		//	最高频率持续时间
		const double fMinFreq,		//	最低频率
		const double fMinFDur)		//	最低频率持续时间
	{
		int		nFSecurity, nSsaResult;

		ReadRSResult(lpszRSResultDir);

		m_fPLOS=0;
		m_fFLOS=0;
		m_fMTTIS=0;
		for (nFSecurity=0; nFSecurity<(int)m_RSResultArray.size(); nFSecurity++)
		{
			nSsaResult=IsBpaOutStable(m_RSResultArray[nFSecurity].strOutFile.c_str(), fMaxAngle, fMaxVolt, fMaxVDur, fMinVolt, fMinVDur, fMaxFreq, fMaxFDur, fMinFreq, fMinFDur);

			switch (nSsaResult)
			{
			case	PRFSecurity_Result_Secure:
				m_RSResultArray[nFSecurity].strSsaResult="安全";
				break;	
			case	PRFSecurity_Result_InSecure:
				m_RSResultArray[nFSecurity].strSsaResult="不安全";
				break;
			case	PRFSecurity_Result_Unknown:
			default:
				m_RSResultArray[nFSecurity].strSsaResult="未知";
				break;	
			}
			if (nSsaResult == PRFSecurity_Result_InSecure)
			{
				m_fFLOS++;
				m_fPLOS += m_RSResultArray[nFSecurity].fStateProb;
			}
		}
		if (m_fFLOS > FLT_MIN)	m_fMTTIS=8760*(1-m_fPLOS)/m_fFLOS;

		SaveRSResult(lpszRSResultDir);
	}

	void CPRSecurity::WriteSecurityResult(tagPRBlock* pPRBlock, const char* lpszFileName, const char* lpszCaseName, const char* lpszRaiFile, const char* lpszDatFile, const char* lpszSwiFile, const char* lpszRmlFile, const char* lpszCriFile, const int nDur)
	{
		register int	i;
		int		nFState, nFSecurity, nField, nFltDev;
		char	szBuf[260];

		FILE*	fp=fopen(lpszFileName, "w");
		fprintf(fp, "*Version 2014\n");
		fprintf(fp, "//版本信息\n\n");

		fprintf(fp, "*Compell information:	%s\n", lpszRaiFile);
		fprintf(fp, "*Powerflow File:		%s\n", lpszDatFile);
		fprintf(fp, "*Stable File:			%s\n", lpszSwiFile);
		fprintf(fp, "*Reliability File:		%s\n", lpszRmlFile);
		fprintf(fp, "*Criteria File:		%s\n", lpszCriFile);
		fprintf(fp, "//输入文件信息\n\n");

		fprintf(fp, "*<CASE %s>\n", lpszCaseName);
		fprintf(fp, "//计算控制信息\n\n");

		fprintf(fp, "*SecurityAnalysis Information\n");
		fprintf(fp, "//安全性评价详情\n");
		fprintf(fp, "//状态号, 状态概率, 状态持续时间, 故障设备数, 状态情况\n");
		fprintf(fp, "//        故障设备\n");

		for (nFState=1; nFState<pPRBlock->m_nRecordNum[PR_FSTATE]; nFState++)
		{
			nFSecurity=0;
			for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_FSECURITY]; i++)
			{
				if (nFState == pPRBlock->m_FSecurityArray[i].nFStateNo)
				{
					nFSecurity=i;
					break;
				}
			}

			fprintf(fp, "%d, ", nFState);
			fprintf(fp, "%f, ", pPRBlock->m_FStateArray[nFState].fStateProb);
			fprintf(fp, "%f, ", pPRBlock->m_FStateArray[nFState].fStateDur);
			fprintf(fp, "%d, ", pPRBlock->m_FStateArray[nFState].nFDevNum);
			if (nFSecurity < 0)
				fprintf(fp, "%s, ", g_PRMemDBInterface.PRGetFieldEnumString(PR_FSECURITY, PR_FSECURITY_RESULT, PRFSecurity_Result_Secure));
			else
				fprintf(fp, "%s, ", g_PRMemDBInterface.PRGetFieldEnumString(PR_FSECURITY, PR_FSECURITY_RESULT, pPRBlock->m_FSecurityArray[nFSecurity].nSaResult));
			fprintf(fp, "\n");

			nFltDev=1;
			//for (i=pPRBlock->m_FStateArray[nFStateNo].pRFDevice; i<pPRBlock->m_FStateArray[nFStateNo+1].pRFDevice; i++)
			for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; i++)
			{
				if (pPRBlock->m_FStateFDevArray[i].nFStateNo < nFState)
					continue;
				if (pPRBlock->m_FStateFDevArray[i].nFStateNo > nFState)
					break;

				nField=g_PRMemDBInterface.PRGetFieldIndex(pPRBlock->m_FStateFDevArray[i].nFDevTyp, "Name");
				g_PRMemDBInterface.PRGetRecordValue(pPRBlock, pPRBlock->m_FStateFDevArray[i].nFDevTyp, nField, pPRBlock->m_FStateFDevArray[i].nFDevIdx, szBuf);

				fprintf(fp, "    故障设备%d=%s, ", nFltDev++, g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_FStateFDevArray[i].nFDevTyp));
				fprintf(fp, "%s, ", szBuf);
				fprintf(fp, "%s, ", g_PRMemDBInterface.PRGetFieldEnumString(PR_FSTATEFDEV, PR_FSTATEFDEV_DFLTTYP, pPRBlock->m_FStateFDevArray[i].nDFltTyp));
				fprintf(fp, "%d, ", pPRBlock->m_FStateFDevArray[i].nDFltPos);
				fprintf(fp, "\n");
			}
		}

		fprintf(fp, "*Security Index\n");
		fprintf(fp, "//全系统安全性计算结果\n");
		fprintf(fp, "//稳定计算总数, 失稳概率PLOS, 失稳频率FLOS, 平均稳定运行时间MTTIS\n");
		fprintf(fp, "//        (次)    ()    (次/年)    (小时/年)\n");
		fprintf(fp, "%d, ", pPRBlock->m_nRecordNum[PR_FSECURITY]);
		fprintf(fp, "%f, ", pPRBlock->m_System.fPLOS);
		fprintf(fp, "%f, ", pPRBlock->m_System.fFLOS);
		fprintf(fp, "%f, ", pPRBlock->m_System.fMTTIS);
		fprintf(fp, "\n");
		fprintf(fp, "\n");

		fprintf(fp, "*Calculate Time: %f\n", nDur/1000.0);

		fflush(fp);
		fclose(fp);
	}

	void CPRSecurity::WriteRSResult(tagPRBlock* pPRBlock, const char* lpszFileName, const char* lpszCaseName, const char* lpszRaiFile, const char* lpszDatFile, const char* lpszSwiFile, const char* lpszRmlFile, const char* lpszCriFile, const int nDur)
	{
		register int	i;
		int		nFSecurity, nFltDev;

		FILE*	fp=fopen(lpszFileName, "w");
		fprintf(fp, "*Version 2014\n");
		fprintf(fp, "//版本信息\n\n");

		fprintf(fp, "*Compell information:	%s\n", lpszRaiFile);
		fprintf(fp, "*Powerflow File:		%s\n", lpszDatFile);
		fprintf(fp, "*Stable File:			%s\n", lpszSwiFile);
		fprintf(fp, "*Reliability File:		%s\n", lpszRmlFile);
		fprintf(fp, "*Criteria File:		%s\n", lpszCriFile);
		fprintf(fp, "//输入文件信息\n\n");

		fprintf(fp, "*<CASE %s>\n", lpszCaseName);
		fprintf(fp, "//计算控制信息\n\n");

		fprintf(fp, "*SecurityAnalysis Information\n");
		fprintf(fp, "//安全性评价详情\n");
		fprintf(fp, "//状态号, 状态概率, 状态持续时间, 故障设备数, 状态情况\n");
		fprintf(fp, "//        故障设备\n");

		for (nFSecurity=0; nFSecurity<(int)m_RSResultArray.size(); nFSecurity++)
		{

			fprintf(fp, "%d, ", m_RSResultArray[nFSecurity].nFStateNo);
			fprintf(fp, "%f, ", m_RSResultArray[nFSecurity].fStateProb);
			fprintf(fp, "%f, ", m_RSResultArray[nFSecurity].fStateDur);
			fprintf(fp, "%d, ", m_RSResultArray[nFSecurity].fDevArray.size());
			fprintf(fp, "%s, ", m_RSResultArray[nFSecurity].strSsaResult.c_str());
			fprintf(fp, "\n");

			nFltDev=1;
			//for (i=pPRBlock->m_FStateArray[nFSecurity].pRFDevice; i<pPRBlock->m_FStateArray[nFSecurity+1].pRFDevice; i++)
			for (i=0; i<(int)m_RSResultArray[nFSecurity].fDevArray.size(); i++)
			{
				fprintf(fp, "    故障设备%d=%s, ", nFltDev++, m_RSResultArray[nFSecurity].fDevArray[i].strFDevType.c_str());
				fprintf(fp, "%s, ", m_RSResultArray[nFSecurity].fDevArray[i].strFDevName.c_str());
				fprintf(fp, "%s, ", m_RSResultArray[nFSecurity].fDevArray[i].strFDevName.c_str());
				fprintf(fp, "%f, ", m_RSResultArray[nFSecurity].fDevArray[i].fFaultPos);
				fprintf(fp, "\n");
			}
		}

		fprintf(fp, "*Security Index\n");
		fprintf(fp, "//全系统安全性计算结果\n");
		fprintf(fp, "//稳定计算总数, 失稳概率PLOS, 失稳频率FLOS, 平均稳定运行时间MTTIS\n");
		fprintf(fp, "//        (次)    ()    (次/年)    (小时/年)\n");
		fprintf(fp, "%d, ", m_RSResultArray.size());
		fprintf(fp, "%f, ", m_fPLOS);
		fprintf(fp, "%f, ", m_fFLOS);
		fprintf(fp, "%f, ", m_fMTTIS);
		fprintf(fp, "\n");
		fprintf(fp, "\n");

		fprintf(fp, "*Calculate Time: %f\n", nDur/1000.0);

		fflush(fp);
		fclose(fp);
	}
}
