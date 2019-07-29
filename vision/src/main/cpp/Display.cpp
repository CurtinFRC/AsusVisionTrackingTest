#include <thread>
#include <iostream>

#include "vision.h"
#include "display.h"

void curtin_frc_vision::displayInit() {
  
}

void curtin_frc_vision::displayPeriodic() {
  if (isDisplayable)
  {
    #ifdef __DESKTOP__
      if (outputOriginalFrame) {cv::imshow("Original Image", imgOriginal);}
      if (outputTrackingFrame) {cv::imshow("Output Image", imgTracking);}
    #endif
      if (outputOriginalFrame) {output.PutFrame(imgOriginal);}
      if (outputTrackingFrame) {output.PutFrame(imgTracking);}
  }
  
}