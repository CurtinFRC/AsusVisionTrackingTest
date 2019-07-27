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

void curtin_frc_vision::run() {
	// Initialization
	captureInit();
	processingInit();
	displayInit();

	// Periodic
	while (true) {
		threading();
	}
}