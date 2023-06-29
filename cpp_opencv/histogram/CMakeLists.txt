cmake_minimum_required( VERSION 3.6 )
project( histogramOps )
find_package( OpenCV REQUIRED )

add_executable( histogram histogram.cpp )

target_include_directories(histogram 
    PRIVATE 
        ${OpenCV_INCLUDE_DIRS} 
)

target_link_libraries( histogram
    PRIVATE 
        ${OpenCV_LIBS}
)

