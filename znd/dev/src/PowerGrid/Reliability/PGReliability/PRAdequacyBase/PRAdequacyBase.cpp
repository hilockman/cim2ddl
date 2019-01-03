#include <process.h>
#include "../../../../MemDB/PRMemDB/PRMemDB.h"
using namespace PRMemDB;
#include "PRAdequacyBase.h"
#include "../../../../MemDB/BpaMemDB/BpaMemDB.h"
using namespace BpaMemDB;

namespace	PRAdequacyBase
{
	CPRMemDBInterface	g_PRMemDBInterface;
	CBpaMemDBInterface	g_BpaMemDBInterface;
	std::vector<tagPRMCSampleState>	g_PRMCSSampleStateArray;

	int AppendMStateParam(tagPRBlock* pPRBlock, tagPRDevMState* pMState)
	{
		register int	i, j;
		int		nFreq;
		unsigned char	bExist=0;
		double	fBuffer;
		double*	pfRate=&pMState->fState1Rate;
		double*	pfProb=&pMState->fState1Prob;
		double*	pfFreq=&pMState->fState1Freq1;

		if (pMState->nStateNum <= 0)
		{
			//::MessageBox(NULL, "多状态模型状态数 = 0", "添加多状态模型", MB_OK|MB_SYSTEMMODAL|MB_ICONERROR);
			return 0;
		}

		for (i=0; i<pPRBlock->m_nRecordNum[PR_DEVMSTATE]; i++)
		{
			if (pPRBlock->m_DevMStateArray[i].nType == pMState->nType && _stricmp(pPRBlock->m_DevMStateArray[i].szName, pMState->szName) == 0)
			{
				bExist=1;
				break;
			}
		}
		if (bExist)
		{
			//::MessageBox(NULL, "该多状态模型已经存在", "添加多状态模型", MB_OK|MB_SYSTEMMODAL|MB_ICONERROR);
			return 0;
		}

		for (i=0; i<pMState->nStateNum; i++)
		{
			for (j=i+1; j<pMState->nStateNum; j++)
			{
				if (pfRate[i] > pfRate[j])
				{
					fBuffer = pfRate[i];
					pfRate[i] = pfRate[j];
					pfRate[j] = fBuffer;

					fBuffer = pfProb[i];
					pfProb[i] = pfProb[j];
					pfProb[j] = fBuffer;

					for (nFreq=0; nFreq<pMState->nStateNum; nFreq++)
					{
						fBuffer = pfFreq[i*pMState->nStateNum+nFreq];
						pfFreq[i*pMState->nStateNum+nFreq] = pfFreq[j*pMState->nStateNum+nFreq];
						pfFreq[j*pMState->nStateNum+nFreq] = fBuffer;
					}
				}
			}
		}

		memcpy(&pPRBlock->m_DevMStateArray[pPRBlock->m_nRecordNum[PR_DEVMSTATE]++], pMState, sizeof(tagPRDevMState));
		g_PRMemDBInterface.PRMaint(pPRBlock);

		return 1;
	}

	int ModifyMStateParam(tagPRBlock* pPRBlock, const int nModRec, tagPRDevMState* pMState)
	{
		register int	i, j;
		int		nFreq;
		unsigned char	bExist=0;
		double	fBuffer;
		double*	pfRate=&pMState->fState1Rate;
		double*	pfProb=&pMState->fState1Prob;
		double*	pfFreq=&pMState->fState1Freq1;

		if (nModRec < 0 || nModRec >= pPRBlock->m_nRecordNum[PR_DEVMSTATE])
		{ 
			//::MessageBox(NULL, "待修改记录号错误", "修改多状态模型", MB_OK|MB_SYSTEMMODAL|MB_ICONERROR);
			return 0;
		}

		if (pMState->nStateNum <= 0)
		{
			//::MessageBox(NULL, "多状态模型状态数 = 0", "修改多状态模型", MB_OK|MB_SYSTEMMODAL|MB_ICONERROR);
			return 0;
		}

		for (i=0; i<pPRBlock->m_nRecordNum[PR_DEVMSTATE]; i++)
		{
			if (i == nModRec)
				continue;
			if (pPRBlock->m_DevMStateArray[i].nType == pMState->nType && _stricmp(pPRBlock->m_DevMStateArray[i].szName, pMState->szName) == 0)
			{
				bExist=1;
				break;
			}
		}
		if (bExist)
		{
			//::MessageBox(NULL, "修改信息中的多状态模型已经存在", "修改多状态模型", MB_OK|MB_SYSTEMMODAL|MB_ICONERROR);
			return 0;
		}

		for (i=0; i<pMState->nStateNum; i++)
		{
			for (j=i+1; j<pMState->nStateNum; j++)
			{
				if (pfRate[i] > pfRate[j])
				{
					fBuffer = pfRate[i];
					pfRate[i] = pfRate[j];
					pfRate[j] = fBuffer;

					fBuffer = pfProb[i];
					pfProb[i] = pfProb[j];
					pfProb[j] = fBuffer;

					for (nFreq=0; nFreq<pMState->nStateNum; nFreq++)
					{
						fBuffer = pfFreq[i*pMState->nStateNum+nFreq];
						pfFreq[i*pMState->nStateNum+nFreq] = pfFreq[j*pMState->nStateNum+nFreq];
						pfFreq[j*pMState->nStateNum+nFreq] = fBuffer;
					}
				}
			}
		}

		memcpy(&pPRBlock->m_DevMStateArray[nModRec], pMState, sizeof(tagPRDevMState));

		return 1;
	}
}
