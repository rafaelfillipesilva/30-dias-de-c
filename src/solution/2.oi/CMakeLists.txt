project("2.oi")

set(HEADERS
    "src/oi.h")

set(SOURCES
    "src/oi.c"
    "src/main.c")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
                      PRIVATE
                      30d_c::utils)

if(BUILD_TESTING)
    add_executable(test_${PROJECT_NAME}
                   "src/oi.h"
                   "src/oi.c"
                   "tests/oi.cpp")

    target_include_directories(test_${PROJECT_NAME}
                               PRIVATE
                               "src/")

    target_link_libraries(test_${PROJECT_NAME}
                          PRIVATE
                          30d_c::utils
                          Boost::filesystem
                          Boost::unit_test_framework)

    add_test(test_${PROJECT_NAME} test_${PROJECT_NAME})
endif()
