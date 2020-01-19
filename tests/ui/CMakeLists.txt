cmake_minimum_required(VERSION 3.0)


add_executable(ui_tests test_window.cpp)
target_link_libraries(ui_tests catch)
target_link_libraries(ui_tests ui ecs)
target_link_libraries(ui_tests sfml-graphics sfml-window sfml-system sfml-audio)