cmake_minimum_required(VERSION 3.15)
project(ashvale LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)
