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

  // Vision Main Functions
  void mapInit();

  // Vision Init
  void captureInit();
  void processingInit();
  void displayInit();

  int camPort;
  int resWidth;
  int resHeight;
  int camExposure;
  int Rvalue;
  int Gvalue;
  int Bvalue;
  bool useTapeDetection;
  bool useBallDetection;
  bool personDetection;
  bool CustomDetection;
  bool offset;
  bool position;
  bool distance;
  int blur;
  int noisefix;
};

// Vision Main Start Function
void visionRun();

// Threading
void threading();

// Vision Periodic
void capturePeriodic();
void processingPeriodic();
void displayPeriodic();