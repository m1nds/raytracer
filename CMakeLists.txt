cmake_minimum_required(VERSION 3.29)

project(raytracer LANGUAGES CXX)

add_executable(raytracer "")
target_sources(raytracer PUBLIC
    src/main.cpp
    src/utils/point.cpp
    src/utils/color.cpp
    src/utils/interval.cpp
    src/utils/camera.cpp
    src/geometry/vector.cpp
    src/geometry/ray.cpp
    src/objects/sphere.cpp
    src/objects/world.cpp
    src/materials/lambertian.cpp
    src/materials/metal.cpp
)

target_include_directories(raytracer PRIVATE "includes")
