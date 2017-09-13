cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
project(Snake)
link_directories(/usr/local/lib)
include_directories(/usr/local/include)

LINK_LIBRARIES(sfml-graphics sfml-window sfml-system)
add_executable(${PROJECT_NAME} "main.cpp" "snake.h")
