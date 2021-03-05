cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)

project(rpg2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(cmake/Conan.cmake)
conan_add_remote(
    NAME
    bincrafters
    URL
    https://api.bintray.com/conan/bincrafters/public-conan)

conan_cmake_run(
REQUIRES
${CONAN_EXTRA_REQUIRES}
catch2/2.13.3
sfml/2.5.1@bincrafters/stable
OPTIONS
${CONAN_EXTRA_OPTIONS}
BASIC_SETUP
CMAKE_TARGETS # individual targets to link to
BUILD
missing)

# include_directories(tmxlite)

include_directories(SYSTEM external)
include_directories(src)

#link_directories(lib)
# link_directories(lib/Debug)


add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
