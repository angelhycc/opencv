#include <opencv2/opencv.hpp>
#include <vector>
#include <stdio.h>

using namespace cv;


int main(){
    // blank canvas
    Mat blank = Mat::zeros(500, 500, CV_8UC3);
    imshow("blank", blank);
    
    Point pt1(30, 30);
    Point pt2(470, 470);
    Mat rec = blank.clone();

    rectangle(rec, pt1, pt2, 255, -1, 8, 0);
    imshow("rectangle", rec);

    Mat circ = blank.clone();
    circle(circ, Point(250, 250), 250, 255, -1, 8, 0);
    imshow("circle", circ);

    // bitwise and
    Mat bit_and; 
    bitwise_and(rec, circ, bit_and);
    imshow("bitwise and", bit_and);

    // bitwise or
    Mat bit_or;
    bitwise_or(rec, circ, bit_or);
    imshow("bitwise or", bit_or);

    // bitwise xor
    Mat bit_xor;
    bitwise_xor(rec, circ, bit_xor);
    imshow("bitwise xor", bit_xor);

    // bitwise nor
    Mat bit_nor;
    bitwise_not(bit_or, bit_nor);
    imshow("bitwise nor", bit_nor);

    

    waitKey(0);
    return 0;
}