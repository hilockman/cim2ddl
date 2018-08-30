#include "stdafx.h"
#include "RandomAlgorithm.hpp"

namespace	RandomAlgorithm
{
	double NormalDistProbDensity(double fX, double fExpect, double fVariance)
	{
		double fDist;
		fDist=exp((-1)*(fX-fExpect)*(fX-fExpect)/(2*fVariance))/(sqrt(fVariance)*sqrt(2*M_PI));
		return fDist;
	}

	double NormalDistRandomValue(double dExpect, double dVariance)
	{
		double	fV1, fV2, fS;
		int		nPhase = 0;
		double	fX;

		nPhase = 0;
		fV1 = fV2 = fS = 0;
		if ( nPhase == 0 )
		{
			do
			{
				double fU1 = (double)rand() / RAND_MAX;
				double fU2 = (double)rand() / RAND_MAX;

				fV1 = 2 * fU1 - 1;
				fV2 = 2 * fU2 - 1;
				fS = fV1 * fV1 + fV2 * fV2;
			}
			while(fS >= 1 || fS == 0);

			fX = fV1 * sqrt(-2 * log(fS) / fS);
		}
		else
		{
			fX = fV2 * sqrt(-2 * log(fS) / fS);
		}

		nPhase = 1 - nPhase;

		return (fX*dVariance + dExpect);
	}

	double Gamma(double fIn)
	{
		register int	i;
		double	fOut, fTemp;
		int     nTemp;

		fIn=fIn-1.0;
		if (fIn < 6.0)
		{
			nTemp=int(7-fIn);
			fTemp=fIn+double(nTemp);
			//		fOut=sqrt(2*M_PI*fTemp)*pow(fTemp/M_E, fTemp)*pow(M_E, (1.0/(12*fTemp+1.0/(1.0+2.25*fTemp))));
			fOut=sqrt(2*M_PI*fTemp)*pow(fTemp/M_E, fTemp)*pow(M_E, (1.0/(12*fTemp)-1.0/(360*pow(fTemp, 3))+1.0/(1260*pow(fTemp, 5))-1.0/(1680*pow(fTemp, 7))));
			for (i=1; i<nTemp+1; i++)
				fOut /= (fIn+i);
		}
		else
		{
			//		fOut=sqrt(2*M_PI*fIn)*pow(fIn/M_E, fIn)*pow(M_E, (1.0/(12*fIn+1.0/(1.0+2.25*fIn))));
			fOut=sqrt(2*M_PI*fIn)*pow(fIn/M_E, fIn)*pow(M_E, (1.0/(12*fIn)-1.0/(360*pow(fIn, 3))+1.0/(1260*pow(fIn, 5))-1.0/(1680*pow(fIn, 7))));
		}

		return fOut;
	}

	double WTOutputP(double fRateWTSpeed, double fWTCutInSpeed, double fWTCutOutSpeed, const double fRatedWTP, const double fWSpeed)
	{
		double	fWTPOutput;
		double	fA, fB, fC;

		fWTPOutput=fA=fB=fC=0;
		if (fWSpeed < fWTCutInSpeed || fWSpeed > fWTCutOutSpeed)
			fWTPOutput=0;
		else if (fWSpeed >= fRateWTSpeed && fWSpeed <= fWTCutOutSpeed)
			fWTPOutput=fRatedWTP;
		else
		{
			fA =  fWTCutInSpeed*(fWTCutInSpeed+fRateWTSpeed)-4*fWTCutInSpeed*fRateWTSpeed*pow((fWTCutInSpeed+fRateWTSpeed)/(2*fRateWTSpeed), 3);
			fA /= pow(fWTCutInSpeed-fRateWTSpeed, 2);

			fB =  4*(fWTCutInSpeed+fRateWTSpeed)*pow((fWTCutInSpeed+fRateWTSpeed)/(2*fRateWTSpeed), 3)-(3*fWTCutInSpeed+fRateWTSpeed);
			fB /= pow(fWTCutInSpeed-fRateWTSpeed, 2);

			fC =  2-4*pow((fWTCutInSpeed+fRateWTSpeed)/(2*fRateWTSpeed), 3);
			fC /= pow(fWTCutInSpeed-fRateWTSpeed, 2);

			fWTPOutput=(fA+fB*fWSpeed+fC*pow(fWSpeed, 2))*fRatedWTP;
		}
		return fWTPOutput;
	}

	double WeiBullProbDensity(double fX, double fWeiBullC, double fWeiBullK)
	{
		return fWeiBullK/fWeiBullC*pow(fX/fWeiBullC, fWeiBullK-1)*exp(-pow(fX/fWeiBullC, fWeiBullK));
	}

	double WeiBullProbCumulative(double fX, double fWeiBullC, double fWeiBullK)
	{
		return 1.0-exp(-pow(fX/fWeiBullC, fWeiBullK));
	}

	double WeiBullRandomValue(double fWeiBullC, double fWeiBullK)
	{
		double fU = (double)rand() / RAND_MAX;
		return fWeiBullC*pow(-log(1-fU), 1.0/fWeiBullK);
	}
}
