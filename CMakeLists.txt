cmake_minimum_required(VERSION 3.8)
project(dominika)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES zadB.c)
add_executable(dominika ${SOURCE_FILES})