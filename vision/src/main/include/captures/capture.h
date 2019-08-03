#pragma once
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
#include "display.h"

class Capture : public curtin_frc_vision, public Displayable {
  public:
  void captureInit();
  void capturePeriodic();

  void CopyCaptureMat(cv::Mat &captureMat);

  void GetDisplayMat(cv::Mat &displayMat) override;
  cv::Size GetDisplaySize() override;

  private:
  cv::Mat _captureMat;
};