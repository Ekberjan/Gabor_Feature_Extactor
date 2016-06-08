// Makeup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "gaborfeature.h"

int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image = cv::imread("/Images/1.png");
	cv::cvtColor(image, image, CV_BGR2GRAY);
	
	cv::Mat source;
	image.convertTo(source, CV_32F);

	// Get Gabor features
	GaborFeature gFeature;
	cv::vector<cv::Mat> gaborFeatures = gFeature.getFeature(source);

	// Final feature vector  of the obtained Gabbor features
	std::vector<double> feature;

	for (int x = 0; x < gaborFeatures.size(); x++)
	{
		cv::Mat gaborMat = gaborFeatures[x];
		for (int y = 0; y < gaborMat.rows; y++)
		{
			const double* My = gaborMat.ptr<double>(y);

			for (int z = 0; z < gaborMat.cols; z++)
			{
				feature.push_back(My[z]);
			} // end of z-loop
		} // end of y-loop
	} // end of x-loop

	std::cout << "feature size: " << feature.size() << std::endl;

	// Use the obtained Gabor feature for further steps based on your goal,
	// such as send it to classifier


	return 0;
}

