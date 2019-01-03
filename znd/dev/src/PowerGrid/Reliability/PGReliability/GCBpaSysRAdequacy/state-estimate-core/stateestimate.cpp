#include "stateestimate.h"
#include <iostream>
using namespace std;

#include <PRAdequacyBase.h>
using namespace PRAdequacyBase;

#include "ThreadPool.h"
#include "ilog.h"

#include <Common/libJson/include/json.h>
using namespace Json;

#include "json_tr.h"
using namespace json_tr;

#include "stateestimatetask.h"

static int index = 0;
std::mutex send_mutex;
std::mutex task_queue_mutex;
#include <queue>

std::queue<string> task_list;

std::atomic_bool quit;

void pushTask(const string &task) {
	task_queue_mutex.lock();
	task_list.push(task);
	task_queue_mutex.unlock();
}

class StateEstimate::StateEstimatePrivate
{
private:
	//CPRMemDBInterface m_PRMemDBInterface;
	//tagPRBlock*	 m_pPRWorkBlock;
	//int m_nWorkMemID;
	//CPRAdequacyStateEstimate *m_pPREstimate;
	ThreadPool *pool;
	send_func sender;
	friend class StateEstimate;

	std::vector<StateEstimateTask *> m_pDataProcThreadArray;

	StateEstimatePrivate()
	{
		pool = new ThreadPool(4);
	}

	int DataReady(tagBpaPRAdequacySetting* pSetting)
	{
		SYSTEM_INFO sysInfo;
		::GetSystemInfo(&sysInfo);

		int		nThreadNum = pSetting->nMultiThread;
		if (nThreadNum <= 0)
			nThreadNum = 1;
		if (nThreadNum > sysInfo.dwNumberOfProcessors)
			nThreadNum = sysInfo.dwNumberOfProcessors;

		for (int nThread = 0; nThread < nThreadNum; nThread++)
		{
			StateEstimateTask *pThread = new StateEstimateTask();
			if (pThread)
			{
				if (pThread->Create(nThread + 1, pSetting, sender) < 0)
				{
					log_error("建立计算分析线程[%d]失败!", nThread + 1);
					continue;
				}
				log_info("建立计算分析线程[%d]完成!\n", nThread + 1);
				m_pDataProcThreadArray.push_back(pThread);
			}
		}

		//start task consume thread
		for (int nThread = 0; nThread < m_pDataProcThreadArray.size(); nThread++)
		{
			StateEstimateTask *r = m_pDataProcThreadArray[nThread];
			pool->enqueue([nThread, r] {
				while (true) {
					if (quit) {
						log_info("Task thread[%d] quit. ", nThread);
						delete r;
						break;
					}
					if (task_list.empty()) {
						continue;
					}
					task_queue_mutex.lock();
					if (task_list.empty()) {
						task_queue_mutex.unlock();
						continue;
					}
					string task = task_list.front();
					task_list.pop();
					task_queue_mutex.unlock();

					r->setParameter(task.c_str());
					r->run();
				}
			});
		}

		return 1;
	}


	int FinishJob()
	{
		quit = true;
		m_pDataProcThreadArray.clear();
		return 1;
	}

