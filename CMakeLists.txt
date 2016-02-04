cmake_minimum_required(VERSION 3.3)
project(HashTableLink)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp HashTableNode.h Student.h HashTableLink.h HashTableArray.h LinkedList.h HashTable.h)
add_executable(HashTableLink ${SOURCE_FILES})