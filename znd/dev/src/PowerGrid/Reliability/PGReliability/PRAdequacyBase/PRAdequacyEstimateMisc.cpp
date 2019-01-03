#include <process.h>
#include "PRAdequacyEstimate.h"
#include "../../../../Common/TinyXML/tinyxmlglobal.h"
#include "../../../../../include/ilog.h"
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	double CPRAdequacyEstimate::ResolveDevELmtCutEnergy(tagPRBlock* pPRBlock, const int nDevType, const char* lpszDevName)
	{
		register int	i;
		int				nFState;

		if (pPRBlock->m_System.fMCSSimTime < FLT_MIN)
			return 0;

		double	fOvlAdjElLoadEnergy = 0;
		for (nFState=0; nFState<pPRBlock->m_nRecordNum[PR_FSTATE]; nFState++)
		{
			if (pPRBlock->m_FStateArray[nFState].fELCutLoad <= FLT_MIN)
				continue;

			for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]; i++)
			{
				if (pPRBlock->m_FStateOvlAdArray[i].nFStateNo < nFState)
					continue;
				if (pPRBlock->m_FStateOvlAdArray[i].nFStateNo > nFState)
					break;

				if (pPRBlock->m_FStateOvlAdArray[i].nOvlDevTyp != nDevType)
					continue;

				if (pPRBlock->m_FStateOvlAdArray[i].nOvlDevTyp == PR_ACLINE)
				{
					if (stricmp(pPRBlock->m_ACLineArray[pPRBlock->m_FStateOvlAdArray[i].nOvlDevIdx].szName, lpszDevName) != 0)
						continue;
				}
				else if (pPRBlock->m_FStateOvlAdArray[i].nOvlDevTyp == PR_WIND)
				{
					if (stricmp(pPRBlock->m_WindArray[pPRBlock->m_FStateOvlAdArray[i].nOvlDevIdx].szName, lpszDevName) != 0)
						continue;
				}

				if (pPRBlock->m_FStateOvlAdArray[i].nAdjDevTyp == PR_POWERLOAD)
					fOvlAdjElLoadEnergy += pPRBlock->m_FStateOvlAdArray[i].fAdValue*pPRBlock->m_FStateArray[nFState].fStateDur;
			}
		}

		return fOvlAdjElLoadEnergy*8760/pPRBlock->m_System.fMCSSimTime;
	}

