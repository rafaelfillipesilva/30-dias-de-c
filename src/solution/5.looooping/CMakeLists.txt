project("5.looooping")

set(HEADERS
    "src/looooping.h")

set(SOURCES
    "src/looooping.c"
    "src/main.c")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
                      PRIVATE
                      30d_c::utils)
