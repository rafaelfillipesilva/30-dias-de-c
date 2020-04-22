cmake_minimum_required(VERSION 3.13)

project("30-dias-de-c"
        VERSION "1.0"
        DESCRIPTION "Solução dos deafios 30 dias de C do IO-Land."
        HOMEPAGE_URL "https://github.com/rafaelfillipesilva/30-dias-de-c"
        LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

include(CTest)

if(BUILD_TESTING)
    set(Boost_USE_STATIC_LIBS        OFF)
    set(Boost_USE_DEBUG_LIBS         OFF)
    set(Boost_USE_RELEASE_LIBS       ON)
    set(Boost_USE_MULTITHREADED      ON)
    set(Boost_USE_STATIC_RUNTIME     OFF)

    find_package(Boost 1.67.0
                 REQUIRED
                 COMPONENTS filesystem
                            unit_test_framework)
endif()

include_directories("include")

add_subdirectory("solution")
