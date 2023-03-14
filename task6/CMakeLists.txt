cmake_minimum_required(VERSION 3.15)

project(Task_6)

add_executable(main main.cpp)

target_link_libraries(main operator)
target_link_libraries(main stack)




add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(googletest)
add_executable(tests tests.cpp)
target_link_libraries(tests operator)

target_link_libraries(tests stack)


target_link_libraries(tests gtest gtest_main)
