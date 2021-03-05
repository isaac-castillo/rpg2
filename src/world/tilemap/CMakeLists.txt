cmake_minimum_required(VERSION 3.0)

add_library(tilemap 
Layer.cpp
tile.cpp
tilemap.cpp
RenderLayer.cpp
)

target_link_libraries(tilemap CONAN_PKG::sfml)



