#pragma once
#include "CJlib/cj.h"

void visionMapInit();
void visionMapPeriodic();

bool usingKinect;
int camPort;
int resWidth;
int resHeight;
int camExposure;
std::string colour;
int Rvalue;
int Gvalue;
int Bvalue;
bool useTapeDetection;
bool useBallDetection;
bool personDetection;
bool CustomDetection;
bool offset;
bool position;
bool distance;
int blur;
int noisefix;


class VisionMap {
 public:


 private:

};