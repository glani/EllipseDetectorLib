// This is the main DLL file.

#include "stdafx.h"

#include "EllipseDetectorLib.h"
#include "EllipseDetectorYaed.h"

using System::Collections::Generic::List;
namespace EllipseDetectorLib {
	/*
	* EllipseDetector is the main class
	* This class implements a .NET wrapper of very fast ellipse detector, codename: YAED (Yet Another Ellipse Detector)
	* Methods Implementation
	*/
	EllipseDetector::EllipseDetector(System::String ^fileName)
		: _sFileName(fileName),  _searchResults(nullptr), _etExecutionTime(nullptr), _result(nullptr),
		_iThLength(16),
		_fThObb(3.0f),
		_fThPos(1.0f),
		_fTaoCenters(0.05f),
		_iNs(16),
		_fThScoreScore(0.7f),
		_dPreProcessingGaussSigma(1.0),
		_fDistanceToEllipseContour(0.1f),
		_fMinReliability(0.5),
		_pPreProcessingGaussKernelSize(System::Drawing::Point(5,5))
	{

	}
	EllipseDetector::~EllipseDetector(void)
	{

	}

	EllipseDetector::!EllipseDetector() 
	{

		if(_searchResults != nullptr)
		{
			delete _searchResults;
		}

		if(_result != nullptr)
		{
			delete _result;
		}

		if(_etExecutionTime != nullptr)
		{
			delete _etExecutionTime;
		}

		if(_sFileName != nullptr) 
		{
			delete _sFileName;
		}

		//Release managed resources
		GC::Collect();

	}

	System::Tuple<System::Drawing::Size, System::Collections::Generic::List<EllipseResult^>^>^ EllipseDetector::Search()
	{
		if(_searchResults == nullptr) {
			_searchResults = gcnew System::Collections::Generic::List<EllipseResult ^>();
		} 
		else
		{
			_searchResults->Clear();	
		}

		if(_result != nullptr)
		{
			delete _result;
		}

		if(_sFileName == nullptr) 
		{
			_result = gcnew System::Tuple<System::Drawing::Size, System::Collections::Generic::List<EllipseResult^>^>(System::Drawing::Size::Empty, _searchResults);
			return _result;
		}

		IntPtr ptr = Marshal::StringToCoTaskMemAnsi(this->_sFileName);
		char *singleByte= (char*)ptr.ToPointer();
		cv::String* image_name = NULL;

		try
		{
			image_name = new cv::String(singleByte);
		}
		finally
		{
			Marshal::FreeCoTaskMem(ptr);
		}
		
		cv::Mat3b image = cv::imread(*image_name);
		cv::Size sz = image.size();
		System::Drawing::Size resultSize(sz.width, sz.height);
		_result = gcnew System::Tuple<System::Drawing::Size, System::Collections::Generic::List<EllipseResult^>^>(resultSize, _searchResults);

		// Convert to grayscale
		cv::Mat1b gray;
		cv::cvtColor(image, gray, CV_BGR2GRAY);

		float fMaxCenterDistance = sqrt(float(sz.width*sz.width + sz.height*sz.height)) * this->_fTaoCenters;
		cv::Size szPreProcessingGaussKernelSize = cv::Size(this->_pPreProcessingGaussKernelSize.Width, this->_pPreProcessingGaussKernelSize.Height);
		// Initialize Detector with selected parameters
		Yaed::CEllipseDetectorYaed yaed;
		yaed.SetParameters(szPreProcessingGaussKernelSize,
			this->_dPreProcessingGaussSigma,
			this->_fThPos,
			fMaxCenterDistance,
			this->_iThLength,
			this->_fThObb,
			this->_fDistanceToEllipseContour,
			this->_fThScoreScore,
			this->_fMinReliability,
			this->_iNs
			);


		// Detect
		std::vector<Yaed::Ellipse> ellsYaed;
		yaed.Detect(gray.clone(), ellsYaed);

		vector<double> times = yaed.GetTimes();

		int sz_ell = int(ellsYaed.size());
		//int n = (iTopN == 0) ? sz_ell : min(iTopN, sz_ell);
		for (int i = 0; i < sz_ell; ++i)
		{
			Yaed::Ellipse& e = ellsYaed[i];
			_searchResults->Add(gcnew EllipseResult(e._xc, e._yc, e._a, e._b, e._rad));
		}

		if(_etExecutionTime != nullptr)
		{
			delete _etExecutionTime;
		}

		_etExecutionTime = gcnew ExecutionTime(times[0], times[1], times[2], times[3], times[4], times[5], yaed.GetExecTime());

		delete image_name;
		return _result;
	}
}

