#pragma once

namespace	RandomAlgorithm
{
	double NormalDistProbDensity(double fX, double fExpect, double fVariance);
	double NormalDistRandomValue(double dExpect, double dVariance);
	double Gamma(double fIn);
	double WTOutputP(double fRateWTSpeed, double fWTCutInSpeed, double fWTCutOutSpeed, const double fRatedWTP, const double fWSpeed);
	double WeiBullProbDensity(double fX, double fWeiBullC, double fWeiBullK);
	double WeiBullProbCumulative(double fX, double fWeiBullC, double fWeiBullK);
	double WeiBullRandomValue(double fWeiBullC, double fWeiBullK);
}
