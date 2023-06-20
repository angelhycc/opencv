cmake_minimum_required( VERSION 3.6 )
project( Contour )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( contour contour.cpp )
target_link_libraries( contour ${OpenCV_LIBS} )

