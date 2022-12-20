cmake_minimum_required(
  VERSION 3.8 
)

project(TaskQueue)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(unittest test/unit_tests.cpp)
