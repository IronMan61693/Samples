# Minimum version for CMake

cmake_minimum_required(VERSION 3.16)

# Project name
project(CDataTypes)

# Output folder 
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/out/build)
set(EXECUTABLES_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# set(CMAKE_C_CLANG_TIDY "clang-tidy;-header-filter=/include/.;-checks=*")

# Including the following folder  
include_directories("${PROJECT_SOURCE_DIR}/include")

# executables
add_executable(DataTypes_Demo 
    ${PROJECT_SOURCE_DIR}/src/DataTypes_Demo.c
    ${PROJECT_SOURCE_DIR}/src/DataTypes.c
    ${PROJECT_SOURCE_DIR}/include/DataTypes.h
)

set_target_properties(DataTypes_Demo  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/executables")