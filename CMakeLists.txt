cmake_minimum_required(VERSION 3.20)
project(ACSHomework2)

set(CMAKE_CXX_STANDARD 14)


set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(BINARY_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(SOURCE_FILES
        main.cpp

        container.cpp
        container.h

        programming_language.cpp
        programming_language.h

        procedural.cpp
        procedural.h

        objectoriented.cpp
        objectoriented.h

        functional.h
        functional.cpp

        filereader.h
        filereader.cpp

        StringRandomizer.h
        StringRandomizer.cpp
        )

add_executable(ACSHomework2 ${SOURCE_FILES})
