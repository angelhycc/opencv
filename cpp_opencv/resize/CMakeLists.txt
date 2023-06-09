cmake_minimum_required( VERSION 3.6 )
project( Resize )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( ResizeImage rescale_photo.cpp )
target_link_libraries( ResizeImage ${OpenCV_LIBS} )
add_executable( ResizeVideo rescale_video.cpp )
target_link_libraries( ResizeVideo ${OpenCV_LIBS} )
