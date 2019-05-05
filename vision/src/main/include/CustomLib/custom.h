// Customlib
#include "CustomLib/captures/Capture.h"
#include "CustomLib/devices/kinect.h"
#include "CustomLib/processes/BallProcessing.h"
#include "CustomLib/processes/HatchProcessing.h"
#include "CustomLib/processes/Process.h"
#include "CustomLib/processes/ProcessController.h"
#include "CustomLib/processes/TapeProcessing.h"
#include "CustomLib/threading/Runnable.h"

// OpenCV
#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

// System & others
#include <stdio.h>
#include <iostream>
#include <cameraserver/CameraServer.h>
#include <cscore.h>
#include <chrono>
#include <thread>

// Devices
#include "devices/kinect.h"

