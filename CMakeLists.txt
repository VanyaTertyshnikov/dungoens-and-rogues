cmake_minimum_required(VERSION 3.16)
project(DungeonAndRogues)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(tests)


add_executable(main main.cpp)
target_link_libraries(main maths)
