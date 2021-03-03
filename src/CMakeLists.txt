cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(ui)
add_subdirectory(world)


add_executable(rpg2 main.cpp)


target_link_libraries(rpg2 ui ecs world tilemap)
target_link_libraries(rpg2 sfml-graphics-d sfml-window-d sfml-system-d sfml-audio-d tmxlite)


