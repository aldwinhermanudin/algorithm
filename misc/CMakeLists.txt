cmake_minimum_required(VERSION 2.8.9)
project(misc)

#Bring the headers, such as Student.h into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
set (CMAKE_CXX_STANDARD 11)
add_executable(sanityCheck ${SOURCES})
