cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Release)

add_compile_options(
    -O2
)

set(LINUX False)
if (UNIX AND NOT APPLE)
    set(LINUX True)
endif ()

set(PLATFORM)
set(PLATFORM_SRC_FILE_EXT c)

if (APPLE)
    set(PLATFORM cocoa)
    set(PLATFORM_SRC_FILE_EXT m)
elseif (LINUX)
    set(PLATFORM x11)
elseif (WIN32)
    set(PLATFORM win32)
endif ()

option(BACKEND_VULKAN "Build using vulkan backend" OFF)
option(BACKEND_METAL "Build using metal backend" OFF)
option(BACKEND_OPENGL "Build using opengl backend" OFF)

set(BACKEND)

if (BACKEND_VULKAN)
    message("Building using vulkan backend")

    set(BACKEND vulkan)

    if (APPLE)
        include_directories(
            "/usr/local/Cellar/Vulkan/macOS/include"
        )
    elseif (WIN32)
        include_directories(
            "/usr/local/Cellar/Vulkan/macOS/include" #TODO: find out where is vulkan saved
        )
    endif ()
elseif (BACKEND_METAL)
    message("Building using metal backend")

    set(BACKEND metal)
elseif (BACKEND_OPENGL)
    message("Building using opengl backend")

    set(BACKEND opengl)

    if (APPLE)
        add_compile_options(
            -Wno-deprecated-declarations
        )
    endif ()
else ()
    set(BACKEND nobackend)
endif ()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${BACKEND})

project(lvnd)

file(GLOB src
    src/*.c
    src/${PLATFORM}/*.${PLATFORM_SRC_FILE_EXT}
)

add_library(lvnd SHARED
    ${src}
)

set_target_properties(lvnd PROPERTIES SOVERSION 1)

include_directories(
    "include"
)

if (APPLE)
    find_library(QUARTZCORE_LIB QuartzCore)

    target_link_libraries(lvnd "-framework Cocoa" ${QUARTZCORE_LIB})
elseif (LINUX)
    find_package(X11 REQUIRED)

    target_link_libraries(${PROJECT_NAME}
        ${X11_LIBRARIES}
    )
elseif (WIN32)
    #TODO: add windows-specific libraries
endif ()

if (BACKEND_VULKAN)
    file(GLOB vulkanSrc
        src/vulkan/*.c
        src/${PLATFORM}/vulkan/*.${PLATFORM_SRC_FILE_EXT}
    )

    target_sources(lvnd PRIVATE
        ${vulkanSrc}
    )

    find_library (
        VULKAN_LIB
        NAMES vulkan libvulkan # what to look for
        HINTS "/usr/local/Cellar/Vulkan/macOS/lib" # where to look
    )

    target_link_libraries(lvnd
        ${VULKAN_LIB}
    )
elseif (BACKEND_METAL)
    file(GLOB metalSrc
        src/metal/*.c
        src/${PLATFORM}/metal/*.m
    )

    target_sources(lvnd PRIVATE
        ${metalSrc}
    )
elseif (BACKEND_OPENGL)
    file(GLOB openglSrc
        src/opengl/*.c
        src/${PLATFORM}/opengl/*.${PLATFORM_SRC_FILE_EXT}
    )

    target_sources(lvnd PRIVATE
        ${openglSrc}
    )
endif ()
