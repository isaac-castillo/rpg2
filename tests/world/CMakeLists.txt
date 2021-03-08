cmake_minimum_required(VERSION 3.0)


add_executable(world_tests test_tile.cpp test_tilemap.cpp)
target_link_libraries(world_tests catchtests)
target_link_libraries(world_tests ecs ui world tilemap)
target_link_libraries(world_tests CONAN_PKG::sfml)


add_test(WORLD_TESTS world_tests)
