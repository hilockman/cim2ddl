#include "json_tr.h"

#include <MemDB/PRMemDB/PRMemDB.h>
#include <PRAdequacyBase.h>
#include <BpaPRDataDefine.h>

#include "stateestimatedef.h"
#include <string>
#include <Common/libJson/include/json.h>
#include "ilog.h"

using namespace Json;
using namespace PRAdequacyBase;

extern CPRMemDBInterface		g_PRMemDBInterface;
namespace json_tr {


	std::string	FormResultJSon(const char* lpszCommand, const char* lpszRetValue, const char* lpszMesg)
	{
		Json::Value sRoot;
		Json::Value sContent;
		Json::FastWriter writer;

		sRoot["Command"] = lpszCommand;
		sContent["Value"] = lpszRetValue;
		sContent["Message"] = lpszMesg;
		sRoot["Content"] = sContent;

		return writer.write(sRoot);
	}

	void FormRecordJSon(tagPRBlock* pPRBlock, const int nTable, const int nRecord, Json::Value& sField)
	{
		int		nField, nFieldType;
		char	szValue[MDB_CHARLEN_LONG];

		sField.clear();
		for (nField = 0; nField < g_PRMemDBInterface.PRGetTableFieldNum(nTable); nField++)
		{
			g_PRMemDBInterface.PRGetRecordValue(pPRBlock, nTable, nField, nRecord, szValue);
			nFieldType = g_PRMemDBInterface.PRGetFieldType(nTable, nField);
			switch (nFieldType)
			{
			case	MDB_STRING:
				sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = szValue;
				break;
			case	MDB_DOUBLE:
				sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = atof(szValue);
				break;
			case	MDB_FLOAT:
				sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = atof(szValue);
				break;
			case	MDB_INT:
				sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = atoi(szValue);
				break;
			case	MDB_SHORT:
				sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = atoi(szValue);
				break;
			case	MDB_BIT:
				sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = atoi(szValue);
				break;
			case	MDB_CHAR:
				sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = (int)szValue[0];
				break;
			default:
				sField[g_PRMemDBInterface.PRGetFieldName(nTable, nField)] = szValue;
				break;
			}
		}
	}

