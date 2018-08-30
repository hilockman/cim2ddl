#pragma once
#if _MSC_VER >= 1400 // VC++ 8.0
#pragma warning( disable : 4996 )   // disable warning about strdup being deprecated.
#endif

#include <float.h>
#include <vector>
using namespace std;
#include "../../../../MemDB/PRMemDB/PRMemDB.h"
using namespace PRMemDB;

namespace	PRAdequacyBase
{
	static	const char*	g_lpszCoptResultFileName ="CoptAdequacyResult.xml";

	class CPRCopTable
	{
	public:
		CPRCopTable(void);
		~CPRCopTable(void);

	public:
		std::vector<tagPRCopTable>		m_CopTabArray;
		void	CopInit(tagPRBlock* pPRBlock, const double fPStep);
		void	CopTable(tagPRBlock* pPRBlock, const double fPStep, const char* lpszCoptResultFile = NULL);

	private:
		void	SortCopGenCapacity(tagPRBlock* pPRBlock, int nDn0, int nUp0);
		void	CopStep(tagPRBlock* pPRBlock, const double fPStep, const double fPrevCapacity, const int nAGen);	//	×´Ì¬¸ÅÂÊµÝ¹é

	private:
		void	CoptExpriment1(tagPRBlock* pPRBlock);
		void	CoptExpriment2(tagPRBlock* pPRBlock);
		void	CoptExpriment3(tagPRBlock* pPRBlock);
		void	CoptExpriment4(tagPRBlock* pPRBlock);
		void	CoptExpriment5(tagPRBlock* pPRBlock);

		void	SaveCoptXml(tagPRBlock* pPRBlock, const char* lpszResultFileName);
	};

	inline double	Factorial(const int nNumber)
	{
		register int	i;
		double	fBuf=1.0;
		for (i=1; i<=nNumber; i++)
			fBuf *= i;

		return fBuf;
	}
}
