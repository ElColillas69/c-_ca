cmake_minimum_required(VERSION 3.27)
project(C___CA)

set(CMAKE_CXX_STANDARD 17)

add_executable(C___CA main.cpp
        hopper.cpp
        hopper.h
        crawler.cpp
        crawler.h
        cell.cpp
        cell.h
        bug.cpp
        bug.h
        board.cpp
        board.h
        dasher.cpp
        dasher.h)
