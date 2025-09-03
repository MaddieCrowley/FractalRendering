cmake_minimum_required(VERSION 4.0.2)

project(gpuCompute VERSION 0.1)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(gpuCompute gpu.cpp gpu.h)
