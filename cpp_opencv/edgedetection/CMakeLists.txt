cmake_minimum_required( VERSION 3.6 )
project( EdgeDetectionOps )
find_package( OpenCV REQUIRED )

add_executable( edge edgedetection.cpp )

target_include_directories(edge 
    PRIVATE 
        ${OpenCV_INCLUDE_DIRS} 
)

target_link_libraries( edge
    PRIVATE 
        ${OpenCV_LIBS}
)

