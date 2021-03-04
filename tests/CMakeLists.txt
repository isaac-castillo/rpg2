cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)


add_subdirectory(ui)
add_subdirectory(world)
add_library(catchtests test_main.cpp)



