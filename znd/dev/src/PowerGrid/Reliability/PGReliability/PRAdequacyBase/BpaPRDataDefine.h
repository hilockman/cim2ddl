#pragma once

#include <vector>
using namespace std;

#include "../../../../MemDB/PRMemDB/PRMemDB.h"
using	namespace	PRMemDB;

namespace	PRAdequacyBase
{
	//////////////////////////////////////////////////////////////////////////
	//	可靠性计算参数，呼应的是窗口的控制变量
	typedef	struct	_BpaPRAdequacySetting_
	{
		std::string		strBpaDatFile;				//	潮流输入文件
		std::string		strBpaSwiFile;				//	稳定输入文件，主要是用于形成发电机模型
		std::string		strBpaRParamFile;			//	可靠性参数输入文件

		//////////////////////////////////////////////////////////////////////////
		//	环辐网分解和小支路清除
		double			fTinyGenThreshold;		//	环辐网分解发电机容量门槛值（容量低于该门槛值的发电机认为不是发电机）
		double			fLowVoltThreshold;		//	环辐网分解发电机低电压门槛值（电压低于该门槛值的发电机认为是负荷而不是发电）
		double			fZIL;					//	小阻抗清除小阻抗门槛值
		//////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////
		//	可靠性抽样参数设置
		unsigned char	nPRSampleObject;
		unsigned char	nPRSampleMethod;			//	抽样类型
		int				nMaxGenFault;			//	MCS, FST, STS, ANA 抽样最大发电机故障重数
		int				nMaxBranFault;			//	MCS, FST, STS, ANA 抽样最大支路故障重数
		unsigned char	bLineELimit;			//	线路消限开关
		unsigned char	bTranELimit;			//	主变消限开关
		unsigned char	bGenPELimit;
		unsigned char	bUPFCELimit;

		unsigned char	bAuxLoadAdjust;			//	厂用电负荷参与调整
		unsigned char	bEQGenAdjust;
		unsigned char	bEQLoadAdjust;

		int				nMCSSimulateTime;		//	MCS最大抽样仿真时长
		double			fMCSMinStateProb;		//	MCS[蒙特卡罗]设备故障概率门槛值
		double			fFSTMaxCumuProb;		//	FST[快速排序]累积概率
		double			fFSTMinStateProb;		//	FST[快速排序]设备故障概率门槛值
		int				nFSTMaxStateNum;		//	FST[快速排序]最大状态数
		int				nSTSMaxStateNum;		//	STS[状态抽样]最大状态数
		double			fANAMinStateProb;		//	ANA[ 解析法 ]设备故障概率门槛值
		//////////////////////////////////////////////////////////////////////////

		double			fDc2AcFactor;			//	直流潮流 2 交流潮流系数
		double			fMinIslandGLRatio;		//	孤岛的最小容载比
		unsigned char	nMultiThread;
		unsigned char	bUPFCAdjustRC;

		unsigned char	bGenBusLoadAsAux;		//	发电机母线负荷按厂用电处理
	}	tagBpaPRAdequacySetting;

	typedef	struct _AdequacyThreadInfo 
	{
		int				nThreadID;
		tagPRBlock*		pPRBlock;
#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
		unsigned long	nParentThreadID;
#else
		pthread_t		nParentThreadID;
#endif

		unsigned char	bMultiThread;
		double			fAC2DCFactor;
		double			fMinGLRatio;
		unsigned char	bLineEOvl;
		unsigned char	bTranEOvl;
		unsigned char	bGenEOvl;
		unsigned char	bUPFCEOvl;
		unsigned char	bAuxLoadAdjust;
		unsigned char	bEQGenAdjust;
		unsigned char	bEQLoadAdjust;

		unsigned char	bUPFCAdjustRC;

		char			szResultXmlFile[260];
	}	tagAdequacyThreadInfo;
}
