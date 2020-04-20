cmake_minimum_required(VERSION 3.13)

project("3.variables")

set(HEADERS
    )

set(SOURCES
    "src/main.c")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

if(BUILD_TESTING)
    find_package(Boost 1.67.0
                 REQUIRED
                 COMPONENTS unit_test_framework)

    set(TESTS
        )

    add_executable(test_${PROJECT_NAME} ${TESTS})

    target_link_libraries(test_${PROJECT_NAME}
                        PRIVATE
                        Boost::unit_test_framework)

    target_compile_definitions(test_${PROJECT_NAME}
                            PRIVATE
                            BOOST_TEST_DYN_LINK)

    add_test(test_${PROJECT_NAME} test_${PROJECT_NAME})
    add_test(test_all test_${PROJECT_NAME})
endif()
