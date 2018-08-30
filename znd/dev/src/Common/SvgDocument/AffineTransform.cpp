#include "StdAfx.h"
#include "AffineTransform.h"

CAffineTransform::CAffineTransform(void)
{

}
CAffineTransform::~CAffineTransform(void)
{

}

void CAffineTransform::Reset() 
{
	cxx = cyy = 1.0;
	//cxx = cyy = 0.0;
	cxy = cyx = 0.0;
	tx = ty = 0.0;
}

void CAffineTransform::SetAffineTransform(const double ixx, const double ixy, const double iyx, const double iyy, const double dtx, const double dty)
{
	cxx = ixx;
	cxy = ixy;
	cyx = iyx;
	cyy = iyy;
	tx = dtx;
	ty = dty;
}

void CAffineTransform::ShapeTransform(const double source[][2], double target[][2], const unsigned int nCount)
{
	transform(source,target,nCount);
}

void CAffineTransform::ShapeTransform(const double* sourceX, double* sourceY,double* targetX,double* targetY, const unsigned int nCount)
{
	transform(sourceX,sourceY,targetX,targetY,nCount);
}

void CAffineTransform::ShapeTranslation(const double source[][2], double target[][2],const unsigned int nCount,const double dtx,const double dty)
{
	cxx = cyy = 1.0;
	cxy = cyx = 0.0;
	tx = dtx;
	ty = dty;
	transform(source,target,nCount);
}
void CAffineTransform::ShapeTranslation(const double* sourceX, double* sourceY,double* targetX,double* targetY,const unsigned int nCount,const double dtx,const double dty)
{
	cxx = cyy = 1.0;
	cxy = cyx = 0.0;
	tx = dtx;
	ty = dty;
	transform(sourceX,sourceY,targetX,targetY,nCount);
}
//垂直翻转
void CAffineTransform::ShapeFlipVerticallyBy(const double source[][2], double target[][2], const unsigned int nCount,double dY)
{
	cxx = 1.0;
	cyy = -1.0;
	cxy = cyx = 0.0;
	tx = 0;
	ty = 2*dY;
	transform(source,target,nCount);
}

//垂直翻转
void CAffineTransform::ShapeFlipVerticallyBy(const double* sourceX,const double* sourceY, double* targetX,double* targetY, const unsigned int nCount,double dY)
{
	cxx = 1.0;
	cyy = -1.0;
	cxy = cyx = 0.0;
	tx = 0;
	ty = 2*dY;
	transform(sourceX,sourceY,targetX,targetY,nCount);
}

//水平翻转
void CAffineTransform::ShapeFlipHorizontallyBy(const double source[][2], double target[][2], const unsigned int nCount,double dX)
{
	cxx = -1.0;
	cyy = 1.0;
	cxy = cyx = 0.0;
	tx = 2*dX;
	ty = 0;
	transform(source,target,nCount);
}

void CAffineTransform::ShapeFlipHorizontallyBy(const double* sourceX,const double* sourceY, double* targetX,double* targetY,const unsigned int nCount,double dX)
{
	cxx = -1.0;
	cyy = 1.0;
	cxy = cyx = 0.0;
	tx = 2*dX;
	ty = 0;
	transform(sourceX,sourceY,targetX,targetY,nCount);
}

void CAffineTransform::ShapeRotateBy(const double source[][2], double target[][2], const unsigned int nCount,POINT origin)
{
	tx = origin.x*(1-cxx)+origin.y*(-1*cyx);
	ty = origin.y*(1-cyy)-origin.x*cxy;
	transform(source,target,nCount);
}

void CAffineTransform::ShapeRotateBy(const double* sourceX,const double* sourceY, double* targetX,double* targetY, const unsigned int nCount,POINT origin)
{
	tx = origin.x*(1-cxx)+origin.y*(-1*cyx);
	ty = origin.y*(1-cyy)-origin.x*cxy;
	transform(sourceX,sourceY,targetX,targetY,nCount);
}
//**************************************************************************************************
/// \fn			void CAffineTransform::transform(const double source[][], double target[][], const unsigned int count)
/// \brief		//在Tool=Cursor的时候，鼠标操作生成的线过程
/// \parameter	source	需要转化的坐标数组
/// \parameter	target	转化完成的坐标数组
/// \parameter	count	数组内坐标的数量
/// \return		no
/// \author		Zhangjin
/// \version	V01.00 Zhangjin Created	2012-06-14
/// \date		2012-06-13
/// \sa			
//**************************************************************************************************
void CAffineTransform::transform(const double source[][2], double target[][2], const unsigned int count) 
{
	for (unsigned int i = 0;i < count;i++)
	{
		double tx = source[i][0];
		double ty = source[i][1];
		target[i][0] = getDX(tx,ty);
		target[i][1] = getDY(tx,ty);
	}
}

