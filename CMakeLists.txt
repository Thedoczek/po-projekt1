cmake_minimum_required(VERSION 4.2)
project(projekt1)

set(CMAKE_CXX_STANDARD 20)

add_executable(projekt1 main.cpp
        World.cpp
        World.h
        Organism.cpp
        Organism.h
        organisms/Plant.cpp
        organisms/Plant.h
        organisms/Animal.cpp
        organisms/Animal.h
        organisms/animals/Human.cpp
        organisms/animals/Human.h
        organisms/animals/Wolf.cpp
        organisms/animals/Wolf.h
        organisms/animals/Sheep.cpp
        organisms/animals/Sheep.h
        organisms/animals/Fox.cpp
        organisms/animals/Fox.h
        organisms/animals/Turtle.cpp
        organisms/animals/Turtle.h
        organisms/animals/Antelope.cpp
        organisms/animals/Antelope.h
        organisms/plants/Grass.cpp
        organisms/plants/Grass.h
        organisms/plants/Dandelion.cpp
        organisms/plants/Dandelion.h
        organisms/plants/Guarana.cpp
        organisms/plants/Guarana.h
        organisms/plants/Belladonna.cpp
        organisms/plants/Belladonna.h
        organisms/plants/SosnowskyHogweed.cpp
        organisms/plants/SosnowskyHogweed.h)
