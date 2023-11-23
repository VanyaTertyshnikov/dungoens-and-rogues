cmake_minimum_required(VERSION 3.16)
project(maths)

set(CMAKE_CXX_STANDARD 20)

file(GLOB
    SRCS "source/*.cpp")

add_library(${PROJECT_NAME} STATIC ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC include)
