#ifndef GABORWAVELET_H
#define GABORWAVELET_H

#define PI 3.141593

#include "opencv2\core\core.hpp"
#include "opencv\highgui.h"

class GaborWavelet
{
public:
	cv::Mat run(int R, int c, double Kmax, double f, double u, double v, double Delt2);
};

#endif