	void setConfig(const std::string &strRecv) {
		Json::Reader	sReader;
		Json::Value		sRoot, sContent, sData, sNull(nullValue);

		std::string		strCommand, strValue;

		strCommand.clear();
		strValue.clear();
		if (!sReader.parse(strRecv, sRoot, false))
		{
			strValue = "控制线程中 Parse Json 错误, 网络接收数据 = ";
			strValue.append(strRecv);

#ifdef _DEBUG
			log_error("        控制线程中 Parse Json 错误");
#endif
			sender(FormResultJSon("Error", "0", strValue.c_str()).c_str());
			return;
		}

		strCommand = sRoot["Command"].asString();
#ifdef _DEBUG
		log_info("接收Command = %s", strCommand.c_str());
#endif

		if (stricmp(strCommand.c_str(), Command_DataReady) == 0)
		{
			if (!m_pDataProcThreadArray.empty())
			{
#ifdef _DEBUG
				log_error("        当前计算任务没有结束，请先JobFinished");
				
#endif
				sender(FormResultJSon(strCommand.c_str(), "0", "控制线程中 DataReady命令 计算任务进行中").c_str());
				return;
			}

			tagBpaPRAdequacySetting	sPRAdequacySetting;
			PRAdequacyBase::InitBpaPRAdequacySetting(&sPRAdequacySetting);

			sContent = sRoot.get("Content", sNull);
			if (!sContent.isNull())
			{
				sData = sContent.get("PRAdequacySetting", sNull);
				if (!sData.isNull())
				{
					ParsePRSetting(sData, &sPRAdequacySetting);
				}
				else
				{

					log_error("Content中无PRAdequacySetting");
					sender(FormResultJSon(strCommand.c_str(), "0", "控制线程中 DataReady命令 Content 中无 PRAdequacySetting").c_str());
					return ;
				}
			}
			log_info("计算线程初始化");
			DataReady(&sPRAdequacySetting);

			char	szMesg[260];
			log_info(szMesg, "%d", m_pDataProcThreadArray.size());
			sender(FormResultJSon(strCommand.c_str(), szMesg, "计算线程初始化完成").c_str());
		}
		else if (stricmp(strCommand.c_str(), Command_JobFinished) == 0)
		{
			if (m_pDataProcThreadArray.empty())
			{
#ifdef _DEBUG
				log_info("        当前无计算任务");
//				Log(g_lpszLogFile, "        当前无计算任务\n");
#endif
				sender(FormResultJSon(strCommand.c_str(), "0", "控制线程中 JobFinished命令 当前无计算任务").c_str());
				return;
			}

			log_info("        关闭计算任务");
			FinishJob();
			sender(FormResultJSon(strCommand.c_str(), "1", "计算任务关闭完成").c_str());
		}
		else if (stricmp(strCommand.c_str(), Command_StateEstimate) == 0)
		{
			pushTask(strRecv);


			//int	nIdleThread = -1;
			//for (int nThread = 0; nThread < m_pDataProcThreadArray.size(); nThread++)
			//{
			//	if (m_pDataProcThreadArray[nThread]->isIdle())
			//	{
			//		nIdleThread = nThread;
			//		break;
			//	}
			//}
			//if (nIdleThread >= 0)
			//{
			//	register int	i;
			//	char*	lpszData = (char*)GlobalAlloc(GPTR, strRecv.size());
			//	memset(lpszData, 0, strRecv.size());

			//	for (i = 0; i < strRecv.size(); i++)
			//		lpszData[i] = strRecv[i];

			//	//m_pDataProcThreadArray[nIdleThread]->m_bIdle = 0;
			//	StateEstimateTask *pThread = m_pDataProcThreadArray[nIdleThread];
			//	pThread->setParameter(lpszData);
			//	//m_pDataProcThreadArray[nIdleThread]->PostThreadMessage(TM_STATE_ESTIMATE, 0, (LPARAM)lpszData);
			//}
			//else
			//{
			//	sender(FormResultJSon(strCommand.c_str(), "0", "控制线程中 无空闲计算线程").c_str());
			//}
		}
	}



};

send_func g_send = NULL;
void  wrapper_send(const char *msg)
{
	send_mutex.lock();
	g_send(msg);
	send_mutex.unlock();
}

StateEstimate::StateEstimate(send_func f) : d(new StateEstimatePrivate())
{
	g_send = f;
	d->sender = wrapper_send;

	//CopyBpaPRAdequacySetting(pSetting, &m_PRAdequacySetting);
}


StateEstimate::~StateEstimate()
{
	delete d;
}

//
//void se_func()
//{
//	
//	StateEstimate se;
//	
//}
//

//StateEstimate *createStateEstimate(const char *settingStr)
//{
//	cout << "Setting = " << settingStr << endl;
//	return new StateEstimate();
//}


void StateEstimate::setConfig(const char *config)
{
	index = 0;
	cout << "Config = " << config << endl;
	//std::string strRecv = config;

	d->setConfig(config);

}


void StateEstimate::runSample(const char *sample)
{
//	task_list.push(sample);

	//string task = sample;
	log_debug("Task %d", index++);
	pushTask(sample);

	////send_func func = d->sender;
	//auto result = d->pool->enqueue([this, task] {
	//	//std::cout << "sample = " << index++ << std::endl;
	//	//return std::string(sample);
	//	log_debug("Task %d", index++);
	//	//std::string response = task;
	//	
	//	pushTask(task);

	//	//d->pool->enqueue([response, func] {
	//	//	send_mutex.lock();
	//	//	func(response.c_str());
	//	//	send_mutex.unlock();
	//	//});
	//});	
}

