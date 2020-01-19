cmake_minimum_required(VERSION 3.0)


add_executable(world_tests test_entity.cpp)
target_link_libraries(world_tests catch)
target_link_libraries(world_tests ui ecs)
target_link_libraries(world_tests sfml-graphics sfml-window sfml-system sfml-audio)
