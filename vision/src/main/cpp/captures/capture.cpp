// Local Libraries
#include "captures/capture.h"
#include "vision.h"

void curtin_frc_vision::captureInit() {
  cs::UsbCamera cam{"USBCam", camPort};
  cs::CvSink sink{"USB"};
  sink.SetSource(cam);

  cam.SetResolution(resWidth, resHeight);

  auto video_mode = cam.GetVideoMode();

  // This lets us see the camera output on the robot dashboard. We give it a name, and a width and height.
  output = frc::CameraServer::GetInstance()->PutVideo("USB Camera", video_mode.width, video_mode.height);

  imgOriginal = cv::Mat::zeros(video_mode.height, video_mode.width, CV_8UC3); // Zeros out the frame

  cam.SetExposureManual(camExposure); // Sets the exposure of the camera

  if (sink.GrabFrame(imgOriginal) != 0) {
    isValidFrame = true;
  }
  
}

void curtin_frc_vision::capturePeriodic() {
  if (isValidFrame) {
    cvtColor(imgOriginal, imgTracking, CV_BGR2HSV); // Converts the frame from BGR to HSV
  }
}