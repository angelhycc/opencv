cmake_minimum_required( VERSION 3.6 )
project( Shapes )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( DrawShapes drawShapes.cpp )
target_link_libraries( DrawShapes ${OpenCV_LIBS} )

