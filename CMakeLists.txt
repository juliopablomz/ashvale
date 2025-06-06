cmake_minimum_required(VERSION 3.15)
project(ashvale LANGUAGES C)

# Enable generation of 'compile_commands.json'
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Configure C language standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Set project directories
set(PROJECT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(PROJECT_SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# Collect all C source files recursively under PROJECT_SRC_DIR
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
  "${PROJECT_SRC_DIR}/*.c"
)

# Create executable from source files
add_executable(${PROJECT_NAME} ${SOURCES})

# Specify include directories for the target
target_include_directories(${PROJECT_NAME} PRIVATE
  ${PROJECT_INCLUDE_DIR}
)

# Add strict warning and standard compliance flags
target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall -Wextra -Wpedantic -Werror
)
