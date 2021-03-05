cmake_minimum_required(VERSION 3.0)


add_executable(ui_tests test_window.cpp)
target_link_libraries(ui_tests catchtests)
target_link_libraries(ui_tests ui ecs world)
target_link_libraries(ui_tests CONAN_PKG::sfml)


add_test(UI_TESTS ui_tests)