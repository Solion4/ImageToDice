cmake_minimum_required(VERSION 3.12)
project(MyProject)

find_package(OpenCV REQUIRED)

add_executable(MyProject main.cpp diceFaces.cpp processImage.cpp)

target_link_libraries(MyProject ${OpenCV_LIBS})
