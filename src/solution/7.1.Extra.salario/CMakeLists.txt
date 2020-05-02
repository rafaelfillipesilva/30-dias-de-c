project("7.1.Extra.salario")

set(HEADERS
    "src/salario.h")

set(SOURCES
    "src/salario.c"
    "src/main.c")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
                      PRIVATE
                      30d_c::utils)

if(BUILD_TESTING)
    add_executable(test_${PROJECT_NAME}
                   "src/salario.c"
                   "tests/salario.cpp")

    target_include_directories(test_${PROJECT_NAME}
                               PRIVATE
                               "src/")

    target_link_libraries(test_${PROJECT_NAME}
                          PRIVATE
                          30d_c::utils
                          Boost::unit_test_framework)

    add_test(test_${PROJECT_NAME} test_${PROJECT_NAME})
endif()
