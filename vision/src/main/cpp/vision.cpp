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

	// Vision Config
	camPort = 4;
	resWidth = 640;
	resHeight = 480;
	camExposure = -100;
	Rvalue = 0;
	Gvalue = 0;
	Bvalue = 0;
	useTapeDetection = true;
	useBallDetection = false;
	personDetection = false;
	CustomDetection = false;
	offset = false;
	position = false;
	distance = false;
	blur = 0;
	noisefix = 0;


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
}

void visionRun() {
	// Initialization
	curtin_frc_vision init;
	init.captureInit();
	init.processingInit();
	init.displayInit();

	// Periodic
	while (true) {
		threading();
	}
}