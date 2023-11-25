cmake_minimum_required(VERSION 3.16)
project(equipments)

set(CMAKE_CXX_STANDARD 20)

file(GLOB
    SRCS "source/*.cpp")

add_library(${PROJECT_NAME} STATIC ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC objects maths)
