cmake_minimum_required(VERSION 3.0)

add_library(catch INTERFACE)
target_include_directories(catch INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_sources(catch INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/test_main.cpp")

add_subdirectory(ui)
add_subdirectory(world)





