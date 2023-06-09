#include <opencv2/opencv.hpp>
#include <vector>
#include <stdio.h>

using namespace cv;

int main(int argc, char** argv){
	if (argc != 2){
		printf("usage: displayImage.out <Image_Path>\n");
		return -1;
	}
	Mat image;
	image = imread(argv[1], 1);
	if (!image.data){
		printf("No image data\n");
		return -1;
	}
	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", image);


    // 1. gray scale
    Mat gray;
    cvtColor(image, gray, COLOR_RGB2GRAY);
    imshow("gray scale", gray);

    // 2. blur 
    Mat blurred;
    GaussianBlur(image,blurred, Size(7,7), 3.0);
    imshow("blur", blurred);

    // 3. edge cascade
    Mat edge;
    Canny(image,edge,125, 175);
    imshow("canny", edge);

    // 4. dilate image
    
    int dilation_size = 2;
    Mat dilated;    
    Mat element = getStructuringElement( MORPH_RECT,
                        Size( 2*dilation_size+1, 2*dilation_size+1 ),
                        Point( dilation_size, dilation_size ) );
    dilate(edge, dilated, element);
    imshow("dialted", dilated);

    // 5. erosion 
    int erosion_size = 2;
    Mat eroded;
    erode(dilated, eroded, element);
    imshow("eroded", eroded);

    // 6. resize
    Mat resized;
    resize(image, resized,Size(200, 200));
    imshow("resized", resized);

    // 7. crop
    Mat cropped = image(Rect(10,10, 200, 500)); // rect(X, Y, Width, Height)
    imshow("cropped", cropped);
	waitKey(0);
	return 0;
}

