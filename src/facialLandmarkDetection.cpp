#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include "drawLandmarks.hpp"


using namespace std;
using namespace cv;
using namespace cv::face;


int main(int argc,char** argv)
{
	// [1]Haar Face Detector
    CascadeClassifier faceDetector("/usr/local/Cellar/opencv/3.4.2/share/OpenCV/haarcascades/haarcascade_frontalface_alt2.xml");
	
	// [2]LBP Face Detector
	//CascadeClassifier faceDetector("lbpcascade_frontalface.xml");

	//TODO fazer o limiar entre 4 pontos na boca. 2 do centro dos labios e 2 dos cantos da boca

    Ptr<Facemark> facemark = FacemarkLBF::create();
    //Ptr<Facemark> facemark = FacemarkKazemi::create();

    //facemark->loadModel("lbfmodel.yaml");
    facemark->loadModel(argv[1]);

    //VideoCapture cam(0);
    
    Mat frame, gray;
    
    //while(cam.read(frame))
		//
		frame = imread(argv[2]);
		if (1)
    {
      
      vector<Rect> faces;
			//resize(frame,frame,Size(800,600),0,0,INTER_LINEAR_EXACT);
      cvtColor(frame, gray, COLOR_BGR2GRAY);

      faceDetector.detectMultiScale(gray, faces);
      
      vector< vector<Point2f> > landmarks;
      
      bool success = facemark->fit(frame,faces,landmarks);
      
      if(success) {
        for(int i = 0; i < landmarks.size(); i++) {
					drawLandmarks(frame, landmarks[i]);
					drawFacemarks(frame, landmarks[i], Scalar(255, 255, 255));
        }
	
      }

      imshow("Facial Landmark Detection", frame);
			imwrite("bibiaalter.jpg", frame); 
			waitKey(0);

			
      return 0;
      
    }
		//return 0;
}
