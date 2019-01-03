#pragma once
#if _MSC_VER >= 1400 // VC++ 8.0
#pragma warning( disable : 4996 )   // disable warning about strdup being deprecated.
#endif
#include <Windows.h>

#include "../../../DCNetwork/DCNetwork.h"
using	namespace	DCNetwork;

#include "BpaPRDataDefine.h"
#include "PRAdequacyBaseExp.h"

namespace	PRAdequacyBase
{
	static const char*	g_lpszGenRResultFileName ="GenRAdequacyResult.xml";
	static const char*	g_lpszSysRResultFileName ="SysRAdequacyResult.xml";

	class PRADEQUACYBASE_EXP CPRAdequacyEstimate
	{
	public:
		CPRAdequacyEstimate(void);
		~CPRAdequacyEstimate(void);

	public:
		void	AdjustDeviceRated(tagPRBlock* pPRBlock, const double fDC2ACRatio, const unsigned char bUPFCAdjustRC);

	public:	//	����������
		static CRITICAL_SECTION m_csLock;

	private:
		unsigned char	m_bEstimating;

		//////////////////////////////////////////////////////////////////////////
		//	״̬������

	public:	//	����ϵͳ�ɿ�������	
		void InitAdequacyXmlFile(const char* lpszXmlFileName, const char* lpszRootTag);
		void ExitAdequacyXmlFile(const char* lpszXmlFileName, const char* lpszRootTag);
		void InitAdequacyEstimate(tagPRBlock* pPRBlock);
		void ExitAdequacyEstimate(tagPRBlock* pPRBlock, const double fAc2DcFactor, const char* lpszResultXmlFile);

		HANDLE GenAdequacyEstimate(tagPRBlock* pPRBlock,
			const unsigned char nMultiThread,
			const char* lpszResultFileName = NULL);	//	����MCS�ķ���ϵͳ�ɿ���
		HANDLE SysAdequacyEstimate(tagPRBlock* pPRBlock,
			const unsigned char nMultiThread,
			const double fDC2ACRatio,
			const double fMinGLRatio,
			const unsigned char bLineEOvl,
			const unsigned char bTranEOvl,
			const unsigned char bGenPEOvl,
			const unsigned char bUPFCEOvl,
			const unsigned char bAuxLoadAdjust,
			const unsigned char	bEQGenAdjust,
			const unsigned char	bEQLoadAdjust,
			const unsigned char bUPFCAdjustRC,
			const char* lpszRResultFileName = NULL);//	�����ϵͳ�ɿ�������	

	private:
		void SaveAdequacyEstimateResult(tagPRBlock* pPRBlock, const char* lpszResultFileName);
		double ResolveDevELmtCutEnergy(tagPRBlock* pPRBlock, const int nDevType, const char* lpszDevName)	;	//{	return 0;	};	//�γ��豸Խ�����޵���

#ifdef _DEBUG
		void SaveCompPRParam(tagPRBlock* pPRBlock)	;//	{};	//	����ʹ�ã�Ŀ����Ϊ�˼�¼�豸�ɿ��Բ���
#endif

	public:	//	ָ���ļ���������
		void WriteAdequacyResult(tagPRBlock* pPRBlock, const char* lpszFileName, const char* lpszCaseName, const char* lpszRaiFile, const char* lpszDatFile, const char* lpszSwiFile, const char* lpszRmlFile, const int nDur);
	};
}
extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, char* pformat, ...);
