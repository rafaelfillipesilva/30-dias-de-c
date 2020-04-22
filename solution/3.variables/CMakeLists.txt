cmake_minimum_required(VERSION 3.13)

project("3.variables")

set(HEADERS
    "src/variables.h")

set(SOURCES
    "src/variables.c"
    "src/main.c")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
