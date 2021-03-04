cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
project(rpg2)


include_directories(SYSTEM include)
include_directories(src)

link_directories(lib)
link_directories(lib/Debug)

add_subdirectory(src)


enable_testing()
add_subdirectory(tests)

