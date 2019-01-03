#if _MSC_VER >= 1400 // VC++ 8.0
#pragma warning( disable : 4996 )   // disable warning about strdup being deprecated.
#endif
#include "BpaPRDataDefine.h"
#include "../../../../Common/TinyXML/tinyxmlglobal.h"
#include "PRAdequacyBase.h"

namespace	PRAdequacyBase
{
	static	char	m_szDefaultSettingFile[260] = "";
	static	double	g_fMinMagFactor=1000000000;
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	void InitBpaPRAdequacySetting(tagBpaPRAdequacySetting* pSetting)
	{
		pSetting->strBpaDatFile.clear();	//	潮流输入文件
		pSetting->strBpaSwiFile.clear();	//	稳定输入文件
		pSetting->strBpaRParamFile.clear();	//	可靠性参数输入文件

		pSetting->fTinyGenThreshold=0;
		pSetting->fLowVoltThreshold=0.0;
		pSetting->fZIL=0.00001;

		pSetting->nPRSampleMethod=PRFState_SamplingMethod_MonteCarlo;
		pSetting->nMaxGenFault=20;
		pSetting->nMaxBranFault=20;
		pSetting->bLineELimit=1;
		pSetting->bTranELimit=1;
		pSetting->bGenPELimit=1;
		pSetting->bUPFCELimit=1;
		pSetting->bAuxLoadAdjust = 0;
		pSetting->bEQGenAdjust = 0;
		pSetting->bEQLoadAdjust = 0;

		pSetting->nMCSSimulateTime=2000000;			//	MCS最大抽样仿真时长
		pSetting->fMCSMinStateProb=0;			 	//	MCS[蒙特卡罗]设备故障概率门槛值
		pSetting->fFSTMaxCumuProb=0.99;				//	FST[快速排序]累积概率
		pSetting->fFSTMinStateProb=1.0/1000000000;	//	FST[快速排序]设备故障概率门槛值
		pSetting->nFSTMaxStateNum=100000;			//	FST[快速排序]最大状态数
		pSetting->nSTSMaxStateNum=100000;			//	STS[状态抽样]最大状态数
		pSetting->fANAMinStateProb=1.0/1000000000;	//	ANA[ 解析法 ]设备故障概率门槛值

		pSetting->fDc2AcFactor = 1.1;
		pSetting->fMinIslandGLRatio = 0.5;
		pSetting->nMultiThread = 1;
		pSetting->bUPFCAdjustRC = 1;
		pSetting->bGenBusLoadAsAux = 0;
	}

	void CopyBpaPRAdequacySetting(tagBpaPRAdequacySetting* pFromSetting, tagBpaPRAdequacySetting* pToSetting)
	{
		pToSetting->strBpaDatFile		= pFromSetting->strBpaDatFile		;
		pToSetting->strBpaSwiFile		= pFromSetting->strBpaSwiFile		;
		pToSetting->strBpaRParamFile	= pFromSetting->strBpaRParamFile	;
		pToSetting->fTinyGenThreshold	= pFromSetting->fTinyGenThreshold	;
		pToSetting->fLowVoltThreshold	= pFromSetting->fLowVoltThreshold	;
		pToSetting->fZIL				= pFromSetting->fZIL				;
		pToSetting->nPRSampleObject		= pFromSetting->nPRSampleObject		;
		pToSetting->nPRSampleMethod		= pFromSetting->nPRSampleMethod		;
		pToSetting->nMaxGenFault		= pFromSetting->nMaxGenFault		;
		pToSetting->nMaxBranFault		= pFromSetting->nMaxBranFault		;
		pToSetting->bLineELimit			= pFromSetting->bLineELimit			;
		pToSetting->bTranELimit			= pFromSetting->bTranELimit			;
		pToSetting->bGenPELimit			= pFromSetting->bGenPELimit			;
		pToSetting->bUPFCELimit			= pFromSetting->bUPFCELimit			;
		pToSetting->bAuxLoadAdjust		= pFromSetting->bAuxLoadAdjust		;
		pToSetting->bEQGenAdjust		= pFromSetting->bEQGenAdjust		;
		pToSetting->bEQLoadAdjust		= pFromSetting->bEQLoadAdjust		;
		pToSetting->nMCSSimulateTime	= pFromSetting->nMCSSimulateTime	;
		pToSetting->fMCSMinStateProb	= pFromSetting->fMCSMinStateProb	;
		pToSetting->fFSTMaxCumuProb		= pFromSetting->fFSTMaxCumuProb		;
		pToSetting->fFSTMinStateProb	= pFromSetting->fFSTMinStateProb	;
		pToSetting->nFSTMaxStateNum		= pFromSetting->nFSTMaxStateNum		;
		pToSetting->nSTSMaxStateNum		= pFromSetting->nSTSMaxStateNum		;
		pToSetting->fANAMinStateProb	= pFromSetting->fANAMinStateProb	;
		pToSetting->fDc2AcFactor		= pFromSetting->fDc2AcFactor		;
		pToSetting->fMinIslandGLRatio	= pFromSetting->fMinIslandGLRatio	;
		pToSetting->nMultiThread		= pFromSetting->nMultiThread		;
		pToSetting->bUPFCAdjustRC		= pFromSetting->bUPFCAdjustRC		;
		pToSetting->bGenBusLoadAsAux	= pFromSetting->bGenBusLoadAsAux	;
	}

