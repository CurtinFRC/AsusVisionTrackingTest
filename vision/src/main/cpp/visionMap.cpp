#include <iostream>
#include "visionMap.h"

// This code by default is designed for 1 camera. and gives the option for one extra camera as a driver cam

Modular::Modular(std::string name, Modularity &target) : _name(name), _target(target) {}

void Modular::Init() {
	UseKinect = false;
	DriverCam = false;

	if(DriverCam) {
		CamPorts_W2 = (4,5); // Latter is Driver
	} else {
		CamPorts_W1 = (4);
	}

	DetectCamExposure = (-100);
	DriverCamExposure = (40); // If true

	DetectRound = false;
	DetectSquare = false;

	DetectColour = green; // red, green, blue

	offset_OutputName = "example";
	


}

void Modular::Periodic() {
}