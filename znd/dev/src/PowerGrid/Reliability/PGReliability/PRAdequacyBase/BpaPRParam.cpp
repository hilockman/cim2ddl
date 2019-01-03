#include <float.h>
#include <algorithm>
#include "BpaPRParam.h"
#include "../../../../Common/TinyXML/tinyxmlglobal.h"
#include "../../../../../include/ilog.h"
//extern	const	char*	g_lpszLogFile;
//extern	void	Log(const char* lpszLogFile, char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;
	extern	int AppendMStateParam(tagPRBlock* pPRBlock, tagPRDevMState* pMState);
	extern	int ModifyMStateParam(tagPRBlock* pPRBlock, const int nModRec, tagPRDevMState* pMState);

	CBpaPRParam::CBpaPRParam(void)
	{
	}

	CBpaPRParam::~CBpaPRParam(void)
	{
	}

	int CBpaPRParam::FindPRACBus(tagPRBlock* pPRBlock, const char* lpszName)
	{
		int		nDev;
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
		{
			if (_stricmp(pPRBlock->m_ACBusArray[nDev].szName, lpszName) == 0)
			{
				return nDev;
				break;
			}
		}

		return -1;
	}

	//////////////////////////////////////////////////////////////////////////
	//	因为需要通过参数添加设备，所以UPFC或TSCS可能未排序
	int CBpaPRParam::FindPRTCSC(tagPRBlock* pPRBlock, const char* lpszName)
	{
		int		nDev;

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_TCSC]; nDev++)
		{
			if (_stricmp(pPRBlock->m_TCSCArray[nDev].szName, lpszName) == 0)
			{
				return nDev;
				break;
			}
		}
		return -1;
	}

	int CBpaPRParam::FindPRUPFC(tagPRBlock* pPRBlock, const char* lpszName)
	{
		int		nDev;

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_UPFC]; nDev++)
		{
			if (_stricmp(pPRBlock->m_UPFCArray[nDev].szName, lpszName) == 0)
			{
				return nDev;
				break;
			}
		}
		return -1;
	}

	int CBpaPRParam::FindPRConverter(tagPRBlock* pPRBlock, const char* lpszName)
	{
		int		nDev;

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_CONVERTER]; nDev++)
		{
			if (_stricmp(pPRBlock->m_ConverterArray[nDev].szName, lpszName) == 0)
			{
				return nDev;
				break;
			}
		}
		return -1;
	}

	int CBpaPRParam::FindPRDCLine(tagPRBlock* pPRBlock, const char* lpszName)
	{
		int		nDev;

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_DCLINE]; nDev++)
		{
			if (_stricmp(pPRBlock->m_DCLineArray[nDev].szName, lpszName) == 0)
			{
				return nDev;
				break;
			}
		}
		return -1;
	}

	int	CBpaPRParam::ReadBpaPRParam(const char* lpszFileName, tagPRBlock* pPRBlock)
	{
		int		nParam;

		pPRBlock->m_nRecordNum[PR_COMMRPARAM] = 0;
		pPRBlock->m_nRecordNum[PR_MANUALFAULT] = 0;
		pPRBlock->m_nRecordNum[PR_COMMONFAULT] = 0;
		pPRBlock->m_nRecordNum[PR_TCSC] = 0;
		pPRBlock->m_nRecordNum[PR_UPFC] = 0;
		pPRBlock->m_nRecordNum[PR_CONVERTER] = 0;
		pPRBlock->m_nRecordNum[PR_DCBUS] = 0;
		pPRBlock->m_nRecordNum[PR_DCLINE] = 0;
		pPRBlock->m_nRecordNum[PR_DEVMSTATE]=0;
		for (nParam=0; nParam<pPRBlock->m_nRecordNum[PR_ACBUS]; nParam++)
		{
			pPRBlock->m_ACBusArray[nParam].fRerr=0;	//	可靠性具体设备参数为实际使用参数
			pPRBlock->m_ACBusArray[nParam].fTrep=0;
			pPRBlock->m_ACBusArray[nParam].fRrep=0;
			pPRBlock->m_ACBusArray[nParam].fGoodProb=0;
			pPRBlock->m_ACBusArray[nParam].fFailProb=0;
			pPRBlock->m_ACBusArray[nParam].nRParamType = PRDevice_RParamType_Common;
		}
		for (nParam=0; nParam<pPRBlock->m_nRecordNum[PR_GENERATOR]; nParam++)
		{
			pPRBlock->m_GeneratorArray[nParam].fRerr=0;
			pPRBlock->m_GeneratorArray[nParam].fTrep=0;
			pPRBlock->m_GeneratorArray[nParam].fRrep=0;
			pPRBlock->m_GeneratorArray[nParam].fGoodProb=0;
			pPRBlock->m_GeneratorArray[nParam].fFailProb=0;
			pPRBlock->m_GeneratorArray[nParam].nRParamType = PRDevice_RParamType_Common;
		}
		for (nParam=0; nParam<pPRBlock->m_nRecordNum[PR_POWERLOAD]; nParam++)
		{
			pPRBlock->m_PowerLoadArray[nParam].fRerr=0;
			pPRBlock->m_PowerLoadArray[nParam].fTrep=0;
			pPRBlock->m_PowerLoadArray[nParam].fRrep=0;
			pPRBlock->m_PowerLoadArray[nParam].fGoodProb=0;
			pPRBlock->m_PowerLoadArray[nParam].fFailProb=0;
			pPRBlock->m_PowerLoadArray[nParam].nRParamType = PRDevice_RParamType_Common;
		}
		for (nParam=0; nParam<pPRBlock->m_nRecordNum[PR_ACLINE]; nParam++)
		{
			pPRBlock->m_ACLineArray[nParam].fRerr=0;
			pPRBlock->m_ACLineArray[nParam].fTrep=0;
			pPRBlock->m_ACLineArray[nParam].fRrep=0;
			pPRBlock->m_ACLineArray[nParam].fGoodProb=0;
			pPRBlock->m_ACLineArray[nParam].fFailProb=0;
			pPRBlock->m_ACLineArray[nParam].nRParamType = PRDevice_RParamType_Common;
		}
		for (nParam=0; nParam<pPRBlock->m_nRecordNum[PR_WIND]; nParam++)
		{
			pPRBlock->m_WindArray[nParam].fRerr=0;	//	可靠性具体设备参数为实际使用参数
			pPRBlock->m_WindArray[nParam].fTrep=0;
			pPRBlock->m_WindArray[nParam].fRrep=0;
			pPRBlock->m_WindArray[nParam].fGoodProb=0;
			pPRBlock->m_WindArray[nParam].fFailProb=0;
			pPRBlock->m_WindArray[nParam].nRParamType = PRDevice_RParamType_Common;
		}
		for (nParam=0; nParam<pPRBlock->m_nRecordNum[PR_HVDC]; nParam++)
		{
			pPRBlock->m_HVDCArray[nParam].fRerr=0;	//	可靠性具体设备参数为实际使用参数
			pPRBlock->m_HVDCArray[nParam].fTrep=0;
			pPRBlock->m_HVDCArray[nParam].fRrep=0;
			pPRBlock->m_HVDCArray[nParam].fGoodProb=0;
			pPRBlock->m_HVDCArray[nParam].fFailProb=0;
			pPRBlock->m_HVDCArray[nParam].nRParamType = PRDevice_RParamType_Common;
		}

		TiXmlElement		*pLine, *pElement, *pFDevice;
		TiXmlAttribute		*pAttr;
		tagPRCommRParam		sRParam;

		TiXmlDocument doc(lpszFileName);
		if (!doc.LoadFile())
			return 0;

		TiXmlElement* pRoot = doc.RootElement();
		if (_stricmp(pRoot->Value(), "BpaPRParam") != 0)
		{
			doc.Clear();
			return 0;
		}

		pLine = pRoot->FirstChildElement();
		while (pLine != NULL)
		{
			if (_stricmp(pLine->Value(),"BpaPRParamCommon") == 0)
			{
				memset(&sRParam, 0, sizeof(tagPRCommRParam));

				pElement = pLine->FirstChildElement();
				while (pElement != NULL)
				{
					pAttr=pElement->FirstAttribute();
					while (pAttr != NULL)
					{
						if (_stricmp(pAttr->Name(), "DevType") == 0)	sRParam.nDevType	=g_PRMemDBInterface.PRGetTableIndex(pAttr->Value());
						else if (_stricmp(pAttr->Name(), "KeyWord") == 0)	strcpy(sRParam.szKeyWord, pAttr->Value());
						else if (_stricmp(pAttr->Name(), "UpVLimit") == 0 || _stricmp(pAttr->Name(), "UpLimit") == 0)	sRParam.fUpVLmt		=atof(pAttr->Value());
						else if (_stricmp(pAttr->Name(), "DnVLimit") == 0 || _stricmp(pAttr->Name(), "DnLimit") == 0)	sRParam.fDnVLmt		=atof(pAttr->Value());
						else if (_stricmp(pAttr->Name(), "UpCapLimit") == 0)	sRParam.fUpCapLmt	=atof(pAttr->Value());
						else if (_stricmp(pAttr->Name(), "DnCapLimit") == 0)	sRParam.fDnCapLmt	=atof(pAttr->Value());
						else if (_stricmp(pAttr->Name(), "Rerr") == 0)		sRParam.fRerr		=atof(pAttr->Value());
						else if (_stricmp(pAttr->Name(), "Trep") == 0)		sRParam.fTrep		=atof(pAttr->Value());

						pAttr=pAttr->Next();
					}

					if (pPRBlock->m_nRecordNum[PR_COMMRPARAM] < g_PRMemDBInterface.PRGetTableMax(PR_COMMRPARAM))
						memcpy(&pPRBlock->m_CommRParamArray[pPRBlock->m_nRecordNum[PR_COMMRPARAM]++], &sRParam, sizeof(tagPRCommRParam));
					else
						log_error("表 %s 容量超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_COMMRPARAM));

					pElement = pElement->NextSiblingElement();
				}
			}
			else if (_stricmp(pLine->Value(), "BpaPRManuState") == 0 || _stricmp(pLine->Value(), "BpaPRManualFault") == 0)
			{
				tagPRManualFault	sMFault;

				pElement = pLine->FirstChildElement();
				while (pElement != NULL)
				{
					memset(&sMFault, 0, sizeof(tagPRManualFault));

					pAttr=pElement->FirstAttribute();
					while (pAttr != NULL)
					{
						if (_stricmp(pAttr->Name(), "StateID") == 0)
						{
							strcpy(sMFault.szName, pAttr->Value());
							if (strlen(sMFault.szName) <= 0)
								sprintf(sMFault.szName, "事件%d", pPRBlock->m_nRecordNum[PR_MANUALFAULT]+1);
						}
						else if (_stricmp(pAttr->Name(), "FaultName") == 0)
							strcpy(sMFault.szName, pAttr->Value());
						pAttr=pAttr->Next();
					}

					pFDevice = pElement->FirstChildElement();
					while (pFDevice != NULL)
					{
						pAttr=pFDevice->FirstAttribute();
						while (pAttr != NULL)
						{
							if (_stricmp(pAttr->Name(), "DevType") == 0 || _stricmp(pAttr->Name(), "FDevType") == 0)		sMFault.nFDevType	=g_PRMemDBInterface.PRGetTableIndex(pAttr->Value());
							else if (_stricmp(pAttr->Name(), "DevName") == 0 || _stricmp(pAttr->Name(), "FDevName") == 0)	strcpy(sMFault.szFDevName, pAttr->Value());
							pAttr=pAttr->Next();
						}

						if (pPRBlock->m_nRecordNum[PR_MANUALFAULT] < g_PRMemDBInterface.PRGetTableMax(PR_MANUALFAULT))
							memcpy(&pPRBlock->m_ManualFaultArray[pPRBlock->m_nRecordNum[PR_MANUALFAULT]++], &sMFault, sizeof(tagPRManualFault));
						else
							log_error("表 %s 容量超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_MANUALFAULT));

						pFDevice = pFDevice->NextSiblingElement();
					}

					pElement = pElement->NextSiblingElement();
				}
			}
			else if (_stricmp(pLine->Value(), "BpaPRCommonFault") == 0)
			{
				tagPRCommonFault		sCommon;
				memset(&sCommon, 0, sizeof(tagPRCommonFault));

				pElement = pLine->FirstChildElement();
				while (pElement != NULL)
				{
					sprintf(sCommon.szName, "%d", pPRBlock->m_nRecordNum[PR_COMMONFAULT]+1);
					pAttr=pElement->FirstAttribute();
					while (pAttr != NULL)
					{
						if (_stricmp(pAttr->Name(), "CommmonFaultName") == 0)
							strcpy(sCommon.szName, pAttr->Value());
						else if (_stricmp(pAttr->Name(), "CommmonFaultType") == 0)
							sCommon.nCommonFaultType = g_PRMemDBInterface.PRGetFieldEnumValue(PR_COMMONFAULT, PR_COMMONFAULT_COMMFAULTTYPE, pAttr->Value());
						pAttr=pAttr->Next();
					}


					pFDevice = pElement->FirstChildElement();
					while (pFDevice != NULL)
					{

						pAttr=pFDevice->FirstAttribute();
						while (pAttr != NULL)
						{
							if (_stricmp(pAttr->Name(), "CommonFaultType") == 0)		sCommon.nCommonFaultType=atoi(pAttr->Value());
							if (_stricmp(pAttr->Name(), "DeviceCommonType") == 0)		sCommon.nDeviceCommonType=atoi(pAttr->Value());
							else if (_stricmp(pAttr->Name(), "DevType") == 0)			sCommon.nDevType	=g_PRMemDBInterface.PRGetTableIndex(pAttr->Value());
							else if (_stricmp(pAttr->Name(), "DevName") == 0)			strcpy(sCommon.szDevName, pAttr->Value());
							pAttr=pAttr->Next();
						}
						if (pPRBlock->m_nRecordNum[PR_COMMONFAULT] < g_PRMemDBInterface.PRGetTableMax(PR_COMMONFAULT))
							memcpy(&pPRBlock->m_CommonFaultArray[pPRBlock->m_nRecordNum[PR_COMMONFAULT]++], &sCommon, sizeof(tagPRCommonFault));
						else
							log_error("表 %s 容量超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_COMMONFAULT));

						pFDevice = pFDevice->NextSiblingElement();
					}

					pElement = pElement->NextSiblingElement();
				}
			}
			else if (_stricmp(pLine->Value(), "BpaPRParamMultState") == 0)
			{
				tagPRDevMState	sMState;
				double			*pfRate, *pfProb, *pfFreq;
				unsigned char	nRateNum, nProbNum, nFreqNum;

				pElement = pLine->FirstChildElement();
				while (pElement != NULL)
				{
					memset(&sMState, 0, sizeof(tagPRDevMState));
					pfRate=&sMState.fState1Rate;
					pfProb=&sMState.fState1Prob;
					pfFreq=&sMState.fState1Freq1;
					nRateNum = nProbNum = nFreqNum = 0;

					pAttr=pElement->FirstAttribute();
					while (pAttr != NULL)
					{
						if (_stricmp(pAttr->Name(), "DevType") == 0)		sMState.nType		=g_PRMemDBInterface.PRGetTableIndex(pAttr->Value());
						else if (_stricmp(pAttr->Name(), "KeyWord") == 0)	strcpy(sMState.szName, pAttr->Value());
						else if (_stricmp(pAttr->Name(), "StateNum") == 0)	sMState.nStateNum	=atoi(pAttr->Value());
						else if (strstr(pAttr->Name(), "Rate") != NULL)		pfRate[nRateNum++]	=atof(pAttr->Value());
						else if (strstr(pAttr->Name(), "Prob") != NULL)		pfProb[nProbNum++]	=atof(pAttr->Value());
						else if (strstr(pAttr->Name(), "Freq") != NULL)		pfFreq[nFreqNum++]	=atof(pAttr->Value());

						pAttr=pAttr->Next();
					}

					AppendMStateParam(pPRBlock, &sMState);

					pElement = pElement->NextSiblingElement();
				}
			}

			pLine = pLine->NextSiblingElement();
		}

		for (nParam=0; nParam<pPRBlock->m_nRecordNum[PR_COMMRPARAM]; nParam++)
		{
			if (_stricmp(pPRBlock->m_CommRParamArray[nParam].szKeyWord, "ALL") != 0)
				continue;
			SetPRParam_Comm(pPRBlock, pPRBlock->m_CommRParamArray[nParam].nDevType, pPRBlock->m_CommRParamArray[nParam].szKeyWord, pPRBlock->m_CommRParamArray[nParam].fDnCapLmt, pPRBlock->m_CommRParamArray[nParam].fUpCapLmt, pPRBlock->m_CommRParamArray[nParam].fDnVLmt, pPRBlock->m_CommRParamArray[nParam].fUpVLmt, pPRBlock->m_CommRParamArray[nParam].fRerr, pPRBlock->m_CommRParamArray[nParam].fTrep);
		}
		for (nParam=0; nParam<pPRBlock->m_nRecordNum[PR_COMMRPARAM]; nParam++)
		{
			if (_stricmp(pPRBlock->m_CommRParamArray[nParam].szKeyWord, "ALL") == 0)
				continue;
			SetPRParam_Comm(pPRBlock, pPRBlock->m_CommRParamArray[nParam].nDevType, pPRBlock->m_CommRParamArray[nParam].szKeyWord, pPRBlock->m_CommRParamArray[nParam].fDnCapLmt, pPRBlock->m_CommRParamArray[nParam].fUpCapLmt, pPRBlock->m_CommRParamArray[nParam].fDnVLmt, pPRBlock->m_CommRParamArray[nParam].fUpVLmt, pPRBlock->m_CommRParamArray[nParam].fRerr, pPRBlock->m_CommRParamArray[nParam].fTrep);
		}

		pLine = pRoot->FirstChildElement();
		while (pLine != NULL)
		{
			if (_stricmp(pLine->Value(),"BpaPRParamDev") == 0)
			{
				int		nParamType, nDevType, nAuxType;
				double	fRerr, fTrep, fAux;
				std::string	strDevBus, strAuxBus, strKeyWord;

				nParamType = nDevType = -1;
				fRerr = fTrep = fAux = 0;
				nAuxType = 0;
				strKeyWord.clear();
				strDevBus.clear();
				strAuxBus.clear();

				pElement = pLine->FirstChildElement();
				while (pElement != NULL)
				{
					pAttr=pElement->FirstAttribute();
					while (pAttr != NULL)
					{
						if (_stricmp(pAttr->Name(), "ParamType") == 0)			nParamType	=atoi(pAttr->Value());
						else if (_stricmp(pAttr->Name(), "DevType") == 0)		nDevType	=g_PRMemDBInterface.PRGetTableIndex(pAttr->Value());
						else if (_stricmp(pAttr->Name(), "KeyWord") == 0)		strKeyWord	=pAttr->Value();
						else if (_stricmp(pAttr->Name(), "Rerr") == 0)			fRerr		=atof(pAttr->Value());
						else if (_stricmp(pAttr->Name(), "Trep") == 0)			fTrep		=atof(pAttr->Value());
						else if (_stricmp(pAttr->Name(), "SeriesBus") == 0)		strDevBus	=pAttr->Value();
						else if (_stricmp(pAttr->Name(), "ACBus") == 0)			strDevBus	=pAttr->Value();
						else if (_stricmp(pAttr->Name(), "DCBusI") == 0)		strDevBus	=pAttr->Value();
						else if (_stricmp(pAttr->Name(), "ParallelBus") == 0)	strAuxBus	=pAttr->Value();
						else if (_stricmp(pAttr->Name(), "DCBus") == 0)			strAuxBus	=pAttr->Value();
						else if (_stricmp(pAttr->Name(), "DCBusJ") == 0)		strAuxBus	=pAttr->Value();
						else if (_stricmp(pAttr->Name(), "Aux") == 0)			fAux		=atof(pAttr->Value());
						else if (_stricmp(pAttr->Name(), "Type") == 0)			nAuxType	=atoi(pAttr->Value());

						pAttr=pAttr->Next();
					}
					if (nParamType == PRDevice_RParamType_Device)
					{
						switch (nDevType)
						{
						case	PR_GENERATOR:
						case	PR_POWERLOAD:
						case	PR_ACBUS:
						case	PR_ACLINE:
						case	PR_WIND:
						case	PR_HVDC:
							SetPRParam_Dev(pPRBlock, nDevType, strKeyWord.c_str(), fRerr, fTrep, fAux);
							break;
						case	PR_TCSC:
						case	PR_UPFC:
						case	PR_CONVERTER:
						case	PR_DCLINE:
							SetPRParam_Dev(pPRBlock, nDevType, strKeyWord.c_str(), strDevBus.c_str(), strAuxBus.c_str(), fRerr, fTrep, fAux, nAuxType);
							break;
						}
					}

					pElement = pElement->NextSiblingElement();
				}
			}
			pLine = pLine->NextSiblingElement();
		}

		doc.Clear();

		register int	i;
		int				nDev;
		char			szBuf[260];
		for (nParam=0; nParam<pPRBlock->m_nRecordNum[PR_COMMONFAULT]; nParam++)
		{
			if (pPRBlock->m_CommonFaultArray[nParam].nDevType == PR_ACBUS)
			{
				for (i=0; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
				{
					if (_stricmp(pPRBlock->m_ACBusArray[i].szName, pPRBlock->m_CommonFaultArray[nParam].szDevName) == 0)
					{
						pPRBlock->m_CommonFaultArray[nParam].nDevIndex = i;
						break;
					}
				}
			}
			else
			{
				pPRBlock->m_CommonFaultArray[nParam].nDevIndex = g_PRMemDBInterface.PRFindRecordbyKey(pPRBlock, pPRBlock->m_CommonFaultArray[nParam].nDevType, pPRBlock->m_CommonFaultArray[nParam].szDevName);
			}
		}
		g_PRMemDBInterface.PRMaint(pPRBlock);

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_CONVERTER]; nDev++)
		{
			for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
			{
				sprintf(szBuf, "%s%g", pPRBlock->m_ACBusArray[i].szName, pPRBlock->m_ACBusArray[i].fkV);
				if (_stricmp(szBuf, pPRBlock->m_ConverterArray[nDev].szACBus) == 0)
				{
					pPRBlock->m_ConverterArray[nDev].nACBus = i;
					break;
				}
			}

			for (i=0; i<pPRBlock->m_nRecordNum[PR_DCBUS]; i++)
			{
				if (_stricmp(pPRBlock->m_DCBusArray[i].szName, pPRBlock->m_ConverterArray[nDev].szDCBus) == 0)
				{
					pPRBlock->m_ConverterArray[nDev].nDCBus = i;
					break;
				}
			}
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_DCLINE]; nDev++)
		{
			for (i=0; i<pPRBlock->m_nRecordNum[PR_DCBUS]; i++)
			{
				if (_stricmp(pPRBlock->m_DCBusArray[i].szName, pPRBlock->m_DCLineArray[nDev].szDCBusI) == 0)
				{
					pPRBlock->m_DCLineArray[nDev].nDCBusI = i;
					break;
				}
			}

			for (i=0; i<pPRBlock->m_nRecordNum[PR_DCBUS]; i++)
			{
				if (_stricmp(pPRBlock->m_DCBusArray[i].szName, pPRBlock->m_DCLineArray[nDev].szDCBusJ) == 0)
				{
					pPRBlock->m_DCLineArray[nDev].nDCBusJ = i;
					break;
				}
			}
		}

		return 1;
	}

	void CBpaPRParam::SaveBpaPRParam(const char* lpszFileName, tagPRBlock* pPRBlock)
	{
		register int	i;
		int		nState, nDev;
		double	*pfRate, *pfProb, *pfFreq;
		char				szAttrName[260];
		TiXmlElement		*pElement, *pSubElement, *pRMState;
		TiXmlDocument*		pDocument = new TiXmlDocument();								//创建一个XML的文档对象。
		TiXmlDeclaration*	pDeclare = new TiXmlDeclaration("1.0","gb2312","no");	pDocument->LinkEndChild(pDeclare);
		TiXmlElement*		pRootElement = new TiXmlElement("BpaPRParam");			pDocument->LinkEndChild(pRootElement);

		pElement = new TiXmlElement("BpaPRParamCommon");
		pRootElement->LinkEndChild(pElement);
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_COMMRPARAM]; nDev++)
		{
			pSubElement = new TiXmlElement("Param");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("DevType",			g_PRMemDBInterface.PRGetTableName(pPRBlock->m_CommRParamArray[nDev].nDevType));
			pSubElement->SetAttribute("KeyWord",			pPRBlock->m_CommRParamArray[nDev].szKeyWord);
			pSubElement->SetDoubleAttribute("UpVLimit",		pPRBlock->m_CommRParamArray[nDev].fUpVLmt);
			pSubElement->SetDoubleAttribute("DnVLimit",		pPRBlock->m_CommRParamArray[nDev].fDnVLmt);
			pSubElement->SetDoubleAttribute("UpCapLimit",	pPRBlock->m_CommRParamArray[nDev].fUpCapLmt);
			pSubElement->SetDoubleAttribute("DnCapLimit",	pPRBlock->m_CommRParamArray[nDev].fDnCapLmt);
			pSubElement->SetDoubleAttribute("Rerr",			pPRBlock->m_CommRParamArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",			pPRBlock->m_CommRParamArray[nDev].fTrep);
		}

		pElement = new TiXmlElement("BpaPRParamDev");
		pRootElement->LinkEndChild(pElement);
		for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
		{
			pSubElement = new TiXmlElement("RParam");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("ParamType",	pPRBlock->m_ACBusArray[nDev].nRParamType);
			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(PR_ACBUS));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_ACBusArray[nDev].szName);
			pSubElement->SetDoubleAttribute("Rerr",	pPRBlock->m_ACBusArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",	pPRBlock->m_ACBusArray[nDev].fTrep);
		}

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
		{
			pSubElement = new TiXmlElement("RParam");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("ParamType",	pPRBlock->m_GeneratorArray[nDev].nRParamType);
			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(PR_GENERATOR));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_GeneratorArray[nDev].szName);
			pSubElement->SetDoubleAttribute("Rerr",	pPRBlock->m_GeneratorArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",	pPRBlock->m_GeneratorArray[nDev].fTrep);
			pSubElement->SetAttribute("Aux",		pPRBlock->m_GeneratorArray[nDev].bEQGen);
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_POWERLOAD]; nDev++)
		{
			pSubElement = new TiXmlElement("RParam");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("ParamType",	pPRBlock->m_PowerLoadArray[nDev].nRParamType);
			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(PR_POWERLOAD));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_PowerLoadArray[nDev].szName);
			pSubElement->SetDoubleAttribute("Rerr",	pPRBlock->m_PowerLoadArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",	pPRBlock->m_PowerLoadArray[nDev].fTrep);
			pSubElement->SetAttribute("Aux",		pPRBlock->m_PowerLoadArray[nDev].bEQLoad);
		}

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
		{
			if (pPRBlock->m_ACLineArray[nDev].fkVI > 300)
				continue;

			pSubElement = new TiXmlElement("RParam");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("ParamType",	pPRBlock->m_ACLineArray[nDev].nRParamType);
			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(PR_ACLINE));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_ACLineArray[nDev].szName);
			pSubElement->SetDoubleAttribute("Rerr",	pPRBlock->m_ACLineArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",	pPRBlock->m_ACLineArray[nDev].fTrep);
		}

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
		{
			if (pPRBlock->m_ACLineArray[nDev].fkVI <= 300)
				continue;

			pSubElement = new TiXmlElement("RParam");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("ParamType",	pPRBlock->m_ACLineArray[nDev].nRParamType);
			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(PR_ACLINE));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_ACLineArray[nDev].szName);
			pSubElement->SetDoubleAttribute("Rerr",	pPRBlock->m_ACLineArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",	pPRBlock->m_ACLineArray[nDev].fTrep);
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
		{
			if (max(pPRBlock->m_WindArray[nDev].fkVI, pPRBlock->m_WindArray[nDev].fkVJ) > 300)
				continue;

			pSubElement = new TiXmlElement("RParam");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("ParamType",	pPRBlock->m_WindArray[nDev].nRParamType);
			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(PR_WIND));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_WindArray[nDev].szName);
			pSubElement->SetDoubleAttribute("Rerr",	pPRBlock->m_WindArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",	pPRBlock->m_WindArray[nDev].fTrep);
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
		{
			if (max(pPRBlock->m_WindArray[nDev].fkVI, pPRBlock->m_WindArray[nDev].fkVJ) <= 300)
				continue;

			pSubElement = new TiXmlElement("RParam");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("ParamType",	pPRBlock->m_WindArray[nDev].nRParamType);
			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(PR_WIND));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_WindArray[nDev].szName);
			pSubElement->SetDoubleAttribute("Rerr",	pPRBlock->m_WindArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",	pPRBlock->m_WindArray[nDev].fTrep);
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
		{
			pSubElement = new TiXmlElement("RParam");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("ParamType",	pPRBlock->m_HVDCArray[nDev].nRParamType);
			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(PR_HVDC));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_HVDCArray[nDev].szName);
			pSubElement->SetDoubleAttribute("Rerr",	pPRBlock->m_HVDCArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",	pPRBlock->m_HVDCArray[nDev].fTrep);
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_TCSC]; nDev++)
		{
			pSubElement = new TiXmlElement("RParam");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("ParamType",	PRDevice_RParamType_Device);
			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(PR_TCSC));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_TCSCArray[nDev].szName);
			pSubElement->SetAttribute("SeriesBus",	pPRBlock->m_TCSCArray[nDev].szInstBus);
			pSubElement->SetDoubleAttribute("Rerr",	pPRBlock->m_TCSCArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",	pPRBlock->m_TCSCArray[nDev].fTrep);
			pSubElement->SetDoubleAttribute("Aux",	pPRBlock->m_TCSCArray[nDev].fX);
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_UPFC]; nDev++)
		{
			pSubElement = new TiXmlElement("RParam");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("ParamType",	PRDevice_RParamType_Device);
			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(PR_UPFC));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_UPFCArray[nDev].szName);
			pSubElement->SetAttribute("SeriesBus",	pPRBlock->m_UPFCArray[nDev].szSeriesBus);
			pSubElement->SetAttribute("ParallelBus",pPRBlock->m_UPFCArray[nDev].szParallelBus);
			pSubElement->SetDoubleAttribute("Rerr",	pPRBlock->m_UPFCArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",	pPRBlock->m_UPFCArray[nDev].fTrep);
			pSubElement->SetDoubleAttribute("Aux",	pPRBlock->m_UPFCArray[nDev].fCapacity);
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_CONVERTER]; nDev++)
		{
			pSubElement = new TiXmlElement("RParam");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("ParamType",	PRDevice_RParamType_Device);
			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(PR_CONVERTER));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_ConverterArray[nDev].szName);
			pSubElement->SetAttribute("ACBus",		pPRBlock->m_ConverterArray[nDev].szACBus);
			pSubElement->SetAttribute("DCBus",		pPRBlock->m_ConverterArray[nDev].szDCBus);
			pSubElement->SetAttribute("Type",		pPRBlock->m_ConverterArray[nDev].nType);
			pSubElement->SetDoubleAttribute("Rerr",	pPRBlock->m_ConverterArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",	pPRBlock->m_ConverterArray[nDev].fTrep);
			pSubElement->SetDoubleAttribute("Aux",	pPRBlock->m_ConverterArray[nDev].fConverterPower);
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_DCLINE]; nDev++)
		{
			pSubElement = new TiXmlElement("RParam");
			pElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute("ParamType",	PRDevice_RParamType_Device);
			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(PR_DCLINE));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_DCLineArray[nDev].szName);
			pSubElement->SetAttribute("DCBusI",		pPRBlock->m_DCLineArray[nDev].szDCBusI);
			pSubElement->SetAttribute("DCBusJ",		pPRBlock->m_DCLineArray[nDev].szDCBusJ);
			pSubElement->SetDoubleAttribute("Rerr",	pPRBlock->m_DCLineArray[nDev].fRerr);
			pSubElement->SetDoubleAttribute("Trep",	pPRBlock->m_DCLineArray[nDev].fTrep);
		}

		for (i=0; i<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; i++)
			pPRBlock->m_ManualFaultArray[i].bProc = 0;

		pElement = new TiXmlElement("BpaPRManualFault");
		pRootElement->LinkEndChild(pElement);
		for (nState=0; nState<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nState++)
		{
			if (pPRBlock->m_ManualFaultArray[nState].bProc)
				continue;

			pSubElement = new TiXmlElement("ManualFault");
			pElement->LinkEndChild(pSubElement);
			pSubElement->SetAttribute("FaultName",	pPRBlock->m_ManualFaultArray[nState].szName);
			for (nDev=nState; nDev<pPRBlock->m_nRecordNum[PR_MANUALFAULT]; nDev++)
			{
				if (stricmp(pPRBlock->m_ManualFaultArray[nState].szName, pPRBlock->m_ManualFaultArray[nDev].szName) != 0)
					continue;

				pPRBlock->m_ManualFaultArray[nDev].bProc = 1;

				pRMState = new TiXmlElement("FDev");
				pSubElement->LinkEndChild(pRMState);

				pRMState->SetAttribute("FDevType",	g_PRMemDBInterface.PRGetTableName(pPRBlock->m_ManualFaultArray[nDev].nFDevType));
				pRMState->SetAttribute("FDevName",	pPRBlock->m_ManualFaultArray[nDev].szFDevName);
			}
		}

		for (i=0; i<pPRBlock->m_nRecordNum[PR_COMMONFAULT]; i++)
			pPRBlock->m_CommonFaultArray[i].bProc = 0;

		pElement = new TiXmlElement("BpaPRCommonFault");
		pRootElement->LinkEndChild(pElement);
		for (nState=0; nState<pPRBlock->m_nRecordNum[PR_COMMONFAULT]; nState++)
		{
			if (pPRBlock->m_CommonFaultArray[nState].bProc)
				continue;

			pSubElement = new TiXmlElement("CommonFault");
			pElement->LinkEndChild(pSubElement);
			pSubElement->SetAttribute("CommonFaultName",	pPRBlock->m_CommonFaultArray[nState].szName);
			pSubElement->SetAttribute("CommonFaultType",	pPRBlock->m_CommonFaultArray[nState].nCommonFaultType);
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_COMMONFAULT]; nDev++)
			{
				if (stricmp(pPRBlock->m_CommonFaultArray[nState].szName, pPRBlock->m_CommonFaultArray[nDev].szName) != 0)
					continue;

				pRMState = new TiXmlElement("FaultDev");
				pSubElement->LinkEndChild(pRMState);

				pRMState->SetAttribute("DeviceCommonType",	pPRBlock->m_CommonFaultArray[nDev].nDeviceCommonType);
				pRMState->SetAttribute("DevType",			g_PRMemDBInterface.PRGetTableName(pPRBlock->m_CommonFaultArray[nDev].nDevType));
				pRMState->SetAttribute("DevName",			pPRBlock->m_CommonFaultArray[nDev].szDevName);
			}
		}

		pElement = new TiXmlElement("BpaPRParamMultState");
		pRootElement->LinkEndChild(pElement);
		for (nState=0; nState<pPRBlock->m_nRecordNum[PR_DEVMSTATE]; nState++)
		{
			pSubElement = new TiXmlElement("State");
			pElement->LinkEndChild(pSubElement);

			pfRate = &pPRBlock->m_DevMStateArray[nState].fState1Rate;
			pfProb = &pPRBlock->m_DevMStateArray[nState].fState1Prob;
			pfFreq = &pPRBlock->m_DevMStateArray[nState].fState1Freq1;

			pSubElement->SetAttribute("DevType",	g_PRMemDBInterface.PRGetTableName(pPRBlock->m_DevMStateArray[nState].nType));
			pSubElement->SetAttribute("KeyWord",	pPRBlock->m_DevMStateArray[nState].szName);
			pSubElement->SetAttribute("StateNum",	pPRBlock->m_DevMStateArray[nState].nStateNum);
			for (nDev=0; nDev<pPRBlock->m_DevMStateArray[nState].nStateNum; nDev++)
			{
				sprintf(szAttrName, "Rate%d", nDev+1);	pSubElement->SetDoubleAttribute(szAttrName,	pfRate[nDev]);
				sprintf(szAttrName, "Prob%d", nDev+1);	pSubElement->SetDoubleAttribute(szAttrName,	pfProb[nDev]);
				for (i=0; i<pPRBlock->m_DevMStateArray[nState].nStateNum; i++)
				{
					sprintf(szAttrName, "Freq%d.%d", nDev+1, i+1);	
					pSubElement->SetDoubleAttribute(szAttrName,	pfFreq[nDev*pPRBlock->m_DevMStateArray[nState].nStateNum+i]);
				}
			}
		}

		pDocument->SaveFile(lpszFileName);		//保存到文件
		pDocument->Clear();
		delete pDocument;
	}

	int	CBpaPRParam::SetBpaPRComParam(tagPRBlock* pPRBlock, const int nTable, const char* lpszKey)
	{
		double	fBuffer;
		int		nParam, nDevice = -1;
		if (nTable == PR_ACBUS)
			nDevice = FindPRACBus(pPRBlock, lpszKey);
		else
			nDevice = g_PRMemDBInterface.PRFindRecordbyKey(pPRBlock, nTable, lpszKey);
		if (nDevice < 0)
			return 0;

		for (nParam=0; nParam<pPRBlock->m_nRecordNum[PR_COMMRPARAM]; nParam++)
		{
			if (_stricmp(pPRBlock->m_CommRParamArray[nParam].szKeyWord, "ALL") != 0)
				continue;
			if (pPRBlock->m_CommRParamArray[nParam].nDevType != nTable)
				continue;

			switch (pPRBlock->m_CommRParamArray[nParam].nDevType)
			{
			case	PR_ACBUS:
				pPRBlock->m_ACBusArray[nDevice].nRParamType = PRDevice_RParamType_Common;
				if (pPRBlock->m_CommRParamArray[nParam].fDnVLmt <= pPRBlock->m_ACBusArray[nDevice].fkV && pPRBlock->m_ACBusArray[nDevice].fkV < pPRBlock->m_CommRParamArray[nParam].fUpVLmt)
				{
					pPRBlock->m_ACBusArray[nDevice].fRerr=(float)(pPRBlock->m_CommRParamArray[nParam].fRerr/100.0);	//	单位为百台年
					pPRBlock->m_ACBusArray[nDevice].fTrep=(float)pPRBlock->m_CommRParamArray[nParam].fTrep;
					if (pPRBlock->m_CommRParamArray[nParam].fTrep > FLT_MIN)	pPRBlock->m_ACBusArray[nDevice].fRrep=(float)(8760.0/pPRBlock->m_CommRParamArray[nParam].fTrep);
				}
				break;
			case	PR_GENERATOR:
				pPRBlock->m_GeneratorArray[nDevice].nRParamType = PRDevice_RParamType_Common;
				if (pPRBlock->m_CommRParamArray[nParam].fDnCapLmt <= pPRBlock->m_GeneratorArray[nDevice].fPMax && pPRBlock->m_GeneratorArray[nDevice].fPMax < pPRBlock->m_CommRParamArray[nParam].fUpCapLmt &&
					pPRBlock->m_CommRParamArray[nParam].fDnVLmt <= pPRBlock->m_GeneratorArray[nDevice].fkV && pPRBlock->m_GeneratorArray[nDevice].fkV < pPRBlock->m_CommRParamArray[nParam].fUpVLmt)
				{
					pPRBlock->m_GeneratorArray[nDevice].fRerr=(float)(pPRBlock->m_CommRParamArray[nParam].fRerr/100.0);	//	单位为百台年
					pPRBlock->m_GeneratorArray[nDevice].fTrep=(float)pPRBlock->m_CommRParamArray[nParam].fTrep;
					if (pPRBlock->m_CommRParamArray[nParam].fTrep > FLT_MIN)	pPRBlock->m_GeneratorArray[nDevice].fRrep=(float)(8760.0/pPRBlock->m_CommRParamArray[nParam].fTrep);
				}
				break;
			case	PR_ACLINE:
				pPRBlock->m_ACLineArray[nDevice].nRParamType = PRDevice_RParamType_Common;
				if (pPRBlock->m_CommRParamArray[nParam].fDnVLmt <= pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDevice].nIBus].fkV && pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDevice].nIBus].fkV < pPRBlock->m_CommRParamArray[nParam].fUpVLmt)
				{
					if (pPRBlock->m_ACLineArray[nDevice].fLength > FLT_MIN)	//	可靠性参数为百公里
						pPRBlock->m_ACLineArray[nDevice].fRerr=pPRBlock->m_CommRParamArray[nParam].fRerr*pPRBlock->m_ACLineArray[nDevice].fLength/100;
					else
						pPRBlock->m_ACLineArray[nDevice].fRerr=pPRBlock->m_CommRParamArray[nParam].fRerr;
					pPRBlock->m_ACLineArray[nDevice].fTrep=pPRBlock->m_CommRParamArray[nParam].fTrep;
					if (pPRBlock->m_CommRParamArray[nParam].fTrep > FLT_MIN)	pPRBlock->m_ACLineArray[nDevice].fRrep=(float)(8760.0/pPRBlock->m_CommRParamArray[nParam].fTrep);
				}
				break;
			case	PR_WIND:
				pPRBlock->m_WindArray[nDevice].nRParamType = PRDevice_RParamType_Common;
				fBuffer=max(pPRBlock->m_ACBusArray[pPRBlock->m_WindArray[nDevice].nIBus].fkV, pPRBlock->m_ACBusArray[pPRBlock->m_WindArray[nDevice].nZBus].fkV);
				if (pPRBlock->m_CommRParamArray[nParam].fDnVLmt <= fBuffer && fBuffer < pPRBlock->m_CommRParamArray[nParam].fUpVLmt)
				{
					pPRBlock->m_WindArray[nDevice].fRerr=pPRBlock->m_CommRParamArray[nParam].fRerr/100;	//	可靠性参数为百台
					pPRBlock->m_WindArray[nDevice].fTrep=pPRBlock->m_CommRParamArray[nParam].fTrep;
					if (pPRBlock->m_CommRParamArray[nParam].fTrep > FLT_MIN)	pPRBlock->m_WindArray[nDevice].fRrep=(float)(8760.0/pPRBlock->m_CommRParamArray[nParam].fTrep);
				}
				break;
			case	PR_HVDC:
				pPRBlock->m_HVDCArray[nDevice].nRParamType = PRDevice_RParamType_Common;
				if (pPRBlock->m_CommRParamArray[nParam].fDnVLmt <= pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDevice].nIBus].fkV &&
					pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDevice].nIBus].fkV < pPRBlock->m_CommRParamArray[nParam].fUpVLmt)
				{
					if (pPRBlock->m_HVDCArray[nDevice].fLength > FLT_MIN)	//	可靠性参数为百公里
						pPRBlock->m_HVDCArray[nDevice].fRerr=pPRBlock->m_CommRParamArray[nParam].fRerr*pPRBlock->m_HVDCArray[nDevice].fLength/100;
					else
						pPRBlock->m_HVDCArray[nDevice].fRerr=pPRBlock->m_CommRParamArray[nParam].fRerr*10;	//	直流线路缺省按1000公里计
					pPRBlock->m_HVDCArray[nDevice].fTrep=pPRBlock->m_CommRParamArray[nParam].fTrep;
					if (pPRBlock->m_CommRParamArray[nParam].fTrep > FLT_MIN)	pPRBlock->m_HVDCArray[nDevice].fRrep=(float)(8760.0/pPRBlock->m_CommRParamArray[nParam].fTrep);
				}
				break;
			}
		}

		for (nParam=0; nParam<(int)pPRBlock->m_nRecordNum[PR_COMMRPARAM]; nParam++)
		{
			if (_stricmp(pPRBlock->m_CommRParamArray[nParam].szKeyWord, "ALL") == 0)
				continue;
			if (pPRBlock->m_CommRParamArray[nParam].nDevType != nTable)
				continue;

			switch (pPRBlock->m_CommRParamArray[nParam].nDevType)
			{
			case	PR_ACBUS:
				pPRBlock->m_ACBusArray[nDevice].nRParamType = PRDevice_RParamType_Common;
				if (pPRBlock->m_CommRParamArray[nParam].fDnVLmt <= pPRBlock->m_ACBusArray[nDevice].fkV && pPRBlock->m_ACBusArray[nDevice].fkV < pPRBlock->m_CommRParamArray[nParam].fUpVLmt)
				{
					pPRBlock->m_ACBusArray[nDevice].fRerr=(float)(pPRBlock->m_CommRParamArray[nParam].fRerr/100.0);	//	单位为百台年
					pPRBlock->m_ACBusArray[nDevice].fTrep=(float)pPRBlock->m_CommRParamArray[nParam].fTrep;
					if (pPRBlock->m_CommRParamArray[nParam].fTrep > FLT_MIN)	pPRBlock->m_ACBusArray[nDevice].fRrep=(float)(8760.0/pPRBlock->m_CommRParamArray[nParam].fTrep);
				}
				break;
			case	PR_GENERATOR:
				pPRBlock->m_GeneratorArray[nDevice].nRParamType = PRDevice_RParamType_Common;
				if (pPRBlock->m_CommRParamArray[nParam].fDnCapLmt <= pPRBlock->m_GeneratorArray[nDevice].fPMax && pPRBlock->m_GeneratorArray[nDevice].fPMax < pPRBlock->m_CommRParamArray[nParam].fUpCapLmt &&
					pPRBlock->m_CommRParamArray[nParam].fDnVLmt <= pPRBlock->m_GeneratorArray[nDevice].fkV && pPRBlock->m_GeneratorArray[nDevice].fkV < pPRBlock->m_CommRParamArray[nParam].fUpVLmt)
				{
					pPRBlock->m_GeneratorArray[nDevice].fRerr=(float)(pPRBlock->m_CommRParamArray[nParam].fRerr/100.0);	//	单位为百台年
					pPRBlock->m_GeneratorArray[nDevice].fTrep=(float)pPRBlock->m_CommRParamArray[nParam].fTrep;
					if (pPRBlock->m_CommRParamArray[nParam].fTrep > FLT_MIN)	pPRBlock->m_GeneratorArray[nDevice].fRrep=(float)(8760.0/pPRBlock->m_CommRParamArray[nParam].fTrep);
				}
				break;
			case	PR_ACLINE:
				pPRBlock->m_ACLineArray[nDevice].nRParamType = PRDevice_RParamType_Common;
				if (pPRBlock->m_CommRParamArray[nParam].fDnVLmt <= pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDevice].nIBus].fkV && pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDevice].nIBus].fkV < pPRBlock->m_CommRParamArray[nParam].fUpVLmt)
				{
					if (pPRBlock->m_ACLineArray[nDevice].fLength > FLT_MIN)	//	可靠性参数为百公里
						pPRBlock->m_ACLineArray[nDevice].fRerr=pPRBlock->m_CommRParamArray[nParam].fRerr*pPRBlock->m_ACLineArray[nDevice].fLength/100;
					else
						pPRBlock->m_ACLineArray[nDevice].fRerr=pPRBlock->m_CommRParamArray[nParam].fRerr;
					pPRBlock->m_ACLineArray[nDevice].fTrep=pPRBlock->m_CommRParamArray[nParam].fTrep;
					if (pPRBlock->m_CommRParamArray[nParam].fTrep > FLT_MIN)	pPRBlock->m_ACLineArray[nDevice].fRrep=(float)(8760.0/pPRBlock->m_CommRParamArray[nParam].fTrep);
				}
				break;
			case	PR_WIND:
				pPRBlock->m_WindArray[nDevice].nRParamType = PRDevice_RParamType_Common;
				fBuffer=max(pPRBlock->m_ACBusArray[pPRBlock->m_WindArray[nDevice].nIBus].fkV, pPRBlock->m_ACBusArray[pPRBlock->m_WindArray[nDevice].nZBus].fkV);
				if (pPRBlock->m_CommRParamArray[nParam].fDnVLmt <= fBuffer && fBuffer < pPRBlock->m_CommRParamArray[nParam].fUpVLmt)
				{
					pPRBlock->m_WindArray[nDevice].fRerr=pPRBlock->m_CommRParamArray[nParam].fRerr/100;	//	可靠性参数为百台
					pPRBlock->m_WindArray[nDevice].fTrep=pPRBlock->m_CommRParamArray[nParam].fTrep;
					if (pPRBlock->m_CommRParamArray[nParam].fTrep > FLT_MIN)	pPRBlock->m_WindArray[nDevice].fRrep=(float)(8760.0/pPRBlock->m_CommRParamArray[nParam].fTrep);
				}
				break;
			case	PR_HVDC:
				pPRBlock->m_HVDCArray[nDevice].nRParamType = PRDevice_RParamType_Common;
				if (pPRBlock->m_CommRParamArray[nParam].fDnVLmt <= pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDevice].nIBus].fkV &&
					pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDevice].nIBus].fkV < pPRBlock->m_CommRParamArray[nParam].fUpVLmt)
				{
					if (pPRBlock->m_HVDCArray[nDevice].fLength > FLT_MIN)	//	可靠性参数为百公里
						pPRBlock->m_HVDCArray[nDevice].fRerr=pPRBlock->m_CommRParamArray[nParam].fRerr*pPRBlock->m_HVDCArray[nDevice].fLength/100;
					else
						pPRBlock->m_HVDCArray[nDevice].fRerr=pPRBlock->m_CommRParamArray[nParam].fRerr;
					pPRBlock->m_HVDCArray[nDevice].fTrep=pPRBlock->m_CommRParamArray[nParam].fTrep;
					if (pPRBlock->m_CommRParamArray[nParam].fTrep > FLT_MIN)	pPRBlock->m_HVDCArray[nDevice].fRrep=(float)(8760.0/pPRBlock->m_CommRParamArray[nParam].fTrep);
				}
				break;
			}
		}

		return 1;
	}

	void CBpaPRParam::SetPRParam_Comm(tagPRBlock* pPRBlock, const unsigned char nDevType, const char* lpszKeyWord, const double fDnP, const double fUpP, const double fDnV, const double fUpV, const double fRerr, const double fTrep)
	{
		int		nDev;
		double	fBuffer;

		if (nDevType == PR_ACBUS)
		{
			for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
			{
				if (pPRBlock->m_ACBusArray[nDev].fkV < fDnV || pPRBlock->m_ACBusArray[nDev].fkV >= fUpV)
					continue;

				if (_stricmp(lpszKeyWord, "ALL") == 0 || _stricmp(pPRBlock->m_ACBusArray[nDev].szZone, lpszKeyWord) == 0)
				{
					pPRBlock->m_ACBusArray[nDev].fRerr=(float)(fRerr/100.0);	//	单位为百台年
					pPRBlock->m_ACBusArray[nDev].fTrep=(float)fTrep;
					if (fTrep > FLT_MIN)	pPRBlock->m_ACBusArray[nDev].fRrep=(float)(8760.0/fTrep);
					pPRBlock->m_ACBusArray[nDev].nRParamType = PRDevice_RParamType_Common;
				}
			}
		}
		else if (nDevType == PR_GENERATOR)
		{
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
			{
				if (pPRBlock->m_GeneratorArray[nDev].fPMax < fDnP || pPRBlock->m_GeneratorArray[nDev].fPMax >= fUpP)
					continue;
				if (pPRBlock->m_GeneratorArray[nDev].fkV < fDnV || pPRBlock->m_GeneratorArray[nDev].fkV >= fUpV)
					continue;

				if (_stricmp(lpszKeyWord, "ALL") == 0 || _stricmp(pPRBlock->m_GeneratorArray[nDev].szZone, lpszKeyWord) == 0)
				{
					pPRBlock->m_GeneratorArray[nDev].fRerr=(float)(fRerr/100.0);	//	单位为百台年
					pPRBlock->m_GeneratorArray[nDev].fTrep=(float)fTrep;
					if (fTrep > FLT_MIN)	pPRBlock->m_GeneratorArray[nDev].fRrep=(float)(8760.0/fTrep);
					pPRBlock->m_GeneratorArray[nDev].nRParamType = PRDevice_RParamType_Common;
				}
			}
		}
		else if (nDevType == PR_POWERLOAD)
		{
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_POWERLOAD]; nDev++)
			{
				if (pPRBlock->m_PowerLoadArray[nDev].fPMax < fDnP || pPRBlock->m_PowerLoadArray[nDev].fPMax >= fUpP)
					continue;
				if (pPRBlock->m_PowerLoadArray[nDev].fkV < fDnV || pPRBlock->m_PowerLoadArray[nDev].fkV >= fUpV)
					continue;

				if (_stricmp(lpszKeyWord, "ALL") == 0 || _stricmp(pPRBlock->m_PowerLoadArray[nDev].szZone, lpszKeyWord) == 0)
				{
					pPRBlock->m_PowerLoadArray[nDev].fRerr=(float)(fRerr/100.0);	//	单位为百台年
					pPRBlock->m_PowerLoadArray[nDev].fTrep=(float)fTrep;
					if (fTrep > FLT_MIN)	pPRBlock->m_PowerLoadArray[nDev].fRrep=(float)(8760.0/fTrep);
					pPRBlock->m_PowerLoadArray[nDev].nRParamType = PRDevice_RParamType_Common;
				}
			}
		}
		else if (nDevType == PR_ACLINE)
		{
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
			{
				if (pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDev].nIBus].fkV < fDnV ||
					pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDev].nIBus].fkV >= fUpV)
					continue;
				if (sqrt(pPRBlock->m_ACLineArray[nDev].fR*pPRBlock->m_ACLineArray[nDev].fR + pPRBlock->m_ACLineArray[nDev].fX*pPRBlock->m_ACLineArray[nDev].fX) < 0.00012)
					continue;

				if (_stricmp(lpszKeyWord, "ALL") == 0 || (_stricmp(pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDev].nIBus].szZone, lpszKeyWord) == 0 || _stricmp(pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDev].nZBus].szZone, lpszKeyWord) == 0))
				{
					if (pPRBlock->m_ACLineArray[nDev].fLength > FLT_MIN)	//	可靠性参数为百公里
						pPRBlock->m_ACLineArray[nDev].fRerr=fRerr*pPRBlock->m_ACLineArray[nDev].fLength/100;
					else
						pPRBlock->m_ACLineArray[nDev].fRerr=fRerr;
					pPRBlock->m_ACLineArray[nDev].fTrep=fTrep;
					if (fTrep > FLT_MIN)	pPRBlock->m_ACLineArray[nDev].fRrep=(float)(8760.0/fTrep);
					pPRBlock->m_ACLineArray[nDev].nRParamType = PRDevice_RParamType_Common;
				}
			}
		}
		else if (nDevType == PR_WIND)
		{
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
			{
				fBuffer=max(pPRBlock->m_ACBusArray[pPRBlock->m_WindArray[nDev].nIBus].fkV, pPRBlock->m_ACBusArray[pPRBlock->m_WindArray[nDev].nZBus].fkV);
				if (fBuffer < fDnV || fBuffer >= fUpV)
					continue;

				if (_stricmp(lpszKeyWord, "ALL") == 0 || (_stricmp(pPRBlock->m_ACBusArray[pPRBlock->m_WindArray[nDev].nIBus].szZone, lpszKeyWord) == 0 || _stricmp(pPRBlock->m_ACBusArray[pPRBlock->m_WindArray[nDev].nZBus].szZone, lpszKeyWord) == 0))
				{
					pPRBlock->m_WindArray[nDev].fRerr=fRerr/100;	//	可靠性参数为百台
					pPRBlock->m_WindArray[nDev].fTrep=fTrep;
					if (fTrep > FLT_MIN)	pPRBlock->m_WindArray[nDev].fRrep=(float)(8760.0/fTrep);
					pPRBlock->m_WindArray[nDev].nRParamType = PRDevice_RParamType_Common;
				}
			}
		}
		else if (nDevType == PR_HVDC)
		{
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
			{
				if (pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nIBus].fkV < fDnV ||
					pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nIBus].fkV >= fUpV)
					continue;

				if (_stricmp(lpszKeyWord, "ALL") == 0 ||
					(_stricmp(pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nRBus].szZone, lpszKeyWord) == 0 ||
					_stricmp(pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nIBus].szZone, lpszKeyWord) == 0))
				{
					if (pPRBlock->m_HVDCArray[nDev].fLength > FLT_MIN)	//	可靠性参数为百公里
						pPRBlock->m_HVDCArray[nDev].fRerr=fRerr*pPRBlock->m_HVDCArray[nDev].fLength/100;
					else
						pPRBlock->m_HVDCArray[nDev].fRerr=fRerr;
					pPRBlock->m_HVDCArray[nDev].fTrep=fTrep;
					if (fTrep > FLT_MIN)	pPRBlock->m_HVDCArray[nDev].fRrep=(float)(8760.0/fTrep);
					pPRBlock->m_HVDCArray[nDev].nRParamType = PRDevice_RParamType_Common;
				}
			}
		}
	}

	void CBpaPRParam::SetPRParam_Dev(tagPRBlock* pPRBlock, const unsigned char nDevType, const char* lpszName, const double fRerr, const double fTrep, const double fAux)
	{
		int		nDev;
		if (nDevType == PR_ACBUS)
		{
			nDev=FindPRACBus(pPRBlock, lpszName);
			if (nDev >= 0)
			{
				pPRBlock->m_ACBusArray[nDev].fRerr=(float)fRerr;	//	单位为台年
				pPRBlock->m_ACBusArray[nDev].fTrep=(float)fTrep;
				if (fTrep > FLT_MIN)	pPRBlock->m_ACBusArray[nDev].fRrep=(float)(8760.0/fTrep);
				pPRBlock->m_ACBusArray[nDev].nRParamType = PRDevice_RParamType_Device;
			}
		}
		else if (nDevType == PR_GENERATOR)
		{
			nDev=g_PRMemDBInterface.PRFindRecordbyKey(pPRBlock, nDevType, lpszName);
			if (nDev >= 0)
			{
				pPRBlock->m_GeneratorArray[nDev].fRerr=(float)fRerr;	//	单位为台年
				pPRBlock->m_GeneratorArray[nDev].fTrep=(float)fTrep;
				if (fTrep > FLT_MIN)	pPRBlock->m_GeneratorArray[nDev].fRrep=(float)(8760.0/fTrep);
				pPRBlock->m_GeneratorArray[nDev].nRParamType = PRDevice_RParamType_Device;
				pPRBlock->m_GeneratorArray[nDev].bEQGen = (unsigned char)fAux;
			}
		}
		else if (nDevType == PR_POWERLOAD)
		{
			nDev=g_PRMemDBInterface.PRFindRecordbyKey(pPRBlock, nDevType, lpszName);
			if (nDev >= 0)
			{
				pPRBlock->m_PowerLoadArray[nDev].fRerr=(float)fRerr;	//	单位为台年
				pPRBlock->m_PowerLoadArray[nDev].fTrep=(float)fTrep;
				if (fTrep > FLT_MIN)	pPRBlock->m_PowerLoadArray[nDev].fRrep=(float)(8760.0/fTrep);
				pPRBlock->m_PowerLoadArray[nDev].nRParamType = PRDevice_RParamType_Device;
				pPRBlock->m_PowerLoadArray[nDev].bEQLoad = (unsigned char)fAux;
			}
		}
		else if (nDevType == PR_ACLINE)
		{
			nDev=g_PRMemDBInterface.PRFindRecordbyKey(pPRBlock, nDevType, lpszName);
			if (nDev >= 0)
			{
				pPRBlock->m_ACLineArray[nDev].fRerr=fRerr;	//	可靠性具体设备参数为实际使用参数
				pPRBlock->m_ACLineArray[nDev].fTrep=fTrep;
				if (fTrep > FLT_MIN)	pPRBlock->m_ACLineArray[nDev].fRrep=(float)(8760.0/fTrep);
				pPRBlock->m_ACLineArray[nDev].nRParamType = PRDevice_RParamType_Device;
				return;
			}
		}
		else if (nDevType == PR_WIND)
		{
			nDev=g_PRMemDBInterface.PRFindRecordbyKey(pPRBlock, nDevType, lpszName);
			if (nDev >= 0)
			{
				pPRBlock->m_WindArray[nDev].fRerr=fRerr;	//	可靠性具体设备参数为实际使用参数
				pPRBlock->m_WindArray[nDev].fTrep=fTrep;
				if (fTrep > FLT_MIN)	pPRBlock->m_WindArray[nDev].fRrep=(float)(8760.0/fTrep);
				pPRBlock->m_WindArray[nDev].nRParamType = PRDevice_RParamType_Device;
				return;
			}
		}
		else if (nDevType == PR_HVDC)
		{
			nDev=g_PRMemDBInterface.PRFindRecordbyKey(pPRBlock, nDevType, lpszName);
			if (nDev >= 0)
			{
				pPRBlock->m_HVDCArray[nDev].fRerr=fRerr;	//	可靠性具体设备参数为实际使用参数
				pPRBlock->m_HVDCArray[nDev].fTrep=fTrep;
				if (fTrep > FLT_MIN)	pPRBlock->m_HVDCArray[nDev].fRrep=(float)(8760.0/fTrep);
				pPRBlock->m_HVDCArray[nDev].nRParamType = PRDevice_RParamType_Device;
				return;
			}
		}
	}

	void CBpaPRParam::SetPRParam_Dev(tagPRBlock* pPRBlock, const unsigned char nDevType, const char* lpszName, const char* lpszDevBusName, const char* lpszAuxBusName, const double fRerr, const double fTrep, const double fAux, const int nAuxType)
	{
		int		nDev;
		char	szBuf[260];
		if (nDevType == PR_TCSC)
		{
			nDev=FindPRTCSC(pPRBlock, lpszName);
			if (nDev >= 0)
			{
				strcpy(pPRBlock->m_TCSCArray[nDev].szInstBus, lpszDevBusName);
				pPRBlock->m_TCSCArray[nDev].fRerr=fRerr;	//	可靠性具体设备参数为实际使用参数
				pPRBlock->m_TCSCArray[nDev].fTrep=fTrep;
				pPRBlock->m_TCSCArray[nDev].fX=(float)fAux;
				if (fTrep > FLT_MIN)	pPRBlock->m_TCSCArray[nDev].fRrep=(float)(8760.0/fTrep);
				return;
			}
			else
			{
				if (pPRBlock->m_nRecordNum[PR_TCSC] < g_PRMemDBInterface.PRGetTableMax(PR_TCSC)-1)
				{
					memset(&pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]], 0, sizeof(tagPRTCSC));
					strcpy(pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].szName, lpszName);
					strcpy(pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].szInstBus, lpszDevBusName);
					pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].fRerr = fRerr;
					pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].fTrep = fTrep;
					pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].fX = (float)fAux;
					pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].nInstBus = -1;
					pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].nACLine = -1;

					for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
					{
						sprintf(szBuf, "%s%g", pPRBlock->m_ACBusArray[nDev].szName, pPRBlock->m_ACBusArray[nDev].fkV);
						if (_stricmp(szBuf, pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].szInstBus) == 0)
						{
							pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].nInstBus = nDev;
							break;
						}
					}
					for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
					{
						if (_stricmp(pPRBlock->m_ACLineArray[nDev].szName, pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].szName) == 0)
						{
							pPRBlock->m_TCSCArray[pPRBlock->m_nRecordNum[PR_TCSC]].nACLine = nDev;
							pPRBlock->m_ACLineArray[nDev].nTCSCIndex = pPRBlock->m_nRecordNum[PR_TCSC];
							break;
						}
					}

					pPRBlock->m_nRecordNum[PR_TCSC]++;
				}
				else
					log_error("        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_TCSC));
			}
		}
		else if (nDevType == PR_UPFC)
		{
			nDev=FindPRUPFC(pPRBlock, lpszName);
			if (nDev >= 0)
			{
				strcpy(pPRBlock->m_UPFCArray[nDev].szSeriesBus, lpszDevBusName);
				strcpy(pPRBlock->m_UPFCArray[nDev].szParallelBus, lpszAuxBusName);
				pPRBlock->m_UPFCArray[nDev].fRerr=fRerr;	//	可靠性具体设备参数为实际使用参数
				pPRBlock->m_UPFCArray[nDev].fTrep=fTrep;
				pPRBlock->m_UPFCArray[nDev].fCapacity=(float)fAux;
				if (fTrep > FLT_MIN)	pPRBlock->m_UPFCArray[nDev].fRrep=(float)(8760.0/fTrep);
				return;
			}
			else
			{
				if (pPRBlock->m_nRecordNum[PR_UPFC] < g_PRMemDBInterface.PRGetTableMax(PR_UPFC)-1)
				{
					memset(&pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]], 0, sizeof(tagPRUPFC));
					strcpy(pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].szName, lpszName);
					strcpy(pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].szSeriesBus, lpszDevBusName);
					strcpy(pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].szParallelBus, lpszAuxBusName);
					pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].fRerr = fRerr;
					pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].fTrep = fTrep;
					pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].fCapacity = (float)fAux;
					pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].nSeriesBus = -1;
					pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].nParallelBus = -1;
					pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].nACLine = -1;

					for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
					{
						sprintf(szBuf, "%s%g", pPRBlock->m_ACBusArray[nDev].szName, pPRBlock->m_ACBusArray[nDev].fkV);
						if (_stricmp(szBuf, pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].szSeriesBus) == 0)
						{
							pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].nSeriesBus = nDev;
							break;
						}
					}
					for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
					{
						sprintf(szBuf, "%s%g", pPRBlock->m_ACBusArray[nDev].szName, pPRBlock->m_ACBusArray[nDev].fkV);
						if (_stricmp(szBuf, pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].szParallelBus) == 0)
						{
							pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].nParallelBus = nDev;
							break;
						}
					}
					for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
					{
						if (_stricmp(pPRBlock->m_ACLineArray[nDev].szName, pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].szName) == 0)
						{
							pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].nACLine = nDev;
							pPRBlock->m_ACLineArray[nDev].nUPFCIndex = pPRBlock->m_nRecordNum[PR_UPFC];

							if (pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].nSeriesBus == pPRBlock->m_ACLineArray[nDev].nIBus)	//	线路I侧是串联侧
								pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].fLinePse=-pPRBlock->m_ACLineArray[nDev].fRtPi;
							else
								pPRBlock->m_UPFCArray[pPRBlock->m_nRecordNum[PR_UPFC]].fLinePse=pPRBlock->m_ACLineArray[nDev].fRtPi;
							break;
						}
					}

					pPRBlock->m_nRecordNum[PR_UPFC]++;
				}
				else
					log_error("        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_UPFC));
			}
		}
		else if (nDevType == PR_CONVERTER)
		{
			nDev=FindPRConverter(pPRBlock, lpszName);
			if (nDev >= 0)
			{
				strcpy(pPRBlock->m_ConverterArray[nDev].szACBus, lpszDevBusName);
				strcpy(pPRBlock->m_ConverterArray[nDev].szDCBus, lpszDevBusName);
				pPRBlock->m_ConverterArray[nDev].fRerr = fRerr;	//	可靠性具体设备参数为实际使用参数
				pPRBlock->m_ConverterArray[nDev].fTrep = fTrep;
				pPRBlock->m_ConverterArray[nDev].fConverterPower = (float)fAux;
				pPRBlock->m_ConverterArray[nDev].nType = nAuxType;
				if (fTrep > FLT_MIN)	pPRBlock->m_ConverterArray[nDev].fRrep = (float)(8760.0/fTrep);
				return;
			}
			else
			{
				if (pPRBlock->m_nRecordNum[PR_CONVERTER] < g_PRMemDBInterface.PRGetTableMax(PR_CONVERTER)-1)
				{
					memset(&pPRBlock->m_ConverterArray[pPRBlock->m_nRecordNum[PR_CONVERTER]], 0, sizeof(tagPRConverter));
					strcpy(pPRBlock->m_ConverterArray[pPRBlock->m_nRecordNum[PR_CONVERTER]].szName, lpszName);
					strcpy(pPRBlock->m_ConverterArray[pPRBlock->m_nRecordNum[PR_CONVERTER]].szACBus, lpszDevBusName);
					strcpy(pPRBlock->m_ConverterArray[pPRBlock->m_nRecordNum[PR_CONVERTER]].szDCBus, lpszDevBusName);
					pPRBlock->m_ConverterArray[pPRBlock->m_nRecordNum[PR_CONVERTER]].fRerr = fRerr;
					pPRBlock->m_ConverterArray[pPRBlock->m_nRecordNum[PR_CONVERTER]].fTrep = fTrep;
					pPRBlock->m_ConverterArray[pPRBlock->m_nRecordNum[PR_CONVERTER]].fConverterPower = (float)fAux;
					pPRBlock->m_ConverterArray[pPRBlock->m_nRecordNum[PR_CONVERTER]].nType = nAuxType;
					pPRBlock->m_ConverterArray[pPRBlock->m_nRecordNum[PR_CONVERTER]].nACBus = -1;
					pPRBlock->m_ConverterArray[pPRBlock->m_nRecordNum[PR_CONVERTER]].nDCBus = -1;

					pPRBlock->m_nRecordNum[PR_CONVERTER]++;
				}
				else
					log_error("        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_CONVERTER));

				if (pPRBlock->m_nRecordNum[PR_DCBUS] < g_PRMemDBInterface.PRGetTableMax(PR_DCBUS)-1)
				{
					memset(&pPRBlock->m_DCBusArray[pPRBlock->m_nRecordNum[PR_DCBUS]], 0, sizeof(tagPRDCBus));
					strcpy(pPRBlock->m_DCBusArray[pPRBlock->m_nRecordNum[PR_DCBUS]].szName, lpszDevBusName);
					pPRBlock->m_nRecordNum[PR_DCBUS]++;
				}
				else
					log_error("        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_DCBUS));
			}
		}
		else if (nDevType == PR_DCLINE)
		{
			nDev=FindPRDCLine(pPRBlock, lpszName);
			if (nDev >= 0)
			{
				strcpy(pPRBlock->m_DCLineArray[nDev].szDCBusI, lpszDevBusName);
				strcpy(pPRBlock->m_DCLineArray[nDev].szDCBusJ, lpszAuxBusName);
				pPRBlock->m_DCLineArray[nDev].fRerr=fRerr;	//	可靠性具体设备参数为实际使用参数
				pPRBlock->m_DCLineArray[nDev].fTrep=fTrep;
				if (fTrep > FLT_MIN)	pPRBlock->m_DCLineArray[nDev].fRrep=(float)(8760.0/fTrep);
				return;
			}
			else
			{
				if (pPRBlock->m_nRecordNum[PR_DCLINE] < g_PRMemDBInterface.PRGetTableMax(PR_DCLINE)-1)
				{
					memset(&pPRBlock->m_DCLineArray[pPRBlock->m_nRecordNum[PR_DCLINE]], 0, sizeof(tagPRDCLine));
					strcpy(pPRBlock->m_DCLineArray[pPRBlock->m_nRecordNum[PR_DCLINE]].szName, lpszName);
					strcpy(pPRBlock->m_DCLineArray[pPRBlock->m_nRecordNum[PR_DCLINE]].szDCBusI, lpszDevBusName);
					strcpy(pPRBlock->m_DCLineArray[pPRBlock->m_nRecordNum[PR_DCLINE]].szDCBusJ, lpszAuxBusName);
					pPRBlock->m_DCLineArray[pPRBlock->m_nRecordNum[PR_DCLINE]].fRerr = fRerr;
					pPRBlock->m_DCLineArray[pPRBlock->m_nRecordNum[PR_DCLINE]].fTrep = fTrep;
					pPRBlock->m_DCLineArray[pPRBlock->m_nRecordNum[PR_DCLINE]].nDCBusI = -1;
					pPRBlock->m_DCLineArray[pPRBlock->m_nRecordNum[PR_DCLINE]].nDCBusJ = -1;

					pPRBlock->m_nRecordNum[PR_DCLINE]++;
				}
				else
					log_error("        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_DCLINE));
			}
		}
	}
}
