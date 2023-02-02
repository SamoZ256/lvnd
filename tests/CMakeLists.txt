cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(
    "../include"
    "../external/glad/include"
)

find_library(
    LVND_LIB
    NAMES lvnd liblvnd
    HINTS "../lib"
    NO_DEFAULT_PATH
)

link_libraries(
    ${LVND_LIB}
)

set(GLAD_SRC ../external/glad/src/glad.c)

add_executable(window window.c)
add_executable(menu_bar menu_bar.c)
add_executable(opengl_triangle opengl_triangle.c ${GLAD_SRC})
