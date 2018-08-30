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

CPRMemDBInterface		g_PRMemDBInterface;
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
		log_debug("形成计算结果JSON完成，耗时%d毫秒", nDur);
		//Log(g_lpszLogFile, "ReturnJson = %d %d %d\n%s\n\n", pPRBlock->m_nRecordNum[PR_FSTATEMISLAND], pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV], pPRBlock->m_nRecordNum[PR_FSTATEOVLAD], sRoot.toStyledString().c_str());
#endif

		return writer.write(sRoot);
	}


	void ParsePRSetting(Json::Value& sData, tagBpaPRAdequacySetting* pSetting)
	{
		Json::Value	sObject, sNull(nullValue);

		sObject = sData.get("BpaDatFile", sNull);		if (!sObject.isNull())	pSetting->strBpaDatFile = sObject.asString();				//潮流输入文件
		sObject = sData.get("BpaSwiFile", sNull);		if (!sObject.isNull())	pSetting->strBpaSwiFile = sObject.asString();				//稳定输入文件，主要是用于形成发电机模型
		sObject = sData.get("BpaRParamFile", sNull);	if (!sObject.isNull())	pSetting->strBpaRParamFile = sObject.asString();				//可靠性参数输入文件
		sObject = sData.get("TinyGenThreshold", sNull);	if (!sObject.isNull())	pSetting->fTinyGenThreshold = sObject.asDouble();	//环辐网分解发电机容量门槛值（容量低于该门槛值的发电机认为不是发电机）
		sObject = sData.get("LowVoltThreshold", sNull);	if (!sObject.isNull())	pSetting->fLowVoltThreshold = sObject.asDouble();	//环辐网分解发电机低电压门槛值（电压低于该门槛值的发电机认为是负荷而不是发电）
		sObject = sData.get("ZIL", sNull);				if (!sObject.isNull())	pSetting->fZIL = sObject.asDouble();	//小阻抗清除小阻抗门槛值
		sObject = sData.get("PRSampleObject", sNull);	if (!sObject.isNull())	pSetting->nPRSampleObject = sObject.asInt();	//抽样对象（全部、发电、支路）
		sObject = sData.get("PRSampleMethod", sNull);	if (!sObject.isNull())	pSetting->nPRSampleMethod = sObject.asInt();	//抽样类型
		sObject = sData.get("MaxGenFault", sNull);		if (!sObject.isNull())	pSetting->nMaxGenFault = sObject.asInt();	//MCS, FST, STS, ANA 抽样最大发电机故障重数
		sObject = sData.get("MaxBranFault", sNull);		if (!sObject.isNull())	pSetting->nMaxBranFault = sObject.asInt();	//MCS, FST, STS, ANA 抽样最大支路故障重数
		sObject = sData.get("LineELimit", sNull);		if (!sObject.isNull())	pSetting->bLineELimit = sObject.asInt();	//线路消限开关
		sObject = sData.get("TranELimit", sNull);		if (!sObject.isNull())	pSetting->bTranELimit = sObject.asInt();	//主变消限开关
		sObject = sData.get("GenPELimit", sNull);		if (!sObject.isNull())	pSetting->bGenPELimit = sObject.asInt();	//发电机参与消限
		sObject = sData.get("UPFCELimit", sNull);		if (!sObject.isNull())	pSetting->bUPFCELimit = sObject.asInt();	//UPFC参与消限
		sObject = sData.get("AuxLoadAdjust", sNull);	if (!sObject.isNull())	pSetting->bAuxLoadAdjust = sObject.asInt();	//厂用电负荷参与调整
		sObject = sData.get("EQGenAdjust", sNull);		if (!sObject.isNull())	pSetting->bEQGenAdjust = sObject.asInt();	//等值发电机参与调整
		sObject = sData.get("EQLoadAdjust", sNull);		if (!sObject.isNull())	pSetting->bEQLoadAdjust = sObject.asInt();	//等值发电机参与调整
		sObject = sData.get("MCSSimulateTime", sNull);	if (!sObject.isNull())	pSetting->nMCSSimulateTime = sObject.asInt();	//MCS最大抽样仿真时长
		sObject = sData.get("MCSMinStateProb", sNull);	if (!sObject.isNull())	pSetting->fMCSMinStateProb = sObject.asInt();	//MCS.get(蒙特卡罗]设备故障概率门槛值
		sObject = sData.get("FSTMaxCumuProb", sNull);	if (!sObject.isNull())	pSetting->fFSTMaxCumuProb = sObject.asDouble();	//FST.get(快速排序]累积概率
		sObject = sData.get("FSTMinStateProb", sNull);	if (!sObject.isNull())	pSetting->fFSTMinStateProb = sObject.asDouble();	//FST.get(快速排序]设备故障概率门槛值
		sObject = sData.get("FSTMaxStateNum", sNull);	if (!sObject.isNull())	pSetting->nFSTMaxStateNum = sObject.asInt();	//FST.get(快速排序]最大状态数
		sObject = sData.get("STSMaxStateNum", sNull);	if (!sObject.isNull())	pSetting->nSTSMaxStateNum = sObject.asInt();	//STS.get(状态抽样]最大状态数
		sObject = sData.get("ANAMinStateProb", sNull);	if (!sObject.isNull())	pSetting->fANAMinStateProb = sObject.asDouble();	//ANA.get( 解析法]设备故障概率门槛值
		sObject = sData.get("Dc2AcFactor", sNull);		if (!sObject.isNull())	pSetting->fDc2AcFactor = sObject.asDouble();	//直流潮流2 交流潮流系数
		sObject = sData.get("MinIslandGLRatio", sNull);	if (!sObject.isNull())	pSetting->fMinIslandGLRatio = sObject.asDouble();	//孤岛的最小容载比
		sObject = sData.get("MultiThread", sNull);		if (!sObject.isNull())	pSetting->nMultiThread = sObject.asInt();	//线程数
		sObject = sData.get("UPFCAdjustRC", sNull);		if (!sObject.isNull())	pSetting->bUPFCAdjustRC = sObject.asInt();	//UPFC采用调整容量法
		sObject = sData.get("GenBusLoadAsAux", sNull);	if (!sObject.isNull())	pSetting->bGenBusLoadAsAux = sObject.asInt();	//发电机母线负荷按厂用电处理
	}

}