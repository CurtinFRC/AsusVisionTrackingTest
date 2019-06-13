#include "threading/Runnable.h"
#include "visionMap.h"
#include <iostream>
#include "CJlib/captures/CJCapture.h"
// #include "CJlib/cj.h"

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

  #ifdef __DESKTOP__
  CJCapture CJcapture{0, -100};
  #else
  CJCapture CJcapture{camPort, camExposure};
  #endif

  if(usingCJlib){
    // Threading
    CJcapture.StartThread(30.0);
    // Process.StartThread(30.0);
  }else{
    // Threading
    // capture.StartThread(30.0);
    // Process.StartThread(30.0);
  }
  // Display.StartThread(30.0);
}