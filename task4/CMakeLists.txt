cmake_minimum_required(VERSION 3.18)

project(RingBuff)

set(RINGBUFF_DIR ${CMAKE_CURRENT_SOURCE_DIR}/RingBuff)
set(RINGBUFF_INCLUDE_DIR ${RINGBUFF_DIR}/include)
message("RINGBUFF_DIR = ${RINGBUFF_DIR}")
message("RINGBUFF_INCLUDE_DIR = ${RINGBUFF_INCLUDE_DIR}")

add_subdirectory(RingBuff)

include_directories(${RINGBUFF_INCLUDE_DIR})

add_executable(main main.cpp)
target_link_libraries(main RingBuff)
