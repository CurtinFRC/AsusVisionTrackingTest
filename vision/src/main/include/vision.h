#pragma once

// Main Libraries
#include <thread>
#include <iostream>
#include <stdio.h>
#include <mutex>

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
  void visionRun();

  // Threading
  void threading();

  // Capture Variables
  float widthGoal;
  float heightGoal;
  float widthOffset;
  float heightOffset;
  bool isValidFrame = false;
  cs::CvSink sink;
  std::mutex classMutex;
  std::condition_variable initCondVar;

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

  // Priority thread starting
  int CapturePriority;
  int ProcessingPriority;
  int TapeDetectionPriority;
  int BallDetectionPriority;
  int SquareDetectionPriority;
  int DisplayPriority;

  cv::Mat imgTracking;

};