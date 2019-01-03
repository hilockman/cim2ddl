#pragma once

#include <vector>
using namespace std;

#include "../../../../MemDB/PRMemDB/PRMemDB.h"
using	namespace	PRMemDB;

namespace	PRAdequacyBase
{
	//////////////////////////////////////////////////////////////////////////
	//	�ɿ��Լ����������Ӧ���Ǵ��ڵĿ��Ʊ���
	typedef	struct	_BpaPRAdequacySetting_
	{
		std::string		strBpaDatFile;				//	���������ļ�
		std::string		strBpaSwiFile;				//	�ȶ������ļ�����Ҫ�������γɷ����ģ��
		std::string		strBpaRParamFile;			//	�ɿ��Բ��������ļ�

		//////////////////////////////////////////////////////////////////////////
		//	�������ֽ��С֧·���
		double			fTinyGenThreshold;		//	�������ֽⷢ��������ż�ֵ���������ڸ��ż�ֵ�ķ������Ϊ���Ƿ������
		double			fLowVoltThreshold;		//	�������ֽⷢ����͵�ѹ�ż�ֵ����ѹ���ڸ��ż�ֵ�ķ������Ϊ�Ǹ��ɶ����Ƿ��磩
		double			fZIL;					//	С�迹���С�迹�ż�ֵ
		//////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////
		//	�ɿ��Գ�����������
		unsigned char	nPRSampleObject;
		unsigned char	nPRSampleMethod;			//	��������
		int				nMaxGenFault;			//	MCS, FST, STS, ANA ������󷢵����������
		int				nMaxBranFault;			//	MCS, FST, STS, ANA �������֧·��������
		unsigned char	bLineELimit;			//	��·���޿���
		unsigned char	bTranELimit;			//	�������޿���
		unsigned char	bGenPELimit;
		unsigned char	bUPFCELimit;

		unsigned char	bAuxLoadAdjust;			//	���õ縺�ɲ������
		unsigned char	bEQGenAdjust;
		unsigned char	bEQLoadAdjust;

		int				nMCSSimulateTime;		//	MCS����������ʱ��
		double			fMCSMinStateProb;		//	MCS[���ؿ���]�豸���ϸ����ż�ֵ
		double			fFSTMaxCumuProb;		//	FST[��������]�ۻ�����
		double			fFSTMinStateProb;		//	FST[��������]�豸���ϸ����ż�ֵ
		int				nFSTMaxStateNum;		//	FST[��������]���״̬��
		int				nSTSMaxStateNum;		//	STS[״̬����]���״̬��
		double			fANAMinStateProb;		//	ANA[ ������ ]�豸���ϸ����ż�ֵ
		//////////////////////////////////////////////////////////////////////////

		double			fDc2AcFactor;			//	ֱ������ 2 ��������ϵ��
		double			fMinIslandGLRatio;		//	�µ�����С���ر�
		unsigned char	nMultiThread;
		unsigned char	bUPFCAdjustRC;

		unsigned char	bGenBusLoadAsAux;		//	�����ĸ�߸��ɰ����õ紦��
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

		unsigned char	nMultiThread;
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
