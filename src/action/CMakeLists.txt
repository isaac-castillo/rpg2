cmake_minimum_required(VERSION 3.0)
add_library(action  
GoToTileAction.cpp
)

target_link_libraries(action PUBLIC CONAN_PKG::sfml)