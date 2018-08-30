#pragma once
#pragma warning( disable: 4251 )

#include <float.h>
#include "../../MemDB/PGMemDB/PGMemDB.h"
using	namespace	PGMemDB;

#include "../../MemDB/PRMemDB/PRMemDB.h"
using	namespace	PRMemDB;

#define	UPFC_MODE_NO		0
#define	UPFC_MODE_UPFC		1

#include "dcnetworkexp.h"

namespace DCNetwork
{
	const int	MaxBPerBus=40;
	const int	g_bWriteDebug=0;

	const	double	g_fDCNMvaBase_500=1082;
	const	double	g_fDCNMvaBase_330=686;
	const	double	g_fDCNMvaBase_220=305;
	const	double	g_fDCNMvaBase_110=114;

	const	double	g_fTripDeltPThreshold=1;

	class  DCNETWORK_EXP	CDCNetwork
	{
	public:
		CDCNetwork(void);
		~CDCNetwork(void);

	public:
		//	直流潮流
		void	PGDCFlow(tagPGBlock* pPGBlock);																	//	面向电网数据库的

		void	PRDCFlow(tagPRBlock* pPRBlock, const unsigned char nUPFCControlMode, const int nRadial=0);		//	面向可靠性数据库的
		void	PRDCFlowSolve(tagPRBlock* pPRBlock);
		void	PRDCMatZ(tagPRBlock* pPRBlock, const int nRadial, std::vector<float>& fMatZArray);				//	阻抗矩阵

		//	潮流法开断计算
		void	PRDCTrip(tagPRBlock* pPRBlock, const int nDevType, const char* lpszDevName);
		void	PRDCTrip(tagPRBlock* pPRBlock, const int nDevType, const int nDevIndex);

	public:
		void	PRDCNetwork_SaveDataFile(tagPRBlock* pPRBlock, const char* lpszFileName);
		int		PRDCNetwork_ReadDataFile(tagPRBlock* pPRBlock, const char* lpszFileName);

	private:	//	导纳矩阵生成、矩阵前代回带等
		int		PGDCNetwork_ReadData(tagPGBlock* pPGBlock, const int nIsland);
		void	PGDCIslandFlowOut(tagPGBlock* pPGBlock, const int nIsland=1, const unsigned char bTripFlow=0);

	private:	//	直流潮流子程序
		int		PRDCNetwork_ReadData(tagPRBlock* pPRBlock, const unsigned char nUPFCControlMode, const int nIsland);
		int		PRDCNetwork_ReadRadial(tagPRBlock* pPRBlock, const int nRadial);

		void	PRIslandMatZ(tagPRBlock* pPRBlock, const int nIsland=1);
		void	PRRadialMatZ(tagPRBlock* pPRBlock, const int nRadial);
		void	PRCheckMatZ(tagPRBlock* pPRBlock, const int nIsland);

		void	PRDCIslandFlowOut(tagPRBlock* pPRBlock, const unsigned char nUPFCControlMode, const int nIsland=1, const unsigned char bTripFlow=0);
		void	PRDCRadialFlowOut(tagPRBlock* pPRBlock, const int nRadial);


	private:	//	无用
		void	PRFlowIslandDFactor(tagPRBlock* pPRBlock, const int nIsland=1);	//	潮流法支路节点功率分布因子, 目前暂时停用
		void	PRFlowDFactorFBIterate(const int nBus);

	private:
		void	DCNetwork_Rename();
		void	DCNetwork_NewZ();
		void	DCNetwork_Admitance();
		void	DCNetwork_CholeskyDecompose();
		void	DCNetwork_Injection();
		void	DCNetwork_BackwardSubstitution();

	//	阻抗矩阵
		void	DCNetwork_InvEliminate();
		void	DCNetwork_InvImpedance();

	private:
		void	EmptyDataBuffer();
		void	AllocDataBuffer(const int nMaxBus);

		//	直流潮流计算用数据，采用独立数据空间设计，方便后续多进程改造
	private:
		int		m_nSlackBus;
		int		m_nNumBus;
		int		m_nMaxBusNumber;

		int		m_nNumBra;
		std::vector<double>	m_fZArray;		//double	m_fZArray[4*DCN_MaxBran];
		int		m_nNumGen;
		std::vector<double>	m_fGenArray;	//double	m_fGenArray[3*DCN_MaxUnit];
		int		m_nNumLoad;
		std::vector<double>	m_fLoadArray;	//double	m_fLoadArray[3*DCN_MaxLoad];

		//	中间数据
		std::vector<int>	m_nBusOld;		//int		m_nBusOld[DCN_MaxBus];				//	节点号从1开始编号 1<=n  n<=Max
		std::vector<int>	m_nBusNew;		//int		m_nBusNew[DCN_MaxBus];				//	节点编号优化

		std::vector<double>	m_fMatrixD;		//double	m_fMatrixD[DCN_MaxBus];				//	对角元
		std::vector<double>	m_fMatrixU;		//double	m_fMatrixU[20*DCN_MaxBus];			//	上三角非零元
		std::vector<int>	m_nMatrixIU;	//int		m_nMatrixIU[20*DCN_MaxBus];			//	上三角非零元列号
		int		m_nNumUTri;							//	上三角元素个数

		std::vector<double>	m_fBII;			//double	m_fBII[DCN_MaxBus];					//	导纳阵对角元，自导纳
		std::vector<double>	m_fWkRow;		//double	m_fWkRow[DCN_MaxBus];				//	工作行

		std::vector<int>	m_nNumFD;		//int		m_nNumFD[DCN_MaxBus];				//	每行非零元个数
		std::vector<int>	m_nNumDZ;		//int		m_nNumDZ[DCN_MaxBus];				//	增量存储每个节点的连接支路数

		std::vector<double>	m_fBusD;		//double	m_fBusD[DCN_MaxBus];				//	功角计算结果

		std::vector<int>	m_nNOB;			//int		m_nNOB[DCN_MaxBus];					//	中间变量，防止分配不出内存
		std::vector<int>	m_nNOCN;		//int		m_nNOCN[MaxBPerBus*DCN_MaxBus];	//	从0开始编号
		std::vector<int>	m_nNDS;			//int		m_nNDS[DCN_MaxBus];					//	每个节点的连接支路数，每个支路取小节点号的

		//	阻抗矩阵，因阻抗矩阵空间要求太大，采用变长设计
	private:
		std::vector<float>	m_fMatZ;		//	逆矩阵
	};
	extern	const	char*	g_lpszDCNetworkLogFile;
}
