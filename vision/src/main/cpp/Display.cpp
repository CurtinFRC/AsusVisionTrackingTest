#include "CJlib/cj.h"
#include "threading/Runnable.h"
#include "Display.h"

Display::Display(std::string name, Displayable &target) : _name(name), _target(target) {}

void Display::Init() {
  cv::Size size = _target.GetDisplaySize();
  _output = frc::CameraServer::GetInstance()->PutVideo(_name, size.width, size.height);

#ifdef __DESKTOP__
  cv::namedWindow(_name);
  SetUseCVWait(true);
#endif
}

void Display::Periodic() {
  _target.GetDisplayMat(_displayMat);
  if (_displayMat.rows > 0 && _displayMat.cols > 0) {
#ifdef __DESKTOP__
    cv::imshow(_name, _displayMat);
#endif
    _output.PutFrame(_displayMat);
  }
}

