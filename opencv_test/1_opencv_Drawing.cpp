#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv ;

# define number 1

#if number == 1 

int main() {

	// Blanck image 
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255)); // Make white image

	circle(img, Point(256, 256), 155, Scalar(0, 0, 255), -1);

	// you can define rect using 2 methods 
	// 1- points : provide location of topleft and bottomright
	// 2- rect object Rect roi(top, left, width, hight)

	rectangle(img, Point(130,226), Point(380,286),Scalar(255,255,255),-1);

	line(img, Point(130, 290), Point(382, 290), Scalar(255, 255, 255),3);

	putText(img, "This is Hekal Workshop", Point(150, 320), FONT_HERSHEY_DUPLEX, .5, Scalar(255, 255, 255),1,1 );

	imshow("img", img);
	waitKey(0);

	return 0;
	}



#endif
