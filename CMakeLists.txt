cmake_minimum_required(VERSION 3.10)
project(WaterSupplyManager)

set(CMAKE_CXX_STANDARD 11)

set(SRC_DIR ./src)

include_directories(SYSTEM ${SRC_DIR})

set(
        SOURCE_FILES
        main.cpp
        ${SRC_DIR}/Node.cpp
        ${SRC_DIR}/Pipe.cpp
        ${SRC_DIR}/City.cpp
        ${SRC_DIR}/Station.cpp
        ${SRC_DIR}/Reservoir.cpp
        ${SRC_DIR}/Network.cpp
        ${SRC_DIR}/Parsing.cpp
        ${SRC_DIR}/MaxFlow.cpp
        ${SRC_DIR}/Menu.cpp
)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output)

add_executable(WaterSupplyManager ${SOURCE_FILES})
