cmake_minimum_required(VERSION 3.0)


add_executable(world_tests test_tile.cpp)
target_link_libraries(world_tests catch)
target_link_libraries(world_tests ecs ui world tilemap)
target_link_libraries(world_tests sfml-graphics-d sfml-window-d sfml-system-d sfml-audio-d)



