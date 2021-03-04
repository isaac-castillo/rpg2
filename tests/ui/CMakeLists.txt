cmake_minimum_required(VERSION 3.0)


add_executable(ui_tests test_window.cpp)
target_link_libraries(ui_tests catchtests)
target_link_libraries(ui_tests ui ecs world)
target_link_libraries(ui_tests sfml-graphics-d sfml-window-d sfml-system-d sfml-audio-d)


add_test(UI_TESTS ui_tests)