//void StateEstimate::runSample(const char *sample, send_func func)
//{
//
//	std::cout << "sample = " << index++ << std::endl;
//	func(sample);
//
//
//}


#include <iostream>
#include <fstream>
using namespace std;

void  printSetting(tagBpaPRAdequacySetting *setting)
{
	log_info("setting = \n{strBpaDatFile:%s, strBpaSwiFile:%s, strBpaRParamFile:%s,"
		"fTinyGenThreshold:%f,fLowVoltThreshold:%f, fZIL:%f, nPRSampleObject:%d,"
		" nPRSampleMethod:%d, nMaxGenFault:%d,nMaxBranFault%d, bLineELimit:%d,bTranELimit%d, "
		"bGenPELimit:%d, bUPFCELimit:%d, bAuxLoadAdjust:%d,bEQGenAdjust:%d, bEQLoadAdjust:%d,"
		"nMCSSimulateTime:%d,fMCSMinStateProb:%f,fFSTMaxCumuProb:%f,fFSTMinStateProb:%f,"
		"nFSTMaxStateNum:%d,nSTSMaxStateNum:%d,fANAMinStateProb:%f,fDc2AcFactor:%f,fMinIslandGLRatio:%f,nMultiThread:%d,bUPFCAdjustRC:%d,"
		"bGenBusLoadAsAux:%d }"
		, setting->strBpaDatFile.c_str()				//	潮流输入文件
		, setting->strBpaSwiFile.c_str()				//	稳定输入文件，主要是用于形成发电机模型
		, setting->strBpaRParamFile.c_str()			//	可靠性参数输入文件
		, setting->fTinyGenThreshold		//	环辐网分解发电机容量门槛值（容量低于该门槛值的发电机认为不是发电机）
		, setting->fLowVoltThreshold		//	环辐网分解发电机低电压门槛值（电压低于该门槛值的发电机认为是负荷而不是发电）
		, setting->fZIL					//	小阻抗清除小阻抗门槛值
		//////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////
		//	可靠性抽样参数设置
		, setting->nPRSampleObject
		, setting->nPRSampleMethod			//	抽样类型
		, setting->nMaxGenFault			//	MCS, FST, STS, ANA 抽样最大发电机故障重数
		, setting->nMaxBranFault			//	MCS, FST, STS, ANA 抽样最大支路故障重数
		, setting->bLineELimit			//	线路消限开关
		, setting->bTranELimit			//	主变消限开关
		, setting->bGenPELimit
		, setting->bUPFCELimit

		, setting->bAuxLoadAdjust			//	厂用电负荷参与调整
		, setting->bEQGenAdjust
		, setting->bEQLoadAdjust

		, setting->nMCSSimulateTime		//	MCS最大抽样仿真时长
		, setting->fMCSMinStateProb		//	MCS[蒙特卡罗]设备故障概率门槛值
		, setting->fFSTMaxCumuProb		//	FST[快速排序]累积概率
		, setting->fFSTMinStateProb		//	FST[快速排序]设备故障概率门槛值
		, setting->nFSTMaxStateNum		//	FST[快速排序]最大状态数
		, setting->nSTSMaxStateNum		//	STS[状态抽样]最大状态数
		, setting->fANAMinStateProb		//	ANA[ 解析法 ]设备故障概率门槛值
		, setting->fDc2AcFactor			//	直流潮流 2 交流潮流系数
		, setting->fMinIslandGLRatio		//	孤岛的最小容载比
		, setting->nMultiThread
		, setting->bUPFCAdjustRC

		, setting->bGenBusLoadAsAux		//	发电机母线负荷按厂用电处理
		);

}

the
#include "MemDB/BpaMemDB/BpaMemDB.h"
using namespace BpaMemDB;

CBpaMemDBInterface	g_BpaMemDBInterface;
CPRMemDBInterface	g_PRMemDBInterface;
CBpaPRParam				g_BpaPRParam;
char				g_szRunDir[260];
tagBpaBlock*		g_pBpaBlock;
tagPRBlock*			g_pPRBlock;
CPRAdequacyStateSample	g_PRStateSample;			//	蒙特卡洛状态抽样
CPRAdequacyEstimate		g_PRAdeEstimate;
tagBpaPRAdequacySetting	g_PRAdeSetting;