//**************************************************************************************************
/// \fn			void CAffineTransform::transform(const double* sourceX,const double* sourceY, double* targetX,double* targetY, const unsigned int count)
/// \brief		//在Tool=Cursor的时候，鼠标操作生成的线过程
/// \parameter	sourceX	需要转化的坐标数组
/// \parameter	sourceY	需要转化的坐标数组
/// \parameter	targetX	转化完成的坐标数组
/// \parameter	targetY	转化完成的坐标数组
/// \parameter	count	数组内坐标的数量
/// \return		no
/// \author		Zhangjin
/// \version	V01.00 Zhangjin Created	2012-06-14
/// \date		2012-06-13
/// \sa			
//**************************************************************************************************
void CAffineTransform::transform(const double* sourceX,const double* sourceY, double* targetX,double* targetY, const unsigned int count) 
{
	for (unsigned int i = 0;i < count;i++)
	{
		double tx = sourceX[i];
		double ty = sourceY[i];
		targetX[i] = getDX(tx,ty);
		targetY[i] = getDY(tx,ty);
	}
}

CAffineTransform* ParseTransform(const char* lpszTransform)
{
	if (lpszTransform == NULL)
		return NULL;

	char*	lpszToken;
	char	szBuffer[260];
	std::vector<std::string>	strEleArray;

	CAffineTransform* pTrans = new CAffineTransform();

	std::string strTransform = (std::string)lpszTransform;
	strcpy(szBuffer, strTransform.c_str());

	strEleArray.clear();
	lpszToken=strtok(szBuffer," (),");
	while (lpszToken != NULL)
	{
		strEleArray.push_back(lpszToken);
		lpszToken=strtok(NULL, " (),");
	}

	int nEle = 0;
	while (nEle < strEleArray.size())
	{
		if (stricmp(strEleArray[nEle].c_str(),"translate") == 0)
		{
			if (strEleArray.size() - nEle >= 3)
			{
// 				pTrans->translate(
// 					CZNDGraphicCommon.tranNumericDtoL(atof(strEleArray[nEle + 1])),
// 					CZNDGraphicCommon.tranNumericDtoL(atof(strEleArray[nEle + 2])));
				nEle += 3;
			}
			else
				break;
		}
		else if (stricmp(strEleArray[nEle].c_str(), "rotate") == 0)
		{
			if (strEleArray.size() - nEle >= 4)
			{
				if (stricmp(strEleArray[nEle + 2].c_str(), "scale") != 0 &&
					stricmp(strEleArray[nEle + 2].c_str(), "rotate") != 0 &&
					stricmp(strEleArray[nEle + 2].c_str(), "translate") != 0)
				{
					//pTrans->rotate(
					//	atof(strEleArray[nEle + 1])*3.14159265/180.0,
					//	CZNDGraphicCommon.tranNumericDtoL(atof(strEleArray[nEle + 2].c_str())),
					//	CZNDGraphicCommon.tranNumericDtoL(atof(strEleArray[nEle + 3].c_str())));
					nEle += 4;
				}
				else
				{
					//pTrans->rotate(atof(strEleArray[nEle + 1].c_str())*3.14159265/180.0);
					nEle += 2;
				}
			}
			else if (strEleArray.size() - nEle >= 2 && strEleArray.size() - nEle < 4)
			{
				//pTrans->rotate(atof(strEleArray[nEle + 1].c_str())*3.14159265/180.0);
				nEle += 2;
			}
			else
				break;
		}
		else if (stricmp(strEleArray[nEle].c_str(), "scale") == 0)
		{
			if (strEleArray.size() - nEle >= 3)
			{
				//pTrans->scale(
				//	atof(strEleArray[nEle + 1].c_str()),
				//	atof(strEleArray[nEle + 2].c_str()));
				nEle += 3;
			}
			else
				break;
		}
		else
			nEle++;
	}

	return pTrans;
}