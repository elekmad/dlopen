cmake_minimum_required(VERSION 2.8)
#Déclaration du projet
cmake_policy(SET CMP0004 OLD)

project (SharedLib1)
add_library(SharedLib1 SHARED lib1.c)

project (SharedLib2)
add_library(SharedLib2 SHARED lib2.c)

project (DLLib1)
add_library(DLLib1 SHARED dllib1.c)

project(MyProject)
add_executable(MyProject main.c)
add_dependencies(MyProject SharedLib1)
target_link_libraries (MyProject SharedLib1)
target_link_libraries (MyProject "-ldl")

include(CheckCCompilerFlag)
check_c_compiler_flag("-std=c99" C99_SUPPORTED)
if (C99_SUPPORTED)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
endif()

set( CMAKE_C_FLAGS_DEBUG   " -ggdb3" )
