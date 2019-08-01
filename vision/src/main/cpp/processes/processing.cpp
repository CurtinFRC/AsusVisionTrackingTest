#include <thread>
#include <iostream>

#include "vision.h"
#include "processes/processing.h"

//Set _capture as a Capture object reference
Process::Process(Capture &capture) : _capture(capture) {}

Capture &Process::GetCapture() {
  return _capture;
}

void Process::processingInit() {
  
}

void Process::processingPeriodic() {
  if (isValidFrame) {

    // Threshold the HSV image, (keeps only desired coloured pixles)
    cv::inRange(imgTracking, cv::Scalar(35, 100, 100), cv::Scalar(78, 255, 255), imgTracking);

    // Forgets Threshholded pixles under a certain size.
    if (noisefix != 0) {
      cv::erode( imgTracking, imgTracking, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(noisefix, noisefix)));
			cv::dilate(imgTracking, imgTracking, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(noisefix, noisefix)));
    }
    
    if (useTapeDetection) {
      
    }

    isDisplayable = true;
  }
}