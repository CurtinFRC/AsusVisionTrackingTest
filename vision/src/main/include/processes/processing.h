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

// Local Libraries
#include "captures/capture.h"

class Process : public curtin_frc_vision, public Displayable {
 public:

  virtual void processingInit();
  virtual void processingPeriodic();

  Process(Capture &capture);
  Capture &GetCapture();

  void GetDisplayMat(cv::Mat &displayMat) override;
  cv::Size GetDisplaySize() override;

  std::string GetProcessType();

 protected:
  Capture &_capture;
};
