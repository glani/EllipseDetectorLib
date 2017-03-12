// EllipsResult.h

#pragma once

using namespace System;

namespace EllipseDetectorLib {
	/*
	* EllipseResult is the result class
	* This class implements a result of running .NET wrapper of YAED (Yet Another Ellipse Detector)
	*/
	public ref class EllipseResult
	{
	public:
		EllipseResult();

		EllipseResult(float xc, float yc, float a, float b, float rad);
		~EllipseResult(void) {}
		!EllipseResult() {}

		property System::Drawing::PointF Center {
			System::Drawing::PointF get()
			{
				return System::Drawing::PointF(_xc, _yc);
			}
			void set(System::Drawing::PointF value) 
			{
				_xc = value.X;
				_yc = value.Y;
			}
		}

		property float RadiusA {
			float get()
			{
				return _a;
			}
			void set(float value) 
			{
				_a = value;
			}
		}

		property float RadiusB {
			float get()
			{
				return _b;
			}
			void set(float value) 
			{
				_b = value;
			}
		}

		property float Radian {
			float get()
			{
				return _rad;
			}
			void set(float value) 
			{
				_rad = value;
			}
		}


	private:
		float _xc;
		float _yc;
		float _a;
		float _b;
		float _rad;

	};
}