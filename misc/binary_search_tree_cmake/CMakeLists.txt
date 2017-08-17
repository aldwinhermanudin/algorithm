cmake_minimum_required(VERSION 2.8.9)
project(bs_tree)

#Bring the headers, such as Student.h into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
set(SOURCES src/main.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
set (CMAKE_CXX_STANDARD 11)
add_executable(BinarySearchTree ${SOURCES})
add_executable(BinarySearch3 ${SOURCES})
