#include "stateestimatetask.h"
#include <MemDB/PRMemDB/PRMemDB.h>
#include <PRAdequacyBase.h>
#include <BpaPRDataDefine.h>

#include "stateestimatedef.h"
#include <string>
#include <Common/libJson/include/json.h>

using namespace Json;
using namespace PRAdequacyBase;


#include "ilog.h"
#include "json_tr.h"
using namespace json_tr;

extern CPRMemDBInterface		g_PRMemDBInterface;


class StateEstimateTask::StateEstimateTaskPrivate
{
private:
	int							m_nWorkMemID;

	CPRAdequacyStateEstimate*	m_pPREstimate;
	tagPRBlock*					m_pPRWorkBlock;
	CPRMemDBInterface			m_PRMemDBInterface;
	tagBpaPRAdequacySetting		m_PRAdequacySetting;
	bool m_bIdle;
	send_func sender;
	string parameter;
	friend class StateEstimateTask;


	int create(const int nThreadID, tagBpaPRAdequacySetting* pSetting, send_func sender) {
		this->sender = sender;
		m_bIdle = 1;
		m_nWorkMemID = g_nPRBlockKey + 1000 + nThreadID;
		CopyBpaPRAdequacySetting(pSetting, &m_PRAdequacySetting);

		m_pPREstimate = new CPRAdequacyStateEstimate();
		if (!m_pPREstimate)
		{
			log_error("建立发输电系统充裕度评估评估类错误，内存空间可能不够");
			return -1;
		}

		m_pPRWorkBlock = (tagPRBlock*)m_PRMemDBInterface.Init_PRBlock(m_nWorkMemID);
		if (!m_pPRWorkBlock)
		{
			log_error("获取PR工作内存库错误\n");
			delete m_pPREstimate;
			return -1;
		}

		memcpy(m_pPRWorkBlock, m_PRMemDBInterface.Init_PRBlock(), sizeof(tagPRBlock));
		m_pPREstimate->PrepareSysStateEstimate(m_pPRWorkBlock, 0);


		return 0;
	}

	~StateEstimateTaskPrivate() {
		if (m_pPRWorkBlock)
			g_PRMemDBInterface.Exit_PRBlock((char*)m_pPRWorkBlock, m_nWorkMemID);
		delete m_pPREstimate;
	}
	void setParameter(const std::string &param) {
		parameter = param;
	}

