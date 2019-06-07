#pragma once
// CJlib
#include "CJlib/captures/Capture.h"
#include "CJlib/processes/BallProcessing.h"
#include "CJlib/processes/HatchProcessing.h"
#include "CJlib/processes/Process.h"
#include "CJlib/processes/ProcessController.h"
#include "CJlib/processes/TapeProcessing.h"
#include "CJlib/threading/CJRunnable.h"
#include "CJlib/threading/CJVisionRunner.h"

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


// Using CJlib

bool usingCJlib;

