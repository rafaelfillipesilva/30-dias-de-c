cmake_minimum_required(VERSION 3.13)

project("7.calculadora")

set(HEADERS
    "src/operations.h"
    "src/calculadora.h")

set(SOURCES
    "src/operations.c"
    "src/calculadora.c"
    "src/main.c")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
                      PRIVATE
                      30d_c::utils)

if(BUILD_TESTING)
    add_executable(test_${PROJECT_NAME}
                   "src/operations.c"
                   "tests/calculadora.cpp")

    target_include_directories(test_${PROJECT_NAME}
                               PRIVATE
                               "src/")

    target_link_libraries(test_${PROJECT_NAME}
                          PRIVATE
                          Boost::unit_test_framework)

    add_test(test_${PROJECT_NAME} test_${PROJECT_NAME})
endif()
