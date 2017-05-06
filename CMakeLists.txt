cmake_minimum_required(VERSION 2.8.12)
project(ArbolB)

include_directories(include)

set(SOURCES src/Nodo.cpp src/main.cpp src/Arbol.cpp)

add_executable(ArbolB ${SOURCES})
