cmake_minimum_required(VERSION 3.10)
project(K)
add_executable(Canny main.cpp)
target_link_directories(Canny PRIVATE ${CMAKE_SOURCE_DIR}/imports/build)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Canny ${OpenCV_LIBS} Functions)


