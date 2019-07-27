#include <thread>
#include <iostream>

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
#include "captures/capture.h"
#include "vision.h"

void curtin_frc_vision::captureInit() {
  cs::UsbCamera cam{"USBCam", camPort};
  cs::CvSink sink{"USB"};
  sink.SetSource(cam);

  cam.SetResolution(resWidth, resHeight);

  auto video_mode = cam.GetVideoMode();

  // This lets us see the camera output on the robot dashboard. We give it a name, and a width and height.
  cs::CvSource output = frc::CameraServer::GetInstance()->PutVideo("USB Camera", video_mode.width, video_mode.height);

  imgOriginal = cv::Mat::zeros(video_mode.height, video_mode.width, CV_8UC3);

  cam.SetExposureManual(camExposure);

  if (sink.GrabFrame(imgOriginal) != 0) {
    isValidFrame = true;
  }
  
}

void curtin_frc_vision::capturePeriodic() {
  if (isValidFrame)
  {
    
  }
  
}