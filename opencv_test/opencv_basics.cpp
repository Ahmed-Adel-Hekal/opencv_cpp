//#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


#define number 3

// Each number correspond to code segment 
// feel free to try any of codes 
// 0 - show img
// 1 - show video & camera stream
// 2 - convert img to Gray
//	   Gaussianblur / CannyEdgedetection / dilation / erode
// 3 - Resize & Crop image 

// number 0
// Load image and show it in c++ 
#if number == 0
int main() {

	std::string path = "G:/phooto/profile-pic.png";

	cv::Mat img = cv::imread(path);

	cv::imshow("Image", img);

	cv::waitKey(0);

	return 0;
}

#endif // number == 0


// number 1 
// Load video 
#if number == 1 
void main() {
	
	// this can be path for video or camera index 
	std::string path = "G:/[TutsNode.net] - Deep Learning for Computer Vision with Tensorflow 2 - 2022/1. Setup/1. Introduction.mp4";

	cv::VideoCapture cap(path);

	cv::Mat img; 
	bool ret;
	while (true) {
		
		ret = cap.read(img);
		if (ret == false) { std::cout << "Frame Error"; return; }
		cv::imshow("video", img);
		cv::waitKey(1);

		if (cv::waitKey(1) == 'q') {
			break; 
		}
	
	
	}


}
#endif

#if number ==2

void main() {

	std::string path = "G:/phooto/profile-pic.png";
	cv::Mat img = cv::imread(path);
	cv::Mat Grayimg, Blurimg, imgCanny, imgDilate, imgErot;

	cv::cvtColor(img, Grayimg, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img, Blurimg, cv::Size(3, 3), 5, 0);
	cv::Canny(Blurimg, imgCanny, 50, 100);
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(3, 3));
	cv::dilate(imgCanny, imgDilate, kernel);
	cv::erode(imgDilate, imgErot, kernel);
	cv::imshow("Original", img);
	cv::imshow("Gray", Grayimg);
	cv::imshow("Blur", Blurimg );
	cv::imshow("Canny", imgCanny);
	cv::imshow("Dilation", imgDilate);
	cv::imshow("Erote", imgErot);

	cv::waitKey(0);

}
#endif

#if number == 3

using namespace std;
using namespace cv ; 

int main() {
	string path = "G:/phooto/profile-pic.png";
	Mat img = cv::imread(path);
	Mat imgResized, imgCorp; 

	//cout << img.size(); 
	resize(img, imgResized, Size(320, 320)); // doesnot keep aspect ration
	resize(img, imgResized,Size(), .5, .5);  //keep aspect ratio 

	// Crop image 
	Rect roi(100, 100, 200, 200);
	imgCorp = img(roi);

	imshow("original", img);
	//imshow("resized without ratio", imgResized);
	imshow("resize keep aspect ratio", imgResized);
	imshow("Cropped Img ", imgCorp);

	waitKey(0);
	return 0;
}


#endif