cmake_minimum_required(VERSION 3.16)
project(controls)

set(CMAKE_CXX_STANDARD 11)

add_executable(controls main.cpp CommandLine/CommandLine.cpp CommandLine/CommandLine.h Actions/Actions.cpp Actions/Actions.h)
