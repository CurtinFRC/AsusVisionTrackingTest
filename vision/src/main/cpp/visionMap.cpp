#include "CJlib/cj.h"
#include "CustomLib/custom.h"
#include "visionMap.h"

void visionMapInit() {
  usingCJlib = true;

  if (usingCJlib) {
    CJVisionRunner vision;
  }
  else {
    VisionRunner vision;
  }

  #ifdef __DESKTOP__
  Capture capture{0, -100};
  // Capture captureGamePiece{0, 50};
  #else
  Capture capture{4, -100};
  Capture captureGamePiece{5, 40};
  #endif

  if (usingCJlib) {
    std::cout << "Using CJ's Library" << std::endl;

    usingKinect = false; // Using the kinect as a camera
    camport = 4; // The port the camera is located
    resolution = 640,480; // The resolution of the camera
    exposure = -100; // The Exposure of the camera
    colour = Green; // What colour to use i.e. (Red/Green/Blue/Custom)
    useTapeDetection = true; // Detect RetroReflective Tape
    useBallDetection = false; // Detect Circular Object
    personDetection = false; // Detect a person (Extemely Slow)
    CustomDetection = false; // Use Custom detection i.e. for the central position of the rectangles in deepspace
    offset = true; // Give xy offset from center of object. Also Sends to network tables
    position = false; // gives xy coordinates of object on screen. Also Sends to network tables
    distance = false ;// Gives Distance of object and sends it to network tables. (Only for Kinect)
    blur = 0; // The blur of the object (gets rid of some imperfections) does slow processing
    noisefix = 0; // gets rid of noise under a certain pixel size
    

    
    

    // Reference code from ye old days
    /*
    HatchProcessing hatchProcess{captureGamePiece};
    BallProcessing ballProcess{capture};
    TapeProcessing tapeProcess{capture};
    
    Display displayBall{ballProcess};
    Display displayHatch{hatchProcess};
    Display displayTape{tapeProcess};
    
    vision.Run(capture);
    vision.Run(captureGamePiece);
    vision.Run(ballProcess);
    vision.Run(hatchProcess);
    vision.Run(tapeProcess);

    vision.Run(displayBall);
    vision.Run(displayHatch);
    vision.Run(displayTape);
    */
  }
  else // Using Custom
  {
    std::cout << "Using Custom Library" << std::endl;
    /*
    Processing Process{captureGamePiece};
    
    Display display{Process};
    
    vision.Run(capture);
    vision.Run(captureGamePiece);
    vision.Run(display);
    */
  }
  


  for (int i = 0; i < vision.workers.size(); i++) {
    vision.workers[i].join();
  }
}


void visionMapPeriodic() {

}