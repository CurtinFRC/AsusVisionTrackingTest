#include "CJlib/cj.h"
#include "visionMap.h"

using namespace cv;
using namespace std;

Capture::Capture(int port, int exposure) : _cam("USBCam", port) {_cam.SetExposureManual(exposure);}

// Getters
cs::VideoMode Capture::GetVideoMode() {
  if (_videoMode.height == 0 || _videoMode.width == 0) {
    // If our videoMode is invalid, wait for Init() to be called (thus setting _videoMode)
    // using our condition variable
    std::unique_lock<std::mutex> lock(_classMutex);
    _initCondVar.wait(lock);
  }
  return _videoMode;
}

// Copiers
void Capture::CopyCaptureMat(cv::Mat &captureMat) {
  std::lock_guard<std::mutex> lock(_classMutex);
  _captureMat.copyTo(captureMat);
}

bool Capture::IsValidFrameThresh() {
  return _isValidThresh;
}

bool Capture::IsValidFrameTrack() {
  return _isValidTrack;
}



void Capture::Init() {
  //std::lock_guard<std::mutex> lock(_classMutex); // do i need this ? *

  _sink.SetSource(_cam);

  // The camera defaults to a lower resolution, but you can choose any compatible resolution here.
  _cam.SetResolution(resWidth,resHeight);

  for (auto it : _cam.EnumerateProperties()) {
    std::cout << "Property: " << it.GetName() << " -> " << it.Get() << std::endl;
  }

  _videoMode = _cam.GetVideoMode();
  std::cout << "Width: " << _videoMode.width << " Height: " << _videoMode.height << std::endl;
  _captureMat = cv::Mat::zeros(_videoMode.height, _videoMode.width, CV_8UC3);
  _initCondVar.notify_all();
}

void Capture::Periodic() {
  _isValidThresh = _isValidTrack = _sink.GrabFrame(_captureMat) != 0;
  // _isValidTrack = _sink.GrabFrame(_captureMat) != 0;
  // std::cout << _sink.GrabFrame(_captureMat) << std::endl;
}