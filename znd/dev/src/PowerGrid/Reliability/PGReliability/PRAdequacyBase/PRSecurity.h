#pragma once
#if _MSC_VER >= 1400 // VC++ 8.0
#pragma warning( disable : 4996 )   // disable warning about strdup being deprecated.
#endif

#include <direct.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../../../MemDB/BpaMemDB/BpaMemDB.h"
using	namespace	BpaMemDB;
#include "../../../../MemDB/PRMemDB/PRMemDB.h"
using	namespace	PRMemDB;

#include "../../../../Common/MFCControls/SimpleCurve.h"

namespace	PRAdequacyBase
{
#define	TM_ESTIMATEBEG	WM_APP+1001
#define	TM_ESTIMATING	WM_APP+1002
#define	TM_ESTIMATEEND	WM_APP+1003

	typedef	struct	_BpaPRSecuritySetting_
	{
		std::string		strBpaWorkDir;			//	软件工作目录，用于存放BPA等之间计算文件和最终计算结果文件，目前应用于安全性评价

		//////////////////////////////////////////////////////////////////////////
		//	曲线显示参数设置
		int				clrBackGround;			//	曲线背景颜色
		int				clrForeGround;			//	曲线网格颜色
		int				clrCurve;				//	曲线颜色
		int				clrAxias;				//	坐标颜色
		int				nXPace;					//	曲线X坐标步距
		int				nYPace;					//	曲线Y坐标步距

		//////////////////////////////////////////////////////////////////////////
		//	安全性评价参数设置
		int				nMinSsaLTFault;			//	安全性评价最小支路故障数
		int				nMaxSsaLTFault;			//	安全性评价最大支路故障数
		int				nMaxSsaState;			//	安全性评价最大评价状态数
		unsigned char	bLTFaultOnly;			//	安全性评价支路故障评价开关(=0，评价发电机+支路故障；=1，仅评价支路故障)
		float			fEndDT;					//	稳定计算时间
		//////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////
		//	稳定计算标准
		double	fCriteriaMaxAngle;				//	最大功角差
		double	fCriteriaMaxVolt;				//	最高电压
		double	fCriteriaMaxVDur;				//	最高电压持续时间
		double	fCriteriaMinVolt;				//	最低电压
		double	fCriteriaMinVDur;				//	最低电压持续时间
		double	fCriteriaMaxFreq;				//	最高频率
		double	fCriteriaMaxFDur;				//	最高频率持续时间
		double	fCriteriaMinFreq;				//	最低频率
		double	fCriteriaMinFDur;				//	最低频率持续时间

		double	fRealCriteriaMaxAngle;			//	最大功角差
		double	fRealCriteriaMaxVolt;			//	最高电压
		double	fRealCriteriaMaxVDur;			//	最高电压持续时间
		double	fRealCriteriaMinVolt;			//	最低电压
		double	fRealCriteriaMinVDur;			//	最低电压持续时间
		double	fRealCriteriaMaxFreq;			//	最高频率
		double	fRealCriteriaMaxFDur;			//	最高频率持续时间
		double	fRealCriteriaMinFreq;			//	最低频率
		double	fRealCriteriaMinFDur;			//	最低频率持续时间
		//////////////////////////////////////////////////////////////////////////

		unsigned char	bMutliThread;
		//short			nProcessNum;			//	进程数
		double			fDc2AcFactor;			//	直流潮流 2 交流潮流系数
		unsigned char	bGenBusLoadAsAux;		//	发电机母线负荷按厂用电处理
	}	tagBpaPRSecuritySetting;

	typedef	struct _RSFDevice
	{
		std::string	strFDevType;
		std::string	strFDevName;
		std::string	strFaultType;
		float		fFaultPos;
	}	tagRSFDevice;

