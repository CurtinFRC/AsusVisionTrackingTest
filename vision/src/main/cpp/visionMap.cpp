#include "CJlib/cj.h"
#include "CustomLib/custom.h"
#include "visionMap.h"

// Vision Map is the main mapping source of the code. And allows you to change the options of the project
void visionMap() {
  usingCJlib = true;

  if (usingCJlib) {
    std::cout << "Using CJ's Library" << std::endl;

    /**/ // <-- Need to Link 

    /**/usingKinect = false; // Using the kinect as a camera
    camPort = 4; // The port the camera is located
    resWidth, resHeight = 640,480; // The resolution of the camera
    camExposure = -100; // The Exposure of the camera
    /**/colour = "Green"; // What colour to use i.e. (Red/Green/Blue/Custom)
    /**/Rvalue,Gvalue,Bvalue = 0,0,0; // Give a value if you have a custom colour i.e. (red,green,blue)/(255,255,255)
    /**/useTapeDetection = true; // Detect RetroReflective Tape
    /**/useBallDetection = false; // Detect Circular Object
    /**/personDetection = false; // Detect a person (Extemely Slow)
    /**/CustomDetection = false; // Use Custom detection i.e. for the central position of the rectangles in deepspace
    /**/offset = true; // Give xy offset from center of object. Also Sends to network tables
    /**/position = false; // gives xy coordinates of object on screen. Also Sends to network tables
    /**/distance = false ;// Gives Distance of object and sends it to network tables. (Only for Kinect)
    /**/blur = 0; // The blur of the object & gets rid of some imperfections (does slow processing)
    /**/noisefix = 0; // gets rid of noise under a certain pixel size (does slow the processing)
    

    
    

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

  if (usingCJlib) {
    CJVisionRunner vision;
  }
  else {
    VisionRunner vision;
  }

  #ifdef __DESKTOP__
  Capture capture{0, -100};
  #else
  Capture capture{camPort, camExposure};
  #endif

  // Threading
  std::thread Capture (Capture);
  //std::thread Process (Process);
  //std::thread Display (Display);



}