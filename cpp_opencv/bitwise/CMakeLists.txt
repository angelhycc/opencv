cmake_minimum_required( VERSION 3.6 )
project( BitwiseOps )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( bitwiseOps bitwise.cpp )
target_link_libraries( bitwiseOps ${OpenCV_LIBS} )