#ifdef _DEBUG
	void CPRAdequacyEstimate::SaveCompPRParam(tagPRBlock* pPRBlock)
	{
		register int	i;
		char	szTempPath[260], szFileName[260];

		GetTempPath(260, szTempPath);
		sprintf(szFileName, "%s/CompPRParam.xml", szTempPath);

		TiXmlDocument*		pDocument = new TiXmlDocument();								//创建一个XML的文档对象。
		TiXmlDeclaration*	pDeclare = new TiXmlDeclaration("1.0", "GB2312", "no");
		pDocument->LinkEndChild(pDeclare);

		TiXmlElement*		pElement;
		TiXmlElement*		pRoot=new TiXmlElement("ComponentReliablityParameter");
		pDocument->LinkEndChild(pRoot);

		for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			pElement = new TiXmlElement("Bus");
			pRoot->LinkEndChild(pElement);

			pElement->SetAttribute("Name",			pPRBlock->m_ACBusArray[i].szName);
			pElement->SetDoubleAttribute("kV",		pPRBlock->m_ACBusArray[i].fkV);
			pElement->SetDoubleAttribute("GenP",	pPRBlock->m_ACBusArray[i].fGenP);
			pElement->SetDoubleAttribute("Load",	pPRBlock->m_ACBusArray[i].fLoadP);
			pElement->SetDoubleAttribute("AdjGen",	pPRBlock->m_ACBusArray[i].fAdjGenP);
			pElement->SetDoubleAttribute("AdjLoad",	pPRBlock->m_ACBusArray[i].fAdjLoadP);
			pElement->SetDoubleAttribute("AdjRad",	pPRBlock->m_ACBusArray[i].fAdjRadP);

			pElement->SetDoubleAttribute("Rerr",	pPRBlock->m_ACBusArray[i].fRerr);
			pElement->SetDoubleAttribute("Rrep",	pPRBlock->m_ACBusArray[i].fRrep);
			pElement->SetDoubleAttribute("Trep",	pPRBlock->m_ACBusArray[i].fTrep);
			pElement->SetDoubleAttribute("Good",	pPRBlock->m_ACBusArray[i].fGoodProb);
			pElement->SetDoubleAttribute("Fail",	pPRBlock->m_ACBusArray[i].fFailProb);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_GENERATOR]; i++)
		{
			pElement = new TiXmlElement("Gen");
			pRoot->LinkEndChild(pElement);

			pElement->SetAttribute("Name",			pPRBlock->m_GeneratorArray[i].szName);
			pElement->SetDoubleAttribute("Rerr",	pPRBlock->m_GeneratorArray[i].fRerr);
			pElement->SetDoubleAttribute("Rrep",	pPRBlock->m_GeneratorArray[i].fRrep);
			pElement->SetDoubleAttribute("Trep",	pPRBlock->m_GeneratorArray[i].fTrep);
			pElement->SetDoubleAttribute("Good",	pPRBlock->m_GeneratorArray[i].fGoodProb);
			pElement->SetDoubleAttribute("Fail",	pPRBlock->m_GeneratorArray[i].fFailProb);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		{
			pElement = new TiXmlElement("ACLine");
			pRoot->LinkEndChild(pElement);

			pElement->SetAttribute("Name",			pPRBlock->m_ACLineArray[i].szName);
			pElement->SetDoubleAttribute("Rerr",	pPRBlock->m_ACLineArray[i].fRerr);
			pElement->SetDoubleAttribute("Rrep",	pPRBlock->m_ACLineArray[i].fRrep);
			pElement->SetDoubleAttribute("Trep",	pPRBlock->m_ACLineArray[i].fTrep);
			pElement->SetDoubleAttribute("Good",	pPRBlock->m_ACLineArray[i].fGoodProb);
			pElement->SetDoubleAttribute("Fail",	pPRBlock->m_ACLineArray[i].fFailProb);
			pElement->SetDoubleAttribute("Rate",	pPRBlock->m_ACLineArray[i].fRated);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
		{
			pElement = new TiXmlElement("Tran");
			pRoot->LinkEndChild(pElement);

			pElement->SetAttribute("Name",			pPRBlock->m_WindArray[i].szName);
			pElement->SetDoubleAttribute("Rerr",	pPRBlock->m_WindArray[i].fRerr);
			pElement->SetDoubleAttribute("Rrep",	pPRBlock->m_WindArray[i].fRrep);
			pElement->SetDoubleAttribute("Trep",	pPRBlock->m_WindArray[i].fTrep);
			pElement->SetDoubleAttribute("Good",	pPRBlock->m_WindArray[i].fGoodProb);
			pElement->SetDoubleAttribute("Fail",	pPRBlock->m_WindArray[i].fFailProb);
			pElement->SetDoubleAttribute("Rate",	pPRBlock->m_WindArray[i].fRated);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_HVDC]; i++)
		{
			pElement = new TiXmlElement("HVDC");
			pRoot->LinkEndChild(pElement);

			pElement->SetAttribute("Name",			pPRBlock->m_HVDCArray[i].szName);
			pElement->SetDoubleAttribute("Rerr",	pPRBlock->m_HVDCArray[i].fRerr);
			pElement->SetDoubleAttribute("Rrep",	pPRBlock->m_HVDCArray[i].fRrep);
			pElement->SetDoubleAttribute("Trep",	pPRBlock->m_HVDCArray[i].fTrep);
			pElement->SetDoubleAttribute("Good",	pPRBlock->m_HVDCArray[i].fGoodProb);
			pElement->SetDoubleAttribute("Fail",	pPRBlock->m_HVDCArray[i].fFailProb);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_TCSC]; i++)
		{
			pElement = new TiXmlElement("TCSC");
			pRoot->LinkEndChild(pElement);

			pElement->SetAttribute("Name",			pPRBlock->m_TCSCArray[i].szName);
			pElement->SetDoubleAttribute("Rerr",	pPRBlock->m_TCSCArray[i].fRerr);
			pElement->SetDoubleAttribute("Rrep",	pPRBlock->m_TCSCArray[i].fRrep);
			pElement->SetDoubleAttribute("Trep",	pPRBlock->m_TCSCArray[i].fTrep);
			pElement->SetDoubleAttribute("Good",	pPRBlock->m_TCSCArray[i].fGoodProb);
			pElement->SetDoubleAttribute("Fail",	pPRBlock->m_TCSCArray[i].fFailProb);
			pElement->SetDoubleAttribute("X",		pPRBlock->m_TCSCArray[i].fX);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_UPFC]; i++)
		{
			pElement = new TiXmlElement("UPFC");
			pRoot->LinkEndChild(pElement);

			pElement->SetAttribute("Name",			pPRBlock->m_UPFCArray[i].szName);
			pElement->SetDoubleAttribute("Rerr",	pPRBlock->m_UPFCArray[i].fRerr);
			pElement->SetDoubleAttribute("Rrep",	pPRBlock->m_UPFCArray[i].fRrep);
			pElement->SetDoubleAttribute("Trep",	pPRBlock->m_UPFCArray[i].fTrep);
			pElement->SetDoubleAttribute("Good",	pPRBlock->m_UPFCArray[i].fGoodProb);
			pElement->SetDoubleAttribute("Fail",	pPRBlock->m_UPFCArray[i].fFailProb);
			pElement->SetDoubleAttribute("Mva",		pPRBlock->m_UPFCArray[i].fCapacity);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_CONVERTER]; i++)
		{
			pElement = new TiXmlElement("Converter");
			pRoot->LinkEndChild(pElement);

			pElement->SetAttribute("Name",			pPRBlock->m_ConverterArray[i].szName);
			pElement->SetDoubleAttribute("Rerr",	pPRBlock->m_ConverterArray[i].fRerr);
			pElement->SetDoubleAttribute("Rrep",	pPRBlock->m_ConverterArray[i].fRrep);
			pElement->SetDoubleAttribute("Trep",	pPRBlock->m_ConverterArray[i].fTrep);
			pElement->SetDoubleAttribute("Good",	pPRBlock->m_ConverterArray[i].fGoodProb);
			pElement->SetDoubleAttribute("Fail",	pPRBlock->m_ConverterArray[i].fFailProb);
			pElement->SetDoubleAttribute("Mva",		pPRBlock->m_ConverterArray[i].fConverterPower);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_DCLINE]; i++)
		{
			pElement = new TiXmlElement("DCLine");
			pRoot->LinkEndChild(pElement);

			pElement->SetAttribute("Name",			pPRBlock->m_DCLineArray[i].szName);
			pElement->SetDoubleAttribute("Rerr",	pPRBlock->m_DCLineArray[i].fRerr);
			pElement->SetDoubleAttribute("Rrep",	pPRBlock->m_DCLineArray[i].fRrep);
			pElement->SetDoubleAttribute("Trep",	pPRBlock->m_DCLineArray[i].fTrep);
			pElement->SetDoubleAttribute("Good",	pPRBlock->m_DCLineArray[i].fGoodProb);
			pElement->SetDoubleAttribute("Fail",	pPRBlock->m_DCLineArray[i].fFailProb);
		}
		pDocument->SaveFile(szFileName);					//保存到文件

		pDocument->Clear();
		delete pDocument;
	}
