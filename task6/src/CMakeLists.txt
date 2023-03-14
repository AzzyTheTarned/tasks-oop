project(Task_6)

add_library(operator operator.cpp)
add_library(stack stack.cpp)
target_include_directories(operator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_include_directories(stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
