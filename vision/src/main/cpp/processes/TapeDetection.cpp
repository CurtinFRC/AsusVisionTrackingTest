#include <thread>
#include <iostream>

#include "vision.h"
#include "process.h"

cv::RNG rng(12345);
cv::Rect bounding_rect;

void curtin_frc_vision::TapeDetection() {

  // Detect Edges using Canny
  cv::Canny(imgTracking, imgTracking, thresh, thresh * 2);
  
  // Find contours
  std::vector<std::vector<cv::Point> > contours;
  std::vector<cv::Vec4i> hierarchy;
  cv::threshold(imgTracking, imgTracking, thresh, 255, cv::THRESH_BINARY);
  cv::findContours(imgTracking, contours, hierarchy, cv::RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

  // Find Convex hull object for each contour
  std::vector<std::vector<cv::Point> >hull(contours.size());
	for (size_t i = 0; i < contours.size(); i++)
	{
		convexHull(contours[i], hull[i]);
	}

  // Draw contours + hull results
  imgTracking = cv::Mat::zeros(imgTracking.size(), CV_8UC3);
  std::vector<cv::Rect> boundRect(contours.size());

  for (int i = 0; i < contours.size(); i++) {
    cv::Scalar color = cv::Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
    drawContours(imgTracking, contours, (int)i, color);
    drawContours(imgTracking, hull, (int)i, color);
  }

  // Detect edges using Threshold
  threshold(imgTracking, imgTracking, thresh, 255, cv::THRESH_BINARY);

  // Approximate contoursBox to polygons + get bounding rects and circles
  std::vector<std::vector<cv::Point> > hull_poly(hull.size());
  std::vector<cv::Point2f>center( hull.size());
	std::vector<float>radius( hull.size());

  for (int i = 0; i < hull.size(); i++ )  {
    approxPolyDP( cv::Mat(hull[i]), hull_poly[i], 3, true);
		boundRect[i] = cv::boundingRect( cv::Mat(hull_poly[i]));
		cv::minEnclosingCircle( (cv::Mat)hull_poly[i], center[i], radius[i]);
	}

  // Draw polygonal contour + bounding rects + circles
  for (int i = 0; i < hull.size(); i++) {
    cv::Scalar color = cv::Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255));
		drawContours( imgTracking, hull_poly, i, color, 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point());
		bounding_rect=boundingRect(contours[i]); // Find the bounding rectangle for biggest contour
		rectangle( imgTracking, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
		circle( imgTracking, center[i], (int)radius[i], color, 2, 8, 0);
  }

  // get the moments
  std::vector<cv::Moments> mu(hull.size());
	for( int i = 0; i<hull.size(); i++ )
	{ mu[i] = moments( hull[i], false ); }
	
	// get the centroid of figures.
	std::vector<cv::Point2f> mc(hull.size());
	for( int i = 0; i<hull.size(); i++)
	{ mc[i] = cv::Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 ); }

	for( int i = 0; i<hull.size(); i++ )
	{
		cv::Scalar color = cv::Scalar(167,151,0); // B G R values
		//drawContours(imgTracking, hull_poly, i, color, 2, 8, hierarchy, 0, Point());
		circle( imgTracking, mc[i], 4, color, -1, 8, 0 );

		// offsets from center
    if (offset) {
      cv::Point center = cv::Point((mc[i].x), (mc[i].y));
		  widthOffset = widthGoal - center.x;
		  heightOffset = heightGoal - center.y;

      std::stringstream offsetY;	offsetY << heightOffset;
      std::stringstream offsetX;	offsetX << widthOffset;
      cv::putText(imgTracking, "xy(" + offsetX.str() + "," + offsetY.str() + ")", mc[i] + cv::Point2f(-25,25), cv::FONT_HERSHEY_COMPLEX_SMALL, 1, cv::Scalar(255,0,255)); //text with distance and angle on target
    }
	}
}