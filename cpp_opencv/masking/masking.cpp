#include <opencv2/opencv.hpp>
#include <vector>
#include <stdio.h>

using namespace cv;

std::string photo = "../../photos/dog1.jpg";

int main(){
    Mat image = imread(photo);
    resize(image, image, cv::Size(), 0.2, 0.2);
    imshow("dog", image);

    // blank canvas
    Mat blank = Mat::zeros(image.rows, image.cols, CV_8U);
    imshow("blank", blank);

    Mat circle_mask = blank.clone();
    circle(circle_mask, Point(image.cols/2, image.rows/2), 100, Scalar(255,255,255), -1, 8, 0);
    imshow("circle", circle_mask);

    // bitwise and
    Mat masked_photo; 
    bitwise_and(image, image, masked_photo, circle_mask);
    imshow("masked_photo", masked_photo);

    waitKey(0);
    return 0;
}