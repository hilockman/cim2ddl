#pragma once
#include <math.h>
#include <float.h>
#include "../../MemDB/PGMemDB/PGMemDB.h"
using namespace PGMemDB;

#if defined(__GNUG__) || defined(__GNUC__)	// GCC编译器预定义的宏
#	ifndef DISALIGN
#		define DISALIGN __attribute__((packed))
#	endif
#else
#	define DISALIGN
#	if (defined(_AIX) || defined(AIX))
#		pragma align(packed)
#	else
#		if (!defined(sun) && !defined(__sun) && !defined(__sun__))
#			pragma pack(push)
#		endif
#	endif
#	pragma pack(1)
#endif

//////////////////////////////////////////////////////////////////////////
//	基本算法用的数据结构定义
typedef	struct	_PGEdge_
{
	unsigned char	nDevType;
	int		nDevIndex;

	float	fRerr;		//	设备故障率
	float	fTrep;		//	设备修复时间
	float	fRchk;		//	设备检修率
	float	fTchk;		//	设备检修时间

	float	fRSwitch;	//	设备切换成功率
	float	fTSwitch;	//	设备切换时间

	float	fLength;	//	路径长度
	//std::string	strDevSub;
	//std::string	strDevVolt;
	//std::string	strDevName;
}	tagPGEdge;

typedef	struct	_PGRouter_
{
	unsigned char	bMarked;	//	标记位，用于显示
	unsigned char	bRouter;	//	路径标记
	int		nDeep;				//	路径起始点的深度
	int		nFrNode;			//	构成本路径起始节点
	int		nToNode;			//	构成本路径终止节点
	float	fLength;			//	路径长度
	double	fR;					//	等效停运率
	double	fT;					//	等效停运时间
	std::vector<tagPGEdge>	edgeArray;	//	连接FrNode和ToNode的边集合
}	tagPGRouter;

typedef	struct	_PGSource_
{
	int		nEndNode;					//	末端节点
	float	fEndLength;					//	从起点～末端的总长度
	unsigned char	nEndingType;		//	末端设备类型
	int		nDevIndex;					//	末端设备索引
}	tagPGSource;					//	路径终点

//////////////////////////////////////////////////////////////////////////
//	负荷电源追溯和电源供电路径的数据结构定义
typedef	struct _PGLoadTraceSource		//	负荷追溯电源
{
	std::string	strLoad;
	float		fLoadMva;
	float		fRadius;
	std::vector<tagPGRouter>	sRArray;
	std::vector<tagPGSource>	sSArray;
}	tagPGLoadTraceSource;

typedef	struct _PGSourceRouteLoad		//	电源~负荷供电路径
{
	std::string					strSource;		//	电源名称
	tagPGSource					infSource;		//	电源信息
	float						fRadius;
	std::vector<tagPGRouter>	sRArray;		//	电源到负荷的路径（按深度排序）

	double	fR;	//	电源路径故障率
	double	fT;	//	电源路径每次停电平均持续时间
	double	fU;	//	电源路径修复时间
}	tagPGSourceRouteLoad;

typedef	struct _PGLoadSourceRouter		//	负荷的电源供电路径集合
{
	std::string	strLoad;
	float		fLoadMva;
	float		fRadius;
	std::vector<tagPGSourceRouteLoad>	sSArray;
}	tagPGLoadSourceRouter;

#if !defined(__GNUG__) && !defined(__GNUC__)
#	pragma pack()
#	if (defined(_AIX) || defined(AIX))
#		pragma align(fPower)
#	else
#		if (!defined(sun) && !defined(__sun) && !defined(__sun__))
#			pragma pack(pop)
#		endif
#	endif
#endif

//	PGTraceSource
//		1、深度优先搜索点集合；
//		2、形成点与点之间边集合
//		3、搜索到电源或者边界点返回
class CPGTraceAlgorithm
{
public:
	CPGTraceAlgorithm(void);
	~CPGTraceAlgorithm(void);

//////////////////////////////////////////////////////////////////////////
//	基本算法
public:
	void PGTraceSource	(tagPGBlock* pPGBlock, const int bCheckOpen, const int nStartNode, std::vector<int>& nBoundNodeArray, std::vector<tagPGRouter>& routerArray, std::vector<tagPGSource>& endingArray);
	void PGTraceRange	(tagPGBlock* pPGBlock, const int bCheckOpen, const int nStartNode, std::vector<int>& nBoundNodeArray, std::vector<tagPGRouter>& routerArray, std::vector<tagPGSource>& endingArray);

private:
	int	IsNodeSource(tagPGBlock* pPGBlock, const int nJudgeNode);
	void RouterRecursive(tagPGBlock* pPGBlock, const int bCheckOpen, tagPGSource& routerEnd, std::vector<tagPGRouter>& routerArray);
	void TraceJoint(tagPGBlock* pPGBlock, const int bCheckOpen, const int nIniNode, int nDeep, std::vector<tagPGRouter>& routerArray, std::vector<tagPGSource>& endingArray);
	//	深度优先搜索
private:
	//	形成nNodeI和nNodeJ之间的所有边设备集合，返回边长度(取最小值)
	float FormRouterEdge(tagPGBlock* pPGBlock, const unsigned char bCheckOpen, const int nNodeI, const int nNodeJ, std::vector<tagPGEdge>& edgeArray);

	void InitializePGRouterSet(tagPGRouter& rBuf)
	{
		rBuf.bMarked = 0;	//	正向回溯标记
		rBuf.bRouter = 0;	//	反向回溯标记
		rBuf.nDeep = 0;		//	路径离起始点的深度
		rBuf.nFrNode = -1;	//	构成本路径起始节点
		rBuf.nToNode = -1;	//	构成本路径终止节点
		rBuf.fLength = 0;
		rBuf.fR = 0;		//	等效停运率
		rBuf.fT = 0;		//	等效停运时间

		rBuf.edgeArray.clear();
	}

private:
	std::vector<unsigned char>	m_bNodeProcArray;

//////////////////////////////////////////////////////////////////////////
//	功能算法
public:
	void FormLoadSourceTracer(IN tagPGBlock* pPGBlock, IN const unsigned char bCheckOpen, OUT std::vector<tagPGLoadTraceSource>& sLoadTraceSourceArray);
	void FormSourceLoadRouter(IN tagPGBlock* pPGBlock, IN std::vector<tagPGLoadTraceSource>& sLoadTraceSourceArray, OUT std::vector<tagPGLoadSourceRouter>& sLoadSourceRouterArray);
	void SourceLoadRouterReliable(IN OUT std::vector<tagPGLoadSourceRouter>& sLoadSourceRouterArray);

private:
	int FindSourceRouter(const int nSourceNode, std::vector<tagPGRouter>& sRArray);
};
