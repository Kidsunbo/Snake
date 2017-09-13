cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)
project(Snake)


LINK_LIBRARIES(sfml-graphics sfml-window sfml-system)
add_executable(${PROJECT_NAME} "main.cpp" "snake.h")
