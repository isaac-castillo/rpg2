cmake_minimum_required(VERSION 3.0)
add_subdirectory(ecs)

add_library(world 
layer_state.cpp
map_manager.cpp
tile.cpp
tilemap.cpp)



