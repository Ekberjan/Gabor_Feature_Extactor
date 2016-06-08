#ifndef GABORFEATURE_H
#define GABORFEATURE_H

#include "opencv2\core\core.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "gaborwavelet.h"


class GaborFeature
{
public:
	cv::vector<cv::Mat> getFeature(cv::Mat & inputImage);

private:
	double Kmax = PI / 2;
	double f = std::sqrt(2);
	double Delt = 2 * PI;
	
	GaborWavelet gWavelet;
};


#endif 