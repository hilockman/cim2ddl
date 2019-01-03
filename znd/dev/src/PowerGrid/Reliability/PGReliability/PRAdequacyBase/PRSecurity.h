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
		char			szBpaWorkDir[260];			//	�������Ŀ¼�����ڴ��BPA��֮������ļ������ռ������ļ���ĿǰӦ���ڰ�ȫ������

		//////////////////////////////////////////////////////////////////////////
		//	������ʾ��������
		int				clrBackGround;			//	���߱�����ɫ
		int				clrForeGround;			//	����������ɫ
		int				clrCurve;				//	������ɫ
		int				clrAxias;				//	������ɫ
		int				nXPace;					//	����X���경��
		int				nYPace;					//	����Y���경��

		//////////////////////////////////////////////////////////////////////////
		//	��ȫ�����۲�������
		int				nMinSsaLTFault;			//	��ȫ��������С֧·������
		int				nMaxSsaLTFault;			//	��ȫ���������֧·������
		int				nMaxSsaState;			//	��ȫ�������������״̬��
		unsigned char	bLTFaultOnly;			//	��ȫ������֧·�������ۿ���(=0�����۷����+֧·���ϣ�=1��������֧·����)
		float			fEndDT;					//	�ȶ�����ʱ��
		//////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////
		//	�ȶ������׼
		double	fCriteriaMaxAngle;				//	��󹦽ǲ�
		double	fCriteriaMaxVolt;				//	��ߵ�ѹ
		double	fCriteriaMaxVDur;				//	��ߵ�ѹ����ʱ��
		double	fCriteriaMinVolt;				//	��͵�ѹ
		double	fCriteriaMinVDur;				//	��͵�ѹ����ʱ��
		double	fCriteriaMaxFreq;				//	���Ƶ��
		double	fCriteriaMaxFDur;				//	���Ƶ�ʳ���ʱ��
		double	fCriteriaMinFreq;				//	���Ƶ��
		double	fCriteriaMinFDur;				//	���Ƶ�ʳ���ʱ��

		double	fRealCriteriaMaxAngle;			//	��󹦽ǲ�
		double	fRealCriteriaMaxVolt;			//	��ߵ�ѹ
		double	fRealCriteriaMaxVDur;			//	��ߵ�ѹ����ʱ��
		double	fRealCriteriaMinVolt;			//	��͵�ѹ
		double	fRealCriteriaMinVDur;			//	��͵�ѹ����ʱ��
		double	fRealCriteriaMaxFreq;			//	���Ƶ��
		double	fRealCriteriaMaxFDur;			//	���Ƶ�ʳ���ʱ��
		double	fRealCriteriaMinFreq;			//	���Ƶ��
		double	fRealCriteriaMinFDur;			//	���Ƶ�ʳ���ʱ��
		//////////////////////////////////////////////////////////////////////////

		unsigned char	bMutliThread;
		//short			nProcessNum;			//	������
		double			fDc2AcFactor;			//	ֱ������ 2 ��������ϵ��
		unsigned char	bGenBusLoadAsAux;		//	�����ĸ�߸��ɰ����õ紦��
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
		int		ReadBpaPRSecuritySetting(const char* lpszSettingFile, tagBpaPRSecuritySetting* pSsaSetting);
		void	SaveBpaPRSecuritySetting(tagBpaPRSecuritySetting* pSsaSetting);

	private:
		char	m_szDefaultSettingFile[260];
		void	InitBpaPRSecuritySetting(tagBpaPRSecuritySetting* pSetting);

	public:
		static CRITICAL_SECTION m_csLock;

	private:
		unsigned char	m_bEstimating;

		//////////////////////////////////////////////////////////////////////////
		//	��ȫ����
	public:	//	��ȫ���������Ӻ���
		int SecurityStateFill(tagPRBlock* pPRBlock, const vector<int>& nFStateArray);
		int SecurityStateFilter(tagPRBlock* pPRBlock, const int nMinSsaLTFault, const int nMaxSsaLTFault, const int nMaxSsaState, const int bLTFaultOnly);
		HANDLE SecurityEstimate(tagPRBlock* pPRBlock, tagBpaBlock* pBpaBlock, const char* lpszWorkDir, const float fEndDT, const unsigned char bMultiThread);
		void ExitSecurityEstimate(tagPRBlock* pPRBlock);

		tagSimpleCurve* GetBpaOutCurve(const char* lpszCurveName);

	private:
		int InitSecurityEstimate(tagPRBlock* pPRBlock, tagBpaBlock* pBpaBlock, const char* lpszWorkPath, const double fEndDT);

	public:
		void ReCalculateRSResult(const char* lpszRSResultDir, 
			const double fMaxAngle,		//	��󹦽ǲ�
			const double fMaxVolt,		//	��ߵ�ѹ
			const double fMaxVDur,		//	��ߵ�ѹ����ʱ��
			const double fMinVolt,		//	��͵�ѹ
			const double fMinVDur,		//	��͵�ѹ����ʱ��
			const double fMaxFreq,		//	���Ƶ��
			const double fMaxFDur,		//	���Ƶ�ʳ���ʱ��
			const double fMinFreq,		//	���Ƶ��
			const double fMinFDur);		//	���Ƶ�ʳ���ʱ��
		int	IsBpaOutStable(const char* lpszOutFile, 
			const double fMaxAngle,		//	��󹦽ǲ�
			const double fMaxVolt,		//	��ߵ�ѹ
			const double fMaxVDur,		//	��ߵ�ѹ����ʱ��
			const double fMinVolt,		//	��͵�ѹ
			const double fMinVDur,		//	��͵�ѹ����ʱ��
			const double fMaxFreq,		//	���Ƶ��
			const double fMaxFDur,		//	���Ƶ�ʳ���ʱ��
			const double fMinFreq,		//	���Ƶ��
			const double fMinFDur);		//	���Ƶ�ʳ���ʱ��
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
		//	RSResult�õ�XML�ļ����롢���
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
	private:	//	Prepare�õ��Ӻ���
		void FormFDeviceFMode(tagPRBlock* pPRBlock);		//	�γɸ��ʰ�ȫ�Բ���

	private:	//	Prepare��FormSwiFiles�����õ��Ӻ����������γ�SWI�ļ��еĹ��Ͽ�
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
		//	������ǰ�汾���������������Ψһ�����������������������������ǰ������ڴ����ݿ����
	public:
		void WriteSecurityResult(tagPRBlock* pPRBlock, const char* lpszFileName, const char* lpszCaseName, const char* lpszRaiFile, const char* lpszDatFile, const char* lpszSwiFile, const char* lpszRmlFile, const char* lpszCriFile, const int nDur);
		void WriteRSResult      (tagPRBlock* pPRBlock, const char* lpszFileName, const char* lpszCaseName, const char* lpszRaiFile, const char* lpszDatFile, const char* lpszSwiFile, const char* lpszRmlFile, const char* lpszCriFile, const int nDur);
	};
}
