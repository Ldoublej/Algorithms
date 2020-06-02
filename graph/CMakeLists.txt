cmake_minimum_required(VERSION 3.16)
project(graph)

set(CMAKE_CXX_STANDARD 11)

add_executable(graph main.cpp undirected_graph/undirected_graph.h undirected_graph/path_dfs.h undirected_graph/path_bfs.h undirected_graph/cc.h directed_graph/directed_graph.h undirected_graph/cycle.h)