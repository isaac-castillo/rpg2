cmake_minimum_required(VERSION 3.0)


add_library(ui window.cpp)


target_link_libraries(ui PUBLIC CONAN_PKG::sfml)
