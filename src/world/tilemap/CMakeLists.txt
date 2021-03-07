cmake_minimum_required(VERSION 3.0)

add_library(tilemap 
Layer.cpp
Tile.cpp
Tilemap.cpp
RenderLayer.cpp
)

target_link_libraries(tilemap CONAN_PKG::sfml ${TMXLITE_LIBRARIES})



