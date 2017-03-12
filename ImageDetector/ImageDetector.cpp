/*	ImageDetector.cpp : Defines the entry point for the console application.
	This example is base on an article
	Michele Fornaciari, Andrea Prati, Rita Cucchiara,
	A fast and effective ellipse detector for embedded vision applications
	Pattern Recognition, Volume 47, Issue 11, November 2014, Pages 3693-3708, ISSN 0031-3203,
	http://dx.doi.org/10.1016/j.patcog.2014.05.012.
	(http://www.sciencedirect.com/science/article/pii/S0031320314001976)
*/
#include "stdafx.h"

#include <opencv2\opencv.hpp>

#include "EllipseDetectorYaed.h"
#include "common.h"

using namespace std;
using namespace cv;
using namespace Yaed;

// Test on single image
int main2(int argc, char** argv)
{
	string images_folder = ".";
	string out_folder = ".";
	if (argc > 1)
	{
		images_folder = string(argv[1]);
		out_folder = images_folder;
	}

	if (argc > 2)
	{
		out_folder = string(argv[2]);
	}
	string filter = "*.jpg";
	if (argc > 3)
	{
		filter = string(argv[3]);
	}

	cout << "OpenCV version : " << CV_VERSION << endl;
	cout << "Major version : " << CV_MAJOR_VERSION << endl;
	cout << "Minor version : " << CV_MINOR_VERSION << endl;
	cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;
	cout << "=========================" << endl;

	cout << "Execution Params: " << endl;
	cout << "Input folder: \t" << images_folder << endl;
	cout << "Output folder: \t" << out_folder << endl;
	cout << "Filter: \t" << filter << endl;
	
	vector<String> names;// = new vector<String>();
	glob(images_folder + filter, names);

	for (const auto& image_name : names)
	{
		string name = image_name.substr(image_name.find_last_of("\\") + 1);
		name = name.substr(0, name.find_last_of("."));

		Mat3b image = imread(image_name);
		Size sz = image.size();
		
		// Convert to grayscale
		Mat1b gray;
		cvtColor(image, gray, CV_BGR2GRAY);
		
		// Parameters Settings (Sect. 4.2)
		int		iThLength = 16;
		float	fThObb = 3.0f;
		float	fThPos = 1.0f;
		float	fTaoCenters = 0.05f;
		int 	iNs = 16;
		float	fThScoreScore = 0.7f;

		float	fMaxCenterDistance = sqrt(float(sz.width*sz.width + sz.height*sz.height)) * fTaoCenters;

		// Other constant parameters settings. 

		// Gaussian filter parameters, in pre-processing
		Size	szPreProcessingGaussKernelSize = Size(5, 5);
		double	dPreProcessingGaussSigma = 1.0;

		float	fDistanceToEllipseContour = 0.1f;	// (Sect. 3.3.1 - Validation)
		float	fMinReliability = 0.5;	// Const parameters to discard bad ellipses


		// Initialize Detector with selected parameters
		CEllipseDetectorYaed yaed;
		yaed.SetParameters(szPreProcessingGaussKernelSize,
			dPreProcessingGaussSigma,
			fThPos,
			fMaxCenterDistance,
			iThLength,
			fThObb,
			fDistanceToEllipseContour,
			fThScoreScore,
			fMinReliability,
			iNs
			);


		// Detect
		vector<Ellipse> ellsYaed;
		yaed.Detect(gray.clone(), ellsYaed);

		vector<double> times = yaed.GetTimes();
		cout << "--------------------------------" << endl;
		cout << "Execution Time: " << endl;
		cout << "Edge Detection: \t" << times[0] << endl;
		cout << "Pre processing: \t" << times[1] << endl;
		cout << "Grouping:       \t" << times[2] << endl;
		cout << "Estimation:     \t" << times[3] << endl;
		cout << "Validation:     \t" << times[4] << endl;
		cout << "Clustering:     \t" << times[5] << endl;
		cout << "--------------------------------" << endl;
		cout << "Total:	         \t" << yaed.GetExecTime() << endl;
		cout << "--------------------------------" << endl;


		
		Mat3b resultImage = image.clone();
		yaed.DrawDetectedEllipses(resultImage, ellsYaed);
		
		imwrite(out_folder + name + ".png", resultImage);

		imshow("Yaed", resultImage);
		waitKey();


		int yghds = 0;
	}
	return 0;
}

int main(int argc, char** argv)
{
	main2(argc, argv);
	return 0;
}