cmake_minimum_required(VERSION 3.19)
project(Evolutivo C)

set(CMAKE_C_STANDARD 99)

add_executable(Evolutivo main.c algoritmo.c algoritmo.h utils.c utils.h funcao.c funcao.h)