#include <thread>
#include <iostream>

#include "vision.h"
#include "process.h"

void curtin_frc_vision::processingInit() {
  
}

void curtin_frc_vision::processingPeriodic() {
  if (isValidFrame) {

    // Threshold the HSV image, (keeps only desired coloured pixles)
    cv::inRange(imgTracking, cv::Scalar(35, 100, 100), cv::Scalar(78, 255, 255), imgTracking);

    // Forgets Threshholded pixles under a certain size.
    if (noisefix != 0) {
      cv::erode( imgTracking, imgTracking, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(noisefix, noisefix)));
			cv::dilate(imgTracking, imgTracking, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(noisefix, noisefix)));
    }

    isDisplayable = true;
  }
}