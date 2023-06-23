#include <opencv2/opencv.hpp>
#include <vector>
#include <stdio.h>
#include <string>
#include <vector>

using namespace cv;

std::string photo = "../../photos/dog1.jpg";

int main(){
    Mat image = imread(photo);
    resize(image, image, cv::Size(), 0.2, 0.2);
    imshow("dog", image);

    // Averaging 
    Mat avg;
    blur(image, avg, Size(3, 3));
    imshow("average", avg);

    // Gaussian
    Mat gau; 
    GaussianBlur(image, gau, Size(3,3), 0);
    imshow("gaussian", gau);

    // Median
    Mat med;
    medianBlur(image, med, 3);
    imshow("median", med);

    // Bilateral 
    Mat bi;
    bilateralFilter(image, bi, 5, 100, 100);
    imshow("bilateral", bi); 


    waitKey(0);
    return 0;
}

