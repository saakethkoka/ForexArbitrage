cmake_minimum_required(VERSION 3.17)
project(ForexArbitrage)

set(CMAKE_CXX_STANDARD 14)

add_executable(ForexArbitrage main.cpp DocumentParser.cpp DocumentParser.h DSAdjacencyList.h DLListNode.h DLList.h)