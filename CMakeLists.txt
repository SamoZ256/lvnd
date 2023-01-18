cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME lvnd)

set(CMAKE_BUILD_TYPE Release)

add_compile_options(
    -O3
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
            "/Users/samuliak/VulkanSDK/1.3.236.0/macOS/include"
        )
    elseif (WIN32)
        find_package(Vulkan REQUIRED)
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

project(${PROJECT_NAME})

file(GLOB src
    src/*.c
    src/${PLATFORM}/*.${PLATFORM_SRC_FILE_EXT}
)

add_library(${PROJECT_NAME} SHARED
    ${src}
)

set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION 1)

include_directories(
    "include"
)

if (APPLE)
    find_library(QUARTZCORE_LIB QuartzCore)

    target_link_libraries(${PROJECT_NAME} "-framework Cocoa" ${QUARTZCORE_LIB})
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

    target_sources(${PROJECT_NAME} PRIVATE
        ${vulkanSrc}
    )

    if (APPLE)
        find_library (
            Vulkan_LIBRARIES
            NAMES vulkan libvulkan # what to look for
            HINTS "/Users/samuliak/VulkanSDK/1.3.236.0/macOS/lib" # where to look
        )
    endif ()

    target_link_libraries(${PROJECT_NAME}
        ${Vulkan_LIBRARIES}
    )
elseif (BACKEND_METAL)
    file(GLOB metalSrc
        src/metal/*.c
        src/${PLATFORM}/metal/*.m
    )

    target_sources(${PROJECT_NAME} PRIVATE
        ${metalSrc}
    )
elseif (BACKEND_OPENGL)
    file(GLOB openglSrc
        src/opengl/*.c
        src/${PLATFORM}/opengl/*.${PLATFORM_SRC_FILE_EXT}
    )

    target_sources(${PROJECT_NAME} PRIVATE
        ${openglSrc}
    )
endif ()