	typedef	struct _RSResult 
	{
		int				nFStateNo;
		unsigned char	bMIsland;
		unsigned char	bLTFault;
		float			fLossGenP;
		std::string		strBseFile;
		std::string		strSwiFile;
		std::string		strOutFile;
		float			fStateProb;
		float			fStateDur;
		int				nStateNum;
		std::string		strSsaResult;

		std::vector<tagRSFDevice>	fDevArray;
	}	tagRSResult;

	typedef	struct _SecurityThreadInfo 
	{
		tagPRBlock*		pPRBlock;
#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
		DWORD			nMainThreadID;
#else
		pthread_t		nMainThreadID;
#endif
		unsigned char	bMultiThread;
	}	tagSecurityThreadInfo;


	class CPRSecurity
	{
	public:
		CPRSecurity(void);
		~CPRSecurity(void);

	public:
		tagBpaPRSecuritySetting	m_PRSecuritySetting;
		int		ReadBpaPRSecuritySetting(const char* lpszSettingFile);
		void	SaveBpaPRSecuritySetting();

	private:
		char	m_szDefaultSettingFile[260];
		void	InitBpaPRSecuritySetting(tagBpaPRSecuritySetting* pSetting);

	public:
		static CRITICAL_SECTION m_csLock;

	private:
		unsigned char	m_bEstimating;

		//////////////////////////////////////////////////////////////////////////
		//	安全评估
	public:	//	安全评估三个子函数
		int SecurityStateFill(tagPRBlock* pPRBlock, const vector<int>& nFStateArray);
		int SecurityStateFilter(tagPRBlock* pPRBlock, const int nMinSsaLTFault, const int nMaxSsaLTFault, const int nMaxSsaState, const int bLTFaultOnly);
		HANDLE SecurityEstimate(tagPRBlock* pPRBlock, tagBpaBlock* pBpaBlock, const char* lpszWorkDir, const float fEndDT, const unsigned char bMultiThread);
		void ExitSecurityEstimate(tagPRBlock* pPRBlock);

		tagSimpleCurve* GetBpaOutCurve(const char* lpszCurveName);

	private:
		int InitSecurityEstimate(tagPRBlock* pPRBlock, tagBpaBlock* pBpaBlock, const char* lpszWorkPath, const double fEndDT);

	public:
		void ReCalculateRSResult(const char* lpszRSResultDir, 
			const double fMaxAngle,		//	最大功角差
			const double fMaxVolt,		//	最高电压
			const double fMaxVDur,		//	最高电压持续时间
			const double fMinVolt,		//	最低电压
			const double fMinVDur,		//	最低电压持续时间
			const double fMaxFreq,		//	最高频率
			const double fMaxFDur,		//	最高频率持续时间
			const double fMinFreq,		//	最低频率
			const double fMinFDur);		//	最低频率持续时间
		int	IsBpaOutStable(const char* lpszOutFile, 
			const double fMaxAngle,		//	最大功角差
			const double fMaxVolt,		//	最高电压
			const double fMaxVDur,		//	最高电压持续时间
			const double fMinVolt,		//	最低电压
			const double fMinVDur,		//	最低电压持续时间
			const double fMaxFreq,		//	最高频率
			const double fMaxFDur,		//	最高频率持续时间
			const double fMinFreq,		//	最低频率
			const double fMinFDur);		//	最低频率持续时间
		int	ParseBpaOutFile(IN const char* lpszOutFile);

	private:
		void ResolveCurveName(const char* lpszLine, char* lpszCurveName);

	public:
		tagSimpleCurve	g_BpaOutCurveMaxAng;
		tagSimpleCurve	g_BpaOutCurveMinVolt;
		tagSimpleCurve	g_BpaOutCurveMaxVolt;
		tagSimpleCurve	g_BpaOutCurveMinFreq;
		tagSimpleCurve	g_BpaOutCurveMaxFreq;
		std::vector<tagSimpleCurve>	g_BpaOutCurveArray;