	int	ReadBpaPRAdequacySetting(const char* lpszSettingFile, tagBpaPRAdequacySetting* pSetting)
	{
		strcpy(m_szDefaultSettingFile, lpszSettingFile);
		InitBpaPRAdequacySetting(pSetting);

		TiXmlElement	*pLine, *pElement;
		TiXmlNode*		pNode;

		TiXmlDocument doc(lpszSettingFile);
		if (!doc.LoadFile())
			return 0;

		TiXmlElement* pRoot = doc.RootElement();
		if (stricmp(pRoot->Value(), "BpaPRAdequacySetting") != 0)
		{
			doc.Clear();
			return 0;
		}

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
						if (stricmp(pElement->Value(), "BpaDatFile") == 0)					{	pSetting->strBpaDatFile		=pNode->Value();						}
						else if (stricmp(pElement->Value(), "BpaSwiFile") == 0)				{	pSetting->strBpaSwiFile		=pNode->Value();						}
						else if (stricmp(pElement->Value(), "BpaRParamFile") == 0)			{	pSetting->strBpaRParamFile	=pNode->Value();						}

						else if (stricmp(pElement->Value(), "TinyGenThreshold") == 0)		{	pSetting->fTinyGenThreshold	=atof(pNode->Value());					}
						else if (stricmp(pElement->Value(), "LowVoltThreshold") == 0)		{	pSetting->fLowVoltThreshold	=atof(pNode->Value());					}
						else if (stricmp(pElement->Value(), "ZIL") == 0)					{	pSetting->fZIL				=atof(pNode->Value());					}

						else if (stricmp(pElement->Value(), "SampleType") == 0)				{	pSetting->nPRSampleMethod	=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "MaxGenFault") == 0)			{	pSetting->nMaxGenFault		=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "MaxBranFault") == 0)			{	pSetting->nMaxBranFault		=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "LineELimit") == 0)				{	pSetting->bLineELimit		=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "TranELimit") == 0)				{	pSetting->bTranELimit		=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "GenPELimit") == 0)				{	pSetting->bGenPELimit		=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "UPFCELimit") == 0)				{	pSetting->bUPFCELimit		=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "AuxLoadAdjust") == 0)			{	pSetting->bAuxLoadAdjust	=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "EQGenAdjust") == 0)			{	pSetting->bEQGenAdjust		=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "EQLoadAdjust") == 0)			{	pSetting->bEQLoadAdjust		=atoi(pNode->Value());					}

						else if (stricmp(pElement->Value(), "MCSSimulateTime") == 0)		{	pSetting->nMCSSimulateTime	=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "MCSMinStateProb") == 0)		{	pSetting->fMCSMinStateProb	=atof(pNode->Value())/g_fMinMagFactor;	}
						else if (stricmp(pElement->Value(), "FSTMaxStateNum") == 0)			{	pSetting->nFSTMaxStateNum	=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "FSTMaxCumuProb") == 0)			{	pSetting->fFSTMaxCumuProb	=atof(pNode->Value());					}
						else if (stricmp(pElement->Value(), "FSTMinStateProb") == 0)		{	pSetting->fFSTMinStateProb	=atof(pNode->Value())/g_fMinMagFactor;	}
						else if (stricmp(pElement->Value(), "STSMaxStateNum") == 0)			{	pSetting->nSTSMaxStateNum	=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "ANAMinStateProb") == 0)		{	pSetting->fANAMinStateProb	=atof(pNode->Value())/g_fMinMagFactor;	}

						else if (stricmp(pElement->Value(), "MultiThread") == 0)			{	pSetting->nMultiThread		=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "UPFCAdjustRatedCapacity") == 0){	pSetting->bUPFCAdjustRC		=atoi(pNode->Value());					}
						else if (stricmp(pElement->Value(), "Dc2AcFactor") == 0)			{	pSetting->fDc2AcFactor		=atof(pNode->Value());					}
						else if (stricmp(pElement->Value(), "MinIslandGLRatio") == 0)		{	pSetting->fMinIslandGLRatio	=atof(pNode->Value());					}
						else if (stricmp(pElement->Value(), "GenBusLoadAsAux") == 0)		{	pSetting->bGenBusLoadAsAux	=atoi(pNode->Value());					}
					}
					pElement = pElement->NextSiblingElement();
				}
			}
			pLine = pLine->NextSiblingElement();
		}

		doc.Clear();

		if (pSetting->fDc2AcFactor < 1 || pSetting->fDc2AcFactor > 2)
			pSetting->fDc2AcFactor=1.1;

		return 1;
	}

	void	SaveBpaPRAdequacySetting(tagBpaPRAdequacySetting* pSetting)
	{
		if (strlen(m_szDefaultSettingFile) <= 0)
			return;

		TiXmlDocument*		pDocument = new TiXmlDocument();								//创建一个XML的文档对象。
		TiXmlDeclaration*	pDeclare = new TiXmlDeclaration("1.0", "gb2312", "no");		pDocument->LinkEndChild(pDeclare);
		TiXmlElement*		pRootElement = new TiXmlElement("BpaPRAdequacySetting");	pDocument->LinkEndChild(pRootElement);

		TiXmlElement*		pElement = new TiXmlElement("Base");
		pRootElement->LinkEndChild(pElement);

		addXmlElement(pElement, "BpaDatFile",				pSetting->strBpaDatFile.c_str()			);
		addXmlElement(pElement, "BpaSwiFile",				pSetting->strBpaSwiFile.c_str()			);
		addXmlElement(pElement, "BpaRParamFile",			pSetting->strBpaRParamFile.c_str()		);

		addXmlElement(pElement, "TinyGenThreshold",			pSetting->fTinyGenThreshold				);
		addXmlElement(pElement, "LowVoltThreshold",			pSetting->fLowVoltThreshold				);
		addXmlElement(pElement, "ZIL",						pSetting->fZIL							);

		addXmlElement(pElement, "SampleType",				pSetting->nPRSampleMethod					);
		addXmlElement(pElement, "MaxGenFault",				pSetting->nMaxGenFault					);
		addXmlElement(pElement, "MaxBranFault",				pSetting->nMaxBranFault					);
		addXmlElement(pElement, "LineELimit",				pSetting->bLineELimit						);
		addXmlElement(pElement, "TranELimit",				pSetting->bTranELimit						);
		addXmlElement(pElement, "GenPELimit",				pSetting->bGenPELimit						);
		addXmlElement(pElement, "UPFCELimit",				pSetting->bUPFCELimit						);
		addXmlElement(pElement, "AuxLoadAdjust",			pSetting->bAuxLoadAdjust					);
		addXmlElement(pElement, "EQGenAdjust",				pSetting->bEQGenAdjust					);
		addXmlElement(pElement, "EQLoadAdjust",				pSetting->bEQLoadAdjust					);

		addXmlElement(pElement, "MCSSimulateTime",			pSetting->nMCSSimulateTime				);
		addXmlElement(pElement, "MCSMinStateProb",			g_fMinMagFactor*pSetting->fMCSMinStateProb);
		addXmlElement(pElement, "FSTMaxStateNum",			pSetting->nFSTMaxStateNum					);
		addXmlElement(pElement, "FSTMaxCumuProb",			pSetting->fFSTMaxCumuProb					);
		addXmlElement(pElement, "FSTMinStateProb",			g_fMinMagFactor*pSetting->fFSTMinStateProb);
		addXmlElement(pElement, "STSMaxStateNum",			pSetting->nSTSMaxStateNum					);
		addXmlElement(pElement, "ANAMinStateProb",			g_fMinMagFactor*pSetting->fANAMinStateProb);

		addXmlElement(pElement, "Dc2AcFactor",				pSetting->fDc2AcFactor					);
		addXmlElement(pElement, "MinIslandGLRatio",			pSetting->fMinIslandGLRatio				);

		addXmlElement(pElement, "MultiThread",				pSetting->nMultiThread					);
		addXmlElement(pElement, "UPFCAdjustRatedCapacity",	pSetting->bUPFCAdjustRC					);
		addXmlElement(pElement, "GenBusLoadAsAux",			pSetting->bGenBusLoadAsAux				);

		pDocument->SaveFile(m_szDefaultSettingFile);		//保存到文件
		pDocument->Clear();
		delete pDocument;
	}
}
