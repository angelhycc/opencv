cmake_minimum_required( VERSION 3.6 )
project( MaskingOps )
find_package( OpenCV REQUIRED )

add_executable( masking masking.cpp )

target_include_directories(masking 
    PRIVATE 
        ${OpenCV_INCLUDE_DIRS} 
)

target_link_libraries( masking
    PRIVATE 
        ${OpenCV_LIBS}
)