		//////////////////////////////////////////////////////////////////////////
		//	RSResult用的XML文件输入、输出
	public:
		void ReadRSResult(const char* lpszRSResultDir);
		void SaveRSResult(const char* lpszRSResultDir);

	public:
		int			m_nRSFState;
		int			m_nRSFSecurity;
		double		m_fPLOS;
		double		m_fFLOS;
		double		m_fMTTIS;
		std::vector<tagRSResult>	m_RSResultArray;

		//////////////////////////////////////////////////////////////////////////
	private:	//	Prepare用的子函数
		void FormFDeviceFMode(tagPRBlock* pPRBlock);		//	形成概率安全性参数

	private:	//	Prepare中FormSwiFiles及其用的子函数，用于形成SWI文件中的故障卡
		int	FormSwiFiles(tagPRBlock* pPRBlock, IN const char* lpszWorkDir, IN const char* lpszBaseFile, IN const char* lpszBpaSwiFile, const double fEndDT=300);

		void SortSsaFState(std::vector<tagPRFSecurity>& arySsaFState, int nDn0, int nUp0);
		void FillFltString(const int nType, const int nIni, const int nEnd, const int nLen, char* lpszValue, char* lpszString);
		int FormFltGenTrip(const char* lpszBus, const float fkV, const char cId, std::vector<std::string>& strFltArray);
		int	FormFltBranTrip(const char* lpszBusI, const float fkVI, const char* lpszBusJ, const float fkVJ, const char cLoop, const float fTFlt, std::vector<std::string>& strFltArray);
		int	FormFltLineSC1(const char* lpszBusI, const float fkVI, const char* lpszBusJ, const float fkVJ, const char cLoop, const float fTFlt, const float fT1TripI, const float fT1TripJ, const float fT1CloseI, const float fT1CloseJ, const float fT3TripI, const float fT3TripJ, const unsigned char nFltPos, std::vector<std::string>& strFltArray);
		int	FormFltTranSC1(const char* lpszBusI, const float fkVI, const char* lpszBusJ, const float fkVJ, const char cLoop, const float fTFlt, const float fT3TripI, const float fT3TripJ, const unsigned char nFltPos, std::vector<std::string>& strFltArray);
		int	FormFltBranSC2(const char* lpszBusI, const float fkVI, const char* lpszBusJ, const float fkVJ, const char cLoop, const float fTFlt, const float fT3TripI, const float fT3TripJ, const unsigned char nFltPos, std::vector<std::string>& strFltArray);
		int	FormFltBranSC3(const char* lpszBusI, const float fkVI, const char* lpszBusJ, const float fkVJ, const char cLoop, const float fTFlt, const float fTTripI, const float fTTripJ, const unsigned char nFltPos, std::vector<std::string>& strFltArray);
		int	FormFltBranSC4(const char* lpszBusI, const float fkVI, const char* lpszBusJ, const float fkVJ, const char cLoop, const float fTFlt, const float fT3TripI, const float fT3TripJ, const unsigned char nFltPos, std::vector<std::string>& strFltArray);

		int	ClearSsaFiles(const char* lpszWorkDir, IN const char* lpszBpaSwiFile);
		//////////////////////////////////////////////////////////////////////////
		//	兼容以前版本的输出，两个函数唯一区别在于输出变量后者输出类变量，前者输出内存数据库变量
	public:
		void WriteSecurityResult(tagPRBlock* pPRBlock, const char* lpszFileName, const char* lpszCaseName, const char* lpszRaiFile, const char* lpszDatFile, const char* lpszSwiFile, const char* lpszRmlFile, const char* lpszCriFile, const int nDur);
		void WriteRSResult      (tagPRBlock* pPRBlock, const char* lpszFileName, const char* lpszCaseName, const char* lpszRaiFile, const char* lpszDatFile, const char* lpszSwiFile, const char* lpszRmlFile, const char* lpszCriFile, const int nDur);
	};
}
