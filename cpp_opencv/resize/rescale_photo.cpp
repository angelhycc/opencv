#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;
// """Resize Image"""
int main(int argc, char** argv){
	if (argc != 2){
		printf("usage: displayImage.out <Image_Path>\n");
		return -1;
	}
	Mat image;
    Mat resized_image;
	image = imread(argv[1], 1);
    if (!image.data){
		printf("No image data\n");
		return -1;
	}
    // resize(in_img, out_img, cv::Size(), x_scale, y_scale, interpolation = 1 )
    resize(image,resized_image,cv::Size(), 0.2, 0.2);

	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", image);
    imshow("Resized Image", resized_image);
	waitKey(0);
	return 0;
}