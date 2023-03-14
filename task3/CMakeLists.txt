cmake_minimum_required(VERSION 3.18)

project(Base69)

set(BASE64_DIR ${CMAKE_CURRENT_SOURCE_DIR}/base64)
set(BASE64_INCLUDE_DIR ${BASE64_DIR}/include)
message("BASE64_DIR = ${BASE64_DIR}")
message("BASE64_INCLUDE_DIR = ${BASE64_INCLUDE_DIR}")

add_subdirectory(base64)
add_subdirectory(googletest)

include_directories(${BASE64_INCLUDE_DIR})

add_executable(main main.cpp)
target_link_libraries(main base64)

add_executable(tests tests.cpp)
target_link_libraries(tests base64 gtest gtest_main)