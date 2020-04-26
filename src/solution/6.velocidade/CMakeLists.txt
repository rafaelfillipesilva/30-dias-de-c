cmake_minimum_required(VERSION 3.13)

project("6.velocidade")

set(HEADERS
    "src/velocidade.h")

set(SOURCES
    "src/velocidade.c"
    "src/main.c")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
                      PRIVATE
                      30d_c::utils)

if(BUILD_TESTING)
    add_executable(test_${PROJECT_NAME}
                   "src/velocidade.h"
                   "src/velocidade.c"
                   "tests/velocidade.cpp")

    target_include_directories(test_${PROJECT_NAME}
                               PRIVATE
                               "src/")

    target_link_libraries(test_${PROJECT_NAME}
                          PRIVATE
                          30d_c::utils
                          Boost::unit_test_framework)

    add_test(test_${PROJECT_NAME} test_${PROJECT_NAME})
endif()
