#pragma once

/*仿射变换类，其构造函数的各个参数在矩阵中的位置如下：
|cxx,cxy,0|
|cyx,cyy,0|
|tx, ty, 1|

平移转换矩阵
|1 ,0 ,0|
|0 ,1 ,0||1,1,1|
|tx,ty,1|

比例转换矩阵
|Sx,0 ,0|
|0 ,Sy,0|
|0 ,0 ,1|
Sx =  Sy <> 1等比
Sx <> Sy 非等比

对称转化矩阵
1）X轴转换
|1 ,0 ,0|
|0 ,-1,0|
|0 ,0 ,1|
2）Y轴转换
|-1,0 ,0|
|0 ,1 ,0|
|0 ,0 ,1|
3）原点转换
|-1,0 ,0|
|0 ,-1,0|
|0 ,0 ,1|

旋转转化矩阵
|cos ,sin ,0|
|-sin,-cos,0|
|0   ,0   ,1|
*/
class CAffineTransform
{
private:
	double cxx; 
	double cxy; 
	double cyx; 
	double cyy; 
	double tx;
	double ty;

public:
	CAffineTransform(void);
	~CAffineTransform(void);
	
	void Reset();
	void SetAffineTransform		(const double ixx, const double ixy, const double iyx, const double iyy, const double dtx, const double dty);
	void ShapeTransform			(const double* sourceX, double* sourceY,double* targetX,double* targetY, const unsigned int nCount);
	void ShapeTranslation		(const double* sourceX, double* sourceY,double* targetX,double* targetY,const unsigned int nCount,const double tx,const double ty);
	void ShapeRotateBy			(const double* sourceX, const double* sourceY, double* targetX,double* targetY, const unsigned int nCount, POINT origin);
	void ShapeFlipVerticallyBy	(const double* sourceX,const double* sourceY, double* targetX,double* targetY, const unsigned int nCount,double dY);	//垂直翻转
	void ShapeFlipHorizontallyBy(const double* sourceX,const double* sourceY, double* targetX,double* targetY, const unsigned int nCount,double dX);	//水平翻转

	void ShapeTransform			(const double source[][2], double target[][2], const unsigned int nCount);				//矩阵转换
	void ShapeTranslation		(const double source[][2], double target[][2], const unsigned int nCount, const double tx, const double ty);
	void ShapeRotateBy			(const double source[][2], double target[][2], const unsigned int nCount, POINT origin);
	void ShapeFlipVerticallyBy	(const double source[][2], double target[][2], const unsigned int nCount, double dY);	//垂直翻转
	void ShapeFlipHorizontallyBy(const double source[][2], double target[][2], const unsigned int nCount, double dX);	//水平翻转
private:
	void transform(const double* sourceX,const double* sourceY, double* targetX,double* targetY, const unsigned int count);	//坐标变换
	void transform(const double source[][2], double target[][2], const unsigned int count );								//坐标变换

	inline double getDX(const double& x,const double& y ) const
	{
		return (cxx * x) + (cyx * y) + (tx/* *1乘以1*/);
	}

	inline double getDY(const double& x,const double& y ) const {
		return (cxy * x ) + (cyy * y )  + (ty/* *1乘以1*/);
	}
};