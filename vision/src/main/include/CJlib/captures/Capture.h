#pragma once

#include "CJlib/cj.h"
#include "threading/Runnable.h"
#include <cscore.h>
#include <mutex>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

class Capture : public Runnable {
 public:
  Capture(int port, int exposure);
  int GetPort();
  void Init() override;
  void Periodic() override;

  cs::VideoMode GetVideoMode();
  void CopyCaptureMat(cv::Mat &captureMat);
  bool IsValidFrameThresh();
  bool IsValidFrameTrack();
  
 private:
  cs::UsbCamera _cam;
  std::mutex _classMutex;
  std::condition_variable _initCondVar;
  cs::CvSink _sink{"USBSink"};
  cv::Mat _captureMat;
  cs::VideoMode _videoMode;
  bool _isValidThresh = false;
  bool _isValidTrack = false;
};