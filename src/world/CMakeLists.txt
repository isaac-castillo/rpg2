cmake_minimum_required(VERSION 3.0)
add_subdirectory(ecs)
add_subdirectory(tilemap)

add_library(world 
map_manager.cpp
)

target_link_libraries(world CONAN_PKG::sfml)