	void calculate()
	{
		const std::string &param = parameter;

		Json::Reader	sReader;
		Json::Value		sRoot, sContent, sData, sRecArray, sObject, sNull(nullValue);

		bool	bSuccess = sReader.parse(param, sRoot, false);
		if (!bSuccess)
		{
			log_error("计算线程中 Parse Json 错误 : %s", param.c_str());
			sender(FormResultJSon(Command_StateEstimate, "0", "计算线程中 Parse Json 错误").c_str());
			m_bIdle = 1;
			return;
		}

		log_info("********** 开始计算任务 **********");

		m_pPRWorkBlock->m_nRecordNum[PR_FSTATE] = 0;
		m_pPRWorkBlock->m_nRecordNum[PR_FSTATEFDEV] = 0;
		m_pPRWorkBlock->m_nRecordNum[PR_FSTATEMSTATE] = 0;
		m_pPRWorkBlock->m_nRecordNum[PR_FSTATEMISLAND] = 0;
		m_pPRWorkBlock->m_nRecordNum[PR_FSTATEOVLDEV] = 0;
		m_pPRWorkBlock->m_nRecordNum[PR_FSTATEOVLAD] = 0;

		sContent = sRoot.get("Content", sNull);

		int				nRec, nTable, nField;
		char			szValue[MDB_CHARLEN_LONG];
		if (!sContent.isNull())
		{
			//////////////////////////////////////////////////////////////////////////
			nTable = PR_FSTATE;
			sRecArray = sContent.get(g_PRMemDBInterface.PRGetTableName(nTable), sNull);
			if (!sRecArray.isNull() || !sRecArray.isArray())
			{
				for (nRec = 0; nRec < sRecArray.size(); nRec++)
				{
					sObject = sRecArray.get(nRec, sNull);
					if (sObject.isNull() || !sObject.isObject())
						continue;

					memset(&m_pPRWorkBlock->m_FStateArray[m_pPRWorkBlock->m_nRecordNum[nTable]], 0, sizeof(tagPRFState));
					Json::ValueIterator iter = sObject.begin();
					for (; iter != sObject.end(); iter++)
					{
						sData = sObject.get(iter.memberName(), sNull);
						if (!sData.isNull())
						{
							nField = g_PRMemDBInterface.PRGetFieldIndex(nTable, iter.memberName());

							if (nField >= 0 && nField < g_PRMemDBInterface.PRGetTableFieldNum(nTable))
							{
								memset(szValue, 0, MDB_CHARLEN_LONG);
								if (sData.isString())
									strcpy(szValue, sData.asString().c_str());
								else if (sData.isDouble()) {
									std::stringstream os;
									double v = sData.asDouble();
									os << v;
									strcpy(szValue, os.str().c_str());
									//sprintf(szValue, "%lf", v);
								}
								else if (sData.isInt())
									sprintf(szValue, "%d", sData.asInt());

//#ifdef _DEBUG
//								log_info("OnCalculate Table[%s] Field[%s] = %s", g_PRMemDBInterface.PRGetTableDesp(nTable), g_PRMemDBInterface.PRGetFieldDesp(nTable, nField), szValue);
//#endif
								g_PRMemDBInterface.PRSetRecordValue(m_pPRWorkBlock, nTable, nField, m_pPRWorkBlock->m_nRecordNum[nTable], szValue);
							}
						}
					}
				}
				m_pPRWorkBlock->m_nRecordNum[nTable]++;
			}
			else
			{
#ifdef _DEBUG
				log_error("        Content中无%s", g_PRMemDBInterface.PRGetTableName(nTable));
#endif
				char	szMesg[260];
				log_error(szMesg, "计算线程解析Json错误：Content中无%s", g_PRMemDBInterface.PRGetTableName(nTable));
				sender(FormResultJSon(Command_StateEstimate, "0", szMesg).c_str());
				m_bIdle = 1;
				return;
			}
			//////////////////////////////////////////////////////////////////////////
			nTable = PR_FSTATEFDEV;
			sRecArray = sContent.get(g_PRMemDBInterface.PRGetTableName(nTable), sNull);
			if (!sRecArray.isNull() || !sRecArray.isArray())
			{
				for (nRec = 0; nRec < sRecArray.size(); nRec++)
				{
					sObject = sRecArray.get(nRec, sNull);
					if (sObject.isNull() || !sObject.isObject())
						continue;

					memset(&m_pPRWorkBlock->m_FStateFDevArray[m_pPRWorkBlock->m_nRecordNum[nTable]], 0, sizeof(tagPRFStateFDev));
					Json::ValueIterator iter = sObject.begin();
					for (; iter != sObject.end(); iter++)
					{
						sData = sObject.get(iter.memberName(), sNull);
						if (!sData.isNull())
						{
							nField = g_PRMemDBInterface.PRGetFieldIndex(nTable, iter.memberName());
							if (nField >= 0 && nField < g_PRMemDBInterface.PRGetTableFieldNum(nTable))
							{
								memset(szValue, 0, MDB_CHARLEN_LONG);
								if (sData.isString())
									strcpy(szValue, sData.asString().c_str());
								else if (sData.isDouble())
									sprintf(szValue, "%lf", sData.asDouble());
								else if (sData.isInt())
									sprintf(szValue, "%d", sData.asInt());

//#ifdef _DEBUG
//								log_info("OnCalculate Table[%s] Field[%s] = %s\n", g_PRMemDBInterface.PRGetTableDesp(nTable), g_PRMemDBInterface.PRGetFieldDesp(nTable, nField), szValue);
//#endif
								g_PRMemDBInterface.PRSetRecordValue(m_pPRWorkBlock, nTable, nField, m_pPRWorkBlock->m_nRecordNum[nTable], szValue);
							}
						}
					}
					m_pPRWorkBlock->m_FStateFDevArray[m_pPRWorkBlock->m_nRecordNum[nTable]].nFStateNo = 0;
					m_pPRWorkBlock->m_nRecordNum[nTable]++;
				}
			}
		}
		else
		{
#ifdef _DEBUG
			log_info("root中无Content: %s", param.c_str());
#endif
			sender(FormResultJSon(Command_StateEstimate, "0", "计算线程解析Json错误：root中无Content").c_str());
			m_bIdle = 1;
			return;
		}

		m_pPREstimate->SysStateEstimate(m_pPRWorkBlock,
			0,
			m_PRAdequacySetting.fDc2AcFactor,
			m_PRAdequacySetting.fMinIslandGLRatio,
			m_PRAdequacySetting.bLineELimit,
			m_PRAdequacySetting.bTranELimit,
			m_PRAdequacySetting.bGenPELimit,
			m_PRAdequacySetting.bUPFCELimit,
			m_PRAdequacySetting.bAuxLoadAdjust,
			m_PRAdequacySetting.bEQGenAdjust,
			m_PRAdequacySetting.bEQLoadAdjust,
			m_PRAdequacySetting.bUPFCAdjustRC,
			NULL);

		char	szMesg[260];
		log_info("FStateID = %d 计算完成", m_pPRWorkBlock->m_FStateArray[0].nFStateId);
		sender(FormResultJSon(m_pPRWorkBlock, szMesg, 0).c_str());
	}
};

StateEstimateTask::StateEstimateTask()
	:d(new StateEstimateTaskPrivate())
{
	
}

int StateEstimateTask::Create(const int nThreadID, PRAdequacyBase::tagBpaPRAdequacySetting* pSetting, send_func sender)
{
	return d->create(nThreadID, pSetting, sender);
}


StateEstimateTask::~StateEstimateTask()
{
	delete d;
}

void StateEstimateTask::setBusy()
{
	d->m_bIdle = true;
}
bool StateEstimateTask::isIdle() const
{
	return d->m_bIdle == 1;
}

void StateEstimateTask::setParameter(const std::string &param)
{
	d->setParameter(param);
}

void StateEstimateTask::run()
{
	d->m_bIdle = 0;
	d->calculate();
	d->m_bIdle = 1;
}