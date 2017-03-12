// ExecutionTime.h

#pragma once

using namespace System;

namespace EllipseDetectorLib {
	/*
	* ExecutionTime is the result class
	* This class implements result time of running .NET wrapper of YAED (Yet Another Ellipse Detector)
	*/
	public ref class ExecutionTime
	{
	public:
		ExecutionTime() :
		_fEdgeDetection(0), _fPreProcessing(0), _fGrouping(0), 
		_fEstimation(0), _fValidation(0), 
		_fClustering(0), _fTotal(0)
		{
		}
		ExecutionTime(float fEdgeDetection, float fPreProcessing, float fGrouping, float fEstimation, float fValidation, float fClustering, float fTotal) : 
		_fEdgeDetection(fEdgeDetection), _fPreProcessing(fPreProcessing), _fGrouping(fGrouping),
		_fEstimation(fEstimation), _fValidation(fValidation), 
		_fClustering(fClustering), _fTotal(fTotal)
		{
		}
			
		~ExecutionTime(void) {}
		!ExecutionTime() {}

		property float EdgeDetection {
			float get()
			{
				return _fEdgeDetection;
			}
			void set(float value) 
			{
				_fEdgeDetection = value;
			}
		}

		property float PreProcessing {
			float get()
			{
				return _fPreProcessing;
			}
			void set(float value) 
			{
				_fPreProcessing = value;
			}
		}

		property float Grouping {
			float get()
			{
				return _fGrouping;
			}
			void set(float value) 
			{
				_fGrouping = value;
			}
		}

		property float Estimation {
			float get()
			{
				return _fEstimation;
			}
			void set(float value) 
			{
				_fEstimation = value;
			}
		}

		property float Validation {
			float get()
			{
				return _fValidation;
			}
			void set(float value) 
			{
				_fValidation = value;
			}
		}

		property float Clustering {
			float get()
			{
				return _fClustering;
			}
			void set(float value) 
			{
				_fClustering = value;
			}
		}

		property float Total {
			float get()
			{
				return _fTotal;
			}
			void set(float value) 
			{
				_fTotal = value;
			}
		}
	private:
		float _fEdgeDetection;
		float _fPreProcessing;
		float _fGrouping;
		float _fEstimation;
		float _fValidation;
		float _fClustering;
		float _fTotal;

	};
}