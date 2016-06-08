#include "stdafx.h"
#include "gaborwavelet.h"

cv::Mat GaborWavelet::run(int R, int C, double Kmax, double f, double u, double v, double Delt2)
{ 
	double eR = std::cos(u * PI / 8);
	double eI = std::sin(u * PI / 8);

	double kR = (Kmax / std::pow(f, v)) * eR;
	double kI = (Kmax / std::pow(f, v)) * eI;

	double kn2R = std::pow(std::abs(kR), 2);
	double kn2I = std::pow(std::abs(kI), 2);
	double kn2 = std::pow(kn2R, 2) + std::pow(kn2I, 2);

	cv::Mat result = cv::Mat::zeros(R, C, CV_32F);
	cv::Mat realMat = cv::Mat::zeros(R, C, CV_32F);
	cv::Mat imagMat = cv::Mat::zeros(R, C, CV_32F);
	
	for (double m = -R / 2; m < R / 2; m++)
	{
		for (double n = -C / 2; n < C / 2; n++)
		{
			double waveR = std::cos(kR * m + kI * n);
			double waveI = std::sin(kR * m + kI * n);

			double term = (kn2 / Delt2) * std::exp(-0.5 * kn2 * (std::pow(m, 2) + std::pow(n, 2)) / Delt2);
			double valR = term * (waveR - std::exp(-0.5 * Delt2));
			double valI = term * (waveI - std::exp(-0.5 * Delt2));

			realMat.at<float>(m + R / 2, n + C / 2) = valR;
			imagMat.at<float>(m + R / 2, n + C / 2) = valI;
		} // end of n-loop
	} // end of m-loop

	cv::vector<cv::Mat> channels;
	channels.push_back(realMat);
	channels.push_back(imagMat);
	cv::merge(channels, result);
	
	return result;
} // end of function definition