#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int hmin = 0, smin = 20, vmin = 20;
int hmax = 200, smax = 200, vmax = 200;

int main() {
    Mat image, mask, hsvImage;
    string path = "G:/phooto/profile-pic.png";
    image = imread(path);
    if (image.empty()) {
        cout << "Error Loading Image";
        return -1;
    }
    cvtColor(image, hsvImage, COLOR_BGR2HSV);

    namedWindow("mask1", (320, 320));
    createTrackbar("h Val", "mask1", &hmin, 179);
    createTrackbar("hVal max", "mask1", &hmax, 179);
    createTrackbar("s Val", "mask1", &smin, 255);
    createTrackbar("sVal max", "mask1", &smax, 255);
    createTrackbar("v Val", "mask1", &vmin, 255);
    createTrackbar("vVal max", "mask1", &vmax, 255);

    while (true) {
        Scalar Lower(hmin, smin, vmin);
        Scalar Upper(hmax, smax, vmax);

        inRange(hsvImage, Lower, Upper, mask);
        imshow("image", image);
        imshow("hsv", hsvImage);
        imshow("mask", mask);

        // Break the loop if 'q' key is pressed
        if (waitKey(1) == 'q') {
            break;
        }
    }

    return 0;
}
