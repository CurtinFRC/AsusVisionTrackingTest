#include <thread>
#include <iostream>

#include "vision.h"
#include "captures/capture.h"
#include "processes/processing.h"
#include "display.h"

Display::Display(std::string name, Displayable &target) : _name(name), _target(target) {}

void Display::displayInit() {
  cv::Size size = _target.GetDisplaySize();
  _output = frc::CameraServer::GetInstance()->PutVideo(_name, size.width, size.height);
}

void Display::displayPeriodic() {
  _target.GetDisplayMat(_displayMat);
  if (_displayMat.rows > 0 && _displayMat.cols > 0) {
#ifdef __DESKTOP__
    cv::imshow(_name, _displayMat);
#endif
    _output.PutFrame(_displayMat);
  }
}

