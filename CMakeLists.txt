cmake_minimum_required(VERSION 4.0)
project(ICPC)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 23)

add_executable(ICPC main.cpp)

target_compile_definitions(
        ICPC
        PUBLIC
        "mhnd01s"
)

target_precompile_headers(ICPC
        PUBLIC
        $<BUILD_INTERFACE:bits/stdc++.h>
)