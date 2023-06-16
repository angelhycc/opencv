cmake_minimum_required( VERSION 3.6 )
project( Transformation )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( transformation transformation.cpp )
target_link_libraries( transformation ${OpenCV_LIBS} )

