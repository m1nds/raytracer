cmake_minimum_required(VERSION 3.29)

project(raytracer LANGUAGES CXX)

add_executable(raytracer "")
target_sources(raytracer PUBLIC
    src/main.cpp
    src/utils/point.cpp
    src/geometry/vector.cpp
)

target_include_directories(raytracer PRIVATE "includes")