extern	int		StartProcess(char* lpszCmd, const char* lpszPath, WORD swType);

int initMem() {
	log_info("init bpa and pr memeroy.");
	g_pBpaBlock = (tagBpaBlock*)g_BpaMemDBInterface.Init_BpaBlock();
	if (!g_pBpaBlock)
	{
		
		return -1;
	}

	g_pPRBlock = (tagPRBlock*)g_PRMemDBInterface.Init_PRBlock();
	if (!g_pPRBlock)
	{
	
		return -1;
	}
	return 0;
}

int  preparePRData()
{
	log_info("prepare bpa and pr memeroy.");
	char	drive[260], dir[260], fname[260], ext[260];
	char	szFileName[260], szBpaPFExec[260], szWorkDir[260], szExec[260];

	if (_access(g_PRAdeSetting.strBpaDatFile.c_str(), 0) == 0)
	{
		g_BpaMemDBInterface.BpaFiles2MemDB(g_pBpaBlock, g_PRAdeSetting.strBpaDatFile.c_str(), g_PRAdeSetting.strBpaSwiFile.c_str(), g_PRAdeSetting.fZIL);
	}
	else {
		log_error("Find no bpa file : %s.", g_PRAdeSetting.strBpaDatFile.c_str());
		return -1;
	}


	sprintf(g_szRunDir, "%s\\bin_x64", getenv("ZND_HOME"));
	sprintf(szBpaPFExec, "%s/pfnt.exe", g_szRunDir);
	if (access(szBpaPFExec, 0) != 0) {
		log_error("Power flow program doesn't exist : %s.", (const char *)szBpaPFExec);
		return 0;
	}

	_splitpath(g_PRAdeSetting.strBpaDatFile.c_str(), drive, dir, fname, ext);
	_makepath(szWorkDir, drive, dir, NULL, NULL);
	SetCurrentDirectory(szWorkDir);

	sprintf(szFileName, "%s%s", fname, ext);
	sprintf(szExec, "%s %s", szBpaPFExec, szFileName);
	log_info("calc power flow : cmd : %s", (const char *)szExec);
	StartProcess(szExec, NULL, SW_HIDE);

	_makepath(szFileName, drive, dir, fname, ".pfo");
	
	if (g_BpaMemDBInterface.BpaParsePfoFile(g_pBpaBlock, szFileName) <= 0)
	{
		log_error("无PFO文件，请计算交流潮流\n");
		return -1;
	}

	BpaMemDB2PRMemDB(g_pBpaBlock, g_pPRBlock, g_PRAdeSetting.strBpaDatFile.c_str(), g_PRAdeSetting.strBpaSwiFile.c_str(), g_PRAdeSetting.bGenBusLoadAsAux);	//	读全网数据
	g_PRAdeEstimate.AdjustDeviceRated(g_pPRBlock, g_PRAdeSetting.fDc2AcFactor, 0);
	if (!g_PRAdeSetting.strBpaRParamFile.empty())
		g_BpaPRParam.ReadBpaPRParam(g_PRAdeSetting.strBpaRParamFile.c_str(), g_pPRBlock);

	return 1;
}

void sample() {
	clock_t	dBeg, dEnd;
	int		nDur;

	dBeg = clock();

	int	nStateNum = g_PRStateSample.Sample(g_pPRBlock, g_PRAdeSetting.nPRSampleObject, g_PRAdeSetting.nPRSampleMethod, &g_PRAdeSetting);

	dEnd = clock();
	nDur = (int)((1000.0*(double)(dEnd - dBeg)) / CLOCKS_PER_SEC);
	log_info("ReadBpaData ( 抽样类型 = %s 设备类型 = %s ) 完毕，耗时%d毫秒",
		g_PRMemDBInterface.PRGetFieldEnumString(PR_SYSTEM, PR_SYSTEM_SAMPLEMETHOD, g_PRAdeSetting.nPRSampleMethod),
		g_PRMemDBInterface.PRGetFieldEnumString(PR_SYSTEM, PR_SYSTEM_SAMPLEOBJECT, g_PRAdeSetting.nPRSampleObject), nDur);

}




