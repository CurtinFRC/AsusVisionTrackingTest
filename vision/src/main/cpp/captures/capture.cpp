// Local Libraries
#include "captures/capture.h"
#include "vision.h"

void Capture::captureInit() {
  cs::UsbCamera cam{"USBCam", camPort};
  cs::CvSink sink{"USB"};
  sink.SetSource(cam);
  std::cout << "Started Capture" << std::endl;

  cam.SetResolution(resWidth, resHeight);
  cam.SetExposureManual(camExposure); // Sets the exposure of the camera

  auto video_mode = cam.GetVideoMode();

  // This lets us see the camera output on the robot dashboard. We give it a name, and a width and height.
  output = frc::CameraServer::GetInstance()->PutVideo("USB Camera", video_mode.width, video_mode.height);

  _captureMat = cv::Mat::zeros(video_mode.height, video_mode.width, CV_8UC3); // Zeros out the frame

  initCondVar.notify_all();
}

void Capture::capturePeriodic() {
  isValidFrame = sink.GrabFrame(_captureMat) != 0;
}

void Capture::CopyCaptureMat(cv::Mat &captureMat) {
  std::lock_guard<std::mutex> lock(classMutex);
  _captureMat.copyTo(captureMat);
}