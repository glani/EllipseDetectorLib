#include "stdafx.h"

#include "EllipseResult.h"

namespace EllipseDetectorLib {
	/*
	* EllipseResult is the result class
	* This class implements a result of running .NET wrapper of YAED (Yet Another Ellipse Detector)
	*/
	EllipseResult::EllipseResult(): _xc(0), _yc(0), _a(0), _b(0), _rad(0)
	{}

	EllipseResult::EllipseResult(float xc, float yc, float a, float b, float rad): _xc(xc), _yc(yc), _a(a), _b(b), _rad(rad)
	{}
}