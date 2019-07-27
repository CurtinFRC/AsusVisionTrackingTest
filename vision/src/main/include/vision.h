#pragma once

#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <stdio.h>

#include <cameraserver/CameraServer.h>
#include <cscore.h>

class curtin_frc_vision {
 public:
  void run();
};

void threading();

// Vision Init
void captureInit();
void processingInit();
void displayInit();

// Vision Periodic
void capturePeriodic();
void processingPeriodic();
void displayPeriodic();