cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(ui)
add_subdirectory(world)


add_executable(rpg2 main.cpp)


target_link_libraries(rpg2 ui ecs world tilemap)
target_link_libraries(rpg2 CONAN_PKG::sfml ${TMXLITE_LIBRARIES})


target_compile_options(rpg2 PRIVATE -Wall -Wextra -Wshadow -pedantic -Wold-style-cast -Wcast-align 
                        -Wunused -Woverloaded-virtual -Wpedantic -Wconversion
                        -Wsign-conversion -Wdouble-promotion -Wformat=2 -Wnon-virtual-dtor 
                        -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op 
                        -Wnull-dereference -Wuseless-cast -Wdouble-promotion)