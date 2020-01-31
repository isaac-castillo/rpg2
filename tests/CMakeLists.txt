cmake_minimum_required(VERSION 3.0)

add_subdirectory(ui)
add_subdirectory(world)
add_library(catch test_main.cpp)



