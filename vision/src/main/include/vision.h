#pragma once

// Main Libraries
#include <thread>
#include <iostream>
#include <stdio.h>

// OpenCV
#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

// Camera Servers
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

  // Threading
  void threading();
    
  // Vision Periodic
  void capturePeriodic();
  void processingPeriodic();
  void displayPeriodic();

  // Capture Variables
  float widthGoal;
  float heightGoal;
  float widthOffset;
  float heightOffset;
  bool isValidFrame = false;

  // Processing Variables and functions
  bool isDisplayable = false;
  int thresh = 100;
  void TapeDetection();

  // Display Variables
  cs::CvSource output;

  // Vision Map
  int camPort;
  int resWidth;
  int resHeight;
  int camExposure;
  int Rvalue;
  int Gvalue;
  int Bvalue;
  int blur;
  int noisefix;
  bool useTapeDetection;
  bool useBallDetection;
  bool personDetection;
  bool CustomDetection;
  bool offset;
  bool position;
  bool distance;
  bool outputOriginalFrame;
	bool outputTrackingFrame;


  cv::Mat imgOriginal;
  cv::Mat imgTracking;
};

// Vision Main Start Function
void visionRun();