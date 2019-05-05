#pragma once

#include <opencv2/core/core.hpp>
#include <cscore.h>

#include "threading/Runnable.h"

#include <mutex>

class Modularity {
 public:
  virtual void GetDisplayMat(cv::Mat &displayMat) = 0;
  virtual cv::Size GetDisplaySize() = 0;
};

class Modular : public RunModular {
 public:

  void Init() override;
  void Periodic() override;

 private:
  std::string _name;
  Modularity &_target;
  
  cs::CvSource _output;
  
  cv::Mat _displayMat;

  bool usingCustom;

}