	std::string	FormResultJSon(tagPRBlock* pPRBlock, const char* lpszMesg, const int nEstimateState)
	{
		register int	i;
		int		nTable;
		Json::Value sRoot;
		Json::Value sContent;
		Json::Value sField;
		Json::Value sFieldArray;
		Json::FastWriter writer;

		clock_t	dBeg, dEnd;
		int		nDur;
		dBeg = clock();

		sRoot.clear();
		sContent.clear();

		sRoot["Command"] = Command_StateEstimate;
		sContent["Message"] = lpszMesg;
		sContent["Value"] = "1";

		//////////////////////////////////////////////////////////////////////////
		nTable = PR_FSTATE;
		FormRecordJSon(pPRBlock, nTable, nEstimateState, sField);
		sContent[g_PRMemDBInterface.PRGetTableName(nTable)].append(sField);

		//////////////////////////////////////////////////////////////////////////
		nTable = PR_FSTATEMISLAND;
		for (i = 0; i < pPRBlock->m_nRecordNum[nTable]; i++)
		{
			if (pPRBlock->m_FStateMIslandArray[i].nFStateNo != nEstimateState)
				continue;
			FormRecordJSon(pPRBlock, nTable, i, sField);
			sContent[g_PRMemDBInterface.PRGetTableName(nTable)].append(sField);
		}

		//////////////////////////////////////////////////////////////////////////
		nTable = PR_FSTATEOVLDEV;
		for (i = 0; i < pPRBlock->m_nRecordNum[nTable]; i++)
		{
			if (pPRBlock->m_FStateOvlDevArray[i].nFStateNo != nEstimateState)
				continue;

			FormRecordJSon(pPRBlock, nTable, i, sField);
			sContent[g_PRMemDBInterface.PRGetTableName(nTable)].append(sField);
		}

		//////////////////////////////////////////////////////////////////////////
		nTable = PR_FSTATEOVLAD;
		for (i = 0; i < pPRBlock->m_nRecordNum[nTable]; i++)
		{
			if (pPRBlock->m_FStateOvlAdArray[i].nFStateNo != nEstimateState)
				continue;

			FormRecordJSon(pPRBlock, nTable, i, sField);
			sContent[g_PRMemDBInterface.PRGetTableName(nTable)].append(sField);
		}

		//remove by wangheng 4/25
		//for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		//{
		//	sField.clear();
		//	sField[g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_NAME)]  = pPRBlock->m_ACBusArray[i].szName;
		//	sField[g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_KV)]  = pPRBlock->m_ACBusArray[i].fkV;
		//	sField[g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_PLC)]  = pPRBlock->m_ACBusArray[i].fPLC ;
		//	sField[g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_ELC)]  = pPRBlock->m_ACBusArray[i].fELC ;
		//	sField[g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_EENS)] = pPRBlock->m_ACBusArray[i].fEENS;
		//	sField[g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_EFLC)] = pPRBlock->m_ACBusArray[i].fEFLC;
		//	sContent[g_PRMemDBInterface.PRGetTableName(PR_ACBUS)].append( sField );
		//}

		sRoot["Content"] = sContent;

		dEnd = clock();
		nDur = (int)((1000.0*(double)(dEnd - dBeg)) / CLOCKS_PER_SEC);
#ifdef _DEBUG
		log_debug("�γɼ�����JSON��ɣ���ʱ%d����", nDur);
		//Log(g_lpszLogFile, "ReturnJson = %d %d %d\n%s\n\n", pPRBlock->m_nRecordNum[PR_FSTATEMISLAND], pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV], pPRBlock->m_nRecordNum[PR_FSTATEOVLAD], sRoot.toStyledString().c_str());
#endif

		return writer.write(sRoot);
	}


