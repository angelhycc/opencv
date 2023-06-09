#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

#include <stdio.h>


int main(int argc, char** argv){
	if (argc != 2){
		printf("usage: DisplayVideo.out <Video_Path>\n");
		return -1;
	}
    cv::VideoCapture cap = cv::VideoCapture(argv[1]);
    cv::Mat frame;
    while(true){
        cap.read(frame);
        // check if we succeeded
        if (frame.empty()) {
            std::cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        cv::imshow("Video", frame);
        if (cv::waitKey(5)>=0){
            break;
        }
    }
    return 0;
}
