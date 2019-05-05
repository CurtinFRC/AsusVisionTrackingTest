#pragma once

#include "CJRunnable.h"

#include <thread>
#include <vector>
#include <mutex>

class CJVisionRunner {
 public:
  void Run(Runnable &run);
  std::vector<std::thread> workers;
};

