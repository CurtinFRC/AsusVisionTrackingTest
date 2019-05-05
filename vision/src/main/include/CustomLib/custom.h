// CustomLib
#include "CustomLib/captures/Capture.h"
#include "CustomLib/devices/kinect.h"
#include "CustomLib/processes/BallProcessing.h"
#include "CustomLib/processes/HatchProcessing.h"
#include "CustomLib/processes/Process.h"
#include "CustomLib/processes/ProcessController.h"
#include "CustomLib/processes/TapeProcessing.h"
#include "CustomLib/threading/Runnable.h"
#include "CustomLib/threading/VisionRunner.h"

// OpenCV
#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

// System and Threading
#include <stdio.h>
#include <iostream>
#include <cameraserver/CameraServer.h>
#include <cscore.h>
#include <chrono>
#include <thread>

// Network Tables and Camera Servers
#include <cameraserver/CameraServer.h>
#include <cscore.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>

// Devices
#include "devices/kinect.h"


// Using CustomLib

bool usingCJlib;

