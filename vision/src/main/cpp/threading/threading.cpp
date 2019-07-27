#include <thread>
#include <iostream>

#include "vision.h"
#include "captures/capture.h"

void curtin_frc_vision::threading() {

  // Thread Initialization
  std::thread captureObj(&curtin_frc_vision::capturePeriodic, this);
  std::thread processingObj(&curtin_frc_vision::processingPeriodic, this);
  std::thread displayObj(&curtin_frc_vision::displayPeriodic, this);

  // Thread Joining
  captureObj.join();
  processingObj.join();
  displayObj.join();
}

