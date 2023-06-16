#include <opencv2/opencv.hpp>
#include <vector>
#include <stdio.h>
#include <string>

using namespace cv;

Mat translation (Mat img, float x, float y);
Mat rotation (Mat img, int angle, Point2f center);
std::string photo = "../../photos/dog2.jpg";

int main(){
    Mat image = imread(photo);
    imshow("dog", image);


    // Translated 
    Mat translated = translation( image, 100, 100 );
    imshow("translated", translated);

    // Rotation
    Mat rotated = rotation ( image, 45, Point2f(image.cols / 2, image.rows /2 ));
    imshow("rotated", rotated);

    // Flipping 
    Mat flipped;
    flip(image, flipped, 0);
    imshow("flipped", flipped);

    waitKey(0);
    return 0;
}

Mat translation(Mat img, float x, float y){
    Mat rtn;
    float warpvalues [] = { 1.0, 0.0, x, 0.0, 1.0, y };
    Mat translationMatrix = Mat(2, 3, CV_32F, warpvalues);

    warpAffine(img, rtn, translationMatrix, img.size());
    return rtn;
}

Mat rotation (Mat img, int angle, Point2f center = Point2f(0, 0)){
    Mat rtn;
    Mat rotationMatrix = getRotationMatrix2D(center, angle, 1);

    warpAffine(img, rtn, rotationMatrix, img.size());
    return rtn;
}   