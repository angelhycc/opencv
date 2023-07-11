#include <opencv2/opencv.hpp>
#include <vector>
#include <stdio.h>

using namespace cv;

std::string photo = "../../photos/dog1.jpg";

int main(){
    Mat image = imread(photo);
    resize(image, image, cv::Size(), 0.2, 0.2);
    imshow("dog", image);

    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);

    // simple thresholding 
    Mat thresh; 
    threshold(gray, thresh, 100,255, THRESH_BINARY);
    imshow("simple threshold", thresh);

    Mat thresh_inv;
    threshold(gray, thresh_inv, 100, 255, THRESH_BINARY_INV);
    imshow("simple threshold inv", thresh_inv);

    // Adaptive Thresholding
    Mat adap; 
    adaptiveThreshold(gray, adap, 100, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 3);
    imshow("adaptive Thresholding", adap);

    Mat gaussian;
    adaptiveThreshold(gray, gaussian, 100, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 3);
    imshow("gaussian", gaussian);


    waitKey(0);
    return 0;
}