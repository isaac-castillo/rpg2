cmake_minimum_required(VERSION 3.0)
add_library(ecs 
entity.cpp
component_animation.cpp
component_graphics.cpp
component_input_player.cpp
component_physics.cpp
)

target_link_libraries(ecs PUBLIC CONAN_PKG::sfml)