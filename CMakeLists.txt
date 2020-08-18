cmake_minimum_required(VERSION 3.10)
project(MY_PROJECT_NAME VERSION 1.0.0)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(extern\\googletest)
