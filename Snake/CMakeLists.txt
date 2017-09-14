cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
project(Snake)
link_directories(E:\\SFML-2.4.2\\lib)
include_directories(E:\\SFML-2.4.2\\include)

LINK_LIBRARIES(sfml-graphics sfml-window sfml-system)
add_executable(${PROJECT_NAME} "main.cpp" "snake.h")
