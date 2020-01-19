cmake_minimum_required(VERSION 3.0)

add_subdirectory(ui)
add_subdirectory(world)


add_executable(rpg2 main.cpp)


target_link_libraries(rpg2 ui ecs)
target_link_libraries(rpg2 sfml-graphics sfml-window sfml-system sfml-audio)


