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


    int histSize = 256;
    float range[] = { 0, 256 };
    const float* histRange[] = { range };
    bool uniform = true, accumulate = false;
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound( (double) hist_w/histSize );

    // GrayScale image histogram 
    Mat grayscale;
    cvtColor(image, grayscale, COLOR_BGR2GRAY);

    std::vector<Mat> bgr_planes0;
    split( grayscale, bgr_planes0 );
    Mat gray_hist;
    calcHist( &bgr_planes0[0], 1, 0, Mat(), gray_hist, 1, &histSize, histRange, uniform, accumulate );

    // plotting the histogram onto an image
    Mat grayhistImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
    normalize(gray_hist, gray_hist, 0, grayhistImage.rows, NORM_MINMAX, -1, Mat() );
    for( int i = 1; i < histSize; i++ )
    {
        line( grayhistImage, Point( bin_w*(i-1), hist_h - cvRound(gray_hist.at<float>(i-1)) ),
            Point( bin_w*(i), hist_h - cvRound(gray_hist.at<float>(i)) ),
            Scalar( 255, 0, 0), 2, 8, 0 
        );
    }
    imshow("gray hist ", grayhistImage);



    // Color Image histogram
    std::vector<Mat> bgr_planes;
    split( image, bgr_planes );
    
    Mat b_hist, g_hist, r_hist;
    calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, histRange, uniform, accumulate );
    calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, histRange, uniform, accumulate );
    calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, histRange, uniform, accumulate );

    // plotting on the histogram
    Mat colorhistImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
    normalize(b_hist, b_hist, 0, colorhistImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(g_hist, g_hist, 0, colorhistImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(r_hist, r_hist, 0, colorhistImage.rows, NORM_MINMAX, -1, Mat() );
    for( int i = 1; i < histSize; i++ )
    {
        line( colorhistImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ),
            Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
            Scalar( 255, 0, 0), 2, 8, 0 
        );
        line( colorhistImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ),
            Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
            Scalar( 0, 255, 0), 2, 8, 0 
        );
        line( colorhistImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ),
            Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
            Scalar( 0, 0, 255), 2, 8, 0 
        );
    }
    imshow("color histogram", colorhistImage );

    waitKey(0);
    return 0;
}