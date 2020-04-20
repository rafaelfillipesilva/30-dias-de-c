cmake_minimum_required(VERSION 3.13)

project("30-dias-de-c"
        VERSION "1.0"
        DESCRIPTION "Solução dos deafios 30 dias de C do IO-Land."
        HOMEPAGE_URL "https://github.com/rafaelfillipesilva/30-dias-de-c"
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

include(CTest)

include_directories("include")

add_subdirectory("solution")
