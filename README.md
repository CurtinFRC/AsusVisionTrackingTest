# ModularVisionTracking
- This program is used for easy placement into an FRC program, using modularity and easy change for the required game.
- To build Program use .\gradlew vision:build .To Run Program use .\gradlew vision:runvision .To deploy to a tinkerboard or pi us .\gradlew vision:deploy  Note that when using tinkerboard deploy might not work to OS, you might need to use Raspbian ISO properly installed to the sd

## Usage 
- To use modular vision tracking (using the options given) navigate to `visionMap.cpp`, and make sure you have `usingCJlib = true`.
- Then you can change the options as you see fit, it also gives the option for a custom colour config, and a custom detection within the options. And boom, that easy, run or deploy your program and it should give you values from the detection to network tables. (if you are using the [CurtinFRC GUI](https://github.com/CJBuchel/CurtinGUI) then you can simply login and see the camera output. else you can use shuffleboard, SmartDashboard or web ui to view the camera output
- But if your the kind of person who needs a very specific set of tracking, look no further. Just change the boolean in `visionMap.cpp -> usingCJlib` to `false` and it will use the custom library that you give and custom vision tracking cpp folders. inside `CustomVision` and `CustomLib` it's comes with a preset of code that detects a green object using a ring light and gives an X & Y offset. But of course, you can change it to what ever you need.

## [More Info](vision)
