cmake_minimum_required( VERSION 3.6 )
project( ThresholdingOps )
find_package( OpenCV REQUIRED )

add_executable( thresholding threshold.cpp )

target_include_directories(thresholding 
    PRIVATE 
        ${OpenCV_INCLUDE_DIRS} 
)

target_link_libraries( thresholding
    PRIVATE 
        ${OpenCV_LIBS}
)

