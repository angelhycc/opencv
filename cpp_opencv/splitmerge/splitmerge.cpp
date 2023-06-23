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

    Mat blank = Mat::zeros(Size(image.cols, image.rows), CV_8UC1);

    Mat bgrchannel[3]; 
    split(image, bgrchannel);
    imshow("b", bgrchannel[0]);
    imshow("g", bgrchannel[1]);
    imshow("r", bgrchannel[2]);

    std::vector<Mat> input_merge = {bgrchannel[0], bgrchannel[1], bgrchannel[2]};
    Mat merged; 
    merge(input_merge, merged);
    imshow("merged", merged);

    std::vector<Mat> bl = {bgrchannel[0], blank, blank};
    std::vector<Mat> gr = {blank, bgrchannel[1], blank};
    std::vector<Mat> re = {blank, blank, bgrchannel[2]};

    Mat blue, green, red;
    merge(bl, blue);
    merge(gr, green);
    merge(re, red);

    imshow("blue", blue);
    imshow("green", green);
    imshow("red", red);


    waitKey(0);
    return 0;
}

