cmake_minimum_required(VERSION 3.16)
project(maths_tests)

find_package(Catch2 2 REQUIRED)

add_executable(parameter-test parameter-test.cpp)
target_link_libraries(parameter-test maths Catch2::Catch2)

add_executable(relation-test relation-test.cpp)
target_link_libraries(relation-test maths Catch2::Catch2)

add_executable(equation-test equation-test.cpp)
target_link_libraries(equation-test maths Catch2::Catch2)

add_executable(factor-test factor-test.cpp)
target_link_libraries(factor-test maths Catch2::Catch2)


