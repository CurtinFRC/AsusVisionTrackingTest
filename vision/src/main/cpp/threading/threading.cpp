#include <thread>
#include <iostream>

#include "vision.h"

void threading() {
  // Thread Initialization
  std::thread captureObj(capturePeriodic);
  std::thread processingObj(processingPeriodic);
  std::thread displayObj(displayPeriodic);

  // Thread Joining
  captureObj.join();
  processingObj.join();
  displayObj.join();
}

