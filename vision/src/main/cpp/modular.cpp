#include <iostream>
#include "modular.h"

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


}

void Modular::Periodic() {
}
