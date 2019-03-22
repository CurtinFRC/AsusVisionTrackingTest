#include <iostream>
#include "modular.h"

Modular::Modular(std::string name, Modularity &target) : _name(name), _target(target) {}

void Modular::Init() {
 UseKinect = false;
 DriverCam = false;

 CamPorts = (4,5); // Latter is Driver

 CamExposure = (-100,40);

 DetectRound = false;
 DetectSquare = false;

 DetectColour = green; // red, green, blue

}

void Modular::Periodic() {
 
}
