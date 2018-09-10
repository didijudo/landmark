// Summary: 绘制人脸关键点和多边形线
// Author:  Amusi
// Date:    2018-03-20

#ifndef _renderFace_H_
#define _renderFace_H_

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv; 
using namespace std; 

#define COLOR Scalar(0, 0, 255)

void drawPolyline
(
  Mat &im,
  const vector<Point2f> &landmarks,
  const int start,
  const int end,
  bool isClosed = false
)
{
    vector <Point> points;
		Point2f ls;
		Point2f li;
    for (int i = start; i <= end; i++)
    {
			if (i == 62) {
				ls = landmarks[i];
			}

			if (i == 66) {
				li = landmarks[i];
			}
        points.push_back(cv::Point(landmarks[i].x, landmarks[i].y));
    }

		double res = norm(ls-li);
		ostringstream strs;
		strs << res;
		string d = " Distancia " + strs.str();
		//Point2f lugar =  Point2f((int(im.cols/2 ),int(im.rows/2)));

		cv::putText(im, 
            d, 
            cv::Point(10, im.rows / 5), 
            cv::FONT_HERSHEY_DUPLEX,
            1.0,
            CV_RGB(118, 185, 0), 
            2);

    //polylines(im, points, isClosed, COLOR, 2, 16);

		cout << li.x << "\n";
		cout << ls.x << "\n";

		//circle(im, ls, 3, COLOR, FILLED);
		//circle(im, li, 3, COLOR, FILLED);
    
}

void drawLandmarks(Mat &im, vector<Point2f> &landmarks)
{
    if (landmarks.size() == 68)
    {
      drawPolyline(im, landmarks, 0, 16);           // Jaw line
      drawPolyline(im, landmarks, 17, 21);          // Left eyebrow
      drawPolyline(im, landmarks, 22, 26);          // Right eyebrow
      drawPolyline(im, landmarks, 27, 30);          // Nose bridge
      drawPolyline(im, landmarks, 30, 35, true);    // Lower nose
      drawPolyline(im, landmarks, 36, 41, true);    // Left eye
      drawPolyline(im, landmarks, 42, 47, true);    // Right Eye
      drawPolyline(im, landmarks, 48, 59, true);    // Outer lip
      drawPolyline(im, landmarks, 60, 67, true);    // Inner lip
    }
    else 
    { 
			for(int i = 0; i < landmarks.size(); i++)
			{
				circle(im,landmarks[i],3, COLOR, FILLED);
				
			}
    }
    
}

#endif // _renderFace_H_
