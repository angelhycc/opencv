cmake_minimum_required( VERSION 3.6 )
project( splitmerge )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( splitmerge splitmerge.cpp )
target_link_libraries( splitmerge ${OpenCV_LIBS} )

