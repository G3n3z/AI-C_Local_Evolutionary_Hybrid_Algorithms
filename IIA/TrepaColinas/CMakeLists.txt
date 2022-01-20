cmake_minimum_required(VERSION 3.19)
project(TrepaColinas C)

set(CMAKE_C_STANDARD 99)

add_executable(TrepaColinas main.c utils.c utils.h algoritmo.c algoritmo.h)