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

    // Laplacian edge detection
    Mat lap; 
    Laplacian(gray, lap, CV_64F);
    convertScaleAbs(lap, lap);

    imshow("laplacian", lap);

    // Sobel 
    Mat sobx, soby;
    Sobel(gray, sobx, CV_64F, 1, 0);
    Sobel(gray, soby, CV_64F, 0, 1); 
    imshow("sobx", sobx);
    imshow("soby", soby);

    Mat sob;
    bitwise_or(sobx, soby, sob);
    imshow("sobel", sob);


    // Canny 
    Mat canny;
    Canny(gray, canny, 150, 175);
    imshow("canny", canny);

    waitKey(0);
    return 0;
}