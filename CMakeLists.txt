cmake_minimum_required(VERSION 4.2)
project(projekt1)

set(CMAKE_CXX_STANDARD 20)

add_executable(projekt1 main.cpp
        World.cpp
        World.h
        Organism.cpp
        Organism.h
        Plant.cpp
        Plant.h)
