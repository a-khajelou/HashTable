cmake_minimum_required(VERSION 3.3)
project(HashTable)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp HashTableNode.h Student.h HashTable.h)
add_executable(HashTable ${SOURCE_FILES})