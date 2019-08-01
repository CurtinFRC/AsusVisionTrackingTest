// OpenCV
#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <stdio.h>
#include <iostream>

// Camera Servers
#include <cameraserver/CameraServer.h>
#include <cscore.h>

// Local Libraries
#include "vision.h"

void curtin_frc_vision::mapInit() {

	/* */ // <--- still need to link

	// Vision Config
	camPort = 0;
	resWidth = 640;
	resHeight = 480;
	camExposure = -100;
	Rvalue = 0; /* */
	Gvalue = 0; /* */
	Bvalue = 0; /* */
	blur = 0; /* */
	noisefix = 0;
	useTapeDetection = true; /* */
	useBallDetection = false; /* */
	personDetection = false; /* */
	CustomDetection = false; /* */
	offset = true;
	position = false; /* */
	distance = false; /* */
	outputOriginalFrame = true; /* */
	outputTrackingFrame = true; /* */


	// Order of initialiazation and threading priority 1 first
	CapturePriority = 1; /* */
	ProcessingPriority = 2; /* */
	TapeDetectionPriority = 3; /* */
	BallDetectionPriority = 4; /* */
	SquareDetectionPriority = 5; /* */
	DisplayPriority = 6; /* */

	// Capture Math
	widthGoal = resWidth/2;
  heightGoal = resHeight/2;

	// Output Values
	std::cout << "camPort = " << camPort << std::endl;
	std::cout << "Width, Height = " << resWidth << ", " << resHeight << std::endl;
	std::cout << "Cam Exposure = " << camExposure << std::endl;
	std::cout << "RGB = " << Rvalue << "," << Gvalue << "," << Bvalue << std::endl;
	std::cout << "useTapeDetection = " << useTapeDetection << std::endl;
	std::cout << "useBallDetection = " << useBallDetection << std::endl;
	std::cout << "PersonDetection = " << personDetection << std::endl;
	std::cout << "CustomDetection = " << CustomDetection << std::endl;
	std::cout << "offset = " << offset << std::endl;
	std::cout << "position = " << position << std::endl;
	std::cout << "distance = " << distance << std::endl;
	std::cout << "blur = " << blur << std::endl;
	std::cout << "noisefix = " << noisefix << std::endl;

	// Capture Output
	std::cout << "Goals: " << widthGoal << "," << heightGoal << std::endl; 
}

void curtin_frc_vision::visionRun() {
	// Initialization
	
	while (true) {
		curtin_frc_vision threadStart;
		threadStart.threading();
	}
}