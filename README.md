# EllipseDetectorLib
.Net library for Ellipse detection based on the algorithm of very fast ellipse detector, codename: YAED (Yet Another Ellipse Detector).

#### What is EllipseDetectorLib ?
Simple .Net wrapper for a very fast ellipse detection algorithm.

#### Third party libraries

It uses:
* [Open Source Computer Vision Library](https://github.com/opencv/opencv) for image reading and processing.

#### The main advantage

Real-time ellipse detection is an important yet challenging task, since the estimation of the five parameters of an ellipse requires heavy computation.

A new efficient ellipse detection method (Y. Xie and Q. Ji) has remained ineffective and inappropriate for realtime processing.

It is suitable in programs which require an approximate ellipse detection and have to do this in realtime. 

#### Projects
There are four projects:
* [EllipseDetectorLib](EllipseDetectorLib/): the main C++ .Net library. In other words this is the wrapper.
* [ImageDetector](ImageDetector/): the example written in C++ and based on the initial code of YAED.
* [libellipsedetect](libellipsedetect/): the code of the YAED library.
* [TestCSharp](TestCSharp/): the example written in C# which uses EllipseDetectorLib library.

#### Build and deploy
This library has been written in Microsoft Visual Studio 2012. Files *.csproj contain all configurations for different platforms x64, x86 as well as Debug and Release modes.
For successfull build [OpenCV](https://github.com/opencv/opencv) has to be installed. In addition environment variable OPENCV_DIR where opencv is installed should be set.

#### Features and Capabilities
Here are just a few examples of what EllipseDetectorLib can do:
* [Samples](test-data/): A couple of files shows the initial and result images.

#### What is YAED (Yet Another Ellipse Detector)?

##### According to the comments in the code:
--------------------------------------------------------------
This code is intended for academic use only.
You are free to use and modify the code, at your own risk.

If you use this code, or find it useful, please refer to the paper:

Michele Fornaciari, Andrea Prati, Rita Cucchiara,
A fast and effective ellipse detector for embedded vision applications
Pattern Recognition, Volume 47, Issue 11, November 2014, Pages 3693-3708, ISSN 0031-3203,
http://dx.doi.org/10.1016/j.patcog.2014.05.012
http://www.sciencedirect.com/science/article/pii/S0031320314001976


The comments in the code refer to the abovementioned paper.
If you need further details about the code or the algorithm, please contact me at:

michele.fornaciari@unimore.it

last update: 23/12/2014

--------------------------------------------------------------