#endif


	void CPRAdequacyEstimate::AdjustDeviceRated(tagPRBlock* pPRBlock, const double fDC2ACRatio, const unsigned char bUPFCAdjustRC)
	{
		int		nDev;
		double	fRatio;

		CDCNetwork*	pDCNetwork=new CDCNetwork();
		pDCNetwork->PRDCFlow(pPRBlock, UPFC_MODE_NO);
		delete pDCNetwork;

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
		{
			if (pPRBlock->m_ACLineArray[nDev].fRated <= FLT_MIN)
				continue;
			fRatio = fDC2ACRatio*fabs(pPRBlock->m_ACLineArray[nDev].fPfPi)/pPRBlock->m_ACLineArray[nDev].fRated;
			if (fRatio > 1.25)
			{
				log_error("线路[%s] 超限严重 = %.2f\n", pPRBlock->m_ACLineArray[nDev].szName, fRatio);
				pPRBlock->m_ACLineArray[nDev].fRated=0;
				continue;
			}

			if (bUPFCAdjustRC && pPRBlock->m_ACLineArray[nDev].nUPFCIndex >= 0)
			{
				if (1.02*fDC2ACRatio*fabs(pPRBlock->m_ACLineArray[nDev].fPfPi) > (pPRBlock->m_ACLineArray[nDev].fRated+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fCapacity))
					pPRBlock->m_ACLineArray[nDev].fRated=(float)(1.02*fDC2ACRatio*fabs(pPRBlock->m_ACLineArray[nDev].fPfPi))-pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fCapacity;
			}
			else
			{
				if (1.02*fDC2ACRatio*fabs(pPRBlock->m_ACLineArray[nDev].fPfPi) > pPRBlock->m_ACLineArray[nDev].fRated)
					pPRBlock->m_ACLineArray[nDev].fRated=(float)(1.02*fDC2ACRatio*fabs(pPRBlock->m_ACLineArray[nDev].fPfPi));
			}
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
		{
			if (pPRBlock->m_WindArray[nDev].fRated <= FLT_MIN)
				continue;
			fRatio = fDC2ACRatio*fabs(pPRBlock->m_WindArray[nDev].fPfPi)/pPRBlock->m_WindArray[nDev].fRated;
			if (fDC2ACRatio*fabs(pPRBlock->m_WindArray[nDev].fPfPi)/pPRBlock->m_WindArray[nDev].fRated > 1.25)
			{
				log_error("变压器[%s] 超限严重 = %.2f\n", pPRBlock->m_WindArray[nDev].szName, fRatio);
				pPRBlock->m_WindArray[nDev].fRated=0;
				continue;
			}

			if (1.02*fDC2ACRatio*fabs(pPRBlock->m_WindArray[nDev].fPfPi) > pPRBlock->m_WindArray[nDev].fRated)
				pPRBlock->m_WindArray[nDev].fRated=(float)(1.02*fDC2ACRatio*fabs(pPRBlock->m_WindArray[nDev].fPfPi));
		}
	}
}
