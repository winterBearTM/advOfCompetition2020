cmake_minimum_required(VERSION 3.17)
project(cpp_medo)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_medo main.cpp day1/task.cpp day1/task.h commonLib.cpp commonLib.h)