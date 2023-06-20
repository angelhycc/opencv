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

    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    imshow("gray", gray);

    Mat blank = Mat::zeros(image.rows, image.cols, CV_8UC3);
    imshow("blank", blank);

    // using canny way << RECOMMENDED
    Mat blur;
    GaussianBlur(gray, blur, Size(5, 5), cv::BORDER_DEFAULT);
    imshow("blur", blur);

    Mat canny;
    Canny(blur, canny, 125, 175);
    imshow("canny edges",canny);

    // using threshold way 
    // Mat thresh;
    // threshold(gray, thresh, 125, 255, THRESH_BINARY);
    // imshow("threshold", thresh);

    std::vector<std::vector<Point> > contours;
    std::vector<Vec4i> hierarchy;
    findContours(canny, contours, hierarchy, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);
    std::cout << contours.size() << " this many contours\n"; 

    drawContours(blank, contours, -1, (0, 0, 255));
    imshow("drawn", blank);



    waitKey(0);
    return 0;
}

