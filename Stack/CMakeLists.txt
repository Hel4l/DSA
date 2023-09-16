cmake_minimum_required(VERSION 3.26)
project(Stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(Stack main.cpp
        StackADT.cpp
        StackADT.h
        StackLinkedList.cpp
        StackLinkedList.h)
