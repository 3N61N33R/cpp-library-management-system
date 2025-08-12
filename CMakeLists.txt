# This is a configuration file for the CMake build system, which automates the compilation process. 
# It's the modern standard for C++ projects.
cmake_minimum_required(VERSION 3.10.0)
project(library VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find all your source files in the src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(library ${SOURCES})

# Tell the compiler where to find header files
target_include_directories(library PUBLIC include)

