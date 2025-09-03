cmake_minimum_required(VERSION 4.0.2)

project(FractalRendering VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

#add_library(gpuCompute SHARED gpu/gpu.cpp gpu/gpu.h)
#target_link_libraries(gpuCompute PRIVATE GLEW::GLEW)

IF (MSVC)
else ()
ENDIF ()

add_executable(FractalRendering main.cpp
        window/window.cpp
        window/window.h
        gpu/gpu.cpp
        gpu/gpu.h)

target_link_libraries(FractalRendering PRIVATE SDL3::SDL3 GLEW::GLEW)