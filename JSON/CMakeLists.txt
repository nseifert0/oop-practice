project(JSON CXX)

cmake_minimum_required(VERSION 3.5)



set(CMAKE_CXX_FLAGS "-std=c++1z")


add_executable(JSON main.cpp json.cpp)