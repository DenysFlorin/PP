cmake_minimum_required(VERSION 3.26)
project(PP)

set(CMAKE_CXX_STANDARD 17)

add_executable(PP main.cpp
        Rezervare.cpp
        Rezervare.h
        Masa.cpp
        Masa.h
        DataBase.cpp
        DataBase.h)
