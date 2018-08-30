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