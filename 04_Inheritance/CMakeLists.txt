cmake_minimum_required(VERSION 3.31)
project(04_Inheritance)

set(CMAKE_CXX_STANDARD 20)

add_executable(04_Inheritance main.cpp
        Point.cpp
        Point.h
        Circle.cpp
        Circle.h)
