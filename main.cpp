// Makeup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include "gaborfeature.h"
#include "lbpfeatureextractor.h"
#include "lbp28descriptor.h"
#include "getmapping.h"
#include "lbp.h"
#include "hog.h"


int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image = cv::imread("D:/Workspace/C++/Makup_Detection/Makeup/x64/Release/Images/4.png");
	cv::cvtColor(image, image, CV_BGR2GRAY);
	
	cv::Mat source, gaborOutput;
	image.convertTo(source, CV_32F);

	// Get Gabor features
	GaborFeature gFeature;
	cv::vector<cv::Mat> gaborFeatures = gFeature.getFeature(image);

	// Get LBP features of the Gabor output
	std::vector<std::vector<double>> lbpFeatureVec;
	LBPFeatureExtractor lbpFeatorExtractor;

	for (int i = 0; i < gaborFeatures.size(); i++)
	{		
		std::vector<double> lbpFeature;
		lbpFeature = lbpFeatorExtractor.getFeature(gaborFeatures[i]);
		lbpFeatureVec.push_back(lbpFeature);
	} // end of i-loop

	// Get HOG features
	HOG myHog;
	myHog.run(image);
	cv::vector<cv::Mat> hogFeature = myHog.getFeatureVec();
	
	// Feature level fusion of the obtained LGBP features with HOG features
	std::vector<double> feature;

	for (int i = 0; i < lbpFeatureVec.size(); i++)
	{
		std::vector<double> lbpSubVec = lbpFeatureVec[i];
		for (int j = 0; j < lbpSubVec.size(); j++)
		{
			feature.push_back(lbpSubVec[j]);
		}
	} // end of i-loop
	
	for (int x = 0; x < hogFeature.size(); x++)
	{
		cv::Mat hogMat = hogFeature[x];
		for (int y = 0; y < hogMat.rows; y++)
		{
			const double* My = hogMat.ptr<double>(y);

			for (int z = 0; z < hogMat.cols; z++)
			{
				feature.push_back(My[z]);
			} // end of z-loop
		} // end of y-loop
	} // end of x-loop

	std::cout << "feature size: " << feature.size() << std::endl;

	// Use SVM to classfy the obtained LGBP features


	return 0;
}

