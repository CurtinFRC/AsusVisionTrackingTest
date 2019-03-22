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
  Display(std::string name, Modularity &target);

  void Init() override;
  void Periodic() override;

 private:
  std::string _name;
  Modularity &_target;
  
  cs::CvSource _output;
  
  cv::Mat _displayMat;

  bool UseKinect;
  bool DriverCam;

  int CamPorts_W2 = (DetectCam, DriverCam);
  int CamProts_W1 = (DetectCam);


  bool DetectRound;
  bool DetectSquare;

  bool red;
  bool green;
  bool blue;

};