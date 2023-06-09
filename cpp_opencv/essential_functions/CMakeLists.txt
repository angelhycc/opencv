cmake_minimum_required( VERSION 3.6 )
project( Basic )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( basic basic.cpp )
target_link_libraries( basic ${OpenCV_LIBS} )

