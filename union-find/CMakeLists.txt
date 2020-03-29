cmake_minimum_required(VERSION 3.15)
project(union_find)

set(CMAKE_CXX_STANDARD 11)

add_executable(union_find main.cpp quick_find.h quick_union.h weighted_quick_union.h)