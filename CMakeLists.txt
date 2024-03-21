cmake_minimum_required(VERSION 3.22)

# Project properties
project(uni_aizo_p)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

add_definitions(-DDATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data/")

# CPM
include(CPM.cmake)
CPMAddPackage(
        NAME fmt
        GITHUB_REPOSITORY fmtlib/fmt
        GIT_TAG 10.1.1
)
CPMAddPackage(
        NAME gsl
        GITHUB_REPOSITORY microsoft/GSL
        GIT_TAG v4.0.0
)

find_package(fmt REQUIRED)
find_package(gsl REQUIRED)

# Code
add_subdirectory(src)
