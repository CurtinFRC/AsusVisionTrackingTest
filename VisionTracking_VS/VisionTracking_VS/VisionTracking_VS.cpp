// VisionTracking_VS.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author CJBuchel <https://github.com/CJBuchel>

#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <Windows.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	VideoCapture cap(0); //capture the video from web cam

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}


	

	while (true)
	{
		Mat imgOriginal;

		bool bSuccess = cap.read(imgOriginal); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}



		// Convert input image to HSV
		Mat img_HSV;

		cvtColor(imgOriginal, img_HSV, COLOR_BGR2HSV); //Convert the captugreen frame from BGR to HSV
		
		// Threshold the HSV image, keep only the green pixels
	 	cv::Mat lower_green_hue_range;
		cv::Mat upper_green_hue_range;
		cv::inRange(img_HSV, cv::Scalar(35, 100, 100), cv::Scalar(50, 255, 255), lower_green_hue_range);
	 	cv::inRange(img_HSV, cv::Scalar(50, 100, 100), cv::Scalar(78, 255, 255), upper_green_hue_range);

		// Combine the above two images
		cv::Mat green_hue_image;
	 	cv::addWeighted(lower_green_hue_range, 1.0, upper_green_hue_range, 1.0, 0.0, green_hue_image);

		//cv::GaussianBlur(green_hue_image, green_hue_image, cv::Size(9, 9), 2, 2);







	   //morphological opening (remove small objects from the foreground)
		erode(green_hue_image, green_hue_image, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(green_hue_image, green_hue_image, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//morphological closing (fill small holes in the foreground)
		dilate(green_hue_image, green_hue_image, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(green_hue_image, green_hue_image, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));








		//Border Code... Not finished, feel free to figure it out.
		//===============================================================================
		vector<Rect> Object;

		for (size_t i = 0; i < Object.size(); i++)
		{
			rectangle(imgOriginal, Object[i], Scalar(0, 255, 0));
		}
		//===============================================================================






		//----------------------------------------------------------------------------
		//----------------------------------------------------------------------------

		//imshow("Thresholded Image", green_hue_image); //show the thresholded image
		imshow("Threshold Image", green_hue_image);
		//imshow("Threshold Image lower", lower_green_hue_range);

		//imshow("Original", imgOriginal); //show the original image

		imshow("Epilepsy", img_HSV);


		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "ESC key is pressed by user" << endl;
			break;
		}
	}

	return 0;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
