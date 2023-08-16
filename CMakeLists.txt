cmake_minimum_required(VERSION 3.0)
project(pitransmitter)

find_path(SNDFILE_INCLUDE_DIR sndfile.h)
find_library(SNDFILE_LIBRARY NAMES sndfile)

add_executable(pitransmitter main.cpp)

target_include_directories(pitransmitter PRIVATE ${SNDFILE_INCLUDE_DIR})
target_link_libraries(pitransmitter PRIVATE ${SNDFILE_LIBRARY})


# cmake_minimum_required(VERSION 3.10.2)
# project (pi-fm-transmitter)

# # SET SOURCES
# set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
# file(GLOB SOURCES src/*.c)

# find_package(SndFile REQUIRED)
# include_directories(${SNDFILE_INCLUDE_DIRS})

# # BUILD TYPE
# if (NOT CMAKE_BUILD_TYPE)
#     message(STATUS "Build type not specified: Use Release by default")
#     set(CMAKE_BUILD_TYPE Release)
#     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/release)

# elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
#     message(STATUS "Build type: Release")
#     set(CMAKE_BUILD_TYPE Release)
#     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/release)

# elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     message(STATUS "Build type: Debug")
#     set(CMAKE_BUILD_TYPE Debug)
#     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/debug)

# endif()

# # SETTING COMPILER
# set(CMAKE_C_STANDARD 11)
# set(CMAKE_C_STANDARD_REQUIRED ON)
# set(CMAKE_C_EXTENSIONS OFF)
# set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")
# set(CMAKE_C_FLAGS_DEBUG "-g")
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# # SETTING RESOURCES
# set(APPLICATIONS_DIR "/usr/share/applications/")
# set(ICON_DIR "/usr/share/icons/hicolor/")

# # PROGRAM
# add_executable(pi-fm-transmitter ${SOURCES})
# target_link_libraries(pi-fm-transmitter ${SNDFILE_LIBRARIES})

# # INSTALL TARGET
# install(TARGETS pi-fm-transmitter RUNTIME DESTINATION bin)

# # UNINSTALL TARGET
# configure_file(
#     "install_manifest.txt.in"
#     "${CMAKE_CURRENT_BINARY_DIR}/install_manifest.txt"
#     IMMEDIATE @ONLY
# )

# add_custom_target(uninstall
#     COMMAND "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake"
# )

# configure_file(
#     "${CMAKE_CURRENT_SOURCE_DIR}/uninstall.cmake.in"
#     "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake"
#     IMMEDIATE @ONLY
# )