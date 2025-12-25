cmake_minimum_required(VERSION 3.22)

project(
    IWPROJECT
    VERSION 1.0.0
    LANGUAGES CXX C
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

# generic project names 
set(LIB_NAME_INCLUDE IWI)
set(LIB_NAME IWL)
set(EXE_NAME App)

include(Addall)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_subdir_list(libs app)