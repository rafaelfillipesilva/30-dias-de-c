project("30d_c_utils")

set(HEADERS
    )

set(SOURCES
    "src/string_utils.c")

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
add_library(30d_c::utils ALIAS ${PROJECT_NAME})

if(BUILD_TESTING)
    add_executable(test_${PROJECT_NAME}
                   "src/string_utils.c"
                   "tests/string_utils.cpp"
                   "tests/main.cpp")

    target_include_directories(test_${PROJECT_NAME}
                               PRIVATE
                               "src/")

    target_link_libraries(test_${PROJECT_NAME}
                          PRIVATE
                          30d_c::utils
                          Boost::unit_test_framework)

    add_test(test_${PROJECT_NAME} test_${PROJECT_NAME})
endif()
