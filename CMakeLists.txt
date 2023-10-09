cmake_minimum_required(VERSION 3.20)

option(BUILD_TESTS "Build tests" ON)

project(vcs C CXX)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release")
endif()

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

# Common flags.
set(BUILD_SHARED_LIBS OFF)

# Third parties come with their own setup of
# C++ standard and compiler options.
add_subdirectory(contrib)

# Setup C++ standard for the project.
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wnon-virtual-dtor -Werror")

# Tests.
if(BUILD_TESTS)
    # Local test projects.
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/junk")
        add_subdirectory(junk EXCLUDE_FROM_ALL)
    endif()
endif()
