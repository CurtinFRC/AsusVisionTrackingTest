#pragma once

// #include "CJlib/cj.h"

#include "threading/Runnable.h"
#include "CJlib/captures/Capture.h"
#include "Display.h"
#include <mutex>

class Process : public Runnable, public Displayable {
 public:
  virtual void Init() override;
  virtual void Periodic() override;

  Process(Capture &capture);
  Capture &GetCapture();
  
  void GetDisplayMat(cv::Mat &displayMat) override;
  cv::Size GetDisplaySize() override;

  std::string GetProcessType();

 protected:
  Capture &_capture;
};