	void ParsePRSetting(Json::Value& sData, tagBpaPRAdequacySetting* pSetting)
	{
		Json::Value	sObject, sNull(nullValue);
		Value::Members members = sData.getMemberNames();


		sObject = sData.get("BpaDatFile", sNull);		
		if (!sObject.isNull())	
			pSetting->strBpaDatFile = sObject.asString();				//���������ļ�
		else {
			log_debug("Find no BpaDatFile\0");
		}
		sObject = sData.get("BpaSwiFile", sNull);		if (!sObject.isNull())	pSetting->strBpaSwiFile = sObject.asString();				//�ȶ������ļ�����Ҫ�������γɷ����ģ��
		sObject = sData.get("BpaRParamFile", sNull);	if (!sObject.isNull())	pSetting->strBpaRParamFile = sObject.asString();				//�ɿ��Բ��������ļ�
		sObject = sData.get("TinyGenThreshold", sNull);	if (!sObject.isNull())	pSetting->fTinyGenThreshold = sObject.asDouble();	//�������ֽⷢ��������ż�ֵ���������ڸ��ż�ֵ�ķ������Ϊ���Ƿ������
		sObject = sData.get("LowVoltThreshold", sNull);	if (!sObject.isNull())	pSetting->fLowVoltThreshold = sObject.asDouble();	//�������ֽⷢ����͵�ѹ�ż�ֵ����ѹ���ڸ��ż�ֵ�ķ������Ϊ�Ǹ��ɶ����Ƿ��磩
		sObject = sData.get("ZIL", sNull);				if (!sObject.isNull())	pSetting->fZIL = sObject.asDouble();	//С�迹���С�迹�ż�ֵ
		sObject = sData.get("PRSampleObject", sNull);	if (!sObject.isNull())	pSetting->nPRSampleObject = sObject.asInt();	//��������ȫ�������硢֧·��
		sObject = sData.get("PRSampleMethod", sNull);	if (!sObject.isNull())	pSetting->nPRSampleMethod = sObject.asInt();	//��������
		sObject = sData.get("MaxGenFault", sNull);		if (!sObject.isNull())	pSetting->nMaxGenFault = sObject.asInt();	//MCS, FST, STS, ANA ������󷢵����������
		sObject = sData.get("MaxBranFault", sNull);		if (!sObject.isNull())	pSetting->nMaxBranFault = sObject.asInt();	//MCS, FST, STS, ANA �������֧·��������
		sObject = sData.get("LineELimit", sNull);		if (!sObject.isNull())	pSetting->bLineELimit = sObject.asInt();	//��·���޿���
		sObject = sData.get("TranELimit", sNull);		if (!sObject.isNull())	pSetting->bTranELimit = sObject.asInt();	//�������޿���
		sObject = sData.get("GenPELimit", sNull);		if (!sObject.isNull())	pSetting->bGenPELimit = sObject.asInt();	//�������������
		sObject = sData.get("UPFCELimit", sNull);		if (!sObject.isNull())	pSetting->bUPFCELimit = sObject.asInt();	//UPFC��������
		sObject = sData.get("AuxLoadAdjust", sNull);	if (!sObject.isNull())	pSetting->bAuxLoadAdjust = sObject.asInt();	//���õ縺�ɲ������
		sObject = sData.get("EQGenAdjust", sNull);		if (!sObject.isNull())	pSetting->bEQGenAdjust = sObject.asInt();	//��ֵ������������
		sObject = sData.get("EQLoadAdjust", sNull);		if (!sObject.isNull())	pSetting->bEQLoadAdjust = sObject.asInt();	//��ֵ������������
		sObject = sData.get("MCSSimulateTime", sNull);	if (!sObject.isNull())	pSetting->nMCSSimulateTime = sObject.asInt();	//MCS����������ʱ��
		sObject = sData.get("MCSMinStateProb", sNull);	if (!sObject.isNull())	pSetting->fMCSMinStateProb = sObject.asInt();	//MCS.get(���ؿ���]�豸���ϸ����ż�ֵ
		sObject = sData.get("FSTMaxCumuProb", sNull);	if (!sObject.isNull())	pSetting->fFSTMaxCumuProb = sObject.asDouble();	//FST.get(��������]�ۻ�����
		sObject = sData.get("FSTMinStateProb", sNull);	if (!sObject.isNull())	pSetting->fFSTMinStateProb = sObject.asDouble();	//FST.get(��������]�豸���ϸ����ż�ֵ
		sObject = sData.get("FSTMaxStateNum", sNull);	if (!sObject.isNull())	pSetting->nFSTMaxStateNum = sObject.asInt();	//FST.get(��������]���״̬��
		sObject = sData.get("STSMaxStateNum", sNull);	if (!sObject.isNull())	pSetting->nSTSMaxStateNum = sObject.asInt();	//STS.get(״̬����]���״̬��
		sObject = sData.get("ANAMinStateProb", sNull);	if (!sObject.isNull())	pSetting->fANAMinStateProb = sObject.asDouble();	//ANA.get( ������]�豸���ϸ����ż�ֵ
		sObject = sData.get("Dc2AcFactor", sNull);		if (!sObject.isNull())	pSetting->fDc2AcFactor = sObject.asDouble();	//ֱ������2 ��������ϵ��
		sObject = sData.get("MinIslandGLRatio", sNull);	if (!sObject.isNull())	pSetting->fMinIslandGLRatio = sObject.asDouble();	//�µ�����С���ر�
		sObject = sData.get("MultiThread", sNull);		if (!sObject.isNull())	pSetting->nMultiThread = sObject.asInt();	//�߳���
		sObject = sData.get("UPFCAdjustRC", sNull);		if (!sObject.isNull())	pSetting->bUPFCAdjustRC = sObject.asInt();	//UPFC���õ���������
		sObject = sData.get("GenBusLoadAsAux", sNull);	if (!sObject.isNull())	pSetting->bGenBusLoadAsAux = sObject.asInt();	//�����ĸ�߸��ɰ����õ紦��
	}

}