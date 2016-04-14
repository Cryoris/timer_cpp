cmake_minimum_required(VERSION 2.8)
project(TimerLib)

add_definitions(-std=c++11)
add_library(Timer timer.cpp)

install(TARGETS Timer DESTINATION lib)
install(FILES timer.hpp DESTINATION include)
