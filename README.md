# MAELab Library

===================================================
20th March 2017

This library is written by C++ and using LibJpeg to decompress/compress the image.

This library provides the methods to:

	- Segment the images: binary threshold, Canny algorithm, Suzuki algorithm

	- Recording the shape descriptors using pairwise geometric histogram (PGH)

	- Estimate the landmarks of the image by using Probabilistic Hought Transform (PHT), 
	  Generalize Hough Transofrm (GHT) and Principal Component Analysis Iteration with SIFT (PCAI).

	- Display the landmarks (manual or estimated) of the image.

	- The util functions: read and write TPS file; save the image; drawing.

The library includes 2 main folders:

	- "libs" folder: contains the execute files (library) formed as *.so files

	- "includes" folder: contains the header files (*.h)

In details:
	- To create an image from a string path, you can use Image class
	
	- The functions to segment an image stayed in EdgeSegmentation class

	- The functions to recording the shape descriptors and compute the 
	  similarity metric stayed in GeometricHistogram class

	- The functions to determine the presence between two images 
	  stayed in PHoughTransform class

	- The functions to estimate the landmarks of a model image in
	  a scene image stayed in LandmarksDetection class

	- Other classes are supporting classes for main functions of library.

To use this library:

	- Install the requiremented libraries:
		- Qt4 (for graphic interface)
		- OpenCL 
		- OpenGL

	- Copy library (two folder) into your project

	- Add the configuration (to library) in your project setting (the path to header files and execute files ).

Notice:
	- Put the required libraries AFTER the module you are compiling.
	  Example: OpenCV libraries are placed after IPM library in config file

	- This library is dynamic library. So, you need to tell
	  the operation system where it can located at runtime.
	  Followed 3 steps:

	  1. Check for the existence of the dynamic library path
	     environnement variable(LD_LIBRARY_PATH)
	     echo $LD_LIBRARY_PATH

	  2. If there is nothing, we can add the default path value
	     LD_LIBRARY_PATH=/usr/local/lib

	  3. Add the desire path and export it and run your application:
	     LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path_to_your_library(absolute path)
	     export LD_LIBRARY_PATH
	     run your application

#=======================================================================================================
Example:

	This example shows how to use this library. In this work, we want to estimate landmarks 
	of an image (scene) by using another image (model) and its manual landmark. The files include:
		- Test.cpp: program to use the library
		- Test.pro: configuration file.
		- data (in "data" folder)
	The result includes:
		- result.jpg: image with the estimated landmarks (yellow ones)
		- result.TPS: contains the coordinate of estimated landmarks and distance with the manual ones.

	How to run this example:
		- Open a terminal
		- Change the current directory this location
		- Run the following commands:
			qmake
			make all
			./Test #execute file
	Results: image and tps file will be export as the same directory.

