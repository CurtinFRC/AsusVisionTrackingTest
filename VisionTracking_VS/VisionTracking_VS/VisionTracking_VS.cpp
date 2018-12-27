// VisionTracking_VS.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author CJBuchel <https://github.com/CJBuchel>

#include "pch.h"
#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

RNG rng(12345);
int thresh = 100;

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

		//Green Hue Processing Block
		//========================================================================================================
		//--------------------------------------------------------------------------------------------------------
		//========================================================================================================
		Mat imgOriginal;
		Mat green_track_output;

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
		//cv::Mat lower_green_hue_range;
		//cv::Mat upper_green_hue_range;
		cv::Mat green_hue_image;
		//cv::inRange(img_HSV, cv::Scalar(35, 100, 100), cv::Scalar(50, 255, 255), lower_green_hue_range);
		//cv::inRange(img_HSV, cv::Scalar(50, 100, 100), cv::Scalar(78, 255, 255), upper_green_hue_range);
		cv::inRange(img_HSV, cv::Scalar(35, 100, 100), cv::Scalar(78, 255, 255), green_hue_image);

		// Combine the above two images (lower green & upper green)
		//cv::Mat green_hue_image;
		//cv::addWeighted(lower_green_hue_range, 1.0, upper_green_hue_range, 1.0, 0.0, green_hue_image);

		// Blurs the Image, (helps with artifacts and small objects that are irrelevant)
		//cv::GaussianBlur(green_hue_image, green_hue_image, cv::Size(9, 9), 2, 2); 




		
	   //morphological opening (remove small objects from the foreground)
		erode(green_hue_image, green_hue_image, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(green_hue_image, green_hue_image, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		/*
		//morphological closing (fill small holes in the foreground)
		dilate(green_hue_image, green_hue_image, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(green_hue_image, green_hue_image, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		*/
		
		//========================================================================================================
		//--------------------------------------------------------------------------------------------------------
		//========================================================================================================


		




		// Contours Blocks (Draws a convex shell over the thresholded image.
		//________________________________________________________________________________________________________
		//________________________________________________________________________________________________________
		/// Detect edges using Canny
		Mat canny_output;
		Canny(green_hue_image, canny_output, thresh, thresh * 2);

		/// Find contours
		vector<vector<Point> > contours;
		findContours(canny_output, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

		/// Find the convex hull object for each contour
		vector<vector<Point> >hull(contours.size());
		for (size_t i = 0; i < contours.size(); i++)
		{
			convexHull(contours[i], hull[i]);
		}

		/// Draw contours + hull results
		Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
		
		for (size_t i = 0; i < contours.size(); i++)
		{
			Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
			drawContours(drawing, contours, (int)i, color);
			drawContours(drawing, hull, (int)i, color);
		}
		
		//________________________________________________________________________________________________________
		//________________________________________________________________________________________________________





		// rectBorder Block, (Draws a border around the processed image and gives an x,y offset value)
		//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,



		//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,





		// User Outputs Block, uneeded for tracking on bot.
		//-------------------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------------------------

		//cv::addWeighted(green_hue_image, 1.0, drawing, 1.0, 0.0, green_track_output);
		
		/// Show in a window
		imshow("Hull", drawing);
		imshow("Track Output", green_hue_image);
		//imshow("Thresholded Image", green_hue_image); //show the thresholded image
		//imshow("Threshold Image upper", green_hue_image);
		//imshow("Threshold Image lower", lower_green_hue_range);
		imshow("Something", img_HSV);
		//imshow("Original", imgOriginal); //show the original image

		//-------------------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------------------------
		
		
		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	return 0;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 