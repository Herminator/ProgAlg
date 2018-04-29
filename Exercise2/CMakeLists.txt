cmake_minimum_required(VERSION 3.9)
project(Exercise2)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS_DEBUG "-O3")

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

find_library(Image freeimageplus)
find_path(ImageHeader FreeImagePlus.h)
message(${ImageHeader})

include_directories(../Stopwatch ${ImageHeader})

add_executable(Exercise2 imageprocessing.cpp summation.cpp main.cpp)

target_link_libraries(Exercise2 ${Image})

