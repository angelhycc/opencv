#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string>

using namespace cv;

std::string photo = "../../photos/dog2.jpg";

int main(){
    Mat image = imread(photo);
    resize(image, image, cv::Size(), 0.2, 0.2);
    imshow("dog", image);

    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    imshow("gray", gray);

    Mat hsv; 
    cvtColor(image, hsv, COLOR_BGR2HSV);
    imshow("hsv", hsv);

    Mat lab;
    cvtColor(image, lab, COLOR_BGR2Lab);
    imshow("lab", lab);

    Mat rgb;
    cvtColor(image, rgb, COLOR_BGR2RGB);
    imshow("rgb", rgb);

    // inverses also work (only no grayscale to hsc)
    Mat hsv_bgr;
    cvtColor(hsv, hsv_bgr, COLOR_HSV2BGR);
    imshow("hsv_bgr", hsv_bgr);

    Mat lab_bgr; 
    cvtColor(lab, lab_bgr, COLOR_Lab2BGR);
    imshow("lab2bgr", lab_bgr);


    waitKey(0);
    return 0;
}

