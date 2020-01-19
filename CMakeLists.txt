cmake_minimum_required(VERSION 3.0)
project(MyApp)
include_directories(include)
include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)