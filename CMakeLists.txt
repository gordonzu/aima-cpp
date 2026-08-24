

cmake_minimum_required(VERSION 3.28)
project(aicpp CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_SCAN_FOR_MODULES ON)

add_compile_options(
  -g -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion 
  -Wdouble-promotion -Wformat=2 -Wnull-dereference 
  -Wswitch-enum -Wswitch-default -Wunused -Wuninitialized -Wshadow 
  -fsanitize=address -fsanitize=undefined -O2
)

add_subdirectory(src)
add_subdirectory(tests)



