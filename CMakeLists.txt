# CMake version check
cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(seriesDetail VERSION 1.0 LANGUAGES CXX)

# specify the C++ compiler and standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_BUILD_TYPE Release)


# set source files list
set(source_files src/main.cpp src/login.cpp src/search.cpp)

# Conan settingns
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(seriesDetail "${source_files}")

target_link_libraries(seriesDetail ${CONAN_LIBS})

target_include_directories(seriesDetail
    PUBLIC "${CMAKE_CURRENT_LIST_DIR}/inc"                          
)
