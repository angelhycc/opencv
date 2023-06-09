#include <opencv2/opencv.hpp>
#include <vector>
#include <stdio.h>

using namespace cv;


int main(){
    // blank canvas
    Mat blank = Mat::zeros(500, 500, CV_8UC3);
    imshow("blank", blank);
    
    // 1. Paint with color;
    Mat paint = blank.clone();
    paint.setTo(Scalar(255,255,255));
    imshow("white", paint);

    // 2. Draw different shapes;
    // std::vector<Point> pts = {Point(1, 1), Point(1, 100), Point(100,100), Point(100,1)};
    // Mat area = blank.clone();
    // // polylines(image to draw on, points, isClosed, color, thickness, lineType, shift)
    // polylines( area, pts, 1, Scalar(0,0,255), 2, 8, 0);
    // imshow("area", area);

    // 3. Draw Rectangle;
    Point pt1(0, 0);
    Point pt2(100, 100);
    Mat rec = blank.clone();
    // rectangle()
    rectangle(rec, pt1, pt2, Scalar(255, 255, 0), -1, 8, 0);
    imshow("rectangle", rec);

    // 4. Draw Line;
    Mat l = blank.clone();
    line(l, pt1, pt2, Scalar(255, 255, 0), 4, 8, 0);
    imshow("line", l);

    // 5. Draw Circle;
    Mat circ = blank.clone();
    circle(circ, Point(100, 100), 40, Scalar(255, 255, 255), 2, 8, 0);
    imshow("circle", circ);

    // 6. Write Text;
    Mat text = blank.clone();
    putText(text, "Hello", Point (100, 100), FONT_HERSHEY_TRIPLEX, 4, Scalar(255, 255, 255),1, 8, 0 );
    imshow("text", text);

    waitKey(0);
    return 0;
}