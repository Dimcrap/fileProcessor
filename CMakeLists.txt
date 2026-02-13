cmake_minimum_required(VERSION 3.15)

project(fileprocessor VERSION 1.0)
set(SOURCES main.cpp scanner.cpp)
set(HEADERS scanner.h)

add_executable(FP)

source_group("src" FILES ${HEADERS} ${SOURCES})
target_sources(FP PRIVATE ${HEADERS} ${SOURCES})
