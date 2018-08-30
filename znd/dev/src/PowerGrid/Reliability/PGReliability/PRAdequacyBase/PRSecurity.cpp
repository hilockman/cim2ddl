#include <process.h>
#include "PRSecurity.h"
#include "../../../../Common/TinyXML/tinyxmlglobal.h"

extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;
	extern	unsigned __stdcall  SecurityEstimateConThreaad(void* lParam);

	CRITICAL_SECTION CPRSecurity::m_csLock;

	CPRSecurity::CPRSecurity(void)
	{
		InitializeCriticalSection(&CPRSecurity::m_csLock);
		m_bEstimating=0;
		memset(m_szDefaultSettingFile, 0, 260);
	}

	CPRSecurity::~CPRSecurity(void)
	{
		DeleteCriticalSection(&CPRSecurity::m_csLock);
		m_bEstimating=0;
	}

	void CPRSecurity::InitBpaPRSecuritySetting(tagBpaPRSecuritySetting* pSetting)
	{
		pSetting->strBpaWorkDir.clear();	//	软件工作目录，用于存放BPA等之间计算文件和最终计算结果文件，目前应用于安全性评价

		pSetting->clrBackGround=RGB(0, 0, 0);
		pSetting->clrForeGround=RGB(128, 128, 128);
		pSetting->clrCurve=RGB(255, 0, 0);
		pSetting->clrAxias=RGB(255, 255, 255);
		pSetting->nXPace=10;
		pSetting->nYPace=10;

		pSetting->nMaxSsaState=2500;
		pSetting->nMinSsaLTFault=3;
		pSetting->nMaxSsaLTFault=8;
		pSetting->bLTFaultOnly=0;
		pSetting->fEndDT=300;

		pSetting->fCriteriaMaxAngle=200;
		pSetting->fCriteriaMaxVolt =1.2;
		pSetting->fCriteriaMaxVDur =1;
		pSetting->fCriteriaMinVolt =0.8;
		pSetting->fCriteriaMinVDur =1;
		pSetting->fCriteriaMaxFreq =52.5;
		pSetting->fCriteriaMaxFDur =1;
		pSetting->fCriteriaMinFreq =47.5;
		pSetting->fCriteriaMinFDur =1;

		pSetting->fRealCriteriaMaxAngle=-1;
		pSetting->fRealCriteriaMaxVolt =-1;
		pSetting->fRealCriteriaMaxVDur =-1;
		pSetting->fRealCriteriaMinVolt =-1;
		pSetting->fRealCriteriaMinVDur =-1;
		pSetting->fRealCriteriaMaxFreq =-1;
		pSetting->fRealCriteriaMaxFDur =-1;
		pSetting->fRealCriteriaMinFreq =-1;
		pSetting->fRealCriteriaMinFDur =-1;

		pSetting->fDc2AcFactor=1.1;
		pSetting->bGenBusLoadAsAux=0;
		pSetting->bMutliThread=0;
	}

	int	CPRSecurity::ReadBpaPRSecuritySetting(const char* lpszSettingFile)
	{
		InitBpaPRSecuritySetting(&m_PRSecuritySetting);

		TiXmlElement	*pLine, *pElement;
		TiXmlNode*		pNode;

		TiXmlDocument doc(lpszSettingFile);
		if (!doc.LoadFile())
			return 0;

		TiXmlElement* pRoot = doc.RootElement();
		if (stricmp(pRoot->Value(), "BpaPRSecuritySetting") != 0)
		{
			doc.Clear();
			return 0;
		}

		strcpy(m_szDefaultSettingFile, lpszSettingFile);

		pLine = pRoot->FirstChildElement();
		while (pLine != NULL)
		{
			if (stricmp(pLine->Value(), "Base") == 0)
			{
				pElement = pLine->FirstChildElement();
				while (pElement != NULL)
				{
					pNode = pElement->FirstChild();
					if (pNode && pNode->Type() == TiXmlNode::TINYXML_TEXT)
					{
						if (stricmp(pElement->Value(), "BpaWorkDir") == 0)					{	m_PRSecuritySetting.strBpaWorkDir	=pNode->Value();				}

						else if (stricmp(pElement->Value(), "BackGroundColor") == 0)		{	m_PRSecuritySetting.clrBackGround=atoi(pNode->Value());				}
						else if (stricmp(pElement->Value(), "ForeGroundColor") == 0)		{	m_PRSecuritySetting.clrForeGround=atoi(pNode->Value());				}
						else if (stricmp(pElement->Value(), "CurveColor") == 0)				{	m_PRSecuritySetting.clrCurve=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "AxiasColor") == 0)				{	m_PRSecuritySetting.clrAxias=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "XPace") == 0)					{	m_PRSecuritySetting.nXPace=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "YPace") == 0)					{	m_PRSecuritySetting.nYPace=atoi(pNode->Value());					}

						else if (stricmp(pElement->Value(), "MinSsaLTFault") == 0)			{	m_PRSecuritySetting.nMinSsaLTFault=atoi(pNode->Value());			}
						else if (stricmp(pElement->Value(), "MaxSsaLTFault") == 0)			{	m_PRSecuritySetting.nMaxSsaLTFault=atoi(pNode->Value());			}
						else if (stricmp(pElement->Value(), "MaxSsaState") == 0)			{	m_PRSecuritySetting.nMaxSsaState=atoi(pNode->Value());				}
						else if (stricmp(pElement->Value(), "LTFaultOnly") == 0)			{	m_PRSecuritySetting.bLTFaultOnly=atoi(pNode->Value());				}
						else if (stricmp(pElement->Value(), "EndDT") == 0)					{	m_PRSecuritySetting.fEndDT=(float)atof(pNode->Value());				}

						else if (stricmp(pElement->Value(), "CriteriaMaxAngle") == 0)		{	m_PRSecuritySetting.fCriteriaMaxAngle=atof(pNode->Value());			}
						else if (stricmp(pElement->Value(), "CriteriaMaxVolt") == 0)		{	m_PRSecuritySetting.fCriteriaMaxVolt=atof(pNode->Value());			}
						else if (stricmp(pElement->Value(), "CriteriaMaxVDur") == 0)		{	m_PRSecuritySetting.fCriteriaMaxVDur=atof(pNode->Value());			}
						else if (stricmp(pElement->Value(), "CriteriaMinVolt") == 0)		{	m_PRSecuritySetting.fCriteriaMinVolt=atof(pNode->Value());			}
						else if (stricmp(pElement->Value(), "CriteriaMinVDur") == 0)		{	m_PRSecuritySetting.fCriteriaMinVDur=atof(pNode->Value());			}
						else if (stricmp(pElement->Value(), "CriteriaMaxFreq") == 0)		{	m_PRSecuritySetting.fCriteriaMaxFreq=atof(pNode->Value());			}
						else if (stricmp(pElement->Value(), "CriteriaMaxFDur") == 0)		{	m_PRSecuritySetting.fCriteriaMaxFDur=atof(pNode->Value());			}
						else if (stricmp(pElement->Value(), "CriteriaMinFreq") == 0)		{	m_PRSecuritySetting.fCriteriaMinFreq=atof(pNode->Value());			}
						else if (stricmp(pElement->Value(), "CriteriaMinFDur") == 0)		{	m_PRSecuritySetting.fCriteriaMinFDur=atof(pNode->Value());			}

						else if (stricmp(pElement->Value(), "RealCriteriaMaxAngle") == 0)	{	m_PRSecuritySetting.fRealCriteriaMaxAngle=atof(pNode->Value());		}
						else if (stricmp(pElement->Value(), "RealCriteriaMaxVolt") == 0)	{	m_PRSecuritySetting.fRealCriteriaMaxVolt=atof(pNode->Value());		}
						else if (stricmp(pElement->Value(), "RealCriteriaMaxVDur") == 0)	{	m_PRSecuritySetting.fRealCriteriaMaxVDur=atof(pNode->Value());		}
						else if (stricmp(pElement->Value(), "RealCriteriaMinVolt") == 0)	{	m_PRSecuritySetting.fRealCriteriaMinVolt=atof(pNode->Value());		}
						else if (stricmp(pElement->Value(), "RealCriteriaMinVDur") == 0)	{	m_PRSecuritySetting.fRealCriteriaMinVDur=atof(pNode->Value());		}
						else if (stricmp(pElement->Value(), "RealCriteriaMaxFreq") == 0)	{	m_PRSecuritySetting.fRealCriteriaMaxFreq=atof(pNode->Value());		}
						else if (stricmp(pElement->Value(), "RealCriteriaMaxFDur") == 0)	{	m_PRSecuritySetting.fRealCriteriaMaxFDur=atof(pNode->Value());		}
						else if (stricmp(pElement->Value(), "RealCriteriaMinFreq") == 0)	{	m_PRSecuritySetting.fRealCriteriaMinFreq=atof(pNode->Value());		}
						else if (stricmp(pElement->Value(), "RealCriteriaMinFDur") == 0)	{	m_PRSecuritySetting.fRealCriteriaMinFDur=atof(pNode->Value());		}

						else if (stricmp(pElement->Value(), "MultiThread") == 0)			{	m_PRSecuritySetting.bMutliThread	=atoi(pNode->Value());			}
						else if (stricmp(pElement->Value(), "Dc2AcFactor") == 0)			{	m_PRSecuritySetting.fDc2AcFactor	=atof(pNode->Value());			}
						else if (stricmp(pElement->Value(), "GenBusLoadAsAux") == 0)		{	m_PRSecuritySetting.bGenBusLoadAsAux=atoi(pNode->Value());			}
					}
					pElement = pElement->NextSiblingElement();
				}
			}
			pLine = pLine->NextSiblingElement();
		}

		doc.Clear();

		if (m_PRSecuritySetting.fRealCriteriaMaxAngle < 0)	m_PRSecuritySetting.fRealCriteriaMaxAngle=m_PRSecuritySetting.fCriteriaMaxAngle;
		if (m_PRSecuritySetting.fRealCriteriaMaxVolt  < 0)	m_PRSecuritySetting.fRealCriteriaMaxVolt =m_PRSecuritySetting.fCriteriaMaxVolt ;
		if (m_PRSecuritySetting.fRealCriteriaMaxVDur  < 0)	m_PRSecuritySetting.fRealCriteriaMaxVDur =m_PRSecuritySetting.fCriteriaMaxVDur ;
		if (m_PRSecuritySetting.fRealCriteriaMinVolt  < 0)	m_PRSecuritySetting.fRealCriteriaMinVolt =m_PRSecuritySetting.fCriteriaMinVolt ;
		if (m_PRSecuritySetting.fRealCriteriaMinVDur  < 0)	m_PRSecuritySetting.fRealCriteriaMinVDur =m_PRSecuritySetting.fCriteriaMinVDur ;
		if (m_PRSecuritySetting.fRealCriteriaMaxFreq  < 0)	m_PRSecuritySetting.fRealCriteriaMaxFreq =m_PRSecuritySetting.fCriteriaMaxFreq ;
		if (m_PRSecuritySetting.fRealCriteriaMaxFDur  < 0)	m_PRSecuritySetting.fRealCriteriaMaxFDur =m_PRSecuritySetting.fCriteriaMaxFDur ;
		if (m_PRSecuritySetting.fRealCriteriaMinFreq  < 0)	m_PRSecuritySetting.fRealCriteriaMinFreq =m_PRSecuritySetting.fCriteriaMinFreq ;
		if (m_PRSecuritySetting.fRealCriteriaMinFDur  < 0)	m_PRSecuritySetting.fRealCriteriaMinFDur =m_PRSecuritySetting.fCriteriaMinFDur ;

		return 1;
	}

	void CPRSecurity::SaveBpaPRSecuritySetting()
	{
		TiXmlDocument*		pDocument = new TiXmlDocument();								//创建一个XML的文档对象。
		TiXmlDeclaration*	pDeclare = new TiXmlDeclaration("1.0", "gb2312", "no");	pDocument->LinkEndChild(pDeclare);
		TiXmlElement*		pRootElement = new TiXmlElement("BpaPRSecuritySetting");		pDocument->LinkEndChild(pRootElement);

		TiXmlElement		*pElement;

		pElement = new TiXmlElement("Base");
		pRootElement->LinkEndChild(pElement);

		addXmlElement(pElement, "BpaWorkDir",			m_PRSecuritySetting.strBpaWorkDir.c_str()	); //->SetAttribute("Desp", "软件工作目录，用于存放BPA等之间计算文件和最终计算结果文件，目前应用于安全性评价");

		addXmlElement(pElement, "BackGroundColor",		m_PRSecuritySetting.clrBackGround			); //->SetAttribute("Desp", "曲线背景颜色");
		addXmlElement(pElement, "ForeGroundColor",		m_PRSecuritySetting.clrForeGround			); //->SetAttribute("Desp", "曲线网格颜色");
		addXmlElement(pElement, "CurveColor",			m_PRSecuritySetting.clrCurve				); //->SetAttribute("Desp", "曲线颜色");
		addXmlElement(pElement, "AxiasColor",			m_PRSecuritySetting.clrAxias				); //->SetAttribute("Desp", "坐标颜色");
		addXmlElement(pElement, "XPace",				m_PRSecuritySetting.nXPace					); //->SetAttribute("Desp", "曲线X坐标步距");
		addXmlElement(pElement, "YPace",				m_PRSecuritySetting.nYPace					); //->SetAttribute("Desp", "曲线Y坐标步距");

		addXmlElement(pElement, "MinSsaLTFault",		m_PRSecuritySetting.nMinSsaLTFault			); //->SetAttribute("Desp", "安全性评价最小支路故障数");
		addXmlElement(pElement, "MaxSsaLTFault",		m_PRSecuritySetting.nMaxSsaLTFault			); //->SetAttribute("Desp", "安全性评价最大支路故障数");
		addXmlElement(pElement, "MaxSsaState",			m_PRSecuritySetting.nMaxSsaState			); //->SetAttribute("Desp", "安全性评价最大评价状态数");
		addXmlElement(pElement, "LTFaultOnly",			m_PRSecuritySetting.bLTFaultOnly			); //->SetAttribute("Desp", "安全性评价支路故障评价开关(=0，评价发电机+支路故障；=1，仅评价支路故障)");
		addXmlElement(pElement, "EndDT",				m_PRSecuritySetting.fEndDT					); //->SetAttribute("Desp", "稳定计算时间");

		addXmlElement(pElement, "CriteriaMaxAngle",		m_PRSecuritySetting.fCriteriaMaxAngle		); //->SetAttribute("Desp", "最大功角差");
		addXmlElement(pElement, "CriteriaMaxVolt",		m_PRSecuritySetting.fCriteriaMaxVolt		); //->SetAttribute("Desp", "最高电压");
		addXmlElement(pElement, "CriteriaMaxVDur",		m_PRSecuritySetting.fCriteriaMaxVDur		); //->SetAttribute("Desp", "最高电压持续时间");
		addXmlElement(pElement, "CriteriaMinVolt",		m_PRSecuritySetting.fCriteriaMinVolt		); //->SetAttribute("Desp", "最低电压");
		addXmlElement(pElement, "CriteriaMinVDur",		m_PRSecuritySetting.fCriteriaMinVDur		); //->SetAttribute("Desp", "最低电压持续时间");
		addXmlElement(pElement, "CriteriaMaxFreq",		m_PRSecuritySetting.fCriteriaMaxFreq		); //->SetAttribute("Desp", "最高频率");
		addXmlElement(pElement, "CriteriaMaxFDur",		m_PRSecuritySetting.fCriteriaMaxFDur		); //->SetAttribute("Desp", "最高频率持续时间");
		addXmlElement(pElement, "CriteriaMinFreq",		m_PRSecuritySetting.fCriteriaMinFreq		); //->SetAttribute("Desp", "最低频率");
		addXmlElement(pElement, "CriteriaMinFDur",		m_PRSecuritySetting.fCriteriaMinFDur		); //->SetAttribute("Desp", "最低频率持续时间");

		addXmlElement(pElement, "RealCriteriaMaxAngle",	m_PRSecuritySetting.fRealCriteriaMaxAngle	); //->SetAttribute("Desp", "最大功角差");
		addXmlElement(pElement, "RealCriteriaMaxVolt",	m_PRSecuritySetting.fRealCriteriaMaxVolt	); //->SetAttribute("Desp", "最高电压");
		addXmlElement(pElement, "RealCriteriaMaxVDur",	m_PRSecuritySetting.fRealCriteriaMaxVDur	); //->SetAttribute("Desp", "最高电压持续时间");
		addXmlElement(pElement, "RealCriteriaMinVolt",	m_PRSecuritySetting.fRealCriteriaMinVolt	); //->SetAttribute("Desp", "最低电压");
		addXmlElement(pElement, "RealCriteriaMinVDur",	m_PRSecuritySetting.fRealCriteriaMinVDur	); //->SetAttribute("Desp", "最低电压持续时间");
		addXmlElement(pElement, "RealCriteriaMaxFreq",	m_PRSecuritySetting.fRealCriteriaMaxFreq	); //->SetAttribute("Desp", "最高频率");
		addXmlElement(pElement, "RealCriteriaMaxFDur",	m_PRSecuritySetting.fRealCriteriaMaxFDur	); //->SetAttribute("Desp", "最高频率持续时间");
		addXmlElement(pElement, "RealCriteriaMinFreq",	m_PRSecuritySetting.fRealCriteriaMinFreq	); //->SetAttribute("Desp", "最低频率");
		addXmlElement(pElement, "RealCriteriaMinFDur",	m_PRSecuritySetting.fRealCriteriaMinFDur	); //->SetAttribute("Desp", "最低频率持续时间");

		addXmlElement(pElement, "MultiThread",			m_PRSecuritySetting.bMutliThread			); //->SetAttribute("Desp", "进程数");
		addXmlElement(pElement, "Dc2AcFactor",			m_PRSecuritySetting.fDc2AcFactor			); //->SetAttribute("Desp", "直流潮流 2 交流潮流系数");
		addXmlElement(pElement, "GenBusLoadAsAux",		m_PRSecuritySetting.bGenBusLoadAsAux		); //->SetAttribute("Desp", "发电机母线负荷按厂用电");

		pDocument->SaveFile(m_szDefaultSettingFile);		//保存到文件
		pDocument->Clear();
		delete pDocument;
	}

	int CPRSecurity::SecurityStateFill(tagPRBlock* pPRBlock, const vector<int>& nFStateArray)
	{
		int		nState, nFDev;
		std::vector<tagPRFSecurity>	arySsaEstimate;
		tagPRFSecurity	stBuf;

		pPRBlock->m_nRecordNum[PR_FSECURITY]=0;

		//////////////////////////////////////////////////////////////////////////
		//	形成各个抽样评估状态的信息，包括损失发电出力、支路故障、多岛，最终按损失发电出力排序（从大-小）
		arySsaEstimate.clear();
		for (nState=0; nState<(int)nFStateArray.size(); nState++)
		{
			memset(&stBuf, 0, sizeof(tagPRFSecurity));
			stBuf.bEstimated=0;
			stBuf.nFStateNo=nFStateArray[nState];
			stBuf.bMIsland=pPRBlock->m_FStateArray[nFStateArray[nState]].bMIsland;
			stBuf.nLTFault=0;
			stBuf.fLossGenP=0;

			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; nFDev++)
			{
				if (pPRBlock->m_FStateFDevArray[nFDev].nFStateNo < nFStateArray[nState])
					continue;
				if (pPRBlock->m_FStateFDevArray[nFDev].nFStateNo > nFStateArray[nState])
					break;

				if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_ACLINE && (pPRBlock->m_ACLineArray[pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx].nIRadial == 0 && pPRBlock->m_ACLineArray[pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx].nZRadial == 0))
					stBuf.nLTFault++;
				else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_WIND && (pPRBlock->m_WindArray[pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx].nIRadial == 0 && pPRBlock->m_WindArray[pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx].nZRadial == 0))
					stBuf.nLTFault++;
				else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_GENERATOR)
					stBuf.fLossGenP += pPRBlock->m_GeneratorArray[pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx].fP;
			}

			arySsaEstimate.push_back(stBuf);
		}

		//////////////////////////////////////////////////////////////////////////
		//	按故障信息形成故障卡
		for (nState=0; nState<(int)arySsaEstimate.size(); nState++)
		{
			if (pPRBlock->m_nRecordNum[PR_FSECURITY] < g_PRMemDBInterface.PRGetTableMax(PR_FSECURITY))
			{
				memcpy(&pPRBlock->m_FSecurityArray[pPRBlock->m_nRecordNum[PR_FSECURITY]], &arySsaEstimate[nState], sizeof(tagPRFSecurity));
				pPRBlock->m_FSecurityArray[pPRBlock->m_nRecordNum[PR_FSECURITY]].nSaResult=PRFSecurity_Result_Unknown;
				pPRBlock->m_nRecordNum[PR_FSECURITY]++;
			}
		}

		arySsaEstimate.clear();

		return 1;
	}

	int CPRSecurity::SecurityStateFilter(tagPRBlock* pPRBlock, const int nMinSsaLTFault, const int nMaxSsaLTFault, const int nMaxSsaState, const int bLTFaultOnly)
	{
		int		nState, nFDev;
		std::vector<tagPRFSecurity>	arySsaState;
		std::vector<tagPRFSecurity>	arySsaEstimate;
		tagPRFSecurity	stBuf;

		pPRBlock->m_nRecordNum[PR_FSECURITY]=0;

		//////////////////////////////////////////////////////////////////////////
		//	形成各个抽样评估状态的信息，包括损失发电出力、支路故障、多岛，最终按损失发电出力排序（从大-小）
		arySsaState.clear();
		for (nState=0; nState<pPRBlock->m_nRecordNum[PR_FSTATE]; nState++)
		{
			memset(&stBuf, 0, sizeof(tagPRFSecurity));
			stBuf.bEstimated=0;
			stBuf.nFStateNo=nState;
			stBuf.bMIsland=pPRBlock->m_FStateArray[nState].bMIsland;
			stBuf.nLTFault=0;
			stBuf.fLossGenP=0;

			for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; nFDev++)
			{
				if (pPRBlock->m_FStateFDevArray[nFDev].nFStateNo < nState)
					continue;
				if (pPRBlock->m_FStateFDevArray[nFDev].nFStateNo > nState)
					break;

				if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_ACLINE && (pPRBlock->m_ACLineArray[pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx].nIRadial == 0 && pPRBlock->m_ACLineArray[pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx].nZRadial == 0))
					stBuf.nLTFault++;
				else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_WIND && (pPRBlock->m_WindArray[pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx].nIRadial == 0 && pPRBlock->m_WindArray[pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx].nZRadial == 0))
					stBuf.nLTFault++;
				else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_GENERATOR)
					stBuf.fLossGenP += pPRBlock->m_GeneratorArray[pPRBlock->m_FStateFDevArray[nFDev].nFDevIdx].fP;
			}

			arySsaState.push_back(stBuf);
		}
		SortSsaFState(arySsaState, 0, (int)arySsaState.size()-1);	//	按发电损失排序
		//////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////
		//	进行故障信息筛选，按最大最小支路故障数
		arySsaEstimate.clear();
		for (nState=0; nState<(int)arySsaState.size(); nState++)
		{
			if (arySsaState[nState].bEstimated)
				continue;
			if (arySsaState[nState].nLTFault >= nMinSsaLTFault && arySsaState[nState].nLTFault <= nMaxSsaLTFault)
			{
				arySsaEstimate.push_back(arySsaState[nState]);
				arySsaState[nState].bEstimated=1;
			}
		}
		//	首先填充支路故障数在最大、最小值中间的
		//////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////
		//	按发电机出力损失筛选
		if (!bLTFaultOnly)
		{
			for (nState=0; nState<(int)arySsaState.size(); nState++)
			{
				if (arySsaState[nState].bEstimated)
					continue;
				arySsaEstimate.push_back(arySsaState[nState]);
				arySsaState[nState].bEstimated=1;
				if (nMaxSsaState > 0 && (int)arySsaEstimate.size() >= nMaxSsaState)
					break;
			}
		}
		arySsaState.clear();
		//	再按负荷损失填充
		//////////////////////////////////////////////////////////////////////////

		for (nState=0; nState<(int)arySsaEstimate.size(); nState++)
			Log(g_lpszLogFile, "FState=%d LTFault=%d MIsland=%d LossGen=%f \n", arySsaEstimate[nState].nFStateNo, arySsaEstimate[nState].nLTFault, arySsaEstimate[nState].bMIsland, arySsaEstimate[nState].fLossGenP);

		//////////////////////////////////////////////////////////////////////////
		//	按故障信息形成故障卡
		for (nState=0; nState<(int)arySsaEstimate.size(); nState++)
		{
			if (nMaxSsaState > 0 && pPRBlock->m_nRecordNum[PR_FSECURITY] >= nMaxSsaState)	break;

			if (pPRBlock->m_nRecordNum[PR_FSECURITY] < g_PRMemDBInterface.PRGetTableMax(PR_FSECURITY))
			{
				memcpy(&pPRBlock->m_FSecurityArray[pPRBlock->m_nRecordNum[PR_FSECURITY]], &arySsaEstimate[nState], sizeof(tagPRFSecurity));
				pPRBlock->m_FSecurityArray[pPRBlock->m_nRecordNum[PR_FSECURITY]].nSaResult=PRFSecurity_Result_Unknown;
				pPRBlock->m_nRecordNum[PR_FSECURITY]++;
			}
		}

		arySsaEstimate.clear();

		return 1;
	}

	//	执行程序是全路径
	//	数据是相对路径
	int CPRSecurity::InitSecurityEstimate(tagPRBlock* pPRBlock, tagBpaBlock* pBpaBlock, const char* lpszWorkPath, const double fEndDT)
	{
		int		nReturn;
		char	drive[260], dir[260], fname[260], ext[260];
		char	szFileName[260], szBseFileName[260], szExec[260];

		//	1、基于DAT文件建立稳定计算BSE文件
		_splitpath(pPRBlock->m_System.szBpaDatFile, drive, dir, fname, ext);

		sprintf(szFileName, "%s%s", fname, ext);
		sprintf(szExec, "%s/pfnt.exe %s", pPRBlock->m_System.szSaRunPath, pPRBlock->m_System.szBpaDatFile);

		// 	Log(g_lpszLogFile, "StartProcess (%s)\n", szExec);
		// 	StartProcess(szExec, lpszWorkPath, SW_HIDE);
		SetCurrentDirectory(lpszWorkPath);
		system(szExec);
		SetCurrentDirectory(pPRBlock->m_System.szSaRunPath);

		_makepath(szFileName, drive, dir, fname, ".pfo");
		nReturn=BpaParsePfoFile(pBpaBlock, szFileName);
		if (nReturn <= 0)
		{
			Log(g_lpszLogFile, "解析PFO文件错误或潮流不收敛 (%s) %d\n", szFileName, nReturn);
			return 0;
		}

		_makepath(szBseFileName, drive, dir, pBpaBlock->m_BpaDat_Case.szCaseID, ".bse");
		if (_access(szBseFileName, 0) != 0)
		{
			Log(g_lpszLogFile, "没有BSE文件 (%s)\n", szBseFileName);
			return 0;
		}

		//	3、形成稳定计算文件和计算空间
		char		szTempPath[260], szWorkDir[260];
		time_t		now;
		struct tm	when;
		time(&now);
		when = *localtime( &now );

		if (strlen(lpszWorkPath) <= 0)
		{
			GetTempPath(260, szTempPath);
			sprintf(szWorkDir, "%s/Ssa%.4d%.2d%.2d%.2d%.2d", szTempPath, when.tm_year+1900, when.tm_mon+1, when.tm_mday, when.tm_hour, when.tm_min);
		}
		else
		{
			sprintf(szWorkDir, "%s/Ssa%.4d%.2d%.2d%.2d%.2d", lpszWorkPath, when.tm_year+1900, when.tm_mon+1, when.tm_mday, when.tm_hour, when.tm_min);
		}
		strcpy(pPRBlock->m_System.szSaDesPath, szWorkDir);

		if (access(pPRBlock->m_System.szSaDesPath, 0) != 0)
			_mkdir(pPRBlock->m_System.szSaDesPath);
		FormSwiFiles(pPRBlock, pPRBlock->m_System.szSaDesPath, szBseFileName, pPRBlock->m_System.szBpaSwiFile, fEndDT);

		m_bEstimating=1;

		return 1;
	}

	HANDLE CPRSecurity::SecurityEstimate(tagPRBlock* pPRBlock, tagBpaBlock* pBpaBlock, const char* lpszWorkPath, const float fEndDT, const unsigned char bMultiThread)
	{
		register int	i;
		unsigned int	nChildThreadID;

		if (m_bEstimating)
			return INVALID_HANDLE_VALUE;

		if (!InitSecurityEstimate(pPRBlock, pBpaBlock, lpszWorkPath, fEndDT))
			return INVALID_HANDLE_VALUE;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSECURITY]; i++)
			pPRBlock->m_FSecurityArray[i].bEstimated = 0;

		tagSecurityThreadInfo* pThreadInfo=(tagSecurityThreadInfo*)malloc(sizeof(tagSecurityThreadInfo));
		pThreadInfo->pPRBlock = pPRBlock;
		pThreadInfo->nMainThreadID = GetCurrentThreadId();
		pThreadInfo->bMultiThread = bMultiThread;
		return (HANDLE)_beginthreadex(NULL, 0, SecurityEstimateConThreaad, (void*)pThreadInfo, 0, &nChildThreadID);
	}

	void CPRSecurity::ExitSecurityEstimate(tagPRBlock* pPRBlock)
	{
		register int	i;
		int		nFSecurity, nFStateDev, nField;
		char	szBuf[260], szFileName[260];

		pPRBlock->m_System.fPLOS=0;
		pPRBlock->m_System.fFLOS=0;
		pPRBlock->m_System.fMTTIS=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSECURITY]; i++)
		{
			pPRBlock->m_FSecurityArray[i].nSaResult=IsBpaOutStable(pPRBlock->m_FSecurityArray[i].szOutFile, 
				pPRBlock->m_System.fMaxAngle, 
				pPRBlock->m_System.fMaxVolt, pPRBlock->m_System.fMaxVDur, 
				pPRBlock->m_System.fMinVolt, pPRBlock->m_System.fMinVDur, 
				pPRBlock->m_System.fMaxFreq, pPRBlock->m_System.fMaxFDur, 
				pPRBlock->m_System.fMinFreq, pPRBlock->m_System.fMinFDur);
		}

		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSECURITY]; i++)
		{
			if (pPRBlock->m_FSecurityArray[i].nSaResult == PRFSecurity_Result_InSecure)
			{
				pPRBlock->m_System.fFLOS++;
				pPRBlock->m_System.fPLOS += pPRBlock->m_FStateArray[pPRBlock->m_FSecurityArray[i].nFStateNo].fStateProb;
			}
		}
		if (pPRBlock->m_System.fFLOS > FLT_MIN)	pPRBlock->m_System.fMTTIS=8760*(1-pPRBlock->m_System.fPLOS)/pPRBlock->m_System.fFLOS;

		sprintf(szFileName, "%s/RSResult.xml", pPRBlock->m_System.szSaDesPath);
		TiXmlDocument*		pDocument = new TiXmlDocument();								//创建一个XML的文档对象。
		TiXmlDeclaration*	pDeclare = new TiXmlDeclaration("1.0", "GB2312", "no");
		pDocument->LinkEndChild(pDeclare);

		TiXmlElement*		pRoot=new TiXmlElement("ReliablitySecurityEstimateResult");
		pDocument->LinkEndChild(pRoot);

		TiXmlElement*	pFSecurity;
		TiXmlElement*	pFaultDev;

		pFSecurity=new TiXmlElement("RSystem");
		pRoot->LinkEndChild(pFSecurity);

		addXmlElement(pFSecurity, "FState",			pPRBlock->m_nRecordNum[PR_FSTATE]);
		addXmlElement(pFSecurity, "FSecurity",		pPRBlock->m_nRecordNum[PR_FSECURITY]);
		addXmlElement(pFSecurity, "PLOS",			pPRBlock->m_System.fPLOS);
		addXmlElement(pFSecurity, "FLOS",			pPRBlock->m_System.fFLOS);
		addXmlElement(pFSecurity, "MTTIS",			pPRBlock->m_System.fMTTIS);

		for (nFSecurity=0; nFSecurity<(int)pPRBlock->m_nRecordNum[PR_FSECURITY]; nFSecurity++)
		{
			sprintf(szBuf, "%d", nFSecurity+1);
			pFSecurity=addXmlAttribute(pRoot, "RState", "State", szBuf);

			addXmlElement(pFSecurity, "FState",			pPRBlock->m_FSecurityArray[nFSecurity].nFStateNo);
			addXmlElement(pFSecurity, "StateProb",		pPRBlock->m_FStateArray[pPRBlock->m_FSecurityArray[nFSecurity].nFStateNo].fStateProb);
			addXmlElement(pFSecurity, "StateDur",		pPRBlock->m_FStateArray[pPRBlock->m_FSecurityArray[nFSecurity].nFStateNo].fStateDur);
			addXmlElement(pFSecurity, "StateNum",		pPRBlock->m_FStateArray[pPRBlock->m_FSecurityArray[nFSecurity].nFStateNo].nStateNum);
			addXmlElement(pFSecurity, "SaResult",		g_PRMemDBInterface.PRGetFieldEnumString(PR_FSECURITY, PR_FSECURITY_RESULT, pPRBlock->m_FSecurityArray[nFSecurity].nSaResult));
			addXmlElement(pFSecurity, "LossGenP",		pPRBlock->m_FSecurityArray[nFSecurity].fLossGenP);
			addXmlElement(pFSecurity, "MIsland",		pPRBlock->m_FSecurityArray[nFSecurity].bMIsland);
			addXmlElement(pFSecurity, "LTFault",		pPRBlock->m_FSecurityArray[nFSecurity].nLTFault);
			addXmlElement(pFSecurity, "BseFile",		pPRBlock->m_FSecurityArray[nFSecurity].szBseFile);
			addXmlElement(pFSecurity, "SwiFile",		pPRBlock->m_FSecurityArray[nFSecurity].szSwiFile);
			addXmlElement(pFSecurity, "OutFile",		pPRBlock->m_FSecurityArray[nFSecurity].szOutFile);

			for (nFStateDev=0; nFStateDev<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; nFStateDev++)
			{
				if (pPRBlock->m_FStateFDevArray[nFStateDev].nFStateNo != pPRBlock->m_FSecurityArray[nFSecurity].nFStateNo)
					continue;

				pFaultDev=new TiXmlElement("FaultDevice");

				addXmlElement(pFaultDev, "FDevType",		g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_FStateFDevArray[nFStateDev].nFDevTyp));

				nField=g_PRMemDBInterface.PRGetFieldIndex(pPRBlock->m_FStateFDevArray[nFStateDev].nFDevTyp, "Name");
				g_PRMemDBInterface.PRGetRecordValue(pPRBlock, pPRBlock->m_FStateFDevArray[nFStateDev].nFDevTyp, nField, pPRBlock->m_FStateFDevArray[nFStateDev].nFDevIdx, szBuf);
				addXmlElement(pFaultDev, "FDevName",		szBuf);
				addXmlElement(pFaultDev, "FaultType",		g_PRMemDBInterface.PRGetFieldEnumString(PR_FSTATEFDEV, PR_FSTATEFDEV_DFLTTYP, pPRBlock->m_FStateFDevArray[nFStateDev].nDFltTyp));
				addXmlElement(pFaultDev, "FaultPosi",		pPRBlock->m_FStateFDevArray[nFStateDev].nDFltPos);

				pFSecurity->LinkEndChild(pFaultDev);
			}
		}
		pDocument->SaveFile(szFileName);					//保存到文件

		pDocument->Clear();
		delete pDocument;

		m_bEstimating=0;
	}


	tagSimpleCurve* CPRSecurity::GetBpaOutCurve(const char* lpszCurveName)
	{
		int		nCurve;
		if (stricmp(lpszCurveName, g_BpaOutCurveMaxAng. strCurveName.c_str()) == 0)	return &g_BpaOutCurveMaxAng;
		if (stricmp(lpszCurveName, g_BpaOutCurveMinVolt.strCurveName.c_str()) == 0)	return &g_BpaOutCurveMinVolt;
		if (stricmp(lpszCurveName, g_BpaOutCurveMaxVolt.strCurveName.c_str()) == 0)	return &g_BpaOutCurveMaxVolt;
		if (stricmp(lpszCurveName, g_BpaOutCurveMinFreq.strCurveName.c_str()) == 0)	return &g_BpaOutCurveMinFreq;
		if (stricmp(lpszCurveName, g_BpaOutCurveMaxFreq.strCurveName.c_str()) == 0)	return &g_BpaOutCurveMaxFreq;

		for (nCurve=0; nCurve<(int)g_BpaOutCurveArray.size(); nCurve++)
		{
			if (stricmp(lpszCurveName, g_BpaOutCurveArray[nCurve].strCurveName.c_str()) == 0)	return &g_BpaOutCurveArray[nCurve];
		}

		return NULL;
	}


	void CPRSecurity::FormFDeviceFMode(tagPRBlock* pPRBlock)
	{
		int		nFDev;
		// 	unsigned short	nRandom;
		// 	double			fRandom;

		srand(1);
		for (nFDev=0; nFDev<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; nFDev++)
		{
			if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_GENERATOR)
			{
				pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_Trip;
				pPRBlock->m_FStateFDevArray[nFDev].nDFltPos=0;
			}
			else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_WIND)
			{
				pPRBlock->m_FStateFDevArray[nFDev].nDFltPos=0;
				pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_ThreePhase;

				//nRandom = (unsigned short)((rand())%1000);
				//fRandom = nRandom/1000.0;
				//if (0 < fRandom && fRandom < 0.2)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_Trip;
				//else if (0.2 <= fRandom && fRandom < 0.4)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_OnePhaseGround;
				//else if (0.4 <= fRandom && fRandom < 0.6)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_TwoPhase;
				//else if (0.6 <= fRandom && fRandom < 0.8)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_ThreePhase;
				//else if (0.8 <= fRandom && fRandom < 1)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_TwoPhaseGround;
			}
			else if (pPRBlock->m_FStateFDevArray[nFDev].nFDevTyp == PR_ACLINE)
			{
				pPRBlock->m_FStateFDevArray[nFDev].nDFltPos=50;
				pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_ThreePhase;

				//nRandom = (unsigned short)((rand())%1000);
				//fRandom = nRandom/1000.0;
				//if (fRandom <= 0.333)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltPos=0;
				//else if (0.333 < fRandom && fRandom <= 0.667)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltPos=50;
				//if (0.667 < fRandom)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltPos=100;

				//nRandom = (unsigned short)((rand())%1000);
				//fRandom = nRandom/1000.0;
				//if (0 < fRandom && fRandom < 0.2)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_Trip;
				//else if (0.2 <= fRandom && fRandom < 0.4)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_OnePhaseGround;
				//else if (0.4 <= fRandom && fRandom < 0.6)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_TwoPhase;
				//else if (0.6 <= fRandom && fRandom < 0.8)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_ThreePhase;
				//else if (0.8 <= fRandom && fRandom < 1)
				//	pPRBlock->m_FStateFDevArray[nFDev].nDFltTyp=PRFState_FaultType_TwoPhaseGround;
			}
		}
	}

	void CPRSecurity::SortSsaFState(std::vector<tagPRFSecurity>& arySsaState, int nDn0, int nUp0)
	{
		if (nUp0 <= nDn0)
			return;

		int nDn = nDn0;
		int nUp = nUp0;

		double	fLossGenP=arySsaState[(nDn0+nUp0)/2].fLossGenP;
		while (nDn <= nUp)
		{
			while (nDn < nUp0 && arySsaState[nDn].fLossGenP > fLossGenP)
				++nDn;			
			while (nUp > nDn0 && arySsaState[nUp].fLossGenP < fLossGenP)
				--nUp;

			if (nDn <= nUp)
			{
				std::swap(arySsaState[nDn], arySsaState[nUp]);

				++nDn;
				--nUp;
			}
		}

		if (nDn0 < nUp)
			SortSsaFState(arySsaState, nDn0, nUp);

		if (nDn < nUp0 )
			SortSsaFState(arySsaState, nDn, nUp0);
	}

	int	CPRSecurity::ClearSsaFiles(IN const char* lpszDestDir, IN const char* lpszBpaSwiFile)
	{
		register int	i;
		char	drive[260], dir[260], fname[260], ext[260];
		char	szBuf[260];
		WIN32_FIND_DATA	FindFileData;
		HANDLE	hFind;
		std::vector<std::string>	strFileArray;

		_splitpath(lpszBpaSwiFile, drive, dir, fname, ext);

		sprintf(szBuf, "%s\\%s-*.swi", lpszDestDir, fname);
		hFind = FindFirstFile(szBuf, &FindFileData);
		if (hFind != INVALID_HANDLE_VALUE) 
		{
			do
			{
				if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (stricmp(FindFileData.cFileName, ".") != 0 && stricmp(FindFileData.cFileName, "..") != 0)
					{
					}
				}
				else
				{
					sprintf(szBuf, "%s\\%s", lpszDestDir, FindFileData.cFileName);
					strFileArray.push_back(szBuf);
				}
			}
			while (FindNextFile(hFind, &FindFileData) != 0);
			for (i=0; i<(int)strFileArray.size(); i++)
				unlink(strFileArray[i].c_str());
		} 

		sprintf(szBuf, "%s\\%s-*.bse", lpszDestDir, fname);
		hFind = FindFirstFile(szBuf, &FindFileData);
		if (hFind != INVALID_HANDLE_VALUE) 
		{
			do
			{
				if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (stricmp(FindFileData.cFileName, ".") != 0 && stricmp(FindFileData.cFileName, "..") != 0)
					{
					}
				}
				else
				{
					sprintf(szBuf, "%s\\%s", lpszDestDir, FindFileData.cFileName);
					strFileArray.push_back(szBuf);
				}
			}
			while (FindNextFile(hFind, &FindFileData) != 0);
			for (i=0; i<(int)strFileArray.size(); i++)
				unlink(strFileArray[i].c_str());
		} 

		sprintf(szBuf, "%s\\%s-*.cur", lpszDestDir, fname);
		hFind = FindFirstFile(szBuf, &FindFileData);
		if (hFind != INVALID_HANDLE_VALUE) 
		{
			do
			{
				if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (stricmp(FindFileData.cFileName, ".") != 0 && stricmp(FindFileData.cFileName, "..") != 0)
					{
					}
				}
				else
				{
					sprintf(szBuf, "%s\\%s", lpszDestDir, FindFileData.cFileName);
					strFileArray.push_back(szBuf);
				}
			}
			while (FindNextFile(hFind, &FindFileData) != 0);
			for (i=0; i<(int)strFileArray.size(); i++)
				unlink(strFileArray[i].c_str());
		} 


		sprintf(szBuf, "%s\\%s-*.swx", lpszDestDir, fname);
		hFind = FindFirstFile(szBuf, &FindFileData);
		if (hFind != INVALID_HANDLE_VALUE) 
		{
			do
			{
				if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (stricmp(FindFileData.cFileName, ".") != 0 && stricmp(FindFileData.cFileName, "..") != 0)
					{
					}
				}
				else
				{
					sprintf(szBuf, "%s\\%s", lpszDestDir, FindFileData.cFileName);
					strFileArray.push_back(szBuf);
				}
			}
			while (FindNextFile(hFind, &FindFileData) != 0);
			for (i=0; i<(int)strFileArray.size(); i++)
				unlink(strFileArray[i].c_str());
		} 


		sprintf(szBuf, "%s\\%s-*.out", lpszDestDir, fname);
		hFind = FindFirstFile(szBuf, &FindFileData);
		if (hFind != INVALID_HANDLE_VALUE) 
		{
			do
			{
				if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (stricmp(FindFileData.cFileName, ".") != 0 && stricmp(FindFileData.cFileName, "..") != 0)
					{
					}
				}
				else
				{
					sprintf(szBuf, "%s\\%s", lpszDestDir, FindFileData.cFileName);
					strFileArray.push_back(szBuf);
				}
			}
			while (FindNextFile(hFind, &FindFileData) != 0);
			for (i=0; i<(int)strFileArray.size(); i++)
				unlink(strFileArray[i].c_str());
		}
		return 1;
	}
}
