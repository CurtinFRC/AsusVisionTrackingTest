#include <thread>
#include <iostream>

#include "vision.h"

cv::RNG rng(12345);
cv::Rect bounding_rect;
int thresh = 100;
float height_offset;
float width_offset;
int ResWidth = 640, ResHeight = 480;
float width_goal;
float height_goal;

bool usingTapeTrack = false;

void captureInit() {
  /*
  cs::CvSink sink{"USB"};
  sink.SetSource(cam);
  
  cam.SetResolution(ResWidth, ResHeight);

  width_goal = ResWidth/2;
  height_goal = ResHeight/2;

	auto video_mode = cam.GetVideoMode();
  std::cout << "Width: " << video_mode.width << " Height: " << video_mode.height << std::endl;
  std::cout << "Goals: " << width_goal << "," << height_goal << std::endl; 

	
	// This lets us see the camera output on the robot dashboard. We give it a name, and a width and height.
  cs::CvSource output = frc::CameraServer::GetInstance()->PutVideo("USB Camera", video_mode.width, video_mode.height);

  cv::Mat imgOriginal{video_mode.height, video_mode.width, CV_8UC3};

	// Changes the exposure for detecting retroReflective Tape and gives minimal error (requires ring light, And only works once deployed to a Pi/Tinker)
	if (usingTapeTrack);
	{
		cam.SetExposureManual(-100);
	}
  */
}

void capturePeriodic() {
  /*
  if (sink.GrabFrame(imgOriginal) != 0) {
  }
  */
  
}