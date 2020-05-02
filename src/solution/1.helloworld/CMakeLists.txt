project("1.helloworld")

set(HEADERS
    "src/helloworld.h")

set(SOURCES
    "src/helloworld.c"
    "src/main.c")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

if(BUILD_TESTING)
    add_executable(test_${PROJECT_NAME}
                   "src/helloworld.h"
                   "src/helloworld.c"
                   "tests/helloworld.cpp")

    target_include_directories(test_${PROJECT_NAME}
                               PRIVATE
                               "src/")

    target_link_libraries(test_${PROJECT_NAME}
                          PRIVATE
                          Boost::filesystem
                          Boost::unit_test_framework)

    add_test(test_${PROJECT_NAME} test_${PROJECT_NAME})
endif()
