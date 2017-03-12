// EllipseDetectorLib.h

#pragma once

using namespace System;

#include "EllipseResult.h"
#include "ExecutionTime.h"

#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;

namespace EllipseDetectorLib {
	/*
	* EllipseDetector is the main class
	* This class implements a .NET wrapper of very fast ellipse detector, codename: YAED (Yet Another Ellipse Detector)
	*/
	public ref class EllipseDetector
	{

	public:

		EllipseDetector(System::String ^fileName);
		~EllipseDetector(void);
		!EllipseDetector();

		property System::String ^FileName
		{
			System::String ^get()
			{
				return _sFileName;
			}

			void set(System::String ^value)
			{
				if(_sFileName != nullptr) 
				{
					delete _sFileName;
				}
				_sFileName = value;
			}
		}

		//System::Collections::Generic::List<EllipseResult ^> ^Search();
		System::Tuple<System::Drawing::Size, System::Collections::Generic::List<EllipseResult^>^> ^EllipseDetector::Search();

		property int ThLength {
			int get()
			{
				return _iThLength;
			}
			void set(int value) 
			{
				_iThLength = value;
			}
		}

		property float ThObb {
			float get()
			{
				return _fThObb;
			}
			void set(float value) 
			{
				_fThObb = value;
			}
		}

		property float ThPos {
			float get()
			{
				return _fThPos;
			}
			void set(float value) 
			{
				_fThPos = value;
			}
		}

		property float TaoCenters {
			float get()
			{
				return _fTaoCenters;
			}
			void set(float value) 
			{
				_fTaoCenters = value;
			}
		}

		property int Ns {
			int get()
			{
				return _iNs;
			}
			void set(int value) 
			{
				_iNs = value;
			}
		}

		property float ThScoreScore {
			float get()
			{
				return _fThScoreScore;
			}
			void set(float value) 
			{
				_fThScoreScore = value;
			}
		}

		

		property System::Drawing::Size PreProcessingGaussKernelSize
		{
			System::Drawing::Size get(){
				return _pPreProcessingGaussKernelSize;
			}
			void set(System::Drawing::Size value){
				_pPreProcessingGaussKernelSize = value;
			}
		}

		property float DistanceToEllipseContour {
			float get()
			{
				return _fDistanceToEllipseContour;
			}
			void set(float value) 
			{
				_fDistanceToEllipseContour = value;
			}
		}

		property double PreProcessingGaussSigma {
			double get()
			{
				return _dPreProcessingGaussSigma;
			}
			void set(double value) 
			{
				_dPreProcessingGaussSigma = value;
			}
		}

		property float MinReliability {
			float get()
			{
				return _fMinReliability;
			}
			void set(float value) 
			{
				_fMinReliability = value;
			}
		}

		property ExecutionTime^ Execution {
			ExecutionTime^ get()
			{
				return _etExecutionTime;
			}

		}

		// TODO: Add your methods for this class here.
	private:
		System::Collections::Generic::List<EllipseResult^> ^_searchResults;
		System::Tuple<System::Drawing::Size, System::Collections::Generic::List<EllipseResult^>^> ^_result;
		System::String ^_sFileName;
		ExecutionTime ^ _etExecutionTime;
		// Parameters Settings (Sect. 4.2)
		int		_iThLength;
		float	_fThObb;
		float	_fThPos;
		float	_fTaoCenters;
		int 	_iNs;
		float	_fThScoreScore;

		System::Drawing::Size _pPreProcessingGaussKernelSize;// Gaussian filter parameters, in pre-processing
		double	_dPreProcessingGaussSigma;
		float	_fDistanceToEllipseContour;	// (Sect. 3.3.1 - Validation)
		float	_fMinReliability;	// Const parameters to discard bad ellipses*/
		

	};
}