void printAdequacyEstimateResult() {
	log_info("%s : %d", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_MAXFLTDEV), g_pPRBlock->m_System.nMaxFltDev);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_PLC), g_pPRBlock->m_System.fPLC);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_EFLC), g_pPRBlock->m_System.fEFLC);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_EDLC), g_pPRBlock->m_System.fEDLC);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_ADLC), g_pPRBlock->m_System.fADLC);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_ELC), g_pPRBlock->m_System.fELC);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_EENS), g_pPRBlock->m_System.fEENS);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_BPII), g_pPRBlock->m_System.fBPII);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_BPECI), g_pPRBlock->m_System.fBPECI);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_SI), g_pPRBlock->m_System.fSI);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_LOLE), g_pPRBlock->m_System.fLOLE);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_MIEENS), g_pPRBlock->m_System.fMIslandEENS);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_AGCEENS), g_pPRBlock->m_System.fLossGenEENS);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_ELEENS), g_pPRBlock->m_System.fERLimitEENS);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_FLTGRADE0PROB), g_pPRBlock->m_System.fFltGrade0Prob);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_FLTGRADE1PROB), g_pPRBlock->m_System.fFltGrade1Prob);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_FLTGRADE2PROB), g_pPRBlock->m_System.fFltGrade2Prob);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_FLTGRADE3PROB), g_pPRBlock->m_System.fFltGrade3Prob);
	log_info("%s : %f", g_PRMemDBInterface.PRGetFieldDesp(PR_SYSTEM, PR_SYSTEM_FLTGRADE4PROB), g_pPRBlock->m_System.fFltGrade4Prob);



}

void adequacyEstimate() 
{
	clock_t	dBeg, dEnd;
	int		nDur;

	dBeg = clock();

	HANDLE threadHandle = g_PRAdeEstimate.SysAdequacyEstimate(g_pPRBlock,
		g_PRAdeSetting.nMultiThread,
		g_PRAdeSetting.fDc2AcFactor,
		g_PRAdeSetting.fMinIslandGLRatio,
		g_PRAdeSetting.bLineELimit,
		g_PRAdeSetting.bTranELimit,
		g_PRAdeSetting.bGenPELimit,
		g_PRAdeSetting.bUPFCELimit,
		g_PRAdeSetting.bAuxLoadAdjust,
		g_PRAdeSetting.bEQGenAdjust,
		g_PRAdeSetting.bEQLoadAdjust,
		g_PRAdeSetting.bUPFCAdjustRC);

	int nEstimateState = -1;
	int sum = g_pPRBlock->m_nRecordNum[PR_FSTATE];
	while (true)
	{
		if (nEstimateState + 1 >= sum)
			break;

		bool change = false;
		for (int i = nEstimateState + 1; i < sum; i++) {

			tagPRFState &state = g_pPRBlock->m_FStateArray[i];
			if (state.bEstimated)
			{
				change = true;
				nEstimateState = i;
			}
			else
				break;

		}

		if (change)
			log_info("current step : %d/%d.", nEstimateState, sum);

	}

	DWORD dwRet = WaitForSingleObject(threadHandle, INFINITE);

	dEnd = clock();
	nDur = (int)((1000.0*(double)(dEnd - dBeg)) / CLOCKS_PER_SEC);
	log_info("后评估完毕，耗时%d毫秒", nDur);

}


void StateEstimate::run(const char *configFile)
{
	///parse config
	Json::Reader	sReader;
	Json::Value		sRoot, sContent, sData, sNull(nullValue);
	string line;
	ifstream is;
	is.open(configFile);
	std::string content;
	if (is)
	{
		while (getline(is, line))
		{
			content.append(line);
			content.append("\n");
			
		}
		is.close();
	}
	else {
		log_error("Fail to open file:%s. ", configFile);
		return;
	}

	log_debug("content = \n %s .", content.c_str());

	
	if (!sReader.parse(content, sRoot, false))
	{
		
		log_error("fail to parse : %s , error:%s.", configFile, sReader.getFormatedErrorMessages().c_str());
		return;
	}
	
	//tagBpaPRAdequacySetting	sPRAdequacySetting;
	PRAdequacyBase::InitBpaPRAdequacySetting(&g_PRAdeSetting);
	ParsePRSetting(sRoot, &g_PRAdeSetting);	
	printSetting(&g_PRAdeSetting);

	///parse config end

	///init  memory
	if (initMem() < 0) {
		return;
	}

	///prepare data for calc reliability
	preparePRData();

	///sample
	sample();

	///system adequacy estimate
	adequacyEstimate();

	printAdequacyEstimateResult();
}	