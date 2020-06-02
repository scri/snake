cmake_minimum_required(VERSION 3.15)
project(snakes)

set(CMAKE_CXX_STANDARD 14)

add_executable(snakes main.cpp include/tool.h include/point.h include/map.h include/snake.h include/food.h include/interface.h src/tool.cpp src/point.cpp src/map.cpp src/snake.cpp src/food.cpp src/ctrl.cpp include/ctrl.h include/direction.h)