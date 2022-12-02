# Minimum version for CMake

cmake_minimum_required(VERSION 3.16)

# Project name
project(CQueue)

# Output folder 
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/out/build)
set(EXECUTABLES_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# set(CMAKE_C_CLANG_TIDY "clang-tidy;-header-filter=/include/.;-checks=*")

# Including the following folder  
include_directories("${PROJECT_SOURCE_DIR}/include")

# executables
add_executable(Queue_Demo 
    ${PROJECT_SOURCE_DIR}/src/Queue_Demo.c
    ${PROJECT_SOURCE_DIR}/src/Queue.c
    ${PROJECT_SOURCE_DIR}/include/Queue.h
)

target_link_libraries(Queue_Demo -lm)

set_target_properties(Queue_Demo  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/executables")