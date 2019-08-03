#include <thread>
#include <iostream>

#include "vision.h"
#include "captures/capture.h"
#include "processes/processing.h"

void curtin_frc_vision::threading() {


  // Capture Thread Initialization
  std::thread captureInitObj(&Capture::captureInit, this);
  std::thread capturePeriodicObj(&Capture::capturePeriodic, this);
  std::thread captureCopyObj(&Capture::CopyCaptureMat, this);

  // Processing Thread Initialization
  std::thread processingInitObj(&Process::processingInit, this);
  std::thread processingPeriodicObj(&Process::processingPeriodic, this);

  // Sub Process Initialization
  std::thread tapeDetectionObj(&curtin_frc_vision::TapeDetection, this);
  // std::thread ballDetectionObj(&curtin_frc_vision::BallDetection, this);
  // std::thread squareDetection(&curtin_frc_vision::SquareDetection, this);

  // Display Thread Initialization
  std::thread displayInitObj(&Display::displayInit, this);
  std::thread displayPeriodicObj(&Display::displayPeriodic, this);

  // Capture Thread Joining
  captureInitObj.join();
  capturePeriodicObj.join();
  captureCopyObj.join();

  // Process Thread Joining
  processingInitObj.join();
  processingPeriodicObj.join();

  // Sub Process Thread joining 
  tapeDetectionObj.join();
  // ballDetectionObj.join();
  // squareDetectionObj.join();
  
  // Display Thread Joining
  displayInitObj.join();
  displayPeriodicObj.join();
}