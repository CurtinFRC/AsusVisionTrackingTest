#include "Display.h"
#include "visionMap.h"
#include "CJlib/Secret/itbroke.h"
#include <iostream>
#include <cameraserver/CameraServer.h>
#include <cscore.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>

#ifndef RUNNING_FRC_TESTS
int main(int argc, char **argv) {
  int team = 0;
  if (argc > 1) {
    team = std::stoi(argv[1]);
  }

#ifdef __DESKTOP__
  std::cout << "Running on Desktop - imshow enabled" << std::endl;
#else
  std::cout << "Running embedded  -imshow disabled" << std::endl;
#endif

  auto ntinst = nt::NetworkTableInstance::GetDefault();
  if (team != 0) {
    std::cout << "Starting Modular Vision Program (Client Mode - Team " << team << ")" << std::endl;
    ntinst.StartClientTeam(team);
  } else {
    std::cout << "Starting Modular Vision Program (Server Mode - For Testing Only)" << std::endl;
    ntinst.SetServer("CurtinFRCVision");
    ntinst.StartServer();
  }


  // Completed Main, Now Starting Up Vision Map
  visionMap();
  
  std::cout << "Vision Program Exited. Broken??" << std::endl;
  itbroke();
  return -1;
}
#endif